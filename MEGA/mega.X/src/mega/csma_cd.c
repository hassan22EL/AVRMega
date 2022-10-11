

/*
 * File:   csma_cd.c
 * Author: Hassan
 *
 * Created on August 6, 2022, 11:43 PM
 */



#include "../../inc/mega.h"
#if             CSMA_CD_MODULE

#define  CSMA_CD_SEND_FLAG             7
#define  CSMA_SEND_BYTE_FLAG           5
#define  CSMA_NETWORK_FLAG             4
#define  CSMA_FREE_NETWORK_MASK      0x03

#define  RECEIVE_CASE                  0x00
#define  TRANSMITTION_CASE             0x01
#define  BLOCKED_CASE                  0x02




volatile uint16_t gu16timeValue;

volatile uint8_t gu8collisionCounter;
volatile uint8_t gu8csmaStatus;
volatile uint8_t gu8Data;
/* byte byte count*/
volatile uint8_t gu8ReceiveByteCount;
volatile uint8_t gu8SendByteCount;
volatile uint8_t gu8Address;

/*received data*/
volatile pAsyncFunc_t gpFcomHostCallback;
volatile pAsyncFunc_t gpFcomClientCallback;


/*back off time*/
uint8_t gu8ReceiveBuf[COMM_BUFFER_LENGTH];
uint8_t gu8SendBuf[COMM_BUFFER_LENGTH];

stFram_t gsReceiveFrame;
stFram_t gsTransmissionFrame;






void FramSend();
void FramNetWork();
void Decapsulate(stFram_t * psFrame);
void Encapsulate(stFram_t * psFrame);
void csma_RestTimer(void);
void csma_StartTimer(uint16_t u16Value);




#if CSMA_ADDRESS == PIN_ADDRESS
uint8_t csmaReadAddress();
#endif

uint8_t FrameLRC(uint8_t *buf, uint8_t u8BufferLengh);
uint8_t ReceiverParsingFram();
uint16_t csma_Regiter(uint8_t Address);






#if defined (__AVR_ATmega8__)|| defined (__AVR_ATmega8A__)
#define        UART_RX_VECTOR      USART_RXC_vect
#define       UART_TX_VECTOR       USART_TXC_vect
#define       UART_UDRE_VECTOR     USART_UDRE_vect
#endif


#if defined (__AVR_ATmega328P__ ) || defined (__AVR_ATmega328__) ||defined (__AVR_ATmega48A__)
#define       UART_RX_VECTOR       USART_RX_vect     
#define       UART_TX_VECTOR       USART_TX_vect
#define       UART_UDRE_VECTOR     USART_UDRE_vect
#endif

#if  defined(__AVR_ATmega128A__) || defined (__AVR_ATmega128__) 
#if (UART == UART0) 
#define       UART_RX_VECTOR       USART0_RX_vect  
#define       UART_TX_VECTOR       USART0_TX_vect
#define       UART_UDRE_VECTOR     USART0_UDRE_vect

#elif (UART == UART1)
#define       UART_RX_VECTOR       USART1_RX_vect 
#define       UART_TX_VECTOR       USART1_TX_vect
#define       UART_UDRE_VECTOR     USART1_UDRE_vect

#endif

#endif

ISR(TIMER1_COMPA_vect) {
    csma_RestTimer();
    if ((gu8csmaStatus & CSMA_FREE_NETWORK_MASK) == RECEIVE_CASE) {
        if (ReceiverParsingFram() != 0) {
            bitSet(gu8csmaStatus, CSMA_NETWORK_FLAG);
        }
        for (uint8_t i = 0; i < COMM_BUFFER_LENGTH; i++)
            gu8ReceiveBuf[i] = 0x00;
        gu8ReceiveByteCount = 0;
        return;
    }

    if ((gu8csmaStatus & CSMA_FREE_NETWORK_MASK) == BLOCKED_CASE) {
        /*check the send sate is ok or no*/
        if (bitIsSet(gu8csmaStatus, CSMA_CD_SEND_FLAG)) {
            csma_StartTimer(gu16timeValue + (uint16_t) gu8collisionCounter);
            bitsValue(gu8csmaStatus, TRANSMITTION_CASE, CSMA_FREE_NETWORK_MASK);
        }
        return;
    }

    if ((gu8csmaStatus & CSMA_FREE_NETWORK_MASK) == TRANSMITTION_CASE) {
        gu8ReceiveByteCount = 0;
        while (!Empty_BUFFER());
        UARTDataTransmit(gu8SendBuf[0]);
        bitSet(gu8csmaStatus, CSMA_SEND_BYTE_FLAG);
        return;
    }

}



