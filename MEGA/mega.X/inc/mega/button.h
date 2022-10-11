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
#ifndef XC_BUTTON_H
#define	XC_BUTTON_H

#include "../mega.h"

#define   NOT_AN_EVENT               (0)
#define   NOT_A_BUTTON               (0)

#define   BUTTON_PRESS_EVENT            (0x00)
#define   BUTTON_LONGPRESS_EVENT        (0x40)
#define   BUTTON_REPEAT_EVENT           (0x80)
#define   BUTTON_RELEASE_EVENT          (0xC0)

#define BUTTON_PRESS(x)                 (((x)&(0x3F))|BUTTON_PRESS_EVENT)
#define BUTTON_LONGPRESS(x)             (((x)&(0x3F))|BUTTON_LONGPRESS_EVENT)
#define BUTTON_REPEAT(x)                (((x)&(0x3F))|BUTTON_REPEAT_EVENT)
#define BUTTON_RELEASE(x)               (((x)&(0x3F))|BUTTON_RELEASE_EVENT)

typedef enum {
    /*
     *************************************************************
     *                    SWITCH ID                            *
     * ***********************************************************
     */

    BUTTON_INVALID_KEY,
    SW01, SW02, SW03, SW04, SW05, SW06, SW07, SW08, SW09,
    SW10, SW11, SW12, SW13, SW14, SW15, SW16, SW17, SW18,
    SW19, SW20, SW21, SW22, SW23, SW24, SW25, SW26, SW27,
    SW28, SW29, SW30, SW31, SW32, SW33, SW34, SW35, SW36,
    SW37, SW38, SW39, SW40, SW41, SW42, SW43, SW44, SW45,
    SW46, SW47, SW48, SW49, SW50, SW51, SW52, SW53, SW54,
    SW55, SW56, SW57, SW58, SW59, SW60, SW61, SW62, SW63,

} ButtonIDs_t;



#define SW_ACTIVE_LOW           (0)
#define SW_ACTIVE_HIGH          (1)

#define SW_PRESSED              (0)
#define SW_RELEASED             (1)


/*
 *************************************************************
 *                       Switches                            *
 * ***********************************************************
 * MAX_BUTTONS                  default used one switch      *        
 * BUTTONS_BUFFER_LENGTH        max event store by default 4 *
 * ***********************************************************
 */
#ifndef  MAX_BUTTONS
#define   MAX_BUTTONS                   (1)
#endif

#ifndef  BUTTONS_BUFFER_LENGTH
#define   BUTTONS_BUFFER_LENGTH         (4)
#endif

/*
 ********************************************************************************************
 *                              Switch de-bounds & Count                                    *
 * ******************************************************************************************
 * BUTTON_SCAN_TIME_DEFAULT                   default as a 10 ms to scan switch             *        
 * BUTTON_RELEASE_COUNT_DEFAULT               default as a 3 to action release              *
 * BUTTON_SHORTPRESS_COUNT_DEFAULT            default as a 3 ms to action Press             *
 * BUTTON_LONGPRESS_COUNT_DEFAULT             default as a 100 ms to action long Press      *
 * BUTTON_REPEAT_COUNT_DEFAULT                default as a 50 ms to  start repeat           *
 * BUTTON_REPEAT_RATE_COUNT_DEFAULT           default as a 3 ms to action repeat per char   *
 * ******************************************************************************************
 */

#define   BUTTON_SCAN_TIME_DEFAULT                   (20)
#define   BUTTON_DEBOUND_COUNT_DEFAULT               (2)
#define   BUTTON_LONGPRESS_COUNT_DEFAULT             (250)
#define   BUTTON_REPEAT_COUNT_DEFAULT                (25)
#define   BUTTON_REPEAT_RATE_COUNT_DEFAULT           (2)


/*
 ********************************************************************************************
 *                              Switch Scan Time                                   *
 * ******************************************************************************************
 * BUTTON_SCAN_TIME_DEFAULT                   default as a 10 ms to scan switch             *        
 * ******************************************************************************************
 */



#ifndef   BUTTON_TASK     
#define   BUTTON_SCAN_TIME                  (BUTTON_SCAN_TIME_DEFAULT)
#else
#define   BUTTON_SCAN_TIME                  (TicksToMs(BUTTON_TASK))
#endif




/*
 ********************************************************************************************
 *                              Switch Press Count                                          *
 * ******************************************************************************************
 * BUTTON_SHORTPRESS_COUNT                default as a increment up to 3  to press switch   *        
 * ******************************************************************************************
 */
