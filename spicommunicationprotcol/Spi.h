/*
 * Uart.h
 *
 * Created: 2/10/2020 12:27:50 PM
 *  Author: hazem
 */ 


#ifndef SPI_H_
#define SPI_H_
#include "Spiconfig.h"

void SPI_Init(ST_S_SPI_Configuration *spi_Config);
uint8_t  SPI_Transceiver(uint8_t Copy_u8Data);





#endif /* UART_H_ */