/*
 * GPIO.c
 *
 * Created: 1/17/2020 3:14:49 PM
 *  Author: hazem
 */ 

#include "gpio.h"
/*GPIO direction implementation*/

void gpioPortDirection(uint8_t u8_port, uint8_t u8_direction){
switch(u8_port){
case GPIOA:
      PORTA_DIR=u8_direction; 
     	break;
case GPIOB:
      PORTB_DIR=u8_direction;
      break;
case GPIOC:
      PORTC_DIR=u8_direction;
      break;	  		 
case GPIOD:
      PORTD_DIR=u8_direction;
      break;	
default:
      break;
}

}
/*implementation of gpio port write */
void gpioPortWrite(uint8_t u8_port, uint8_t u8_value){
	switch(u8_port){
		case GPIOA:
		PORTA_DATA=u8_value;
		break;
		case GPIOB:
		PORTB_DATA=u8_value;
		break;
		case GPIOC:
		PORTC_DATA=u8_value;
		break;
		case GPIOD:
		PORTD_DATA=u8_value;
		break;
		default:
		break;
	}
	
	
	
	
	
	
}


 

