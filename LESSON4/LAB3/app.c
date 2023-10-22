#include "Platform_Types.h"

#define SYSCTL_RCGC2_R 		*((vuint32_t*)(0x400fe108))
#define GPIO_PORTF_DIR_R 	*((vuint32_t*)(0x40025400))
#define GPIO_PORTF_DEN_R 	*((vuint32_t*)(0x4002551c))
/*#define GPIO_PORTF_DATA_R 	*((vuint32_t*)(0x400253fc))*/

typedef union{
	vuint32_t all_pins ;
	struct 
	{
		vuint32_t reserved : 3 ;
		vuint32_t pin_3	   : 1 ;
	}Spins;
}Upins;

volatile Upins* ptr_pins = (volatile Upins*)(0x400253fc);
vuint64_t  i = 0;

void main(void){

	SYSCTL_RCGC2_R = 0x00000020;

	GPIO_PORTF_DEN_R  |= (1<<3);
	GPIO_PORTF_DIR_R  |= (1<<3);

	while(1){
		ptr_pins->Spins.pin_3 = 0;
		for(i=0 ; i < 250000 ; i++);
		ptr_pins->Spins.pin_3 = 1;
		for(i=0 ; i < 250000 ; i++);
	}


}