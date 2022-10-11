/*
 * File:   hx711.c
 * Author: hassa
 *
 * Created on July 3, 2022, 8:51 AM
 */



#include <stdint-gcc.h>

#include "../../inc/mega.h"
#if HX711_MODULE


volatile uint8_t gu8Hx711Flags;
volatile long gu8hx711ReadX;
volatile long gu8hx711ReadAVG;
volatile uint8_t gu8hx711Index;
#define     HX711_DELAY_FLAG           (7)
#define     HX711_READ_FLAG            (6)
#define     HX711_SYNC_FLAG            (5)
#define     HX711_READ_DONE            (4)
#define     HX711_FIRST_READ           (3)
#define     HX711_SLEEP_MODE           (2)
#define     Hx711_READ_MASK            (0x03)
stTimer_t gsThx711Timeout;

uint8_t hx711Read(); /* waits for the chip to be ready and returns a reading*/

void hx711Init() {
    if (HX711_PD_SCK == NOT_A_PIN || HX711_DOUT == NOT_A_PIN)
        return;
    digitalpinMode(HX711_DOUT, MODE_INPUT_PULLUP);
    digitalpinMode(HX711_PD_SCK, MODE_OUTPUT_LOW);
    /*set gain*/
    gu8Hx711Flags = 0;
    gu8hx711ReadX = 0;
    gu8hx711Index = 0;
    gu8hx711ReadAVG = 0;
}

uint8_t hx711IsReady() {
    return ((digitalPinRead(HX711_DOUT)) == GPIO_LOW);
}

uint8_t hx711ReadDone() {
    if (bitIsSet(gu8Hx711Flags, HX711_READ_FLAG)) {
        return (1);
    }
    return (0);
}

/* waits for the chip to be ready and returns a reading peridic task */
uint8_t hx711Read() {
    uint32_t value;
    uint8_t data[3];
    uint8_t lastByte; /*last byte*/
    value = 0;
    lastByte = 0x00;
    if (hx711IsReady()) {

        for (uint8_t i = 0; i < 3; i++) {
            data[i] = 0;
        }
        /*read 24 bit value 3byte * 8 = 24 bit*/
        data[2] = uShiftin(HX711_DOUT, HX711_PD_SCK, UMSB);
        data[1] = uShiftin(HX711_DOUT, HX711_PD_SCK, UMSB);
        data[0] = uShiftin(HX711_DOUT, HX711_PD_SCK, UMSB);
        /*set gain for the next reading clock pin*/
        for (uint8_t i = 0; i < HX711_GAIN; i++) {
            digitalPinWrite(HX711_PD_SCK, GPIO_HIGH);
            _delay_us(1);
            digitalPinWrite(HX711_PD_SCK, GPIO_LOW);

        }

        if (data[2] & 0x80) {
            lastByte = 0xFF; /*set last byte as ff if data is neg*/
            /*negative value*/
        } else {
            lastByte = 0x00; /*set is postive*/
        }
        /*convert data to unsigned long */
        value = (uint32_t) lastByte << 24 |
                (uint32_t) data[2] << 16 |
                (uint32_t) data[1] << 8 |
                (uint32_t) data[0];
        gu8hx711ReadX = value;
        return (1);
    }
    return (0);
}
long gu8hx711ReadY = 0;
long gu8hx711ReadY_1 = 0;

long hx711ReadADC() {
    /*filliter of the */
    return (gu8hx711ReadX);
}

void hx711Powerdown() {
    /*Power down control (pin clock as high active)*/
    digitalPinWrite(HX711_PD_SCK, GPIO_LOW);
    digitalPinWrite(HX711_PD_SCK, GPIO_HIGH);
}

void hx711Powerup() {
    /*Power down control pin as active low*/
    digitalPinWrite(HX711_PD_SCK, GPIO_LOW);
}


void LPF(double *x, double *y, uint8_t M) {
    uint8_t n;

    y[0] = x[0];
    double conf = 1UL / (pow(2.0, 6.0));
    printf("con =%f\n", conf);
    for (n = 1; n < M; n++) {
        y[n] = y[n - 1] +((conf) *(x[n] + x[n - 1] - 2UL * y[n - 1]));
    }
}

void hx711Driver() {
    switch (gu8Hx711Flags & Hx711_READ_MASK) {
        case 0:
            hx711Powerup();
            sysSetPeriodMS(&gsThx711Timeout, HX711_POWER_UP_DELAY);
            sysSetTimer(&gsThx711Timeout, getSystemTick());
            bitsValue(gu8Hx711Flags, 0x01, Hx711_READ_MASK);

            break;
        case 1:
            if (sysIsTimeout(&gsThx711Timeout)) {
                /*check the sleep in first */
                if (bitIsSet(gu8Hx711Flags, HX711_SLEEP_MODE)) {
                    hx711Powerdown();
                    sysSetPeriodMS(&gsThx711Timeout, HX711_POWER_UP_DELAY);
                    sysSetTimer(&gsThx711Timeout, getSystemTick());
                    bitsValue(gu8Hx711Flags, 0x03, Hx711_READ_MASK);
                    return;
                }

                if (bitIsSet(gu8Hx711Flags, HX711_SYNC_FLAG)) {
                    bitClear(gu8Hx711Flags, HX711_READ_FLAG);
                    bitsValue(gu8Hx711Flags, 0x02, Hx711_READ_MASK);
                    return;
                }
                if (bitIsSet(gu8Hx711Flags, HX711_READ_DONE)) {
                    bitClear(gu8Hx711Flags, HX711_READ_DONE);
                    if (gu8hx711Index < 8) {
                        gu8hx711ReadAVG += gu8hx711ReadX;

                        gu8hx711Index++;
                    } else {
                        /*means  of the value */
                        bitSet(gu8Hx711Flags, HX711_READ_FLAG);
                        gu8hx711ReadX = (gu8hx711ReadAVG / gu8hx711Index);
                        gu8hx711Index = 0;
                        gu8hx711ReadAVG = 0;


                    }
                }
            }
            break;
        case 2:/*read state*/
            if (hx711Read()) {
                sysSetPeriodMS(&gsThx711Timeout, 1); /*delay 1 ms*/
                sysSetTimer(&gsThx711Timeout, getSystemTick());
                bitSet(gu8Hx711Flags, HX711_READ_DONE);
                bitClear(gu8Hx711Flags, HX711_SYNC_FLAG);
                bitsValue(gu8Hx711Flags, 0x01, Hx711_READ_MASK);
            }
            break;
        case 3:/*sleep state*/
            if (sysIsTimeout(&gsThx711Timeout)) {
                if (bitIsClear(gu8Hx711Flags, HX711_SLEEP_MODE)) {
                    bitsValue(gu8Hx711Flags, 0x00, Hx711_READ_MASK);
                }
            }
            break;
        default:
            bitsValue(gu8Hx711Flags, 0x00, Hx711_READ_MASK);
            break;

    }
}

void hx711Sync() {
    if (bitIsClear(gu8Hx711Flags, HX711_SYNC_FLAG)) {
        bitSet(gu8Hx711Flags, HX711_SYNC_FLAG);
    }
}


#endif  