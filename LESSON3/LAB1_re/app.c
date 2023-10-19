#include "UART.h"
unsigned char my_text[100] = "learn_in_deapth: <Hossam Diab>";
const unsigned char rodata_text[100] = "learn_in_deapth: <Hossam Diab>";

/*Calling UART FUNCTION*/

void main(void ){

UART_TXT(my_text);

}