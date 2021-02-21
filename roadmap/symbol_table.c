#include<stdio.h>
#include<string.h>

#ifndef SYMBOLS_H
#define SYMBOLS_H
#include "symbol_table.h"
#endif

GSymbol *head = NULL;
int VAR_ADDRESS = 4096;

void addVariable(char* name, int type, int size){
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
	temp->address = VAR_ADDRESS;
	VAR_ADDRESS += size;
	temp->next = head;
	head = temp;
}

struct GSymbol* findVariable(char* name){
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

int getVarAddress(){
	return VAR_ADDRESS;
}