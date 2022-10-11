/*
 * File:   utility.c
 * Author: Hassan
 *
 * Created on May 27, 2022, 3:23 PM
 */



#include <stdint-gcc.h>

#include "../../inc/mega.h"

void appShfitBuffer(uint8_t *buf, uint8_t first, uint8_t max) {
    uint8_t temp[max];
    temp[0] = first;
    for (uint8_t i = 0; i < max - 1; i++)
        temp[i + 1] = buf[i];

    for (uint8_t i = 0; i < max; i++)
        buf[i] = temp[i];
}

char *reverse(char *str) {
    char *p1, *p2;

    if (!str || ! *str)
        return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}

//const char * convettNumberToString(uint8_t number, uint8_t s8base) {
//    char str[16];
//    uint8_t u8Digit;
//    uint8_t u8rem;
//    u8rem = 0;
//    uint8_t j;
//
//    for (uint8_t i = 0; i < 8; i++) {
//        str[i] = ' ';
//    }
//    u8Digit = getdigitofNUmber(number);
//    if (u8Digit > 16) {
//        return NULL;
//    }
//    if (number == 0) {
//        for (uint8_t i = 0; i < u8Digit; i++) {
//            str[i] = '0';
//            str[i++] = '\0';
//        }
//        return str;
//    }
//
//    j = 0;
//    while (number != 0) {
//        u8rem = number % s8base;
//        str[j++] = (u8rem > 9) ? ((u8rem - 10) + 'a') : (u8rem + '0');
//        number = number / s8base;
//    }
//    str[j] = '\0';
//    reverse(str);
//    return str;
//}

uint8_t getdigitofNUmber(uint8_t u8Number) {
    uint8_t u8Count;
    u8Count = 0;
    if (u8Number == 0) {
        u8Count = 1;
    }
    while (u8Number != 0) {
        u8Number = u8Number / 10;
        u8Count++;
    }
    return u8Count;
}

void uNumberToString(char *s, uint8_t number) {
    sprintf(s, "%d", number);
}

int uStringToNumber(char *s) {
    return atoi(s);
}

uint8_t uShiftin(uint8_t u8DataPin, uint8_t clockPin, uint8_t BitOrder) {
    uint8_t value;
    value = 0;
    for (uint8_t i = 0; i < 8; i++) {
        digitalPinWrite(clockPin, GPIO_HIGH);
        _delay_us(1);
        if (BitOrder == ULSB) {
            value |= digitalPinRead(u8DataPin) << i;
        } else if (BitOrder == UMSB) {
            value |= digitalPinRead(u8DataPin) << (7 - i);
        }
        digitalPinWrite(clockPin, GPIO_LOW);
        _delay_us(1);
    }
    return value;
}

void u8ToBCD(byte *data, byte length, byte Byte) {
    uint8_t i = 0;
    while (Byte > 0 && i < length) {
        data[i] = (Byte % 10);
        Byte = Byte / 10;
        i++;
    }
    for (uint8_t j = i; j < length; j++) data[j] = 0x00;
}

long map(long x, long in_min, long in_max, long out_min, long out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}



