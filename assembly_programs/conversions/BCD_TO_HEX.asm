;Set number in address 30h
;hexadecimal output will be shown in 31h
;example input : 12(set 0x12 at 0x30 address)
;example output : 0c

MOV R0,#30H
MOV A,@R0
MOV R1,A
ANL A,#0F0H
SWAP A
MOV B,#0AH
MUL AB
MOV R2,A
MOV A,R1
ANL A,#0FH
ADD A,R2
INC R0
MOV @R0,A
HLT : SJMP HLT