#if defined (__AVR_ATmega328P__ ) || defined (__AVR_ATmega328__) 

ISR(PCINT2_vect) {
    csma_RestTimer();
    bitsValue(gu8csmaStatus, RECEIVE_CASE, CSMA_FREE_NETWORK_MASK);
}

#endif
#if  defined(__AVR_ATmega128A__) || defined (__AVR_ATmega128__)

ISR(INT2_vect) {
    csma_RestTimer();
    bitsValue(gu8csmaStatus, RECEIVE_CASE, CSMA_FREE_NETWORK_MASK);
}
#endif



#if  defined(__AVR_ATmega8__) || defined (__AVR_ATmega8A__) ||defined (__AVR_ATmega48A__)

ISR(INT0_vect) {
    csma_RestTimer();
    bitsValue(gu8csmaStatus, RECEIVE_CASE, CSMA_FREE_NETWORK_MASK);
}
#endif

ISR(UART_RX_VECTOR) {
    if (gu8ReceiveByteCount < COMM_BUFFER_LENGTH) {
        gu8ReceiveBuf[gu8ReceiveByteCount] = UARTDataReceive();
        if (bitIsSet(gu8csmaStatus, CSMA_SEND_BYTE_FLAG)) {
            if (gu8ReceiveBuf[gu8ReceiveByteCount] != gu8SendBuf[gu8SendByteCount]) {
                gu8collisionCounter += REGITER_RECIVE_VALUE;
                gu8SendByteCount = 0;
                gu8ReceiveByteCount = 0;
                bitClear(gu8csmaStatus, CSMA_SEND_BYTE_FLAG);
            } else {
                if (gu8SendByteCount < gu8SendBuf[bytecount] - 1) {
                    gu8SendByteCount++;
                    UARTDataTransmit(gu8SendBuf[gu8SendByteCount]);
                } else {
                    for (uint8_t i = 0; i < COMM_BUFFER_LENGTH; i++)
                        gu8ReceiveBuf[i] = 0x00;
                    for (uint8_t i = 0; i < COMM_BUFFER_LENGTH; i++)
                        gu8SendBuf[i] = 0x00;
                    gu8SendByteCount = 0;
                    gu8collisionCounter = 0;
                    gu8ReceiveByteCount = 0;
                    bitClear(gu8csmaStatus, CSMA_CD_SEND_FLAG);
                    bitClear(gu8csmaStatus, CSMA_SEND_BYTE_FLAG);
                }
            }
        }

        gu8ReceiveByteCount++;
        csma_StartTimer(REGITER_RECIVE_VALUE);
    }

#if  defined(__AVR_ATmega128A__) || defined (__AVR_ATmega128__) 
    EICRA &= ~_BV(ISC20);
    EICRA |= _BV(ISC21);
#endif
    return;
}

void csmaInit() {

#if DECIVE_TYPE == SLAVE
#if CSMA_ADDRESS  == PIN_ADDRESS
    digitalpinMode(CSMA_A0, MODE_INPUT_PULLUP);
    digitalpinMode(CSMA_A1, MODE_INPUT_PULLUP);
    digitalpinMode(CSMA_A2, MODE_INPUT_PULLUP);
    digitalpinMode(CSMA_A3, MODE_INPUT_PULLUP);
    digitalpinMode(CSMA_A4, MODE_INPUT_PULLUP);
    digitalpinMode(CSMA_A5, MODE_INPUT_PULLUP);
    digitalpinMode(CSMA_A6, MODE_INPUT_PULLUP);
#endif
#endif


#if defined (__AVR_ATmega328P__ ) || defined (__AVR_ATmega328__) 
    PCMSK2 = _BV(PCINT16); /* We only want to use this pin.  */
    PCICR |= _BV(PCIE2);
#endif
#if  defined(__AVR_ATmega128A__) || defined (__AVR_ATmega128__) 
    EIMSK |= _BV(INT2);
    EICRA &= ~_BV(ISC20);
    EICRA |= _BV(ISC21);
#endif

#if defined (__AVR_ATmega8__)|| defined (__AVR_ATmega8A__)

    MCUCR &= ~(1 << ISC01);
    MCUCR |= (1 << ISC00);
    GICR |= (1 << INT0);
#endif

    gu8csmaStatus = 0x00;
    gu8ReceiveByteCount = 0;
    gu8SendByteCount = 0;
    gu8collisionCounter = 0;
    gu8Address = 0;
    for (uint8_t i = 0; i < COMM_BUFFER_LENGTH; i++)
        gu8SendBuf[i] = 0x00;
    for (uint8_t i = 0; i < COMM_BUFFER_LENGTH; i++)
        gu8ReceiveBuf[i] = 0x00;

#if DECIVE_TYPE == SLAVE
#if CSMA_ADDRESS == PIN_ADDRESS
    gu8Address = csmaReadAddress();
#endif
#endif
    gu16timeValue = csma_Regiter(gu8Address);
}

