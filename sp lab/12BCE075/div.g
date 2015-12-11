grammar div;

options {
  k=2; // two characters of lookahead
}  


tokens {
	PLUS 	= '+' ;
	MINUS	= '-' ;
	MULT	= '*' ;
	DIV	= '/' ;
	LPAREN  = '(' ;
	RPAREN  = ')' ;
	EQU	= '=' ;
	RCURL	= '{' ;
	LCURL	= '}' ;
	EOS	= ';' ;
	NULL    = ' ';
	//IF	= 'if';
}

//root 	: (cstatement)+;

cstatement
	: ( ifStatement | expression | loopStatement ) (cstatement) ;

ifStatement
  : 'if' LPAREN condi RPAREN ( RCURL (cstatement)* LCURL )
    ( ('else')=> 'else' ( RCURL (cstatement)* LCURL )
    | ( ) // nothing
    )
  ;
  
  

loopStatement
  : 'while' LPAREN condi RPAREN ( RCURL ( cstatement )* LCURL ) EOS    
  ;

condi
  :  factor ('<'|'=='|'>'|'<='|'>=') (factor|expression2)
    ;
  
//assignment 
//	:	( ID EQU )+ expression EOS;
  

expression	: term ( ( PLUS | MINUS | EQU )  term )* EOS ;    

expression2     
	:	(LPAREN (term (( PLUS | MINUS ) expression2)* ) RPAREN) | factor  ; 

term	: factor ( ( MULT | DIV ) ( factor | expression2 ) )* ;

factor	: INT | ID ;

ID  :	('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'0'..'9'|'_')*
    ;

INT :	'0'..'9'+
    ;

COMMENT
    :   '//' ~('\n'|'\r')* '\r'? '\n' {$channel=HIDDEN;}
    |   '/*' ( options {greedy=false;} : . )* '*/' {$channel=HIDDEN;}
    ;

WS  :   ( ' '
        | '\t'
        | '\r'
        | '\n'
        ) {$channel=HIDDEN;}
    ;

STRING
    :  '"' ( ESC_SEQ | ~('\\'|'"') )* '"'
    ;

CHAR:  '\'' ( ESC_SEQ | ~('\''|'\\') ) '\''
    ;

fragment
HEX_DIGIT : ('0'..'9'|'a'..'f'|'A'..'F') ;

fragment
ESC_SEQ
    :   '\\' ('b'|'t'|'n'|'f'|'r'|'\"'|'\''|'\\')
    |   UNICODE_ESC
    |   OCTAL_ESC
    ;

fragment
OCTAL_ESC
    :   '\\' ('0'..'3') ('0'..'7') ('0'..'7')
    |   '\\' ('0'..'7') ('0'..'7')
    |   '\\' ('0'..'7')
    ;

fragment
UNICODE_ESC
    :   '\\' 'u' HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT
    ;
