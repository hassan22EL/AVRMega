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
ifeq "$(wildcard nbproject/Makefile-local-Atmega328.mk)" "nbproject/Makefile-local-Atmega328.mk"
include nbproject/Makefile-local-Atmega328.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=Atmega328
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
	${MAKE}  -f nbproject/Makefile-Atmega328.mk ${DISTDIR}/mega.X.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega328P
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/mega/sys.o: src/mega/sys.c  .generated_files/flags/Atmega328/36d217f3739f5815384f257ec44b135a5aa0c1fa .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/sys.o.d 
	@${RM} ${OBJECTDIR}/src/mega/sys.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/sys.o.d" -MT "${OBJECTDIR}/src/mega/sys.o.d" -MT ${OBJECTDIR}/src/mega/sys.o -o ${OBJECTDIR}/src/mega/sys.o src/mega/sys.c 
	
${OBJECTDIR}/src/mega/lcd.o: src/mega/lcd.c  .generated_files/flags/Atmega328/98698b098f7495e021d40fca5f6ea456408a1f8 .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/lcd.o.d 
	@${RM} ${OBJECTDIR}/src/mega/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/lcd.o.d" -MT "${OBJECTDIR}/src/mega/lcd.o.d" -MT ${OBJECTDIR}/src/mega/lcd.o -o ${OBJECTDIR}/src/mega/lcd.o src/mega/lcd.c 
	
${OBJECTDIR}/src/mega/buffers.o: src/mega/buffers.c  .generated_files/flags/Atmega328/4ecf30eda59c51b7d7c1ca8b64c12bd21486189d .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/buffers.o.d 
	@${RM} ${OBJECTDIR}/src/mega/buffers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/buffers.o.d" -MT "${OBJECTDIR}/src/mega/buffers.o.d" -MT ${OBJECTDIR}/src/mega/buffers.o -o ${OBJECTDIR}/src/mega/buffers.o src/mega/buffers.c 
	
${OBJECTDIR}/src/mega/button.o: src/mega/button.c  .generated_files/flags/Atmega328/78880508a1f4ad6b869ad3986c522ae4521516fb .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/button.o.d 
	@${RM} ${OBJECTDIR}/src/mega/button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/button.o.d" -MT "${OBJECTDIR}/src/mega/button.o.d" -MT ${OBJECTDIR}/src/mega/button.o -o ${OBJECTDIR}/src/mega/button.o src/mega/button.c 
	
${OBJECTDIR}/src/mega/keypad.o: src/mega/keypad.c  .generated_files/flags/Atmega328/abed50a06d82a46a7547f620fd3090771415f585 .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/keypad.o.d 
	@${RM} ${OBJECTDIR}/src/mega/keypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/keypad.o.d" -MT "${OBJECTDIR}/src/mega/keypad.o.d" -MT ${OBJECTDIR}/src/mega/keypad.o -o ${OBJECTDIR}/src/mega/keypad.o src/mega/keypad.c 
	
${OBJECTDIR}/src/mega/rtc.o: src/mega/rtc.c  .generated_files/flags/Atmega328/7161a4c2aeab95e8d86e8b6fb21b6b8ab366d2e3 .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/rtc.o.d 
	@${RM} ${OBJECTDIR}/src/mega/rtc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/rtc.o.d" -MT "${OBJECTDIR}/src/mega/rtc.o.d" -MT ${OBJECTDIR}/src/mega/rtc.o -o ${OBJECTDIR}/src/mega/rtc.o src/mega/rtc.c 
	
${OBJECTDIR}/src/mega/menu.o: src/mega/menu.c  .generated_files/flags/Atmega328/3023d73e34ff1d7395964df3ee9b57599922ea53 .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/menu.o.d 
	@${RM} ${OBJECTDIR}/src/mega/menu.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/menu.o.d" -MT "${OBJECTDIR}/src/mega/menu.o.d" -MT ${OBJECTDIR}/src/mega/menu.o -o ${OBJECTDIR}/src/mega/menu.o src/mega/menu.c 
	
