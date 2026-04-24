#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

// 4.1 Classe Compteur
class Compteur {
private:
    int valeur_;

public:
    Compteur() : valeur_(0) {}

    void incremente() {
        ++valeur_;
    }

    int getValeur() const {
        return valeur_;
    }
};

// 4.2 Fonction sans argument et sans retour
void UnExemple() {
    Compteur pile;
    Compteur face;

    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < 100; ++i) {
        int tirage = rand() % 2; // 0 ou 1

        if (tirage == 0) {
            pile.incremente();
        } else {
            face.incremente();
        }
    }

    cout << "Resultat des 100 tirages:" << endl;
    cout << "Pile: " << pile.getValeur() << endl;
    cout << "Face: " << face.getValeur() << endl;
}

int main() {
    UnExemple();
    return 0;
}
