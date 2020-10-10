/*
 * Timer.h
 *
 *  Created on: Oct 9, 2020
 *
 * @author  Maitreyee Rao
 */

#ifndef TIMER_H_
#define TIMER_H_
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
#define CLOCK 30000 //load with initial value, value for a delay of 10ms.48M/(100*16)=30000.
typedef uint32_t ticktime_t;

//************************************************Function Prototypes*********************************************



/**********************************************************************************************************************
 * void Init_SysTick(void): Function to Initialize SYSTICK TIMERT
 *INITIALIZE SYSTEM CLOCK
 * 48Mhz/16=3Mhz gives delay of 1 second.
 * So 48M/(100*16)=30000, will give delay of 10msec.
 **********************************************************************************************************************/

void Init_SysTick(void);

/**********************************************************************************************************************
 * ticktime_t now():
 * returns the time since boot in one tenth of a second
 **********************************************************************************************************************/

ticktime_t now();


/**********************************************************************************************************************
 * ticktime_t now():
 * returns the time since boot in one tenth of a second
 **********************************************************************************************************************/


void reset_timer(); // resets timer to 0; doesn't affect now() values


/**********************************************************************************************************************
 * ticktime_t get_timer():
 * returns ticks since the last call to get_timer()
 **********************************************************************************************************************/


ticktime_t get_timer();
#endif /* TIMER_H_ */
