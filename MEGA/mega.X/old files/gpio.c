/*
 * File:   gpio.c
 * Author: Hassan
 *
 * Created on July 29, 2022, 12:12 AM
 */



#include  "../../inc/mega/gpio.h"





void digitalTogglePin(uint8_t u8Pin) {
    volatile uint8_t *pu8PortAddress;
    uint8_t u8PortId;
    uint8_t u8Mask;


    u8PortId = digitalPinToPort(u8Pin); // get Port ID From Pin ID
    u8Mask = digitalPinToBitMask(u8Pin); // get Mask From Pin ID

    if (u8PortId == NOT_A_PORT) return; // This PORT Not exist
    pu8PortAddress = portOutputRegister(u8PortId); // get PORT Address From memory
    *(pu8PortAddress) ^= (u8Mask); //set a specific pin in DDR Register as a OUTPUT

}

/*pin operation*/

/**
 * 
 * @param u8Pin  Pin ID
 * @param u8Mode Three mode of the Pin (Input - Output- PULLUP Resistor) 
 * @param u8Init   Pin start High or Low load a Pin is the Output  
 */
void digitalpinMode(uint8_t u8Pin, uint8_t u8Mode) {
    volatile uint8_t *pu8ModeAddress; // PORT Address , DDR Address 
    volatile uint8_t *pu8PortAddress;
    uint8_t u8PortId;
    uint8_t u8Mask;



    u8PortId = digitalPinToPort(u8Pin); // get Port ID From Pin ID
    u8Mask = digitalPinToBitMask(u8Pin); // get Mask From Pin ID

    if (u8PortId == NOT_A_PORT) return; // This PORT Not exist
    pu8ModeAddress = portModeRegister(u8PortId); // get DDR Address From memory 
    pu8PortAddress = portOutputRegister(u8PortId); // get PORT Address From memory
    if (u8Mode == MODE_OUTPUT_HIGH) { // check the mode is a OutPut 
        // check the Init value is High 
        *(pu8PortAddress) |= (u8Mask); // set a specific bit in PORT Register is a high  
        *(pu8ModeAddress) |= (u8Mask); //set a specific pin in DDR Register as a OUTPUT
    } else if (u8Mode == MODE_OUTPUT_LOW) {
        // check the Init value is High 
        *(pu8PortAddress) &= ~(u8Mask); // set a specific bit in PORT Register is a high  
        *(pu8ModeAddress) |= (u8Mask); //set a specific pin in DDR Register as a OUTPUT
    } else if (u8Mode == MODE_INPUT_PULLUP) { // check the mode is a PULLUP 
        *(pu8PortAddress) |= (u8Mask); // set a a specific bit in a PORT Register is a high
        *(pu8ModeAddress) &= ~(u8Mask); // clear a specific bit in a DDR Register (set is a Input Mode)
    } else { // default mode is a Input Mode
        *(pu8PortAddress) &= ~(u8Mask); // clear specific bit in PORT Register
        *(pu8ModeAddress) &= ~(u8Mask); // clear specific bit in DDR  Register (Input-Mode)
    }

}

/**
 * 
 * @param u8Pin PIN ID
 * @param u8Value PIN Value
 */
void digitalPinWrite(uint8_t u8Pin, uint8_t u8Value) {
    volatile uint8_t *pu8PortAddress; // PORT Address 
    uint8_t u8PortId;
    uint8_t u8Mask;

    u8PortId = digitalPinToPort(u8Pin); // get PortId From Pin ID
    u8Mask = digitalPinToBitMask(u8Pin); // get mask From Pin ID

    pu8PortAddress = portOutputRegister(u8PortId); // get PORT Address From memory 

    if (u8PortId == NOT_A_PORT) return; // PORT Not exists

    if (u8Value == GPIO_HIGH) // check the value is a high
        *(pu8PortAddress) |= (u8Mask); // set a specific bit in PORT Register is a high 
    else // default value is low 
        *(pu8PortAddress) &= ~(u8Mask); // clear a specific bit in PORT Register

}

/**
 * 
 * @param u8Pin
 * @return PIN Register Value 
 */
uint8_t digitalPinRead(uint8_t u8Pin) {
    volatile uint8_t *pu8PinAddress; // PIN Register Address
    uint8_t u8Mask;
    uint8_t u8PortId;
    u8PortId = digitalPinToPort(u8Pin); // get Port ID using Pin ID
    if (u8PortId == NOT_A_PORT) return (0); // PORT NOT exists 
    u8Mask = digitalPinToBitMask(u8Pin); // get mask using Pin ID
    pu8PinAddress = portInputRegister(u8PortId); // get Pin Register From memory 
    return ((*(pu8PinAddress) & (u8Mask)) ? (1) : (0)); // check is a specific bit in PIN Register is a High or Low and return 
}

