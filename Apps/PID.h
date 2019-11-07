#ifndef __PID_H
#define __PID_H

#include "user_common.h"

void PWM_Limit(int motor);

int Incremental_PI_LEFT(int Encoder, int Target);
int Incremental_PI_RIGHT(int Encoder, int Target);

int Position_PID_LEFT(int Encoder, int Target);
int Position_PID_RIGHT(int Encoder, int Target);

#endif   /* __PID_H */
