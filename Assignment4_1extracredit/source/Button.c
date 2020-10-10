/*
 * Button.c
 *
 *  Created on: Oct 10, 2020
 *      Author: MAITREYEE RAO
 */
#include "Button.h"
extern char state;
extern int button_pressed;
void Initialize_Interrupts(void){

	/* Configure PORT peripheral. Select GPIO and enable pull-up
	resistors and interrupts on all edges for pins connected to switches */
	PORTD->PCR[SW_pin] = PORT_PCR_MUX(1) | PORT_PCR_PS_MASK |
		PORT_PCR_PE_MASK | PORT_PCR_IRQC(11);

	/* Configure NVIC */
	NVIC_SetPriority(PORTD_IRQn,1);
	NVIC_ClearPendingIRQ(PORTD_IRQn);
	NVIC_EnableIRQ(PORTD_IRQn);

	/* Configure PRIMASK */
	__enable_irq();
}

void PORTD_IRQHandler(void) {

	// Read switch
	if ((PORTD->ISFR & (1<<SW_pin))==0)
		return;
	button_pressed=1;

	PORTD->ISFR &= (1<<SW_pin);

}
