%{
#include<math.h>
#include<stdio.h>
#include"y.tab.h"
%}
%union
{
	float dval ;
}
%token <dval> NUMBER 

%left '+' '-'
%left '*' '/'
%left '&'
%type <dval> exp
%%
state : exp {printf("answer = %f\n",$1);}
;
exp : NUMBER 
 |exp '+' exp {$$=$1+$3;}
 |exp '-' exp {$$=$1-$3;}
 |exp '*' exp {$$=$1*$3;}
 |exp '/' exp {$$=$1/$3;}
 |exp '&' exp {$$=$1&&$3;}

;
%%

