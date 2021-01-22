%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>

%}

%union {
	char* c;
	char operator;
};

%token ALPHA OPLOW OPHIGH
%token NEWLINE
%left OPLOW
%left OPHIGH

%%

start	: 	expr 	NEWLINE {
						printf("%s", $<c>1);
						printf("\nCOMPLETED\n");
						exit(1);
					}
		;

expr	: expr OPLOW expr	{
								int len = strlen($<c>1)+strlen($<c>3)+3;
								char* result = (char*)malloc((sizeof(char))*(len));
								strcpy(result, (char[2]) { (char) $<operator>2, '\0' });
								strcat(result, " ");
								strcat(result, $<c>1);
								strcat(result, " ");
								strcat(result, $<c>3);
								$<c>$ = result; 
							}
		| expr OPHIGH expr	{
								int len = strlen($<c>1)+strlen($<c>3)+3;
								char* result = (char*)malloc((sizeof(char))*(len));
								strcpy(result, (char[2]) { (char) $<operator>2, '\0' });
								strcat(result, " ");
								strcat(result, $<c>1);
								strcat(result, " ");
								strcat(result, $<c>3);
								$<c>$ = result; 
							}
		| '('expr')'		
		|	ALPHA			{ $<c>$=$<c>1; }
		;
%%

void yyerror(char const *s){
	printf("Error: %s\n", s);
	return;
}

int main() {
	yyparse();
	return 1;
}