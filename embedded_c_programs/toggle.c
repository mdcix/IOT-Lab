#include <reg51.h>
sbit MYBIT = P2^0;

void delay(unsigned int lim){
	unsigned int i;
	for(i=0;i<lim;i++);
}

int main(){
	while(1){
	MYBIT = 0;
	delay(250);
	MYBIT = 1;
	delay(250);
	}
}