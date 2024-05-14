#include <reg51.h>

void delay_in_ms(unsigned int time){
	unsigned int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<1275;j++);
	}

}
void main() {
	unsigned int num1,num2,result;
	P2 = 0;
	P3 = 0;
	while(1){
		num1 = P0;
		num2 = P1;
		
		result = num1 + num2;
		P2 = result >> 8;
		P3 = result;
		delay_in_ms(10000);
		
		result = num1 - num2;
		P2 = result >> 8;
		P3 = result;
		delay_in_ms(10000);
		
		result = num1 * num2;
		P2 = result >> 8;
		P3 = result;
		delay_in_ms(10000);
		
		result = num1 / num2;
		P2 = result >> 8;
		P3 = result;
		delay_in_ms(10000);
	}
			
}
