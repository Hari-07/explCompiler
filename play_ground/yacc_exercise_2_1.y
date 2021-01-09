%{
#include<stdio.h>
#include<stdlib.h>

int count = 0;
int flag = 0;
%}

%token IF
%token VAR
%token COMP

%%

program	:	statement '\n' 			{printf("STATEMENT\n");exit(0);}
	   	|   program statement '\n' {printf("PROGRAM STATEMENT\n");}
		;

statement: if_statement '\n' 	{printf("IF STATEMENT\n");}
		 ;

if_statement:	IF '(' condition ')' {printf("NON BRACE IF\n");count++;}
			|	IF '(' condition ')' '{' program '}' {printf("BRACE IF\n");count++;}
			;

condition: VAR COMP VAR {printf("CONDITION\n");}
		 ;

%%

yyerror(char const *s)
{
    printf("yyerror %s",s);
}

yylex(){
    char c;
    c = getchar();
	if(c == ' ') {
		flag = 0;
        yylex();         /*This is to ignore whitespaces in the input*/
    } else if(c == '<' || c == '=='|| c == '!='|| c == '>') {
		flag = 0;
		return COMP;		
	} else if(c == 'i'){
		flag = 1;
		yylex();
	} else if(c=='f' && flag == 1){
		flag = 0;
		return IF;
	} else if(isdigit(c) || isalpha(c)) {
		flag = 0;
		return VAR;
	}
}

main(){
	yyparse();
	printf("if count: %d", count);
}