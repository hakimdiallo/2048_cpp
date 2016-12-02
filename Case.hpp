

#ifndef CASE_HPP
#define CASE_HPP

#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

template <class T> class Case {
private:
  T etat;

public:
  Case();
  Case(T t);
  T getEtat();
  void setEtat(T _etat);
};

template <class T> ostream& operator<<(ostream& out, Case<T>& c);

#endif /* CASE_HPP */
