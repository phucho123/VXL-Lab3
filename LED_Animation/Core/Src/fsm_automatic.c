/*
 * fsm_automatic.c
 *
 *  Created on: Oct 11, 2022
 *      Author: ADMIN
 */


#include "fsm_automatic.h"
int led_duration[3] = {5000,3000,2000};
int led_state1 = 0;
int led_state2 = 1;
int set_duration = 0;
int index_7seg = 0;

void fsm_automatic_run(){
	switch(status){
		case INIT:
			status = MODE1;
			setTimer1(led_duration[0]);
			setTimer2(led_duration[1]);
			led_state1 = 0;
			led_state2 = 1;
			setTimer3(500);
			break;
		case MODE1:
			if(timer_flag1 == 1){
				led_state1 = (led_state1+1)%3;
				setTimer1(led_duration[led_state1]);
			}
			if(timer_flag2 == 1){
				led_state2 = (led_state2+1)%3;
				setTimer2(led_duration[led_state2]);
			}
			if(timer_flag3){
			  setTimer3(500);
			  index_7seg = 1-index_7seg;
			}
			if(button_flag[0] == 1){
				button_flag[0] = 0;
				GPIOA->ODR = 0xffff;
				set_duration = 0;
				status = MODE2;
			}
			break;
		case MODE2:
			if(button_flag[2]){
			  button_flag[2] = 0;
			  led_duration[0] = set_duration*1000;
			}
			if(button_flag[0] == 1){
				button_flag[0] = 0;
				GPIOA->ODR = 0xffff;
				set_duration = 0;
				status = MODE3;
			}
			break;
		case MODE3:
			if(timer_flag3){
				setTimer3(500);
				index_7seg = 1-index_7seg;
				toggle_led(2);
			}
			if(button_flag[0] == 1){
				button_flag[0] = 0;
				GPIOA->ODR = 0xffff;
				set_duration = 0;
				status = MODE4;
			}
			break;
		case MODE4:
			if(timer_flag3){
			  setTimer3(500);
			  index_7seg = 1-index_7seg;
			  toggle_led(1);
			}
			if(button_flag[0] == 1){
				button_flag[0] = 0;
				GPIOA->ODR = 0xffff;
				set_duration = 0;
				status = INIT;
			}
			break;
		default:
			break;
	}
}

void fsm_man_run(){
	switch(status){
		case MODE1:
			turn_led1(led_state1);
			turn_led2(led_state2);
			turn_7segment(index_7seg,(int)timer_counter1/100,(int)timer_counter2/100);
			break;
		case MODE2:
			if(timer_flag3){
			  setTimer3(500);
			  index_7seg = 1-index_7seg;
			  toggle_led(0);
			}
			if(button_flag[1]){
			  button_flag[1] = 0;
			  set_duration++;
			  if(set_duration>99){
				  set_duration = 99;
			  }
			}
			turn_7segment(index_7seg,set_duration,2);
			break;
		case MODE3:
			if(button_flag[1]){
				button_flag[1] = 0;
				set_duration++;
				if(set_duration>99){
					set_duration = 99;
				}
			}
			if(button_flag[2]){
				button_flag[2] = 0;
				led_duration[0] = set_duration*1000;
			}
			turn_7segment(index_7seg,set_duration,3);
			break;
		case MODE4:
			if(button_flag[1]){
			  button_flag[1] = 0;
			  set_duration++;
			  if(set_duration>99){
				  set_duration = 99;
			  }
			}
			if(button_flag[2]){
			  button_flag[2] = 0;
			  led_duration[1] = set_duration*1000;
			}
			turn_7segment(index_7seg,set_duration,4);
			break;
		default:
			break;
	}
}
