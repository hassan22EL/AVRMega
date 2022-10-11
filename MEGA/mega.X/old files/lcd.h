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



#ifndef XC_LCD_H
#define XC_LCD_H


#include "../mega.h"


extern volatile uint8_t gu8LcdOPtion;
extern volatile uint8_t gu8LCDPosition;

#define  LCD_8BIT_MODE        (0x01)
#define  LCD_4BIT_MODE        (0x02)
#define  LCD_NONINTERACTIVE   (0x03)
#define  LCD_INTERAVTIVE      (0x04)
#define  LCD_COMMAND          (0x05)
#define  LCD_DATA             (0x06)


/*LCD Commands*/
#define LCD_8BIT_COMMAND                (0x30)
#define LCD_8BIT_2LINE_COMMAND          (0x38)   /*set number of line 2 and font 5*10 dot */



/*4bit mode commands*/
#define LCD_4BIT_COMMAND           (0x20)  /*set 4bit mode*/
#define LCD_2LINE_COMMAND          (0x28)   /*set number of line 2 and font 5*10 dot */


#define LCD_DISPLAY_ON_COMMAND     (0x0C)  /*display ON  */
#define LCD_DISPLAY_OFF_COMMAND    (0x08) /*display off*/
#define LCD_CLEAR_COMMAND          (0x01)   /*clear data*/
#define LCD_ENTRY_SET              (0x06)   



#define  LCD_CGRAM_ADDRESS_CHECK   (0x3F) /*last char in cgram*/
#define  LCD_CGRRAM_MODE           (0x40)
#define  LCD_DDRAM_MODE            (0x80)
/*Timing*/
#define LCD_TIMING_POWER_ON    (15) /*uint 15ms*/
#define LCD_TIMING_8BIT_LONG   (5) /*uint 5ms*/
#define LCD_TIMING_CLEAR_COMMAND   (3) /*uint 3ms*/
#define LCD_OPERATION_TIME     (40) /*uint 40us*/

#ifndef LCD_UPDATE_TIME_OUT
#define LCD_UPDATE_TIME_OUT    (1000)
#endif


#define  LCD_OK    (1)
#define  LCD_RUNNING  (0)


#define   LCD_INIT_IDLE                              state_00
#define   LCD_INIT_WAIT                              state_01
#define   LCD_INIT_WRITE_HIGH                        state_02

#define    LCD_INIT_WRITE_CLEAR_COMMAND                state_03
#define    LCD_INIT_WRITE_COMMAND                       state_04


#define   LCD_UPDATE_IDLE                              state_00
#define   LCD_UPDATE_CHECK                             state_01
#define   LCD_UPDATE_WRITE                             state_02
#define   LCD_UPDATE_POS                               state_03


#define LCD_LINE0_START         (0x80) /* 0x00 as 7 bit data*/
#define LCD_LINE1_START         (0xC0)  
#define LCD_LINE2_START         (0x90)  
#define LCD_LINE3_START          (0xD0)  


/*LCD Flags*/
#define  LCD_ReInit_SET_TIME_OUT_FLAG       (0)
#define   LCD_INIT_WRITE_HIGH_FLAG (1)

/*LCD BYTE POS*/
#define  LCD_LINE_POS    (2)
#define  LCD_CHAR_POS    (6)
/*LCD Option*/
#define   LCD_DISPLAY    (2)
#define   LCD_CUSOR      (1)
#define   LCD_BLINK      (0)

#ifndef LCD_RS 
#define LCD_RS NOT_A_PIN
#endif 

#ifndef LCD_EN 
#define LCD_EN NOT_A_PIN
#endif

#ifndef LCD_RW 
#define LCD_RW NOT_A_PIN
#endif

#ifndef LCD_D0 
#define LCD_D0 NOT_A_PIN
#endif

#ifndef LCD_D1 
#define LCD_D1 NOT_A_PIN
#endif


#ifndef  LCD_D2 
#define  LCD_D2 NOT_A_PIN
#endif


#ifndef  LCD_D3 
#define  LCD_D3 NOT_A_PIN
#endif

#ifndef  LCD_D4 
#define  LCD_D4 NOT_A_PIN
#endif

#ifndef  LCD_D5 
#define  LCD_D5 NOT_A_PIN
#endif

#ifndef  LCD_D6 
#define  LCD_D6 NOT_A_PIN
#endif

#ifndef  LCD_D7 
#define  LCD_D7  NOT_A_PIN
#endif

#ifndef  LCD_NUMBER_OF_LINES 
#define  LCD_NUMBER_OF_LINES   (2)
#endif

#ifndef  LCD_NUMBER_OF_BYTE   
#define  LCD_NUMBER_OF_BYTE    (16)
#endif



#ifndef  LCD_LINE_MODE 
#define  LCD_LINE_MODE  (LCD_INTERAVTIVE)
#endif 


#ifndef  LCD_BITS_MODE
#define  LCD_BITS_MODE  (LCD_4BIT_MODE)
#endif 





void lcdCursor(uint8_t u8line, uint8_t u8pos);

void lcdNoCursor();

void lcdBlink(uint8_t u8line, uint8_t u8pos);
void lcdNoBlink();

void lcdDisplay();

void lcdNoDisplay();

void lcdCreateChar(uint8_t u8location, const uint8_t *pu8Data);


#define  LCD_TXET_CENTER  (0)
#define  LCD_TEXT_LEFT    (1)

void lcdHwInit();
uint8_t lcdInit();
uint8_t lcdUpdate();

void lcdClear();
void lcdClearlines(uint8_t from);
void lcdClearPos(uint8_t line, uint8_t pos);

void lcdprintbuf(uint8_t *buf, uint8_t line, uint8_t length);
void lcdPrint(uint8_t line, uint8_t alignment, const char *s);
void lcdwrite(uint8_t line, uint8_t pos, const char *string);
void lcdwriteCGRAM(uint8_t line, uint8_t pos, uint8_t index);

uint8_t lcdIsCharEmpty(uint8_t line, uint8_t pos);

uint8_t lcdIsCurrentNumber(uint8_t line, uint8_t pos);
void lcdReplace(uint8_t line, uint8_t startpos);
void getlcdData(char *str, uint8_t line, uint8_t pos);
uint8_t lcdfindchar(uint8_t line, uint8_t pos, uint8_t s);
/*buffer interface*/

#endif	/* XC_LCD_H */

