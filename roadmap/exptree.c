#include <stdlib.h>
#include <string.h>

#ifndef EXPTREE_H
#define EXPTREE_H
#include "exptree.h"
#endif

#ifndef SYMBOLS_H
#define SYMBOLS_H
#include "symbol_table.h"
#endif

tnode *makeConnectorNode(tnode *l, tnode *r)
{
	tnode *temp;
	temp = (tnode *)malloc(sizeof(tnode));
	temp->left = l;
	temp->right = r;
	temp->nodetype = -1;
	return temp;
}

tnode *makeReadNode(tnode *target)
{
	tnode *temp;

	if(target -> nodetype == 4){
		temp = (tnode *)malloc(sizeof(tnode));
		temp->nodetype = 2;
		temp->left = target;
		temp->right = NULL;
	} else {
		printf("CAN ONLY READ TO A VARIABLE \n");
		exit(-1);
	}
}

tnode *makeWriteNode(tnode *source)
{
	if((source -> nodetype == 5 && source->metatype == 1) || (source->nodetype == 4) || (source->nodetype == 3)) {
		tnode *temp;
		temp = (tnode *)malloc(sizeof(tnode));
		temp->nodetype = 1;
		temp->left = source;
		temp->right = NULL;
	} else {
		printf("ILLEGAL WRITE STATEMENT\n");
		exit(-1);
	}
}

tnode *makeConstantNode(int type, char *s)
{
	tnode *temp;
	temp = (tnode *)malloc(sizeof(tnode));
	temp->nodetype = 3;
	temp->metatype = type;
	if(temp->metatype == 0)
		temp->val.decimal = atoi(s);
	else {
		temp->val.string = (char*)malloc(sizeof(char)*strlen(s));
		strcpy(temp->val.string, s);
	}
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

tnode *makeVariableNode(char *s)
{
	tnode *temp;
	temp = (tnode *)malloc(sizeof(tnode));
	temp->nodetype = 4;
	temp->varLocation = findVariable(s);
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

tnode *makeOperatorNode(int meta, char *c, tnode *l, tnode *r)
{
	if(strcmp(c, "=") == 0){
		if((l->nodetype != 4) || (r->nodetype !=3 && r->nodetype != 4 && r->nodetype != 5) || (r->nodetype == 5 && r->metatype != 1)) {
			printf("ILLEGAL ASSINGMENT OPERATION\n");
			exit(-1);
		}
	} else if(meta == 2) {
		if((l->nodetype != 3 && l->nodetype != 4 && l->nodetype != 5) || (r->nodetype != 3 && r->nodetype != 4 && r->nodetype != 5)) {
			printf("INCORRECT COMPARISON OPERATION\n");
			exit(-1);
		}
	} else {
		if((l->nodetype == 5 && r->nodetype == 5 && (l->metatype != 4 || r->metatype !=4))) {
			printf("CANNOT MIX BOOLEAN EXPRESSION WITH ARITHMETIC EXPRESSION\n");
			exit(-1);
		}
	}

	tnode *temp;
	temp = (tnode *)malloc(sizeof(tnode));
	temp->op = c;
	temp->left = l;
	temp->right = r;
	temp->nodetype = 5;
	temp->metatype = meta;
	return temp;
}

tnode *makeIfNode(tnode *condn, tnode *trueBody, tnode *falseBody)
{
	if(condn -> nodetype == 5 && condn->metatype == 2) {
		tnode *temp;
		temp = (tnode *)malloc(sizeof(tnode));
		temp->nodetype = 6;
		temp->left = condn;
		temp->right = makeConnectorNode(trueBody, falseBody);
		return temp;
	} else {
		printf("ILLEGAL CONDITION STATEMENT\n");
		exit(-1);
	}
};

tnode *makeWhileNode(int looptype, tnode *condn, tnode *body)
{
	if(condn -> nodetype == 5 && condn->metatype == 2) {
		tnode *temp;
		temp = (tnode *)malloc(sizeof(tnode));
		temp->nodetype = 7;
		temp->left = condn;
		temp->right = body;
		temp->metatype = looptype;
	} else {
		printf("ILLEGAL CONDITION STATEMENT\n");
		exit(-1);
	}
}

tnode* makeJumpStatement(int type) {
	tnode* temp;
	temp = (tnode*)malloc(sizeof(tnode));
	temp-> nodetype = 8;
	temp-> left = NULL;
	temp-> right = NULL; 
	temp-> metatype = type;
}