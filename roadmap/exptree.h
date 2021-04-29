#ifndef TYPES_H
#define TYPES_H
#include "type_table.h"
#endif

#ifndef CLASS_H
#define CLASS_H
#include "class_table.h"
#endif

typedef struct value{
	int decimal;
	char* string;
}value;

enum nodeType {
	newNode,
	connectorNode,
	readNode,
	writeNode,
	constantNode,
	variableNode,
	operatorNode,
	ifNode,
	whileNode,
	jumpNode,
	functionCallNode,
	methodCallNode,
	functionReturnNode,
	fieldNode,
	allocNode,
	deAllocNode,
	constructorNode,
	breakNode,
};

/*
	Nodetype Keys
	-1: Connectors
	1:	Write
	2:	Read
	3:	Constants
	- 0: Integer
	- 1: String
	4:	Variable
	- 0: Integer
	- 1: String
	5:	Operator
	- 0: Assignment
	- 1: Arithmetic Expression
	- 2: Boolean Expression
	6:	IF Node
	7:	WHILE Node
	- 0: While Loop
	- 1: Do While Loop
	- 2: Repeat Until Loop
	8:	Jump Statements
	- 0: Continue
	- 1: Break
	9: Function Call
	- 0: Returns Integer
	- 1: Returns String
	10: Function Return Statement
	- 0: Return Integer
	- 1: Returns String
	11: Field Node
*/
typedef struct tnode{
 	value val;
 	enum nodeType nodeType;
	int metadata;
	struct TypetableNode* type;
	struct FieldlistNode* fieldChain;
	struct ClassTableNode* classRef;
	char* op;
 	struct tnode *left,*right;
	void* varLocation; //Points to SYMBOL TABLE ENTRY
}tnode;

tnode* makeConnectorNode(tnode* l, tnode* r);

tnode* makeWriteNode(tnode* source);
tnode* makeReadNode(tnode* target);
tnode* makeAllocNode(tnode* target);
tnode* makeDeAllocNode(tnode* target);

tnode* makeConstantNode(TypetableNode* type, int number, char *s);
tnode* makeVariableNode(char *s, tnode* offset);
tnode* makeOperatorNode(int meta, char* op, tnode* l, tnode* r);
tnode* makeIfNode(tnode* condn, tnode* trueBody, tnode* falseBody);
tnode* makeWhileNode(int looptype, tnode* condn, tnode* body);
tnode* makeJumpStatement(int type);
tnode* makeFunctionCallNode(char* fName, tnode* arg);
tnode* makeClassMethodCallNode(FieldlistNode* fieldChain, tnode* arg);
tnode* makeClassConstructorNode(tnode* l, char* className);
tnode* makeReturnNode(tnode* r);
tnode* makeBreakPointNode();


FieldlistNode* makeVariableChain(char* parentFieldName, char* childFieldName, FieldlistNode* childFieldNode);
tnode* makeFieldNode(FieldlistNode* variableChain, tnode* offset);