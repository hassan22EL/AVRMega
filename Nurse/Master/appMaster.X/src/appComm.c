
/*
 * File:   appComm.c
 * Author: Hassan
 *
 * Created on August 22, 2022, 12:29 PM
 */

#include  "../inc/appComm.h"

#define  REQ_LENGTH          (10) /*5 adddress , 5 request*/
#define  COMM_OK             (0x01)
#define  COMM_NOT_OK         (0x02)


#define  PING_TIME_OUT             2000UL
#define  RESPONSE_TIME_OUT         50


uint8_t gu8appCommRequestState;
uint8_t gu8appCommRequestAddress;
volatile uint8_t gu8appCommPingDataIndex;
volatile uint8_t gu8appCommDataIndex;
volatile uint8_t gu8appCommFlags;
volatile uint8_t gu8appCommFlags2;
volatile uint8_t gu8FramIndex;

#if AS_DISABLED_SYSTEM
volatile uint8_t gu8appComBuzState;

#endif
#define     COMM_TRAFFIC                       (7)
#define     COMM_REESET_FLAG                   (6)
#define     COMM_REQ_ID_ROOM                   (5)
#define     COMM_READY_FLAG                    (4)
#define     COMM_RESPONSE_REQ_STATE            (3)
#define     COMM_DATA_MASK                    (0x07)

/*Flags 2*/

#define     COMM_ZONE_CONFIG_STATE            (0x03)

uint8_t gu8appRequest[REQ_LENGTH];
stTimer_t gsResponseTimeOut;
stByteBufDescriptor_t gstRequest;


void appComm();


uint8_t appCommRequestHandle();
uint8_t appCommClinentResponse();
uint8_t appCommTraffic();
uint8_t appCommZoneConfigSet();
uint8_t appCommFree(void);
uint8_t appLoadZoneConfig();
uint8_t appPingResPonse();
uint8_t appCommConfigRes();


uint8_t appCommRequestGetBuffer(uint8_t *CMD, uint8_t *Address);

uint8_t appCommReadCMD() {
    return gu8appCommRequestState;
}

