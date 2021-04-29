#include<stdio.h>
#include<string.h>

#ifndef CLASS_H
#define CLASS_H
#include "class_table.h"
#endif

ClassTableNode* classTableHead = NULL;

//To create copy of linked list
ClassMethodNode* getCopyMethods(ClassMethodNode* head);

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

void createClassTableEntry(char* name, ClassTableNode* parent){
	ClassTableNode* temp = (ClassTableNode*)malloc(sizeof(ClassTableNode));

	temp->name = (char*)malloc(sizeof(char)*strlen(name));
	strcpy(temp->name, name);

	temp->parent = parent;
	temp->next = classTableHead;

	if(parent != NULL) {
		temp->methods = getCopyMethods(parent->methods);
		temp->fields = parent->fields;
	}

	classTableHead = temp;
}

void addFieldToClass(char* className, FieldlistNode* fields){
	ClassTableNode* classRef = findClassTableEntry(className);

	FieldlistNode* temp = fields;

	while(temp != NULL) {
		FieldlistNode* tempNext = temp->next;
		if(findClassField(classRef, temp->name) != NULL) {
			printf("Field names must be unique\n");
			exit(-1);
		}

		if(classRef->fields == NULL){
			temp->fieldIndex = 0;
		} else if (temp->fieldIndex == 7){
			printf("MAXIMUM 8 FIELDS FOR A CLASS\n");
			exit(-1);
		} else {
			temp->fieldIndex = classRef->fields->fieldIndex + 1;
		}
		temp->next = classRef->fields;
		classRef->fields = temp;
		temp = tempNext;
	}	

}

void addMethodsToClass(char* className, ClassMethodNode* methods){
	ClassTableNode* classRef = findClassTableEntry(className);

	ClassMethodNode* temp = methods;

	while(temp != NULL) {
		ClassMethodNode* tempNext = temp->next;

		if(findClassMethod(classRef, temp->name) != NULL && classRef->parent != NULL && (classRef->parent, temp->name) == NULL) {
			printf("Method names must be unique\n");
			exit(-1);
		}

		if(classRef->parent != NULL) {
			if(findClassMethod(classRef->parent, temp->name) != NULL) {
				ClassMethodNode* oldMethodRef = findClassMethod(classRef, temp->name);
				ClassMethodNode* newMethodRef = temp;

				Param* tempParam1 = oldMethodRef->paramlist;
				Param* tempParam2 = newMethodRef->paramlist;

				while(tempParam1 != NULL && tempParam2 != NULL){
					if(tempParam1->type != tempParam2 ->type){
						printf("INVALID FUNCTION OVERRIDE\n");
						exit(-1);
					}
					else if(strcmp(tempParam1->name, tempParam2->name) != 0){
						printf("INVALID FUNCTION OVERRIDE\n");
						exit(-1);
					}
				}

				if(tempParam1 != NULL || tempParam2 != NULL){
					printf("INVALID FUNCTION OVERRIDE\n");
					exit(-1);
				}
				oldMethodRef->flabel = newMethodRef->flabel;
			}
			temp = temp->next;
			continue;
		}

		if(classRef->methods == NULL){
			temp->methodIndex = 0;
		} else if (temp->methodIndex == 7){
			printf("MAXIMUM 8 METHODS FOR A CLASS\n");
			exit(-1);
		} else {
			temp->methodIndex = classRef->methods->methodIndex + 1;
		}
		temp->next = classRef->methods;
		classRef->methods = temp;
		temp = tempNext;
	}
}

FieldlistNode* findClassField(ClassTableNode* classRef, char* fieldName){
	FieldlistNode* temp = classRef->fields;

	while (temp != NULL) {
		if(strcmp(temp->name, fieldName) == 0)
			return temp;

		temp = temp->next;
	}

	return NULL;
}

ClassMethodNode* findClassMethod(ClassTableNode* classRef, char* methodName){
	ClassMethodNode* temp = classRef->methods;

	while (temp != NULL) {
		if(strcmp(temp->name, methodName) == 0)
			return temp;

		temp = temp->next;
	}

	return NULL;
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
	temp->next = next;
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
	temp->next = next;
	return temp;
}

void checkMethodValidity(char* methodName, Param* params){
	ClassMethodNode* methodRef = findClassMethod(classTableHead, methodName);

	if(methodRef == NULL){
		printf("NO SUCH METHOD DEFINED\n");
		exit(-1);
	}

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

void createFunctionTable(){
	classTableHead->functionTableAddress = get8VarAddress();
}

ClassMethodNode* getCopyMethods(ClassMethodNode* head){
	if(head == NULL)
		return NULL;
	else {
		ClassMethodNode* temp = (ClassMethodNode*)malloc(sizeof(ClassMethodNode));
		
		temp ->flabel = head->flabel;
		temp ->methodIndex = head -> methodIndex;
		
		temp ->name = (char*)malloc(sizeof(char)*strlen(head->name));
		strcpy(temp->name, head->name);

		temp->paramlist = head->paramlist;
		temp->returnType = head->returnType;

		temp->next = getCopyMethods(head->next);

		return temp;
	}
}
