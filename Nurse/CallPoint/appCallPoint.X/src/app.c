/*
 * File:   main.c
 * Author: Hassan
 *
 * Created on 25 ??????, 2021, 10:06 ?
 */





#include "../inc/app.h"

volatile uint8_t gu8appState;
volatile uint8_t gu8aPPLED_STATE;



void appReadEvent();
void appUpdateState();
stTimer_t gstLED_TIME;
volatile uint8_t gu8LEDTest;

void appBoot(void) {
    digitalpinMode(LED_BULE, MODE_OUTPUT);
    digitalpinMode(LED_RED, MODE_OUTPUT);
    digitalpinMode(LED_GREEN, MODE_OUTPUT);
}

void appInit(void) {
    gu8appState = 0;
    gu8LEDTest = 0;
    appcommInit();
    sysSetPeriodMS(&gstLED_TIME, 200);
}

void appSync(void) {
    gu8sentSec++;
}

void appMain(void) {
    uint8_t state;
    if (!appCommStart()) {
        gu8appState = 0;
    } else {
        if (!gu8appState) {
            gu8appState = 1;
            gu8LEDTest = 0;
        }
    }

    if (!gu8appState) {
        if (sysIsTimeout(&gstLED_TIME)) {
            switch (gu8LEDTest) {
                case 0:
                    digitalPinWrite(LED_BULE, GPIO_HIGH);
                    digitalPinWrite(LED_GREEN, GPIO_LOW);
                    digitalPinWrite(LED_RED, GPIO_LOW);
                    break;
                case 1:
                    digitalPinWrite(LED_BULE, GPIO_LOW);
                    digitalPinWrite(LED_GREEN, GPIO_HIGH);
                    digitalPinWrite(LED_RED, GPIO_LOW);
                    break;
                case 2:
                    digitalPinWrite(LED_BULE, GPIO_LOW);
                    digitalPinWrite(LED_GREEN, GPIO_LOW);
                    digitalPinWrite(LED_RED, GPIO_HIGH);
                    break;
                case 3:
                    digitalPinWrite(LED_BULE, GPIO_LOW);
                    digitalPinWrite(LED_GREEN, GPIO_LOW);
                    digitalPinWrite(LED_RED, GPIO_LOW);
                    break;
            }
            sysSetTimer(&gstLED_TIME, getSystemTick());
            if (gu8LEDTest < 4)
                gu8LEDTest++;
            else
                gu8LEDTest = 0;
        }
    } else {
        /*CALL POINT */
        switch (getStateCallPoint()) {
            case CALL_POINT_NOT_DEFINED:
                break;
            case CALL_POINT_AS_SW:
                state = SREG;
                ATOMIC_BEGIN
                gu8aPPLED_STATE = getState();
                SREG = state;
                ATOMIC_END
                appUpdateState();
                appReadEvent();
                break;
            case CALL_POINT_AS_ROOM:
                state = SREG;
                ATOMIC_BEGIN
                gu8aPPLED_STATE = getState();
                SREG = state;
                ATOMIC_END
                appUpdateState();
                break;
            default:
                break;
        }
    }
    appCommPingTimeOut();
}

void appReadEvent() {
    uint8_t u8event;

    if (getcommStateCMD() != NO_CMD)
        return;


    u8event = buttonGetEvent();
    if (u8event == NOT_AN_EVENT) {
        return;
    }

    if (u8event == BUTTON_PRESS(CALL_SW)) {
        appCommunication(CALL_STATE);
        return;
    }

    if (u8event == BUTTON_PRESS(ASS_SW)) {
        appCommunication(ASS_STATE);
        return;
    }

    if (u8event == BUTTON_PRESS(EMG_SW)) {
        appCommunication(EMG_STATE);
        return;
    }

    if (u8event == BUTTON_PRESS(CENCEL_SW)) {
        appCommunication(CENCEL_STATE);
        return;
    }
}

void appUpdateState() {

    if (gu8aPPLED_STATE == 0xFF)
        return;
    /*change status leds and clear commands*/
    switch (gu8aPPLED_STATE) {
        case CALL_STATE:
//            buzStop();
            gu8LEDTest = 0;
            digitalPinWrite(LED_BULE, GPIO_LOW);
            digitalPinWrite(LED_RED, GPIO_HIGH);
            digitalPinWrite(LED_GREEN, GPIO_LOW);

            break;
        case ASS_STATE:
//            buzStop();
            gu8LEDTest = 0;
            digitalPinWrite(LED_BULE, GPIO_LOW);
            digitalPinWrite(LED_RED, GPIO_HIGH);
            digitalPinWrite(LED_GREEN, GPIO_HIGH);
            break;
        case EMG_STATE:
//            buzStop();
            gu8LEDTest = 0;
            digitalPinWrite(LED_BULE, GPIO_HIGH);
            digitalPinWrite(LED_RED, GPIO_LOW);
            digitalPinWrite(LED_GREEN, GPIO_LOW);
            break;
        case CENCEL_STATE:
//            buzStop();
            gu8LEDTest = 0;
            digitalPinWrite(LED_BULE, GPIO_LOW);
            digitalPinWrite(LED_RED, GPIO_LOW);
            digitalPinWrite(LED_GREEN, GPIO_HIGH);
            break;
        case ACCEPTABLE_STATE:
            digitalPinWrite(LED_BULE, GPIO_HIGH);
            digitalPinWrite(LED_RED, GPIO_HIGH);
            digitalPinWrite(LED_GREEN, GPIO_HIGH);
            if (buzPeriodDone() ) {
                buzGenerateSignalTime(100, 1000);
            }
            break;
        default:
            break;
    }
    gu8aPPLED_STATE = 0xFF;
}
