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
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:UART    
 * Author: Hassan Elsaied
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_UART_H
#define	XC_UART_H

#include "../mega.h"


#ifndef F_CPU 
#warning F_CPU is Not defined , Please define F_CPU
#endif /*F_CPU*/

#ifndef BaudRate
#warning BaudRate in UART is Not defined , Please define Baudrate
#endif

#define  PTP           (1)

#define STOPBIT_ONE    (0)
#define STOPBIT_TWO     (1)

#define FRAM_FORMAT_5BIT  (5)
#define FRAM_FORMAT_6BIT  (6)
#define FRAM_FORMAT_7BIT  (7)
#define FRAM_FORMAT_8BIT  (8)
#define FRAM_FORMAT_9BIT  (9)

#define  ParityMode_Disable      (0)
#define  ParityMode_Enabled_ODD  (1)
#define  ParityMode_Enabled_even (2)




#define UART_NOT_FOUND (0)
#define UART0_ID   (1)
#define UART1_ID   (2)
#define UART2_ID   (3)
#define UART_ID    (4)




#ifdef  UDR 
#define   UASRT       UART_ID
#else 
#define  UASRT  UART_NOT_FOUND
#endif

#ifdef UDR0 
#define  UART0  UART0_ID   
#else 
#define  UART0  UART_NOT_FOUND
#endif 

#ifdef UDR1
#define  UART1  UART1_ID  
#else 
#define  UART1  UART_NOT_FOUND
#endif 

#ifdef UDR2 
#define  UART2  UART2_ID
#else 
#define  UART2  UART_NOT_FOUND
#endif 

#ifndef UART 
#warning please define UART to select UART to work
#else

#if (UART == UASRT)
#if(UART==UART_NOT_FOUND)
#warning  the UAERT Selected NOT FOUND
#else

//Registers
#define  UBRRnH   UBRRH 
#define  UBRRnL   UBRRL







#define  UDRn     UDR
#define  UCSRnA   UCSRA
#define  UCSRnB   UCSRB
#define  UCSRnC   UCSRC
//bits of Registers
//UCSR0A  Register
#define  RXCn   RXC
#define  TXCn   TXC
#define  UDREn  UDRE 
#define  FEn    FE
#define  DORn   DOR
#define  UPEn   UPE
#define  U2Xn   U2X
#define  MPCMn  MPCM
//UCSR0B  Register
#define  RXCIEn   RXCIE
#define  TXCIEn   TXCIE
#define  UDRIEn   UDRIE 
#define  RXENn    RXEN 
#define  TXENn    TXEN
#define  UCSZn2   UCSZ2
#define  RXB8n    RXB8
#define  TXB8n    TXB8

//UCSR0C  Register
#define  URSELn   URSEL
#define  UMSELn   UMSEL
#define  UPMn1    UPM1 
#define  UPMn0    UPM0 
#define  USBSn    USBS
#define  UCSZn1   UCSZ1
#define  UCSZn0   UCSZ0
#define  UCPOLn   UCPOL
#endif

#elif  (UART==UART0)
#if(UART0==UART_NOT_FOUND)
#warning  the UAERT Selected NOT FOUND
#else 
//Registers
#define  UBRRnH   UBRR0H 
#define  UBRRnL   UBRR0L


#if defined (__AVR_ATmega328P__ ) || defined (__AVR_ATmega328__) ||defined (__AVR_ATmega8__)||defined (__AVR_ATmega8A__) ||defined (__AVR_ATmega48A__) 
#define  UBRRn    UBRR0
#endif


#define  UDRn     UDR0
#define  UCSRnA   UCSR0A
#define  UCSRnB   UCSR0B
#define  UCSRnC   UCSR0C
//bits of Registers
//UCSR0A  Register
#define  RXCn   RXC0
#define  TXCn   TXC0
#define  UDREn  UDRE0 
#define  FEn    FE0 
#define  DORn   DOR0
#define  UPEn   UPE0
#define  U2Xn   U2X0
#define  MPCMn  MPCM0

//UCSR0B  Register
#define  RXCIEn   RXCIE0
#define  TXCIEn   TXCIE0
#define  UDRIEn   UDRIE0 
#define  RXENn    RXEN0 
#define  TXENn    TXEN0
#define  UCSZn2   UCSZ02
#define  RXB8n    RXB80
#define  TXB8n    TXB80

//UCSR0C  Register
#if defined (__AVR_ATmega328P__ ) || defined (__AVR_ATmega328__) ||defined (__AVR_ATmega8__)||defined (__AVR_ATmega8A__)  || defined (__AVR_ATmega48A__)
#define  UMSELn1  UMSEL01
#define  UMSELn0  UMSEL00
#endif

