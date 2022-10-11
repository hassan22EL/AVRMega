
#include <stdint-gcc.h>
#include <string.h>

#include "../../inc/mega.h"

#if LCD_MODULE

#define  LCD_ERORR_01        0x01
const uint8_t CGRAM_ZERO[] = {
    0b11111,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b11111
};
const uint8_t CGRAM_ONE[] = {
    0b11111,
    0b10000,
    0b10000,
    0b10000,
    0b10000,
    0b10000,
    0b10000,
    0b11111
};
const uint8_t CGRAM_TWO[] = {
    0b11111,
    0b11000,
    0b11000,
    0b11000,
    0b11000,
    0b11000,
    0b11000,
    0b11111
};
const uint8_t CGRAM_THREE[] = {
    0b11111,
    0b11100,
    0b11100,
    0b11100,
    0b11100,
    0b11100,
    0b11100,
    0b11111
};
const uint8_t CGRAM_FOUR[] = {
    0b11111,
    0b11110,
    0b11110,
    0b11110,
    0b11110,
    0b11110,
    0b11110,
    0b11111
};
const uint8_t CGRAM_FIVE[] = {
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111
};








volatile uint8_t gu8LCDPosition;
volatile uint8_t gu8LCDBuffer[LCD_SIZE];
volatile uint8_t gu8LcdOPtion;
volatile uint8_t gu8LcdBufferIndex;
volatile uint8_t gu8lcdState;
#define  LCD_BUSY_FLAG      (7)
#define  LCD_READ_FLAG      (6)
#define  LCD_UPDATE_MASK    (0x07)




void lcdCgramGenrate(const uint8_t *pData, uint8_t location);
void lcdWaitBusy();
void lcdSendByte(uint8_t u8Byte);
void lcdSendCommand(uint8_t u8Cmd);
void lcdSend(uint8_t u8Data);
uint8_t lcdRead(uint8_t type);
uint8_t lcdReadByte();
void lcdSendCommdHigh(uint8_t u8Data);

void lcdHwInit() {
    /*4 bit mode*/
    if ((LCD_RS == NOT_A_PIN) ||
            (LCD_EN == NOT_A_PIN) ||
            (LCD_RW == NOT_A_PIN) ||
            (LCD_D4 == NOT_A_PIN) ||
            (LCD_D5 == NOT_A_PIN) ||
            (LCD_D6 == NOT_A_PIN) ||
            (LCD_D7 == NOT_A_PIN))
        return;
    digitalpinMode(LCD_RS, MODE_OUTPUT);
    digitalpinMode(LCD_EN, MODE_OUTPUT);
    digitalpinMode(LCD_RW, MODE_OUTPUT);
    digitalpinMode(LCD_D4, MODE_OUTPUT);
    digitalpinMode(LCD_D5, MODE_OUTPUT);
    digitalpinMode(LCD_D6, MODE_OUTPUT);
    digitalpinMode(LCD_D7, MODE_OUTPUT);
    for (uint8_t i = 0; i < LCD_SIZE; i++)
        gu8LCDBuffer[i] = 0x20;
    gu8LcdOPtion = LCD_DISPLAY_ON_COMMAND; /*the display on*/
    gu8LCDPosition = 0;
    gu8LcdBufferIndex = 0;
    gu8lcdState = 0;
    lcdInit();
}

void lcdInit() {
    _delay_ms(15); /*this function is can't aysnc*/
    lcdSendCommdHigh(LCD_8BIT_COMMAND);
    _delay_ms(5);
    lcdSendCommdHigh(LCD_8BIT_COMMAND);
    _delay_us(100);
    lcdSendCommdHigh(LCD_8BIT_COMMAND);
#if GPIO2_USE_INLINE_FUNCTIONS
    _delay_us(37);
#else
    _delay_us(25);
#endif
    lcdSendCommdHigh(LCD_4BIT_COMMAND);
#if GPIO2_USE_INLINE_FUNCTIONS
    _delay_us(37);
#else
    _delay_us(25);
#endif
    lcdSendCommand(LCD_2LINE_COMMAND);
    lcdSendCommand(LCD_DISPLAY_ON_COMMAND);
    lcdSendCommand(LCD_CLEAR_COMMAND);
    lcdSendCommand(LCD_ENTRY_SET);
    /*create custom char*/
    lcdCgramGenrate(CGRAM_ZERO, 0);
    lcdCgramGenrate(CGRAM_ONE, 1);
    lcdCgramGenrate(CGRAM_TWO, 2);
    lcdCgramGenrate(CGRAM_THREE, 3);
    lcdCgramGenrate(CGRAM_FOUR, 4);
    lcdCgramGenrate(CGRAM_FIVE, 5);
}

