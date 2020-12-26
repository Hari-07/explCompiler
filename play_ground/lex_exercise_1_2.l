/*to count the number of integers and floating point numbers appearing in the input.*/

%{

	#include<stdio.h>

	int int_count = 0, float_count = 0;
%}

sign   [-+]
number [0-9]

%option noyywrap

%%

^{sign}?({number})+ { int_count++; }
^{sign}?({number})+.({number})* { float_count++; }
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


	printf("Integer count: %d\n", int_count);
	printf("Float count: %d\n", float_count);
}