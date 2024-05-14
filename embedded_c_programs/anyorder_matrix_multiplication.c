#include <reg51.h>
#include <stdio.h>

//define the order of the 2 matrices
#define ROWS_A 4
#define COLS_A 1
#define ROWS_B 1
#define COLS_B 4

void matrix_multiply(int A[ROWS_A][COLS_A], int B[ROWS_B][COLS_B], int C[ROWS_A][COLS_B]) {
    int i, j, k;
    for (i = 0; i < ROWS_A; i++) {
			for (j = 0; j < COLS_B; j++) {
				C[i][j] = 0;
				for (k = 0; k < COLS_A; k++) {
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
    int A[ROWS_A][COLS_A] = {{1},{2},{3},{4}};
    int B[ROWS_B][COLS_B] = {{1,2,3,4}};
		int C[ROWS_A][COLS_B];
		int i,j;
		char num_str[10];
		uart_init();

    matrix_multiply(A, B, C);
		
		for(i=0;i<ROWS_A;i++){
			for(j=0;j<COLS_B;j++){
				int_to_string(C[i][j],num_str);
				send_string(num_str);
				send_string("  ");
				delay(1000);
			}
			send_string("\n");
		}
		while(1);
}
