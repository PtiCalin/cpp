// ============================================================================
// Exercice 06 — Vectors et la STL
// Thème : vector, itération, algorithmes STL, range-based for.
// ============================================================================
//
// CONSIGNES :
//   1. Créer un vector, ajouter des éléments, afficher la taille/capacité.
//   2. Parcourir avec indices, itérateurs, et range-based for.
//   3. Utiliser les algorithmes STL : sort, reverse, find, count, accumulate.
//   4. Supprimer des éléments (erase, pop_back).
//   5. Créer un vector 2D (matrice dynamique).
//   6. Challenge : filtrer un vector (copier les éléments pairs).
//
// CONCEPTS PRATIQUÉS :
//   - vector<T> (push_back, pop_back, size, capacity, at, [], clear)
//   - Itérateurs (begin, end)
//   - Range-based for (for-each)
//   - <algorithm> : sort, reverse, find, count, min_element, max_element
//   - <numeric>   : accumulate
//   - Vector de vectors (2D)
//
// ============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

// Fonction utilitaire d'affichage
void afficher(const vector<int>& v, const string& label = "") {
    if (!label.empty()) cout << label << " ";
    cout << "[ ";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1) cout << ", ";
    }
    cout << " ]  (size=" << v.size() << ")" << endl;
}

int main() {

    // -----------------------------------------------------------------------
    // PARTIE 1 : Création et propriétés
    // -----------------------------------------------------------------------
    cout << "=== Partie 1 : Création et propriétés ===" << endl;
    vector<int> notes;

    notes.push_back(85);
    notes.push_back(92);
    notes.push_back(78);
    notes.push_back(95);
    notes.push_back(88);

    cout << "Taille   : " << notes.size() << endl;
    cout << "Capacité : " << notes.capacity() << endl;
    cout << "Vide ?   : " << (notes.empty() ? "oui" : "non") << endl;
    cout << "Premier  : " << notes.front() << endl;
    cout << "Dernier  : " << notes.back() << endl;
    cout << "Élément[2] (at) : " << notes.at(2) << endl;

    // -----------------------------------------------------------------------
    // PARTIE 2 : Différentes façons de parcourir
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 2 : Parcours ===" << endl;

    // a) Par indice
    cout << "Par indice     : ";
    for (size_t i = 0; i < notes.size(); i++) {
        cout << notes[i] << " ";
    }
    cout << endl;

    // b) Par itérateur
    cout << "Par itérateur  : ";
    for (vector<int>::iterator it = notes.begin(); it != notes.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // c) Range-based for
    cout << "Range-based    : ";
    for (int n : notes) {
        cout << n << " ";
    }
    cout << endl;

    // d) Range-based const ref
    cout << "Const ref      : ";
    for (const int& n : notes) {
        cout << n << " ";
    }
    cout << endl;

    // -----------------------------------------------------------------------
    // PARTIE 3 : Algorithmes STL
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 3 : Algorithmes STL ===" << endl;

    afficher(notes, "Avant tri :");

    sort(notes.begin(), notes.end());
    afficher(notes, "Après sort :");

    reverse(notes.begin(), notes.end());
    afficher(notes, "Après reverse :");

    // Recherche
    auto it = find(notes.begin(), notes.end(), 92);
    if (it != notes.end())
        cout << "Trouvé 92 à l'indice " << (it - notes.begin()) << endl;
    else
        cout << "92 non trouvé." << endl;

    // Count
    notes.push_back(85);
    cout << "Nombre d'occurrences de 85 : " << count(notes.begin(), notes.end(), 85) << endl;

    // Min et Max
    auto minIt = min_element(notes.begin(), notes.end());
    auto maxIt = max_element(notes.begin(), notes.end());
    cout << "Min : " << *minIt << "  Max : " << *maxIt << endl;

    // Somme (accumulate)
    int somme = accumulate(notes.begin(), notes.end(), 0);
    cout << "Somme : " << somme << endl;
    cout << "Moyenne : " << fixed << setprecision(2)
         << static_cast<double>(somme) / notes.size() << endl;

    // -----------------------------------------------------------------------
    // PARTIE 4 : Suppression
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 4 : Suppression ===" << endl;
    afficher(notes, "Avant suppression :");

    notes.pop_back();  // supprime le dernier
    afficher(notes, "Après pop_back :");

    // Supprimer l'élément à l'indice 1
    notes.erase(notes.begin() + 1);
    afficher(notes, "Après erase(indice 1) :");

    // Supprimer toutes les occurrences de 85 (idiome erase-remove)
    notes.push_back(85);
    notes.push_back(85);
    afficher(notes, "Avec des 85 ajoutés :");
    notes.erase(remove(notes.begin(), notes.end(), 85), notes.end());
    afficher(notes, "Après erase-remove(85) :");

    // -----------------------------------------------------------------------
    // PARTIE 5 : Vector 2D
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 5 : Vector 2D (matrice) ===" << endl;
    int nbLignes = 3, nbCols = 4;
    vector<vector<int>> matrice(nbLignes, vector<int>(nbCols, 0));

    // Remplir
    int val = 1;
    for (int i = 0; i < nbLignes; i++) {
        for (int j = 0; j < nbCols; j++) {
            matrice[i][j] = val++;
        }
    }

    // Afficher
    for (const auto& ligne : matrice) {
        cout << "  | ";
        for (int elem : ligne) {
            cout << setw(4) << elem;
        }
        cout << " |" << endl;
    }

    // -----------------------------------------------------------------------
    // PARTIE 6 : Filtrage (copier les pairs)
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 6 : Filtrage ===" << endl;
    vector<int> source = {3, 8, 15, 22, 7, 40, 11, 36, 5, 18};
    vector<int> pairs;

    for (int v : source) {
        if (v % 2 == 0) {
            pairs.push_back(v);
        }
    }

    afficher(source, "Source :");
    afficher(pairs,  "Pairs  :");

    // Avec copy_if (alternative STL)
    vector<int> impairs;
    copy_if(source.begin(), source.end(), back_inserter(impairs),
            [](int v) { return v % 2 != 0; });
    afficher(impairs, "Impairs (copy_if) :");

    return 0;
}
