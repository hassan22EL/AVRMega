#include "../../inc/mega.h"

#if SYSTEM_MODULE
volatile tick_t gSystemTick;
volatile uint8_t gTaskTick;
volatile uint8_t gu8ErrorCode;


#if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega328__)
#define      TIMER0_INTERRUPT_COMP_vet       TIMER0_COMPA_vect  
#endif


#if  defined(__AVR_ATmega128A__) || defined (__AVR_ATmega128__) 
#define      TIMER0_INTERRUPT_COMP_vet       TIMER0_COMP_vect
#endif 

#if defined (__AVR_ATmega8__)||defined (__AVR_ATmega8A__)  ||defined (__AVR_ATmega48A__)
#define      TIMER0_INTERRUPT_COMP_vet       TIMER0_OVF_vect
#endif

ISR(TIMER0_INTERRUPT_COMP_vet) {
    gSystemTick++;
#if SSD_MODULE
    if ((gTaskTick % SDD_TASK) == 0) {
        ssdSync();
    }
#endif


#if  BUTTON_MODULE
    if ((gTaskTick % BUTTON_TASK) == 0) {
        buttonSync(); // run task every button task
    }
#endif  


#if  KEYPAD_MODULE
    if ((gTaskTick % KEYPAD_TASK) == 0) {
        keypadSync(); // run task every button task
    }
#endif

#if RTC_MODULE
    if ((gTaskTick % RTC_TASK) == 0) {
        rtcSync(); // run task every 10ms 
    }
#endif

#if HX711_MODULE
    if ((gTaskTick % HX711_READ_TASK) == 0) {
        hx711Sync();
    }
#endif
    if ((gTaskTick % APP_TASK) == 0) {
        appSync();
    }
    if (++gTaskTick == MAX_TASK) {
        gTaskTick = 0;
    }

#if defined (__AVR_ATmega8__)||defined (__AVR_ATmega8A__)  
    TCNT0 = 0xFF - TIMER_VALUE;
#endif    

}

void systemTickInit() {
    gSystemTick = 0;
    gTaskTick = 0;
}

tick_t getSystemTick() {
    tick_t tick;
    ATOMIC_BEGIN
    tick = gSystemTick;
    ATOMIC_END
    return (tick);
}

uint8_t sysIsTimeout(stTimer_t * psTimer) {
    tick_t End, Current;

    if (psTimer->Period > (TIMER_MAX)) {
        //error case
        return (0);
    }
    End = psTimer->Timer + psTimer->Period;
    Current = getSystemTick();
    if (((Current ^ End) & (TIMER_MAX + 1)) == 0) {
        if (Current >= End) {
            return (1);
        }
    }
    return (0);
}
uint8_t sysTimerInitMS(stTimer_t *psTimer, millis_t Delay, millis_t Period) {
    /*load period  or delay*/
    tick_t tickDelay, tickPeriod;

    tickDelay = 0;
    tickPeriod = 0;

    if ((Delay) != 0) {
        tickDelay = (msToTicks(Delay));
    }

    if ((Period) != 0) {
        tickPeriod = (msToTicks(Period));
    }
    return (sysTimerInit(psTimer, tickDelay, tickPeriod));
}

uint8_t sysTimerInit(stTimer_t *psTimer, tick_t tickDelay, tick_t tickPeriod) {
    if (tickDelay < TICK_MAX) {
        if (tickDelay > TIMER_MAX) {
            tickDelay = TIMER_MAX;
        }
    }
    if (tickPeriod < TICK_MAX) {
        if (tickPeriod > TIMER_MAX) {
            tickPeriod = TIMER_MAX;
        }
    }
    psTimer->Timer = getSystemTick();
    if (tickDelay != 0) {
        psTimer->Timer += tickDelay;
    } else {
        psTimer->Timer += tickPeriod;
    }
    psTimer->Period = tickPeriod;

    return (RET_TRUE);
}

void sysTimerReset(stTimer_t * psTimer) {
    /*reload period and add current time */
    psTimer->Timer = psTimer->Period;
    psTimer->Timer += getSystemTick();
}

uint8_t sysTimerCheck(stTimer_t * psTimer) {
    tick_t systick;

    if (psTimer->Period == TICK_MAX) {
        return (RET_FALSE);
    }
    systick = getSystemTick();
    if ((((systick) ^ (psTimer->Timer)) & ((TIMER_MAX) + 1)) == 0) {
        if (systick >= psTimer->Timer) {
            if (psTimer->Period != 0) {
                psTimer->Timer += psTimer->Period;
            } else {
                psTimer->Period = TICK_MAX;
            }
            return (RET_TRUE);
        }
    }
    return (RET_FALSE);
}

#endif