#ifndef STUPIDROBOT
#define STUPIDROBOT

#include "DeuxMille48v1.hpp"
#include "DeuxMille48v2.hpp"
//#include <thread>
//#include <chrono>

class StupidRobot{
private:
  BaseJeuAvecDeplacement<int>& jeu;

public:
  StupidRobot(BaseJeuAvecDeplacement<int>& j);
  void run();
};

#endif
