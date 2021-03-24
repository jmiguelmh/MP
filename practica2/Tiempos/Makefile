CC = g++
BIN = ./bin
DOC = ./doc
INCLUDE = ./include
LIB = ./lib
OBJ = ./obj
SRC = ./src

all : $(BIN)/prueba

$(BIN)/prueba : $(OBJ)/prueba.o $(OBJ)/tiempo.o
	$(CC) -o $(BIN)/prueba $(OBJ)/prueba.o $(OBJ)/tiempo.o

$(OBJ)/prueba.o : $(SRC)/prueba.cpp $(INCLUDE)/tiempo.h
	$(CC) -c -I$(INCLUDE) -o $(OBJ)/prueba.o $(SRC)/prueba.cpp

$(OBJ)/tiempo.o : $(SRC)/tiempo.cpp $(INCLUDE)/tiempo.h
	$(CC) -c -I$(INCLUDE) -o $(OBJ)/tiempo.o $(SRC)/tiempo.cpp

clean :
	rm -f $(OBJ)/*.o