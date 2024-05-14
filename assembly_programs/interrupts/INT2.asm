


org 00h
sjmp main

org 0bh
cpl p1.7
reti

org 01bh
sjmp t1isr

org 030h
main:
clr p0.7
mov tmod,#12h
mov th0,#0b9h
setb tr0
setb tr1
setb et0
setb et1
setb ea
sjmp $

t1isr:
clr tr1
mov th1,#0fch
mov tl1,#18h
setb tr1
cpl p1.6
reti


