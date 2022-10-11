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
#ifndef XC_I2C_H
#define	XC_I2C_H

#include "../mega.h"

typedef enum {
    I2C_STATE_IDLE = 0x00,
    I2C_STATE_ADD_ACK = 0x01,
    I2C_STATE_ADD_NACK = 0x02,
    I2C_STATE_ARBIT = 0x03,
    I2C_STATE_TX_DATA_ACK = 0x04,
    I2C_STATE_TX_DATA_NACK = 0x05,
    I2C_STATE_RX_DATA_ACK = 0x06,
    I2C_STATE_RX_DATA_NACK = 0x07,
    I2C_STATE_WAIT = 0x08,

    I2C_SLAVE_STATE_IDLE = 0x10,
    I2C_SLAVE_STATE_TX_PROCESS = 0x20,
    I2C_SLAVE_STATE_TX_OUTSIDE = 0x30,
    I2C_SLAVE_STATE_TX_SUCESS = 0x40,
    I2C_SLAVE_STATE_TX_FAILE = 0x50,
    I2C_SLAVE_RX_STOP_RESTART = 0x60,
    I2C_SLAVE_RX_PORCESS = 0x70,
    I2C_SLAVE_RX_OUTSIDE = 0x80,
    I2C_SLAVE_WAIT = 0x90,
    I2C_SLAVE_DATA_NACK = 0xA0
} etState;






#define I2C_MASTER_MASK              0x0F
#define I2C_SLAVE_MASK               0xF0






#define  I2C_INTERNAL_PULLUP     (0)
#define  I2C_EXTERNAL_PULLUP     (1)

/****************************************************************
 *                     I2C ACK                                    *
 **************************************************************** 
 */
#define                   I2C_ACK               (1)
#define                   I2C_NACK              (0)

/****************************************************************
 *                     I2C General bit                                    *
 **************************************************************** 
 */
#define                   I2C_GEN_ENABLE               (1)
#define                   I2C_GEN_DISABLE              (0)
/****************************************************************
 *                     I2C Operation                                    *
 **************************************************************** 
 */
#define                   I2C_READ_MASK               (0x01)  // address | with This Values
#define                   I2C_WRITE_MASK              (0xFE)  //address & with This Value
#define                   I2C_SLA_READ                (0x01)
#define                   I2C_SLA_WRITE               (0x00)

#define                   I2C_SLA_W(ADDRESS)             (ADDRESS & I2C_WRITE_MASK)
#define                   I2C_SLA_R(ADDRESS)             (ADDRESS | I2C_READ_MASK )


#define              I2C_MASTER           (0)
#define              I2C_SLAVE            (1)
#define              I2C_COMM             (2)

/*******************CLOCK Frequncy******************************/
#define     I2C_400KHZ                        (400000UL)
#define     I2C_100KHZ                        (100000UL)
/****************************ISR********************************/
#define     I2C_ISR                            (0)
#define     I2C_POL                            (1)
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
#ifndef I2C_BUS_SPEED 
#define I2C_BUS_SPEED   I2C_400KHZ
#endif

/******************* Divided Frequncy*********************************/
#define  I2C_PRESCARE_1                                   (1UL)
#define  I2C_PRESCARE_4                                   (4UL) 
#define  I2C_PRESCARE_16                                  (16UL) 
#define  I2C_PRESCARE_64                                  (64UL) 

/*******************caculate value for each pre-scaller   *********************************/
#define I2C_PRESCARE_1_TWRB_VALUE              ((F_CPU-(16UL*I2C_BUS_SPEED)+(I2C_PRESCARE_1*I2C_BUS_SPEED))/(I2C_BUS_SPEED*2UL*I2C_PRESCARE_1))//6
#define I2C_PRESCARE_4_TWRB_VALUE              ((F_CPU-(16UL*I2C_BUS_SPEED)+(I2C_PRESCARE_4*I2C_BUS_SPEED))/(I2C_BUS_SPEED*2UL*I2C_PRESCARE_4))//1
#define I2C_PRESCARE_16_TWRB_VALUE             ((F_CPU-(16UL*I2C_BUS_SPEED)+(I2C_PRESCARE_16*I2C_BUS_SPEED))/(I2C_BUS_SPEED*2UL*I2C_PRESCARE_16))//0
#define I2C_PRESCARE_64_TWRB_VALUE             ((F_CPU-(16UL*I2C_BUS_SPEED)+(I2C_PRESCARE_64*I2C_BUS_SPEED))/(I2C_BUS_SPEED*2UL*I2C_PRESCARE_64))//0


