/*
 * File:   appMenueTime.c
 * Author: Hassan
 *
 * Created on July 25, 2022, 10:43 AM
 */


#include "../inc/appMenuTime.h"

#if APP_MENUE

#define  TIME_MAX_DIGIT      2
void appMenueTimeEvents();
uint8_t gu8YearIndex;
void appMenueDateEvents();

uint8_t appMenueTime() {
    uint8_t u8event;
    uint8_t u8sec, u8min, u8hour;
    uint8_t rtcbuf[8];
    char str[16] = {0};
    char *ptr;
    if (!gu8appMenueState) {
        appEventSetStart(4);
        gu8appMenueState = 1;
    }

    /*cencel*/
    appMenueTimeEvents();
    u8event = appMenuReadEvents();



    if (!appMenuIsLCDReady()) {
        return (0);
    }

    if ((u8event == 0x04) || (u8event == 0x03))
        return (0);



    if (u8event == 0x01) {
        appMenueCloseEvent();
        appMenuClearEvent();
        return (1);
    }
    /*Enter*/
    if (u8event == 0x02) {
        /*read data and generate eeror */
        ptr = NULL;
        getlcdData(str, 1, 4);
        rtc_getDate(rtcbuf);
        ptr = strtok(str, ":");
        u8hour = uStringToNumber(ptr);
        ptr = strtok(str + 3, ":");
        u8min = uStringToNumber(ptr);
        ptr = strtok(str + 6, ":");
        u8sec = uStringToNumber(ptr);

        if (u8sec < 60 && u8min < 60 && u8hour < 24) {
            rtcbuf[rtc_sec] = u8sec;
            rtcbuf[rtc_min] = u8min;
            rtcbuf[rtc_hour] = u8hour;
            rtcSetDate(rtcbuf);
            bitsValue(gu8MnueFlags, 0x06, APP_MENU_EVENT_RESPONS);
            return (0);

        } else {
            lcdNoBlink();
            lcdClear();
            lcdwrite(0, LCD_TEXT_CENTER, " Invalid Time");
            lcdwrite(1, LCD_TEXT_CENTER, "Please Try Again");
            bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
            bitsValue(gu8MnueFlags, 0x04, APP_MENU_EVENT_RESPONS);
            return (0);
        }
    }


    if (u8event == 0x05) {
        gu8appMenueState = 0;
        appMenuClearEvent();
        return (0);
    }
    /*True*/
    if (u8event == 0x06) {
        if (rtcIsSetDone()) {
            gu8appMenueState = 0;
            appMenueCloseEvent();
            appMenuClearEvent();
            return (1);
        }
    }

    if (rtcSecondEvent() && appMenuIsLCDReady()) {
        clearSecondEvent();
        lcdClear();
        lcdNoBlink();
        rtc_getDate(rtcbuf);
        u8sec = rtcbuf[rtc_sec];
        u8min = rtcbuf[rtc_min];
        u8hour = rtcbuf[rtc_hour];
        lcdwrite(0, 0, "Set Current Time");
        sprintf(str, "%02d:%02d:%02d", u8hour, u8min, u8sec);
        lcdwrite(1, LCD_TEXT_CENTER, str);
        bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
        return (0);
    }
    return (0);
}

void appTimeDateInit() {
    gu8YearIndex = 3;
}

