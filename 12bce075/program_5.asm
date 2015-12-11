data segment
	a db 10,9,8,7,6,5,4,3,2,1
	listsize EQU $-a
data ends

code segment
	assume cs:code,ds:data
mystart: mov ax,data
        mov ds,ax
		
		mov cx,listsize
		
		dec cx
	outer_loop:	mov dx,cx
		;dec cx
		lea bx,a

	inner_loop:	mov al,[bx]
		inc bx
		mov ah,[bx]
		cmp al,ah
		jna in_loop
		
		mov [bx],al
		dec bx
		mov [bx],ah
		inc bx
		
	in_loop:	loop inner_loop
		mov cx,dx
		loop outer_loop
		
	mov ah,4ch
	int 21h

code ends
end mystart