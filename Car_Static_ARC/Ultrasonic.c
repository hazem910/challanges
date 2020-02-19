/*
 * DIO_TEST.c
 *
 * Created: 2/17/2020 4:14:39 PM
 *  Author: Hazem
 */ 

#include "car_sm.h"
int main(void)
{ 
Car_SM_Init();

	while(1)
  {
	Car_SM_Update();
   softwareDelayMs(100);
}

}