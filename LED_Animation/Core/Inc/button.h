/*
 * button.h
 *
 *  Created on: Sep 27, 2022
 *      Author: Admin
 */
#include "main.h"

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_


#define NORMAL_STATE SET
#define PRESSED_STATE RESET

extern int button_flag[3];

void getKeyInput();
//void subKeyProcess();


#endif /* INC_BUTTON_H_ */
