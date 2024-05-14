#include <reg51.h>

int main(){
	unsigned int x = 0;
	for(;;){
		x=0;
		while(x++<255){
			P2 = x;
		}
		while(x-->0){
			P2 = x;
		}
	}
}