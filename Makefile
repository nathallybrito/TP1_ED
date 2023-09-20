CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o 
HDRS = $(INC)/avaliador.hpp
CFLAGS = -g -Wall -I$(INC)

EXE = $(BIN)/main

all: $(EXE)

$(EXE): $(OBJS) $(OBJ)/avaliador.o
	$(CC) -o $(EXE) $(OBJS) $(OBJ)/avaliador.o $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o -c $(SRC)/main.cpp 

$(OBJ)/avaliador.o: $(HDRS) $(SRC)/avaliador.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/avaliador.o -c $(SRC)/avaliador.cpp

run: $(EXE)
	./$(EXE)

clean:
	rm -f $(EXE) $(OBJ)/*.o
