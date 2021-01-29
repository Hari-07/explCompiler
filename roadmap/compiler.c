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
void printFromIndex(int index);
void readToIndex(int index);

void starter(tnode* t){
	target = fopen("output.xsm","w");
	fprintf(target, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 0, 2056, 0, 0, 0, 0, 0, 0);
	fprintf(target, "MOV SP, 4123\n");
	codeGen(t);
	fprintf(target, "INT 10\n");
}


int codeGen(tnode* t) {
	if(t == NULL){
		return 0;
	}
	if(t -> nodetype == - 1) {
		codeGen(t -> left);
		codeGen(t -> right);
		return 0;	
	}
	else if(t -> nodetype == 1) {
		int p = codeGen(t -> left);
		printFromIndex(p);
		return 0;
	}
	else if(t -> nodetype == 2) {
		int q = getReg();
		readToIndex(q);
		int p;

		if(t -> left -> nodetype != 4) {
			printf("INVALID WRITE STATEMENT\n");
			exit(-1);
		} else {
			p = 4096 + *(t -> left ->varname) - 'a';
		}
		fprintf(target, "MOV [%d], R%d\n", p, q);
		freeReg();
		return 0;
	}
	else if(t -> nodetype == 3){
		int p = getReg();
		fprintf(target, "MOV R%d, %d\n", p, t->val);
		return p;
	}
	else if(t -> nodetype == 4) {
		int p = getReg();
		fprintf(target, "MOV R%d, [%d]\n", p, 4096 + (*(t -> varname) - 'a'));
		return p;
	}
	else if(t -> nodetype == 5) {
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
		} else if(t -> op =='=') {
			int p;
			if(t -> left -> nodetype != 4) {
				printf("INVALID ASSINGMENT\n");
				exit(-1);
			} else {
				p = 4096 + (*(t -> left ->varname) - 'a');
			}
			fprintf(target, "MOV [%d], R%d\n", p, q);
		}

		freeReg();
		return p;
	}
	else {
		printf("INVALID NODE\n");
		exit(-1);
	}
}

void printFromIndex(int index) {
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
	fprintf(target, "POP R%d\n",p);
	fprintf(target, "POP R%d\n",p);
	fprintf(target, "POP R%d\n",p);
	fprintf(target, "POP R%d\n",p);
	fprintf(target, "POP R%d\n",p);
	freeReg();
}

void readToIndex(int index) {
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
	fprintf(target, "POP R%d\n",p);
	fprintf(target, "POP R%d\n",p);
	fprintf(target, "POP R%d\n",p);
	fprintf(target, "POP R%d\n",p);
	fprintf(target, "POP R%d\n",p);
	freeReg();
	fprintf(target, "MOV R%d, [4122]\n", index);
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