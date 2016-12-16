#ifndef BASEJEU
#define BASEJEU

#include "Plateau.hpp"

template <class T> class BaseJeuAvecDeplacement: public Plateau<T> {
private:

public:
  BaseJeuAvecDeplacement(int n, int m);
  virtual Case<T>** plateau();
  virtual bool canMoveRight() = 0;
  virtual bool canMoveRight(int l, int c) = 0;
  virtual bool canMoveLeft() = 0;
  virtual bool canMoveLeft(int l, int c) = 0;
  virtual bool canMoveDown() = 0;
  virtual bool canMoveDown(int l, int c) = 0;
  virtual bool canMoveUp() = 0;
  virtual bool canMoveUp(int l, int c) = 0;
  virtual void moveRight() = 0;
  virtual void moveRight(int l, int c) = 0;
  virtual void moveLeft() = 0;
  virtual void moveLeft(int l, int c) = 0;
  virtual void moveDown() = 0;
  virtual void moveDown(int l, int c) = 0;
  virtual void moveUp() = 0;
  virtual void moveUp(int l, int c) = 0;
  virtual bool isOver() = 0;
};

#endif
