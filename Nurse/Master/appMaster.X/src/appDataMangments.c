/*
 * File:   appDataMangments.c
 * Author: Hassan
 *
 * Created on August 2, 2022, 4:08 PM
 */

#include <stdint.h>

#include "../inc/appDataMangments.h"
#if APP_MENUE 
stExeeprom_t gstExeeprom;


/*Call Backs Function*/



#define  APP_MENU_MEM_MAX_DIGITS              (3)
volatile uint8_t gu8appErrorCode;
volatile uint8_t gu8appLastConfig;
volatile uint8_t gu8appMemIndex;
volatile uint8_t gu8appMemZoneDevice;


uint8_t gu8appZone[MAX_ZONE_DATA];
uint8_t gu8callPoint[MAX_POINT_DATA];
uint8_t gu8PointsData[MAX_BASE_DATA_CONFIG][2];
uint8_t getZoneDeviceAddress(uint8_t *buf, uint8_t address);


void appMemEvents();
void appMemRemoveEvent();
void appMemEraseEvent();


uint8_t appMemRease(uint8_t offset);
uint8_t appMemPointConfig(uint8_t Index);
uint8_t appMemRemoveConfig(uint8_t Index);
uint8_t appMemValidtionConfig(uint8_t *structValid);
uint8_t appMemGetAddress(uint8_t Address);

void appMemInit() {
    gu8appMemIndex = 0;
    gu8appErrorCode = 0;
    gu8appLastConfig = 0;
    gu8appMemZoneDevice = 0;
}

uint8_t getZoneDeviceAddress(uint8_t *buf, uint8_t address) {
    for (uint8_t i = (address / MAX_ZONE_DATA); i < MAX_ZONE_DATA; i++) {
        for (uint8_t j = (address % MAX_ZONE_DATA); j < 8; j++) {
            if (buf[i]&(1 << j)) {
                return ( i * 8 + j);
            }
        }
    }
    return (0);
}

