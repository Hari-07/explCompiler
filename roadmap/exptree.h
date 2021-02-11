typedef struct value{
	int decimal;
	char* string;
}value;

typedef struct tnode{
 	value val;
 	int nodetype;
	int metatype;
	char* varname;
	char* op;
 	struct tnode *left,*right;
	struct GSymbol* varLocation;
}tnode;

/*
	Nodetype Keys
	-1: Connectors
	1:	Write
	2:	Read
	3:	Constants
		0: Integer
		1: String
	4:	Variable
		0: Integer
		1: String
	5:	Operator
		1:	Arithmetic Expression
		2:	Boolean Expression
	6:	IF Node
	7:	WHILE Node
		0: While Loop
		1: Do While Loop
		2: Repeat Until Loop
	8:	Jump Statements
		0:	Continue
		1: 	Break
*/
tnode* makeConnectorNode(tnode* l, tnode* r);

tnode* makeWriteNode(tnode* source);
tnode* makeReadNode(tnode* target);
tnode* makeConstantNode(int type, char* s);
tnode* makeVariableNode(char* s);
tnode* makeOperatorNode(int meta, char* c, tnode* l, tnode* r);
tnode* makeIfNode(tnode* condn, tnode* trueBody, tnode* falseBody);
tnode* makeWhileNode(int looptype, tnode* condn, tnode* body);
tnode* makeJumpStatement(int type);


/*
	LeafNode types
	0 - Number
	1 - Variable
*/
