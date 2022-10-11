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
#ifndef XC_RESOURCE_H
#define	XC_RESOURCE_H

#include "mega.h"
#include "resource.h"
// List Of XTALs

#define GPIO2_PREFER_SPEED    (0)

#define     DISPLAY_POINT                (1)
#define     XTAL_08000000               (8000000UL)
#define     XTAL_11059200               (11059200UL)
#define     XTAL_16000000               (16000000UL)

#define     F_CPU                       XTAL_11059200


// List of system ticks
#define     TICK_00625                   (625UL)
#define     TICK_01250                   (1250UL)
#define     TICK_10000                   (1000UL)
#define     SYS_TICK                     TICK_01250




#if defined (__AVR_ATmega328P__ ) || defined (__AVR_ATmega328__) || defined (__AVR_ATmega8__)|| defined (__AVR_ATmega8A__)||defined (__AVR_ATmega48A__)
#define  CALL_POINT_MASTER              (1)
/*
 ***********************************************************************
 *                                Mega Modules                         *
 * *********************************************************************
 */
/*******************SYSTEM_MODULE*********************(active/de-active)(0/1)**************/
#define             SYSTEM_MODULE                               (1)  
/*******************LCD_MODULE************************(active/de-active)(0/1)**************/
#define             LCD_MODULE                                  (0)

#if DISPLAY_POINT
/*******************BUTTON__MODULE********************(active/de-active)(0/1)**************/
#define             BUTTON_MODULE                               (0)

/*******************SSD_MODULE************************(active/de-active)(0/1)**************/
#define             SSD_MODULE                                  (1)
#else
/*******************BUTTON__MODULE********************(active/de-active)(0/1)**************/
#define             BUTTON_MODULE                               (1)

#define             SSD_MODULE                                  (0)
#endif
/**********************BUZ_MODULE*********************(active/de-active)(0/1)**************/
#define             BUZ_MODULE                                  (1)
/*******************KEYPAD_MODULE*********************(active/de-active)(0/1)**************/
#define             KEYPAD_MODULE                               (0)
/*******************RTC_MODULE************************(active/de-active)(0/1)**************/
#define             RTC_MODULE                                  (0)
/*******************MENU_MODULE************************(active/de-active)(0/1)**************/
#define             MENU_MODULE                                 (0)
/*******************SPI_MODULE***********************(active/de-active)(0/1)**************/
#define             SPI_MODULE                                  (0)
/*******************SSSD_MODULE************************(active/de-active)(0/1)**************/
#define             SSSD_MODULE                                 (0)
/*******************HX711_MODULE************************(active/de-active)(0/1)**************/
#define             HX711_MODULE                                (0)
/*******************EEPROM_MODULE************************(active/de-active)(0/1)**************/
#define             EEPROM_MODULE                               (1)
/*******************KEYPADEVENT_MODULE************************(active/de-active)(0/1)**************/
#define            KEYPADEVENT_MODULE                           (0)
/*******************TWI_MODULE************************(active/de-active)(0/1)**************/
#define            TWI_MODULE                                   (0)
/*******************EX_EEPROM_MODULE************************(active/de-active)(0/1)**************/
#define            EX_EEPROM_MODULE                             (0)                                      
/*******************CSMA_CD_MODULE************************(active/de-active)(0/1)**************/
#define            CSMA_CD_MODULE                               (1)
/*
 ***********************************************************************
 *                                System Modules                       *
 * *********************************************************************
 */
#if SYSTEM_MODULE 

#define       APP_TASK                    (8)

#if SSD_MODULE
#define     SDD_TASK                    (1)
#endif
#if BUTTON_MODULE
#define     BUTTON_TASK                  (16)   // 20 ms
#endif

#if KEYPAD_MODULE
#define   KEYPAD_TASK                   (16)
#endif

#if RTC_MODULE
#define     RTC_TASK                     (8)
#endif

#if HX711_MODULE  

#define    HX711_READ_TASK              (4)
#endif

#define     MAX_TASK                    (16)
#endif
/*
 ***********************************************************************
 *                                LCD Modules                          *
 * *********************************************************************
 */
#if LCD_MODULE
#define   LCD_RS    NOT_A_PIN
#define   LCD_EN    NOT_A_PIN


#define   LCD_D4    NOT_A_PIN
#define   LCD_D5    NOT_A_PIN
#define   LCD_D6    NOT_A_PIN
#define   LCD_D7    NOT_A_PIN

#define   LCD_RW    NOT_A_PIN
#define   LCD_BL    NOT_A_PIN

#define   LCD_D0    NOT_A_PIN
#define   LCD_D1    NOT_A_PIN
#define   LCD_D2    NOT_A_PIN
#define   LCD_D3    NOT_A_PIN


#define   LCD_NUMBER_OF_LINES (2)
#define   LCD_NUMBER_OF_BYTE  (16)
#define   LCD_LINE_MODE        LCD_INTERAVTIVE
#define   LCD_BITS_MODE        LCD_4BIT_MODE
#endif
/*
 ***********************************************************************
 *                                SSD Modules                          *
 * *********************************************************************
 */
#if SSD_MODULE
#define     SSD_MAX_DIGIT             (7)
#define     SSD_TYPE_LED            SSD_COMMON_ANADOD
#define     SSD_DIR                 SSD_RIGHT

#define      SSD_DIGIT0_PIN          GPIO_D6
#define      SSD_DIGIT1_PIN          GPIO_D5
#define      SSD_DIGIT2_PIN          GPIO_D4
#define      SSD_DIGIT3_PIN          GPIO_D3
#define      SSD_DIGIT4_PIN          GPIO_C3
#define      SSD_DIGIT5_PIN          GPIO_C4
#define      SSD_DIGIT6_PIN          GPIO_C5


