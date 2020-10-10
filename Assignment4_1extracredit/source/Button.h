/*
 * Button.h
 *
 *  Created on: Oct 10, 2020
 *      Author: maitreyee Rao
 */

#ifndef BUTTON_H_
#define BUTTON_H_
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
#include "State_machine_extracredit.h"


#define SW_pin (7)  // switch is connected on pin 7 PORTD

//************************************************FUNCTION PROTOTYPES*********************************************


/**********************************************************************************************************************
 *void Initialize_Interrupts(void):Initialize GPIO interrupt for PORT D
 **********************************************************************************************************************/

void Initialize_Interrupts(void);

/**********************************************************************************************************************
 * Handle interrupt if switch is pressed update flag for button pressed
 **********************************************************************************************************************/
void PORTD_IRQHandler(void);

#endif /* BUTTON_H_ */