${OBJECTDIR}/inc/mega/buz.o: inc/mega/buz.c  .generated_files/flags/Atmega328/f27f6c86a1ed5ff9ee9c485e81e9a20ad5bb5bce .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/inc/mega" 
	@${RM} ${OBJECTDIR}/inc/mega/buz.o.d 
	@${RM} ${OBJECTDIR}/inc/mega/buz.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/inc/mega/buz.o.d" -MT "${OBJECTDIR}/inc/mega/buz.o.d" -MT ${OBJECTDIR}/inc/mega/buz.o -o ${OBJECTDIR}/inc/mega/buz.o inc/mega/buz.c 
	
${OBJECTDIR}/src/mega/spi.o: src/mega/spi.c  .generated_files/flags/Atmega328/a884018b937aa253b6ea7b9e15d6e797e50699b0 .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/spi.o.d 
	@${RM} ${OBJECTDIR}/src/mega/spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/spi.o.d" -MT "${OBJECTDIR}/src/mega/spi.o.d" -MT ${OBJECTDIR}/src/mega/spi.o -o ${OBJECTDIR}/src/mega/spi.o src/mega/spi.c 
	
${OBJECTDIR}/src/mega/sssd.o: src/mega/sssd.c  .generated_files/flags/Atmega328/4cfffc405b09e50dfc18eeed0584e866344a9c20 .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/sssd.o.d 
	@${RM} ${OBJECTDIR}/src/mega/sssd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/sssd.o.d" -MT "${OBJECTDIR}/src/mega/sssd.o.d" -MT ${OBJECTDIR}/src/mega/sssd.o -o ${OBJECTDIR}/src/mega/sssd.o src/mega/sssd.c 
	
${OBJECTDIR}/src/mega/hx711.o: src/mega/hx711.c  .generated_files/flags/Atmega328/2ffd2ce0ed4c1eb527c9adba08d35b04ae97279c .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/hx711.o.d 
	@${RM} ${OBJECTDIR}/src/mega/hx711.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/hx711.o.d" -MT "${OBJECTDIR}/src/mega/hx711.o.d" -MT ${OBJECTDIR}/src/mega/hx711.o -o ${OBJECTDIR}/src/mega/hx711.o src/mega/hx711.c 
	
${OBJECTDIR}/src/mega/eeprom.o: src/mega/eeprom.c  .generated_files/flags/Atmega328/97d88ef18b42a28429d6a3e12af786ff19622d2e .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/eeprom.o.d 
	@${RM} ${OBJECTDIR}/src/mega/eeprom.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/eeprom.o.d" -MT "${OBJECTDIR}/src/mega/eeprom.o.d" -MT ${OBJECTDIR}/src/mega/eeprom.o -o ${OBJECTDIR}/src/mega/eeprom.o src/mega/eeprom.c 
	
${OBJECTDIR}/src/mega/keypadEvent.o: src/mega/keypadEvent.c  .generated_files/flags/Atmega328/ca2a8e3c3e051e42f3c2323f2d4d5b3ba2d7a8fd .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/keypadEvent.o.d 
	@${RM} ${OBJECTDIR}/src/mega/keypadEvent.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/keypadEvent.o.d" -MT "${OBJECTDIR}/src/mega/keypadEvent.o.d" -MT ${OBJECTDIR}/src/mega/keypadEvent.o -o ${OBJECTDIR}/src/mega/keypadEvent.o src/mega/keypadEvent.c 
	
