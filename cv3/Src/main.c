/**
  ******************************************************************************
  * @file    main.c
  * @author  Auto-generated by STM32CubeIDE
  * @version V1.0
  * @brief   Default main function.
  ******************************************************************************
*/

#include "stm32f0xx.h"
#include "sct.h"



int main(void)
{
	sct_init();
	sct_led(0x7A5C36DE);
	for (volatile uint32_t i = 0; i < 1000000; i++);
	for(int i=111; i<=999; i+=111) {
		sct_value(i);
		for (volatile uint32_t i = 0; i < 1000000; i++);
	}


	while(1) {

	}

}
