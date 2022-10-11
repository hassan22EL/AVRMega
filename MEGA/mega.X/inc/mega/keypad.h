/*
 *  Microchip Technology Inc. and its subsidiaries.  You may use this software 
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
#ifndef XC_KEYPAD_H
#define	XC_KEYPAD_H

#include "../mega.h"
#include "gpio.h"

#define   KEYPAD_NOT_AN_EVENT               (0)
#define   KEYPAD_NOT_A_BUTTON               (0)




#define   KEYPAD_PRESS_EVENT            (0x00)
#define   KEYPAD_LONGPRESS_EVENT        (0x40)
#define   KEYPAD_REPEAT_EVENT           (0x80)
#define   KEYPAD_RELEASE_EVENT          (0xC0)

#define KEYPAD01_PRESS(x)                 (((x)&(0x3F))|KEYPAD_PRESS_EVENT)
#define KEYPAD01_LONGPRESS(x)             (((x)&(0x3F))|KEYPAD_LONGPRESS_EVENT)
#define KEYPAD01_REPEAT(x)                (((x)&(0x3F))|KEYPAD_REPEAT_EVENT)
#define KEYPAD01_RELEASE(x)               (((x)&(0x3F))|KEYPAD_RELEASE_EVENT)

typedef enum {
    /*
     *************************************************************
     *                    SWITCH ID                            *
     * ***********************************************************
     */

    KEYPAD01_INVALID_KEY,
    KEYPAD01_SW01, KEYPAD01_SW02, KEYPAD01_SW03, KEYPAD01_SW04, KEYPAD01_SW05, KEYPAD01_SW06, KEYPAD01_SW07, KEYPAD01_SW08, KEYPAD01_SW09,
    KEYPAD01_SW10, KEYPAD01_SW11, KEYPAD01_SW12, KEYPAD01_SW13, KEYPAD01_SW14, KEYPAD01_SW15, KEYPAD01_SW16, KEYPAD01_SW17, KEYPAD01_SW18,
    KEYPAD01_SW19, KEYPAD01_SW20, KEYPAD01_SW21, KEYPAD01_SW22, KEYPAD01_SW23, KEYPAD01_SW24, KEYPAD01_SW25, KEYPAD01_SW26, KEYPAD01_SW27,
    KEYPAD01_SW28, KEYPAD01_SW29, KEYPAD01_SW30, KEYPAD01_SW31, KEYPAD01_SW32, KEYPAD01_SW33, KEYPAD01_SW34, KEYPAD01_SW35, KEYPAD01_SW36,
    KEYPAD01_SW37, KEYPAD01_SW38, KEYPAD01_SW39, KEYPAD01_SW40, KEYPAD01_SW41, KEYPAD01_SW42, KEYPAD01_SW43, KEYPAD01_SW44, KEYPAD01_SW45,
    KEYPAD01_SW46, KEYPAD01_SW47, KEYPAD01_SW48, KEYPAD01_SW49, KEYPAD01_SW50, KEYPAD01_SW51, KEYPAD01_SW52, KEYPAD01_SW53, KEYPAD01_SW54,
    KEYPAD01_SW55, KEYPAD01_SW56, KEYPAD01_SW57, KEYPAD01_SW58, KEYPAD01_SW59, KEYPAD01_SW60, KEYPAD01_SW61, KEYPAD01_SW62, KEYPAD01_SW63,

} KEYPAD01IDs_t;



#define KEYPAD_SW_ACTIVE_LOW           (0)
#define KEYPAD_SW_ACTIVE_HIGH          (1)

#define KEYPAD_SW_PRESSED              (0)
#define KEYPAD_SW_RELEASED             (1)


/*
 *************************************************************
 *                       Switches                            *
 * ***********************************************************
 * MAX_KEYPADS                  default used one switch      *        
 * BUTTONS_BUFFER_LENGTH        max event store by default 4 *
 * ***********************************************************
 */


#ifndef   KEYPADS_BUFFER_LENGTH
#define   KEYPADS_BUFFER_LENGTH         (4)
#endif

/*
 ********************************************************************************************
 *                              Switch de-bounds & Count                                    *
 * ******************************************************************************************
 * KEYPAD_SCAN_TIME_DEFAULT                   default as a 10 ms to scan switch             *        
 * KEYPAD_RELEASE_COUNT_DEFAULT               default as a 3 to action release              *
 * KEYPAD_SHORTPRESS_COUNT_DEFAULT            default as a 3 ms to action Press             *
 * KEYPAD_LONGPRESS_COUNT_DEFAULT             default as a 100 ms to action long Press      *
 * KEYPAD_REPEAT_COUNT_DEFAULT                default as a 50 ms to  start repeat           *
 * KEYPAD_REPEAT_RATE_COUNT_DEFAULT           default as a 3 ms to action repeat per char   *
 * ******************************************************************************************
 */

