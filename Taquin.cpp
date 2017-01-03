#include "Taquin.hpp"
#include <algorithm>

Taquin::Taquin(int n): BaseJeuAvecDeplacement<int>(n,n){
  ligne = n-1;
  colonne = n-1;
}

bool Taquin::canMoveRight(int l, int c){
    if (l < longueur && c < largeur && getCase(l,c).getEtat() == 0 && c != 0) {
      return true;
    }
    return false;
}

bool Taquin::canMoveLeft(int l, int c){
    if (l < longueur && c < largeur && getCase(l,c).getEtat() == 0 && c != largeur-1) {
      return true;
    }
    return false;
}

bool Taquin::canMoveDown(int l, int c){
    if (l < longueur && c < largeur && getCase(l,c).getEtat() == 0 && l != 0) {
      return true;
    }
    return false;
}

bool Taquin::canMoveUp(int l, int c){
    if (l < longueur && c < largeur && getCase(l,c).getEtat() == 0 && l != longueur-1) {
      return true;
    }
    return false;
}

void Taquin::moveRight(int l, int c){
  if (canMoveRight(l,c)) {
    int tmp = getCase(l,c-1).getEtat();
    getCase(l,c-1).setEtat(0);
    getCase(l,c).setEtat(tmp);
    colonne = c-1;
  }
}

void Taquin::moveLeft(int l, int c){
  if (canMoveLeft(l,c)) {
    int tmp = getCase(l,c+1).getEtat();
    getCase(l,c+1).setEtat(0);
    getCase(l,c).setEtat(tmp);
    colonne = c+1;
  }
}

void Taquin::moveDown(int l, int c){
  if (canMoveDown(l,c)) {
    int tmp = getCase(l-1,c).getEtat();
    getCase(l-1,c).setEtat(0);
    getCase(l,c).setEtat(tmp);
    ligne = l-1;
  }
}

void Taquin::moveUp(int l, int c){
  if (canMoveUp(l,c)) {
    int tmp = getCase(l+1,c).getEtat();
    getCase(l+1,c).setEtat(0);
    getCase(l,c).setEtat(tmp);
    ligne = l+1;
  }
}

void Taquin::moveRight(){
  moveRight(ligne,colonne);
}

void Taquin::moveLeft(){
  moveLeft(ligne,colonne);
}

void Taquin::moveDown(){
  moveDown(ligne,colonne);
}

void Taquin::moveUp(){
  moveUp(ligne,colonne);
}

int myrandom(int i){
  return rand()%i;
}

void Taquin::init(){
  int count = (longueur*longueur);
  int tab[count];
  for (int i = 0; i < count-1; ++i) {
    tab[i] = i+1;
  }
  tab[count-1] = 0;
  random_shuffle(&tab[0],&tab[count-1],myrandom);
  int k = 0;
  for (int i = 0; i < longueur; ++i) {
    for (int j = 0; j < largeur; ++j) {
      getCase(i,j).setEtat(tab[k++]);
    }
  }
}

bool Taquin::isOver(){
  int count = (longueur*longueur);
  int tab[count];
  int k = 0;
  for (int i = 0; i < longueur; ++i) {
    for (int j = 0; j < largeur; ++j) {
      tab[k++] = getCase(i,j).getEtat();
    }
  }
  return is_sorted(&tab[0],&tab[count-2]);
}

void Taquin::print(ostream& out) const{
  for (int i = 0; i < longueur; ++i) {
    for (int j = 0; j < largeur; ++j) {
      if (getCase(i,j).getEtat() == 0) {
        out << "|    ";
      }
      else if (getCase(i,j).getEtat() >= 10) {
        out << "| " << getCase(i,j) << " ";
      }
      else {
        out << "| " << getCase(i,j) << "  ";
      }
    }
    out << "|" << endl;
  }
  //return out;
}
