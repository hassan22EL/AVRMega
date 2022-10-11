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

#define NOT_A_PORT 0
//#define NOT_A_PIN  0

typedef uint8_t gpio_t;

typedef enum {
    NOT_A_PIN, //Invalid Pin
    GPIO_A0, GPIO_A1, GPIO_A2, GPIO_A3, GPIO_A4, GPIO_A5, GPIO_A6, GPIO_A7, //PORTA Pins
    GPIO_B0, GPIO_B1, GPIO_B2, GPIO_B3, GPIO_B4, GPIO_B5, GPIO_B6, GPIO_B7, //PORTB Pins
    GPIO_C0, GPIO_C1, GPIO_C2, GPIO_C3, GPIO_C4, GPIO_C5, GPIO_C6, GPIO_C7, //PORTC Pins
    GPIO_D0, GPIO_D1, GPIO_D2, GPIO_D3, GPIO_D4, GPIO_D5, GPIO_D6, GPIO_D7, //PORTD Pins
    GPIO_E0, GPIO_E1, GPIO_E2, GPIO_E3, GPIO_E4, GPIO_E5, GPIO_E6, GPIO_E7, //PORTE Pins
    GPIO_F0, GPIO_F1, GPIO_F2, GPIO_F3, GPIO_F4, GPIO_F5, GPIO_F6, GPIO_F7, //PORTF Pins
    GPIO_G0, GPIO_G1, GPIO_G2, GPIO_G3, GPIO_G4, GPIO_G5, GPIO_G6, GPIO_G7, //PORTG Pins
    GPIO_H0, GPIO_H1, GPIO_H2, GPIO_H3, GPIO_H4, GPIO_H5, GPIO_H6, GPIO_H7, //PORTH Pins
    GPIO_I0, GPIO_I1, GPIO_I2, GPIO_I3, GPIO_I4, GPIO_I5, GPIO_I6, GPIO_I7, //PORTI Pins
    GPIO_J0, GPIO_J1, GPIO_J2, GPIO_J3, GPIO_J4, GPIO_J5, GPIO_J6, GPIO_J7, //PORTJ Pins
    GPIO_K0, GPIO_K1, GPIO_K2, GPIO_K3, GPIO_K4, GPIO_K5, GPIO_K6, GPIO_K7, //PORTK Pins
    GPIO_L0, GPIO_L1, GPIO_L2, GPIO_L3, GPIO_L4, GPIO_L5, GPIO_L6, GPIO_L7, //PORTL Pins
} EN_PIN_t;

#define     PORT_ADDR(Port)             (_SFR_ADDR(Port))

#if 1
#define PA_ID   1
#define PB_ID   2
#define PC_ID   3
#define PD_ID   4
#define PE_ID   5
#define PF_ID   6
#define PG_ID   7
#define PH_ID   8
#define PI_ID   9
#define PJ_ID   10
#define PK_ID   11
#define PL_ID   12

