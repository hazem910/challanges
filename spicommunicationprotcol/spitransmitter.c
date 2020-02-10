/*
 * main.c
 *
 * Created: 2/10/2020 11:31:55 PM
 *  Author: hazem
 */ 

#include "Spi.h"
#include "softwareDelay.h"
int main (void)
{
	ST_S_SPI_Configuration spistr1={
		 spistr1.SLAVE_MODE=SPI_MASTER,
		 spistr1.INT_ENABLE=SPI_INT_OFF,
		 spistr1.PRESCALAR=SPI_Fosc16,
		 spistr1.DOUBLE_SPEED=SPI_DOUBLE_SPEED_MODE_OFF,
		 spistr1.ENABLE=SPI_ENABLE_ON,
		 spistr1.SAMPLING_EDGE=SPI_RISING,
		 spistr1.DATA_ORDER=SPI_LSB_FISRT,
		 spistr1.clock_phase=leading_EDGE
		 };
	SPI_Init(&spistr1);


	softwareDelayMs(2000);
	while(1){
		
			SPI_Transceiver(20);
			softwareDelayMs(1000);
		
			
		
	
	
		
		
	}
	

}
