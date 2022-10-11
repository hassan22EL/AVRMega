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
#ifndef XC_TWI_H
#define	XC_TWI_H

#include "../mega.h"  

typedef struct {
    uint8_t slave_adr; //Slave address and W/R byte
    uint8_t size; //Number of bytes to send or 
    //receive 	
    uint8_t *data_ptr; //Pointer to the bytes to send
} stTWi_Tx; //or pointerto RX buffer 


/****************************************************************************
    Function definitions
 ****************************************************************************/
uint8_t Send_to_TWI(stTWi_Tx * data_pack, uint8_t u8lenth);
uint8_t Send_byte(uint8_t); //Send one byte
uint8_t Get_byte(uint8_t*rx_ptr, uint8_t u8Max, uint8_t last_byte);
uint8_t Send_start(void); //Send a Start condition
uint8_t Send_adr(uint8_t); //Send a Slave adr.
void Send_stop(void); //Send a Stop condition
void Wait_TWI_int(void); //Wait for TWI interrupt to occur
void Reset_TWI(void); //Reset the TWI module and 
//release the bus
uint8_t Send_to_TWI_FRAM(stTWi_Tx *data_pack);
void twiInitFram(stTWi_Tx *stTwiFram, uint8_t u8Size, uint8_t *u8Data);
void Init_TWI(void);
void TWI_READY();
void TWI_BUSY();
uint8_t TWI_ISReady();
uint8_t TWI_start(uint8_t SLA);
/****************************************************************************
Bit and byte definitions
 ****************************************************************************/
#define  TWI_W 				0					//Data transfer direction WRITE
#define  TWI_R 				1					//Data transfer direction READ
#define  TWI_OWN_ADR 		60  				//Own slave address
#define  TWI_SUCCESS 		0xFF
#define  TWI_INTERNAL_PULLUP     (0)
#define  TWI_EXTERNAL_PULLUP     (1)

#ifndef   TWI_ISR_ACTIVE
#define  TWI_ISR_ACTIVE     TWI_POL
#endif 


//General Master staus codes											
#define TWI_START		0x08					//START has been transmitted	
#define	TWI_REP_START	0x10					//Repeated START has been 
//transmitted	
//Master Transmitter staus codes											
#define	MTX_ADR_ACK		0x18				//SLA+W has been tramsmitted
//and ACK received	
#define	MTX_ADR_NACK	0x20				//SLA+W has been tramsmitted
//and NACK received		
#define	MTX_DATA_ACK	0x28				//Data byte has been tramsmitted
//and ACK received			
#define	MTX_DATA_NACK	0x30				//Data byte has been tramsmitted
//and NACK received			
#define	MTX_ARB_LOST	0x38				//Arbitration lost in SLA+W or 
//data bytes	
//Master Receiver staus codes	
#define	MRX_ARB_LOST	0x38				//Arbitration lost in SLA+R or 
//NACK bit
#define	MRX_ADR_ACK		0x40				//SLA+R has been tramsmitted
//and ACK received	
#define	MRX_ADR_NACK	0x48				//SLA+R has been tramsmitted
//and NACK received		
#define	MRX_DATA_ACK	0x50				//Data byte has been received
//and ACK tramsmitted
#define	MRX_DATA_NACK	0x58				//Data byte has been received
//and NACK tramsmitted

/*******************CLOCK Frequncy******************************/
#define     TWI_400KHZ                        (400000UL)
#define     TWI_100KHZ                        (100000UL)
/****************************ISR********************************/
#define     TWI_ISR                            (0)
#define     TWI_POL                            (1)
/****************************************************************
 *                     F_CPU                                    *
 **************************************************************** 
 */
#ifndef F_CPU
#warning "This Drive need the FCPU please define f_cpu"
#endif
/****************************************************************
 *                      I2C BUS SPEED                           *
 **************************************************************** 
 */
#ifndef TWI_BUS_SPEED 
#define TWI_BUS_SPEED   TWI_400KHZ
#endif

/******************* Divided Frequncy*********************************/
#define  TWI_PRESCARE_1                                   (1UL)
#define  TWI_PRESCARE_4                                   (4UL) 
#define  TWI_PRESCARE_16                                  (16UL) 
#define  TWI_PRESCARE_64                                  (64UL) 

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


#define              TWI_MASTER           (0)
#define              TWI_SLAVE            (1)
#define              TWI_COMM             (2)


#endif	/* XC_TWI_H */

