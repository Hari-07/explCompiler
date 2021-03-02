%{
	#include<stdio.h>
	#include<stdlib.h>
	#include "y.tab.h"
	#ifndef EXPTREE_H
	#define EXPTREE_H
	#include"exptree.h"
	#endif
%}

%%

[0-9]+		{
				yylval.d = atoi(yytext);
				return NUM;
			}
			
\"[:_a-zA-z 0-9]*\" {
					yylval.s = yytext;
					return STRING;
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
[(),\[\]{}]	{	return *yytext;	}
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
repeat 		{	return REPEAT;	}
until		{	return UNTIL;	}
int			{	return INT;		}
str 		{	return STR;		}
decl		{	return DECL;	}
enddecl		{	return ENDDECL;	}
main		{	return MAIN;	}
[a-z][a-z0-9]*		{	
						char* temp = (char*)malloc(sizeof(char)*strlen(yytext));
						strcpy(temp, yytext);
						yylval.s = temp;
						return VAR;
					}
.			{	printf("UNKNOWN CHARACTER\n %s", yytext); exit(1);	}

%%

int yywrap(void){
	return 1;
}