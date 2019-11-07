#ifndef __BSP_USART_H
#define __BSP_USART_H

#include "user_common.h"

/********USART1_Pin_define********/
#define USART1_TX_GPIO_CLK          RCC_APB2Periph_GPIOA
#define USART1_TX_GPIO_PORT         GPIOA
#define USART1_TX_Pin          	    GPIO_Pin_9
#define USART1_TX_PINSOURCE			GPIO_PinSource9

#define USART1_RX_GPIO_CLK          RCC_APB2Periph_GPIOA
#define USART1_RX_GPIO_PORT         GPIOA
#define USART1_RX_Pin           	GPIO_Pin_10
#define USART1_RX_PINSOURCE			GPIO_PinSource10
/********USART1_Pin_define_END********/

void USART1_QuickInit(uint32_t USART_BaudRate);

int fputc(int ch, FILE *f);

#endif /* __BSP_USART_H */
