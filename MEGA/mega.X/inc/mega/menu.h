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
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_MENU_H
#define	XC_MENU_H


#include "../mega.h"

#if (LCD_MODULE == 0 || KEYPAD_MODULE == 0)
#error "PLEASE ENABLE LCD MODULE && KEYPAD_MODULE"
#endif 

#ifndef MENU_DOWN_SW 
#define  MENU_DOWN_SW  KEYPAD01_SW01
#endif 

#ifndef MENU_UP_SW 
#define  MENU_UP_SW  KEYPAD01_SW02
#endif 


#ifndef  MENU_ENTER_SW 
#define  MENU_ENTER_SW  KEYPAD01_SW03
#endif 

#ifndef MENU_CENSEL_SW
#define MENU_CENSEL_SW  KEYPAD01_SW04
#endif

/*menu_item*/



typedef uint8_t(*pFuncPara_t)(void);

typedef struct menueItem_s {
    struct menueItem_s const *menuNext;
    struct menueItem_s const *menuPre;
    struct menueItem_s const *menuParent;
    struct menueItem_s const *menuChild;
    pFuncPara_t menuCallback;
    const char *menuLable;
} menueItem_t;

#if  LCD_NUMBER_OF_LINE >2

typedef struct Info_s {
    uint8_t ItemsCount;
    uint8_t position;
} menuItemInfo_t;
#endif

/*store value */
extern const menueItem_t NullItem;
#define MenuItem(Name, Next, Previous, Parent, Child, Callback,Label) \
    extern  const menueItem_t Next, Previous, Parent, Child; \
    const menueItem_t  Name PROGMEM = {&Next, &Previous, &Parent, &Child,  Callback,Label};


void menuOpen();
void MenuInit();
void menueDriver();
uint8_t menuIsOpen();
void menuStartItem(const menueItem_t *item);
#endif	/* XC_MENU_H */

