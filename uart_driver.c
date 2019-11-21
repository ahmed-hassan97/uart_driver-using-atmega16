/*
 * uart_driver.c
 *
 * Created: 9/4/2019 12:46:11 PM
 *  Author: A
 */ 
#include "uart_driver.h"
#include "macro.h"
volatile uint8_t data_rx;
void uart_init_as_tx(){
	
	
	SET_BIT(UCSRB,TXEN);      //enable transimitter 
	SET_BIT(UCSRC,UCSZ0);   //set frame 8 bit data   1 stop bit and no parity
	SET_BIT(UCSRC,UCSZ1);   //set frame 8 bit data   1 stop bit and no parity
	SET_BIT(UCSRC,URSEL) ;  //this bit must 
		
    UBRRL =0x33;                 // set BAUD 9600   focs  8MH    asynchronus normal mode
}
void uart_init_as_Rx(){
	
	SET_BIT(UCSRB,RXEN);     //enable receiver
	SET_BIT(UCSRC,UCSZ0);   //set frame 8 bit data   1 stop bit and no parity
	SET_BIT(UCSRC,UCSZ1);   //set frame 8 bit data   1 stop bit and no parity
	SET_BIT(UCSRC,URSEL) ;  //this bit must
	UBRRL =0x33;                 // set BAUD 9600   focs  8MH    asynchronus normal mode
	

}


void uart_write(uint8_t data){

while(READBIT(UCSRA,UDRE)!=1);	
	UDR = data;
	
}
void uart_write_string(uint8_t *data){
	uint8_t i=0;
	for(i=0;data[i]!='\0';i++){
		
		uart_write(data[i]);
	}
	
}
uint8_t uart_Read(){
while(READBIT(UCSRA,RXC)!=1);	
	
return UDR;	
	
}
uint8_t uart_available(){      //check if data is available to read it
	
	if(READBIT(UCSRA,RXC)){
		
		return 1;
	}
	else{
		
		return 0;
	}
	
}

void uart_read_interrupt_init(){
	SET_BIT(UCSRC,UCSZ0);   //set frame 8 bit data   1 stop bit and no parity
	SET_BIT(UCSRC,UCSZ1);   //set frame 8 bit data   1 stop bit and no parity
	SET_BIT(UCSRB,RXEN);     //enable receiver
	SET_BIT(UCSRB,RXCIE);    //enables interrupt on the RXC Flag
	UBRRL =0x33;                 // set BAUD 9600   focs  8MH    asynchronus normal mode
	SET_BIT(SREG,7);        //enable glopal interrupt
}
ISR(USART_RXC_vect){
	
	data_rx = UDR;
	lcd_write_char(data_rx);
	
}


