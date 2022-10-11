#include <stdint-gcc.h>

#include "../../inc/mega.h"

#if LCD_MODULE 

volatile uint8_t gu8LCDFlags;
volatile uint8_t gu8LCDPosition;
volatile uint8_t gu8LcdOPtion;
volatile uint8_t gu8LcdBufferIndex;
volatile uint8_t gu8LCDBuffer[LCD_NUMBER_OF_LINES][LCD_NUMBER_OF_BYTE];
uint8_t lcdPosToAddress(uint8_t u8line, uint8_t u8pos);
void lcdwriteCMD(uint8_t u8Cmd);

#if(LCD_BITS_MODE == LCD_8BIT_MODE)

void lcdWriteByte(uint8_t u8Byte);

void lcdWriteByte(uint8_t u8Byte) {

    /*8 bit data*/

    /*write bit 7*/
    if ((u8Byte & 0x80)) {
        digitalPinWrite(LCD_D7, GPIO_HIGH);
    } else {
        digitalPinWrite(LCD_D7, GPIO_LOW);
    }

    /*write bit 6*/
    if ((u8Byte & 0x40)) {
        digitalPinWrite(LCD_D6, GPIO_HIGH);
    } else {
        digitalPinWrite(LCD_D6, GPIO_LOW);
    }
    /*write bit 5*/
    if ((u8Byte & 0x20)) {
        digitalPinWrite(LCD_D5, GPIO_HIGH);
    } else {
        digitalPinWrite(LCD_D5, GPIO_LOW);
    }

    /*write bit 4*/
    if ((u8Byte & 0x10)) {
        digitalPinWrite(LCD_D4, GPIO_HIGH);
    } else {

        digitalPinWrite(LCD_D4, GPIO_LOW);
    }
    /*write bit 3*/
    if ((u8Byte & 0x08)) {
        digitalPinWrite(LCD_D3, GPIO_HIGH);
    } else {

        digitalPinWrite(LCD_D3, GPIO_LOW);
    }
    /*write bit 2*/
    if ((u8Byte & 0x04)) {
        digitalPinWrite(LCD_D2, GPIO_HIGH);
    } else {

        digitalPinWrite(LCD_D2, GPIO_LOW);
    }
    /*write bit 2*/
    if ((u8Byte & 0x02)) {
        digitalPinWrite(LCD_D1, GPIO_HIGH);
    } else {
        digitalPinWrite(LCD_D1, GPIO_LOW);
    }
    /*write bit 0*/
    if ((u8Byte & 0x01)) {
        digitalPinWrite(LCD_D0, GPIO_HIGH);
    } else {
        digitalPinWrite(LCD_D0, GPIO_LOW);
    }
    digitalPinWrite(LCD_EN, GPIO_HIGH);
    _delay_us(1);
    digitalPinWrite(LCD_EN, GPIO_LOW);
    _delay_us(LCD_OPERATION_TIME);

}

#if (LCD_LINE_MODE == LCD_INTERAVTIVE)

uint8_t lcdRead();
uint8_t lcdReadByte();

uint8_t lcdRead() {

    uint8_t u8Readbit;

    digitalpinMode(LCD_D0, MODE_INPUT);
    digitalpinMode(LCD_D1, MODE_INPUT);
    digitalpinMode(LCD_D2, MODE_INPUT);
    digitalpinMode(LCD_D3, MODE_INPUT);
    digitalpinMode(LCD_D4, MODE_INPUT);
    digitalpinMode(LCD_D5, MODE_INPUT);
    digitalpinMode(LCD_D6, MODE_INPUT);
    digitalpinMode(LCD_D7, MODE_INPUT);

    digitalPinWrite(LCD_RW, GPIO_HIGH);

    u8Readbit = lcdReadByte();

    digitalPinWrite(LCD_RS, GPIO_HIGH);

    digitalpinMode(LCD_D0, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D1, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D2, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D3, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D4, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D5, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D6, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D7, MODE_OUTPUT_LOW);

    digitalPinWrite(LCD_RW, GPIO_LOW);

    return (u8Readbit);
}

