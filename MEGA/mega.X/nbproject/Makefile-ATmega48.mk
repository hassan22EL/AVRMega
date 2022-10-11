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
ifeq "$(wildcard nbproject/Makefile-local-ATmega48.mk)" "nbproject/Makefile-local-ATmega48.mk"
include nbproject/Makefile-local-ATmega48.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=ATmega48
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
	${MAKE}  -f nbproject/Makefile-ATmega48.mk ${DISTDIR}/mega.X.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega48A
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/mega/sys.o: src/mega/sys.c  .generated_files/flags/ATmega48/ec1f3a7893e49e87c05816528d7797fbd2772a9d .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/sys.o.d 
	@${RM} ${OBJECTDIR}/src/mega/sys.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/sys.o.d" -MT "${OBJECTDIR}/src/mega/sys.o.d" -MT ${OBJECTDIR}/src/mega/sys.o -o ${OBJECTDIR}/src/mega/sys.o src/mega/sys.c 
	
${OBJECTDIR}/src/mega/lcd.o: src/mega/lcd.c  .generated_files/flags/ATmega48/9ff9bdbeb408482464a0592d4bed2186473a93fc .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/lcd.o.d 
	@${RM} ${OBJECTDIR}/src/mega/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/lcd.o.d" -MT "${OBJECTDIR}/src/mega/lcd.o.d" -MT ${OBJECTDIR}/src/mega/lcd.o -o ${OBJECTDIR}/src/mega/lcd.o src/mega/lcd.c 
	
${OBJECTDIR}/src/mega/buffers.o: src/mega/buffers.c  .generated_files/flags/ATmega48/5b5bd458851c65aa13fece79aaa8eb143272de2a .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/buffers.o.d 
	@${RM} ${OBJECTDIR}/src/mega/buffers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/buffers.o.d" -MT "${OBJECTDIR}/src/mega/buffers.o.d" -MT ${OBJECTDIR}/src/mega/buffers.o -o ${OBJECTDIR}/src/mega/buffers.o src/mega/buffers.c 
	
${OBJECTDIR}/src/mega/button.o: src/mega/button.c  .generated_files/flags/ATmega48/1c23b87a98fd350f4855c4c8f85743118bd03647 .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/button.o.d 
	@${RM} ${OBJECTDIR}/src/mega/button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/button.o.d" -MT "${OBJECTDIR}/src/mega/button.o.d" -MT ${OBJECTDIR}/src/mega/button.o -o ${OBJECTDIR}/src/mega/button.o src/mega/button.c 
	
${OBJECTDIR}/src/mega/keypad.o: src/mega/keypad.c  .generated_files/flags/ATmega48/22922242c47f32aaa8cb827976df6898ed98429c .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/keypad.o.d 
	@${RM} ${OBJECTDIR}/src/mega/keypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/keypad.o.d" -MT "${OBJECTDIR}/src/mega/keypad.o.d" -MT ${OBJECTDIR}/src/mega/keypad.o -o ${OBJECTDIR}/src/mega/keypad.o src/mega/keypad.c 
	
${OBJECTDIR}/src/mega/rtc.o: src/mega/rtc.c  .generated_files/flags/ATmega48/d0dcc2c59103b84fb9ab180e1c2264bf24a82acb .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/rtc.o.d 
	@${RM} ${OBJECTDIR}/src/mega/rtc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/rtc.o.d" -MT "${OBJECTDIR}/src/mega/rtc.o.d" -MT ${OBJECTDIR}/src/mega/rtc.o -o ${OBJECTDIR}/src/mega/rtc.o src/mega/rtc.c 
	
${OBJECTDIR}/src/mega/menu.o: src/mega/menu.c  .generated_files/flags/ATmega48/21c995b5f4b34c117652f4b0fb1a0e0c82c635c4 .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/menu.o.d 
	@${RM} ${OBJECTDIR}/src/mega/menu.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/menu.o.d" -MT "${OBJECTDIR}/src/mega/menu.o.d" -MT ${OBJECTDIR}/src/mega/menu.o -o ${OBJECTDIR}/src/mega/menu.o src/mega/menu.c 
	