#if  defined(__AVR_ATmega128A__) || defined (__AVR_ATmega128__)
#define  UMSELn   UMSEL0
#endif


#define  UPMn1    UPM01 
#define  UPMn0    UPM00 
#define  USBSn    USBS0
#define  UCSZn1   UCSZ01
#define  UCSZn0   UCSZ00
#define  UCPOLn   UCPOL0

#endif 
#elif (UART==UART1)

#if(UART1 == UART_NOT_FOUND)
#warning  the UAERT Selected NOT FOUND
#else 
//Registers
#define  UBRRnH   UBRR1H 
#define  UBRRnL   UBRR1L
#define  UDRn     UDR1
#define  UCSRnA   UCSR1A
#define  UCSRnB   UCSR1B
#define  UCSRnC   UCSR1C
//bits of Registers
//UCSR0A  Register
#define  RXCn   RXC1
#define  TXCn   TXC1
#define  UDREn  UDRE1 
#define  FEn    FE1
#define  DORn   DOR1
#define  UPEn   UPE1
#define  U2Xn   U2X1
#define  MPCMn  MPCM1
//UCSR0B  Register
#define  RXCIEn   RXCIE1
#define  TXCIEn   TXCIE1
#define  UDRIEn   UDRIE1 
#define  RXENn    RXEN1 
#define  TXENn    TXEN1
#define  UCSZn2   UCSZ12
#define  RXB8n    RXB81
#define  TXB8n    TXB81

//UCSR0C  Register
#define  UMSELn1  UMSEL1
#define  UMSELn0  UMSEL0
#define  UPMn1    UPM11 
#define  UPMn0    UPM10 
#define  USBSn    USBS1
#define  UCSZn1   UCSZ11
#define  UCSZn0   UCSZ10
#define  UCPOLn   UCPOL1

#endif 


#elif (UART==UART2)
#if(UART1 == UART_NOT_FOUND)
#warning  the UAERT Selected NOT FOUND
#else 
//Registers
#define  UBRRnH   UBRR2H 
#define  UBRRnL   UBRR2L
#define  UBRRn    UBRR2
#define  UDRn     UDR2
#define  UCSRnA   UCSR2A
#define  UCSRnB   UCSR2B
#define  UCSRnC   UCSR2C
//bits of Registers
//UCSR0A  Register
#define  RXCn   RXC2
#define  TXCn   TXC2
#define  UDREn  UDRE2 
#define  FEn    FE2 
#define  DORn   DOR2
#define  UPEn   UPE2
#define  U2Xn   U2X2
#define  MPCMn  MPCM2
//UCSR0B  Register
#define  RXCIEn   RXCIE2
#define  TXCIEn   TXCIE2
#define  UDRIEn   UDRIE2 
#define  RXENn    RXEN2
#define  TXENn    TXEN2
#define  UCSZn2   UCSZ22
#define  RXB8n    RXB82
#define  RXB8n    TXB82

//UCSR0C  Register
#define  UMSELn1  UMSEL21
#define  UMSELn0  UMSEL20
#define  UPMn1    UPM21 
#define  UPMn0    UPM20 
#define  USBSn    USBS2
#define  UCSZn1   UCSZ21
#define  UCSZn0   UCSZ20
#define  UCPOLn   UCPOL2

#endif 
#endif
#endif

/**
 *Control bit to select between this mode is a UMSELn bit in UCSRnC control register 
 * if this set a one the UART is a operation For Sync mode else is a for Async
 */



/**
 * with Async mode UART can operate with Normal speed or Double Speed 
 * the  u2x bit in UCSTRnA is a set 1 the uart operate with double speed else operate normal speed 
 */

/*
 *  the sync mode operate with internal clock  and external clock 
 *  the Direction of XCKn can be select the sync mode is a operate Master two need internal clock 
 *  and sync mode operate slave to need the external clock  
 **/
#define  UARTAsyncNormalSpeed      (0)
#define  UARTAsyncDoubleSpeed      (1)
#define  UARTSyncMaster            (2)
#define  UARTSyncSlave             (4)
#define  UARTMasterSPI             (5)





/**
 * clock generation to UART 
 Baud Rate  = (F_CPU/ (N*(R+1))) N is is pre scale , R --> UBRRn (UART Baud Rate Register)
 **/
#define Prescaller_16   (16UL)
#define Prescaller_8    (8UL)
#define Prescaller_2    (2UL)