#ifndef   BUTTON_DEBOUND_DELAY
#define   BUTTON_DEBOUND_COUNT           (BUTTON_DEBOUND_COUNT_DEFAULT)
#else
#define   BUTTON_DEBOUND_COUNT           (((BUTTON_DEBOUND_DELAY/BUTTON_SCAN_TIME)<1 ) ? (BUTTON_DEBOUND_COUNT_DEFAULT) : (BUTTON_DEBOUND_DELAY/BUTTON_SCAN_TIME))
#endif

/*
 **************************************************************************************************
 *                              Switch Long Press Count                                           *
 * ************************************************************************************************
 * BUTTON_LONGPRESS_COUNT                   default as a increment up to 3  to Long Press Switch  *        
 * ************************************************************************************************
 */
#ifndef   BUTTON_LONGPRESS_DELAY
#define   BUTTON_LONGPRESS_COUNT            (BUTTON_LONGPRESS_COUNT_DEFAULT)
#else
#define   BUTTON_LONGPRESS_COUNT           (((BUTTON_LONGPRESS_DELAY/BUTTON_SCAN_TIME)<1 ) ? (BUTTON_LONGPRESS_COUNT_DEFAULT) : (BUTTON_LONGPRESS_DELAY/BUTTON_SCAN_TIME))
#endif

/*
 **************************************************************************************************
 *                              Switch Repeat Count                                               *
 * ************************************************************************************************
 * BUTTON_REPEAT_COUNT                  default as a increment up to 3  to Start Repeat Switch    *        
 * ************************************************************************************************
 */
#ifndef   BUTTON_REPEAT_DELAY
#define   BUTTON_REPEAT_COUNT              (BUTTON_REPEAT_COUNT_DEFAULT)
#else
#define   BUTTON_REPEAT_COUNT           (((BUTTON_REPEAT_DELAY/BUTTON_SCAN_TIME)<1 ) ? (BUTTON_REPEAT_COUNT_DEFAULT) : (BUTTON_REPEAT_DELAY/BUTTON_SCAN_TIME))
#endif

/*
 ********************************************************************************************
 *                              Switch Release Rate Count                                   *
 * ******************************************************************************************
 * BUTTON_REPEAT_COUNT                    default as a increment up to 3  to Repeat rate    *        
 * ******************************************************************************************
 */
#ifndef   BUTTON_REPEAT_RATE
#define   BUTTON_REPEAT_RATE_COUNT          (BUTTON_REPEAT_RATE_COUNT_DEFAULT)
#else
#define   C_REPEAT_RATE                              (1000)/(BUTTON_REPEAT_RATE)
#define   BUTTON_REPEAT_RATE_COUNT                   ((C_REPEAT_RATE /BUTTON_SCAN_TIME ) < 1 ? (BUTTON_REPEAT_RATE_COUNT_DEFAULT) : (C_REPEAT_RATE /BUTTON_SCAN_TIME))
#endif



/*
 ********************************************************
 *                  Switch 1 Option                     *
 * ******************************************************
 * SW_01_PIN             default not a pin              *        
 * SW_01_PRIORITY        default active low             *
 * SW_01_MODE            default mode input pull up     *
 * ******************************************************
 */
#ifndef     SW_01_PIN
#define     SW_01_PIN                    NOT_A_PIN
#endif

#ifndef     SW_01_PRIORITY
#define     SW_01_PRIORITY               SW_ACTIVE_LOW
#endif

#ifndef     SW_01_MODE
#define     SW_01_MODE                   MODE_INPUT_PULLUP
#endif
/*
 ********************************************************
 *                  Switch 2 Option                     *
 * ******************************************************
 * SW_02_PIN             default not a pin              *        
 * SW_02_PRIORITY        default active low             *
 * SW_02_MODE            default mode input pull up     *
 * ******************************************************
 */

#ifndef     SW_02_PRIORITY
#define     SW_02_PIN                    NOT_A_PIN
#endif

#ifndef     SW_02_PRIORITY
#define     SW_02_PRIORITY               SW_ACTIVE_LOW
#endif 

#ifndef     SW_02_MODE
#define     SW_02_MODE                   MODE_INPUT_PULLUP
#endif
/*
 ********************************************************
 *                  Switch 3 Option                     *
 * ******************************************************
 * SW_03_PIN             default not a pin              *        
 * SW_03_PRIORITY        default active low             *
 * SW_03_MODE            default mode input pull up     *
 * ******************************************************
 */
#ifndef     SW_03_PRIORITY
#define     SW_03_PIN                    NOT_A_PIN
#endif

