#include "Case.hpp"

template <class T> Case<T>::Case(){}

template <class T> Case<T>::Case(T _etat): etat(_etat){}

template <class T> ostream& operator<<(ostream& out, Case<T>& c){
  return out << c.getEtat();
}

template <class T> T Case<T>::getEtat(){
  return etat;
}

template <class T> void Case<T>::setEtat(T _etat){
  etat = _etat;
}
