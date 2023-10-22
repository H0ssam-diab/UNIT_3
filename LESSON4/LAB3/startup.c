/*Author : Hossam Diab */
#include "Platform_Types.h"
extern int main(void);
extern uint32 _E_text ;
extern uint32 _S_data ;
extern uint32 _E_data ;
extern uint32 _S_bss ;
extern uint32 _E_bss ;

static uint32 Stack_Top[256];

void Reset_Handler(void){
	int i;
	/*Copying Data , Reserving bss*/
	uint32 _data_size =(unsigned char *) &_E_data - (unsigned char *) &_S_data;
	uint32 _bss_size  =(unsigned char *) &_E_bss  - (unsigned char *) &_S_bss ;
	unsigned char* P_src = (unsigned char *) &_E_text ;
	unsigned char* P_dst = (unsigned char *) &_S_data ;
	for(i=0;i<_data_size;i++){
			
			*((unsigned char*)P_dst++) = *((unsigned char*)P_src++) ;  

		}
    P_dst = (unsigned char *) &_S_bss ;
	for(i=0;i<_bss_size;i++){
			
			*((unsigned char*)P_dst++) = (unsigned char)0 ;  

		}


	main();
}

void Default_Handler(void){Reset_Handler();}
void NMI_Handler(void) __attribute__ ((weak,alias("Default_Handler")));
void H_Fault_Handler(void) __attribute__ ((weak,alias("Default_Handler")));
void MM_Fault_Handler(void) __attribute__ ((weak,alias("Default_Handler")));
void Bus_Fault(void) __attribute__ ((weak,alias("Default_Handler")));
void Usage_Fault_Handler(void) __attribute__ ((weak,alias("Default_Handler")));



 void (* const vectors[])()  __attribute__ ((section(".vectors"))) ={

(void(*)()) ((uint32)Stack_Top + sizeof(Stack_Top)),
&Reset_Handler,
&NMI_Handler,
&H_Fault_Handler,
&MM_Fault_Handler,
&Bus_Fault,
&Usage_Fault_Handler

};