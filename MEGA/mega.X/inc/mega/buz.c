/*
 * File:   buz.c
 * Author: Hassan
 *
 * Created on May 17, 2022, 1:10 PM
 */

#include <stdint-gcc.h>

#include "../../inc/mega.h"
#if (BUZ_MODULE)
stTimer_t gsbuzTime;
time_t offTime;
volatile uint8_t gu8BuzState;

void buzInit() {
    digitalpinMode(BUZ_PIN, BUZ_PIN_MODE_OUT);
    buzOFF();
    gu8BuzState = 0;
}

/*on buz every this time*/
void buzGenerateSignalTime(time_t Onwitdth, time_t OffWidth) {
    sysSetPeriodMS(&gsbuzTime, Onwitdth);
    sysSetTimer(&gsbuzTime, getSystemTick());
    gu8BuzState = 1;
    offTime = OffWidth;
    buzOn();
}

/*if Counter equal Zero The System is*/


void buzDriver() {
    if (!gu8BuzState)return;
    if (gu8BuzState == 1) {
        if (sysIsTimeout(&gsbuzTime)) {
            sysSetPeriodMS(&gsbuzTime, offTime);
            sysSetTimer(&gsbuzTime, getSystemTick());
            gu8BuzState = 2;
            buzOFF();
            return;
        }
        return;
    }

    if (gu8BuzState == 2) {
        if (sysIsTimeout(&gsbuzTime)) {
            gu8BuzState = 0;
            return;
        }
    }
}

void buzOn() {
    digitalPinWrite(BUZ_PIN, BUZ_ACTIVE);
}

void buzOFF() {
    digitalPinWrite(BUZ_PIN, !BUZ_ACTIVE);
}

uint8_t buzPeriodDone() {
    if (!gu8BuzState)
        return (1);
    return (0);
}

void buzStop() {
    buzOFF();
    gu8BuzState = 0;
}
#endif