#define     SSD_DATA0_PIN       GPIO_B1
#define     SSD_DATA1_PIN       GPIO_B2
#define     SSD_DATA2_PIN       GPIO_B3
#define     SSD_DATA3_PIN       GPIO_B4
#define     SSD_DATA4_PIN       GPIO_B5
#define     SSD_DATA5_PIN       GPIO_C0
#define     SSD_DATA6_PIN       GPIO_C1
#define     SSD_DATA7_PIN       GPIO_C2
#endif
/*
 ***********************************************************************
 *                                BUTTON Modules                       *
 * *********************************************************************
 */
#if BUTTON_MODULE

/*
 *************************************************************
 *                       Switches                            *
 * ***********************************************************
 * MAX_BUTTONS                  default used one switch      *        
 * BUTTONS_BUFFER_LENGTH        max event store by default 4 *
 * ***********************************************************
 */
#define   MAX_BUTTONS       (4)
#define   BUTTONS_BUFFER_LENGTH  (4)


/*
 *************************************************************************************
 *                              Switch de-bounds & delays                            *
 * ***********************************************************************************
 * BUTTON_SCAN_TIME                   default as a 10 ms to scan switch              *        
 * BUTTON_RELEASE_DELAY               default as a 33 ms to action release           *
 * BUTTON_SHORTPRESS_DELAY            default as a 33 ms to action Press             *
 * BUTTON_LONGPRESS_DELAY             default as a 1000 ms to action long Press      *
 * BUTTON_REPEAT_DELAY                default as a 500 ms to  start repeat           *
 * BUTTON_REPEAT_RATE_DELAY           default as a 33 ms to action repeat per char   *
 * ***********************************************************************************
 */

#define   BUTTON_DEBOUND_DELAY              (20)
#define   BUTTON_LONGPRESS_DELAY            (2000)
#define   BUTTON_REPEAT_DELAY               (1000)
#define   BUTTON_REPEAT_RATE                (5)/*char per sec*/

