// ============================================================================
// Exercice — Tableau de notes dynamique
// ============================================================================
//
// CONSIGNES :
//   1. Demander à l'utilisateur combien de notes il veut saisir (n).
//   2. Allouer un tableau dynamique de n doubles avec new[].
//   3. Remplir le tableau (saisir chaque note, valider 0 ≤ note ≤ 100).
//   4. Écrire des fonctions (avec pointeurs) pour :
//        a. calculer la moyenne
//        b. trouver la note minimale
//        c. trouver la note maximale
//        d. afficher toutes les notes
//   5. Libérer la mémoire avec delete[] et mettre le pointeur à nullptr.
//   6. Vérifier avec un assert ou un if que le pointeur est bien nullptr.
//
// CONCEPTS PRATIQUÉS :
//   - new / delete[]
//   - Passage de pointeur à une fonction (const double*, int)
//   - Arithmétique de pointeurs
//   - nullptr
//   - Validation de saisie
//
// ⚠ PIÈGE À ÉVITER :
//   Ne pas oublier delete[] (pas delete seul pour un tableau).
//   Mettre le pointeur à nullptr après libération.
//
// ============================================================================

#include <iostream>
#include <iomanip>

using namespace std;

// ── Prototypes ──────────────────────────────────────────────────────────────

// TODO : double moyenne(const double* tab, int n)
// TODO : double minimum(const double* tab, int n)
// TODO : double maximum(const double* tab, int n)
// TODO : void   afficher(const double* tab, int n)

// ── main ────────────────────────────────────────────────────────────────────

int main() {

    // TODO 1 : lire n (valider n >= 1)

    // TODO 2 : allouer double* notes = new double[n]

    // TODO 3 : remplir le tableau (boucle + validation 0-100)

    // TODO 4 : appeler et afficher résultats de chaque fonction

    // TODO 5 : libérer la mémoire, mettre à nullptr

    // TODO 6 : vérifier que notes == nullptr

    return 0;
}

// ── Implémentations ─────────────────────────────────────────────────────────

// TODO : implémenter chaque fonction
//        Conseil : parcourir avec un indice ou avec l'arithmétique de pointeurs
