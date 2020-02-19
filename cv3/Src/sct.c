/*
 * sct.c
 *
 *  Created on: 19. 2. 2020
 *      Author: student
 */

#include "sct.h"
#include "stm32f0xx.h"

#define sct_nla(x) do { if (x) GPIOB->BSRR = (1 << 5); else GPIOB->BRR = (1 << 5); } while (0)
#define sct_sdi(x) do { if (x) GPIOB->BSRR = (1 << 4); else GPIOB->BRR = (1 << 4); } while (0)
#define sct_clk(x) do { if (x) GPIOB->BSRR = (1 << 3); else GPIOB->BRR = (1 << 3); } while (0)
#define sct_noe(x) do { if (x) GPIOB->BSRR = (1 << 10); else GPIOB->BRR = (1 << 10); } while (0)


void sct_led(uint32_t value)
{
	while(value) {

		if (value & 1)
			sct_sdi(1); // set
		else
			sct_sdi(0);
//		for (volatile uint32_t i = 0; i < 10000; i++);
		sct_clk(1);
//		for (volatile uint32_t i = 0; i < 10000; i++);
		sct_clk(0);
//		for (volatile uint32_t i = 0; i < 10000; i++);
		value >>= 1;
	}
	sct_nla(1);
	sct_nla(0);
}

void sct_init(void)
{
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN; // enable
	GPIOB -> MODER |= GPIO_MODER_MODER3_0;
	GPIOB -> MODER |= GPIO_MODER_MODER4_0;
	GPIOB -> MODER |= GPIO_MODER_MODER5_0;
	GPIOB -> MODER |= GPIO_MODER_MODER10_0;
	sct_led(0);
	sct_noe(0);
}


