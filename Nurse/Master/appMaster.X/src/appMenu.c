/*
 * File:   appMenu.c
 * Author: Hassan
 *
 * Created on July 25, 2022, 10:43 AM
 */


#include "../inc/appMenu.h"


#if APP_MENUE == 1


volatile uint8_t gu8appMenueState;
volatile uint8_t gu8MnueFlags;
uint8_t menuDummy();
void appProgressBarsetup();



MenuItem(Menu, NullItem, NullItem, NullItem, User, menuDummy, "0.SYSTEM MENU");
MenuItem(User, System, System, Menu, Time, menuDummy, "1.User");
MenuItem(System, User, User, Menu, NetWork, menuDummy, "2.System");

/*test 1*/
MenuItem(Time, Date, Reset, User, NullItem, appMenueTime, "1.Time");
MenuItem(Date, Report, Time, User, NullItem, appMenuDate, "2.Date");
MenuItem(Report, Summary, Date, User, NullItem, menuDummy, "3.Reports");
MenuItem(Summary, Reset, Report, User, NullItem, menuDummy, "4.Summary");
MenuItem(Reset, Time, Summary, User, NullItem, appMemEraseData, "5.Reset Data");


MenuItem(NetWork, Points, ResetSystem, System, TestNetWork, menuDummy, "1.Network");
MenuItem(Points, Zones, NetWork, System, NullItem, appMemCreatePoint, "2.Points");
MenuItem(Zones, ResetSystem, Points, System, NullItem, appMemCreateZone, "3.Zones");
MenuItem(ResetSystem, NetWork, Zones, System, ResetData, menuDummy, "4.Reset");
/*network*/
MenuItem(TestNetWork, RepNetwork, RepNetwork, NetWork, NullItem, appCommTestEvent, "1.Test Network ");
MenuItem(RepNetwork, TestNetWork, TestNetWork, NetWork, NullItem, appCommRepEvent, "2.Rep Network ");
/*Reset*/
MenuItem(ResetData, EraseData, EraseZone, ResetSystem, NullItem, appMemEraseData, "1.Reset Data");
MenuItem(EraseData, EraseZone, ResetData, ResetSystem, NullItem, appMemEraseConfig, "2.Erase Data");
MenuItem(EraseZone, ResetData, EraseData, ResetSystem, NullItem, appMemEraseZone, "3.Erase zone");

uint8_t menuDummy() {

    return (1);
}

void appMenu() {
    if (bitIsClear(gu8MnueFlags, APP_MENU_LCD_UPDATE)) {
        return;
    } else {
        if (lcdUpdate()) {
            bitClear(gu8MnueFlags, APP_MENU_LCD_UPDATE);
            return;
        }
    }
}

void appMenuInit() {
    gu8appMenueState = 0;
    gu8MnueFlags = 0x00;
    //    appProgressBarsetup();
}

void appStartMenu() {
    menuStartItem(&Menu);
}

uint8_t appMenuReadEvents() {
    return ((gu8MnueFlags & APP_MENU_EVENT_RESPONS));
}

uint8_t appMenuIsLCDReady() {
    if (bitIsSet(gu8MnueFlags, APP_MENU_LCD_UPDATE)) {
        return (0);
    } else {
        return (1);
    }
}

void appMenuClearEvent() {
    bitsValue(gu8MnueFlags, 0x00, APP_MENU_EVENT_RESPONS);
}

void appMenueCloseEvent() {
    gu8MnueFlags = 0x00;
}

void updateProgressBar(uint8_t count, uint8_t totalCount, uint8_t lineToPrintOn) {
    float factor;
    uint8_t percent;
    uint8_t number;
    uint8_t remainder;
    factor = totalCount / 80.0; //See note above!
    percent = (count + 1) / factor;
    number = percent / 5;
    remainder = percent % 5;
    if (number > 0) {
        for (uint8_t j = 0; j < number; j++) {
            lcdwriteCGRAM(lineToPrintOn, j, 5);
        }
    }
    lcdwriteCGRAM(lineToPrintOn, number, remainder);
    if (number < LCD_NUMBER_OF_BYTE) {
        for (uint8_t j = number + 1; j <= LCD_NUMBER_OF_BYTE; j++) {
            lcdwriteCGRAM(lineToPrintOn, j, 0);
        }
    }
}
#endif