// PORTA
#ifdef  PINA
#define GPIO_A  PA_ID
#define PA_PIN  PORT_ADDR(PINA)
#define PA_DDR  PORT_ADDR(DDRA)
#define PA_PORT PORT_ADDR(PORTA)
#else 
#define GPIO_A  NOT_A_PORT
#define PA_PIN  NOT_A_PORT
#define PA_DDR  NOT_A_PORT
#define PA_PORT NOT_A_PORT
#endif
// PORTB
#ifdef  PINB
#define GPIO_B      PB_ID 
#define PB_PIN  PORT_ADDR(PINB)
#define PB_DDR  PORT_ADDR(DDRB)
#define PB_PORT PORT_ADDR(PORTB)
#else 
#define GPIO_B  NOT_A_PORT
#define PB_PIN  NOT_A_PORT
#define PB_DDR  NOT_A_PORT
#define PB_PORT NOT_A_PORT
#endif
//PORTC
#ifdef  PINC
#define GPIO_C   PC_ID
#define PC_PIN  PORT_ADDR(PINC)
#define PC_DDR  PORT_ADDR(DDRC)
#define PC_PORT PORT_ADDR(PORTC)
#else 
#define GPIO_C  NOT_A_PORT
#define PC_PIN  NOT_A_PORT
#define PC_DDR  NOT_A_PORT
#define PC_PORT NOT_A_PORT
#endif
//PORTD
#ifdef  PIND
#define GPIO_D   PD_ID
#define PD_PIN  PORT_ADDR(PIND)
#define PD_DDR  PORT_ADDR(DDRD)
#define PD_PORT PORT_ADDR(PORTD)
#else 
#define GPIO_D  NOT_A_PORT
#define PD_PIN  NOT_A_PORT
#define PD_DDR  NOT_A_PORT
#define PD_PORT NOT_A_PORT
#endif
//PORTE
#ifdef  PINE
#define GPIO_E  PE_ID
#define PE_PIN  PORT_ADDR(PINE)
#define PE_DDR  PORT_ADDR(DDRE)
#define PE_PORT PORT_ADDR(PORTE)
#else 
#define GPIO_E  NOT_A_PORT
#define PE_PIN  NOT_A_PORT
#define PE_DDR  NOT_A_PORT
#define PE_PORT NOT_A_PORT
#endif
//PORTF
#ifdef  PINF
#define GPIO_F  PF_ID
#define PF_PIN  PORT_ADDR(PINF)
#define PF_DDR  PORT_ADDR(DDRF)
#define PF_PORT PORT_ADDR(PORTF)
#else 
#define GPIO_F  NOT_A_PORT
#define PF_PIN  NOT_A_PORT
#define PF_DDR  NOT_A_PORT
#define PF_PORT NOT_A_PORT
#endif
//PORTG
#ifdef  PING
#define GPIO_G  7
#define PG_PIN  PORT_ADDR(PING)
#define PG_DDR  PORT_ADDR(DDRG)
#define PG_PORT PORT_ADDR(PORTG)
#else 
#define GPIO_G  NOT_A_PORT
#define PG_PIN  NOT_A_PORT
#define PG_DDR  NOT_A_PORT
#define PG_PORT NOT_A_PORT
#endif
//PORTH
#ifdef  PINH
#define GPIO_H  8
#define PH_PIN  PORT_ADDR(PINH)
#define PH_DDR  PORT_ADDR(DDRH)
#define PH_PORT PORT_ADDR(PORTH)
#else 
#define GPIO_H  NOT_A_PORT
#define PH_PIN  NOT_A_PORT
#define PH_DDR  NOT_A_PORT
#define PH_PORT NOT_A_PORT
#endif
//PORTI
#ifdef  PINI
#define GPIO_I  9
#define PI_PIN  PORT_ADDR(PINI)
#define PI_DDR  PORT_ADDR(DDRI)
#define PI_PORT PORT_ADDR(PORTI)
#else 
#define GPIO_I  NOT_A_PORT
#define PI_PIN  NOT_A_PORT
#define PI_DDR  NOT_A_PORT
#define PI_PORT NOT_A_PORT
#endif
//PORTJ
#ifdef  PINJ
#define GPIO_J  10
#define PJ_PIN  PORT_ADDR(PINJ)
#define PJ_DDR  PORT_ADDR(DDRJ)
#define PJ_PORT PORT_ADDR(PORTJ)
#else 
#define GPIO_J  NOT_A_PORT
#define PJ_PIN  NOT_A_PORT
#define PJ_DDR  NOT_A_PORT
#define PJ_PORT NOT_A_PORT
#endif
//PORTK
#ifdef  PINK
#define GPIO_K  11
#define PK_PIN  PORT_ADDR(PINK)
#define PK_DDR  PORT_ADDR(DDRK)
#define PK_PORT PORT_ADDR(PORTK)
#else 
#define GPIO_K  NOT_A_PORT
#define PK_PIN  NOT_A_PORT
#define PK_DDR  NOT_A_PORT
#define PK_PORT NOT_A_PORT
#endif
//PORTL
#ifdef  PINL
#define GPIO_L  12
#define PL_PIN  PORT_ADDR(PINL)
#define PL_DDR  PORT_ADDR(DDRL)
#define PL_PORT PORT_ADDR(PORTL)
#else 
#define GPIO_L  NOT_A_PORT
#define PL_PIN  NOT_A_PORT
#define PL_DDR  NOT_A_PORT
#define PL_PORT NOT_A_PORT
#endif
#endif
#if 1
#define     PA0_ID      1
//Pins OF PORTA
#ifdef  PINA0
#define     GPIO_A0    PA0_ID
#define     _PA_0      GPIO_A
#else
#define     GPIO_A0    NOT_A_PIN
#define     _PA_0      NOT_A_PIN
#endif
#ifdef  PINA1
#define     _PA_1   GPIO_A
#else 
#define     _PA_1   NOT_A_PIN
#endif
#ifdef  PINA2
#define     _PA_2   GPIO_A
#else      
#define     _PA_2   NOT_A_PIN
#endif
#ifdef  PINA3
#define     _PA_3   GPIO_A
#else      
#define     _PA_3   NOT_A_PIN
#endif
#ifdef  PINA4
#define     _PA_4   GPIO_A
#else 
#define     _PA_4   NOT_A_PIN
#endif
#ifdef  PINA5
#define     _PA_5   GPIO_A
#else 
#define     _PA_5   NOT_A_PIN
#endif
#ifdef  PINA6
#define    _PA_6    GPIO_A
#else
#define    _PA_6    NOT_A_PIN
#endif
#ifdef  PINA7
#define     _PA_7   GPIO_A
#else       
#define     _PA_7   NOT_A_PIN
#endif
//Pins OF PORTB
#ifdef  PINB0
#define     _PB_0   GPIO_B
#else
#define     _PB_0   NOT_A_PIN
#endif
#ifdef  PINB1
#define     _PB_1   GPIO_B
#else 
#define     _PB_1   NOT_A_PIN
#endif
#ifdef  PINB2
#define     _PB_2   GPIO_B
#else      
#define     _PB_2   NOT_A_PIN
#endif
#ifdef  PINB3
#define     _PB_3   GPIO_B
#else      
#define     _PB_3   NOT_A_PIN
#endif
#ifdef  PINB4
#define     _PB_4   GPIO_B
#else 
#define     _PB_4   NOT_A_PIN
#endif
#ifdef  PINB5
#define     _PB_5   GPIO_B
#else 
#define     _PB_5   NOT_A_PIN
#endif
#ifdef  PINB6
#define    _PB_6    GPIO_B
#else
#define    _PB_6    NOT_A_PIN
#endif
#ifdef  PINB7
#define     _PB_7   GPIO_B
#else       
#define     _PB_7   NOT_A_PIN
#endif
//Pins OF PORTC
#ifdef  PINC0
#define     _PC_0   GPIO_C
#else
#define     _PC_0   NOT_A_PIN
#endif
#ifdef  PINC1
#define     _PC_1   GPIO_C
#else 
#define     _PC_1   NOT_A_PIN
#endif
#ifdef  PINC2
#define     _PC_2   GPIO_C
#else      
#define     _PC_2   NOT_A_PIN
#endif
#ifdef  PINC3
#define     _PC_3   GPIO_C
#else      
#define     _PC_3   NOT_A_PIN
#endif
#ifdef  PINC4
#define     _PC_4   GPIO_C
#else 
#define     _PC_4   NOT_A_PIN
#endif
#ifdef  PINC5
#define     _PC_5   GPIO_C
#else 
#define     _PC_5   NOT_A_PIN
#endif
#ifdef  PINC6
#define    _PC_6    GPIO_C
#else
#define    _PC_6    NOT_A_PIN
#endif
#ifdef  PINC7
#define     _PC_7   GPIO_C
#else       
#define     _PC_7   NOT_A_PIN
#endif
//Pins OF PORTD
#ifdef  PIND0
#define     _PD_0   GPIO_D
#else
#define     _PD_0   NOT_A_PIN
#endif
#ifdef  PIND1
#define     _PD_1   GPIO_D
#else 
#define     _PD_1   NOT_A_PIN
#endif
#ifdef  PIND2
#define     _PD_2   GPIO_D
#else      
#define     _PD_2   NOT_A_PIN
#endif
#ifdef  PIND3
#define     _PD_3   GPIO_D
#else      
#define     _PD_3   NOT_A_PIN
#endif
#ifdef  PIND4
#define     _PD_4   GPIO_D
#else 
#define     _PD_4   NOT_A_PIN
#endif
#ifdef  PIND5
#define     _PD_5   GPIO_D
#else 
#define     _PD_5   NOT_A_PIN
#endif
#ifdef  PIND6
#define    _PD_6    GPIO_D
#else
#define    _PD_6    NOT_A_PIN
#endif
#ifdef  PIND7
#define     _PD_7   GPIO_D
#else       
#define     _PD_7   NOT_A_PIN
#endif
//Pins OF PORTE
#ifdef  PINE0
#define     _PE_0   GPIO_E
#else
#define     _PE_0   NOT_A_PIN
#endif
#ifdef  PINE1
#define     _PE_1   GPIO_E
#else 
#define     _PE_1   NOT_A_PIN
#endif
#ifdef  PINE2
#define     _PE_2   GPIO_E
#else      
#define     _PE_2   NOT_A_PIN
#endif
#ifdef  PINE3
#define     _PE_3   GPIO_E
#else      
#define     _PE_3   NOT_A_PIN
#endif
#ifdef  PINE4
#define     _PE_4   GPIO_E
#else 
#define     _PE_4   NOT_A_PIN
#endif
#ifdef  PINE5
#define     _PE_5   GPIO_E
#else 
#define     _PE_5   NOT_A_PIN
#endif
#ifdef  PINE6
#define    _PE_6    GPIO_E
#else
#define    _PE_6    NOT_A_PIN
#endif
#ifdef  PINE7
#define     _PE_7   GPIO_E
#else       
#define     _PE_7   NOT_A_PIN
#endif
//Pins OF PORTF
#ifdef  PINF0
#define     _PF_0   GPIO_F
#else
#define     _PF_0   NOT_A_PIN
#endif
#ifdef  PINF1
#define     _PF_1   GPIO_F
#else 
#define     _PF_1   NOT_A_PIN
#endif
#ifdef  PINF2
#define     _PF_2   GPIO_F
#else      
#define     _PF_2   NOT_A_PIN
#endif
#ifdef  PINF3
#define     _PF_3   GPIO_F
#else      
#define     _PF_3   NOT_A_PIN
#endif
#ifdef  PINF4
#define     _PF_4   GPIO_F
#else 
#define     _PF_4   NOT_A_PIN
#endif
#ifdef  PINF5
#define     _PF_5   GPIO_F
#else 
#define     _PF_5   NOT_A_PIN
#endif
#ifdef  PINF6
#define    _PF_6    GPIO_F
#else
#define    _PF_6    NOT_A_PIN
#endif
#ifdef  PINF7
#define     _PF_7   GPIO_F
#else       
#define     _PF_7   NOT_A_PIN
#endif
//Pins OF PORTG
#ifdef  PING0
#define     _PG_0   GPIO_G
#else
#define     _PG_0   NOT_A_PIN
#endif
#ifdef  PING1
#define     _PG_1   GPIO_G
#else 
#define     _PG_1   NOT_A_PIN
#endif
#ifdef  PING2
#define     _PG_2   GPIO_G
#else      
#define     _PG_2   NOT_A_PIN
#endif
#ifdef  PING3
#define     _PG_3   GPIO_G
#else      
#define     _PG_3   NOT_A_PIN
#endif
#ifdef  PING4
#define     _PG_4   GPIO_G
#else 
#define     _PG_4   NOT_A_PIN
#endif
#ifdef  PING5
#define     _PG_5   GPIO_G
#else 
#define     _PG_5   NOT_A_PIN
#endif
#ifdef  PING6
#define    _PG_6    GPIO_G
#else
#define    _PG_6    NOT_A_PIN
#endif
#ifdef  PING7
#define     _PG_7   GPIO_G
#else       
#define     _PG_7   NOT_A_PIN
#endif
//Pins OF PORTH
#ifdef  PINH0
#define     _PH_0   GPIO_H
#else
#define     _PH_0   NOT_A_PIN
#endif
#ifdef  PINH1
#define     _PH_1   GPIO_H
#else 
#define     _PH_1   NOT_A_PIN
#endif
#ifdef  PINH2
#define     _PH_2   GPIO_H
#else      
#define     _PH_2   NOT_A_PIN
#endif
#ifdef  PINH3
#define     _PH_3   GPIO_H
#else      
#define     _PH_3   NOT_A_PIN
#endif
#ifdef  PINH4
#define     _PH_4   GPIO_H
#else 
#define     _PH_4   NOT_A_PIN
#endif
#ifdef  PINH5
#define     _PH_5   GPIO_H
#else 
#define     _PH_5   NOT_A_PIN
#endif
#ifdef  PINH6
#define    _PH_6    GPIO_H
#else
#define    _PH_6    NOT_A_PIN
#endif
#ifdef  PINH7
#define     _PH_7   GPIO_H
#else       
#define     _PH_7   NOT_A_PIN
#endif
//Pins OF PORTI
#ifdef  PINI0
#define     _PI_0   GPIO_I
#else
#define     _PI_0   NOT_A_PIN
#endif
#ifdef  PINI1
#define     _PI_1   GPIO_I
#else 
#define     _PI_1   NOT_A_PIN
#endif
#ifdef  PINI2
#define     _PI_2   GPIO_I
#else      
#define     _PI_2   NOT_A_PIN
#endif
#ifdef  PINI3
#define     _PI_3   GPIO_I
#else      
#define     _PI_3   NOT_A_PIN
#endif
#ifdef  PINI4
#define     _PI_4   GPIO_I
#else 
#define     _PI_4   NOT_A_PIN
#endif
#ifdef  PINI5
#define     _PI_5   GPIO_I
#else 
#define     _PI_5   NOT_A_PIN
#endif
#ifdef  PINI6
#define    _PI_6    GPIO_I
#else
#define    _PI_6    NOT_A_PIN
#endif
#ifdef  PINI7
#define     _PI_7   GPIO_I
#else       
#define     _PI_7   NOT_A_PIN
#endif
//Pins OF PORTJ
#ifdef  PINJ0
#define     _PJ_0   GPIO_J
#else
#define     _PJ_0   NOT_A_PIN
#endif
#ifdef  PINJ1
#define     _PJ_1   GPIO_J
#else 
#define     _PJ_1   NOT_A_PIN
#endif
#ifdef  PINJ2
#define     _PJ_2   GPIO_D
#else      
#define     _PJ_2   NOT_A_PIN
#endif
#ifdef  PINJ3
#define     _PJ_3   GPIO_J
#else      
#define     _PJ_3   NOT_A_PIN
#endif
#ifdef  PINJ4
#define     _PJ_4   GPIO_J
#else 
#define     _PJ_4   NOT_A_PIN
#endif
#ifdef  PINJ5
#define     _PJ_5   GPIO_J
#else 
#define     _PJ_5   NOT_A_PIN
#endif
#ifdef  PINJ6
#define    _PJ_6    GPIO_J
#else
#define    _PJ_6    NOT_A_PIN
#endif
#ifdef  PINJ7
#define     _PJ_7   GPIO_J
#else       
#define     _PJ_7   NOT_A_PIN
#endif
//Pins OF PORTK
#ifdef  PINK0
#define     _PK_0   GPIO_K
#else
#define     _PK_0   NOT_A_PIN
#endif
#ifdef  PINK1
#define     _PK_1   GPIO_K
#else 
#define     _PK_1   NOT_A_PIN
#endif
#ifdef  PINK2
#define     _PK_2   GPIO_K
#else      
#define     _PK_2   NOT_A_PIN
#endif
#ifdef  PINK3
#define     _PK_3   GPIO_K
#else      
#define     _PK_3   NOT_A_PIN
#endif
#ifdef  PINK4
#define     _PK_4   GPIO_K
#else 
#define     _PK_4   NOT_A_PIN
#endif
#ifdef  PINK5
#define     _PK_5   GPIO_K
#else 
#define     _PK_5   NOT_A_PIN
#endif
#ifdef  PINK6
#define    _PK_6    GPIO_K
#else
#define    _PK_6    NOT_A_PIN
#endif
#ifdef  PINK7
#define     _PK_7   GPIO_K
#else       
#define     _PK_7   NOT_A_PIN
#endif
//Pins OF PORTL
#ifdef  PINL0
#define     _PL_0   GPIO_L
#else
#define     _PL_0   NOT_A_PIN
#endif
#ifdef  PINL1
#define     _PL_1   GPIO_L
#else 
#define     _PL_1   NOT_A_PIN
#endif
#ifdef  PINL2
#define     _PL_2   GPIO_L
#else      
#define     _PL_2   NOT_A_PIN
#endif
#ifdef  PINL3
#define     _PL_3   GPIO_L
#else      
#define     _PL_3   NOT_A_PIN
#endif
#ifdef  PINL4
#define     _PL_4   GPIO_L
#else 
#define     _PL_4   NOT_A_PIN
#endif
#ifdef  PINL5
#define     _PL_5   GPIO_L
#else 
#define     _PL_5   NOT_A_PIN
#endif
#ifdef  PINL6
#define    _PL_6    GPIO_L
#else
#define    _PL_6    NOT_A_PIN
#endif
#ifdef  PINL7
#define     _PL_7   GPIO_L
#else       
#define     _PL_7   NOT_A_PIN
#endif
#endif

