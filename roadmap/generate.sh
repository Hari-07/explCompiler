lex parser.l
yacc -d --debug -v parser.y
gcc -g lex.yy.c y.tab.c -o parser
./parser $1
lex label.l
gcc -g lex.yy.c -o label
./label