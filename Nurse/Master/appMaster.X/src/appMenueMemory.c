


#include <stdint.h>

#include "../inc/appMenuMemory.h"

#if APP_MENUE == 1

#define    APP_MENU_MEM_MAX_DIGITS       (3)
#define    APP_MENU_MEM_MAX_VALUE       (129)
#define    APP_MEM_DATA_BASEADDRESS    (0x0002)
#define    APP_BASE_ADDRESS              (0xA0)
#define    NUMBER_OF_BYTE               (3)
#define   BASEPOINTLENGTH   10
#define   STATUS_IDLE       0x00


volatile uint8_t gu8memStartIndex;
volatile uint8_t gu8MAXRooms;
volatile uint8_t gu8MAXBads;
volatile uint8_t gu8RoomIndex;
uint8_t gu8ErrorCode;
BasePoint_t gsCurrentDataBasePoint = {0};
stExEEPROM_t gsEEPROMPoints;

void appEraseAllDataEvents();
void appMenueMemEvents(uint8_t u8Index);
uint8_t appMEMDataValid(BasePoint_t *baseP, uint8_t Index, uint8_t type);
uint8_t appMemConfig(const char *Lable, uint8_t Index, uint8_t type);
uint16_t appMemAddress(uint8_t index);
uint8_t appMemEraseData(uint8_t uIndex);
uint8_t appMemErase(uint16_t address, uint8_t u8max);

void appMemInit() {
    uint8_t BaseAddress, buf;
    for (uint8_t i = 0; i < 2; i++) {
        BaseAddress = APP_MEM_DATA_BASEADDRESS + i;
        exEEPROMInit(&gsEEPROMPoints, APP_BASE_ADDRESS, (uint16_t) BaseAddress, &buf, 1, EEPROM_SIZE_64K);
        while (exEEPROMLoad(&gsEEPROMPoints) == 0);
        if (i == 0) {
            gu8MAXRooms = buf;
        } else {
            gu8MAXBads = buf;
        }
    }
    gu8RoomIndex = 0;
    gu8memStartIndex = 0;
    gu8ErrorCode = 0;


}

uint8_t appMemConfig(const char *Lable, uint8_t Index, uint8_t type) {

    char s1[3];
    char s2[3];
    char s3[3];
    switch (gu8appMenueState) {
        case 0:
            gu8memStartIndex = 0;
            /*address calucations*/
            if (appMemLoad(&gsCurrentDataBasePoint, Index, type)) {
                lcdClear();
                lcdwrite(0, 0, Lable);
                if (Index < 2) {
                    sprintf(s1, "%d", gsCurrentDataBasePoint.index);
                    lcdwrite(1, 0, s1);
                } else {
                    uNumberToString(s2, gsCurrentDataBasePoint.pAddressP);
                    lcdwrite(1, 0, s2);
                    uNumberToString(s2, gsCurrentDataBasePoint.pID);
                    lcdwrite(1, 6, s2);
                    if (bitIsSet(gu8MnueFlags, APP_MENU_NODATA_FLAG)) {
                        uNumberToString(s2, gsCurrentDataBasePoint.pAddressR);
                        lcdwrite(1, 12, s2);
                    } else {
                        uNumberToString(s2, gsCurrentDataBasePoint.pAddressD);
                        lcdwrite(1, 12, s2);
                    }
                }
                bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
                (gu8appMenueState = 1);
            }
            break;
        case 1:

            appMenueMemEvents(Index);
            keypadEventSet(0);
            if (appMenuReadEvents() == 0x01) {
                appMenuClearEvent();
                appMenueCloseEvent();
                bitSet(gu8MnueFlags, APP_MENU_CENCEL);
                gu8appMenueState = 0;
                return (1);
            } else if (appMenuReadEvents() == 0x02) {
                if (type) {
                    getlcdData(s1, 1, 0);
                    getlcdData(s2, 1, 5);
                    getlcdData(s3, 1, 10);
                    gsCurrentDataBasePoint.pAddressP = uStringToNumber(s1);
                    gsCurrentDataBasePoint.Date = rtcGetCurrentTime();
                    gsCurrentDataBasePoint.index = gu8RoomIndex;
                    gsCurrentDataBasePoint.Status = 128;
                    gsCurrentDataBasePoint.pID = uStringToNumber(s2);
                    if (bitClear(gu8MnueFlags, APP_MENU_NODATA_FLAG)) {
                        gsCurrentDataBasePoint.pAddressD = uStringToNumber(s3);
                        gsCurrentDataBasePoint.pAddressR = gsCurrentDataBasePoint.pAddressP;
                    } else {
                        gsCurrentDataBasePoint.pAddressR = uStringToNumber(s3);
                        gsCurrentDataBasePoint.pAddressD = 128;
                    }
                } else {
                    getlcdData(s1, 1, 0);
                    gsCurrentDataBasePoint.index = uStringToNumber(s1);
                }

                if (appMemStore(&gsCurrentDataBasePoint, Index, type)) {
                    lcdClear();
                    switch (gu8ErrorCode) {
                        case 0x00:
                        case 0x04:
                            appMenuClearEvent();
                            appMenueCloseEvent();
                            gu8appMenueState = 0;
                            return (1);
                            break;
                        case 0x01:
                            lcdPrint(0, LCD_TXET_CENTER, "Undefined Max");
                            break;
                        case 0x02:
                            lcdPrint(0, LCD_TXET_CENTER, "Invalid Address");
                            break;
                        case 0x03:
                            lcdPrint(0, LCD_TXET_CENTER, "Address Blocked");
                            break;
                        case 0x05:
                            lcdPrint(0, LCD_TXET_CENTER, "Invalid Max");
                            break;

                    }
                    lcdNoBlink();
                    lcdPrint(1, LCD_TXET_CENTER, "Please Try Again");
                    bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
                    appMenuClearEvent();
                    gu8appMenueState = 2;
                }
            }

            break;
        case 2:
            if (appMenuIsLCDReady()) {
                appMenueMemEvents(Index);
                keypadEventSet(0);
                if ((appMenuReadEvents() == 0x01) || (appMenuReadEvents() == 0x02)) {
                    appMenuClearEvent();
                    appMenueCloseEvent();
                    gu8ErrorCode = 0x00;
                    gu8appMenueState = 0;
                    return (1);
                }
            }
            break;
    }


    return (0);

}

