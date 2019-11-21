/*
 * uart_app.c
 *
 * Created: 9/4/2019 12:45:20 PM
 *  Author: Ahmedhassan
 */ 


#include "macro.h"
#include "uart_driver.h"
volatile extern uint8_t data_rx;
int main(void)
{
	uart_init_as_tx();
	uart_init_as_Rx();
	uart_read_interrupt_init();
    uart_write_string("ahmedhassan");
    while(1)
    {
		
		
		
    }
}
