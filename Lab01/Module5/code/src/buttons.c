/*----------------------------------------------------------------------------
 Button C file
 *----------------------------------------------------------------------------*/
#include "buttons.h"
#include "stm32f4xx.h"

void init_button(void) {
	//Enable IO port C 
	//Set pins to input mode and pull-up mode
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	GPIOC->MODER &= ~GPIO_MODER_MODER13_0 | ~GPIO_MODER_MODER13_1;
	GPIOC->PUPDR |= GPIO_PUPDR_PUPDR13_0;
	GPIOC->PUPDR &= ~GPIO_PUPDR_PUPDR13_1;
}

// *******************************ARM University Program Copyright (c) ARM Ltd 2014*************************************
