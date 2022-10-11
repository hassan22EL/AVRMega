/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S *TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  


#ifndef XC_GPIO_H
#define	XC_GPIO_H

#include "../mega.h"



#if GPIO2_PREFER_SPEED ==1
#define		GPIO2_USE_INLINE_FUNCTIONS	0
#else
#define		GPIO2_USE_INLINE_FUNCTIONS	1
#endif






#if GPIO2_IOREGS_ABOVEFF
#define	GPIO2_OPTIONAL_ATOMIC_BEGIN		ATOMIC_BEGIN
#define GPIO2_OPTIONAL_ATOMIC_END		ATOMIC_END
#else
#define	GPIO2_OPTIONAL_ATOMIC_BEGIN
#define	GPIO2_OPTIONAL_ATOMIC_END
#endif


typedef uint16_t gpio_t;
#define	GPIO_Create_PIN(port, pin)         ((uint16_t)port > 0xFF ) ? \
		(((uint16_t)port & 0x00FF) | ((1<<pin) << 8) | 0x0080 ) : \
		(((uint16_t)port & 0x00FF) | ((1<<pin) << 8))



#define     PORT_ADDR(Port)             (_SFR_ADDR(Port))
#define NOT_A_PIN     0
// Note: The invalid value can be any valid port register
// - as long as the bit mask in upper byte is 0, the
// operation on this register will have no effect.
#ifdef  PORTA
#ifdef PA0
#define GPIO_A0          GPIO_Create_PIN(PORT_ADDR(PORTA) , 0)
#else 
#define GPIO_A0          DP_INVALID
#endif
#ifdef PA1
#define GPIO_A1          GPIO_Create_PIN(PORT_ADDR(PORTA) , 1)
#else 
#define GPIO_A1          DP_INVALID
#endif
#ifdef PA2
#define  GPIO_A2          GPIO_Create_PIN(PORT_ADDR(PORTA) , 2)
#else 
#define GPIO_A2         DP_INVALID
#endif


#ifdef PA3
#define GPIO_A3 GPIO_Create_PIN(PORT_ADDR(PORTA), 3)
#else 
#define GPIO_A3         DP_INVALID
#endif

#ifdef PA4
#define GPIO_A4          GPIO_Create_PIN(PORT_ADDR(PORTA), 4)
#else 
#define GPIO_A4          DP_INVALID
#endif

#ifdef PA5
#define GPIO_A5 GPIO_Create_PIN(PORT_ADDR(PORTA), 5)
#else 
#define GPIO_A5          DP_INVALID
#endif
#ifdef PA6
#define GPIO_A6 GPIO_Create_PIN(PORT_ADDR(PORTA), 6)
#else 
#define GPIO_A6          DP_INVALID
#endif

#ifdef PA7
#define GPIO_A7 GPIO_Create_PIN(PORT_ADDR(PORTA), 7)
#else 
#define GPIO_A7          DP_INVALID
#endif
#endif
#ifdef  PORTB
#ifdef PB0
#define GPIO_B0          GPIO_Create_PIN(PORT_ADDR(PORTB) , 0)
#else 
#define GPIO_B0          NOT_A_PIN
#endif
#ifdef PB1
#define GPIO_B1          GPIO_Create_PIN(PORT_ADDR(PORTB) , 1)
#else 
#define GPIO_B1          NOT_A_PIN
#endif
#ifdef PB2
#define  GPIO_B2          GPIO_Create_PIN(PORT_ADDR(PORTB) , 2)
#else 
#define GPIO_B2         NOT_A_PIN
#endif
#ifdef PB3
#define  GPIO_B3 GPIO_Create_PIN(PORT_ADDR(PORTB), 3)
#else 
#define GPIO_B3         NOT_A_PIN
#endif
#ifdef PB4
#define GPIO_B4 GPIO_Create_PIN(PORT_ADDR(PORTB), 4)
#else 
#define GPIO_B4          NOT_A_PIN
#endif
#ifdef PB5
#define GPIO_B5 GPIO_Create_PIN(PORT_ADDR(PORTB), 5)
#else 
#define GPIO_B5          NOT_A_PIN
#endif
#ifdef PB6
#define GPIO_B6 GPIO_Create_PIN(PORT_ADDR(PORTB), 6)
#else 
#define GPIO_B6          NOT_A_PIN
#endif
#ifdef PB7
#define  GPIO_B7 GPIO_Create_PIN(PORT_ADDR(PORTB), 7)
#else 
#define GPIO_B7          NOT_A_PIN
#endif
#endif
#ifdef  PORTC
#ifdef PC0
#define GPIO_C0          GPIO_Create_PIN(PORT_ADDR(PORTC) , 0)
#else 
#define GPIO_C0          NOT_A_PIN
#endif
#ifdef PC1
#define GPIO_C1          GPIO_Create_PIN(PORT_ADDR(PORTC) , 1)
#else 
#define GPIO_C1          NOT_A_PIN
#endif
#ifdef PC2
#define  GPIO_C2          GPIO_Create_PIN(PORT_ADDR(PORTC) , 2)
#else 
#define GPIO_C2         NOT_A_PIN
#endif