#ifndef     SW_03_PRIORITY
#define     SW_03_PRIORITY               SW_ACTIVE_LOW
#endif 

#ifndef     SW_03_MODE
#define     SW_03_MODE                   MODE_INPUT_PULLUP
#endif

/*
 ********************************************************
 *                  Switch 4 Option                     *
 * ******************************************************
 * SW_04_PIN             default not a pin              *        
 * SW_04_PRIORITY        default active low             *
 * SW_04_MODE            default mode input pull up     *
 * ******************************************************
 */
#ifndef     SW_04_PRIORITY
#define     SW_04_PIN                    NOT_A_PIN
#endif

#ifndef     SW_04_PRIORITY
#define     SW_04_PRIORITY               SW_ACTIVE_LOW
#endif 

#ifndef     SW_04_MODE
#define     SW_04_MODE                   MODE_INPUT_PULLUP
#endif

/*
 ********************************************************
 *                  Switch 5 Option                     *
 * ******************************************************
 * SW_05_PIN             default not a pin              *        
 * SW_05_PRIORITY        default active low             *
 * SW_05_MODE            default mode input pull up     *
 * ******************************************************
 */
#ifndef     SW_05_PRIORITY
#define     SW_05_PIN                    NOT_A_PIN
#endif

#ifndef     SW_05_PRIORITY
#define     SW_05_PRIORITY               SW_ACTIVE_LOW
#endif 

#ifndef     SW_05_MODE
#define     SW_05_MODE                   MODE_INPUT_PULLUP
#endif

/*
 ********************************************************
 *                  Switch 6 Option                     *
 * ******************************************************
 * SW_06_PIN             default not a pin              *        
 * SW_06_PRIORITY        default active low             *
 * SW_06_MODE            default mode input pull up     *
 * ******************************************************
 */
#ifndef     SW_06_PRIORITY
#define     SW_06_PIN                    NOT_A_PIN
#endif

#ifndef     SW_06_PRIORITY
#define     SW_06_PRIORITY               SW_ACTIVE_LOW
#endif 

#ifndef     SW_06_MODE
#define     SW_06_MODE                   MODE_INPUT_PULLUP
#endif


/*
 ********************************************************
 *                  Switch 7 Option                     *
 * ******************************************************
 * SW_07_PIN             default not a pin              *        
 * SW_07_PRIORITY        default active low             *
 * SW_07_MODE            default mode input pull up     *
 * ******************************************************
 */
#ifndef     SW_07_PRIORITY
#define     SW_07_PIN                    NOT_A_PIN
#endif

#ifndef     SW_07_PRIORITY
#define     SW_07_PRIORITY               SW_ACTIVE_LOW
#endif 

#ifndef     SW_07_MODE
#define     SW_07_MODE                   MODE_INPUT_PULLUP
#endif
/*
 ********************************************************
 *                  Switch 8 Option                     *
 * ******************************************************
 * SW_08_PIN             default not a pin              *        
 * SW_08_PRIORITY        default active low             *
 * SW_08_MODE            default mode input pull up     *
 * ******************************************************
 */
#ifndef     SW_08_PRIORITY
#define     SW_08_PIN                    NOT_A_PIN
#endif

#ifndef     SW_08_PRIORITY
#define     SW_08_PRIORITY               SW_ACTIVE_LOW
#endif 

#ifndef     SW_08_MODE
#define     SW_08_MODE                   MODE_INPUT_PULLUP
#endif
/*
 ********************************************************
 *                  Switch 9 Option                     *
 * ******************************************************
 * SW_09_PIN             default not a pin              *        
 * SW_09_PRIORITY        default active low             *
 * SW_09_MODE            default mode input pull up     *
 * ******************************************************
 */
#ifndef     SW_09_PRIORITY
#define     SW_09_PIN                    NOT_A_PIN
#endif

#ifndef     SW_09_PRIORITY
#define     SW_09_PRIORITY               SW_ACTIVE_LOW
#endif 

#ifndef     SW_09_MODE
#define     SW_09_MODE                   MODE_INPUT_PULLUP
#endif



/*
 ********************************************************
 *                  Switch 10 Option                    *
 * ******************************************************
 * SW_10_PIN             default not a pin              *        
 * SW_10_PRIORITY        default active low             *
 * SW_10_MODE            default mode input pull up     *
 * ******************************************************
 */
#ifndef     SW_10_PRIORITY
#define     SW_10_PIN                    NOT_A_PIN
#endif

