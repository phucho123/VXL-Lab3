
#include"button.h"

int KeyReg0[3] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg1[3] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg2[3] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg3[3] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};


int TimeOutForKeyPress[3] = {500,70,500};

int turn = 0;
int button_flag[3] = {0,0,0};

//void subKeyProcess(){
//	//TODO
//	button_flag[0] = 1;
//}

void getKeyInput(){
	for(int i = 0;i<3;i++){
		KeyReg2[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg0[i];
		if(i == 0){
			KeyReg0[i] = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
		}
		else if(i == 1){
			KeyReg0[i] = HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin);
		}
		else{
			KeyReg0[i] = HAL_GPIO_ReadPin(Button3_GPIO_Port, Button3_Pin);
		}
		if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
			if (KeyReg2[i] != KeyReg3[i]){
			  KeyReg3[i] = KeyReg2[i];

			  if (KeyReg3[i] == PRESSED_STATE){
				if(i == 1) TimeOutForKeyPress[i] = 70; //use to have button_flag[1] every 700ms for pressed button 1
				button_flag[i] = 1;
			  }
			  else{
				  button_flag[i] = 0;
				  TimeOutForKeyPress[i] = 0;
			  }
			}
			else{
				if(i == 1 && TimeOutForKeyPress[i] > 0) TimeOutForKeyPress[i] --;
				if (i == 1 && TimeOutForKeyPress[i] == 0){
				  KeyReg3[i] = NORMAL_STATE;
				}
			}
		}
	}

}
