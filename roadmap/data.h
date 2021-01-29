typedef struct tnode{
 	int val;
 	int nodetype;
	char* varname;
	char op;
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
*/
tnode* createTreeNode(tnode* l, tnode* r);

tnode* makeReadNode(tnode* target);
tnode* makeWriteNode(tnode* source);

tnode* makeLeafNode(int type, char* s);
/*
	leafNode types
	0 - Number
	1 - Variable
*/

tnode* makeOperatorNode(char c, tnode* l, tnode* r);