uint8_t appMemCreateZone() {
    char s1[3];
    uint8_t u8Event;
    uint8_t nByte;
    uint8_t nBit;


    if (gu8appMenueState == 0x00) {
        /*show data*/
        appEventSetStart(0);
        gu8appMemIndex = 0;
        gu8appMemZoneDevice = 0;
        lcdClear();
        lcdwrite(0, 0, "ZID");
        lcdwrite(0, 12, "ADD");
        bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
        bitClear(gu8MnueFlags, APP_MEM_ZONE_ENTER);
        bitSet(gu8MnueFlags, APP_MEM_ZONE_EVENT);
        /*show data*/
        gu8appMenueState = 0x01;
        return (0);
    }

    if (!appMenuIsLCDReady())
        return (0);

    if (gu8appMenueState == 0x01) {
        /*load current zone*/
        if (appMemLoadDate(gu8appZone, MAX_ZONE_DATA, ((gu8appMemIndex * MAX_ZONE_DATA) + START_ZONE_ADDRESS), 0)) {
            gu8appMenueState = 0x02; /*show*/
        }
        return (0);
    }

    if (gu8appMenueState == 0x02) {

        nByte = (gu8appMemZoneDevice / MAX_ZONE_DATA);
        nBit = (gu8appMemZoneDevice % MAX_ZONE_DATA);
        if (bitRead(gu8appZone[nByte], nBit)) {
            /*show this address*/
            lcdClearlines(1);
            sprintf(s1, "%03d", gu8appMemIndex);
            lcdwrite(1, 0, s1);
            sprintf(s1, "%03d", gu8appMemZoneDevice);
            lcdwrite(1, 12, s1);
            bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
            gu8appMenueState = 0x03; /*action new data*/
            return (0);
        }
        if (gu8appMemZoneDevice < MEM_MAX_VALUE) {
            gu8appMemZoneDevice++;
            return (0);
        }
        if (gu8appMemIndex < MAX_ZONE) {
            gu8appMemIndex++;
            gu8appMemZoneDevice = 0;
            gu8appMenueState = 0x01; /*load new data*/
        } else {
            gu8appMemIndex = 0;
            gu8appMemZoneDevice = 0;
            gu8appMenueState = 0x00; /*load new data*/
            /*check no data*/
            if (bitIsSet(gu8MnueFlags, APP_MEM_ZONE_ENTER)) {
                bitClear(gu8MnueFlags, APP_MEM_ZONE_ENTER);
                return (1);
            }
            lcdwrite(1, 0, "000");
            lcdwrite(1, 12, "000");
            bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
            gu8appMenueState = 0x03; /*action new data*/
        }
        return (0);
    }

    if (gu8appMenueState == 0x03) {
        /*read event*/
        appMemEvents();
        u8Event = appMenuReadEvents();
        if (u8Event == 0x01) {
            appMenuClearEvent();
            appMenueCloseEvent();
            gu8appMenueState = 0;
            gu8appMemIndex = 0;
            gu8appMemZoneDevice = 0;
            return (1);
        }

        if (u8Event == 0x02) {

            /*set data and save*/
            getlcdData(s1, 1, 0);
            gu8appMemIndex = uStringToNumber(s1);
            getlcdData(s1, 1, 12);
            gu8appMemZoneDevice = uStringToNumber(s1);
            if (!gu8appMemZoneDevice) {
                /*error*/
                lcdClear();
                lcdwrite(0, LCD_TEXT_CENTER, "Invalid Address");
                lcdwrite(1, LCD_TEXT_CENTER, "Enter Valid key");
                bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
                bitsValue(gu8MnueFlags, 0x04, APP_MENU_EVENT_RESPONS);
                return (0);
            }
            if (gu8PointsData[gu8appMemZoneDevice][0] < 255) {
                gu8PointsData[gu8appMemZoneDevice][0] += gu8appMemZoneDevice;
            } else {
                gu8PointsData[gu8appMemZoneDevice][0] = gu8appMemZoneDevice;
            }
            /*load data*/


            gu8callPoint[0] = (gu8appMemZoneDevice / MAX_ZONE_DATA);
            gu8callPoint[1] = (gu8appMemZoneDevice % MAX_ZONE_DATA);
            gu8callPoint[2] = (gu8callPoint[0] | (1 << gu8callPoint[1]));
            bitsValue(gu8MnueFlags, 0x06, APP_MENU_EVENT_RESPONS);
            return (0);
        }

        if (u8Event == 0x03 || u8Event == 0x04)
            return (0);
        if (u8Event == 0x05) {
            appMenueCloseEvent();
            gu8appMenueState = 0;
            gu8appMemIndex = 0;
            gu8appMemZoneDevice = 0;
            return (0);
        }

        if (u8Event == 0x06) {
            if (!gu8appErrorCode) {
                /*save current Index*/
                if (appMemSaveDate(&gu8PointsData[gu8appMemZoneDevice][0], 1, ((gu8appMemZoneDevice * MAX_POINT_DATA) + MAX_POINTS_ADDRESS), lastConfig)) {
                    gu8appErrorCode = 1;
                }
                return (0);
            }
            /*load current Index*/
            if (bitIsClear(gu8MnueFlags, APP_MEM_ZONE_READ)) {
                if (appMemLoadDate(&gu8callPoint[3], 1, ((gu8appMemIndex * MAX_ZONE_DATA) + START_ZONE_ADDRESS), gu8callPoint[0])) {
                    gu8callPoint[3] |= gu8callPoint[2];
                    bitSet(gu8MnueFlags, APP_MEM_ZONE_READ);
                }
                return (0);
            }


            if (appMemSaveDate(&gu8callPoint[3], 1, ((gu8appMemIndex * MAX_ZONE_DATA) + START_ZONE_ADDRESS), gu8callPoint[0])) {
                gu8ErrorCode = 0;
                appMenuClearEvent();
                appMenueCloseEvent();
                bitSet(gu8MnueFlags, APP_MEM_ZONE_ENTER);
                if (appEventGetEventNumber() < 3) {
                    gu8appMemIndex++;
                    gu8appMenueState = 0x01;
                } else {
                    gu8appMenueState = 0x02;
                    gu8appMemZoneDevice++;
                }
                return (0);
            }
            return (0);
        }
        return (0);
    }
    return (0);
}

