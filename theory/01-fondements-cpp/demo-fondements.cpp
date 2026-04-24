// demo-fondements.cpp
// Démonstration : types, opérateurs, entrées/sorties, conversions
// IFT1166 — Chapitre 1-2
// Compiler : g++ -Wall -std=c++17 demo-fondements.cpp -o demo-fondements

#include <iostream>
#include <iomanip>   // setprecision, fixed
#include <string>
#include <limits>    // numeric_limits
using namespace std;

int main() {
    // ── Types de base ─────────────────────────
    cout << "=== Types de base ===\n";
    bool   vrai   = true;
    char   lettre = 'A';
    int    entier = -42;
    double reel   = 3.14159;
    string texte  = "Bonjour";

    cout << "bool   : " << vrai    << " (1=true, 0=false)\n";
    cout << "char   : " << lettre  << " (ASCII=" << (int)lettre << ")\n";
    cout << "int    : " << entier  << "\n";
    cout << "double : " << reel    << "\n";
    cout << "string : " << texte   << "\n\n";

    // ── Tailles ───────────────────────────────
    cout << "=== Tailles (sizeof) ===\n";
    cout << "bool        : " << sizeof(bool)        << " octet(s)\n";
    cout << "char        : " << sizeof(char)        << " octet(s)\n";
    cout << "int         : " << sizeof(int)         << " octet(s)\n";
    cout << "double      : " << sizeof(double)      << " octet(s)\n";
    cout << "long long   : " << sizeof(long long)   << " octet(s)\n\n";

    // ── Arithmétique et modulo ─────────────────
    cout << "=== Opérateurs ===\n";
    cout << "17 / 5   = " << 17 / 5   << " (division entière)\n";
    cout << "17 % 5   = " << 17 % 5   << " (reste)\n";
    cout << "17.0 / 5 = " << 17.0 / 5 << " (division réelle)\n\n";

    // ── Conversions ───────────────────────────
    cout << "=== Conversions ===\n";
    int    i = 7;
    double d = i;           // int → double (implicite)
    int    j = 3.99;        // double → int (troncature)
    cout << "int → double : " << i << " → " << d << "\n";
    cout << "double → int : 3.99 → " << j << " (troncature, pas arrondi)\n\n";

    // ── Formatage de l'affichage ──────────────
    cout << "=== Formatage ===\n";
    double pi = 3.14159265358979;
    cout << "Par défaut       : " << pi << "\n";
    cout << fixed << setprecision(2);
    cout << "fixed, 2 déc.    : " << pi << "\n";
    cout << fixed << setprecision(6);
    cout << "fixed, 6 déc.    : " << pi << "\n\n";

    // ── Incrémentation pré / post ─────────────
    cout << "=== Pré vs. post-incrémentation ===\n";
    int a = 5;
    cout << "a = " << a << "\n";
    cout << "a++ = " << a++ << " (a devient " << a << " après)\n";
    cout << "++a = " << ++a << " (a incrémenté avant l'affichage)\n\n";

    // ── Lecture clavier ───────────────────────
    cout << "=== Lecture clavier ===\n";
    int n;
    cout << "Entrez un entier : ";
    cin >> n;
    cout << "Vous avez entré : " << n << "\n";
    cout << "Son carré       : " << n * n << "\n";

    return 0;
}
