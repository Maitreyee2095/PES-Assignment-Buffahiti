/*
 * PWM.h
 *
 *  Created on: Oct 9, 2020
 *      Author: maitr
 */

#ifndef PWM_H_
#define PWM_H_

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
#define RED_LED_PIN 18	//define led pin for red led
#define GREEN_LED_PIN 19	//define green led pin
#define BLUE_LED_PIN 1		//define blue led pin
#define PWM_PERIOD (255)		//total period of PWM

//************************************************Function Prototypes*********************************************



/**********************************************************************************************************************
 * void Init_Blue_LED_PWM(uint16_t period): Function to Initialize BLUE LED as PWM OUTPUT
 * @PARAM: Takes uint16_t period as parameter; Its the period for PWM
 *
 **********************************************************************************************************************/
void Init_Blue_LED_PWM(uint16_t period);
/**********************************************************************************************************************
 * void Init_RED_LED_PWM(uint16_t period): Function to Initialize RED LED as PWM OUTPUT
 * @PARAM: Takes uint16_t period as parameter; Its the period for PWM
 *
 **********************************************************************************************************************/
void Init_RED_LED_PWM(uint16_t period);

/**********************************************************************************************************************
 * void Init_Green_LED_PWM(uint16_t period): Function to Initialize GREEN LED as PWM OUTPUT
 * @PARAM: Takes uint16_t period as parameter; Its the period for PWM
 *
 **********************************************************************************************************************/
void Init_GREEN_LED_PWM(uint16_t period);

#endif /* PWM_H_ */
