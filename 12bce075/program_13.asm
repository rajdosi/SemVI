DATA SEGMENT
	N DB 0CH
	ANS DB 5 DUP(0)
DATA ENDS

MYSTACK SEGMENT STACK
	DB 100 DUP(0)
	TOS LABEL WORD
MYSTACK ENDS

CODE SEGMENT
	ASSUME DS:DATA,SS:MYSTACK,CS:CODE
MYSTA:	MOV AX,DATA
	MOV DS,AX
	MOV AX,MYSTACK
	MOV SS,AX
	MOV SP,TOS
	MOV CL,N
	MOV AL,00H
	MOV BL,01H
	MOV AH,00H
	MOV DX,0000H
	CALL PRINTFN
	MOV DX,0001H
	CALL PRINTFN

PASS:	MOV BH,BL
	ADD AL,BL
	;DAA
	;MOV DH,AL
	;MOV DL,AL
	;AND DL,0FH
	;SHR DH,04H
	;AND DH,0FH
	CALL PRINTFN
	MOV BL,AL
	MOV AL,BH
	DEC CL
	JNZ  PASS
	
	MOV AH,4CH
	INT 21H

	PRINTFN PROC
		PUSH BX
		PUSHF
		PUSH AX
		PUSH CX
		PUSH DX
		mov bx,0000h
		l4 : cmp al, 64h     ; if ax>100  
		      jb      l6  
		      sub      al, 64h 
		      add      bx, 100h         ; add 100h to result  
		      jmp      l4  
		l6 : cmp al, 0Ah       ; if ax>10  
		      jb      l8  
		      sub      ax, 0Ah
		      add      bx, 10h          ; add 10h to result  
		      jmp      l6  
		l8 :  add      bx, ax       ; add remainder  
		
		MOV DH,BL
		MOV DL,BL
		MOV CL,BH
		AND CL,0FH
		
		AND DL,0FH
		SHR DH,04H
		AND DH,0FH
		
		ADD DH,30H
		ADD DL,30H
		ADD CL,30H
		
		LEA SI,ANS
		MOV [SI],CL
		INC SI
		MOV [SI],DH
		INC SI
		MOV [SI],DL

		MOV BX,01H
		MOV CX,04H
		MOV AH, 40H
		MOV DX, OFFSET ANS
		INT 21H
		
		POP DX
		POP CX
		POP AX
		POPF
		POP BX
		RET
	ENDP
CODE ENDS
	END MYSTA