#define portId2PIN(x)       portId2PINA(x)
#define portId2PINA(x)      (((x) == PA_ID) ? PA_PIN : portId2PINB(x))
#define portId2PINB(x)      (((x) == PB_ID) ? PB_PIN : portId2PINC(x))
#define portId2PINC(x)      (((x) == PC_ID) ? PC_PIN : portId2PIND(x))
#define portId2PIND(x)      (((x) == PD_ID) ? PD_PIN : portId2PINE(x))
#define portId2PINE(x)      (((x) == PE_ID) ? PE_PIN : portId2PINF(x))
#define portId2PINF(x)      (((x) == PF_ID) ? PF_PIN : portId2PING(x))
#define portId2PING(x)      (((x) == PG_ID) ? PG_PIN : portId2PINH(x))
#define portId2PINH(x)      (((x) == PH_ID) ? PH_PIN : portId2PINI(x))
#define portId2PINI(x)      (((x) == PI_ID) ? PI_PIN : portId2PINJ(x))
#define portId2PINJ(x)      (((x) == PJ_ID) ? PJ_PIN : portId2PINK(x))
#define portId2PINK(x)      (((x) == PK_ID) ? PK_PIN : portId2PINL(x))
#define portId2PINL(x)      (((x) == PL_ID) ? PL_PIN : NOT_A_PORT)


