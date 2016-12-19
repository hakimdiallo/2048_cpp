#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include "Case.hpp"

template <class T> class Plateau{

protected:
  int longueur;
  int largeur;
  //static Plateau<T> *instance;

public:
  Case<T>** plateau;
  Plateau(int n,int m);
  //static Plateau<T> *getInstance();
  //virtual void create(int n, int m);
  virtual ~Plateau();
  virtual int getLongueur();
  virtual int getLargeur();
  virtual void setLongueur(int n);
  virtual void setLargeur(int m);
  Case<T>& getCase(int l, int c);
};

template <class T> ostream& operator<<(ostream& out, const Plateau<T>& p);

#endif /* PLATEAU_HPP */
