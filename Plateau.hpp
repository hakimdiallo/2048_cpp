
#ifndef PLATEAU_HPP
#define PLATEAU_HPP
#include "Case.hpp"

template <class T>
class Plateau{
private:
    int longueur;
    int largeur;
    Case<T>** plateau;
    static Plateau<T> *instance;
    Plateau<T>(int n,int m);
    
public:
    static Plateau<T> *getInstance();
    void create(int n, int m);
    ~Plateau<T>();    
    int getLongueur(){ return longueur;}
    int getLargeur(){ return largeur;}
    
};

#endif /* PLATEAU_HPP */

