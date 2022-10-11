#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-Atmega128A.mk)" "nbproject/Makefile-local-Atmega128A.mk"
include nbproject/Makefile-local-Atmega128A.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=Atmega128A
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=a
DEBUGGABLE_SUFFIX=a
FINAL_IMAGE=${DISTDIR}/mega.X.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=a
DEBUGGABLE_SUFFIX=a
FINAL_IMAGE=${DISTDIR}/mega.X.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=src/mega/sys.c src/mega/lcd.c src/mega/buffers.c src/mega/button.c src/mega/keypad.c src/mega/rtc.c src/mega/menu.c inc/mega/buz.c src/mega/spi.c src/mega/sssd.c src/mega/hx711.c src/mega/eeprom.c src/mega/keypadEvent.c D:/Company/SMART/MEGA/mega.X/src/mega/exEEPROM.c D:/Company/SMART/MEGA/mega.X/src/mega/gpio.c D:/Company/SMART/MEGA/mega.X/src/mega/csma_cd.c src/mega/utility.c src/mega/SSD.c src/mega/twi.c src/mega.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/mega/sys.o ${OBJECTDIR}/src/mega/lcd.o ${OBJECTDIR}/src/mega/buffers.o ${OBJECTDIR}/src/mega/button.o ${OBJECTDIR}/src/mega/keypad.o ${OBJECTDIR}/src/mega/rtc.o ${OBJECTDIR}/src/mega/menu.o ${OBJECTDIR}/inc/mega/buz.o ${OBJECTDIR}/src/mega/spi.o ${OBJECTDIR}/src/mega/sssd.o ${OBJECTDIR}/src/mega/hx711.o ${OBJECTDIR}/src/mega/eeprom.o ${OBJECTDIR}/src/mega/keypadEvent.o ${OBJECTDIR}/_ext/88461258/exEEPROM.o ${OBJECTDIR}/_ext/88461258/gpio.o ${OBJECTDIR}/_ext/88461258/csma_cd.o ${OBJECTDIR}/src/mega/utility.o ${OBJECTDIR}/src/mega/SSD.o ${OBJECTDIR}/src/mega/twi.o ${OBJECTDIR}/src/mega.o
POSSIBLE_DEPFILES=${OBJECTDIR}/src/mega/sys.o.d ${OBJECTDIR}/src/mega/lcd.o.d ${OBJECTDIR}/src/mega/buffers.o.d ${OBJECTDIR}/src/mega/button.o.d ${OBJECTDIR}/src/mega/keypad.o.d ${OBJECTDIR}/src/mega/rtc.o.d ${OBJECTDIR}/src/mega/menu.o.d ${OBJECTDIR}/inc/mega/buz.o.d ${OBJECTDIR}/src/mega/spi.o.d ${OBJECTDIR}/src/mega/sssd.o.d ${OBJECTDIR}/src/mega/hx711.o.d ${OBJECTDIR}/src/mega/eeprom.o.d ${OBJECTDIR}/src/mega/keypadEvent.o.d ${OBJECTDIR}/_ext/88461258/exEEPROM.o.d ${OBJECTDIR}/_ext/88461258/gpio.o.d ${OBJECTDIR}/_ext/88461258/csma_cd.o.d ${OBJECTDIR}/src/mega/utility.o.d ${OBJECTDIR}/src/mega/SSD.o.d ${OBJECTDIR}/src/mega/twi.o.d ${OBJECTDIR}/src/mega.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/mega/sys.o ${OBJECTDIR}/src/mega/lcd.o ${OBJECTDIR}/src/mega/buffers.o ${OBJECTDIR}/src/mega/button.o ${OBJECTDIR}/src/mega/keypad.o ${OBJECTDIR}/src/mega/rtc.o ${OBJECTDIR}/src/mega/menu.o ${OBJECTDIR}/inc/mega/buz.o ${OBJECTDIR}/src/mega/spi.o ${OBJECTDIR}/src/mega/sssd.o ${OBJECTDIR}/src/mega/hx711.o ${OBJECTDIR}/src/mega/eeprom.o ${OBJECTDIR}/src/mega/keypadEvent.o ${OBJECTDIR}/_ext/88461258/exEEPROM.o ${OBJECTDIR}/_ext/88461258/gpio.o ${OBJECTDIR}/_ext/88461258/csma_cd.o ${OBJECTDIR}/src/mega/utility.o ${OBJECTDIR}/src/mega/SSD.o ${OBJECTDIR}/src/mega/twi.o ${OBJECTDIR}/src/mega.o