#ifdef PC3
#define  GPIO_C3 GPIO_Create_PIN(PORT_ADDR(PORTC), 3)
#else 
#define GPIO_C3         NOT_A_PIN
#endif

#ifdef PC4
#define GPIO_C4 GPIO_Create_PIN(PORT_ADDR(PORTC), 4)
#else 
#define GPIO_C4          NOT_A_PIN
#endif

#ifdef PC5
#define GPIO_C5 GPIO_Create_PIN(PORT_ADDR(PORTC), 5)
#else 
#define GPIO_C5          NOT_A_PIN
#endif
#ifdef PC6
#define GPIO_C6 GPIO_Create_PIN(PORT_ADDR(PORTC), 6)
#else 
#define GPIO_C6          NOT_A_PIN
#endif

#ifdef PC7
#define  GPIO_C7 GPIO_Create_PIN(PORT_ADDR(PORTC), 7)
#else 
#define GPIO_C7          NOT_A_PIN
#endif
#endif
#ifdef  PORTD
#ifdef PD0
#define GPIO_D0          GPIO_Create_PIN(PORT_ADDR(PORTD) , 0)
#else 
#define GPIO_D0          NOT_A_PIN
#endif
#ifdef PD1
#define GPIO_D1          GPIO_Create_PIN(PORT_ADDR(PORTD) , 1)
#else 
#define GPIO_D1          NOT_A_PIN
#endif
#ifdef PD2
#define  GPIO_D2          GPIO_Create_PIN(PORT_ADDR(PORTD) , 2)
#else 
#define GPIO_D2         NOT_A_PIN
#endif


#ifdef PD3
#define  GPIO_D3 GPIO_Create_PIN(PORT_ADDR(PORTD), 3)
#else 
#define GPIO_D3         NOT_A_PIN
#endif

#ifdef PD4
#define GPIO_D4 GPIO_Create_PIN(PORT_ADDR(PORTD), 4)
#else 
#define GPIO_D4          NOT_A_PIN
#endif

#ifdef PD5
#define GPIO_D5      GPIO_Create_PIN(PORT_ADDR(PORTD), 5)
#else 
#define GPIO_D5          NOT_A_PIN
#endif
#ifdef PD6
#define GPIO_D6      GPIO_Create_PIN(PORT_ADDR(PORTD), 6)
#else 
#define GPIO_D6          NOT_A_PIN
#endif

#ifdef PD7
#define  GPIO_D7 GPIO_Create_PIN(PORT_ADDR(PORTD), 7)
#else 
#define GPIO_D7          NOT_A_PIN
#endif
#endif
#ifdef  PORTE
#ifdef PE0
#define GPIO_E0          GPIO_Create_PIN(PORT_ADDR(PORTE) , 0)
#else 
#define GPIO_E0          NOT_A_PIN
#endif
#ifdef PE1
#define GPIO_E1          GPIO_Create_PIN(PORT_ADDR(PORTE) , 1)
#else 
#define GPIO_E1          NOT_A_PIN
#endif
#ifdef PE2
#define  GPIO_E2          GPIO_Create_PIN(PORT_ADDR(PORTE) , 2)
#else 
#define GPIO_E2         NOT_A_PIN
#endif


#ifdef PE3
#define  GPIO_E3 GPIO_Create_PIN(PORT_ADDR(PORTE), 3)
#else 
#define GPIO_E3         NOT_A_PIN
#endif

#ifdef PE4
#define GPIO_E4 GPIO_Create_PIN(PORT_ADDR(PORTE), 4)
#else 
#define GPIO_E4          NOT_A_PIN
#endif

