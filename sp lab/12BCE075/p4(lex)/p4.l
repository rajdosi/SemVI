d [0-9]
l [A-Za-z]
%{
#include<stdio.h>
int id=0,num=0;
%}
%%
(_|{l})({l}|{d})* {printf("Its identifier number %d",++id);}
({d}+)|(.({d})+)?  {printf("Its numeral number %d",++num);}
%%

int main()
{
yylex();
printf("%d %d",id,num);
return 0;
}