# Source Files
SOURCEFILES=src/mega/sys.c src/mega/lcd.c src/mega/buffers.c src/mega/button.c src/mega/keypad.c src/mega/rtc.c src/mega/menu.c inc/mega/buz.c src/mega/spi.c src/mega/sssd.c src/mega/hx711.c src/mega/eeprom.c src/mega/keypadEvent.c D:/Company/SMART/MEGA/mega.X/src/mega/exEEPROM.c D:/Company/SMART/MEGA/mega.X/src/mega/gpio.c D:/Company/SMART/MEGA/mega.X/src/mega/csma_cd.c src/mega/utility.c src/mega/SSD.c src/mega/twi.c src/mega.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-Atmega128A.mk ${DISTDIR}/mega.X.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega128A
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/mega/sys.o: src/mega/sys.c  .generated_files/flags/Atmega128A/4b0301ab38682b9918cfeb532d3595dacc7b5d99 .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/sys.o.d 
	@${RM} ${OBJECTDIR}/src/mega/sys.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/sys.o.d" -MT "${OBJECTDIR}/src/mega/sys.o.d" -MT ${OBJECTDIR}/src/mega/sys.o -o ${OBJECTDIR}/src/mega/sys.o src/mega/sys.c 
	
${OBJECTDIR}/src/mega/lcd.o: src/mega/lcd.c  .generated_files/flags/Atmega128A/2cac5fc8f4e482919d10f479c1ed8118dcacd8c8 .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/lcd.o.d 
	@${RM} ${OBJECTDIR}/src/mega/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/lcd.o.d" -MT "${OBJECTDIR}/src/mega/lcd.o.d" -MT ${OBJECTDIR}/src/mega/lcd.o -o ${OBJECTDIR}/src/mega/lcd.o src/mega/lcd.c 
	
${OBJECTDIR}/src/mega/buffers.o: src/mega/buffers.c  .generated_files/flags/Atmega128A/5de19c9af28d425c34df6172981b85a225364ee5 .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/buffers.o.d 
	@${RM} ${OBJECTDIR}/src/mega/buffers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/buffers.o.d" -MT "${OBJECTDIR}/src/mega/buffers.o.d" -MT ${OBJECTDIR}/src/mega/buffers.o -o ${OBJECTDIR}/src/mega/buffers.o src/mega/buffers.c 
	
${OBJECTDIR}/src/mega/button.o: src/mega/button.c  .generated_files/flags/Atmega128A/aa9670f25a524d7bf175671e0ba68af299557a36 .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/button.o.d 
	@${RM} ${OBJECTDIR}/src/mega/button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/button.o.d" -MT "${OBJECTDIR}/src/mega/button.o.d" -MT ${OBJECTDIR}/src/mega/button.o -o ${OBJECTDIR}/src/mega/button.o src/mega/button.c 
	
${OBJECTDIR}/src/mega/keypad.o: src/mega/keypad.c  .generated_files/flags/Atmega128A/d9a0baf7511116f3d86306af8e9e8a4bce03fe01 .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/keypad.o.d 
	@${RM} ${OBJECTDIR}/src/mega/keypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/keypad.o.d" -MT "${OBJECTDIR}/src/mega/keypad.o.d" -MT ${OBJECTDIR}/src/mega/keypad.o -o ${OBJECTDIR}/src/mega/keypad.o src/mega/keypad.c 
	
${OBJECTDIR}/src/mega/rtc.o: src/mega/rtc.c  .generated_files/flags/Atmega128A/889b120d816f627e117f12aa0d7e2f9566ffef99 .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/rtc.o.d 
	@${RM} ${OBJECTDIR}/src/mega/rtc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/rtc.o.d" -MT "${OBJECTDIR}/src/mega/rtc.o.d" -MT ${OBJECTDIR}/src/mega/rtc.o -o ${OBJECTDIR}/src/mega/rtc.o src/mega/rtc.c 
	
