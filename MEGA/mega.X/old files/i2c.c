

#include <stdint-gcc.h>

#include "../../inc/mega.h"

#if I2C_MODULE


volatile uint8_t gu8I2cState;
volatile uint8_t gu8I2cAddress;
volatile uint8_t *gu8I2cSlaveBuffer;
volatile uint8_t gu8I2cLength;
volatile uint8_t gu8I2cIndex;
volatile uint8_t gu8BusyFlag;

#define  I2C_MTX_REQUSET_FLAG         (0)
#define  I2C_MTX_RET_FLAG             (1)
#define  I2C_MTX_ACK_FLAG             (2)
#define  I2C_MRX_REQUSET_FLAG         (3)
#define  I2C_MRX_ACK_FLAG             (4)
#define  I2C_MRX_RET_FLAG             (5)
#define  I2C_MRX_STOP_FLAG            (6)
#define  I2C_BUSY_FLAG                (7)


#define I2C_RX_STOP         (1)
#define I2C_RX_NEWBYTE      (0)

ISR(TWI_vect) {
    switch (i2cHwStatus()) {
        case I2C_START:
        case I2C_REPEAT_START:
            i2cHwSend(gu8I2cAddress);
            i2cHwCondition();
            break;
        case I2C_ARBITRATION:
            bitsValue(gu8I2cState, I2C_STATE_ARBIT, I2C_MASTER_MASK);
            i2cHwCondition();
            break;
            /*
             ****************************************************************
             *            Status Codes for Master Transmitter Mode          *
             **************************************************************** 
             */

        case I2C_MTX_ADR_ACK:
            /*disable interrupt*/
            bitsValue(gu8I2cState, I2C_STATE_ADD_ACK, I2C_MASTER_MASK);
            break;
        case I2C_MTX_ADR_NACK:
            /*disable interrupt*/
            bitsValue(gu8I2cState, I2C_STATE_ADD_NACK, I2C_MASTER_MASK);
            break;
        case I2C_MTX_DATA_ACK:
            bitSet(gu8I2cIndex, I2C_MTX_ACK_FLAG);
            bitsValue(gu8I2cState, I2C_STATE_TX_DATA_ACK, I2C_MASTER_MASK);
            break;
        case I2C_MTX_DATA_NACK:
            bitsValue(gu8I2cState, I2C_STATE_TX_DATA_NACK, I2C_MASTER_MASK);
            /*
             ****************************************************************
             *             Master Receive Mode              *
             **************************************************************** 
             */
            break;
        case I2C_MRX_ADR_ACK:

            bitsValue(gu8I2cState, I2C_STATE_ADD_ACK, I2C_MASTER_MASK);
            break;
        case I2C_MRX_ADR_NACK:
            bitsValue(gu8I2cState, I2C_STATE_ADD_NACK, I2C_MASTER_MASK);
            break;
        case I2C_MRX_DATA_ACK:
            bitSet(gu8I2cIndex, I2C_MRX_ACK_FLAG);
            bitsValue(gu8I2cState, I2C_STATE_RX_DATA_ACK, I2C_MASTER_MASK);

            break;
        case I2C_MRX_DATA_NACK:
            bitsValue(gu8I2cState, I2C_STATE_RX_DATA_NACK, I2C_MASTER_MASK);
            break;
            /*
             ****************************************************************
             *             SLAVE Transmitter Mode              *
             **************************************************************** 
             */

        case I2C_STX_SLA_R_ACK:
            gu8I2cIndex = 0;
        case I2C_STX_DATA_ACK:
            if (gu8I2cIndex < gu8I2cLength) {
                i2cHwSend(gu8I2cSlaveBuffer[gu8I2cIndex++]);
                bitsValue(gu8I2cState, I2C_SLAVE_STATE_TX_PROCESS, I2C_SLAVE_MASK);
            } else {
                //Error
                gu8I2cIndex = 0;
                bitsValue(gu8I2cState, I2C_SLAVE_STATE_TX_OUTSIDE, I2C_SLAVE_MASK);
            }
            i2cHwCondition();
            break;
        case I2C_STX_DATA_NACK:
            if (gu8I2cIndex == gu8I2cLength) {
                //Error
                bitsValue(gu8I2cState, I2C_SLAVE_STATE_TX_SUCESS, I2C_SLAVE_MASK);
            }
            i2cHwCondition();
            break;
        case I2C_STX_LAST_DATA_ACK:
        case I2C_STX_SLA_R_ACK_Arbitration:
            break;
            /*
             ****************************************************************
             *            Status Codes for SLAVE Receive Mode               *
             **************************************************************** 
             */
        case I2C_SRX_SLA_W_ACK:
        case I2C_SRX_GEN_ACK:
            gu8I2cIndex = 0;
            i2cHwACK(I2C_ACK);
            i2cHwCondition();
            break;
        case I2C_SRX_ADR_DATA_ACK:
        case I2C_SRX_GEN_DATA_ACK:
            //receive the data and store index
            if (gu8I2cIndex < gu8I2cLength) {
                gu8I2cSlaveBuffer[gu8I2cIndex++] = TWDR;
                bitsValue(gu8I2cState, I2C_SLAVE_RX_PORCESS, I2C_SLAVE_MASK);
            } else {
                gu8I2cIndex = 0;
                bitsValue(gu8I2cState, I2C_SLAVE_RX_OUTSIDE, I2C_SLAVE_MASK);
            }
            i2cHwCondition();
            break;
        case I2C_SRX_SLA_W_ACK_ARBITRATION:
        case I2C_SRX_GEN_ACK_ARBITRATION:
            break;
        case I2C_SRX_ADR_DATA_NACK:
        case I2C_SRX_GEN_DATA_NACK:
            bitsValue(gu8I2cState, I2C_SLAVE_DATA_NACK, I2C_SLAVE_MASK);
            i2cHwCondition();
            break;
        case I2C_SRX_STOP_RSTART:
            bitsValue(gu8I2cState, I2C_SLAVE_RX_STOP_RESTART, I2C_SLAVE_MASK);
            i2cHwCondition();
            break;
        default:
            break;
    }
}

