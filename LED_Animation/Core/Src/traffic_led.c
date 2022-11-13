/*
 * traffic_led.c
 *
 *  Created on: Nov 10, 2022
 *      Author: ADMIN
 */
#include "traffic_led.h"
void turn_led1(int index){
	switch(index){
		case 0:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1);
			break;

		default:
			break;
	}
}
void turn_led2(int index){
	switch(index){
		case 0:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 1);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 1);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);
			break;

		default:
			break;
	}
}
void toggle_led(int index){
	switch(index){
		case 0:
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7);
			break;
		case 1:
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_9);
			break;
		case 2:
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
			break;
		default:
			break;
	}
}

