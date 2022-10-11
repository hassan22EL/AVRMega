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
#ifndef XC_TWI_MASTER_H
#define	XC_TWI_MASTER_H
#include "../mega.h"


#define TWI_TWBR            0x0C 
#define     TWI_400KHZ                        (400000UL)
#define     TWI_100KHZ                        (100000UL)

#ifndef TWI_BUS_SPEED 
#define TWI_BUS_SPEED   TWI_400KHZ
#endif
/******************* Divided Frequncy*********************************/
#define  TWI_PRESCARE_1                                   (1UL)
#define  TWI_PRESCARE_4                                   (4UL) 
#define  TWI_PRESCARE_16                                  (16UL) 
#define  TWI_PRESCARE_64                                  (64UL) 

#define  TWI_INTERNAL_PULLUP     (0)
#define  TWI_EXTERNAL_PULLUP     (1)

/*******************caculate value for each pre-scaller   *********************************/
#define TWI_PRESCARE_1_TWRB_VALUE              ((F_CPU-(16UL*TWI_BUS_SPEED)+(TWI_PRESCARE_1*TWI_BUS_SPEED))/(TWI_BUS_SPEED*2UL*TWI_PRESCARE_1))//6
#define TWI_PRESCARE_4_TWRB_VALUE              ((F_CPU-(16UL*TWI_BUS_SPEED)+(TWI_PRESCARE_4*TWI_BUS_SPEED))/(TWI_BUS_SPEED*2UL*TWI_PRESCARE_4))//1
#define TWI_PRESCARE_16_TWRB_VALUE             ((F_CPU-(16UL*TWI_BUS_SPEED)+(TWI_PRESCARE_16*TWI_BUS_SPEED))/(TWI_BUS_SPEED*2UL*TWI_PRESCARE_16))//0
#define TWI_PRESCARE_64_TWRB_VALUE             ((F_CPU-(16UL*TWI_BUS_SPEED)+(TWI_PRESCARE_64*TWI_BUS_SPEED))/(TWI_BUS_SPEED*2UL*TWI_PRESCARE_64))//0



#if     (TWI_PRESCARE_1_TWRB_VALUE > TWI_PRESCARE_4_TWRB_VALUE)  && (TWI_PRESCARE_1_TWRB_VALUE > TWI_PRESCARE_16_TWRB_VALUE) && (TWI_PRESCARE_1_TWRB_VALUE >TWI_PRESCARE_64_TWRB_VALUE)
#define              TWI_TWRB_VALUE                 TWI_PRESCARE_1_TWRB_VALUE
#define              TWI_TWPS_VALUE                 ((0x00)&0x03)
#elif   (TWI_PRESCARE_4_TWRB_VALUE > TWI_PRESCARE_1_TWRB_VALUE) && (TWI_PRESCARE_4_TWRB_VALUE > TWI_PRESCARE_16_TWRB_VALUE) && (TWI_PRESCARE_4_TWRB_VALUE >TWI_PRESCARE_64_TWRB_VALUE)
#define              TWI_TWRB_VALUE                 TWI_PRESCARE_4_TWRB_VALUE
#define              TWI_TWPS_VALUE                 ((0x01)&0x03)
#elif   (TWI_PRESCARE_16_TWRB_VALUE > TWI_PRESCARE_1_TWRB_VALUE) && (TWI_PRESCARE_16_TWRB_VALUE > TWI_PRESCARE_4_TWRB_VALUE) && (TWI_PRESCARE_16_TWRB_VALUE >TWI_PRESCARE_64_TWRB_VALUE)
#define              TWI_TWRB_VALUE                 TWI_PRESCARE_16_TWRB_VALUE
#define              TWI_TWPS_VALUE                 ((0x02)&0x03)
#elif   (TWI_PRESCARE_64_TWRB_VALUE > TWI_PRESCARE_1_TWRB_VALUE) && (TWI_PRESCARE_64_TWRB_VALUE > TWI_PRESCARE_4_TWRB_VALUE) && (TWI_PRESCARE_64_TWRB_VALUE >TWI_PRESCARE_16_TWRB_VALUE)
#define              TWI_TWRB_VALUE                  TWI_PRESCARE_64_TWRB_VALUE
#define              TWI_TWPS_VALUE                 ((0x03)&0x03)
#endif









#ifndef F_CPU
#warning "This Drive need the FCPU please define f_cpu"
#endif

