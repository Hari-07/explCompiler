#include <stdlib.h>
#include <string.h>

#ifndef EXPTREE_H
#define EXPTREE_H
#include "exptree.h"
#endif

#ifndef SYMBOLS_H
#define SYMBOLS_H
#include "symbol_table.h"
#endif

#ifndef CLASS_H
#define CLASS_H
#include "class_table.h"
#endif

void checkInputConditions(tnode* t);
void checkOutputConditions(tnode* t);
void checkVariableConditions(tnode* t);
void checkOperatorConditions(int meta, tnode*l, tnode* r);
void checkConditionalValidity(tnode* condn);
void checkFunctionCallValidity(tnode* iterator, Param* param);

tnode* createNode(){
	tnode* temp = (tnode*)malloc(sizeof(tnode));

	temp -> val.decimal = 0;
	temp -> val.string = "";

	temp -> nodeType = newNode;
	temp -> metadata = 0;
	temp -> type = NULL;
	temp -> op = NULL;
	temp -> left = NULL;
	temp -> right = NULL;
	temp -> varLocation = NULL;
	temp -> fieldChain = NULL;

	return temp;
}

tnode *makeConnectorNode(tnode *l, tnode *r)
{
	tnode *temp = createNode();
	temp->left = l;
	temp->right = r;
	temp->nodeType = connectorNode;
	return temp;
}

tnode *makeReadNode(tnode *target)
{
	checkInputConditions(target);

	tnode* temp = createNode();
	temp->nodeType = readNode;
	temp->left = target;
	temp->right = NULL;
	return temp;
}

tnode *makeWriteNode(tnode *source)
{	
	checkOutputConditions(source);

	tnode *temp = createNode();
	temp->nodeType = writeNode;
	temp->left = source;
	temp->right = NULL;
	return temp;
}

tnode* makeAllocNode(tnode* target)
{
	if(target->type->fields == NULL) {
		printf("Can only allocate to a struct");
		exit(-1);
	}

	tnode* temp = createNode();
	temp->nodeType = allocNode;

	temp->left = target;
	temp->right = NULL;

	return temp;
}

tnode* makeDeAllocNode(tnode* target)
{
	if(target->type->fields == NULL) {
		printf("Can only allocate to a struct");
		exit(-1);
	}

	tnode* temp = createNode();
	temp->nodeType = deAllocNode;

	temp->left = target;
	temp->right = NULL;

	return temp;
}

tnode *makeConstantNode(TypetableNode* type, int number, char *s)
{
	tnode* temp = createNode();
	temp->nodeType = constantNode;
	temp->type = type;
	if(strcmp(type->name,"int") == 0)
		temp->val.decimal = number;
	else if (strcmp(type->name,"string") == 0){
		temp->val.string = (char*)malloc(sizeof(char)*strlen(s));
		strcpy(temp->val.string, s);
	}
	return temp;
}

tnode *makeVariableNode(char *s, tnode* offset)
{
	checkVariableConditions(offset);

	tnode *temp = createNode();
	temp->nodeType = variableNode;

	LSymbol* tempRes = findLocalVariable(s);
	if(tempRes != NULL){
		temp->type = tempRes->type;
		temp->varLocation = tempRes;
	} else {
		GSymbol* result = (GSymbol*)findGlobalVariable(s);
		temp->type = result->type;
		temp->varLocation =  result;
	}

	temp->left = offset;
	temp->right = NULL;
	return temp;
}

tnode *makeOperatorNode(int meta, char *op, tnode *l, tnode *r)
{
	checkOperatorConditions(meta, l, r);

	tnode *temp = createNode();
	temp->nodeType = operatorNode;
	temp->metadata = meta;
	if(meta == 1){
		temp->type = findTypeTableEntry("int");
	}
	temp->op = op;
	temp->left = l;
	temp->right = r;
	return temp;
}

