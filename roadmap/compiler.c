#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef DATA_H
#define DATA_H
#include "data.h"
#endif

int HIGHEST_REGISTER = -1;
int LABEL_COUNTER = -1;
FILE *target;

// CODEGEN FUNCTIONS
int codeGen(tnode *t);
int writeNodeCodeGen(tnode *t);
int readNodeCodeGen(tnode *t);
int numberNodeCodeGen(tnode *t);
int variableNodeCodeGen(tnode *t);
int operatorNodeCodeGen(tnode *t);
int ifNodeCodeGen(tnode *t);
int whileNodeCodeGen(tnode *t);

// CODEGEN ABSTRACTIONS
void printFromIndex(int index);
void readToIndex(int index);

// HELPER FUNCTIONS
int getReg();
void freeReg();
int getLabel();


void starter(tnode *t)
{
	target = fopen("output.xsm", "w");
	fprintf(target, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 0, 2056, 0, 0, 0, 0, 0, 0);
	fprintf(target, "MOV SP, 4123\n");
	codeGen(t);
	fprintf(target, "INT 10\n");
}

int codeGen(tnode *t)
{
	if (t == NULL)
	{
		return 0;
	}

	if (t->nodetype == -1)
	{
		codeGen(t->left);
		codeGen(t->right);
		return 0;
	} else if (t->nodetype == 1) {
		return writeNodeCodeGen(t);
	} else if (t->nodetype == 2) {
		return readNodeCodeGen(t);
	} else if (t->nodetype == 3) {
		return numberNodeCodeGen(t);
	} else if (t->nodetype == 4) {
		return variableNodeCodeGen(t);
	} else if (t->nodetype == 5) {
		return operatorNodeCodeGen(t);
	} else if (t->nodetype == 6) {
		return ifNodeCodeGen(t);
	} else if (t->nodetype == 7) {
		return whileNodeCodeGen(t);
	} else {
		printf("INVALID NODE\n");
		exit(-1);
	}
}

int writeNodeCodeGen(tnode *t)
{
	int p = codeGen(t->left);
	printFromIndex(p);
	return 0;
}

int readNodeCodeGen(tnode *t)
{
	int q = getReg();
	readToIndex(q);
	int p;

	if (t->left->nodetype != 4)
	{
		printf("INVALID WRITE STATEMENT\n");
		exit(-1);
	}
	else
	{
		p = 4096 + *(t->left->varname) - 'a';
	}
	fprintf(target, "MOV [%d], R%d\n", p, q);
	freeReg();
	return 0;
}

int numberNodeCodeGen(tnode *t)
{
	int p = getReg();
	fprintf(target, "MOV R%d, %d\n", p, t->val);
	return p;
}

int variableNodeCodeGen(tnode *t)
{
	int p = getReg();
	fprintf(target, "MOV R%d, [%d]\n", p, 4096 + (*(t->varname) - 'a'));
	return p;
}

int operatorNodeCodeGen(tnode *t)
{
	int p = codeGen(t->left);
	int q = codeGen(t->right);

	if (strcmp((t->op),"+") == 0)
	{
		fprintf(target, "ADD R%d, R%d\n", p, q);
	}
	else if (strcmp((t->op),"-") == 0)
	{
		fprintf(target, "SUB R%d, R%d\n", p, q);
	}
	else if (strcmp((t->op),"*") == 0)
	{
		fprintf(target, "MUL R%d, R%d\n", p, q);
	}
	else if (strcmp((t->op),"/") == 0)
	{
		fprintf(target, "DIV R%d, R%d\n", p, q);
	}
	else if (strcmp((t->op),"=") == 0)
	{
		int p = 4096 + (*(t->left->varname) - 'a');
		fprintf(target, "MOV [%d], R%d\n", p, q);
	}
	else if (strcmp((t->op),"<") == 0)
	{
		fprintf(target, "LT R%d, R%d\n", p, q);
		freeReg();
	}
	else if (strcmp((t->op),">") == 0)
	{
		fprintf(target, "GT R%d, R%d\n", p, q);
		freeReg();
	}
	else if (strcmp((t->op),"<=") == 0)
	{
		fprintf(target, "LE R%d, R%d\n", p, q);
		freeReg();
	}
	else if (strcmp((t->op),">=") == 0)
	{
		fprintf(target, "GE R%d, R%d\n", p, q);
		freeReg();
	}
	else if (strcmp((t->op),"!=") == 0)
	{
		fprintf(target, "NE R%d, R%d\n", p, q);
		freeReg();
	}
	else if (strcmp((t->op),"==") == 0)
	{
		fprintf(target, "EQ R%d, R%d\n", p, q);
		freeReg();
	}
	else {
		printf("INVALID OPERATION\n");
		exit(-1);
	}

	freeReg();
	return p;
}