/*
 ********************************************************
 *                  Switch 1 Option                     *
 * ******************************************************
 * SW_01_PIN             default not a pin              *        
 * SW_01_PRIORITY        default active low             *
 * SW_01_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_01_PIN                    GPIO_D3
#define     SW_01_PRIORITY               SW_ACTIVE_LOW
#define     SW_01_MODE                   MODE_INPUT_PULLUP

/*
 ********************************************************
 *                  Switch 2 Option                     *
 * ******************************************************
 * SW_02_PIN             default not a pin              *        
 * SW_02_PRIORITY        default active low             *
 * SW_02_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_02_PIN                    GPIO_D4
#define     SW_02_PRIORITY               SW_ACTIVE_LOW
#define     SW_02_MODE                   MODE_INPUT_PULLUP

/*
 ********************************************************
 *                  Switch 3 Option                     *
 * ******************************************************
 * SW_03_PIN             default not a pin              *        
 * SW_03_PRIORITY        default active low             *
 * SW_03_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_03_PIN                    GPIO_D5
#define     SW_03_PRIORITY               SW_ACTIVE_LOW
#define     SW_03_MODE                   MODE_INPUT_PULLUP

/*
 ********************************************************
 *                  Switch 4 Option                     *
 * ******************************************************
 * SW_04_PIN             default not a pin              *        
 * SW_04_PRIORITY        default active low             *
 * SW_04_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_04_PIN                    GPIO_D6
#define     SW_04_PRIORITY               SW_ACTIVE_LOW
#define     SW_04_MODE                   MODE_INPUT_PULLUP

/*
 ********************************************************
 *                  Switch 5 Option                     *
 * ******************************************************
 * SW_05_PIN             default not a pin              *        
 * SW_05_PRIORITY        default active low             *
 * SW_05_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_05_PIN                    NOT_A_PIN
#define     SW_05_PRIORITY               SW_ACTIVE_LOW
#define     SW_05_MODE                   MODE_INPUT_PULLUP

/*
 ********************************************************
 *                  Switch 6 Option                     *
 * ******************************************************
 * SW_06_PIN             default not a pin              *        
 * SW_06_PRIORITY        default active low             *
 * SW_06_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_06_PIN                    NOT_A_PIN
#define     SW_06_PRIORITY               SW_ACTIVE_LOW
#define     SW_06_MODE                   MODE_INPUT_PULLUP


/*
 ********************************************************
 *                  Switch 7 Option                     *
 * ******************************************************
 * SW_07_PIN             default not a pin              *        
 * SW_07_PRIORITY        default active low             *
 * SW_07_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_07_PIN                    NOT_A_PIN
#define     SW_07_PRIORITY               SW_ACTIVE_LOW
#define     SW_07_MODE                   MODE_INPUT_PULLUP
/*
 ********************************************************
 *                  Switch 8 Option                     *
 * ******************************************************
 * SW_08_PIN             default not a pin              *        
 * SW_08_PRIORITY        default active low             *
 * SW_08_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_08_PIN                    NOT_A_PIN
#define     SW_08_PRIORITY               SW_ACTIVE_LOW
#define     SW_08_MODE                   MODE_INPUT_PULLUP
/*
 ********************************************************
 *                  Switch 9 Option                     *
 * ******************************************************
 * SW_09_PIN             default not a pin              *        
 * SW_09_PRIORITY        default active low             *
 * SW_09_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_09_PIN                    NOT_A_PIN
#define     SW_09_PRIORITY               SW_ACTIVE_LOW
#define     SW_09_MODE                   MODE_INPUT_PULLUP

/*
 ********************************************************
 *                  Switch 10 Option                    *
 * ******************************************************
 * SW_10_PIN             default not a pin              *        
 * SW_10_PRIORITY        default active low             *
 * SW_10_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_10_PIN                    NOT_A_PIN
#define     SW_10_PRIORITY               SW_ACTIVE_LOW
#define     SW_10_MODE                   MODE_INPUT_PULLUP

/*
 ********************************************************
 *                  Switch 11 Option                    *
 * ******************************************************
 * SW_11_PIN             default not a pin              *        
 * SW_11_PRIORITY        default active low             *
 * SW_11_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_11_PIN                    NOT_A_PIN
#define     SW_11_PRIORITY               SW_ACTIVE_LOW
#define     SW_11_MODE                   MODE_INPUT_PULLUP

/*
 ********************************************************
 *                  Switch 12 Option                    *
 * ******************************************************
 * SW_12_PIN             default not a pin              *        
 * SW_12_PRIORITY        default active low             *
 * SW_12_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_12_PIN                    NOT_A_PIN
#define     SW_12_PRIORITY               SW_ACTIVE_LOW
#define     SW_12_MODE                   MODE_INPUT_PULLUP

/*
 ********************************************************
 *                  Switch 13 Option                    *
 * ******************************************************
 * SW_13_PIN             default not a pin              *        
 * SW_13_PRIORITY        default active low             *
 * SW_13_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_13_PIN                    NOT_A_PIN
#define     SW_13_PRIORITY               SW_ACTIVE_LOW
#define     SW_13_MODE                   MODE_INPUT_PULLUP

/*
 ********************************************************
 *                  Switch 14 Option                    *
 * ******************************************************
 * SW_14_PIN             default not a pin              *        
 * SW_14_PRIORITY        default active low             *
 * SW_14_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_14_PIN                    NOT_A_PIN
#define     SW_14_PRIORITY               SW_ACTIVE_LOW
#define     SW_14_MODE                   MODE_INPUT_PULLUP


/*
 ********************************************************
 *                  Switch 15 Option                    *
 * ******************************************************
 * SW_15_PIN             default not a pin              *        
 * SW_15_PRIORITY        default active low             *
 * SW_15_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_15_PIN                    NOT_A_PIN
#define     SW_15_PRIORITY               SW_ACTIVE_LOW
#define     SW_15_MODE                   MODE_INPUT_PULLUP
/*
 ********************************************************
 *                  Switch 16 Option                    *
 * ******************************************************
 * SW_16_PIN             default not a pin              *        
 * SW_16_PRIORITY        default active low             *
 * SW_16_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_16_PIN                    NOT_A_PIN
#define     SW_16_PRIORITY               SW_ACTIVE_LOW
#define     SW_16_MODE                   MODE_INPUT_PULLUP

/*
 ********************************************************
 *                  Switch 17 Option                     *
 * ******************************************************
 * SW_17_PIN             default not a pin              *        
 * SW_17_PRIORITY        default active low             *
 * SW_17_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_17_PIN                    NOT_A_PIN
#define     SW_17_PRIORITY               SW_ACTIVE_LOW
#define     SW_17_MODE                   MODE_INPUT_PULLUP

/*
 ********************************************************
 *                  Switch 18 Option                    *
 * ******************************************************
 * SW_18_PIN             default not a pin              *        
 * SW_18_PRIORITY        default active low             *
 * SW_18_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_18_PIN                    NOT_A_PIN
#define     SW_18_PRIORITY               SW_ACTIVE_LOW
#define     SW_18_MODE                   MODE_INPUT_PULLUP

/*
 ********************************************************
 *                  Switch 19 Option                    *
 * ******************************************************
 * SW_19_PIN             default not a pin              *        
 * SW_19_PRIORITY        default active low             *
 * SW_19_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_19_PIN                    NOT_A_PIN
#define     SW_19_PRIORITY               SW_ACTIVE_LOW
#define     SW_19_MODE                   MODE_INPUT_PULLUP

/*
 ********************************************************
 *                  Switch 20 Option                    *
 * ******************************************************
 * SW_20_PIN             default not a pin              *        
 * SW_20_PRIORITY        default active low             *
 * SW_20_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_20_PIN                    NOT_A_PIN
#define     SW_20_PRIORITY               SW_ACTIVE_LOW
#define     SW_20_MODE                   MODE_INPUT_PULLUP

/*
 ********************************************************
 *                  Switch 21 Option                    *
 * ******************************************************
 * SW_21_PIN             default not a pin              *        
 * SW_21_PRIORITY        default active low             *
 * SW_21_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_21_PIN                    NOT_A_PIN
#define     SW_21_PRIORITY               SW_ACTIVE_LOW
#define     SW_21_MODE                   MODE_INPUT_PULLUP
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
#define     SW_23_PIN                    NOT_A_PIN
#define     SW_23_PRIORITY               SW_ACTIVE_LOW
#define     SW_23_MODE                   MODE_INPUT_PULLUP
/*
 ********************************************************
 *                  Switch 24 Option                     *
 * ******************************************************
 * SW_24_PIN             default not a pin              *        
 * SW_24_PRIORITY        default active low             *
 * SW_24_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_24_PIN                    NOT_A_PIN
#define     SW_24_PRIORITY               SW_ACTIVE_LOW
#define     SW_24_MODE                   MODE_INPUT_PULLUP


#endif
/*
 ***********************************************************************
 *                                KEYPAD Modules                       *
 * *********************************************************************
 */
#if (KEYPAD_MODULE)

/*
 ************************************************************
 *                    KEYPADs Option                        *
 * in this version the only keypad01 supported              *
 * **********************************************************
 */

#define  KEYPADS_BUFFER_LENGTH                        (8)

#define  KEYPAD01                                     (1)  /************** KEYPAD01 active/Deactive 1/0 ***************/
#define  KEYPAD02                                     (0) /************** KEYPAD02 active/Deactive 1/0 ***************/
#define  KEYPAD03                                     (0) /************** KEYPAD03 active/Deactive 1/0 ***************/
#define  KEYPAD04                                     (0) /************** KEYPAD04 active/Deactive 1/0 ***************/
/*
 **************************************************
 * keypads timing  apply for all keypads           *
 * ************************************************
 */
#define   KEYPAD_DEBOUND_DELAY              (20)
#define   KEYPAD_LONGPRESS_DELAY            (2000)
#define   KEYPAD_REPEAT_DELAY               (1000)
#define   KEYPAD_REPEAT_RATE                (5)/*char per sec*/

/*
 **************************************************
 * keypads OPTIONS                                *
 * ************************************************
 */

#if KEYPAD01
/*
 **************************************************
 *          FIRST KEYPAD Options                  *
 * ************************************************
 */
