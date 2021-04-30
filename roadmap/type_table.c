#include<stdio.h>
#include<string.h>

#ifndef SYMBOLS_H
#define SYMBOLS_H
#include "symbol_table.h"
#endif

TypetableNode* typeTableHead = NULL;

int getSize(FieldlistNode* fields);

void typeTableCreate() {
	createTypeTableEntry("int");
	addFieldsToTypeTable("int", NULL);
	createTypeTableEntry("string");
	addFieldsToTypeTable("string", NULL);
	createTypeTableEntry("bool");
	addFieldsToTypeTable("bool", NULL);
	createTypeTableEntry("void");
	addFieldsToTypeTable("void", NULL);
}

void createTypeTableEntry(char* name){
	TypetableNode* temp = (TypetableNode*)malloc(sizeof(TypetableNode));
	temp->name = (char*)malloc(strlen(name) * sizeof(char));
	strcpy(temp->name, name);

	temp->next = typeTableHead;
	typeTableHead = temp;
}

void addFieldsToTypeTable(char* name, FieldlistNode* fields) {
	TypetableNode* temp = findTypeTableEntry(name);

	temp->fields = fields;
	if(strcmp(name, "void") == 0)
		temp->size = 0;
	else
		temp->size = getSize(fields);
}

TypetableNode* findTypeTableEntry(char* name) {
	if(name == NULL){
		return NULL;
	}

	TypetableNode* temp = typeTableHead;

	while (temp != NULL)
	{
		if(strcmp(name, temp->name) == 0)
			return temp;
		
		temp = temp->next;
	}

	return NULL;
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