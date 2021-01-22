%{
#include<stdio.h>
#include<stdlib.h>

int count = 0;
%}

%token COMP
%token VAR

%%

program	: 'i' 'f' '(' cond ')' {count++;}
		;

cond:	VAR COMP VAR

%%

yyerror(char const *s)
{
    printf("yyerror %s",s);
}

yylex(){
    char c;
    c = getchar();
	if(c == ' ') {
        yylex();         /*This is to ignore whitespaces in the input*/
    } 
	else if(c == '<' || c == '=='|| c == '!='|| c == '>') {
		return COMP;		
	} 
	else if(isdigit(c) || isalpha(c)) {
		return VAR;
	}
	else {
		return c;
	}
}

main(){
	yyparse();
}