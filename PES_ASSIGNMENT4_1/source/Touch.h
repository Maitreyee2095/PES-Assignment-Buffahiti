/*
 * Touch.h
 *
 *  Created on: Oct 9, 2020
 *
 * @author  Maitreyee Rao
 */

#ifndef TOUCH_H_
#define TOUCH_H_
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"

/* insert other include files here. */

#include "MKL25Z4.h"
#include "fsl_debug_console.h"
 #include "core_cm0plus.h"

//************************************************DEFINES*********************************************
#define TOUCH_THRESHOLD 650

//************************************************Function Prototypes*********************************************


/**********************************************************************************************************************
 * void Touch_Init : Initializes capacitive touch pad on freedom board

 **********************************************************************************************************************/

void Touch_Init();
/**********************************************************************************************************************
 * void touch_scan :Scans the electrodes and returns value 1 if the scanned value is greater than defined threshold else returns 0
 * threshold value is used to eliminate the noise that can be observed when no touch is present

 **********************************************************************************************************************/

int touch_scan(void);

#endif /* TOUCH_H_ */
