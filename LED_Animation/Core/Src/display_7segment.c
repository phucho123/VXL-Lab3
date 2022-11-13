/*
 * display_7segment.c
 *
 *  Created on: Nov 10, 2022
 *      Author: ADMIN
 */
#include "display_7segment.h"
int arr[10] = {
	0x00C0,  //0
	0x00F9,  //1
	0x00A4,  //2
	0x00B0,  //3
	0x0099,  //4
	0x0092,  //5
	0x0082,  //6
	0x00F8,  //7
	0x0080,  //8
	0x0090,  //9
};
void display_7seg1(int num){
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,((arr[num]>>0)&0x01));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,((arr[num]>>1)&0x01));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,((arr[num]>>2)&0x01));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,((arr[num]>>3)&0x01));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,((arr[num]>>4)&0x01));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,((arr[num]>>5)&0x01));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,((arr[num]>>6)&0x01));
}
void display_7seg2(int num){
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,((arr[num]>>0)&0x01));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,((arr[num]>>1)&0x01));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,((arr[num]>>2)&0x01));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,((arr[num]>>3)&0x01));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,((arr[num]>>4)&0x01));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,((arr[num]>>5)&0x01));
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,((arr[num]>>6)&0x01));
}
void turn_7segment(int index,int num1,int num2){
	switch(index){
		case 0:
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,0);
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,1);
			display_7seg1((int)num1/10);

			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,0);
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_13,1);
			display_7seg2((int)num2/10);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,1);
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,0);
			display_7seg1(num1%10);

			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,1);
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_13,0);
			display_7seg2(num2%10);
			break;
		default:
			break;
	}
}
