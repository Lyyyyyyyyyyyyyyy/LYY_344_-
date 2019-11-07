#ifndef __TYPEDEFS_H
#define __TYPEDEFS_H

#include <stdbool.h>
#include <stdint.h>

/* PID���� */
typedef struct
{
	float Target; 			        //�趨Ŀ��ֵ
	float Measured; 			    //����ֵ
	float err; 						//����ƫ��ֵ
	float err_last; 			    //��һ��ƫ��
	float err_beforeLast; 			//���ϴ�ƫ��
	float Kp, Ki, Kd;				//Kp, Ki, Kd����ϵ��
	float pwm; 						//pwm���
	uint32_t MaxOutput;				//����޷�
	uint32_t IntegralLimit;			//�����޷� 
}incrementalpid_t;                  //����ʽ

typedef struct
{
	float Target; 					    //�趨Ŀ��ֵ
	float Measured; 				    //����ֵ
	float err; 						    //����ƫ��ֵ
	float err_last; 				    //��һ��ƫ��
	float integral_err; 			    //����ƫ��֮��
	float Kp, Ki, Kd;				    //Kp, Ki, Kd����ϵ��
	float pwm; 						    //pwm���
	uint32_t MaxOutput;				    //����޷�
	uint32_t IntegralLimit;			    //�����޷� 
}positionpid_t;							//λ��ʽ

#endif /* __TYPEDEFS_H */
