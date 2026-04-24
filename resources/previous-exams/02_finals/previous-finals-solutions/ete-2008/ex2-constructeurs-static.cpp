#include <iostream>
#include <string>

using namespace std;

// Exercice 2.1
// Classe donnee dans l'enonce.
class A {
public:
    int x;
    A() {
        x = 5;
    }
};

// Exercice 2.2
class B : public A {
public:
    static int x;

    B() {
        x++;
    }

    B(int i) {
        x = x + i;
    }

    B(const string&) {
        x--;
    }
};

int B::x = 10;

int main() {
    // --- 2.1: Nombre d'appels au constructeur A() ---
    A u;           // 1
    A v;           // 2
    A* pA = nullptr;
    pA = new A();  // 3
    A y = u;       // copie => constructeur de recopie, pas A()
    A* z = new A();// 4

    cout << "Ex 2.1 - Nombre d'appels de A(): 4" << endl;
    cout << "Valeurs: u=" << u.x << " v=" << v.x << " y=" << y.x << " *pA=" << pA->x << " *z=" << z->x << endl;

    delete pA;
    delete z;

    // --- 2.2: Sortie du programme de l'enonce ---
    B b1;          // x: 10 -> 11
    B b2(2008);    // x: 11 -> 2019
    B b3("IFT1166"); // x: 2019 -> 2018

    cout << "Ex 2.2 - Affichage attendu: 2018 : 2018 : 2018" << endl;
    cout << b1.x << " : " << b2.x << " : " << b3.x << endl;

    return 0;
}
