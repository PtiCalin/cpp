// ============================================================================
// Exercice 03 — Boucles
// Thème : for, while, do-while, boucles imbriquées, break/continue.
// ============================================================================
//
// CONSIGNES :
//   1. Table de multiplication (for).
//   2. Deviner un nombre (while + compteur de tentatives).
//   3. Validation de saisie (do-while).
//   4. Motifs avec boucles imbriquées (triangle, losange).
//   5. Suite de Collatz (while + break condition).
//   6. Nombres premiers dans un intervalle (for + continue).
//
// CONCEPTS PRATIQUÉS :
//   - for (classique et range-based)
//   - while et do-while
//   - Boucles imbriquées
//   - break et continue
//   - Compteurs et accumulateurs
//
// ============================================================================

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    // -----------------------------------------------------------------------
    // PARTIE 1 : Table de multiplication
    // -----------------------------------------------------------------------
    cout << "=== Partie 1 : Table de multiplication ===" << endl;
    int n;
    cout << "Table de quel nombre ? ";
    cin >> n;

    for (int i = 1; i <= 12; i++) {
        cout << setw(3) << n << " x " << setw(2) << i
             << " = " << setw(4) << n * i << endl;
    }

    // -----------------------------------------------------------------------
    // PARTIE 2 : Deviner un nombre
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 2 : Deviner un nombre (1–100) ===" << endl;
    srand(static_cast<unsigned>(time(nullptr)));
    int secret = rand() % 100 + 1;
    int essai;
    int tentatives = 0;
    const int MAX_TENTATIVES = 7;

    while (tentatives < MAX_TENTATIVES) {
        cout << "Tentative " << tentatives + 1 << "/" << MAX_TENTATIVES << " : ";
        cin >> essai;
        tentatives++;

        if (essai == secret) {
            cout << "Bravo ! Trouvé en " << tentatives << " tentatives !" << endl;
            break;
        } else if (essai < secret) {
            cout << "Trop bas !" << endl;
        } else {
            cout << "Trop haut !" << endl;
        }
    }
    if (essai != secret) {
        cout << "Perdu ! Le nombre était " << secret << "." << endl;
    }

    // -----------------------------------------------------------------------
    // PARTIE 3 : Validation de saisie (do-while)
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 3 : Saisie validée ===" << endl;
    int valeur;
    do {
        cout << "Entrez un nombre entre 1 et 10 : ";
        cin >> valeur;
        if (valeur < 1 || valeur > 10) {
            cout << "  → Invalide ! Réessayez." << endl;
        }
    } while (valeur < 1 || valeur > 10);
    cout << "Vous avez choisi : " << valeur << endl;

    // -----------------------------------------------------------------------
    // PARTIE 4 : Motifs (boucles imbriquées)
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 4a : Triangle ===" << endl;
    int hauteur = 5;
    for (int i = 1; i <= hauteur; i++) {
        for (int j = 0; j < hauteur - i; j++) cout << " ";
        for (int j = 0; j < 2 * i - 1; j++)   cout << "*";
        cout << endl;
    }

    cout << "\n=== Partie 4b : Losange ===" << endl;
    int demi = 4;
    // Moitié haute
    for (int i = 1; i <= demi; i++) {
        for (int j = 0; j < demi - i; j++) cout << " ";
        for (int j = 0; j < 2 * i - 1; j++) cout << "*";
        cout << endl;
    }
    // Moitié basse
    for (int i = demi - 1; i >= 1; i--) {
        for (int j = 0; j < demi - i; j++) cout << " ";
        for (int j = 0; j < 2 * i - 1; j++) cout << "*";
        cout << endl;
    }

    // -----------------------------------------------------------------------
    // PARTIE 5 : Suite de Collatz
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 5 : Suite de Collatz ===" << endl;
    cout << "Nombre de départ : ";
    int collatz;
    cin >> collatz;

    int etapes = 0;
    cout << collatz;
    while (collatz != 1) {
        if (collatz % 2 == 0)
            collatz /= 2;
        else
            collatz = 3 * collatz + 1;
        cout << " → " << collatz;
        etapes++;
    }
    cout << "\nConvergence en " << etapes << " étapes." << endl;

    // -----------------------------------------------------------------------
    // PARTIE 6 : Nombres premiers (for + continue)
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 6 : Nombres premiers de 2 à 100 ===" << endl;
    int compteurPremiers = 0;
    for (int i = 2; i <= 100; i++) {
        bool estPremier = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                estPremier = false;
                break;           // inutile de tester les autres diviseurs
            }
        }
        if (!estPremier) continue;  // passer au nombre suivant

        cout << setw(4) << i;
        compteurPremiers++;
        if (compteurPremiers % 10 == 0) cout << endl;
    }
    cout << "\nTotal : " << compteurPremiers << " nombres premiers." << endl;

    return 0;
}
