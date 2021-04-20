#ifndef TYPES_H
#define TYPES_H
#include "type_table.h"
#endif

typedef struct Param {
	char* name;
	TypetableNode* type;
	struct Param* next;
}Param;

typedef struct GSymbol {
	char* name;
	TypetableNode* type;
	int size; 
	int address;
	int flabel;
	Param* paramlist;
	struct GSymbol* next;
}GSymbol;

typedef struct LSymbol {
	char* name;
	TypetableNode* type;
	int binding;
	struct LSymbol* next;
} LSymbol;

void addGlobalVariable(char* name, TypetableNode* type, int size, int flabel, Param* paramList);
void addLocalVariable (char* name, TypetableNode* type);
Param* createParameter(char *name, TypetableNode* type);
Param* addParameter(Param* next, Param* paramNode);

int checkNameEquivalence(Param* params, char* fname);
void addParamstoLSymbol(Param* param);

struct GSymbol* findGlobalVariable(char* name);
struct LSymbol* findLocalVariable(char* name);

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
