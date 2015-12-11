mydata segment
	mylist db 20h,30h,40h,15h,99h	
	cnt EQU $ - mylist
	max db ?		
	min db ?
mydata ends

mycode segment
	assume cs:mycode, ds:mydata

mylabel:mov ax, mydata
	mov ds,ax

	lea bx,mylist
	mov ah,[bx]
	mov al,[bx]
	mov cl,cnt
	dec cl
pass:	inc bx
	cmp ah,[bx]
	jnc maxjump
	mov ah,[bx]
maxjump:	cmp al,[bx]
	jc minjump
	mov al,[bx]
minjump:	dec cl
	jnz pass
	mov max,ah
	mov min,al
	

	;normal termination of program
	mov ah, 4ch
	int 21h

mycode ends
	end mylabel
