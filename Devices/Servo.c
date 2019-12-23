/*
|--------------------------------Copyright-------------------------------------|
|                                                                              |
|                          (C)Copyright 2019,yy                          |
|                                                                              |
|                          By:GCU The wolf of team                             |
|------------------------------------------------------------------------------|
|  FileName     : Servo.c
|  Version      : v1.0
|  Author       : yy
|  Date         : 2019-11-06
|  Libsupports  : STM32F10x_StdPeriph_Lib_V3.5.0
|  Description  :
|------------------------------declaration of end------------------------------|
**/
/*------------------------ I N C L U D E - F I L E S -------------------------*/

#include "Servo.h"

/*----------------------------- D E F I N E S --------------------------------*/
int Servo = 15;
/**/
/*------------ L O C A L - F U N C T I O N S - P R O T O T Y P E S -----------*/
/**/
/*--------------------- G L O B A L - F U N C T I O N S ----------------------*/
/**/
/*----------------------- L O C A L - F U N C T I O N S ----------------------*/
/**/
/*------------------------------- FILE OF END --------------------------------*/

void Servo_PWM_Init(u16 arr, u16 psc)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	TIM_TimeBaseStructure.TIM_Period = arr;
	TIM_TimeBaseStructure.TIM_Prescaler = psc;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 15;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC1Init(TIM1, &TIM_OCInitStructure);

	TIM_CtrlPWMOutputs(TIM1, ENABLE);

	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);
	TIM_ARRPreloadConfig(TIM1, ENABLE);

	TIM_Cmd(TIM1, ENABLE);
}
