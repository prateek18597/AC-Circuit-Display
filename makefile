all:
	@flex Start.cpp
	@g++ -w -std=c++11 lex.yy.c	
	@./a.out top.cir
	@google-chrome top.html	

debug:
	@flex Start.cpp
	@g++ -g -w -std=c++11 lex.yy.c	
	@gdb ./a.out top.cir
