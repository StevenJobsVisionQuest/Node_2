/*
* PID.c
*
* Created: 08.11.2017 14:55:41
*  Author: karlmt
*/
#include "PID.h"

#include <stdlib.h>
static int16_t rot_max = 0;
static int16_t rot_min = 0;

//double motor_mid = 0;
double Kp = 1;
double Ki = 1;
double Kd = 0.1;

double integral = 0;
int16_t error = 0;
double dt = 0.016;
int16_t prev_error = 0;

//static uint8_t right_ref = 255;
//static uint8_t left_ref = 0;
//static uint8_t mid_ref = 127;
//static uint8_t scaling_factor = 1;


ISR(TIMER2_OVF_vect) {
	
	
	//can_message_t *msg;
	//CAN_recieve_data(msg);
	//
	//uint8_t ref = msg->data[0];
	//uint8_t measured = PID_scale(MOTOR_read());
	//
	//error = ref - measured;
	//
	//integral += error*dt;
	//double derivative = -(error - prev_error)/dt;
	//prev_error = error;
	//double gain =  Kp * error + Ki * integral + Kd * derivative;
	//
	//uint8_t dir;
	//
	//if (error > 0) {
		//dir = RIGHT;
	//}
	//else {
		//dir = LEFT;
	//}
	//
	//MOTOR_write(abs(gain),dir);
	

	
}


void PID_init(void){
	
	MOTOR_write(127,LEFT);
	_delay_ms(500);
	MOTOR_write(0,LEFT);
	rot_max = MOTOR_read();
	_delay_ms(2000);
	
	
	MOTOR_write(127,RIGHT);
	_delay_ms(500);
	MOTOR_write(0,RIGHT);
	rot_min = MOTOR_read();
	printf("MOTOR_read() = %d\n", MOTOR_read());
	_delay_ms(2000);
	
	
	MOTOR_write(127,LEFT);
	_delay_ms(70);
	MOTOR_write(0,LEFT);
	
/*
	printf("rot_min = %d\n", rot_min);
	printf("rot_max = %d\n", rot_max);
	
	printf("MOTOR_read() = %d\n", MOTOR_read());
	printf("(rot_max+rot_min)/2 = %d\n", (rot_max+rot_min)/2);*/

	while(MOTOR_read() < (rot_max+rot_min)/2) {
		printf("(rot_max+rot_min)/2 = %d\n", (rot_max+rot_min)/2);
		printf("MOTOR_read() = %d\n\n\n", MOTOR_read());
		MOTOR_write(127,LEFT);
	}
	MOTOR_write(0,LEFT);
	
	//uint8_t motor_mid = abs((rot_max+rot_min)/2);
	
/*
	DAC_init();
	
	
	
	
	
	motor_mid = abs((rot_max+rot_min)/2);
	
	while(MOTOR_read() > motor_mid) {
		MOTOR_write(70,LEFT);
	}
	
	//MOTOR_write(0,right);*/
	
	cli();
	
	TIMSK2=(1<<TOIE2);
	
	
	// start timer2 with /1024 prescaler --> dt = 0.016
	TCCR2B = (1<<CS20) | (1<<CS21) | (1<<CS22);
	
	sei();
	
}


uint8_t PID_scale(int8_t motor_rot) {
	return (uint8_t)((motor_rot-rot_min)/(rot_max-rot_min))*255;
}



