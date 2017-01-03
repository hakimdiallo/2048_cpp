#include "Plateau.cpp"
#include "DeuxMille48v2.hpp"
#include "Taquin.hpp"
#include "StupidRobot.hpp"

void menu_choix_jeu();

void play_manual(BaseJeuAvecDeplacement<int>& jeu){
  cout << "Initialisation..." << endl;
  jeu.init();
  while (!jeu.isOver()) {
    cout << jeu << endl;
    jeu.keyPressed();
    jeu.deplacement();
  }
}

void play_robot(BaseJeuAvecDeplacement<int>& jeu) {
  StupidRobot sr(jeu);
  sr.run();
}

void play(BaseJeuAvecDeplacement<int>& jeu) {
  int a;
  cout << "Comment?" << endl;
  cout << "Tapez 1 pour jouer manuellement" << endl;
  cout << "Tapez 2 pour lancer le robot" << endl;
  cout << "Tapez 3 pour retourner au choix du jeu" << endl;
  cin >> a;
  if (a == 1) {
    play_manual(jeu);
  }else if (a == 2) {
    play_robot(jeu);
  }else if (a == 3) {
    menu_choix_jeu();
  }
}

void menu_choix_jeu(){
  int a;
  cout << "Choisir le jeu " << endl;
  cout << "Tapez 1 pour 2048 classique" << endl;
  cout << "Tapez 2 pour 2048 v2" << endl;
  cout << "Tapez 3 pour Taquin" << endl;
  cout << "Tapez 4 pour Quitter le menu" << endl;
  cin >> a;
    int c;
  if(a == 1){
    cout << "Entrez la taille du plateau: " << endl;
    cin >> c;
    DeuxMille48v1 v1(c);
    play(v1);
  }
  else if(a == 2){
    cout << "Entrez la taille du plateau: " << endl;
    cin >> c;
    DeuxMille48v2 v2(c);
    play(v2);
  }
  else if (a == 3){
    cout << "Entrez la taille du plateau: " << endl;
    cin >> c;
    Taquin v3(c);
    play(v3);
  }else{
    cout << "Bye...! " << endl;
    exit(0);
  }

}

int main(int argc, char** argv) {
    /*cout << "Entrez la taille du plateau: " << endl;
    int c;
    cin >> c;
    DeuxMille48v2 v(c);
    //Taquin v(c);
    cout << "Initialisation..." << endl;
    v.init();
    while (!v.isOver()) {
      cout << v << endl;
      v.keyPressed();
      v.deplacement();
    }*/
    menu_choix_jeu();
}
