#include "Encoder.h"

int Encoder_Right;
int Encoder_Left;

void Encoder1_TIM_Mode_Config(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_ICInitTypeDef TIM_ICInitStruct;
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);     //ʹ�ܶ�ʱ��4��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);    //ʹ��PB�˿�ʱ��

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;	//�˿�����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;   //��������
	GPIO_Init(GPIOB, &GPIO_InitStructure);				    //�����趨������ʼ��GPIOB

	TIM_TimeBaseStructure.TIM_Prescaler = 0x0; // Ԥ��Ƶ�� 
	TIM_TimeBaseStructure.TIM_Period = (u16)(65535); //�趨�������Զ���װֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;//ѡ��ʱ�ӷ�Ƶ������Ƶ
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;////TIM���ϼ���  
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

	TIM_EncoderInterfaceConfig(TIM4, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);   //ʹ�ñ�����ģʽ3

	TIM_ICInitStruct.TIM_Channel = TIM_Channel_1;                             // ѡ�񲶻�ͨ��
	TIM_ICInitStruct.TIM_ICPrescaler = TIM_ICPSC_DIV1;                        // 1 ��Ƶ���������źŵ�ÿ����Ч���ض�����
	TIM_ICInitStruct.TIM_ICPolarity = TIM_ICPolarity_Rising;                  // ���ò���ı���
	TIM_ICInitStruct.TIM_ICSelection = TIM_ICSelection_DirectTI;              // ���ò���ͨ�����ź��������ĸ�����ͨ������ֱ���ͷ�ֱ������
	TIM_ICInitStruct.TIM_ICFilter = 0;                                        // ���˲�
	TIM_ICInit(TIM4, &TIM_ICInitStruct);

	TIM_ICInitStruct.TIM_Channel = TIM_Channel_2;
	TIM_ICInitStruct.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	TIM_ICInitStruct.TIM_ICPolarity = TIM_ICPolarity_Rising;
	TIM_ICInitStruct.TIM_ICSelection = TIM_ICSelection_DirectTI;
	TIM_ICInitStruct.TIM_ICFilter = 0;
	TIM_ICInit(TIM4, &TIM_ICInitStruct);

	TIM_ClearFlag(TIM4, TIM_FLAG_Update);//���TIM�ĸ��±�־λ

	TIM_SetCounter(TIM4, 0);
	TIM_Cmd(TIM4, ENABLE);
}

void Encoder2_TIM_Mode_Config(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_ICInitTypeDef TIM_ICInitStruct;
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);// ��Ҫʹ��AFIOʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);//ʹ�ܶ�ʱ��2��ʱ��

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//ʹ��PA�˿�ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);//ʹ��PB�˿�ʱ��

	GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2, ENABLE);//������ӳ��

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;	          //�˿�����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //��������
	GPIO_Init(GPIOA, &GPIO_InitStructure);				  //�����趨������ʼ��GPIOA

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;				//�˿�����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;   //��������
	GPIO_Init(GPIOB, &GPIO_InitStructure);				    //�����趨������ʼ��GPIOB 

	TIM_TimeBaseStructure.TIM_Prescaler = 0x0;						// Ԥ��Ƶ�� 
	TIM_TimeBaseStructure.TIM_Period = (u16)(65535);				//�趨�������Զ���װֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;			//ѡ��ʱ�ӷ�Ƶ������Ƶ
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;		//TIM���ϼ���  
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

	TIM_EncoderInterfaceConfig(TIM2, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);

	TIM_ICInitStruct.TIM_Channel = TIM_Channel_1;                         // ѡ�񲶻�ͨ��
	TIM_ICInitStruct.TIM_ICPrescaler = TIM_ICPSC_DIV1;                    // 1 ��Ƶ���������źŵ�ÿ����Ч���ض�����
	TIM_ICInitStruct.TIM_ICPolarity = TIM_ICPolarity_Rising;              // ���ò���ı���
	TIM_ICInitStruct.TIM_ICSelection = TIM_ICSelection_DirectTI;          // ���ò���ͨ�����ź��������ĸ�����ͨ������ֱ���ͷ�ֱ������
	TIM_ICInitStruct.TIM_ICFilter = 0;                                    // ���˲�
	TIM_ICInit(TIM2, &TIM_ICInitStruct);

	TIM_ICInitStruct.TIM_Channel = TIM_Channel_2;
	TIM_ICInitStruct.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	TIM_ICInitStruct.TIM_ICPolarity = TIM_ICPolarity_Rising;
	TIM_ICInitStruct.TIM_ICSelection = TIM_ICSelection_DirectTI;
	TIM_ICInitStruct.TIM_ICFilter = 0;
	TIM_ICInit(TIM2, &TIM_ICInitStruct);

	TIM_ClearFlag(TIM2, TIM_FLAG_Update);//���TIM�ĸ��±�־λ

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
