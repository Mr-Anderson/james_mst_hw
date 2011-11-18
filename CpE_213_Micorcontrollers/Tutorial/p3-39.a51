; example for a p39-like problem 

	cseg at 0
	ljmp start

table:	db 0,1,4,9,16,25,36,49

	cseg at 100h
start:	mov P1,#0eoh
