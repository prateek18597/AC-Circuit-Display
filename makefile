all:
	@flex Start.cpp
	@g++ -I eg/Eigen -w -std=c++11 lex.yy.c	
	@./a.out top.cir
	