#define  KEYPAD01_MAX_COMMON                             (4)         // if not using   set value is zero 
#define  KEYPAD01_MAX_SWITCHES_PER_COMMON                (4)         /*8 switch per common*/
#define  KEYPAD01_SW_MODE                                 MODE_INPUT_PULLUP
#define  KEYPAD01_SW_POL                                  KEYPAD_SW_ACTIVE_LOW 
/*
 **************************************************
 *              keypad Commons Pins                *
 * ************************************************
 */

/*
 ********************************************************************************************
 *                              KEYPAD01_COMMONS_PINS                                       *
 * ******************************************************************************************
 */
/***********************KEYPAD01 C01********************/
#define  KEYPAD01_C01_PIN          GPIO_B6
/***********************KEYPAD01 C02********************/
#define  KEYPAD01_C02_PIN          GPIO_B7
/***********************KEYPAD01 C03********************/
#define  KEYPAD01_C03_PIN          GPIO_G3
/***********************KEYPAD01 C04********************/
#define  KEYPAD01_C04_PIN          GPIO_G4
/***********************KEYPAD01 C05********************/
#define  KEYPAD01_C05_PIN          NOT_A_PIN
/***********************KEYPAD01 C06********************/
#define  KEYPAD01_C06_PIN          NOT_A_PIN
/***********************KEYPAD01 C07********************/
#define  KEYPAD01_C07_PIN          NOT_A_PIN
/***********************KEYPAD01 C08********************/
#define  KEYPAD01_C08_PIN          NOT_A_PIN
/*
 ********************************************************************************************
 *                              KEYPAD01_SWITCH_PINS                                       *
 * ******************************************************************************************
 */
/***********************KEYPAD01 SW01********************/
#define  KEYPAD01_SW01_PIN          GPIO_E7
/***********************KEYPAD01 SW02********************/
#define  KEYPAD01_SW02_PIN          GPIO_B0
/***********************KEYPAD01 SW03********************/
#define  KEYPAD01_SW03_PIN          GPIO_B4
/***********************KEYPAD01 SW04********************/
#define  KEYPAD01_SW04_PIN          GPIO_B5
/***********************KEYPAD01 SW05********************/
#define  KEYPAD01_SW05_PIN          NOT_A_PIN
/***********************KEYPAD01 SW06********************/
#define  KEYPAD01_SW06_PIN          NOT_A_PIN
/***********************KEYPAD01 SW07********************/
#define  KEYPAD01_SW07_PIN          NOT_A_PIN
/***********************KEYPAD01 SW08********************/
#define  KEYPAD01_SW08_PIN          NOT_A_PIN
#endif


#endif
#if CSMA_CD_MODULE 
/*this values must with change value*/
#if defined (__AVR_ATmega8__)|| defined (__AVR_ATmega8A__)
#define     UART                        UASRT
#endif
#if defined (__AVR_ATmega328P__ ) || defined (__AVR_ATmega328__)||defined(__AVR_ATmega48A__)
#define     UART                        UART0
#endif

#define     BaudRate                   (StandBaudRate_19200)
#define     UART_MODE                   UARTAsyncNormalSpeed
#define     UARTFramFormat              FRAM_FORMAT_8BIT 
#define     UARTSTOPBIT                 STOPBIT_ONE 
#define     UARTParityMode              ParityMode_Disable
#define     COMM_TYPE                    CSMA_CD_WAITRECEIVE
#if DISPLAY_POINT
#define     CSMA_ADDRESS             (POINT_ADDRESS)
#else 
#define     CSMA_ADDRESS             (PIN_ADDRESS)
#endif
#if CALL_POINT_MASTER == 1
#define     DECIVE_TYPE                    (SLAVE)
#define      CSMA_A0                       GPIO_B1
#define      CSMA_A1                       GPIO_B2
#define      CSMA_A2                       GPIO_B3
#define      CSMA_A3                       GPIO_B4
#define      CSMA_A4                       GPIO_B5
#define      CSMA_A5                       GPIO_C0
#define      CSMA_A6                       GPIO_C1
#else
#define     DECIVE_TYPE                     (MASTER)
#endif
#endif 

#if TWI_MODULE 
#define            TWI_BUS_SPEED                        TWI_100KHZ
#define            TWI_ISR_ACTIVE                       TWI_POL
#define            TWI_PULLUP                           TWI_INTERNAL_PULLUP
#define            TWI_TYPE                             TWI_MASTER
#if (TWI_PULLUP==TWI_INTERNAL_PULLUP)
#define            TWI_SCL_PIN                              GPIO_D0
#define            TWI_SDA_PIN                              GPIO_D1

#endif

#endif 

#if RTC_MODULE 
#define     RTC_CLOCK_MODE              (RTC_MODE_24H)
#define     RTC_CLOCK_UPDATE             (5) // 5 per min
#endif

#if MENU_MODULE
#define         MENU_UP_SW                  KEYPAD01_SW04
#define         MENU_DOWN_SW                KEYPAD01_SW03
#define         MENU_ENTER_SW               KEYPAD01_SW01
#define         MENU_CENSEL_SW              KEYPAD01_SW05
#define         MAX_CHILD_PER_LINE          1
#endif

#if BUZ_MODULE
#define  BUZ_PIN                GPIO_C5
#define  BUZ_PIN_MODE_OUT       MODE_OUTPUT
#define  BUZ_ACTIVE             GPIO_HIGH
#endif 

#if SPI_MODULE
#define        SPI_MODE               SPI_MASTER_MODE
#define        SPI_CLK_MODE           SPI_SAMPLE_R
#define        SPI_CLOCK              SPI_CLOCK_64
#define        SPI_SPEED              SPI_NORMAL_SPEED
#define        SPI_DATA_SEND          SPI_MSB_FIRST
#define        SPI_SCLK_PIN            GPIO_B1
#define        SPI_MOSI_PIN            GPIO_B2
#define        SPI_MISO_PIN            GPIO_B3
#endif

