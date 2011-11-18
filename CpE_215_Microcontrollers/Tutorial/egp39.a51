; example for a p39-like problem 

	cseg at 0
	ljmp start

table:	db 0,1,4,9,16,25,36,49

	cseg at 100h
start:	mov P1,#0eoh	;bits 5 to 7 inputs

loop:	mov a,p1	;read p1

	mov r2,#5	;shift right 5x 
rotlp:	rr a
	djnz r2,rotlp

	anl a,#7	;mask input bits
	mov dptr,#table	;get table address
	movc a,@a+dptr	;get ith entry in table