${OBJECTDIR}/_ext/88461258/exEEPROM.o: D:/Company/SMART/MEGA/mega.X/src/mega/exEEPROM.c  .generated_files/flags/Atmega328/4baea0913b9fa80090ee1d6ea1cde8f60dc8f735 .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/_ext/88461258" 
	@${RM} ${OBJECTDIR}/_ext/88461258/exEEPROM.o.d 
	@${RM} ${OBJECTDIR}/_ext/88461258/exEEPROM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/88461258/exEEPROM.o.d" -MT "${OBJECTDIR}/_ext/88461258/exEEPROM.o.d" -MT ${OBJECTDIR}/_ext/88461258/exEEPROM.o -o ${OBJECTDIR}/_ext/88461258/exEEPROM.o D:/Company/SMART/MEGA/mega.X/src/mega/exEEPROM.c 
	
${OBJECTDIR}/_ext/88461258/gpio.o: D:/Company/SMART/MEGA/mega.X/src/mega/gpio.c  .generated_files/flags/Atmega328/b2c3da2d3e1c48adcfbf311097654459ede307ef .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/_ext/88461258" 
	@${RM} ${OBJECTDIR}/_ext/88461258/gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/88461258/gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/88461258/gpio.o.d" -MT "${OBJECTDIR}/_ext/88461258/gpio.o.d" -MT ${OBJECTDIR}/_ext/88461258/gpio.o -o ${OBJECTDIR}/_ext/88461258/gpio.o D:/Company/SMART/MEGA/mega.X/src/mega/gpio.c 
	
${OBJECTDIR}/_ext/88461258/csma_cd.o: D:/Company/SMART/MEGA/mega.X/src/mega/csma_cd.c  .generated_files/flags/Atmega328/b9d24314241e946a8eee8e456a01eb52936eeebc .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/_ext/88461258" 
	@${RM} ${OBJECTDIR}/_ext/88461258/csma_cd.o.d 
	@${RM} ${OBJECTDIR}/_ext/88461258/csma_cd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/88461258/csma_cd.o.d" -MT "${OBJECTDIR}/_ext/88461258/csma_cd.o.d" -MT ${OBJECTDIR}/_ext/88461258/csma_cd.o -o ${OBJECTDIR}/_ext/88461258/csma_cd.o D:/Company/SMART/MEGA/mega.X/src/mega/csma_cd.c 
	
${OBJECTDIR}/src/mega/utility.o: src/mega/utility.c  .generated_files/flags/Atmega328/b81964e9c0de46d61659b5e1575f7fcbcccd8c8a .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/utility.o.d 
	@${RM} ${OBJECTDIR}/src/mega/utility.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/utility.o.d" -MT "${OBJECTDIR}/src/mega/utility.o.d" -MT ${OBJECTDIR}/src/mega/utility.o -o ${OBJECTDIR}/src/mega/utility.o src/mega/utility.c 
	
${OBJECTDIR}/src/mega/SSD.o: src/mega/SSD.c  .generated_files/flags/Atmega328/bc3d53572495cf783fc3c1ba12b4135dda10f382 .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/SSD.o.d 
	@${RM} ${OBJECTDIR}/src/mega/SSD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/SSD.o.d" -MT "${OBJECTDIR}/src/mega/SSD.o.d" -MT ${OBJECTDIR}/src/mega/SSD.o -o ${OBJECTDIR}/src/mega/SSD.o src/mega/SSD.c 
	
${OBJECTDIR}/src/mega/twi.o: src/mega/twi.c  .generated_files/flags/Atmega328/a95f221bec7c56d3b6c394d89b3614984f24b61a .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/twi.o.d 
	@${RM} ${OBJECTDIR}/src/mega/twi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/twi.o.d" -MT "${OBJECTDIR}/src/mega/twi.o.d" -MT ${OBJECTDIR}/src/mega/twi.o -o ${OBJECTDIR}/src/mega/twi.o src/mega/twi.c 
	
${OBJECTDIR}/src/mega.o: src/mega.c  .generated_files/flags/Atmega328/6bd7383d9e9214ccf58908658c0213aef8521a78 .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/mega.o.d 
	@${RM} ${OBJECTDIR}/src/mega.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega.o.d" -MT "${OBJECTDIR}/src/mega.o.d" -MT ${OBJECTDIR}/src/mega.o -o ${OBJECTDIR}/src/mega.o src/mega.c 
	
