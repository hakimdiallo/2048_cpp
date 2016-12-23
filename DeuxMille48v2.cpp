#include "BaseJeuAvecDeplacement.cpp"
#include "DeuxMille48v2.hpp"
#include <ctime>

DeuxMille48v2::DeuxMille48v2(int n, int m): DeuxMille48v1(n,m){
  //BaseJeuAvecDeplacement<NumberOrVide>(n,m);
  srand((unsigned int) time (NULL));
}

DeuxMille48v2::~DeuxMille48v2(){}

Case<int>** DeuxMille48v2::plateau(){
  return DeuxMille48v2::plateau();
}

void DeuxMille48v2::init(){
  int l1 = rand()%longueur;
  int c1 = rand()%largeur;
  int l2 = rand()%longueur;
  int c2 = rand()%largeur;
  while(l1 == l2 && c1 == c2){
    l2 = rand()%longueur;
    c2 = rand()%largeur;
  }
  int r = rand()%4;
  if (r<3) {
    getCase(l1,c1).setEtat(2);
  }else{
    getCase(l1,c1).setEtat(4);
  }
  getCase(l2,c2).setEtat(2);


}

void DeuxMille48v2::newNumber(){
  int l = rand()%longueur;
  int c = rand()%largeur;
  while(getCase(l,c).getEtat() != 0){
    l = rand()%longueur;
    c = rand()%largeur;
  }
  int r = rand()%6;
  if (r<=2) {
    getCase(l,c).setEtat(2);
    }
  else if(r==3 || r==4){
    getCase(l,c).setEtat(-1);
        }
        else getCase(l,c).setEtat(4);
}

bool DeuxMille48v2::isOver(){
  for (int i = 0; i < longueur; ++i) {
    for (int j = 0; j < largeur; ++j) {
      if (getCase(i,j).getEtat() == 0) {
        return false;
      }
    }
  }
  return true;
}

bool DeuxMille48v2::canMoveRight(int l, int c){
  if (c == largeur-1) {
    return false;
  }
  Case<int> ca = getCase(l,c+1);
  if ((ca.getEtat() == 0 || ca.getEtat() == getCase(l,c).getEtat() || ca.getEtat() == -1 || getCase(l,c).getEtat() == -1)
        || (((ca.getEtat() == -1 || getCase(l,c).getEtat() == -1)) && ca.getEtat() != getCase(l,c).getEtat())) {
    return true;
  }
  return false;
}

bool DeuxMille48v2::canMoveRight(){
  return false;
}

bool DeuxMille48v2::canMoveLeft(int l, int c){
  if (c == 0) {
    return false;
  }
  Case<int> ca = getCase(l,c-1);
  if ((ca.getEtat() == 0 || ca.getEtat() == getCase(l,c).getEtat() || ca.getEtat() == -1 || getCase(l,c).getEtat() == -1)
        || (((ca.getEtat() == -1 || getCase(l,c).getEtat() == -1)) && ca.getEtat() != getCase(l,c).getEtat())) {
    return true;
  }
  return false;
}

bool DeuxMille48v2::canMoveLeft(){
  return false;
}

bool DeuxMille48v2::canMoveDown(int l, int c){
  if (l == longueur-1) {
    return false;
  }
  Case<int> ca = getCase(l+1,c);
  if ((ca.getEtat() == 0 || ca.getEtat() == getCase(l,c).getEtat() || ca.getEtat() == -1 || getCase(l,c).getEtat() == -1)
        || (((ca.getEtat() == -1 || getCase(l,c).getEtat() == -1)) && ca.getEtat() != getCase(l,c).getEtat())) {
    return true;
  }
  return false;
}

bool DeuxMille48v2::canMoveDown(){
  return false;
}

bool DeuxMille48v2::canMoveUp(int l, int c){
  if (l == 0) {
    return false;
  }
  Case<int> ca = getCase(l-1,c);
  if ((ca.getEtat() == 0 || ca.getEtat() == getCase(l,c).getEtat() || ca.getEtat() == -1 || getCase(l,c).getEtat() == -1)
        || (((ca.getEtat() == -1 || getCase(l,c).getEtat() == -1)) && ca.getEtat() != getCase(l,c).getEtat())) {
    return true;
  }
  return false;
}

bool DeuxMille48v2::canMoveUp(){
  return false;
}