uint8_t appMemMaxRooms() {
    bitClear(gu8MnueFlags, APP_MENU_NODATA_FLAG);
    if (appMemConfig("Set Max Rooms", 0, 0)) {
        gu8MAXRooms = gsCurrentDataBasePoint.index;
        return (1);
    }
    return (0);
}

uint8_t appMemMaxBads() {
    bitSet(gu8MnueFlags, APP_MENU_NODATA_FLAG);
    if (appMemConfig("Set Max Bads", 1, 0)) {
        gu8MAXBads = gsCurrentDataBasePoint.index;
        return (1);
    }
    return (0);
}

uint8_t appMemBads() {
    char s[16];
    bitSet(gu8MnueFlags, APP_MENU_NODATA_FLAG);
    sprintf(s, "BA%d   ID%d    RA%d", gu8RoomIndex + 1, gu8RoomIndex + 1, gu8RoomIndex + 1);
    if (appMemConfig(s, 2, 1)) {
        if (bitIsSet(gu8MnueFlags, APP_MENU_CENCEL)) {
            bitClear(gu8MnueFlags, APP_MENU_CENCEL);
            return (1);
        }

        if (gu8RoomIndex < gu8MAXBads - 1) {
            if (gu8ErrorCode == 0x00 || gu8ErrorCode == 0x04)
                gu8RoomIndex++;
        } else {
            gu8RoomIndex = 0;
            return (1);
        }
    }
    return (0);
}

uint8_t appMemRooms() {
    char s[16];
    bitClear(gu8MnueFlags, APP_MENU_NODATA_FLAG);
    sprintf(s, "RA%d   ID%d   DA%d", gu8RoomIndex + 1, gu8RoomIndex + 1, gu8RoomIndex + 1);
    if (appMemConfig(s, 2, 1)) {
        if (bitIsSet(gu8MnueFlags, APP_MENU_CENCEL)) {
            bitClear(gu8MnueFlags, APP_MENU_CENCEL);
            return (1);
        }
        if (gu8RoomIndex < gu8MAXRooms - 1) {
            if (gu8ErrorCode == 0x00 || gu8ErrorCode == 0x04)
                gu8RoomIndex++;
        } else {
            gu8RoomIndex = 0;
            return (1);
        }

    }
    return (0);
}

