/*
 * State_machine.c
 *  Created on: Oct 9, 2020
 *
 * @author  Maitreyee Rao
 */
#include "State_machine.h"
#include"log.h"


//************************************************GLOBAL VARIABLES*********************************************
extern char state;
//setting the colours, as suggested by Jake Micheal
//rgbcolour_t is defined in state_machine.h
const rgbcolour_t STOP ={ .R=0x61, .G=0x1E,.B=0x3C};
const rgbcolour_t GO ={ .R=0x22,.G=0x96,.B=0x22};
const rgbcolour_t WARNING ={ .R=0xFF, .G=0xB2,.B=0x00};
const rgbcolour_t CROSSWALK ={ .R=0x00, .G=0x10,.B=0x3C};
int start_r;
int end_r;
int start_g;
int end_g;
int start_b;
int end_b;

//This code was an inspiration from Jake Micheal, who suggested this in my Peer Review
void log_transition(int start, int end, uint32_t system_time)
{
// only include this code if we are in debug target
#ifdef DEBUG
	const char *strings[] = {
			"STOP",
			"GO  ",
			"WARNING",
			"CROSSWALK"
	};

	// log the transition
	LOG("TRANSITION from  %5s state to %5s state: %u msec \r\n", strings[start], strings[end], system_time);
#endif
}


void set_RGB(int r, int g, int b)
{
		TPM2->CONTROLS[0].CnV = r; // setting Cnv will give us duty cycle of CnV/Time period i.e(r/0xFF) which is duty cycle of r/255
		TPM2->CONTROLS[1].CnV =g ; // setting Cnv will give us duty cycle of CnV/Time period i.e(g/0xFF) which is duty cycle of g/255
		TPM0->CONTROLS[1].CnV =b; //setting Cnv will give us duty cycle of CnV/Time period i.e(b/0xFF) which is duty cycle of b/255

}
void delay(int time)
{
		reset_timer(); //reset timer

		int time_count;
		time_count = get_timer();

		while(time_count!=time) // wait till desired delay is obtained
		{


			time_count = get_timer();

		}

}
void stop_state()
{
	int x;
	int i=0;

	//set state colour to #611E3C by setting appropriate duty cycles for RGB LEDs
	set_RGB(STOP.R,STOP.G,STOP.B);
	x=touch_scan();// SCAN TOUCH SLIDER
	while((i!=delay_count)&&(x==0))//POLL TOUCH SLIDER EVERY 100MS
	{
	    delay(delay_100ms);
	    i++;
	    x=touch_scan();
	}


	if(x)	//IF TOUCH IS DETECTED CHANGE STATE TO CROSSWALK
	{
		state='C';
		// SET START AND END VALUES FOR RED LED FOR TRANSITION FROM #611E3C TO #001030
		start_r=STOP.R;
		end_r=CROSSWALK.R;
		// SET START AND END VALUES FOR GREEN LED FOR TRANSITION FROM #611E3C TO #001030
		start_g=STOP.G;
		end_g=CROSSWALK.G;
		// SET START AND END VALUES FOR BLUE LED FOR TRANSITION FROM #611E3C TO #001030
		start_b=STOP.B;
		end_b=CROSSWALK.B;

		LOG("\t Button pressed \r \n");
		log_transition(STOP_state,CROSSWALK_state,(now()*10));
		//CALL TRANSITION FUNCTION
		transition();
		return;
	}
	//IF TOUCH IS NOT DETECTED TRANSITION TO GREEN STATE
	state='G';

	// SET START AND END VALUES FOR RED LED FOR TRANSITION FROM #611E3C TO #229622
	start_r=STOP.R;
	end_r=GO.R;
	// SET START AND END VALUES FOR GREEN LED FOR TRANSITION FROM #611E3C TO #229622
	start_g=STOP.G;
	end_g=GO.G;
	// SET START AND END VALUES FOR BLUE LED FOR TRANSITION FROM #611E3C TO #229622
	start_b=STOP.B;
	end_b=GO.B;

	log_transition(STOP_state,GO_state,(now()*10));
	//CALL TRANSITION FUNCTION
	transition();

}