tnode *makeIfNode(tnode *condn, tnode *trueBody, tnode *falseBody)
{
	checkConditionalValidity(condn);

	tnode *temp = createNode();
	temp->nodeType = ifNode;
	temp->left = condn;
	temp->right = makeConnectorNode(trueBody, falseBody);
	return temp;
};

tnode *makeWhileNode(int looptype, tnode *condn, tnode *body)
{
	checkConditionalValidity(condn);
		
	tnode *temp = createNode();
	temp->nodeType = whileNode;
	temp->metadata = looptype;
	temp->left = condn;
	temp->right = body;
	return temp;
}

tnode* makeJumpStatement(int type) {
	tnode* temp = createNode();
	temp-> nodeType = jumpNode;
	temp-> metadata = type;
	return temp;
}

tnode* makeFunctionCallNode(char* fName, tnode* arg) {
	
	GSymbol* reference = findGlobalVariable(fName);

	tnode* iterator = arg;
	Param* param = reference->paramlist;
	
	checkFunctionCallValidity(iterator, param);

	tnode* temp = createNode();
	temp->nodeType = functionCallNode;
	temp->type = reference->type;
	temp->varLocation = (GSymbol*)reference->paramlist;
	temp->right = arg;
	temp->val.decimal = reference->flabel;

	return temp;
}

tnode* makeClassMethodCallNode(FieldlistNode* fieldChain, tnode* arg){
	tnode *temp = createNode();
	temp->nodeType = methodCallNode;

	FieldlistNode* res = fieldChain;
	if(strcmp(res->name, "SELF") == 0){
		res->classRef = getCurrentClassRef();
	} else if(findClassTableEntry(res->name) != NULL) {
		res->classRef = findClassTableEntry(res->name);
	} else if(findLocalVariable(fieldChain->name) != NULL){
		LSymbol* localRef = findLocalVariable(fieldChain->name);
		temp->varLocation = localRef;
		res->classRef = localRef->classRef;
		res->type = localRef->type;
	} else if(findGlobalVariable(fieldChain->name) != NULL) {
		GSymbol* result = findGlobalVariable(fieldChain->name);
		temp->varLocation =  result;
		res->classRef = result->classRef;
		res->type = result->type;
	} else {
		printf("UNDEFINED ELEMENT IN FIELD CHAIN\n");
		exit(-1);
	}

	TypetableNode* parentType = res->type;
	ClassTableNode* parentClass = res->classRef;
	res = res->next;

	while(res->next != NULL) {
		FieldlistNode* fieldRef;
		if(parentType != NULL){
			fieldRef = fieldLookup(parentType, res->name);	
		} else if(parentClass != NULL) {
			fieldRef = findClassField(parentClass, res->name);
		}

		res->classRef = fieldRef->classRef;
		res->type = fieldRef->type;
		res->fieldIndex = fieldRef->fieldIndex;

		parentType = res->type;
		parentClass = res->classRef;
		res = res->next;
	}

	res = fieldChain;
	while(res->next->next != NULL){
		res = res->next;
	}

	if(res->classRef == NULL){
		printf("INVALID METHOD CALL");
		exit(-1);
	}
	
	tnode* iterator = arg;
	ClassMethodNode* methodRef = findClassMethod(res->classRef, res->next->name);
	Param* param = methodRef->paramlist;

	checkFunctionCallValidity(iterator, param);

	temp->fieldChain = fieldChain;
	temp->type = methodRef->returnType;
	temp->varLocation = (GSymbol*)methodRef->paramlist;
	temp->right = arg;
	temp->val.decimal = methodRef->flabel;

	return temp;
}

tnode* makeReturnNode(tnode* r) {
	tnode* temp = createNode();
	temp->nodeType = functionReturnNode;
	temp->type = r->type;
	temp->right = r;
}

