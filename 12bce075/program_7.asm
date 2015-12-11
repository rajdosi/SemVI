mydata segment
	mylist db 02h,05h
	cnt EQU $ - mylist
	avg_int db ?
	avg_dec db ?
mydata ends

mycode segment
	assume cs:mycode, ds:mydata

mylabel:mov ax, mydata
	mov ds,ax

	lea bx,mylist
	mov al,[bx]
	mov cl,cnt	
	mov ah,00h
	mov dl,64h
pass:	inc bx
	add al,[bx]
	jnc notcarry
	inc ah
notcarry:	dec cl
	jnz pass
	
	mov cl,cnt
	div cl
	mov avg_int,al
	mov al,ah
	mov ah,00h
	mul dl
	div cl
	mov avg_dec,al;
	

	;normal termination of program
	mov ah, 4ch
	int 21h

mycode ends
	end mylabel
