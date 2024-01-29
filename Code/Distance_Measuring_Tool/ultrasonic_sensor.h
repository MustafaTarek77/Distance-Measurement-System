/*
 * ultrasonic_sensor.h
 *
 *  Created on: Oct 12, 2022
 *      Author: mustafa
 */

#ifndef ULTRASONIC_SENSOR_H_
#define ULTRASONIC_SENSOR_H_

#include "std_types.h"
#include "gpio.h"


#define US_TRIG_PORT_ID                 PORTB_ID
#define US_TRIG_PIN_ID                  PIN5_ID

#define US_ECHO_PORT_ID                 PORTD_ID
#define US_ECHO_PIN_ID                  PIN6_ID



void Ultrasonic_init(void);

void Ultrasonic_Trigger(void);

uint16 Ultrasonic_readDistance(void);

#endif /* ULTRASONIC_SENSOR_H_ */
