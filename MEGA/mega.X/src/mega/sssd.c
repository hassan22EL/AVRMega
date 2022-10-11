/*
 * File:   sssd.c
 * Author: hassa
 *
 * Created on June 29, 2022, 2:11 PM
 */


#include <stdint-gcc.h>

#include "../../inc/mega.h"
#if SSSD_MODULE 

uint8_t gu8CSPins[SSSD_MAX_DIVICES];
uint8_t gu8DigitLimit[SSSD_MAX_DIVICES];
static const uint8_t PROGMEM charTable[] = {
    0b01111110, /*0*/
    0b00110000, /*1*/
    0b01101101, /*2*/
    0b01111001, /*3*/
    0b00110011, /*4*/
    0b01011011, /*5*/
    0b01011111, /*6*/
    0b01110000, /*7*/
    0b01111111, /*8*/
    0b01111011, /*9*/
    0b01110111, /*A*/
    0b00011111, /*b*/
    0b01001110, /*c*/
    0b00111101, /*d*/
    0b01001111, /*E*/
    0b01000111, /*F*/
    0b01011110, /*G*/
    0b00010111, /*h*/
    0b00010000, /*i*/
    0b00111000, /*j*/
    0b00101111, /*k*/
    0b00001110, /*L*/
    0b01110110, /*M*/
    0b00010101, /*n*/
    0b00011101, /*O*/
    0b01100111, /*P*/
    0b01110011, /*q*/
    0b00000101, /*r*/
    0b00011011, /*S*/
    0b00001111, /*t*/
    0b00111110, /*U*/
    0b00011100, /*V*/
    0b00101011, /*w*/
    0b00110110, /*x*/
    0b00111011, /*y*/
    0b01001001, /*z*/
    0b00001000, /*_*/
    0b00000001
};
#define SSSD_TABLE_READ(P)     (pgm_read_byte(charTable + (P)))

/*
 *  @opCode :bits from D8 to D11
 *  @data   :bits from D0 to D7 
 *  @device : select display for communication
 */

void sssdShiftAll(uint8_t nDevice);
uint8_t parse(char s);
void sssdSpiWriteByte(uint8_t u8decive, uint8_t opCode, uint8_t u8Data);

void sssdSpiWriteByte(uint8_t u8decive, uint8_t opCode, uint8_t u8Data) {
    uint8_t u8buf[2];
    u8buf [0] = opCode;
    u8buf [1] = u8Data;
    while (spiReady() == 0); /*wait for ready*/
    spiStart(gu8CSPins[u8decive]);
    spiMasterTransmit(u8buf, 2);
    while (spiReady() == 0); /*wait */
    spiStop(gu8CSPins[u8decive]);
    return;
}

void sssdShiftAll(uint8_t nDevice) {
    for (uint8_t i = nDevice; i < SSSD_MAX_DIVICES; ++i) {
        sssdSpiWriteByte(i, SSSD_NOOP_ADDR, SSSD_OP_OFF);
    }
}

void sssdInit() {
    sei();
    for (uint8_t i = 0; i < SSSD_MAX_DIVICES; i++) {
        sssdSpiWriteByte(i, SSSD_DISPLAYTEST_ADDR, SSSD_OP_OFF);
        sssdSpiWriteByte(i, SSSD_SHUTDOWN_ADDR, SSSD_OP_OFF);
        sssdSpiWriteByte(i, SSSD_SCANLIMIT_ADDR, 7);
        sssdSpiWriteByte(i, SSSD_DECODEMODE_ADDR, 0x00);
        for (uint8_t j = 1; j < 9; ++j)
            sssdSpiWriteByte(i, j, SSSD_MAX72b);
        sssdSpiWriteByte(i, SSSD_BRIGHTNESS_ADDR, 0x00);
        if (SSSD_MAX_DIVICES > 1)
            sssdShiftAll(i);
    }

}

