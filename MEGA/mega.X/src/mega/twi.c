/*
 * File:   twi.c
 * Author: Hassan
 *
 * Created on July 28, 2022, 7:28 AM
 */

#include <stdint-gcc.h>

#include "../../inc/mega.h"
#if TWI_MODULE 

#define OWN_ADR 0x60
/****************************************************************************
    Function definitions
 ****************************************************************************/

//release the bus
volatile uint8_t gu8TW_READY;

void Init_TWI(void) {
    TWAR = OWN_ADR; //Set own slave address
    //4 MHz xtal
    TWDR = 0xFF;
    /***********************SET BIT RATE*****************************/
    TWBR = (uint8_t) TWI_TWRB_VALUE;
    /***********************SET PRESCALLER***************************/
    TWSR |= (TWI_TWPS_VALUE);
    TWCR = (1 << TWEN); //Enable TWI-interface
    gu8TW_READY = 1;
#if TWI_PULLUP == TWI_INTERNAL_PULLUP
    digitalpinMode(TWI_SCL_PIN, MODE_INPUT_PULLUP);
    digitalpinMode(TWI_SDA_PIN, MODE_INPUT_PULLUP);
#endif
}

void Wait_TWI_int(void) {
    while (!(TWCR & (1 << TWINT)));
}



unsigned char Send_start(void) {
    TWCR = ((1 << TWINT)+(1 << TWSTA)+(1 << TWEN)); //Send START
    Wait_TWI_int(); //Wait for TWI interrupt flag set

    if ((TWSR != TWI_START)&&(TWSR != TWI_REP_START))//If status other than START 
        return TWSR; //transmitted(0x08) or Repeated
    return TWI_SUCCESS;
}

void Send_stop(void) {
    TWCR = ((1 << TWEN)+(1 << TWINT)+(1 << TWSTO)); //Send STOP condition

} //Send a Stop condition

void twiInitFram(stTWi_Tx *stTwiFram, uint8_t u8Size, uint8_t *u8Data) {
    stTwiFram->data_ptr = u8Data;
    stTwiFram->size = u8Size;
}

uint8_t Send_to_TWI(stTWi_Tx * data_pack, uint8_t u8lenth) {

    uint8_t state, i, j;
    state = TWI_SUCCESS;
    for (i = 0; i < u8lenth && (state == TWI_SUCCESS); i++) {
        state = Send_start(); //Send START and repeated START
        if (state == TWI_SUCCESS)
            state = Send_adr(data_pack[i].slave_adr); //Send slave address+W/R

        /*Dependent on the R/W in the slave address it will receive or 
        transmitt data.*/
        if (!(data_pack[i].slave_adr & TWI_R)) {
            /*If W, it will transmitt data and loops until all data have been
             shifted out*/
            for (j = 0; ((j < data_pack[i].size)&&(state == TWI_SUCCESS)); j++)
                state = Send_byte(data_pack[i].data_ptr[j]);
        } else //Else read from slave 
        {
            /*If R, it will receive data and loops until all data have been
             shifted in. When j == 0x00 this is the last byte and a NACK 
             will be sent to the slave to make it stop transmitting */
            for (j = 0; ((j < data_pack[i].size)&&(state == TWI_SUCCESS)); j++)
                state = Get_byte(data_pack[i].data_ptr++, ((data_pack[i].size) - 1), j);
        }
    }
    Send_stop();
    return state;

}

uint8_t Send_byte(uint8_t data) {
    Wait_TWI_int(); //Wait for TWI interrupt flag set

    TWDR = data;
    TWCR = ((1 << TWINT)+(1 << TWEN)); //Clear int flag to send byte 

    Wait_TWI_int(); //Wait for TWI interrupt flag set

    if (TWSR != MTX_DATA_ACK) //If NACK received return TWSR
        return TWSR;
    return TWI_SUCCESS;
}

uint8_t Get_byte(uint8_t*rx_ptr, uint8_t u8Max, uint8_t last_byte) {
    Wait_TWI_int(); //Wait for TWI interrupt flag set

    /*When receiving the last byte from the slave it will be sent a NACK to 
    make the slave stop transmitting, all bits before the last will get 
    a ACK*/
    if (last_byte < u8Max) //Not the last byte
        //Clear int flag and enable acknowledge to receive data.
        TWCR = ((1 << TWINT)+(1 << TWEA)+(1 << TWEN));
    else //Last byte
        /*Clear int flag to and do not enable acknowledge to tell the slave 
        to stop transmitting*/
        TWCR = ((1 << TWINT)+(1 << TWEN));
    Wait_TWI_int(); //Wait for TWI interrupt flag set

    *rx_ptr = TWDR; //Save received byte

    /*If ACK has been transmitted or this was the last byte and NACK has been
    sent -> return SUCCESS, else return TWSR*/
    if (((TWSR == MRX_DATA_NACK)&&(last_byte >= u8Max)) || (TWSR == MRX_DATA_ACK))
        return TWI_SUCCESS;
    return TWSR;
}

uint8_t Send_adr(uint8_t adr) {
    Wait_TWI_int(); //Wait for TWI interrupt flag set

    TWDR = adr;
    TWCR = ((1 << TWINT)+(1 << TWEN)); //Clear int flag to send byte 

    Wait_TWI_int(); //Wait for TWI interrupt flag set

    if ((TWSR != MTX_ADR_ACK)&&(TWSR != MRX_ADR_ACK))//If NACK received return
        //TWSR
        return TWSR;
    return TWI_SUCCESS; //Else return SUCCESS
}

void TWI_READY() {
    gu8TW_READY = 1;
}

void TWI_BUSY() {
    gu8TW_READY = 0;
}

uint8_t TWI_ISReady() {
    return (gu8TW_READY);
}

uint8_t TWI_start(uint8_t SLA) {
    TWCR = ((1 << TWINT)+(1 << TWSTA)+(1 << TWEN)); //Send START
    Wait_TWI_int(); //Wait for TWI interrupt flag set
    if ((TWSR == TWI_START) || (TWSR == TWI_REP_START))//If status other than START 
        TWDR = SLA;
    TWCR = ((1 << TWINT)+(1 << TWEN)); //Clear int flag to send byte 
    Wait_TWI_int(); //Wait for TWI interrupt flag set
    if ((TWSR != MTX_ADR_ACK)&&(TWSR != MRX_ADR_ACK))//If NACK received return
        //TWSR
        return TWSR;
    return TWI_SUCCESS; //Else return SUCCESS
}

#endif