void DeuxMille48v2::moveRight(){
  for (int i = 0; i < longueur; ++i) {
    for (int j = largeur-1; j >= 0; --j) {
      if (getCase(i,j).getEtat() != 0) {
        moveRight(i,j);
      }
    }
  }
  cleanMerge();
  newNumber();
}

void DeuxMille48v2::moveRight(int l, int c){
  if (canMoveRight(l,c)) {
    for (int i = c+1; i < largeur; ++i) {
      if(getCase(l,i).getEtat() == getCase(l,c).getEtat() && getCase(l,i).getEtat() != -1 && getCase(l,c).getEtat() != -1 && getCase(l,i).canMerge()){
        getCase(l,i).setEtat(getCase(l,i).getEtat()*2);
        getCase(l,c).setEtat(0);
        getCase(l,i).setCanMerge(false);
        return;
      }
      else if (getCase(l,i).getEtat() == getCase(l,c).getEtat() && !getCase(l,i).canMerge()) {
        getCase(l,i-1).setEtat(getCase(l,c).getEtat());
        getCase(l,c).setEtat(0);
        return;
      }
      else if(getCase(l,i).getEtat() != 0 && getCase(l,c).getEtat() == -1){
        //getCase(l,i-1).setEtat(0);
        getCase(l,c).setEtat(0);
        getCase(l,i).setEtat(0);
        return;
      }
      else if(getCase(l,i).getEtat() == -1 && getCase(l,c).getEtat() != 0){
        getCase(l,i+1).setEtat(0);
        getCase(l,c).setEtat(0);
        getCase(l,i).setEtat(0);
        return;
      }
      else if(getCase(l,i).getEtat() != getCase(l,c).getEtat() && getCase(l,i).getEtat() != 0){
        getCase(l,i-1).setEtat(getCase(l,c).getEtat());
        getCase(l,c).setEtat(0);
        return;
      }


    }
    getCase(l,largeur-1).setEtat(getCase(l,c).getEtat());
    getCase(l,c).setEtat(0);
  }
}

void DeuxMille48v2::moveLeft(){
  for (int i = 0; i < longueur; ++i) {
    for (int j = 0; j < largeur; ++j) {
      if (getCase(i,j).getEtat() != 0) {
        moveLeft(i,j);
      }
    }
  }
  cleanMerge();
  newNumber();
}

void DeuxMille48v2::moveLeft(int l, int c){
  if (canMoveLeft(l,c)) {
    for (int i = c-1; i >= 0; --i) {
      if(getCase(l,i).getEtat() == getCase(l,c).getEtat() && getCase(l,i).getEtat() != -1 && getCase(l,c).getEtat() != -1 && getCase(l,i).canMerge()){
        getCase(l,i).setEtat(getCase(l,i).getEtat()*2);
        getCase(l,c).setEtat(0);
        getCase(l,i).setCanMerge(false);
        return;
      }
      else if (getCase(l,i).getEtat() == getCase(l,c).getEtat() && !getCase(l,i).canMerge()) {
        getCase(l,i+1).setEtat(getCase(l,c).getEtat());
        getCase(l,c).setEtat(0);
        return;
      }
      else if(getCase(l,c).getEtat() != 0 && getCase(l,i).getEtat() == -1){
        getCase(l,i+1).setEtat(0);
        getCase(l,c).setEtat(0);
        getCase(l,i).setEtat(0);
        return;
      }
      else if(getCase(l,c).getEtat() == -1 && getCase(l,i).getEtat() != 0){
        //getCase(l,i-1).setEtat(0);
        getCase(l,c).setEtat(0);
        getCase(l,i).setEtat(0);
        return;
      }
      else if(getCase(l,i).getEtat() != getCase(l,c).getEtat() && getCase(l,i).getEtat() != 0){
        getCase(l,i+1).setEtat(getCase(l,c).getEtat());
        getCase(l,c).setEtat(0);
        return;
      }
    }
    getCase(l,0).setEtat(getCase(l,c).getEtat());
    getCase(l,c).setEtat(0);
  }
}

void DeuxMille48v2::moveDown(){
  for (int j = 0; j < largeur; ++j) {
    for (int i = longueur-1; i >= 0; --i) {
      if (getCase(i,j).getEtat() != 0) {
        moveDown(i,j);
      }
    }
  }
  cleanMerge();
  newNumber();
}