void sssdClearAll(uint8_t u8StartDigit, uint8_t u8EndDigit) {
    uint8_t u8StartDecive;
    uint8_t u8EndDecive;
    uint8_t u8EndIndex;
    uint8_t u8IndexDigit;
    u8StartDecive = u8StartDigit / 8;
    u8EndDecive = u8EndDigit / 8;
    u8IndexDigit = (u8StartDigit % 8) - 1;
    u8EndIndex = u8StartDigit;

    for (uint8_t i = u8StartDecive; i < (u8EndDecive + 1); i++) {
        while (u8IndexDigit < 8) {
#if SSSD_DIR ==SSSD_RIGHT
            sssdSpiWriteByte(i, 8 - u8IndexDigit, SSSD_MAX72b);
#elif SSSD_DIR == SSSD_LEFT
            sssdSpiWriteByte(i, (u8Digit + 1), SSSD_MAX72b);
#endif
            u8IndexDigit++;

            if (u8EndIndex >= u8EndDigit) {
                break;
            } else {
                u8EndIndex++;
            }
        }
        u8IndexDigit = 0;
    }
}

void sssdStart(uint8_t * u8Pins) {
    for (uint8_t i = 0; i < SSSD_MAX_DIVICES; i++) {
        spiStop(u8Pins[i]);
        gu8CSPins[i] = u8Pins[i];

    }

    for (uint8_t i = 0; i < SSSD_MAX_DIVICES; i++) {
        gu8DigitLimit[i] = 8;
    }

}

void sssdOn(uint8_t nDevice) {
    sssdSpiWriteByte(nDevice, SSSD_SHUTDOWN_ADDR, SSSD_OP_ON);
}

void sssdOff(uint8_t nDevice) {
    sssdSpiWriteByte(nDevice, SSSD_SHUTDOWN_ADDR, SSSD_OP_OFF);
}

void sssdSetDigit(uint8_t value, uint8_t nDevice, uint8_t digit, uint8_t dp) {

    if (digit > 8) {
        return;
    }

    if (dp > 0) {
        dp = SSSD_DP_FLAG;
    }

#if SSSD_DIR == SSSD_LEFT
    sssdSpiWriteByte(nDevice, digit, (value | dp));
#elif SSSD_DIR == SSSD_RIGHT
    digit = digit - 1;
    sssdSpiWriteByte(nDevice, 8 - digit, (value | dp));
#endif
}

void sssdPrintAll(long number, uint8_t u8startDigit, uint8_t u8EndDigit, uint8_t dpDigit) {
    long num;
    long temp;
    uint8_t startDevice;
    uint8_t EndDeive;
    uint8_t parsed;
    uint8_t startDigit;
    uint8_t u8IndexDigit;
    uint8_t u8EndIndex;
    uint8_t count;
    uint8_t j;

    num = labs(number);
    parsed = 0B01111110; /*zero digit*/
    startDevice = ((u8startDigit - 1) / 8);
    EndDeive = ((u8EndDigit - 1) / 8);
    startDigit = ((u8startDigit - 1) % 8);
    u8IndexDigit = startDigit;
    u8EndIndex = u8startDigit;
    sssdShiftAll(0);

    count = 0;
    j = 0;
    while (num > 0) {
        num = num / 10;
        count++;
    }
    num = labs(number);

    if (count < dpDigit) {
        count++;
    }

#if (SSSD_DIR == SSSD_RIGHT) 
    if (number == 0) {
        sssdSpiWriteByte(startDevice, 8 - (startDigit), parsed);
    } else {
        u8IndexDigit = startDigit;
        u8EndIndex = u8startDigit;
        for (uint8_t i = startDevice; i < (EndDeive + 1); i++) {
            while (u8IndexDigit < 8 && j < count) {
                temp = (num / 10);
                parsed = SSSD_TABLE_READ(num - 10 * temp);
                num = temp;

                if (dpDigit > 0) {
                    if (dpDigit < count) {
                        if (((u8IndexDigit - startDigit) == dpDigit)) {
                            parsed |= SSSD_DP_FLAG;
                        }
                    } else {
                        if (j + 1 == dpDigit) {
                            parsed |= SSSD_DP_FLAG;
                        }
                    }
                }
                sssdSpiWriteByte(i, 8 - (u8IndexDigit), parsed);
                u8IndexDigit++;
                if (u8EndIndex > u8EndDigit - 1) {
                    break;
                } else {
                    u8EndIndex++;
                }
                j++;
            }

            u8IndexDigit = 0;
        }


#if (SSSD_PRINT_NEG_ALOW == SSSD_NEG_ALLOW)
        if ((number < 0) && (u8IndexDigit <= 8)) {
            sssdSpiWriteByte(u8EndIndex / 8, 8 - ((u8EndIndex) % 8), SSSD_MAX72d);
        }
#endif 

    }
#elif SSSD_DIR == SSSD_LEFT
#endif

}

