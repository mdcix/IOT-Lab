MOV R0,#30H
MOV A,@R0
CJNE A,#0AH,L1

L1:
JNC L2
ADD A,#30H
SJMP STR

L2:
ADD A,#37H

STR: 
INC R0
MOV @R0,A

HLT : SJMP HLT
