#include <stdlib.h>

#ifndef DATA_H
#define DATA_H
#include "data.h"
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
	temp = (tnode *)malloc(sizeof(tnode));
	temp->nodetype = 2;
	temp->left = target;
	temp->right = NULL;
}

tnode *makeWriteNode(tnode *source)
{
	tnode *temp;
	temp = (tnode *)malloc(sizeof(tnode));
	temp->nodetype = 1;
	temp->left = source;
	temp->right = NULL;
}

tnode *makeLeafNode(int type, char *s)
{
	tnode *temp;
	temp = (tnode *)malloc(sizeof(tnode));
	if (type == 0)
	{
		temp->val = atoi(s);
		temp->nodetype = 3;
	}
	else if (type == 1)
	{
		temp->varname = s;
		temp->nodetype = 4;
	}
	else
	{
		printf("ILLEGAL NODE CREATION REQUEST\n");
		exit(3);
	}
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

tnode *makeOperatorNode(int meta, char *c, tnode *l, tnode *r)
{
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
	tnode *temp;
	temp = (tnode *)malloc(sizeof(tnode));
	temp->nodetype = 6;
	temp->left = condn;
	temp->right = makeConnectorNode(trueBody, falseBody);
	return temp;
};

tnode *makeWhileNode(tnode *condn, tnode *body)
{
	tnode *temp;
	temp = (tnode *)malloc(sizeof(tnode));
	temp->nodetype = 7;
	temp->left = condn;
	temp->right = body;
}

// IMPLEMENT CHECKING OF NODES INCLUDING ASSIGNMENT STATEMENT