uint8_t appMenuDate() {
    char s[2];
    char *ptr;
    char str[4];
    char str2[16];
    //set time 
    uint8_t u8year, u8month, u8day, u8dayw, u8event;
    uint8_t rtcbuf[8];
    if (!gu8appMenueState) {
        lcdClear();
        lcdBlink(1, 0);
        rtc_getDate(rtcbuf);
        u8day = rtcbuf[rtc_daym] + 1;
        u8dayw = rtcbuf[rtc_dayw];
        u8month = rtcbuf[rtc_month] + 1;
        u8year = rtcbuf[rtc_year];
        lcdwrite(0, LCD_TEXT_CENTER, "Set Current Date");
        switch (u8dayw) {
            case 1:
                sprintf(str2, "SAT   %02d-%02d-20%02d", u8day, u8month, u8year);
                break;
            case 2:
                sprintf(str2, "SAN   %02d-%02d-20%02d", u8day, u8month, u8year);
                break;
            case 3:
                sprintf(str2, "MON   %02d-%02d-20%02d", u8day, u8month, u8year);
                break;
            case 4:
                sprintf(str2, "TUS   %02d-%02d-20%02d", u8day, u8month, u8year);
                break;
            case 5:
                sprintf(str2, "WED   %02d-%02d-20%02d", u8day, u8month, u8year);
                break;
            case 6:
                sprintf(str2, "THR   %02d-%02d-20%02d", u8day, u8month, u8year);
                break;
            case 7:
                sprintf(str2, "FRI   %02d-%02d-20%02d", u8day, u8month, u8year);
                break;
            default:
                sprintf(str2, "SAT   %02d-%02d-20%02d", u8day, u8month, u8year);
                break;
        }

        lcdwrite(1, LCD_TEXT_CENTER, str2);
        appEventSetStart(0);
        lcdBlink(1, 0);
        bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
        gu8appMenueState = 1;
        return (0);
    }

    if (!appMenuIsLCDReady()) {
        return (0);
    }
    appMenueDateEvents();
    u8event = appMenuReadEvents();

    if ((u8event == 0x04) || (u8event == 0x00) || (u8event == 0x03))
        return (0);

    if (u8event == 0x01) {
        gu8appMenueState = 0;
        appMenuClearEvent();
        appMenueCloseEvent();
        return (1);
    }
    if (appMenuReadEvents() == 0x02) {
        ptr = NULL;
        getlcdData(str, 1, 0);
        getlcdData(str2, 1, 6);
        rtc_getDate(rtcbuf);
        u8dayw = rtcbuf[rtc_dayw];
        u8day = rtcbuf[rtc_daym];
        u8month = rtcbuf[rtc_month];
        u8year = rtcbuf[rtc_year];
        if (strcmp(str, "SAN") == 0) {
            u8dayw = 2;
        } else if (strcmp(str, "MON") == 0) {
            u8dayw = 3;
        } else if (strcmp(str, "TUS") == 0) {
            u8dayw = 4;
        } else if (strcmp(str, "WED") == 0) {
            u8dayw = 5;
        } else if (strcmp(str, "THR") == 0) {
            u8dayw = 6;
        } else if (strcmp(str, "FRI") == 0) {
            u8dayw = 7;
        } else if (strcmp(str, "SAT") == 0) {
            u8dayw = 1;
        }
        ptr = strtok(str2, "-");
        u8day = uStringToNumber(ptr);
        ptr = strtok(str2 + 3, "-");
        u8month = uStringToNumber(ptr);
        uNumberToString(s, u8month);
        strncpy(ptr, str2 + 8, 2);
        u8year = uStringToNumber(ptr);
        if (u8month < 13 && u8month != 0 && u8day != 0 && u8day < 32) {
            rtcbuf[rtc_dayw] = u8dayw - 1;
            rtcbuf[rtc_daym] = u8day - 1;
            rtcbuf[rtc_month] = u8month - 1;
            rtcbuf[rtc_year] = u8year;
            rtcSetDate(rtcbuf);
            bitsValue(gu8MnueFlags, 0x06, APP_MENU_EVENT_RESPONS);
            return (0);
        } else {
            lcdNoBlink();
            lcdClear();
            lcdwrite(0, LCD_TEXT_CENTER, " Invalid Date");
            lcdwrite(1, 1, "Please Try Again");
            bitsValue(gu8MnueFlags, 0x04, APP_MENU_EVENT_RESPONS);
            bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
            return (0);
        }

    }


    if (appMenuReadEvents() == 0x05) {
        appMenuClearEvent();
        gu8appMenueState = 0;
    }

    if (appMenuReadEvents() == 0x06) {
        if (rtcIsSetDone()) {
            gu8appMenueState = 0;
            appMenueCloseEvent();
            appMenuClearEvent();
            return (1);
        }
    }
    return (0);
}

void appMenueTimeEvents() {
    uint8_t u8Event;
    u8Event = keypadGetEvent();
    if (u8Event == KEYPAD_NOT_AN_EVENT) {
        return;
    }
    if (appEventNumber(u8Event, "0", KEYPAD01_PRESS(KEYPAD_SW0), TIME_MAX_DIGIT)) return;
    if (appEventNumber(u8Event, "1", KEYPAD01_PRESS(KEYPAD_SW1), TIME_MAX_DIGIT)) return;
    if (appEventNumber(u8Event, "2", KEYPAD01_PRESS(KEYPAD_SW2), TIME_MAX_DIGIT)) return;
    if (appEventNumber(u8Event, "3", KEYPAD01_PRESS(KEYPAD_SW3), TIME_MAX_DIGIT)) return;
    if (appEventNumber(u8Event, "4", KEYPAD01_PRESS(KEYPAD_SW4), TIME_MAX_DIGIT)) return;
    if (appEventNumber(u8Event, "5", KEYPAD01_PRESS(KEYPAD_SW5), TIME_MAX_DIGIT)) return;
    if (appEventNumber(u8Event, "6", KEYPAD01_PRESS(KEYPAD_SW6), TIME_MAX_DIGIT)) return;
    if (appEventNumber(u8Event, "7", KEYPAD01_PRESS(KEYPAD_SW7), TIME_MAX_DIGIT)) return;
    if (appEventNumber(u8Event, "8", KEYPAD01_PRESS(KEYPAD_SW8), TIME_MAX_DIGIT)) return;
    if (appEventNumber(u8Event, "9", KEYPAD01_PRESS(KEYPAD_SW9), TIME_MAX_DIGIT)) return;
    /*cencel Event*/
    if (appEventCencel(u8Event, KEYPAD01_PRESS(KEYPAD_SW_CENCEL)))return;
    /*Enter Event*/
    if (appEventEnter(u8Event, KEYPAD01_PRESS(KEYPAD_SW_ENTER)))return;
    /*Move Event*/
    if (appEventMove(u8Event, KEYPAD01_PRESS(KEYPAD_SW_MODE), 3, 4, TIME_MAX_DIGIT))return;
    /*up Event*/
    if (appEventUp(u8Event, KEYPAD01_PRESS(KEYPAD_SW_F2), TIME_MAX_DIGIT))return;
    /*Down Event*/
    if (appEventDown(u8Event, KEYPAD01_PRESS(KEYPAD_SW_F3), TIME_MAX_DIGIT))return;
}

