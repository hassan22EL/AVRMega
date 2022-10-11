#include "../inc/mega.h"

int main(void) {
    appBoot();
    // Platform Init
    /*System */
#if SYSTEM_MODULE
    setupHwTimer0();
    systemTickInit();
#endif

#if LCD_MODULE
    lcdHwInit();
#endif

#if       CSMA_CD_MODULE 
    /*UART INIT*/
#if defined (__AVR_ATmega8__) ||  defined (__AVR_ATmega8A__)
    uart_init();
#else
    UART_INIT(UART_MODE, UARTFramFormat, UARTSTOPBIT, UARTParityMode);
#endif
    /*communication Init*/
#if (COMM_TYPE == CSMA_CD_WAITRECEIVE)
    csmaInit();
#endif
#endif



    /*communication driver*/
#if    CSMA_CD_MODULE
#if (COMM_TYPE == CSMA_CD_WAITRECEIVE)
    csmaInit();
#endif
#endif





#if BUTTON_MODULE
    buttonDriverInit();
#endif     

#if KEYPAD_MODULE
    keypadDriverInit();
#endif

#if I2C_MODULE
    I2cInit();
#endif  
#if TWI_MODULE
    Init_TWI();
#endif

#if MENU_MODULE
    MenuInit();
#endif

#if BUZ_MODULE
    buzInit();
#endif

#if EX_EEPROM_MODULE
    exEEPROMInit();
#endif
#if SPI_MODULE 
    spiInit();
#endif 

#if SSD_MODULE
    ssdInit();
#endif

#if SSSD_MODULE
    sssdInit();
#endif  

#if HX711_MODULE 
    hx711Init();
#endif

#if RTC_MODULE
    rtcInit();
#endif

#if KEYPADEVENT_MODULE
    keypadEventInit();
#endif
    /*app Init*/
    appInit();
    // Start Sys tick



#if SYSTEM_MODULE
    startHwTimer0();
#endif
    while (1) {


        // Platform Driver
        /*communication driver*/
#if  CSMA_CD_MODULE
#if (COMM_TYPE == CSMA_CD_WAITRECEIVE)
        csmaDriver();
#endif
#endif

        // Platform Driver
        /*communication driver*/
#if    COMMUNICATION_MODULE
#if (COMM_TYPE == CSMA_CD_WAITRECEIVE)
        commDriver();
#endif
#endif

#if RTC_MODULE 
        rtcDriver();
#endif

#if SSD_MODULE
        ssdDriver();
#endif 


#if MENU_MODULE
        menueDriver();
#endif


#if BUZ_MODULE
        buzDriver();
#endif

#if HX711_MODULE 
        hx711Driver();
#endif

#if KEYPADEVENT_MODULE
        keypadEvent();
#endif
        /*application*/
        appMain();
        // Check -> Sleep -> Re-Init
        // sysSleep();
    }
    return (0);
}

