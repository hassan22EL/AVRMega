/*
 * File:   exEEPROM.c
 * Author: Hassan
 *
 * Created on July 28, 2022, 8:52 AM
 */


#include "../../inc/mega.h"
#if EX_EEPROM_MODULE

/*app interface*/

volatile uint8_t gu8eepromsate;
volatile uint8_t gu8eepromTwiState;
volatile uint8_t gu8PageReminder;
volatile uint8_t gu8exEEpromIndex;



#define  EEPROM_SEND_ADDRESS  (7)
#define  EEPROM_START_LOAD    (6)
#define EEPROM_SAVE_PAGE      (5)
#define   EEPROM_LOAD_DATA    (0x0C)
#define   EEPROM_SAVE_MASK     (0x03)

uint8_t exEEPROMSavePage(stExeeprom_t *pstExeeprom, uint8_t u8Length);

void exEEPROMInit() {
    gu8eepromsate = 0;
    gu8PageReminder = 0;
    gu8exEEpromIndex = 0;
    gu8eepromTwiState = TWI_SUCCESS;
}

uint8_t exEEPROMSave(stExeeprom_t *pstExeeprom, byte SLA, word address, byte *data, byte length) {

    volatile uint8_t u8PageOffset;

    switch (gu8eepromsate & EEPROM_SAVE_MASK) {
        case 0:
            if (TWI_ISReady()) {
                TWI_BUSY();
                pstExeeprom->SLA = SLA & 0xFE;
                pstExeeprom->address = address;
                pstExeeprom->data = data;
                pstExeeprom->length = length;
                gu8PageReminder = 0;
                gu8exEEpromIndex = 0;
                bitsValue(gu8eepromsate, 0x01, EEPROM_SAVE_MASK);
            }
            break;
        case 1:
            u8PageOffset = pstExeeprom->address % ExEEPROM_PAGE_SIZE;
            gu8PageReminder = ExEEPROM_PAGE_SIZE - u8PageOffset;
            if (pstExeeprom->length < gu8PageReminder) {
                gu8PageReminder = pstExeeprom->length;
            }
            bitsValue(gu8eepromsate, 0x02, EEPROM_SAVE_MASK);
            break;
        case 2:
            if (exEEPROMSavePage(pstExeeprom, gu8PageReminder)) {
                pstExeeprom->length -= gu8PageReminder;
                if (pstExeeprom->length > 0) {
                    pstExeeprom->address += gu8PageReminder;
                    gu8exEEpromIndex += gu8PageReminder;
                    bitsValue(gu8eepromsate, 0x01, EEPROM_SAVE_MASK);
                } else {
                    TWI_READY();
                    gu8exEEpromIndex = 0;
                    bitsValue(gu8eepromsate, 0x00, EEPROM_SAVE_MASK);
                    return (1);

                }
            }
            break;

    }
    return (0);
}

uint8_t exEEPROMSavePage(stExeeprom_t *pstExeeprom, uint8_t u8Length) {
    byte addressLoad[2];
    if (bitIsClear(gu8eepromsate, EEPROM_SAVE_PAGE)) {
        gu8eepromTwiState = TWI_start(pstExeeprom->SLA & 0xFE);
        if (gu8eepromTwiState == TWI_SUCCESS) {
            bitSet(gu8eepromsate, EEPROM_SAVE_PAGE);
        } else {
            Send_stop();
        }

    } else {
        addressLoad [0] = (pstExeeprom->address >> 8);
        addressLoad [1] = (pstExeeprom->address & 0xFF);
        for (uint8_t i = 0; (i < 2) && (gu8eepromTwiState == TWI_SUCCESS); i++) {
            gu8eepromTwiState = Send_byte(addressLoad[i]);
        }
        for (uint8_t i = gu8exEEpromIndex; (i < u8Length + gu8exEEpromIndex) && (gu8eepromTwiState == TWI_SUCCESS); i++) {
            gu8eepromTwiState = Send_byte(pstExeeprom->data[i]);
        }
        Send_stop();
        bitClear(gu8eepromsate, EEPROM_SAVE_PAGE);
        return (1);
    }
    return (0);
}

uint8_t exEEPROMLoad(stExeeprom_t *pstExeeprom, byte SLA, word address, byte *data, byte length) {
    byte addressLoad[2];
    switch ((gu8eepromsate & EEPROM_LOAD_DATA) >> 2) {
        case 0:
            if (TWI_ISReady()) {
                TWI_BUSY();
                pstExeeprom->SLA = SLA & 0xFE; /*send address*/
                pstExeeprom->address = address;
                pstExeeprom->data = data;
                pstExeeprom->length = length;
                bitsValue(gu8eepromsate, 0x01 << 2, EEPROM_LOAD_DATA);
            }
            break;
        case 1:
            gu8eepromTwiState = TWI_start(pstExeeprom->SLA);
            if (gu8eepromTwiState == TWI_SUCCESS) {
                if (bitIsClear(gu8eepromsate, EEPROM_SEND_ADDRESS)) {
                    /*send address*/
                    bitsValue(gu8eepromsate, 0x02 << 2, EEPROM_LOAD_DATA);
                } else {
                    /*Read Data*/
                    bitsValue(gu8eepromsate, 0x03 << 2, EEPROM_LOAD_DATA);
                }
            } else {
                Send_stop();
            }
            break;
        case 2:
            addressLoad [0] = (pstExeeprom->address >> 8);
            addressLoad [1] = (pstExeeprom->address & 0xFF);
            for (uint8_t i = 0; (i < 2) && (gu8eepromTwiState == TWI_SUCCESS); i++) {
                gu8eepromTwiState = Send_byte(addressLoad[i]);
            }
            pstExeeprom->SLA |= 0x01;
            bitSet(gu8eepromsate, EEPROM_SEND_ADDRESS);
            bitsValue(gu8eepromsate, 0x01 << 2, EEPROM_LOAD_DATA);
            break;
        case 3:

            for (uint8_t i = 0; (i < pstExeeprom->length) && (gu8eepromTwiState == TWI_SUCCESS); i++) {
                gu8eepromTwiState = Get_byte(pstExeeprom->data++, pstExeeprom->length - 1, i);
            }
            Send_stop();
            TWI_READY();
            bitClear(gu8eepromsate, EEPROM_SEND_ADDRESS);
            bitsValue(gu8eepromsate, 0x00 << 2, EEPROM_LOAD_DATA);
            return (1);
            break;
        default:
            bitsValue(gu8eepromsate, 0x00 << 2, EEPROM_LOAD_DATA);
            break;

    }
    return (0);
}




#endif
