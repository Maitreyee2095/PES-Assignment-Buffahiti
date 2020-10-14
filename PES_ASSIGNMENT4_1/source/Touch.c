/*
 * Touch.c
 *
 *  Created on: Oct 9, 2020
 *  Author: maitreyee
 *
 *  Code is inspired from
 *  @Author:Howdy Pierce and Alexander G Dean
 */


// TSI initialization function

#include"Touch.h"

void Touch_Init()
{
	SIM->SCGC5 |= SIM_SCGC5_TSI_MASK; // enabling the clock

	TSI0->GENCS =TSI_GENCS_OUTRGF_MASK |  // Out of range flag, set to 1 to clear
		TSI_GENCS_MODE(0U) | //operating in non-noise mode
		TSI_GENCS_REFCHRG(0U) | //reference oscillator charge and discharge value 500nA
		TSI_GENCS_DVOLT(0U) | //oscillator voltage rails set to default
		TSI_GENCS_EXTCHRG(0U) | //electrode oscillator charge and discharge value 500nA
		TSI_GENCS_PS(0U) |  // frequency clcok divided by one
		TSI_GENCS_NSCN(31U) | //scanning the electrode 32 times
		TSI_GENCS_TSIEN_MASK | //enabling the TSI module
		TSI_GENCS_STPE_MASK |
		TSI_GENCS_EOSF_MASK; // writing one to clear the end of scan flag
}


//Touch scan function


int touch_scan(void)
{
	__disable_irq();
	int scan = 0;
	TSI0->DATA =  TSI_DATA_TSICH(9U); // Using channel 9 of the TSI
	TSI0->DATA |= TSI_DATA_SWTS_MASK;  // Software trigger to start scan
	//for(int i=0; i<10000; i++)// hard spin until scan completes
	while (! (TSI0->GENCS & TSI_GENCS_EOSF_MASK) )
	;

	scan = TSI0->DATA & 0xFFFF;

	TSI0->GENCS |= TSI_GENCS_EOSF_MASK ; // Reset end of scan flag
	__enable_irq();
	if(scan>TOUCH_THRESHOLD)
		return 1;
	else
		return 0;
}