/****************** Load new Byte******************************/
void i2cLoadnewByte() {
    bitSet(gu8I2cIndex, I2C_MTX_REQUSET_FLAG);
}

void i2cLoadClearByte() {
    bitClear(gu8I2cIndex, I2C_MTX_REQUSET_FLAG);
}

/****************** Receive Stop******************************/
void i2cReceiveStop() {
    bitClear(gu8I2cIndex, I2C_MRX_REQUSET_FLAG);
    bitSet(gu8I2cIndex, I2C_MRX_STOP_FLAG);
}

/****************** Receive new Byte******************************/
void i2cReceiveNewByte() {
    bitClear(gu8I2cIndex, I2C_MRX_STOP_FLAG);
    bitSet(gu8I2cIndex, I2C_MRX_REQUSET_FLAG);
}

/****************** Restart new Byte******************************/

/****************** Receive Byte******************************/
uint8_t i2cReceiveByte(uint8_t* u8pData) {
    switch ((gu8I2cState & I2C_MASTER_MASK)) {
        case I2C_STATE_IDLE:
            break;
        case I2C_STATE_ARBIT:
            bitsValue(gu8I2cState, I2C_STATE_IDLE, I2C_MASTER_MASK);
            return (I2C_STATE_ARBIT);
            break;
        case I2C_STATE_RX_DATA_ACK:
            /*read byte*/
            if (bitIsSet(gu8I2cIndex, I2C_MRX_REQUSET_FLAG) && bitIsClear(gu8I2cIndex, I2C_MRX_STOP_FLAG)) {
                i2cHwACK(I2C_ACK);
                i2cResetInterruptFlag();
                bitsValue(gu8I2cIndex, 0x00, 0x78);
                bitsValue(gu8I2cState, I2C_STATE_IDLE, I2C_MASTER_MASK);
            } else if (bitIsSet(gu8I2cIndex, I2C_MRX_STOP_FLAG) && bitIsClear(gu8I2cIndex, I2C_MRX_REQUSET_FLAG)) {
                i2cHwACK(I2C_NACK);
                i2cResetInterruptFlag();
                bitsValue(gu8I2cIndex, 0x00, 0x78);
                bitsValue(gu8I2cState, I2C_STATE_IDLE, I2C_MASTER_MASK);
            } else {
                if (bitIsSet(gu8I2cIndex, I2C_MRX_ACK_FLAG) && bitIsClear(gu8I2cIndex, I2C_MRX_RET_FLAG)) {
                    *(u8pData) = i2cHwReceive();
                    bitSet(gu8I2cIndex, I2C_MRX_RET_FLAG);
                    bitsValue(gu8I2cState, I2C_STATE_IDLE, I2C_MASTER_MASK);
                    return (I2C_STATE_RX_DATA_ACK);
                }
            }
            break;
        case I2C_STATE_ADD_ACK:
            if (bitIsSet(gu8I2cIndex, I2C_MRX_STOP_FLAG) && bitIsClear(gu8I2cIndex, I2C_MRX_REQUSET_FLAG))
                i2cHwACK(I2C_NACK);
            else
                i2cHwACK(I2C_ACK);
            i2cResetInterruptFlag();
            bitsValue(gu8I2cState, I2C_STATE_IDLE, I2C_MASTER_MASK);
            break;
        case I2C_STATE_ADD_NACK:
            i2cResetInterruptFlag();
            bitsValue(gu8I2cState, I2C_STATE_ADD_NACK, I2C_MASTER_MASK);
            return I2C_STATE_ADD_NACK;
            break;
        case I2C_STATE_RX_DATA_NACK:
            /*read last byte*/
            *(u8pData) = i2cHwReceive();
            i2cResetInterruptFlag();
            i2cHwStop();
            bitsValue(gu8I2cState, I2C_STATE_IDLE, I2C_MASTER_MASK);
            return (I2C_STATE_RX_DATA_NACK);
            break;
        default:
            bitsValue(gu8I2cState, I2C_STATE_IDLE, I2C_MASTER_MASK);
            break;
    }
    return (I2C_STATE_IDLE);
}

