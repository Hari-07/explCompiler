#include<stdio.h>
#include<string.h>

#ifndef SYMBOLS_H
#define SYMBOLS_H
#include "symbol_table.h"
#endif

GSymbol *globalSymbolTableHead = NULL;
LSymbol* localSymbolTableHead = NULL;
int LOCAL_ADDRESS = 1;
int VAR_ADDRESS = 4097;

void addGlobalVariable(char* name, char* typeString, int size, int flabel, Param* paramList){
	TypetableNode* type = findTypeTableEntry(typeString);
	ClassTableNode* classRef = findClassTableEntry(typeString);
	
	GSymbol* temp = globalSymbolTableHead;
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
	temp->classRef = classRef;
	temp->address = VAR_ADDRESS;
	if(temp->classRef != NULL){
		temp->size = 2;
		VAR_ADDRESS += 2;
	} else {
		temp->size = size;
		VAR_ADDRESS += size;
	}
	temp->flabel = flabel;
	temp->paramlist = paramList;
	temp->next = globalSymbolTableHead;
	globalSymbolTableHead = temp;
}


void addLocalVariable (char* name, TypetableNode* type) {
	LSymbol* temp = localSymbolTableHead;
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
	temp->next = localSymbolTableHead;
	localSymbolTableHead = temp;
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
	GSymbol* temp = globalSymbolTableHead;
	while(temp){
		if(strcmp(temp->name, name) == 0){
			return temp;
		}
		temp = temp->next;
	}
	printf("UNDECLARED VARIABLE: %s\n", name);
	return NULL;
}

struct LSymbol* findLocalVariable(char* name){
	LSymbol* temp = localSymbolTableHead;
	while(temp){
		if(strcmp(temp->name, name) == 0){
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}



Param* createParameter(char *name, TypetableNode* type) {
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
	return localSymbolTableHead;
}

int getVarAddress(){
	return VAR_ADDRESS;
}

int get8VarAddress(){
	int t = VAR_ADDRESS;
	VAR_ADDRESS += 8;
	return t;
}

void terminateFunction(){
	free(localSymbolTableHead);
	localSymbolTableHead = NULL;
	LOCAL_ADDRESS = 1;
}

void test(){
	printf("HELLO");
}

int isUserDefined(TypetableNode* type){
	if(type->fields == NULL)
		return 0;
	else 
		return 1;
}