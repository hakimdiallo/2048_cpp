#include "Plateau.cpp"
#include "BaseJeuAvecDeplacement.hpp"

template <class T> BaseJeuAvecDeplacement<T>::BaseJeuAvecDeplacement(int n, int m): Plateau<T>(n,m){}

template <class T> BaseJeuAvecDeplacement<T>::~BaseJeuAvecDeplacement(){}

template <class T> Case<T>** BaseJeuAvecDeplacement<T>::plateau(){
  return Plateau<T>::plateau;
}
template <class T> void BaseJeuAvecDeplacement<T>::keyPressed(){
  cin >> control;
}

template <class T> void BaseJeuAvecDeplacement<T>::deplacement(){
  switch (control) {
    case 'z':
      moveUp();
      break;
    case 'q':
      moveLeft();
      break;
    case 's':
      moveDown();
      break;
    case 'd':
      moveRight();
      break;
    default:
    cout << "WRONG KEY!!! PRESS: s, q, z or d ONLY..." << endl;
  }
}
