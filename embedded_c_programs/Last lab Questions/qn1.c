#include <reg51.h>

sbit leftMost = P1^7;
sbit rightMost = P1^0;
unsigned int temp;

void delay_in_ms(unsigned int time){
	unsigned int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<1275;j++);
	}
}

void main() {
	unsigned int opt;
	while(1){
		opt = P2&3;
		if(opt==0){
			P1 = ~P1;
		}
		else if(opt == 1){
			P1 = P0;
		}
		else if(opt == 2){
			temp = rightMost;
			P1 = P1 >> 1;
			leftMost = temp;
		}
		else{
			temp = leftMost;
			P1 = P1 << 1;
			rightMost = temp;
		}
		delay_in_ms(5000);
	}
			
}
