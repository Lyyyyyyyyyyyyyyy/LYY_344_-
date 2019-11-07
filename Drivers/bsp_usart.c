/*
 ******************************************************************************
 * @file    bsp_usart.c
 * @author
 * @version
 * @date
 * @brief   USART应用函数接口
 ******************************************************************************
 */

#include "bsp_usart.h"

/**
* @brief  USART1快速初始化
* @param  USART_BaudRate 	波特率设置
* @retval None
* @Using  用于pc端发送，接收调试信息
*/
void USART1_QuickInit(uint32_t USART_BaudRate)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;

	/* 使能 GPIO 时钟 */
	RCC_APB1PeriphClockCmd(USART1_TX_GPIO_CLK, ENABLE);
	/* 使能 USART3时钟 */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);

	/* 配置Tx引脚  */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = USART1_TX_Pin;
	GPIO_Init(USART1_TX_GPIO_PORT, &GPIO_InitStructure);

	/* 配置Rx引脚 */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin = USART1_RX_Pin;
	GPIO_Init(USART1_RX_GPIO_PORT, &GPIO_InitStructure);

	/* 配置串USART 模式 */
	/* 波特率设置：USART_BAUDRATE */
	USART_InitStructure.USART_BaudRate = USART_BaudRate;
	/* 数据长度(数据位+校验位)：8 */
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	/* 停止位：1个停止位 */
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	/* 校验位选择：不使用校验 */
	USART_InitStructure.USART_Parity = USART_Parity_No;
	/* 硬件流控制：不使用硬件流 */
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	/* USART模式控制：同时使能接收和发送 */
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	/* 完成USART初始化配置 */
	USART_Init(USART1, &USART_InitStructure);

	/* 使能串口接收中断 */
	//USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);

	/* 使能串口空闲中断 */
	//USART_ITConfig(USART3, USART_IT_IDLE, ENABLE);

	/* 使能串口 */
	USART_Cmd(USART3, ENABLE);
}

//重定向c库函数printf到串口，重定向后可使用printf函数
int fputc(int ch, FILE *f)
{
	/* 发送一个字节数据到串口 */
	USART_SendData(USART1, (uint8_t)ch);

	/* 等待发送完毕 */
	while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);

	return (ch);
}

