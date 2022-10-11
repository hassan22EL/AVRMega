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
#ifndef XC_MEGA_H
#define	XC_MEGA_H

#include <xc.h>





#include "resource.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <avr/pgmspace.h>
#include <avr/io.h>
#include <math.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <util/atomic.h>
#include "mega/macros.h"
#include "mega/gpio.h"
#include "mega/types.h"
#include "mega/buffers.h"
#include "mega/utility.h"
#include <stdio.h>

#if SYSTEM_MODULE
#include "mega/sys.h"
#endif


#if SSD_MODULE 
#include "mega/SSD.h"
#endif

#if  BUZ_MODULE 
#include "mega/buz.h"
#endif



#if      CSMA_CD_MODULE                     
#include "mega/uart.h"
#if COMM_TYPE == CSMA_CD_WAITRECEIVE
#include  "mega/csma_cd.h"
#endif
#endif


#if   BUTTON_MODULE
#include "mega/button.h"
#endif 

#if KEYPAD_MODULE
#include "mega/keypad.h"
#endif

#if LCD_MODULE
#include "mega/lcd.h"
#endif



#if RTC_MODULE
#include  "mega/rtc.h"
#endif



#if EX_EEPROM_MODULE
#include "mega/exEEPROM.h"
#endif 

#if MENU_MODULE
#include "mega/menu.h"
#endif

#if BUZ_MODULE 
#include "mega/buz.h"
#endif

#if SPI_MODULE 
#include "mega/spi.h"
#endif

#if SSSD_MODULE
#include "mega/sssd.h"
#endif

#if HX711_MODULE
#include "mega/hx711.h"
#endif 

#if EEPROM_MODULE
#include "mega/eeprom.h"
#endif 

#if KEYPADEVENT_MODULE 
#include "mega/kepadEvents.h"
#endif

#if TWI_MODULE
#include "mega/TWI.h"
#endif


extern int main(void);
// Application Functions
extern void appMain(void);
extern void appBoot(void);
extern void appInit(void);
extern void appSync(void);

#endif	/* XC_MEGA_H */