uint8_t lcdReadByte() {
    uint8_t u8Byte;
    u8Byte = 0;
    lcdWaitBusy();
    digitalpinMode(LCD_D4, MODE_INPUT);
    digitalpinMode(LCD_D5, MODE_INPUT);
    digitalpinMode(LCD_D6, MODE_INPUT);
    digitalpinMode(LCD_D7, MODE_INPUT);
    digitalPinWrite(LCD_RS, GPIO_LOW); //RS = 0
    digitalPinWrite(LCD_RW, GPIO_HIGH); //RW=1

    digitalPinWrite(LCD_EN, GPIO_HIGH);
    if (digitalPinRead(LCD_D4))
        u8Byte |= 0x10;
    if (digitalPinRead(LCD_D5))
        u8Byte |= 0x20;
    if (digitalPinRead(LCD_D6))
        u8Byte |= 0x40;
    digitalPinWrite(LCD_EN, GPIO_LOW);
    digitalPinWrite(LCD_EN, GPIO_HIGH);
    if (digitalPinRead(LCD_D4))
        u8Byte |= 0x01;
    if (digitalPinRead(LCD_D5))
        u8Byte |= 0x02;
    if (digitalPinRead(LCD_D6))
        u8Byte |= 0x04;
    if (digitalPinRead(LCD_D7))
        u8Byte |= 0x08;
    digitalPinWrite(LCD_EN, GPIO_LOW);
    digitalpinMode(LCD_D4, MODE_OUTPUT);
    digitalpinMode(LCD_D5, MODE_OUTPUT);
    digitalpinMode(LCD_D6, MODE_OUTPUT);
    digitalpinMode(LCD_D7, MODE_OUTPUT);
    digitalPinWrite(LCD_RW, GPIO_LOW); //R=1
    return (u8Byte);
}

void lcdWaitBusy() {
    uint8_t state;
    state = 0;
    uint16_t Timeout;
    digitalpinMode(LCD_D4, MODE_INPUT); /* 600ns*/
    digitalpinMode(LCD_D5, MODE_INPUT); /*600ns*/
    digitalpinMode(LCD_D6, MODE_INPUT); /*600ns*/
    digitalpinMode(LCD_D7, MODE_INPUT); /*600ns*/
    digitalPinWrite(LCD_RS, GPIO_LOW); //RS=0; /*600ns*/
    digitalPinWrite(LCD_RW, GPIO_HIGH); //RW=1 /*600ns*/
    Timeout = microsecondsToClockCycles(100);
    do {
        digitalPinWrite(LCD_EN, GPIO_HIGH);
        Timeout--;
        state = digitalPinRead(LCD_D7);
        digitalPinWrite(LCD_EN, GPIO_LOW);
        Pulse_En();
    } while (state && Timeout); /*and wait 60us and break loop*/
    if (!Timeout) gu8ErrorCode = LCD_ERORR_01;
    digitalpinMode(LCD_D4, MODE_OUTPUT);
    digitalpinMode(LCD_D5, MODE_OUTPUT);
    digitalpinMode(LCD_D6, MODE_OUTPUT);
    digitalpinMode(LCD_D7, MODE_OUTPUT);
    digitalPinWrite(LCD_RW, GPIO_LOW);
}

void lcdSend(uint8_t u8Data) {
    /*total time 8u = 800ns *4 + 1300ns  + 800ns *4 + 1300ns = 8000ns = */
    digitalPinWrite(LCD_D4, BitCheck(u8Data, 4)); /*800ns = 600ns write + 200ns bit check*/
    digitalPinWrite(LCD_D5, BitCheck(u8Data, 5)); /*800ns = 600ns write + 200ns bit check*/
    digitalPinWrite(LCD_D6, BitCheck(u8Data, 6)); /*800ns = 600ns write + 200ns bit check*/
    digitalPinWrite(LCD_D7, BitCheck(u8Data, 7)); /*800ns = 600ns write + 200ns bit check*/
    Pulse_En(); /*1300 ns*/
    digitalPinWrite(LCD_D4, BitCheck(u8Data, 0)); /*800ns = 600ns write + 200ns bit check*/
    digitalPinWrite(LCD_D5, BitCheck(u8Data, 1)); /*800ns = 600ns write + 200ns bit check*/
    digitalPinWrite(LCD_D6, BitCheck(u8Data, 2)); /*800ns = 600ns write + 200ns bit check*/
    digitalPinWrite(LCD_D7, BitCheck(u8Data, 3)); /*800ns = 600ns write + 200ns bit check*/
    Pulse_En(); /*1300ns*/
}

