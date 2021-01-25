%{
	#include<stdio.h>
	#include<stdlib.h>
	#include "y.tab.h"
	#include "data.h"
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