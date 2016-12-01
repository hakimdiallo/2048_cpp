#include <cstdlib>
#include "Plateau.hpp"

using namespace std;


int main(int argc, char** argv) {
    Case<int> c = new Case<int>(3);
    Plateau<Case> *p = new Plateau<Case>(10,10); 
    
    int i;
    int j;
    for(i = 0; i<*p.getLargeur(); i++){
        for(j=0; j<*p.getLongueur(); i++){
            *p[i] = c;
        }
    }
    
    
}

