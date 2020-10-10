# PES-Assignment-4
TRAFFIC SIGNAL FOR BUFFAHITI RESIDENTS

In this Assignment we design a traffic signal with certain specifications

1)  STOP state with the colour  #611E3C1
2)	GO state with colour #229622
3)  WARNING state with colour #FFB200
4)  CROSSWALK state with colour #001030

The State Machine.pdf shows the state diagram for the given problem
1)Assignment4_1.c : Contains main function
2)State Machine.c : Contains state functions, transition function
3)State Machine.h : Contains #defines and function prototypes for state machine.c
4)Timer.c : Initialization of timer, timer interrupt,and other functions to track time
5)PWM.c : Initialization for PWM for each LED
6)Touch.c: Initialize touch, and scan touch

Assignment_1extracredit
1) This folder contains project for extra credit 
2) I used GPIO port D interrupt and did the same assignment using external switch
3) I developed another project with rest all same files only change was in my state machine.c and .h files, and included button.c and button.h
4) In the assignment earlier, i was polling the touch sensor after every 100ms, but in extra credit assignment I am using interrupts and priortising them
5) My external switch has  interrupt priority 1 which is greater than timer interrupt and so as soon as button is pressed crroswalk is initiated
6) Created a new project with rest all same settings for easy testing.