uint8_t appMemCreatePoint() {
    char s1[3];
    if (!gu8appMenueState) {
        lcdClear();

        appEventSetStart(0);
        gu8appMemIndex = appMemNext(gu8appMemIndex);
        if (gu8appMemIndex == 0xFF) {
            gu8appMemIndex = 0;
        }
        /*load this data of next*/
        if (appMemLoadDate(gu8callPoint, 2, ((gu8appMemIndex * MAX_POINT_DATA) + MAX_POINTS_ADDRESS), 0)) {
            /*load data of the current Index*/
            const char *s = "ADD   IDD   ROA";
            lcdwrite(0, 0, s);
            sprintf(s1, "%03d", gu8appMemIndex);
            lcdwrite(1, 0, s1);
            sprintf(s1, "%03d", gu8callPoint[0]); /*ID*/
            lcdwrite(1, 6, s1);
            sprintf(s1, "%03d", gu8callPoint[1]); /*RA*/
            lcdwrite(1, 12, s1);
            gu8appLastConfig = gu8PointsData[gu8appMemIndex][0];
            gu8appMenueState = 1;
            bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
            bitClear(gu8MnueFlags, APP_MEM_ZONE_EVENT);
        }
    }
    if (!appMenuIsLCDReady()) {
        return (0);
    }
    appMemEvents();
    switch (appMenuReadEvents()) {
        case 0x00:/*no action*/
            break;
        case 0x01:/*clear*/
            appMenuClearEvent();
            appMenueCloseEvent();
            gu8appMenueState = 0;
            gu8appMemIndex = 0;
            return (1);
            break;
        case 0x02:/*save and fined next value*/
            getlcdData(s1, 1, 0);
            gu8callPoint[2] = (uint8_t) uStringToNumber(s1); /*address*/
            getlcdData(s1, 1, 6);
            gu8callPoint[0] = (uint8_t) uStringToNumber(s1); /*id*/
            getlcdData(s1, 1, 12);
            gu8callPoint[1] = (uint8_t) uStringToNumber(s1); /*room add*/
            gu8appErrorCode = appMemValidtionConfig(gu8callPoint);
            if (!gu8appErrorCode) {
                /*save memory*/
                gu8appMemIndex = gu8callPoint[2];
                if (gu8appLastConfig < 255) {
                    gu8appLastConfig += gu8appMemIndex;
                } else {
                    gu8appLastConfig = gu8appMemIndex;
                }
                gu8callPoint[2] = (gu8appLastConfig);
                /*encode Index and gu8callPoint*/
                bitsValue(gu8MnueFlags, 0x06, APP_MENU_EVENT_RESPONS);
            } else {
                /*Error case */
                lcdClear();
                lcdNoBlink();
                switch (gu8appErrorCode) {
                    case MEM_DONE:
                        break;
                    case MEM_ERROR_INVLIAD_ADD:
                        lcdwrite(0, LCD_TEXT_CENTER, "Invalid Address");
                        break;
                    case MEM_ERROR_INVLIAD_RA:
                        lcdwrite(0, LCD_TEXT_CENTER, "Invalid Room");
                        break;
                    case MEM_ERROR_INVLID_DSA:
                        lcdwrite(0, LCD_TEXT_CENTER, "Invalid Display");
                        break;
                    case MEM_ERROR_BLOCKED_ADDRESS:
                        lcdwrite(0, LCD_TEXT_CENTER, "Address Blocked");
                        break;
                    case MEM_ERROR_RA_NOT_FOUND:
                        lcdwrite(0, LCD_TEXT_CENTER, "Undefined Room");
                        break;
                    case MEM_ERROR_DA_NOT_FOUND:
                        lcdwrite(0, LCD_TEXT_CENTER, "Undefined Display");
                        break;
                    default:
                        gu8appErrorCode = MEM_DONE;
                        gu8appMenueState = 0;
                        return (1);
                        break;
                }
                lcdwrite(1, LCD_TEXT_CENTER, "Enter Valid Key");
                bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
                bitsValue(gu8MnueFlags, 0x04, APP_MENU_EVENT_RESPONS);
            }
            break;
        case 0x03:/*find current and show data is found*/
            /*check the start address*/
            if (appEventGetEventNumber() > 3)
                return (0);
            /*get address and find my data*/
            getlcdData(s1, 1, 0);
            gu8callPoint[2] = (uint8_t) uStringToNumber(s1); /*address*/
            if (gu8PointsData[gu8callPoint[2]][0] == 0) {
                appMenuClearEvent();
                return (0);
            }

            if (appMemLoadDate(gu8callPoint, 2, ((gu8callPoint[2] * MAX_POINT_DATA) + MAX_POINTS_ADDRESS), ID)) {
                appMenuClearEvent();
                /*load data of the current Index*/
                sprintf(s1, "%03d", gu8callPoint[0]); /*ID*/
                lcdwrite(1, 6, s1);
                sprintf(s1, "%03d", gu8callPoint[1]); /*ROA*/
                lcdwrite(1, 12, s1);
                gu8appMemIndex = gu8callPoint[2];
                bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
            }
            break;
        case 0x04:/*no-action*/
            break;
        case 0x05:/*mem error*/
            gu8appMenueState = 0;
            appMenuClearEvent();
            break;
        case 0x06:/*save and fined next value*/
            if (appMemSaveDate(gu8callPoint, 3, ((gu8appMemIndex * MAX_POINT_DATA) + MAX_POINTS_ADDRESS), 0)) {
                gu8PointsData[gu8appMemIndex][0] = gu8appLastConfig; /*save last config*/
                gu8appMenueState = 0;
                appMenuClearEvent();
                gu8appMemIndex++;
                if (appMemNext(gu8appMemIndex) == 0xFF) {
                    gu8appMemIndex = 0;
                    gu8ErrorCode = 0;
                    return (1);
                }
            }
            break;
        case 0x07:/*remove current A*/
            if (gu8PointsData[gu8appMemIndex][0] == 0x00) {
                appMenuClearEvent();
                return (0);
            }
            for (uint8_t i = 0; i < MAX_POINT_DATA; i++)
                gu8callPoint[i] = 0x00;
            if (appMemSaveDate(gu8callPoint, 10, ((gu8appMemIndex * MAX_POINT_DATA) + MAX_POINTS_ADDRESS), 0)) {
                gu8PointsData[gu8appMemIndex][0] = 0x00; /*save last config*/
                gu8PointsData[gu8appMemIndex][1] = 0x00; /*save last config*/
                gu8appMenueState = 0;
                appMenuClearEvent();
                gu8appMemIndex--;
                if (appMemNext(gu8appMemIndex) == 0xFF) {
                    gu8appMemIndex = 0;
                    gu8ErrorCode = 0;
                    return (1);
                }
            }
            break;
        default:
            break;
    }
    return (0);
}

