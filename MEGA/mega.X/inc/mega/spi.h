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
#ifndef XC_SPI_H
#define	XC_SPI_H




#ifndef F_CPU
#warning "This Drive need the FCPU please define f_cpu"
#endif


#define  SPI_RX_BUFFER_SIZE          (8)
#define  SPI_TX_BUFFER_SIZE          (8)


#define  SPI_MASTER_MODE      (1)
#define  SPI_SLAVE_MODE       (0)


#define  SPI_IDLE_HIGH        (1)
#define  SPI_IDLE_LOW         (0)

#define      SPI_CLOCK_4                    (0)
#define      SPI_CLOCK_16                   (1)
#define      SPI_CLOCK_64                   (2)
#define      SPI_CLOCK_128                  (3)

#define  SPI_SAMPLE_R           (0)
#define  SPI_SETUP_R            (1)
#define  SPI_SAMPLE_F           (2)
#define  SPI_SETUP_F            (3)

#define   SPI_DOUBLE_SPEED      (1)
#define   SPI_NORMAL_SPEED      (0)

#define    SPI_LSB_FIRST        (1)
#define    SPI_MSB_FIRST        (0)


#ifndef  SPI_MODE             
#define  SPI_MODE             SPI_MASTER_MODE
#endif 

#ifndef  SPI_CLK_MODE
#define  SPI_CLK_MODE            SPI_SETUP_R
#endif 

#ifndef    SPI_CLOCK
#define    SPI_CLOCK              SPI_CLOCK_64
#endif


#ifndef        SPI_SPEED           
#define        SPI_SPEED           SPI_NORMAL_SPEED
#endif

#ifndef        SPI_DATA_SEND
#define        SPI_DATA_SEND          SPI_LSB_FIRST
#endif


#ifndef        SPI_SS_PIN
#define        SPI_SS_PIN              NOT_A_PIN
#endif 

#ifndef        SPI_SCLK_PIN
#define        SPI_SCLK_PIN            NOT_A_PIN
#endif

#ifndef        SPI_MOSI_PIN
#define        SPI_MOSI_PIN            NOT_A_PIN
#endif 

#ifndef        SPI_MISO_PIN
#define        SPI_MISO_PIN            NOT_A_PIN
#endif 


#if (SPI_MODE == SPI_MASTER_MODE) 
void spiInit(void);
void spiMasterTransmit(uint8_t *byte , uint8_t length);
void spiMasterRead(uint8_t u8NumberofByte);
void spiStart(uint8_t Cspin);
void spiStop(uint8_t u8Pin);
uint8_t spiReady();

#elif (SPI_MODE == SPI_SLAVE_MODE)
void spiInit(void);
#endif
#endif	/* XC_SPI_H */