uint8_t lcdReadByte() {
    uint8_t u8Byte;

    digitalPinWrite(LCD_EN, GPIO_HIGH);

    u8Byte = 0;

    if (digitalPinRead(LCD_D7)) {
        u8Byte |= 0x80;
    }
    if (digitalPinRead(LCD_D6)) {
        u8Byte |= 0x40;
    }
    if (digitalPinRead(LCD_D5)) {
        u8Byte |= 0x20;
    }
    if (digitalPinRead(LCD_D4)) {
        u8Byte |= 0x10;
    }
    if (digitalPinRead(LCD_D3)) {
        u8Byte |= 0x08;
    }
    if (digitalPinRead(LCD_D2)) {
        u8Byte |= 0x04;
    }

    if (digitalPinRead(LCD_D1)) {
        u8Byte |= 0x02;
    }
    if (digitalPinRead(LCD_D0)) {
        u8Byte |= 0x01;
    }
    digitalPinWrite(LCD_EN, GPIO_LOW);

    return (u8Byte);
}

void lcdHwInit() {
    /*8 bit mode*/

    if ((LCD_RS == NOT_A_PIN) ||
            (LCD_EN == NOT_A_PIN) ||
            (LCD_RW == NOT_A_PIN) ||
            (LCD_D0 == NOT_A_PIN) ||
            (LCD_D1 == NOT_A_PIN) ||
            (LCD_D2 == NOT_A_PIN) ||
            (LCD_D3 == NOT_A_PIN) ||
            (LCD_D4 == NOT_A_PIN) ||
            (LCD_D5 == NOT_A_PIN) ||
            (LCD_D6 == NOT_A_PIN) ||
            (LCD_D7 == NOT_A_PIN))
        return;

    digitalpinMode(LCD_RS, MODE_OUTPUT_HIGH);

    digitalpinMode(LCD_RW, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_EN, MODE_OUTPUT_LOW);

    digitalpinMode(LCD_D0, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D1, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D2, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D3, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D4, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D5, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D6, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D7, MODE_OUTPUT_LOW);

    gu8LCDFlags = 0;
    gu8LcdOPtion = LCD_DISPLAY_ON_COMMAND; /*the display on*/
    gu8LCDPosition = 0x00; /*no position set*/
    genLCDInitState = LCD_INIT_IDLE;
    genLCDUpdateState = LCD_UPDATE_IDLE;
    gu8LcdBufferIndex = 0;
    for (int i = 0; i < LCD_NUMBER_OF_LINES; i++) {
        for (int j = 0; j < LCD_NUMBER_OF_BYTE; i++) {
            gu8LCDBuffer[i][j] = ' ';
        }
    }
}

