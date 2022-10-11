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
#ifndef XC_APPCOMMUICATION_H
#define	XC_APPCOMMUICATION_H

#include "appRes.h"

#define CALL_POINT_LENGTH       9
#define   CENCEL_STATE         0x00
#define   ACCEPTABLE_STATE     0x01
#define   CALL_STATE           0x02
#define   ASS_STATE            0x03
#define   EMG_STATE            0x04

#define  CALL_POINT_NOT_DEFINED 0x00
#define   CALL_POINT_AS_SW      0x01
#define   CALL_POINT_AS_ROOM    0x02
#define   CALL_POINT_AS_DISPLAY 0x03

typedef enum {
    callPointID = 0,
    callPointRoomID = 1,
    callPointRoomA = 2,
    callPointLastConfig = 3,
    callPointLastState = 4,
    callPointTime = 5,
} enCallPoint;



void appcommInit();
void appCommunication();
uint8_t appCommPowerOn();
uint8_t appCommRequestPutBuffer(uint8_t CMD);
uint8_t getcommStateCMD();
uint8_t getState();
void appCommResetButton();
void appCommsetCencel();
void appCommClearCencel();
#endif	/* XC_APPCOMMUICATION_H */