${OBJECTDIR}/src/mega/menu.o: src/mega/menu.c  .generated_files/flags/Atmega128A/1cf98783ff8178c0e63ae49f401fe9d915ff3b4a .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/menu.o.d 
	@${RM} ${OBJECTDIR}/src/mega/menu.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/menu.o.d" -MT "${OBJECTDIR}/src/mega/menu.o.d" -MT ${OBJECTDIR}/src/mega/menu.o -o ${OBJECTDIR}/src/mega/menu.o src/mega/menu.c 
	
${OBJECTDIR}/inc/mega/buz.o: inc/mega/buz.c  .generated_files/flags/Atmega128A/3dc55e4ccbd619d22a4106700aaaba8322ce6cc3 .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/inc/mega" 
	@${RM} ${OBJECTDIR}/inc/mega/buz.o.d 
	@${RM} ${OBJECTDIR}/inc/mega/buz.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/inc/mega/buz.o.d" -MT "${OBJECTDIR}/inc/mega/buz.o.d" -MT ${OBJECTDIR}/inc/mega/buz.o -o ${OBJECTDIR}/inc/mega/buz.o inc/mega/buz.c 
	
${OBJECTDIR}/src/mega/spi.o: src/mega/spi.c  .generated_files/flags/Atmega128A/d036f4be96f0686cd4361d20f28c5538d2b396e9 .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/spi.o.d 
	@${RM} ${OBJECTDIR}/src/mega/spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/spi.o.d" -MT "${OBJECTDIR}/src/mega/spi.o.d" -MT ${OBJECTDIR}/src/mega/spi.o -o ${OBJECTDIR}/src/mega/spi.o src/mega/spi.c 
	
${OBJECTDIR}/src/mega/sssd.o: src/mega/sssd.c  .generated_files/flags/Atmega128A/29afb073cbecf96256f8fc986133ddd608b52d8c .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/sssd.o.d 
	@${RM} ${OBJECTDIR}/src/mega/sssd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/sssd.o.d" -MT "${OBJECTDIR}/src/mega/sssd.o.d" -MT ${OBJECTDIR}/src/mega/sssd.o -o ${OBJECTDIR}/src/mega/sssd.o src/mega/sssd.c 
	
${OBJECTDIR}/src/mega/hx711.o: src/mega/hx711.c  .generated_files/flags/Atmega128A/7a5c3581cad193bb3e0f9be3c09fba880a349612 .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/hx711.o.d 
	@${RM} ${OBJECTDIR}/src/mega/hx711.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/hx711.o.d" -MT "${OBJECTDIR}/src/mega/hx711.o.d" -MT ${OBJECTDIR}/src/mega/hx711.o -o ${OBJECTDIR}/src/mega/hx711.o src/mega/hx711.c 
	
${OBJECTDIR}/src/mega/eeprom.o: src/mega/eeprom.c  .generated_files/flags/Atmega128A/2f3e575a9d853642d0f101c6337b565fe3e9803b .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/eeprom.o.d 
	@${RM} ${OBJECTDIR}/src/mega/eeprom.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/eeprom.o.d" -MT "${OBJECTDIR}/src/mega/eeprom.o.d" -MT ${OBJECTDIR}/src/mega/eeprom.o -o ${OBJECTDIR}/src/mega/eeprom.o src/mega/eeprom.c 
	
${OBJECTDIR}/src/mega/keypadEvent.o: src/mega/keypadEvent.c  .generated_files/flags/Atmega128A/f255a403bc8a5f90fd2d52c71f20e24cfa60918b .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/keypadEvent.o.d 
	@${RM} ${OBJECTDIR}/src/mega/keypadEvent.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/keypadEvent.o.d" -MT "${OBJECTDIR}/src/mega/keypadEvent.o.d" -MT ${OBJECTDIR}/src/mega/keypadEvent.o -o ${OBJECTDIR}/src/mega/keypadEvent.o src/mega/keypadEvent.c 
	