#if SSSD_MODULE
#define   SSSD_MAX_DIVICES             (2)
#define   SSSD_DIR                     SSSD_RIGHT
#define  SSSD_PRINT_NEG_ALOW           SSSD_NEG_ALLOW
#endif

#if HX711_MODULE
#define     HX711_PD_SCK           GPIO_G0
#define     HX711_DOUT             GPIO_D7
#define     HX711_GAIN             Hx711_128
#define     HX711_LPF_Coffient     (6)
#define     HX711_RATE_TYPE        (HX711_RATE_HIGH)
#endif

#if KEYPADEVENT_MODULE 
#define   KEYPAD_MAX_EVENT           (1)
#endif
#endif

#if  defined(__AVR_ATmega128A__) || defined (__AVR_ATmega128__)



/*
 ***********************************************************************
 *                                Mega Modules                         *
 * *********************************************************************
 */
/*******************SYSTEM_MODULE*********************(active/de-active)(0/1)**************/
#define             SYSTEM_MODULE                               (1)  
/*******************LCD_MODULE************************(active/de-active)(0/1)**************/
#define             LCD_MODULE                                  (1)
#define             BUTTON_MODULE                               (0)
/*******************SSD_MODULE************************(active/de-active)(0/1)**************/
#define             SSD_MODULE                                  (0)
/**********************BUZ_MODULE*********************(active/de-active)(0/1)**************/
#define             BUZ_MODULE                                  (1)
/*******************KEYPAD_MODULE*********************(active/de-active)(0/1)**************/
#define             KEYPAD_MODULE                               (1)
/*******************RTC_MODULE************************(active/de-active)(0/1)**************/
#define             RTC_MODULE                                  (1)
/*******************RTC_MODULE************************(active/de-active)(0/1)**************/
#define             MENU_MODULE                                 (1)
/*******************SPI_MODULE************************(active/de-active)(0/1)**************/
#define             SPI_MODULE                                  (0)
/*******************SSSD_MODULE************************(active/de-active)(0/1)**************/
#define             SSSD_MODULE                                 (0)
/*******************HX711_MODULE************************(active/de-active)(0/1)**************/
#define             HX711_MODULE                                (0)
/*******************EEPROM_MODULE************************(active/de-active)(0/1)**************/
#define             EEPROM_MODULE                               (0)
/*******************KEYPADEVENT_MODULE************************(active/de-active)(0/1)**************/
#define            KEYPADEVENT_MODULE                           (0)
/*******************TWI_MODULE************************(active/de-active)(0/1)**************/
#define            TWI_MODULE                                   (1)
/*******************EX_EEPROM_MODULE************************(active/de-active)(0/1)**************/
#define            EX_EEPROM_MODULE                             (1)                                     
/*******************CSMA_CD_MODULE************************(active/de-active)(0/1)**************/
#define            CSMA_CD_MODULE                               (1)
/*
 ***********************************************************************
 *                                System Modules                       *
 * *********************************************************************
 */
#if SYSTEM_MODULE 
#define       APP_TASK                    (1)
#if SSD_MODULE
#define       SDD_TASK                    (1)
#endif

#if BUTTON_MODULE
#define     BUTTON_TASK                  (16)   // 20 ms
#endif

#if KEYPAD_MODULE
#define   KEYPAD_TASK                   (16)
#endif

#if RTC_MODULE
#define     RTC_TASK                     (8)
#endif

#if HX711_MODULE  

#define    HX711_READ_TASK              (4)
#endif


#if EX_EEPROM_MODULE
#define       EX_EEPROM_PAGE_SIZE          (32)
#endif


#define     MAX_TASK                    (16)
#endif
/*
 ***********************************************************************
 *                                LCD Modules                          *
 * *********************************************************************
 */
#if LCD_MODULE
#define   LCD_RW    GPIO_A2
#define   LCD_RS    GPIO_A3
#define   LCD_EN    GPIO_A4


#define   LCD_D4    GPIO_F7
#define   LCD_D5    GPIO_A5
#define   LCD_D6    GPIO_F6
#define   LCD_D7    GPIO_F1
#define   LCD_BL    GPIO_F5

#define   LCD_NUMBER_OF_LINE   (2)
#define   LCD_NUMBER_OF_BYTE  (16)

#endif
/*
 ***********************************************************************
 *                                SSD Modules                          *
 * *********************************************************************
 */
#if SSD_MODULE
#define     SSD_MAX_DIGIT             (8)
#define     SSD_TYPE_LED            SSD_COMMON_CATHOD

#define      SSD_DIGIT0_PIN          GPIO_C0
#define      SSD_DIGIT1_PIN          GPIO_C1
#define      SSD_DIGIT2_PIN          GPIO_C2
#define      SSD_DIGIT3_PIN          GPIO_C3
#define      SSD_DIGIT4_PIN          GPIO_C4
#define      SSD_DIGIT5_PIN          GPIO_C5
#define      SSD_DIGIT6_PIN          GPIO_C6
#define      SSD_DIGIT7_PIN          GPIO_C7

#define     SSD_DATA0_PIN       GPIO_E0
#define     SSD_DATA1_PIN       GPIO_E1
#define     SSD_DATA2_PIN       GPIO_E2
#define     SSD_DATA3_PIN       GPIO_E3
#define     SSD_DATA4_PIN       GPIO_E4
#define     SSD_DATA5_PIN       GPIO_E5
#define     SSD_DATA6_PIN       GPIO_E6
#define     SSD_DATA7_PIN       GPIO_E7

#endif
/*
 ***********************************************************************
 *                                BUTTON Modules                       *
 * *********************************************************************
 */
#if BUTTON_MODULE

/*
 *************************************************************
 *                       Switches                            *
 * ***********************************************************
 * MAX_BUTTONS                  default used one switch      *        
 * BUTTONS_BUFFER_LENGTH        max event store by default 4 *
 * ***********************************************************
 */
#define   MAX_BUTTONS       (4)
#define   BUTTONS_BUFFER_LENGTH  (4)


