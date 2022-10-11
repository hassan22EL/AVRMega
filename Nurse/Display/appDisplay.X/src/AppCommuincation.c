#include <stdint.h>

#include "../inc/AppCommuication.h"

#define    WAIT_RESP         0xFF;
#define    PING_TIME_OUT             5000UL
#define    DISPLAY_START_FLAG          (6)
#define    DISPLAY_SHOW_DATA_WAIT_MASK  (7)
#define    DIPSLAY_SHOW_MASK_EMG     (0x0C)
#define    DISPLAY_SHOW_MASK_NORAML  (0x03)


volatile uint8_t gu8CallPoint[CALL_POINT_LENGTH];
volatile uint8_t gu8RequestState;
volatile uint8_t gu8StartComm;
volatile uint8_t gu8appAddress;
volatile uint8_t gu8TimeIndex;
volatile uint8_t gu8GenralState;
volatile uint8_t gu8ZoneFrameIndex;
volatile uint8_t gu8CurrentIndex;
volatile uint8_t gu8appCommState;
volatile uint8_t gu8Displaydata[MAX_DEVICE][ADDRESS_DATA];

stTimer_t gsPingTimer;



uint8_t appCommGetState(uint8_t Index);
uint8_t gu8ssdData[3];
uint8_t appCommResponse(void);
uint8_t appCommRequestHandle(void);
uint8_t appCommFree(void);
uint8_t appCommStateDone(void);
uint8_t appCallPointDefined(void);
uint8_t findAddressInALLZone(uint8_t u8Address);



void displayloadData();
void appShowDataNormal();
void appShowDataEMG();

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
    if ((gu8StartComm) && gu8CallPoint[callPointLastConfig] != 0) {
        return (1);
    }
    return (0);
}

uint8_t findAddressInALLZone(uint8_t u8Address) {
    /*sync task*/
    uint8_t u8nByte;
    uint8_t u8nBit;
    uint8_t u8ByteData;
    u8nByte = u8Address / ZONE_DATA;
    u8nBit = u8Address % ZONE_DATA;
    for (uint8_t i = 0; i < MAX_ZONE; i++) {
        u8ByteData = eepromGetByte((i * ZONE_DATA) + u8nByte + START_ZONE_ADDRESS);
        if (u8ByteData & (1 << u8nBit)) {
            return (1);
        }
    }
    return (0);
}

uint8_t appCommResponse(void) {
    uint8_t state;
    /*check the call point state*/
    if (gsReceiveFrame.u8Data[0] == STATE_RES_CMD) {
        /*check the address*/
        /*0 CMD 1 SWA 2-SW  STATE 3 RA  4 -RSTATE 5-sw ID 6-Room ID   */
        /*1-search swA i all zone and zone*/
        state = gu8Displaydata[gsReceiveFrame.u8Data[1]][0];
        if (state != DISPLED_STATE) {
            /*save state of the switch in eeprom*/
            gu8TimeIndex = 0;
            gu8appCommState = 0; /*show data*/
            sysSetPeriodMS(&gsPingTimer, 10);
            gu8Displaydata[gsReceiveFrame.u8Data[1]][0] = gsReceiveFrame.u8Data[2];
            gu8Displaydata[gsReceiveFrame.u8Data[1]][1] = gsReceiveFrame.u8Data[5];
            gu8Displaydata[gsReceiveFrame.u8Data[1]][2] = gsReceiveFrame.u8Data[6];
            gu8Displaydata[gsReceiveFrame.u8Data[1]][3] = gsReceiveFrame.u8Data[7];
            gu8CurrentIndex = appCommGetState(gsReceiveFrame.u8Data[1]); /*get General state*/
        }
        return (1);
    }
    /*time */
    return (1);

}

void appcommInit() {
    csmaSetAddress(0x01);
    gu8appAddress = 0x01;
    if (eepromGetByte(START_ZONE_ADDRESS) == 0xFF) {
        for (uint8_t i = START_ZONE_ADDRESS; i < (MAX_ZONE * ZONE_DATA + START_ZONE_ADDRESS); i++) {
            eepromPutByte(i, 0);
        }
    }
    sysSetPeriodMS(&gsPingTimer, 10);
    sysSetTimer(&gsPingTimer, getSystemTick());
    digitalpinMode(GPIO_B0, MODE_OUTPUT);
    gu8CurrentIndex = 0;
    gu8TimeIndex = 0;
    gu8appCommState = 0;
    gu8GenralState = CENCEL_STATE;
    for (uint8_t i = 0; i < CALL_POINT_LENGTH; i++) {
        gu8CallPoint[i] = eepromGetByte(START_CALLPOINT_ADDRESS + i);
    }
    displayloadData();
    OnHostFrame(appCommRequestHandle);
    OnClientFrame(appCommResponse);
    gu8RequestState = NO_CMD;
    gu8StartComm = 0;
}

/*send Request */