uint8_t appMemoryStart() {
    uint8_t pre;
    char s[16];
    switch (gu8appMenueState) {
        case 0:
            if (appMemLoadDate(gu8callPoint, 9, 0x0000, 0)) {
                if (!gu8callPoint[0]&&
                        !gu8callPoint[1]&&
                        !gu8callPoint[2]&&
                        !gu8callPoint[3]&&
                        !gu8callPoint[4]&&
                        !gu8callPoint[5]&&
                        !gu8callPoint[6]&&
                        !gu8callPoint[7]&&
                        !gu8callPoint[8]
                        ) {
                    return (1);
                } else {
                    for (uint8_t i = 0; i < MAX_POINT_DATA; i++) {
                        gu8callPoint[i] = 0x00;
                    }
                    gu8appMenueState = 1;
                }
            }
            break;
        case 1:
            if (appMemSaveDate(gu8callPoint, MAX_POINT_DATA, ((gu8appMemIndex * MAX_POINT_DATA) + MAX_POINTS_ADDRESS), 0)) {
                if (gu8appMemIndex < 128) {
                    gu8PointsData[gu8appMemIndex][0] = 0x00;
                    gu8PointsData[gu8appMemIndex][1] = 0x00;
                    lcdClear();
                    pre = ((gu8appMemIndex * 100) / 128);
                    sprintf(s, "Memory Init  %02d", pre);
                    s[15] = '%';
                    lcdwrite(0, 0, s);
                    updateProgressBar(pre, 100, 1);
                    gu8appMemIndex++;
                    bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
                } else {
                    gu8appMemIndex = 0;
                    gu8appMenueState = 0;
                    gu8appMenueState = 2;
                }
            }
            break;
        case 2:
            if (appMemSaveDate(gu8callPoint, 8, ((gu8appMemIndex * (8)) + START_ZONE_ADDRESS), 0)) {
                if (gu8appMemIndex < MAX_ZONE_DATA * MAX_ZONE) {
                    gu8PointsData[gu8appMemIndex][1] = 0x00;
                    lcdClear();
                    pre = ((gu8appMemIndex * 100) / (MAX_ZONE_DATA * MAX_ZONE));
                    sprintf(s, "Zone Init %02d", pre);
                    s[15] = '%';
                    lcdwrite(0, 0, s);
                    updateProgressBar(pre, 100, 1);
                    gu8appMemIndex++;
                    bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
                } else {
                    gu8appMemIndex = 0;
                    gu8appMenueState = 0;
                    return (1);
                }
                break;
            }
        default:
            break;


    }
    return (0);

}

