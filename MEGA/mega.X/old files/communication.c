#include <stdint.h>

#include "../../inc/mega.h"

#if  COMMUNICATION_MODULE
#if COMM_TYPE == CSMA_CD_WAITRECEIVE

/*
 * physical layer flag
 * -------------------------------------------
 * | SF | RF | CF | BSF | SRF | REF | BF | NF | 
 * -------------------------------------------
 * bit7 : SF ==>send flag   default 0
 * bit6 : RF ==> receive Flag default 0
 * bit5 : CF ==> collision Flag  default 0
 * bit4 : BSF ==> Byte Send Flag default 0
 * bit3 : SRF ==> Send request Flag default 0
 * bit2 : REF ==> Receive Time out Flag default 1 no receive data
 * bit1 : BF ==> Bus Flag     default 1 bus is busy
 * bit0 : NF ==> Network layer Flag default 0
 * default value 000000110 (0x06)
 */
volatile uint8_t gu8CommunicationFlags;
/*network Flags*/
volatile uint8_t gu8NetworkFlags;
/*receive byte count*/
volatile uint8_t gu8ReceiveByteCount;
/*transmitter byte byte count*/
volatile uint8_t gu8TransmissionByteCount;
/*Transmission Buffer */
volatile uint8_t gu8TransmissionBuffer[COMM_BUFFER_LENGTH];
/*Receive Buffer*/
volatile uint8_t gu8ReceiveBuffer[COMM_BUFFER_LENGTH];
/*NET work buffer*/
uint8_t gu8NetworkBuffer[NET_BUFFER_LENGTH];
/*Last byte off Time*/
volatile uint32_t gu32LastByteReceivedTime;
/*Back Off Time*/
volatile uint8_t gu8BackOffTime;
/*Read byte*/
volatile uint8_t gu8ReadByte;
/*collision counter*/
volatile uint8_t gu8collisionCounter;
/*address byte*/
volatile uint8_t gu8AddressByte;
/*received data*/
volatile pAsyncFunc_t gpFcomHostCallback;
/*Frame of the Transmission */
sFrame gsTransmissionFrame;
/*Frame of the Receive*/
sFrame gsReceiveFrame;
/*NetWork Work Frame*/
sFrame gsNetworkFrame;
/*State of TX*/
States_t geTransmissionFSM;
/*State of RX*/
States_t geReceiveFSM;
/*state NetWork */
States_t geNetworkFSM;
/*network TLV*/
stBufferTLVDescriptor_t gsNetWorkTLV;
/*send Time Out*/
stTimer_t gsSendTimeOut;
/*functions*/
/*remove Frame*/
void removeFrame(sFrame * psFrame);
/*remove buffer*/
void removeBuffer(volatile uint8_t *buf, uint8_t u8length);
/*Transmission FSM*/
void TransmissionFSM(sFrame *psFrame);
/*receive FSM*/
void ReceiveFSM(sFrame *psFrame);
/*NETWORK FSM*/
void NetworkFSM();
/*Host Side*/
void HostFSM();
/*Timing*/
/*Back Off Time*/
uint8_t BackoffTime();
/*Check Bus */
void CheckBus();
/*encapsulate*/
void Encapsulate(sFrame *psFrame);
/*De-capsulate*/
void Decapsulate(sFrame *psFrame);
/*LRC Check*/
uint8_t FrameLRC(volatile uint8_t *buf, uint8_t u8BufferLengh);

/*interrupt handler*/
#if (ATMEGA328)