#define portId2DDR(x)       portId2DDRA(x)
#define portId2DDRA(x)      (((x) == PA_ID) ? PA_DDR : portId2DDRB(x))
#define portId2DDRB(x)      (((x) == PB_ID) ? PB_DDR : portId2DDRC(x))
#define portId2DDRC(x)      (((x) == PC_ID) ? PC_DDR : portId2DDRD(x))
#define portId2DDRD(x)      (((x) == PD_ID) ? PD_DDR : portId2DDRE(x))
#define portId2DDRE(x)      (((x) == PE_ID) ? PE_DDR : portId2DDRF(x))
#define portId2DDRF(x)      (((x) == PF_ID) ? PF_DDR : portId2DDRG(x))
#define portId2DDRG(x)      (((x) == PG_ID) ? PG_DDR : portId2DDRH(x))
#define portId2DDRH(x)      (((x) == PH_ID) ? PH_DDR : portId2DDRI(x))
#define portId2DDRI(x)      (((x) == PI_ID) ? PI_DDR : portId2DDRJ(x))
#define portId2DDRJ(x)      (((x) == PJ_ID) ? PJ_DDR : portId2DDRK(x))
#define portId2DDRK(x)      (((x) == PK_ID) ? PK_DDR : portId2DDRL(x))
#define portId2DDRL(x)      (((x) == PL_ID) ? PL_DDR : NOT_A_PORT)

