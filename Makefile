CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o 
HDRS = $(INC)/avaliador.h
CFLAGS = -g -Wall -c -I$(INC)


EXE = $(BIN)/main

all: run EXE

run: $(EXE)

$(BIN)/main: $(OBJS) $(SRC)/avaliador.cpp
	$(CC) -g -o $(BIN)/main $(OBJS) $(SRC)/avaliador.cpp $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

clean:
	rm -f $(EXE) $(OBJ)/*.o
