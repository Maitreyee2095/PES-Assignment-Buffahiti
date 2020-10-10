/*
 * State_machine.c
 *  Created on: Oct 9, 2020
 *
 * @author  Maitreyee Rao
 */
#include <State_machine_extracredit.h>



//************************************************GLOBAL VARIABLES*********************************************
extern char state;
int start_r;
int end_r;
int start_g;
int end_g;
int start_b;
int end_b;
int button_pressed =0;
void delay(int time)
{
		reset_timer(); //reset timer

		int time_count;
		time_count = get_timer();

		while(time_count!=time) // wait till desired delay is obtained
		{


			time_count = get_timer();
			if(button_pressed)
			{
				return;
			}

		}

		if(button_pressed)
		{
			return;
		}

}

bool gpio_button()
{
	  uint32_t masking_state = __get_PRIMASK();
	  __disable_irq();	//disable interrupts

	  int ret = button_pressed;//store button pressed value
	  button_pressed = 0;

	  __set_PRIMASK(masking_state);//enable interrupts

	  return ret;


}
void stop_state()
{


	//set state colour to #611E3C by setting appropriate duty cycles for RGB LEDs

	TPM2->CONTROLS[0].CnV = 0x61; // setting Cnv will give us duty cycle of CnV/Time period i.e(0x61/0xFF) which is duty cycle of 97/255
	TPM2->CONTROLS[1].CnV =0x1E ; // setting Cnv will give us duty cycle of CnV/Time period i.e(0x1E/0xFF) which is duty cycle of 30/255
	TPM0->CONTROLS[1].CnV =0x3C; //setting Cnv will give us duty cycle of CnV/Time period i.e(0x3C/0xFF) which is duty cycle of 60/255


	delay(delay_count); //delay of 20seconds/5seconds KEEP ONLY WHEN EXTERNAL BUTTON CONNECTED CODE FOR EXTRA CREDIT


	if(button_pressed)	//IF TOUCH IS DETECTED CHANGE STATE TO CROSSWALK
	{
		button_pressed=0;
		state='C';
		// SET START AND END VALUES FOR RED LED FOR TRANSITION FROM #611E3C TO #001030
		start_r=0x61;
		end_r=0x00;
		// SET START AND END VALUES FOR GREEN LED FOR TRANSITION FROM #611E3C TO #001030
		start_g=0x1E;
		end_g=0x10;
		// SET START AND END VALUES FOR BLUE LED FOR TRANSITION FROM #611E3C TO #001030
		start_b=0x3C;
		end_b=0x30;
		//CALL TRANSITION FUNCTION

		#ifdef DEBUG
		PRINTF("\n TIME SINCE STARTUP:%d msec \t BUTTON PRESS DETECTED",now());
		#endif

		transition();
		return;
	}
	//IF TOUCH IS NOT DETECTED TRANSITION TO GREEN STATE
	state='G';

	// SET START AND END VALUES FOR RED LED FOR TRANSITION FROM #611E3C TO #229622
	start_r=0x61;
	end_r=0x22;
	// SET START AND END VALUES FOR GREEN LED FOR TRANSITION FROM #611E3C TO #229622
	start_g=0x1E;
	end_g=0x96;
	// SET START AND END VALUES FOR BLUE LED FOR TRANSITION FROM #611E3C TO #229622
	start_b=0x3C;
	end_b=0x22;
	//CALL TRANSITION FUNCTION
	#ifdef DEBUG
	PRINTF("\n TIME SINCE STARTUP:%d msec \t TRANSITION FROM  STOP TO GO",now());
	#endif
	transition();

}

void go_state()
{

	//set state colour to #229622 by setting appropriate duty cycles for RGB LEDs
	TPM2->CONTROLS[0].CnV = 0x22;// setting Cnv will give us duty cycle of CnV/Time period i.e(0x22/0xFF) which is duty cycle of 34/255
	TPM2->CONTROLS[1].CnV =0x96;// setting Cnv will give us duty cycle of CnV/Time period i.e(0x96/0xFF) which is duty cycle of 150/255
	TPM0->CONTROLS[1].CnV =0x22;// setting Cnv will give us duty cycle of CnV/Time period i.e(0x22/0xFF) which is duty cycle of 34/255

	delay(delay_count);

	if(button_pressed)//IF TOUCH IS DETECTED CHANGE STATE TO CROSSWALK
	{
		button_pressed=0;
		state='C';
		// SET START AND END VALUES FOR RED LED FOR TRANSITION FROM #221022 TO #001030
		start_r=0x22;
		end_r=0x00;
		// SET START AND END VALUES FOR GREEN LED FOR TRANSITION FROM #221022 TO #001030
		start_g=0x96;
		end_g=0x10;
		// SET START AND END VALUES FOR BLUE LED FOR TRANSITION FROM #221022 TO #001030
		start_b=0x22;
		end_b=0x30;
#ifdef DEBUG
PRINTF("\n TIME SINCE STARTUP:%d msec \t BUTTON PRESS DETECTED",now());
#endif
		transition();
		return;
	}

	//IF TOUCH IS NOT DETECTED CHANGE STATE TO WARNING
	state='W';
	// SET START AND END VALUES FOR RED LED FOR TRANSITION FROM #221022 TO #FFB200
	start_r=0x22;
	end_r=0xff;
	// SET START AND END VALUES FOR GREEN LED FOR TRANSITION FROM #221022 TO #FFB200
	start_g=0x96;
	end_g=0xb2;
	// SET START AND END VALUES FOR BLUE LED FOR TRANSITION FROM #221022 TO #FFB200
	start_b=0x22;
	end_b=0x00;


#ifdef DEBUG
PRINTF("\n TIME SINCE STARTUP:%d msec \t TRANSITION FROM GO  TO WARNING",now());
#endif
	transition();

}


