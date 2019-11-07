#ifndef __TYPEDEFS_H
#define __TYPEDEFS_H

#include <stdbool.h>
#include <stdint.h>

/* PID参数 */
typedef struct
{
	float Target; 			        //设定目标值
	float Measured; 			    //测量值
	float err; 						//本次偏差值
	float err_last; 			    //上一次偏差
	float err_beforeLast; 			//上上次偏差
	float Kp, Ki, Kd;				//Kp, Ki, Kd控制系数
	float pwm; 						//pwm输出
	uint32_t MaxOutput;				//输出限幅
	uint32_t IntegralLimit;			//积分限幅 
}incrementalpid_t;                  //增量式

typedef struct
{
	float Target; 					    //设定目标值
	float Measured; 				    //测量值
	float err; 						    //本次偏差值
	float err_last; 				    //上一次偏差
	float integral_err; 			    //所有偏差之和
	float Kp, Ki, Kd;				    //Kp, Ki, Kd控制系数
	float pwm; 						    //pwm输出
	uint32_t MaxOutput;				    //输出限幅
	uint32_t IntegralLimit;			    //积分限幅 
}positionpid_t;							//位置式

#endif /* __TYPEDEFS_H */
