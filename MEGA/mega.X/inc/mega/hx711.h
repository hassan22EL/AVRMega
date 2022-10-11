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
#ifndef XC_HX711_H
#define	XC_HX711_H
#include "../mega.h"

#define     Hx711_128             (1)
#define     Hx711_64              (3)
#define     Hx711_32              (2)

#define         HX711_RATE_HIGH         (1)
#define         HX711_RATE_LOW          (2)
#define         HX711_RATE_CLK          (3)


#ifndef    HX711_PD_SCK
#define     HX711_PD_SCK           NOT_A_PIN
#endif 

#ifndef     HX711_DOUT
#define     HX711_DOUT             NOT_A_PIN
#endif 

#ifndef     HX711_GAIN
#define     HX711_GAIN             Hx711_128
#endif



#ifndef   HX711_LPF_Coffient 
#define   HX711_LPF_Coffient             (6)
#endif 

#ifndef  HX711_RATE_TYPE            
#define  HX711_RATE_TYPE            HX711_RATE_HIGH
#endif 

#define       HX711_DELAY              1 /*1 ms */
#define       HX711_TimeOUT            500/*500 ms*/

#ifndef    HX711_READ_TASK
#define    HX711_READ_TASK              (8)
#endif

#define   HX711_LPF_Coffient_fequction         (pow(2.0,HX711_LPF_Coffient))


#if      HX711_RATE_TYPE == HX711_RATE_HIGH 
#define  HX711_POWER_UP_DELAY                     (50)
#elif    HX711_RATE_TYPE == HX711_RATE_LOW 
#define  HX711_POWER_UP_DELAY                      (400)
#endif

void hx711Init();


uint8_t hx711IsReady();

long hx711ReadADC();

void hx711Driver();

void hx711Sync();

uint8_t hx711ReadDone();

void hx711Powerdown(); /*Power down control (pin clock as high active)*/

void hx711Powerup(); /*Power down control pin as active low*/
#endif	/* XC_HEADER_TEMPLATE_H */

