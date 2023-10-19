#include "stdio.h"
#include "UART.h"


#define UART0  *((volatile unsigned int * const)((unsigned int *)0x101f1000))


void UART_TXT(unsigned char * P_text){

while (*P_text != 0){

UART0 = (unsigned int ) (*P_text) ;
++P_text;

}

}