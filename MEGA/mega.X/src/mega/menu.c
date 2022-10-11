
/*
 * File:   menue.c
 * Author: Hassan
 *
 * Created on April 27, 2022, 9:53 AM
 */




#include "../../inc/mega.h"
#if MENU_MODULE


#define  MENU_LCD_UPDATE (7)
#define  MENU_UPDATE     (6)
#define  MENU_UPDATE_ACTION (5)
#define  MENU_OPEN_STATE    (4)

/*current item*/
const menueItem_t NullItem = {(const menueItem_t *) NULL, (const menueItem_t *) NULL, (const menueItem_t *) NULL, (const menueItem_t *) NULL,
    (pFuncPara_t) NULL,
    (const char *) NULL};


const menueItem_t *gpCurrentMenuItem;
volatile uint8_t gu8OPenMenueFlag;

const char * getmenuLable(const menueItem_t *item);
const menueItem_t * getmenuNext(const menueItem_t *item);
const menueItem_t * getmenuPrev(const menueItem_t *item);
const menueItem_t * getmenuParent(const menueItem_t *item);
const menueItem_t * getmenuChlid(const menueItem_t *item);
#if LCD_NUMBER_OF_LINE >2
menuItemInfo_t getItemInfo(const menueItem_t *item);
#endif
void changPointerRefernce(const menueItem_t *item, menueItem_t *gpItem);

void menuAction();
uint8_t menuEvent();
void menuLCDReader();
void menuLCDChild(const menueItem_t *item, uint8_t line, uint8_t pos);
void showMenueItem(const menueItem_t *item);
void menueReadEvents();
void menuItemPos();

void MenuInit() {
    gpCurrentMenuItem = &NullItem;
    gu8OPenMenueFlag = 0;
}

const char * getmenuLable(const menueItem_t *item) {
    return (char const *) (item->menuLable);
}

const menueItem_t * getmenuNext(const menueItem_t *item) {
    return (const menueItem_t *) item->menuNext;
}

const menueItem_t * getmenuPrev(const menueItem_t *item) {
    return (const menueItem_t *) item->menuPre;
}

const menueItem_t * getmenuParent(const menueItem_t *item) {
    return (const menueItem_t *) item->menuParent;
}

const menueItem_t * getmenuChlid(const menueItem_t *item) {
    return (const menueItem_t *) item->menuChild;
}

uint8_t menuEvent() {
    pFuncPara_t callback;
    if (gpCurrentMenuItem && gpCurrentMenuItem != &NullItem) {
        callback = (pFuncPara_t) (gpCurrentMenuItem->menuCallback);
        if (callback != NULL) {
            return (*callback)();
        }
    }
    return false;
}

void showMenueItem(const menueItem_t *uitme) {
    if (uitme && uitme != &NullItem) {
        gpCurrentMenuItem = uitme; /*invalid instruction assignment pad address error*/
    }
}

/*show item with chid in lcd before show */
void menuAction() {
    if (menuEvent()) {
        if (getmenuChlid(gpCurrentMenuItem) && getmenuChlid(gpCurrentMenuItem) != &NullItem) {
            showMenueItem(getmenuChlid(gpCurrentMenuItem));
        }
        bitSet(gu8OPenMenueFlag, MENU_UPDATE);
        bitClear(gu8OPenMenueFlag, MENU_UPDATE_ACTION);
    }
}


#if LCD_NUMBER_OF_LINE >2

/*get item */
menuItemInfo_t getItemInfo(const menueItem_t *item) {
    menuItemInfo_t res;
    res.position = 0;
    res.ItemsCount = 0;
    const menueItem_t *i = getmenuChlid(getmenuParent(item));
    for (; i && i != &NullItem; i = getmenuNext(i)) {
        if (item == i) {
            res.position = res.ItemsCount;
        }
        res.ItemsCount++;
        if (i->menuNext == getmenuChlid(getmenuParent(i))) {
            break;
        }
    }
    return res;
}
#endif
/*render call back*/
#if LCD_NUMBER_OF_LINE >2

void menuItemPos() {
    /*max of lines*/
    uint8_t u8startLine;
    uint8_t u8Endline;
    uint8_t u8center;
    uint8_t pos;
    uint8_t maxItemPerline;
    uint8_t maxlines;
    uint8_t u;
    menuItemInfo_t ItemInfo;
    u8startLine = 0;
    if (MAX_CHILD_PER_LINE == 0) {
        maxItemPerline = 1;
    }
    if (MAX_CHILD_PER_LINE > 1) {
        maxItemPerline = 2;
    } else {
        maxItemPerline = 1;
    }
    maxlines = LCD_NUMBER_OF_LINE - 1;
    u8center = maxItemPerline >> 1;
    /*get max of the item count , and item pos*/
    const menueItem_t *i = getmenuChlid(getmenuParent(gpCurrentMenuItem));
    for (; i && i != &NullItem; i = getmenuNext(i)) {
        ItemInfo = getItemInfo(i);
        u8Endline = (ItemInfo.position >> (maxItemPerline - 1)) + 1;
        if (u8Endline > maxlines) u8startLine = u8Endline - maxlines; /*at 4.,5,6 = 1 ,2,3*/
        pos = ItemInfo.position & u8center;
        /*max line = 3 and  and start = 0 or max-end*/
        //1,2,3,4  next=>2,3,4 pre=>1,2,3
        if (u8Endline > maxlines) {
            if (gpCurrentMenuItem == i) {
                const menueItem_t * j = i;
                u = u8Endline - u8startLine;
                lcdClearlines(1);
                while (u > 0) {
                    if (pos) {
                        /*move icon*/
                        if (gpCurrentMenuItem == j)
                            lcdBlink(u, pos + ((LCD_NUMBER_OF_BYTE) / 2));
                        menuLCDChild(j, (u), pos + ((LCD_NUMBER_OF_BYTE) / 2));
                        if (j->menuNext && j->menuNext != &NullItem && maxItemPerline > 1)
                            menuLCDChild(j->menuNext, u, !pos);
                    } else {
                        if (gpCurrentMenuItem == j)
                            lcdBlink(u, pos);
                        menuLCDChild(j, (u), pos);
                        if (j->menuNext && j->menuNext != &NullItem && maxItemPerline > 1)
                            menuLCDChild(j->menuNext, u, !pos + (LCD_NUMBER_OF_BYTE / 2));
                        u--;
                    }
                    j = getmenuPrev(j);
                    ItemInfo = getItemInfo(j);
                    pos = ItemInfo.position & u8center;
                }
            }
        } else {
            if (pos) {
                /*move icon*/
                if (gpCurrentMenuItem == i) {
                    lcdBlink(u8Endline, pos + ((LCD_NUMBER_OF_BYTE) / 2));
                }
                menuLCDChild(i, (u8Endline), pos + ((LCD_NUMBER_OF_BYTE) / 2));
            } else {
                if (gpCurrentMenuItem == i) {
                    lcdBlink(u8Endline, pos);
                }
                menuLCDChild(i, (u8Endline), pos);
            }
        }
        if (i->menuNext == getmenuChlid(getmenuParent(i))) {
            break;
        }
    }
}

