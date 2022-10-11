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
#ifndef XC_APPMENUMEMORY_H
#define	XC_APPMENUMEMORY_H

#include "appRes.h"


typedef struct {
    uint8_t index;
    uint8_t pAddressR;
    uint8_t pAddressP;
    uint8_t pAddressD;
    uint8_t pID;
    uint8_t Status;
    time_t Date;
} BasePoint_t;


uint8_t appMemMaxRooms();

uint8_t appMemLoad(BasePoint_t *baseP, uint8_t Index, uint8_t type);
uint8_t appMemStore(BasePoint_t *baseP, uint8_t Index, uint8_t type);

void appMemCreateBasePonit(BasePoint_t *baseP, uint8_t index, uint8_t addressP, uint8_t addressR, uint8_t id, uint8_t status, time_t date);

uint8_t appMemMaxBads();
uint8_t appMemBads();
uint8_t appMemRooms();
uint8_t appMemResetData();
uint8_t appMemResetALLData();

void appMemInit();
#endif	/* XC_APPMENUMEMORY_H */

