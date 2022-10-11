/*
 * File:   gpio.c
 * Author: Hassan
 *
 * Created on July 29, 2022, 12:12 AM
 */



#include  "../../inc/mega.h"

/*
 * File:   gpio.c
 * Author: Hassan
 *
 * Created on July 29, 2022, 12:12 AM
 */

void internal_pinMode2(gpio_t pin, uint8_t mode) {
    if (mode == MODE_OUTPUT) {
        ATOMIC_BEGIN
        GPIO_DDR_REG(pin) |= GPIO_PIN_MASK(pin);
        ATOMIC_END
    } else {
        if (mode == MODE_INPUT_PULLUP) {
            ATOMIC_BEGIN
            GPIO_DDR_REG(pin) &= ~GPIO_PIN_MASK(pin);
            GPIO_PORT_REG(pin) |= GPIO_PIN_MASK(pin);
            ATOMIC_END
        } else {
            // input mode without pull-up
            ATOMIC_BEGIN
            GPIO_DDR_REG(pin) &= ~GPIO_PIN_MASK(pin);
            GPIO_PORT_REG(pin) &= ~GPIO_PIN_MASK(pin);
            ATOMIC_END
        }
    }
}

uint8_t internal_digitalRead2(gpio_t pin) {

    if ((GPIO_PIN_REG(pin) & GPIO_PIN_MASK(pin)) != 0)
        return GPIO_HIGH;
    else
        return GPIO_LOW;
}

void internal_digitalWrite2(gpio_t pin, uint8_t value) {
    if (value == 0) {
        ATOMIC_BEGIN
        GPIO_PORT_REG(pin) &= ~GPIO_PIN_MASK(pin);
        ATOMIC_END
    } else {
        ATOMIC_BEGIN
        GPIO_PORT_REG(pin) |= GPIO_PIN_MASK(pin);
        ATOMIC_END
    }
}