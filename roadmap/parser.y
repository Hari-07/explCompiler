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

	#ifndef TYPES_H
	#define TYPES_H
	#include "type_table.h"
	#endif

	#include "exptree.c"
	#include "compiler.c"
	#include "symbol_table.c"
	#include "type_table.c"

	int yylex(void);
	void yyerror(const char *s);
	int getfLabel();

	// int yydebug = 1;
	int flabel = 0;
%}

// %define parse.error verbose

%union {
	struct tnode* node;
	int integer;
	char* string;
	struct Param* fparams;
	struct FieldlistNode* fieldnode;
	struct TypetableNode* typenode;
};

//TOP LEVEL 
/*
	TYPE DEFINITIONS
	GLOBAL VARIABLE AND FUNCTION DECLARATIONS
	FUNCTION DEFINITIONS
	MAIN FUNCTION
*/

//TYPE DEFINITIONS
%type<node> typedefSection
%type<node> typedefList
%type<node> typeDefinition
%type<fieldnode> fieldList
%type<fieldnode> fieldDeclaration
%type<typenode> fieldType

//GLOBAL VARIABLE AND FUNCTION DECLARATIONS
%type<node> globalDeclarations
%type<node> declarationList
%type<node> declaration
%type<typenode> dataType
%type<node> variableList

//FUNCTION DEFINITIONS
%type<node> functionDefinitionList
%type<node> functionDefinition
%type<typenode> returnType
%type<fparams> parameterList
%type<fparams> parameter
%type<node> localDeclarationBlock
%type<node> localDeclarationList
%type<node> localDeclaration
%type<node> localVariableList
%type<node> functionBody

//MAIN FUNCTION AND CORE
%type<node> mainFunction
%type<node> statementList
%type<node> statement
%type<node> inputStatement	
%type<node>	outputStatement
%type<node>	assignmentStatement
%type<node>	ifStatement
%type<node>	whileStatement
%type<node>	jumpStatement
%type<node>	functionCallStatement
%type<node>	returnStatement
%type<node> allocStatement
%type<node> deAllocStatement
%type<node> expression
%type<node> arithmeticExpression
%type<node> logicalExpression
%type<node> constant
%type<node> variable
%type<node> argList
%type<fieldnode> field

%token START END DECL ENDDECL
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE READ WRITE CONTINUE BREAK REPEAT UNTIL MAIN ARGS RETURN ALLOC DEALLOC
%token INT STR NULL_TOKEN TYPE ENDTYPE 
%token NUM VAR ADD SUB MUL DIV EQUALS SLT SGT LTE GTE NEQ EQU STRING ARR_INDEX
%nonassoc SLT SGT LTE GTE NEQ EQU
%left ADD SUB
%left MUL DIV



%%

//***************** PROGRAM STRUCTURE*****************

	code : typedefSection globalDeclarations functionDefinitionList mainFunction
		| globalDeclarations functionDefinitionList mainFunction
		| typedefSection globalDeclarations mainFunction
		| mainFunction
		;

//*****************TYPE DEFINITION SECTION*****************

	typedefSection : 
		TYPE						
			{
				typeTableCreate();
			}
		typedefList 
		ENDTYPE 					{} |
		TYPE						
			{
				typeTableCreate();
			}
		ENDTYPE 					{}
		;

	typedefList : 
		typedefList typeDefinition			{} | 
		typeDefinition						{} 
		;

	//VARIABLES TYPES ARE CREATED AND ADDED TO THE TYPE TABLE
	typeDefinition : 
		VAR {
				createTypeTableEntry($<string>1);
			}
		'{' fieldList '}'';'	
			{	
				addFieldsToTypeTable($<string>1, $4); 
			}
		;

	//GENERATES A LINKED LIST OF MEMBER FIELDS
	fieldList : 
		fieldList fieldDeclaration 
			{   
				$$ = addToFieldList($2, $1);
			} |
		fieldDeclaration
			{
				$$ = addToFieldList($1, NULL);
			}
		;

	//CREATES A NODE REPRESENTING A SINGLE FIELD
	fieldDeclaration : 
		fieldType VAR ';'
			{
				$$ = createFieldNode($1, $<string>2);
			}
		; 

	//RETURNS POINTER TO TYPETABLE ENTRY
	fieldType: 
		INT	{	$$ = findTypeTableEntry($<string>1);	} |
		STR	{	$$ = findTypeTableEntry($<string>1);	} |
		VAR	{	$$ = findTypeTableEntry($<string>1);	} ;