${OBJECTDIR}/_ext/88461258/exEEPROM.o: D:/Company/SMART/MEGA/mega.X/src/mega/exEEPROM.c  .generated_files/flags/Atmega128A/82e471f440253fa9079d20502f892a13992f0e91 .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/_ext/88461258" 
	@${RM} ${OBJECTDIR}/_ext/88461258/exEEPROM.o.d 
	@${RM} ${OBJECTDIR}/_ext/88461258/exEEPROM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/88461258/exEEPROM.o.d" -MT "${OBJECTDIR}/_ext/88461258/exEEPROM.o.d" -MT ${OBJECTDIR}/_ext/88461258/exEEPROM.o -o ${OBJECTDIR}/_ext/88461258/exEEPROM.o D:/Company/SMART/MEGA/mega.X/src/mega/exEEPROM.c 
	
${OBJECTDIR}/_ext/88461258/gpio.o: D:/Company/SMART/MEGA/mega.X/src/mega/gpio.c  .generated_files/flags/Atmega128A/e28159c0e1aec512dac935b25189fd3fc24e3d6f .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/_ext/88461258" 
	@${RM} ${OBJECTDIR}/_ext/88461258/gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/88461258/gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/88461258/gpio.o.d" -MT "${OBJECTDIR}/_ext/88461258/gpio.o.d" -MT ${OBJECTDIR}/_ext/88461258/gpio.o -o ${OBJECTDIR}/_ext/88461258/gpio.o D:/Company/SMART/MEGA/mega.X/src/mega/gpio.c 
	
${OBJECTDIR}/_ext/88461258/csma_cd.o: D:/Company/SMART/MEGA/mega.X/src/mega/csma_cd.c  .generated_files/flags/Atmega128A/d827e019fd5789b573cb6f88d144fb1143b72c00 .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/_ext/88461258" 
	@${RM} ${OBJECTDIR}/_ext/88461258/csma_cd.o.d 
	@${RM} ${OBJECTDIR}/_ext/88461258/csma_cd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/88461258/csma_cd.o.d" -MT "${OBJECTDIR}/_ext/88461258/csma_cd.o.d" -MT ${OBJECTDIR}/_ext/88461258/csma_cd.o -o ${OBJECTDIR}/_ext/88461258/csma_cd.o D:/Company/SMART/MEGA/mega.X/src/mega/csma_cd.c 
	
${OBJECTDIR}/src/mega/utility.o: src/mega/utility.c  .generated_files/flags/Atmega128A/2af17ec6961b4e32fac029486051aa01b701e5c7 .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/utility.o.d 
	@${RM} ${OBJECTDIR}/src/mega/utility.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/utility.o.d" -MT "${OBJECTDIR}/src/mega/utility.o.d" -MT ${OBJECTDIR}/src/mega/utility.o -o ${OBJECTDIR}/src/mega/utility.o src/mega/utility.c 
	
${OBJECTDIR}/src/mega/SSD.o: src/mega/SSD.c  .generated_files/flags/Atmega128A/289fcc9f31c0d4ee290191ae462019f74f9740f0 .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/SSD.o.d 
	@${RM} ${OBJECTDIR}/src/mega/SSD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/SSD.o.d" -MT "${OBJECTDIR}/src/mega/SSD.o.d" -MT ${OBJECTDIR}/src/mega/SSD.o -o ${OBJECTDIR}/src/mega/SSD.o src/mega/SSD.c 
	
${OBJECTDIR}/src/mega/twi.o: src/mega/twi.c  .generated_files/flags/Atmega128A/c0bd0f5a6a22d2b31ae8fa36e9aec5a4f5f19dc3 .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/twi.o.d 
	@${RM} ${OBJECTDIR}/src/mega/twi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/twi.o.d" -MT "${OBJECTDIR}/src/mega/twi.o.d" -MT ${OBJECTDIR}/src/mega/twi.o -o ${OBJECTDIR}/src/mega/twi.o src/mega/twi.c 
	
