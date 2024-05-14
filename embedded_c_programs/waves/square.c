#include <reg51.h>

void delay(unsigned int lim){
	unsigned int i;
	for(i=0;i<lim;i++);
}

int main(){
	while(1){
	P2 = 0;
	delay(250);
	P2 = 255;
	delay(250);
	}
}