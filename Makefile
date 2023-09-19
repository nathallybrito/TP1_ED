#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa de avaliador de expressões
# Autor		: Náthally Fernandes
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#               : make prof - faz medidas de tempo de desempenho
#               : make gprof - ilustra uso do gprof para depuração
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/avaliador.o 
HDRS = $(INC)/avaliador.h  
CFLAGS = -pg -Wall -c -I$(INC)

EXE = $(BIN)/main

all: run EXE

run: $(EXE)

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS) -lstdc++

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/avaliador.o: $(HDRS) $(SRC)/avaliador.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/avaliador.o $(SRC)/avaliador.cpp


clean:
	rm -f $(EXE) $(OBJS) 
