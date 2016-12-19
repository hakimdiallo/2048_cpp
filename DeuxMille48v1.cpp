#include "BaseJeuAvecDeplacement.cpp"
#include "DeuxMille48v1.hpp"

DeuxMille48v1::DeuxMille48v1(int n, int m): BaseJeuAvecDeplacement<NumberOrVide>(n,m){
  //BaseJeuAvecDeplacement<NumberOrVide>(n,m);
}

DeuxMille48v1::~DeuxMille48v1(){}

Case<NumberOrVide>** DeuxMille48v1::plateau(){
  return BaseJeuAvecDeplacement<NumberOrVide>::plateau();
}

bool DeuxMille48v1::canMoveRight(int l, int c){
  if (c == largeur-1) {
    return false;
  }
  Case<NumberOrVide> case = getCase(l,c+1);
  if (case.getEtat() == NumberOrVide::Vide) {
    return true;
  }
  return false;
}

bool DeuxMille48v1::canMoveRight(){
  return false;
}

bool DeuxMille48v1::canMoveLeft(int l, int c){
  if (c == 0) {
    return false;
  }
  if (getCase(l,c-1).getEtat() == NumberOrVide::Vide) {
    return true;
  }
  return false;
}

bool DeuxMille48v1::canMoveLeft(){
  return false;
}

bool DeuxMille48v1::canMoveDown(int l, int c){
  if (l == longueur-1) {
    return false;
  }
  if (getCase(l+1,c).getEtat() == NumberOrVide::Vide) {
    return true;
  }
  return false;
}

bool DeuxMille48v1::canMoveDown(){
  return false;
}

bool DeuxMille48v1::canMoveUp(int l, int c){
  if (l == 0) {
    return false;
  }
  if (getCase(l-1,c).getEtat() == NumberOrVide::Vide) {
    return true;
  }
  return false;
}

bool DeuxMille48v1::canMoveUp(){
  return false;
}

void DeuxMille48v1::moveRight(){
  for (int i = 0; i < longueur; ++i) {
    for (int j = 0; j < largeur; ++j) {
      moveRight(i,j);
    }
  }
}

void DeuxMille48v1::moveRight(int l, int c){
  if (canMoveRight(l,c)) {
    for (int i = c; i < largeur; ++i) {

    }
  }
}
