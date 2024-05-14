;get 2 numbers and an operator as input
;operator 1->addition, 2->subtraction, 3->multiplication, 4->division

MOV A,#0FFH
MOV P2,A

LOOP:

MOV A,P2	;get number 1
MOV R0,A

MOV A,P2	;get number 2
MOV R1,A

MOV A,P2	;get operator

CJNE A,#1,CHK1
;perform addition
MOV B,R0	
MOV A,R1
ADD A,B
MOV P1,A
SJMP LOOP

CHK1: CJNE A,#2,CHK2
;perform subtraction
MOV B,R0
MOV A,R1
SUBB A,B
MOV P1,A
SJMP LOOP

CHK2: CJNE A,#3,CHK3
;perform multiplication
MOV B,R0
MOV A,R1
MUL AB
MOV P0,A
MOV P1,B
SJMP LOOP

CHK3: CJNE A,#4,LOOP
;perform division
MOV B,R0
MOV A,R1
DIV AB
MOV P0,A
MOV P1,B
SJMP LOOP
