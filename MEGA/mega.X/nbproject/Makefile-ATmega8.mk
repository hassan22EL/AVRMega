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
ifeq "$(wildcard nbproject/Makefile-local-ATmega8.mk)" "nbproject/Makefile-local-ATmega8.mk"
include nbproject/Makefile-local-ATmega8.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=ATmega8
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
	${MAKE}  -f nbproject/Makefile-ATmega8.mk ${DISTDIR}/mega.X.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega8A
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/mega/sys.o: src/mega/sys.c  .generated_files/flags/ATmega8/15e4d8ca45a56c2439a2bc1dd3594e3a62f95f7 .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/sys.o.d 
	@${RM} ${OBJECTDIR}/src/mega/sys.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/sys.o.d" -MT "${OBJECTDIR}/src/mega/sys.o.d" -MT ${OBJECTDIR}/src/mega/sys.o -o ${OBJECTDIR}/src/mega/sys.o src/mega/sys.c 
	
${OBJECTDIR}/src/mega/lcd.o: src/mega/lcd.c  .generated_files/flags/ATmega8/8902d8db5298e4a22f0dbcd6ee85cd5cc9df521c .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/lcd.o.d 
	@${RM} ${OBJECTDIR}/src/mega/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/lcd.o.d" -MT "${OBJECTDIR}/src/mega/lcd.o.d" -MT ${OBJECTDIR}/src/mega/lcd.o -o ${OBJECTDIR}/src/mega/lcd.o src/mega/lcd.c 
	
${OBJECTDIR}/src/mega/buffers.o: src/mega/buffers.c  .generated_files/flags/ATmega8/83245483aa654c5f193af6ccdaf570aa1e435c93 .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/buffers.o.d 
	@${RM} ${OBJECTDIR}/src/mega/buffers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/buffers.o.d" -MT "${OBJECTDIR}/src/mega/buffers.o.d" -MT ${OBJECTDIR}/src/mega/buffers.o -o ${OBJECTDIR}/src/mega/buffers.o src/mega/buffers.c 
	
${OBJECTDIR}/src/mega/button.o: src/mega/button.c  .generated_files/flags/ATmega8/6a880ea1ccfe74c3b26acd1605889f04be07b9b .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/button.o.d 
	@${RM} ${OBJECTDIR}/src/mega/button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/button.o.d" -MT "${OBJECTDIR}/src/mega/button.o.d" -MT ${OBJECTDIR}/src/mega/button.o -o ${OBJECTDIR}/src/mega/button.o src/mega/button.c 
	
${OBJECTDIR}/src/mega/keypad.o: src/mega/keypad.c  .generated_files/flags/ATmega8/26ac2523642fd75e091a9a95f590fe96a32f8d2b .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/keypad.o.d 
	@${RM} ${OBJECTDIR}/src/mega/keypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/keypad.o.d" -MT "${OBJECTDIR}/src/mega/keypad.o.d" -MT ${OBJECTDIR}/src/mega/keypad.o -o ${OBJECTDIR}/src/mega/keypad.o src/mega/keypad.c 
	
${OBJECTDIR}/src/mega/rtc.o: src/mega/rtc.c  .generated_files/flags/ATmega8/e3422439b502883511184ccaa06038d1ebffe81b .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/rtc.o.d 
	@${RM} ${OBJECTDIR}/src/mega/rtc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/rtc.o.d" -MT "${OBJECTDIR}/src/mega/rtc.o.d" -MT ${OBJECTDIR}/src/mega/rtc.o -o ${OBJECTDIR}/src/mega/rtc.o src/mega/rtc.c 
	
${OBJECTDIR}/src/mega/menu.o: src/mega/menu.c  .generated_files/flags/ATmega8/203e16c39e96c2880bfdc5c680db3b8c5c342d76 .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/menu.o.d 
	@${RM} ${OBJECTDIR}/src/mega/menu.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/menu.o.d" -MT "${OBJECTDIR}/src/mega/menu.o.d" -MT ${OBJECTDIR}/src/mega/menu.o -o ${OBJECTDIR}/src/mega/menu.o src/mega/menu.c 
	
