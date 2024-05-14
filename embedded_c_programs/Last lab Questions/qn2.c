#include <reg51.h>

#define DELAY 1000; 

unsigned char code_2421[] = {0x00,0x01,0x02,0x03,0x04,0x0B,0x0C,0x0D,0x0E,0x0F};
unsigned char code_8421[] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09};

void delay_in_ms(unsigned int time){
	unsigned int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<1275;j++);
	}

}
void main() {
	unsigned int dig1,dig2,dig3,num;
	P2 = 0;
	num = P0;
	if(num<100){
		dig1 = num/10;
		dig2 = num%10;
		dig1 = code_2421[dig1];
		dig2 = code_2421[dig2];
		while(1){
			P2 = dig1;
			delay_in_ms(1000);
			P2 = dig2;
			delay_in_ms(1000);
		}
			
	}
	else{
		dig1 = num/100;
		num = num%100;
		dig2 = num/10;
		dig3 = num%10;
		dig1 = code_8421[dig1];
		dig2 = code_8421[dig2];
		dig3 = code_8421[dig3];
		while(1){
			P2 = dig1;
			delay_in_ms(1000);
			P2 = dig2;
			delay_in_ms(1000);
			P2 = dig3;
			delay_in_ms(1000);
		}
	}
			
}
