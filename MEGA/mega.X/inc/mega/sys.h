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
 * File:   System 
 * Author:Hassan Elsaied Mohamed Mohammed 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_SYS_H
#define	XC_SYS_H

extern volatile uint8_t gu8ErrorCode;

#include "../mega.h"
/*
 ****************************************************************************
 *                             MARCRO                                       *
 ****************************************************************************
 * 
 */
//Timers

#ifndef F_CPU 
#warning Please define F_CPU 
#endif 

#define RET_TRUE   (0)
#define RET_FALSE  (1)

#define TICK_MAX  (0xFFFFFFFFUL)
#define TIMER_MAX (0x7FFFFFFFUL)






//Sleep mode
#define USE_IDLE_SLEEP      (0<<SM0)|(0<<SM1)|(1<<SE)|(0<<SM2)
#ifdef SYS_TICK
#define SYS_HW_TICK         (SYS_TICK)  //  TIME_PREIOD
#else 
#define SYS_HW_TICK         (1250UL)  //1.25ms  TIME_PREIOD
#endif


#define   msTOus            (1000UL)  
#define TMR0_FREQUNCY      ((1000000UL)/(SYS_HW_TICK)) // TMR0_FREQUNCY = 1/TIME_PREIOD ==> 1/(SYS_HW_TICK*10^-6) = (10^6/SYS_HW_TICK)



/**
 * TMR0_FREQUNCY = (F_CPU / (N(R+1))  //N==>TMR0_PRESCALLER , R ==>REGSISTER_VALUE 
 */
#define REGSISTER_MAX_VALUE  (0xFF)      //2^8 -1  = 255  in hexdecimal becouse timer 0 as 8 bit witdth
#define  DIVIDCLOCK      (2UL)
#define  PRESCARE_1      (1UL)
#define  PRESCARE_8      (8UL) 
#define  PRESCARE_64     (64UL) 
#define  PRESCARE_256    (256UL) 
#define  PRESCARE_1024   (1024UL) 


#define EQUATIONS_1           ((F_CPU) / ((PRESCARE_1)    * ((REGSISTER_MAX_VALUE) + 1UL)))
#define EQUATIONS_8           ((F_CPU) / ((PRESCARE_8)    * ((REGSISTER_MAX_VALUE) + 1UL)))
#define EQUATIONS_64          ((F_CPU) / ((PRESCARE_64)   * ((REGSISTER_MAX_VALUE) + 1UL)))
#define EQUATIONS_256         ((F_CPU) / ((PRESCARE_256)  * ((REGSISTER_MAX_VALUE) + 1UL)))
#define EQUATIONS_1024        ((F_CPU) / ((PRESCARE_1024) * ((REGSISTER_MAX_VALUE) + 1UL)))

#if    (EQUATIONS_1 < TMR0_FREQUNCY )
#define  TMR0_PS			(0x01)          // no prescaling
#define  TMR0_PRESCALLER    (PRESCARE_1)
#elif    (EQUATIONS_8 < TMR0_FREQUNCY )
#define   TMR0_PS		(0x02)         // 8 prescaler
#define  TMR0_PRESCALLER    (PRESCARE_8)
#elif  (EQUATIONS_64 < TMR0_FREQUNCY )
#if  defined(__AVR_ATmega128A__) || defined (__AVR_ATmega128__)
#define TMR0_PS		(0x04)        // 64 prescaler
#endif
#if defined (__AVR_ATmega328P__ ) || defined (__AVR_ATmega328__) ||defined (__AVR_ATmega8__)||defined (__AVR_ATmega8A__)  
#define TMR0_PS		(0x03)        // 64 prescaler
#endif
#define  TMR0_PRESCALLER   (PRESCARE_64)
#elif    (EQUATIONS_256 < TMR0_FREQUNCY)
#define TMR0_PS		(0x04)	   // 256 prescaler
#define  TMR0_PRESCALLER  (PRESCARE_256)
#elif    (EQUATIONS_1024 < TMR0_FREQUNCY)
#define  TMR0_PS		(0x05)      // 1024 prescaler
#define  TMR0_PRESCALLER   (PRESCARE_1024)
#else
#error TIMER0 settings For actual SYS_TICK , Wrong TIMER_FREQUENCY
#endif


#define   TIMER_VALUE                    (((F_CPU) / ((TMR0_FREQUNCY) * (TMR0_PRESCALLER))) - 1UL)