else
${OBJECTDIR}/src/mega/sys.o: src/mega/sys.c  .generated_files/flags/Atmega328/9d3287a6737317d39740e0cdb1228bb6923ccde7 .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/sys.o.d 
	@${RM} ${OBJECTDIR}/src/mega/sys.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/sys.o.d" -MT "${OBJECTDIR}/src/mega/sys.o.d" -MT ${OBJECTDIR}/src/mega/sys.o -o ${OBJECTDIR}/src/mega/sys.o src/mega/sys.c 
	
${OBJECTDIR}/src/mega/lcd.o: src/mega/lcd.c  .generated_files/flags/Atmega328/c40f7902ef092b6ea9f1cfbb7cd16212100ee3cc .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/lcd.o.d 
	@${RM} ${OBJECTDIR}/src/mega/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/lcd.o.d" -MT "${OBJECTDIR}/src/mega/lcd.o.d" -MT ${OBJECTDIR}/src/mega/lcd.o -o ${OBJECTDIR}/src/mega/lcd.o src/mega/lcd.c 
	
${OBJECTDIR}/src/mega/buffers.o: src/mega/buffers.c  .generated_files/flags/Atmega328/e9e7f3f2726e03d477e129591e74aa837b81d34e .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/buffers.o.d 
	@${RM} ${OBJECTDIR}/src/mega/buffers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/buffers.o.d" -MT "${OBJECTDIR}/src/mega/buffers.o.d" -MT ${OBJECTDIR}/src/mega/buffers.o -o ${OBJECTDIR}/src/mega/buffers.o src/mega/buffers.c 
	
${OBJECTDIR}/src/mega/button.o: src/mega/button.c  .generated_files/flags/Atmega328/5112c6d95f0200c1fe06d2aa07e8117186d3280a .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/button.o.d 
	@${RM} ${OBJECTDIR}/src/mega/button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/button.o.d" -MT "${OBJECTDIR}/src/mega/button.o.d" -MT ${OBJECTDIR}/src/mega/button.o -o ${OBJECTDIR}/src/mega/button.o src/mega/button.c 
	
${OBJECTDIR}/src/mega/keypad.o: src/mega/keypad.c  .generated_files/flags/Atmega328/277cf65f4234b56865ad786d19072331dc2950b .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/keypad.o.d 
	@${RM} ${OBJECTDIR}/src/mega/keypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/keypad.o.d" -MT "${OBJECTDIR}/src/mega/keypad.o.d" -MT ${OBJECTDIR}/src/mega/keypad.o -o ${OBJECTDIR}/src/mega/keypad.o src/mega/keypad.c 
	
${OBJECTDIR}/src/mega/rtc.o: src/mega/rtc.c  .generated_files/flags/Atmega328/d745ae64d94cfca5b8a67705ad450872ffec7663 .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/rtc.o.d 
	@${RM} ${OBJECTDIR}/src/mega/rtc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/rtc.o.d" -MT "${OBJECTDIR}/src/mega/rtc.o.d" -MT ${OBJECTDIR}/src/mega/rtc.o -o ${OBJECTDIR}/src/mega/rtc.o src/mega/rtc.c 
	
${OBJECTDIR}/src/mega/menu.o: src/mega/menu.c  .generated_files/flags/Atmega328/13a3005b5c02f8161724cf137f73490ec324eac6 .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/menu.o.d 
	@${RM} ${OBJECTDIR}/src/mega/menu.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/menu.o.d" -MT "${OBJECTDIR}/src/mega/menu.o.d" -MT ${OBJECTDIR}/src/mega/menu.o -o ${OBJECTDIR}/src/mega/menu.o src/mega/menu.c 
	