uint8_t appMemPowerOn() {
    uint8_t pre;
    char s[16];
    if (!appMenuIsLCDReady()) {
        return (0);
    }
    if (gu8appMemIndex < MAX_BASE_DATA_CONFIG) {
        if (appMemLoadDate(gu8callPoint, 2, ((gu8appMemIndex * MAX_POINT_DATA) + MAX_POINTS_ADDRESS), lastConfig)) {
            gu8PointsData[gu8appMemIndex][0] = gu8callPoint[0]; /*last config */
            gu8PointsData[gu8appMemIndex][1] = gu8callPoint[1]; /*last state*/

            lcdClear();
            pre = ((gu8appMemIndex * 100) / 128);
            sprintf(s, "Load Memory  %02d", pre);
            s[15] = '%';
            lcdwrite(0, 0, s);
            updateProgressBar(pre, 100, 1);
            gu8appMemIndex++;
            bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
        }
    } else {
        gu8appMemIndex = 0;
        return (1);
    }

    return (0);
}

void appMemEvents() {
    uint8_t u8Event;
    u8Event = keypadGetEvent();
    if (u8Event == KEYPAD_NOT_AN_EVENT) {
        return;
    }
    if (appEventNumber(u8Event, "0", KEYPAD01_PRESS(KEYPAD_SW0), APP_MENU_MEM_MAX_DIGITS))
        return;
    if (appEventNumber(u8Event, "1", KEYPAD01_PRESS(KEYPAD_SW1), APP_MENU_MEM_MAX_DIGITS))
        return;
    if (appEventNumber(u8Event, "2", KEYPAD01_PRESS(KEYPAD_SW2), APP_MENU_MEM_MAX_DIGITS))
        return;
    if (appEventNumber(u8Event, "3", KEYPAD01_PRESS(KEYPAD_SW3), APP_MENU_MEM_MAX_DIGITS))
        return;
    if (appEventNumber(u8Event, "4", KEYPAD01_PRESS(KEYPAD_SW4), APP_MENU_MEM_MAX_DIGITS))
        return;
    if (appEventNumber(u8Event, "5", KEYPAD01_PRESS(KEYPAD_SW5), APP_MENU_MEM_MAX_DIGITS))
        return;
    if (appEventNumber(u8Event, "6", KEYPAD01_PRESS(KEYPAD_SW6), APP_MENU_MEM_MAX_DIGITS))
        return;
    if (appEventNumber(u8Event, "7", KEYPAD01_PRESS(KEYPAD_SW7), APP_MENU_MEM_MAX_DIGITS))
        return;
    if (appEventNumber(u8Event, "8", KEYPAD01_PRESS(KEYPAD_SW8), APP_MENU_MEM_MAX_DIGITS))
        return;
    if (appEventNumber(u8Event, "9", KEYPAD01_PRESS(KEYPAD_SW9), APP_MENU_MEM_MAX_DIGITS))
        return;
    /*cencel Event*/
    if (appEventCencel(u8Event, KEYPAD01_PRESS(KEYPAD_SW_CENCEL)))return;
    /*Enter Event*/
    if (appEventEnter(u8Event, KEYPAD01_PRESS(KEYPAD_SW_ENTER)))return;
    /*Move Event*/
    if (bitIsSet(gu8MnueFlags, APP_MEM_ZONE_EVENT)) {
        if (appEventMove(u8Event, KEYPAD01_PRESS(KEYPAD_SW_MODE), 12, 0, APP_MENU_MEM_MAX_DIGITS))return;
    } else {
        if (appEventMove(u8Event, KEYPAD01_PRESS(KEYPAD_SW_MODE), 6, 0, APP_MENU_MEM_MAX_DIGITS))return;
    }
    /*Remove Event*/
    if (appEventRemove(u8Event, KEYPAD01_PRESS(KEYPAD_SW_F1), APP_MENU_MEM_MAX_DIGITS))return;
    /*up Event*/
    if (appEventUp(u8Event, KEYPAD01_PRESS(KEYPAD_SW_F2), APP_MENU_MEM_MAX_DIGITS))return;
    /*Down Event*/
    if (appEventDown(u8Event, KEYPAD01_PRESS(KEYPAD_SW_F3), APP_MENU_MEM_MAX_DIGITS))return;

    if (u8Event == KEYPAD01_LONGPRESS(KEYPAD_SW_F1)) {
        /*remove state*/
        bitsValue(gu8MnueFlags, 0x07, APP_MENU_EVENT_RESPONS);
    }

}

