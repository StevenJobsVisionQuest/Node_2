/*
 * PWM.h
 *
 * Created: 25.10.2017 10:07:21
 *  Author: Administrator
 */ 

#include <avr/io.h>
#ifndef PWM_H_
#define PWM_H_

#define PWM_min 14
#define PWM_mid	22
#define PWM_max 30

#include "../CAN/CAN.h"
#include "../DEFINITIONS.h"

void PWM_init(void);

float PWM_get_duty_cycle(can_message_t msg);

void PWM_set_duty_cycle(float val);


#endif /* PWM_H_ */