void DeuxMille48v2::moveDown(int l, int c){
  if (canMoveDown(l,c)) {
    for (int i = l+1; i < longueur; ++i) {
      if(getCase(i,c).getEtat() == getCase(l,c).getEtat() && getCase(i,c).getEtat() != -1 && getCase(l,c).getEtat() != -1 && getCase(i,c).canMerge()){
        getCase(i,c).setEtat(getCase(i,c).getEtat()*2);
        getCase(l,c).setEtat(0);
        getCase(i,c).setCanMerge(false);
        return;
      }
      else if (getCase(i,c).getEtat() == getCase(l,c).getEtat() && !getCase(i,c).canMerge()) {
        getCase(i-1,c).setEtat(getCase(l,c).getEtat());
        getCase(l,c).setEtat(0);
        return;
      }
      else if(getCase(i,c).getEtat() != 0 && getCase(l,c).getEtat() == -1){
        //getCase(i+1,c).setEtat(0);
        getCase(l,c).setEtat(0);
        getCase(i,c).setEtat(0);
        return;
      }
      else if(getCase(i,c).getEtat() == -1 && getCase(l,c).getEtat() != 0){
        getCase(i-1,c).setEtat(0);
        getCase(l,c).setEtat(0);
        getCase(i,c).setEtat(0);
        return;
      }
      else if(getCase(i,c).getEtat() != getCase(l,c).getEtat() && getCase(i,c).getEtat() != 0){
        getCase(i-1,c).setEtat(getCase(l,c).getEtat());
        getCase(l,c).setEtat(0);
        return;
      }
    }
    getCase(longueur-1,c).setEtat(getCase(l,c).getEtat());
    getCase(l,c).setEtat(0);
  }
}

void DeuxMille48v2::moveUp(){
  for (int j = 0; j < largeur; ++j) {
    for (int i = 0; i < longueur; ++i) {
      if (getCase(i,j).getEtat() != 0) {
        moveUp(i,j);
      }
    }
  }
  cleanMerge();
  newNumber();
}

void DeuxMille48v2::moveUp(int l, int c){
  if (canMoveUp(l,c)) {
    for (int i = l-1; i >= 0; --i) {
      if(getCase(i,c).getEtat() == getCase(l,c).getEtat() && getCase(i,c).getEtat() != -1 && getCase(l,c).getEtat() != -1 && getCase(l,c).getEtat() && getCase(i,c).canMerge()){
        getCase(i,c).setEtat(getCase(i,c).getEtat()*2);
        getCase(l,c).setEtat(0);
        getCase(i,c).setCanMerge(false);
        return;
      }
      else if (getCase(i,c).getEtat() == getCase(l,c).getEtat() && !getCase(i,c).canMerge()) {
        getCase(i+1,c).setEtat(getCase(l,c).getEtat());
        getCase(l,c).setEtat(0);
        return;
      }
      else if(getCase(l,c).getEtat() != 0 && getCase(i,c).getEtat() == -1){
        getCase(i+1,c).setEtat(0);
        getCase(l,c).setEtat(0);
        getCase(i,c).setEtat(0);
        return;
      }
      else if(getCase(l,c).getEtat() == -1 && getCase(i,c).getEtat() != 0){
        getCase(l,c).setEtat(0);
        getCase(i,c).setEtat(0);
        return;
      }

      else if(getCase(i,c).getEtat() != getCase(l,c).getEtat() && getCase(i,c).getEtat() != 0){
        getCase(i+1,c).setEtat(getCase(l,c).getEtat());
        getCase(l,c).setEtat(0);
        return;
      }


    }
    getCase(0,c).setEtat(getCase(l,c).getEtat());
    getCase(l,c).setEtat(0);
  }
}

void DeuxMille48v2::cleanMerge(){
  for (int j = 0; j < largeur; ++j) {
    for (int i = 0; i < longueur; ++i) {
      getCase(i,j).setCanMerge(true);
    }
  }
}

void DeuxMille48v2::keyPressed(){
  cin >> control;
}

void DeuxMille48v2::deplacement(){
  switch (control) {
    case 'z':
      moveUp();
      break;
    case 'q':
      moveLeft();
      break;
    case 's':
      moveDown();
      break;
    case 'd':
      moveRight();
      break;
    default:
    cout << "WRONG KEY!!! PRESS: s, q, z or d ONLY..." << endl;
  }
}
