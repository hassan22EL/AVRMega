/*
 * File:   TWI_MASTER.c
 * Author: hassa
 *
 * Created on October 6, 2022, 11:19 PM
 */


#include <stdint-gcc.h>

#include "../../inc/mega.h"

#if TWI_MODULE


TWI_statusReg_t twiStatus;
volatile uint8_t gu8TWI_state;
volatile uint8_t gu8TWI_msgSize;
volatile uint8_t *gu8pTWI_buf;

ISR(TWI_vect) {
    static uint8_t TWI_bufPtr;
    switch (TWSR) {
        case TWI_START: // START has been transmitted  
        case TWI_REP_START: // Repeated START has been transmitted
            TWI_bufPtr = 0; // Set buffer pointer to the TWI Address location
        case TWI_MTX_ADR_ACK: // SLA+W has been tramsmitted and ACK received
        case TWI_MTX_DATA_ACK: // Data byte has been tramsmitted and ACK received
            if (TWI_bufPtr < gu8TWI_msgSize) {
                TWDR = gu8pTWI_buf[TWI_bufPtr++];
                TWCR = (1 << TWEN) | // TWI Interface enabled
                        (1 << TWIE) | (1 << TWINT) | // Enable TWI Interupt and clear the flag to send byte
                        (0 << TWEA) | (0 << TWSTA) | (0 << TWSTO) | //
                        (0 << TWWC); //  
            } else {
                TWI_statusReg.lastTransOK = TRUE; // Set status bits to completed successfully. 
                TWCR = (1 << TWEN) | // TWI Interface enabled
                        (0 << TWIE) | (1 << TWINT) | // Disable TWI Interrupt and clear the flag
                        (0 << TWEA) | (0 << TWSTA) | (1 << TWSTO) | // Initiate a STOP condition.
                        (0 << TWWC); //
            }
            break;
        case TWI_MRX_DATA_ACK: // Data byte has been received and ACK tramsmitted
            gu8pTWI_buf[TWI_bufPtr++] = TWDR;
        case TWI_MRX_ADR_ACK: // SLA+R has been tramsmitted and ACK received
            if (TWI_bufPtr < (gu8TWI_msgSize - 1)) // Detect the last byte to NACK it.
            {
                TWCR = (1 << TWEN) | // TWI Interface enabled
                        (1 << TWIE) | (1 << TWINT) | // Enable TWI Interupt and clear the flag to read next byte
                        (1 << TWEA) | (0 << TWSTA) | (0 << TWSTO) | // Send ACK after reception
                        (0 << TWWC); //  
            } else // Send NACK after next reception
            {
                TWCR = (1 << TWEN) | // TWI Interface enabled
                        (1 << TWIE) | (1 << TWINT) | // Enable TWI Interupt and clear the flag to read next byte
                        (0 << TWEA) | (0 << TWSTA) | (0 << TWSTO) | // Send NACK after reception
                        (0 << TWWC); // 
            }
            break;
        case TWI_MRX_DATA_NACK: // Data byte has been received and NACK tramsmitted
            gu8pTWI_buf[TWI_bufPtr] = TWDR;
            TWI_statusReg.lastTransOK = TRUE; // Set status bits to completed successfully. 
            TWCR = (1 << TWEN) | // TWI Interface enabled
                    (0 << TWIE) | (1 << TWINT) | // Disable TWI Interrupt and clear the flag
                    (0 << TWEA) | (0 << TWSTA) | (1 << TWSTO) | // Initiate a STOP condition.
                    (0 << TWWC); //
            break;
        case TWI_ARB_LOST: // Arbitration lost
            TWCR = (1 << TWEN) | // TWI Interface enabled
                    (1 << TWIE) | (1 << TWINT) | // Enable TWI Interupt and clear the flag
                    (0 << TWEA) | (1 << TWSTA) | (0 << TWSTO) | // Initiate a (RE)START condition.
                    (0 << TWWC); //
            break;
        case TWI_MTX_ADR_NACK: // SLA+W has been transmitted and NACK received
        case TWI_MRX_ADR_NACK: // SLA+R has been transmitted and NACK received    
        case TWI_MTX_DATA_NACK: // Data byte has been transmitted and NACK received
            //    case TWI_NO_STATE              // No relevant state information available; TWINT = ?0?
        case TWI_BUS_ERROR: // Bus error due to an illegal START or STOP condition
        default:
            gu8TWI_state = TWSR; // Store TWSR and automatically sets clears noErrors bit.
            // Reset TWI Interface
            TWCR = (1 << TWEN) | // Enable TWI-interface and release TWI pins
                    (0 << TWIE) | (0 << TWINT) | // Disable Interupt
                    (0 << TWEA) | (0 << TWSTA) | (0 << TWSTO) | // No Signal requests
                    (0 << TWWC); //
    }
}