#ifdef PE5
#define GPIO_E5 GPIO_Create_PIN(PORT_ADDR(PORTE), 5)
#else 
#define GPIO_E5          NOT_A_PIN
#endif
#ifdef PE6
#define GPIO_E6 GPIO_Create_PIN(PORT_ADDR(PORTE), 6)
#else 
#define GPIO_E6          NOT_A_PIN
#endif

#ifdef PE7
#define  GPIO_E7 GPIO_Create_PIN(PORT_ADDR(PORTE), 7)
#else 
#define GPIO_E7          NOT_A_PIN
#endif
#endif
#ifdef  PORTF
#ifdef PF0
#define GPIO_F0          GPIO_Create_PIN(PORT_ADDR(PORTF) , 0)
#else 
#define GPIO_F0          NOT_A_PIN
#endif
#ifdef PF1
#define GPIO_F1          GPIO_Create_PIN(PORT_ADDR(PORTF) , 1)
#else 
#define GPIO_F1          NOT_A_PIN
#endif
#ifdef PF2
#define  GPIO_F2          GPIO_Create_PIN(PORT_ADDR(PORTF) , 2)
#else 
#define GPIO_F2         NOT_A_PIN
#endif


#ifdef PF3
#define  GPIO_F3 GPIO_Create_PIN(PORT_ADDR(PORTF), 3)
#else 
#define GPIO_F3         NOT_A_PIN
#endif

#ifdef PF4
#define GPIO_F4 GPIO_Create_PIN(PORT_ADDR(PORTF), 4)
#else 
#define GPIO_F4          NOT_A_PIN
#endif

#ifdef PF5
#define GPIO_F5 GPIO_Create_PIN(PORT_ADDR(PORTF), 5)
#else 
#define GPIO_F5          NOT_A_PIN
#endif
#ifdef PF6
#define GPIO_F6 GPIO_Create_PIN(PORT_ADDR(PORTF), 6)
#else 
#define GPIO_F6          NOT_A_PIN
#endif

#ifdef PF7
#define  GPIO_F7 GPIO_Create_PIN(PORT_ADDR(PORTF), 7)
#else 
#define GPIO_F7          NOT_A_PIN
#endif
#endif
#ifdef  PORTG
#ifdef PG0
#define GPIO_G0          GPIO_Create_PIN(PORT_ADDR(PORTG) , 0)
#else 
#define GPIO_G0          NOT_A_PIN
#endif
#ifdef PG1
#define GPIO_G1          GPIO_Create_PIN(PORT_ADDR(PORTG) , 1)
#else 
#define GPIO_G1          NOT_A_PIN
#endif
#ifdef PG2
#define  GPIO_G2          GPIO_Create_PIN(PORT_ADDR(PORTG) , 2)
#else 
#define GPIO_G2         NOT_A_PIN
#endif


#ifdef PG3
#define  GPIO_G3 GPIO_Create_PIN(PORT_ADDR(PORTG), 3)
#else 
#define GPIO_G3         NOT_A_PIN
#endif

#ifdef PG4
#define GPIO_G4 GPIO_Create_PIN(PORT_ADDR(PORTG), 4)
#else 
#define GPIO_G4          NOT_A_PIN
#endif

#ifdef PG5
#define GPIO_G5 GPIO_Create_PIN(PORT_ADDR(PORTG), 5)
#else 
#define GPIO_G5          NOT_A_PIN
#endif
#ifdef PG6
#define GPIO_G6 GPIO_Create_PIN(PORT_ADDR(PORTG), 6)
#else 
#define GPIO_G6          NOT_A_PIN
#endif

#ifdef PG7
#define  GPIO_G7 GPIO_Create_PIN(PORT_ADDR(PORTG), 7)
#else 
#define GPIO_G7          NOT_A_PIN
#endif
#endif
#ifdef  PORTH
#ifdef PH0
#define GPIO_H0          GPIO_Create_PIN(PORT_ADDR(PORTH) , 0)
#else 
#define GPIO_H0          NOT_A_PIN
#endif
#ifdef PH1
#define GPIO_H1          GPIO_Create_PIN(PORT_ADDR(PORTH) , 1)
#else 
#define GPIO_H1          NOT_A_PIN
#endif
#ifdef PH2
#define  GPIO_H2          GPIO_Create_PIN(PORT_ADDR(PORTH) , 2)
#else 
#define GPIO_H2         NOT_A_PIN
#endif


