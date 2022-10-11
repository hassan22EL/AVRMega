/*
 * File:   appEvents.c
 * Author: Hassan
 *
 * Created on August 23, 2022, 7:16 AM
 */


#include "../inc/appRes.h"

volatile uint8_t gu8memStartIndex;
volatile uint8_t gu8EventNumber;
volatile uint8_t gu8Step;

uint8_t appEventStart() {
    return gu8memStartIndex;
}

void appEventInit() {
    gu8memStartIndex = 0;
    gu8EventNumber = 0;
    gu8Step = 0;
}

void appEventSetStart(uint8_t start) {
    gu8memStartIndex = start;
    gu8EventNumber = start;
    gu8Step = 0;
}

/*action*/
uint8_t appEventMove(uint8_t u8Event, uint8_t eventNumber, uint8_t step, uint8_t start, uint8_t maxDigit) {
    if (u8Event != eventNumber)
        return (0);
    if (gu8Step < step - 1) {
        gu8memStartIndex += step;
        gu8Step++;
        if (gu8memStartIndex >= LCD_NUMBER_OF_BYTE) {
            gu8Step = 0;
            gu8memStartIndex = start;
        }
    } else {
        gu8Step = 0;
        gu8memStartIndex = start;
    }
    gu8EventNumber = gu8memStartIndex;
    lcdBlink(1, gu8memStartIndex);
    bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
    return (1);

}

uint8_t appEventRemove(uint8_t u8Event, uint8_t eventNumber, uint8_t maxDigit) {
    if (u8Event != eventNumber)
        return (0);
    if (!lcdIsCurrentNumber(1, gu8EventNumber)) {
        if (gu8EventNumber != gu8memStartIndex) {
            lcdwrite(1, gu8EventNumber - 1, " ");
            lcdBlink(1, gu8EventNumber - 1);
            gu8EventNumber--;
        }
    } else {
        if (gu8EventNumber == (gu8memStartIndex + maxDigit) - 1) {
            lcdwrite(1, gu8EventNumber, " ");
            lcdBlink(1, gu8EventNumber);
        } else {
            // get data from buffer
            lcdReplace(1, gu8EventNumber);
            lcdBlink(1, gu8EventNumber);
        }
    }
    bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
    return (1);
}

uint8_t appEventUp(uint8_t u8Event, uint8_t eventNumber, uint8_t maxDigit) {
    if (u8Event != eventNumber)
        return (0);

    gu8EventNumber++;
    if (!lcdIsCurrentNumber(1, gu8EventNumber) || gu8EventNumber == maxDigit + gu8memStartIndex) {
        gu8EventNumber = gu8memStartIndex;
        lcdBlink(1, gu8EventNumber);

    } else {
        lcdBlink(1, gu8EventNumber);
    }
    bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
    return (1);
}

uint8_t appEventDown(uint8_t u8Event, uint8_t eventNumber, uint8_t maxDigit) {

    uint8_t u8pos;
    uint8_t mined;

    if (u8Event != eventNumber)
        return (0);
    u8pos = gu8memStartIndex;
    gu8EventNumber--;
    while (lcdIsCurrentNumber(1, u8pos)) {
        u8pos++;
        if (u8pos == (maxDigit + gu8memStartIndex)) {
            break;
        }
    }
    if (gu8memStartIndex == 0)
        mined = 0xff;
    else
        mined = gu8memStartIndex - 1;

    if (gu8EventNumber == mined) {
        gu8EventNumber = u8pos;
        lcdBlink(1, gu8EventNumber);
    } else {
        lcdBlink(1, gu8EventNumber);
    }
    bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
    return (1);
}

uint8_t appEventNumber(uint8_t u8Event, const char *s, uint8_t eventNumber, uint8_t maxDigit) {
    if (u8Event != eventNumber)
        return (0);
    lcdwrite(1, gu8EventNumber, s);
    if (gu8EventNumber < (gu8memStartIndex + maxDigit) - 1) {
        lcdBlink(1, gu8EventNumber + 1);
        gu8EventNumber++;
    } else {
        gu8EventNumber = gu8memStartIndex;
        lcdBlink(1, gu8memStartIndex);
    }
    bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
    bitsValue(gu8MnueFlags, 0x03, APP_MENU_EVENT_RESPONS);
    return (1);
}

uint8_t appEventGetEventNumber() {
    return gu8EventNumber;
}

uint8_t appEventCencel(uint8_t u8Event, uint8_t eventNumber) {
    if (u8Event != eventNumber)
        return (0);
    if (appMenuReadEvents() != 0x04) {
        bitsValue(gu8MnueFlags, 0x01, APP_MENU_EVENT_RESPONS);
    } else {
        bitsValue(gu8MnueFlags, 0x05, APP_MENU_EVENT_RESPONS);
    }
    return (1);
}

uint8_t appEventEnter(uint8_t u8Event, uint8_t eventNumber) {
    if (u8Event != eventNumber)
        return (0);
    if (appMenuReadEvents() != 0x04) {
        bitsValue(gu8MnueFlags, 0x02, APP_MENU_EVENT_RESPONS);
    } else {
        bitsValue(gu8MnueFlags, 0x05, APP_MENU_EVENT_RESPONS);
    }
    return (1);
}