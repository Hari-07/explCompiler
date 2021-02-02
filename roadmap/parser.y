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

%type <node> expr program stmt slist inputStmt outputStmt assgStmt ifStmt whileStmt;
%token START END
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE READ WRITE 
%token NUM VAR ADD SUB MUL DIV EQUALS SLT SGT LTE GTE NEQ EQU
%left SLT SGT LTE GTE NEQ EQU
%left ADD SUB
%left MUL DIV

%%

program: START slist END	{
								starter($2);
								printf("COMPLETED\n");
							}
	   | START END			{
		   						printf("EMPTY PROGRAM\n");
	   						}
	   ;


slist:	slist stmt		{	$$ = makeConnectorNode($1, $2);	}
	 |	stmt			{	$$ = makeConnectorNode($1, NULL);	}
	 ;

stmt:	inputStmt		{	$$ = $<node>1;	}
	|   outputStmt		{	$$ = $<node>1;	}
	|	assgStmt		{	$$ = $<node>1;	}
	|   ifStmt
	|	whileStmt
	;

inputStmt:	READ'('expr')'	{	$$ = makeReadNode($3);	}
		 ;

outputStmt:	WRITE'('expr')' { 	$$ = makeWriteNode($3);	}
		  ;

assgStmt: expr EQUALS expr	{	$$ = makeOperatorNode(1, "=",$1,$3);	}
		;

ifStmt : IF '('expr')' THEN slist ELSE slist ENDIF	{ $$ = makeIfNode($3, $6, $8); }
	   | IF '('expr')' THEN slist ENDIF				{ $$ = makeIfNode($3, $6, NULL); }
	   ;

whileStmt	: WHILE '('expr')' DO slist ENDWHILE	{	$$ = makeWhileNode($3, $6);	}
			;

expr: '('expr')'		{	$$ = $<node>2; }
	| expr	ADD	expr	{	$$ = makeOperatorNode(1, "+",  $1, $3);	}
	| expr	SUB	expr	{	$$ = makeOperatorNode(1, "-",  $1, $3);	}
	| expr	MUL	expr	{	$$ = makeOperatorNode(1, "*",  $1, $3);	}
	| expr	DIV	expr	{	$$ = makeOperatorNode(1, "/",  $1, $3);	}
	| expr 	SLT expr    {	$$ = makeOperatorNode(2, "<",  $1, $3);	}
	| expr 	SGT expr    {	$$ = makeOperatorNode(2, ">",  $1, $3);	}
	| expr 	LTE expr    {	$$ = makeOperatorNode(2, "<=", $1, $3);	}
	| expr 	GTE expr    {	$$ = makeOperatorNode(2, ">=", $1, $3);	}
	| expr 	NEQ expr    {	$$ = makeOperatorNode(2, "!=", $1, $3);	}
	| expr 	EQU expr    {	$$ = makeOperatorNode(2, "==", $1, $3);	}
	| NUM				{	$$ = $<node>1; }
	| VAR				{	$$ = $<node>1; }
	;
%%

void yyerror(char const *s)
{
    printf("yyerror: %s",s);
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