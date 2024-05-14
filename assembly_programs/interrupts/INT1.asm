org 0500h
main: 
clr p0.7
mov ie,#82h
mov p2,#0ffh
mov p1,#00h
mov tmod,#22h
mov scon,#50h
mov th1,#-6
mov th0,#0ah
setb tr1
setb tr0
mov sbuf,#'s'
jnb ti,$
clr ti
org 00h
ljmp main
org 0bh
xrl p1,#0ffh
reti
