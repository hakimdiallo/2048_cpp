#ifndef DEUXMILLE48V2
#define DEUXMILLE48V2

#include "DeuxMille48v1.hpp"


class DeuxMille48v2: public DeuxMille48v1 {
//private:

public:
  char control;
  DeuxMille48v2(int n, int m);
  void keyPressed();
  void deplacement();
  virtual ~DeuxMille48v2();
  virtual Case<int>** plateau();
  virtual void init();
  void newNumber();
  void cleanMerge();
  virtual bool canMoveRight();
  virtual bool canMoveRight(int l, int c);
  virtual bool canMoveLeft();
  virtual bool canMoveLeft(int l, int c);
  virtual bool canMoveDown();
  virtual bool canMoveDown(int l, int c);
  virtual bool canMoveUp();
  virtual bool canMoveUp(int l, int c);
  virtual void moveRight();
  virtual void moveRight(int l, int c);
  virtual void moveLeft();
  virtual void moveLeft(int l, int c);
  virtual void moveDown();
  virtual void moveDown(int l, int c);
  virtual void moveUp();
  virtual void moveUp(int l, int c);
  virtual bool isOver();
};

#endif