${OBJECTDIR}/src/mega.o: src/mega.c  .generated_files/flags/Atmega128A/64324b4ea332349dd9a50c5057ff0955278a89af .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/mega.o.d 
	@${RM} ${OBJECTDIR}/src/mega.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega.o.d" -MT "${OBJECTDIR}/src/mega.o.d" -MT ${OBJECTDIR}/src/mega.o -o ${OBJECTDIR}/src/mega.o src/mega.c 
	
else
${OBJECTDIR}/src/mega/sys.o: src/mega/sys.c  .generated_files/flags/Atmega128A/1cc01c119d1d006f62b5096dbde1f4913607b8a5 .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/sys.o.d 
	@${RM} ${OBJECTDIR}/src/mega/sys.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/sys.o.d" -MT "${OBJECTDIR}/src/mega/sys.o.d" -MT ${OBJECTDIR}/src/mega/sys.o -o ${OBJECTDIR}/src/mega/sys.o src/mega/sys.c 
	
${OBJECTDIR}/src/mega/lcd.o: src/mega/lcd.c  .generated_files/flags/Atmega128A/f2c50af32d53b8aa35a319d3ffb3afef13df9a33 .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/lcd.o.d 
	@${RM} ${OBJECTDIR}/src/mega/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/lcd.o.d" -MT "${OBJECTDIR}/src/mega/lcd.o.d" -MT ${OBJECTDIR}/src/mega/lcd.o -o ${OBJECTDIR}/src/mega/lcd.o src/mega/lcd.c 
	
${OBJECTDIR}/src/mega/buffers.o: src/mega/buffers.c  .generated_files/flags/Atmega128A/c12f3657d23260f65216cb3223bd82a040e3d03d .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/buffers.o.d 
	@${RM} ${OBJECTDIR}/src/mega/buffers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/buffers.o.d" -MT "${OBJECTDIR}/src/mega/buffers.o.d" -MT ${OBJECTDIR}/src/mega/buffers.o -o ${OBJECTDIR}/src/mega/buffers.o src/mega/buffers.c 
	
${OBJECTDIR}/src/mega/button.o: src/mega/button.c  .generated_files/flags/Atmega128A/435d4d3488b0a58d6b1107ce7d8a257f7e11c094 .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/button.o.d 
	@${RM} ${OBJECTDIR}/src/mega/button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/button.o.d" -MT "${OBJECTDIR}/src/mega/button.o.d" -MT ${OBJECTDIR}/src/mega/button.o -o ${OBJECTDIR}/src/mega/button.o src/mega/button.c 
	
${OBJECTDIR}/src/mega/keypad.o: src/mega/keypad.c  .generated_files/flags/Atmega128A/27aa8fa3abea20b34c9c64799014fb2fc7169481 .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/keypad.o.d 
	@${RM} ${OBJECTDIR}/src/mega/keypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/keypad.o.d" -MT "${OBJECTDIR}/src/mega/keypad.o.d" -MT ${OBJECTDIR}/src/mega/keypad.o -o ${OBJECTDIR}/src/mega/keypad.o src/mega/keypad.c 
	
${OBJECTDIR}/src/mega/rtc.o: src/mega/rtc.c  .generated_files/flags/Atmega128A/a4341c6f0e16ac5c3c05c4f08c044a3ea2c83b89 .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/rtc.o.d 
	@${RM} ${OBJECTDIR}/src/mega/rtc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/rtc.o.d" -MT "${OBJECTDIR}/src/mega/rtc.o.d" -MT ${OBJECTDIR}/src/mega/rtc.o -o ${OBJECTDIR}/src/mega/rtc.o src/mega/rtc.c 
	
${OBJECTDIR}/src/mega/menu.o: src/mega/menu.c  .generated_files/flags/Atmega128A/2c66719d30334d1037bf21788e1da1e74c4113c9 .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/menu.o.d 
	@${RM} ${OBJECTDIR}/src/mega/menu.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/menu.o.d" -MT "${OBJECTDIR}/src/mega/menu.o.d" -MT ${OBJECTDIR}/src/mega/menu.o -o ${OBJECTDIR}/src/mega/menu.o src/mega/menu.c 
	