#ifdef PH3
#define  GPIO_H3 GPIO_Create_PIN(PORT_ADDR(PORTH), 3)
#else 
#define GPIO_H3         NOT_A_PIN
#endif

#ifdef PH4
#define GPIO_H4 GPIO_Create_PIN(PORT_ADDR(PORTH), 4)
#else 
#define GPIO_H4          NOT_A_PIN
#endif

#ifdef PH5
#define GPIO_H5 GPIO_Create_PIN(PORT_ADDR(PORTH), 5)
#else 
#define GPIO_H5          NOT_A_PIN
#endif
#ifdef PH6
#define GPIO_H6 GPIO_Create_PIN(PORT_ADDR(PORTH), 6)
#else 
#define GPIO_H6          NOT_A_PIN
#endif

#ifdef PH7
#define  GPIO_H7 GPIO_Create_PIN(PORT_ADDR(PORTH), 7)
#else 
#define GPIO_H7          NOT_A_PIN
#endif
#endif
#ifdef  PORTI
#ifdef PI0
#define GPIO_I0          GPIO_Create_PIN(PORT_ADDR(PORTI) , 0)
#else 
#define GPIO_I0          NOT_A_PIN
#endif
#ifdef PI1
#define GPIO_I1          GPIO_Create_PIN(PORT_ADDR(PORTI) , 1)
#else 
#define GPIO_I1          NOT_A_PIN
#endif
#ifdef PI2
#define  GPIO_I2          GPIO_Create_PIN(PORT_ADDR(PORTI) , 2)
#else 
#define GPIO_I2         NOT_A_PIN
#endif


#ifdef PI3
#define  GPIO_I3 GPIO_Create_PIN(PORT_ADDR(PORTI), 3)
#else 
#define GPIO_I3         NOT_A_PIN
#endif

#ifdef PI4
#define GPIO_I4 GPIO_Create_PIN(PORT_ADDR(PORTI), 4)
#else 
#define GPIO_I4          NOT_A_PIN
#endif

#ifdef PI5
#define GPIO_I5 GPIO_Create_PIN(PORT_ADDR(PORTI), 5)
#else 
#define GPIO_I5          NOT_A_PIN
#endif
#ifdef PI6
#define GPIO_I6 GPIO_Create_PIN(PORT_ADDR(PORTI), 6)
#else 
#define GPIO_I6          NOT_A_PIN
#endif

#ifdef PI7
#define  GPIO_I7 GPIO_Create_PIN(PORT_ADDR(PORTI), 7)
#else 
#define GPIO_I7          NOT_A_PIN
#endif
#endif
#ifdef  PORTJ
#ifdef PJ0
#define GPIO_J0          GPIO_Create_PIN(PORT_ADDR(PORTJ) , 0)
#else 
#define GPIO_J0          NOT_A_PIN
#endif
#ifdef PJ1
#define GPIO_J1          GPIO_Create_PIN(PORT_ADDR(PORTJ) , 1)
#else 
#define GPIO_J1          NOT_A_PIN
#endif
#ifdef PJ2
#define  GPIO_J2          GPIO_Create_PIN(PORT_ADDR(PORTJ) , 2)
#else 
#define GPIO_J2         NOT_A_PIN
#endif


#ifdef PJ3
#define  GPIO_J3 GPIO_Create_PIN(PORT_ADDR(PORTJ), 3)
#else 
#define GPIO_J3         NOT_A_PIN
#endif

#ifdef PJ4
#define GPIO_J4 GPIO_Create_PIN(PORT_ADDR(PORTJ), 4)
#else 
#define GPIO_J4          NOT_A_PIN
#endif

#ifdef PJ5
#define GPIO_J5 GPIO_Create_PIN(PORT_ADDR(PORTJ), 5)
#else 
#define GPIO_J5          NOT_A_PIN
#endif
#ifdef PJ6
#define GPIO_J6 GPIO_Create_PIN(PORT_ADDR(PORTJ), 6)
#else 
#define GPIO_J6          NOT_A_PIN
#endif

