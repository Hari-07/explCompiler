typedef struct tnode{
 	int val;
 	int nodetype;
	int metatype;
	char* varname;
	char* op;
 	struct tnode *left,*right;
}tnode;

/*
	nodetype keys
	-1 : Connectors
	1 : Write
	2 : Read
	3 : Number
	4 : Variable
	5 : Operator
		1 : Arithmetic Expression
		2 : Boolean Expression
	6 : IF Node
	7 : WHILE Node
*/
tnode* makeConnectorNode(tnode* l, tnode* r);

tnode* makeWriteNode(tnode* source);
tnode* makeReadNode(tnode* target);
tnode* makeLeafNode(int type, char* s);
tnode* makeOperatorNode(int meta, char* c, tnode* l, tnode* r);
tnode* makeIfNode(tnode* condn, tnode* trueBody, tnode* falseBody);
tnode* makeWhileNode(tnode* condn, tnode* body);

/*
	LeafNode types
	0 - Number
	1 - Variable
*/