void appMenueDateEvents() {
    uint8_t u8Event;
    u8Event = keypadGetEvent();
    if (u8Event == KEYPAD_NOT_AN_EVENT) {
        return;
    }
    if (!appEventGetEventNumber()) {
        if (appEventNumber(u8Event, "SAT", KEYPAD01_PRESS(KEYPAD_SW1), 1))return;
        if (appEventNumber(u8Event, "SAN", KEYPAD01_PRESS(KEYPAD_SW2), 1))return;
        if (appEventNumber(u8Event, "MON", KEYPAD01_PRESS(KEYPAD_SW3), 1))return;
        if (appEventNumber(u8Event, "TUS", KEYPAD01_PRESS(KEYPAD_SW4), 1))return;
        if (appEventNumber(u8Event, "WES", KEYPAD01_PRESS(KEYPAD_SW5), 1))return;
        if (appEventNumber(u8Event, "THS", KEYPAD01_PRESS(KEYPAD_SW6), 1))return;
        if (appEventNumber(u8Event, "FRE", KEYPAD01_PRESS(KEYPAD_SW7), 1))return;
        appEventMove(u8Event, KEYPAD01_PRESS(KEYPAD_SW_MODE), 6, 0, 1);
    } else {
        if (appEventNumber(u8Event, "0", KEYPAD01_PRESS(KEYPAD_SW0), TIME_MAX_DIGIT)) return;
        if (appEventNumber(u8Event, "1", KEYPAD01_PRESS(KEYPAD_SW1), TIME_MAX_DIGIT))return;
        if (appEventNumber(u8Event, "2", KEYPAD01_PRESS(KEYPAD_SW2), TIME_MAX_DIGIT))return;
        if (appEventNumber(u8Event, "3", KEYPAD01_PRESS(KEYPAD_SW3), TIME_MAX_DIGIT))return;
        if (appEventNumber(u8Event, "4", KEYPAD01_PRESS(KEYPAD_SW4), TIME_MAX_DIGIT))return;
        if (appEventNumber(u8Event, "5", KEYPAD01_PRESS(KEYPAD_SW5), TIME_MAX_DIGIT))return;
        if (appEventNumber(u8Event, "6", KEYPAD01_PRESS(KEYPAD_SW6), TIME_MAX_DIGIT))return;
        if (appEventNumber(u8Event, "7", KEYPAD01_PRESS(KEYPAD_SW7), TIME_MAX_DIGIT))return;
        if (appEventNumber(u8Event, "8", KEYPAD01_PRESS(KEYPAD_SW8), TIME_MAX_DIGIT))return;
        if (appEventNumber(u8Event, "9", KEYPAD01_PRESS(KEYPAD_SW9), TIME_MAX_DIGIT))return;
        /*cencel Event*/
        if (appEventCencel(u8Event, KEYPAD01_PRESS(KEYPAD_SW_CENCEL)))return;
        /*Enter Event*/
        if (appEventEnter(u8Event, KEYPAD01_PRESS(KEYPAD_SW_ENTER)))return;
        /*up Event*/
        if (appEventUp(u8Event, KEYPAD01_PRESS(KEYPAD_SW_F2), TIME_MAX_DIGIT))return;
        /*Down Event*/
        if (appEventDown(u8Event, KEYPAD01_PRESS(KEYPAD_SW_F3), TIME_MAX_DIGIT))return;

        if (appEventGetEventNumber() == 9) {
            gu8YearIndex = 5;
        } else if (appEventGetEventNumber() == 10) {
            gu8YearIndex = 6;
        } else {
            gu8YearIndex = 3;
        }
        if (appEventMove(u8Event, KEYPAD01_PRESS(KEYPAD_SW_MODE), gu8YearIndex, 0, TIME_MAX_DIGIT))return;
    }

    if (appEventCencel(u8Event, KEYPAD01_PRESS(KEYPAD_SW_CENCEL)))return;
    /*Enter Event*/
    if (appEventEnter(u8Event, KEYPAD01_PRESS(KEYPAD_SW_ENTER)))return;

}

#endif