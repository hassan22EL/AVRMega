/*
 * File:   keypadEvent.c
 * Author: hassa
 *
 * Created on July 14, 2022, 5:21 AM
 */


#include <stdint-gcc.h>

#include "../../inc/mega.h"
#if KEYPADEVENT_MODULE
volatile uint8_t gu8Event;
volatile uint8_t gu8EventState;

void keypadEventInit() {
    gu8EventState = 0x00;
    gu8Event = 0;

}

void keypadEventSet(uint8_t u8Index) {
    if (u8Index >= KEYPAD_MAX_EVENT)
        return;
    gu8EventState |= (1 << u8Index);
}

uint8_t keypadEventRead(uint8_t u8Index) {
    if (bitIsClear(gu8EventState, u8Index))
        return gu8Event;
    return KEYPAD_NOT_AN_EVENT;
}

void keypadEvent() {
    if ((gu8EventState & KEYPAD_MASK_EVENT) != KEYPAD_MASK_EVENT)
        return;
    gu8Event = keypadGetEvent();
    gu8EventState = 0x00;
}
#endif