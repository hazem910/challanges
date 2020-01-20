
#include "pushButton.h"
#include "led.h"


int main (void)
{
	uint16_t counter_flag=1;
	uint16_t check_ittirate=0;
	pushButtonInit(BTN_0);
	Led_Init(LED_3);
	while (1)
	{
		if(pushButtonGetStatus(BTN_0)==Pressed){
			
		Led_On(LED_3);
		while(counter_flag>0){
	for(check_ittirate=0;check_ittirate<10;check_ittirate++){
if(pushButtonGetStatus(BTN_0)==Pressed){
counter_flag++;
}
softwareDelayMs(10);	
	}
counter_flag--;
}
		}
		counter_flag=1;
		Led_Off(LED_3);
	}
}
		