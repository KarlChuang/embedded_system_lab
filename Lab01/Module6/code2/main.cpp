/*----------------------------------------------------------------------------
LAB EXERCISE - LED blinky with interrupts
 ----------------------------------------
	In this exercise we will create a program which uses a button to turn on and off a blinky LED.

	GOOD LUCK!
 *----------------------------------------------------------------------------*/

#include "mbed.h"

// Create a DigitalOut objects for the LED
DigitalOut LED(LED1);

// Create an InterruptIn object for the button. 
InterruptIn  BUTTON (USER_BUTTON);


// Create a recurring interruption.
Ticker blinky;
bool active = false;

//Button handler
void BUTTON_ISR(){
    active = !active;
}

//Recurrent handler
void BLINKY_ISR(){
  if (active) LED =!LED;
	else LED = 0;
}

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/
int main() {
// Set up
		BUTTON.mode(PullUp);
		BUTTON.fall(&BUTTON_ISR);
		
		blinky.attach(&BLINKY_ISR, 0.5);
		
	while(1){
		__wfi();	//Wait for interruptions
	}
}