void warning_state()
{

	delay(delay_count);
	if(button_pressed)//IF TOUCH IS DETECTED CHANGE STATE TO CROSSWALK
	{
		button_pressed=0;
		state='C';
		// SET START AND END VALUES FOR RED LED FOR TRANSITION FROM #FFB200 TO #001030
		start_r=0xff;
		end_r=0x00;
		// SET START AND END VALUES FOR GREEN LED FOR TRANSITION FROM #FFB200 TO #001030
		start_g=0xb2;
		end_g=0x10;
		// SET START AND END VALUES FOR BLUE LED FOR TRANSITION FROM #FFB200 TO #001030
		start_b=0x00;
		end_b=0x30;
		//START TRANSITION
#ifdef DEBUG
PRINTF("\n TIME SINCE STARTUP:%d msec \t BUTTON PRESS DETECTED",now());
#endif
		transition();
		return;
	}
	//IF TOUCH NOT DETECTED TRANSITION TO STOP STATE
	state='S';
	// SET START AND END VALUES FOR RED LED FOR TRANSITION FROM #FFB200 TO #611E3C
	start_r=0xff;
	end_r=0x61;
	// SET START AND END VALUES FOR GREEN LED FOR TRANSITION FROM #FFB200 TO #611E3C
	start_g=0xb2;
	end_g=0x1E;
	// SET START AND END VALUES FOR BLUE LED FOR TRANSITION FROM #FFB200 TO #611E3C
	start_b=0x00;
	end_b=0x3C;
#ifdef DEBUG
PRINTF("\n TIME SINCE STARTUP:%d msec \t TRANSITION FROM  WARNING TO STOP",now());
#endif

	transition();

}

void crosswalk_state()
{
	//set state colour to #301000 by setting appropriate duty cycles for RGB LEDs
	TPM0->CONTROLS[1].CnV =0x30;
	TPM2->CONTROLS[1].CnV =0x10 ;
	TPM2->CONTROLS[0].CnV = 0x00;
	for(int count=0;count<10;count++)
	{
		//LED ON FOR 750MS
		TPM0->CONTROLS[1].CnV =0x30;
		TPM2->CONTROLS[1].CnV =0x10 ;
		TPM2->CONTROLS[0].CnV = 0x00;
		delay(delay_750ms);
		//LED OFF FOR 250MS
		TPM0->CONTROLS[1].CnV =0;
		TPM2->CONTROLS[1].CnV =0;
		TPM2->CONTROLS[0].CnV = 0;
		delay(delay_250ms);
	}

	//TRANSITION STATE TO GO STATE
	state='G';
	// SET START AND END VALUES FOR RED LED FOR TRANSITION FROM #001030 TO #229622
	start_r=0x00;
	end_r=0x22;
	// SET START AND END VALUES FOR GREEN LED FOR TRANSITION FROM #001030 TO #229622
	start_g=0x10;
	end_g=0x96;
	// SET START AND END VALUES FOR BLUE LED FOR TRANSITION FROM #001030 TO #229622
	start_b=0x30;
	end_b=0x22;
#ifdef DEBUG
PRINTF("\n TIME SINCE STARTUP:%d msec \t TRANSITION FROM CROSSWALK  TO GO",now());
#endif


if(button_pressed)
{
	button_pressed=0;
}

	transition();

}
void transition()
{
	int current_red,current_g,current_b;
	reset_timer();
	int time_count;
	time_count = get_timer();
	if(button_pressed)
	{
		button_pressed=0;
	}
	while((int)time_count<=delay_1000ms ) //TRANSITION OVER 1 SECOND DELAY POLL EVERY 10MS
	{
		current_red=(end_r-start_r)*(int)time_count/100+start_r;
		current_g=(end_g-start_g)*(int)time_count/100+start_g;
		current_b=(end_b-start_b)*(int)time_count/100+start_b;
		//SET CURRENT COLOUR BY SETTING PROPER DUTY CYCLES
		TPM0->CONTROLS[1].CnV =current_b;
		TPM2->CONTROLS[1].CnV =current_g ;
		TPM2->CONTROLS[0].CnV = current_red;
		time_count = get_timer();
	}
	if(button_pressed)
	{
		button_pressed=0;
	}

}
