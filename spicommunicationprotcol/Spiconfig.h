/*
 * UartConfig.h
 *
 * Created: 2/10/2020 11:13:42 AM
 *  Author: hazem ebrahim 
 */ 


#ifndef UARTCONFIG_H_
#define UARTCONFIG_H_

#include "registers.h"
#include "std_types.h"
#include "gpio.h"
#define  MISO_PORT (GPIOB)
#define  MOSI_PORT (GPIOB)
#define  SCK_PORT  (GPIOB)
#define  SS_PORT   (GPIOB)

#define  MISO_PIN (BIT6)
#define  MOSI_PIN (BIT5)
#define  SCK_PIN  (BIT7)
#define  SS_PIN   (BIT4)


typedef enum SPI_SLAVE_MODE
{
	SPI_MASTER =(1<<MSTR),
	SPI_SLAVE =0
}EN_SPI_SLAVE_MODE;

typedef enum SPI_PRESCALAR
{
	SPI_Fosc4 = 0,
	SPI_Fosc16 = (1<<SPR0),
	SPI_Fosc64 = (1<<SPR1),
	SPI_Fosc128 = (1<<SPR0)|(1<<SPR1)
}EN_SPI_PRESCALAR;

typedef enum SPI_ENABLE
{
	SPI_ENABLE_ON =(1<<SPE),
	SPI_ENABLE_OFF = 0
}EN_SPI_ENABLE;

typedef enum SPI_DOUBLE_SPEED
{
	SPI_DOUBLE_SPEED_MODE_OFF=0,
	SPI_DOUBLE_SPEED_MODE_ON=(1<<SPI2X)
}EN_SPI_DOUBLE_SPEED;



typedef enum SPI_SAMPLING_EDGE
{
	SPI_RISING =0,
	SPI_FALLING =(1<<CPOL)
}EN_SPI_SAMPLING_EDGE;


typedef enum SPI_INT_ENABLE
{
	SPI_INT_OFF=0,
	SPI_INT_ON=(1<<SPIE)
}EN_SPI_INT_ENABLE;


typedef enum SPI_DATA_ORDER
{
	SPI_LSB_FISRT = (1<<DORD),
	SPI_MSB_FISRT = 0
}EN_SPI_DATA_ORDER;
typedef enum Clock_Phase_MODE
{
	leading_EDGE=0,
	trailing_EDGE=(1<<CPHA)
	
}EN_Clock_Phase_MODE;

typedef struct S_SPI_Configuration
{
	 EN_SPI_SLAVE_MODE SLAVE_MODE ;
	 EN_SPI_PRESCALAR  PRESCALAR ;
	 EN_SPI_ENABLE  ENABLE;
	 EN_SPI_DOUBLE_SPEED  DOUBLE_SPEED;
	 EN_SPI_SAMPLING_EDGE   SAMPLING_EDGE;
	 EN_SPI_INT_ENABLE    INT_ENABLE;
	 EN_SPI_DATA_ORDER  DATA_ORDER ;
	 EN_Clock_Phase_MODE clock_phase;
}ST_S_SPI_Configuration;




#endif /* UARTCONFIG_H_ */