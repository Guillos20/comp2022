all:
	flex jucompiler.l
	yacc -d jucompiler.y
	clang -o run *.c

	
