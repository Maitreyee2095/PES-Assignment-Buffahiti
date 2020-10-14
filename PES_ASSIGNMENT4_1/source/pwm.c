/*
 * pwm.c
 *
 *  Created on: Oct 9, 2020
 *
 * @author  Maitreyee Rao
 *
 * @code inspiration from
 * @author : Alexander G Dean
 */



/* insert other include files here. */

#include "PWM.h"



/**********************************************************************************************************************
 * void Init_Blue_LED_PWM(uint16_t period): Function to Initialize BLUE LED as PWM OUTPUT
 * @PARAM: Takes uint16_t period as parameter; Its the period for PWM
 *
 **********************************************************************************************************************/
void Init_Blue_LED_PWM(uint16_t period){
	// Enable clock to port D
	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;;

	// Blue FTM0_CH1, Mux Alt 4
	// Set pin to FTMs
	PORTD->PCR[BLUE_LED_PIN] &= ~PORT_PCR_MUX_MASK;
	PORTD->PCR[BLUE_LED_PIN] |= PORT_PCR_MUX(4);

	// Configure TPM
	SIM->SCGC6 |= SIM_SCGC6_TPM0_MASK;
	//set clock source for tpm: 48 MHz
	SIM->SOPT2 |= (SIM_SOPT2_TPMSRC(1) | SIM_SOPT2_PLLFLLSEL_MASK);
	//load the counter and mod
	TPM0->MOD = period-1;
	//set TPM count direction to up with a divide by 2 prescaler
	TPM0->SC =  TPM_SC_PS(1);
	// Continue operation in debug mode
	TPM0->CONF |= TPM_CONF_DBGMODE(3);
	// Set channel 1 to edge-aligned low-true PWM
	TPM0->CONTROLS[1].CnSC = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK;
	// Set initial duty cycle
	TPM0->CONTROLS[1].CnV = 0;
	// Start TPM
	TPM0->SC |= TPM_SC_CMOD(1);
}
/**********************************************************************************************************************
 * void Init_RED_LED_PWM(uint16_t period): Function to Initialize RED LED as PWM OUTPUT
 * @PARAM: Takes uint16_t period as parameter; Its the period for PWM
 *
 **********************************************************************************************************************/
void Init_RED_LED_PWM(uint16_t period)
{
	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;;

	// RED FTM2_CH0, Mux Alt 3
	// Set pin to FTMs
	PORTB->PCR[RED_LED_PIN] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[RED_LED_PIN] |= PORT_PCR_MUX(3);

	// Configure TPM
	SIM->SCGC6 |= SIM_SCGC6_TPM2_MASK;
	//set clock source for tpm: 48 MHz
	SIM->SOPT2 |= (SIM_SOPT2_TPMSRC(1) | SIM_SOPT2_PLLFLLSEL_MASK);
	//load the counter and mod
	TPM2->MOD = period-1;
	//set TPM count direction to up with a divide by 2 prescaler
	TPM2->SC =  TPM_SC_PS(1);
	// Continue operation in debug mode
	TPM2->CONF |= TPM_CONF_DBGMODE(3);
	// Set channel 1 to edge-aligned low-true PWM
	TPM2->CONTROLS[0].CnSC = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK;
	// Set initial duty cycle
	TPM2->CONTROLS[0].CnV = 0;
	// Start TPM
	TPM2->SC |= TPM_SC_CMOD(1);

}
/**********************************************************************************************************************
 * void Init_Green_LED_PWM(uint16_t period): Function to Initialize GREEN LED as PWM OUTPUT
 * @PARAM: Takes uint16_t period as parameter; Its the period for PWM
 *
 **********************************************************************************************************************/
void Init_GREEN_LED_PWM(uint16_t period)
{
	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;;

	// green FTM2_CH1, Mux Alt 3
	// Set pin to FTMs
	PORTB->PCR[GREEN_LED_PIN] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[GREEN_LED_PIN] |= PORT_PCR_MUX(3);

	// Configure TPM
	SIM->SCGC6 |= SIM_SCGC6_TPM2_MASK;
	//set clock source for tpm: 48 MHz
	SIM->SOPT2 |= (SIM_SOPT2_TPMSRC(1) | SIM_SOPT2_PLLFLLSEL_MASK);
	//load the counter and mod
	TPM2->MOD = period-1;
	//set TPM count direction to up with a divide by 2 prescaler
	TPM2->SC =  TPM_SC_PS(1);
	// Continue operation in debug mode
	TPM2->CONF |= TPM_CONF_DBGMODE(3);
	// Set channel 1 to edge-aligned low-true PWM
	TPM2->CONTROLS[1].CnSC = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK;
	// Set initial duty cycle
	TPM2->CONTROLS[1].CnV = 0;
	// Start TPM
	TPM2->SC |= TPM_SC_CMOD(1);
}
