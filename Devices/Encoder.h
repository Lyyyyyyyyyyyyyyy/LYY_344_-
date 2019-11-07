#ifndef __ENCODER_H
#define __ENCODER_H

#include "user_common.h"

extern int Encoder_Right;
extern int Encoder_Left;

void Encoder1_TIM_Mode_Config(void);
void Encoder2_TIM_Mode_Config(void);
	
int Read_Encoder(u8 TIMX);

#endif   /*__ENCODER_H*/
