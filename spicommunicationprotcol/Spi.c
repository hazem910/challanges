/*
 * Spi.c
 *
 * Created: 2/10/2020 1:09:50 PM
 *  Author: hazem
 */ 


#include "Spi.h"

/******************************************************************
****************** spi initialization******************************
params:pointer to config struct 
return :void 
*******************************************************************/


void SPI_Init(ST_S_SPI_Configuration *spi_Config){
	
	/********************Enable SPI Interrupt ******************/
	
	SPCR|=SPI_ENABLE_ON;
	
	/*******************Data Order******************/
	if (spi_Config->DATA_ORDER == SPI_LSB_FISRT)
	SPCR|=SPI_LSB_FISRT;
	else if (spi_Config->DATA_ORDER == SPI_MSB_FISRT)
	SPCR|=SPI_MSB_FISRT;
	/********************Master Slave Select ******************/
	if (spi_Config->SLAVE_MODE == SPI_MASTER)
	{SPCR|=SPI_MASTER;
	/********************SPI pre-scalar in case of master ******************/
		switch(spi_Config->PRESCALAR){
			case SPI_Fosc4:
			              SPCR|=SPI_Fosc4;
				          break;
			case  SPI_Fosc16:
			                SPCR|=SPI_Fosc16;
							break;
			case SPI_Fosc64:
			                SPCR|=SPI_Fosc64;
							break;
			case SPI_Fosc128:
			                SPCR|=SPI_Fosc128;
			                break;
			default:
			       break;				
							 								   	   
		}
		/********************Double SPI speed if master******************/

		if (spi_Config->DOUBLE_SPEED == SPI_DOUBLE_SPEED_MODE_ON)
		SPSR|=SPI_DOUBLE_SPEED_MODE_ON;
		else if (spi_Config->DOUBLE_SPEED == SPI_DOUBLE_SPEED_MODE_OFF)
		SPSR|=SPI_DOUBLE_SPEED_MODE_OFF;
		/*********************MASTER_Port****************************/
		gpioPinDirection(MISO_PORT,MISO_PIN,INPUT);
		gpioPinDirection(MOSI_PORT,MOSI_PIN,OUTPUT);
		gpioPinDirection(SCK_PORT,SCK_PIN,OUTPUT);
		gpioPinDirection(SS_PORT,SS_PIN,OUTPUT);
		
	}
	else if (spi_Config->SLAVE_MODE == SPI_SLAVE){
	SPCR|=SPI_SLAVE;
	/*********************Slave_Port****************************/

	gpioPinDirection(MISO_PORT,MISO_PIN,OUTPUT);
	gpioPinDirection(MOSI_PORT,MOSI_PIN,INPUT);
	gpioPinDirection(SCK_PORT,SCK_PIN,INPUT);
	gpioPinDirection(SS_PORT,SS_PIN,INPUT);
	
	}

	

	/********************clock ploarity******************/
	if (spi_Config->SAMPLING_EDGE == SPI_RISING)
	 SPCR|=SPI_RISING;
	else if (spi_Config->SAMPLING_EDGE == SPI_FALLING)
	 SPCR|=SPI_FALLING;

	
	

	/********************Enable SPI ******************/
	if (spi_Config->ENABLE == SPI_ENABLE_ON)
	SPCR|=SPI_ENABLE_ON;
	else if (spi_Config->ENABLE == SPI_ENABLE_OFF)
	SPCR|=SPI_ENABLE_OFF;
	/*********************Clock_Phase******************/
	if(spi_Config->clock_phase==leading_EDGE)
	SPCR|=leading_EDGE;
	else if(spi_Config->clock_phase==trailing_EDGE)
	SPCR|=trailing_EDGE;
	
}





/******************************************************************
****************** spi Transceiver******************************
params: data wants to transfer
return :data  Received
*******************************************************************/


uint8_t  SPI_Transceiver(uint8_t Copy_u8Data){
	gpioPinWrite(SS_PORT,SS_PIN,HIGH);
	SPDR = Copy_u8Data; //send data
	while(!(SPSR & (1<<SPIF)));
	SPSR|=(1<<SPIF);
	return SPDR ; // Received data
}



