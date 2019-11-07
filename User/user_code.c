#include "user_code.h"

void Init(void)
{
	JTAG_Set(SWD_ENABLE);
	KEY_GPIO_Config();
	Encoder1_TIM_Mode_Config();
	Encoder2_TIM_Mode_Config();
	Motor_Tim_Config(7199, 0);
	USART1_QuickInit(115200);
	OLED_Init();
	TIM6_CounterMode(99, 7199);

	OLED_ShowString(0, 00, "In preparation,Press User Key");
	OLED_Refresh_Gram();
}