#ifdef PJ7
#define  GPIO_J7 GPIO_Create_PIN(PORT_ADDR(PORTJ), 7)
#else 
#define GPIO_I7          NOT_A_PIN
#endif
#endif
#ifdef  PORTK
#ifdef PK0
#define GPIO_K0          GPIO_Create_PIN(PORT_ADDR(PORTK) , 0)
#else 
#define GPIO_K0          NOT_A_PIN
#endif
#ifdef PK1
#define GPIO_K1          GPIO_Create_PIN(PORT_ADDR(PORTK) , 1)
#else 
#define GPIO_K1          NOT_A_PIN
#endif
#ifdef PK2
#define  GPIO_K2          GPIO_Create_PIN(PORT_ADDR(PORTK) , 2)
#else 
#define GPIO_K2         NOT_A_PIN
#endif


#ifdef PK3
#define  GPIO_K3 GPIO_Create_PIN(PORT_ADDR(PORTK), 3)
#else 
#define GPIO_K3         NOT_A_PIN
#endif

#ifdef PK4
#define GPIO_K4 GPIO_Create_PIN(PORT_ADDR(PORTK), 4)
#else 
#define GPIO_K4          NOT_A_PIN
#endif

#ifdef PK5
#define GPIO_K5 GPIO_Create_PIN(PORT_ADDR(PORTK), 5)
#else 
#define GPIO_K5          NOT_A_PIN
#endif
#ifdef PK6
#define GPIO_K6 GPIO_Create_PIN(PORT_ADDR(PORTK), 6)
#else 
#define GPIO_K6          NOT_A_PIN
#endif

#ifdef PK7
#define  GPIO_K7 GPIO_Create_PIN(PORT_ADDR(PORTK), 7)
#else 
#define GPIO_I7          NOT_A_PIN
#endif
#endif
#ifdef  PORTL
#ifdef PL0
#define PORTL0          GPIO_Create_PIN(PORT_ADDR(PORTL) , 0)
#else 
#define PORTL0          NOT_A_PIN
#endif
#ifdef PL1
#define PORTL1          GPIO_Create_PIN(PORT_ADDR(PORTL) , 1)
#else 
#define PORTL1          NOT_A_PIN
#endif
#ifdef PL2
#define  PORTL2          GPIO_Create_PIN(PORT_ADDR(PORTL) , 2)
#else 
#define PORTL2         NOT_A_PIN
#endif


#ifdef PL3
#define  PORTL3 GPIO_Create_PIN(PORT_ADDR(PORTL), 3)
#else 
#define PORTL3         NOT_A_PIN
#endif

#ifdef PL4
#define PORTL4 GPIO_Create_PIN(PORT_ADDR(PORTL), 4)
#else 
#define PORTL4          NOT_A_PIN
#endif

#ifdef PL5
#define PORTL5 GPIO_Create_PIN(PORT_ADDR(PORTL), 5)
#else 
#define PORTL5          NOT_A_PIN
#endif
#ifdef PL6
#define PORTL6 GPIO_Create_PIN(PORT_ADDR(PORTL), 6)
#else 
#define PORTL6          NOT_A_PIN
#endif

#ifdef PL7
#define  PORTL7 GPIO_Create_PIN(PORT_ADDR(PORTL), 7)
#else 
#define GPIO_I7          NOT_A_PIN
#endif
#endif








#define		GPIO_PIN_MASK(pin)		 ((uint8_t)((uint16_t)pin >> 8))

#if  defined(__AVR_ATmega128A__) || defined (__AVR_ATmega128__)
#define		GET_PORT_REG_ADR(pin)	  ((((pin) & 0x0080) == 0) ? \
			(((pin) & 0x00FF)) : \
			((((pin) & 0x007F) | 0x0100)))
#else
#define		GET_PORT_REG_ADR(pin)	  ((((pin) & 0x0080) == 0) ? \
			((volatile uint8_t*)((pin) & 0x00FF)) : \
			((volatile uint8_t*)(((pin) & 0x007F) | 0x0100)))
#endif
#if  defined(__AVR_ATmega128A__) || defined (__AVR_ATmega128__)
#define		GET_PIN_REG_ADR(pin)        (volatile uint8_t*)(((GET_PORT_REG_ADR(pin)-2) != 0x0060)?(GET_PORT_REG_ADR(pin)-2) : 0x0020)
#else
#define		GET_PIN_REG_ADR(pin)		(GET_PORT_REG_ADR(pin)-2)
#endif
#define		GET_DDR_REG_ADR(pin)		(GET_PORT_REG_ADR(pin)-1)

#define   GPIO_PIN_REG(pin)    (*(volatile uint8_t*)GET_PIN_REG_ADR(pin) )
#define   GPIO_PORT_REG(pin)    (*(volatile uint8_t*)GET_PORT_REG_ADR(pin))
#define   GPIO_DDR_REG(pin)    (*(volatile uint8_t*)GET_DDR_REG_ADR(pin) )





