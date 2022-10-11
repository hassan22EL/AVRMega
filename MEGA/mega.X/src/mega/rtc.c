
#include <stdint.h>

#include "../../inc/mega.h"


#include <time.h>
#include <stdint-gcc.h>
#if RTC_MODULE 

#define     RTC_BASE_TIME                 (2000UL)
#define 	SECS_PER_HOUR                 (3600UL)
#define 	SECS_PER_MIN                  (60UL)
#define 	DAY_PER_WEEK                  (7)
#define     SECS_PER_DAY                 ((SECS_PER_HOUR) * (24UL))
#define     YAER_SIZE(Y)                  ((RTC_LEAP_YEAR(Y + (RTC_BASE_TIME))) ? (366) : (365))

#define     RTC_SOFT_UPDATE_PERIOD       (time_t) (RTC_CLOCK_UPDATE * SECS_PER_MIN)

volatile uint8_t gu8rtcStates;
uint8_t gu8rtcBuffer[8];


volatile time_t gu32RTC;
volatile uint8_t gu8sentSec;
volatile uint8_t gu8TanthSec;

stTWi_Tx gstRtcTWI[2];


static const uint8_t gu8RtcMonthLeapYear[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static const uint8_t gu8RtcMonthYear[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


time_t rtcConvertDateToTime(uint8_t *ptm);
void rtcConvertTimeToDate(time_t Time, uint8_t *ptm);
void rtcConvertbuffer(uint8_t *buf, uint8_t state);
/**********************update Hardware clock*************************/
uint8_t rtcHwUpdate();
/**********************Read clock*************************/
uint8_t rtcSwUpdate();
/************************* soft clock*****************************************/
void rtccSoftTime();

/*************************rtc init *****************************************/
void rtcInit() {
    gu32RTC = 0;
    gu8sentSec = 0;
    gu8TanthSec = 0;
    gu8rtcStates = 0x00;
    bitSet(gu8rtcStates, RTC_READ_FLAG);
    bitSet(gu8rtcStates, RTC_SECOND_EVENT);
    gstRtcTWI[0].slave_adr = RTC_WRITE_ADDRESS;
    gstRtcTWI[1].slave_adr = RTC_READ_ADDRESS;
}

time_t rtcConvertDateToTime(uint8_t *ptm) {
    time_t time;
    uint8_t u8temp;

    time = 0;

    if (ptm[rtc_month] > 11
            && ptm[rtc_daym] > 30
            && ptm[rtc_hour] > 23
            && ptm[rtc_min] > 59
            && ptm[rtc_sec] > 59) {
        time = gu32RTC;
        return time;
    } else {

        u8temp = 0;
        //convert year to day
        while (u8temp < ptm[rtc_year]) {
            time += YAER_SIZE(u8temp);
            u8temp++;
        }
        // convert month to day
        u8temp = 0;
        while (u8temp < ptm[rtc_month]) {
            if (RTC_LEAP_YEAR(ptm[rtc_year] + RTC_BASE_TIME)) {
                time += gu8RtcMonthLeapYear[u8temp];
            } else {
                time += gu8RtcMonthYear[u8temp];
            }
            u8temp++;
        }
        time += ptm[rtc_daym];
        /*convert dayes to sec*/
        time = time * (SECS_PER_DAY);
        /*add hours and min and sec*/
        time += (ptm[rtc_hour] * SECS_PER_HOUR) + (ptm[rtc_min] * 60) + ptm[rtc_sec];

        return (time);
    }
}

void rtcConvertTimeToDate(time_t Time, uint8_t *ptm) {
    time_t rem;
    time_t Days;
    uint8_t u8Temp;

    rem = (Time % SECS_PER_DAY);

    ptm[rtc_hour] = (rem) / SECS_PER_HOUR;
    rem = (rem) % (SECS_PER_HOUR);

    ptm[rtc_min] = (rem) / (SECS_PER_MIN);
    ptm[rtc_sec] = ((rem) % (SECS_PER_MIN));


    Days = (Time / SECS_PER_DAY);
    if (Days < 1) {
        ptm[rtc_year] = 0;
        ptm[rtc_month] = 0;
        ptm[rtc_daym] = 0; //
    } else {
        /*week days 1-1-2000  (starday*/

        /*convert days to years*/
        /*start year*/
        u8Temp = 0; /*start year 2000 (00)*/
        while (Days >= YAER_SIZE(u8Temp)) {
            Days = Days - (YAER_SIZE(u8Temp));
            u8Temp++;
        }
        ptm[rtc_year] = u8Temp;
        /*month*/
        u8Temp = 0;
        if (RTC_LEAP_YEAR(ptm[rtc_year] + RTC_BASE_TIME)) {
            while (Days >= gu8RtcMonthLeapYear[u8Temp]) {
                Days = Days - gu8RtcMonthLeapYear[u8Temp];
                u8Temp++;
            }
        } else {
            while (Days >= gu8RtcMonthYear[u8Temp]) {
                Days = Days - gu8RtcMonthYear[u8Temp];
                u8Temp++;
            }
        }
        ptm[rtc_month] = u8Temp;
        ptm[rtc_daym] = Days;
    }
}

/*run every 10 ms*/
void rtcSync() {
    gu8sentSec++;
}

void rtccSoftTime() {
    while (gu8sentSec != 0) {
        //on 1/10 from sec 
        gu8sentSec--;
        gu8TanthSec++;
    }

    if (gu8TanthSec >= 99) {
        gu32RTC++;
        bitSet(gu8rtcStates, RTC_SECOND_EVENT);
        if (gu32RTC % (RTC_SOFT_UPDATE_PERIOD) == 0) {
            bitSet(gu8rtcStates, RTC_READ_FLAG);
        }
        gu8TanthSec = 0;
    }
    /*update every 5 min*/
}

void setSencodEvent() {
    bitSet(gu8rtcStates, RTC_SECOND_EVENT);
}

uint8_t rtcSecondEvent() {
    if (bitIsClear(gu8rtcStates, RTC_SECOND_EVENT)) {
        return (0);
    } else {
        return (1);
    }
}

void clearSecondEvent() {
    bitClear(gu8rtcStates, RTC_SECOND_EVENT);
}

/*************************************************************/
void rtcDriver() {
    if (bitIsSet(gu8rtcStates, RTC_WRITE_FLAG)) {
        if (rtcHwUpdate()) {
            bitClear(gu8rtcStates, RTC_WRITE_FLAG);
        }
        return;
    }

    if (bitIsSet(gu8rtcStates, RTC_READ_FLAG)) {
        if (rtcSwUpdate()) {
            bitClear(gu8rtcStates, RTC_READ_FLAG);
        }
        return;
    }
    rtccSoftTime();
}

uint8_t rtcHwUpdate() {
    if (bitIsClear(gu8rtcStates, RTC_MEM_STATE)) {
        if (TWI_ISReady()) {
            //convert this time
            TWI_BUSY();
            rtcConvertTimeToDate(gu32RTC, gu8rtcBuffer);
            gu8rtcBuffer[rtc_address] = 0x00;
            rtcConvertbuffer(gu8rtcBuffer, 1);
            twiInitFram(&gstRtcTWI[0], 8, gu8rtcBuffer);
            bitSet(gu8rtcStates, RTC_MEM_STATE);
        }
    } else {
        if (Send_to_TWI(gstRtcTWI, 1) == TWI_SUCCESS) {
            TWI_READY();
            bitClear(gu8rtcStates, RTC_MEM_STATE);
            return (1);
        }
    }
    return (0);
}

uint8_t rtcSwUpdate() {
    if (bitIsClear(gu8rtcStates, RTC_MEM_STATE)) {
        if (TWI_ISReady()) {
            //convert this time
            TWI_BUSY();
            gu8rtcBuffer[rtc_address] = 0x00;
            twiInitFram(&gstRtcTWI[0], 1, gu8rtcBuffer);
            twiInitFram(&gstRtcTWI[1], 7, gu8rtcBuffer);
            bitSet(gu8rtcStates, RTC_MEM_STATE);
        }
    } else {
        if (Send_to_TWI(gstRtcTWI, 2) == TWI_SUCCESS) {
            TWI_READY();
            /*convert bcd to decimal*/
            appShfitBuffer(gu8rtcBuffer, 0x00, 8);
            rtcConvertbuffer(gu8rtcBuffer, 0);
            gu8rtcBuffer[rtc_sec] |= (0x80);
            gu32RTC = rtcConvertDateToTime(gu8rtcBuffer);
            bitClear(gu8rtcStates, RTC_MEM_STATE);
            return (1);
        }
    }
    return (0);
}

uint8_t rtcIsSetDone() {
    if (bitIsClear(gu8rtcStates, RTC_WRITE_FLAG)) {
        return (1);
    } else {
        return (0);
    }
}

void rtcSetDate(uint8_t * rtcbuf) {
    bitSet(gu8rtcStates, RTC_WRITE_FLAG);
    gu32RTC = rtcConvertDateToTime(rtcbuf);
    gu8rtcBuffer[rtc_dayw] = rtcbuf[rtc_dayw];
}

void rtc_getDate(uint8_t * rtcbuf) {
    rtcConvertTimeToDate(gu32RTC, rtcbuf);
    rtcbuf[rtc_dayw] = gu8rtcBuffer[rtc_dayw];
}

void rtcConvertbuffer(uint8_t *buf, uint8_t state) {
    if (state) {

        for (uint8_t i = 1; i < 8; i++)
            buf[i] = decToBcd(buf[i]);

    } else {
        /*zero to 7 to 1 to 8*/
        for (uint8_t i = 1; i < 8; i++)
            buf[i] = BcdToDec(buf[i]);

    }
}

time_t rtcGetCurrentTime() {
    return (gu32RTC);
}
#endif