FieldlistNode* makeVariableChain(char* parentFieldName, char* childFieldName, FieldlistNode* childFieldNode){
	FieldlistNode* parentField = (FieldlistNode*)malloc(sizeof(FieldlistNode));
	parentField->name = (char*)malloc(sizeof(char)* strlen(parentFieldName));
	strcpy(parentField->name, parentFieldName);

	
	if(childFieldNode != NULL){
		parentField->next = childFieldNode;
	} else {
		FieldlistNode* temp = (FieldlistNode*)malloc(sizeof(FieldlistNode));
		temp->name = (char*)malloc(sizeof(char)* strlen(childFieldName));
		strcpy(temp->name, childFieldName);
		parentField->next = temp;
	}
	
	return parentField;
}


tnode* makeFieldNode(FieldlistNode* variableChain, tnode* offset){
	tnode *temp = createNode();
	temp->nodeType = fieldNode;

	FieldlistNode* res = variableChain;

	if(strcmp(res->name, "SELF") == 0){
		res->classRef = getCurrentClassRef();
		temp->varLocation = findLocalVariable("SELF");
	} else if(findLocalVariable(variableChain->name) != NULL){
		LSymbol* localRef = findLocalVariable(variableChain->name);
		temp->varLocation = localRef;
		res->type = localRef->type;
	} else {
		GSymbol* result = (GSymbol*)findGlobalVariable(variableChain->name);
		temp->varLocation =  result;
		res->type = result->type;
	}

	TypetableNode* parentType = res->type;
	ClassTableNode* parentClass = res->classRef;
	res = res->next;

	while(res != NULL) {
		FieldlistNode* fieldRef;
		if(parentType != NULL){
			fieldRef = fieldLookup(parentType, res->name);	
		} else if(parentClass != NULL) {
			fieldRef = findClassField(parentClass, res->name);
		}

		res->classRef = fieldRef->classRef;
		res->type = fieldRef->type;
		res->fieldIndex = fieldRef->fieldIndex;

		parentType = res->type;
		parentClass = res->classRef;
		res = res->next;

	}
	temp->type = parentType;
	

	temp->fieldChain = variableChain;
	temp->left = offset;



	return temp;
}

tnode* makeClassConstructorNode(tnode* l, char* className){

	tnode* temp = createNode();
	temp->nodeType = allocNode;

	temp->left = l;
	temp->right = NULL;

	return temp;
}

tnode* makeBreakPointNode(){
	tnode* temp = createNode();
	temp->nodeType = breakNode;
	return temp;
}


/*
Input Conditions:
- Can only read to variable
*/
void checkInputConditions(tnode* t){
	if(t->nodeType != variableNode && t->nodeType != fieldNode){
		printf("INVALID READ STATEMENT");
		exit(-1);
	}
}



/*
Output Conditions:
- Can Output Constants
- Can Output Variable
- Can Output Arithmetic expression
*/
void checkOutputConditions(tnode* t){
	if (t->nodeType != constantNode &&
		t->nodeType != variableNode &&
		t->nodeType != fieldNode &&
		t->nodeType != functionCallNode &&
		t->nodeType != methodCallNode &&
		(t->nodeType != operatorNode ||
		t->metadata != 1)
	) {
		printf("INVALID WRITE STATEMENT");
		exit(-1);
	}
}

/*
Variable Conditions:
- Offset must be constant or variable of type integer
*/
void checkVariableConditions(tnode* t){
	if(!((t->nodeType == constantNode && t->type == findTypeTableEntry("int")) ||
		 (t->nodeType == variableNode && t->type == findTypeTableEntry("int")) ||
		 (t->nodeType == fieldNode && t->type == findTypeTableEntry("int"))
	)) {
		printf("ILLEGAL OFFSET\n");
		exit(-1);
	}
}