uint8_t lcdUpdate() {

    switch (genLCDUpdateState) {
        case LCD_UPDATE_IDLE:
            /*return to DDRAM*/
            if (lcdInit()) {
                /*set period*/
                /*change rw as a high to read a data*/
                digitalPinWrite(LCD_RS, GPIO_LOW); /*write a command*/
                /*write byte in CGRAM*/
                lcdWriteByte(LCD_CGRRAM_MODE | LCD_CGRAM_ADDRESS_CHECK); /*write data into CGRAM with address 0x07*/
                digitalPinWrite(LCD_RS, GPIO_HIGH); /*write a command*/
                lcdWriteByte(0xA5);
                genLCDUpdateState = LCD_UPDATE_CHECK;
            }
            break;
        case LCD_UPDATE_CHECK:
            /*read byte*/
            digitalPinWrite(LCD_RS, GPIO_LOW); /*write a command*/
            if (!(lcdRead() & 0x80)) {
                /*write byte*/
                /*write byte in CGRAM*/
                /*check the byte read*/
                digitalPinWrite(LCD_RS, GPIO_LOW); /*write a command*/
                lcdWriteByte(LCD_CGRRAM_MODE | LCD_CGRAM_ADDRESS_CHECK); /*write data into CGRAM with address 0x07*/
                digitalPinWrite(LCD_RS, GPIO_HIGH); /*write a command*/

                if (lcdRead() != (0xA5)) {
                    /*check the Time */
                    /*set current time and period*/
                    if (bitIsClear(gu8LCDFlags, LCD_ReInit_SET_TIME_OUT_FLAG)) {
                        sysSetTimer(&gsLCDUpdateTimeOUT, getSystemTick());
                        sysSetPeriodMS(&gsLCDUpdateTimeOUT, LCD_UPDATE_TIME_OUT);
                        bitSet(gu8LCDFlags, LCD_ReInit_SET_TIME_OUT_FLAG);
                    }
                    if (sysIsTimeout(&gsLCDUpdateTimeOUT)) {
                        genLCDUpdateState = LCD_UPDATE_CHECK; /*default state */
                        return (LCD_OK); /*LCD OK With NO DATA SHOW*/
                    } else {
                        genLCDUpdateState = LCD_UPDATE_IDLE;
                    }
                } else {
                    /*return to DDRAM*/
                    gu8LcdBufferIndex = 0;
                    digitalPinWrite(LCD_RS, GPIO_LOW); /*write a command*/
                    lcdWriteByte(LCD_DDRAM_MODE); /*write data into CGRAM with address 0x07*/
                    digitalPinWrite(LCD_RS, GPIO_HIGH); /*write a command*/
                    genLCDUpdateState = LCD_UPDATE_WRITE;
                }
            }

            break;
        case LCD_UPDATE_WRITE:

            if (bitIsClear(gu8LcdOPtion, LCD_DISPLAY)) {
                /*the display on write command*/
                digitalPinWrite(LCD_RS, GPIO_LOW);
                /*set the display on*/
                lcdWriteByte(LCD_DISPLAY_ON_COMMAND);
                digitalPinWrite(LCD_RS, GPIO_HIGH);
                genLCDUpdateState = LCD_UPDATE_CHECK; /*default state*/
                return (LCD_OK);
            }
            if ((gu8LcdBufferIndex / LCD_NUMBER_OF_BYTE) != LCD_NUMBER_OF_LINES) {
                /*write a bytes*/
                if (gu8LcdBufferIndex % LCD_NUMBER_OF_BYTE == 0) {
                    digitalPinWrite(LCD_RS, GPIO_LOW);
                    lcdWriteByte(lcdPosToAddress((gu8LcdBufferIndex / LCD_NUMBER_OF_BYTE), 0));
                    digitalPinWrite(LCD_RS, GPIO_HIGH);
                }
                lcdWriteByte(gu8LCDBuffer[(gu8LcdBufferIndex / LCD_NUMBER_OF_BYTE)][(gu8LcdBufferIndex % LCD_NUMBER_OF_BYTE)]);
                gu8LcdBufferIndex++;
            } else {
                /*the display on write command*/
                digitalPinWrite(LCD_RS, GPIO_LOW);
                /*set the display on*/
                gu8LcdBufferIndex = 0;
                lcdWriteByte(LCD_DISPLAY_ON_COMMAND);
                digitalPinWrite(LCD_RS, GPIO_HIGH);
                genLCDUpdateState = LCD_UPDATE_POS; /*next state*/
            }
            break;
        case LCD_UPDATE_POS:
            /*the change*/
            /*check the cursor*/

            digitalPinWrite(LCD_RS, GPIO_LOW);
            /*write pos*/
            lcdWriteByte(gu8LCDPosition);
            /*set option*/
            lcdWriteByte(LCD_DISPLAY_ON_COMMAND | gu8LcdOPtion);

            digitalPinWrite(LCD_RS, GPIO_HIGH); /*reset */
            genLCDUpdateState = LCD_UPDATE_CHECK;
            return (LCD_OK);
            break;
        default:
            genLCDUpdateState = LCD_UPDATE_CHECK; /*default state */
            break;
    }
    return (LCD_RUNNING);
}



#elif (LCD_LINE_MODE==LCD_NONINTERACTIVE)

void lcdHwInit() {
    /*8 bit mode*/
    if ((LCD_RS == NOT_A_PIN) ||
            (LCD_EN == NOT_A_PIN) ||
            (LCD_D0 == NOT_A_PIN) ||
            (LCD_D1 == NOT_A_PIN) ||
            (LCD_D2 == NOT_A_PIN) ||
            (LCD_D3 == NOT_A_PIN) ||
            (LCD_D4 == NOT_A_PIN) ||
            (LCD_D5 == NOT_A_PIN) ||
            (LCD_D6 == NOT_A_PIN) ||
            (LCD_D7 == NOT_A_PIN))

        return;

    digitalpinMode(LCD_RS, MODE_OUTPUT_HIGH);
    digitalpinMode(LCD_EN, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D0, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D1, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D2, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D3, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D4, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D5, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D6, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D7, MODE_OUTPUT_LOW);

    gu8LCDFlags = 0;
    gu8LcdOPtion = LCD_DISPLAY_ON_COMMAND; /*the display on*/
    gu8LCDPosition = 0x00; /*no position set*/
    genLCDInitState = LCD_INIT_IDLE;
    genLCDUpdateState = LCD_UPDATE_IDLE;
    gu8LcdBufferIndex = 0;
    for (int i = 0; i < LCD_NUMBER_OF_LINES; i++) {
        for (int j = 0; j < LCD_NUMBER_OF_BYTE; i++) {
            gu8LCDBuffer[i][j] = ' ';
        }
    }
}