/**/
typedef union TWI_statusReg {
    uint8_t all;

    struct {
        uint8_t lastTransOK : 1;
        uint8_t unusedBits : 7;
    };
} TWI_statusReg_t;




void TWI_Init(void);
uint8_t TWI_Start_Transceiver(void);
uint8_t TWI_Start_Transceiver_With_Data(uint8_t *, uint8_t);
uint8_t TWI_Transceiver_Busy(void);
uint8_t TWI_Get_State_Info(void);
uint8_t TWI_Get_Data_From_Transceiver(uint8_t *, uint8_t);


/****************************************************************************
  Bit and byte definitions
 ****************************************************************************/
#define TWI_READ_BIT  0       // Bit position for R/W bit in "address byte".
#define TWI_ADR_BITS  1       // Bit position for LSB of the slave address bits in the init byte.

#define TRUE          1
#define FALSE         0

/****************************************************************************
  TWI State codes
 ****************************************************************************/
// General TWI Master staus codes                      
#define TWI_START                  0x08  // START has been transmitted  
#define TWI_REP_START              0x10  // Repeated START has been transmitted
#define TWI_ARB_LOST               0x38  // Arbitration lost

// TWI Master Transmitter staus codes                      
#define TWI_MTX_ADR_ACK            0x18  // SLA+W has been tramsmitted and ACK received
#define TWI_MTX_ADR_NACK           0x20  // SLA+W has been tramsmitted and NACK received 
#define TWI_MTX_DATA_ACK           0x28  // Data byte has been tramsmitted and ACK received
#define TWI_MTX_DATA_NACK          0x30  // Data byte has been tramsmitted and NACK received 

// TWI Master Receiver staus codes  
#define TWI_MRX_ADR_ACK            0x40  // SLA+R has been tramsmitted and ACK received
#define TWI_MRX_ADR_NACK           0x48  // SLA+R has been tramsmitted and NACK received
#define TWI_MRX_DATA_ACK           0x50  // Data byte has been received and ACK tramsmitted
#define TWI_MRX_DATA_NACK          0x58  // Data byte has been received and NACK tramsmitted

// TWI Slave Transmitter staus codes
#define TWI_STX_ADR_ACK            0xA8  // Own SLA+R has been received; ACK has been returned
#define TWI_STX_ADR_ACK_M_ARB_LOST 0xB0  // Arbitration lost in SLA+R/W as Master; own SLA+R has been received; ACK has been returned
#define TWI_STX_DATA_ACK           0xB8  // Data byte in TWDR has been transmitted; ACK has been received
#define TWI_STX_DATA_NACK          0xC0  // Data byte in TWDR has been transmitted; NOT ACK has been received
#define TWI_STX_DATA_ACK_LAST_BYTE 0xC8  // Last data byte in TWDR has been transmitted (TWEA = ?0?); ACK has been received

// TWI Slave Receiver staus codes
#define TWI_SRX_ADR_ACK            0x60  // Own SLA+W has been received ACK has been returned
#define TWI_SRX_ADR_ACK_M_ARB_LOST 0x68  // Arbitration lost in SLA+R/W as Master; own SLA+W has been received; ACK has been returned
#define TWI_SRX_GEN_ACK            0x70  // General call address has been received; ACK has been returned
#define TWI_SRX_GEN_ACK_M_ARB_LOST 0x78  // Arbitration lost in SLA+R/W as Master; General call address has been received; ACK has been returned
#define TWI_SRX_ADR_DATA_ACK       0x80  // Previously addressed with own SLA+W; data has been received; ACK has been returned
#define TWI_SRX_ADR_DATA_NACK      0x88  // Previously addressed with own SLA+W; data has been received; NOT ACK has been returned
#define TWI_SRX_GEN_DATA_ACK       0x90  // Previously addressed with general call; data has been received; ACK has been returned
#define TWI_SRX_GEN_DATA_NACK      0x98  // Previously addressed with general call; data has been received; NOT ACK has been returned
#define TWI_SRX_STOP_RESTART       0xA0  // A STOP condition or repeated START condition has been received while still addressed as Slave

// TWI Miscellaneous status codes
#define TWI_NO_STATE               0xF8  // No relevant state information available; TWINT = ?0?
#define TWI_BUS_ERROR              0x00  // Bus error due to an illegal START or STOP condition



#endif	/* XC_HEADER_TEMPLATE_H */

