/*
 * main.c
 *
 *  Created on: Jan 25, 2021
 *      Author: alex
 */

#include "stm32f3xx_hal.h"
#include "main.h"

void SystemClockConfig(void);

int main()
{
	HAL_Init();
	SystemClockConfig();
	return 0;
}

void SystemClockConfig(void)
{

}