${OBJECTDIR}/inc/mega/buz.o: inc/mega/buz.c  .generated_files/flags/ATmega48/83fda4df0aa5e05718743c33e802d9e5caa75ec .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/inc/mega" 
	@${RM} ${OBJECTDIR}/inc/mega/buz.o.d 
	@${RM} ${OBJECTDIR}/inc/mega/buz.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/inc/mega/buz.o.d" -MT "${OBJECTDIR}/inc/mega/buz.o.d" -MT ${OBJECTDIR}/inc/mega/buz.o -o ${OBJECTDIR}/inc/mega/buz.o inc/mega/buz.c 
	
${OBJECTDIR}/src/mega/spi.o: src/mega/spi.c  .generated_files/flags/ATmega48/889a2ecffab1d23bdb488e49ddbbd53a0f0cfc0d .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/spi.o.d 
	@${RM} ${OBJECTDIR}/src/mega/spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/spi.o.d" -MT "${OBJECTDIR}/src/mega/spi.o.d" -MT ${OBJECTDIR}/src/mega/spi.o -o ${OBJECTDIR}/src/mega/spi.o src/mega/spi.c 
	
${OBJECTDIR}/src/mega/sssd.o: src/mega/sssd.c  .generated_files/flags/ATmega48/aa8e6cc50597a39add135c92ef2c82b1dd2d99eb .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/sssd.o.d 
	@${RM} ${OBJECTDIR}/src/mega/sssd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/sssd.o.d" -MT "${OBJECTDIR}/src/mega/sssd.o.d" -MT ${OBJECTDIR}/src/mega/sssd.o -o ${OBJECTDIR}/src/mega/sssd.o src/mega/sssd.c 
	
${OBJECTDIR}/src/mega/hx711.o: src/mega/hx711.c  .generated_files/flags/ATmega48/40ef2c1980f362b1792058ae73c44eb164455a83 .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/hx711.o.d 
	@${RM} ${OBJECTDIR}/src/mega/hx711.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/hx711.o.d" -MT "${OBJECTDIR}/src/mega/hx711.o.d" -MT ${OBJECTDIR}/src/mega/hx711.o -o ${OBJECTDIR}/src/mega/hx711.o src/mega/hx711.c 
	
${OBJECTDIR}/src/mega/eeprom.o: src/mega/eeprom.c  .generated_files/flags/ATmega48/c4324b729f822b4eb9dff070419424137df1f286 .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/eeprom.o.d 
	@${RM} ${OBJECTDIR}/src/mega/eeprom.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/eeprom.o.d" -MT "${OBJECTDIR}/src/mega/eeprom.o.d" -MT ${OBJECTDIR}/src/mega/eeprom.o -o ${OBJECTDIR}/src/mega/eeprom.o src/mega/eeprom.c 
	
${OBJECTDIR}/src/mega/keypadEvent.o: src/mega/keypadEvent.c  .generated_files/flags/ATmega48/24c88cd36d46dfa3ad4410cfefe7aa5f9ce11f94 .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/keypadEvent.o.d 
	@${RM} ${OBJECTDIR}/src/mega/keypadEvent.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/keypadEvent.o.d" -MT "${OBJECTDIR}/src/mega/keypadEvent.o.d" -MT ${OBJECTDIR}/src/mega/keypadEvent.o -o ${OBJECTDIR}/src/mega/keypadEvent.o src/mega/keypadEvent.c 
	
