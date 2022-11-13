/*
 * software_timer.c
 *
 *  Created on: Oct 11, 2022
 *      Author: ADMIN
 */

#include "software_timer.h"

int timer_counter1 = 0,timer_counter2 = 0,timer_counter3 = 0;
int timer_flag1 = 0,timer_flag2 = 0,timer_flag3 = 0;
void setTimer1(int duration){
	timer_counter1 = duration/TICK;
	timer_flag1 = 0;
}
void setTimer2(int duration){
	timer_counter2 = duration/TICK;
	timer_flag2 = 0;
}
void setTimer3(int duration){
	timer_counter3 = duration/TICK;
	timer_flag3 = 0;
}
void timerRun(){
	if(timer_counter1 > 0){
		timer_counter1--;
		if(timer_counter1 <= 0){
			timer_flag1 = 1;
		}
	}
	if(timer_counter2 > 0){
		timer_counter2--;
		if(timer_counter2 <= 0){
			timer_flag2 = 1;
		}
	}
	if(timer_counter3 > 0){
		timer_counter3--;
		if(timer_counter3 <= 0){
			timer_flag3 = 1;
		}
	}
}
