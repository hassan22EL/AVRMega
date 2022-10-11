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
#ifndef XC_CMD_H
#define	XC_CMD_H

/*Event Commad*/

#define            NO_CMD                        0x00
#define            WAIT_FOR_RES                  0x01

#define           STATE_REQ_CMD                 0x02
/*Config Res*/
#define       SET_CONFIG_REQ_CMD                0x03
/*Comm Command*/
#define       POWERON_REQ_CMD                      0x04


#define       PING_REQ_CMD                      0x05
#define       REMOVE_CONFIG_REQ                 0x06
#define       PING_STATE_REQ_CMD                      0x07



#define       STATE_RES_CMD                          0x81
#define       PING_RES_CMD                           0x82
#define       POWERON_RES_CMD                        0x83
#define       CONFIG_RES_CMD                         0x84
#define       CONFRAM_STATE_CMD                      0x85
#define       PING_STATE_RES_CMD                     0x86




#endif	/* XC_HEADER_TEMPLATE_H */

