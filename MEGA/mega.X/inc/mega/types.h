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
#ifndef XC_TPYES_H
#define	XC_TPYES_H



typedef uint8_t boolean_t;

typedef uint32_t tick_t;
typedef uint32_t millis_t;
typedef uint32_t time_t;

typedef void(*pFunc_t)(void);
typedef uint8_t(*pAsyncFunc_t)(void);


typedef uint8_t byte;
typedef uint16_t word;

typedef struct {
    tick_t Timer;
    tick_t Period;
} stTimer_t;

typedef struct {
    uint8_t Write;
    uint8_t Read;
    uint8_t Length;
    uint8_t Max_Length;
    uint8_t* Data_Buffer;

} stByteBufDescriptor_t;

typedef struct {
    uint8_t StructSize;
    stByteBufDescriptor_t stByteBufDescriptor;

} stBufferStructDescriptor_t;

typedef struct {
    uint8_t TlvCount;
    stByteBufDescriptor_t stByteBufDescriptor;

} stBufferTLVDescriptor_t;

typedef enum {
    state_00,
    state_01,
    state_02,
    state_03,
    state_04,
    state_05,
    state_06,
    state_07,
    state_08,
    state_09,
    state_10,
    state_11,
    state_12,
    state_13,
    state_14,
    state_15,
    state_16,
    state_17,
    state_18,
    state_19,
    state_20,
    state_21,
    state_22,
    state_23,
    state_24,
    state_25,
    state_26,
    state_27,
    state_28,
    state_29,
    state_30,
    state_31,
    state_32,
    state_33,
    state_34,
    state_35,
    state_36,
    state_37,
    state_38,
    state_39,
    state_40,
    state_41,
    state_42,
    state_43,
    state_44,
    state_45,
    state_46,
    state_47,
    state_48,
    state_49,
    state_50,
    state_51,
    state_52,
    state_53,
    state_54,
    state_55,
    state_56,
    state_57,
    state_58,
    state_59,
    state_60,
    state_61,
    state_62,
    state_63,
    state_64,
    state_65,
    state_66,
    state_67,
    state_68,
    state_69,
    state_70,
    state_71,
    state_72,
    state_73,
    state_74,
    state_75,
    state_76,
    state_77,
    state_78,
    state_79,
    state_80,
    state_81,
    state_82,
    state_83,
    state_84,
    state_85,
    state_86,
    state_87,
    state_88,
    state_89,
    state_90,
    state_91,
    state_92,
    state_93,
    state_94,
    state_95,
    state_96,
    state_97,
    state_98,
    state_99
} States_t;

#endif	/* XC_TPYES_H */

