#include "BaseJeuAvecDeplacement.cpp"
#include "StupidRobot.hpp"

StupidRobot::StupidRobot(BaseJeuAvecDeplacement<int>& j): jeu(j){}

void StupidRobot::run() {
  jeu.init();
  cout << jeu << endl;
  while (!jeu.isOver()) {
    jeu.moveRight();
    cout << jeu << endl;
    //this_thread::sleep_for(chrono::milliseconds(5));
    jeu.moveLeft();
    cout << jeu << endl;
    //this_thread::sleep_for(chrono::milliseconds(5));
    jeu.moveUp();
    cout << jeu << endl;
    //this_thread::sleep_for(chrono::milliseconds(5));
    jeu.moveDown();
    cout << jeu << endl;
    //this_thread::sleep_for(chrono::milliseconds(5));
  }
}
