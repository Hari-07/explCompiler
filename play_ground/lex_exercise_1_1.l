/*to count the number of lines, words, and characters in the input.*/

%{

	#include<stdio.h>

	int line_count = 0, word_count = 0, char_count = 0;
%}

newline	\n
newword " "
anychar (.)

%option noyywrap

%%

{newline} { line_count++; }

{newword} { word_count++; }

{anychar} { char_count++; }

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

	if( char_count != 0 )
		word_count++;

	printf("Line count: %d\n", line_count);
	printf("Word count: %d\n", word_count);
	printf("Character count: %d\n", char_count);
}