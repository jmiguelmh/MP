all : bin/demo2

bin/demo2 : obj/demo2.o obj/oper2.o
	g++ -o bin/demo2 obj/demo2.o obj/oper2.o

obj/demo2.o : src/demo2.cpp include/oper2.h
	g++ -c -I./include -o obj/demo2.o src/demo2.cpp

obj/oper2.o : src/oper2.cpp include/oper2.h
	g++ -c -I./include -o obj/oper2.o src/oper2.cpp

clean :
	rm obj/*.o