uint8_t lcdUpdate() {
    lcdSendCommand((LCD_CGRRAM_MODE | LCD_CGRAM_ADDRESS_CHECK));
    if (lcdReadByte() != (LCD_CGRRAM_MODE | LCD_CGRAM_ADDRESS_CHECK)) {
        lcdInit();
        if (gu8ErrorCode == LCD_ERORR_01)
            return (1);
        return (0);
    }

    while (gu8LcdBufferIndex < LCD_SIZE) {
        if (gu8LcdBufferIndex % LCD_NUMBER_OF_BYTE == 0) {
            lcdSendCommand(lcdPosToAddress((gu8LcdBufferIndex / LCD_NUMBER_OF_BYTE), 0));
            if (gu8ErrorCode == LCD_ERORR_01) {
                gu8LcdBufferIndex = 0;
                return (1);
            }
        }
        lcdSendByte(gu8LCDBuffer[gu8LcdBufferIndex]);
        if (gu8ErrorCode == LCD_ERORR_01) {
            return (1);
        }
        gu8LcdBufferIndex++;
        /*break after 60u*/
    }
    gu8LcdBufferIndex = 0;
    lcdSendCommand(gu8LCDPosition);
    lcdSendCommand(LCD_DISPLAY_ON_COMMAND | gu8LcdOPtion);
    return (1);
}

void lcdSendCommand(uint8_t u8Cmd) {
    lcdWaitBusy();
    digitalPinWrite(LCD_RS, GPIO_LOW);
    lcdSend(u8Cmd);
}

void lcdSendCommdHigh(uint8_t u8Data) {
    digitalPinWrite(LCD_RS, GPIO_LOW);
    digitalPinWrite(LCD_D4, BitCheck(u8Data, 4));
    digitalPinWrite(LCD_D5, BitCheck(u8Data, 5));
    digitalPinWrite(LCD_D6, BitCheck(u8Data, 6));
    digitalPinWrite(LCD_D7, BitCheck(u8Data, 7));
    Pulse_En();
}

void lcdSendByte(uint8_t u8Byte) {
    lcdWaitBusy();
    digitalPinWrite(LCD_RS, GPIO_HIGH);
    lcdSend(u8Byte);
}

void lcdCursor(uint8_t u8line, uint8_t u8pos) {
    gu8LCDPosition = lcdPosToAddress(u8line, u8pos);
    bitSet(gu8LcdOPtion, LCD_CUSOR);
}

void lcdNoCursor() {
    bitClear(gu8LcdOPtion, LCD_CUSOR);
}

void lcdBlink(uint8_t u8line, uint8_t u8pos) {
    gu8LCDPosition = lcdPosToAddress(u8line, u8pos);
    bitSet(gu8LcdOPtion, LCD_BLINK);
}

void lcdNoBlink() {
    bitClear(gu8LcdOPtion, LCD_BLINK);
}

void lcdwrite(uint8_t line, uint8_t pos, const char *string) {
    uint8_t newPos;
    if (pos != LCD_TEXT_CENTER) {
        newPos = line * LCD_NUMBER_OF_BYTE + pos;
    } else {
        newPos = line * LCD_NUMBER_OF_BYTE + ((LCD_NUMBER_OF_BYTE - strlen(string)) / 2);
    }
    for (uint8_t i = 0; i < strlen(string); i++)
        gu8LCDBuffer[newPos + i] = string[i];
}

void lcdReplace(uint8_t line, uint8_t startpos) {
    uint8_t i;
    i = line * LCD_NUMBER_OF_BYTE + startpos;
    while (gu8LCDBuffer[i] != 0x20) {
        gu8LCDBuffer[i] = gu8LCDBuffer[i + 1];
        i++;
    }
    gu8LCDBuffer[i] = ' ';
}

void lcdCgramGenrate(const uint8_t *pData, uint8_t location) {
    location &= 0x07;
    location *= 8;
    lcdSendCommand(LCD_CGRRAM_MODE + location);
    for (uint8_t j = 0; j < 8; j++) {
        lcdSendByte(pData[j]);
    }
}

void lcdClearlines(uint8_t from) {
    for (uint8_t i = from * LCD_NUMBER_OF_BYTE; i < LCD_SIZE; i++) {
        gu8LCDBuffer[i] = 0x20;
    }
}

void lcdClear() {
    for (uint8_t j = 0; j < LCD_SIZE; j++) {
        gu8LCDBuffer[j] = 0x20;
    }
}

void getlcdData(char *str, uint8_t line, uint8_t pos) {
    /*memory */
    uint8_t i, u8count;
    i = line * LCD_NUMBER_OF_BYTE + pos;
    u8count = 0;
    while (gu8LCDBuffer[i] != 0x20) {
        str[u8count++] = gu8LCDBuffer[i];
        i++;
        if (i % LCD_NUMBER_OF_BYTE == 0) {
            break;
        }
    }
}

void lcdwriteCGRAM(uint8_t line, uint8_t pos, uint8_t index) {
    uint8_t newPos;
    newPos = line * LCD_NUMBER_OF_BYTE + pos;
    gu8LCDBuffer[newPos] = index;
}

uint8_t lcdIsCurrentNumber(uint8_t line, uint8_t pos) {
    uint8_t newPos;
    newPos = line * LCD_NUMBER_OF_BYTE + pos;
    if (gu8LCDBuffer[newPos] >= '0' && gu8LCDBuffer[newPos] <= '9')
        return (1);
    return (0);
}
#endif