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
	int getfLabel();

	int flabel = 0;
%}

%define parse.error verbose

%union {
	struct tnode* node;
	int d;
	char* s;
	struct Param* fparams;
};

%type <d> type varlist
%type <node> expr program stmt slist inputStmt outputStmt assgStmt ifStmt whileStmt jmpStmts fnCallStmts declarations decllist decl fbody fdef argList
%type <fparams> paramlist param
%token START END DECL ENDDECL
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE READ WRITE CONTINUE BREAK REPEAT UNTIL MAIN
%token INT STR
%token NUM VAR ADD SUB MUL DIV EQUALS SLT SGT LTE GTE NEQ EQU STRING ARR_INDEX
%nonassoc SLT SGT LTE GTE NEQ EQU
%left ADD SUB
%left MUL DIV

%%
code : declarations fdefblock program
	 | declarations program
	 | program
	 ;

declarations : DECL decllist ENDDECL	{
											test();
										}
			 | DECL ENDDECL				{}
			 ;

decllist : decllist decl
		 | decl
		 ;

decl : type varlist						{}
	 ;


varlist: varlist ',' VAR				{	addGlobalVariable($<s>3, $<d>0, 1, -1, NULL);		}
	   | varlist ',' VAR '['NUM']'		{	addGlobalVariable($<s>3, $<d>0, $<d>5, -1, NULL);	}
	   | varlist ',' VAR '('paramlist')'{   addGlobalVariable($<s>3, $<d>0, 0, getfLabel(), $5);}
	   | VAR							{	addGlobalVariable($<s>1, $<d>0, 1, -1, NULL); 		}
	   | VAR '['NUM']'					{	addGlobalVariable($<s>1, $<d>0, $<d>2, -1, NULL);	}
	   | VAR '('paramlist')'			{   addGlobalVariable($<s>1, $<d>0, 0, getfLabel(), $3);}
	   ;

fdefblock : fdefblock fdef
		  | fdef
		  ;

fdef : type VAR '('paramlist')''{' ldeclarations fbody'}' 	
		{
			startCodeGen($<s>2, $8);
			free($8);
			terminateFunction();
		}

fbody : slist					{
									if(checkNameEquivalence($<fparams>-3, $<s>-5) == 0){
										printf("ILLEGAL FUNCTION DEFINITION\n");
										exit(-1);
									}
									addParamstoLSymbol($<fparams>-3);
								}
	  ;

paramlist : paramlist',' param			{ $$ = addParameter($1, $<fparams>3); }
		  | param						{ $$ = $<fparams>1; }
		  |								{}
		  ;

param : type VAR	{ 	$$ = createParameter($<s>2, $<d>1); 	}
	  ;

ldeclarations : DECL ldecllist ENDDECL
			  | DECL ENDDECL
			  ;

ldecllist : ldecllist ldecl
		  | ldecl
		  ;

ldecl : type lvarlist
	  ;

lvarlist : lvarlist ',' VAR				{	addLocalVariable($<s>3, $<d>0);	}
	     | VAR							{	addLocalVariable($<s>1, $<d>0); }
	     ;

type: INT 	{	$<d>$ = 0;	}
	| STR	{	$<d>$ = 1;	}
	;

program : INT MAIN '('')''{' ldeclarations slist'}'	
			{
				startCodeGen("main", $7);
				printf("COMPLETED\n");
			}
	    ;


slist :	slist stmt		{	$$ = makeConnectorNode($1, $2);	}
	  |	stmt			{	$$ = makeConnectorNode($1, NULL);	}
	  ;

stmt :	inputStmt		{	$$ = $<node>1;	}
	 |  outputStmt		{	$$ = $<node>1;	}
	 |	assgStmt		{	$$ = $<node>1;	}
	 |  ifStmt			{	$$ = $<node>1;	}
	 |	whileStmt		{	$$ = $<node>1;	}
	 | 	jmpStmts		{   $$ = $<node>1;	}
	 | 	fnCallStmts		{   $$ = $<node>1;  }
	 ;

inputStmt:	READ'('expr')'	{	$$ = makeReadNode($3);	};

outputStmt:	WRITE'('expr')' { 	$$ = makeWriteNode($3);	};

assgStmt: expr EQUALS expr	{	$$ = makeOperatorNode(0, "=",$1,$3);	};

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

fnCallStmts : VAR '('argList')' {	$$ = makeFunctionCallNode($<s>1, $<node>3); }
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
	| NUM				{	$$ = makeConstantNode(0, $<d>1, NULL); 	}
	| STRING			{	$$ = makeConstantNode(1, 0, $<s>1);		}
	| VAR '['expr']'	{	$$ = makeVariableNode($<s>1, $<node>3);	}
	| VAR '('argList')' {	$$ = makeFunctionCallNode($<s>1, $<node>3); }
	| VAR				{	$$ = makeVariableNode($<s>1, makeConstantNode(0, 0, NULL)); }
	;

argList : argList',' expr	{ $$ = makeConnectorNode($<node>1, $<node>3);	}
		| expr				{ $$ = makeConnectorNode(NULL, $<node>1);  }
		| 					{}
		;
%%

int getfLabel() {
	return flabel++;
}

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