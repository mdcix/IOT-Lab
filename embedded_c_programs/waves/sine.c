#include <math.h>
#include <reg51.h>

unsigned int a;
float rad;
float val;

int main(){
	for(a=0;a<360;a++){
	rad = 0.0174533*a;
	val = sin(rad)*128;
	val = 128+val;
	P2 = val;
}
}
