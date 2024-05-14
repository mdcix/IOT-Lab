#include <reg51.h>

void uart_init(){
	SCON = 0x50;
	TMOD = 0x20;
	TH1 = -6;
	TR1 = 1;
}

void send_char(char c){
	SBUF = c;
	while(!TI);
	TI = 0;
}

void send_string(char *str){
	int i;
	for(i=0;str[i]!=0;i++){
		send_char(str[i]);
	}
}

void delay(unsigned int count){
	int i,j;
	for(i=0; i<count; i++){
		for(j=0; j<1275; j++);
	}
}

char name[] = "karthik";	// Any declaration should be outside the main function

void main(){
	uart_init();
	while(1){
		send_string("Hello ");
		delay(1000);
		send_string(name);
		send_string("\n");
	}
}