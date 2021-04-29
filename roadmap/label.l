%{
	#include<stdio.h>
	#include<string.h>
	FILE* target;
	int address = 2040;
	int pass = 0;
	int main_address;
	typedef struct node{
		char* label;
		int address;
		struct node* next;
	}node;
	node* head = NULL;

	void printLine(char* s);
	void addLabel(char* s);
	void printLabel(char* s);
	void addMain();
	void printMain();
%}

%%

^MAIN\n				{	addMain(); 			}
^LABEL[0-9]+\n		{	addLabel(yytext);	};
^FUNCTION[0-9]+\n	{	addLabel(yytext); 	};
"CALL MAIN\n"		{	printMain(); 		};
LABEL[0-9]+\n		{	printLabel(yytext);	};
FUNCTION[0-9]+\n 	{ 	printLabel(yytext); };
[-,a-zA-Z0-9"\[\]]+	{   printLine(yytext);	};
[\n ]				{	printLine(yytext);  };
%%

void printLine(char* s){
	if(pass == 1) {
		fprintf(target, "%s", s);
	} else {
		if(strcmp(s,"\n") == 0)
			address += 2;
	}
}

void printLabel(char* s){
	if(pass == 1) {
		node* temp = head;
		while(strcmp(temp->label, s) != 0){
			temp = temp->next;
			if(!temp)
				break;
		}
		if(temp) {
			fprintf(target, "%d\n", temp->address);
		} else {
			printf("LABEL NOT FOUND: %s \n", s);
			exit(-1);
		}
	} else {
		address += 2;
	}
}

void printMain(){
	if(pass == 1){
		fprintf(target, "%d\n", main_address);
	} else {
		address += 2;
	}
}

void addLabel(char* s){
	if(pass == 0) {
		node* temp = (node*)malloc(sizeof(node));
		temp->label = (char*)malloc(strlen(s)*sizeof(char));
		strcpy(temp -> label,s);
		temp -> next = head;
		temp -> address = address;
		head = temp;
	}
}

void addMain(){
	main_address = address;
}

int yywrap(void){
	if(pass == 0){
		FILE* fp = fopen("output.xsm","r");
		yyin = fp;
		pass = 1;
		return 0;
	} else {
		return 1;
	}
}

int main()
{
	FILE* fp = fopen("output.xsm","r");
	target = fopen("final.xsm", "w");
	if(fp)
		yyin = fp;
	yylex();
	return 0;
}