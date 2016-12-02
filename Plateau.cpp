#include "Case.cpp"
#include "Plateau.hpp"

template <class T> Plateau<T>::Plateau(int n, int m): longueur(n), largeur(m){
  plateau = new Case<T>*[n];
  for (int i = 0; i < n; ++i) {
    plateau[i] = new Case<T>[m];
    //for (int j = 0; j < m; ++j) {
      //plateau[i][j](etat_zero);
    //}
  }
}

template <class T> Plateau<T>::~Plateau(){
  for (int i = 0; i < longueur; i++) {
    delete [] plateau[i];
  }
  delete [] plateau;
}

template <class T> ostream& operator<<(ostream& out, Plateau<T>& p){
  for (int i = 0; i < p.getLongueur(); ++i) {
    for (int j = 0; j < p.getLargeur(); ++j) {
      out << "| " << p.plateau[i][j] << " ";
    }
    out << "|" << endl;
  }
  return out;
}
