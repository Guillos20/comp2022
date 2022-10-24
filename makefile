all:
	flex jucompiler.l
	yacc -v -d jucompiler.y
	cc -o run *.c

	