ISR(USART_RX_vect) {
#elif (ATMEGA128A)
#if(UART == UART0)

ISR(USART0_RX_vect) {
#elif (UART == UART1)

ISR(USART1_RX_vect) {
#endif

#endif
    gu8ReadByte = UARTDataReceive();
    /*set bus is busy*/
    bitSet(gu8CommunicationFlags, BUS_FLAG); /*change bus to busy*/
    gu32LastByteReceivedTime = getSystemTick(); /*current Time at received byte*/

    if (bitIsSet(gu8CommunicationFlags, SEND_FLAG)) {
        /*the state is transmission **/
        if (gu8TransmissionBuffer[gu8TransmissionByteCount] != gu8ReadByte) {
            /*collision state is true */
            bitClear(gu8CommunicationFlags, BYTESEND_FLAG);
            /*collision counter */
            bitSet(gu8CommunicationFlags, COLLISION_FLAG);
        } else {
            /*send next byte */
            bitSet(gu8CommunicationFlags, BYTESEND_FLAG);
            /*collision flag */
            bitClear(gu8CommunicationFlags, COLLISION_FLAG);
        }
    } else {

        bitSet(gu8CommunicationFlags, RECEIVE_FLAG);
        /*update timer after receive byte*/
        /*the receive time out is a slave */
        bitClear(gu8CommunicationFlags, RECEIVETIMEOUT_FLAG);
    }
}

/*Init values*/
void commInit() {
    /*set the Flags 
     * physical layer flag
     * -------------------------------------------
     * | SF | RF | CF | BSF | SRF | REF | BF | NF | 
     * --------------------------------------------
     * | 0  | 0  | 0  | 0   | 0   | 1   |  1 | 0  |  
     * -------------------------------------------
     */
    gu8CommunicationFlags = 0x06;
    /*network flags*/
    gu8NetworkFlags = 0x00;
    /*srand address*/
    srand(gu8AddressByte);
    gu8ReadByte = 0;
    /*back off time  the state of the master or slave*/
    gu8BackOffTime = BackoffTime();
    /*collision counter reset*/
    gu8collisionCounter = 0;
    /*Last Time*/
    gu32LastByteReceivedTime = getSystemTick();
    /*Receive Byte Count*/
    gu8ReceiveByteCount = 0;
    /*Transmission byte Count*/
    gu8TransmissionByteCount = 0;
    /*RX state*/
    geReceiveFSM = RX_IDLE;
    /*TX State*/
    geTransmissionFSM = TX_IDLE;
    /*Network FSM */
    geNetworkFSM = NET_CHECK_CLIENT;
    /*init of new received data*/
    gpFcomHostCallback = NULL;
    /*add network buffer*/
    TLVBufferInit(&gsNetWorkTLV, gu8NetworkBuffer, sizeof (gu8NetworkBuffer));
    /*transmission Time Out */
    sysSetPeriodMS(&gsSendTimeOut, TRANSMISSION_TIME_OUT);
    /*remove receive Frame*/
    removeFrame(&gsReceiveFrame);
    /*remove transmission frame*/
    removeFrame(&gsTransmissionFrame);
    /*remove Transmission Buffer*/
    removeBuffer(gu8TransmissionBuffer, COMM_BUFFER_LENGTH);
    /*remove Receive Buffer*/
    removeBuffer(gu8ReceiveBuffer, COMM_BUFFER_LENGTH);
}

/*call back function new Received data*/
void OnHostFrame(pAsyncFunc_t receiveFrame) {
    gpFcomHostCallback = receiveFrame;
}

/*Transmission FSM*/
void TransmissionFSM(sFrame *psFrame) {

    switch (geTransmissionFSM) {

        case TX_IDLE:
            if (bitIsSet(gu8CommunicationFlags, SENDREQUEST_FLAG)) {
                Encapsulate(psFrame);
                geTransmissionFSM = TX_BUS;
            }
            break;

        case TX_BUS:
            if ((bitIsClear(gu8CommunicationFlags, RECEIVE_FLAG))&&(bitIsClear(gu8CommunicationFlags, BUS_FLAG))) {
                bitSet(gu8CommunicationFlags, BUS_FLAG); /*change the bus to busy*/
                geTransmissionFSM = TX_SEND;
            } else if (bitIsSet(gu8CommunicationFlags, RECEIVE_FLAG)) {
                bitClear(gu8CommunicationFlags, RECEIVE_FLAG);
                bitClear(gu8CommunicationFlags, SEND_FLAG);
                geTransmissionFSM = TX_IDLE;
            }
            break;

        case TX_SEND:
            if (gu8TransmissionByteCount < gu8TransmissionBuffer[bytecount]) {
                if (Empty_BUFFER())UARTDataTransmit(gu8TransmissionBuffer[gu8TransmissionByteCount]);
                /*change state to Send mode*/
                bitSet(gu8CommunicationFlags, SEND_FLAG);
                /*change state to check state*/
                geTransmissionFSM = TX_CHECK;
            } else {

                gu8TransmissionByteCount = 0;
                geTransmissionFSM = TX_END;
            }
            break;

        case TX_CHECK:
            /*check the Transmission receive byte state*/
            if (bitIsSet(gu8CommunicationFlags, BYTESEND_FLAG)) {
                /*increment the index of transmitter*/
                gu8TransmissionByteCount++;
                /*confirmed the send */
                bitSet(gu8CommunicationFlags, SEND_FLAG);
                /*Clear send byte flag*/
                bitClear(gu8CommunicationFlags, BYTESEND_FLAG);
                /*change state to tx byte*/
                geTransmissionFSM = TX_SEND;

            } else {
                if (bitIsSet(gu8CommunicationFlags, COLLISION_FLAG)) {
                    /*the state of the bus is busy*/
                    /*reset the receive interrupt RF*/
                    bitClear(gu8CommunicationFlags, RECEIVE_FLAG);
                    /*confirmed the send request SRF*/
                    bitSet(gu8CommunicationFlags, SENDREQUEST_FLAG);
                    /*change state of the bus to busy*/
                    bitSet(gu8CommunicationFlags, BUS_FLAG);
                    /*generate a random number*/
                    /*set Time of the back off with collision counter is one*/
                    gu8collisionCounter++;
                    /*set back off time*/
                    gu8BackOffTime = BackoffTime();
                    /*clear Interrupt*/
                    bitClear(gu8CommunicationFlags, RECEIVE_FLAG);
                    /*clear collision flag*/
                    bitClear(gu8CommunicationFlags, COLLISION_FLAG);
                    /*Clear send flag*/
                    bitClear(gu8CommunicationFlags, SEND_FLAG); /*change to idle mode*/
                    /*Clear send byte flag*/
                    bitClear(gu8CommunicationFlags, BYTESEND_FLAG);
                    /*remove buffer*/
                    removeBuffer(gu8TransmissionBuffer, gu8TransmissionByteCount);
                    /*reset Transmission Counter*/
                    gu8TransmissionByteCount = 0;
                    if (gu8collisionCounter == 6)gu8collisionCounter = 0;
                    /*go to idle state with out remove the frame*/
                    geTransmissionFSM = TX_IDLE;
                }
            }
            break;

        case TX_END:
            /*reset all data*/
            /*clear send flag*/
            bitClear(gu8CommunicationFlags, SEND_FLAG);
            /*clear byte send flag*/
            bitClear(gu8CommunicationFlags, BYTESEND_FLAG);
            /*reset the request flag*/
            bitClear(gu8CommunicationFlags, SENDREQUEST_FLAG);
            /*remove buffer*/
            removeBuffer(gu8TransmissionBuffer, gu8TransmissionByteCount);
            /*reset counter*/
            gu8TransmissionByteCount = 0;
            /*remove Frame*/
            removeFrame(psFrame);
            /*reset the period to slave or master*/
            gu8BackOffTime = BackoffTime();
            /*go to ready state*/
            geTransmissionFSM = TX_IDLE;
            break;

        default:
            geTransmissionFSM = TX_IDLE;
            break;
    }
}

/*receive FSM*/
void ReceiveFSM(sFrame *psFrame) {
    /*time between Frame is time */
    switch (geReceiveFSM) {

        case RX_IDLE:
            /*check the new byte receive or no*/
            if (bitIsSet(gu8CommunicationFlags, RECEIVE_FLAG)) {
                if (bitIsSet(gu8CommunicationFlags, NETWORK_FLAG)) {
                    bitClear(gu8CommunicationFlags, NETWORK_FLAG);
                    removeFrame(psFrame);
                }
                /*store the byte*/
                /*new byte receive */
                bitClear(gu8CommunicationFlags, RECEIVE_FLAG); /*receive byte reset flag  */
                geReceiveFSM = RX_RECEIVE;
            }
            break;

        case RX_RECEIVE:

            if (gu8ReceiveByteCount < COMM_BUFFER_LENGTH) {
                /*store into buffer and goto receive Time out state*/
                gu8ReceiveBuffer[gu8ReceiveByteCount] = gu8ReadByte;
                bitClear(gu8CommunicationFlags, RECEIVE_FLAG);
                /*reset data*/
                geReceiveFSM = RX_TIMEOUT;
            } else {
                /*remove receive  buffer*/
                removeBuffer(gu8ReceiveBuffer, gu8ReceiveByteCount);
                /*reset receive byte counter*/
                gu8ReceiveByteCount = 0;
                bitClear(gu8CommunicationFlags, RECEIVE_FLAG);
                /*go to error state*/
                geReceiveFSM = RX_ERROR;
            }
            break;

        case RX_ERROR:
            /*error check to Bus Ready*/
            if (bitIsClear(gu8CommunicationFlags, BUS_FLAG)) {
                /*goto receive idle state*/
                geReceiveFSM = RX_IDLE;
            }
            break;

        case RX_TIMEOUT:
            /*check the new*/
            if ((bitIsSet(gu8CommunicationFlags, RECEIVETIMEOUT_FLAG)) && bitIsClear(gu8CommunicationFlags, RECEIVE_FLAG)) {
                bitClear(gu8CommunicationFlags, RECEIVE_FLAG);
                if ((gu8ReceiveBuffer[bytecount] - 1) != gu8ReceiveByteCount) {
                    /*remove receive  buffer*/
                    removeBuffer(gu8ReceiveBuffer, gu8ReceiveByteCount);
                    /*reset receive byte counter*/
                    gu8ReceiveByteCount = 0;
                    /*go to idle state*/
                    geReceiveFSM = RX_IDLE;
                } else {
                    bitClear(gu8CommunicationFlags, RECEIVE_FLAG);
                    geReceiveFSM = RX_PROCESS;
                }
            } else if (bitIsSet(gu8CommunicationFlags, RECEIVE_FLAG)) {
                gu8ReceiveByteCount++;
                geReceiveFSM = RX_RECEIVE;
            }
            break;

        case RX_PROCESS:
            /*check LRC*/
            if (gu8ReceiveBuffer[gu8ReceiveBuffer[bytecount] - 1] != FrameLRC(gu8ReceiveBuffer, gu8ReceiveBuffer[bytecount] - 1)) {
                /*remove receive  buffer*/
                removeBuffer(gu8ReceiveBuffer, gu8ReceiveByteCount);
                /*reset receive byte counter*/
                gu8ReceiveByteCount = 0;
                bitClear(gu8CommunicationFlags, RECEIVE_FLAG);
                geReceiveFSM = RX_IDLE;
            } else {
                bitClear(gu8CommunicationFlags, RECEIVE_FLAG);
                /*Frame Parsing*/
                Decapsulate(psFrame);
                if (putTLV(&gsNetWorkTLV, &gsReceiveFrame)) {
                    bitSet(gu8CommunicationFlags, NETWORK_FLAG); /*inform network  layer  an new Frame received*/
                }
                /*remove receive  buffer*/
                removeBuffer(gu8ReceiveBuffer, gu8ReceiveByteCount);
                /*reset receive byte counter*/
                gu8ReceiveByteCount = 0;
                /*event a new frame received this function can callback function*/
                geReceiveFSM = RX_IDLE;
            }
            break;

        default:
            geReceiveFSM = RX_IDLE;
            break;
    }
}

/*Back Off Time */
uint8_t BackoffTime() {
    uint8_t u8CollisionTime = 0;
    if (DECIVE_TYPE != MASTER) {
        /*the slave rang of rand 0 to 5 and master of rang 0 to 2 */
        if ((bitIsSet(gu8CommunicationFlags, COLLISION_FLAG))) {
            /*the slave node is ready*/
            // u16CollisionTime = ((rand() % (BACKOFFRANG)) + BACKOFFRANDMIN) + (gu8CollsionCounter);
            u8CollisionTime = SLAVE_TIME_OUT + ((uint8_t) (((rand()) * (5UL)) / (RAND_MAX)) + (gu8collisionCounter));
        } else {
            u8CollisionTime = SLAVE_TIME_OUT;
        }
    } else {
        u8CollisionTime = MASTER_TIME_OUT;
    }
    return u8CollisionTime;
}

/*Check Bus */
void CheckBus() {
    /*check the bus flag*/
    uint8_t state;
    if (bitIsClear(gu8CommunicationFlags, BUS_FLAG)) {
        return;
    }

    state = SREG;
    SREG &= ~(1 << 7);
    __disable_interrupt();
    if (bitIsClear(gu8CommunicationFlags, RECEIVETIMEOUT_FLAG)) {
        /*check receive time out*/
        if ((RECEIVE_TIME_OUT + gu32LastByteReceivedTime) < getSystemTick()) {
            bitSet(gu8CommunicationFlags, RECEIVETIMEOUT_FLAG);
        }
    } else {
        if (((gu8BackOffTime) + gu32LastByteReceivedTime) < (getSystemTick())) {
            /*the bus is ready*/
            /*reset the flag of the bus busy*/
            bitClear(gu8CommunicationFlags, BUS_FLAG);
        }
    }
    SREG = state;
    __enable_interrupt();
}

/*encapsulate*/
void Encapsulate(sFrame * psFrame) {
    if ((psFrame->u8ByteCount + startbyte) <= COMM_BUFFER_LENGTH) {
        gu8TransmissionBuffer[Address] = psFrame->u8Address; // index 0  
        gu8TransmissionBuffer[bytecount] = psFrame->u8ByteCount + startbyte + 1; //index 2 = data length + (3)
        for (uint8_t i = 0; i < psFrame->u8ByteCount; i++) {
            gu8TransmissionBuffer[startbyte + (i)] = (psFrame->u8Data[i]);
        }
        /*set LRC value*/
        gu8TransmissionBuffer[gu8TransmissionBuffer[bytecount] - 1] = FrameLRC(gu8TransmissionBuffer, gu8TransmissionBuffer[bytecount] - 1);
    }
}

/*De-capsulate*/
void Decapsulate(sFrame * psFrame) {
    psFrame->u8Address = gu8ReceiveBuffer[Address];
    psFrame->u8ByteCount = gu8ReceiveBuffer[bytecount] - startbyte - 1;
    for (uint8_t i = 0; i < psFrame->u8ByteCount; i++) {
        psFrame->u8Data[i] = gu8ReceiveBuffer[i + startbyte];
    }
}

/*LRC Check*/
uint8_t FrameLRC(volatile uint8_t *buf, uint8_t u8BufferLengh) {
    uint8_t u8temp = 0;
    for (uint8_t i = 0; i < u8BufferLengh; i++) {
        u8temp ^= buf[i];
    }
    u8temp &= 0xFF;

    return u8temp;
}

void removeBuffer(volatile uint8_t *buf, uint8_t u8length) {
    for (int i = 0; i < u8length; i++) {
        buf[i] = 0x00;
    }
}

void removeFrame(sFrame * psFrame) {
    psFrame->u8Address = 0x00;
    psFrame->u8ByteCount = 0x00;
}

void NetworkFSM() {

    switch (geNetworkFSM) {

        case NET_CHECK_CLIENT:
            if (bitIsClear(gu8CommunicationFlags, NETWORK_FLAG)) {
                geNetworkFSM = NET_CHECK_CLIENT;
            } else {
                geNetworkFSM = NET_NEW_FRAME;
            }
            break;

        case NET_NEW_FRAME:
            if (getTLV(&gsNetWorkTLV, &gsNetworkFrame)) {
                /*reset a buffer receive a new frame */
                bitClear(gu8CommunicationFlags, NETWORK_FLAG);
                /*net flag is true*/
                geNetworkFSM = NET_FRAME_EXECUATION;

            } else {
                geNetworkFSM = NET_CHECK_CLIENT;
            }
            break;

        case NET_FRAME_EXECUATION:
            if (gpFcomHostCallback()) {
                bitClear(gu8NetworkFlags, HOST_FLAG);
                geNetworkFSM = NET_CHECK_CLIENT;
            }
            break;

        default:
            geNetworkFSM = NET_CHECK_CLIENT;
            break;
    }
}


/*Application interface function*/

/*start transmission*/
void StartTransmission() {
    /*set send timer from this  */
    sysSetTimer(&gsSendTimeOut, getSystemTick());
    bitSet(gu8CommunicationFlags, SENDREQUEST_FLAG);
}

/*open communication*/
uint8_t IsCommunicationOpen() {
    if (bitIsClear(gu8CommunicationFlags, SENDREQUEST_FLAG)) {
        return true;
    }
    return false;
}

/*low Level communication*/
void commDriver() {
    CheckBus();
    ReceiveFSM(&gsReceiveFrame);
    TransmissionFSM(&gsTransmissionFrame);
    NetworkFSM();
}


#endif
//second

#endif

