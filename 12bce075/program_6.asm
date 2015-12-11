mydata segment
	mylist db 20h,30h,40h,15h,99h	
	cnt EQU $ - mylist
	flag db 00h
mydata ends

mycode segment
	assume cs:mycode, ds:mydata

mylabel:mov ax, mydata
	mov ds,ax
	mov dh,flag;
	
	mov ch,cnt
	dec ch
outerp:	lea bx,mylist
	lea si,mylist
	inc si
	mov cl,ch
pass:	
	cmp dh,00h
	jnc desc

	mov dl,[bx]
	cmp dl,[si]
	jc nothin
	jmp done

desc:	mov dl,[bx]
	cmp dl,[si]
	jnc nothin

done:	mov al,[bx]
	mov ah,[si]
	mov [bx],ah
	mov [si],al
	
nothin:   	inc bx
	inc si
	dec cl
	jnz pass
	dec ch
	jnz outerp



	;normal termination of program
	mov ah, 4ch
	int 21h

mycode ends
	end mylabel
