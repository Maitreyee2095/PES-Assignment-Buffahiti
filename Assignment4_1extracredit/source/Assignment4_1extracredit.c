/*
 * @file    Assignment4_1.c
 * @brief   BUFFAHITI TRAFFIC SIGNAL
 * @author  Maitreyee Rao
 */
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
#include "Button.h"



volatile char state;



int main(void) {

  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif



	Init_Blue_LED_PWM(PWM_PERIOD); //INITIALIZE PWM FOR BLUE LED
	Init_RED_LED_PWM(PWM_PERIOD);	//INITIALIZE PWM FOR RED LED
	Init_GREEN_LED_PWM(PWM_PERIOD); //INITIALIZE PWM FOR GREEN LED


	Initialize_Interrupts(); //Initialize GPIO interrupts
	Touch_Init();	//INITIALIZE TOUCH
    Init_SysTick(); // INITIALIZE TIMER
    state='S';	//SET STATE TO STOP
#ifdef DEBUG
PRINTF("\n STARTING MAIN LOOP");
#endif



    while(1) {


    	switch(state)
    	{
    	 case 'S' :
    	        stop_state();
    	         break;
    	 case 'G' :

    	        go_state();
    	         break;
    	 case 'W' :

    		 	 warning_state();
				 break;
    	 case 'C' :

				 crosswalk_state();
    		 	 break;

    	}



    }
    return 0 ;
}

