CC = g++
BIN = ./bin
DOC = ./doc
INCLUDE = ./include
LIB = ./lib
OBJ = ./obj
SRC = ./src

all : $(BIN)/prueba

$(BIN)/prueba : $(OBJ)/prueba.o $(OBJ)/contenedor.o
	$(CC) -o $(BIN)/prueba $(OBJ)/prueba.o $(OBJ)/contenedor.o

$(OBJ)/prueba.o : $(SRC)/prueba.cpp $(INCLUDE)/contenedor.h
	$(CC) -c -I$(INCLUDE) -o $(OBJ)/prueba.o $(SRC)/prueba.cpp

$(OBJ)/contenedor.o : $(SRC)/contenedor.cpp $(INCLUDE)/contenedor.h
	$(CC) -c -I$(INCLUDE) -o $(OBJ)/contenedor.o $(SRC)/contenedor.cpp

clean :
	rm -f $(OBJ)/*.o