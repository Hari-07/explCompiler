#include<stdio.h>
#include<string.h>

#ifndef SYMBOLS_H
#define SYMBOLS_H
#include "symbol_table.h"
#endif

GSymbol *head = NULL;
int VAR_ADDRESS = 4096;

void addVariable(char* name, int type, int size){
	GSymbol* temp = (GSymbol*)malloc(sizeof(GSymbol));
	temp->name = name;
	temp->type = type;
	temp->size = 1;
	temp->address = VAR_ADDRESS++;
	temp->next = head;
	head = temp;
}

struct GSymbol* findVariable(char* name){
	GSymbol* temp = head;
	while(strcmp(temp->name, name) != 0){
		temp = temp->next;
		if(!temp)
			break;
	}
	if(temp){
		return temp;
	} else {
		printf("UNDECLARED VARIABLE\n");
		exit(-1);
	}
}