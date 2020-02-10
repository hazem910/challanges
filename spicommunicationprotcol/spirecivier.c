
#include "Spi.h"
#include "softwareDelay.h"
#include "sevenSeg.h"
int main (void)
{
	ST_S_SPI_Configuration spistr1={
		 spistr1.SLAVE_MODE=SPI_SLAVE,
		 spistr1.INT_ENABLE=SPI_INT_OFF,
		 spistr1.PRESCALAR=SPI_Fosc16,
		 spistr1.DOUBLE_SPEED=SPI_DOUBLE_SPEED_MODE_OFF,
		 spistr1.ENABLE=SPI_ENABLE_ON,
		 spistr1.SAMPLING_EDGE=SPI_RISING,
		 spistr1.DATA_ORDER=SPI_LSB_FISRT,
		 spistr1.clock_phase=leading_EDGE
		 };
	SPI_Init(&spistr1);
	sevenSegInit(SEG_0);
	sevenSegInit(SEG_1);

uint8_t data=0;
	//softwareDelayMs(2000);
	while(1){
	/*	
			SPI_Transceiver(20);
			softwareDelayMs(1000);
		*/
			
		
		
	if(SPI_Transceiver(25)==20){
	sevenSegWrite(SEG_0,data);
	sevenSegEnable(SEG_0);
	sevenSegDisable(SEG_1);
	data++;
	softwareDelayMs(1000);
	
	if(data==9){
		data=0;
	}
	}	
	else{
			sevenSegWrite(SEG_1,data);
			sevenSegEnable(SEG_1);
			sevenSegDisable(SEG_0);
			data++;
			softwareDelayMs(1000);
			
			if(data==9){
				data=0;
			}
	}
	
		
		
	}
	

}
