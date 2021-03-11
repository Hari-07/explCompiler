#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef EXPTREE_H
#define EXPTREE_H
#include "exptree.h"
#endif

#ifndef SYMBOLS_H
#define SYMBOLS_H
#include "symbol_table.h"
#endif

int INIT_CODE = 0;
int HIGHEST_REGISTER = -1;
int LABEL_COUNTER = -1;
int CURRENT_WHILE_START = -1;
int CURRENT_WHILE_END = -1;
int READ_WRITE_BUFFER = -1;
FILE *target;

char* CURRENT_FUNCTION;

// CODEGEN FUNCTIONS
int codeGen(tnode *t);
int writeNodeCodeGen(tnode *t);
int readNodeCodeGen(tnode *t);
int constantNodeCodeGen(tnode *t);
int variableNodeCodeGen(tnode *t);
int operatorNodeCodeGen(tnode *t);
int ifNodeCodeGen(tnode *t);
int whileNodeCodeGen(tnode *t);
int jumpNodeCodeGen(tnode *t);
int functionCallNodeCodeGen(tnode *t);
int returnNodeCodeGen(tnode *t);

// CODEGEN ABSTRACTIONS
void printFromIndex(int index);
void readToIndex(int index);
int getOffsetGlobalVar(tnode *t);

// HELPER FUNCTIONS
int getReg();
int getActiveRegIndex();
void freeReg();
void setRegIndex();
int getLabel();

void startCodeGen(char* fName, tnode *t)
{
	CURRENT_FUNCTION = (char*) malloc(sizeof(char) * strlen(fName));
	strcpy(CURRENT_FUNCTION, fName);

	if(INIT_CODE == 0){
		target = fopen("output.xsm", "w");
		fprintf(target, "%d\nCALL MAIN\n%d\n%d\n%d\n%d\n%d\n%d\n", 0, 0, 0, 0, 0, 0, 0);
		INIT_CODE = 1;
	}

	if(strcmp(fName, "main") != 0) {
		GSymbol* functionEntry = findGlobalVariable(fName);
		fprintf(target, "FUNCTION%d\n", functionEntry->flabel);
		fprintf(target, "PUSH BP\n");
		fprintf(target, "MOV BP, SP\n");
		Param* param = functionEntry->paramlist;
		LSymbol* temp = getLocalSymbolTableHeader();
		int paramOffset = -3;
		while(param!=NULL) {
			param = param->next;
			temp->binding = paramOffset;
			paramOffset--;
			temp = temp->next;
		}
		while(temp != NULL) {
			fprintf(target, "PUSH BP\n");
			temp = temp->next;
		}
	}
	else {
		fprintf(target, "MAIN\n");
		READ_WRITE_BUFFER = getVarAddress();
		fprintf(target, "MOV SP, %d\n", getVarAddress()+1);
		fprintf(target, "MOV BP, SP\n");
		LSymbol* temp = getLocalSymbolTableHeader();
		while(temp != NULL) {
			fprintf(target, "PUSH BP\n");
			temp = temp->next;
		}
	}
	codeGen(t);

	free(CURRENT_FUNCTION);
	CURRENT_FUNCTION = NULL;
	HIGHEST_REGISTER = -1;
}

int codeGen(tnode *t)
{
	if (t == NULL)
	{
		return 0;
	}

	else if (t->nodetype == -1)
	{
		codeGen(t->left);
		codeGen(t->right);
		return 0;
	}
	else if (t->nodetype == 1)
	{
		return writeNodeCodeGen(t);
	}
	else if (t->nodetype == 2)
	{
		return readNodeCodeGen(t);
	}
	else if (t->nodetype == 3)
	{
		return constantNodeCodeGen(t);
	}
	else if (t->nodetype == 4)
	{
		return variableNodeCodeGen(t);
	}
	else if (t->nodetype == 5)
	{
		return operatorNodeCodeGen(t);
	}
	else if (t->nodetype == 6)
	{
		return ifNodeCodeGen(t);
	}
	else if (t->nodetype == 7)
	{
		return whileNodeCodeGen(t);
	}
	else if (t->nodetype == 8)
	{
		return jumpNodeCodeGen(t);
	}
	else if (t->nodetype == 9)
	{
		return functionCallNodeCodeGen(t);
	}
	else if (t->nodetype == 10)
	{
		return returnNodeCodeGen(t);
	}
	else
	{
		printf("INVALID NODE\n");
		exit(-1);
	}
}

int writeNodeCodeGen(tnode *t)
{
	int p = codeGen(t->left);
	printFromIndex(p);
	freeReg();
	return 0;
}

