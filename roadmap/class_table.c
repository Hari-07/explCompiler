#include<stdio.h>
#include<string.h>

#ifndef CLASS_H
#define CLASS_H
#include "class_table.h"
#endif

ClassTableNode* classTableHead = NULL;

ClassTableNode* findClassTableEntry(char* className){
	ClassTableNode* temp = classTableHead;
	while (temp != NULL)
	{
		if(strcmp(temp->name, className) == 0){
			return temp;
		}
		temp = temp->next;
	}

	return NULL;
}

void createClassTableEntry(char* name){
	ClassTableNode* temp = (ClassTableNode*)malloc(sizeof(ClassTableNode));

	temp->name = (char*)malloc(sizeof(char)*strlen(name));
	strcpy(temp->name, name);

	temp->next = classTableHead;
	classTableHead = temp;
}

void addFieldToClass(char* className, FieldlistNode* fields){
	ClassTableNode* temp = findClassTableEntry(className);
	temp->fields = fields;
}

void addMethodsToClass(char* className, ClassMethodNode* methods){
	ClassTableNode* temp = findClassTableEntry(className);
	temp->methods = methods;
}

FieldlistNode* findClassField(ClassTableNode* classRef, char* fieldName){
	FieldlistNode* temp = classRef->fields;

	while (temp != NULL) {
		if(strcmp(temp->name, fieldName) == 0)
			return temp;

		temp = temp->next;
	}

	printf("FIELD ACCESSED DOES NOT EXIST\n");
	exit(-1);
}

ClassMethodNode* findClassMethod(ClassTableNode* classRef, char* methodName){
	ClassMethodNode* temp = classRef->methods;

	while (temp != NULL) {
		if(strcmp(temp->name, methodName) == 0)
			return temp;

		temp = temp->next;
	}

	printf("METHOD ACCESSED DOES NOT EXIST\n");
	exit(-1);
}

FieldlistNode* createClassFieldNode(char* fieldTypeString, char* fieldName){
	FieldlistNode* temp = (FieldlistNode*)malloc(sizeof(FieldlistNode));

	temp->next = NULL;

	temp->name = (char*)malloc(strlen(fieldName)*sizeof(char));
	strcpy(temp->name, fieldName);

	if(findClassTableEntry(fieldTypeString) != NULL){
		temp->classRef = findClassTableEntry(fieldTypeString);
		temp->type = NULL;
	} else if(findTypeTableEntry(fieldTypeString) != NULL){
		temp->classRef = NULL;
		temp->type = findTypeTableEntry(fieldTypeString);
	} else {
		printf("UNDECLARED DATATYPE %s\n", fieldTypeString);
		exit(-1);
	}

	return temp;
}

FieldlistNode* addToClassFieldNodeList(FieldlistNode* classFieldNode, FieldlistNode* next){
	FieldlistNode* temp = classFieldNode;

	if(next == NULL){
		temp->fieldIndex = 0;
	} else if (next->fieldIndex == 7) {
		printf("MAXIMUM 8 FIELDS FOR A CLASS\n");
		exit(-1);
	} else {
		temp->next = next;
		temp->fieldIndex = next->fieldIndex + 1;
	}

	return temp;
}

ClassMethodNode* createClassMethodNode(char* name, int flabel, TypetableNode* returnType, Param* paramList){
	ClassMethodNode* temp = (ClassMethodNode*)malloc(sizeof(ClassMethodNode));

	temp->name = (char*)malloc(sizeof(char)* strlen(name));
	strcpy(temp->name, name);

	temp->flabel = flabel;
	temp->returnType = returnType;
	temp->paramlist = paramList;
	temp->next = NULL;

	return temp;
}

ClassMethodNode* addToClassMethodList(ClassMethodNode* classMethodNode, ClassMethodNode* next){
	ClassMethodNode* temp = classMethodNode;
	
	if(next == NULL){
		temp->methodIndex = 0;
	} else {
		if(next->methodIndex == 7) {
			printf("MAXIMUM 8 METHODS ALLOWED FOR A CLASS");
			exit(-1);
		}

		temp->next = next;
		temp->methodIndex = next->methodIndex + 1;
	}

	return temp;
}

void checkMethodValidity(char* methodName, Param* params){
	ClassMethodNode* methodRef = findClassMethod(classTableHead, methodName);

	Param* definedParams = methodRef->paramlist;

	while(definedParams != NULL && params != NULL){
		if(strcmp(definedParams->name, params->name) != 0 || definedParams->type != params->type) {
			printf("INVALID METHOD DEFINITION IN CLASS: %s", classTableHead->name);
			exit(-1);
		} else {
			definedParams = definedParams->next;
			params = params->next;
		}
	}

	if(definedParams != NULL || params != NULL){
		printf("INVALID METHOD DEFINITION IN CLASS: %s", classTableHead->name);
		exit(-1);
	}
}

void addSelfToLSymbol(){
	addLocalVariable("SELF", NULL);
}

ClassTableNode* getCurrentClassRef(){
	return classTableHead;
}