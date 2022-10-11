#include "../../inc/mega.h"
#if MEM_MODULE 

#define  MEM_AMODE_FLAG (9)
#define  MEM_ATYPE_FLAG (8)
#define  MEM_ASEND_FLAG (7)
#define  MEM_DSEND_FLAG (6)

/*State*/

#define  MEM_LOAD_START_IDLE        state_00
#define  MEM_LOAD_IDLE              state_01
#define  MEM_LOAD_START             state_02 
#define  MEM_LOAD_ADDRESS           state_03
#define  MEM_READ_BYTE              state_04 

#define  MEM_SAVE_START_IDLE        state_00
#define  MEM_SAVE_IDLE              state_02
#define  MEM_SAVE_START             state_03 
#define  MEM_SAVE_WRITE             state_04 
#define  MEM_SAVE_READ              state_05


#define  MEM_LOAD_MASK   0x0038
#define  MEM_SAVE_MASK   0x0007

/*define state*/
volatile uint16_t gu8i2cMemByteOperation;
volatile uint8_t gu8Memindex;
uint8_t gu8MemByte;

void i2cMemInit(stI2cMemDis_t * stI2cMem, uint8_t * u8Data, uint8_t u8DataLength, uint8_t u8BaseAddress) {
    I2cInit();
    stI2cMem->u8BaseAddress = u8BaseAddress;
    stI2cMem->u8Data = u8Data;
    stI2cMem->u8DataLength = u8DataLength;
    gu8i2cMemByteOperation = 0x00;
    gu8Memindex = 0;
    gu8MemByte = 0;
}

uint8_t Mem8BitAddress(stI2cMemDis_t * stI2cMem, uint8_t u8Address) {
    uint8_t u8memEnd;
    gu8Memindex = 0;
    if (stI2cMem->u8DataLength == 0) {
        return (0);
    }
    u8memEnd = u8Address + stI2cMem->u8DataLength;
    if (u8memEnd > 0xFF) {
        return (0);
    }
    stI2cMem->u8FirstAddress = 0x00;
    stI2cMem->u8SecondAddress = u8Address;
    bitClear(gu8i2cMemByteOperation, MEM_AMODE_FLAG);
    return (1);
}

uint8_t Mem16BitAddress(stI2cMemDis_t * stI2cMem, uint16_t u16Address, uint8_t u8MemSize) {
    uint8_t u8memEnd;
    gu8Memindex = 0;

    if (stI2cMem->u8DataLength == 0) {
        return (0);
    }
    u8memEnd = u16Address + stI2cMem->u8DataLength;
    switch (u8MemSize) {
        case MEM_SIZE_32K:
            if (u8memEnd > 0x0FFF) {
                return (0);
            }
            break;
        case MEM_SIZE_64K:
            if (u8memEnd > 0x1FFF) {
                return (0);
            }
            break;
        case MEM_SIZE_128K:
            if (u8memEnd > 0x3FFF) {
                return (0);
            }
            break;
        case MEM_SIZE_256K:
            if (u8memEnd > 0x7FFF) {
                return (0);
            }
            break;
    }
    stI2cMem->u8FirstAddress = u16Address & 0x00FF;
    stI2cMem->u8SecondAddress = ((u16Address & 0xFF00) >> 8);
    bitSet(gu8i2cMemByteOperation, MEM_AMODE_FLAG);
    return (1);
}