${OBJECTDIR}/inc/mega/buz.o: inc/mega/buz.c  .generated_files/flags/ATmega8/e1f71cdbec029c816590bc30c6c1d9c7ef65f1b1 .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/inc/mega" 
	@${RM} ${OBJECTDIR}/inc/mega/buz.o.d 
	@${RM} ${OBJECTDIR}/inc/mega/buz.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/inc/mega/buz.o.d" -MT "${OBJECTDIR}/inc/mega/buz.o.d" -MT ${OBJECTDIR}/inc/mega/buz.o -o ${OBJECTDIR}/inc/mega/buz.o inc/mega/buz.c 
	
${OBJECTDIR}/src/mega/spi.o: src/mega/spi.c  .generated_files/flags/ATmega8/2764617dc093b0220d4b5b73d148c3a1c949ed47 .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/spi.o.d 
	@${RM} ${OBJECTDIR}/src/mega/spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/spi.o.d" -MT "${OBJECTDIR}/src/mega/spi.o.d" -MT ${OBJECTDIR}/src/mega/spi.o -o ${OBJECTDIR}/src/mega/spi.o src/mega/spi.c 
	
${OBJECTDIR}/src/mega/sssd.o: src/mega/sssd.c  .generated_files/flags/ATmega8/280f9392bce376afbecbdf7e66b33b6f359166ac .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/sssd.o.d 
	@${RM} ${OBJECTDIR}/src/mega/sssd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/sssd.o.d" -MT "${OBJECTDIR}/src/mega/sssd.o.d" -MT ${OBJECTDIR}/src/mega/sssd.o -o ${OBJECTDIR}/src/mega/sssd.o src/mega/sssd.c 
	
${OBJECTDIR}/src/mega/hx711.o: src/mega/hx711.c  .generated_files/flags/ATmega8/89217e3daadfa432bc26f83185a1ed320732100a .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/hx711.o.d 
	@${RM} ${OBJECTDIR}/src/mega/hx711.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/hx711.o.d" -MT "${OBJECTDIR}/src/mega/hx711.o.d" -MT ${OBJECTDIR}/src/mega/hx711.o -o ${OBJECTDIR}/src/mega/hx711.o src/mega/hx711.c 
	
${OBJECTDIR}/src/mega/eeprom.o: src/mega/eeprom.c  .generated_files/flags/ATmega8/e73af444ed3b6795e05a9eb43feff1329d18cf3d .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/eeprom.o.d 
	@${RM} ${OBJECTDIR}/src/mega/eeprom.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/eeprom.o.d" -MT "${OBJECTDIR}/src/mega/eeprom.o.d" -MT ${OBJECTDIR}/src/mega/eeprom.o -o ${OBJECTDIR}/src/mega/eeprom.o src/mega/eeprom.c 
	
${OBJECTDIR}/src/mega/keypadEvent.o: src/mega/keypadEvent.c  .generated_files/flags/ATmega8/55a7a10567d61832b3e69876ded3b6697bdca9ab .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/keypadEvent.o.d 
	@${RM} ${OBJECTDIR}/src/mega/keypadEvent.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/keypadEvent.o.d" -MT "${OBJECTDIR}/src/mega/keypadEvent.o.d" -MT ${OBJECTDIR}/src/mega/keypadEvent.o -o ${OBJECTDIR}/src/mega/keypadEvent.o src/mega/keypadEvent.c 
	
