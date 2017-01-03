CPP = g++
CFLAGS = -std=c++11 -Wall

all: main

main: main.cpp main.o StupidRobot.o Taquin.o DeuxMille48v2.o DeuxMille48v1.o BaseJeuAvecDeplacement.o Plateau.o Case.o
	$(CPP) -o main main.o StupidRobot.o Taquin.o DeuxMille48v2.o DeuxMille48v1.o BaseJeuAvecDeplacement.o Plateau.o Case.o $(CFLAGS)

StupidRobot.o: StupidRobot.cpp StupidRobot.hpp DeuxMille48v2.hpp
	$(CPP) -c  StupidRobot.cpp $(CFLAGS)

Taquin.o: Taquin.cpp Taquin.hpp BaseJeuAvecDeplacement.hpp
	$(CPP) -c  Taquin.cpp $(CFLAGS)

DeuxMille48v2.o: DeuxMille48v2.cpp DeuxMille48v2.hpp DeuxMille48v1.cpp DeuxMille48v1.hpp BaseJeuAvecDeplacement.hpp
	$(CPP) -c  DeuxMille48v2.cpp $(CFLAGS)

DeuxMille48v1.o: DeuxMille48v1.cpp DeuxMille48v1.hpp BaseJeuAvecDeplacement.hpp
	$(CPP) -c  DeuxMille48v1.cpp $(CFLAGS)

BaseJeuAvecDeplacement.o: BaseJeuAvecDeplacement.cpp BaseJeuAvecDeplacement.hpp Plateau.hpp
	$(CPP) -c BaseJeuAvecDeplacement.cpp $(CFLAGS)

Plateau.o: Plateau.cpp Plateau.hpp Case.hpp
	$(CPP) -c  Plateau.cpp $(CFLAGS)

Case.o: Case.cpp Case.hpp
	$(CPP) -c  Case.cpp $(CFLAGS)

clean:
	rm -f *.o

mrproper: clean
	rm -f main