uint8_t i2cMemSave(stI2cMemDis_t *stI2cMem) {
    uint8_t u8StartState;
    switch (gu8i2cMemByteOperation & MEM_SAVE_MASK) {
        case MEM_SAVE_START_IDLE:
            if (i2cIsReady()) {
                i2cBusy();
                bitsValue(gu8i2cMemByteOperation, MEM_SAVE_IDLE, MEM_SAVE_MASK);
            }
            break;
        case MEM_SAVE_IDLE:
            stI2cMem->u8BaseAddress &= ~(0x01); /*write address*/
            gu8MemByte = stI2cMem->u8SecondAddress; /*load lsb in size 2k and load MSB in size > 2k*/
            bitClear(gu8i2cMemByteOperation, MEM_ASEND_FLAG);
            bitClear(gu8i2cMemByteOperation, MEM_ATYPE_FLAG);
            bitClear(gu8i2cMemByteOperation, MEM_DSEND_FLAG);
            bitsValue(gu8i2cMemByteOperation, MEM_SAVE_START, MEM_SAVE_MASK);
            break;
        case MEM_SAVE_START:
            u8StartState = i2cStart(stI2cMem->u8BaseAddress);
            if (u8StartState != I2C_STATE_IDLE) {
                if (u8StartState == I2C_STATE_ADD_ACK) {
                    if (bitIsSet(gu8i2cMemByteOperation, MEM_ATYPE_FLAG)) {
                        i2cReceiveStop();
                        bitsValue(gu8i2cMemByteOperation, MEM_SAVE_READ, MEM_SAVE_MASK);
                    } else {
                        bitsValue(gu8i2cMemByteOperation, MEM_SAVE_WRITE, MEM_SAVE_MASK);
                    }
                } else if (u8StartState == I2C_STATE_ADD_NACK) {
                    /*re-start*/
                    i2cHwStop();
                    i2cStop();
                }
            }
            break;
        case MEM_SAVE_WRITE:
            u8StartState = i2cSendByte(gu8MemByte);
            if (u8StartState != I2C_STATE_IDLE) {
                if (u8StartState == I2C_STATE_TX_DATA_ACK) {
                    if (bitIsClear(gu8i2cMemByteOperation, MEM_AMODE_FLAG)) {
                        if (bitIsClear(gu8i2cMemByteOperation, MEM_DSEND_FLAG)) {
                            gu8MemByte = stI2cMem->u8Data[gu8Memindex];
                            i2cLoadnewByte();
                            bitSet(gu8i2cMemByteOperation, MEM_DSEND_FLAG);
                        } else {
                            i2cHwStop();
                            i2cStop();
                            bitSet(gu8i2cMemByteOperation, MEM_ATYPE_FLAG);
                            bitClear(gu8i2cMemByteOperation, MEM_DSEND_FLAG);
                            bitClear(gu8i2cMemByteOperation, MEM_ASEND_FLAG);
                            stI2cMem->u8BaseAddress &= ~(0x01);
                            gu8MemByte = stI2cMem->u8SecondAddress;
                            bitsValue(gu8i2cMemByteOperation, MEM_SAVE_START, MEM_SAVE_MASK);
                        }
                    } else {
                        /*2 checks send address*/
                        if (bitIsSet(gu8i2cMemByteOperation, MEM_ASEND_FLAG)) {
                            if (bitIsClear(gu8i2cMemByteOperation, MEM_DSEND_FLAG)) {
                                gu8MemByte = stI2cMem->u8Data[gu8Memindex];
                                i2cLoadnewByte();
                                bitSet(gu8i2cMemByteOperation, MEM_DSEND_FLAG);
                            } else {
                                i2cHwStop();
                                i2cStop();
                                bitSet(gu8i2cMemByteOperation, MEM_ATYPE_FLAG);
                                bitClear(gu8i2cMemByteOperation, MEM_DSEND_FLAG);
                                bitClear(gu8i2cMemByteOperation, MEM_ASEND_FLAG);
                                stI2cMem->u8BaseAddress &= ~(0x01);
                                gu8MemByte = stI2cMem->u8SecondAddress;
                                bitsValue(gu8i2cMemByteOperation, MEM_SAVE_START, MEM_SAVE_MASK);
                            }
                        } else {
                            gu8MemByte = stI2cMem->u8FirstAddress;
                            i2cLoadnewByte();
                            bitSet(gu8i2cMemByteOperation, MEM_ASEND_FLAG);
                        }
                    }
                } else if (u8StartState == I2C_STATE_TX_DATA_NACK) {
                    i2cHwStop();
                    i2cStop();
                    bitsValue(gu8i2cMemByteOperation, MEM_SAVE_IDLE, MEM_SAVE_MASK);
                } else if (u8StartState == I2C_STATE_ARBIT) {
                    i2cHwStop();
                    i2cStop();
                    bitsValue(gu8i2cMemByteOperation, MEM_SAVE_IDLE, MEM_SAVE_MASK);
                }
            }
            break;
        case MEM_SAVE_READ:
            if (bitIsSet(gu8i2cMemByteOperation, MEM_DSEND_FLAG)) {
                u8StartState = i2cReceiveByte(&gu8MemByte);
                if (u8StartState != I2C_STATE_IDLE) {
                    if (u8StartState == I2C_STATE_RX_DATA_ACK) {
                        _NOP();
                    } else if (u8StartState == I2C_STATE_RX_DATA_NACK) {
                        //i2cStop();
                        /*check*/
                        if (gu8Memindex < stI2cMem->u8DataLength - 1) {
                            /*check the byte*/
                            if (stI2cMem->u8Data[gu8Memindex] == gu8MemByte) {
                                /*write the next byte in next address*/
                                gu8Memindex++;
                                if (bitIsClear(gu8i2cMemByteOperation, MEM_AMODE_FLAG)) {
                                    stI2cMem->u8SecondAddress++;
                                } else {
                                    if (stI2cMem->u8FirstAddress != 255) {
                                        stI2cMem->u8FirstAddress++;
                                    } else {
                                        stI2cMem->u8FirstAddress = 0;
                                        stI2cMem->u8SecondAddress++;
                                    }
                                }
                                bitsValue(gu8i2cMemByteOperation, MEM_SAVE_IDLE, MEM_SAVE_MASK);
                            } else {
                                gu8Memindex = 0;
                                i2cReady();
                                i2cStop();
                                bitsValue(gu8i2cMemByteOperation, MEM_SAVE_START_IDLE, MEM_SAVE_MASK);
                                bitsValue(gu8i2cMemByteOperation, MEM_LOAD_START_IDLE << 3, MEM_LOAD_MASK);
                                return (1);
                            }
                        } else {
                            i2cStop();
                            i2cReady();
                            gu8Memindex = 0;
                            i2cReceiveClear();
                            bitsValue(gu8i2cMemByteOperation, MEM_SAVE_START_IDLE, MEM_SAVE_MASK);
                            return (1);
                        }
                    }

                }
            } else {
                /*write byte*/
                u8StartState = i2cSendByte(gu8MemByte);
                if (u8StartState != I2C_STATE_IDLE) {
                    if (u8StartState == I2C_STATE_TX_DATA_ACK) {
                        if (bitIsClear(gu8i2cMemByteOperation, MEM_AMODE_FLAG)) {
                            /*go to start*/
                            stI2cMem->u8BaseAddress |= (0x01);
                            bitsValue(gu8i2cMemByteOperation, MEM_SAVE_START, MEM_SAVE_MASK);
                            bitSet(gu8i2cMemByteOperation, MEM_DSEND_FLAG);
                        } else {
                            /*2 checks send address*/
                            if (bitIsSet(gu8i2cMemByteOperation, MEM_ASEND_FLAG)) {
                                /*go to start*/
                                stI2cMem->u8BaseAddress |= (0x01);
                                bitsValue(gu8i2cMemByteOperation, MEM_SAVE_START, MEM_SAVE_MASK);
                                bitSet(gu8i2cMemByteOperation, MEM_DSEND_FLAG);
                            } else {
                                gu8MemByte = stI2cMem->u8FirstAddress;
                                i2cLoadnewByte();
                                bitSet(gu8i2cMemByteOperation, MEM_ASEND_FLAG);
                            }
                        }
                    } else if (u8StartState == I2C_STATE_TX_DATA_NACK) {
                        i2cHwStop();
                        i2cStop();
                        bitsValue(gu8i2cMemByteOperation, MEM_SAVE_START_IDLE, MEM_SAVE_MASK);
                    } else if (u8StartState == I2C_STATE_ARBIT) {
                        i2cHwStop();
                        i2cStop();
                        bitsValue(gu8i2cMemByteOperation, MEM_SAVE_START_IDLE, MEM_SAVE_MASK);
                    }
                }

            }
            break;
        default:
            i2cReceiveClear();
            i2cHwStop();
            i2cStop();
            i2cReady();
            bitsValue(gu8i2cMemByteOperation, MEM_SAVE_START_IDLE, MEM_SAVE_MASK);
            bitsValue(gu8i2cMemByteOperation, MEM_LOAD_START_IDLE << 3, MEM_LOAD_MASK);
            break;
    }
    return (0);
}

