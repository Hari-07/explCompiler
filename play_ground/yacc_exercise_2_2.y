%{

#include<stdio.h>
#include<stdlib.h>

%}

%token DIGIT
%token ALPHA

%%

start: varname '\n'		{exit(0);};
	 ;

varname	: ALPHA string	{printf("Valid\n");};
		| DIGIT string 	{printf("Invalid\n");};
		;

string	: ALPHA string
		| ALPHA
		| DIGIT string
		| DIGIT
		;
%%

yyerror(char const *s)
{
    printf("yyerror %s\n",s);
}

yylex(){
    char c;
    c = getchar();
    if(isdigit(c)){
        return DIGIT;
    } 
	else if(isalpha(c)) {
		return ALPHA;
	} 
	else if(c == ' '){
        yylex();
    } 
	else{
        return c;
    }
}

main()
{
	yyparse();
	return 1;
}