

#ifndef CASE_HPP
#define CASE_HPP

#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

template <class T>
class Case{
    
private:
    T etat;       
        
public : 
    Case<T>();
    Case<T>(T& t);
    T getEtat();
};

#endif /* CASE_HPP */

