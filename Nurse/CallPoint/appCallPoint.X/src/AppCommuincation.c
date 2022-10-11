#include <stdint.h>

#include "../inc/AppCommuication.h"

#define  WAIT_RESP         0xFF;


#define  PING_TIME_OUT             5000UL
volatile uint8_t gu8CallPoint[CALL_POINT_LENGTH];
volatile uint8_t gu8RequestState;
volatile uint8_t gu8StartComm;
volatile uint8_t gu8Address;
volatile uint8_t gu8CallPointState;
stTimer_t gsPingTimer;


uint8_t setConfig();
uint8_t appCommResponse(void);
uint8_t appCommRequestHandle(void);
uint8_t appCommFree(void);
uint8_t appCommStateDone(void);
uint8_t appCallPointDefined(void);

void storeConfig();

uint8_t appCommFree(void) {
    if (IsCommunicationOpen()) {
        gsTransmissionFrame.u8Address = CSMA_FREE_ADDRESS;
        gsTransmissionFrame.u8ByteCount = 0;
        StartTransmission();
        return (1);
    }
    return (0);
}

uint8_t appCommStart() {
    if ((gu8StartComm) && (gu8CallPoint[callPointLastConfig] != 0) && gu8CallPoint[callPointLastConfig] != 0xFF) {
        return (1);
    }
    return (0);
}

void appCommPingTimeOut() {
    if (sysIsTimeout(&gsPingTimer)) {
        gu8StartComm = 0;
    }
}

void appCommunication(uint8_t u8state) {
    gu8RequestState = STATE_REQ_CMD;
    gsTransmissionFrame.u8Address = gu8Address;
    gsTransmissionFrame.u8ByteCount = 5;
    gsTransmissionFrame.u8Data[0] = STATE_REQ_CMD;
    gsTransmissionFrame.u8Data[1] = gu8CallPoint[callPointID];
    gsTransmissionFrame.u8Data[2] = gu8CallPoint[callPointRoomID]; /*Room ID*/
    gsTransmissionFrame.u8Data[3] = gu8CallPoint[callPointRoomA];
    gsTransmissionFrame.u8Data[4] = u8state;
    StartTransmission();
}

uint8_t appCommResponse(void) {
    /*check the call point state*/
    if (gsReceiveFrame.u8Data[0] == STATE_RES_CMD) {
        switch (gu8CallPointState) {
            case CALL_POINT_AS_SW:
                /*check the address is my address or no*/
                if (gsReceiveFrame.u8Data[1] != gu8Address) {
                    gu8RequestState = NO_CMD;
                    return (1);
                }
                /*store in EEPROM*/
                /*send ResPonse*/
                appCommFree();
                gu8CallPoint[callPointLastState] = gsReceiveFrame.u8Data[2];
                break;
            case CALL_POINT_AS_ROOM:
                if (gsReceiveFrame.u8Data[3] != gu8Address) {
                    gu8RequestState = NO_CMD;
                    return (1);
                }
                /*store in EEPROM*/
                gu8CallPoint[callPointLastState] = gsReceiveFrame.u8Data[4];
                gu8RequestState = NO_CMD;
                break;
            default:
                break;
        }
        gu8RequestState = NO_CMD;
        return (1);
    }
    return (0);
}

void storeConfig() {

    for (uint8_t i = 0; i < gsReceiveFrame.u8ByteCount; i++) {
        gu8CallPoint[i] = gsReceiveFrame.u8Data[i + 1];
    }

    /*store in EEPROM*/
    for (uint8_t i = 0; i < CALL_POINT_LENGTH - 1; i++) {
        eepromPutByte(START_CALLPOINT_ADDRESS + i, gu8CallPoint[i]);
    }
    gu8CallPointState = appCallPointDefined();

}

uint8_t appCallPointDefined(void) {
    if ((!gu8CallPoint[callPointRoomA]))
        return CALL_POINT_AS_ROOM;
    return CALL_POINT_AS_SW;
}

void appcommInit() {
    gu8Address = csmaGetAddress();
    for (uint8_t i = 0; i < CALL_POINT_LENGTH - 1; i++) {
        gu8CallPoint[i] = eepromGetByte(START_CALLPOINT_ADDRESS + i);
    }
    OnHostFrame(appCommRequestHandle);
    OnClientFrame(appCommResponse);
    gu8RequestState = NO_CMD;
    gu8StartComm = 0;
    gu8CallPointState = appCallPointDefined();
    sysSetPeriod(&gsPingTimer, PING_TIME_OUT);
    sysSetTimer(&gsPingTimer, getSystemTick());
}

/*send Request */