void go_state()
{
	int x;
	int i=0;
	//set state colour to #229622 by setting appropriate duty cycles for RGB LEDs
	set_RGB(0x22,0x96,0x22);
	x=touch_scan();// SCAN TOUCH SLIDER
	while((i!=delay_count)&&(x==0))//POLL TOUCH SLIDER EVERY 100MS
	{
	    delay(delay_100ms);
	    i++;
	    x=touch_scan();
	}

	if(x)//IF TOUCH IS DETECTED CHANGE STATE TO CROSSWALK
	{
		state='C';
		// SET START AND END VALUES FOR RED LED FOR TRANSITION FROM #221022 TO #001030
		start_r=GO.R;
		end_r=CROSSWALK.R;
		// SET START AND END VALUES FOR GREEN LED FOR TRANSITION FROM #221022 TO #001030
		start_g=GO.G;
		end_g=CROSSWALK.G;
		// SET START AND END VALUES FOR BLUE LED FOR TRANSITION FROM #221022 TO #001030
		start_b=GO.B;
		end_b=CROSSWALK.B;

		LOG("\t Button pressed \r \n");
		log_transition(GO_state,CROSSWALK_state,(now()*10));
		//START TRANSITION
		transition();
		return;
	}

	//IF TOUCH IS NOT DETECTED CHANGE STATE TO WARNING
	state='W';
	// SET START AND END VALUES FOR RED LED FOR TRANSITION FROM #221022 TO #FFB200
	start_r=GO.R;
	end_r=WARNING.R;
	// SET START AND END VALUES FOR GREEN LED FOR TRANSITION FROM #221022 TO #FFB200
	start_g=GO.G;
	end_g=WARNING.G;
	// SET START AND END VALUES FOR BLUE LED FOR TRANSITION FROM #221022 TO #FFB200
	start_b=GO.B;
	end_b=WARNING.B;
	log_transition(GO_state,WARNING_state,(now()*10));
	//START TRANSITION
	transition();

}


void warning_state()
{
	int i=0;
	int x;


	x=touch_scan();
	while((i!=delay_warningcount)&&(x==0))//POLL TOUCH SLIDER EVERY 100MS
	{
	    delay(delay_100ms);
	    i++;
	    x=touch_scan();
	}

	if(x)//IF TOUCH IS DETECTED CHANGE STATE TO CROSSWALK
	{
		state='C';
		// SET START AND END VALUES FOR RED LED FOR TRANSITION FROM #FFB200 TO #001030
		start_r=WARNING.R;
		end_r=CROSSWALK.R;
		// SET START AND END VALUES FOR GREEN LED FOR TRANSITION FROM #FFB200 TO #001030
		start_g=WARNING.G;
		end_g=CROSSWALK.G;
		// SET START AND END VALUES FOR BLUE LED FOR TRANSITION FROM #FFB200 TO #001030
		start_b=WARNING.B;
		end_b=CROSSWALK.B;

		LOG("\t Button pressed \r \n");
		log_transition(WARNING_state,CROSSWALK_state,(now()*10));
		//START TRANSITION
		transition();
		return;
	}
	//IF TOUCH NOT DETECTED TRANSITION TO STOP STATE
	state='S';
	// SET START AND END VALUES FOR RED LED FOR TRANSITION FROM #FFB200 TO #611E3C
	start_r=WARNING.R;
	end_r=STOP.R;
	// SET START AND END VALUES FOR GREEN LED FOR TRANSITION FROM #FFB200 TO #611E3C
	start_g=WARNING.G;
	end_g=STOP.G;
	// SET START AND END VALUES FOR BLUE LED FOR TRANSITION FROM #FFB200 TO #611E3C
	start_b=WARNING.B;
	end_b=STOP.B;

	log_transition(WARNING_state,STOP_state,(now()*10));
	transition();

}

void crosswalk_state()
{
	//set state colour to #301000 by setting appropriate duty cycles for RGB LEDs
	set_RGB(0x00,0x10,0x30);
	for(int count=0;count<10;count++)
	{
		//LED ON FOR 750MS
		set_RGB(0x00,0x10,0x30);
		delay(delay_750ms);
		//LED OFF FOR 250MS
		set_RGB(0x00,0x00,0x00);
		delay(delay_250ms);
	}

	//TRANSITION STATE TO GO STATE
	state='G';
	// SET START AND END VALUES FOR RED LED FOR TRANSITION FROM #001030 TO #229622
	start_r=CROSSWALK.R;
	end_r=GO.R;
	// SET START AND END VALUES FOR GREEN LED FOR TRANSITION FROM #001030 TO #229622
	start_g=CROSSWALK.G;
	end_g=GO.G;
	// SET START AND END VALUES FOR BLUE LED FOR TRANSITION FROM #001030 TO #229622
	start_b=CROSSWALK.B;
	end_b=GO.B;

	log_transition(CROSSWALK_state,GO_state,(now()*10));

	transition();

}
void transition()
{
	int current_red,current_g,current_b;
	reset_timer();
	int time_count;
	time_count = get_timer();

	while((int)time_count<=delay_1000ms ) //TRANSITION OVER 1 SECOND DELAY POLL EVERY 10MS
	{
		current_red=(end_r-start_r)*(int)time_count/100+start_r;
		current_g=(end_g-start_g)*(int)time_count/100+start_g;
		current_b=(end_b-start_b)*(int)time_count/100+start_b;
		//SET CURRENT COLOUR BY SETTING PROPER DUTY CYCLES
		set_RGB(current_red,current_g,current_b);
		time_count = get_timer();
	}

}
