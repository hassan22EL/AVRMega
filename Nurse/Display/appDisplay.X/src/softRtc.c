/*
 * File:   softRtc.c
 * Author: hassa
 *
 * Created on September 3, 2022, 2:09 AM
 */


#include "../inc/appRes.h"
volatile time_t gu32RTC;
volatile uint8_t gu8sentSec;
volatile uint8_t gu8TanthSec;

void appRtcRest() {
    gu8sentSec = 0;
    gu8TanthSec = 0;
}

void appRtcSoftTime() {
    while (gu8sentSec != 0) {
        //on 1/10 from sec 
        gu8sentSec--;
        gu8TanthSec++;
    }

    if (gu8TanthSec >= 99) {
        gu32RTC++;
        gu8TanthSec = 0;
    }
}