${OBJECTDIR}/_ext/88461258/exEEPROM.o: D:/Company/SMART/MEGA/mega.X/src/mega/exEEPROM.c  .generated_files/flags/ATmega8/2aa04e930d585b65a7b42f72af348824850a3f66 .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/_ext/88461258" 
	@${RM} ${OBJECTDIR}/_ext/88461258/exEEPROM.o.d 
	@${RM} ${OBJECTDIR}/_ext/88461258/exEEPROM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/88461258/exEEPROM.o.d" -MT "${OBJECTDIR}/_ext/88461258/exEEPROM.o.d" -MT ${OBJECTDIR}/_ext/88461258/exEEPROM.o -o ${OBJECTDIR}/_ext/88461258/exEEPROM.o D:/Company/SMART/MEGA/mega.X/src/mega/exEEPROM.c 
	
${OBJECTDIR}/_ext/88461258/gpio.o: D:/Company/SMART/MEGA/mega.X/src/mega/gpio.c  .generated_files/flags/ATmega8/a0a404acb3f4392217172cb068bc7d68edc91468 .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/_ext/88461258" 
	@${RM} ${OBJECTDIR}/_ext/88461258/gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/88461258/gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/88461258/gpio.o.d" -MT "${OBJECTDIR}/_ext/88461258/gpio.o.d" -MT ${OBJECTDIR}/_ext/88461258/gpio.o -o ${OBJECTDIR}/_ext/88461258/gpio.o D:/Company/SMART/MEGA/mega.X/src/mega/gpio.c 
	
${OBJECTDIR}/_ext/88461258/csma_cd.o: D:/Company/SMART/MEGA/mega.X/src/mega/csma_cd.c  .generated_files/flags/ATmega8/8e94a727b5cdfe732f5344cc0c4f60fbfee96b4c .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/_ext/88461258" 
	@${RM} ${OBJECTDIR}/_ext/88461258/csma_cd.o.d 
	@${RM} ${OBJECTDIR}/_ext/88461258/csma_cd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/88461258/csma_cd.o.d" -MT "${OBJECTDIR}/_ext/88461258/csma_cd.o.d" -MT ${OBJECTDIR}/_ext/88461258/csma_cd.o -o ${OBJECTDIR}/_ext/88461258/csma_cd.o D:/Company/SMART/MEGA/mega.X/src/mega/csma_cd.c 
	
${OBJECTDIR}/src/mega/utility.o: src/mega/utility.c  .generated_files/flags/ATmega8/10f79e8fe3d4248953ca9d5d2a2c202c10f342e3 .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/utility.o.d 
	@${RM} ${OBJECTDIR}/src/mega/utility.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/utility.o.d" -MT "${OBJECTDIR}/src/mega/utility.o.d" -MT ${OBJECTDIR}/src/mega/utility.o -o ${OBJECTDIR}/src/mega/utility.o src/mega/utility.c 
	
${OBJECTDIR}/src/mega/SSD.o: src/mega/SSD.c  .generated_files/flags/ATmega8/3042fed4cadbca722d6428d25e80e2060dc71333 .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/SSD.o.d 
	@${RM} ${OBJECTDIR}/src/mega/SSD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/SSD.o.d" -MT "${OBJECTDIR}/src/mega/SSD.o.d" -MT ${OBJECTDIR}/src/mega/SSD.o -o ${OBJECTDIR}/src/mega/SSD.o src/mega/SSD.c 
	
${OBJECTDIR}/src/mega/twi.o: src/mega/twi.c  .generated_files/flags/ATmega8/62ee6977242e42c24ce97127d954478827c07efc .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/twi.o.d 
	@${RM} ${OBJECTDIR}/src/mega/twi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/twi.o.d" -MT "${OBJECTDIR}/src/mega/twi.o.d" -MT ${OBJECTDIR}/src/mega/twi.o -o ${OBJECTDIR}/src/mega/twi.o src/mega/twi.c 
	
${OBJECTDIR}/src/mega.o: src/mega.c  .generated_files/flags/ATmega8/fdff125fd1f6448270fc2fb63f9f0c06a5bc443c .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/mega.o.d 
	@${RM} ${OBJECTDIR}/src/mega.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega.o.d" -MT "${OBJECTDIR}/src/mega.o.d" -MT ${OBJECTDIR}/src/mega.o -o ${OBJECTDIR}/src/mega.o src/mega.c 
	
