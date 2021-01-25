%{
	#include<stdio.h>
	#include<stdlib.h>
	#include "y.tab.h"
	
	#ifndef DATA_H
	#define DATA_H
	#include"data.h"
	#endif
%}

%%

[0-9]+		{
				yylval.node = makeLeafNode(atoi(yytext));
				return NUM;
			}

"+"			{	return ADD;	}
"-"			{	return SUB;	}
"*"			{	return MUL;	}
"/"			{	return DIV;	}
[ \t]		{}
[()]		{	return *yytext; }
[\n]		{	return END;	}
.			{	printf("UNKNOWN CHARACTER\n"); exit(1);	}

%%

int yywrap(void){
	return 1;
}