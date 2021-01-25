%{
	#include<stdio.h>
	#include<stdlib.h>
	#include "data.h"
	#include "exptree.c"

	int yylex(void);
	void yyerror(const char *s);
%}

%union {
	struct tnode* node;
}

%type <node> expr program;
%token NUM END ADD SUB MUL DIV
%left ADD SUB
%left MUL DIV

%%

program: expr END	{
						printTree($1);
						printf("\n");
						printPreOrder($1);
						printf("\n");
						printPostOrder($1);
						printf("\nCOMPLETED\n");
						exit(0);
					}

expr: expr	ADD	expr	{	$$ = makeOperatorNode('+',$1,$3);	}
	| expr	SUB	expr	{	$$ = makeOperatorNode('-',$1,$3);	}
	| expr	MUL	expr	{	$$ = makeOperatorNode('*',$1,$3);	}
	| expr	DIV	expr	{	$$ = makeOperatorNode('/',$1,$3);	}
	| '('expr')'		{	$$ = $2; }
	| NUM				{	$$ = $<node>1; }
%%

void yyerror(char const *s)
{
    printf("yyerror %s",s);
}


int main(void) {
	yyparse();
	return 0;
}