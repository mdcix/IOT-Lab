#include <reg51.h>

int main(){
	unsigned int x = 0;
	for(;;){
		x=0;
		while(x++<255){
			P2 = x;
		}
		P2=0;
	}
}