int readNodeCodeGen(tnode *t)
{
	int q = getReg();
	readToIndex(q);

	GSymbol *var = t->left->varLocation;
	char* varName = var->name;

	LSymbol* localSearch = findLocalVariable(varName);

	if(localSearch != NULL){
		int p = getReg();
		fprintf(target, "MOV R%d, BP\n", p);
		fprintf(target, "ADD R%d, %d\n", p, localSearch->binding);
		fprintf(target, "MOV [R%d], R%d\n", p, q);
		freeReg();
	} else {
		GSymbol* globalSearch = findGlobalVariable(varName);
		int p = getReg();
		int offsetValueRegister = getOffsetGlobalVar(t->left->left);

		fprintf(target, "MOV R%d, %d\n", p, var->address);
		fprintf(target, "ADD R%d, R%d\n", p, offsetValueRegister);
		fprintf(target, "MOV [R%d], R%d\n", p, q);
		freeReg();
		freeReg();
	}
	freeReg();
	return 0;
}

int constantNodeCodeGen(tnode *t)
{
	int p = getReg();
	if (t->metadata == 0)
		fprintf(target, "MOV R%d, %d\n", p, t->val.decimal);
	if (t->metadata == 1)
		fprintf(target, "MOV R%d, %s\n", p, t->val.string);
	return p;
}

int variableNodeCodeGen(tnode *t)
{
	int p = getReg();
	GSymbol *var = t->varLocation;
	char* varName = var->name;

	LSymbol* localSearch = findLocalVariable(varName);

	if(localSearch != NULL){
		fprintf(target, "MOV R%d, BP\n", p);
		fprintf(target, "ADD R%d, %d\n", p, localSearch->binding);
		fprintf(target, "MOV R%d, [R%d]\n", p, p);
	} else {
		GSymbol* globalSearch = findGlobalVariable(varName);
		int offsetValueRegister = getOffsetGlobalVar(t->left);
		fprintf(target, "MOV R%d, %d\n", p, var->address);
		fprintf(target, "ADD R%d, R%d\n", p, offsetValueRegister);
		fprintf(target, "MOV R%d, [R%d]\n", p, p);
		freeReg();
	}
	return p;
}

int operatorNodeCodeGen(tnode *t)
{
	int p, q;
	if (t->metadata == 0)
	{
		GSymbol *var = t->left->varLocation;
		char* varName = var->name;

		p = getReg();
		q = codeGen(t->right);

		LSymbol* localSearch = findLocalVariable(varName);

		if(localSearch != NULL){
			fprintf(target, "MOV R%d, BP\n", p);
			fprintf(target, "ADD R%d, %d\n", p, localSearch->binding);
			fprintf(target, "MOV [R%d], R%d\n", p, q);
		} else {
			GSymbol* globalSearch = findGlobalVariable(varName);
			int offsetValueRegister = getOffsetGlobalVar(t->left->left);
			fprintf(target, "MOV R%d, %d\n", p, var->address);
			fprintf(target, "ADD R%d, R%d\n", p, offsetValueRegister);
			fprintf(target, "MOV [R%d], R%d\n", p, q);
			freeReg();
		}
		freeReg();
		freeReg();
	}
	else
	{
		p = codeGen(t->left);
		q = codeGen(t->right);

		if (strcmp((t->op), "+") == 0)
		{
			fprintf(target, "ADD R%d, R%d\n", p, q);
		}
		else if (strcmp((t->op), "-") == 0)
		{
			fprintf(target, "SUB R%d, R%d\n", p, q);
		}
		else if (strcmp((t->op), "*") == 0)
		{
			fprintf(target, "MUL R%d, R%d\n", p, q);
		}
		else if (strcmp((t->op), "/") == 0)
		{
			fprintf(target, "DIV R%d, R%d\n", p, q);
		}
		else if (strcmp((t->op), "<") == 0)
		{
			fprintf(target, "LT R%d, R%d\n", p, q);
			freeReg();
		}
		else if (strcmp((t->op), ">") == 0)
		{
			fprintf(target, "GT R%d, R%d\n", p, q);
			freeReg();
		}
		else if (strcmp((t->op), "<=") == 0)
		{
			fprintf(target, "LE R%d, R%d\n", p, q);
			freeReg();
		}
		else if (strcmp((t->op), ">=") == 0)
		{
			fprintf(target, "GE R%d, R%d\n", p, q);
			freeReg();
		}
		else if (strcmp((t->op), "!=") == 0)
		{
			fprintf(target, "NE R%d, R%d\n", p, q);
			freeReg();
		}
		else if (strcmp((t->op), "==") == 0)
		{
			fprintf(target, "EQ R%d, R%d\n", p, q);
			freeReg();
		}
		else
		{
			printf("INVALID OPERATION\n");
			exit(-1);
		}

		freeReg();
		return p;
	}
}

int ifNodeCodeGen(tnode *t)
{
	int p = codeGen(t->left);
	int midLabel = getLabel();
	int endLabel = getLabel();

	fprintf(target, "JZ R%d, LABEL%d\n", p, midLabel);
	codeGen(t->right->left);
	fprintf(target, "JMP LABEL%d\n", endLabel);
	fprintf(target, "LABEL%d\n", midLabel);
	codeGen(t->right->right);
	fprintf(target, "LABEL%d\n", endLabel);
}