else
${OBJECTDIR}/src/mega/sys.o: src/mega/sys.c  .generated_files/flags/ATmega8/e8be1bd34c0bbfed76d01ffa63360544102101c3 .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/sys.o.d 
	@${RM} ${OBJECTDIR}/src/mega/sys.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/sys.o.d" -MT "${OBJECTDIR}/src/mega/sys.o.d" -MT ${OBJECTDIR}/src/mega/sys.o -o ${OBJECTDIR}/src/mega/sys.o src/mega/sys.c 
	
${OBJECTDIR}/src/mega/lcd.o: src/mega/lcd.c  .generated_files/flags/ATmega8/1717f18839186fe4b548df4542d3cefc0c050926 .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/lcd.o.d 
	@${RM} ${OBJECTDIR}/src/mega/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/lcd.o.d" -MT "${OBJECTDIR}/src/mega/lcd.o.d" -MT ${OBJECTDIR}/src/mega/lcd.o -o ${OBJECTDIR}/src/mega/lcd.o src/mega/lcd.c 
	
${OBJECTDIR}/src/mega/buffers.o: src/mega/buffers.c  .generated_files/flags/ATmega8/94ff29397c04f11af755db9cae281dd02457e8d4 .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/buffers.o.d 
	@${RM} ${OBJECTDIR}/src/mega/buffers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/buffers.o.d" -MT "${OBJECTDIR}/src/mega/buffers.o.d" -MT ${OBJECTDIR}/src/mega/buffers.o -o ${OBJECTDIR}/src/mega/buffers.o src/mega/buffers.c 
	
${OBJECTDIR}/src/mega/button.o: src/mega/button.c  .generated_files/flags/ATmega8/716e26c76a386ede0ca81b4db8ad3cb944e17577 .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/button.o.d 
	@${RM} ${OBJECTDIR}/src/mega/button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/button.o.d" -MT "${OBJECTDIR}/src/mega/button.o.d" -MT ${OBJECTDIR}/src/mega/button.o -o ${OBJECTDIR}/src/mega/button.o src/mega/button.c 
	
${OBJECTDIR}/src/mega/keypad.o: src/mega/keypad.c  .generated_files/flags/ATmega8/38ed99e9490a8771d714e56acfcf99e302750920 .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/keypad.o.d 
	@${RM} ${OBJECTDIR}/src/mega/keypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/keypad.o.d" -MT "${OBJECTDIR}/src/mega/keypad.o.d" -MT ${OBJECTDIR}/src/mega/keypad.o -o ${OBJECTDIR}/src/mega/keypad.o src/mega/keypad.c 
	
${OBJECTDIR}/src/mega/rtc.o: src/mega/rtc.c  .generated_files/flags/ATmega8/fdb19ee42ca87c858bb5c91a8eaa1bb78ac8673 .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/rtc.o.d 
	@${RM} ${OBJECTDIR}/src/mega/rtc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/rtc.o.d" -MT "${OBJECTDIR}/src/mega/rtc.o.d" -MT ${OBJECTDIR}/src/mega/rtc.o -o ${OBJECTDIR}/src/mega/rtc.o src/mega/rtc.c 
	
${OBJECTDIR}/src/mega/menu.o: src/mega/menu.c  .generated_files/flags/ATmega8/71fb12ed8a07a18326e95b12245cd8d648c370a8 .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/menu.o.d 
	@${RM} ${OBJECTDIR}/src/mega/menu.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/menu.o.d" -MT "${OBJECTDIR}/src/mega/menu.o.d" -MT ${OBJECTDIR}/src/mega/menu.o -o ${OBJECTDIR}/src/mega/menu.o src/mega/menu.c 
	
