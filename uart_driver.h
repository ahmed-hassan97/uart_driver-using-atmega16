/*
 * uart_driver.h
 *
 * Created: 9/4/2019 12:46:43 PM
 *  Author: A
 */ 


#ifndef UART_DRIVER_H_
#define UART_DRIVER_H_
#include "macro.h"
void uart_init_as_Rx();
void uart_init_as_tx();
void uart_write(uint8_t);
void uart_write_string(uint8_t *);
uint8_t uart_Read();
uint8_t uart_available();
void uart_read_interrupt_init();



#endif /* UART_DRIVER_H_ */