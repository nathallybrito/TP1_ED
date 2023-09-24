#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa main
# Autor		: Náthally Fernandes
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#           : make run - compila o exécutavel 
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------
CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/stack.o $(OBJ)/avaliador.o
HDRS = $(INC)/avaliador.hpp $(INC)/stack.hpp
CFLAGS = -Wall -c -g -I$(INC)

EXE = $(BIN)/main

run:  $(EXE)
		./$(EXE) -a "0 | 1" 01
		./$(EXE) -a "0 | 1 & 2" 010
		./$(EXE) -a "~ ( 0 | 1 ) & 2" 101
		./$(EXE) -s "0 | 1 & 2" 0e0
		./$(EXE) -s	"0 | 1 & 2" e00
		./$(EXE) -s "1 | 2 & 3" a11

$(BIN)/main: $(OBJS)
	$(CC) -g -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/stack.o: $(HDRS) $(SRC)/stack.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/stack.o $(SRC)/stack.cpp  

$(OBJ)/avaliador.o: $(HDRS) $(SRC)/avaliador.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/avaliador.o $(SRC)/avaliador.cpp	 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out