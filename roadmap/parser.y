%{
	#include<stdio.h>
	#include<stdlib.h>

	#ifndef EXPTREE_H
	#define EXPTREE_H
	#include"exptree.h"
	#endif

	#ifndef SYMBOLS_H
	#define SYMBOLS_H
	#include "symbol_table.h"
	#endif

	#include "exptree.c"
	#include "compiler.c"
	#include "symbol_table.c"

	int yylex(void);
	void yyerror(const char *s);
%}

%union {
	struct tnode* node;
	int d;
	char* s;
};

%type <d> type varlist
%type <node> expr program stmt slist inputStmt outputStmt assgStmt ifStmt whileStmt jmpStmts declarations decllist decl
%token START END DECL ENDDECL
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE READ WRITE CONTINUE BREAK REPEAT UNTIL
%token INT STR
%token NUM VAR ADD SUB MUL DIV EQUALS SLT SGT LTE GTE NEQ EQU STRING
%left SLT SGT LTE GTE NEQ EQU
%left ADD SUB
%left MUL DIV

%%
code: declarations program
	;

declarations: DECL decllist ENDDECL		{}
			| DECL ENDDECL				{}
			;

decllist: decllist decl
		| decl
		;

decl: type varlist						{}
	;

type: INT 	{	$<d>$ = 0;	}
	| STR	{	$<d>$ = 1;	}
	;

varlist: varlist ',' VAR				{	addVariable($<s>3, $<d>0, 1);	} 
	   | VAR							{	addVariable($<s>1, $<d>0, 1); 	}
	   ;

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
	|   ifStmt			{	$$ = $<node>1;	}
	|	whileStmt		{	$$ = $<node>1;	}
	| 	jmpStmts		{   $$ = $<node>1;	}
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

whileStmt	: WHILE '('expr')' DO slist ENDWHILE	{	$$ = makeWhileNode(0, $3, $6);	}
			| DO slist WHILE '('expr')' ENDWHILE	{	$$ = makeWhileNode(1, $5, $2); 	}
			| REPEAT slist UNTIL '('expr')'			{	$$ = makeWhileNode(2, $5, $2);	}
			;

jmpStmts	: CONTINUE	{	$$ = makeJumpStatement(0);	}
			| BREAK		{	$$ = makeJumpStatement(1);	}
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
	| NUM				{	$$ = $<node>1; 	}
	| STRING			{	$$ = $<node>1;	}
	| VAR				{	$$ = makeVariableNode($<s>$); }
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