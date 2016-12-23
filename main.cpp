#include "Plateau.cpp"
#include "DeuxMille48v2.hpp"
#include "Taquin.hpp"

int main(int argc, char** argv) {
    cout << "Entrez la taille du plateau: " << endl;
    int c;
    cin >> c;
    //DeuxMille48v2 v(c);
    Taquin v(c);
    cout << "Initialisation..." << endl;
    v.init();
    while (!v.isOver()) {
      cout << v << endl;
      v.keyPressed();
      v.deplacement();
    }
}