#endif

void menuLCDReader() {
    if (gpCurrentMenuItem && gpCurrentMenuItem == &NullItem) {
        return;
    }
    /*update child and current item in the display*/
    const char *Sparent = (getmenuLable(getmenuParent(gpCurrentMenuItem))) + 2;
    lcdwrite(0, LCD_TEXT_CENTER, Sparent);
#if LCD_NUMBER_OF_LINE >2
    menuItemPos();
#else
    const char *lable = getmenuLable(gpCurrentMenuItem);
    lcdwrite(1, 0, lable);

#endif
    bitSet(gu8OPenMenueFlag, MENU_LCD_UPDATE);
}

void menuLCDChild(const menueItem_t *item, uint8_t line, uint8_t pos) {
    const char *ScurrentItem = getmenuLable(item);
    lcdwrite(line, pos, ScurrentItem);
}

/*events up,down,enter buttons*/
void menueReadEvents() {
    /*read event  up , down , enter*/
    uint8_t u8Event;
    u8Event = keypadGetEvent();
    if (u8Event == KEYPAD01_PRESS(MENU_ENTER_SW)) {
        bitSet(gu8OPenMenueFlag, MENU_UPDATE_ACTION);
        return;
    }

    if (u8Event == KEYPAD01_PRESS(MENU_DOWN_SW)) {
        showMenueItem(getmenuPrev(gpCurrentMenuItem));
        bitSet(gu8OPenMenueFlag, MENU_UPDATE);
        return;
    }
    if (u8Event == KEYPAD01_PRESS(MENU_UP_SW)) {
        /*next _ item*/
        showMenueItem(getmenuNext(gpCurrentMenuItem));
        bitSet(gu8OPenMenueFlag, MENU_UPDATE);
        return;
    }
    if (u8Event == KEYPAD01_PRESS(MENU_CENSEL_SW)) {
        if (getmenuParent(getmenuParent(gpCurrentMenuItem)) == &NullItem) {
            gpCurrentMenuItem = &NullItem;
            bitClear(gu8OPenMenueFlag, MENU_OPEN_STATE);
            bitClear(gu8OPenMenueFlag, MENU_LCD_UPDATE);
            bitClear(gu8OPenMenueFlag, MENU_UPDATE);
            bitClear(gu8OPenMenueFlag, MENU_UPDATE_ACTION);
            return;
        }
        lcdNoBlink();
        showMenueItem(getmenuParent(gpCurrentMenuItem));
        bitSet(gu8OPenMenueFlag, MENU_UPDATE);
        return;
    }
}

void menueDriver() {
    /*in first create the first item*/
    /*open menu , read event */
    if (bitIsClear(gu8OPenMenueFlag, MENU_OPEN_STATE))
        return;

    if (bitIsSet(gu8OPenMenueFlag, MENU_UPDATE_ACTION)) {
        menuAction();
        bitClear(gu8OPenMenueFlag, MENU_LCD_UPDATE);
    } else {
        menueReadEvents();
        if (bitIsSet(gu8OPenMenueFlag, MENU_LCD_UPDATE)) {
            if (lcdUpdate()) {
                /*clear lcd buffer*/
                lcdClear();
                bitClear(gu8OPenMenueFlag, MENU_LCD_UPDATE);
            }
        }
        if (bitIsClear(gu8OPenMenueFlag, MENU_LCD_UPDATE)) {
            if (bitIsSet(gu8OPenMenueFlag, MENU_UPDATE)) {
                lcdClear();
                lcdNoBlink();
                lcdNoCursor();
                menuLCDReader();
                bitClear(gu8OPenMenueFlag, MENU_UPDATE);
            }
        }
    }
}

void menuStartItem(const menueItem_t * item) {
    /*show item and open menu with event open menu */
    showMenueItem(item);
    menuAction();
    bitSet(gu8OPenMenueFlag, MENU_UPDATE);
}

void menuOpen() {
    bitSet(gu8OPenMenueFlag, MENU_OPEN_STATE);
}

uint8_t menuIsOpen() {
    if (bitIsSet(gu8OPenMenueFlag, MENU_OPEN_STATE))
        return (1);
    return (0);
}
#endif
