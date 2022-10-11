
#include <stdint.h>

#include "../inc/AppCommuication.h"


#define COMM_ADDRESS         START_CALLPOINT_ADDRESS +CALL_POINT_LENGTH+1


#define  REQ_LENGTH          (5) /*5 adddress , 5 request*/
#define  COMM_OK             (0x01)
#define  COMM_NOT_OK         (0x02)


#define  CALL_POINT_ADDRESS       (0x01)
#define  PING_TIME_OUT             1000UL
#define  RESPONSE_TIME_OUT         50

volatile uint8_t gu8CallPoint[CALL_POINT_LENGTH];
uint8_t gu8RequestState;




#define     COMM_POWER_ON        (7)
#define     COMM_REESET_FLAG     (6)
#define     COMM_READ_CENCEL     (5)
#define     COMM_PING_MASK       (0x03)
volatile uint8_t gu8CommFlags;


uint8_t gu8appRequest[REQ_LENGTH];
stTimer_t gsResponseTimeOut;
stByteBufDescriptor_t gstRequest;

void appCommSetPoint();
uint8_t appCommRequestHandle(void);
uint8_t appCommClinentResponse(void);

uint8_t appCommFree(void);
uint8_t appPingResPonse();

uint8_t appCommRequestGetBuffer(uint8_t *CMD);

uint8_t appCommRequestPutBuffer(uint8_t CMD) {
    uint8_t state, CMDstate;
    state = SREG;
    __disable_interrupt();
    CMDstate = putByte(&gstRequest, CMD);
    SREG = state;
    __enable_interrupt();
    if (CMDstate)
        return (1);
    return (0);
}

void appCommResetButton() {
    if (digitalPinRead(RESET_BUTTON) == 0) {
        bitClear(gu8CommFlags, COMM_REESET_FLAG);
    } else {
        bitSet(gu8CommFlags, COMM_REESET_FLAG);
    }
}

uint8_t appCommRequestGetBuffer(uint8_t *CMD) {
    uint8_t state, CMDstate;
    state = SREG;
    __disable_interrupt();
    CMDstate = getByte(&gstRequest, CMD);
    SREG = state;
    __enable_interrupt();
    if (CMDstate)
        return (1);
    return (0);
}

uint8_t appCommReadCMD() {
    return gu8RequestState;
}

uint8_t appPingResPonse() {
    if (gu8CallPoint[callPointLastConfig] != gsReceiveFrame.u8Data[1]) {
        /*set Configuration*/
        appCommRequestPutBuffer(SET_CONFIG_REQ_CMD);
        gu8RequestState = NO_CMD;
        return (1);
    }

    if (gu8CallPoint[callPointLastState] != gsReceiveFrame.u8Data[2]) {
        appCommRequestPutBuffer(PING_STATE_REQ_CMD);
        gu8RequestState = NO_CMD;
        return (1);
    }

    if (appCommFree()) {
        gu8RequestState = NO_CMD;
        return (1);
    }
    return (0);
}

uint8_t appCommFree(void) {
    if (IsCommunicationOpen()) {
        gsTransmissionFrame.u8Address = CSMA_FREE_ADDRESS;
        gsTransmissionFrame.u8ByteCount = 0;
        StartTransmission();
        return (1);
    }
    return (0);
}

