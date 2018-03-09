all:
	@flex Start.cpp
	@g++ -w -std=c++11 lex.yy.c
	@echo "Enter Netlist:"	
	@rlwrap ./a.out input.txt
	
