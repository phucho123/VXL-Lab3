/*
 * software_timer.h
 *
 *  Created on: Oct 11, 2022
 *      Author: ADMIN
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define TICK 10

extern int timer_flag1;
extern int timer_flag2;
extern int timer_flag3;

extern int timer_counter1;
extern int timer_counter2;
extern int timer_counter3;

void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
