#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include "Case.hpp"

template <class T> class Plateau{

private:
  int longueur;
  int largeur;
  //static Plateau<T> *instance;

public:
  Case<T>** plateau;
  Plateau(int n,int m);
  //static Plateau<T> *getInstance();
  void create(int n, int m);
  ~Plateau();
  int getLongueur(){ return longueur;}
  int getLargeur(){ return largeur;}
  void setLongueur(int n){longueur = n;}
  void setLargeur(int m){largeur = m;}
};

template <class T> ostream& operator<<(ostream& out, const Plateau<T>& p);

#endif /* PLATEAU_HPP */
