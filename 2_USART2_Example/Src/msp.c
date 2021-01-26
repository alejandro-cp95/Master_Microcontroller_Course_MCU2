/*
 * msp.c
 *
 *  Created on: Jan 25, 2021
 *      Author: alex
 */

#include "stm32f3xx_hal.h"

void HAL_MspInit(void)
{
	// 1. Set up the priority grouping of the Arm Cortex Mx Processor
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
	// 2. Enable the required system exceptions of the Arm Cortex Mx Processor
	SCB->SHCSR |= 7<<16;
	// 3. Set the priority of the system exceptions
	HAL_NVIC_SetPriority(MemoryManagement_IRQn,0,0);
	HAL_NVIC_SetPriority(BusFault_IRQn,0,0);
	HAL_NVIC_SetPriority(UsageFault_IRQn,0,0);
}