uint16_t csma_Regiter(uint8_t Address) {
    uint16_t time, freq, value;
    time = (uint16_t) ((2UL * BYTE_DURATION) + (CSMA_BIT_DURATION * 2UL * Address));
    freq = (uint16_t) ((1000000UL / time) + 1UL);
    value = (uint16_t) (F_CPU / (64UL * freq));
    return ((uint16_t) value);
}

void csma_RestTimer(void) {
    TCCR1B = 0x00;
    TCNT1 = 0;
#if defined (__AVR_ATmega328P__ ) || defined (__AVR_ATmega328__) 
    TIMSK1 &= ~_BV(OCIE1A);
#endif
#if  defined(__AVR_ATmega128A__) || defined (__AVR_ATmega128__) 
    TIMSK &= ~_BV(OCIE1A);
#endif

#if defined (__AVR_ATmega8__)|| defined (__AVR_ATmega8A__)
    TIMSK &= ~_BV(OCIE1A);
#endif


}

void csma_StartTimer(uint16_t u16Value) {
    TCCR1B = REGITER_CONTROL_B;
    TCCR1A = 0x00;
    OCR1A = u16Value;
#if defined (__AVR_ATmega328P__ ) || defined (__AVR_ATmega328__) 
    TIMSK1 |= _BV(OCIE1A);
#endif
#if  defined(__AVR_ATmega128A__) || defined (__AVR_ATmega128__)
    TIMSK |= _BV(OCIE1A);
#endif

#if defined (__AVR_ATmega8__) || defined (__AVR_ATmega8A__)
    TIMSK |= _BV(OCIE1A);
#endif


}

void csmaDriver() {
    FramNetWork();
}

uint8_t FrameLRC(uint8_t *buf, uint8_t u8BufferLengh) {
    uint8_t u8temp = 0;
    for (uint8_t i = 0; i < u8BufferLengh; i++) {
        u8temp ^= buf[i];
    }
    u8temp &= 0xFF;
    return u8temp;
}

/*new frame send*/
void StartTransmission() {
    Encapsulate(&gsTransmissionFrame);
    csma_StartTimer(gu16timeValue + gu8collisionCounter);
    bitSet(gu8csmaStatus, CSMA_CD_SEND_FLAG);
    bitsValue(gu8csmaStatus, TRANSMITTION_CASE, CSMA_FREE_NETWORK_MASK);
}

void Decapsulate(stFram_t * psFrame) {
    psFrame->u8Address = gu8ReceiveBuf[Address];
    psFrame->u8ByteCount = gu8ReceiveBuf[bytecount] - startbyte - 1;
    for (uint8_t i = 0; i < psFrame->u8ByteCount; i++) {
        psFrame->u8Data[i] = gu8ReceiveBuf[i + startbyte];
    }
}

/*encapsulate*/
void Encapsulate(stFram_t * psFrame) {
    if ((psFrame->u8ByteCount + startbyte) <= COMM_BUFFER_LENGTH) {
        gu8SendBuf[Address] = psFrame->u8Address; // index 0 
        gu8SendBuf[bytecount] = psFrame->u8ByteCount + startbyte + 1; //index 2 = data length + (3)
        for (uint8_t i = 0; i < psFrame->u8ByteCount; i++) {
            gu8SendBuf[startbyte + (i)] = (psFrame->u8Data[i]);
        }
        /*set LRC value*/
        gu8SendBuf[gu8SendBuf[bytecount] - 1] = FrameLRC(gu8SendBuf, gu8SendBuf[bytecount] - 1);
    }
}

