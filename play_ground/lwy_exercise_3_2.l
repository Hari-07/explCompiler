%{
	#include<stdio.h>
	#include<string.h>
	#include"y.tab.h"
%}

%%

[a-z A-Z]+	{
				char* temp = (char*)malloc(sizeof(char)*strlen(yytext));
				strcpy(temp, yytext);
				yylval.c = temp;
				printf("FLEX: %s\n", yytext);
				return ALPHA;
			}
[-+]		{
				yylval.operator =  *yytext;
				return OPLOW;
			}	
[*/]		{
				yylval.operator =  *yytext;
				return OPHIGH;
			}	
[()]			return *yytext;
[\n]			return NEWLINE;

%%

int yywrap(){
	return 1;
}