#if     (I2C_PRESCARE_1_TWRB_VALUE > I2C_PRESCARE_4_TWRB_VALUE)  && (I2C_PRESCARE_1_TWRB_VALUE > I2C_PRESCARE_16_TWRB_VALUE) && (I2C_PRESCARE_1_TWRB_VALUE >I2C_PRESCARE_64_TWRB_VALUE)
#define              I2C_TWRB_VALUE                 I2C_PRESCARE_1_TWRB_VALUE
#define              I2C_TWPS_VALUE                 ((0x00)&0x03)
#elif   (I2C_PRESCARE_4_TWRB_VALUE > I2C_PRESCARE_1_TWRB_VALUE) && (I2C_PRESCARE_4_TWRB_VALUE > I2C_PRESCARE_16_TWRB_VALUE) && (I2C_PRESCARE_4_TWRB_VALUE >I2C_PRESCARE_64_TWRB_VALUE)
#define              I2C_TWRB_VALUE                 I2C_PRESCARE_4_TWRB_VALUE
#define              I2C_TWPS_VALUE                 ((0x01)&0x03)
#elif   (I2C_PRESCARE_16_TWRB_VALUE > I2C_PRESCARE_1_TWRB_VALUE) && (I2C_PRESCARE_16_TWRB_VALUE > I2C_PRESCARE_4_TWRB_VALUE) && (I2C_PRESCARE_16_TWRB_VALUE >I2C_PRESCARE_64_TWRB_VALUE)
#define              I2C_TWRB_VALUE                 I2C_PRESCARE_16_TWRB_VALUE
#define              I2C_TWPS_VALUE                 ((0x02)&0x03)
#elif   (I2C_PRESCARE_64_TWRB_VALUE > I2C_PRESCARE_1_TWRB_VALUE) && (I2C_PRESCARE_64_TWRB_VALUE > I2C_PRESCARE_4_TWRB_VALUE) && (I2C_PRESCARE_64_TWRB_VALUE >I2C_PRESCARE_16_TWRB_VALUE)
#define              I2C_TWRB_VALUE                  I2C_PRESCARE_64_TWRB_VALUE
#define              I2C_TWPS_VALUE                 ((0x03)&0x03)
#endif

#define   I2C_STATUS_CODE_MASK                 (0xF8)
/*
 ****************************************************************
 *            Status Codes for Master Transmitter Mode          *
 **************************************************************** 
 */
/*********************** master start transmission ***********************/
#define  I2C_START                             (0x08)
/*********************** master send a new byte *************************/
#define  I2C_REPEAT_START                      (0x10)
/***********************address  ACK***********************************/
#define  I2C_MTX_ADR_ACK                       (0x18)
/*********************** address NACK  ********************************/
#define  I2C_MTX_ADR_NACK                      (0x20)
/*********************** Data ACK ************************************/
#define  I2C_MTX_DATA_ACK                      (0x28)
/*********************** Data NACK **********************************/
#define  I2C_MTX_DATA_NACK                     (0x30)
/*********************** arbitration *******************************/
#define  I2C_ARBITRATION                       (0x38)

/*
 ****************************************************************
 *            Status Codes for Master Receive Mode              *
 **************************************************************** 
 */

/*********************** Received address with not ack return  *******************************/
#define  I2C_MRX_ADR_ACK                    (0x40)
/*********************** Received address with  ack return  *******************************/
#define  I2C_MRX_ADR_NACK                   (0x48)
/*********************** Received data with not ack return  *******************************/
#define  I2C_MRX_DATA_ACK                   (0x50)
/*********************** Received data with  ack return  *******************************/
#define  I2C_MRX_DATA_NACK                  (0x58)
/*
 ****************************************************************
 *            Status Codes for SLAVE Receive Mode              *
 **************************************************************** 
 */

/*********************** Received address with not ack return  *******************************/
#define  I2C_SRX_ADR_ACK                                    (0x60)
/*********************** Received DATA with  ack return  *******************************/
#define  I2C_SRX_ADR_NACK                                   (0x68)
/*********************** Received all address with  ack return  *******************************/
#define  I2C_SRX_GENERAL_ADR_ACK                            (0x70)
/*********************** Received all address with  ack return  *******************************/
#define  I2C_SRX_GENERAL_ADR_NACK                           (0x78)
/*********************** Received DATA with  ack return  *******************************/
#define  I2C_SRX_DATA_ACK                                   (0x80)
/*
 ****************************************************************
 *            Status Codes for SLAVE Transmitter Mode            *
 **************************************************************** 
 */
/*********************** Received address with not ack return  *******************************/
#define  I2C_STX_SLA_R_ACK                                  (0xA8)
/*********************** Received With arbitratrion   *******************************/
#define  I2C_STX_SLA_R_ACK_Arbitration                      (0xB0)
/*********************** Received all address with  ack return  *******************************/
#define  I2C_STX_DATA_ACK                                   (0xB8)
/*********************** Received all address with  ack return  *******************************/
#define  I2C_STX_DATA_NACK                                  (0xC0)
/*********************** Received DATA with  ack return  *******************************/
#define  I2C_STX_LAST_DATA_ACK                              (0xC8)

/*
 ****************************************************************
 *            Status Codes for SLAVE Receive Mode               *
 **************************************************************** 
 */
