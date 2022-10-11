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
#ifndef XC_SSSD_H
#define	XC_SSSD_H

#if (SPI_MODULE == 0)
#error "please Enable SPI System"
#endif

#define SSSD_NOOP_ADDR                   (0x00) /*no opreation address*/
#define SSSD_DECODEMODE_ADDR             (0x09) /*BCD code each bit as digit*/
#define SSSD_BRIGHTNESS_ADDR             (0x0A) /*control of light of the digit control by duty cycle*/
#define SSSD_SCANLIMIT_ADDR              (0x0B)  /*number of the digit scan*/
#define SSSD_SHUTDOWN_ADDR               (0X0C) /*select between normal operation or suhtdown operation*/
#define SSSD_DISPLAYTEST_ADDR            (0x0F)    /*display test */

#define  SSSD_RIGHT    (0) 
#define  SSSD_LEFT     (1)
#define SSSD_NEG_ALLOW (0)
#define SSSD_NEG_BLOKED (1)

#ifndef   SSSD_DIR 
#define   SSSD_DIR   SSSD_RIGHT
#endif

#ifndef  SSSD_PRINT_NEG_ALOW
#define  SSSD_PRINT_NEG_ALOW           SSSD_NEG_ALLOW
#endif 
#define SSSD_OP_OFF (0x0)
#define SSSD_OP_ON  (0x1)
#define SSSD_MAX72d (0x1)        // '-'
#define SSSD_MAX72b (0x0)        // ' '
#define SSSD_DP_FLAG (0B10000000) // '.'




#ifndef  SSSD_MAX_DIVICES
#define   SSSD_MAX_DIVICES             (1)
#endif


void sssdInit();
void sssdStart(uint8_t *u8Pins);

void sssdOn(uint8_t nDevice);
void sssdOff(uint8_t nDevice);
void sssdClear(uint8_t nDevice);
void sssdClearEnd(uint8_t nDevice , uint8_t u8Start ,uint8_t u8End);
void sssdSetDigitLimit(uint8_t limit, uint8_t nDevice);
void sssdSetBright(uint8_t brightness, uint8_t nDevice);
void sssdPrintDigit(long number, uint8_t nDevice, uint8_t startDigit, uint8_t dpdigit);
void sssdSetDigit(uint8_t value, uint8_t nDevice, uint8_t digit, uint8_t dp);

void sssdPrintAll(long number, uint8_t u8startDigit, uint8_t u8EndDigit, uint8_t dpDigit);
void sssdPrintString(const char *s, uint8_t u8startDigit, uint8_t u8EndDigit, uint8_t dpDigit);
void sssdClearAll(uint8_t u8StartDigit, uint8_t u8EndDigit);
#endif	/* XC_HEADER_TEMPLATE_H */

