#ifndef SYMBOLS_H
#define SYMBOLS_H
#include "symbol_table.h"
#endif

#ifndef TYPES_H
#define TYPES_H
#include "type_table.h"
#endif

typedef struct ClassMethodNode {
	char* name;
	TypetableNode* returnType;
	struct Param* paramlist;
	int methodIndex;
	struct ClassMethodNode* next;
	int flabel;
}ClassMethodNode;

typedef struct ClassTableNode {
	char* name;
	FieldlistNode* fields;
	ClassMethodNode* methods;
	struct ClassTableNode* next;
}ClassTableNode;


ClassTableNode* findClassTableEntry(char* className);

void createClassTableEntry(char* name);
void addFieldToClass(char* className, FieldlistNode* fields);
void addMethodsToClass(char* className, ClassMethodNode* methods);

FieldlistNode* findClassField(ClassTableNode* classRef, char* fieldName);
ClassMethodNode* findClassMethod(ClassTableNode* classRef, char* methodName);

FieldlistNode* createClassFieldNode(char* fieldTypeString, char* fieldName);
FieldlistNode* addToClassFieldNodeList(FieldlistNode* classFieldNode, FieldlistNode* next);


ClassMethodNode* createClassMethodNode(char* name, int flabel, TypetableNode* returnType,struct Param* paramList);
ClassMethodNode* addToClassMethodList(ClassMethodNode* classMethodNode, ClassMethodNode* next);


void checkMethodValidity(char* methodName,struct Param* params);
void addSelfToLSymbol();

ClassTableNode* getCurrentClassRef();