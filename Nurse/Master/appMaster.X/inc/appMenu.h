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
#ifndef XC_APPMENU_H
#define	XC_APPMENU_H


#include "appRes.h"

extern volatile uint8_t gu8appMenueState;
extern volatile uint8_t gu8MnueFlags;


#define  APP_MENU_LCD_UPDATE              (7)
#define  APP_MEM_SAVE_UPDATE              (6)
#define  APP_MEM_ZONE_EVENT               (5)
#define  APP_MEM_ZONE_READ                 (4)
#define  APP_MEM_ZONE_ENTER                (3)
#define  APP_MENU_EVENT_RESPONS           (0x07) // first 3 bits
void appStartMenu();
void appMenuInit();
void appMenu();
void appMenuClearEvent();
uint8_t appMenuIsLCDReady();
uint8_t appMenuReadEvents();
void appMenueCloseEvent();

void updateProgressBar(uint8_t count, uint8_t totalCount, uint8_t lineToPrintOn);
#endif	/* XC_HEADER_TEMPLATE_H */