void sssdPrintDigit(long number, uint8_t nDevice, uint8_t startDigit, uint8_t dpdigit) {
    long num;
    long temp;
    uint8_t digit;
    uint8_t parsed;
    num = labs(number);
    parsed = 0B01111110; /*zero digit*/
    sssdShiftAll(0);
#if (SSSD_DIR == SSSD_RIGHT) 
    digit = startDigit - 1;
    if (number == 0) {
        sssdSpiWriteByte(nDevice, 8 - digit, parsed);
    } else {
        for (; num > 0; digit++) {
            temp = (num / 10);
            parsed = SSSD_TABLE_READ(num - 10 * temp);
            num = temp;
            if (dpdigit > 0) {
                if (((digit + 1 - startDigit) == dpdigit))
                    parsed |= SSSD_DP_FLAG;
            }
            sssdSpiWriteByte(nDevice, 8 - digit, parsed);
            if (digit > 8)
                break;
        }
#if (SSSD_PRINT_NEG_ALOW == SSSD_NEG_ALLOW)
        if ((number < 0) && (digit <= 8)) {
            sssdSpiWriteByte(nDevice, 8 - digit, SSSD_MAX72d);
        }
#endif

    }


#elif SSSD_DIR == SSSD_LEFT
    digit = startDigit;
    temp = 1;
    if (number == 0) {
        sssdSpiWriteByte(nDevice, digit, parsed);
    } else {
#if (SSSD_PRINT_NEG_ALOW == SSSD_NEG_ALLOW)
        if ((number < 0) && (digit <= 8)) {
            sssdSpiWriteByte(nDevice, 1, SSSD_MAX72d);
            digit = startDigit + 1;
        }
#endif

        while (num >= 10) {
            num /= 10;
            temp *= 10;
        }
        num = labs(number);
        for (; temp > 0; digit++) {
            parsed = SSSD_TABLE_READ(num / temp);
            num = num % temp;
            temp /= 10;
            if (((digit + 1 - startDigit) == dpdigit))
                parsed |= SSSD_DP_FLAG;
            sssdSpiWriteByte(nDevice, digit, parsed);
            if (digit > 8)
                break;
        }

    }


#endif

}

void sssdClear(uint8_t nDevice) {
    for (uint8_t i = 1; i <= gu8DigitLimit[nDevice]; i++) {
        sssdSpiWriteByte(nDevice, i, SSSD_MAX72b);
    }
}

void sssdClearEnd(uint8_t nDevice, uint8_t u8Start, uint8_t u8End) {
    for (uint8_t i = u8Start; i <= u8End; i++) {
        sssdSpiWriteByte(nDevice, i, SSSD_MAX72b);
    }
}

void sssdSetDigitLimit(uint8_t limit, uint8_t nDevice) {
    if ((limit == 0) || (limit > 8))
        return;
    for (uint8_t i = 0; i < SSSD_MAX_DIVICES; ++i)
        if ((nDevice >= SSSD_MAX_DIVICES) || (i == nDevice)) {
            gu8DigitLimit[i] = limit;
            sssdSpiWriteByte(i, SSSD_SCANLIMIT_ADDR, limit - 1);
        }
}

void sssdSetBright(uint8_t brightness, uint8_t nDevice) {
    if (brightness > 15)
        return;
    sssdSpiWriteByte(nDevice, SSSD_BRIGHTNESS_ADDR, brightness);
}