uint8_t appMemSaveDate(uint8_t *structSave, uint8_t length, uint16_t address, uint8_t offset) {
    /*this function only used */
    if (exEEPROMSave(&gstExeeprom, MEM_BASE_ADDRESS, address + offset, structSave, length)) {

        return (1);
    }
    return (0);
}

uint8_t appMemLoadDate(uint8_t *structLoad, uint8_t length, uint16_t address, uint8_t offset) {
    if (exEEPROMLoad(&gstExeeprom, MEM_BASE_ADDRESS, address + offset, structLoad, length)) {

        return (1);
    }
    return (0);
}

uint8_t appMemValidtionConfig(uint8_t * structValid) {
    uint8_t errorCode;

    errorCode = MEM_DONE;

    if ((structValid[2] >= MAX_BASE_DATA_CONFIG) || (!structValid[2])) {
        errorCode = MEM_ERROR_INVLIAD_ADD;
        return errorCode;
    }



    if (structValid[1] >= 128) {
        errorCode = MEM_ERROR_INVLIAD_RA;
        return errorCode;
    }


    if ((gu8PointsData[structValid[2]][0] != 0) && (gu8appMemIndex != structValid[2])) {
        /*address Blocked*/
        errorCode = MEM_ERROR_BLOCKED_ADDRESS;
        return errorCode;
    }



    if (structValid[1] == 0 && structValid[0] == 0) {
        return errorCode; /*as display*/
    }

    if (structValid[1] != 0 && structValid[1] < MAX_BASE_DATA_CONFIG) {
        /*this Point as a callPoint*/
        if (gu8PointsData[structValid[1]][0] == 0) {
            /*address room address not created*/
            errorCode = MEM_ERROR_RA_NOT_FOUND;

            return errorCode;
        }
    }
    return errorCode;
}

void appMemRemoveEvent() {
    /*cencel Event*/
    uint8_t u8Event;
    u8Event = keypadGetEvent();
    if (u8Event == KEYPAD_NOT_AN_EVENT) {
        return;
    }
    if (appEventCencel(u8Event, KEYPAD01_PRESS(KEYPAD_SW_CENCEL)))return;
    /*Enter Event*/
    if (appEventEnter(u8Event, KEYPAD01_PRESS(KEYPAD_SW_ENTER)))return;

    if (u8Event == KEYPAD01_PRESS(KEYPAD_SW0)) {
        bitsValue(gu8MnueFlags, 0x03, APP_MENU_EVENT_RESPONS);

        return;
    }

}