void appMenueMemEvents(uint8_t u8Index) {
    uint8_t u8Event;
    uint8_t u8pos;
    uint8_t mined;


    u8pos = 0;

    u8Event = keypadEventRead(0);
    if (u8Event == KEYPAD_NOT_AN_EVENT)
        return;

    if (u8Event == KEYPAD01_PRESS(KEYPAD_SW_CENCEL)) {
        bitsValue(gu8MnueFlags, 0x01, APP_MENU_EVENT_RESPONS);
        return;
    }
    if (u8Event == KEYPAD01_PRESS(KEYPAD_SW_ENTER)) {
        bitsValue(gu8MnueFlags, 0x02, APP_MENU_EVENT_RESPONS);
        return;
    }

    if (u8Event == KEYPAD01_PRESS(KEYPAD_SW0)) {
        lcdwrite(1, gu8EventNumber, "0");
        if (gu8EventNumber < (gu8memStartIndex + APP_MENU_MEM_MAX_DIGITS) - 1) {
            lcdBlink(1, gu8EventNumber + 1);
            gu8EventNumber++;
        } else {
            gu8EventNumber = gu8memStartIndex;
            lcdBlink(1, gu8memStartIndex);
        }

        bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
        return;
    }


    if (u8Event == KEYPAD01_PRESS(KEYPAD_SW1)) {
        lcdwrite(1, gu8EventNumber, "1");
        if (gu8EventNumber < (gu8memStartIndex + APP_MENU_MEM_MAX_DIGITS) - 1) {
            lcdBlink(1, gu8EventNumber + 1);
            gu8EventNumber++;
        } else {
            gu8EventNumber = gu8memStartIndex;
            lcdBlink(1, gu8memStartIndex);
        }

        bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
        return;
    }


    if (u8Event == KEYPAD01_PRESS(KEYPAD_SW2)) {
        lcdwrite(1, gu8EventNumber, "2");
        if (gu8EventNumber < (gu8memStartIndex + APP_MENU_MEM_MAX_DIGITS) - 1) {
            lcdBlink(1, gu8EventNumber + 1);
            gu8EventNumber++;
        } else {
            gu8EventNumber = gu8memStartIndex;
            lcdBlink(1, gu8memStartIndex);
        }

        bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
        return;
    }


    if (u8Event == KEYPAD01_PRESS(KEYPAD_SW3)) {
        lcdwrite(1, gu8EventNumber, "3");
        if (gu8EventNumber < (gu8memStartIndex + APP_MENU_MEM_MAX_DIGITS) - 1) {
            lcdBlink(1, gu8EventNumber + 1);
            gu8EventNumber++;
        } else {
            gu8EventNumber = gu8memStartIndex;
            lcdBlink(1, gu8memStartIndex);
        }

        bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
        return;
    }


    if (u8Event == KEYPAD01_PRESS(KEYPAD_SW4)) {
        lcdwrite(1, gu8EventNumber, "4");
        if (gu8EventNumber < (gu8memStartIndex + APP_MENU_MEM_MAX_DIGITS) - 1) {
            lcdBlink(1, gu8EventNumber + 1);
            gu8EventNumber++;
        } else {
            gu8EventNumber = gu8memStartIndex;
            lcdBlink(1, gu8memStartIndex);
        }

        bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
        return;
    }


    if (u8Event == KEYPAD01_PRESS(KEYPAD_SW5)) {
        lcdwrite(1, gu8EventNumber, "5");
        if (gu8EventNumber < (gu8memStartIndex + APP_MENU_MEM_MAX_DIGITS) - 1) {
            lcdBlink(1, gu8EventNumber + 1);
            gu8EventNumber++;
        } else {
            gu8EventNumber = gu8memStartIndex;
            lcdBlink(1, gu8memStartIndex);
        }

        bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
        return;
    }


    if (u8Event == KEYPAD01_PRESS(KEYPAD_SW6)) {
        lcdwrite(1, gu8EventNumber, "6");
        if (gu8EventNumber < (gu8memStartIndex + APP_MENU_MEM_MAX_DIGITS) - 1) {
            lcdBlink(1, gu8EventNumber + 1);
            gu8EventNumber++;
        } else {
            gu8EventNumber = gu8memStartIndex;
            lcdBlink(1, gu8memStartIndex);
        }

        bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
        return;
    }


    if (u8Event == KEYPAD01_PRESS(KEYPAD_SW7)) {
        lcdwrite(1, gu8EventNumber, "7");
        if (gu8EventNumber < (gu8memStartIndex + APP_MENU_MEM_MAX_DIGITS) - 1) {
            lcdBlink(1, gu8EventNumber + 1);
            gu8EventNumber++;
        } else {
            gu8EventNumber = gu8memStartIndex;
            lcdBlink(1, gu8memStartIndex);
        }

        bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
        return;
    }


    if (u8Event == KEYPAD01_PRESS(KEYPAD_SW8)) {
        lcdwrite(1, gu8EventNumber, "8");
        if (gu8EventNumber < (gu8memStartIndex + APP_MENU_MEM_MAX_DIGITS) - 1) {
            lcdBlink(1, gu8EventNumber + 1);
            gu8EventNumber++;
        } else {
            gu8EventNumber = gu8memStartIndex;
            lcdBlink(1, gu8memStartIndex);
        }

        bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
        return;
    }


    if (u8Event == KEYPAD01_PRESS(KEYPAD_SW9)) {
        lcdwrite(1, gu8EventNumber, "9");
        if (gu8EventNumber < (gu8memStartIndex + APP_MENU_MEM_MAX_DIGITS) - 1) {
            lcdBlink(1, gu8EventNumber + 1);
            gu8EventNumber++;
        } else {
            gu8EventNumber = gu8memStartIndex;
            lcdBlink(1, gu8memStartIndex);
        }

        bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
        return;
    }

    if (u8Event == KEYPAD01_PRESS(KEYPAD_SW_F1)) {
        if (lcdIsCharEmpty(1, gu8EventNumber)) {
            if (gu8EventNumber != gu8memStartIndex) {
                lcdwrite(1, gu8EventNumber - 1, " ");
                lcdBlink(1, gu8EventNumber - 1);
                gu8EventNumber--;
            }
        } else {
            if (gu8EventNumber == (gu8memStartIndex + APP_MENU_MEM_MAX_DIGITS) - 1) {
                lcdwrite(1, gu8EventNumber, " ");
                lcdBlink(1, gu8EventNumber);
            } else {
                // get data from buffer
                lcdReplace(1, gu8EventNumber);
                lcdBlink(1, gu8EventNumber);
            }
        }
        bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
        return;
    }
    if (u8Event == KEYPAD01_PRESS(KEYPAD_SW_F2)) {

        gu8EventNumber++;
        if (lcdIsCharEmpty(1, gu8EventNumber) || gu8EventNumber == APP_MENU_MEM_MAX_DIGITS + gu8memStartIndex) {
            gu8EventNumber = gu8memStartIndex;
            lcdBlink(1, gu8EventNumber);

        } else {
            lcdBlink(1, gu8EventNumber);
        }
        bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
        return;
    }
    if (u8Event == KEYPAD01_PRESS(KEYPAD_SW_F3)) {

        u8pos = gu8memStartIndex;
        gu8EventNumber--;
        while (!lcdIsCharEmpty(1, u8pos)) {
            u8pos++;
            if (u8pos == (APP_MENU_MEM_MAX_DIGITS + gu8memStartIndex)) {
                break;
            }
        }
        if (gu8memStartIndex == 0)
            mined = 0xff;
        else
            mined = gu8memStartIndex - 1;

        if (gu8EventNumber == mined) {
            gu8EventNumber = u8pos;
            lcdBlink(1, gu8EventNumber);
        } else {
            lcdBlink(1, gu8EventNumber);
        }

        bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
        return;
    }

    if (u8Event == KEYPAD01_PRESS(KEYPAD_SW_MODE)) {
        if (u8Index == 2) {
            u8pos = gu8EventNumber + APP_MENU_MEM_MAX_DIGITS;
            if (u8pos < LCD_NUMBER_OF_BYTE - 1) {
                gu8memStartIndex += 6;
            } else {

                gu8memStartIndex = 0;
            }
            gu8EventNumber = gu8memStartIndex;
            lcdBlink(1, gu8memStartIndex);
            bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
        }
        return;
    }
}