uint8_t lcdUpdate() {

    switch (genLCDUpdateState) {
        case LCD_UPDATE_IDLE:
            if (lcdInit()) {
                /*set period*/
                genLCDUpdateState = LCD_UPDATE_CHECK;
            }
            break;
        case LCD_UPDATE_CHECK:
            /*read byte*/
            gu8LcdBufferIndex = 0;
            genLCDUpdateState = LCD_UPDATE_WRITE;
            break;
        case LCD_UPDATE_WRITE:

            if (bitIsClear(gu8LcdOPtion, LCD_DISPLAY)) {
                /*the display on write command*/
                digitalPinWrite(LCD_RS, GPIO_LOW);
                /*set the display on*/
                lcdWriteByte(LCD_DISPLAY_ON_COMMAND);
                digitalPinWrite(LCD_RS, GPIO_HIGH);
                genLCDUpdateState = LCD_UPDATE_CHECK; /*default state*/
                return (LCD_OK);
            }
            if ((gu8LcdBufferIndex / LCD_NUMBER_OF_BYTE) != LCD_NUMBER_OF_LINES) {
                /*write a bytes*/
                if (gu8LcdBufferIndex % LCD_NUMBER_OF_BYTE == 0) {
                    digitalPinWrite(LCD_RS, GPIO_LOW);
                    lcdWriteByte(lcdPosToAddress((gu8LcdBufferIndex / LCD_NUMBER_OF_BYTE), 0));
                    digitalPinWrite(LCD_RS, GPIO_HIGH);
                }
                lcdWriteByte(gu8LCDBuffer[(gu8LcdBufferIndex / LCD_NUMBER_OF_BYTE)][(gu8LcdBufferIndex % LCD_NUMBER_OF_BYTE)]);
                gu8LcdBufferIndex++;
            } else {
                /*the display on write command*/
                digitalPinWrite(LCD_RS, GPIO_LOW);
                /*set the display on*/
                /*set the display on*/
                gu8LcdBufferIndex = 0;
                lcdWriteByte(LCD_DISPLAY_ON_COMMAND);
                digitalPinWrite(LCD_RS, GPIO_HIGH);
                genLCDUpdateState = LCD_UPDATE_POS; /*next state*/
            }
            break;
        case LCD_UPDATE_POS:
            /*the change*/
            /*check the cursor*/
            digitalPinWrite(LCD_RS, GPIO_LOW);
            /*write pos*/
            lcdWriteByte(gu8LCDPosition);
            /*set option*/
            lcdWriteByte(LCD_DISPLAY_ON_COMMAND | gu8LcdOPtion);
            digitalPinWrite(LCD_RS, GPIO_HIGH); /*reset */
            genLCDUpdateState = LCD_UPDATE_CHECK;
            return (LCD_OK);
            break;
        default:
            genLCDUpdateState = LCD_UPDATE_CHECK; /*default state */
            break;
    }
    return (LCD_RUNNING);
}

#endif

