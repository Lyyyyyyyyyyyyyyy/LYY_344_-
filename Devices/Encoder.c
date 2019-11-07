#include "Encoder.h"

int Encoder_Right;
int Encoder_Left;

void Encoder1_TIM_Mode_Config(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_ICInitTypeDef TIM_ICInitStruct;
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);     //使能定时器4的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);    //使能PB端口时钟

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;	//端口配置
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;   //浮空输入
	GPIO_Init(GPIOB, &GPIO_InitStructure);				    //根据设定参数初始化GPIOB

	TIM_TimeBaseStructure.TIM_Prescaler = 0x0; // 预分频器 
	TIM_TimeBaseStructure.TIM_Period = (u16)(65535); //设定计数器自动重装值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;//选择时钟分频：不分频
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;////TIM向上计数  
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

	TIM_EncoderInterfaceConfig(TIM4, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);   //使用编码器模式3

	TIM_ICInitStruct.TIM_Channel = TIM_Channel_1;                             // 选择捕获通道
	TIM_ICInitStruct.TIM_ICPrescaler = TIM_ICPSC_DIV1;                        // 1 分频，即捕获信号的每个有效边沿都捕获
	TIM_ICInitStruct.TIM_ICPolarity = TIM_ICPolarity_Rising;                  // 设置捕获的边沿
	TIM_ICInitStruct.TIM_ICSelection = TIM_ICSelection_DirectTI;              // 设置捕获通道的信号来自于哪个输入通道，有直连和非直连两种
	TIM_ICInitStruct.TIM_ICFilter = 0;                                        // 不滤波
	TIM_ICInit(TIM4, &TIM_ICInitStruct);

	TIM_ICInitStruct.TIM_Channel = TIM_Channel_2;
	TIM_ICInitStruct.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	TIM_ICInitStruct.TIM_ICPolarity = TIM_ICPolarity_Rising;
	TIM_ICInitStruct.TIM_ICSelection = TIM_ICSelection_DirectTI;
	TIM_ICInitStruct.TIM_ICFilter = 0;
	TIM_ICInit(TIM4, &TIM_ICInitStruct);

	TIM_ClearFlag(TIM4, TIM_FLAG_Update);//清除TIM的更新标志位

	TIM_SetCounter(TIM4, 0);
	TIM_Cmd(TIM4, ENABLE);
}

void Encoder2_TIM_Mode_Config(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_ICInitTypeDef TIM_ICInitStruct;
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);// 需要使能AFIO时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);//使能定时器2的时钟

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//使能PA端口时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);//使能PB端口时钟

	GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2, ENABLE);//引脚重映射

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;	          //端口配置
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //浮空输入
	GPIO_Init(GPIOA, &GPIO_InitStructure);				  //根据设定参数初始化GPIOA

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;				//端口配置
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;   //浮空输入
	GPIO_Init(GPIOB, &GPIO_InitStructure);				    //根据设定参数初始化GPIOB 

	TIM_TimeBaseStructure.TIM_Prescaler = 0x0;						// 预分频器 
	TIM_TimeBaseStructure.TIM_Period = (u16)(65535);				//设定计数器自动重装值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;			//选择时钟分频：不分频
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;		//TIM向上计数  
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

	TIM_EncoderInterfaceConfig(TIM2, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);

	TIM_ICInitStruct.TIM_Channel = TIM_Channel_1;                         // 选择捕获通道
	TIM_ICInitStruct.TIM_ICPrescaler = TIM_ICPSC_DIV1;                    // 1 分频，即捕获信号的每个有效边沿都捕获
	TIM_ICInitStruct.TIM_ICPolarity = TIM_ICPolarity_Rising;              // 设置捕获的边沿
	TIM_ICInitStruct.TIM_ICSelection = TIM_ICSelection_DirectTI;          // 设置捕获通道的信号来自于哪个输入通道，有直连和非直连两种
	TIM_ICInitStruct.TIM_ICFilter = 0;                                    // 不滤波
	TIM_ICInit(TIM2, &TIM_ICInitStruct);

	TIM_ICInitStruct.TIM_Channel = TIM_Channel_2;
	TIM_ICInitStruct.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	TIM_ICInitStruct.TIM_ICPolarity = TIM_ICPolarity_Rising;
	TIM_ICInitStruct.TIM_ICSelection = TIM_ICSelection_DirectTI;
	TIM_ICInitStruct.TIM_ICFilter = 0;
	TIM_ICInit(TIM2, &TIM_ICInitStruct);

	TIM_ClearFlag(TIM2, TIM_FLAG_Update);//清除TIM的更新标志位

	TIM_SetCounter(TIM2, 0);
	TIM_Cmd(TIM2, ENABLE);
}


int Read_Encoder(u8 TIMX)
{
	int Encoder_TIM;
	switch (TIMX)
	{
	case 1:  Encoder_TIM = (short)TIM1->CNT;  TIM1->CNT = 0; break;
	case 2:  Encoder_TIM = (short)TIM2->CNT;  TIM2->CNT = 0; break;
	case 3:  Encoder_TIM = (short)TIM3->CNT;  TIM3->CNT = 0; break;
	case 4:  Encoder_TIM = (short)TIM4->CNT;  TIM4->CNT = 0; break;
	case 5:  Encoder_TIM = (short)TIM5->CNT;  TIM5->CNT = 0; break;
	case 8:  Encoder_TIM = (short)TIM8->CNT;  TIM8->CNT = 0; break;
	default: Encoder_TIM = 0;
	}
	return Encoder_TIM;
}
