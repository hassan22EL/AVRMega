/*
 * File:   main.c
 * Author: Hassan
 *
 * Created on 25 ??????, 2021, 10:06 ?
 */





#include "../inc/app.h"




volatile uint8_t gu8aPPLED_STATE;
volatile uint8_t gu8aPPBUZState;


void appReadEvent();
void appUpdateState();

void appBoot(void) {
    digitalpinMode(LED_RED, MODE_OUTPUT_LOW);
    digitalpinMode(LED_GREEN, MODE_OUTPUT_HIGH);
    digitalpinMode(LED_BULE, MODE_OUTPUT_LOW);
    digitalpinMode(RESET_BUTTON, MODE_INPUT_PULLUP);
}

void appInit(void) {
    gu8aPPLED_STATE = 0;
    appcommInit();

}

void appSync(void) {

}

void appMain(void) {
    uint8_t state;
    state = SREG;
    __disable_interrupt();
    gu8aPPLED_STATE = getState();
    SREG = state;
    __enable_interrupt();
    appUpdateState();
    appReadEvent();
    appCommunication();
}

void appReadEvent() {
    uint8_t u8event;
    if (getcommStateCMD() != NO_CMD)
        return;
    u8event = buttonGetEvent();
    if (u8event == NOT_AN_EVENT) {
        return;
    }
    if (u8event == BUTTON_PRESS(CENCEL_SW)) {
        appCommRequestPutBuffer(STATE_REQ_CMD);
        return;
    }
}

void appUpdateState() {
    if (gu8aPPLED_STATE == 0xFF)
        return;
    /*change status leds and clear commands*/
    switch (gu8aPPLED_STATE) {
        case CENCEL_STATE:
            digitalPinWrite(LED_BULE, GPIO_LOW);
            digitalPinWrite(LED_RED, GPIO_LOW);
            digitalPinWrite(LED_GREEN, GPIO_HIGH);
            gu8aPPBUZState = 0;
            appCommClearCencel();
            break;
        case CALL_STATE:
            digitalPinWrite(LED_BULE, GPIO_LOW);
            digitalPinWrite(LED_RED, GPIO_HIGH);
            digitalPinWrite(LED_GREEN, GPIO_LOW);
            if (buzPeriodDone())
                buzGenerateSignalTime(100, 1000);
            if (gu8aPPBUZState == 0) {
                gu8aPPBUZState = 1;
                appCommsetCencel();
            }

            break;
        case EMG_STATE:
            digitalPinWrite(LED_BULE, GPIO_HIGH);
            digitalPinWrite(LED_RED, GPIO_LOW);
            digitalPinWrite(LED_GREEN, GPIO_LOW);
            if (buzPeriodDone())
                buzGenerateSignalTime(50, 100);
            if (gu8aPPBUZState == 0) {
                gu8aPPBUZState = 1;
                appCommsetCencel();
            }
            break;
        case ACCEPTABLE_STATE:
            digitalPinWrite(LED_BULE, GPIO_HIGH);
            digitalPinWrite(LED_RED, GPIO_HIGH);
            digitalPinWrite(LED_GREEN, GPIO_HIGH);
            gu8aPPBUZState = 0;
            appCommClearCencel();
            break;
        default:
            break;
    }
    gu8aPPLED_STATE = 0xFF;
}



