all:
	flex jucompiler.l
	yacc -v -d jucompiler.y
	cc -g -o run *.c

	