void appEraseAllDataEvents() {
    uint8_t u8Event;

    u8Event = keypadEventRead(0);
    if (u8Event == KEYPAD_NOT_AN_EVENT)
        return;

    if (u8Event == KEYPAD01_PRESS(KEYPAD_SW1)) {
        gu8memStartIndex |= (1 << 0);
        return;
    }
    if (u8Event == KEYPAD01_PRESS(KEYPAD_SW2)) {
        gu8memStartIndex |= (1 << 1);
        return;
    }

    if (u8Event == KEYPAD01_PRESS(KEYPAD_SW3)) {
        gu8memStartIndex |= (1 << 2);

        return;
    }

    if (u8Event == KEYPAD01_PRESS(KEYPAD_SW_CENCEL)) {
        gu8memStartIndex = 0x05;

        return;
    }

}

void appMemCreateBasePonit(BasePoint_t *baseP, uint8_t index, uint8_t addressP, uint8_t addressR, uint8_t id, uint8_t status, time_t date) {
    baseP->index = index;
    baseP->pAddressP = addressP;
    baseP->Status = status;
    baseP->Date = date;
    baseP->pAddressR = addressR;
    baseP->pID = id;
}

uint8_t appMemStore(BasePoint_t *baseP, uint8_t Index, uint8_t type) {
    uint16_t address;
    uint8_t length;

    if (bitIsClear(gu8MnueFlags, APP_MENU_DATA_FLAG)) {
        if (appMEMDataValid(baseP, Index, type)) {
            if (Index < 2) {
                address = (APP_MEM_DATA_BASEADDRESS + Index);
                length = 1;
            } else {
                address = APP_MEM_DATA_BASEADDRESS + Index + ((baseP->pAddressP - 1) * BASEPOINTLENGTH);
                length = BASEPOINTLENGTH;
            }
            exEEPROMInit(&gsEEPROMPoints, APP_BASE_ADDRESS, address, (uint8_t *) baseP, length, EEPROM_SIZE_64K);
            bitSet(gu8MnueFlags, APP_MENU_DATA_FLAG);
            return (0);
        }
    }
    if (gu8ErrorCode != 0x00) {
        return (1);
    } else {
        if (exEEPROMMemSave(&gsEEPROMPoints)) {
            bitClear(gu8MnueFlags, APP_MENU_DATA_FLAG);
            gu8ErrorCode = 0x00;
            return (1);
        }
        return (0);
    }
    return (0);
}

