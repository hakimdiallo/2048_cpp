//#include "Plateau.cpp"
#include "DeuxMille48v1.cpp"

int main(int argc, char** argv) {
    Case<int> c(4);
    Case<int> c7;
    c7.setEtat(7);
    Plateau<int> p(10,10);
    p.plateau[8][7] = c;
    p.plateau[5][3] = c7;
    cout << p << endl;
    DeuxMille48v1 v(4,4);
}
