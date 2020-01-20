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

/*implementation of GPIO TOGGEL */
void gpioPortToggle(uint8_t u8_port){
	
		switch(u8_port){
			case GPIOA:
			          PORTA_DATA^=HIGH;
			          break;
			case GPIOB:
			           PORTB_DATA^=HIGH;
			           break;
			case GPIOC:
			           PORTC_DATA^=HIGH;
			           break;
			case GPIOD:
			          PORTD_DATA^=HIGH;
			          break;
			default:
			break;
		}	
}
 
/*implementation of GPIO port read */
uint8_t gpioPortRead(uint8_t u8_port){
		switch(u8_port){
			case GPIOA:
			           return PORTA_PIN;
			           break;
			case GPIOB:
			          return PORTB_PIN;
			          break;
			case GPIOC:
			          return PORTC_PIN;
			          break;
			case GPIOD:
			          return PORTD_PIN;
			          break;
			default:
			  break;
		}	
		return u8_port;
}
/*implementation of GPIO port PIN DIRECTION */
void gpioPinDirection(uint8_t u8_port, uint8_t u8_pins, uint8_t u8_direction){
	switch (u8_direction){
	  case OUTPUT:
	  switch(u8_port){
		case GPIOA:
		          PORTA_DIR|=(u8_pins);
		          break;
		case GPIOB:
		           PORTB_DIR|=(u8_pins);
		           break;
		case GPIOC:
		           PORTC_DIR|=(u8_pins);
		           break;
		case GPIOD:
	               PORTD_DIR|=(u8_pins);
	               break;
		default:
		        break;
	   }
	   break;
	case  INPUT:
	          switch(u8_port){
		          case GPIOA:
		                    PORTA_DIR&=~(u8_pins);
		                    break;
		          case GPIOB:
		                     PORTB_DIR&=~(u8_pins);
		                     break;
		          case GPIOC:
		                     PORTC_DIR&=~(u8_pins);
		                     break;
		          case GPIOD:
		                     PORTD_DIR&=~(u8_pins);
		                     break;
		          default:
		                  break;
	          }
	         break;
	
	default:
	      break;}
	
}
/*implementation of GPIO port PIN DIRECTION */
void gpioPinWrite(uint8_t u8_port, uint8_t u8_pins, uint8_t u8_value){
	switch (u8_value){
		case HIGH:
		switch(u8_port){
			case GPIOA:
			           PORTA_DATA=(u8_pins);
			           break;
			case GPIOB:
			          PORTB_DATA=(u8_pins);
			          break;
			case GPIOC:
			         PORTC_DATA=(u8_pins);
			         break;
			case GPIOD:
			        PORTD_DATA=(u8_pins);
			        break;
			default:
			break;
		}
		break;
		case  LOW:
		switch(u8_port){
			case GPIOA:
			          PORTA_DATA&=~(u8_pins);
			          break;
			case GPIOB:
			          PORTB_DATA&=~(u8_pins);
			          break;
			case GPIOC:
			          PORTC_DATA &=~(u8_pins);
			          break;
			case GPIOD:
			          PORTD_DATA &=~(u8_pins);
			          break;
			default:
			break;
		}
		break;
		
		
			  }	
	
}
/*IMPLEMENTATION OF  gpioPinToggle */
void gpioPinToggle(uint8_t u8_port, uint8_t u8_pins){
	
switch(u8_port){
	case GPIOA:
	          PORTA_DATA^=(u8_pins);
	          break;
	case GPIOB:
	          PORTB_DATA^=(u8_pins);
	          break;
	case GPIOC:
	          PORTC_DATA^=(u8_pins);
	          break;
	case GPIOD:
	          PORTD_DATA^=(u8_pins);
	          break;
	default:
	       break;
}	
	
}


uint8_t gpioPinRead(uint8_t u8_port, uint8_t u8_pin){
	uint8_t data=0;
	switch(u8_port){
		case GPIOA:
		          
				  data= (PORTA_PIN & u8_pin);
				  break;
		         
		case GPIOB:
		           
		           data=(PORTB_PIN & u8_pin);
		           break;
		case GPIOC:
		          
		           data= (PORTC_PIN & u8_pin);
		           break;
		case GPIOD:
		          data= (PORTD_PIN & u8_pin);
		          break;
		default:
		        break;
	}
	if(data){
		
		data=1;
	}
	else{
		data=LOW;
	}
	return data;
}
 