/*
 *************************************************************************************
 *                              Switch de-bounds & delays                            *
 * ***********************************************************************************
 * BUTTON_SCAN_TIME                   default as a 10 ms to scan switch              *        
 * BUTTON_RELEASE_DELAY               default as a 33 ms to action release           *
 * BUTTON_SHORTPRESS_DELAY            default as a 33 ms to action Press             *
 * BUTTON_LONGPRESS_DELAY             default as a 1000 ms to action long Press      *
 * BUTTON_REPEAT_DELAY                default as a 500 ms to  start repeat           *
 * BUTTON_REPEAT_RATE_DELAY           default as a 33 ms to action repeat per char   *
 * ***********************************************************************************
 */

#define   BUTTON_DEBOUND_DELAY              (20)
#define   BUTTON_LONGPRESS_DELAY            (5000)
#define   BUTTON_REPEAT_DELAY               (1000)
#define   BUTTON_REPEAT_RATE                (5)/*char per sec*/

/*
 ********************************************************
 *                  Switch 1 Option                     *
 * ******************************************************
 * SW_01_PIN             default not a pin              *        
 * SW_01_PRIORITY        default active low             *
 * SW_01_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_01_PIN                     GPIO_D3
#define     SW_01_PRIORITY               SW_ACTIVE_LOW
#define     SW_01_MODE                   MODE_INPUT_PULLUP

/*
 ********************************************************
 *                  Switch 2 Option                     *
 * ******************************************************
 * SW_02_PIN             default not a pin              *        
 * SW_02_PRIORITY        default active low             *
 * SW_02_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_02_PIN                    GPIO_D4
#define     SW_02_PRIORITY               SW_ACTIVE_LOW
#define     SW_02_MODE                   MODE_INPUT_PULLUP

/*
 ********************************************************
 *                  Switch 3 Option                     *
 * ******************************************************
 * SW_03_PIN             default not a pin              *        
 * SW_03_PRIORITY        default active low             *
 * SW_03_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_03_PIN                    GPIO_D5
#define     SW_03_PRIORITY               SW_ACTIVE_LOW
#define     SW_03_MODE                   MODE_INPUT_PULLUP

/*
 ********************************************************
 *                  Switch 4 Option                     *
 * ******************************************************
 * SW_04_PIN             default not a pin              *        
 * SW_04_PRIORITY        default active low             *
 * SW_04_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_04_PIN                    GPIO_D6
#define     SW_04_PRIORITY               SW_ACTIVE_LOW
#define     SW_04_MODE                   MODE_INPUT_PULLUP

/*
 ********************************************************
 *                  Switch 5 Option                     *
 * ******************************************************
 * SW_05_PIN             default not a pin              *        
 * SW_05_PRIORITY        default active low             *
 * SW_05_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_05_PIN                    NOT_A_PIN
#define     SW_05_PRIORITY               SW_ACTIVE_LOW
#define     SW_05_MODE                   MODE_INPUT_PULLUP

/*
 ********************************************************
 *                  Switch 6 Option                     *
 * ******************************************************
 * SW_06_PIN             default not a pin              *        
 * SW_06_PRIORITY        default active low             *
 * SW_06_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_06_PIN                    NOT_A_PIN
#define     SW_06_PRIORITY               SW_ACTIVE_LOW
#define     SW_06_MODE                   MODE_INPUT_PULLUP


/*
 ********************************************************
 *                  Switch 7 Option                     *
 * ******************************************************
 * SW_07_PIN             default not a pin              *        
 * SW_07_PRIORITY        default active low             *
 * SW_07_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_07_PIN                    NOT_A_PIN
#define     SW_07_PRIORITY               SW_ACTIVE_LOW
#define     SW_07_MODE                   MODE_INPUT_PULLUP
/*
 ********************************************************
 *                  Switch 8 Option                     *
 * ******************************************************
 * SW_08_PIN             default not a pin              *        
 * SW_08_PRIORITY        default active low             *
 * SW_08_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_08_PIN                    NOT_A_PIN
#define     SW_08_PRIORITY               SW_ACTIVE_LOW
#define     SW_08_MODE                   MODE_INPUT_PULLUP
/*
 ********************************************************
 *                  Switch 9 Option                     *
 * ******************************************************
 * SW_09_PIN             default not a pin              *        
 * SW_09_PRIORITY        default active low             *
 * SW_09_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_09_PIN                    NOT_A_PIN
#define     SW_09_PRIORITY               SW_ACTIVE_LOW
#define     SW_09_MODE                   MODE_INPUT_PULLUP

/*
 ********************************************************
 *                  Switch 10 Option                    *
 * ******************************************************
 * SW_10_PIN             default not a pin              *        
 * SW_10_PRIORITY        default active low             *
 * SW_10_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_10_PIN                    NOT_A_PIN
#define     SW_10_PRIORITY               SW_ACTIVE_LOW
#define     SW_10_MODE                   MODE_INPUT_PULLUP

/*
 ********************************************************
 *                  Switch 11 Option                    *
 * ******************************************************
 * SW_11_PIN             default not a pin              *        
 * SW_11_PRIORITY        default active low             *
 * SW_11_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_11_PIN                    NOT_A_PIN
#define     SW_11_PRIORITY               SW_ACTIVE_LOW
#define     SW_11_MODE                   MODE_INPUT_PULLUP

/*
 ********************************************************
 *                  Switch 12 Option                    *
 * ******************************************************
 * SW_12_PIN             default not a pin              *        
 * SW_12_PRIORITY        default active low             *
 * SW_12_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_12_PIN                    NOT_A_PIN
#define     SW_12_PRIORITY               SW_ACTIVE_LOW
#define     SW_12_MODE                   MODE_INPUT_PULLUP

/*
 ********************************************************
 *                  Switch 13 Option                    *
 * ******************************************************
 * SW_13_PIN             default not a pin              *        
 * SW_13_PRIORITY        default active low             *
 * SW_13_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_13_PIN                    NOT_A_PIN
#define     SW_13_PRIORITY               SW_ACTIVE_LOW
#define     SW_13_MODE                   MODE_INPUT_PULLUP

/*
 ********************************************************
 *                  Switch 14 Option                    *
 * ******************************************************
 * SW_14_PIN             default not a pin              *        
 * SW_14_PRIORITY        default active low             *
 * SW_14_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_14_PIN                    NOT_A_PIN
#define     SW_14_PRIORITY               SW_ACTIVE_LOW
#define     SW_14_MODE                   MODE_INPUT_PULLUP


/*
 ********************************************************
 *                  Switch 15 Option                    *
 * ******************************************************
 * SW_15_PIN             default not a pin              *        
 * SW_15_PRIORITY        default active low             *
 * SW_15_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_15_PIN                    NOT_A_PIN
#define     SW_15_PRIORITY               SW_ACTIVE_LOW
#define     SW_15_MODE                   MODE_INPUT_PULLUP
/*
 ********************************************************
 *                  Switch 16 Option                    *
 * ******************************************************
 * SW_16_PIN             default not a pin              *        
 * SW_16_PRIORITY        default active low             *
 * SW_16_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_16_PIN                    NOT_A_PIN
#define     SW_16_PRIORITY               SW_ACTIVE_LOW
#define     SW_16_MODE                   MODE_INPUT_PULLUP

/*
 ********************************************************
 *                  Switch 17 Option                     *
 * ******************************************************
 * SW_17_PIN             default not a pin              *        
 * SW_17_PRIORITY        default active low             *
 * SW_17_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_17_PIN                    NOT_A_PIN
#define     SW_17_PRIORITY               SW_ACTIVE_LOW
#define     SW_17_MODE                   MODE_INPUT_PULLUP

/*
 ********************************************************
 *                  Switch 18 Option                    *
 * ******************************************************
 * SW_18_PIN             default not a pin              *        
 * SW_18_PRIORITY        de
 * fault active low             *
 * SW_18_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_18_PIN                    NOT_A_PIN
#define     SW_18_PRIORITY               SW_ACTIVE_LOW
#define     SW_18_MODE                   MODE_INPUT_PULLUP

/*
 ********************************************************
 *                  Switch 19 Option                    *
 * ******************************************************
 * SW_19_PIN             default not a pin              *        
 * SW_19_PRIORITY        default active low             *
 * SW_19_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_19_PIN                    NOT_A_PIN
#define     SW_19_PRIORITY               SW_ACTIVE_LOW
#define     SW_19_MODE                   MODE_INPUT_PULLUP

/*
 ********************************************************
 *                  Switch 20 Option                    *
 * ******************************************************
 * SW_20_PIN             default not a pin              *        
 * SW_20_PRIORITY        default active low             *
 * SW_20_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_20_PIN                    NOT_A_PIN
#define     SW_20_PRIORITY               SW_ACTIVE_LOW
#define     SW_20_MODE                   MODE_INPUT_PULLUP

/*
 ********************************************************
 *                  Switch 21 Option                    *
 * ******************************************************
 * SW_21_PIN             default not a pin              *        
 * SW_21_PRIORITY        default active low             *
 * SW_21_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_21_PIN                    NOT_A_PIN
#define     SW_21_PRIORITY               SW_ACTIVE_LOW
#define     SW_21_MODE                   MODE_INPUT_PULLUP
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
#define     SW_23_PIN                    NOT_A_PIN
#define     SW_23_PRIORITY               SW_ACTIVE_LOW
#define     SW_23_MODE                   MODE_INPUT_PULLUP
/*
 ********************************************************
 *                  Switch 24 Option                     *
 * ******************************************************
 * SW_24_PIN             default not a pin              *        
 * SW_24_PRIORITY        default active low             *
 * SW_24_MODE            default mode input pull up     *
 * ******************************************************
 */
