#include "Plateau.cpp"
#include "DeuxMille48v1.hpp"

int main(int argc, char** argv) {
    cout << "Entrez la taille du plateau: " << endl;
    int c;
    cin >> c;
    DeuxMille48v1 v(c,c);
    cout << "Initialisation..." << endl;
    v.init();
    while (1) {
      cout << v << endl;
      v.keyPressed();
      v.deplacement();
    }
}
