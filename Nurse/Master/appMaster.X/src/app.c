/*
 * File:   main.c
 * Author: Hassan
 *
 * Created on 25 ??????, 2021, 10:06 ?
 */



#include "../inc/app.h"
volatile uint8_t gu8appMasterState;
volatile uint8_t gu8ShowDataIndex;
volatile uint8_t gu8DataShowState;
uint8_t gu8ShowID[3];

void appEvent();
void appCurrentTimeShow();
void appshowData();

void appBoot(void) {

}

void appInit(void) {
    gu8appMasterState = 0;
    appTimeDateInit();
    appEventInit();
    appMemInit();
    appMenuInit();
    appCommInit();
    gu8ShowDataIndex = 0;
    gu8DataShowState = 0;

}

void appSync(void) {

}

void appMain(void) {
    uint8_t u8event;
    switch (gu8appMasterState) {
        case 0:
            if (appMemoryStart()) {
                gu8appMasterState = 1;
            }
            break;
        case 1:
            if (appMemPowerOn()) {
                appCommReady();
                gu8appComBuzState = appCommGetBuzzerState();
                gu8appMasterState = 2;
            }
            break;
        case 2:
            appEvent();
            u8event = appMenuReadEvents();
            if (menuIsOpen()) {
                appCommNotReady();
                appStartMenu();
                gu8appMasterState = 3;
                return;
            }
#if AS_DISABLED_SYSTEM
            if (u8event == 0x01) {
                if (appCommRetBuState()) {
                    appCommRequestPutBuffer(STATE_REQ_CMD, 0xFF);
                }
                appMenuClearEvent();
                return;
            }
#endif
            /*check configuration*/
            if (appMenuIsLCDReady()) {
                /*buzzer On*/
                appshowData();
            }
            break;
        case 3:
            if (!menuIsOpen()) {
                gu8appMemIndex = 0;
                setSencodEvent();
                appCommReady();
                gu8appMasterState = 2;
            }
            break;
        default:
            break;
    }
    appCommunications();
    appMenu();
}

void appEvent() {
    uint8_t u8event;
    u8event = keypadGetEvent();
    if (u8event == KEYPAD_NOT_AN_EVENT) {
        return;
    }
    if (u8event == KEYPAD01_PRESS(KEYPAD_SW_MODE)) {
        menuOpen();
        return;
    }

    appEventEnter(u8event, KEYPAD01_PRESS(KEYPAD_SW_ENTER));
    appEventCencel(u8event, KEYPAD01_PRESS(KEYPAD_SW_CENCEL));

}

void appCurrentTimeShow() {
    uint8_t rtcbuf[8];
    uint8_t u8day, u8dayw, u8month, u8year, u8sec, u8min, u8hour;
    char s[16];
    lcdClear();
    lcdNoBlink();
    if (appMemNext(0) == 0xFF) {
        lcdwrite(0, LCD_TEXT_CENTER, "No Configuration");
        lcdwrite(1, LCD_TEXT_CENTER, "Please Enter Mode");
        bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
        return;
    }
    rtc_getDate(rtcbuf);
    if (rtcSecondEvent()) {
        clearSecondEvent();
        /*read data and sent is display*/
        rtc_getDate(rtcbuf);
        u8sec = rtcbuf[rtc_sec];
        u8min = rtcbuf[rtc_min];
        u8hour = rtcbuf[rtc_hour];
        u8day = rtcbuf[rtc_daym] + 1;
        u8dayw = rtcbuf[rtc_dayw];
        u8month = rtcbuf[rtc_month] + 1;
        u8year = rtcbuf[rtc_year];

        switch (u8dayw) {
            case 1:
                sprintf(s, "SAT   %02d-%02d-20%02d", u8day, u8month, u8year);
                break;
            case 2:
                sprintf(s, "SAN   %02d-%02d-20%02d", u8day, u8month, u8year);
                break;
            case 3:
                sprintf(s, "MON   %02d-%02d-20%02d", u8day, u8month, u8year);
                break;
            case 4:
                sprintf(s, "TUS   %02d-%02d-20%02d", u8day, u8month, u8year);
                break;
            case 5:
                sprintf(s, "WED   %02d-%02d-20%02d", u8day, u8month, u8year);
                break;
            case 6:
                sprintf(s, "THR   %02d-%02d-20%02d", u8day, u8month, u8year);
                break;
            case 7:
                sprintf(s, "FRI   %02d-%02d-20%02d", u8day, u8month, u8year);
                break;
            default:
                sprintf(s, "SAT   %02d-%02d-20%02d", u8day, u8month, u8year);
                break;
        }

        lcdwrite(0, LCD_TEXT_CENTER, s);
        sprintf(s, "MODE   %02d:%02d:%02d", u8hour, u8min, u8sec);
        lcdwrite(1, LCD_TEXT_CENTER, s);
        bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
    }
}

void appshowData() {
    char s[16];

    if (gu8appComBuzState) {
        if (!gu8DataShowState) {
            gu8ShowDataIndex = 0;
            gu8DataShowState = 1;
        }

    } else {
        gu8ShowDataIndex = 0;
        appCurrentTimeShow();
        return;
    }



    if (gu8DataShowState == 1) {
        gu8ShowDataIndex = appMemNext(gu8ShowDataIndex);
        if (gu8ShowDataIndex != 0xFF) {
            gu8DataShowState = 2;
        } else {
            gu8ShowDataIndex = 0;
            gu8DataShowState = 0;
        }
    }

    if (gu8DataShowState == 2) {
        if (appMemLoadDate(gu8ShowID, 2, ((gu8ShowDataIndex * MAX_POINT_DATA) + MAX_POINTS_ADDRESS), 0)) {
#if AS_DISABLED_SYSTEM
            if (gu8ShowID[1] == 0 || (gu8PointsData[gu8ShowDataIndex][1] == CENCEL_STATE) || gu8PointsData[gu8ShowDataIndex][1] == ACCEPTABLE_STATE) {
                gu8ShowDataIndex++;
                gu8DataShowState = 1;
                return;
            }
            lcdClear();
            sprintf(s, "Patient ID:%d", gu8ShowID[0]);
            lcdwrite(0, 0, s);

            if (gu8PointsData[gu8ShowDataIndex][1] == CALL_STATE) {
                buzGenerateSignalTime(100, 20);
                /*wait for */
                lcdwrite(1, 0, "Call State");
            } else if (gu8PointsData[gu8ShowDataIndex][1] == EMG_STATE) {
                buzGenerateSignalTime(50, 20);
                lcdwrite(1, 0, "Emergency State");
            } else if (gu8PointsData[gu8ShowDataIndex][1] == ASS_STATE) {
                buzGenerateSignalTime(100, 20);
                lcdwrite(1, 0, "Assistance State");
            }
            gu8DataShowState = 3;
            bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
            return;
        }
#endif  
    }


    if (gu8DataShowState == 3) {
        /*wait for */
        if (rtcSecondEvent()) {
            clearSecondEvent();
            gu8ShowDataIndex++;
            gu8DataShowState = 1;
            return;
        }
        return;
    }


}