${OBJECTDIR}/inc/mega/buz.o: inc/mega/buz.c  .generated_files/flags/Atmega328/1830fb06a9b141bb56855d99da5592d280a6da1e .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/inc/mega" 
	@${RM} ${OBJECTDIR}/inc/mega/buz.o.d 
	@${RM} ${OBJECTDIR}/inc/mega/buz.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/inc/mega/buz.o.d" -MT "${OBJECTDIR}/inc/mega/buz.o.d" -MT ${OBJECTDIR}/inc/mega/buz.o -o ${OBJECTDIR}/inc/mega/buz.o inc/mega/buz.c 
	
${OBJECTDIR}/src/mega/spi.o: src/mega/spi.c  .generated_files/flags/Atmega328/e26c84f5b309f6d1a805f62e3e6aac7abf81b331 .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/spi.o.d 
	@${RM} ${OBJECTDIR}/src/mega/spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/spi.o.d" -MT "${OBJECTDIR}/src/mega/spi.o.d" -MT ${OBJECTDIR}/src/mega/spi.o -o ${OBJECTDIR}/src/mega/spi.o src/mega/spi.c 
	
${OBJECTDIR}/src/mega/sssd.o: src/mega/sssd.c  .generated_files/flags/Atmega328/e5a1ef1d32b3e614357c8d962813377ce66c7b8c .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/sssd.o.d 
	@${RM} ${OBJECTDIR}/src/mega/sssd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/sssd.o.d" -MT "${OBJECTDIR}/src/mega/sssd.o.d" -MT ${OBJECTDIR}/src/mega/sssd.o -o ${OBJECTDIR}/src/mega/sssd.o src/mega/sssd.c 
	
${OBJECTDIR}/src/mega/hx711.o: src/mega/hx711.c  .generated_files/flags/Atmega328/87da626cbbb551269956d7b016ff70465d1b4772 .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/hx711.o.d 
	@${RM} ${OBJECTDIR}/src/mega/hx711.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/hx711.o.d" -MT "${OBJECTDIR}/src/mega/hx711.o.d" -MT ${OBJECTDIR}/src/mega/hx711.o -o ${OBJECTDIR}/src/mega/hx711.o src/mega/hx711.c 
	
${OBJECTDIR}/src/mega/eeprom.o: src/mega/eeprom.c  .generated_files/flags/Atmega328/5ff767bf78def3fc7ef538719931126bf7399c59 .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/eeprom.o.d 
	@${RM} ${OBJECTDIR}/src/mega/eeprom.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/eeprom.o.d" -MT "${OBJECTDIR}/src/mega/eeprom.o.d" -MT ${OBJECTDIR}/src/mega/eeprom.o -o ${OBJECTDIR}/src/mega/eeprom.o src/mega/eeprom.c 
	
${OBJECTDIR}/src/mega/keypadEvent.o: src/mega/keypadEvent.c  .generated_files/flags/Atmega328/2f53fefa2f01265f6b30c7dbdfabb370e4e0ee7d .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/keypadEvent.o.d 
	@${RM} ${OBJECTDIR}/src/mega/keypadEvent.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/keypadEvent.o.d" -MT "${OBJECTDIR}/src/mega/keypadEvent.o.d" -MT ${OBJECTDIR}/src/mega/keypadEvent.o -o ${OBJECTDIR}/src/mega/keypadEvent.o src/mega/keypadEvent.c 
	
${OBJECTDIR}/_ext/88461258/exEEPROM.o: D:/Company/SMART/MEGA/mega.X/src/mega/exEEPROM.c  .generated_files/flags/Atmega328/c50936ce1389c30a3f1e5d87eaa39e84b721e389 .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/_ext/88461258" 
	@${RM} ${OBJECTDIR}/_ext/88461258/exEEPROM.o.d 
	@${RM} ${OBJECTDIR}/_ext/88461258/exEEPROM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/88461258/exEEPROM.o.d" -MT "${OBJECTDIR}/_ext/88461258/exEEPROM.o.d" -MT ${OBJECTDIR}/_ext/88461258/exEEPROM.o -o ${OBJECTDIR}/_ext/88461258/exEEPROM.o D:/Company/SMART/MEGA/mega.X/src/mega/exEEPROM.c 
	
