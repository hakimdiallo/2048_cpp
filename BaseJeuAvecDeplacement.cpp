#include "Plateau.cpp"
#include "BaseJeuAvecDeplacement.hpp"

template <class T> BaseJeuAvecDeplacement<T>::BaseJeuAvecDeplacement(int n, int m): Plateau<T>(n,m){}

template <class T> BaseJeuAvecDeplacement<T>::~BaseJeuAvecDeplacement(){}

template <class T> Case<T>** BaseJeuAvecDeplacement<T>::plateau(){
  return Plateau<T>::plateau;
}
