d [0-9]
l [A-Za-z_]
%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int i=0,flag=0,n=0,j=0,*dt;
char **sym;

%}
%%
({l})({l}|{d})*  {
flag=0;	
for(i=0;i<n;i++)
{
	if(!strcmp(yytext,sym[i]))
	{
		printf("id%d",i+1);
		flag=1;
		break;
	}
	
} 
if(flag==0)
{
	n++;
	printf("id%d",n);
	sym=(char **)realloc(sym,n*sizeof(char *));
	dt=(int *)realloc(dt,n*sizeof(int));
	sym[n-1]=(char *)malloc(256*sizeof(char));
	strcpy(sym[n-1],yytext);
	dt[n-1]=1;
}
}

("int")(" ")({l})({l}|{d})*(";") {
j=0; 
char *str=(char *)malloc(256*sizeof(char)); 
while(j<(yyleng-4))
{
	str[j]=yytext[j+4];
	j++;
}
printf("%s",str);
flag=0;	
for(i=0;i<n;i++)
{
	if(!strcmp(str,sym[i]))
	{
		printf("int id%d",i+1);
		flag=1;
		break;
	}
	
} 
if(flag==0)
{
	n++;
	printf("int id%d",n);
	sym=(char **)realloc(sym,n*sizeof(char *));
	dt=(int *)realloc(dt,n*sizeof(int));
	sym[n-1]=(char *)malloc(256*sizeof(char));
	strcpy(sym[n-1],str);
	dt[n-1]=1;
}
}

("float")(" ")({l})({l}|{d})*(";") {
j=0; 
char *str=(char *)malloc(256*sizeof(char)); 
while(j<(yyleng-4))
{
	str[j]=yytext[j+4];
	j++;
}
printf("%s",str);
flag=0;	
for(i=0;i<n;i++)
{
	if(!strcmp(str,sym[i]))
	{
		printf("float id%d",i+1);
		flag=1;
		break;
	}
	
} 
if(flag==0)
{
	n++;
	printf("float id%d",n);
	sym=(char **)realloc(sym,n*sizeof(char *));
	dt=(int *)realloc(dt,n*sizeof(int));
	sym[n-1]=(char *)malloc(256*sizeof(char));
	strcpy(sym[n-1],str);
	dt[n-1]=2;
}
}



%%

int main()
{
yylex();

return 0;
}