${OBJECTDIR}/_ext/88461258/gpio.o: D:/Company/SMART/MEGA/mega.X/src/mega/gpio.c  .generated_files/flags/Atmega328/c167613a0cc136c41bd6a5d99f8e9a4bc48b1d43 .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/_ext/88461258" 
	@${RM} ${OBJECTDIR}/_ext/88461258/gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/88461258/gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/88461258/gpio.o.d" -MT "${OBJECTDIR}/_ext/88461258/gpio.o.d" -MT ${OBJECTDIR}/_ext/88461258/gpio.o -o ${OBJECTDIR}/_ext/88461258/gpio.o D:/Company/SMART/MEGA/mega.X/src/mega/gpio.c 
	
${OBJECTDIR}/_ext/88461258/csma_cd.o: D:/Company/SMART/MEGA/mega.X/src/mega/csma_cd.c  .generated_files/flags/Atmega328/2a025dabe422a587553d72ba39a321142aec9c29 .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/_ext/88461258" 
	@${RM} ${OBJECTDIR}/_ext/88461258/csma_cd.o.d 
	@${RM} ${OBJECTDIR}/_ext/88461258/csma_cd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/88461258/csma_cd.o.d" -MT "${OBJECTDIR}/_ext/88461258/csma_cd.o.d" -MT ${OBJECTDIR}/_ext/88461258/csma_cd.o -o ${OBJECTDIR}/_ext/88461258/csma_cd.o D:/Company/SMART/MEGA/mega.X/src/mega/csma_cd.c 
	
${OBJECTDIR}/src/mega/utility.o: src/mega/utility.c  .generated_files/flags/Atmega328/c9ba0f925d733d650d2c73285cfca104d12f6902 .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/utility.o.d 
	@${RM} ${OBJECTDIR}/src/mega/utility.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/utility.o.d" -MT "${OBJECTDIR}/src/mega/utility.o.d" -MT ${OBJECTDIR}/src/mega/utility.o -o ${OBJECTDIR}/src/mega/utility.o src/mega/utility.c 
	
${OBJECTDIR}/src/mega/SSD.o: src/mega/SSD.c  .generated_files/flags/Atmega328/4d2803fbf30324e283b3147415cf0cbef11779d8 .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/SSD.o.d 
	@${RM} ${OBJECTDIR}/src/mega/SSD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/SSD.o.d" -MT "${OBJECTDIR}/src/mega/SSD.o.d" -MT ${OBJECTDIR}/src/mega/SSD.o -o ${OBJECTDIR}/src/mega/SSD.o src/mega/SSD.c 
	
${OBJECTDIR}/src/mega/twi.o: src/mega/twi.c  .generated_files/flags/Atmega328/a16aab9a3798fcb734497dc6385f99a4056e64af .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/twi.o.d 
	@${RM} ${OBJECTDIR}/src/mega/twi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/twi.o.d" -MT "${OBJECTDIR}/src/mega/twi.o.d" -MT ${OBJECTDIR}/src/mega/twi.o -o ${OBJECTDIR}/src/mega/twi.o src/mega/twi.c 
	
${OBJECTDIR}/src/mega.o: src/mega.c  .generated_files/flags/Atmega328/32f41896d284341c4e28d36497fa91bce874e783 .generated_files/flags/Atmega328/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/mega.o.d 
	@${RM} ${OBJECTDIR}/src/mega.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_Atmega328=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega.o.d" -MT "${OBJECTDIR}/src/mega.o.d" -MT ${OBJECTDIR}/src/mega.o -o ${OBJECTDIR}/src/mega.o src/mega.c 
	
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
