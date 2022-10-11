#include <stdint.h>

#include "../../inc/mega.h"


#if BUTTON_MODULE
volatile uint8_t gu8LastRepeatKey;
volatile uint8_t gu8RepeatCount;

uint8_t gu8ButtonBuffer[BUTTONS_BUFFER_LENGTH];
uint8_t gu8ButtonCounterBuffer[MAX_BUTTONS];

stByteBufDescriptor_t gsButtonDescriptor;
void buttonScan(uint8_t u8CounterIndex, gpio_t u8SwPin, uint8_t u8POL);
#define PinState(pin,pol)                     ((digitalPinRead(pin) == pol) ? SW_PRESSED : SW_RELEASED)

void buttonScan(uint8_t u8CounterIndex, gpio_t u8SwPin, uint8_t u8POL) {
    uint8_t u8Event;

    if (u8SwPin == NOT_A_PIN)
        return;
    u8Event = NOT_AN_EVENT;

    if (PinState(u8SwPin, u8POL) == SW_PRESSED) {
        gu8ButtonCounterBuffer[u8CounterIndex]++;
        if (gu8ButtonCounterBuffer[u8CounterIndex] > BUTTON_LONGPRESS_COUNT) {
            gu8ButtonCounterBuffer[u8CounterIndex] = BUTTON_LONGPRESS_COUNT;
        } else if (gu8ButtonCounterBuffer[u8CounterIndex] == BUTTON_LONGPRESS_COUNT) {
            u8Event = BUTTON_LONGPRESS(u8CounterIndex + 1);
        } else if (gu8ButtonCounterBuffer[u8CounterIndex] == BUTTON_DEBOUND_COUNT) {
            u8Event = BUTTON_PRESS(u8CounterIndex + 1);
            gu8LastRepeatKey = (u8CounterIndex + 1); //current Id +1 
            gu8RepeatCount = BUTTON_REPEAT_COUNT;
        }

    } else {
        if (gu8ButtonCounterBuffer[u8CounterIndex] >= BUTTON_DEBOUND_COUNT) {
            //Release State
            //reset counter after de-bound
            gu8ButtonCounterBuffer[u8CounterIndex] = 0;
            u8Event = BUTTON_RELEASE(u8CounterIndex + 1);
            if (gu8LastRepeatKey == (u8CounterIndex + 1))
                gu8LastRepeatKey = NOT_A_BUTTON;
        }
    }


    if (u8Event != NOT_AN_EVENT) {
#if (BUZ_MODULE)
        if (putByte(&gsButtonDescriptor, u8Event)) {
            if (u8Event == BUTTON_PRESS(u8CounterIndex + 1)) {
                    buzGenerateSignalTime(100, 0);
            }
        } else {
            if (u8Event == BUTTON_PRESS(u8CounterIndex + 1)) {
                    buzGenerateSignalTime(200, 0);
            }
        }
#else
        putByte(&gsButtonDescriptor, u8Event);
#endif
    }
}

