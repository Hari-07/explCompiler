%{
	#include<stdio.h>
	#include<stdlib.h>

	#ifndef DATA_H
	#define DATA_H
	#include"data.h"
	#endif

	#include "exptree.c"
	#include "compiler.c"

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
						starter($1);
						printf("COMPLETED\n");
						exit(0);
					}

expr: ADD	expr expr	{	$$ = makeOperatorNode('+',$2,$3);	}
	| SUB	expr expr	{	$$ = makeOperatorNode('-',$2,$3);	}
	| MUL 	expr expr	{	$$ = makeOperatorNode('*',$2,$3);	}
	| DIV 	expr expr	{	$$ = makeOperatorNode('/',$2,$3);	}
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