//*****************GLOBAL DECLARATIONS SECTION*****************

	globalDeclarations : 
		DECL declarationList ENDDECL	{}  
		;

	declarationList : 
		declarationList declaration		{} |
		declaration						{}
		;

	declaration : 
		dataType variableList';'		{}
		;

	dataType: 
		INT	{	$$ = findTypeTableEntry($<string>1);	} |
		STR	{	$$ = findTypeTableEntry($<string>1);	} |
		VAR	{	$$ = findTypeTableEntry($<string>1);	} ;

	variableList: 
		variableList ',' VAR					{	addGlobalVariable($<string>3, $<typenode>0, 		1, 		  -1, NULL);	} |
		variableList ',' VAR '['NUM']'			{	addGlobalVariable($<string>3, $<typenode>0, 	$<integer>5, -1, NULL);		} |
		variableList ',' VAR '('parameterList')'{   addGlobalVariable($<string>3, $<typenode>0, 		0, getfLabel(), $5);	} |
		VAR										{	addGlobalVariable($<string>1, $<typenode>0, 		1, 		  -1, NULL); 	} |
		VAR '['NUM']'							{	addGlobalVariable($<string>1, $<typenode>0, 	$<integer>2, -1, NULL);		} |
		VAR '('parameterList')'					{   addGlobalVariable($<string>1, $<typenode>0, 		0, getfLabel(), $3);	}
		;

//*****************FUNCTION DEFINITIONS SECTION*****************

	functionDefinitionList :
		functionDefinitionList functionDefinition | 
		functionDefinition
		;

	functionDefinition : 	
		returnType VAR '('parameterList')''{' 
			localDeclarationBlock 	
				{
					if(checkNameEquivalence($4, $<string>2) == 0){
						printf("ILLEGAL FUNCTION DEFINITION\n");
						exit(-1);
					}
					addParamstoLSymbol($4);
				}
		functionBody '}'							
			{
				startCodeGen($<string>2, $9);
				terminateFunction();
			}
		;
	returnType: 
		INT	{	$$ = findTypeTableEntry($<string>1);	} |
		STR	{	$$ = findTypeTableEntry($<string>1);	} |
		VAR	{	$$ = findTypeTableEntry($<string>1);	} 
		;

	parameterList : 
		parameterList',' parameter		{ $$ = addParameter($1, $3); } |
		parameter						{ $$ = $1; } |
			{}
		;

	parameter : 
		dataType VAR
			{ 	
				$$ = createParameter($<string>2, $1);
			}
		;

	localDeclarationBlock : 
		DECL localDeclarationList ENDDECL	{ $$ = $<node>2; } |
			{}
		;

	localDeclarationList : 
		localDeclarationList localDeclaration | 
		localDeclaration
		;

	localDeclaration : 
		dataType localVariableList';'		{}
		;

	localVariableList : 
		localVariableList ',' VAR		{	addLocalVariable($<string>3, $<typenode>0);	}| 
		VAR								{	addLocalVariable($<string>1, $<typenode>0); 	}
		;

	functionBody :
		statementList 	{ 	$$ = $1;	}
		;

