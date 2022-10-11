
#include "../../inc/mega.h"

#if (KEYPAD_MODULE)

uint8_t gu8KeypadBufferEvents[KEYPADS_BUFFER_LENGTH];
stByteBufDescriptor_t gstKeypadDescriptor;
#if KEYPAD01 
volatile uint8_t gu8KEYPAD01Counters[KEYPAD01_MAX_COUNTER];
volatile uint8_t gu8Keypad01LastKey;
volatile uint8_t gu8Keypad01RepeatCounter;
#endif
void keypad01ButtonScan(uint8_t u8CounterIndex, gpio_t u8SwPin);
void keypad01SwitchScan(uint8_t u8Index);
#define PinState(pin,pol)                     ((digitalPinRead(pin) == pol) ? KEYPAD_SW_PRESSED : KEYPAD_SW_RELEASED)

void keypad01ButtonScan(uint8_t u8CounterIndex, gpio_t u8SwPin) {
    uint8_t u8Event;

    if ((u8SwPin == NOT_A_PIN))
        return;

    u8Event = KEYPAD_NOT_AN_EVENT;

    if (PinState(u8SwPin, KEYPAD01_SW_POL) == KEYPAD_SW_PRESSED) {
        gu8KEYPAD01Counters[u8CounterIndex]++;
        if (gu8KEYPAD01Counters[u8CounterIndex] > KEYPAD_LONGPRESS_COUNT) {
            gu8KEYPAD01Counters[u8CounterIndex] = KEYPAD_LONGPRESS_COUNT;
        } else if (gu8KEYPAD01Counters[u8CounterIndex] == KEYPAD_LONGPRESS_COUNT) {
            u8Event = KEYPAD01_LONGPRESS(u8CounterIndex + 1);
        } else if (gu8KEYPAD01Counters[u8CounterIndex] == KEYPAD_DEBOUND_COUNT) {
            u8Event = KEYPAD01_PRESS(u8CounterIndex + 1);
            gu8Keypad01LastKey = (u8CounterIndex + 1); //current Id +1 
            gu8Keypad01RepeatCounter = KEYPAD_REPEAT_COUNT;
        }

    } else {
        if (gu8KEYPAD01Counters[u8CounterIndex] >= KEYPAD_DEBOUND_COUNT) {
            //Release State
            //reset counter after de-bound
            gu8KEYPAD01Counters[u8CounterIndex] = 0;
            u8Event = KEYPAD01_RELEASE(u8CounterIndex + 1);
            if (gu8Keypad01LastKey == (u8CounterIndex + 1))
                gu8Keypad01LastKey = KEYPAD_NOT_A_BUTTON;
        }
    }


    if (u8Event != KEYPAD_NOT_AN_EVENT) {
#if (BUZ_MODULE)
        if (putByte(&gstKeypadDescriptor, u8Event)) {
            if (u8Event == KEYPAD01_PRESS(u8CounterIndex + 1)) {
//                buzStop();
                buzGenerateSignalTime(100, 0);
            }
        } else {
            if (u8Event == KEYPAD01_PRESS(u8CounterIndex + 1)) {
//                 buzStop();
                buzGenerateSignalTime(200, 0);
            }
        }
#else
        putByte(&gstKeypadDescriptor, u8Event);
#endif
    }
}

