/*
 * File:   softRtc.c
 * Author: hassa
 *
 * Created on September 3, 2022, 2:09 AM
 */


#include "../inc/appRes.h"

#if defined (__AVR_ATmega328P__ ) || defined (__AVR_ATmega328__) || defined (__AVR_ATmega8__)|| defined (__AVR_ATmega8A__)
volatile time_t gu32RTC;
volatile uint8_t gu8sentSec;
volatile uint8_t gu8TanthSec;

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
    /*update every 5 min*/
}

time_t getCurrentTime() {
    return gu32RTC;
}

#endif
