// demo-controle-flux.cpp
// Démonstration : variables, conditions, boucles, tableaux
// IFT1166 — ex01-03, ex05
// Compiler : g++ -Wall -std=c++17 demo-controle-flux.cpp -o demo-controle-flux

#include <iostream>
#include <string>
using namespace std;

int main() {
    // ── Variables et constantes ───────────────
    cout << "=== Variables et constantes ===\n";
    const int TAILLE = 5;
    int tableau[TAILLE] = {8, 3, 7, 1, 5};

    cout << "Tableau : ";
    for (int i = 0; i < TAILLE; i++) cout << tableau[i] << " ";
    cout << "\n\n";

    // ── if/else — trouver min et max ──────────
    cout << "=== if/else : min et max ===\n";
    int min = tableau[0], max = tableau[0];
    for (int i = 1; i < TAILLE; i++) {
        if (tableau[i] < min) min = tableau[i];
        if (tableau[i] > max) max = tableau[i];
    }
    cout << "Min=" << min << " Max=" << max << "\n\n";

    // ── switch — menu ─────────────────────────
    cout << "=== switch : menu ===\n";
    int choix = 2;
    switch (choix) {
        case 1:  cout << "Afficher\n"; break;
        case 2:  cout << "Calculer\n"; break;
        case 3:  cout << "Quitter\n";  break;
        default: cout << "Inconnu\n";  break;
    }
    cout << "\n";

    // ── while — puissance de 2 ─────────────────
    cout << "=== while : puissances de 2 ===\n";
    int val = 1;
    while (val <= 512) {
        cout << val << " ";
        val *= 2;
    }
    cout << "\n\n";

    // ── do...while — validation ────────────────
    cout << "=== do...while : validation ===\n";
    int n;
    do {
        cout << "Entrez un nombre entre 1 et 10 : ";
        cin >> n;
    } while (n < 1 || n > 10);
    cout << "Nombre valide : " << n << "\n\n";

    // ── for — table de multiplication ─────────
    cout << "=== for : table de " << n << " ===\n";
    for (int i = 1; i <= 10; i++) {
        cout << n << " × " << i << " = " << n * i << "\n";
    }
    cout << "\n";

    // ── range-for — calcul de somme ───────────
    cout << "=== range-for : somme du tableau ===\n";
    int somme = 0;
    for (int x : tableau) somme += x;
    cout << "Somme = " << somme << "\n";
    cout << "Moyenne = " << (double)somme / TAILLE << "\n\n";

    // ── break et continue ─────────────────────
    cout << "=== break/continue : nombres impairs < 20 ===\n";
    for (int i = 1; i < 100; i++) {
        if (i >= 20) break;
        if (i % 2 == 0) continue;
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}
