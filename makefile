all:
	flex jucompiler.l
	yacc -v -d jucompiler.y
	clang -o run *.c

	
