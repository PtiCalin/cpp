// ============================================================================
// SOLUTION — Indice de Masse Corporelle (IMC)
// ============================================================================
// Compiler : g++ -Wall -std=c++17 ex-imc-solution.cpp -o ex-imc
// ============================================================================

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {

    // ── Variables ─────────────────────────────────────────────────────────
    string prenom;
    double poids, taille;

    cout << "=== Calculateur d'IMC ===" << endl;

    // ── Saisie ────────────────────────────────────────────────────────────
    cout << "Prénom : ";
    cin >> prenom;

    // Validation : boucle do...while jusqu'à entrée correcte
    do {
        cout << "Poids (kg) : ";
        cin >> poids;
        if (poids <= 0) cout << "  ⚠ Le poids doit être > 0." << endl;
    } while (poids <= 0);

    do {
        cout << "Taille (m, ex: 1.75) : ";
        cin >> taille;
        if (taille <= 0) cout << "  ⚠ La taille doit être > 0." << endl;
    } while (taille <= 0);

    // ── Calcul ────────────────────────────────────────────────────────────
    // const garantit qu'on ne modifie pas accidentellement l'IMC ensuite
    const double imc = poids / (taille * taille);

    // ── Catégorie OMS ─────────────────────────────────────────────────────
    // Ordre important : du plus petit au plus grand
    string categorie;
    if      (imc < 18.5) categorie = "Insuffisance pondérale";
    else if (imc < 25.0) categorie = "Poids normal";
    else if (imc < 30.0) categorie = "Surpoids";
    else                 categorie = "Obésité";

    // ── Affichage ─────────────────────────────────────────────────────────
    // fixed + setprecision(1) : affiche exactement 1 chiffre après la virgule
    cout << "\n--- Résultat pour " << prenom << " ---" << endl;
    cout << "IMC    : " << fixed << setprecision(1) << imc << " kg/m²" << endl;
    cout << "Statut : " << categorie << endl;

    return 0;
}
