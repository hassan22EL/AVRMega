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
#ifndef XC_DATA_MANGMENTS_H
#define	XC_DATA_MANGMENTS_H
#include "appRes.h"
#define  PONIT_DATA_LENTH         (10)
#define  DATA_PAGE0_ADDRESS       (0x0002)
#define  DATA_INDEX                (3)
#define  MEM_BASE_ADDRESS          0xA0
#define  MEM_TYPE_COFIG            (0)
#define  MEM_TYPE_DATA             (1)
#define  MEM_MAX_VALUE             (128)

#define MEM_PAGE0                 (0)
#define MEM_PAGE1                 (1)
#define MEM_PAGE2                 (2)
#define MEM_PAGE3                 (3)


#define      MAX_ZONE                  (3)
#define      MAX_BASE_DATA_CONFIG       (128)
#define      MAX_ZONE_DATA                 (MAX_BASE_DATA_CONFIG /8)
#define      MAX_POINT_DATA              (9) /*9Byte*/
#define      MAX_POINTS_ADDRESS          (0x00)
#define      START_ZONE_ADDRESS          (MAX_POINTS_ADDRESS + (MAX_POINT_DATA * MAX_BASE_DATA_CONFIG)+MAX_POINT_DATA)
extern uint8_t gu8PointsData[MAX_BASE_DATA_CONFIG][2];
extern uint8_t gu8callPoint[MAX_POINT_DATA];
extern uint8_t gu8appZone[MAX_ZONE_DATA];
extern volatile uint8_t gu8appMemIndex;
extern volatile uint8_t gu8appMemZoneDevice;
#define  MEM_DONE                             (0x00)
#define  MEM_ERROR_INVLIAD_ADD                (0x01)
#define  MEM_ERROR_INVLIAD_RA                 (0x02)
#define  MEM_ERROR_INVLID_DSA                 (0x03)
#define  MEM_ERROR_BLOCKED_ADDRESS            (0x04)
#define  MEM_ERROR_RA_NOT_FOUND               (0x05)
#define  MEM_ERROR_DA_NOT_FOUND               (0x06)

typedef enum {
    ID = 0,
    RA = 1,
    lastConfig = 2,
    Data1 = 3,
    calltime = 4,
    callcomm = 8,
} EnCallPointData;



void appMemInit();
/*Call Backs Function*/
uint8_t appMemCreatePoint();
uint8_t appMemCreateZone();
uint8_t appMemEraseConfig();
uint8_t appMemEraseData();
uint8_t appMemEraseZone();

/*Power On Function*/

uint8_t appMemoryStart();
uint8_t appMemPowerOn();
uint8_t appMemNext(uint8_t Address);
uint8_t appgetLastAddress();

uint8_t appMemSaveDate(uint8_t *structSave, uint8_t length, uint16_t address, uint8_t offset);
uint8_t appMemLoadDate(uint8_t *structLoad, uint8_t length, uint16_t address, uint8_t offset);
#endif	/* XC_DATA_MANGMENTS_H */

