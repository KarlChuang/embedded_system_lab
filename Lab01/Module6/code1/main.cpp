/*----------------------------------------------------------------------------
LAB EXERCISE - Simple LED blinky
 ----------------------------------------
In this exercise we will create a program that blinks a LED while the user button is being pressed.

	GOOD LUCK!
 *----------------------------------------------------------------------------*/

#include "mbed.h"

// Create a DigitalOut objects for the LED
DigitalOut LED(LED1);

// Create a DigitalIn objects for the button. 
DigitalIn  BUTTON (USER_BUTTON);

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/
int main() {

	while(1) {
		// The buttons is active low
    // If the button is pressed the LED blinks twice per second
		if(!BUTTON){
			LED = !LED;
		}
		// Otherwise the LED is switch off.
		else {
			LED = 0;
		}
		wait(0.25);
  }
}