void keypadSync() {


    /*
     ********************************************************************************************
     *                              KEYPAD01_COMMONS_PINS                                       *
     * ******************************************************************************************
     */
    /***********************KEYPAD01 C01********************/
#if (KEYPAD01_MAX_COMMON > 0)
    digitalpinMode(KEYPAD01_C01_PIN, MODE_OUTPUT); /* active output*/
    keypad01SwitchScan(0);
    digitalpinMode(KEYPAD01_C01_PIN, MODE_INPUT); /*no active output*/
#endif
    /***********************KEYPAD01 C02********************/
#if (KEYPAD01_MAX_COMMON > 1)
    digitalpinMode(KEYPAD01_C02_PIN, MODE_OUTPUT); /*active output*/
    keypad01SwitchScan(1);
    digitalpinMode(KEYPAD01_C02_PIN, MODE_INPUT); /*no active output*/
#endif
    /***********************KEYPAD01 C03********************/
#if (KEYPAD01_MAX_COMMON > 2)
    digitalpinMode(KEYPAD01_C03_PIN, MODE_OUTPUT); /* active output*/
    keypad01SwitchScan(2);
    digitalpinMode(KEYPAD01_C03_PIN, MODE_INPUT); /*no active output*/
#endif

    /***********************KEYPAD01 C04********************/
#if (KEYPAD01_MAX_COMMON > 3)
    digitalpinMode(KEYPAD01_C04_PIN, MODE_OUTPUT); /* active output*/
    keypad01SwitchScan(3);
    digitalpinMode(KEYPAD01_C04_PIN, MODE_INPUT); /*no active output*/
#endif

    /***********************KEYPAD01 C05********************/
#if (KEYPAD01_MAX_COMMON > 4)
    digitalpinMode(KEYPAD01_C05_PIN, MODE_OUTPUT); /* active output*/
    keypad01SwitchScan(4);
    digitalpinMode(KEYPAD01_C05_PIN, MODE_INPUT); /*no active output*/
#endif

    /***********************KEYPAD01 C06********************/
#if (KEYPAD01_MAX_COMMON > 5)
    digitalpinMode(KEYPAD01_C06_PIN, MODE_OUTPUT); /* active output*/
    keypad01SwitchScan(5);
    digitalpinMode(KEYPAD01_C06_PIN, MODE_INPUT); /* active output*/
#endif

    /***********************KEYPAD01 C07********************/
#if (KEYPAD01_MAX_COMMON > 6)
    digitalpinMode(KEYPAD01_C07_PIN, MODE_OUTPUT); /* active output*/
    keypad01SwitchScan(6);
    digitalpinMode(KEYPAD01_C07_PIN, MODE_INPUT); /*no active output*/
#endif

    /***********************KEYPAD01 C08********************/
#if (KEYPAD01_MAX_COMMON > 7)
    digitalpinMode(KEYPAD01_C08_PIN, MODE_OUTPUT); /* active output*/
    keypad01SwitchScan(7);
    digitalpinMode(KEYPAD01_C08_PIN, MODE_INPUT); /*no active output*/
#endif
    //Repeat State
    if (gu8Keypad01LastKey != KEYPAD_NOT_A_BUTTON) {
        if (--gu8Keypad01RepeatCounter == 0) {
            gu8Keypad01RepeatCounter = KEYPAD_REPEAT_RATE_COUNT;
            putByte(&gstKeypadDescriptor, KEYPAD01_REPEAT(gu8Keypad01LastKey));
        }
    }



}

void keypadDriverInit() {
#if KEYPAD01 

    for (uint8_t i = 0; i < KEYPAD01_MAX_COUNTER; i++) {
        gu8KEYPAD01Counters[i] = 0x00;
    }
    gu8Keypad01LastKey = 0;
    gu8Keypad01RepeatCounter = 0;
    byteBufferInit(&gstKeypadDescriptor, gu8KeypadBufferEvents, KEYPADS_BUFFER_LENGTH);
    /*
     ********************************************************************************************
     *                              KEYPAD01_COMMONS PINS INIT                                  *
     * ******************************************************************************************
     */

    /***********************1-common********************/
#if (KEYPAD01_MAX_COMMON > 0)
    digitalpinMode(KEYPAD01_C01_PIN, MODE_INPUT); /*no active output*/
#endif    
#if (KEYPAD01_MAX_COMMON > 1)
    digitalpinMode(KEYPAD01_C02_PIN, MODE_INPUT); /*no active output*/
#endif 
    /***********************3-common********************/
#if (KEYPAD01_MAX_COMMON > 2)  
    digitalpinMode(KEYPAD01_C03_PIN, MODE_INPUT); /*no active output*/
#endif
    /***********************4-common********************/
#if (KEYPAD01_MAX_COMMON > 3)  
    digitalpinMode(KEYPAD01_C04_PIN, MODE_INPUT); /*no active output*/
#endif
    /***********************5-common********************/
#if (KEYPAD01_MAX_COMMON > 4)
    digitalpinMode(KEYPAD01_C05_PIN, MODE_INPUT); /*no active output*/
#endif
    /***********************6-common********************/
#if (KEYPAD01_MAX_COMMON > 5)   
    digitalpinMode(KEYPAD01_C06_PIN, MODE_INPUT); /*no active output*/
#endif
    /***********************7-common********************/
#if (KEYPAD01_MAX_COMMON > 6)  
    digitalpinMode(KEYPAD01_C07_PIN, MODE_INPUT); /*no active output*/
#endif
    /***********************8-common********************/
#if (KEYPAD01_MAX_COMMON > 7)    
    digitalpinMode(KEYPAD01_C08_PIN, MODE_INPUT); /*no active output*/
#endif

    /*
     ********************************************************************************************
     *                     KEYPAD01_SWITCH_PINS PER COMMON                                      *
     * ******************************************************************************************
     */
    /***********************KEYPAD01 SW01********************/
#if(KEYPAD01_MAX_SWITCHES_PER_COMMON > 0)
    digitalpinMode(KEYPAD01_SW01_PIN, KEYPAD01_SW_MODE);
#endif
    /***********************KEYPAD01 SW02********************/
#if(KEYPAD01_MAX_SWITCHES_PER_COMMON > 1)
    digitalpinMode(KEYPAD01_SW02_PIN, KEYPAD01_SW_MODE);
#endif
    /***********************KEYPAD01 SW03********************/
#if(KEYPAD01_MAX_SWITCHES_PER_COMMON > 2)
    digitalpinMode(KEYPAD01_SW03_PIN, KEYPAD01_SW_MODE);
#endif

    /***********************KEYPAD01 SW04********************/
#if(KEYPAD01_MAX_SWITCHES_PER_COMMON > 3)
    digitalpinMode(KEYPAD01_SW04_PIN, KEYPAD01_SW_MODE);
#endif

    /***********************KEYPAD01 SW05********************/
#if(KEYPAD01_MAX_SWITCHES_PER_COMMON > 4)
    digitalpinMode(KEYPAD01_SW05_PIN, KEYPAD01_SW_MODE);
#endif

    /***********************KEYPAD01 SW06********************/
#if(KEYPAD01_MAX_SWITCHES_PER_COMMON > 5)
    digitalpinMode(KEYPAD01_SW06_PIN, KEYPAD01_SW_MODE);
#endif

    /***********************KEYPAD01 SW06********************/
#if(KEYPAD01_MAX_SWITCHES_PER_COMMON > 6)
    digitalpinMode(KEYPAD01_SW07_PIN, KEYPAD01_SW_MODE);
#endif

    /***********************KEYPAD01 SW07********************/
#if(KEYPAD01_MAX_SWITCHES_PER_COMMON > 7)
    digitalpinMode(KEYPAD01_SW08_PIN, KEYPAD01_SW_MODE);
#endif

#endif
}

