/*
 * Timer.c
 *
 *  Created on: Oct 9, 2020
 *
 * @author  Maitreyee Rao
 */



#include "Timer.h"

//************************************************GLOBAL VARIABLES*********************************************
volatile ticktime_t Count=0;
volatile ticktime_t RESET=0;
volatile ticktime_t TIMER=0;

/**********************************************************************************************************************
 * void Init_SysTick(void): Function to Initialize SYSTICK TIMERT
 *INITIALIZE SYSTEM CLOCK
 * 48Mhz/16=3Mhz gives delay of 1 second.
 * So 48M/(100*16)=30000, will give delay of 10msec.
 **********************************************************************************************************************/
void Init_SysTick(void)
{
	SysTick->LOAD=(CLOCK);//load with initial value, value for a delay of 10ms.48M/(100*16)=30000.
	NVIC_SetPriority(SysTick_IRQn,3);//priority of interrupt
	SysTick->VAL=0;//force load of reload value
	SysTick->CTRL = SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk;
}
/**********************************************************************************************************************
 * ticktime_t now():
 * returns the time since boot in one tenth of a second
 **********************************************************************************************************************/
ticktime_t now()
{
	return(Count);
}
/**********************************************************************************************************************
 * ticktime_t now():
 * returns the time since boot in one tenth of a second
 **********************************************************************************************************************/
void reset_timer() // resets timer to 0; doesn't affect now() values
{
	RESET=now();
	Init_SysTick();
}
/**********************************************************************************************************************
 * ticktime_t get_timer():
 * returns ticks since the last call to get_timer()
 **********************************************************************************************************************/
ticktime_t get_timer()
{
	TIMER=Count - RESET;
	return(TIMER);
}

void SysTick_Handler()
{

	Count++;

}
