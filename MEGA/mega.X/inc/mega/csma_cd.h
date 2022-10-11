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
#ifndef XC_CSMA_CD_H
#define	XC_CSMA_CD_H

#include "gpio.h"
#include "uart.h"
#include "csma_cd.h"


#define MASTER    (0x01)
#define SLAVE     (0x02)
#define RECEIVE   (0x03)

#define         POINT_ADDRESS            0x01
#define         PIN_ADDRESS              0x00

#ifndef        CSMA_ADDRESS 
#define        CSMA_ADDRESS        PIN_ADDRESS
#endif

#ifndef DECIVE_TYPE
#define DECIVE_TYPE    (MASTER)
#endif

#ifndef Master_Address
#define Master_Address    (0)
#endif
#define   CSMA_FREE_ADDRESS          0x81
#define   CSMA_BLOCK_ADDRESS         0x80
#if DECIVE_TYPE == SLAVE
#if  CSMA_ADDRESS == PIN_ADDRESS
#ifndef       CSMA_A0 
#define      CSMA_A0                       NOT_A_PIN
#endif 

#ifndef       CSMA_A1 
#define      CSMA_A1                      NOT_A_PIN
#endif 
#ifndef       CSMA_A2 
#define      CSMA_A2                       NOT_A_PIN
#endif 
#ifndef       CSMA_A3 
#define      CSMA_A3                      NOT_A_PIN
#endif 
#ifndef       CSMA_A4 
#define      CSMA_A4                       NOT_A_PIN
#endif 
#ifndef       CSMA_A5 
#define      CSMA_A5                       NOT_A_PIN
#endif 
#ifndef       CSMA_A6 
#define      CSMA_A6                       NOT_A_PIN
#endif 
#endif
#endif

#define   CSMA_TYPED_BLOCKED       0x00
#define   CSMA_TYPED_NORMAL        0x01

typedef struct {
    uint8_t u8Address;
    uint8_t u8ByteCount;
    uint8_t u8Data[8]; // 8byte data
} stFram_t;

typedef enum _eFrameIndex {
    Address = 0,
    bytecount = 1,
    startbyte = 2
} eFrameIndex;



extern stFram_t gsTransmissionFrame;
extern stFram_t gsReceiveFrame;


#define  COMM_BUFFER_LENGTH      (11) 

#define DATA_REMOVED             (128)





#define  FREQUNCY_VALUE(x)        ((1000000UL) / x)+1       
#define  REGITER_RECIVE_VALUE   (F_CPU / (64UL * ByteBuadRate))
#define  REGISTER_BLOCKED_VALUE        (F_CPU / (64UL * 10UL))

#define  CSMA_BIT_DURATION            ((1000000UL)/BaudRate)
#define  BYTE_DURATION           ((1000000UL)/ByteBuadRate)

#define          CSMA_RESPONSE_TIME_OUT_US        (127UL*2UL*CSMA_BIT_DURATION) + (COMM_BUFFER_LENGTH*BYTE_DURATION) + (2*BYTE_DURATION)
#define          CSMA_RESPONSE_TIME_OUT_MS        (CSMA_RESPONSE_TIME_OUT_US / 1000UL)

#define           REGITER_CONTROL_A              0x00
#define           REGITER_CONTROL_B              0x0B
#if  ATMEGA128A
#define           REFITER_CONTROL_E              0x10
#else
#define           REFITER_CONTROL_E              0x02
#endif








void csmaInit();
void csmaDriver();
void StartTransmission();
void OnHostFrame(pAsyncFunc_t receiveFrame);
void OnClientFrame(pAsyncFunc_t receiveFrame);
uint8_t csmaGetAddress();

uint8_t IsCommunicationOpen();
#if  CSMA_ADDRESS == POINT_ADDRESS
void csmaSetAddress(uint8_t address);
#endif



#endif	/* XC_CSMA_CD_H */