void appCommunication() {

    if (!IsCommunicationOpen())
        return;

    if (gu8RequestState == NO_CMD) {
        appCommRequestGetBuffer(&gu8RequestState);
        if (sysIsTimeout(&gsResponseTimeOut) && (gu8RequestState == NO_CMD)) {
            gu8RequestState = PING_REQ_CMD;
            sysSetPeriodMS(&gsResponseTimeOut, PING_TIME_OUT);
            sysSetTimer(&gsResponseTimeOut, getSystemTick());
        }

        return;
    }

    if (gu8RequestState == WAIT_FOR_RES) {
        if (sysIsTimeout(&gsResponseTimeOut)) {
            appCommFree();
            sysSetPeriodMS(&gsResponseTimeOut, PING_TIME_OUT);
            sysSetTimer(&gsResponseTimeOut, getSystemTick());
            gu8RequestState = NO_CMD;
        }
        return;
    }

    if (gu8RequestState == PING_REQ_CMD) {
        /*wait for conFrimaed send Frame*/
        gu8RequestState = WAIT_FOR_RES;
        gsTransmissionFrame.u8Address = 0x01; /*all Points Receive*/
        gsTransmissionFrame.u8ByteCount = 5;
        gsTransmissionFrame.u8Data[0] = PING_REQ_CMD;
        for (uint8_t i = 1; i < 5; i++)
            gsTransmissionFrame.u8Data[i] = 0x00; /*sync time with master*/
        sysSetPeriodMS(&gsResponseTimeOut, RESPONSE_TIME_OUT);
        sysSetTimer(&gsResponseTimeOut, getSystemTick());
        StartTransmission();
        return;
    }


    if (gu8RequestState == PING_STATE_REQ_CMD) {
        gu8RequestState = WAIT_FOR_RES;
        gsTransmissionFrame.u8Address = 0x01; /*all Receive*/
        gsTransmissionFrame.u8ByteCount = 2;
        gsTransmissionFrame.u8Data[0] = PING_STATE_REQ_CMD;
        gsTransmissionFrame.u8Data[1] = gu8CallPoint[callPointLastState];
        sysSetPeriodMS(&gsResponseTimeOut, RESPONSE_TIME_OUT); /*40 ms for response*/
        sysSetTimer(&gsResponseTimeOut, getSystemTick());
        StartTransmission();
        return;
    }

    if (gu8RequestState == SET_CONFIG_REQ_CMD) {
        /*wait conframed */
        gsTransmissionFrame.u8Address = CALL_POINT_ADDRESS; /*all Points Receive*/
        gsTransmissionFrame.u8ByteCount = 6;
        gsTransmissionFrame.u8Data[0] = SET_CONFIG_REQ_CMD;
        gsTransmissionFrame.u8Data[1] = gu8CallPoint[CALL_POINT_ADDRESS]; /*id*/
        gsTransmissionFrame.u8Data[2] = gu8CallPoint[callPointRoomID]; /*Room ID*/
        gsTransmissionFrame.u8Data[3] = gu8CallPoint [callPointRoomA]; /*RA*/
        gsTransmissionFrame.u8Data[4] = gu8CallPoint[callPointLastConfig];
        gsTransmissionFrame.u8Data[5] = gu8CallPoint[callPointLastState]; /*last sate*/
        gu8RequestState = WAIT_FOR_RES;
        sysSetPeriodMS(&gsResponseTimeOut, RESPONSE_TIME_OUT);
        sysSetTimer(&gsResponseTimeOut, getSystemTick());
        StartTransmission();
        return;
    }

    if (gu8RequestState == STATE_REQ_CMD) {
        if (bitIsSet(gu8CommFlags, COMM_READ_CENCEL)) {
            gu8RequestState = WAIT_FOR_RES;
            gsTransmissionFrame.u8Address = 0x01; /*all Points Receive*/
            gsTransmissionFrame.u8ByteCount = 2;
            gsTransmissionFrame.u8Data[0] = STATE_REQ_CMD;
            /*read pin dep switch*/
            if (bitIsClear(gu8CommFlags, COMM_REESET_FLAG)) {
                gsTransmissionFrame.u8Data[1] = CENCEL_STATE; /*SW  DATA 1*/
            } else {
                gsTransmissionFrame.u8Data[1] = ACCEPTABLE_STATE; /*SW  DATA 1*/
            }
            sysSetPeriodMS(&gsResponseTimeOut, RESPONSE_TIME_OUT);
            sysSetTimer(&gsResponseTimeOut, getSystemTick());
            StartTransmission();
        } else {
            gu8RequestState = NO_CMD;
        }
        return;
    }
}

void appCommsetCencel() {
    bitSet(gu8CommFlags, COMM_READ_CENCEL);
}

void appCommClearCencel() {
    bitClear(gu8CommFlags, COMM_READ_CENCEL);
}