uint8_t appMEMDataValid(BasePoint_t *baseP, uint8_t Index, uint8_t type) {
    uint8_t Buff[10];
    uint8_t offset;
    uint8_t baseaddress;
    uint8_t length;

    (Index < 2) ? (length = 1) : (length = BASEPOINTLENGTH);
    if (Index == 2) {
        if (gu8MAXRooms < 128 && gu8MAXBads < 128 && gu8MAXRooms != 0 && gu8MAXBads != 0) {
            if (baseP->pAddressP > (gu8MAXBads + gu8MAXRooms)) {
                gu8ErrorCode = 0x02; /*invalid address*/
                return (1);
            }
        } else {
            gu8ErrorCode = 0x01; /*Undefined MAX VALUE*/
            return (1);
        }
    } else {
        if (baseP->index >= (128)) {
            gu8ErrorCode = 0x05; /*invalid max*/
            return (1);
        } else {
            gu8ErrorCode = 0x00;
            return (1);
        }
    }

    if (type) {
        /*save config*/
        baseaddress = APP_MEM_DATA_BASEADDRESS + Index;
        offset = (((baseP->pAddressP - 1) * BASEPOINTLENGTH) + 1);
        exEEPROMInit(&gsEEPROMPoints, APP_BASE_ADDRESS, (uint16_t) (baseaddress + offset), Buff, length, EEPROM_SIZE_64K);
        while (exEEPROMLoad(&gsEEPROMPoints) == 0);
        if (baseP->pAddressP == Buff[1] && baseP->index != Buff[0]) {
            /*blocked*/
            gu8ErrorCode = 0x03;
            return (1);
        } else if (baseP->pAddressP == Buff[1] && baseP->index == Buff[0]) {
            gu8ErrorCode = 0x04;
            return (1);
        } else {
            gu8ErrorCode = 0x00;
            return (1);
        }
        /*Init Mem*/
    }

    return (0);

}

