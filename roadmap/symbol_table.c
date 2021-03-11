#include<stdio.h>
#include<string.h>

#ifndef SYMBOLS_H
#define SYMBOLS_H
#include "symbol_table.h"
#endif

GSymbol *head = NULL;
LSymbol* headLocal = NULL;
int LOCAL_ADDRESS = 1;
int VAR_ADDRESS = 4096;

void addGlobalVariable(char* name, int type, int size, int flabel, Param* paramList){
	GSymbol* temp = head;
	while(temp){
		if(strcmp(temp->name, name) == 0){
			printf("MULTIPLE DECLARATION\n");
			exit(-1);
		}
		temp = temp->next;
	}

	temp = (GSymbol*)malloc(sizeof(GSymbol));
	temp->name = name;
	temp->type = type;
	temp->size = size;
	temp->flabel = flabel;
	temp->paramlist = paramList;
	temp->address = VAR_ADDRESS;
	VAR_ADDRESS += size;
	temp->next = head;
	head = temp;
}


void addLocalVariable (char* name, int type) {
	LSymbol* temp = headLocal;
	while(temp){
		if(strcmp(temp->name, name) == 0){
			printf("MULTIPLE DECLARATION\n");
			exit(-1);
		}
		temp = temp->next;
	}

	temp = (LSymbol*)malloc(sizeof(LSymbol));
	temp->name = name;
	temp->type = type;
	temp->binding = LOCAL_ADDRESS++;
	temp->next = headLocal;
	headLocal = temp;
}

int checkNameEquivalence(Param* params, char* fname) {
	GSymbol* temp = findGlobalVariable(fname);
	Param* definedparams = temp->paramlist;

	while(definedparams != NULL && params != NULL){
		if(strcmp(definedparams->name, params->name) != 0 || definedparams->type != params->type) {
			return 0;
		} else {
			definedparams = definedparams->next;
			params = params->next;
		}
	}

	if(definedparams != NULL || params != NULL)
		return 0;

	return 1;
}

void addParamstoLSymbol(Param* param) {
	while(param != NULL){
		addLocalVariable(param->name, param->type);
		param = param->next;
	}
}

struct GSymbol* findGlobalVariable(char* name){
	GSymbol* temp = head;
	while(temp){
		if(strcmp(temp->name, name) == 0){
			return temp;
		}
		temp = temp->next;
	}
	printf("UNDECLARED VARIABLE: %s\n", name);
	exit(-1);
}

struct LSymbol* findLocalVariable(char* name){
	LSymbol* temp = headLocal;
	while(temp){
		if(strcmp(temp->name, name) == 0){
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}



Param* createParameter(char *name, int type) {
	Param* temp = (Param*)malloc(sizeof(Param));

	temp->name = (char*)malloc(strlen(name)*sizeof(char));
	strcpy(temp->name,name);
	temp->type = type;
	temp->next = NULL;

	return temp;
}

Param* addParameter(Param* next, Param* paramNode) {
	paramNode->next = next;
	return paramNode;
}

LSymbol* getLocalSymbolTableHeader(){
	return headLocal;
}

int getVarAddress(){
	return VAR_ADDRESS;
}

void terminateFunction(){
	free(headLocal);
	headLocal = NULL;
	LOCAL_ADDRESS = 1;
}

void test(){
	printf("HELLO");
}