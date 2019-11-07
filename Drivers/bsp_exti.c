/*
******************************************************************************
* @file   bsp_exti.c
* @author
* @version
* @date
* @brief  �����ж�����
******************************************************************************
*/

#include "bsp_exti.h"

/**
* @brief  EXTI�ж�����
* @param  
* @retval None
*/

void KEY_GPIO_Config(void)
{
 GPIO_InitTypeDef GPIO_InitStructure;
 EXTI_InitTypeDef EXTI_InitStructure;

 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14; 
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
 GPIO_Init(GPIOB, &GPIO_InitStructure);
 
 NVIC_Config(EXTI15_10_IRQn,0,3);

 GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource14);
 EXTI_InitStructure.EXTI_Line = EXTI_Line14;
 
 /* EXTIΪ�ж�ģʽ */
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
 /* �������ж� */
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  /* ʹ���ж� */ 
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);
}