${OBJECTDIR}/inc/mega/buz.o: inc/mega/buz.c  .generated_files/flags/Atmega128A/5d75fecab243b7807c129815166d65357b974fd2 .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/inc/mega" 
	@${RM} ${OBJECTDIR}/inc/mega/buz.o.d 
	@${RM} ${OBJECTDIR}/inc/mega/buz.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/inc/mega/buz.o.d" -MT "${OBJECTDIR}/inc/mega/buz.o.d" -MT ${OBJECTDIR}/inc/mega/buz.o -o ${OBJECTDIR}/inc/mega/buz.o inc/mega/buz.c 
	
${OBJECTDIR}/src/mega/spi.o: src/mega/spi.c  .generated_files/flags/Atmega128A/e70366d232b3c64c41f6156c914d0e7fef00d5bb .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/spi.o.d 
	@${RM} ${OBJECTDIR}/src/mega/spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/spi.o.d" -MT "${OBJECTDIR}/src/mega/spi.o.d" -MT ${OBJECTDIR}/src/mega/spi.o -o ${OBJECTDIR}/src/mega/spi.o src/mega/spi.c 
	
${OBJECTDIR}/src/mega/sssd.o: src/mega/sssd.c  .generated_files/flags/Atmega128A/ada46e07bc27fb834943d1b405547308932271e7 .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/sssd.o.d 
	@${RM} ${OBJECTDIR}/src/mega/sssd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/sssd.o.d" -MT "${OBJECTDIR}/src/mega/sssd.o.d" -MT ${OBJECTDIR}/src/mega/sssd.o -o ${OBJECTDIR}/src/mega/sssd.o src/mega/sssd.c 
	
${OBJECTDIR}/src/mega/hx711.o: src/mega/hx711.c  .generated_files/flags/Atmega128A/53ffc143b8505ef669ab4a90f8fbaf642a612544 .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/hx711.o.d 
	@${RM} ${OBJECTDIR}/src/mega/hx711.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/hx711.o.d" -MT "${OBJECTDIR}/src/mega/hx711.o.d" -MT ${OBJECTDIR}/src/mega/hx711.o -o ${OBJECTDIR}/src/mega/hx711.o src/mega/hx711.c 
	
${OBJECTDIR}/src/mega/eeprom.o: src/mega/eeprom.c  .generated_files/flags/Atmega128A/f948d2f61994f4931b5db8b14a1703d36d6be571 .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/eeprom.o.d 
	@${RM} ${OBJECTDIR}/src/mega/eeprom.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/eeprom.o.d" -MT "${OBJECTDIR}/src/mega/eeprom.o.d" -MT ${OBJECTDIR}/src/mega/eeprom.o -o ${OBJECTDIR}/src/mega/eeprom.o src/mega/eeprom.c 
	
${OBJECTDIR}/src/mega/keypadEvent.o: src/mega/keypadEvent.c  .generated_files/flags/Atmega128A/20575b016f16a7add3337d3cc8ed27101f852539 .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/keypadEvent.o.d 
	@${RM} ${OBJECTDIR}/src/mega/keypadEvent.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/keypadEvent.o.d" -MT "${OBJECTDIR}/src/mega/keypadEvent.o.d" -MT ${OBJECTDIR}/src/mega/keypadEvent.o -o ${OBJECTDIR}/src/mega/keypadEvent.o src/mega/keypadEvent.c 
	
${OBJECTDIR}/_ext/88461258/exEEPROM.o: D:/Company/SMART/MEGA/mega.X/src/mega/exEEPROM.c  .generated_files/flags/Atmega128A/ce444aa36f18510e0ce189cae3fa183345f72225 .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/_ext/88461258" 
	@${RM} ${OBJECTDIR}/_ext/88461258/exEEPROM.o.d 
	@${RM} ${OBJECTDIR}/_ext/88461258/exEEPROM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/88461258/exEEPROM.o.d" -MT "${OBJECTDIR}/_ext/88461258/exEEPROM.o.d" -MT ${OBJECTDIR}/_ext/88461258/exEEPROM.o -o ${OBJECTDIR}/_ext/88461258/exEEPROM.o D:/Company/SMART/MEGA/mega.X/src/mega/exEEPROM.c 
	
