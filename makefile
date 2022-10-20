all:
	flex jucompiler.l
	yacc -d jucompiler.y
	cc -o run y.tab.c lex.yy.c

	