${OBJECTDIR}/inc/mega/buz.o: inc/mega/buz.c  .generated_files/flags/ATmega8/fcb3ed39d57cf15fc94c39de9be4b0da440ee406 .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/inc/mega" 
	@${RM} ${OBJECTDIR}/inc/mega/buz.o.d 
	@${RM} ${OBJECTDIR}/inc/mega/buz.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/inc/mega/buz.o.d" -MT "${OBJECTDIR}/inc/mega/buz.o.d" -MT ${OBJECTDIR}/inc/mega/buz.o -o ${OBJECTDIR}/inc/mega/buz.o inc/mega/buz.c 
	
${OBJECTDIR}/src/mega/spi.o: src/mega/spi.c  .generated_files/flags/ATmega8/ccd587c4dfd4fa99bc984a0efd5d862201b573c3 .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/spi.o.d 
	@${RM} ${OBJECTDIR}/src/mega/spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/spi.o.d" -MT "${OBJECTDIR}/src/mega/spi.o.d" -MT ${OBJECTDIR}/src/mega/spi.o -o ${OBJECTDIR}/src/mega/spi.o src/mega/spi.c 
	
${OBJECTDIR}/src/mega/sssd.o: src/mega/sssd.c  .generated_files/flags/ATmega8/858698d2f0fba2ebbf84c6a3a984b225bdf55861 .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/sssd.o.d 
	@${RM} ${OBJECTDIR}/src/mega/sssd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/sssd.o.d" -MT "${OBJECTDIR}/src/mega/sssd.o.d" -MT ${OBJECTDIR}/src/mega/sssd.o -o ${OBJECTDIR}/src/mega/sssd.o src/mega/sssd.c 
	
${OBJECTDIR}/src/mega/hx711.o: src/mega/hx711.c  .generated_files/flags/ATmega8/a773d8af571cf44791b0080513c393ac622047e .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/hx711.o.d 
	@${RM} ${OBJECTDIR}/src/mega/hx711.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/hx711.o.d" -MT "${OBJECTDIR}/src/mega/hx711.o.d" -MT ${OBJECTDIR}/src/mega/hx711.o -o ${OBJECTDIR}/src/mega/hx711.o src/mega/hx711.c 
	
${OBJECTDIR}/src/mega/eeprom.o: src/mega/eeprom.c  .generated_files/flags/ATmega8/c4d9b68370ea76d45866f66822f6372e5e2d7cf8 .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/eeprom.o.d 
	@${RM} ${OBJECTDIR}/src/mega/eeprom.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/eeprom.o.d" -MT "${OBJECTDIR}/src/mega/eeprom.o.d" -MT ${OBJECTDIR}/src/mega/eeprom.o -o ${OBJECTDIR}/src/mega/eeprom.o src/mega/eeprom.c 
	
${OBJECTDIR}/src/mega/keypadEvent.o: src/mega/keypadEvent.c  .generated_files/flags/ATmega8/4d784f1c1249327988e6816d1fed48a5b99f45e0 .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/keypadEvent.o.d 
	@${RM} ${OBJECTDIR}/src/mega/keypadEvent.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/keypadEvent.o.d" -MT "${OBJECTDIR}/src/mega/keypadEvent.o.d" -MT ${OBJECTDIR}/src/mega/keypadEvent.o -o ${OBJECTDIR}/src/mega/keypadEvent.o src/mega/keypadEvent.c 
	
${OBJECTDIR}/_ext/88461258/exEEPROM.o: D:/Company/SMART/MEGA/mega.X/src/mega/exEEPROM.c  .generated_files/flags/ATmega8/b5aa468a001656ba8c8a403066e4edd636f08ca1 .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/_ext/88461258" 
	@${RM} ${OBJECTDIR}/_ext/88461258/exEEPROM.o.d 
	@${RM} ${OBJECTDIR}/_ext/88461258/exEEPROM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/88461258/exEEPROM.o.d" -MT "${OBJECTDIR}/_ext/88461258/exEEPROM.o.d" -MT ${OBJECTDIR}/_ext/88461258/exEEPROM.o -o ${OBJECTDIR}/_ext/88461258/exEEPROM.o D:/Company/SMART/MEGA/mega.X/src/mega/exEEPROM.c 
	
