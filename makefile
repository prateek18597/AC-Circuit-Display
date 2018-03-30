all:
	@flex Start.cpp
	@g++ -w -std=c++11 lex.yy.c	
	@./a.out top.cir
	@firefox top.html