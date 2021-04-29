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

[-+]?[0-9]+	{
				yylval.integer = atoi(yytext);
				return NUM;
			}
			
\"[:_a-zA-z 0-9]*\" {
					char* temp = (char*)malloc(sizeof(char)*(strlen(yytext)-2));
					strncpy(temp, yytext+1, strlen(yytext) - 2);
					yylval.string = temp;
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
[ \t\n]		{}
[(),\[\]{};.] {	return *yytext;	}
start		{	return START;	}
end 		{	return END;		}
read 		{	return READ; 	}
write		{	return WRITE;	}
alloc		{	return ALLOC;	}
dealloc		{	return DEALLOC;	}
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
self		{	return SELF;	}
new			{	return NEW;		}
extends		{	return EXTENDS;	}
brkp		{	return BREAKPOINT;	}
int			{	
				char* temp = (char*)malloc(sizeof(char)*strlen(yytext));
				strcpy(temp, yytext);
				yylval.string = temp;
				return INT;		
			}
string		{	
				char* temp = (char*)malloc(sizeof(char)*strlen(yytext));
				strcpy(temp, yytext);
				yylval.string = temp;
				return STR;		
			}
null 		{	return NULL_TOKEN;	}
decl		{	return DECL;	}
enddecl		{	return ENDDECL;	}
class		{	return CLASSBEGIN; 	}
endclass	{	return ENDCLASS;	}
main		{	return MAIN;	}
args 		{	return ARGS;	}
return 		{	return RETURN;  }
type		{	return TYPE;	}
endtype		{ 	return ENDTYPE; }
[a-zA-Z_][_a-zA-Z0-9]*		{	
						char* temp = (char*)malloc(sizeof(char)*strlen(yytext));
						strcpy(temp, yytext);
						yylval.string = temp;
						return VAR;
					}
.			{	printf("UNKNOWN CHARACTER\n %s", yytext); exit(1);	}

%%

int yywrap(void){
	return 1;
}