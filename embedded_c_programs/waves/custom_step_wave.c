#include <reg51.h>

void delay(unsigned int lim){
	unsigned int i;
	for(i=0;i<lim;i++);
}

int main(){
	unsigned int x;
	for(;;){
		x = 0;
		P2 = x;
		delay(250);
		while(x++<=85){
			P2 = x;
		}
		x = 170;
		P2 = x;
		delay(250);
		while(x++<=254){
			P2 = x;
		}
		while(x-->=170){
			P2 = x;
		}
		delay(250);
		x = 85;
		P2 = x;
		while(x-->=1){
			P2 = x;
		}
		delay(250);
	}
}
