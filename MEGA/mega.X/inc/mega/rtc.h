/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_RTC_H
#define	XC_RTC_H
#include "../mega.h"

typedef enum {
    rtc_address = 0,
    rtc_sec = 1,
    rtc_min = 2,
    rtc_hour = 3,
    rtc_dayw = 4,
    rtc_daym = 5,
    rtc_month = 6,
    rtc_year = 7

} rtc_buffer_index;





#if (SYSTEM_MODULE == 0)
#error  "Please Enable System  module to work this module"
#endif

#define  RTC_WRITE_ADDRESS          (0xD0)
#define  RTC_READ_ADDRESS           (0xD1)

#define RTC_MODE_24H                (0)
#define RTC_MODE_12H                (1)

#define  RTC_SECONDE_ADDRESS        (0x00)
#define  RTC_MIN_ADDRESS            (0x01)
#define  RTC_HOUR_ADDRESS           (0x02)
#define  RTC_DAY_ADDRESS            (0x03)
#define  RTC_DATE_ADDRESS           (0x04)
#define  RTC_MONTH_ADDRESS          (0x05)
#define  RTC_YEAR_ADDRESS           (0x06)
#define  RTC_CONTROL_ADDRESS        (0x07)

/*RTC CLOCK GENERATOR*/


#if (TWI_MODULE == 0)
#error  "Please Enable TWI module to work this module"
#endif

#define  RTC_LEAP_YEAR(Y)            ((Y>0) && (!(Y%4)) && ((Y%100) || (!(Y%400))))




#define                     RTC_MAIN_STATE_MASK                          0x03




#define  RTC_WRITE_FLAG          (6)
#define  RTC_READ_FLAG           (7)
#define  RTC_MEM_STATE           (5)
#define  RTC_SECOND_EVENT        (4)
void rtcDriver();
/**/
void rtcInit();
/*sync task*/
void rtcSync();
/*app set Date*/
void rtcSetDate(uint8_t *rtcbuf);
/*app get Time*/
void rtc_getDate(uint8_t *rtcbuf);

uint8_t rtcIsSetDone();

uint8_t rtcSecondEvent();

void clearSecondEvent();

time_t rtcGetCurrentTime();
void setSencodEvent() ;
#endif	/* XC_RTC_H */

