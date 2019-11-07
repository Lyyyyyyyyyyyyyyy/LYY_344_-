/*
 *******************************************************************************
 * @file    PID.c
 * @author  Luu-yy
 * @version
 * @date
 * @brief   PID¹¦ÄÜº¯Êý
 ******************************************************************************
 */

#include "PID.h"


void PWM_Limit(int motor)
{
	int Amplitude = 7200;
	if (motor > Amplitude)
		motor = Amplitude;
	if (motor < -Amplitude)
		motor = -Amplitude;
}


int Incremental_PI_LEFT(int Encoder, int Target)
{
	pid_left.Kp = 150;
	pid_left.Ki = 40;

	pid_left.err = Encoder - Target;
	pid_left.pwm += pid_left.Kp*(pid_left.err - pid_left.err_last) + pid_left.Ki*pid_left.err;

	if (pid_left.pwm>7200)
		pid_left.pwm = 7200;
	else if (pid_left.pwm<-7200)
		pid_left.pwm = -7200;

	pid_left.err_last = pid_left.err;

	return pid_left.pwm;
}


int Incremental_PI_RIGHT(int Encoder, int Target)
{
	pid_right.Kp = 150;
	pid_right.Ki = 40;

	pid_right.err = Encoder - Target;
	pid_right.pwm += pid_right.Kp*(pid_right.err - pid_right.err_last) + pid_right.Ki*pid_right.err;

	if (pid_right.pwm>7200)
		pid_right.pwm = 7200;
	else if (pid_right.pwm<-7200)
		pid_right.pwm = -7200;

	pid_right.err_last = pid_right.err;

	return pid_right.pwm;
}


int Position_PID_LEFT(int Encoder, int Target)
{
	PID_LEFT.Kp = 40;
	PID_LEFT.Ki = 5;
	PID_LEFT.Kd = 0;

	PID_LEFT.err = Encoder - Target;
	PID_LEFT.integral_err += PID_LEFT.err;

	PID_LEFT.pwm += PID_LEFT.Kp*PID_LEFT.err + PID_LEFT.Ki + PID_LEFT.integral_err + PID_LEFT.Kd*(PID_LEFT.err - PID_LEFT.err_last);

	if (PID_LEFT.pwm>7200)
		PID_LEFT.pwm = 7200;
	else if (PID_LEFT.pwm<-7200)
		PID_LEFT.pwm = -7200;

	PID_LEFT.err_last = PID_LEFT.err;

	return PID_LEFT.pwm;
}


int Position_PID_RIGHT(int Encoder, int Target)
{
	//if (Target<0){Target = -Target;	}			else {Target = Target;	}

	PID_RIGHT.Kp = 40;
	PID_RIGHT.Ki = 5;
	PID_RIGHT.Kd = 0;

	PID_RIGHT.err = Encoder - Target;
	PID_RIGHT.integral_err += PID_RIGHT.err;

	PID_RIGHT.pwm += PID_RIGHT.Kp*PID_RIGHT.err + PID_RIGHT.Ki + PID_RIGHT.integral_err + PID_RIGHT.Kd*(PID_RIGHT.err - PID_RIGHT.err_last);

	if (PID_RIGHT.pwm>7200)
		PID_RIGHT.pwm = 7200;
	else if (PID_RIGHT.pwm<-7200)
		PID_RIGHT.pwm = -7200;

	PID_RIGHT.err_last = PID_RIGHT.err;

	return PID_RIGHT.pwm;
}

