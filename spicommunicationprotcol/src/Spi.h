/*
 * Uart.h
 *
 * Created: 2/10/2020 12:27:50 PM
 *  Author: hazem
 */ 


#ifndef SPI_H_
#define SPI_H_

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
	SPI_DOUBLE_SPEED_MODE_OFF,
	SPI_DOUBLE_SPEED_MODE_ON
}EN_SPI_DOUBLE_SPEED;

typedef enum SPI_OPERATING_LEVEL
{
	SPI_IDLE_LOW,
	SPI_IDLE_HIGH
}EN_SPI_OPERATING_LEVEL;

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





#endif /* UART_H_ */