//*****************MAIN FUNCTION AND CORE COMPONENTS*****************

	mainFunction : 
		INT MAIN '('')''{' localDeclarationBlock statementList'}'	
			{
				startCodeGen("main", $7);
				printf("COMPLETED\n");
			}
		;


	statementList :
		statementList statement';'		{	$$ = makeConnectorNode($1, $2);		} |
		statement ';'					{	$$ = makeConnectorNode($1, NULL);	}
		;

	statement :
		inputStatement				{  $$ = $1; } |		
		outputStatement				{  $$ = $1; } |
		assignmentStatement			{  $$ = $1; } |
		ifStatement					{  $$ = $1; } |
		whileStatement				{  $$ = $1; } |
		jumpStatement				{  $$ = $1; } |
		functionCallStatement		{  $$ = $1; } |
		returnStatement				{  $$ = $1; } |
		allocStatement				{  $$ = $1; } |
		deAllocStatement			{  $$ = $1; } 
		;

	inputStatement :	
		READ'('expression')'	{	$$ = makeReadNode($3);	}
		;

	outputStatement :	
		WRITE'('expression')' 	{ 	$$ = makeWriteNode($3);	}
		;

	allocStatement :
		expression EQUALS ALLOC'('')'		{  $$ = makeAllocNode($1); }

	deAllocStatement:
		DEALLOC '(' expression ')'			{  $$ = makeDeAllocNode($3); } 

	assignmentStatement: 
		expression EQUALS expression		{	$$ = makeOperatorNode(0, "=",$1,$3);	};

	ifStatement 
		: IF '('expression')' THEN statementList ELSE statementList ENDIF		{ 	$$ = makeIfNode($3, $6, $8); 	}
		| IF '('expression')' THEN statementList ENDIF							{ 	$$ = makeIfNode($3, $6, NULL); 	}
		;

	whileStatement : 
		WHILE '('expression')' DO statementList ENDWHILE	{	$$ = makeWhileNode(0, $3, $6);	} |
		DO statementList WHILE '('expression')' ENDWHILE	{	$$ = makeWhileNode(1, $5, $2); 	} |
		REPEAT statementList UNTIL '('expression')'			{	$$ = makeWhileNode(2, $5, $2);	}
		;

	jumpStatement : 
		CONTINUE	{	$$ = makeJumpStatement(0);	} |
		BREAK		{	$$ = makeJumpStatement(1);	}
		;

	functionCallStatement :
		VAR '('argList')' 	{	$$ = makeFunctionCallNode($<string>1, $3);	}
		;

	returnStatement : 
		RETURN expression	{ 	$$ = makeReturnNode($2); }
		;

	expression:
		'('expression')'		{  	$$ = $<node>2; 	} |
		VAR '('argList')' 		{	$$ = makeFunctionCallNode($<string>1, $3);	} |
		arithmeticExpression  	{  	$$ = $1; 		} |
		logicalExpression		{  	$$ = $1; 		} |
		constant  				{  	$$ = $1; 		} |
		variable				{  	$$ = $1; 		}
		;

	arithmeticExpression :
		expression ADD expression		{	$$ = makeOperatorNode(1, "+",  $1, $3);	} |
		expression SUB expression		{	$$ = makeOperatorNode(1, "-",  $1, $3);	} |
		expression MUL expression		{	$$ = makeOperatorNode(1, "*",  $1, $3);	} |
		expression DIV expression		{	$$ = makeOperatorNode(1, "/",  $1, $3);	}
		;

	logicalExpression :
		expression SLT expression    	{	$$ = makeOperatorNode(2, "<",  $1, $3);	} |
		expression SGT expression    	{	$$ = makeOperatorNode(2, ">",  $1, $3);	} |
		expression LTE expression    	{	$$ = makeOperatorNode(2, "<=", $1, $3);	} |
		expression GTE expression    	{	$$ = makeOperatorNode(2, ">=", $1, $3);	} |
		expression NEQ expression    	{	$$ = makeOperatorNode(2, "!=", $1, $3);	} |
		expression EQU expression    	{	$$ = makeOperatorNode(2, "==", $1, $3);	}
		;

	constant :
		NUM				{	$$ = makeConstantNode(findTypeTableEntry("int"), $<integer>1, NULL); 	} |
		STRING			{	$$ = makeConstantNode(findTypeTableEntry("string"), 0, $<string>1);		} |
		NULL_TOKEN		{   $$ = makeConstantNode(findTypeTableEntry("void"), 0, NULL);				}
		;

	variable :
		VAR '['expression']'	{	$$ = makeVariableNode($<string>1, $<node>3);	} |
		VAR						{	$$ = makeVariableNode($<string>1, makeConstantNode(findTypeTableEntry("int"), 0, NULL)); } |
		field					{ 	$$ = makeFieldNode($1, makeConstantNode(findTypeTableEntry("int"), 0, NULL)); }
		;

	field : 
		VAR'.'field			{	$$ = makeVariableChain($<string>1, NULL, $3); 			} |
		VAR'.'VAR			{	$$ = makeVariableChain($<string>1, $<string>3, NULL); 	} 
		;

	argList : 
		argList',' expression	{ $$ = makeConnectorNode($<node>1, $<node>3);	} |
		expression				{ $$ = makeConnectorNode(NULL, $<node>1);  		} |
			{}
		;
%%

int getfLabel() {
	return flabel++;
}

void yyerror(char const *s)
{
    printf("yyerror: %s\n",s);
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