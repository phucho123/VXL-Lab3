/*
 * fsm_automatic.h
 *
 *  Created on: Oct 11, 2022
 *      Author: ADMIN
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

#include "global.h"
#include "software_timer.h"
#include "button.h"
#include "display_7segment.h"
#include "traffic_led.h"

//extern int led_duration[3];
//extern int led_state1;
//extern int led_state2;
//extern int set_duration;

void fsm_automatic_run();
void fsm_man_run();


#endif /* INC_FSM_AUTOMATIC_H_ */
