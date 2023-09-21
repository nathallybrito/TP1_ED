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
OBJS = $(OBJ)/main.o 
HDRS = $(INC)/avaliador.hpp $(INC)/stack.hpp
CFLAGS = -g -Wall -I$(INC)

EXE = $(BIN)/main

all: $(EXE)

$(EXE): $(OBJS) $(OBJ)/avaliador.o $(OBJ)/stack.o
	$(CC) -o $(EXE) $(OBJS) $(OBJ)/avaliador.o $(OBJ)/stack.o $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o -c $(SRC)/main.cpp 

$(OBJ)/avaliador.o: $(HDRS) $(SRC)/avaliador.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/avaliador.o -c $(SRC)/avaliador.cpp

$(OBJ)/stack.o: $(HDRS) $(SRC)/stack.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/stack.o -c $(SRC)/stack.cpp


run: $(EXE)
	./$(EXE)

clean:
	rm -f $(EXE) $(OBJ)/*.o
