;SCON PRINT THE TWO DATA

MOV TMOD, #20H    ; Set Timer 1 to mode 2 (8-bit auto-reload) for serial communication
MOV TH1, #-6      ; Set the reload value for baud rate generation
MOV SCON, #50H    ; Set serial mode 1, 8-bit UART
SETB TR1          ; Start Timer 1

MAIN:
    MOV DPTR, #MYDATA1   ; Load address of MYDATA1 into DPTR
SEND_HELLO:
    CLR A                ; Clear accumulator
    MOVC A, @A+DPTR      ; Move character from code memory to accumulator
    JZ SEND_WELCOME      ; If null terminator encountered, jump to sending welcome message
    MOV SBUF, A          ; Move character to serial buffer
WAIT_HELLO:
    JNB TI, WAIT_HELLO   ; Wait for transmit complete
    CLR TI               ; Clear transmit interrupt flag
    INC DPTR             ; Increment data pointer
    SJMP SEND_HELLO      ; Continue sending characters

SEND_WELCOME:
    MOV DPTR, #MYDATA2   ; Load address of MYDATA2 into DPTR
SEND_WELCOME_LOOP:
    CLR A                ; Clear accumulator
    MOVC A, @A+DPTR      ; Move character from code memory to accumulator
    JZ MAIN              ; If null terminator encountered, return to main loop
    MOV SBUF, A          ; Move character to serial buffer
WAIT_WELCOME:
    JNB TI, WAIT_WELCOME ; Wait for transmit complete
    CLR TI               ; Clear transmit interrupt flag
    INC DPTR             ; Increment data pointer
    SJMP SEND_WELCOME_LOOP ; Continue sending characters

ORG 0600H
MYDATA1:
    DB "HELLO"           ; Message 1
    DB 00H               ; Null terminator
MYDATA2: 
    DB "WELCOME TO IOT"  ; Message 2
    DB 00H               ; Null terminator