uint8_t ReceiverParsingFram() {
    /*my data*/
    if (gu8ReceiveByteCount - 1 == 0) {
        if (gu8collisionCounter != 0) {
            csma_StartTimer(gu16timeValue + (uint16_t) gu8collisionCounter);
            bitsValue(gu8csmaStatus, TRANSMITTION_CASE, CSMA_FREE_NETWORK_MASK);
        }
        return (0);
    }

    if (gu8ReceiveByteCount < 3)
        return (0);



#if DECIVE_TYPE == SLAVE
    if ((gu8ReceiveBuf[Address] < CSMA_FREE_ADDRESS)) {
        if (gu8ReceiveBuf[Address] != gu8Address) {
            csma_StartTimer(REGISTER_BLOCKED_VALUE);
            bitsValue(gu8csmaStatus, BLOCKED_CASE, CSMA_FREE_NETWORK_MASK);
            return (0);
        }
    }
#endif 


    if (bitIsSet(gu8csmaStatus, CSMA_CD_SEND_FLAG)) {
        csma_StartTimer(gu16timeValue + (uint16_t) gu8collisionCounter);
        bitsValue(gu8csmaStatus, TRANSMITTION_CASE, CSMA_FREE_NETWORK_MASK);
    }



    if (gu8ReceiveBuf[Address] == CSMA_FREE_ADDRESS) {
        return (0);
    }


    if (gu8ReceiveBuf[Address] == CSMA_BLOCK_ADDRESS) {
        return (0);
    }



    if (gu8ReceiveByteCount > COMM_BUFFER_LENGTH) {
        return (0);
    }

    if (gu8ReceiveBuf[gu8ReceiveBuf[bytecount] - 1] != FrameLRC(gu8ReceiveBuf, gu8ReceiveBuf[bytecount] - 1)) {
        return (0);
    }
    /*chaek address and type*/
    Decapsulate(&gsReceiveFrame);
    return (1);
}

/*new Received data*/
void OnHostFrame(pAsyncFunc_t receiveFrame) {
    gpFcomHostCallback = receiveFrame;
}

void OnClientFrame(pAsyncFunc_t receiveFrame) {
    gpFcomClientCallback = receiveFrame;
}

/*open communication*/
uint8_t IsCommunicationOpen() {
    if (bitIsClear(gu8csmaStatus, CSMA_CD_SEND_FLAG) && ((gu8csmaStatus & CSMA_FREE_NETWORK_MASK) != BLOCKED_CASE)) {
        return (1);
    }
    return (0);
}

void FramNetWork() {
    if (bitIsClear(gu8csmaStatus, CSMA_NETWORK_FLAG))
        return;


    if (gsReceiveFrame.u8Data[0] >= 128) {
        if (gpFcomClientCallback()) {
            /*response handling*/
            bitClear(gu8csmaStatus, CSMA_NETWORK_FLAG);
        }
    } else {
        if (gpFcomHostCallback()) {
            /*request handing */
            bitClear(gu8csmaStatus, CSMA_NETWORK_FLAG);
        }
    }
}
#if  CSMA_ADDRESS == POINT_ADDRESS

void csmaSetAddress(uint8_t address) {
    gu8Address = address;
    gu16timeValue = csma_Regiter(gu8Address);
}
#endif

uint8_t csmaGetAddress() {
    return gu8Address;
}

#if DECIVE_TYPE == SLAVE
#if CSMA_ADDRESS == PIN_ADDRESS

uint8_t csmaReadAddress() {
    uint8_t u8Address;
    u8Address = 0x00;
    u8Address |= (digitalPinRead(CSMA_A0) << 0);
    u8Address |= (digitalPinRead(CSMA_A1) << 1);
    u8Address |= (digitalPinRead(CSMA_A2) << 2);
    u8Address |= (digitalPinRead(CSMA_A3) << 3);
    u8Address |= (digitalPinRead(CSMA_A4) << 4);
    u8Address |= (digitalPinRead(CSMA_A5) << 5);
    u8Address |= (digitalPinRead(CSMA_A6) << 6);
    if (u8Address == 0) u8Address = 127;
    return (u8Address & 0x7f);
}
#endif
#endif
#endif