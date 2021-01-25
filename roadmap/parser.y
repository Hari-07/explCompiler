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