#include "control.h"

int Target_Left = 0;
int Target_Right = 0;

uint8_t KEY_FLAG = 0;

float Wheel_Left_Speed = 0;

double Encoder = 0;
double Position_Left = 0.0;

#define Car_Wheel_diameter    65
#define PI                    3.14
#define CAR_Quadruple_Pulse   1560

void JTAG_Set(u8 mode)
{
	u32 temp;
	temp = mode;
	temp <<= 25;
	RCC->APB2ENR |= 1 << 0;
	AFIO->MAPR &= 0XF8FFFFFF;
	AFIO->MAPR |= temp;
}

void Set_Pwm(int motor_left, int motor_right)
{
	if (motor_left > 0)
		PWM_LEFT_A = 7200, PWM_LEFT_B = 7200 - motor_left;
	else
		PWM_LEFT_B = 7200, PWM_LEFT_A = 7200 + motor_left;

	if (motor_right > 0)
		PWM_RIGHT_A = 7200, PWM_RIGHT_B = 7200 - motor_right;
	else
		PWM_RIGHT_B = 7200, PWM_RIGHT_A = 7200 + motor_right;
}

void Trolley_Movement(void)
{
	Target_Left = 50;
	Target_Right = 50;

	Encoder += (float)Encoder_Left;       
	//ÿ10ms��ȡ����������ֵ�����ۼ�
	Wheel_Left_Speed = (float)Encoder_Left * 100 / 7643;
	//ÿ�������� = һȦ����ֵ /��PI*�뾶��
	//1560 /��0.065 * 3.14��Լ=7643    ����/�룩�Ŵ�100��10ms
	Position_Left = Encoder * 0.001 * 0.127;
	//ʵ��λ�� = �������ۼ�ֵ *��PI * �뾶 * ���������/������������/���ٱ�30/һȦ������ֵ��
	//ת����λ

	OLED_ShowString(0, 00, "Car_Speed:");
	OLED_Showdecimal(0, 10, Wheel_Left_Speed, 8, 12);
	OLED_Refresh_Gram();

	OLED_ShowString(0, 20, "Car_Position:");
	OLED_Showdecimal(0, 30, Wheel_Left_Speed, 8, 12);
	OLED_Refresh_Gram();

	if (Position_Left - 2.00 >= 0)
	{
		Target_Left = 0;
		Target_Right = 0;
		KEY_FLAG = 0;

		OLED_Clear();
		OLED_ShowString(0, 00, "Car_Stop!!!");
		OLED_ShowString(0, 10, "Car_Speed:");
		OLED_Showdecimal(0, 20, Wheel_Left_Speed, 8, 12);

		OLED_ShowString(0, 30, "Car position:");
		OLED_Showdecimal(0, 40, Position_Left, 8, 12);

		OLED_Refresh_Gram();
	}
}




