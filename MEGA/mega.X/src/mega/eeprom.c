/*
 * File:   eeprom.c
 * Author: hassa
 *
 * Created on July 6, 2022, 10:11 PM
 */


#include <stdint-gcc.h>

#include "../../inc/mega.h"
#if  EEPROM_MODULE

void eepromPutByte(uint16_t address, uint8_t u8byte) {

#if defined (__AVR_ATmega328P__ ) || defined (__AVR_ATmega328__)  
    while (EECR & (1 << EEPE));
#endif

#if  defined(__AVR_ATmega128A__) || defined (__AVR_ATmega128__)  ||defined (__AVR_ATmega8__)||defined (__AVR_ATmega8A__) 
    while (EECR & (1 << EEWE));
#endif
    ATOMIC_BEGIN
    EEAR = address; // Place EEPROM Address in EEAR
    EEDR = u8byte; // Place EEPROM Data in EEDR
#if  defined(__AVR_ATmega128A__) || defined (__AVR_ATmega128__)  ||defined (__AVR_ATmega8__)||defined (__AVR_ATmega8A__)  
    EECR |= (1 << EEMWE); // Assert EEPROM Master Write Enable
    EECR |= (1 << EEWE); // Assert EEPROM Write Enable
#endif
#if defined (__AVR_ATmega328P__ ) || defined (__AVR_ATmega328__)
    EECR |= (1 << EEMPE); // Assert EEPROM Master Write Enable
    EECR |= (1 << EEPE); // Assert EEPROM Write Enable
#endif
    ATOMIC_END
}

uint8_t eepromGetByte(uint16_t address) {
    uint8_t u8Byte;
#if  defined(__AVR_ATmega128A__) || defined (__AVR_ATmega128__)  ||defined (__AVR_ATmega8__)||defined (__AVR_ATmega8A__)  
    while (EECR & (1 << EEWE)); //Is EEPROM Currently Being Accessed?  Yes, Loop
#endif
#if defined (__AVR_ATmega328P__ ) || defined (__AVR_ATmega328__) 
    while (EECR & (1 << EEPE)); //Is EEPROM Currently Being Accessed?  Yes, Loop
#endif
    ATOMIC_BEGIN
    EEAR = address; //Place Address in EEPROM Address Register
    EECR |= (1 << EERE);
    u8Byte = EEDR;
    ATOMIC_END
    return u8Byte;
}




#endif