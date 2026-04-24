// ============================================================================
// Exercice — Calculatrice avec surcharge de fonctions
// ============================================================================
//
// CONSIGNES :
//   1. Écrire une fonction  calculer()  surchargée pour :
//        - deux entiers (int)
//        - deux réels (double)
//        - un entier et un réel (int, double)
//      Chaque version effectue addition, soustraction, multiplication,
//      division selon un caractère '+', '-', '*', '/'.
//   2. La division par zéro doit signaler l'erreur via un paramètre
//      booléen passé par référence : erreur = true.
//   3. Écrire une fonction  tableMultiplication(int n)  qui affiche
//      la table de n de 1 à 10.
//   4. Écrire une fonction  puissance(double base, int exp)  récursive.
//   5. Depuis main(), tester chaque surcharge et les cas limites.
//
// CONCEPTS PRATIQUÉS :
//   - Prototypes de fonctions
//   - Surcharge (overloading)
//   - Passage par référence (&)
//   - Paramètre par défaut
//   - Récursivité
//
// ============================================================================

#include <iostream>
#include <iomanip>

using namespace std;

// ── Prototypes ──────────────────────────────────────────────────────────────

// TODO : déclarer les 3 surcharges de calculer()
// TODO : déclarer tableMultiplication()
// TODO : déclarer puissance()

// ── main ────────────────────────────────────────────────────────────────────

int main() {

    // TODO 1 : tester calculer(int, int, '+') etc. pour +, -, *, /
    //          (inclure division par zéro et afficher un message d'erreur)

    // TODO 2 : tester calculer(double, double, ...)

    // TODO 3 : tester calculer(int, double, ...)

    // TODO 4 : afficher la table de 7

    // TODO 5 : calculer 2^10 via puissance() récursive

    return 0;
}

// ── Implémentations ─────────────────────────────────────────────────────────

// TODO : implémenter les 3 surcharges de calculer()

// TODO : implémenter tableMultiplication()

// TODO : implémenter puissance()  (cas de base : exp == 0 → retourner 1)
