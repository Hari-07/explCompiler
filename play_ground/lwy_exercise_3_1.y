%{
	#include<stdio.h>
	#include<stdlib.h>
%}

%union {
	char character;
	char operator
};

%token ALPHA
%token NEWLINE
%left '+' '-'
%left '*' '/'

%%

start	: 	expr 	NEWLINE {
								printf("\nCOMPLETED\n");
								exit(1);
							}
			;

expr	:	expr '+' expr		{ printf("+"); }
			| expr '-' expr		{ printf("-"); }
			| expr '*' expr		{ printf("*"); }
			| expr '/' expr		{ printf("/"); }
			| '('expr')'
			|	ALPHA					{ printf("%c", $<character>1); }
			;
%%

void yyerror(char const *s){
	printf("Error: %s\n", s);
	return;
}

int main() {
	yyparse();
	return 1;
}