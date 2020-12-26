/*to list out all C-like comments (both single line and multi line comments) from a text file.*/

%{

	#include<stdio.h>
%}

single 		\/\/
multilineB	\/*
multilineE	\*\/
newline 	\n

%option noyywrap

%%

^{single}(.|" ")*$ { printf("%s\n", yytext); }
{multilineB}(.|\n|" ")*{multilineE} { printf("%s\n", yytext); }
[ \t\n] ; //Ignore other characters
(.)* ;
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