//uint8_t lcdInit() {
//
//    switch (genLCDInitState) {
//        case LCD_INIT_IDLE:
//            digitalPinWrite(LCD_RS, GPIO_LOW);
//            sysSetTimer(&gstLCDInitTime, getSystemTick());
//            sysSetPeriodMS(&gstLCDInitTime, LCD_TIMING_POWER_ON);
//            genLCDInitState = LCD_INIT_WAIT;
//            break;
//        case LCD_INIT_WAIT:
//            if (sysIsTimeout(&gstLCDInitTime)) {
//                lcdWriteByte(LCD_8BIT_COMMAND);
//                genLCDInitState = LCD_INIT_WRITE_HIGH;
//            }
//            break;
//        case LCD_INIT_WRITE_HIGH:
//            if (bitIsClear(gu8LCDFlags, LCD_INIT_WRITE_HIGH_FLAG)) {
//                sysSetPeriodMS(&gstLCDInitTime, LCD_TIMING_8BIT_LONG); /*se period 5ms*/
//                sysSetTimer(&gstLCDInitTime, getSystemTick());
//                bitSet(gu8LCDFlags, LCD_INIT_WRITE_HIGH_FLAG);
//                genLCDInitState = LCD_INIT_WAIT;
//            } else {
//                bitClear(gu8LCDFlags, LCD_INIT_WRITE_HIGH_FLAG);
//                genLCDInitState = LCD_INIT_WRITE_COMMAND;
//
//            }
//            break;
//
//        case LCD_INIT_WRITE_COMMAND:
//
//            lcdWriteByte(LCD_8BIT_COMMAND);
//            _delay_us(100);
//            lcdWriteByte(LCD_8BIT_COMMAND);
//            /*4bit mode setting*/
//            /*8bit mode setting*/
//            lcdWriteByte(LCD_8BIT_COMMAND); /*0x3*  */
//            lcdWriteByte(LCD_8BIT_2LINE_COMMAND);
//            lcdWriteByte(LCD_DISPLAY_OFF_COMMAND);
//            /*set Time of the Clear Command*/
//            sysSetPeriodMS(&gstLCDInitTime, LCD_TIMING_CLEAR_COMMAND); /*se period 2ms*/
//            sysSetTimer(&gstLCDInitTime, getSystemTick());
//            lcdWriteByte(LCD_CLEAR_COMMAND);
//            genLCDInitState = LCD_INIT_WRITE_CLEAR_COMMAND;
//            break;
//        case LCD_INIT_WRITE_CLEAR_COMMAND:
//            if (sysIsTimeout(&gstLCDInitTime)) {
//                lcdWriteByte(LCD_ENTRY_SET);
//                digitalPinWrite(LCD_RS, GPIO_HIGH); /*default state of a write data */
//                genLCDInitState = LCD_INIT_IDLE;
//                return (1);
//            }
//            break;
//        default:
//            genLCDInitState = LCD_INIT_IDLE;
//            break;
//    }
//    return (0);
//}

uint8_t lcdInit() {
    digitalPinWrite(LCD_RS, GPIO_LOW);
    _delay_ms(LCD_TIMING_POWER_ON);
    LcdWriteHigh(LCD_8BIT_COMMAND);
    _delay_us(100);
    LcdWriteHigh(LCD_8BIT_COMMAND);
    /*4bit mode setting*/
    lcdWriteByte(LCD_8BIT_COMMAND); /*0x3*  */
    lcdWriteByte(LCD_8BIT_2LINE_COMMAND);
    lcdWriteByte(LCD_DISPLAY_OFF_COMMAND);
    _delay_ms(LCD_TIMING_CLEAR_COMMAND);
    lcdWriteByte(LCD_ENTRY_SET);
    digitalPinWrite(LCD_RS, GPIO_HIGH); /*default state of a write data */
    return (1);
}
#elif (LCD_BITS_MODE == LCD_4BIT_MODE)


void LcdWriteHigh(uint8_t u8Byte);
void lcdWriteByte(uint8_t u8Byte);

void LcdWriteHigh(uint8_t uMSB8Byte) {
    /*write bit 7*/
    if ((uMSB8Byte & 0x80)) {
        digitalPinWrite(LCD_D7, GPIO_HIGH);
    } else {
        digitalPinWrite(LCD_D7, GPIO_LOW);
    }

    /*write bit 6*/
    if ((uMSB8Byte & 0x40)) {
        digitalPinWrite(LCD_D6, GPIO_HIGH);
    } else {
        digitalPinWrite(LCD_D6, GPIO_LOW);
    }
    /*write bit 5*/
    if ((uMSB8Byte & 0x20)) {
        digitalPinWrite(LCD_D5, GPIO_HIGH);
    } else {
        digitalPinWrite(LCD_D5, GPIO_LOW);
    }

    /*write bit 4*/
    if ((uMSB8Byte & 0x10)) {
        digitalPinWrite(LCD_D4, GPIO_HIGH);
    } else {
        digitalPinWrite(LCD_D4, GPIO_LOW);
    }

    digitalPinWrite(LCD_EN, GPIO_HIGH);
    _delay_us(10);
    digitalPinWrite(LCD_EN, GPIO_LOW);
}

void lcdWriteByte(uint8_t u8Byte) {
    LcdWriteHigh(u8Byte);
    LcdWriteHigh(u8Byte << 4);
}

