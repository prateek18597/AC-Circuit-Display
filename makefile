all:
	@flex Start.cpp
	@g++ -w -std=c++11 lex.yy.c	
	@rlwrap ./a.out input.cir
	