#define portId2PORT(x)       portId2PORTA(x)
#define portId2PORTA(x)      (((x) == PA_ID) ? PA_PORT : portId2PORTB(x))
#define portId2PORTB(x)      (((x) == PB_ID) ? PB_PORT : portId2PORTC(x))
#define portId2PORTC(x)      (((x) == PC_ID) ? PC_PORT : portId2PORTD(x))
#define portId2PORTD(x)      (((x) == PD_ID) ? PD_PORT : portId2PORTE(x))
#define portId2PORTE(x)      (((x) == PE_ID) ? PE_PORT : portId2PORTF(x))
#define portId2PORTF(x)      (((x) == PF_ID) ? PF_PORT : portId2PORTG(x))
#define portId2PORTG(x)      (((x) == PG_ID) ? PG_PORT : portId2PORTH(x))
#define portId2PORTH(x)      (((x) == PH_ID) ? PH_PORT : portId2PORTI(x))
#define portId2PORTI(x)      (((x) == PI_ID) ? PI_PORT : portId2PORTJ(x))
#define portId2PORTJ(x)      (((x) == PJ_ID) ? PJ_PORT : portId2PORTK(x))
#define portId2PORTK(x)      (((x) == PK_ID) ? PK_PORT : portId2PORTL(x))
#define portId2PORTL(x)      (((x) == PL_ID) ? PL_PORT : NOT_A_PORT)


