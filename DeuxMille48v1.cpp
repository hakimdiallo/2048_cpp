#include "BaseJeuAvecDeplacement.cpp"
#include "DeuxMille48v1.hpp"
#include <ctime>

DeuxMille48v1::DeuxMille48v1(int n): BaseJeuAvecDeplacement<int>(n,n){
  //BaseJeuAvecDeplacement<NumberOrVide>(n,m);
  srand((unsigned int) time (NULL));
}

void DeuxMille48v1::init(){
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

void DeuxMille48v1::newNumber(){
  int l = rand()%longueur;
  int c = rand()%largeur;
  while(getCase(l,c).getEtat() != 0){
    l = rand()%longueur;
    c = rand()%largeur;
  }
  int r = rand()%4;
  if (r<3) {
    getCase(l,c).setEtat(2);
  }else{
    getCase(l,c).setEtat(4);
  }
}

bool DeuxMille48v1::isOver(){
  for (int i = 0; i < longueur; ++i) {
    for (int j = 0; j < largeur; ++j) {
      if (getCase(i,j).getEtat() == 0 || canMoveRight(i,j) || canMoveLeft(i,j) || canMoveDown(i,j) || canMoveUp(i,j)) {
        return false;
      }
    }
  }
  return true;
}

bool DeuxMille48v1::canMoveRight(int l, int c){
  if (c == largeur-1) {
    return false;
  }
  Case<int> ca = getCase(l,c+1);
  if (ca.getEtat() == 0 || ca.getEtat() == getCase(l,c).getEtat()) {
    return true;
  }
  return false;
}

bool DeuxMille48v1::canMoveLeft(int l, int c){
  if (c == 0) {
    return false;
  }
  if (getCase(l,c-1).getEtat() == 0 || getCase(l,c).getEtat() == getCase(l,c-1).getEtat()) {
    return true;
  }
  return false;
}

bool DeuxMille48v1::canMoveDown(int l, int c){
  if (l == longueur-1) {
    return false;
  }
  if (getCase(l+1,c).getEtat() == 0 || getCase(l,c).getEtat() == getCase(l+1,c).getEtat()) {
    return true;
  }
  return false;
}

bool DeuxMille48v1::canMoveUp(int l, int c){
  if (l == 0) {
    return false;
  }
  if (getCase(l-1,c).getEtat() == 0 || getCase(l,c).getEtat() == getCase(l-1,c).getEtat()) {
    return true;
  }
  return false;
}

void DeuxMille48v1::moveRight(){
  bool move = false;
  for (int i = 0; i < longueur; ++i) {
    for (int j = largeur-1; j >= 0; --j) {
      if (getCase(i,j).getEtat() != 0) {
        if (canMoveRight(i,j)) {
          moveRight(i,j);
          move = true;
        }
      }
    }
  }
  if(move){
    cleanMerge();
    newNumber();
  }
}

void DeuxMille48v1::moveRight(int l, int c){
  if (canMoveRight(l,c)) {
    for (int i = c+1; i < largeur; ++i) {
      if(getCase(l,i).getEtat() == getCase(l,c).getEtat() && getCase(l,i).canMerge()){
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

void DeuxMille48v1::moveLeft(){
  bool move = false;
  for (int i = 0; i < longueur; ++i) {
    for (int j = 0; j < largeur; ++j) {
      if (getCase(i,j).getEtat() != 0) {
        if (canMoveLeft(i,j)) {
          moveLeft(i,j);
          move = true;
        }
      }
    }
  }
  if(move){
    cleanMerge();
    newNumber();
  }
}

void DeuxMille48v1::moveLeft(int l, int c){
  if (canMoveLeft(l,c)) {
    for (int i = c-1; i >= 0; --i) {
      if(getCase(l,i).getEtat() == getCase(l,c).getEtat() && getCase(l,i).canMerge()){
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

void DeuxMille48v1::moveDown(){
  bool move = false;
  for (int j = 0; j < largeur; ++j) {
    for (int i = longueur-1; i >= 0; --i) {
      if (getCase(i,j).getEtat() != 0) {
        if (canMoveDown(i,j)) {
          moveDown(i,j);
          move = true;
        }
      }
    }
  }
  if (move) {
    cleanMerge();
    newNumber();
  }
}

void DeuxMille48v1::moveDown(int l, int c){
  if (canMoveDown(l,c)) {
    for (int i = l+1; i < longueur; ++i) {
      if(getCase(i,c).getEtat() == getCase(l,c).getEtat() && getCase(i,c).canMerge()){
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

void DeuxMille48v1::moveUp(){
  bool move = false;
  for (int j = 0; j < largeur; ++j) {
    for (int i = 0; i < longueur; ++i) {
      if (getCase(i,j).getEtat() != 0) {
        if (canMoveUp(i,j)) {
          moveUp(i,j);
          move = true;
        }
      }
    }
  }
  if (move) {
    cleanMerge();
    newNumber();
  }
}

void DeuxMille48v1::moveUp(int l, int c){
  if (canMoveUp(l,c)) {
    for (int i = l-1; i >= 0; --i) {
      if(getCase(i,c).getEtat() == getCase(l,c).getEtat() && getCase(i,c).canMerge()){
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

void DeuxMille48v1::cleanMerge(){
  for (int j = 0; j < largeur; ++j) {
    for (int i = 0; i < longueur; ++i) {
      getCase(i,j).setCanMerge(true);
    }
  }
}

void DeuxMille48v1::print(ostream& out) const {
  for (int i = 0; i < longueur; ++i) {
    for (int j = 0; j < largeur; ++j) {
      if (getCase(i,j).getEtat() == 0) {
        out << "|      ";
      }
      else if (getCase(i,j).getEtat() >= 10 && getCase(i,j).getEtat() < 100) {
        out << "| " << getCase(i,j) << "   ";
      }
      else if (getCase(i,j).getEtat() >= 100 && getCase(i,j).getEtat() < 1000) {
        out << "| " << getCase(i,j) << "  ";
      }
      else if (getCase(i,j).getEtat() >= 1000) {
        out << "| " << getCase(i,j) << " ";
      }
      else if (getCase(i,j).getEtat() == -1) {
        out << "| D    ";
      }
      else if (getCase(i,j).getEtat() == -2){
        out << "| x2    ";
      }
      else {
        out << "| " << getCase(i,j) << "    ";
      }
    }
    out << "|" << endl;
  }
  //return out;
}
