// ============================================================================
// SOLUTION — Tableau de notes dynamique
// ============================================================================
// Compiler : g++ -Wall -std=c++17 ex-tableau-dynamique-solution.cpp -o ex-tab
// ============================================================================

#include <iostream>
#include <iomanip>
#include <cassert>   // assert()

using namespace std;

// ── Prototypes ───────────────────────────────────────────────────────────────
double moyenne  (const double* tab, int n);
double minimum  (const double* tab, int n);
double maximum  (const double* tab, int n);
void   afficher (const double* tab, int n);

// ── main ─────────────────────────────────────────────────────────────────────

int main() {

    // ── Saisie de n ──────────────────────────────────────────────────────
    int n = 0;
    do {
        cout << "Nombre de notes (>= 1) : ";
        cin >> n;
        if (n < 1) cout << "  ⚠ Entrez au moins 1." << endl;
    } while (n < 1);

    // ── Allocation dynamique ──────────────────────────────────────────────
    // new[] : alloue n doubles sur le tas (heap)
    double* notes = new double[n];

    // ── Remplissage avec validation ───────────────────────────────────────
    for (int i = 0; i < n; i++) {
        do {
            cout << "Note " << (i + 1) << " (0–100) : ";
            cin >> notes[i];
            if (notes[i] < 0.0 || notes[i] > 100.0)
                cout << "  ⚠ Note invalide." << endl;
        } while (notes[i] < 0.0 || notes[i] > 100.0);
    }

    // ── Calculs et affichage ──────────────────────────────────────────────
    cout << fixed << setprecision(2);

    cout << "\n--- Résultats ---" << endl;
    afficher(notes, n);
    cout << "Moyenne : " << moyenne(notes, n) << endl;
    cout << "Minimum : " << minimum(notes, n) << endl;
    cout << "Maximum : " << maximum(notes, n) << endl;

    // ── Libération ───────────────────────────────────────────────────────
    // RÈGLE : pour new[], toujours delete[] (pas delete seul)
    delete[] notes;
    notes = nullptr;   // bonne pratique : invalider le pointeur

    // ── Vérification ─────────────────────────────────────────────────────
    // assert() plante en mode DEBUG si la condition est fausse
    assert(notes == nullptr);
    cout << "Mémoire libérée — pointeur = nullptr ✓" << endl;

    return 0;
}

// ── Implémentations ──────────────────────────────────────────────────────────

// Parcours par indice classique
double moyenne(const double* tab, int n) {
    double somme = 0.0;
    for (int i = 0; i < n; i++) somme += tab[i];
    return somme / n;
}

// Parcours par arithmétique de pointeurs
// tab pointe sur tab[0]; (tab + i) pointe sur tab[i]
double minimum(const double* tab, int n) {
    double min = *tab;                           // *tab == tab[0]
    for (int i = 1; i < n; i++) {
        if (*(tab + i) < min) min = *(tab + i);  // équivalent à tab[i]
    }
    return min;
}

double maximum(const double* tab, int n) {
    double max = *tab;
    for (int i = 1; i < n; i++) {
        if (*(tab + i) > max) max = *(tab + i);
    }
    return max;
}

void afficher(const double* tab, int n) {
    cout << "Notes : [ ";
    for (int i = 0; i < n; i++) {
        cout << tab[i];
        if (i < n - 1) cout << ", ";
    }
    cout << " ]" << endl;
}