/*********************** Received address with not ack return  *******************************/
#define  I2C_SRX_SLA_W_ACK                                  (0x60)
/*********************** Received With arbitratrion   *******************************/
#define  I2C_SRX_SLA_W_ACK_ARBITRATION                      (0x68)
/*********************** Received all address with  ack return  *******************************/
#define  I2C_SRX_GEN_ACK                                    (0x70)
/*********************** Received all address with  ack return  *******************************/
#define  I2C_SRX_GEN_ACK_ARBITRATION                        (0x78)
/*********************** Received DATA with  ack return  *******************************/
#define  I2C_SRX_ADR_DATA_ACK                               (0X80)
/*********************** Received DATA with  ack return  *******************************/
#define  I2C_SRX_ADR_DATA_NACK                              (0X88)
/*********************** Received DATA with  ack return  *******************************/
#define  I2C_SRX_GEN_DATA_ACK                               (0x90)
/*********************** Received DATA with  ack return  *******************************/
#define  I2C_SRX_GEN_DATA_NACK                              (0x98)
/*********************** Received DATA with  ack return  *******************************/
#define  I2C_SRX_STOP_RSTART                                (0xA0)

static inline void i2cHwInit() {
    /********************IDLE STATE OF BUS equal one*****************/
    TWDR = 0xFF;
    /***********************SET BIT RATE*****************************/
    TWBR = (uint8_t) I2C_TWRB_VALUE;
    /***********************SET PRESCALLER***************************/
    TWSR |= (I2C_TWPS_VALUE);
    /***********************Enable Two Wire interface****************/
    TWCR |= (1 << TWEN);
    /***********************Clear STOP Condition****************/
    TWCR &= ~(1 << TWSTA);
    /***********************Clear ACK************************************/
    TWCR &= ~(1 << TWEA);
    /***********************Clear collision in Wire interface****************/
    TWCR &= ~(1 << TWWC);
    /***********************Enable Interrupt  **********************/
#if (I2C_ISR_ACTIVE== I2C_ISR)   
    TWCR |= (1 << TWIE);
#else
    TWCR &= ~(1 << TWIE);
    /************************Enable Generale Interrupt****************/
    cei();
#endif
    /************************Clear  Interrupt Flag******************/
    TWCR |= (1 << TWINT);
}

static inline void i2cHwStart() {
    /************************SET START Condition ******************/
    TWCR |= (1 << TWSTA);
    /************************Clear Stop Condition ******************/
    TWCR &= ~(1 << TWSTO);
    /************************Clear Interrupt Flag***************************/
    TWCR |= (1 << TWINT);
}

static inline void i2cHwStop() {
    /************************Clear START Condition ******************/
    TWCR &= ~(1 << TWSTA);
    /************************Set Stop Condition ******************/
    TWCR |= (1 << TWSTO);

    /************************Clear Interrupt Flag***************************/
    TWCR |= (1 << TWINT);
}

static inline void i2cHwCondition() {
    /************************Clear START Condition ******************/
    TWCR &= ~(1 << TWSTA);
    /************************Clear Stop Condition ******************/
    TWCR &= ~(1 << TWSTO);
    /***********************Clear collision in Wire interface****************/
    TWCR &= ~(1 << TWWC);
    /************************Clear Interrupt Flag***************************/
    TWCR |= (1 << TWINT);

}

static inline void i2cResetInterruptFlag() {
    /************************Clear Interrupt Flag***************************/
    TWCR |= (1 << TWINT);
}

static inline void i2cHwACK(uint8_t gu8Ack) {
    if (gu8Ack) {
        /***********************Set ACK************************************/
        TWCR |= (1 << TWEA);
    } else {
        /***********************Clear ACK************************************/
        TWCR &= ~(1 << TWEA);
    }

}

static inline uint8_t i2cHwStatus() {
    return (TWSR & (0xF8));
}

static inline void i2cHwSend(uint8_t byte) {
    /***********************Send Byte***********************************/
    TWDR = byte;
}

/****************** SEND BYTE*****************************/
static inline uint8_t i2cHwReceive() {
    return TWDR;
}
/****************** SEND BYTE*****************************/
void I2cInit();
/****************** Start Communication*****************************/
uint8_t i2cStart(uint8_t u8Address);
/****************** SEND BYTE*****************************/
uint8_t i2cSendByte(uint8_t u8Byte);
/****************** Receive BYTE*****************************/
uint8_t i2cReceiveByte(uint8_t* u8pData);
/****************** Set Address*****************************/
void i2cHwAddress(uint8_t u8Address);
/****************** Slave Transmission*****************************/
uint8_t i2cSlaveTransmission(uint8_t *u8Data, uint8_t u8Length);
/****************** Slave receive*****************************/
uint8_t i2cSlaveReceive(uint8_t *u8Data, uint8_t u8Length);
/****************** get state gode*****************************/
uint8_t i2cGetStatusCode();
/****************** Request Send BYTE*****************************/
void i2cLoadnewByte();
/****************** Stop receive BYTE*****************************/
void i2cReceiveStop();
/****************** Request receive BYTE*****************************/
void i2cReceiveNewByte();
/****************** Request Restar*****************************/
void i2cStop();

void i2cReceiveClear();

void i2cLoadClearByte();

void i2cBusy();

uint8_t i2cIsReady();

void i2cReady();
#endif	/* XC_I2C_H */

