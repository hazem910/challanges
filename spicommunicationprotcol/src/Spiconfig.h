/*
 * UartConfig.h
 *
 * Created: 2/10/2020 11:13:42 AM
 *  Author: hazem ebrahim 
 */ 


#ifndef UARTCONFIG_H_
#define UARTCONFIG_H_

#include "Spi.h"

typedef struct S_SPI_Configuration
{
	 EN_SPI_SLAVE_MODE SLAVE_MODE ;
	 EN_SPI_PRESCALAR  PRESCALAR ;
	 EN_SPI_ENABLE  ENABLE;
	 EN_SPI_DOUBLE_SPEED  DOUBLE_SPEED;
     EN_SPI_OPERATING_LEVEL  OPERATING_LEVEL;
	 EN_SPI_SAMPLING_EDGE   SAMPLING_EDGE;
	 EN_SPI_INT_ENABLE    INT_ENABLE;
	 EN_SPI_DATA_ORDER  DATA_ORDER ;
	 EN_Clock_Phase_MODE clock_phase;
}ST_S_SPI_Configuration;




#endif /* UARTCONFIG_H_ */