/****************** Load Address******************************/
void i2cHwAddress(uint8_t u8Address) {
    TWAR = (u8Address << 1);
    i2cHwACK(I2C_ACK);
    i2cHwCondition();
}

/******************Slave Transmission******************************/
uint8_t i2cSlaveTransmission(uint8_t *u8Data, uint8_t u8Length) {
    switch (gu8I2cState & (I2C_SLAVE_MASK)) {
        case I2C_SLAVE_STATE_IDLE:
            gu8I2cSlaveBuffer = u8Data; /*assign the address*/
            gu8I2cLength = u8Length;
            gu8I2cIndex = 0;
            bitsValue(gu8I2cState, I2C_SLAVE_WAIT, I2C_SLAVE_MASK);
            break;
        case I2C_SLAVE_WAIT:break;
        case I2C_SLAVE_STATE_TX_FAILE:
            bitsValue(gu8I2cState, I2C_SLAVE_STATE_IDLE, I2C_SLAVE_MASK);
            return (I2C_SLAVE_STATE_TX_FAILE);
            break;
        case I2C_SLAVE_STATE_TX_OUTSIDE:
            bitsValue(gu8I2cState, I2C_SLAVE_STATE_IDLE, I2C_SLAVE_MASK);
            return (I2C_SLAVE_STATE_TX_OUTSIDE);
            break;
        case I2C_SLAVE_STATE_TX_PROCESS:
            bitsValue(gu8I2cState, I2C_SLAVE_WAIT, I2C_SLAVE_MASK);
            break;
        case I2C_SLAVE_STATE_TX_SUCESS:
            bitsValue(gu8I2cState, I2C_SLAVE_STATE_IDLE, I2C_SLAVE_MASK);
            return (I2C_SLAVE_STATE_TX_SUCESS);
            break;
        case I2C_SLAVE_RX_STOP_RESTART:
            bitsValue(gu8I2cState, I2C_SLAVE_STATE_IDLE, I2C_SLAVE_MASK);
            return (I2C_SLAVE_RX_STOP_RESTART);
            break;
        default:
            bitsValue(gu8I2cState, I2C_SLAVE_STATE_IDLE, I2C_SLAVE_MASK);
            break;
    }
    return I2C_SLAVE_STATE_IDLE;
}