#if (LCD_LINE_MODE == LCD_INTERAVTIVE)
/*Read Operation*/

uint8_t lcdReadNibble();
static inline uint8_t lcdReadByte();
uint8_t lcdRead();

uint8_t lcdReadNibble() {
    uint8_t u8Byte;

    digitalPinWrite(LCD_EN, GPIO_HIGH);

    u8Byte = 0;
    if (digitalPinRead(LCD_D7)) {
        u8Byte |= 0x80;
    }
    if (digitalPinRead(LCD_D6)) {
        u8Byte |= 0x40;
    }
    if (digitalPinRead(LCD_D5)) {
        u8Byte |= 0x20;
    }
    if (digitalPinRead(LCD_D4)) {
        u8Byte |= 0x10;
    }

    digitalPinWrite(LCD_EN, GPIO_LOW);
    return (u8Byte);

}

uint8_t lcdRead() {

    uint8_t u8Readbit;
    digitalpinMode(LCD_D4, MODE_INPUT);
    digitalpinMode(LCD_D5, MODE_INPUT);
    digitalpinMode(LCD_D6, MODE_INPUT);
    digitalpinMode(LCD_D7, MODE_INPUT);
    digitalPinWrite(LCD_RW, GPIO_HIGH);
    u8Readbit = lcdReadByte();
    digitalPinWrite(LCD_RS, GPIO_HIGH);
    digitalpinMode(LCD_D4, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D5, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D6, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D7, MODE_OUTPUT_LOW);
    digitalPinWrite(LCD_RW, GPIO_LOW);

    return (u8Readbit);
}

static inline uint8_t lcdReadByte() {
    uint8_t u8Read;

    u8Read = lcdReadNibble();
    u8Read |= ((lcdReadNibble()) >> 4);
    return (u8Read);

}

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

    digitalpinMode(LCD_RS, MODE_OUTPUT_HIGH);
    digitalpinMode(LCD_EN, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_RW, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D4, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D5, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D6, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D7, MODE_OUTPUT_LOW);
    gu8LCDFlags = 0;
    gu8LcdOPtion = LCD_DISPLAY_ON_COMMAND; /*the display on*/
    gu8LCDPosition = 0x00; /*no position set*/
    gu8LcdBufferIndex = 0;
    for (int i = 0; i < LCD_NUMBER_OF_LINES; i++) {
        for (int j = 0; j < LCD_NUMBER_OF_BYTE; j++) {
            gu8LCDBuffer[i][j] = ' ';
        }
    }
    lcdInit();
    lcdwriteCMD(LCD_CGRRAM_MODE | LCD_CGRAM_ADDRESS_CHECK);
    lcdWriteByte(0xA5);
    lcdwriteCMD(LCD_DDRAM_MODE);
    DDRD |= (1 << PD4);

}

uint8_t lcdUpdate() {
    if (!(lcdRead() & 0x80)) {
        lcdwriteCMD(LCD_CGRRAM_MODE | LCD_CGRAM_ADDRESS_CHECK);
        if (lcdRead() != (0xA5)) {
            gu8LcdBufferIndex = 0;
            lcdInit();
        } else {
            PORTD |= (1 << PD4);
            while ((gu8LcdBufferIndex / LCD_NUMBER_OF_BYTE) != LCD_NUMBER_OF_LINES) {
                /*write a bytes*/
                if (gu8LcdBufferIndex % LCD_NUMBER_OF_BYTE == 0) {
                    lcdwriteCMD(lcdPosToAddress((gu8LcdBufferIndex / LCD_NUMBER_OF_BYTE), 0));
                }
                PORTD ^= (1 << PD4);
                lcdWriteByte(gu8LCDBuffer[(gu8LcdBufferIndex / LCD_NUMBER_OF_BYTE)][(gu8LcdBufferIndex % LCD_NUMBER_OF_BYTE)]);
                gu8LcdBufferIndex++;
            }
            PORTD &= ~(1 << PD4);
            gu8LcdBufferIndex = 0;
            /*write pos*/
            lcdwriteCMD(gu8LCDPosition);
            /*set option*/
            lcdwriteCMD(LCD_DISPLAY_ON_COMMAND | gu8LcdOPtion);
            return (LCD_OK);
        }
    }
    return (LCD_RUNNING);
}



#elif (LCD_LINE_MODE == LCD_NONINTERACTIVE)

