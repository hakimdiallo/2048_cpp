

#ifndef CASE_HPP
#define CASE_HPP

#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

template <class T> class Case {
private:
  T etat;
  bool merge;

public:
  Case();
  Case(T t);
  T getEtat();
  bool canMerge();
  void setEtat(T _etat);
  void setCanMerge(bool b);
};

template <class T> ostream& operator<<(ostream& out, Case<T>& c);

#endif /* CASE_HPP */
