CC = g++
BIN = ./bin
DOC = ./doc
INCLUDE = ./include
LIB = ./lib
OBJ = ./obj
SRC = ./src

all : $(BIN)/central

$(BIN)/central : $(OBJ)/central.o $(OBJ)/punto2d.o $(OBJ)/circulo.o
	$(CC) -o $(BIN)/central $(OBJ)/central.o $(OBJ)/punto2d.o $(OBJ)/circulo.o

$(OBJ)/central.o : $(SRC)/central.cpp $(INCLUDE)/punto2d.h $(INCLUDE)/circulo.h
	$(CC) -c -I$(INCLUDE) -o $(OBJ)/central.o $(SRC)/central.cpp

$(OBJ)/punto2d.o : $(SRC)/punto2d.cpp $(INCLUDE)/punto2d.h
	$(CC) -c -I$(INCLUDE) -o $(OBJ)/punto2d.o $(SRC)/punto2d.cpp

$(OBJ)/circulo.o : $(SRC)/circulo.cpp $(INCLUDE)/circulo.h
	$(CC) -c -I$(INCLUDE) -o $(OBJ)/circulo.o $(SRC)/circulo.cpp

clean :
	rm $(OBJ)/*.o