/*
 * 
 * @param u8PortId
 * @param u8Mode
 */
void digitalPortMode(uint8_t u8PortId, uint8_t u8Mode) {
    //Port is ALL INPUT or PORT is ALL OUTPUT
    volatile uint8_t *pu8ModeAddress;
    volatile uint8_t *pu8PortAddress; // PORT Address and Pin Address  // get Port Id From memory  


    pu8ModeAddress = portModeRegister(u8PortId); // get DDR Address From memory 
    pu8PortAddress = portOutputRegister(u8PortId); // get PORT Address From memory
    if (u8PortId == NOT_A_PORT)return; // PORT Not exists 

    if (u8Mode == MODE_OUTPUT_HIGH) { // check mode is a Output
        *pu8PortAddress = 0XFF; // Load Init value in PORT Register
        *pu8ModeAddress = 0xFF; // set all pins in PORT is a OutPut
    } else if (u8Mode == MODE_OUTPUT_LOW) {
        *pu8PortAddress = 0x00; // Load Init value in PORT Register
        *pu8ModeAddress = 0xFF; // set all pins in PORT is a OutPut
    } else if (u8Mode == MODE_INPUT_PULLUP) { // check mode is a PULLUP 
        *pu8PortAddress = 0xFF; // All bits in PORT Register is a high
        *pu8ModeAddress = 0x00; // set DDR Register is a Input
    } else { // Default Mode is a Input 
        *pu8PortAddress = 0x00; // Clear All bits in a PORT Register 
        *pu8ModeAddress = 0x00; // set Mode Input in DDR Register
    }

}

/**
 * 
 * @param u8PortId
 * @param u8Value
 */
void digitalPortWrite(uint8_t u8PortId, uint8_t u8Value) {
    volatile uint8_t *pu8PortAddress; // PORT Address 
    if (u8PortId == NOT_A_PORT)return; // PORT Not exits  
    pu8PortAddress = portOutputRegister(u8PortId); // get PORT Address From memory 
    *pu8PortAddress = u8Value; // set value in PORT Register 

}

/**
 * 
 * @param u8PortId
 * @return 
 */
uint8_t digitalPortRead(uint8_t u8PortId) {
    volatile uint8_t *pu8PinAddress; //Pin Address

    if (u8PortId == NOT_A_PORT)return (NOT_A_PORT); //Port Not exits
    pu8PinAddress = portInputRegister(u8PortId); // get Pin Address From memory 
    return *(pu8PinAddress); //return Pin Register Val ue 
}

/*pins operation*/
void digitalPinsMode(uint8_t u8PortId, uint8_t u8Mask, uint8_t u8Mode, uint8_t u8Init) {
    volatile uint8_t * pu8PortAddress;
    volatile uint8_t *pu8ModeAddress;


    if (u8PortId == NOT_A_PORT) return;
    pu8ModeAddress = portModeRegister(u8PortId);
    pu8PortAddress = portOutputRegister(u8PortId);
    if (u8Mode == MODE_OUTPUT_LOW) {
        uint8_t u8notMasked = (*pu8PortAddress & (~u8Mask));
        *pu8PortAddress = (u8Init) | (u8notMasked);
        *pu8ModeAddress |= (u8Mask);
    } else if (u8Mode == MODE_INPUT_PULLUP) {
        *pu8PortAddress |= (u8Mask);
        *pu8ModeAddress &= ~(u8Mask);
    } else {
        *pu8PortAddress &= ~(u8Mask);
        *pu8ModeAddress &= ~(u8Mask);
    }
}

void digitalPinsWrite(uint8_t u8PortId, uint8_t u8Mask, uint8_t u8Value) {
    volatile uint8_t *pu8PortAddress;
    uint8_t u8notMasked;

    if (u8PortId == NOT_A_PORT) return;
    pu8PortAddress = portOutputRegister(u8PortId);
    //0101 0101  0x55  old data 
    //1100 0100  mask  (bit 2 , bit 6 , bit 7)
    //0011 1011  ~(0xC4) ~mask
    //0001 0001  0x11         result(old data & (~mask))
    //1000 0000  0x80&0xC4    value only bit7 set a high and clear bit 2 , bit 6
    //1001 0001  0x91   new   value (new Value | result(old data & (~mask)))
    u8notMasked = (*pu8PortAddress & (~u8Mask));
    *pu8PortAddress = (u8Value & u8Mask) | (u8notMasked);
}

uint8_t digitalPinsRead(uint8_t u8PortId, uint8_t u8Mask) {
    volatile uint8_t *pu8PinAddress;
    if (u8PortId == NOT_A_PORT) return (NOT_A_PORT);
    pu8PinAddress = portInputRegister(u8PortId);
    return ((*pu8PinAddress) & (u8Mask));
}