void sssdPrintString(const char *s, uint8_t u8startDigit, uint8_t u8EndDigit, uint8_t dpDigit) {
    uint8_t startDevice;
    uint8_t EndDeive;
    uint8_t parsed;
    uint8_t startDigit;
    uint8_t u8IndexDigit;
    uint8_t u8EndIndex;
    uint8_t num;
    uint8_t count;

    num = strlen(s);
    parsed = 0B01111110; /*zero digit*/
    startDevice = ((u8startDigit - 1) / 8);
    EndDeive = ((u8EndDigit - 1) / 8);
    startDigit = ((u8startDigit - 1) % 8);
    u8IndexDigit = startDigit;
    u8EndIndex = u8startDigit;

    for (uint8_t i = startDevice; i < (EndDeive + 1); i++) {
        while (u8IndexDigit < 8 && num > 0) {
            count++;
            parsed = parse(s[num - 1]);
            if (dpDigit > 0) {

                if ((u8IndexDigit - startDigit) == dpDigit) {
                    parsed |= SSSD_DP_FLAG;
                }
            }
            sssdSpiWriteByte(i, 8 - (u8IndexDigit), parsed);
            if (num != 0) {
                num--;
            }
            u8IndexDigit++;
            if (u8EndIndex > u8EndDigit - 1) {
                break;
            } else {
                u8EndIndex++;
            }
        }
        u8IndexDigit = 0;
    }

    return;
}

uint8_t parse(char s) {
    if (s == '0')
        return SSSD_TABLE_READ(0); /*0*/
    ;
    if (s == '1')
        return SSSD_TABLE_READ(1); /*1*/
    ;
    if (s == '2')
        return SSSD_TABLE_READ(2); /*0*/

    if (s == '3')
        return SSSD_TABLE_READ(3); /*0*/

    if (s == '4')
        return SSSD_TABLE_READ(4); /*0*/

    if (s == '5')
        return SSSD_TABLE_READ(5); /*0*/

    if (s == '6')
        return SSSD_TABLE_READ(6); /*0*/

    if (s == '7')
        return SSSD_TABLE_READ(6); /*0*/

    if (s == '8')
        return SSSD_TABLE_READ(6); /*0*/

    if (s == '9')
        return SSSD_TABLE_READ(9); /*0*/

    if (s == 'A')
        return SSSD_TABLE_READ(10); /*0*/

    if (s == 'B')
        return SSSD_TABLE_READ(11); /*0*/

    if (s == 'C')
        return SSSD_TABLE_READ(12); /*0*/

    if (s == 'D')
        return SSSD_TABLE_READ(13); /*0*/

    if (s == 'E')
        return SSSD_TABLE_READ(14); /*0*/

    if (s == 'F')
        return SSSD_TABLE_READ(15); /*0*/

    if (s == 'G')
        return SSSD_TABLE_READ(16); /*0*/

    if (s == 'H')
        return SSSD_TABLE_READ(17); /*0*/

    if (s == 'I')
        return SSSD_TABLE_READ(18); /*0*/

    if (s == 'J')
        return SSSD_TABLE_READ(19); /*0*/

    if (s == 'K')
        return SSSD_TABLE_READ(20); /*0*/

    if (s == 'L')
        return SSSD_TABLE_READ(21); /*0*/

    if (s == 'M')
        return SSSD_TABLE_READ(22); /*0*/

    if (s == 'N')
        return SSSD_TABLE_READ(23); /*0*/

    if (s == 'O')
        return SSSD_TABLE_READ(24); /*0*/

    if (s == 'P')
        return SSSD_TABLE_READ(25); /*0*/

    if (s == 'Q')
        return SSSD_TABLE_READ(26); /*0*/

    if (s == 'R')
        return SSSD_TABLE_READ(27); /*0*/

    if (s == 'S')
        return SSSD_TABLE_READ(28); /*0*/

    if (s == 'T')
        return SSSD_TABLE_READ(29); /*0*/

    if (s == 'V')
        return SSSD_TABLE_READ(30); /*0*/

    if (s == 'U')
        return SSSD_TABLE_READ(31); /*0*/

    if (s == 'W')
        return SSSD_TABLE_READ(32); /*0*/

    if (s == 'X')
        return SSSD_TABLE_READ(33); /*0*/

    if (s == 'Y')
        return SSSD_TABLE_READ(34); /*0*/

    if (s == 'Z')
        return SSSD_TABLE_READ(35); /*0*/

    if (s == '_')
        return SSSD_TABLE_READ(36);
    if (s == '-')
        return SSSD_TABLE_READ(37);

    return SSSD_TABLE_READ(0);
}

#endif


