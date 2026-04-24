// demo-fonctions.cpp
// Démonstration : prototypes, modes de passage, surcharge, inline, récursivité
// IFT1166 — ex04, ex06-07
// Compiler : g++ -Wall -std=c++17 demo-fonctions.cpp -o demo-fonctions

#include <iostream>
#include <string>
using namespace std;

// ─────────────────────────────────────────────
// Prototypes (déclarations)
// ─────────────────────────────────────────────
void afficher(const string& titre, int valeur);
int  maximum(int a, int b);
double maximum(double a, double b);    // surcharge
void  echanger(int& a, int& b);
int   factorielle(int n);
inline double carre(double x);

// ─────────────────────────────────────────────
// main
// ─────────────────────────────────────────────
int main() {
    // ── Passage par valeur vs. référence ──────
    cout << "=== Passage par valeur vs. référence ===\n";
    int a = 5, b = 12;
    cout << "Avant échange : a=" << a << " b=" << b << "\n";
    echanger(a, b);
    cout << "Après échange : a=" << a << " b=" << b << "\n\n";

    // ── Surcharge ─────────────────────────────
    cout << "=== Surcharge de maximum() ===\n";
    cout << "maximum(3, 7)       = " << maximum(3, 7)       << "\n";
    cout << "maximum(3.5, 2.1)   = " << maximum(3.5, 2.1)   << "\n\n";

    // ── Inline ────────────────────────────────
    cout << "=== Fonction inline : carre() ===\n";
    for (int i = 1; i <= 5; i++) {
        cout << i << "² = " << carre(i) << "\n";
    }
    cout << "\n";

    // ── Argument par défaut ───────────────────
    cout << "=== Affichage avec arguments par défaut ===\n";
    afficher("Résultat", 42);
    afficher("Score", 100);
    cout << "\n";

    // ── Récursivité ───────────────────────────
    cout << "=== Factorielle récursive ===\n";
    for (int i = 0; i <= 7; i++) {
        cout << i << "! = " << factorielle(i) << "\n";
    }
    cout << "\n";

    // ── Variable statique locale ──────────────
    cout << "=== Variable statique locale ===\n";
    auto compter = []() {
        static int count = 0;
        count++;
        cout << "Appel #" << count << "\n";
    };
    compter(); compter(); compter();

    return 0;
}

// ─────────────────────────────────────────────
// Définitions
// ─────────────────────────────────────────────
void afficher(const string& titre, int valeur) {
    cout << titre << " : " << valeur << "\n";
}

int maximum(int a, int b) {
    return (a > b) ? a : b;
}

double maximum(double a, double b) {
    return (a > b) ? a : b;
}

void echanger(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int factorielle(int n) {
    if (n <= 0) return 1;
    return n * factorielle(n - 1);
}

inline double carre(double x) {
    return x * x;
}
