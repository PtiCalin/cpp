// ============================================================================
// Exercice 05 — Tableaux et tableaux 2D
// Thème : tableaux C-style, parcours, recherche, tri, tableaux 2D.
// ============================================================================
//
// CONSIGNES :
//   1. Déclarer un tableau de 10 entiers et le remplir via clavier.
//   2. Calculer la somme, la moyenne, le min et le max.
//   3. Recherche linéaire d'un élément.
//   4. Implémenter le tri à bulles (Bubble Sort).
//   5. Travailler avec un tableau 2D (matrice).
//   6. Calculer les sommes par ligne et par colonne d'une matrice.
//
// CONCEPTS PRATIQUÉS :
//   - Tableaux C-style (déclaration, initialisation, sizeof)
//   - Parcours avec for et indices
//   - Passage de tableaux aux fonctions
//   - Tri à bulles
//   - Tableaux 2D
//
// ============================================================================

#include <iostream>
#include <iomanip>
#include <climits>

using namespace std;

// ---- Prototypes -----------------------------------------------------------
void remplir(int tab[], int taille);
void afficherTab(const int tab[], int taille);
double moyenne(const int tab[], int taille);
int minimum(const int tab[], int taille);
int maximum(const int tab[], int taille);
int rechercheLineaire(const int tab[], int taille, int cible);
void triBulles(int tab[], int taille);

const int LIGNES = 3;
const int COLS   = 4;
void afficherMatrice(const int mat[][COLS], int lignes);
void sommesParLigne(const int mat[][COLS], int lignes);
void sommesParColonne(const int mat[][COLS], int lignes);

// ---- main -----------------------------------------------------------------
int main() {

    // -----------------------------------------------------------------------
    // PARTIE 1 : Remplir un tableau
    // -----------------------------------------------------------------------
    cout << "=== Partie 1 : Remplir un tableau de 10 entiers ===" << endl;
    const int TAILLE = 10;
    int notes[TAILLE];
    remplir(notes, TAILLE);

    cout << "Tableau saisi : ";
    afficherTab(notes, TAILLE);

    // -----------------------------------------------------------------------
    // PARTIE 2 : Statistiques
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 2 : Statistiques ===" << endl;
    int somme = 0;
    for (int i = 0; i < TAILLE; i++) somme += notes[i];

    cout << "Somme   : " << somme << endl;
    cout << "Moyenne : " << fixed << setprecision(2)
         << moyenne(notes, TAILLE) << endl;
    cout << "Minimum : " << minimum(notes, TAILLE) << endl;
    cout << "Maximum : " << maximum(notes, TAILLE) << endl;

    // -----------------------------------------------------------------------
    // PARTIE 3 : Recherche linéaire
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 3 : Recherche linéaire ===" << endl;
    int cible;
    cout << "Valeur à chercher : ";
    cin >> cible;

    int pos = rechercheLineaire(notes, TAILLE, cible);
    if (pos != -1)
        cout << "Trouvé à l'indice " << pos << endl;
    else
        cout << "Non trouvé." << endl;

    // -----------------------------------------------------------------------
    // PARTIE 4 : Tri à bulles
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 4 : Tri à bulles ===" << endl;
    cout << "Avant tri : ";
    afficherTab(notes, TAILLE);

    triBulles(notes, TAILLE);

    cout << "Après tri : ";
    afficherTab(notes, TAILLE);

    // -----------------------------------------------------------------------
    // PARTIE 5 & 6 : Matrice 2D
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 5 : Matrice 3×4 ===" << endl;
    int mat[LIGNES][COLS] = {
        { 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9, 10, 11, 12}
    };

    afficherMatrice(mat, LIGNES);
    cout << endl;
    sommesParLigne(mat, LIGNES);
    sommesParColonne(mat, LIGNES);

    return 0;
}

// ---- Implémentations ------------------------------------------------------

void remplir(int tab[], int taille) {
    for (int i = 0; i < taille; i++) {
        cout << "  Élément [" << i << "] : ";
        cin >> tab[i];
    }
}

void afficherTab(const int tab[], int taille) {
    cout << "{ ";
    for (int i = 0; i < taille; i++) {
        cout << tab[i];
        if (i < taille - 1) cout << ", ";
    }
    cout << " }" << endl;
}

double moyenne(const int tab[], int taille) {
    int s = 0;
    for (int i = 0; i < taille; i++) s += tab[i];
    return static_cast<double>(s) / taille;
}

int minimum(const int tab[], int taille) {
    int m = INT_MAX;
    for (int i = 0; i < taille; i++) {
        if (tab[i] < m) m = tab[i];
    }
    return m;
}

int maximum(const int tab[], int taille) {
    int m = INT_MIN;
    for (int i = 0; i < taille; i++) {
        if (tab[i] > m) m = tab[i];
    }
    return m;
}

int rechercheLineaire(const int tab[], int taille, int cible) {
    for (int i = 0; i < taille; i++) {
        if (tab[i] == cible) return i;
    }
    return -1;
}

void triBulles(int tab[], int taille) {
    for (int i = 0; i < taille - 1; i++) {
        bool echange = false;
        for (int j = 0; j < taille - 1 - i; j++) {
            if (tab[j] > tab[j + 1]) {
                int tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
                echange = true;
            }
        }
        if (!echange) break;  // déjà trié
    }
}

void afficherMatrice(const int mat[][COLS], int lignes) {
    for (int i = 0; i < lignes; i++) {
        cout << "  | ";
        for (int j = 0; j < COLS; j++) {
            cout << setw(4) << mat[i][j];
        }
        cout << " |" << endl;
    }
}

void sommesParLigne(const int mat[][COLS], int lignes) {
    cout << "Sommes par ligne :" << endl;
    for (int i = 0; i < lignes; i++) {
        int s = 0;
        for (int j = 0; j < COLS; j++) s += mat[i][j];
        cout << "  Ligne " << i << " : " << s << endl;
    }
}

void sommesParColonne(const int mat[][COLS], int lignes) {
    cout << "Sommes par colonne :" << endl;
    for (int j = 0; j < COLS; j++) {
        int s = 0;
        for (int i = 0; i < lignes; i++) s += mat[i][j];
        cout << "  Colonne " << j << " : " << s << endl;
    }
}