int whileNodeCodeGen(tnode *t)
{
	int startLabel = getLabel();
	int endLabel = getLabel();
	CURRENT_WHILE_START = startLabel;
	CURRENT_WHILE_END = endLabel;

	fprintf(target, "LABEL%d\n", startLabel);
	if (t->metadata == 0)
	{
		int p = codeGen(t->left);
		fprintf(target, "JZ R%d, LABEL%d\n", p, endLabel);
		codeGen(t->right);
		fprintf(target, "JMP LABEL%d\n", startLabel);
	}
	else if (t->metadata == 1)
	{
		codeGen(t->right);
		int p = codeGen(t->left);
		fprintf(target, "JNZ R%d, LABEL%d\n", p, startLabel);
	}
	else if (t->metadata == 2)
	{
		codeGen(t->right);
		int p = codeGen(t->left);
		fprintf(target, "JZ R%d, LABEL%d\n", p, startLabel);
	}
	else
	{
		printf("UNEXPECTED WHILE NODE\n");
		exit(-1);
	}
	fprintf(target, "LABEL%d\n", endLabel);

	CURRENT_WHILE_START = -1;
	CURRENT_WHILE_END = -1;
}

int jumpNodeCodeGen(tnode *t)
{
	if (CURRENT_WHILE_START != -1)
	{
		if (t->metadata == 0)
		{
			fprintf(target, "JMP LABEL%d\n", CURRENT_WHILE_START);
		}
		else if (t->metadata == 1)
		{
			fprintf(target, "JMP LABEL%d\n", CURRENT_WHILE_END);
		}
	}
}

int functionCallNodeCodeGen(tnode *t)
{
	int state_reg_count = getActiveRegIndex();

	for(int i = state_reg_count; i >= 0; i--){
		fprintf(target, "PUSH R%d\n", i);
	}

	for(tnode* arg = t->right; arg != NULL; arg = arg->left){
		int argValue = codeGen(arg->right);
		fprintf(target, "PUSH R%d\n", argValue);
		freeReg();
	}

	fprintf(target, "PUSH R0\n");
	setRegIndex(-1);
	
	fprintf(target, "CALL FUNCTION%d\n", t->val.decimal);
	
	setRegIndex(state_reg_count);
	int result = getReg();

	fprintf(target, "POP R%d\n", result);

	int buffer = getReg();
	for(tnode* arg = t->right; arg != NULL; arg = arg->left){
		fprintf(target, "POP R%d\n", buffer);
	}
	freeReg();

	for(int i = 0; i <= state_reg_count; i++){
		fprintf(target, "POP R%d\n", i);
	}
}

int returnNodeCodeGen(tnode* t) {

	if(strcmp(CURRENT_FUNCTION, "main") == 0) {
		fprintf(target, "INT 10\n");
	}
	else {
		LSymbol* temp = getLocalSymbolTableHeader();
		GSymbol* functionEntry = findGlobalVariable(CURRENT_FUNCTION);
		Param* param = functionEntry->paramlist;
		
		while(param!=NULL) {
			param = param->next;
			temp = temp->next;
		}
		while(temp != NULL) {
			fprintf(target, "POP R0\n");
			temp = temp->next;
		}

		int p = codeGen(t->right);
		int q = getReg();
		fprintf(target, "MOV R%d, BP\n", q);
		fprintf(target, "ADD R%d, -2\n", q);
		fprintf(target, "MOV [R%d], R%d\n", q, p);
		fprintf(target, "MOV BP, [BP]\n");
		fprintf(target, "POP R0\n");
		fprintf(target, "RET\n");
		freeReg();
		freeReg();
	}
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
	fprintf(target, "MOV R%d, %d\n", p, READ_WRITE_BUFFER);
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
	fprintf(target, "MOV R%d, [%d]\n", index, READ_WRITE_BUFFER);
}

int getOffsetGlobalVar(tnode *t)
{
	int p = getReg();
	if (t->nodetype == 3)
	{
		fprintf(target, "MOV R%d, %d\n", p, t->val.decimal);
	}
	else if (t->nodetype == 4)
	{
		GSymbol *var = t->varLocation;
		int offsetValueRegister = getOffsetGlobalVar(t->left);
		fprintf(target, "MOV R%d, %d\n", p, var->address);
		fprintf(target, "ADD R%d, R%d\n", p, offsetValueRegister);
		fprintf(target, "MOV R%d, [R%d]\n", p, p);
		freeReg();
	}
	return p;
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

int getActiveRegIndex()
{
	return HIGHEST_REGISTER;
}

int getLabel()
{
	return ++LABEL_COUNTER;
}

void freeReg()
{
	--HIGHEST_REGISTER;
}

void setRegIndex(int index)
{
	HIGHEST_REGISTER = index;
}