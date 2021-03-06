/*
 * MOTOR.h
 *
 * Created: 08.11.2017 10:38:37
 *  Author: karlmt
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

#define EN PH4
#define DIR PH1
#define _RST PH6
#define SEL PH3
#define _OE PH5

#include <avr/interrupt.h>
#include <avr/sleep.h>

#include <util/delay.h>

#include <avr/io.h>
#include "../CAN/CAN.h"
#include "../TWI/TWI_Master.h"
#include "../DEFINITIONS.h"
//Set EN on MJ1
//Set DIR on MJ1
//PROVIDE Analog value on DA1 on MJEX from 0V-5V
//!RST on MJ1 set High

//reading the encoder
//!OE onMJ1 to LOW
//SEL on MJ1 to low to get high byte
//Wait about 20 microsecs
//Read MSB


#define	LEFT	0
#define	RIGHT	1



void MOTOR_init(void);


uint16_t MOTOR_read(void);
void MOTOR_encoder_reset(void);
void MOTOR_write(uint8_t speed, uint8_t direction);
void MOTOR_position_control(int16_t target_pos);
uint8_t MOTOR_scale_to_8bit(int16_t encoder_val);


#endif /* MOTOR_H_ */