${OBJECTDIR}/_ext/88461258/exEEPROM.o: D:/Company/SMART/MEGA/mega.X/src/mega/exEEPROM.c  .generated_files/flags/ATmega48/9f86db046ba310534ab7a8ac960f1e005d8ec982 .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/_ext/88461258" 
	@${RM} ${OBJECTDIR}/_ext/88461258/exEEPROM.o.d 
	@${RM} ${OBJECTDIR}/_ext/88461258/exEEPROM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/88461258/exEEPROM.o.d" -MT "${OBJECTDIR}/_ext/88461258/exEEPROM.o.d" -MT ${OBJECTDIR}/_ext/88461258/exEEPROM.o -o ${OBJECTDIR}/_ext/88461258/exEEPROM.o D:/Company/SMART/MEGA/mega.X/src/mega/exEEPROM.c 
	
${OBJECTDIR}/_ext/88461258/gpio.o: D:/Company/SMART/MEGA/mega.X/src/mega/gpio.c  .generated_files/flags/ATmega48/251a0ab96b383b8430fb304773bc18addd6fdb7 .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/_ext/88461258" 
	@${RM} ${OBJECTDIR}/_ext/88461258/gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/88461258/gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/88461258/gpio.o.d" -MT "${OBJECTDIR}/_ext/88461258/gpio.o.d" -MT ${OBJECTDIR}/_ext/88461258/gpio.o -o ${OBJECTDIR}/_ext/88461258/gpio.o D:/Company/SMART/MEGA/mega.X/src/mega/gpio.c 
	
${OBJECTDIR}/_ext/88461258/csma_cd.o: D:/Company/SMART/MEGA/mega.X/src/mega/csma_cd.c  .generated_files/flags/ATmega48/d776f1366d05fd4d6743b87c9f2bd49f55f3b90c .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/_ext/88461258" 
	@${RM} ${OBJECTDIR}/_ext/88461258/csma_cd.o.d 
	@${RM} ${OBJECTDIR}/_ext/88461258/csma_cd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/88461258/csma_cd.o.d" -MT "${OBJECTDIR}/_ext/88461258/csma_cd.o.d" -MT ${OBJECTDIR}/_ext/88461258/csma_cd.o -o ${OBJECTDIR}/_ext/88461258/csma_cd.o D:/Company/SMART/MEGA/mega.X/src/mega/csma_cd.c 
	
${OBJECTDIR}/src/mega/utility.o: src/mega/utility.c  .generated_files/flags/ATmega48/9034a54bb0b42238f401c76c3a9f2180f23d7e3c .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/utility.o.d 
	@${RM} ${OBJECTDIR}/src/mega/utility.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/utility.o.d" -MT "${OBJECTDIR}/src/mega/utility.o.d" -MT ${OBJECTDIR}/src/mega/utility.o -o ${OBJECTDIR}/src/mega/utility.o src/mega/utility.c 
	
${OBJECTDIR}/src/mega/SSD.o: src/mega/SSD.c  .generated_files/flags/ATmega48/e59916550dd57f18bf1a05a896b6e8c81b2aa785 .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/SSD.o.d 
	@${RM} ${OBJECTDIR}/src/mega/SSD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/SSD.o.d" -MT "${OBJECTDIR}/src/mega/SSD.o.d" -MT ${OBJECTDIR}/src/mega/SSD.o -o ${OBJECTDIR}/src/mega/SSD.o src/mega/SSD.c 
	
${OBJECTDIR}/src/mega/twi.o: src/mega/twi.c  .generated_files/flags/ATmega48/f931044d28c5392c07cc786df3d4b1e8a7e3ca9f .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/twi.o.d 
	@${RM} ${OBJECTDIR}/src/mega/twi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/twi.o.d" -MT "${OBJECTDIR}/src/mega/twi.o.d" -MT ${OBJECTDIR}/src/mega/twi.o -o ${OBJECTDIR}/src/mega/twi.o src/mega/twi.c 
	
${OBJECTDIR}/src/mega.o: src/mega.c  .generated_files/flags/ATmega48/a98f2a219ba518ae449a94ec378b25d21ef7e8d3 .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/mega.o.d 
	@${RM} ${OBJECTDIR}/src/mega.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega.o.d" -MT "${OBJECTDIR}/src/mega.o.d" -MT ${OBJECTDIR}/src/mega.o -o ${OBJECTDIR}/src/mega.o src/mega.c 
	
