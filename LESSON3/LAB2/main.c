/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Hossam Diab
 * @brief          : Main program body
 ******************************************************************************
 ******************************************************************************
 */
#include "stdio.h"
#include "Platform_Types.h"

#define RCC_BASE 0x40021000
#define APB2ENR_OFFSET 0x18

#define GPIO_PORTA_BASE 0x40010800
#define PA_CRH_OFFSET 0X04 /*Port A*/
#define PA_ODR_OFFSET 0x0C /*Port A*/

#define RCC_APB2ENR  *((vuint32_t*)(RCC_BASE + APB2ENR_OFFSET ))
#define GPIOA_CRH    *((vuint32_t*)(GPIO_PORTA_BASE + PA_CRH_OFFSET ))
#define GPIOA_ODR    *((vuint32_t*)(GPIO_PORTA_BASE + PA_ODR_OFFSET ))

typedef union{
	vuint32_t all_pins ;
	struct{
		vuint32_t reserved : 13;
		vuint32_t pin_13 :1;
	}Spins;
}Upins_t;

volatile Upins_t * PINS = (volatile Upins_t *)(GPIO_PORTA_BASE + PA_ODR_OFFSET );

volatile  const int const_variables[5]={1,5,8,9,6};
int i;
int main(void)
{
	vuint64_t i;
	RCC_APB2ENR |= (1<<2);
	GPIOA_CRH   &= 0xff0fffff;
	GPIOA_CRH   |= 0x00200000;

	while(1){
		PINS ->Spins.pin_13 = 1;
		for(i=0 ; i<10000;i++);
		PINS ->Spins.pin_13 = 0;
		for(i=0 ; i<10000;i++);
	}
}