#define   KEYPAD_SCAN_TIME_DEFAULT                   (20)
#define   KEYPAD_DEBOUND_COUNT_DEFAULT               (2)
#define   KEYPAD_LONGPRESS_COUNT_DEFAULT             (250)
#define   KEYPAD_REPEAT_COUNT_DEFAULT                (25)
#define   KEYPAD_REPEAT_RATE_COUNT_DEFAULT           (2)


/*
 ********************************************************************************************
 *                              Switch Scan Time                                   *
 * ******************************************************************************************
 * KEYPAD_SCAN_TIME_DEFAULT                   default as a 10 ms to scan switch             *        
 * ******************************************************************************************
 */



#ifndef   KEYPAD_TASK     
#define   KEYPAD_SCAN_TIME                  (KEYPAD_SCAN_TIME_DEFAULT)
#else
#define   KEYPAD_SCAN_TIME                  (TicksToMs(KEYPAD_TASK))
#endif




/*
 ********************************************************************************************
 *                              Switch Press Count                                          *
 * ******************************************************************************************
 * KEYPAD_SHORTPRESS_COUNT                default as a increment up to 3  to press switch   *        
 * ******************************************************************************************
 */
#ifndef   KEYPAD_DEBOUND_DELAY
#define   KEYPAD_DEBOUND_COUNT           (KEYPAD_DEBOUND_COUNT_DEFAULT)
#else
#define   KEYPAD_DEBOUND_COUNT           (((KEYPAD_DEBOUND_DELAY/KEYPAD_SCAN_TIME)<1 ) ? (KEYPAD_DEBOUND_COUNT_DEFAULT) : (KEYPAD_DEBOUND_DELAY/KEYPAD_SCAN_TIME))
#endif

/*
 **************************************************************************************************
 *                              Switch Long Press Count                                           *
 * ************************************************************************************************
 * KEYPAD_LONGPRESS_COUNT                   default as a increment up to 3  to Long Press Switch  *        
 * ************************************************************************************************
 */
#ifndef   KEYPAD_LONGPRESS_DELAY
#define   KEYPAD_LONGPRESS_COUNT            (KEYPAD_LONGPRESS_COUNT_DEFAULT)
#else
#define   KEYPAD_LONGPRESS_COUNT           (((KEYPAD_LONGPRESS_DELAY/KEYPAD_SCAN_TIME)<1 ) ? (KEYPAD_LONGPRESS_COUNT_DEFAULT) : (KEYPAD_LONGPRESS_DELAY/KEYPAD_SCAN_TIME))
#endif

/*
 **************************************************************************************************
 *                              Switch Repeat Count                                               *
 * ************************************************************************************************
 * KEYPAD_REPEAT_COUNT                  default as a increment up to 3  to Start Repeat Switch    *        
 * ************************************************************************************************
 */
#ifndef   KEYPAD_REPEAT_DELAY
#define   KEYPAD_REPEAT_COUNT              (KEYPAD_REPEAT_COUNT_DEFAULT)
#else
#define   KEYPAD_REPEAT_COUNT           (((KEYPAD_REPEAT_DELAY/KEYPAD_SCAN_TIME)<1 ) ? (KEYPAD_REPEAT_COUNT_DEFAULT) : (KEYPAD_REPEAT_DELAY/KEYPAD_SCAN_TIME))
#endif

/*
 ********************************************************************************************
 *                              Switch Release Rate Count                                   *
 * ******************************************************************************************
 * KEYPAD_REPEAT_COUNT                    default as a increment up to 3  to Repeat rate    *        
 * ******************************************************************************************
 */
#ifndef   KEYPAD_REPEAT_RATE
#define   KEYPAD_REPEAT_RATE_COUNT          (KEYPAD_REPEAT_RATE_COUNT_DEFAULT)
#else
#define   KEYPAD_C_REPEAT_RATE                              (1000)/(KEYPAD_REPEAT_RATE)
#define   KEYPAD_REPEAT_RATE_COUNT                   ((KEYPAD_C_REPEAT_RATE /KEYPAD_SCAN_TIME ) < 1 ? (KEYPAD_REPEAT_RATE_COUNT_DEFAULT) : (KEYPAD_C_REPEAT_RATE /KEYPAD_SCAN_TIME))
#endif


/***********************KEYPAD01********************/
#ifndef    KEYPAD01
#define    KEYPAD01  (0)
#endif
/***********************KEYPAD01********************/
#ifndef    KEYPAD01
#define    KEYPAD01  (0)
#endif
/***********************KEYPAD03********************/
#ifndef    KEYPAD03
#define    KEYPAD03  (0)
#endif
/***********************KEYPAD04********************/
#ifndef    KEYPAD04
#define    KEYPAD04  (0)
#endif



