#include<stdio.h>
#include<string.h>

#ifndef SYMBOLS_H
#define SYMBOLS_H
#include "symbol_table.h"
#endif

TypetableNode* typeTableHead = NULL;

int getSize(FieldlistNode* fields);

void typeTableCreate() {
	addToTypeTable("int", NULL);
	addToTypeTable("string", NULL);
	addToTypeTable("bool", NULL);
	addToTypeTable("void", NULL);
}

void addToTypeTable(char* name, FieldlistNode* fields) {
	TypetableNode* temp = (TypetableNode*)malloc(sizeof(TypetableNode));
	temp->name = (char*)malloc(strlen(name) * sizeof(char));
	strcpy(temp->name, name);

	temp->fields = fields;
	if(strcmp(name, "void") == 0)
		temp->size = 0;
	else
		temp->size = getSize(fields);

	temp->next = typeTableHead;
	typeTableHead = temp;
}

TypetableNode* findTypeTableEntry(char* name) {
	TypetableNode* temp = typeTableHead;

	while (temp != NULL)
	{
		if(strcmp(name, temp->name) == 0)
			return temp;
		
		temp = temp->next;
	}

	printf("UNDEFINED DATATYPE\n");
	exit(-1);
}

FieldlistNode* createFieldNode(TypetableNode* type, char*name){
	FieldlistNode* temp = (FieldlistNode*)malloc(sizeof(FieldlistNode));

	temp->next = NULL;
	temp->name = (char*)malloc(strlen(name)*sizeof(char));
	strcpy(temp->name, name);
	temp->type = type;
	temp->fieldIndex = 0;

	return temp;
}


FieldlistNode* addToFieldList(FieldlistNode* fieldNode, FieldlistNode* next) {
	FieldlistNode* temp = fieldNode;

	if(next == NULL){
		fieldNode->fieldIndex = 0;
	} else if (next->fieldIndex == 7) {
		printf("MAXIMUM 8 MEMBERS FOR A STRUCT\n");
		exit(-1);
	} else {
		fieldNode->next = next;
		fieldNode->fieldIndex = next->fieldIndex + 1;
	}

	return temp;
}

FieldlistNode* fieldLookup(TypetableNode* type, char* fieldName){
	FieldlistNode* temp = type->fields;

	while(temp != NULL){
		if(strcmp(temp->name, fieldName) == 0)
			return temp;

		temp = temp->next;
	}

	printf("INVALID FIELD MEMBER");
	exit(-1);
}

int getSize(FieldlistNode* fields) {
	if(fields == NULL){
		return 1;
	} else {
		return 1;
		//TODO
	}
}