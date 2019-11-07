/*
|--------------------------------Copyright-------------------------------------|
|                                                                              |
|                          (C)Copyright 2019,yy                          |
|                                                                              |
|                          By:GCU The wolf of team                             |
|------------------------------------------------------------------------------|
|  FileName     : Motor.c
|  Version      : v1.0
|  Author       : yy
|  Date         : 2019-11-06
|  Libsupports  : STM32F10x_StdPeriph_Lib_V3.5.0
|  Description  :
|------------------------------declaration of end------------------------------|
**/
/*------------------------ I N C L U D E - F I L E S -------------------------*/
#include "Motor.h"
/*----------------------------- D E F I N E S --------------------------------*/
/**/
/*------------ L O C A L - F U N C T I O N S - P R O T O T Y P E S -----------*/
/**/
/*--------------------- G L O B A L - F U N C T I O N S ----------------------*/
/**/
/*----------------------- L O C A L - F U N C T I O N S ----------------------*/
/**/
/*------------------------------- FILE OF END --------------------------------*/

incrementalpid_t pid_left;
incrementalpid_t pid_right;
positionpid_t PID_LEFT;
positionpid_t PID_RIGHT;

int Motor_Left;
int Motor_Right;

void Motor_Tim_Config(u16 arr, u16 psc)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_OCInitTypeDef TIM_OCInitStruct;

	//	TIM_DeInit(TIM8);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE);

	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);

	TIM_TimeBaseInitStruct.TIM_Prescaler = psc;
	TIM_TimeBaseInitStruct.TIM_Period = arr;
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM8, &TIM_TimeBaseInitStruct);

	TIM_OCInitStruct.TIM_Pulse = 0;
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OC1Init(TIM8, &TIM_OCInitStruct);
	TIM_OC2Init(TIM8, &TIM_OCInitStruct);
	TIM_OC3Init(TIM8, &TIM_OCInitStruct);
	TIM_OC4Init(TIM8, &TIM_OCInitStruct);

	TIM_CtrlPWMOutputs(TIM8, ENABLE);

	TIM_OC1PreloadConfig(TIM8, TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM8, TIM_OCPreload_Enable);
	TIM_OC3PreloadConfig(TIM8, TIM_OCPreload_Enable);
	TIM_OC4PreloadConfig(TIM8, TIM_OCPreload_Enable);

	TIM_ARRPreloadConfig(TIM8, ENABLE);

	TIM_Cmd(TIM8, ENABLE);
}