uint8_t appCommRequestHandle(void) {
    /*the data is not my data*/
    switch (gsReceiveFrame.u8Data[0]) {
            /*handling Requesting*/
        case STATE_REQ_CMD:
            return (1);
            break;
        case SET_MUTI_CONFIG_REQ_CMD:
            if (IsCommunicationOpen()) {
                for (uint8_t i = 2; i < gsReceiveFrame.u8ByteCount; i++) {
                    eepromPutByte((START_ZONE_ADDRESS + (gsReceiveFrame.u8Data[1] * ZONE_DATA) + (gu8ZoneFrameIndex)), gsReceiveFrame.u8Data[i]);
                    gu8ZoneFrameIndex++;
                }

                gsTransmissionFrame.u8Address = gu8appAddress;
                gsTransmissionFrame.u8ByteCount = 3;
                gsTransmissionFrame.u8Data[0] = SET_MUTI_CONFIG_RES_CMD;
                gsTransmissionFrame.u8Data[1] = gsReceiveFrame.u8Data[1];
                gsTransmissionFrame.u8Data[2] = gu8ZoneFrameIndex;
                StartTransmission();
                return (1);
            }
            break;
        case SET_CONFIG_REQ_CMD:
            if (IsCommunicationOpen()) {
                gu8RequestState = NO_CMD;
                /*store my config is verifiying and start communication*/
                /*put data into */
                for (uint8_t i = 0; i < (gsReceiveFrame.u8ByteCount - 1); i++) {
                    gu8CallPoint[i] = gsReceiveFrame.u8Data[i + 1];
                }

                /*store in EEPROM*/
                for (uint8_t i = 0; i < CALL_POINT_LENGTH; i++) {
                    eepromPutByte(START_CALLPOINT_ADDRESS + i, gu8CallPoint[i]);
                }

                gsTransmissionFrame.u8Address = gu8appAddress;
                gsTransmissionFrame.u8ByteCount = 3;
                gsTransmissionFrame.u8Data[0] = CONFIG_RES_CMD;
                gsTransmissionFrame.u8Data[1] = gu8CallPoint[callPointID]; /*ID*/
                gsTransmissionFrame.u8Data[2] = gsReceiveFrame.u8Data[callPointRoomA]; /*RA*/
                StartTransmission();
                gu8ZoneFrameIndex = 0;
                return (1);
            }
            break;

        case REMOVE_CONFIG_REQ:
            gu8StartComm = 0;
            gu8RequestState = NO_CMD;
            if (IsCommunicationOpen()) {
                /*remove all config*/
                gsTransmissionFrame.u8Address = gu8appAddress;
                gsTransmissionFrame.u8ByteCount = 1;
                gsTransmissionFrame.u8Data[0] = REMOVE_CONFIG_RES_CMD;
                StartTransmission();
                return (1);
            }
            break;
        case PING_REQ_CMD:
            if (IsCommunicationOpen()) {
                ATOMIC_BEGIN
                for (uint8_t i = 1; i < 5; i++) {
                    gu32RTC |= (gsReceiveFrame.u8Data[i]) << ((i - 2)*8); /*sync time with master*/
                }
                appRtcRest();
                ATOMIC_END
                gsTransmissionFrame.u8Address = gu8appAddress;
                gsTransmissionFrame.u8ByteCount = 5;
                gsTransmissionFrame.u8Data[0] = PING_RES_CMD;
                gsTransmissionFrame.u8Data[1] = gu8CallPoint[callPointLastConfig];
                gsTransmissionFrame.u8Data[2] = gu8CallPoint[callPointID];
                gsTransmissionFrame.u8Data[3] = gu8CallPoint[callPointRoomA];
                gsTransmissionFrame.u8Data[4] = 0x00;
                StartTransmission();
                return (1);
            }
            break;
        case PING_STATE_REQ_CMD:
            gu8StartComm = 1;
            if (gu8Displaydata[gsReceiveFrame.u8Data[1]][0] != DISPLED_STATE) {
                /*save state of the switch in eeprom*/
                gu8Displaydata[gsReceiveFrame.u8Data[1]][0] = gsReceiveFrame.u8Data[2];
                gu8Displaydata[gsReceiveFrame.u8Data[1]][1] = gsReceiveFrame.u8Data[3];
                gu8Displaydata[gsReceiveFrame.u8Data[1]][2] = gsReceiveFrame.u8Data[4];
                gu8Displaydata[gsReceiveFrame.u8Data[1]][3] = gsReceiveFrame.u8Data[5];
            }
            return (1);
            break;
        case SET_MUTI_CONFIG_REQ_CMD_DONE:
            displayloadData();
            gu8ZoneFrameIndex = 0;
            gsTransmissionFrame.u8Address = gu8appAddress;
            gsTransmissionFrame.u8ByteCount = 1;
            gsTransmissionFrame.u8Data[0] = SET_MUTI_CONFIG_RES_CMD_DONE;
            StartTransmission();
            return (1);
            break;
        default:
            return (1);
            break;
    }
    return (0);
}

void displayloadData() {
    /*set default*/
    for (uint8_t i = 0; i < MAX_DEVICE; i++) {
        if (findAddressInALLZone(i)) {
            /*find address in all zones*/
            gu8Displaydata[i][0] = CENCEL_STATE;
        } else {
            gu8Displaydata[i][0] = DISPLED_STATE;
        }
    }

}

