/*
 ******************************************************************************
 * @file    bsp_usart.c
 * @author
 * @version
 * @date
 * @brief   USARTӦ�ú����ӿ�
 ******************************************************************************
 */

#include "bsp_usart.h"

/**
* @brief  USART1���ٳ�ʼ�����շ���
* @param  USART_BaudRate 	����������
* @retval None
* @Using  ����pc�˷��ͣ����յ�����Ϣ
*/
void USART1_QuickInit(uint32_t USART_BaudRate)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;

	/* ʹ�� GPIO ʱ�� */
	RCC_APB1PeriphClockCmd(USART1_TX_GPIO_CLK, ENABLE);
	/* ʹ�� USART3ʱ�� */
	RCC_APB1PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

	/* ����Tx����  */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = USART1_TX_Pin;
	GPIO_Init(USART1_TX_GPIO_PORT, &GPIO_InitStructure);

	/* ����Rx���� */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin = USART1_RX_Pin;
	GPIO_Init(USART1_RX_GPIO_PORT, &GPIO_InitStructure);

	/* ���ô�USART ģʽ */
	/* ���������ã�USART_BAUDRATE */
	USART_InitStructure.USART_BaudRate = USART_BaudRate;
	/* ���ݳ���(����λ+У��λ)��8 */
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	/* ֹͣλ��1��ֹͣλ */
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	/* У��λѡ�񣺲�ʹ��У�� */
	USART_InitStructure.USART_Parity = USART_Parity_No;
	/* Ӳ�������ƣ���ʹ��Ӳ���� */
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	/* USARTģʽ���ƣ�ͬʱʹ�ܽ��պͷ��� */
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	/* ���USART��ʼ������ */
	USART_Init(USART1, &USART_InitStructure);

	/* ʹ�ܴ��ڽ����ж� */
	//USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);

	/* ʹ�ܴ��ڿ����ж� */
	//USART_ITConfig(USART3, USART_IT_IDLE, ENABLE);

	/* ʹ�ܴ��� */
	USART_Cmd(USART1, ENABLE);
}

/**
 * @brief  UART4���ٳ�ʼ����������
 * @param  USART_BaudRate 	����������
 * @retval None
 * @Using  ����pc�˷��ͣ����յ�����Ϣ
 */
void UART4_Config(uint32_t Baudrate)
{
	USART_InitTypeDef USART_InitStruct;
	GPIO_InitTypeDef  GPIO_InitStruct;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE);

	NVIC_Config(UART4_IRQn,0,1);

	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_11;
	GPIO_Init(GPIOC, &GPIO_InitStruct);

	USART_InitStruct.USART_BaudRate = Baudrate;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	USART_Init(UART4, &USART_InitStruct);

	USART_ITConfig(UART4, USART_IT_RXNE, ENABLE);
	USART_ClearITPendingBit(UART4, USART_IT_RXNE);

	USART_Cmd(UART4, ENABLE);
}

//�ض���c�⺯��printf�����ڣ��ض�����ʹ��printf����
int fputc(int ch, FILE *f)
{
	/* ����һ���ֽ����ݵ����� */
	USART_SendData(USART1, (uint8_t)ch);

	/* �ȴ�������� */
	while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);

	return (ch);
}

int fgetc(FILE *f)
{
	while (USART_GetFlagStatus(UART4, USART_FLAG_RXNE) == RESET);
	return (int)USART_ReceiveData(UART4);
}

