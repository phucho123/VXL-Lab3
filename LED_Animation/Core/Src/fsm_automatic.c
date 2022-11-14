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
			status = MODE1; //set status to MODE1
			setTimer1(led_duration[0]); // set timer1 to red led duration
			setTimer2(led_duration[1]); // set timer2 to green led duration
			led_state1 = 0; //set vertical led to red led
			led_state2 = 1; //set horizontal led to green led
			setTimer3(500); //set timer3 to 0.5s to switch between two 7 led
			break;
		case MODE1:
			if(timer_flag1 == 1){
				led_state1 = (led_state1+1)%3; // change vertical led state
				setTimer1(led_duration[led_state1]); //set timer1 to time duration of vertical led state
			}
			if(timer_flag2 == 1){
				led_state2 = (led_state2+1)%3;// change horizontal led state
				setTimer2(led_duration[led_state2]);//set timer1 to time duration of horizontal led state
			}
			if(timer_flag3){
			  setTimer3(500); //set timer3 to 0.5s
			  index_7seg = 1-index_7seg; //switch between two 7 led
			}
			if(button_flag[0] == 1){
				button_flag[0] = 0;
				GPIOA->ODR = 0xffff; //reset state of traffic led
				set_duration = 0; //set time to 0
				status = MODE2; // go to MODE2
			}
			break;
		case MODE2:
			if(timer_flag3){
			  setTimer3(500);
			  index_7seg = 1-index_7seg;
			  toggle_led(0); //toggle 4 traffic led red
			}
			if(button_flag[0] == 1){
				button_flag[0] = 0;
				GPIOA->ODR = 0xffff; //reset traffic led
				set_duration = 0;
				status = MODE3; //go to MODE3
			}
			break;
		case MODE3:
			if(timer_flag3){
				setTimer3(500);
				index_7seg = 1-index_7seg;
				toggle_led(2); //toggle 4 traffic amber led
			}
			if(button_flag[0] == 1){
				button_flag[0] = 0;
				GPIOA->ODR = 0xffff;
				set_duration = 0;
				status = MODE4; //go to MODE4
			}
			break;
		case MODE4:
			if(timer_flag3){
			  setTimer3(500);
			  index_7seg = 1-index_7seg;
			  toggle_led(1); //toggle 4 traffic green led
			}
			if(button_flag[0] == 1){
				button_flag[0] = 0;
				GPIOA->ODR = 0xffff;
				set_duration = 0;
				status = INIT; //return INIT status
			}
			break;
		default:
			break;
	}
}

void fsm_man_run(){
	switch(status){
		case MODE1:
			turn_led1(led_state1); //turn vertical traffic led
			turn_led2(led_state2); //turn horizontal traffic led
			turn_7segment(index_7seg,(int)timer_counter1/100,(int)timer_counter2/100); //turn four 7segment led
			break;
		case MODE2:
			if(button_flag[1]){
			  button_flag[1] = 0;
			  set_duration++; //increase set duration
			  if(set_duration>99){
				  set_duration = 99; //max duration is 99
			  }
			}
			if(button_flag[2]){
			  button_flag[2] = 0;
			  led_duration[0] = set_duration*1000; //save set_duration for led red duration
			}
			turn_7segment(index_7seg,set_duration,2); //turn on four led 7 with set_duration value and 2(MODE2)
			break;
		case MODE3:
			if(button_flag[1]){
				button_flag[1] = 0;
				set_duration++;//increase set duration
				if(set_duration>99){
					set_duration = 99;//max duration is 99
				}
			}
			if(button_flag[2]){
				button_flag[2] = 0;
				led_duration[2] = set_duration*1000;//save set_duration for amber led duration
			}
			turn_7segment(index_7seg,set_duration,3);//turn on four led 7 with set_duration value and 3(MODE3)
			break;
		case MODE4:
			if(button_flag[1]){
			  button_flag[1] = 0;
			  set_duration++;//increase set duration
			  if(set_duration>99){
				  set_duration = 99;//max duration is 99
			  }
			}
			if(button_flag[2]){
			  button_flag[2] = 0;
			  led_duration[1] = set_duration*1000;//save set_duration for green led duration
			}
			turn_7segment(index_7seg,set_duration,4);//turn on four led 7 with set_duration value and 4(MODE4)
			break;
		default:
			break;
	}
}
