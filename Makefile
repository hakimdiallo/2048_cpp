CPP = g++ -std=c++11 -Wall

all: main

main: main.cpp main.o Taquin.o DeuxMille48v2.o DeuxMille48v1.o BaseJeuAvecDeplacement.o Plateau.o Case.o
	$(CPP) -o main main.o Taquin.o DeuxMille48v2.o DeuxMille48v1.o BaseJeuAvecDeplacement.o Plateau.o Case.o

Taquin.o: Taquin.cpp Taquin.hpp BaseJeuAvecDeplacement.hpp
	$(CPP) -c  Taquin.cpp

DeuxMille48v2.o: DeuxMille48v2.cpp DeuxMille48v2.hpp DeuxMille48v1.cpp DeuxMille48v1.hpp BaseJeuAvecDeplacement.hpp
	$(CPP) -c  DeuxMille48v2.cpp

DeuxMille48v1.o: DeuxMille48v1.cpp DeuxMille48v1.hpp BaseJeuAvecDeplacement.hpp
	$(CPP) -c  DeuxMille48v1.cpp

BaseJeuAvecDeplacement.o: BaseJeuAvecDeplacement.cpp BaseJeuAvecDeplacement.hpp Plateau.hpp
	$(CPP) -c BaseJeuAvecDeplacement.cpp

Plateau.o: Plateau.cpp Plateau.hpp Case.hpp
	$(CPP) -c  Plateau.cpp

Case.o: Case.cpp Case.hpp
	$(CPP) -c  Case.cpp

clean:
	rm -f *.o

mrproper: clean
	rm -f main