uint8_t appCommRequestHandle(void) {

    sysSetPeriodMS(&gsResponseTimeOut, PING_TIME_OUT);
    sysSetTimer(&gsResponseTimeOut, getSystemTick());


    if (gsReceiveFrame.u8Data[0] == STATE_REQ_CMD) {
        /*Borad casting CMD D[0]=STATE_RES_CMD  , D[1] = SW_STATE    , D[1] = R_STATE   D[2] = SWID     , D[1] = RID */
        eepromPutByte(START_CALLPOINT_ADDRESS + callPointLastState, gsReceiveFrame.u8Data[4]);
        gu8CallPoint[callPointLastState] = gsReceiveFrame.u8Data[4];
        gsTransmissionFrame.u8Address = 0x01; /*all Points Receive*/
        gsTransmissionFrame.u8ByteCount = 3;
        gsTransmissionFrame.u8Data[0] = STATE_RES_CMD;
        gsTransmissionFrame.u8Data[1] = gsReceiveFrame.u8Address; /*SW ADDRESS*/
        gsTransmissionFrame.u8Data[2] = gu8CallPoint[callPointLastState]; /*SW  DATA 1*/
        StartTransmission();
        return (1);
    }
    return (1);
}

void appCommSetPoint() {
    for (uint8_t i = 0; i < 4; i++) {
        eepromPutByte(i, 0x00);
    }
    gu8CallPoint[callPointID] = 102;
    gu8CallPoint[callPointRoomID] = 101;
    gu8CallPoint[callPointRoomA] = 0x02;
    gu8CallPoint[callPointLastConfig] = 0x01;
    gu8CallPoint[callPointLastState] = 0x00;
    for (uint8_t i = callPointTime; i < CALL_POINT_LENGTH; i++)
        gu8CallPoint[i] = 0x00;

    for (uint8_t i = 0; i < CALL_POINT_LENGTH; i++) {
        eepromPutByte(START_CALLPOINT_ADDRESS + i, gu8CallPoint[i]);
    }

}

void appcommInit() {
    for (uint8_t i = 0; i < 4; i++)
        gu8CallPoint[i] = eepromGetByte(i);
    if (!gu8CallPoint[0]&&!gu8CallPoint[1]&&!gu8CallPoint[2]&&!gu8CallPoint[3]) {
        for (uint8_t i = 0; i < CALL_POINT_LENGTH; i++) {
            gu8CallPoint[i] = eepromGetByte(START_CALLPOINT_ADDRESS + i);
        }
    } else {
        appCommSetPoint();
    }
    OnHostFrame(appCommRequestHandle);
    OnClientFrame(appCommClinentResponse);
    gu8RequestState = NO_CMD;
    byteBufferInit(&gstRequest, gu8appRequest, REQ_LENGTH);
    gu8CommFlags = 0;
    appCommResetButton();
}

uint8_t appCommClinentResponse() {
    if (gsReceiveFrame.u8Data[0] == PING_RES_CMD) {
        if (appPingResPonse()) {
            /*Ping */
            sysSetPeriodMS(&gsResponseTimeOut, PING_TIME_OUT);
            sysSetTimer(&gsResponseTimeOut, getSystemTick());
            return (1);
        }
    }

    if (gsReceiveFrame.u8Data[0] == PING_STATE_RES_CMD || (gsReceiveFrame.u8Data[0] == CONFIG_RES_CMD)) {
        if (appCommFree()) {
            gu8RequestState = NO_CMD;
            /*Ping */
            sysSetPeriodMS(&gsResponseTimeOut, PING_TIME_OUT);
            sysSetTimer(&gsResponseTimeOut, getSystemTick());
            return (1);
        }
    }

    if (gsReceiveFrame.u8Data[0] == CONFRAM_STATE_CMD) {
        if (bitIsClear(gu8CommFlags, COMM_REESET_FLAG)) {
            gu8CallPoint[callPointLastState] = CENCEL_STATE;
        } else {
            gu8CallPoint[callPointLastState] = ACCEPTABLE_STATE;
        }
        eepromPutByte(START_CALLPOINT_ADDRESS + callPointLastState, gu8CallPoint[callPointLastState]);
        appCommFree();
        gu8RequestState = NO_CMD;
        return (1);
    }
    return (0);
}

/*send Request */

uint8_t getcommStateCMD() {
    return gu8RequestState;
}

uint8_t getState() {
    return gu8CallPoint[callPointLastState];
}