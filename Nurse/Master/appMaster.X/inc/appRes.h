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
#ifndef XC_APPRES_H
#define	XC_APPRES_H

#include <xc.h> // include processor files - each processor file is guarded.  

#define             AS_DISABLED_SYSTEM           (1)

/*KEYPAD Defined*/
/*NUMBERS*/
#define   KEYPAD_SW0               KEYPAD01_SW09
#define   KEYPAD_SW1               KEYPAD01_SW16
#define   KEYPAD_SW2               KEYPAD01_SW12
#define   KEYPAD_SW3               KEYPAD01_SW08
#define   KEYPAD_SW4               KEYPAD01_SW15
#define   KEYPAD_SW5               KEYPAD01_SW11
#define   KEYPAD_SW6               KEYPAD01_SW07
#define   KEYPAD_SW7               KEYPAD01_SW14
#define   KEYPAD_SW8               KEYPAD01_SW10
#define   KEYPAD_SW9               KEYPAD01_SW06

/*function*/
#define   KEYPAD_SW_F1             KEYPAD01_SW04
#define   KEYPAD_SW_F2             KEYPAD01_SW03
#define   KEYPAD_SW_F3             KEYPAD01_SW02
#define   KEYPAD_SW_ENTER          KEYPAD01_SW01
#define   KEYPAD_SW_CENCEL         KEYPAD01_SW05
#define   KEYPAD_SW_MODE           KEYPAD01_SW13




#include "../../../../MEGA/mega.X/inc/mega.h"
#include "appMenu.h"
#include "appEvents.h"
#include "appComm.h"
#include "appDataMangments.h"
#include "appMenuTime.h"
#include "CMD.h"

#define APP_MENUE  (1)

#endif	/* XC_APPRES_H */