uint8_t keypadGetEvent() {
    uint8_t u8keypadevent;
    if (getByte(&gstKeypadDescriptor, &u8keypadevent))
        return u8keypadevent;
    return KEYPAD_NOT_AN_EVENT;
}

void keypad01SwitchScan(uint8_t u8Index) {
    /*
     ********************************************************************************************
     *                              KEYPAD01_SWITCH_PINS                                       *
     * ******************************************************************************************
     */
    /***********************KEYPAD01 SW01********************/
#if (KEYPAD01_MAX_SWITCHES_PER_COMMON >0)
    keypad01ButtonScan(((u8Index * KEYPAD01_MAX_SWITCHES_PER_COMMON) + 0), KEYPAD01_SW01_PIN);
#endif
    /***********************KEYPAD01 SW01********************/
#if (KEYPAD01_MAX_SWITCHES_PER_COMMON >1)
    keypad01ButtonScan(((u8Index * KEYPAD01_MAX_SWITCHES_PER_COMMON) + 1), KEYPAD01_SW02_PIN);
#endif
    /***********************KEYPAD01 SW01********************/
#if (KEYPAD01_MAX_SWITCHES_PER_COMMON > 2)
    keypad01ButtonScan(((u8Index * KEYPAD01_MAX_SWITCHES_PER_COMMON) + 2), KEYPAD01_SW03_PIN);
#endif
    /***********************KEYPAD01 SW01********************/
#if (KEYPAD01_MAX_SWITCHES_PER_COMMON >3)
    keypad01ButtonScan(((u8Index * KEYPAD01_MAX_SWITCHES_PER_COMMON) + 3), KEYPAD01_SW04_PIN);
#endif    /***********************KEYPAD01 SW01********************/
#if (KEYPAD01_MAX_SWITCHES_PER_COMMON >4)
    keypad01ButtonScan(((u8Index * KEYPAD01_MAX_SWITCHES_PER_COMMON) + 4), KEYPAD01_SW05_PIN);
#endif
    /***********************KEYPAD01 SW01********************/
#if (KEYPAD01_MAX_SWITCHES_PER_COMMON >5)
    keypad01ButtonScan(((u8Index * KEYPAD01_MAX_SWITCHES_PER_COMMON) + 5), KEYPAD01_SW06_PIN);
#endif
    /***********************KEYPAD01 SW01********************/
#if (KEYPAD01_MAX_SWITCHES_PER_COMMON >6)
    keypad01ButtonScan(((u8Index * KEYPAD01_MAX_SWITCHES_PER_COMMON) + 6), KEYPAD01_SW07_PIN);
#endif

    /***********************KEYPAD01 SW01********************/
#if (KEYPAD01_MAX_SWITCHES_PER_COMMON >7)
    keypad01ButtonScan(((u8Index * KEYPAD01_MAX_SWITCHES_PER_COMMON) + 7), KEYPAD01_SW08_PIN);
#endif
}

#endif