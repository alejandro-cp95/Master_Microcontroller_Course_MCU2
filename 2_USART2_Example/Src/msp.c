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

void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
	GPIO_InitTypeDef uart2_gpio;
	// Enable clock for the USART2 peripheral
	__HAL_RCC_USART2_CLK_ENABLE();
	// Pin muxing configurations
	uart2_gpio.Alternate = GPIO_AF7_USART2;
	uart2_gpio.Mode = GPIO_MODE_AF_PP;
	uart2_gpio.Pin = GPIO_PIN_2;
	uart2_gpio.Pull = GPIO_PULLUP;
	uart2_gpio.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &uart2_gpio);
	// Enable IRQ and set priority
	HAL_NVIC_EnableIRQ(USART2_IRQn);
	HAL_NVIC_SetPriority(USART2_IRQn,15,0);
}