uint8_t appCommGetBuzzerState() {
    uint8_t i;
    i = 0;
    i = appMemNext(0);
    while (i != 0xFF) {
        if ((gu8PointsData[i][1] == CENCEL_STATE) || (gu8PointsData[i][1] == ACCEPTABLE_STATE)) {
            i++;
            i = appMemNext(i);
        } else {
            /*show Data*/
            return (1);
        }
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

uint8_t appDataResPons() {
    /*
     *************************************************************
     *                         Request Frame                     *
     * ***********************************************************
     *| A | L | STATE_REQ | ID | RID |DA | RA | Last config |state |      *
     * ***********************************************************
     *                     Response Frame                      *
     * *********************************************************
     * | 0xFF| L | STATE_RES | SW_STATE | R_STATE | SW_ID | R_ID  *
     * *********************************************************
     * this response all devices is listen this response and effect data by data required 
     * 
     * steps 
     * 1- save state in address request and save in memory
     **/

    switch (gu8appCommFlags & COMM_DATA_MASK) {
        case 0:
            gu8PointsData[gsReceiveFrame.u8Address][1] = gsReceiveFrame.u8Data[4]; /*assignment data*/
            /*save Room*/
            if (gsReceiveFrame.u8Data[4] >= gu8PointsData[gsReceiveFrame.u8Data[3]][1]) {
                bitsValue(gu8appCommFlags, (0x03), COMM_DATA_MASK);
            } else {
                /*get Largest*/
                bitsValue(gu8appCommFlags, (0x01), COMM_DATA_MASK);
            }
            gu8appMemIndex = 0;
            gu8PointsData[ gsReceiveFrame.u8Data[3]][1] = gsReceiveFrame.u8Data[4]; /*set as Current state*/
            break;
        case 1:/*get Largest Value Of the Room*/
            gu8appMemIndex = appMemNext(gu8appMemIndex);
            if (gu8appMemIndex != 0xFF) {
                bitsValue(gu8appCommFlags, 0x02, COMM_DATA_MASK);
            } else {
                bitsValue(gu8appCommFlags, 0x03, COMM_DATA_MASK);
            }
            break;
        case 2:
            if (appMemLoadDate(gu8callPoint, 1, ((gu8appMemIndex * MAX_POINT_DATA) + MAX_POINTS_ADDRESS), 1)) {
                /*callpoint[0] = RA*/
                if ((gu8callPoint[0] != 0) && (gu8callPoint[0] == gsReceiveFrame.u8Data[3])) {
                    if (gu8PointsData[gu8appMemIndex][1] >= gu8PointsData[gu8callPoint[0]][1]) {
                        gu8PointsData[gsReceiveFrame.u8Data[3]][1] = gu8PointsData[gu8appMemIndex][1];
                    }
                }
                gu8appMemIndex++;
                bitsValue(gu8appCommFlags, 0x01, COMM_DATA_MASK);
            }
            break;
        case 3:/*save call Point In Memory*/
            /*Init Data*/
            /*load data of */
            if (gu8appCommDataIndex == 0) {
                gu8appMemIndex = gsReceiveFrame.u8Data[3];
                gu8callPoint[0] = gu8PointsData[gsReceiveFrame.u8Data[3]][1];

            } else if (gu8appCommDataIndex == 1) {
                gu8appMemIndex = gsReceiveFrame.u8Address;
                gu8callPoint[0] = gsReceiveFrame.u8Data[4]; /*state*/
                gu8PointsData[gsReceiveFrame.u8Address][1] = gsReceiveFrame.u8Data[4];
            }
            for (uint8_t i = 1; i < 5; i++) {
                gu8callPoint[i] |= (rtcGetCurrentTime()>>((i - 2)*8));
            }
            bitsValue(gu8appCommFlags, 0x04, COMM_DATA_MASK);
            break;
        case 4:
            if (appMemSaveDate(gu8callPoint, 5, ((gu8appMemIndex * MAX_POINT_DATA) + MAX_POINTS_ADDRESS), Data1)) {
                gu8appCommDataIndex++;
                if (gu8appCommDataIndex >= 2) {
                    /*call point data*/
                    gu8appCommDataIndex = 0;
                    bitsValue(gu8appCommFlags, 0x00, COMM_DATA_MASK);
                    gu8appMemIndex = 0;
                    return (1);
                }
                bitsValue(gu8appCommFlags, 0x03, COMM_DATA_MASK);
            }
            break;
        default:
            break;
    }
    return (0);
}

uint8_t appCommRequestHandle(void) {
    /*the data is not my data*/
    sysSetPeriodMS(&gsResponseTimeOut, PING_TIME_OUT);
    sysSetTimer(&gsResponseTimeOut, getSystemTick());

    if (gu8PointsData[gsReceiveFrame.u8Address][0] == 0) {
        /*send Point Remove ConfigRequest*/
        appCommRequestPutBuffer(REMOVE_CONFIG_REQ, gsReceiveFrame.u8Address);
        return (1);
    }
    /*handling Requesting*/
    if (gsReceiveFrame.u8Data[0] == STATE_REQ_CMD) {
        if (appDataResPons()) {
            /*send this ResPonse*/
            /*Borad casting CMD D[0]=STATE_RES_CMD  , D[1] = SW_STATE    , D[1] = R_STATE   D[2] = SWID     , D[1] = RID */
            gsTransmissionFrame.u8Address = 0xFF; /*all Points Receive*/
            gsTransmissionFrame.u8ByteCount = 7;
            gsTransmissionFrame.u8Data[0] = STATE_RES_CMD;
            gsTransmissionFrame.u8Data[1] = gsReceiveFrame.u8Address; /*SW ADDRESS*/
            gsTransmissionFrame.u8Data[2] = gu8PointsData[gsReceiveFrame.u8Address][1]; /*SW  DATA 1*/
            gsTransmissionFrame.u8Data[3] = gsReceiveFrame.u8Data[3]; /*Room ADDRESS */
            gsTransmissionFrame.u8Data[4] = gu8PointsData[ gsReceiveFrame.u8Data[3]][1]; /*ROOM DATA 1*/
            gsTransmissionFrame.u8Data[5] = gsReceiveFrame.u8Data[1]; /*DISPLAY DATA SWID*/
            gsTransmissionFrame.u8Data[6] = gsReceiveFrame.u8Data[2]; /*DISPLAY DATA RID*/
            gsTransmissionFrame.u8Data[7] = /*Room ID 2*/
#if AS_DISABLED_SYSTEM
                    gu8appComBuzState = appCommGetBuzzerState();
#endif
            StartTransmission();
            return (1);
        }


    }


    if ((gsReceiveFrame.u8Data[0] == SET_CONFIG_REQ_CMD)) {
        return (1);
    }

    if (gsReceiveFrame.u8Data[0] == POWERON_REQ_CMD) {
        return (1);
    }

    return (0);
}

uint8_t appPingResPonse() {
    uint8_t commState;
    commState = COMM_OK;
    if (appMemSaveDate(&commState, 1, ((gsReceiveFrame.u8Address * MAX_POINT_DATA) + MAX_POINTS_ADDRESS), callcomm)) {
        if (gu8PointsData[gsReceiveFrame.u8Address][0] == 0) {
            appCommRequestPutBuffer(REMOVE_CONFIG_REQ, gsReceiveFrame.u8Address);
            gu8appCommRequestState = NO_CMD;
            return (1);
        }
        if (gu8PointsData[gsReceiveFrame.u8Address][0] != gsReceiveFrame.u8Data[1]) {
            /*set Configuration*/
            appCommRequestPutBuffer(SET_CONFIG_REQ_CMD, gsReceiveFrame.u8Address);
            gu8appCommRequestState = NO_CMD;
            return (1);
        }

        if (gsReceiveFrame.u8Data[2] != 0 && gsReceiveFrame.u8Data[3] != 0) {
            appCommRequestPutBuffer(PING_STATE_REQ_CMD, gsReceiveFrame.u8Address);
            gu8appCommRequestState = NO_CMD;
            return (1);
        }

        if (appCommFree()) {
            gu8appCommRequestState = NO_CMD;
            return (1);
        }
    }
    return (0);
}

uint8_t appCommTestEvent() {
    return (1);
}

uint8_t appCommRepEvent() {

    /*Print not active decvice in this network*/
    return (1);
}

uint8_t appCommRequestGetBuffer(uint8_t *CMD, uint8_t * Address) {
    uint8_t CMDstate, ADDRESSstate;
    ATOMIC_BEGIN
    CMDstate = getByte(&gstRequest, CMD);
    ADDRESSstate = getByte(&gstRequest, Address);
    ATOMIC_END
    if (CMDstate && ADDRESSstate)

        return (1);
    return (0);
}

uint8_t appCommRequestPutBuffer(uint8_t CMD, uint8_t Address) {
    uint8_t CMDstate, ADDRESSstate;
    ATOMIC_BEGIN
    CMDstate = putByte(&gstRequest, CMD);
    ADDRESSstate = putByte(&gstRequest, Address);
    ATOMIC_END
    if (CMDstate && ADDRESSstate)
        return (1);
    return (0);
}

void appCommInit() {
    gu8appCommRequestState = NO_CMD;
    gu8appCommRequestAddress = 0;
    gu8appCommFlags = 0;
    gu8appCommDataIndex = 0;
    gu8appCommPingDataIndex = 0;
    gu8FramIndex = 0;
    gu8appCommFlags2 = 0;
#if AS_DISABLED_SYSTEM
    gu8appComBuzState = 0;
    bitSet(gu8appCommFlags, COMM_REESET_FLAG);
#endif
    byteBufferInit(&gstRequest, gu8appRequest, REQ_LENGTH);
    sysSetPeriodMS(&gsResponseTimeOut, 1);
    sysSetTimer(&gsResponseTimeOut, getSystemTick());
    OnHostFrame(appCommRequestHandle);
    OnClientFrame(appCommClinentResponse);
}

void appCommReady() {
    bitSet(gu8appCommFlags, COMM_READY_FLAG);
}

void appCommNotReady() {
    bitClear(gu8appCommFlags, COMM_READY_FLAG);
}

#if AS_DISABLED_SYSTEM

/*on Buzzer*/
uint8_t appCommRetBuState() {
    return gu8appComBuzState;
}
#endif

uint8_t appCommTraffic() {
    uint8_t u8comm;
    u8comm = COMM_NOT_OK;
    if (bitIsClear(gu8appCommFlags, COMM_TRAFFIC)) {
        gu8appCommPingDataIndex = appMemNext(gu8appCommPingDataIndex);
        if (gu8appCommPingDataIndex != 0xFF) {
            bitSet(gu8appCommFlags, COMM_TRAFFIC);

        } else {
            gu8appCommPingDataIndex = 0;
            bitClear(gu8appCommFlags, COMM_TRAFFIC);
            return (1);
        }
    } else {
        if (appMemSaveDate(&u8comm, 1, ((gu8appCommPingDataIndex * MAX_POINT_DATA) + MAX_POINTS_ADDRESS), 8)) {
            gu8appCommPingDataIndex++;
            bitClear(gu8appCommFlags, COMM_TRAFFIC);
        }
    }

    return (0);
}

void appCommunications() {
    uint8_t nBit;
    uint8_t nByte;
    if (!IsCommunicationOpen())
        return;
    /*wait */
    /*get request from buffer and handel*/
    if (gu8appCommRequestState == NO_CMD) {
        appCommRequestGetBuffer(&gu8appCommRequestState, &gu8appCommRequestAddress);
        if (sysIsTimeout(&gsResponseTimeOut) && bitIsSet(gu8appCommFlags, COMM_READY_FLAG) && gu8appCommRequestState == NO_CMD) {
            if (appMemNext(0) != 0xFF) {
                gu8appCommRequestState = PING_REQ_CMD;
                sysSetPeriodMS(&gsResponseTimeOut, PING_TIME_OUT);
                sysSetTimer(&gsResponseTimeOut, getSystemTick());
            }
        }
        return;
    }

    if (gu8appCommRequestState == WAIT_FOR_RES) {
        if (sysIsTimeout(&gsResponseTimeOut)) {
            appCommFree();
            sysSetPeriodMS(&gsResponseTimeOut, PING_TIME_OUT);
            sysSetTimer(&gsResponseTimeOut, getSystemTick());
            gu8appCommRequestState = NO_CMD;

        }
        return;
    }


    if (gu8appCommRequestState == PING_REQ_CMD) {
        if (appCommTraffic()) {
            gu8appCommRequestState = WAIT_FOR_RES;
            gsTransmissionFrame.u8Address = 0xFF; /*all Points Receive*/
            gsTransmissionFrame.u8ByteCount = 5;
            gsTransmissionFrame.u8Data[0] = PING_REQ_CMD;
            for (uint8_t i = 1; i < 5; i++)
                gsTransmissionFrame.u8Data[i] = (rtcGetCurrentTime()) >> ((i - 2)*8); /*sync time with master*/
            sysSetPeriodMS(&gsResponseTimeOut, RESPONSE_TIME_OUT); /*40 ms for response*/
            sysSetTimer(&gsResponseTimeOut, getSystemTick());
            StartTransmission();
            return;
        }
    }

    if (gu8appCommRequestState == PING_STATE_REQ_CMD) {
        gu8appCommRequestState = WAIT_FOR_RES;
        gsTransmissionFrame.u8Address = 0xFF; /*all Points Receive*/
        gsTransmissionFrame.u8ByteCount = 6;
        gsTransmissionFrame.u8Data[0] = PING_STATE_REQ_CMD;
        gsTransmissionFrame.u8Data[1] = gu8appCommRequestAddress;
        gsTransmissionFrame.u8Data[2] = gu8PointsData[gu8appCommRequestAddress][1];
        gsTransmissionFrame.u8Data[3] = gsReceiveFrame.u8Data[2]; /*ID*/
        gsTransmissionFrame.u8Data[4] = gsReceiveFrame.u8Data[4]; /*RID*/
        gsTransmissionFrame.u8Data[5] = 0x00; /*second byte of the room*/
        sysSetPeriodMS(&gsResponseTimeOut, RESPONSE_TIME_OUT); /*40 ms for response*/
        sysSetTimer(&gsResponseTimeOut, getSystemTick());
        StartTransmission();
        return;
    }


    if (gu8appCommRequestState == REMOVE_CONFIG_REQ) {
        gu8appCommRequestState = WAIT_FOR_RES;
        gsTransmissionFrame.u8Address = gu8appCommRequestAddress; /*all Points Receive*/
        gsTransmissionFrame.u8ByteCount = 1;
        gsTransmissionFrame.u8Data[0] = REMOVE_CONFIG_REQ;
        sysSetPeriodMS(&gsResponseTimeOut, RESPONSE_TIME_OUT); /*40 ms for response*/
        sysSetTimer(&gsResponseTimeOut, getSystemTick());
        StartTransmission();
        return;
    }

    if (gu8appCommRequestState == SET_MUTI_CONFIG_REQ_CMD) {
        switch (gu8appCommFlags2 & COMM_ZONE_CONFIG_STATE) {
            case 0:
                gu8appMemZoneDevice = 0;
                gu8FramIndex = 0;
                bitsValue(gu8appCommFlags2, 0x01, COMM_ZONE_CONFIG_STATE);
                break;
            case 1:
                if (appMemLoadDate(gu8appZone, MAX_ZONE_DATA, ((gu8appMemZoneDevice * MAX_ZONE_DATA) + START_ZONE_ADDRESS), 0)) {
                    /*find address*/
                    nByte = (gu8appCommRequestAddress / MAX_ZONE_DATA);
                    nBit = (gu8appCommRequestAddress % MAX_ZONE_DATA);
                    if ((gu8appZone[nByte] & (1 << nBit))) {
                        bitsValue(gu8appCommFlags2, 0x02, COMM_ZONE_CONFIG_STATE);
                    } else {
                        if (gu8appMemZoneDevice < MAX_ZONE) {
                            gu8appMemZoneDevice++;
                        } else {
                            gu8appMemZoneDevice = 0;
                            bitsValue(gu8appCommFlags2, 0x03, COMM_ZONE_CONFIG_STATE);
                        }
                    }
                }
                break;
            case 2:
                /*send data*/
                gsTransmissionFrame.u8Address = gu8appCommRequestAddress;
                if ((MAX_ZONE_DATA - gu8FramIndex) < 6) {
                    gsTransmissionFrame.u8ByteCount = (MAX_ZONE_DATA - gu8FramIndex) + 2;
                } else {
                    gsTransmissionFrame.u8ByteCount = 8;
                }
                gsTransmissionFrame.u8Data[0] = SET_MUTI_CONFIG_REQ_CMD;
                gsTransmissionFrame.u8Data[1] = gu8appMemZoneDevice; /*Zone ID*/
                /*send zone*/
                for (uint8_t i = 2; i < (gsTransmissionFrame.u8ByteCount); i++) {
                    gsTransmissionFrame.u8Data[i] = gu8appZone[gu8FramIndex];
                    gu8FramIndex++;
                }
                gu8appCommRequestState = WAIT_FOR_RES;
                sysSetPeriodMS(&gsResponseTimeOut, RESPONSE_TIME_OUT); /*40 ms for response*/
                sysSetTimer(&gsResponseTimeOut, getSystemTick());
                StartTransmission();
                bitsValue(gu8appCommFlags2, 0x00, COMM_ZONE_CONFIG_STATE);
                break;
            case 3:
                gsTransmissionFrame.u8Address = gu8appCommRequestAddress;
                gsTransmissionFrame.u8ByteCount = 1;
                gsTransmissionFrame.u8Data[0] = SET_MUTI_CONFIG_REQ_CMD_DONE;
                bitsValue(gu8appCommFlags2, 0x00, COMM_ZONE_CONFIG_STATE);
                gu8appCommRequestState = WAIT_FOR_RES;
                sysSetPeriodMS(&gsResponseTimeOut, RESPONSE_TIME_OUT); /*40 ms for response*/
                sysSetTimer(&gsResponseTimeOut, getSystemTick());
                StartTransmission();
                break;
            default:
                bitsValue(gu8appCommFlags2, 0x00, COMM_ZONE_CONFIG_STATE);
                break;

        }
        return;
    }

    if (gu8appCommRequestState == SET_CONFIG_REQ_CMD) {
        /*wait conframed */
        if (bitIsClear(gu8appCommFlags, COMM_REQ_ID_ROOM)) {
            if (appMemLoadDate(gu8callPoint, 2, (((gu8appCommRequestAddress) * MAX_POINT_DATA) + MAX_POINTS_ADDRESS), 0)) {
                if (gu8callPoint[1] == 0 && gu8callPoint[0] == 0) {
                    gsTransmissionFrame.u8Address = gu8appCommRequestAddress; /*all Points Receive*/
                    gsTransmissionFrame.u8ByteCount = 4;
                    gsTransmissionFrame.u8Data[0] = SET_CONFIG_REQ_CMD;
                    gsTransmissionFrame.u8Data[1] = gu8callPoint[0]; /*id*/
                    gsTransmissionFrame.u8Data[2] = gu8callPoint [1]; /*RA*/
                    gsTransmissionFrame.u8Data[3] = gu8PointsData[gu8appCommRequestAddress][0];
                    gu8appCommRequestState = WAIT_FOR_RES;
                    sysSetTimer(&gsResponseTimeOut, getSystemTick());
                    StartTransmission();
                    return;
                }
                gsTransmissionFrame.u8Address = gu8appCommRequestAddress; /*all Points Receive*/
                gsTransmissionFrame.u8ByteCount = 6;
                gsTransmissionFrame.u8Data[0] = SET_CONFIG_REQ_CMD;
                gsTransmissionFrame.u8Data[1] = gu8callPoint[0]; /*id*/
                gsTransmissionFrame.u8Data[2] = 0x00; /*Room ID*/
                gsTransmissionFrame.u8Data[3] = gu8callPoint [1]; /*RA*/
                gsTransmissionFrame.u8Data[4] = gu8PointsData[gu8appCommRequestAddress][0];
                gsTransmissionFrame.u8Data[5] = gu8PointsData[gu8appCommRequestAddress][1]; /*last sate*/
                bitSet(gu8appCommFlags, COMM_REQ_ID_ROOM);
            }
        } else {
            /*load R_ID*/
            if (gsTransmissionFrame.u8Data[3] == 0) {
                /*clear call Point*/
                gu8appCommRequestState = WAIT_FOR_RES;
                sysSetPeriodMS(&gsResponseTimeOut, RESPONSE_TIME_OUT); /*40 ms for response*/
                sysSetTimer(&gsResponseTimeOut, getSystemTick());
                bitClear(gu8appCommFlags, COMM_REQ_ID_ROOM);
                StartTransmission();
                return;
            }
            if (appMemLoadDate(gu8callPoint, 1, (((gsTransmissionFrame.u8Data[3]) * MAX_POINT_DATA) + MAX_POINTS_ADDRESS), 0)) {
                gu8appCommRequestState = WAIT_FOR_RES;
                gsTransmissionFrame.u8Data[2] = gu8callPoint[0]; /*Room ID*/
                /*clear call Point*/
                sysSetTimer(&gsResponseTimeOut, getSystemTick());
                bitClear(gu8appCommFlags, COMM_REQ_ID_ROOM);
                StartTransmission();
            }
        }
        return;
    }

#if AS_DISABLED_SYSTEM
    if (gu8appCommRequestState == STATE_REQ_CMD) {
        /*save this state*/
        gu8appCommRequestState = WAIT_FOR_RES;
        gsTransmissionFrame.u8Address = 0xFF; /*all Points Receive*/
        gsTransmissionFrame.u8ByteCount = 2;
        gsTransmissionFrame.u8Data[0] = STATE_REQ_CMD;
        if (bitIsClear(gu8appCommFlags, COMM_REESET_FLAG)) {
            gsTransmissionFrame.u8Data[1] = CENCEL_STATE;
        } else {
            gsTransmissionFrame.u8Data[1] = ACCEPTABLE_STATE;
        }
        sysSetPeriodMS(&gsResponseTimeOut, RESPONSE_TIME_OUT); /*40 ms for response*/
        sysSetTimer(&gsResponseTimeOut, getSystemTick());
        StartTransmission();
        return;
    }
#endif
}

uint8_t appCommClinentResponse() {

    if (gsReceiveFrame.u8Data[0] == PING_RES_CMD) {
        if (appPingResPonse()) {
            gu8appCommRequestState = NO_CMD;
            sysSetPeriodMS(&gsResponseTimeOut, PING_TIME_OUT);
            sysSetTimer(&gsResponseTimeOut, getSystemTick());
            return (1);
        }
        return (0);
    }




    if ((gsReceiveFrame.u8Data[0] == PING_STATE_RES_CMD) || (gsReceiveFrame.u8Data[0] == REMOVE_CONFIG_RES_CMD) || (gsReceiveFrame.u8Data[0] == SET_MUTI_CONFIG_RES_CMD_DONE)) {
        if (appCommFree()) {
            gu8appCommRequestState = NO_CMD;
            sysSetPeriodMS(&gsResponseTimeOut, PING_TIME_OUT);
            sysSetTimer(&gsResponseTimeOut, getSystemTick());
            return (1);
        }
        return (0);
    }



    if (gsReceiveFrame.u8Data[0] == CONFIG_RES_CMD) {
        if (gsReceiveFrame.u8Data[1] == 0 && gsReceiveFrame.u8Data[2] == 0) {
            appCommRequestPutBuffer(SET_MUTI_CONFIG_REQ_CMD, gsReceiveFrame.u8Address);
            gu8appCommRequestState = NO_CMD;
            /*no free data*/
            return (1);
        } else {
            if (appCommFree()) {
                gu8appCommRequestState = NO_CMD;
                sysSetPeriodMS(&gsResponseTimeOut, PING_TIME_OUT);
                sysSetTimer(&gsResponseTimeOut, getSystemTick());
                return (1);
            }
        }
        return (0);
    }



    if (gsReceiveFrame.u8Data[0] == SET_MUTI_CONFIG_RES_CMD) {

        if (gsReceiveFrame.u8Data[1] != gu8appMemZoneDevice) {
            gu8appMemZoneDevice = gsReceiveFrame.u8Data[1];
        }

        if (gsReceiveFrame.u8Data[2] != gu8FramIndex) {
            gu8FramIndex = gsReceiveFrame.u8Data[2];
        }

        if (gu8FramIndex < MAX_ZONE_DATA) {
            bitsValue(gu8appCommFlags2, 0x02, COMM_ZONE_CONFIG_STATE);
            appCommRequestPutBuffer(SET_MUTI_CONFIG_REQ_CMD, gsReceiveFrame.u8Address);
        } else {
            gu8FramIndex = 0;
            if (gu8appMemZoneDevice < MAX_ZONE) {
                gu8appMemZoneDevice++; /*check second zone*/
                bitsValue(gu8appCommFlags2, 0x01, COMM_ZONE_CONFIG_STATE);
                appCommRequestPutBuffer(SET_MUTI_CONFIG_REQ_CMD, gsReceiveFrame.u8Address);
            } else {
                gu8appMemZoneDevice = 0;
                bitsValue(gu8appCommFlags2, 0x00, COMM_ZONE_CONFIG_STATE);
            }
        }

        gu8appCommRequestState = NO_CMD;
        return (1);
    }






    if (gsReceiveFrame.u8Data[0] == CONFRAM_STATE_CMD) {
        if (bitIsClear(gu8appCommFlags, COMM_RESPONSE_REQ_STATE)) {
            if (bitIsClear(gu8appCommFlags, COMM_REESET_FLAG)) {
                gu8callPoint[0] = CENCEL_STATE;
            } else {
                gu8callPoint[0] = ACCEPTABLE_STATE;

            }
            gu8PointsData[gsReceiveFrame.u8Address][1] = gu8callPoint[0];
            for (uint8_t i = 1; i < 5; i++)
                gu8callPoint[i] = (rtcGetCurrentTime()) >> ((i - 2)*8); /*sync time with master*/
            bitSet(gu8appCommFlags, COMM_RESPONSE_REQ_STATE);
        } else {
            if (appMemSaveDate(gu8callPoint, 5, ((gsReceiveFrame.u8Address * MAX_POINT_DATA) + MAX_POINTS_ADDRESS), Data1)) {
                appCommFree();
                gu8appCommRequestState = NO_CMD;
                bitClear(gu8appCommFlags, COMM_RESPONSE_REQ_STATE);
                /*Ping */
                sysSetPeriodMS(&gsResponseTimeOut, PING_TIME_OUT);
                sysSetTimer(&gsResponseTimeOut, getSystemTick());
                gu8appComBuzState = appCommGetBuzzerState();
                return (1);
            }
        }
    }
    return (0);
}