uint8_t i2cMemLoad(stI2cMemDis_t * stI2cMem) {
    uint8_t u8StartState;
    switch ((gu8i2cMemByteOperation & MEM_LOAD_MASK) >> 3) {
        case MEM_LOAD_START_IDLE:
            if (i2cIsReady()) {
                i2cBusy();
                bitsValue(gu8i2cMemByteOperation, (MEM_LOAD_IDLE << 3), MEM_LOAD_MASK);
            }
            break;
        case MEM_LOAD_IDLE:

            gu8Memindex = 0;
            if (stI2cMem->u8DataLength == 1) {
                i2cReceiveStop();
            } else {
                i2cReceiveClear();
            }
            stI2cMem->u8BaseAddress &= ~(0x01); /*write address*/
            gu8MemByte = stI2cMem->u8SecondAddress; /*load lsb in size 2k and load MSB in size > 2k*/
            bitClear(gu8i2cMemByteOperation, MEM_ASEND_FLAG);
            bitClear(gu8i2cMemByteOperation, MEM_ATYPE_FLAG);
            bitClear(gu8i2cMemByteOperation, MEM_DSEND_FLAG);
            bitsValue(gu8i2cMemByteOperation, (MEM_LOAD_START << 3), MEM_LOAD_MASK);

            break;
        case MEM_LOAD_START:
            u8StartState = i2cStart(stI2cMem->u8BaseAddress);
            if (u8StartState != I2C_STATE_IDLE) {
                if (u8StartState == I2C_STATE_ADD_ACK) {
                    if (bitIsSet(gu8i2cMemByteOperation, MEM_ATYPE_FLAG)) {
                        bitClear(gu8i2cMemByteOperation, MEM_ATYPE_FLAG);
                        bitsValue(gu8i2cMemByteOperation, (MEM_READ_BYTE << 3), MEM_LOAD_MASK);
                    } else {
                        bitsValue(gu8i2cMemByteOperation, (MEM_LOAD_ADDRESS << 3), MEM_LOAD_MASK);
                    }
                } else if (u8StartState == I2C_STATE_ADD_NACK) {
                    /*re-start*/
                    i2cHwStop();
                    //i2cStop();
                    i2cReady();
                    bitsValue(gu8i2cMemByteOperation, (MEM_LOAD_START_IDLE << 3), MEM_LOAD_MASK);
                }
            }
            break;
        case MEM_LOAD_ADDRESS:
            /*send address*/
            u8StartState = i2cSendByte(gu8MemByte);
            if (u8StartState != I2C_STATE_IDLE) {
                if (u8StartState == I2C_STATE_TX_DATA_ACK) {
                    if (bitIsSet(gu8i2cMemByteOperation, MEM_AMODE_FLAG)) {
                        if (bitIsClear(gu8i2cMemByteOperation, MEM_ASEND_FLAG)) {
                            gu8MemByte = stI2cMem->u8FirstAddress;
                            i2cLoadnewByte();
                            bitSet(gu8i2cMemByteOperation, MEM_ASEND_FLAG);
                        } else {
                            stI2cMem->u8BaseAddress |= (0x01);
                            bitClear(gu8i2cMemByteOperation, MEM_ASEND_FLAG);
                            bitSet(gu8i2cMemByteOperation, MEM_ATYPE_FLAG);
                            bitsValue(gu8i2cMemByteOperation, MEM_LOAD_START << 3, MEM_LOAD_MASK);
                        }
                    } else {
                        stI2cMem->u8BaseAddress |= (0x01);
                        bitSet(gu8i2cMemByteOperation, MEM_ATYPE_FLAG);
                        bitsValue(gu8i2cMemByteOperation, MEM_LOAD_START << 3, MEM_LOAD_MASK);
                    }
                } else if (u8StartState == I2C_STATE_TX_DATA_NACK) {
                    i2cHwStop();
                    i2cReady();
                    i2cStop();
                    bitsValue(gu8i2cMemByteOperation, MEM_LOAD_START_IDLE << 3, MEM_LOAD_MASK);
                    return (1);
                } else if (u8StartState == I2C_STATE_ARBIT) {
                    i2cHwStop();
                    i2cStop();
                    i2cReady();
                    bitsValue(gu8i2cMemByteOperation, MEM_LOAD_START_IDLE << 3, MEM_LOAD_MASK);
                    return (1);
                }
            }
            break;
        case MEM_READ_BYTE:
            u8StartState = i2cReceiveByte(&gu8MemByte);
            if (u8StartState != I2C_STATE_IDLE) {
                if (u8StartState == I2C_STATE_RX_DATA_ACK) {
                    stI2cMem->u8Data[gu8Memindex++] = gu8MemByte;
                    if (gu8Memindex < stI2cMem->u8DataLength - 1) {
                        i2cReceiveNewByte();
                    } else {
                        gu8Memindex = 0;
                        i2cReceiveStop();
                    }
                } else if (u8StartState == I2C_STATE_RX_DATA_NACK) {
                    i2cStop();
                    gu8Memindex = 0;
                    i2cReady();
                    stI2cMem->u8Data[stI2cMem->u8DataLength - 1] = gu8MemByte;
                    bitsValue(gu8i2cMemByteOperation, MEM_LOAD_START_IDLE << 3, MEM_LOAD_MASK);
                    return (1);
                }
            }
            break;
        default:
            i2cHwStop();
            i2cStop();
            i2cReady();
            gu8Memindex = 0;
            bitsValue(gu8i2cMemByteOperation, MEM_LOAD_START_IDLE << 3, MEM_LOAD_MASK);
            break;

    }
    return (0);
}
#endif