#if 1 

static const uint16_t PROGMEM port_to_input_PGM[] = {
    NOT_A_PORT,
    PA_PIN, PB_PIN, PC_PIN, PD_PIN, PE_PIN, PF_PIN,
    PG_PIN, PH_PIN, PI_PIN, PJ_PIN, PK_PIN, PL_PIN
};

static const uint16_t PROGMEM port_to_mode_PGM[] = {
    NOT_A_PORT,
    PA_DDR, PB_DDR, PC_DDR, PD_DDR, PE_DDR, PF_DDR,
    PG_DDR, PH_DDR, PI_DDR, PJ_DDR, PK_DDR, PL_DDR
};

static const uint16_t PROGMEM port_to_output_PGM[] = {
    NOT_A_PORT,
    PA_PORT, PB_PORT, PC_PORT, PD_PORT, PE_PORT, PF_PORT,
    PG_PORT, PH_PORT, PI_PORT, PJ_PORT, PK_PORT, PL_PORT
};

static const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
    NOT_A_PIN,
    _PA_0, _PA_1, _PA_2, _PA_3, _PA_4, _PA_5, _PA_6, _PA_7, // PORTA
    _PB_0, _PB_1, _PB_2, _PB_3, _PB_4, _PB_5, _PB_6, _PB_7, // PORTB
    _PC_0, _PC_1, _PC_2, _PC_3, _PC_4, _PC_5, _PC_6, _PC_7, // PORTC
    _PD_0, _PD_1, _PD_2, _PD_3, _PD_4, _PD_5, _PD_6, _PD_7, // PORTD
    _PE_0, _PE_1, _PE_2, _PE_3, _PE_4, _PE_5, _PE_6, _PE_7, // PORTE
    _PF_0, _PF_1, _PF_2, _PF_3, _PF_4, _PF_5, _PF_6, _PF_7, // PORTF
    _PG_0, _PG_1, _PG_2, _PG_3, _PG_4, _PG_5, _PG_6, _PG_7, // PORTG
    _PH_0, _PH_1, _PH_2, _PH_3, _PH_4, _PH_5, _PH_6, _PH_7, // PORTH
    _PI_0, _PI_1, _PI_2, _PI_3, _PI_4, _PI_5, _PI_6, _PI_7, // PORTI
    _PJ_0, _PJ_1, _PJ_2, _PJ_3, _PJ_4, _PJ_5, _PJ_6, _PJ_7, // PORTJ
    _PK_0, _PK_1, _PK_2, _PK_3, _PK_4, _PK_5, _PK_6, _PK_7, // PORTK
    _PL_0, _PL_1, _PL_2, _PL_3, _PL_4, _PL_5, _PL_6, _PL_7 // PORTL
};