int ifNodeCodeGen(tnode *t) {
	int p = codeGen(t->left);
	int l1 = getLabel();
	int l2 = getLabel();

	fprintf(target, "JZ R%d, LABEL%d\n", p, l1);
	codeGen(t->right->left);
	fprintf(target, "JMP LABEL%d\n", l2);
	fprintf(target, "LABEL%d\n", l1);
	codeGen(t->right->right);
	fprintf(target, "LABEL%d\n", l2);
}

int whileNodeCodeGen(tnode *t) {
	int l1 = getLabel();
	int l2 = getLabel();

	fprintf(target, "LABEL%d\n", l1);
	int p = codeGen(t->left);
	fprintf(target, "JZ R%d, LABEL%d\n", p, l2);
	codeGen(t->right);
	fprintf(target, "JMP LABEL%d\n", l1);
	fprintf(target, "LABEL%d\n", l2);
}

void printFromIndex(int index)
{
	int p = getReg();
	fprintf(target, "MOV R%d, \"Write\"\n", p);
	fprintf(target, "PUSH R%d\n", p);
	fprintf(target, "MOV R%d, -2\n", p);
	fprintf(target, "PUSH R%d\n", p);
	fprintf(target, "MOV R%d, R%d\n", p, index);
	fprintf(target, "PUSH R%d\n", p);
	fprintf(target, "PUSH R%d\n", p);
	fprintf(target, "PUSH R%d\n", p);
	fprintf(target, "CALL 0\n");
	fprintf(target, "POP R%d\n", p);
	fprintf(target, "POP R%d\n", p);
	fprintf(target, "POP R%d\n", p);
	fprintf(target, "POP R%d\n", p);
	fprintf(target, "POP R%d\n", p);
	freeReg();
}

void readToIndex(int index)
{
	int p = getReg();
	fprintf(target, "MOV R%d, \"Read\"\n", p);
	fprintf(target, "PUSH R%d\n", p);
	fprintf(target, "MOV R%d, -1\n", p);
	fprintf(target, "PUSH R%d\n", p);
	fprintf(target, "MOV R%d, 4122\n", p);
	fprintf(target, "PUSH R%d\n", p);
	fprintf(target, "PUSH R%d\n", p);
	fprintf(target, "PUSH R%d\n", p);
	fprintf(target, "CALL 0\n");
	fprintf(target, "POP R%d\n", p);
	fprintf(target, "POP R%d\n", p);
	fprintf(target, "POP R%d\n", p);
	fprintf(target, "POP R%d\n", p);
	fprintf(target, "POP R%d\n", p);
	freeReg();
	fprintf(target, "MOV R%d, [4122]\n", index);
}

int getReg()
{
	if (HIGHEST_REGISTER == 19)
	{
		printf("No More Registers Available\nTERMINATING\n");
		exit(2);
	}

	return ++HIGHEST_REGISTER;
}

int getLabel()
{
	return ++LABEL_COUNTER;
}

void freeReg()
{
	--HIGHEST_REGISTER;
}