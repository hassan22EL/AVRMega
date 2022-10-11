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
#ifndef XC_APPCOM_H
#define	XC_APPCOM_H

#include "appRes.h"

#define   CENCEL_STATE         0x00
#define   ACCEPTABLE_STATE     0x01
#define   CALL_STATE           0x02
#define   ASS_STATE            0x03
#define   EMG_STATE            0x04
#define   DISPLED_STATE        0x80


#if AS_DISABLED_SYSTEM
extern volatile uint8_t gu8appComBuzState;
#endif
void appCommunications();
uint8_t appCommRequestPutBuffer(uint8_t CMD, uint8_t Address);

void appCommInit();
uint8_t appCommRepEvent();
uint8_t appCommTestEvent();
uint8_t appCommPowerOn();
uint8_t appCommReadCMD();
void appCommNoResPonse();
void appCommReady();
void appCommNotReady();


#if AS_DISABLED_SYSTEM
uint8_t appCommGetBuzzerState();
uint8_t appCommRetBuState();
#endif


#endif	/* XC_APPCOM_H */

