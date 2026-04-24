// ============================================================================
// Exercice 09 — Mémoire dynamique
// Thème : new, delete, new[], delete[], fuites mémoire, RAII.
// ============================================================================
//
// CONSIGNES :
//   1. Allouer un entier sur le tas et le libérer.
//   2. Allouer un tableau dynamique, le remplir, le libérer.
//   3. Tableau dont la taille est déterminée à l'exécution.
//   4. Matrice dynamique (tableau de pointeurs).
//   5. Détecter et corriger une fuite mémoire.
//   6. Challenge : implémenter un tableau dynamique redimensionnable.
//
// CONCEPTS PRATIQUÉS :
//   - new / delete
//   - new[] / delete[]
//   - Allocation dynamique de tableaux 1D et 2D
//   - Fuites mémoire (memory leaks)
//   - Dangling pointers
//   - RAII (principe)
//
// ============================================================================

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    // -----------------------------------------------------------------------
    // PARTIE 1 : Allocation simple
    // -----------------------------------------------------------------------
    cout << "=== Partie 1 : Allocation simple ===" << endl;

    int* p = new int;       // allouer un int sur le tas
    *p = 42;
    cout << "Valeur : " << *p << endl;
    cout << "Adresse : " << p << endl;

    delete p;               // libérer la mémoire
    p = nullptr;            // bonne pratique

    // Allocation avec initialisation
    int* q = new int(99);
    cout << "Initialisé à : " << *q << endl;
    delete q;
    q = nullptr;

    // -----------------------------------------------------------------------
    // PARTIE 2 : Tableau dynamique
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 2 : Tableau dynamique ===" << endl;

    const int TAILLE = 5;
    int* tab = new int[TAILLE];  // allouer un tableau de 5 entiers

    // Remplir
    for (int i = 0; i < TAILLE; i++) {
        tab[i] = (i + 1) * 10;
    }

    // Afficher
    cout << "Tableau : ";
    for (int i = 0; i < TAILLE; i++) {
        cout << tab[i] << " ";
    }
    cout << endl;

    delete[] tab;   // IMPORTANT : delete[] pour les tableaux !
    tab = nullptr;

    // -----------------------------------------------------------------------
    // PARTIE 3 : Taille à l'exécution
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 3 : Taille dynamique ===" << endl;

    int n;
    cout << "Combien d'éléments ? ";
    cin >> n;

    double* notes = new double[n];

    for (int i = 0; i < n; i++) {
        cout << "  Note [" << i << "] : ";
        cin >> notes[i];
    }

    // Calculer la moyenne
    double somme = 0;
    for (int i = 0; i < n; i++) {
        somme += notes[i];
    }
    cout << "Moyenne : " << fixed << setprecision(2) << somme / n << endl;

    delete[] notes;
    notes = nullptr;

    // -----------------------------------------------------------------------
    // PARTIE 4 : Matrice dynamique (2D)
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 4 : Matrice dynamique ===" << endl;

    int lignes = 3, cols = 4;

    // Étape 1 : allouer un tableau de pointeurs (les lignes)
    int** matrice = new int*[lignes];

    // Étape 2 : pour chaque ligne, allouer un tableau (les colonnes)
    for (int i = 0; i < lignes; i++) {
        matrice[i] = new int[cols];
    }

    // Remplir
    int val = 1;
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < cols; j++) {
            matrice[i][j] = val++;
        }
    }

    // Afficher
    for (int i = 0; i < lignes; i++) {
        cout << "  | ";
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << matrice[i][j];
        }
        cout << " |" << endl;
    }

    // Libérer dans l'ordre INVERSE de l'allocation
    for (int i = 0; i < lignes; i++) {
        delete[] matrice[i];   // libérer chaque ligne
    }
    delete[] matrice;          // libérer le tableau de pointeurs
    matrice = nullptr;

    // -----------------------------------------------------------------------
    // PARTIE 5 : Fuites mémoire — démonstration
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 5 : Fuites mémoire ===" << endl;

    // ❌ MAUVAIS EXEMPLE (commenté pour ne pas fuir)
    // int* fuite = new int[1000];
    // fuite = new int[500];   // l'ancien bloc de 1000 est perdu → FUITE !

    // ✅ BON EXEMPLE
    int* bloc1 = new int[1000];
    // … utilisation …
    delete[] bloc1;            // libérer avant de réassigner
    bloc1 = new int[500];
    // … utilisation …
    delete[] bloc1;
    bloc1 = nullptr;
    cout << "Aucune fuite mémoire !" << endl;

    // ❌ DANGLING POINTER (commenté)
    // int* dp = new int(10);
    // delete dp;
    // cout << *dp;   // COMPORTEMENT INDÉFINI !

    // ✅ Toujours mettre à nullptr après delete
    int* dp = new int(10);
    delete dp;
    dp = nullptr;
    // if (dp != nullptr) cout << *dp;  // sécuritaire
    cout << "Dangling pointer évité." << endl;

    // -----------------------------------------------------------------------
    // PARTIE 6 : Tableau redimensionnable (mini-vector)
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 6 : Tableau redimensionnable ===" << endl;

    int capacite = 4;
    int taille = 0;
    int* dynTab = new int[capacite];

    // Fonction lambda pour ajouter un élément avec redimensionnement
    auto ajouter = [&](int valeur) {
        if (taille >= capacite) {
            // Doubler la capacité
            int nouvCapacite = capacite * 2;
            int* nouveau = new int[nouvCapacite];

            // Copier les anciens éléments
            for (int i = 0; i < taille; i++) {
                nouveau[i] = dynTab[i];
            }

            delete[] dynTab;        // libérer l'ancien
            dynTab = nouveau;       // pointer vers le nouveau
            capacite = nouvCapacite;

            cout << "  [Redimensionné : capacité = " << capacite << "]" << endl;
        }
        dynTab[taille++] = valeur;
    };

    // Ajouter 10 éléments (provoque des redimensionnements)
    for (int i = 1; i <= 10; i++) {
        ajouter(i * 10);
    }

    // Afficher
    cout << "Contenu (taille=" << taille << ", capacité=" << capacite << ") : ";
    for (int i = 0; i < taille; i++) {
        cout << dynTab[i] << " ";
    }
    cout << endl;

    delete[] dynTab;
    dynTab = nullptr;

    return 0;
}