${OBJECTDIR}/_ext/88461258/gpio.o: D:/Company/SMART/MEGA/mega.X/src/mega/gpio.c  .generated_files/flags/Atmega128A/d57e92165380c61deaecaa23dacec4c648b2dd89 .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/_ext/88461258" 
	@${RM} ${OBJECTDIR}/_ext/88461258/gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/88461258/gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/88461258/gpio.o.d" -MT "${OBJECTDIR}/_ext/88461258/gpio.o.d" -MT ${OBJECTDIR}/_ext/88461258/gpio.o -o ${OBJECTDIR}/_ext/88461258/gpio.o D:/Company/SMART/MEGA/mega.X/src/mega/gpio.c 
	
${OBJECTDIR}/_ext/88461258/csma_cd.o: D:/Company/SMART/MEGA/mega.X/src/mega/csma_cd.c  .generated_files/flags/Atmega128A/cceb42cf53bd1aee5caa80c5ae046493b53bb1d7 .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/_ext/88461258" 
	@${RM} ${OBJECTDIR}/_ext/88461258/csma_cd.o.d 
	@${RM} ${OBJECTDIR}/_ext/88461258/csma_cd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/88461258/csma_cd.o.d" -MT "${OBJECTDIR}/_ext/88461258/csma_cd.o.d" -MT ${OBJECTDIR}/_ext/88461258/csma_cd.o -o ${OBJECTDIR}/_ext/88461258/csma_cd.o D:/Company/SMART/MEGA/mega.X/src/mega/csma_cd.c 
	
${OBJECTDIR}/src/mega/utility.o: src/mega/utility.c  .generated_files/flags/Atmega128A/ba79bc0a188900575a62feacdee30677d65348a9 .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/utility.o.d 
	@${RM} ${OBJECTDIR}/src/mega/utility.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/utility.o.d" -MT "${OBJECTDIR}/src/mega/utility.o.d" -MT ${OBJECTDIR}/src/mega/utility.o -o ${OBJECTDIR}/src/mega/utility.o src/mega/utility.c 
	
${OBJECTDIR}/src/mega/SSD.o: src/mega/SSD.c  .generated_files/flags/Atmega128A/9da0cb9c3d48f55f7f509db9df0768bd95175be0 .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/SSD.o.d 
	@${RM} ${OBJECTDIR}/src/mega/SSD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/SSD.o.d" -MT "${OBJECTDIR}/src/mega/SSD.o.d" -MT ${OBJECTDIR}/src/mega/SSD.o -o ${OBJECTDIR}/src/mega/SSD.o src/mega/SSD.c 
	
${OBJECTDIR}/src/mega/twi.o: src/mega/twi.c  .generated_files/flags/Atmega128A/18af0d4792a6aa00e0232fe56df99a250009c3ab .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/twi.o.d 
	@${RM} ${OBJECTDIR}/src/mega/twi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/twi.o.d" -MT "${OBJECTDIR}/src/mega/twi.o.d" -MT ${OBJECTDIR}/src/mega/twi.o -o ${OBJECTDIR}/src/mega/twi.o src/mega/twi.c 
	
${OBJECTDIR}/src/mega.o: src/mega.c  .generated_files/flags/Atmega128A/d3ce5f55e3c87134c897740a81e8e3ca4a9ee4e8 .generated_files/flags/Atmega128A/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/mega.o.d 
	@${RM} ${OBJECTDIR}/src/mega.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fcommon -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega128A=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega.o.d" -MT "${OBJECTDIR}/src/mega.o.d" -MT ${OBJECTDIR}/src/mega.o -o ${OBJECTDIR}/src/mega.o src/mega.c 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: archive
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/mega.X.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_AR} $(MP_EXTRA_AR_PRE) --target $(MP_PROCESSOR_OPTION)  r -o ${DISTDIR}/mega.X.a  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/mega.X.hex 
	
else
${DISTDIR}/mega.X.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_AR} $(MP_EXTRA_AR_PRE) --target $(MP_PROCESSOR_OPTION)  r -o ${DISTDIR}/mega.X.a  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
