#ifndef TAQUIN
#define TAQUIN

#include "BaseJeuAvecDeplacement.hpp"

class Taquin: public BaseJeuAvecDeplacement<int> {
private:
  int ligne;
  int colonne;

public:
  Taquin(int n);
  virtual void init();
  virtual bool canMoveRight(int l, int c);
  virtual bool canMoveLeft(int l, int c);
  virtual bool canMoveDown(int l, int c);
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
  virtual void print(ostream& os) const;
};

#endif