#ifndef     SW_10_PRIORITY
#define     SW_10_PRIORITY               SW_ACTIVE_LOW
#endif 

#ifndef     SW_10_MODE
#define     SW_10_MODE                   MODE_INPUT_PULLUP
#endif

/*
 ********************************************************
 *                  Switch 11 Option                    *
 * ******************************************************
 * SW_11_PIN             default not a pin              *        
 * SW_11_PRIORITY        default active low             *
 * SW_11_MODE            default mode input pull up     *
 * ******************************************************
 */
#ifndef     SW_11_PRIORITY
#define     SW_11_PIN                    NOT_A_PIN
#endif

#ifndef     SW_11_PRIORITY
#define     SW_11_PRIORITY               SW_ACTIVE_LOW
#endif 

#ifndef     SW_11_MODE
#define     SW_11_MODE                   MODE_INPUT_PULLUP
#endif

/*
 ********************************************************
 *                  Switch 12 Option                    *
 * ******************************************************
 * SW_12_PIN             default not a pin              *        
 * SW_12_PRIORITY        default active low             *
 * SW_12_MODE            default mode input pull up     *
 * ******************************************************
 */
#ifndef     SW_12_PRIORITY
#define     SW_12_PIN                    NOT_A_PIN
#endif

#ifndef     SW_12_PRIORITY
#define     SW_12_PRIORITY               SW_ACTIVE_LOW
#endif 

#ifndef     SW_12_MODE
#define     SW_12_MODE                   MODE_INPUT_PULLUP
#endif

/*
 ********************************************************
 *                  Switch 13 Option                    *
 * ******************************************************
 * SW_13_PIN             default not a pin              *        
 * SW_13_PRIORITY        default active low             *
 * SW_13_MODE            default mode input pull up     *
 * ******************************************************
 */
#ifndef     SW_13_PRIORITY
#define     SW_13_PIN                    NOT_A_PIN
#endif

#ifndef     SW_13_PRIORITY
#define     SW_13_PRIORITY               SW_ACTIVE_LOW
#endif 

#ifndef     SW_13_MODE
#define     SW_13_MODE                   MODE_INPUT_PULLUP
#endif



/*
 ********************************************************
 *                  Switch 14 Option                    *
 * ******************************************************
 * SW_14_PIN             default not a pin              *        
 * SW_14_PRIORITY        default active low             *
 * SW_14_MODE            default mode input pull up     *
 * ******************************************************
 */
#ifndef     SW_14_PRIORITY
#define     SW_14_PIN                    NOT_A_PIN
#endif

#ifndef     SW_14_PRIORITY
#define     SW_14_PRIORITY               SW_ACTIVE_LOW
#endif 

#ifndef     SW_14_MODE
#define     SW_14_MODE                   MODE_INPUT_PULLUP
#endif


/*
 ********************************************************
 *                  Switch 15 Option                    *
 * ******************************************************
 * SW_15_PIN             default not a pin              *        
 * SW_15_PRIORITY        default active low             *
 * SW_15_MODE            default mode input pull up     *
 * ******************************************************
 */
#ifndef     SW_15_PRIORITY
#define     SW_15_PIN                    NOT_A_PIN
#endif

#ifndef     SW_15_PRIORITY
#define     SW_15_PRIORITY               SW_ACTIVE_LOW
#endif 

#ifndef     SW_15_MODE
#define     SW_15_MODE                   MODE_INPUT_PULLUP
#endif
/*
 ********************************************************
 *                  Switch 16 Option                    *
 * ******************************************************
 * SW_16_PIN             default not a pin              *        
 * SW_16_PRIORITY        default active low             *
 * SW_16_MODE            default mode input pull up     *
 * ******************************************************
 */
#ifndef     SW_16_PRIORITY
#define     SW_16_PIN                    NOT_A_PIN
#endif

#ifndef     SW_16_PRIORITY
#define     SW_16_PRIORITY               SW_ACTIVE_LOW
#endif 

#ifndef     SW_16_MODE
#define     SW_16_MODE                   MODE_INPUT_PULLUP
#endif

/*
 ********************************************************
 *                  Switch 17 Option                     *
 * ******************************************************
 * SW_17_PIN             default not a pin              *        
 * SW_17_PRIORITY        default active low             *
 * SW_17_MODE            default mode input pull up     *
 * ******************************************************
 */
#ifndef     SW_17_PRIORITY
#define     SW_17_PIN                    NOT_A_PIN
#endif

#ifndef     SW_17_PRIORITY
#define     SW_17_PRIORITY               SW_ACTIVE_LOW
#endif 

