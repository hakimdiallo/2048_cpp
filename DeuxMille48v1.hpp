#ifndef DEUXMILLE48V1
#define DEUXMILLE48V1

#include "BaseJeuAvecDeplacement.hpp"
//#include "NumberOrVide.hpp"

class DeuxMille48v1: public BaseJeuAvecDeplacement<int> {
//private:

public:
  DeuxMille48v1(int n, int m);
  virtual ~DeuxMille48v1();
  virtual Case<int>** plateau();
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
  /*virtual void moveLeft();
  virtual void moveLeft(int l, int c);
  virtual void moveDown();
  virtual void moveDown(int l, int c);
  virtual void moveUp();
  virtual void moveUp(int l, int c);
  virtual bool isOver();*/
};

#endif