void lcdHwInit() {
    /*4 bit mode*/
    if ((LCD_RS == NOT_A_PIN) ||
            (LCD_EN == NOT_A_PIN) ||
            (LCD_D4 == NOT_A_PIN) ||
            (LCD_D5 == NOT_A_PIN) ||
            (LCD_D6 == NOT_A_PIN) ||
            (LCD_D7 == NOT_A_PIN))
        return;

    digitalpinMode(LCD_RS, MODE_OUTPUT_HIGH);
    digitalpinMode(LCD_EN, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D4, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D5, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D6, MODE_OUTPUT_LOW);
    digitalpinMode(LCD_D7, MODE_OUTPUT_LOW);
    gu8LCDFlags = 0;
    gu8LcdOPtion = LCD_DISPLAY_ON_COMMAND; /*the display on*/
    gu8LCDPosition = 0x00; /*no position set*/
    genLCDInitState = LCD_INIT_IDLE;
    genLCDUpdateState = LCD_UPDATE_IDLE;
    gu8LcdBufferIndex = 0;
    for (int i = 0; i < LCD_NUMBER_OF_LINES; i++) {
        for (int j = 0; j < LCD_NUMBER_OF_BYTE; i++) {
            gu8LCDBuffer[i][j] = ' ';
        }
    }
    DDRD |= (1 << PD4);
}

uint8_t lcdUpdate() {

    while ((gu8LcdBufferIndex / LCD_NUMBER_OF_BYTE) != LCD_NUMBER_OF_LINES) {
        /*write a bytes*/
        if (gu8LcdBufferIndex % LCD_NUMBER_OF_BYTE == 0) {
            lcdwriteCMD(lcdPosToAddress((gu8LcdBufferIndex / LCD_NUMBER_OF_BYTE), 0));
        }

        lcdWriteByte(gu8LCDBuffer[(gu8LcdBufferIndex / LCD_NUMBER_OF_BYTE)][(gu8LcdBufferIndex % LCD_NUMBER_OF_BYTE)]);
        gu8LcdBufferIndex++;
    }
    gu8LcdBufferIndex = 0;
    /*write pos*/
    lcdwriteCMD(gu8LCDPosition);
    /*set option*/
    lcdwriteCMD(LCD_DISPLAY_ON_COMMAND | gu8LcdOPtion);
    return (LCD_OK);
    return (LCD_RUNNING);
}








#endif

uint8_t lcdInit() {
    digitalPinWrite(LCD_RS, GPIO_LOW);
    _delay_ms(LCD_TIMING_POWER_ON);
    LcdWriteHigh(LCD_8BIT_COMMAND);
    _delay_ms(LCD_TIMING_8BIT_LONG); //
    LcdWriteHigh(LCD_8BIT_COMMAND);
    /*4bit mode setting*/
    _delay_us(100);
    LcdWriteHigh(LCD_8BIT_COMMAND);
    LcdWriteHigh(LCD_4BIT_COMMAND); /*0x2*  */
    lcdWriteByte(LCD_2LINE_COMMAND);
    lcdWriteByte(LCD_DISPLAY_ON_COMMAND);
    lcdWriteByte(LCD_CLEAR_COMMAND);
    _delay_ms(LCD_TIMING_CLEAR_COMMAND);
    lcdWriteByte(LCD_ENTRY_SET);
    digitalPinWrite(LCD_RS, GPIO_HIGH); /*default state of a write data */
    return (1);
}


#endif

void lcdwriteCMD(uint8_t u8Cmd) {
    digitalPinWrite(LCD_RS, GPIO_LOW); /*write a command*/
    lcdWriteByte(u8Cmd);
    digitalPinWrite(LCD_RS, GPIO_HIGH); /*write a Data*/
}

void lcdCreateChar(uint8_t u8location, const uint8_t *pu8Data) {
    u8location &= 0x07;
    u8location *= 8;

    digitalPinWrite(LCD_RS, GPIO_LOW);
    /*set cgram address*/
    lcdWriteByte(LCD_CGRRAM_MODE + u8location);
    digitalPinWrite(LCD_RS, GPIO_HIGH);
    for (int i = 0; i < 8; i++) {
        lcdWriteByte(pu8Data[i]);
    }
    digitalPinWrite(LCD_RS, GPIO_LOW);
    lcdWriteByte(LCD_DDRAM_MODE);
    digitalPinWrite(LCD_RS, GPIO_HIGH);
}