uint8_t appMemEraseZone() {
    char s[16];
    uint8_t pre;
    uint8_t u8Event;
    if (!gu8appMenueState) {
        /*Please Enter Valid Data*/
        lcdClear();
        lcdNoBlink();
        gu8appMemIndex = 0;
        lcdwrite(0, LCD_TEXT_CENTER, "Please Enter");
        lcdwrite(1, LCD_TEXT_CENTER, "Confirmed Key");
        bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
        gu8appMenueState = 1;
        return (0);
    }

    if (!appMenuIsLCDReady()) {
        return (0);
    }
    appMemRemoveEvent();
    u8Event = appMenuReadEvents();
    if ((u8Event == 0x04) || (u8Event == 0x00) || (u8Event == 0x03))
        return (0);

    if (u8Event == 0x01) {
        appMenuClearEvent();
        appMenueCloseEvent();
        gu8appMenueState = 0;

        return (1);
    }

    if (u8Event == 0x02) {
        for (uint8_t i = 0; i < 8; i++) {
            gu8callPoint[i] = 0x00;
        }

        if (appMemSaveDate(gu8callPoint, 8, ((gu8appMemIndex * (8)) + START_ZONE_ADDRESS), 0)) {
            if (gu8appMemIndex < MAX_ZONE_DATA * MAX_ZONE) {
                gu8PointsData[gu8appMemIndex][1] = 0x00;
                lcdClear();
                pre = ((gu8appMemIndex * 100) / (MAX_ZONE_DATA * MAX_ZONE));
                sprintf(s, "Removing     %02d", pre);
                s[15] = '%';
                lcdwrite(0, 0, s);
                updateProgressBar(pre, 100, 1);
                gu8appMemIndex++;
                bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
            } else {
                gu8appMemIndex = 0;
                appMenuClearEvent();
                appMenueCloseEvent();
                gu8appMenueState = 0;

                return (1);
            }
        }
    }
    return (0);
}

uint8_t appMemGetAddress(uint8_t Address) {
    if (gu8PointsData[Address][0] != 0)

        return (1);
    return (0);
}

uint8_t appgetLastAddress() {
    uint8_t last;
    last = 0;
    for (uint8_t i = 0; i < 128; i++) {

        if (gu8PointsData[i][0] != 0)
            last = i;
    }

    return last;
}

uint8_t appMemRease(uint8_t offset) {
    char s[16];
    uint8_t pre;
    uint8_t u8Event;
    if (!gu8appMenueState) {
        /*Please Enter Valid Data*/
        lcdClear();
        lcdNoBlink();
        gu8appMemIndex = 0;
        lcdwrite(0, LCD_TEXT_CENTER, "Please Enter");
        lcdwrite(1, LCD_TEXT_CENTER, "Confirmed Key");
        bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
        gu8appMenueState = 1;
        return (0);
    }

    if (!appMenuIsLCDReady()) {
        return (0);
    }
    appMemRemoveEvent();
    u8Event = appMenuReadEvents();
    if ((u8Event == 0x04) || (u8Event == 0x00) || (u8Event == 0x03))
        return (0);

    if (u8Event == 0x01) {
        appMenuClearEvent();
        appMenueCloseEvent();
        gu8appMenueState = 0;
        return (1);
    }

    if (u8Event == 0x02) {
        for (uint8_t i = 0; i < MAX_POINT_DATA - offset; i++) {
            gu8callPoint[i] = 0x00;
        }

        if (appMemSaveDate(gu8callPoint, MAX_POINT_DATA - offset, ((gu8appMemIndex * MAX_POINT_DATA) + MAX_POINTS_ADDRESS), offset)) {
            if (gu8appMemIndex < 128) {
                if (offset == 0x00) {
                    gu8PointsData[gu8appMemIndex][0] = 0x00;
                }

                gu8PointsData[gu8appMemIndex][1] = 0x00;
                lcdClear();
                pre = ((gu8appMemIndex * 100) / 128);
                sprintf(s, "Removing     %02d", pre);
                s[15] = '%';
                lcdwrite(0, 0, s);
                updateProgressBar(pre, 100, 1);
                gu8appMemIndex++;
                bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
                return (0);
            } else {
                gu8appMemIndex = 0;
                appMenuClearEvent();
                appMenueCloseEvent();
                gu8appMenueState = 0;

                return (1);

            }
        }
    }
    return (0);
}

uint8_t appMemEraseConfig() {
    if (appMemRease(0)) {

        return (1);
    }
    return (0);
}

uint8_t appMemEraseData() {
    if (appMemRease(Data1)) {

        return (1);
    }
    return (0);
}

uint8_t appMemNext(uint8_t Address) {
    for (uint8_t i = Address; i < MAX_BASE_DATA_CONFIG; i++) {
        if (gu8PointsData[i][0] != 0) {
            return i;
        }
    }
    return (0xFF); /*not Found Data*/
}

#endif