#define   __msToTicks(ms)                (((ms) * (msTOus) + ((1UL/2UL) * (SYS_HW_TICK)))/ (SYS_HW_TICK))
#define   _msToTicks(ms)                 ((__msToTicks(ms) > TIMER_MAX) ? TIMER_MAX : __msToTicks(ms))
#define    msToTicks(ms)                  (((ms) == 0) ? 0 : ((_msToTicks(ms) == 0) ? 1 : (_msToTicks(ms))))
#define    TicksToMs(tick)                 ((tick > TIMER_MAX) ? ((TIMER_MAX*SYS_HW_TICK + ((1/2UL) * msTOus))/msTOus) : (((tick*SYS_HW_TICK) + ((1/2UL) * msTOus))/msTOus))




static inline void stopHwTimer0();
static inline void setupHwTimer0();
static inline void startHwTimer0();
static inline void Sleep();
static inline void sysSetTimer(stTimer_t *psTimer, tick_t Timer);
static inline void sysSetPeriod(stTimer_t *psTimer, tick_t Period);
static inline void sysSetPeriodMS(stTimer_t* psTimer, millis_t Period);

static inline void setupHwTimer0() __attribute__((always_inline, unused));

static inline void setupHwTimer0() {
#if defined (__AVR_ATmega328P__ ) || defined (__AVR_ATmega328__)
    TCCR0A |= (0 << WGM00) | (1 << WGM01) | (0 << COM0A0) | (0 << COM0A1) | (0 << COM0B0) | (0 << COM0B1);
    TCCR0B |= (TMR0_PS) | (0 << WGM02);
    OCR0A = TIMER_VALUE;
    TCNT0 = 0x00;
    OCR0B = 0x00;

#endif

#if  defined(__AVR_ATmega128A__) || defined (__AVR_ATmega128__) 
    TCCR0 |= (0 << WGM00) | (1 << WGM01) | (0 << COM00) | (1 << COM01);
    TCCR0 |= (TMR0_PS);
    OCR0 = TIMER_VALUE;
    TCNT0 = 0x00;
#endif  

#if defined (__AVR_ATmega8__) || defined (__AVR_ATmega8A__)  
    TCCR0 |= TMR0_PS;
    TCNT0 = 0xFF - TIMER_VALUE;
#endif


}

static inline void startHwTimer0() __attribute__((always_inline, unused));

static inline void startHwTimer0() {
#if defined (__AVR_ATmega328P__ ) || defined (__AVR_ATmega328__)
    TIMSK0 |= (1 << OCIE0A); // Enable interrupt
#endif 

#if  defined(__AVR_ATmega128A__) || defined (__AVR_ATmega128__) 
    TIMSK |= (1 << OCIE0); // Enable interrupt
#endif   
#if defined (__AVR_ATmega8__) ||defined (__AVR_ATmega8A__)  
    TIMSK |= (1 << TOIE0);
#endif
    sei();
}
static inline void stopHwTimer0() __attribute__((always_inline, unused));

static inline void stopHwTimer0() {
    cli(); //
#if defined (__AVR_ATmega328P__ ) || defined (__AVR_ATmega328__)
    TIMSK0 &= ~(1 << OCIE0A); // Enable interrupt
#endif

#if  defined(__AVR_ATmega128A__) || defined (__AVR_ATmega128__) 
    TIMSK &= ~(1 << OCIE0); // Enable interrupt
#endif

#if defined (__AVR_ATmega8__)|| defined (__AVR_ATmega8A__)  
    TIMSK &= ~(1 << TOIE0);
#endif


}
static inline void Sleep() __attribute__((always_inline, unused));

static inline void Sleep() {
    MCUCR = USE_IDLE_SLEEP;
}
static inline void sysSetTimer(stTimer_t *psTimer, tick_t Timer) __attribute__((always_inline, unused));
static inline void sysSetTimer(stTimer_t *psTimer, tick_t Timer) {
    psTimer->Timer = Timer;
}
static inline void sysSetPeriod(stTimer_t *psTimer, tick_t Period) __attribute__((always_inline, unused));
static inline void sysSetPeriod(stTimer_t *psTimer, tick_t Period) {
    psTimer->Period = Period;
}
static inline void sysSetPeriodMS(stTimer_t *psTimer, millis_t Period) __attribute__((always_inline, unused));
static inline void sysSetPeriodMS(stTimer_t* psTimer, millis_t Period) {
    psTimer->Period = msToTicks(Period);
}


void systemTickInit();

tick_t getSystemTick();

uint8_t sysTimerInitMS(stTimer_t *psTimer, millis_t Delay, millis_t Period);

uint8_t sysTimerInit(stTimer_t *psTimer, tick_t tickDelay, tick_t tickPeriod);

uint8_t sysIsTimeout(stTimer_t *psTimer);

void sysTimerReset(stTimer_t *psTimer);

uint8_t sysTimerCheck(stTimer_t *psTimer);


#endif	/* XC_SYSTEMTICK_H */

