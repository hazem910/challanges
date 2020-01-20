/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include "led.h"
#include "softwareDelay.h"

int main (void)
{
	
	Led_Init(LED_0);
	Led_Init(LED_1);
	Led_Init(LED_2);
	while (1)
	{
		Led_On(LED_0);
		Led_Off(LED_1);
		Led_Off(LED_2);
		softwareDelayMs(1000);
		Led_On(LED_1);
		Led_Off(LED_0);
		Led_Off(LED_2);
		softwareDelayMs(1000);
		Led_On(LED_2);
		Led_Off(LED_1);
		Led_Off(LED_0);
		softwareDelayMs(1000);
		
	}
	
}
