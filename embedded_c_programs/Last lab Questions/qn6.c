#include <reg51.h>

sbit P2_STATUS = P2^2;

unsigned int fib1 = 0, fib2 = 1, fib_next;
unsigned int delay_reload;

void delay(unsigned int count) {
	if(P2_STATUS)
		delay_reload = 0xFFFF - 5000;
	else
		delay_reload = 0xFFFF - 1000;
	while(count--){
		TH0 = delay_reload >> 8;
		TL0 = delay_reload & 0xFF;
		TR0 = 1;
		while (!TF0);
		TF0 = 0;
		TR0 = 0;
	}
}

void fibonacci() {
    fib_next = fib1 + fib2;
    fib1 = fib2;
    fib2 = fib_next;
    P1 = fib1;
}

void main() {
		P1 = 0;
    TMOD = 0x01;
    ET0 = 0;
    TR0 = 0;
    EA = 1;

    while (1) {
        fibonacci();
				if(fib1 >= 50){
					fib1 = 0;
					fib2 = 1;
				}
        delay(1000);
    }
}