#define     SW_24_PIN                    NOT_A_PIN
#define     SW_24_PRIORITY               SW_ACTIVE_LOW
#define     SW_24_MODE                   MODE_INPUT_PULLUP


#endif
/*
 ***********************************************************************
 *                                KEYPAD Modules                       *
 * *********************************************************************
 */
#if (KEYPAD_MODULE)

/*
 ************************************************************
 *                    KEYPADs Option                        *
 * in this version the only keypad01 supported              *
 * **********************************************************
 */

#define  KEYPADS_BUFFER_LENGTH                        (8)

#define  KEYPAD01                                     (1)  /************** KEYPAD01 active/Deactive 1/0 ***************/
#define  KEYPAD02                                     (0) /************** KEYPAD02 active/Deactive 1/0 ***************/
#define  KEYPAD03                                     (0) /************** KEYPAD03 active/Deactive 1/0 ***************/
#define  KEYPAD04                                     (0) /************** KEYPAD04 active/Deactive 1/0 ***************/
/*
 **************************************************
 * keypads timing  apply for all keypads           *
 * ************************************************
 */
#define   KEYPAD_DEBOUND_DELAY              (20)
#define   KEYPAD_LONGPRESS_DELAY            (2000)
#define   KEYPAD_REPEAT_DELAY               (1000)
#define   KEYPAD_REPEAT_RATE                (5)/*char per sec*/

/*
 **************************************************
 * keypads OPTIONS                                *
 * ************************************************
 */

#if KEYPAD01
/*
 **************************************************
 *          FIRST KEYPAD Options                  *
 * ************************************************
 */
#define  KEYPAD01_MAX_COMMON                             (4)         // if not using   set value is zero 
#define  KEYPAD01_MAX_SWITCHES_PER_COMMON                (4)         /*8 switch per common*/
#define  KEYPAD01_SW_MODE                                 MODE_INPUT_PULLUP
#define  KEYPAD01_SW_POL                                  KEYPAD_SW_ACTIVE_LOW 
/*
 **************************************************
 *              keypad Commons Pins                *
 * ************************************************
 */

/*
 ********************************************************************************************
 *                              KEYPAD01_COMMONS_PINS                                       *
 * ******************************************************************************************
 */
