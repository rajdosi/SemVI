Mydata segment

	buffer db 82 dup(0)	;string to be stored here
	max equ 80		;max size of string allowed

	prompt db "Enter string:",'$'		;use this when we want to ask for string
	prompt1 db 0dh,0ah,'$'			;use this when we want to go to next line
	prompt2 db "Entered string is:",'$'	;use this to display "Entered string:" message
	prompt3 db "Reversed string:",'$'	;use this to display "Reversed string:" message

	temp db 82 dup(0)			;to store temporary string

Mydata ends


Mystack segment stack
	dw 50 dup(0)
	tos label word
Mystack ends


code segment

	start:
	assume cs:code,ds:Mydata,ss:Mystack
	mov ax,Mydata
	mov ds,ax
	mov ax,Mystack
	mov ss,ax
	lea sp,tos

	;start body

	;Asking user to enter string

	mov ah,09h
	lea dx,prompt
	int 21h

		
	;buffer[0]=Max length of string (done by us)
	;buffer[1]=Actual length of string (done implicitely)
	;buffer[2] onwards is actual string
	
	lea dx,buffer
	mov byte ptr [bx],max	;stored max in buffer[0]

	;reading input from user


	mov ah,0ah
	mov dx,offset buffer
	int 21h
	

	
	;taking display two lines down
	mov ah,09h
	lea dx,prompt1
	int 21h

	mov ah,09h
	lea dx,prompt1
	int 21h

	;displaying message on screen

	mov ah,09h
	lea dx,prompt2
	int 21h

	;displaying string on screen

	mov si,offset buffer
	mov cl,[si+1]
	mov ch,00h
	mov ah,40h
	mov bx,01h
	mov dx,si
	add dx,02h
	int 21h

	;taking display two lines down
	mov ah,09h
	lea dx,prompt1
	int 21h

	mov ah,09h
	lea dx,prompt1
	int 21h

	;Calling procedure to reverse string

	lea bx,buffer
	lea di,buffer	;storing buffer starting point in two places
	call reverse
	

	;displaying message on screen

	mov ah,09h
	lea dx,prompt3
	int 21h

	;Printing reversed string on screen

	mov si,offset buffer
	mov cl,[si+1]
	mov ch,00h
	mov ah,40h
	mov bx,01h
	mov dx,si
	add dx,02h
	int 21h

	;taking display two lines down
	mov ah,09h
	lea dx,prompt1
	int 21h
	
	mov ah,09h
	lea dx,prompt1
	int 21h



	mov ah,4ch
	int 21h


	;Fuction defintion
	reverse proc near

		pushf
		push ax
		push bx
		push cx
		push dx

		 
                
                mov cl,[di+1]     ;storing size of string in cl
               

		mov dl,cl	;storing length of string in dl as well

		lea si,temp	;si points to starting of temp

		inc bx
		inc bx
		;bx now points to actual content of buffer

	  loop1:mov ah,[bx]	;storing letter in ah 
		mov [si],ah	;storing letter in temp
		inc si
		inc bx
		dec cl
		jnz loop1

		dec si	;si now points to last letter stored in temp

		;di points to start of buffer
		inc di
		inc di
		;di now points to actual content of buffer
		
		;dl contains length of string in buffer

	  loop2:mov ah,[si]
		mov [di],ah
		dec si
		inc di
		dec dl
		jnz loop2
		

		pop dx
		pop cx
		pop bx
		pop ax
		popf

                ret
	reverse endp			
	
	code ends 

end start	

		
