/*
 * ultrasonic_sensor.c
 *
 *  Created on: Oct 12, 2022
 *      Author: mustafa
 */

#include <util/delay.h>
#include "ultrasonic_sensor.h"
#include "icu.h"

extern void Ultrasonic_edgeProcessing();
uint16 Edge_Count=0;
uint16 Time=0;


/*Description
➢ Initialize the ICU driver as required.
➢ Setup the ICU call back function.
➢ Setup the direction for the trigger pin as output pin through the
GPIO driver*/
void Ultrasonic_init(void)
{
	Icu_ConfigType Config_Ptr;
	Config_Ptr.clock=F_CPU_8;
	Config_Ptr.edge=RAISING;
	Icu_init(&Config_Ptr);
	Icu_setCallBack(Ultrasonic_edgeProcessing);
	GPIO_setupPinDirection(US_TRIG_PORT_ID, US_TRIG_PIN_ID, PIN_OUTPUT);
	GPIO_writePin(US_TRIG_PORT_ID, US_TRIG_PIN_ID, LOGIC_LOW);
}



/*Description
➢ Send the Trigger pulse to the ultrasonic.*/

void Ultrasonic_Trigger(void)
{
	GPIO_writePin(US_TRIG_PORT_ID, US_TRIG_PIN_ID, LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(US_TRIG_PORT_ID, US_TRIG_PIN_ID, LOGIC_LOW);
}


/*Description
➢ Send the trigger pulse by using Ultrasonic_Trigger function.
➢ Start the measurements by the ICU from this moment.*/

uint16 Ultrasonic_readDistance(void)
{
	Ultrasonic_Trigger();

	while(Edge_Count!=0) {}

	uint16 distance=Time/57.9;

	if(distance<110)
		distance++;
	else if(distance<130)
		distance=Time/57.8;


	return distance;
}

