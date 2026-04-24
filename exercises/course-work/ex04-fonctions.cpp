// ============================================================================
// Exercice 04 — Fonctions
// Thème : prototypes, passage par valeur/référence/pointeur, surcharge,
//         paramètres par défaut, récursion.
// ============================================================================
//
// CONSIGNES :
//   1. Écrire une fonction qui retourne le maximum de deux entiers.
//   2. Écrire une fonction swap par référence et une par pointeur.
//   3. Surcharger une fonction « afficher » pour int, double et string.
//   4. Utiliser des paramètres par défaut dans une fonction salutation.
//   5. Implémenter factorielle et Fibonacci récursifs.
//   6. Écrire une fonction qui retourne plusieurs valeurs via référence.
//
// CONCEPTS PRATIQUÉS :
//   - Prototypes de fonction
//   - Passage par valeur, par référence (&), par pointeur (*)
//   - Surcharge de fonctions
//   - Paramètres par défaut
//   - Récursion (simple et multiple)
//   - Portée (scope) des variables
//
// ============================================================================

#include <iostream>
#include <string>

using namespace std;

// ---- Prototypes -----------------------------------------------------------
int maximum(int a, int b);
void swapRef(int& a, int& b);
void swapPtr(int* a, int* b);
void afficher(int v);
void afficher(double v);
void afficher(const string& v);
void salutation(const string& nom, const string& titre = "M./Mme");
long long factorielle(int n);
int fibonacci(int n);
void divisionEntiere(int dividende, int diviseur, int& quotient, int& reste);

// ---- main -----------------------------------------------------------------
int main() {

    // -----------------------------------------------------------------------
    // PARTIE 1 : Maximum
    // -----------------------------------------------------------------------
    cout << "=== Partie 1 : Maximum ===" << endl;
    int a = 42, b = 73;
    cout << "max(" << a << ", " << b << ") = " << maximum(a, b) << endl;
    cout << "max(" << b << ", " << a << ") = " << maximum(b, a) << endl;

    // -----------------------------------------------------------------------
    // PARTIE 2 : Swap (référence vs pointeur)
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 2 : Swap ===" << endl;
    int x = 10, y = 20;
    cout << "Avant swapRef : x=" << x << ", y=" << y << endl;
    swapRef(x, y);
    cout << "Après swapRef : x=" << x << ", y=" << y << endl;

    cout << "Avant swapPtr : x=" << x << ", y=" << y << endl;
    swapPtr(&x, &y);
    cout << "Après swapPtr : x=" << x << ", y=" << y << endl;

    // -----------------------------------------------------------------------
    // PARTIE 3 : Surcharge
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 3 : Surcharge ===" << endl;
    afficher(42);
    afficher(3.14159);
    afficher("Bonjour le monde");

    // -----------------------------------------------------------------------
    // PARTIE 4 : Paramètres par défaut
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 4 : Paramètres par défaut ===" << endl;
    salutation("Bouchard");
    salutation("Tremblay", "Dr.");

    // -----------------------------------------------------------------------
    // PARTIE 5 : Récursion
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 5 : Récursion ===" << endl;
    for (int i = 0; i <= 10; i++) {
        cout << i << "! = " << factorielle(i) << endl;
    }
    cout << endl;
    for (int i = 0; i <= 15; i++) {
        cout << "fib(" << i << ") = " << fibonacci(i) << endl;
    }

    // -----------------------------------------------------------------------
    // PARTIE 6 : Retours multiples via référence
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 6 : Retours multiples ===" << endl;
    int q, r;
    divisionEntiere(17, 5, q, r);
    cout << "17 / 5 = " << q << " reste " << r << endl;
    divisionEntiere(100, 7, q, r);
    cout << "100 / 7 = " << q << " reste " << r << endl;

    return 0;
}

// ---- Implémentations ------------------------------------------------------

int maximum(int a, int b) {
    return (a > b) ? a : b;
}

void swapRef(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void swapPtr(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void afficher(int v) {
    cout << "[int]    " << v << endl;
}

void afficher(double v) {
    cout << "[double] " << v << endl;
}

void afficher(const string& v) {
    cout << "[string] " << v << endl;
}

void salutation(const string& nom, const string& titre) {
    cout << "Bonjour, " << titre << " " << nom << " !" << endl;
}

long long factorielle(int n) {
    if (n <= 1) return 1;
    return n * factorielle(n - 1);
}

int fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void divisionEntiere(int dividende, int diviseur, int& quotient, int& reste) {
    quotient = dividende / diviseur;
    reste    = dividende % diviseur;
}