void TWI_Init(void) {
    gu8TWI_state = TWI_NO_STATE;
    gu8TWI_msgSize = 0;
    gu8pTWI_buf = NULL;
    TWBR = TWI_TWRB_VALUE; /*baud rate*/
    TWSR = TWI_TWPS_VALUE; /*prescaller*/
    TWDR = 0xFF; // Default content = SDA released.
    TWCR = (1 << TWEN) | // Enable TWI-interface and release TWI pins.
            (0 << TWIE) | (0 << TWINT) | // Disable Interrupt.
            (0 << TWEA) | (0 << TWSTA) | (0 << TWSTO) | // No Signal requests.
            (0 << TWWC);
#if TWI_PULLUP == TWI_INTERNAL_PULLUP
    digitalpinMode(TWI_SCL_PIN, MODE_INPUT_PULLUP);
    digitalpinMode(TWI_SDA_PIN, MODE_INPUT_PULLUP);
#endif
}

uint8_t TWI_Transceiver_Busy(void) {
    return ( TWCR & (1 << TWIE)); // IF TWI Interrupt is enabled then the Transceiver is busy
}

uint8_t TWI_Get_State_Info(void) {
    if (TWI_Transceiver_Busy()) return (0); // Wait until TWI has completed the transmission.
    return ( gu8TWI_state); // Return error state.
}

uint8_t TWI_Start_Transceiver_With_Data(uint8_t *msg, uint8_t msgSize) {
    uint8_t temp;

    if (TWI_Transceiver_Busy())
        return (0); // Wait until TWI is ready for next transmission.

    gu8TWI_msgSize = msgSize; // Number of data to transmit.
    gu8pTWI_buf = msg; // Store slave address with R/W setting.
    if (!(msg[0] & (TRUE << TWI_READ_BIT))) // If it is a write operation, then also copy data.
    {
        for (temp = 1; temp < msgSize; temp++)
            gu8pTWI_buf[ temp ] = msg[ temp ];
    }
    twiStatus.all = 0;
    gu8TWI_state = TWI_NO_STATE;
    TWCR = (1 << TWEN) | // TWI Interface enabled.
            (1 << TWIE) | (1 << TWINT) | // Enable TWI Interupt and clear the flag.
            (0 << TWEA) | (1 << TWSTA) | (0 << TWSTO) | // Initiate a START condition.
            (0 << TWWC); //
    return (1);
}

uint8_t TWI_Start_Transceiver(void) {
    if (TWI_Transceiver_Busy()) return (0); // Wait until TWI is ready for next transmission.
    twiStatus.all = 0;
    gu8TWI_state = TWI_NO_STATE;
    TWCR = (1 << TWEN) | // TWI Interface enabled.
            (1 << TWIE) | (1 << TWINT) | // Enable TWI Interupt and clear the flag.
            (0 << TWEA) | (1 << TWSTA) | (0 << TWSTO) | // Initiate a START condition.
            (0 << TWWC); //
    return (0);
}

uint8_t TWI_Get_Data_From_Transceiver(uint8_t *msg, uint8_t msgSize) {
    uint8_t i;

    if (TWI_Transceiver_Busy()) return (0); // Wait until TWI is ready for next transmission.

    if (TWI_statusReg.lastTransOK) // Last transmission competed successfully.              
    {
        for (i = 0; i < msgSize; i++) // Copy data from Transceiver buffer.
        {
            msg[ i ] = gu8pTWI_buf[ i ];
        }
    }
    return ( TWI_statusReg.lastTransOK); // current transmission competed successfully. 
}

#endif