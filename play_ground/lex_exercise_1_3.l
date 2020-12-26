/*to list out all words of length three, starting with "A" to uppercase*/

%{

	#include<stdio.h>
%}

low [a-z]
upp [A-Z]

%option noyywrap

%%

^A({low}|{upp})({low}|{upp})$ { printf("%s\n", yytext); }
\n ; //Ignore other characters
. ;
%%

int main(int argc, char* argv[])
{
	if(argc != 2) {
		printf("Usage : ./a.out <FILENAME>\n");
		return 1;
	}

	FILE *fp = fopen(argv[1], "r");
	
	if(!fp) {
		printf("File cannot be opened\n");
		return 2;
	}

	yyin = fp;
	yylex();


	return 0;
}