#define StandBaudRate_1200     (1200UL)     // Bit duration 833.33us   byterate = 120byte/s        byte duration = 8.333ms
#define StandBaudRate_2400     (2400UL)    //  Bit duration 416.66us   byterate = 240byte/s        byte duration = 4.166ms 
#define StandBaudRate_4800     (4800UL)   //   Bit duration 208.33us   byterate = 480byte/s        byte duration = 2.08ms
#define StandBaudRate_9600     (9600UL)  //    Bit duration 104.16us   byterate = 960byte/s        byte duration = 1.04ms
#define StandBaudRate_19200    (19200UL) //    Bit duration 52.083us   byterate = 1920byte/s       byte duration = 520.83us
#define StandBaudRate_38400    (38400UL) //    Bit duration 26.0416us  byterate = 3840byte/s       byte duration = 260.41us
#define StandBaudRate_57600    (57600UL)  //   Bit duration 17.36 us   byterate = 5760byte/s       byte duration = 173.611us
#define StandBaudRate_76800     (76800UL)  //  Bit duration 13.68us    byterate = 96000byte/s      byte duration = 104.16us
#define StandBaudRate_115200   (115200UL)  //  Bit duration 8.68us     byterate = 11520byte/s      byte duration = 86u



#define BitDuration     (1UL/(BaudRate))
#define ByteBuadRate    (BaudRate/10UL)

//select buadrate by F_CPU 
/**
 * R= (F_CPU/(N*BuadRate))-1 when N is a prescaller 
 * check best baudrate with F_CPU
 * T_CPu = 1/F_CPU
 * T_baudRate = bit_duration  
 */
#define T_CPU = (UL) (1UL/F_CPU)
#ifndef UART_MODE
#warning Please defined UART_MODE 
#else 
#if (UART_MODE==UARTAsyncNormalSpeed)
#define BAUDREG             (((F_CPU) / ((Prescaller_16) * (BaudRate))) + ((1UL)/((2UL)*(BaudRate)*(Prescaller_16))))-1UL
#define BaudRate_R          ((F_CPU) / ((Prescaller_16) * (BAUDREG+1)))
#elif (UART_MODE == UARTAsyncDoubleSpeed)
#define BAUDREG             (((F_CPU) / ((Prescaller_16) * (BaudRate))) + ((1UL)/((2UL)*(BaudRate)*(Prescaller_16))))-1UL
#define BaudRate_R       ((F_CPU) / ((Prescaller_16) * (BAUDREG+1)))
#elif (UART_MODE == UARTSyncMaster)
#define BAUDREG             (((F_CPU) / ((Prescaller_16) * (BaudRate))) + ((1UL)/((2UL)*(BaudRate)*(Prescaller_16))))-1UL
#define BaudRate_R      (((F_CPU) / ((Prescaller_16) * (BAUDREG+1)))
#endif
#endif

#define Error_presantage      ((((BaudRate_R) / (BaudRate))-1UL)*(100UL))
#define Error_BaudRate          Error_presantage

#if (Error_BaudRate != 0)
#warning Please select other BaudRate with inform best buadrate with opreate 11.0592 MHz frequncy of CPU 
#endif


#define  BAUDREG_L         (BAUDREG)
#define  BAUDREG_H         (BAUDREG) >> (8)

#define  Transmit_Enable()              (UCSRnB |=(1<<TXENn))
#define  Receive_Enable()               (UCSRnB |=(1<<RXENn))
#define  Transmit_Disable()             (UCSRnB &=~(1<<TXENn))
#define  Empty_BUFFER()                 ((UCSRnA & (1<<UDREn)))
#define  BuFFer_IS_FULL()               (!(UCSRnA & 1<<UDREn))
#define  Data_NOT_Recevied()            (!(UCSRnA & (1<<RXCn)))
#define  Data_Recevied_Complete()       ((UCSRnA & (1<<RXCn)))
#define  Data_Transmit_Complete()       ((UCSRnA & (1<<TXCn)))
#define  Frame_ERROR()                  ((UCSRnA & (1<<FEn)))
#define  DataOverRun()                  ((UCSRnA & (1<<DORn)))
#define  ParityError()                  ((UCSRnA & (1<<UPEn)))
#define  TX_Complete_Intrupt_Enable()   ((UCSRnB |=(1<<TXCIEn)))
#define  RX_Complete_Interrupt_Enable() ((UCSRnB |=(1<<RXCIEn)))
#define  UDRE_Enable_Interrupt()        ((UCSRnB) |=(1<<UDRIEn))
#define  UDRE_Disable_Interrupt()       ((UCSRnB) &=~(1<<UDRIEn))

// function to initialize UART

