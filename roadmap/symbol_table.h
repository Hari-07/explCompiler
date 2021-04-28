#ifndef CLASS_H
#define CLASS_H
#include "class_table.h"
#endif

typedef struct Param {
	char* name;
	TypetableNode* type;
	ClassTableNode* classRef;
	struct Param* next;
}Param;

typedef struct GSymbol {
	char* name;
	TypetableNode* type;
	ClassTableNode* classRef;
	int size; 
	int address;
	int flabel;
	Param* paramlist;
	struct GSymbol* next;
}GSymbol;

typedef struct LSymbol {
	char* name;
	TypetableNode* type;
	ClassTableNode* classRef;
	int binding;
	struct LSymbol* next;
} LSymbol;

void addGlobalVariable(char* name, char* typeString, int size, int flabel, Param* paramList);
void addLocalVariable (char* name, TypetableNode* type);
Param* createParameter(char *name, TypetableNode* type);
Param* addParameter(Param* next, Param* paramNode);

int checkNameEquivalence(Param* params, char* fname);
void addParamstoLSymbol(Param* param);

GSymbol* findGlobalVariable(char* name);
LSymbol* findLocalVariable(char* name);

LSymbol* getLocalSymbolTableHeader();
int getVarAddress();
void test();
int isUserDefined(TypetableNode* type);
void terminateFunction();
/*
	Variable Types
	0: Integer
	1: String
*/
