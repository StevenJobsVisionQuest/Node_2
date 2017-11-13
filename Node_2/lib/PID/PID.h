/*
 * PID.h
 *
 * Created: 08.11.2017 14:55:59
 *  Author: karlmt
 */ 



#ifndef PID_H_
#define PID_H_

#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "../DAC/DAC.h"
#include "../MOTOR/MOTOR.h"
#include "../ADC/ADC.h"

#define F_CPU 16000000

void PID_init(void);
uint8_t PID_scale(int8_t encoder_val);
int8_t PID_control(can_message_t msg);

/*
uint8_t PID_get_rot_min(void)
uint8_t PID_get_rot_max(void)*/


#endif /* PID_H_ */