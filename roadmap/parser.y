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

%type <node> expr program stmt slist inputStmt outputStmt assgStmt;
%token NUM VAR ADD SUB MUL DIV EQUALS START END READ WRITE
%left ADD SUB
%left MUL DIV

%%

program: START slist END	{
								starter($2);
								printf("COMPLETED\n");
								exit(0);
							}
	   | START END			{
		   						printf("EMPTY PROGRAM\n");
								exit(0);
	   						}
	   ;

slist:	slist stmt		{	$$ = createTreeNode($1, $2);	}
	 |	stmt			{	$$ = createTreeNode($1, NULL);	}
	 ;

stmt:	inputStmt		{	$$ = $<node>1;	}
	|   outputStmt		{	$$ = $<node>1;	}
	|	assgStmt		{	$$ = $<node>1;	}
	;

inputStmt:	READ'('expr')'	{	$$ = makeReadNode($3);	}
		 ;

outputStmt:	WRITE'('expr')' { 	$$ = makeWriteNode($3);	}
		  ;

assgStmt: expr EQUALS expr	{	$$ = makeOperatorNode('=',$1,$3);	}
		;

expr: expr	ADD	expr	{	$$ = makeOperatorNode('+',$1,$3);	}
	| expr	SUB	expr	{	$$ = makeOperatorNode('-',$1,$3);	}
	| expr	MUL	expr	{	$$ = makeOperatorNode('*',$1,$3);	}
	| expr	DIV	expr	{	$$ = makeOperatorNode('/',$1,$3);	}
	| '('expr')'		{	$$ = $<node>2; }
	| NUM				{	$$ = $<node>1; }
	| VAR				{	$$ = $<node>1; }
	;
%%

void yyerror(char const *s)
{
    printf("yyerror %s",s);
}

extern FILE* yyin;

int main(int argc, char* argv[]) {
	if(argc > 1) {
		FILE* fp = fopen(argv[1],"r");
		if(fp)
			yyin = fp;
	}
	yyparse();
	return 0;
}