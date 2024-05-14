#include <reg51.h>

sbit d7 = P3^7;
sbit d6 = P3^6;
sbit d5 = P3^5;
sbit d4 = P3^4;

void delay_in_ms(unsigned int time){
	unsigned int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<1275;j++);
	}
}

void main() {
	P2 = 0;
	while(1){
		if(d7 == 0){
			P2 = 0x0A;
		}
		else if(d6 == 0){
			P2 = 0x0B;
		}
		else if(d5 == 0){
			P2 = 0x0C;
		}
		else if(d4 == 0){
			P2 = 0x0D;
		}
		else{
			P2 = 0x0E;
		}
	}
			
}