${OBJECTDIR}/_ext/88461258/gpio.o: D:/Company/SMART/MEGA/mega.X/src/mega/gpio.c  .generated_files/flags/ATmega8/67cdf6722f59721753c39f4bbe5a8caf06584fe .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/_ext/88461258" 
	@${RM} ${OBJECTDIR}/_ext/88461258/gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/88461258/gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/88461258/gpio.o.d" -MT "${OBJECTDIR}/_ext/88461258/gpio.o.d" -MT ${OBJECTDIR}/_ext/88461258/gpio.o -o ${OBJECTDIR}/_ext/88461258/gpio.o D:/Company/SMART/MEGA/mega.X/src/mega/gpio.c 
	
${OBJECTDIR}/_ext/88461258/csma_cd.o: D:/Company/SMART/MEGA/mega.X/src/mega/csma_cd.c  .generated_files/flags/ATmega8/99adb7441d1e860717259d9885357869bd47efd4 .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/_ext/88461258" 
	@${RM} ${OBJECTDIR}/_ext/88461258/csma_cd.o.d 
	@${RM} ${OBJECTDIR}/_ext/88461258/csma_cd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/88461258/csma_cd.o.d" -MT "${OBJECTDIR}/_ext/88461258/csma_cd.o.d" -MT ${OBJECTDIR}/_ext/88461258/csma_cd.o -o ${OBJECTDIR}/_ext/88461258/csma_cd.o D:/Company/SMART/MEGA/mega.X/src/mega/csma_cd.c 
	
${OBJECTDIR}/src/mega/utility.o: src/mega/utility.c  .generated_files/flags/ATmega8/73a8ea2888b314f8730fe098c1154718b9b1751f .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/utility.o.d 
	@${RM} ${OBJECTDIR}/src/mega/utility.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/utility.o.d" -MT "${OBJECTDIR}/src/mega/utility.o.d" -MT ${OBJECTDIR}/src/mega/utility.o -o ${OBJECTDIR}/src/mega/utility.o src/mega/utility.c 
	
${OBJECTDIR}/src/mega/SSD.o: src/mega/SSD.c  .generated_files/flags/ATmega8/8ec724aa3af5b884c8e0c45001239d438b0fcab7 .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/SSD.o.d 
	@${RM} ${OBJECTDIR}/src/mega/SSD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/SSD.o.d" -MT "${OBJECTDIR}/src/mega/SSD.o.d" -MT ${OBJECTDIR}/src/mega/SSD.o -o ${OBJECTDIR}/src/mega/SSD.o src/mega/SSD.c 
	
${OBJECTDIR}/src/mega/twi.o: src/mega/twi.c  .generated_files/flags/ATmega8/4411e0f9fb101f26879f6e9808b98cef633ffca2 .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/twi.o.d 
	@${RM} ${OBJECTDIR}/src/mega/twi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/twi.o.d" -MT "${OBJECTDIR}/src/mega/twi.o.d" -MT ${OBJECTDIR}/src/mega/twi.o -o ${OBJECTDIR}/src/mega/twi.o src/mega/twi.c 
	
