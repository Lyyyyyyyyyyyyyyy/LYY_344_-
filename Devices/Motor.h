#ifndef __MOTOR_H
#define __MOTOR_H

#include "user_common.h"

extern int Motor_Left;
extern int Motor_Right;

extern incrementalpid_t pid_left;
extern incrementalpid_t pid_right;
extern positionpid_t PID_LEFT;
extern positionpid_t PID_RIGHT;

void Motor_Tim_Config(u16 arr, u16 psc);

#endif  /*__MOTOR_H*/
