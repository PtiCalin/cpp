// demo-pointeurs.cpp
// Démonstration : pointeurs, références, mémoire dynamique, RAII
// IFT1166 — ex08-ex09
// Compiler : g++ -Wall -std=c++17 demo-pointeurs.cpp -o demo-pointeurs

#include <iostream>
#include <cstring>
using namespace std;

// ─────────────────────────────────────────────
// Section 1 : bases des pointeurs
// ─────────────────────────────────────────────
void sectionPointeurs() {
    cout << "=== 1. Pointeurs fondamentaux ===\n";

    int  x   = 42;
    int* ptr = &x;

    cout << "x     = " << x     << "\n";
    cout << "&x    = " << &x    << "\n";
    cout << "ptr   = " << ptr   << "\n";
    cout << "*ptr  = " << *ptr  << "\n";

    *ptr = 100;
    cout << "x après *ptr=100 : " << x << "\n\n";
}

// ─────────────────────────────────────────────
// Section 2 : arithmétique des pointeurs
// ─────────────────────────────────────────────
void sectionArithmetique() {
    cout << "=== 2. Arithmétique des pointeurs ===\n";

    int tab[5] = {10, 20, 30, 40, 50};
    int* p = tab;

    for (int i = 0; i < 5; i++) {
        cout << "tab[" << i << "] = " << *(p + i)
             << " (adresse " << (p + i) << ")\n";
    }
    cout << "\n";
}

// ─────────────────────────────────────────────
// Section 3 : références
// ─────────────────────────────────────────────
void doublerParRef(int& n) { n *= 2; }      // modifie l'original
void doublerParVal(int  n) { n *= 2; }      // modifie une copie

void sectionReferences() {
    cout << "=== 3. Références ===\n";

    int a = 10;
    doublerParVal(a);
    cout << "Après doublerParVal : " << a << "\n";   // 10 (inchangé)

    doublerParRef(a);
    cout << "Après doublerParRef : " << a << "\n";   // 20

    // Alias
    int& r = a;
    r = 99;
    cout << "a après r=99 : " << a << "\n\n";   // 99
}

// ─────────────────────────────────────────────
// Section 4 : mémoire dynamique simple
// ─────────────────────────────────────────────
void sectionDynamiqueSimple() {
    cout << "=== 4. Mémoire dynamique — scalaire ===\n";

    int* p = new int(42);
    cout << "Valeur allouée : " << *p << "\n";
    *p = 100;
    cout << "Valeur modifiée : " << *p << "\n";
    delete p;
    p = nullptr;
    cout << "Mémoire libérée\n\n";
}

// ─────────────────────────────────────────────
// Section 5 : tableau dynamique
// ─────────────────────────────────────────────
void sectionTableauDynamic() {
    cout << "=== 5. Tableau dynamique ===\n";

    int n;
    cout << "Taille du tableau ? ";
    cin >> n;

    int* tab = new int[n];
    for (int i = 0; i < n; i++) tab[i] = (i + 1) * (i + 1);

    cout << "Tableau : [";
    for (int i = 0; i < n; i++) {
        cout << tab[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]\n";

    delete[] tab;   // [] obligatoire
    tab = nullptr;
    cout << "\n";
}

// ─────────────────────────────────────────────
// Section 6 : classe RAII (pas de fuite mémoire)
// ─────────────────────────────────────────────
class VecteurDyn {
    int* data;
    int  n;
public:
    explicit VecteurDyn(int taille) : n(taille), data(new int[taille]()) {
        cout << "[VecteurDyn+] taille=" << n << "\n";
    }
    ~VecteurDyn() {
        delete[] data;
        cout << "[VecteurDyn-] taille=" << n << "\n";
    }

    // Désactiver la copie superficielle
    VecteurDyn(const VecteurDyn&) = delete;
    VecteurDyn& operator=(const VecteurDyn&) = delete;

    void   set(int i, int val) { if (i >= 0 && i < n) data[i] = val; }
    int    get(int i)    const { return (i >= 0 && i < n) ? data[i] : 0; }
    int    taille()      const { return n; }

    void afficher() const {
        cout << "[";
        for (int i = 0; i < n; i++) {
            cout << data[i];
            if (i < n - 1) cout << ", ";
        }
        cout << "]\n";
    }
};

void sectionRAII() {
    cout << "=== 6. RAII — libération automatique ===\n";
    {
        VecteurDyn v(4);
        for (int i = 0; i < 4; i++) v.set(i, (i + 1) * 10);
        cout << "Vecteur : "; v.afficher();
    }   // v détruit ici → delete[] automatique
    cout << "\n";
}

int main() {
    sectionPointeurs();
    sectionArithmetique();
    sectionReferences();
    sectionDynamiqueSimple();
    sectionTableauDynamic();
    sectionRAII();

    return 0;
}
