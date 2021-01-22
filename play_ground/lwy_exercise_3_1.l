%{
	#include<stdio.h>
	#include"y.tab.h"
%}

%%

[a-z A-Z]	{
				yylval.character = *yytext;
				return ALPHA;
			}
[-+*/]			return *yytext;
[()]			return *yytext;
[\n]			return NEWLINE;

%%

int yywrap(){
	return 1;
}