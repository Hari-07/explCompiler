#include<stdlib.h>
#include<stdio.h>

#ifndef DATA_H
#define DATA_H
#include"data.h"
#endif

int HIGHEST_REGISTER = -1;
FILE* target;

int codeGen(tnode* t);
int getReg();
void freeReg();
void codePrintFromStack();

void starter(tnode* t){
	target = fopen("output.xsm","w");
	fprintf(target, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 0, 2056, 0, 0, 0, 0, 0, 0);
	int result = codeGen(t);
	fprintf(target, "PUSH R%d\n", result);
	codePrintFromStack();
}


int codeGen(tnode* t) {
	if(t->val){
		int p = getReg();
		fprintf(target, "MOV R%d, %d\n", p, t->val);
		return p;
	}
	else {
		int p = codeGen(t->left);
		int q = codeGen(t->right);

		if(t -> op == '+') {
			fprintf(target, "ADD R%d, R%d\n", p, q);
		}
		else if(t -> op == '-') {
			fprintf(target, "SUB R%d, R%d\n", p, q);
		}
		else if(t -> op == '*') {
			fprintf(target, "MUL R%d, R%d\n", p, q);
		}
		else if(t -> op == '/') {
			fprintf(target, "DIV R%d, R%d\n", p, q);
		}

		freeReg();
		return p;
	}
}

void codePrintFromStack() {
	int p = getReg();
	fprintf(target, "MOV R%d, \"Write\"\n", p);
	fprintf(target, "PUSH R%d\n", p);
	fprintf(target, "MOV R%d, -2\n", p);
	fprintf(target, "PUSH R%d\n", p);
	fprintf(target, "MOV R%d, [4096]\n", p);
	fprintf(target, "PUSH R%d\n", p);
	fprintf(target, "PUSH R%d\n", p);
	fprintf(target, "PUSH R%d\n", p);
	fprintf(target, "CALL 0\n");
	fprintf(target, "POP R%d\n",p);
	fprintf(target, "POP R%d\n",p);
	fprintf(target, "POP R%d\n",p);
	fprintf(target, "POP R%d\n",p);
	fprintf(target, "POP R%d\n",p);
	fprintf(target, "INT 10\n");
}

int getReg() {
	if(HIGHEST_REGISTER == 19){
		printf("No More Registers Available\nTERMINATING\n");
		exit(2);
	}

	return ++HIGHEST_REGISTER;
}

void freeReg() {
	--HIGHEST_REGISTER;
}