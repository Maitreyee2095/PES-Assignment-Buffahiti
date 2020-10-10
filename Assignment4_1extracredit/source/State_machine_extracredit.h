/*
 * State_machine.h
 *  Created on: Oct 9, 2020
 *
 * @author  Maitreyee Rao
 */

#ifndef STATE_MACHINE_EXTRACREDIT_H_
#define STATE_MACHINE_EXTRACREDIT_H_
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
 #include "core_cm0plus.h"
/* insert other include files here. */
#include "PWM.h"
#include "Touch.h"
#include "Timer.h"

//************************************************DEFINES*********************************************
#define delay_100ms 10
#define delay_250ms	25
#define delay_750ms	75
#ifdef DEBUG
#define delay_count 500
#define delay_warningcount 300
#endif
#define delay_1000ms 100

#ifdef NDEBUG
#define delay_count 2000
#define delay_warningcount 500
#endif



//************************************************FUNCTION PROTOTYPES*********************************************


/**********************************************************************************************************************
 * bool gpio_button(): returns true if button was pressed
 **********************************************************************************************************************/

bool gpio_button();

/**********************************************************************************************************************
 * void delay(int time): Function to call delay of (time ms)
 * takes argument int time: as time in ms
 **********************************************************************************************************************/
void delay(int time);


/**********************************************************************************************************************
 * void stop_state: Stays in this state for 5 seconds, in debug mode and 20 seconds in production mode
 * transitions to go state if button is not pressed
 * If button is pressed(variable x is used to check if button pressed) transitions to crosswalk state
 **********************************************************************************************************************/
void stop_state();



/**********************************************************************************************************************
 * void go_state: Stays in this state for 5 seconds, in debug mode and 20 seconds in production mode
 * transitions to warning state if button is not pressed
 * If button is pressed(variable x is used to check if button pressed) transitions to crosswalk state
 **********************************************************************************************************************/
void go_state();


/**********************************************************************************************************************
 * void warning_state: Stays in this state for 3 seconds, in debug mode and 5 seconds in production mode
 * transitions to stop state if button is not pressed
 * If button is pressed(variable x is used to check if button pressed) transitions to crosswalk state
 **********************************************************************************************************************/

void warning_state();



/**********************************************************************************************************************
 * void crosswalk_state: blinks for 10 seconds, in debug mode and in production mode.switched on for 750ms and off for 250ms
 * transitions to go state everytime ,
 **********************************************************************************************************************/
void crosswalk_state();


/**********************************************************************************************************************
 * void transition: function for smooth transition from one state to another it uses the formula provided by @Howdy Pierce
 * the transition takes place over 1 second period
 **********************************************************************************************************************/
void transition();

#endif /* STATE_MACHINE_EXTRACREDIT_H_ */
