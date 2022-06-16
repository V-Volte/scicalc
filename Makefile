calc: lex.yy.c y.tab.c
	g++ -g lex.yy.c y.tab.c -o calc

lex.yy.c: y.tab.c inp.lex
	lex inp.lex

y.tab.c: parse.y
	yacc -d parse.y

clean: 
	rm -rf lex.yy.c y.tab.c y.tab.h calc calc.dSYM
