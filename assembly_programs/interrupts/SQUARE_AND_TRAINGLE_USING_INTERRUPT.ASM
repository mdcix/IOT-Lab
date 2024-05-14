;Normally plot square wave
;if interrupt occur at p3.2, plot traingle wave
ORG 0000H
	LJMP MAIN
	
ORG 0003H
	LJMP SERVICE0
	
ORG 0030H
	MAIN:
	CLR P0.7
	CLR A
	SETB IE.0
	SETB IE.7
	CLR TCON.0
	L1:
		MOV A,#5
		MOV P1,A
		ACALL DELAY
		SJMP L2
	L2:
		MOV A,#250
		MOV P1,A
		ACALL DELAY
		SJMP L1
		
	DELAY:
		MOV R1,#255
		HERE:DJNZ R1,HERE
		RET

SERVICE0:
	MOV A,#0
	UPLOOP:
		MOV P1,A
		ADD A,#5
		CJNE A,#200,UPLOOP
	DOWNLOOP:
		MOV P1,A
		SUBB A,#5
		CJNE A,#0,DOWNLOOP
	RETI