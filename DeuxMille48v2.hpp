#ifndef DEUXMILLE48V2
#define DEUXMILLE48V2

#include "DeuxMille48v1.hpp"


class DeuxMille48v2: public DeuxMille48v1 {
//private:

public:
  char control;
  DeuxMille48v2(int n, int m);
  virtual void init();
  virtual void newNumber();
  virtual bool canMoveRight(int l, int c);
  virtual bool canMoveLeft(int l, int c);
  virtual bool canMoveDown(int l, int c);
  virtual bool canMoveUp(int l, int c);
  virtual void moveRight(int l, int c);
  virtual void moveLeft(int l, int c);
  virtual void moveDown(int l, int c);
  virtual void moveUp(int l, int c);
};

#endif
