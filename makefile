all:
	flex jucompiler.l
	yacc -d jucompiler.y