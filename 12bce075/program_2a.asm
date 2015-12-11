
mydata segment
	num1 db	12h	; offset 0000; [0000]=34h and [0001]=12h
	num2 db	34h
	ans  dw ?
mydata ends

mycode segment
	assume cs:mycode, ds:mydata

	; 4 seg regs: cs, ds, es, ss
	; GP regs: AX,BX, CX, DX, SI,DI, SP, BP (16bit)
	;	 : ah, al, bl,bh,cl,ch
	; init ds
mylabel:mov ax, mydata
	mov ds,ax

	mov al, num1
	mul num2
	mov ans, ax
	;normal termination of program
	mov ah, 4ch
	int 21h

mycode ends
	end mylabel