/***********************KEYPAD01 C01********************/
#define  KEYPAD01_C01_PIN          GPIO_B6
/***********************KEYPAD01 C02********************/
#define  KEYPAD01_C02_PIN          GPIO_B7
/***********************KEYPAD01 C03********************/
#define  KEYPAD01_C03_PIN          GPIO_G3
/***********************KEYPAD01 C04********************/
#define  KEYPAD01_C04_PIN          GPIO_G4
/***********************KEYPAD01 C05********************/
#define  KEYPAD01_C05_PIN          NOT_A_PIN
/***********************KEYPAD01 C06********************/
#define  KEYPAD01_C06_PIN          NOT_A_PIN
/***********************KEYPAD01 C07********************/
#define  KEYPAD01_C07_PIN          NOT_A_PIN
/***********************KEYPAD01 C08********************/
#define  KEYPAD01_C08_PIN          NOT_A_PIN
/*
 ********************************************************************************************
 *                              KEYPAD01_SWITCH_PINS                                       *
 * ******************************************************************************************
 */
/***********************KEYPAD01 SW01********************/
#define  KEYPAD01_SW01_PIN          GPIO_B2
/***********************KEYPAD01 SW02********************/
#define  KEYPAD01_SW02_PIN          GPIO_B3
/***********************KEYPAD01 SW03********************/
#define  KEYPAD01_SW03_PIN          GPIO_B4
/***********************KEYPAD01 SW04********************/
#define  KEYPAD01_SW04_PIN          GPIO_B5
/***********************KEYPAD01 SW05********************/
#define  KEYPAD01_SW05_PIN          NOT_A_PIN
/***********************KEYPAD01 SW06********************/
#define  KEYPAD01_SW06_PIN          NOT_A_PIN
/***********************KEYPAD01 SW07********************/
#define  KEYPAD01_SW07_PIN          NOT_A_PIN
/***********************KEYPAD01 SW08********************/
#define  KEYPAD01_SW08_PIN          NOT_A_PIN
#endif


#endif

#if CSMA_CD_MODULE 
/*this values must with change value*/
#define     UART                        UART1
#define     BaudRate                   (StandBaudRate_19200)
#define     UART_MODE                   UARTAsyncNormalSpeed
#define     UARTFramFormat              FRAM_FORMAT_8BIT 
#define     UARTSTOPBIT                 STOPBIT_ONE 
#define     UARTParityMode              ParityMode_Disable
#define     COMM_TYPE                    CSMA_CD_WAITRECEIVE
#define     DECIVE_TYPE                 (MASTER)
#define      CSMA_A0                       NOT_A_PIN
#define      CSMA_A1                       NOT_A_PIN
#define      CSMA_A2                       NOT_A_PIN
#define      CSMA_A3                       NOT_A_PIN
#define      CSMA_A4                       NOT_A_PIN
#define      CSMA_A5                       NOT_A_PIN
#define      CSMA_A6                       NOT_A_PIN
#endif 
/*
 ***********************************************************************
 *                                I2C Modules                          *
 * *********************************************************************
 */
#if I2C_MODULE
#define            I2C_BUS_SPEED                        I2C_100KHZ
#define            I2C_ISR_ACTIVE                       I2C_ISR
#define            I2C_PULLUP                           I2C_INTERNAL_PULLUP
#define            I2C_TYPE                             I2C_MASTER
#if (I2C_PULLUP==I2C_INTERNAL_PULLUP)
#define            I2C_SCL_PIN                              GPIO_D0
#define            I2C_SDA_PIN                              GPIO_D1
#endif
#endif

#if TWI_MODULE 
#define            TWI_BUS_SPEED                        TWI_100KHZ
#define            TWI_ISR_ACTIVE                       TWI_POL
#define            TWI_PULLUP                           TWI_INTERNAL_PULLUP
#define            TWI_TYPE                             TWI_MASTER
#if (TWI_PULLUP==TWI_INTERNAL_PULLUP)
#define            TWI_SCL_PIN                              GPIO_D0
#define            TWI_SDA_PIN                              GPIO_D1
#endif
#endif 

#if RTC_MODULE 
#define     RTC_CLOCK_MODE              (RTC_MODE_24H)
#define     RTC_CLOCK_UPDATE             (5) // 5 per min
#endif

#if MENU_MODULE
#define         MENU_UP_SW                  KEYPAD01_SW04
#define         MENU_DOWN_SW                KEYPAD01_SW03
#define         MENU_ENTER_SW               KEYPAD01_SW01
#define         MENU_CENSEL_SW              KEYPAD01_SW05
#define         MAX_CHILD_PER_LINE          1
#endif

#if BUZ_MODULE
#define  BUZ_PIN                GPIO_F0
#define  BUZ_PIN_MODE_OUT       MODE_OUTPUT
#define  BUZ_ACTIVE             GPIO_HIGH
#endif 

#if SPI_MODULE
#define        SPI_MODE               SPI_MASTER_MODE
#define        SPI_CLK_MODE           SPI_SAMPLE_R
#define        SPI_CLOCK              SPI_CLOCK_64
#define        SPI_SPEED              SPI_NORMAL_SPEED
#define        SPI_DATA_SEND          SPI_MSB_FIRST
#define        SPI_SCLK_PIN            GPIO_B1
#define        SPI_MOSI_PIN            GPIO_B2
#define        SPI_MISO_PIN            GPIO_B3
#endif

#if SSSD_MODULE
#define   SSSD_MAX_DIVICES             (2)
#define   SSSD_DIR                     SSSD_RIGHT
#define  SSSD_PRINT_NEG_ALOW           SSSD_NEG_ALLOW
#endif

#if HX711_MODULE
#define     HX711_PD_SCK           GPIO_G0
#define     HX711_DOUT             GPIO_D7
#define     HX711_GAIN             Hx711_128
#define     HX711_LPF_Coffient     (6)
#define     HX711_RATE_TYPE        (HX711_RATE_HIGH)
#endif

#if KEYPADEVENT_MODULE 
#define   KEYPAD_MAX_EVENT           (1)
#endif

#endif

#endif	/* XC_RESOURCE_H */