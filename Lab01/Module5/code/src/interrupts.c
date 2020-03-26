/*----------------------------------------------------------------------------
 Interrupts C file
 *----------------------------------------------------------------------------*/
#include "interrupts.h"
#include "stm32f4xx.h"

void init_interrupts(void){
	//Start clock for the SYSCFG
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
	//Enable debug in low-power modes
	DBGMCU->CR |= DBGMCU_CR_DBG_SLEEP | DBGMCU_CR_DBG_STOP | DBGMCU_CR_DBG_STANDBY;
	//Setup interrupt configuration register for interrupts
	SYSCFG->EXTICR[3] |= SYSCFG_EXTICR4_EXTI13_PC;
  //Set the interrupt mask
	EXTI->IMR |= (EXTI_IMR_MR13);
  //trigger on falling edge
	EXTI->FTSR |= (EXTI_FTSR_TR13);
	//Enable interrupts
	__enable_irq();
	//Set priority
	NVIC_SetPriority(EXTI15_10_IRQn, 0);
	//Clear pending interrupts
	NVIC_ClearPendingIRQ(EXTI15_10_IRQn);
	//Enable the specific interrupt
	NVIC_EnableIRQ(EXTI15_10_IRQn);
}

// *******************************ARM University Program Copyright (c) ARM Ltd 2014*************************************