void buttonSync() {

#if(MAX_BUTTONS > 0)
    buttonScan(0, SW_01_PIN, SW_01_PRIORITY);
#endif

    /*
     *************************************************************
     *                       Switch 02                          *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS >1)
    buttonScan(1, SW_02_PIN, SW_02_PRIORITY);
#endif


    /*
     *************************************************************
     *                       Switch 03                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS >2)
    buttonScan(2, SW_03_PIN, SW_03_PRIORITY);
#endif

    /*
     *************************************************************
     *                       Switch 04                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS >3)
    buttonScan(3, SW_04_PIN, SW_04_PRIORITY);
#endif

    /*
     *************************************************************
     *                       Switch 05                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 4)

    buttonScan(4, SW_05_PIN, SW_05_PRIORITY);
#endif


    /*
     *************************************************************
     *                       Switch 06                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 5)
    buttonScan(5, SW_06_PIN, SW_06_PRIORITY);
#endif

    /*
     *************************************************************
     *                       Switch 07                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 6)
    buttonScan(6, SW_07_PIN, SW_07_PRIORITY);
#endif

    /*
     *************************************************************
     *                       Switch 08                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 7)
    buttonScan(6, SW_07_PIN, SW_07_PRIORITY);
#endif

    /*
     *************************************************************
     *                       Switch 09                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 8)
    buttonScan(8, SW_09_PIN, SW_09_PRIORITY);
#endif

    /*
     *************************************************************
     *                       Switch 10                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 9)
    buttonScan(9, SW_10_PIN, SW_10_PRIORITY);
#endif

    /*
     *************************************************************
     *                       Switch 11                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 10)
    buttonScan(10, SW_11_PIN, SW_11_PRIORITY);
#endif

    /*
     *************************************************************
     *                       Switch 12                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 11 )
    buttonScan(11, SW_12_PIN, SW_12_PRIORITY);
#endif

    /*
     *************************************************************
     *                       Switch 13                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 12)
    buttonScan(12, SW_13_PIN, SW_13_PRIORITY);
#endif

    /*
     *************************************************************
     *                       Switch 14                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 13)
    buttonScan(13, SW_14_PIN, SW_14_PRIORITY);
#endif

    /*
     *************************************************************
     *                       Switch 15                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 14)
    buttonScan(14, SW_15_PIN, SW_15_PRIORITY);
#endif

    /*
     *************************************************************
     *                       Switch 16                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 15)
    buttonScan(15, SW_16_PIN, SW_16_PRIORITY);
#endif

    /*
     *************************************************************
     *                       Switch 17                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 16)
    buttonScan(16, SW_17_PIN, SW_17_PRIORITY);
#endif

    /*
     *************************************************************
     *                       Switch 18                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 17)
    buttonScan(17, SW_18_PIN, SW_18_PRIORITY);
#endif

    /*
     *************************************************************
     *                       Switch 19                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 18)
    buttonScan(18, SW_19_PIN, SW_19_PRIORITY);
#endif

    /*
     *************************************************************
     *                       Switch 19                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 19)
    buttonScan(19, SW_20_PIN, SW_20_PRIORITY);
#endif

    /*
     *************************************************************
     *                       Switch 21                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 20)
    buttonScan(21, SW_21_PIN, SW_21_PRIORITY);
#endif

    /*
     *************************************************************
     *                       Switch 22                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 21 )
    buttonScan(21, SW_22_PIN, SW_22_PRIORITY);
#endif

    /*
     *************************************************************
     *                       Switch 23                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 22)
    buttonScan(22, SW_23_PIN, SW_23_PRIORITY);
#endif

    /*
     *************************************************************
     *                       Switch 24                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 23)
    buttonScan(23, SW_24_PIN, SW_24_PRIORITY);
#endif

    //Repeat State
    if (gu8LastRepeatKey != NOT_A_BUTTON) {
        if (--gu8RepeatCount == 0) {
            gu8RepeatCount = BUTTON_REPEAT_RATE_COUNT;
            putByte(&gsButtonDescriptor, BUTTON_REPEAT(gu8LastRepeatKey));
        }
    }

}

void buttonDriverInit() {
    for (uint8_t i = 0; i < MAX_BUTTONS; i++) {
        gu8ButtonCounterBuffer[i] = 0;
    }

    byteBufferInit(&gsButtonDescriptor, gu8ButtonBuffer, BUTTONS_BUFFER_LENGTH);
    gu8LastRepeatKey = NOT_A_BUTTON;
    gu8RepeatCount = 0;

    /*
     *************************************************************
     *                       Switch 01                           *
     * ***********************************************************
     
     */



#if(MAX_BUTTONS > 0)
    digitalpinMode(SW_01_PIN, SW_01_MODE);
#endif

    /*
     *************************************************************
     *                       Switch 02                          *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS >1)
    digitalpinMode(SW_02_PIN, SW_02_MODE);
#endif


    /*
     *************************************************************
     *                       Switch 03                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS >2)
    digitalpinMode(SW_03_PIN, SW_03_MODE);
#endif

    /*
     *************************************************************
     *                       Switch 04                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS >3)
    digitalpinMode(SW_04_PIN, SW_04_MODE);
#endif

    /*
     *************************************************************
     *                       Switch 05                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 4)
    digitalpinMode(SW_05_PIN, SW_05_MODE);
#endif


    /*
     *************************************************************
     *                       Switch 06                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 5)
    digitalpinMode(SW_06_PIN, SW_06_MODE);
#endif

    /*
     *************************************************************
     *                       Switch 07                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 6)
    digitalpinMode(SW_07_PIN, SW_07_MODE);
#endif

    /*
     *************************************************************
     *                       Switch 08                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 7)
    digitalpinMode(SW_08_PIN, SW_08_MODE);
#endif

    /*
     *************************************************************
     *                       Switch 09                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 8)
    digitalpinMode(SW_09_PIN, SW_09_MODE);
#endif

    /*
     *************************************************************
     *                       Switch 10                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 9)
    digitalpinMode(SW_10_PIN, SW_10_MODE);
#endif

    /*
     *************************************************************
     *                       Switch 11                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 10)
    digitalpinMode(SW_11_PIN, SW_11_MODE);
#endif

    /*
     *************************************************************
     *                       Switch 12                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 11 )
    digitalpinMode(SW_12_PIN, SW_12_MODE);
#endif

    /*
     *************************************************************
     *                       Switch 13                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 12)
    digitalpinMode(SW_13_PIN, SW_13_MODE);
#endif

    /*
     *************************************************************
     *                       Switch 14                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 13)
    digitalpinMode(SW_14_PIN, SW_14_MODE);
#endif

    /*
     *************************************************************
     *                       Switch 15                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 14)
    digitalpinMode(SW_15_PIN, SW_15_MODE);
#endif

    /*
     *************************************************************
     *                       Switch 16                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 15)
    digitalpinMode(SW_16_PIN, SW_16_MODE);
#endif

    /*
     *************************************************************
     *                       Switch 17                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 16)
    digitalpinMode(SW_17_PIN, SW_17_MODE);
#endif

    /*
     *************************************************************
     *                       Switch 18                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 17)
    digitalpinMode(SW_18_PIN, SW_18_MODE);
#endif

    /*
     *************************************************************
     *                       Switch 19                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 18)
    digitalpinMode(SW_19_PIN, SW_19_MODE);
#endif

    /*
     *************************************************************
     *                       Switch 19                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 19)
    digitalpinMode(SW_20_PIN, SW_20_MODE);
#endif

    /*
     *************************************************************
     *                       Switch 21                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 20)
    digitalpinMode(SW_21_PIN, SW_21_MODE);
#endif

    /*
     *************************************************************
     *                       Switch 22                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 21 )
    digitalpinMode(SW_21_PIN, SW_21_MODE);
#endif

    /*
     *************************************************************
     *                       Switch 23                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 22)
    digitalpinMode(SW_23_PIN, SW_23_MODE);
#endif

    /*
     *************************************************************
     *                       Switch 24                           *
     * ***********************************************************
     
     */
#if(MAX_BUTTONS > 23)
    digitalpinMode(SW_24_PIN, SW_24_MODE);
#endif
}

uint8_t buttonGetEvent() {
    uint8_t u8Event;
    if (getByte(&gsButtonDescriptor, &u8Event)) {
        return u8Event;
    }
    return NOT_AN_EVENT;
}
#endif
