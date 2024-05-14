;get input from user in port2
;put output at port1

MOV A,#0FFH	
MOV P2,A	;make p2 as input port
MOV A,#00H
MOV P1,A	;make p1 as output port

LOOP:
  MOV A,P2	;get input number1 from user
  MOV B,A

  MOV A,P2	;get input number2 from user
  ADD A,B
  MOV P1,A	;write output in p1
  SJMP LOOP
