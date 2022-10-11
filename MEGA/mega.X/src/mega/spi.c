/*
 * File:   spi.c
 * Author: hassa
 *
 * Created on June 28, 2022, 3:20 PM
 */

#include <stdint-gcc.h>

#include "../../inc/mega.h"
#if SPI_MODULE 

#define SPI_ACTIVE			0 // SS Pin put Low
#define SPI_INACTIVE		1 // SS Pin put High	


#if (SPI_MODE == SPI_MASTER_MODE) 
volatile uint8_t gu8SpiCTS;
volatile uint8_t gu8SpiBytesRequest; // Number of bytes request
#elif #if (SPI_MODE == SPI_SLAVE_MODE) 
static volatile uint8_t gu8SpiSPDR;
#define SPI_SPDR_EMPTY	0
#define SPI_SPDR_FULL	1
#endif

uint8_t gu8spiTxBuf[SPI_TX_BUFFER_SIZE];
uint8_t gu8spiRxBuf[SPI_RX_BUFFER_SIZE];

stByteBufDescriptor_t gu8spiTx;
stByteBufDescriptor_t gu8spiRx;

ISR(SPI_STC_vect) {
    uint8_t u8data;
#if (SPI_MODE == SPI_MASTER_MODE) 
    /*receive data */
    /*send data*/
    if (getByte(&gu8spiTx, &u8data)) {
        SPDR = u8data;
    } else if (gu8SpiBytesRequest > 0) {
        if (putByte(&gu8spiRx, SPDR)) {
            gu8SpiBytesRequest--;
            SPDR = 0x00;
        }
    } else {
        gu8SpiCTS = SPI_INACTIVE;
    }
#elif (SPI_MODE == SPI_SLAVE_MODE)

#endif
}
#if (SPI_MODE == SPI_MASTER_MODE) 

void spiStart(uint8_t Cspin) {
    digitalPinWrite(Cspin, GPIO_LOW);
    SPCR |= (1 << SPIE);
    

}

void spiStop(uint8_t u8Pin) {
    /*spi is ready*/

    digitalpinMode(u8Pin, MODE_OUTPUT_HIGH);
    digitalpinMode(SPI_MOSI_PIN, MODE_OUTPUT_HIGH);
    //     /*SCLK as a output*/
    digitalpinMode(SPI_SCLK_PIN, MODE_OUTPUT_HIGH);
     SPCR &= ~(1 << SPIE);
}

uint8_t spiReady() {
    if (gu8SpiCTS == SPI_INACTIVE) {
        return (1);
    }
    return (0);
}

void spiInit(void) {
    /*init buffer tx , rx*/
    gu8SpiBytesRequest = 0;
    gu8SpiCTS = SPI_INACTIVE;
    byteBufferInit(&gu8spiTx, gu8spiTxBuf, SPI_TX_BUFFER_SIZE);
    byteBufferInit(&gu8spiRx, gu8spiRxBuf, SPI_RX_BUFFER_SIZE);
    for (uint8_t i = 0; i < SPI_TX_BUFFER_SIZE; i++) {
        gu8spiTxBuf[i] = 0x00;
    }
    for (uint8_t i = 0; i < SPI_RX_BUFFER_SIZE; i++) {
        gu8spiRxBuf[i] = 0x00;
    }
    SPCR = 0x00;
    SPSR &= ~(1 << SPI2X);
    /*SPI ENABLE*/
    SPCR |= (1 << SPE);
    bitsValue(SPCR, SPI_CLK_MODE, 0x0C);
    bitsValue(SPCR, SPI_CLOCK, 0x03);
    SPCR |= (1 << MSTR);
    SPSR |= (SPI_SPEED << SPI2X);
    SPSR |= (SPI_DATA_SEND << DORD);
    SPCR &= ~(1 << SPIE);
}

void spiMasterTransmit(uint8_t *byte, uint8_t length) {
    /*puts data into buffer*/
    uint8_t data;
    //    digitalPinWrite(gu8SpiCsPin, GPIO_LOW);
    for (uint8_t i = 0; i < length; i++) {
        putByte(&gu8spiTx, byte[i]);
    }

    /*send byte*/
    if (gu8SpiCTS == SPI_INACTIVE) {
        gu8SpiCTS = SPI_ACTIVE;

        /*spi is active*/
        /*puts data into buffer*/
        if (getByte(&gu8spiTx, &data)) {
            SPDR = data;
        }
    }
}

void spiMasterRead(uint8_t u8NumberofByte) {

    gu8SpiBytesRequest = u8NumberofByte;
    if (gu8SpiCTS == SPI_INACTIVE) {
        gu8SpiCTS = SPI_ACTIVE; /*spi is active*/
        SPDR = 0x00;
    }

}


#elif (SPI_MODE == SPI_SLAVE_MODE)
void spiInit(void);
#endif

#endif