static const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
    NOT_A_PIN,
    _BV(0), _BV(1), _BV(2), _BV(3), _BV(4), _BV(5), _BV(6), _BV(7), // PORTA
    _BV(0), _BV(1), _BV(2), _BV(3), _BV(4), _BV(5), _BV(6), _BV(7), // PORTB
    _BV(0), _BV(1), _BV(2), _BV(3), _BV(4), _BV(5), _BV(6), _BV(7), // PORTC
    _BV(0), _BV(1), _BV(2), _BV(3), _BV(4), _BV(5), _BV(6), _BV(7), // PORTD
    _BV(0), _BV(1), _BV(2), _BV(3), _BV(4), _BV(5), _BV(6), _BV(7), // PORTE
    _BV(0), _BV(1), _BV(2), _BV(3), _BV(4), _BV(5), _BV(6), _BV(7), // PORTF
    _BV(0), _BV(1), _BV(2), _BV(3), _BV(4), _BV(5), _BV(6), _BV(7), // PORTG
    _BV(0), _BV(1), _BV(2), _BV(3), _BV(4), _BV(5), _BV(6), _BV(7), // PORTH
    _BV(0), _BV(1), _BV(2), _BV(3), _BV(4), _BV(5), _BV(6), _BV(7), // PORTI
    _BV(0), _BV(1), _BV(2), _BV(3), _BV(4), _BV(5), _BV(6), _BV(7), // PORTJ
    _BV(0), _BV(1), _BV(2), _BV(3), _BV(4), _BV(5), _BV(6), _BV(7), // PORTK
    _BV(0), _BV(1), _BV(2), _BV(3), _BV(4), _BV(5), _BV(6), _BV(7) // PORTL
};