/****************** SLAVE Receive******************************/
uint8_t i2cSlaveReceive(uint8_t *u8Data, uint8_t u8Length) {
    switch (gu8I2cState & (I2C_SLAVE_MASK)) {
        case I2C_SLAVE_STATE_IDLE:
            gu8I2cSlaveBuffer = u8Data; /*assign the address*/
            gu8I2cLength = u8Length;
            gu8I2cIndex = 0;
            i2cHwACK(I2C_ACK);
            i2cHwCondition();
            bitsValue(gu8I2cState, I2C_SLAVE_WAIT, I2C_SLAVE_MASK);
            break;
        case I2C_SLAVE_WAIT:break;
        case I2C_SLAVE_RX_PORCESS:
            bitsValue(gu8I2cState, I2C_SLAVE_WAIT, I2C_SLAVE_MASK);
            break;
        case I2C_SLAVE_RX_OUTSIDE:
            bitsValue(gu8I2cState, I2C_SLAVE_STATE_IDLE, I2C_SLAVE_MASK);
            return (I2C_SLAVE_RX_OUTSIDE);
            break;
        case I2C_SLAVE_RX_STOP_RESTART:
            gu8I2cIndex = 0;
            bitsValue(gu8I2cState, I2C_SLAVE_STATE_IDLE, I2C_SLAVE_MASK);
            return (I2C_SLAVE_RX_STOP_RESTART);
            break;
        case I2C_SLAVE_DATA_NACK:
            bitsValue(gu8I2cState, I2C_SLAVE_STATE_IDLE, I2C_SLAVE_MASK);
            return (I2C_SLAVE_DATA_NACK);
        default:
            bitsValue(gu8I2cState, I2C_SLAVE_STATE_IDLE, I2C_SLAVE_MASK);
            break;
    }
    return I2C_SLAVE_STATE_IDLE;
}

/****************** GET STATUS CODE******************************/
uint8_t i2cGetStatusCode() {
    return (gu8I2cState);
}

/******************I2C INIT*****************************/
void I2cInit() {
    i2cSendByte(0xFF);
    if (I2C_PULLUP == I2C_INTERNAL_PULLUP) {
        digitalpinMode(I2C_SCL_PIN, MODE_INPUT_PULLUP);
        digitalpinMode(I2C_SDA_PIN, MODE_INPUT_PULLUP);
    }
    i2cHwInit();
    gu8I2cState = I2C_STATE_IDLE | I2C_SLAVE_STATE_IDLE;
    gu8I2cAddress = 0x00;
    gu8I2cIndex = 0;
    gu8I2cLength = 0;
    gu8I2cSlaveBuffer = NULL;
    i2cReady();
    gu8BusyFlag = 0;
}