${OBJECTDIR}/src/mega.o: src/mega.c  .generated_files/flags/ATmega8/483df24e85e8efd01b207065935cf3d7fac66ca3 .generated_files/flags/ATmega8/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/mega.o.d 
	@${RM} ${OBJECTDIR}/src/mega.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O2 -Og -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -mcall-prologues -DXPRJ_ATmega8=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega.o.d" -MT "${OBJECTDIR}/src/mega.o.d" -MT ${OBJECTDIR}/src/mega.o -o ${OBJECTDIR}/src/mega.o src/mega.c 
	
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
# Rules for buildStep: createLPPResponseFiles
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
nbproject/$(CND_CONF).$(IMAGE_TYPE):   nbproject/Makefile-${CND_CONF}.mk    
		@cmd /C "gnuecho -n "$(MP_EXTRA_AR_PRE) --target $(MP_PROCESSOR_OPTION) " > nbproject/ATmega8.debug"
	@cmd /C "gnuecho -n "r -o ${DISTDIR}/mega.X.a " >> nbproject/ATmega8.debug"
	@cmd /C "gnuecho -n "${OBJECTDIR}/src/mega/sys.o ${OBJECTDIR}/src/mega/lcd.o ${OBJECTDIR}/src/mega/buffers.o ${OBJECTDIR}/src/mega/button.o ${OBJECTDIR}/src/mega/keypad.o ${OBJECTDIR}/src/mega/rtc.o ${OBJECTDIR}/src/mega/menu.o ${OBJECTDIR}/inc/mega/buz.o ${OBJECTDIR}/src/mega/spi.o ${OBJECTDIR}/src/mega/sssd.o ${OBJECTDIR}/src/mega/hx711.o ${OBJECTDIR}/src/mega/eeprom.o ${OBJECTDIR}/src/mega/keypadEvent.o ${OBJECTDIR}/_ext/88461258/exEEPROM.o ${OBJECTDIR}/_ext/88461258/gpio.o ${OBJECTDIR}/_ext/88461258/csma_cd.o ${OBJECTDIR}/src/mega/utility.o " >> nbproject/ATmega8.debug"
	@cmd /C "gnuecho -n "${OBJECTDIR}/src/mega/SSD.o ${OBJECTDIR}/src/mega/twi.o ${OBJECTDIR}/src/mega.o " >> nbproject/ATmega8.debug"

	
else
nbproject/$(CND_CONF).$(IMAGE_TYPE):   nbproject/Makefile-${CND_CONF}.mk   
		@cmd /C "gnuecho -n "$(MP_EXTRA_AR_PRE) --target $(MP_PROCESSOR_OPTION) " > nbproject/ATmega8.production"
	@cmd /C "gnuecho -n "r -o ${DISTDIR}/mega.X.a " >> nbproject/ATmega8.production"
	@cmd /C "gnuecho -n "${OBJECTDIR}/src/mega/sys.o ${OBJECTDIR}/src/mega/lcd.o ${OBJECTDIR}/src/mega/buffers.o ${OBJECTDIR}/src/mega/button.o ${OBJECTDIR}/src/mega/keypad.o ${OBJECTDIR}/src/mega/rtc.o ${OBJECTDIR}/src/mega/menu.o ${OBJECTDIR}/inc/mega/buz.o ${OBJECTDIR}/src/mega/spi.o ${OBJECTDIR}/src/mega/sssd.o ${OBJECTDIR}/src/mega/hx711.o ${OBJECTDIR}/src/mega/eeprom.o ${OBJECTDIR}/src/mega/keypadEvent.o ${OBJECTDIR}/_ext/88461258/exEEPROM.o ${OBJECTDIR}/_ext/88461258/gpio.o ${OBJECTDIR}/_ext/88461258/csma_cd.o ${OBJECTDIR}/src/mega/utility.o " >> nbproject/ATmega8.production"
	@cmd /C "gnuecho -n "${OBJECTDIR}/src/mega/SSD.o ${OBJECTDIR}/src/mega/twi.o ${OBJECTDIR}/src/mega.o " >> nbproject/ATmega8.production"

	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: linkWithResponseFileArchive
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/mega.X.${OUTPUT_SUFFIX}: ${OBJECTFILES} nbproject/$(CND_CONF).$(IMAGE_TYPE)  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_AR}  @nbproject/$(CND_CONF).$(IMAGE_TYPE) 
	@${RM} ${DISTDIR}/mega.X.hex 
	
else
${DISTDIR}/mega.X.${OUTPUT_SUFFIX}: ${OBJECTFILES} nbproject/$(CND_CONF).$(IMAGE_TYPE)  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_AR}  @nbproject/$(CND_CONF).$(IMAGE_TYPE) 
	
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