static inline void digitalpinMode(gpio_t pin, uint8_t mode);
static inline uint8_t digitalPinRead(gpio_t pin);
static inline void digitalPinWrite(gpio_t pin, uint8_t value);



void internal_pinMode2(gpio_t pin, uint8_t mode); // implemented in gpio.c
uint8_t internal_digitalRead2(gpio_t pin); // implemented in gpio.c
void internal_digitalWrite2(gpio_t pin, uint8_t value); // implemented in gpio.c

typedef enum {
    MODE_INPUT,
    MODE_INPUT_PULLUP,
    MODE_OUTPUT,
} EN_Mode_t;

typedef enum {
    GPIO_LOW,
    GPIO_HIGH
} EN_GPIO_t;









static inline void digitalpinMode(gpio_t, uint8_t) __attribute__((always_inline, unused));

static inline void digitalpinMode(gpio_t pin, uint8_t mode) {
    if (__builtin_constant_p(pin) && __builtin_constant_p(mode)) {
        GPIO2_OPTIONAL_ATOMIC_BEGIN
        if (mode == MODE_OUTPUT) {
            GPIO_DDR_REG(pin) |= GPIO_PIN_MASK(pin);
        } else {
            if (mode == MODE_INPUT_PULLUP) {
                GPIO_DDR_REG(pin) &= ~GPIO_PIN_MASK(pin);
                GPIO_PORT_REG(pin) |= GPIO_PIN_MASK(pin);
            } else {
                // input mode without pull-up
                GPIO_DDR_REG(pin) &= ~GPIO_PIN_MASK(pin);
                GPIO_PORT_REG(pin) &= ~GPIO_PIN_MASK(pin);
            }
        }
        GPIO2_OPTIONAL_ATOMIC_END
    } else {
        // The pin or mode are not know at compile-time but the user wants
        // inline code (GPIO2_PREFER_SPEED = 1)
#if	GPIO2_USE_INLINE_FUNCTIONS
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

#else
        // Call non-inline 
        internal_pinMode2(pin, mode);
#endif

    }
}
static inline uint8_t digitalPinRead(gpio_t) __attribute__((always_inline, unused));

static inline uint8_t digitalPinRead(gpio_t pin) {

    if (__builtin_constant_p(pin)) {
        if ((GPIO_PIN_REG(pin) & GPIO_PIN_MASK(pin)) != 0)
            return GPIO_HIGH;
        else
            return GPIO_LOW;
    } else {

#if	GPIO2_USE_INLINE_FUNCTIONS
        if ((GPIO_PIN_REG(pin) & GPIO_PIN_MASK(pin)) != 0)
            return GPIO_HIGH;
        else
            return GPIO_LOW;

#else
        return internal_digitalRead2(pin);
#endif

    }
}


static inline void digitalPinWrite(gpio_t, uint8_t) __attribute__((always_inline, unused));

static inline void digitalPinWrite(gpio_t pin, uint8_t value) {
    // If we know the pin number and value at compile-time, the compiler
    // will compute everything during compilation and resulting code will
    // be single instruction - which does not need disabled interrupts	 
    if (__builtin_constant_p(pin) && __builtin_constant_p(value)) {
        GPIO2_OPTIONAL_ATOMIC_BEGIN
        if (value == 0)
            GPIO_PORT_REG(pin) &= ~GPIO_PIN_MASK(pin);
        else
            GPIO_PORT_REG(pin) |= GPIO_PIN_MASK(pin);
        GPIO2_OPTIONAL_ATOMIC_END
    } else {
        // If pin or value must be computed in runtime, resulting code
        // will always require disabled interrupts.
#if GPIO2_USE_INLINE_FUNCTIONS

        // NOTE: if you make change here, make it also in internal_digitalWrite2()!
        if (value == 0) {
            ATOMIC_BEGIN
            GPIO_PORT_REG(pin) &= ~GPIO_PIN_MASK(pin);
            ATOMIC_END
        } else {
            ATOMIC_BEGIN
            GPIO_PORT_REG(pin) |= GPIO_PIN_MASK(pin);
            ATOMIC_END
        }

#else
        internal_digitalWrite2(pin, value);
#endif
    }
}

#endif	/* XC_GPIO_V2_H */