/****************** START COMMUINCATION******************************/
uint8_t i2cStart(uint8_t u8Address) {
    switch ((gu8I2cState & I2C_MASTER_MASK)) {
        case I2C_STATE_IDLE:
            gu8I2cAddress = (u8Address);
            i2cHwStart();
            bitsValue(gu8I2cState, I2C_STATE_WAIT, I2C_MASTER_MASK);
            break;
        case I2C_STATE_ARBIT:
            bitsValue(gu8I2cState, I2C_STATE_IDLE, I2C_MASTER_MASK);
            break;
        case I2C_STATE_ADD_NACK:
            //clear the intrrupt
            i2cResetInterruptFlag();
            i2cHwStop();
            bitsValue(gu8I2cState, I2C_STATE_IDLE, I2C_MASTER_MASK);
            return (I2C_STATE_ADD_NACK);
            break;
        case I2C_STATE_ADD_ACK:
            bitSet(gu8I2cIndex, I2C_MTX_REQUSET_FLAG);
            bitClear(gu8I2cIndex, I2C_MTX_ACK_FLAG);
            bitsValue(gu8I2cState, I2C_STATE_ADD_ACK, I2C_MASTER_MASK);
            return (I2C_STATE_ADD_ACK);
            break;
        case I2C_STATE_WAIT:
            break;
        case I2C_STATE_TX_DATA_ACK:
        case I2C_STATE_TX_DATA_NACK:
        case I2C_STATE_RX_DATA_ACK:
        case I2C_STATE_RX_DATA_NACK:
            /*reset interrupt*/
            gu8I2cAddress = (u8Address);
            i2cHwStart();
            bitsValue(gu8I2cState, I2C_STATE_WAIT, I2C_MASTER_MASK);
            break;
        default:
            bitsValue(gu8I2cState, I2C_STATE_IDLE, I2C_MASTER_MASK);
            break;
    }

    return (I2C_STATE_IDLE);
}

/****************** SEND BYTE*****************************/
uint8_t i2cSendByte(uint8_t u8Byte) {
    switch ((gu8I2cState & I2C_MASTER_MASK)) {
        case I2C_STATE_IDLE:
            break;
        case I2C_STATE_ARBIT:
            bitsValue(gu8I2cState, I2C_STATE_IDLE, I2C_MASTER_MASK);
            return (I2C_STATE_ARBIT);
            break;
        case I2C_STATE_ADD_ACK:
        case I2C_STATE_TX_DATA_ACK:
            if (bitIsSet(gu8I2cIndex, I2C_MTX_REQUSET_FLAG)) {
                i2cHwSend(u8Byte);
                i2cResetInterruptFlag();
                bitsValue(gu8I2cIndex, 0x00, 0x07);
                bitsValue(gu8I2cState, I2C_STATE_IDLE, I2C_MASTER_MASK);
            } else {
                if (bitIsSet(gu8I2cIndex, I2C_MTX_ACK_FLAG)) {
                    if (bitIsClear(gu8I2cIndex, I2C_MTX_RET_FLAG)) {
                        //return Flag i'ts ok 
                        bitSet(gu8I2cIndex, I2C_MTX_RET_FLAG);
                        bitsValue(gu8I2cState, I2C_STATE_IDLE, I2C_MASTER_MASK);
                        return (I2C_STATE_TX_DATA_ACK);
                    }
                }
            }
            break;
        case I2C_STATE_ADD_NACK:
        case I2C_STATE_TX_DATA_NACK:
            i2cHwStop();
            bitsValue(gu8I2cIndex, 0x00, 0x07);
            bitsValue(gu8I2cState, I2C_STATE_IDLE, I2C_MASTER_MASK);
            return (I2C_STATE_TX_DATA_NACK);
            break;
        default:
            bitsValue(gu8I2cIndex, 0x00, 0x07);
            bitsValue(gu8I2cState, I2C_STATE_IDLE, I2C_MASTER_MASK);
            break;
    }
    return (I2C_STATE_IDLE);
}

void i2cStop() {
    bitsValue(gu8I2cIndex, 0x00, 0x80);
    bitsValue(gu8I2cState, I2C_STATE_IDLE, I2C_MASTER_MASK);

}

void i2cReceiveClear() {
    bitClear(gu8I2cIndex, I2C_MRX_REQUSET_FLAG);
    bitClear(gu8I2cIndex, I2C_MRX_STOP_FLAG);
}

void i2cBusy() {
    gu8BusyFlag = 1;
}

uint8_t i2cIsReady() {
    if (gu8BusyFlag) {
        return (0);
    } else {
        return (1);
    }
}

void i2cReady() {
    gu8BusyFlag = 0;
}
#endif
