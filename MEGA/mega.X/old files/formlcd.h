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
#ifndef XC_FORMLCD_H
#define	XC_FORMLCD_H

#include <xc.h>

#include "formlcd.h"
#include "formlcd.h" // include processor files - each processor file is guarded.  

typedef struct sFiled {
    const char *lable;
    struct sFiled *next;
    struct sFiled *prv;
} stFiled_t;

typedef struct {
    uint8_t _minValue;
    uint8_t _maxValue;
    uint8_t _stepValue;
    uint8_t _value;
    uint8_t _printLen;
    const char * _suffix;
} IntField_t;
#define LCD_BUTTON_NONE             0
#define LCD_BUTTON_LEFT             1
#define LCD_BUTTON_RIGHT            2
#define LCD_BUTTON_UP               3
#define LCD_BUTTON_DOWN             4
#define LCD_BUTTON_SELECT           5


void lcdFormInit();
void IntField(stFiled_t *filed, const char *label, uint8_t minValue, uint8_t maxValue, uint8_t stepValue, uint8_t value);

/*add filed*/


#endif	/* XC_FORMLCD_H */