uint8_t appCommRequestHandle(void) {
    /*the data is not my data*/
    switch (gsReceiveFrame.u8Data[0]) {
            /*handling Requesting*/
        case STATE_REQ_CMD:
#if AS_DISABLED_SYSTEM 
            if (IsCommunicationOpen()) {
                gu8RequestState = NO_CMD;
                if (gu8CallPoint[callPointLastState] != CENCEL_STATE && gu8CallPointState != CALL_POINT_AS_DISPLAY) {
                    gu8CallPoint[callPointLastState] = gsReceiveFrame.u8Data[1];
                    gsTransmissionFrame.u8Address = gu8Address;
                    gsTransmissionFrame.u8ByteCount = 1;
                    gsTransmissionFrame.u8Data[0] = CONFRAM_STATE_CMD;
                    sysSetTimer(&gsPingTimer, getSystemTick());
                    StartTransmission();
                }
                return (1);
            }
#else 
            return (1);
#endif
            break;
        case SET_CONFIG_REQ_CMD:
            if (IsCommunicationOpen()) {
                gu8RequestState = NO_CMD;
                /*store my config is verifiying and start communication*/
                /*put data into */
                gsTransmissionFrame.u8Address = gu8Address;
                gsTransmissionFrame.u8ByteCount = 3;
                gsTransmissionFrame.u8Data[0] = CONFIG_RES_CMD;
                gsTransmissionFrame.u8Data[1] = gsReceiveFrame.u8Data[1];
                gsTransmissionFrame.u8Data[1] = gsReceiveFrame.u8Data[3];
                if (gu8CallPoint[callPointLastConfig] != gsReceiveFrame.u8Data[4]) {
                    storeConfig();
                } else {
                    /*save only state*/
                    gu8CallPoint[callPointLastState] = gsReceiveFrame.u8Data[5];
                }
                sysSetTimer(&gsPingTimer, getSystemTick());
                StartTransmission();
                return (1);
            }
            break;
        case REMOVE_CONFIG_REQ:
            gu8StartComm = 0;
            gu8RequestState = NO_CMD;
            if (IsCommunicationOpen()) {
                gsTransmissionFrame.u8Address = gu8Address;
                gsTransmissionFrame.u8ByteCount = 1;
                gsTransmissionFrame.u8Data[0] = REMOVE_CONFIG_RES_CMD;
                for (uint8_t i = 0; i < CALL_POINT_LENGTH; i++) {
                    gu8CallPoint[i] = 0;
                    if (i < CALL_POINT_LENGTH - 1)
                        eepromPutByte(START_CALLPOINT_ADDRESS + i, gu8CallPoint[i]);
                }
                gu8CallPointState = CALL_POINT_NOT_DEFINED;
                sysSetTimer(&gsPingTimer, getSystemTick());
                StartTransmission();
                return (1);
            }
            break;
        case PING_REQ_CMD:
            if (IsCommunicationOpen()) {
                //                for (uint8_t i = 1; i < 5; i++)
                ////                    gu32RTC |= (gsReceiveFrame.u8Data[i]) << ((i - 2)*8); /*sync time with master*/
                gsTransmissionFrame.u8Address = gu8Address;
                gsTransmissionFrame.u8ByteCount = 5;
                gsTransmissionFrame.u8Data[0] = PING_RES_CMD;
                gsTransmissionFrame.u8Data[1] = gu8CallPoint[callPointLastConfig];
                gsTransmissionFrame.u8Data[2] = gu8CallPoint[callPointID];
                gsTransmissionFrame.u8Data[3] = gu8CallPoint[callPointRoomA];
                gsTransmissionFrame.u8Data[4] = gu8CallPoint[callPointRoomID];
                gu8StartComm = 1;
                sysSetTimer(&gsPingTimer, getSystemTick());
                StartTransmission();
                return (1);
            }
            break;
        case PING_STATE_REQ_CMD:
            if (IsCommunicationOpen()) {
                gu8RequestState = NO_CMD;
                if (gsReceiveFrame.u8Data[1] != gu8Address) {
                    return (1);
                }
                gu8CallPoint[callPointLastState] = gsReceiveFrame.u8Data[2];
                gsTransmissionFrame.u8Address = gu8Address;
                gsTransmissionFrame.u8ByteCount = 1;
                gsTransmissionFrame.u8Data[0] = PING_STATE_RES_CMD;
                sysSetTimer(&gsPingTimer, getSystemTick());
                StartTransmission();

                return (1);
            }
            break;
        default:
            return (1);
            break;
    }
    return (0);
}

uint8_t getcommStateCMD() {
    return gu8RequestState;
}

uint8_t getState() {
    return gu8CallPoint[callPointLastState];
}

uint8_t getStateCallPoint() {
    return gu8CallPointState;
}

