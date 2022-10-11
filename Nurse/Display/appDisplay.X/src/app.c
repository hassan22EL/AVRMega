/*
 * File:   main.c
 * Author: Hassan
 *
 * Created on 25 ??????, 2021, 10:06 ?
 */

#include "../inc/app.h"

/*0 state  1 sw ID  , 2 - RID*/




void appBoot(void) {

}

void appInit(void) {
    appcommInit();
}

void appSync(void) {
    gu8sentSec++;
}

void appMain(void) {
    if (!appCommStart()) {
        /*show address*/
        u8ToBCD(gu8ssdData, 3, csmaGetAddress());
        ssdPrint(gu8ssdData, 1, 7);
    } else {
        /**/
        displayShowData();
        appRtcSoftTime();
    }
}