uint8_t appMemLoad(BasePoint_t *baseP, uint8_t Index, uint8_t type) {
    uint8_t length;
    uint16_t address;

    if (bitIsClear(gu8MnueFlags, APP_MENU_DATA_FLAG)) {
        if (!type) {
            if (Index < 2) {
                address = (APP_MEM_DATA_BASEADDRESS + Index);
                length = 1;
            } else {
                if (gu8MAXRooms < 128 && gu8MAXBads < 128 && baseP->pAddressP < 128) {
                    address = APP_MEM_DATA_BASEADDRESS + Index + ((baseP->pAddressP - 1) * BASEPOINTLENGTH);
                    length = BASEPOINTLENGTH;
                } else {
                    gu8ErrorCode = 0x02;
                    return (1);
                }
            }
        } else {
            length = BASEPOINTLENGTH;
            address = APP_MEM_DATA_BASEADDRESS + ((gu8RoomIndex * BASEPOINTLENGTH) + Index);
        }
        exEEPROMInit(&gsEEPROMPoints, APP_BASE_ADDRESS, address, (uint8_t *) baseP, length, EEPROM_SIZE_64K);
        bitSet(gu8MnueFlags, APP_MENU_DATA_FLAG);
    }
    if (exEEPROMLoad(&gsEEPROMPoints)) {
        bitClear(gu8MnueFlags, APP_MENU_DATA_FLAG);
        return (1);
    }
    return (0);
}

uint8_t appMemResetData() {
    if (appMemEraseData(0)) {
        return (1);
    }
    return (0);
}

uint8_t appMemResetALLData() {
    if (appMemEraseData(1)) {
        return (1);
    }
    return (0);
}

uint8_t appMemEraseData(uint8_t uIndex) {
    switch (gu8appMenueState) {
        case 0:
            lcdPrint(0, LCD_TXET_CENTER, "Please Enter");
            lcdPrint(1, LCD_TXET_CENTER, "Confirmed keys");
            bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
            gu8appMenueState = 1;
            break;
        case 1:
            if (appMenuIsLCDReady()) {
                appEraseAllDataEvents();
                keypadEventSet(0);
                if (gu8memStartIndex == 0x07) {
                    if (appMemErase((APP_MEM_DATA_BASEADDRESS + 2), ((gu8MAXBads + gu8MAXRooms) * BASEPOINTLENGTH))) {
                        if (uIndex) {
                            gu8memStartIndex = 0;
                            gu8appMenueState = 0;
                            return (1);
                        } else {
                            gu8appMenueState = 2;
                        }
                    }
                } else if (gu8memStartIndex == 0x05) {
                    gu8memStartIndex = 0;
                    gu8appMenueState = 0;
                    return (1);
                }
            }
            break;
        case 2:
            return (1);
            break;
    }
    return (0);
}

uint8_t appMemErase(uint16_t address, uint8_t u8max) {
    uint8_t pre;
    char s[16];
    if (bitIsClear(gu8MnueFlags, APP_MENU_DATA_FLAG)) {
        gu8ErrorCode = 0x80;
        pre = map(gu8RoomIndex, 0, u8max, 0, 100);
        sprintf(s, "Removing     %d", pre);
        lcdwrite(0, 0, s);
        address = (APP_MEM_DATA_BASEADDRESS + 2) + gu8RoomIndex;
        exEEPROMInit(&gsEEPROMPoints, APP_BASE_ADDRESS, address, &gu8ErrorCode, 1, EEPROM_SIZE_64K);
        bitSet(gu8MnueFlags, APP_MENU_DATA_FLAG);
    } else {
        if (appMenuIsLCDReady()) {
            if (gu8RoomIndex < u8max) {
                if (exEEPROMMemSave(&gsEEPROMPoints)) {
                    updateProgressBar(gu8RoomIndex, u8max, 1);
                    gu8RoomIndex++;
                    bitSet(gu8MnueFlags, APP_MENU_LCD_UPDATE);
                    bitClear(gu8MnueFlags, APP_MENU_DATA_FLAG);
                }
            } else {
                gu8RoomIndex = 0;
                gu8ErrorCode = 0x00;
                bitClear(gu8MnueFlags, APP_MENU_DATA_FLAG);
                return (1);
            }
        }
    }
    return (0);

}



#endif