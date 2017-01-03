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
  virtual int getLongueur() const;
  virtual int getLargeur() const;
  virtual void setLongueur(int n);
  virtual void setLargeur(int m);
  Case<T>& getCase(int l, int c) const;
  virtual void print(ostream& os) const = 0;
};

template <class T> ostream& operator<<(ostream& out, const Plateau<T>& p);

#endif /* PLATEAU_HPP */
