
#ifndef PLATEAU_HPP
#define PLATEAU_HPP
#include "Case.hpp"

template <class T>
class Plateau{
private:
    int longueur;
    int largeur;
    Case<T>** plateau;
    //static Plateau<T> *instance;
    
    
public:
    Plateau<T>(int n,int m, Case<T>** p): longueur(n), largeur(m), plateau(p){};
    //static Plateau<T> *getInstance();
    void create(int n, int m);
    ~Plateau<T>();    
    int getLongueur(){ return longueur;}
    int getLargeur(){ return largeur;}
    void setLongueur(int n){longueur = n;}
    void setLargeur(int m){largeur = m;}
    
};

#endif /* PLATEAU_HPP */