else
${OBJECTDIR}/src/mega/sys.o: src/mega/sys.c  .generated_files/flags/ATmega48/2cd2eecc6068db3f43698763fca17ad4f9f6d430 .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/sys.o.d 
	@${RM} ${OBJECTDIR}/src/mega/sys.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/sys.o.d" -MT "${OBJECTDIR}/src/mega/sys.o.d" -MT ${OBJECTDIR}/src/mega/sys.o -o ${OBJECTDIR}/src/mega/sys.o src/mega/sys.c 
	
${OBJECTDIR}/src/mega/lcd.o: src/mega/lcd.c  .generated_files/flags/ATmega48/712ec15f1868c4092b380aacbeb9a1c7d2629f3c .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/lcd.o.d 
	@${RM} ${OBJECTDIR}/src/mega/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/lcd.o.d" -MT "${OBJECTDIR}/src/mega/lcd.o.d" -MT ${OBJECTDIR}/src/mega/lcd.o -o ${OBJECTDIR}/src/mega/lcd.o src/mega/lcd.c 
	
${OBJECTDIR}/src/mega/buffers.o: src/mega/buffers.c  .generated_files/flags/ATmega48/5eb065b674d2012e00bac6cc15f4c556e993e8d4 .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/buffers.o.d 
	@${RM} ${OBJECTDIR}/src/mega/buffers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/buffers.o.d" -MT "${OBJECTDIR}/src/mega/buffers.o.d" -MT ${OBJECTDIR}/src/mega/buffers.o -o ${OBJECTDIR}/src/mega/buffers.o src/mega/buffers.c 
	
${OBJECTDIR}/src/mega/button.o: src/mega/button.c  .generated_files/flags/ATmega48/fd2918b01a57ec27a34accf024652246cd176978 .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/button.o.d 
	@${RM} ${OBJECTDIR}/src/mega/button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/button.o.d" -MT "${OBJECTDIR}/src/mega/button.o.d" -MT ${OBJECTDIR}/src/mega/button.o -o ${OBJECTDIR}/src/mega/button.o src/mega/button.c 
	
${OBJECTDIR}/src/mega/keypad.o: src/mega/keypad.c  .generated_files/flags/ATmega48/a24919032c814fb8b49a65d5c74e66653f4d4f6d .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/keypad.o.d 
	@${RM} ${OBJECTDIR}/src/mega/keypad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/keypad.o.d" -MT "${OBJECTDIR}/src/mega/keypad.o.d" -MT ${OBJECTDIR}/src/mega/keypad.o -o ${OBJECTDIR}/src/mega/keypad.o src/mega/keypad.c 
	
${OBJECTDIR}/src/mega/rtc.o: src/mega/rtc.c  .generated_files/flags/ATmega48/d537bf64fc3993e9eeb25003b1b1bb6c2027b37 .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/rtc.o.d 
	@${RM} ${OBJECTDIR}/src/mega/rtc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/rtc.o.d" -MT "${OBJECTDIR}/src/mega/rtc.o.d" -MT ${OBJECTDIR}/src/mega/rtc.o -o ${OBJECTDIR}/src/mega/rtc.o src/mega/rtc.c 
	
${OBJECTDIR}/src/mega/menu.o: src/mega/menu.c  .generated_files/flags/ATmega48/f380b2b9ca489947f70b9eb6d4b7d1037d2b36d6 .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/menu.o.d 
	@${RM} ${OBJECTDIR}/src/mega/menu.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/menu.o.d" -MT "${OBJECTDIR}/src/mega/menu.o.d" -MT ${OBJECTDIR}/src/mega/menu.o -o ${OBJECTDIR}/src/mega/menu.o src/mega/menu.c 
	