/*
Operator Conditions:
- LHS of assignment should be a variable
- LHS, RHS of assignment should be of same type
- LHS, RHS of boolean expression should be integer variable/constant
- LHS, RHS of arithmetic expression should be integer variable/constants/arithmetic expressions
*/
void checkOperatorConditions(int meta, tnode*l, tnode* r){
	if(meta == 0){
		if(l->nodeType != variableNode && l->nodeType != fieldNode) {
			printf("Can only assign to a variable\n");
			exit(-1);
		}
		else if(r->nodeType != constantNode && 
				r->nodeType != variableNode && 
				r->nodeType != operatorNode && 
				r->nodeType != functionCallNode &&
				r->nodeType != methodCallNode &&
				r->nodeType != fieldNode
		) {
			printf("Invalid Assignment Statement\n");
			exit(-1);
		}
		else if(r->nodeType == operatorNode && r->metadata != 1){
			printf("Non arithmetic expressions cannot be assigned\n");
			exit(-1);
		}
		else if(l->type != r->type && r->type != findTypeTableEntry("void")){
			printf("Type Mismatch in Assignment Statement\n");
			exit(-1);
		}
	} else if(meta == 1){
		if( (l->nodeType != constantNode && l->nodeType != variableNode && l->nodeType != operatorNode && l->nodeType != functionReturnNode && l->nodeType != fieldNode && l->nodeType != methodCallNode) ||
		   	(r->nodeType != constantNode && r->nodeType != variableNode && r->nodeType != operatorNode && r->nodeType != functionReturnNode && r->nodeType != fieldNode && r->nodeType != methodCallNode)
		) {
			printf("Invalid Node in operation\n");
			exit(-1);
		}
		else if((l->nodeType == operatorNode && l->metadata != 1) ||
				(r->nodeType == operatorNode && r->metadata != 1)
		) {
			printf("Invalid Arithmetic Expresson\n");
			exit(-1);
		}
	} else if(meta == 2){
		if((l->nodeType != constantNode && l->nodeType != variableNode && l->nodeType != fieldNode) ||
		   (r->nodeType != constantNode && r->nodeType != variableNode && r->nodeType != fieldNode)
		) {
			printf("Invalid Expression\n");
			exit(-1);
		}
		else if((l->type != findTypeTableEntry("int") || r->type != findTypeTableEntry("int")) && l->type!= findTypeTableEntry("void") && r->type != findTypeTableEntry("void")) {
			printf("Invalid comparsion\n");
			exit(-1);
		}
	}
}

void checkConditionalValidity(tnode* condn){
	if(condn -> nodeType == operatorNode && condn->metadata == 2) {
		return;
	}
	
	printf("INVALID CONDITION EXPRESSION\n");
	exit(-1);
}

void checkFunctionCallValidity(tnode* iterator, Param* param){

	while(iterator != NULL){
		if(param == NULL){
			printf("INVALID FUNCTION CALL\n");
			exit(-1);
		}

		tnode* temp = iterator->right;
		if(temp->nodeType == constantNode ){
			if(param->type != temp->type){
				printf("INVALID FUNCTION CALL\n");
				exit(-1);
			}
		}
		else if(temp->nodeType == variableNode){
			LSymbol* localSymbolReference = (LSymbol*)temp->varLocation;
			GSymbol* globalSymbolReference = (GSymbol*)temp->varLocation;
			if(localSymbolReference != NULL){
				if(param->type != localSymbolReference->type){
					printf("INVALID FUNCTION CALL\n");
					exit(-1);
				}
			} else {
				if(param->type != globalSymbolReference->type){
					printf("INVALID FUNCTION CALL\n");
					exit(-1);
				}
			}
		}
		else if(temp->nodeType == operatorNode){
			if(temp->metadata != 1 || strcmp(param->type->name,"int") != 0){
				printf("INVALID FUNCTION CALL\n");
				exit(-1);
			}
		}
		iterator = iterator->left;
		param = param->next;
	}

	if(param != NULL){
		printf("INVALID FUNCTION CALL\n");
		exit(-1);
	}
}