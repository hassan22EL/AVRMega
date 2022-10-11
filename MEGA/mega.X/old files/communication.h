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
 * Author: Hassan Elsayed
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_COMMUNICATION_H
#define	XC_COMMUNICATION_H

#include "../mega.h"




#define MASTER    (1)
#define SLAVE     (0)

#ifndef DECIVE_TYPE
#define DECIVE_TYPE    (MASTER)
#endif

#ifndef Master_Address
#define Master_Address    (254)
#endif

/*communication Flags*/
#define NETWORK_FLAG         (0)
#define BUS_FLAG             (1) 
#define RECEIVETIMEOUT_FLAG  (2)
#define SENDREQUEST_FLAG     (3)
#define BYTESEND_FLAG        (4)
#define COLLISION_FLAG       (5)
#define RECEIVE_FLAG         (6)
#define SEND_FLAG            (7)
/*network Flags*/
#define NET_FLAG               (0)
#define CLINET_FLAG            (1)
#define HOST_FLAG              (2)
#define BUFFER_STORE_NEW_FRAME (3)


/*transmission state*/
#define NETWORK_RET_OK           (1)
#define NETWORK_RET_RUNNING      (0)
#define NETWORK_RET_KO           (2)


#define COMM_BUFFER_LENGTH   (11) /*max send 8byte of data and 1- byte addres and 1- byte length of data and 1- byte LRC*/
/*net work buffer length*/
#define NET_BUFFER_LENGTH   (4)*(8) /*four frame max store into network buffer*/

/*Timing */
/*delay unit*/
#define u8TimeByteTransmit   ((((10UL)*(1000000UL))/(BaudRate))) /*this is us in this case the data = 521 us*/
/*convert 520 us to ms */
#define TimeTosendFrameUSToMs   ((((2UL)*(u8TimeByteTransmit)) + (1000UL))/(2000UL)) /*this time by ms*/
/*convert to ms to tick*/
#define FrameDelayunit               (TimeTosendFrameUSToMs)

#define RECEIVE_TIME_OUT         (FrameDelayunit)
#define MASTER_TIME_OUT          (RECEIVE_TIME_OUT)
#define SLAVE_TIME_OUT           (MASTER_TIME_OUT) 
#define TRANSMISSION_TIME_OUT    (10000UL)

#define BACK_OFF_RANG            (5UL)

/*pointer to function has a new data received*/

/*Tx State*/
#define TX_IDLE   state_00
#define TX_BUS    state_01
#define TX_SEND   state_02
#define TX_CHECK  state_03
#define TX_END    state_04
/*Rx State*/
#define RX_IDLE     state_00
#define RX_RECEIVE  state_01
#define RX_TIMEOUT  state_02 
#define RX_ERROR    state_03
#define RX_PROCESS  state_04
/*Network  State*/
#define NET_CHECK_CLIENT  state_00
#define NET_NEW_FRAME     state_01
#define NET_FRAME_EXECUATION state_02

/*Frame indexing*/
typedef enum _eFrameIndex {
    Address = 0,
    bytecount = 1,
    startbyte = 2
} eFrameIndex;

/*
 * Frame Format (Buffer)
 *--------------------------------------
 * | Address | ByteNumber | Data | LCR |
 * -------------------------------------
 */
typedef struct _sFram {
    volatile uint8_t u8Address;
    volatile uint8_t u8ByteCount;
    volatile uint8_t u8Data[COMM_BUFFER_LENGTH - startbyte - 1];
} sFrame;


/*
 * physical layer flag
 * -------------------------------------------
 * | SF | RF | CF | BSF | SRF | REF | BF | NF | 
 * -------------------------------------------
 * bit7 : SF ==> send flag
 * bit6 : RF ==> receive Flag
 * bit5 : CF ==> collision Flag
 * bit4 : BSF ==> Byte Send Flag
 * bit3 : SRF ==> Send request Flag
 * bit2 : REF ==> Receive Time out Flag
 * bit1 : BF ==>  Bus Flag
 * bit0 : NF ==> Network layer Flag
 */

extern volatile uint8_t gu8AddressByte;
/*Frame of the Transmission */
extern sFrame gsTransmissionFrame;
/*Frame of the Receive*/
extern sFrame gsReceiveFrame;
/*Network Frame*/
extern sFrame gsNetworkFrame;
/*Functions*/

/*Init values*/
void commInit();
/*communication layer driver*/
void commDriver();
/*new frame send*/
void StartTransmission();
/*new Received data*/
void OnHostFrame(pAsyncFunc_t receiveFrame);
/*open communication*/
uint8_t IsCommunicationOpen();

#endif	/* XC_COMMUNICATION_H */

