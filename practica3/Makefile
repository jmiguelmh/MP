CC = g++
BIN = ./bin
DOC = ./doc
INCLUDE = ./include
LIB = ./lib
OBJ = ./obj
SRC = ./src

all : $(BIN)/mainPruebas

$(BIN)/mainPruebas : $(OBJ)/mainPruebas.o $(OBJ)/GestionArrays.o
	$(CC) -o $(BIN)/mainPruebas $(OBJ)/mainPruebas.o $(OBJ)/GestionArrays.o

$(OBJ)/mainPruebas.o : $(SRC)/mainPruebas.cpp $(INCLUDE)/GestionArrays.h
	$(CC) -c -I$(INCLUDE) -o $(OBJ)/mainPruebas.o $(SRC)/mainPruebas.cpp

$(OBJ)/GestionArrays.o : $(SRC)/GestionArrays.cpp $(INCLUDE)/GestionArrays.h
	$(CC) -c -I$(INCLUDE) -o $(OBJ)/GestionArrays.o $(SRC)/GestionArrays.cpp

clean :
	rm -f $(OBJ)/*.o