#define PORT_MASK  0xFF

#define digitalPinToPort(P)     (pgm_read_byte(digital_pin_to_port_PGM + (P)))
#define digitalPinToBitMask(P)  (pgm_read_byte(digital_pin_to_bit_mask_PGM + (P)))

//#define portIdRegister(P)       ((volatile uint8_t) (pgm_read_byte(port_to_ID_PGM + (P))))
#define portInputRegister(P)    ((volatile uint8_t*)(pgm_read_word(port_to_input_PGM + (P))))
#define portModeRegister(P)     ((volatile uint8_t*)(pgm_read_word(port_to_mode_PGM + (P))))
#define portOutputRegister(P)   ((volatile uint8_t*)(pgm_read_word(port_to_output_PGM + (P))))

#endif 

typedef enum {
    MODE_INPUT,
    MODE_INPUT_PULLUP,
    MODE_OUTPUT_LOW,
    MODE_OUTPUT_HIGH,
} EN_Mode_t;

typedef enum {
    GPIO_LOW,
    GPIO_HIGH
} EN_GPIO_t;

/*pin operation*/

/**
 * 
 * @param u8Pin  Pin ID
 * @param u8Mode Three mode of the Pin (Input - Output- PULLUP Resistor) 
 * @param u8Init   Pin start High or Low load a Pin is the Output  
 */
void digitalpinMode(uint8_t u8Pin, uint8_t u8Mode);

/**
 * 
 * @param u8Pin PIN ID
 * @param u8Value PIN Value
 */
void digitalPinWrite(uint8_t u8Pin, uint8_t u8Value);

/**
 * 
 * @param u8Pin
 * @return PIN Register Value 
 */
uint8_t digitalPinRead(uint8_t u8Pin);

/*
 * 
 * @param u8PortId
 * @param u8Mode
 */
void digitalPortMode(uint8_t u8PortId, uint8_t u8Mode);

/**
 * 
 * @param u8PortId
 * @param u8Value
 */
void digitalPortWrite(uint8_t u8PortId, uint8_t u8Value);

/**
 * 
 * @param u8PortId
 * @return 
 */
uint8_t digitalPortRead(uint8_t u8PortId);

/*pins operation*/
void digitalPinsMode(uint8_t u8PortId, uint8_t u8Mask, uint8_t u8Mode, uint8_t u8Init);

void digitalPinsWrite(uint8_t u8PortId, uint8_t u8Mask, uint8_t u8Value);

uint8_t digitalPinsRead(uint8_t u8PortId, uint8_t u8Mask);

void digitalTogglePin(uint8_t u8Pin);
#endif	/* XC_GPIO_V2_H */