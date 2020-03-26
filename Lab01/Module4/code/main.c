/*----------------------------------------------------------------------------
LAB EXERCISE - Low Level LED blinky
 ----------------------------------------
	In this exercise you will have to write a program which reads the state of
	the on board button and turns on the on board LED.
	
	GOOD LUCK!
 *----------------------------------------------------------------------------*/
#include "stm32f4xx.h"

// Set input GPIO to read the on board button. 
void init_button(void) {
	//Enable IO port C and set pin C_13 to input mode and pull-up mode.
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	
	//Set pins to input mode
	GPIOC->MODER &= ~GPIO_MODER_MODER13_0 | ~GPIO_MODER_MODER13_1 ;
	
	//Set pins to pull-up mode
	GPIOC->PUPDR |= GPIO_PUPDR_PUPDR13_0;
	GPIOC->PUPDR &= ~GPIO_PUPDR_PUPDR13_1;
}

// Set output GPIO to control the on board LED
void init_led(void) {
	//Enable IO port A and set pin A_5 to output mode, push-pull output state, pull-up mode and fast speed.
	
	//Enable IO port A 
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
  
	//Set the pin to output mode
	GPIOA->MODER |= GPIO_MODER_MODER5_0;
	GPIOA->MODER &= ~GPIO_MODER_MODER5_1;
	
	//Set the pin to push-pull output state
	GPIOA->OTYPER &= ~GPIO_OTYPER_OT_5 ;
	
	//Set pins to pull-up mode
	GPIOA->PUPDR |= GPIO_PUPDR_PUPDR5_0;
	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR5_1;
	
	//Set pin to fast speed
	GPIOA->OSPEEDR &= ~GPIO_OSPEEDER_OSPEEDR5_0;
	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR5_1;
	
}

// Set output pin PA_5 to high
void led_on(void) {
	GPIOA->BSRRL |= GPIO_BSRR_BS_5;
}

// Set output pin PA_5 to low
void led_off(void) {
	GPIOA->BSRRH |= GPIO_BSRR_BS_5;
}

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main() {
	// Initialise LEDs and buttons
	init_led();
	init_button();
	
	while(1){
		// If the button is pressed turn on the LED 
		if(!(GPIOC->IDR & GPIO_IDR_IDR_13)) {
			led_on();
		}
		// Otherwise turn off the LED
		else{ 
			led_off();
		}
		
	}
}

// *******************************ARM University Program Copyright © ARM Ltd 2014*************************************
