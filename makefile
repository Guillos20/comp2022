all:
	flex jucompiler.l
	yacc -d jucompiler.y
	cc -o run *.c

	
