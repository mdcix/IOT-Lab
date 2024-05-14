#include <reg51.h>
#include <stdio.h>

#define N 2

void matrix_multiply(int A[N][N], int B[N][N], int C[N][N]) {
    int i, j, k;
    for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				C[i][j] = 0;
				for (k = 0; k < N; k++) {
						C[i][j] += A[i][k] * B[k][j];
				}
			}
    }
}
void uart_init(){
    TMOD = 0x20;    
    TH1 = 0xFD;    
    SCON = 0x50;    
    TR1 = 1;       
}
void send_char(char c){
	SBUF = c;
	while(!TI);
	TI = 0;
}

void send_string(char *str){
	int i;
	for(i=0;str[i]!=0;i++){
		send_char(str[i]);
	}
}
void delay(unsigned int count){
	int i,j;
	for(i=0; i<count; i++){
		for(j=0; j<1275; j++);
	}
}

void int_to_string(int num, char *str){
    sprintf(str, "%d", num);
}

void main() {
    int A[N][N] = {{1, 2}, {4, 5}};
    int B[N][N] = {{9, 8}, {6, 5}};
		int C[N][N];
		int i,j;
		char num_str[10];
		uart_init();

    matrix_multiply(A, B, C);
		
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				int_to_string(C[i][j],num_str);
				send_string(num_str);
				send_string("  ");
				delay(1000);
			}
            send_string("\n");
		}
}
