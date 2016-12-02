CPP = g++ -std=c++11 -Wall

all: main

main: main.cpp main.o Plateau.o Case.o
	$(CPP) -o main main.o Plateau.o Case.o

Plateau.o: Plateau.cpp Plateau.hpp Case.hpp
	$(CPP) -c  Plateau.cpp

Case.o: Case.cpp Case.hpp
	$(CPP) -c  Case.cpp

clean:
	rm -f *.o

mrproper: clean
	rm -f main
