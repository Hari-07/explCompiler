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

void checkInputConditions(tnode* t);
void checkOutputConditions(tnode* t);
void checkVariableConditions(tnode* t);
void checkOperatorConditions(int meta, tnode*l, tnode* r);
void checkConditionalValidity(tnode* condn);

tnode* createNode(){
	tnode* temp = (tnode*)malloc(sizeof(tnode));
	temp -> val.decimal = 0;
	temp -> val.string = "";

	temp -> nodetype = 0;
	temp -> metadata = 0;
	temp -> op = NULL;
	temp -> left = NULL;
	temp -> right = NULL;
	temp -> varLocation = NULL;

	return temp;
}

tnode *makeConnectorNode(tnode *l, tnode *r)
{
	tnode *temp = createNode();
	temp->left = l;
	temp->right = r;
	temp->nodetype = -1;
	return temp;
}

tnode *makeReadNode(tnode *target)
{
	checkInputConditions(target);

	tnode* temp = createNode();
	temp->nodetype = 2;
	temp->left = target;
	temp->right = NULL;
	return temp;
}

tnode *makeWriteNode(tnode *source)
{	
	checkOutputConditions(source);

	tnode *temp = createNode();
	temp->nodetype = 1;
	temp->left = source;
	temp->right = NULL;
	return temp;
}

tnode *makeConstantNode(int type, int number, char *s)
{
	tnode* temp = createNode();
	temp->nodetype = 3;
	temp->metadata = type;
	if(type == 0)
		temp->val.decimal = number;
	else {
		temp->val.string = (char*)malloc(sizeof(char)*strlen(s));
		strcpy(temp->val.string, s);
	}
	return temp;
}

tnode *makeVariableNode(char *s, tnode* offset)
{
	checkVariableConditions(offset);

	tnode *temp = createNode();
	temp->nodetype = 4;

	LSymbol* tempRes = findLocalVariable(s);
	if(tempRes != NULL){
		temp->varLocation = (LSymbol*)findLocalVariable(s);
	} else {
		temp->varLocation = (GSymbol*)findGlobalVariable(s); 
	}

	temp->left = offset;
	temp->right = NULL;
	return temp;
}

tnode *makeOperatorNode(int meta, char *op, tnode *l, tnode *r)
{
	checkOperatorConditions(meta, l, r);

	tnode *temp = createNode();
	temp->nodetype = 5;
	temp->metadata = meta;
	temp->op = op;
	temp->left = l;
	temp->right = r;
	return temp;
}

tnode *makeIfNode(tnode *condn, tnode *trueBody, tnode *falseBody)
{
	checkConditionalValidity(condn);

	tnode *temp = createNode();
	temp->nodetype = 6;
	temp->left = condn;
	temp->right = makeConnectorNode(trueBody, falseBody);
	return temp;
};

tnode *makeWhileNode(int looptype, tnode *condn, tnode *body)
{
	checkConditionalValidity(condn);
		
	tnode *temp = createNode();
	temp->nodetype = 7;
	temp->metadata = looptype;
	temp->left = condn;
	temp->right = body;
	return temp;
}

tnode* makeJumpStatement(int type) {
	tnode* temp = createNode();
	temp-> nodetype = 8;
	temp-> metadata = type;
}

tnode* makeFunctionCallNode(char* fName, tnode* arg) {
	
	tnode* iterator = arg;
	Param* param = findGlobalVariable(fName)->paramlist;
	
	while(iterator != NULL){
		if(param == NULL){
			printf("INVALID FUNCTION CALL");
			exit(-1);
		}

		tnode* temp = iterator->right;
		if(temp->nodetype == 3 || temp->nodetype == 4){
			if(param->type != temp->metadata){
				printf("INVALID FUNCTION CALL");
				exit(-1);
			}
		}
		else if(temp->nodetype == 5){
			if(temp->metadata != 1 || param->type != 0){
				printf("INVALID FUNCTION CALL");
				exit(-1);
			}
		}
		iterator = iterator->left;
		param = param->next;
	}

	if(param != NULL){
		printf("INVALID FUNCTION CALL");
		exit(-1);
	}

	return makeConnectorNode(NULL, NULL);
}

/*
Input Conditions:
- Can only read to variable
*/
void checkInputConditions(tnode* t){
	if(t->nodetype == 4){
		return;
	} else {
		printf("INVALID READ STATEMENT");
		exit(-1);
	}
}

/*
Output Conditions:
- Can Output Constants
- Can Output Variable
- Can Output Arithmetic expression
*/
void checkOutputConditions(tnode* t){
	if(t->nodetype == 3) {
		return;
	} else if (t->nodetype == 4) {
		return;
	} else if (t->nodetype == 5 && t->metadata == 1) {
		return;
	} else {
		printf("INVALID WRITE STATEMENT");
		exit(-1);
	}
}

/*
Variable Conditions:
- Offset must be constant or variable of type integer
*/
void checkVariableConditions(tnode* t){
	if((t->nodetype != 3 && t->nodetype != 4) || t->metadata!= 0){
		printf("ILLEGAL OFFSET\n");
		exit(-1);
	}
}

/*
Operator Conditions:
- LHS of assignment should be a variable
- LHS, RHS of assignment should be of same type
- LHS, RHS of boolean expression should be integer variable/constant
- LHS, RHS of arithmetic expression should be integer variable/constants/arithmetic expressions
*/
void checkOperatorConditions(int meta, tnode*l, tnode* r){
	if(meta == 0){
		if(l->nodetype != 4) {
			printf("Can only assign to a variable");
			exit(-1);
		}
		else if(r->nodetype != 3 && r->nodetype != 4 && r->nodetype != 5){
			printf("Invalid Assignment Statement");
			exit(-1);
		}
		else if(r->nodetype == 5 && r->metadata != 1){
			printf("Invalid Assignment Statement");
			exit(-1);
		}
		else if((l->metadata != r->metadata) && (l->metadata != 0 && r->nodetype == 5)){
			printf("Type Mismatch in Assignment Statement");
			exit(-1);
		}
	} else if(meta == 1){
		if((l->nodetype != 3 && l->nodetype != 4 && l->nodetype != 5) ||
		   (r->nodetype != 3 && r->nodetype != 4 && r->nodetype != 5)
		) {
			printf("Invalid Expression");
			exit(-1);
		}
		else if((l->nodetype != 5 && l->metadata != 0) ||
				(r->nodetype != 5 && r->metadata != 0)
		) {
			printf("Invalid Arithmetic Expresson");
			exit(-1);
		} else if((l->nodetype == 5 && l->metadata != 1) || (r->nodetype==5 && r->metadata != 1)) {
			printf("Invalid Arithmetic Expresson");
			exit(-1);
		} 
	} else if(meta == 2){
		if((l->nodetype != 3 && l->nodetype != 4) ||
		   (r->nodetype != 3 && r->nodetype != 4)
		) {
			printf("Invalid Expression");
			exit(-1);
		}
		else if(l->metadata != 0 || r->metadata != 0) {
			printf("Invalid comparsion");
			exit(-1);
		}
	}
}

void checkConditionalValidity(tnode* condn){
	if(condn -> nodetype == 5 && condn->metadata == 2) {
		return;
	}
	
	printf("INVALID CONDITION EXPRESSION");
	exit(-1);
}