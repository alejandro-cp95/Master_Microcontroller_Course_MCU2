/*
 * main.c
 *
 *  Created on: Jan 25, 2021
 *      Author: alex
 */

#include "stm32f3xx_hal.h"
#include "main.h"

UART_HandleTypeDef huart2;

void SystemClockConfig(void);
void UART2_Init(void);
void Error_handler(void);

int main()
{
	HAL_Init();
	SystemClockConfig();
	UART2_Init();
	return 0;
}

void SystemClockConfig(void)
{

}

void UART2_Init(void)
{
	huart2.Instance = USART2;
	huart2.Init.BaudRate = 115200;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart2.Init.Mode = UART_MODE_TX_RX;
	if(HAL_UART_Init(&huart2) != HAL_OK)
	{
		Error_handler();
	}
}

void Error_handler(void)
{

}
