mydata segment
	num dw 4542h
	cnt db ?
mydata ends

mycode segment
	assume cs:mycode, ds:mydata

mylabel:mov ax, mydata
	mov ds,ax

	mov ax,num
	mov cl,00h
	mov bl,10h
loop1:	ror ax,01
	jnc not1
	inc cl
not1:	dec bl
	jnz loop1
	mov cnt,cl
	;normal termination of program
	mov ah, 4ch
	int 21h

mycode ends
	end mylabel