/*
 ********************************************************************************************
 *                                 KEYPAD01 option                                          *
 * ******************************************************************************************
 */
#if KEYPAD01

/**********************************KEYPAD01_MAX_COMMON**************************************/
#ifndef KEYPAD01_MAX_COMMON
#define KEYPAD01_MAX_COMMON                                                (2)  
#else 
#if (KEYPAD01_MAX_COMMON <2 )
#error  "if  common is less than two please using button .h "
#endif

#if (KEYPAD01_MAX_COMMON > 8 )
#error " common is greater than 8 is not accpet "
#endif


#endif
/**********************************KEYPAD01_MAX_SWITCHES************************************/
#ifndef KEYPAD01_MAX_SWITCHES_PER_COMMON 
#define KEYPAD01_MAX_SWITCHES_PER_COMMON                                   (1) 
#endif
/**********************************KEYPAD01_SW_MODE*****************************************/
#ifndef  KEYPAD01_SW_MODE
#define  KEYPAD01_SW_MODE                                       MODE_INPUT_PULLUP
#endif
/**********************************KEYPAD01_SW_POL*****************************************/
#ifndef  KEYPAD01_SW_POL
#define  KEYPAD01_SW_POL                                         SW_ACTIVE_LOW
#endif
/**********************************KEYPAD01_MAX_COUNTER*****************************************/

#define KEYPAD01_MAX_COUNTER                                    (KEYPAD01_MAX_COMMON * KEYPAD01_MAX_SWITCHES_PER_COMMON) 





/*
 ********************************************************************************************
 *                              KEYPAD01_COMMONS_PINS                                       *
 * ******************************************************************************************
 */
/***********************KEYPAD01 C01********************/
#ifndef  KEYPAD01_C01_PIN
#define  KEYPAD01_C01_PIN          NOT_A_PIN
#endif
/***********************KEYPAD01 C02********************/
#ifndef  KEYPAD01_C02_PIN
#define  KEYPAD01_C02_PIN          NOT_A_PIN
#endif
/***********************KEYPAD01 C03********************/
#ifndef  KEYPAD01_C03_PIN
#define  KEYPAD01_C03_PIN          NOT_A_PIN
#endif
/***********************KEYPAD01 C04********************/
#ifndef  KEYPAD01_C04_PIN
#define  KEYPAD01_C04_PIN          NOT_A_PIN
#endif
/***********************KEYPAD01 C05********************/
#ifndef  KEYPAD01_C05_PIN
#define  KEYPAD01_C05_PIN          NOT_A_PIN
#endif
/***********************KEYPAD01 C06*******************/
#ifndef  KEYPAD01_C06_PIN
#define  KEYPAD01_C06_PIN          NOT_A_PIN
#endif
/***********************KEYPAD01 C07********************/
#ifndef  KEYPAD01_C07_PIN
#define  KEYPAD01_C07_PIN          NOT_A_PIN
#endif
/***********************KEYPAD01 C08********************/
#ifndef  KEYPAD01_C08_PIN
#define  KEYPAD01_C08_PIN          NOT_A_PIN
#endif



/*
 ********************************************************************************************
 *                              KEYPAD01_SWITCH_PINS                                       *
 * ******************************************************************************************
 */
/***********************KEYPAD01 SW01********************/
#ifndef  KEYPAD01_SW01_PIN
#define  KEYPAD01_SW01_PIN          NOT_A_PIN
#endif
/***********************KEYPAD01 SW02********************/
#ifndef  KEYPAD01_SW02_PIN
#define  KEYPAD01_SW02_PIN          NOT_A_PIN
#endif

/***********************KEYPAD01 SW02********************/
#ifndef  KEYPAD01_SW03_PIN
#define  KEYPAD01_SW03_PIN          NOT_A_PIN
#endif
/***********************KEYPAD01 SW02********************/
#ifndef  KEYPAD01_SW04_PIN
#define  KEYPAD01_SW04_PIN         NOT_A_PIN
#endif
/***********************KEYPAD01 SW02********************/
#ifndef  KEYPAD01_SW05_PIN
#define  KEYPAD01_SW05_PIN          NOT_A_PIN
#endif
/***********************KEYPAD01 SW02********************/
#ifndef  KEYPAD01_SW06_PIN
#define  KEYPAD01_SW06_PIN          NOT_A_PIN
#endif
/***********************KEYPAD01 SW02********************/
#ifndef  KEYPAD01_SW07_PIN
#define  KEYPAD01_SW07_PIN          NOT_A_PIN
#endif
/***********************KEYPAD01 SW02********************/
#ifndef  KEYPAD01_SW08_PIN
#define  KEYPAD01_SW08_PIN          NOT_A_PIN
#endif

#endif



void keypadSync();
void keypadDriverInit();
uint8_t keypadGetEvent();

#endif	/* XC_KEYPAD_H */