void lcdClearlines(uint8_t from) {
    for (uint8_t i = from; i < LCD_NUMBER_OF_LINES; i++) {
        for (uint8_t j = 0; j < LCD_NUMBER_OF_BYTE; j++) {
            gu8LCDBuffer[i][j] = ' ';
        }
    }
}

void lcdClearPos(uint8_t line, uint8_t pos) {

    uint8_t i;
    i = pos;
    while (i < LCD_NUMBER_OF_BYTE) {
        gu8LCDBuffer[line][i] = ' ';
        i++;
    }
}

void lcdClear() {
    for (uint8_t i = 0; i < LCD_NUMBER_OF_LINES; i++) {
        for (uint8_t j = 0; j < LCD_NUMBER_OF_BYTE; j++) {
            gu8LCDBuffer[i][j] = ' ';
        }
    }
}

void lcdPrint(uint8_t line, uint8_t alignment, const char *s) {
    uint8_t u8length, u8Start, u8End, u8Index;
    u8length = strlen(s);

    if (alignment == LCD_TEXT_LEFT) {
        for (int i = 0; i < u8length; i++) {
            gu8LCDBuffer[line][i] = s[i];
        }

    } else if (alignment == LCD_TXET_CENTER) {
        u8Index = 0;
        u8Start = (((LCD_NUMBER_OF_BYTE - u8length) / 2)+ (1 / 2));
        u8End = u8Start + u8length;

        for (uint8_t i = u8Start; i < u8End; i++) {
            gu8LCDBuffer[line][i] = s[u8Index];
            u8Index++;
        }
    }
}

void lcdwrite(uint8_t line, uint8_t pos, const char *string) {
    uint8_t j = 0;
    for (uint8_t i = pos; i < strlen(string) + pos; i++) {
        gu8LCDBuffer[line][i] = string[j];
        j++;
    }
}

void getlcdData(char *str, uint8_t line, uint8_t pos) {
    /*memory */
    uint8_t i, u8count;
    i = pos;
    u8count = 0;
    while (!(lcdIsCharEmpty(line, i))) {
        str[u8count++] = gu8LCDBuffer[line][i];
        i++;
        if (i == LCD_NUMBER_OF_BYTE) {
            break;
        }
    }
}

void lcdprintbuf(uint8_t *buf, uint8_t line, uint8_t length) {
    for (int i = 0; i < length; i++) {
        gu8LCDBuffer[line][i] = buf[i];
    }
}

void lcdReplace(uint8_t line, uint8_t startpos) {
    uint8_t i = startpos;
    while (!lcdIsCharEmpty(line, i)) {
        gu8LCDBuffer[line][i] = gu8LCDBuffer[line][i + 1];
        i++;
    }
    gu8LCDBuffer[line][i] = ' ';
}

uint8_t lcdIsCharEmpty(uint8_t line, uint8_t pos) {
    if (gu8LCDBuffer[line][pos] == ' ') {
        return (1);
    }
    return (0);

}

uint8_t lcdfindchar(uint8_t line, uint8_t pos, uint8_t s) {
    if (gu8LCDBuffer[line][pos] == s) {
        return (1);
    }
    return (0);
}

uint8_t lcdPosToAddress(uint8_t u8line, uint8_t u8pos) {
    uint8_t u8Address;
    u8pos &= 0x3F;
    u8line &= 0x03;
    if (u8line == 3) {
        u8Address = ((LCD_LINE1_START + (LCD_NUMBER_OF_BYTE)) + u8pos);
    } else if (u8line == 2) {
        u8Address = ((LCD_LINE0_START + (LCD_NUMBER_OF_BYTE)) + u8pos);
    } else if (u8line == 1) {
        u8Address = ((LCD_LINE1_START) + u8pos);
    } else {
        u8Address = ((LCD_LINE0_START) + u8pos);
    }
    return (u8Address);
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

void lcdwriteCGRAM(uint8_t line, uint8_t pos, uint8_t index) {
    gu8LCDBuffer[line][pos] = index;
}

uint8_t lcdIsCurrentNumber(uint8_t line, uint8_t pos) {
    if (gu8LCDBuffer[line][pos] >= '0' && gu8LCDBuffer[line][pos] <= '9')
        return (1);
    return (0);

}
#endif
