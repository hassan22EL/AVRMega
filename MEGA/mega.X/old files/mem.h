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
#ifndef XC_MEM_H
#define	XC_MEM_H

#include "../mega.h"
#if  (I2C_MODULE == 0)
#error  "Pleas Enable I2C Module"
#endif

#define  MEM_SIZE_32K     (0)
#define  MEM_SIZE_64K     (1)
#define  MEM_SIZE_128K    (2)
#define  MEM_SIZE_256K    (3)

typedef struct {
    uint8_t u8BaseAddress;
    uint8_t u8FirstAddress;
    uint8_t u8SecondAddress;
    uint8_t *u8Data;
    uint8_t u8DataLength;
} stI2cMemDis_t;

/*app interface*/
void i2cMemInit(stI2cMemDis_t * stI2cMem, uint8_t * u8Data, uint8_t u8DataLength, uint8_t u8BaseAddress);
uint8_t Mem8BitAddress(stI2cMemDis_t * stI2cMem, uint8_t u8Address);
uint8_t Mem16BitAddress(stI2cMemDis_t * stI2cMem, uint16_t u16Address, uint8_t u8MemSize);
uint8_t i2cMemLoad(stI2cMemDis_t * stI2cMem); /*retrun state*/
uint8_t i2cMemSave(stI2cMemDis_t *stI2cMem); /*write data and return*/

#endif	/* XC_MEM_H */