${OBJECTDIR}/inc/mega/buz.o: inc/mega/buz.c  .generated_files/flags/ATmega48/6e2960e0c5b873abf55ee7c709b5cb99a8a22f1a .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/inc/mega" 
	@${RM} ${OBJECTDIR}/inc/mega/buz.o.d 
	@${RM} ${OBJECTDIR}/inc/mega/buz.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/inc/mega/buz.o.d" -MT "${OBJECTDIR}/inc/mega/buz.o.d" -MT ${OBJECTDIR}/inc/mega/buz.o -o ${OBJECTDIR}/inc/mega/buz.o inc/mega/buz.c 
	
${OBJECTDIR}/src/mega/spi.o: src/mega/spi.c  .generated_files/flags/ATmega48/b7b185751666df33fe89ec6caee055a83217081d .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/spi.o.d 
	@${RM} ${OBJECTDIR}/src/mega/spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/spi.o.d" -MT "${OBJECTDIR}/src/mega/spi.o.d" -MT ${OBJECTDIR}/src/mega/spi.o -o ${OBJECTDIR}/src/mega/spi.o src/mega/spi.c 
	
${OBJECTDIR}/src/mega/sssd.o: src/mega/sssd.c  .generated_files/flags/ATmega48/c6f050d359321bef3207a0176fe80eb5781d7a8 .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/sssd.o.d 
	@${RM} ${OBJECTDIR}/src/mega/sssd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/sssd.o.d" -MT "${OBJECTDIR}/src/mega/sssd.o.d" -MT ${OBJECTDIR}/src/mega/sssd.o -o ${OBJECTDIR}/src/mega/sssd.o src/mega/sssd.c 
	
${OBJECTDIR}/src/mega/hx711.o: src/mega/hx711.c  .generated_files/flags/ATmega48/f7bb6517476c7f4d39cdff7f6d366e35e1a00444 .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/hx711.o.d 
	@${RM} ${OBJECTDIR}/src/mega/hx711.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/hx711.o.d" -MT "${OBJECTDIR}/src/mega/hx711.o.d" -MT ${OBJECTDIR}/src/mega/hx711.o -o ${OBJECTDIR}/src/mega/hx711.o src/mega/hx711.c 
	
${OBJECTDIR}/src/mega/eeprom.o: src/mega/eeprom.c  .generated_files/flags/ATmega48/d19b58258ba63db8de799c803c07bca5356c74ab .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/eeprom.o.d 
	@${RM} ${OBJECTDIR}/src/mega/eeprom.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/eeprom.o.d" -MT "${OBJECTDIR}/src/mega/eeprom.o.d" -MT ${OBJECTDIR}/src/mega/eeprom.o -o ${OBJECTDIR}/src/mega/eeprom.o src/mega/eeprom.c 
	
${OBJECTDIR}/src/mega/keypadEvent.o: src/mega/keypadEvent.c  .generated_files/flags/ATmega48/7e0af8be95f29f259f67fdd00e304dd92613210f .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/keypadEvent.o.d 
	@${RM} ${OBJECTDIR}/src/mega/keypadEvent.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/keypadEvent.o.d" -MT "${OBJECTDIR}/src/mega/keypadEvent.o.d" -MT ${OBJECTDIR}/src/mega/keypadEvent.o -o ${OBJECTDIR}/src/mega/keypadEvent.o src/mega/keypadEvent.c 
	
${OBJECTDIR}/_ext/88461258/exEEPROM.o: D:/Company/SMART/MEGA/mega.X/src/mega/exEEPROM.c  .generated_files/flags/ATmega48/ccc49cb99babe56bd440d86c41b59f190d4e15d2 .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/_ext/88461258" 
	@${RM} ${OBJECTDIR}/_ext/88461258/exEEPROM.o.d 
	@${RM} ${OBJECTDIR}/_ext/88461258/exEEPROM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/88461258/exEEPROM.o.d" -MT "${OBJECTDIR}/_ext/88461258/exEEPROM.o.d" -MT ${OBJECTDIR}/_ext/88461258/exEEPROM.o -o ${OBJECTDIR}/_ext/88461258/exEEPROM.o D:/Company/SMART/MEGA/mega.X/src/mega/exEEPROM.c 
	