void displayShowData() {
    gu8CurrentIndex = appCommGetState(gu8CurrentIndex);

    if (gu8GenralState == EMG_STATE) {
        appShowDataEMG();
        return;
    }

    if (gu8GenralState == CALL_STATE) {
        appShowDataNormal();
        return;
    }
    ssdClearWithDefault(CHAR_NEG, 1, 7);
    return;
}

void appShowDataNormal() {
    switch (gu8appCommState) {
        case 0:/*OF state*/
            if (sysIsTimeout(&gsPingTimer)) {
                ssdclearALL();
                sysSetPeriodMS(&gsPingTimer, 500);
                sysSetTimer(&gsPingTimer, getSystemTick());
                gu8appCommState = 1;
            }
            break;
        case 1:/*wait for 2sec sate*/
            if (sysIsTimeout(&gsPingTimer)) {
                u8ToBCD(gu8ssdData, 1, gu8Displaydata[gu8CurrentIndex][1]);
                ssdPrint(gu8ssdData, 1, 3);
                u8ToBCD(gu8ssdData, 3, gu8Displaydata[gu8CurrentIndex][2]);
                ssdPrint(gu8ssdData, 4, 7);
                if (gu8TimeIndex < 1) {
                    gu8TimeIndex++;
                    sysSetPeriodMS(&gsPingTimer, 500);
                    sysSetTimer(&gsPingTimer, getSystemTick());
                    gu8appCommState = 0;
                } else {
                    sysSetPeriodMS(&gsPingTimer, 5000);
                    sysSetTimer(&gsPingTimer, getSystemTick());
                    gu8appCommState = 2;
                }
            }
            break;
        case 2:
            if (sysIsTimeout(&gsPingTimer)) {
                /*get Next Index*/
                if (gu8CurrentIndex < MAX_DEVICE)
                    gu8CurrentIndex++;
                else
                    gu8CurrentIndex = 0;
                gu8appCommState = 1;
                gu8CurrentIndex = appCommGetState(gu8CurrentIndex);
            }
            break;
        default:
            gu8appCommState = 0;
            break;

    }
}

void appShowDataEMG() {
    /**/
    switch (gu8appCommState) {
        case 0:/*OF state*/
            if (sysIsTimeout(&gsPingTimer)) {
                ssdclearALL();
                sysSetPeriodMS(&gsPingTimer, 500);
                sysSetTimer(&gsPingTimer, getSystemTick());
                gu8appCommState = 1;
            }
            break;
        case 1:/*wait for 2sec sate*/
            if (sysIsTimeout(&gsPingTimer)) {
                u8ToBCD(gu8ssdData, 1, gu8Displaydata[gu8CurrentIndex][1]);
                ssdPrint(gu8ssdData, 1, 3);
                u8ToBCD(gu8ssdData, 3, gu8Displaydata[gu8CurrentIndex][2]);
                ssdPrint(gu8ssdData, 4, 7);
                if (gu8TimeIndex < 3) {
                    gu8TimeIndex++;
                    sysSetPeriodMS(&gsPingTimer, 500);
                    sysSetTimer(&gsPingTimer, getSystemTick());
                    gu8appCommState = 0;
                } else {
                    sysSetPeriodMS(&gsPingTimer, 2000);
                    sysSetTimer(&gsPingTimer, getSystemTick());
                    gu8appCommState = 2; /*Next State*/
                }
            }
            break;
        case 2:
            /*flash is fast */
            if (sysIsTimeout(&gsPingTimer)) {
                /*get Next Index*/
                if (gu8CurrentIndex < MAX_DEVICE)
                    gu8CurrentIndex++;
                else
                    gu8CurrentIndex = 0;
                gu8TimeIndex = 0;
                gu8appCommState = 1;
                gu8CurrentIndex = appCommGetState(gu8CurrentIndex);
            }
            break;
        default:
            gu8appCommState = 0;
            break;

    }
}

uint8_t appCommGetState(uint8_t Index) {
    for (uint8_t i = (Index); i < MAX_DEVICE; i++) {
        if (gu8Displaydata[i][0] == EMG_STATE) {
            gu8GenralState = EMG_STATE;
            return (i);
        }
    }

    for (uint8_t i = (0); i < MAX_DEVICE; i++) {
        if (gu8Displaydata[i][0] == EMG_STATE) {
            gu8GenralState = EMG_STATE;
            return (i);
        }
    }
    for (uint8_t i = (Index); i < MAX_DEVICE; i++) {
        if (gu8Displaydata[i][0] == CALL_STATE || gu8Displaydata[i][0] == ACCEPTABLE_STATE) {
            gu8GenralState = CALL_STATE;
            return (i);
        }
    }


    /*can't find from current state */

    for (uint8_t i = (0); i < MAX_DEVICE; i++) {
        if (gu8Displaydata[i][0] == CALL_STATE || gu8Displaydata[i][0] == ACCEPTABLE_STATE) {
            gu8GenralState = CALL_STATE;
            return (i);
        }
    }
    gu8GenralState = CENCEL_STATE;
    return (0); /*NOT FOUND DATA*/

}

