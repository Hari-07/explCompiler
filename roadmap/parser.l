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
				yylval.node = makeLeafNode(0, yytext);
				return NUM;
			}
[a-z]		{
				yylval.node = makeLeafNode(1, yytext);	
				return VAR;	
			}
"+"			{	return ADD;	}
"-"			{	return SUB;	}
"*"			{	return MUL;	}
"/"			{	return DIV;	}
"="			{	return EQUALS;	}
"<"			{	return SLT;	}
">"			{	return SGT;	}
"<="		{	return LTE;	}
">="		{	return GTE;	}
"!="		{	return NEQ;	}
"=="		{	return EQU;	}
[ \t\n;]	{}
[()]		{	return *yytext;	}
start		{	return START;	}
end 		{	return END;		}
read 		{	return READ; 	}
write		{	return WRITE;	}
if			{	return IF;		}
then		{	return THEN;	}
else		{	return ELSE;	}
endif		{	return ENDIF;	}
while		{	return WHILE;	}
do			{	return DO;		}
endwhile	{	return ENDWHILE;}
break		{	return BREAK;	}
continue 	{	return CONTINUE;}
.			{	printf("UNKNOWN CHARACTER\n %s", yytext); exit(1);	}

%%

int yywrap(void){
	return 1;
}