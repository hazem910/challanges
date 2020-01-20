
#include "sevenSeg.h"
#include "softwareDelay.h"
#include "gpio.h"
#define max_occurs 99
#define sec_passed 50
int main (void)
{
	uint16_t counter=0;
	uint16_t outer_counter=0;
	sevenSegInit(SEG_0);
	sevenSegInit(SEG_1);

	while (1)
	{
		sevenSegEnable(SEG_0);
		sevenSegDisable(SEG_1);
		sevenSegWrite(SEG_0,counter%10);
		softwareDelayMs(10);
		sevenSegDisable(SEG_0);
		sevenSegEnable(SEG_1);
		sevenSegWrite(SEG_1,counter/10);
		softwareDelayMs(10);
	outer_counter++;
	if(outer_counter==sec_passed){
		outer_counter=0;
		counter++;
		if(counter>max_occurs){
			counter=0;
		}

	}
	}

}
