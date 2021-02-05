yacc -d parser.y
lex parser.l
gcc -g lex.yy.c y.tab.c -o parser
./parser $1
./label