#ifndef     SW_17_MODE
#define     SW_17_MODE                   MODE_INPUT_PULLUP
#endif

/*
 ********************************************************
 *                  Switch 18 Option                    *
 * ******************************************************
 * SW_18_PIN             default not a pin              *        
 * SW_18_PRIORITY        default active low             *
 * SW_18_MODE            default mode input pull up     *
 * ******************************************************
 */
#ifndef     SW_18_PRIORITY
#define     SW_18_PIN                    NOT_A_PIN
#endif

#ifndef     SW_18_PRIORITY
#define     SW_18_PRIORITY               SW_ACTIVE_LOW
#endif 

#ifndef     SW_18_MODE
#define     SW_18_MODE                   MODE_INPUT_PULLUP
#endif

/*
 ********************************************************
 *                  Switch 19 Option                    *
 * ******************************************************
 * SW_19_PIN             default not a pin              *        
 * SW_19_PRIORITY        default active low             *
 * SW_19_MODE            default mode input pull up     *
 * ******************************************************
 */
#ifndef     SW_19_PRIORITY
#define     SW_19_PIN                    NOT_A_PIN
#endif

#ifndef     SW_19_PRIORITY
#define     SW_19_PRIORITY               SW_ACTIVE_LOW
#endif 

#ifndef     SW_19_MODE
#define     SW_19_MODE                   MODE_INPUT_PULLUP
#endif

/*
 ********************************************************
 *                  Switch 20 Option                    *
 * ******************************************************
 * SW_20_PIN             default not a pin              *        
 * SW_20_PRIORITY        default active low             *
 * SW_20_MODE            default mode input pull up     *
 * ******************************************************
 */
#ifndef     SW_20_PRIORITY
#define     SW_20_PIN                    NOT_A_PIN
#endif

#ifndef     SW_20_PRIORITY
#define     SW_20_PRIORITY               SW_ACTIVE_LOW
#endif 

#ifndef     SW_20_MODE
#define     SW_20_MODE                   MODE_INPUT_PULLUP
#endif

/*
 ********************************************************
 *                  Switch 21 Option                    *
 * ******************************************************
 * SW_21_PIN             default not a pin              *        
 * SW_21_PRIORITY        default active low             *
 * SW_21_MODE            default mode input pull up     *
 * ******************************************************
 */
#ifndef     SW_21_PRIORITY
#define     SW_21_PIN                    NOT_A_PIN
#endif

#ifndef     SW_21_PRIORITY
#define     SW_21_PRIORITY               SW_ACTIVE_LOW
#endif 

#ifndef     SW_21_MODE
#define     SW_21_MODE                   MODE_INPUT_PULLUP
#endif
/*
 ********************************************************
 *                  Switch 22 Option                    *
 * ******************************************************
 * SW_22_PIN             default not a pin              *        
 * SW_22_PRIORITY        default active low             *
 * SW_22_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_22_PIN                    NOT_A_PIN
#define     SW_22_PRIORITY               SW_ACTIVE_LOW
#define     SW_22_MODE                   MODE_INPUT_PULLUP
/*
 ********************************************************
 *                  Switch 23 Option                    *
 * ******************************************************
 * SW_23_PIN             default not a pin              *        
 * SW_23_PRIORITY        default active low             *
 * SW_23_MODE            default mode input pull up     *
 * ******************************************************
 */
#ifndef     SW_23_PRIORITY
#define     SW_23_PIN                    NOT_A_PIN
#endif

#ifndef     SW_23_PRIORITY
#define     SW_23_PRIORITY               SW_ACTIVE_LOW
#endif 

#ifndef     SW_23_MODE
#define     SW_23_MODE                   MODE_INPUT_PULLUP
#endif
/*
 ********************************************************
 *                  Switch 24 Option                     *
 * ******************************************************
 * SW_24_PIN             default not a pin              *        
 * SW_24_PRIORITY        default active low             *
 * SW_24_MODE            default mode input pull up     *
 * ******************************************************
 */
#ifndef     SW_24_PRIORITY
#define     SW_24_PIN                    NOT_A_PIN
#endif

#ifndef     SW_24_PRIORITY
#define     SW_24_PRIORITY               SW_ACTIVE_LOW
#endif 

#ifndef     SW_24_MODE
#define     SW_24_MODE                   MODE_INPUT_PULLUP
#endif

void buttonSync();
void buttonDriverInit();
uint8_t buttonGetEvent();

#endif	/* XC_BUTTON_H */