static inline void uart_init(void) {
#if defined (__AVR_ATmega8__)||defined (__AVR_ATmega8A__)  
    UBRRH = (uint8_t) ((BAUDREG) >> (8)); // shift the register right by 8 bits
    UBRRL = (uint8_t) BAUDREG; // set baud rate
    UCSRB |= (1 << TXEN) | (1 << RXEN); // enable receiver and transmitter
    UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1); // 8bit data format
    RX_Complete_Interrupt_Enable();
#endif
}

static inline void UART_INIT(uint8_t u8Mode, uint8_t u8FramFormat, uint8_t u8StopBit, uint8_t u8ParityMode) {


    UBRRnH = (uint8_t) BAUDREG_H;
    UBRRnL = (uint8_t) BAUDREG_L;

    Transmit_Enable();
    Receive_Enable();

#if defined (__AVR_ATmega8__) ||defined (__AVR_ATmega8A__)  
    UCSRC |= (1 << URSEL);
#endif
    switch (u8Mode) {
        case UARTAsyncNormalSpeed:
            //Select AsyncNormal 
#if defined (__AVR_ATmega8__) ||defined (__AVR_ATmega8A__)  
            //      UCSRC = (1 << URSEL);
            UCSRnC &= ~(1 << UMSELn);
#else    
            UCSRnC &= ~(1 << UMSELn0);
            UCSRnC &= ~(1 << UMSELn1);
#endif
            //Normal Speed
            UCSRnA &= ~(1 << U2Xn);
            break;
        case UARTAsyncDoubleSpeed:
            //Select AsyncNormal 
#if defined (__AVR_ATmega8__)||defined (__AVR_ATmega8A__)  
            UCSRnC &= ~(1 << UMSELn);
            //Double Speed
#else
            UCSRnC &= ~(1 << UMSELn0);
            UCSRnC &= ~(1 << UMSELn1);
#endif
            UCSRnA |= (1 << U2Xn);
            break;
        case UARTSyncMaster:

            break;
        case UARTSyncSlave:
            break;
        case UARTMasterSPI:
            break;
        default:
            break;

    }


    switch (u8FramFormat) {
        case FRAM_FORMAT_5BIT:
            UCSRnB &= ~(1 << UCSZn2);
            UCSRnC &= ~(1 << UCSZn1);
            UCSRnC &= ~(1 << UCSZn0);
            break;
        case FRAM_FORMAT_6BIT:
            UCSRnB &= ~(1 << UCSZn2);
            UCSRnC &= ~(1 << UCSZn1);
            UCSRnC |= (1 << UCSZn0);
            break;
        case FRAM_FORMAT_7BIT:
            UCSRnB &= ~(1 << UCSZn2);
            UCSRnC |= (1 << UCSZn1);
            UCSRnC &= ~(1 << UCSZn0);
            break;
        case FRAM_FORMAT_8BIT:
            UCSRnB &= ~(1 << UCSZn2);
            UCSRnC |= (1 << UCSZn1);
            UCSRnC |= (1 << UCSZn0);
            break;
        case FRAM_FORMAT_9BIT:
            UCSRnB |= (1 << UCSZn2);
            UCSRnC |= (1 << UCSZn1);
            UCSRnC |= (1 << UCSZn0);
            break;
        default:
            UCSRnB &= ~(1 << UCSZn2);
            UCSRnC |= (1 << UCSZn1);
            UCSRnC |= (1 << UCSZn0);
            break;

    }
    switch (u8StopBit) {
        case STOPBIT_ONE:
            UCSRnC &= ~(1 << USBSn);
            break;
        case STOPBIT_TWO:
            UCSRnC |= (1 << USBSn);
            break;
        default:
            UCSRnC &= ~(1 << USBSn);
            break;
    }
    switch (u8ParityMode) {
        case ParityMode_Disable:
            UCSRnC &= ~(1 << UPMn1);
            UCSRnC &= ~(1 << UPMn0);
            break;
        case ParityMode_Enabled_ODD:
            UCSRnC |= (1 << UPMn1);
            UCSRnC |= (1 << UPMn0);
            break;
        case ParityMode_Enabled_even:
            UCSRnC |= (1 << UPMn1);
            UCSRnC &= ~(1 << UPMn0);
            break;
        default:
            UCSRnC &= ~(1 << UPMn1);
            UCSRnC &= ~(1 << UPMn0);
            break;
    }
    RX_Complete_Interrupt_Enable();
}

static inline void UARTDataTransmit(uint8_t u8Data) {
    UDRn = u8Data;
}

static inline uint8_t UARTDataReceive() {
    return UDRn;
}
#endif	/* XC_HEADER_TEMPLATE_H */ 