${OBJECTDIR}/_ext/88461258/gpio.o: D:/Company/SMART/MEGA/mega.X/src/mega/gpio.c  .generated_files/flags/ATmega48/fbf94fdd01423b751b579b8a9a39580df137449d .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/_ext/88461258" 
	@${RM} ${OBJECTDIR}/_ext/88461258/gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/88461258/gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/88461258/gpio.o.d" -MT "${OBJECTDIR}/_ext/88461258/gpio.o.d" -MT ${OBJECTDIR}/_ext/88461258/gpio.o -o ${OBJECTDIR}/_ext/88461258/gpio.o D:/Company/SMART/MEGA/mega.X/src/mega/gpio.c 
	
${OBJECTDIR}/_ext/88461258/csma_cd.o: D:/Company/SMART/MEGA/mega.X/src/mega/csma_cd.c  .generated_files/flags/ATmega48/ce0c6a48a31b3ea54937cb8a5fdec1c7bfd50916 .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/_ext/88461258" 
	@${RM} ${OBJECTDIR}/_ext/88461258/csma_cd.o.d 
	@${RM} ${OBJECTDIR}/_ext/88461258/csma_cd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/_ext/88461258/csma_cd.o.d" -MT "${OBJECTDIR}/_ext/88461258/csma_cd.o.d" -MT ${OBJECTDIR}/_ext/88461258/csma_cd.o -o ${OBJECTDIR}/_ext/88461258/csma_cd.o D:/Company/SMART/MEGA/mega.X/src/mega/csma_cd.c 
	
${OBJECTDIR}/src/mega/utility.o: src/mega/utility.c  .generated_files/flags/ATmega48/3d014446251019939e914ce053cbebb4b0da2723 .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/utility.o.d 
	@${RM} ${OBJECTDIR}/src/mega/utility.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/utility.o.d" -MT "${OBJECTDIR}/src/mega/utility.o.d" -MT ${OBJECTDIR}/src/mega/utility.o -o ${OBJECTDIR}/src/mega/utility.o src/mega/utility.c 
	
${OBJECTDIR}/src/mega/SSD.o: src/mega/SSD.c  .generated_files/flags/ATmega48/8e85cdc5e479d027d2f61a812560871a365f7623 .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/SSD.o.d 
	@${RM} ${OBJECTDIR}/src/mega/SSD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/SSD.o.d" -MT "${OBJECTDIR}/src/mega/SSD.o.d" -MT ${OBJECTDIR}/src/mega/SSD.o -o ${OBJECTDIR}/src/mega/SSD.o src/mega/SSD.c 
	
${OBJECTDIR}/src/mega/twi.o: src/mega/twi.c  .generated_files/flags/ATmega48/2608ac016659c3ff55517d09a0004e1b33d6d07d .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src/mega" 
	@${RM} ${OBJECTDIR}/src/mega/twi.o.d 
	@${RM} ${OBJECTDIR}/src/mega/twi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega/twi.o.d" -MT "${OBJECTDIR}/src/mega/twi.o.d" -MT ${OBJECTDIR}/src/mega/twi.o -o ${OBJECTDIR}/src/mega/twi.o src/mega/twi.c 
	
${OBJECTDIR}/src/mega.o: src/mega.c  .generated_files/flags/ATmega48/b421bfb8a9a498d184d3e28def11c939bc379b1e .generated_files/flags/ATmega48/7300a4ed7e27d28dcabe6ca6fcfb41256bc2446d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/mega.o.d 
	@${RM} ${OBJECTDIR}/src/mega.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -funsigned-char -funsigned-bitfields -Wall -DXPRJ_ATmega48=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/src/mega.o.d" -MT "${OBJECTDIR}/src/mega.o.d" -MT ${OBJECTDIR}/src/mega.o -o ${OBJECTDIR}/src/mega.o src/mega.c 
	
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
