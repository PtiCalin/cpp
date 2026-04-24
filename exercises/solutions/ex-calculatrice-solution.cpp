// ============================================================================
// SOLUTION — Calculatrice avec surcharge de fonctions
// ============================================================================
// Compiler : g++ -Wall -std=c++17 ex-calculatrice-solution.cpp -o ex-calc
// ============================================================================

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// ── Prototypes ───────────────────────────────────────────────────────────────
// Trois surcharges : même nom, signatures différentes → le compilateur choisit
double calculer(int    a, int    b, char op, bool& erreur);
double calculer(double a, double b, char op, bool& erreur);
double calculer(int    a, double b, char op, bool& erreur);

void   tableMultiplication(int n, int limite = 10);  // paramètre par défaut
double puissance(double base, int exp);              // récursif

// ── Fonction utilitaire ───────────────────────────────────────────────────────
// Affiche le résultat ou l'erreur (évite la duplication dans main)
void afficherResultat(const string& expr, double result, bool erreur) {
    if (erreur)
        cout << expr << " → ERREUR (division par zéro)" << endl;
    else
        cout << expr << " = " << fixed << setprecision(4) << result << endl;
}

// ── main ─────────────────────────────────────────────────────────────────────

int main() {

    bool err = false;

    // ── Surcharge int, int ────────────────────────────────────────────────
    cout << "=== calculer(int, int) ===" << endl;
    afficherResultat("7 + 3",  calculer(7,  3, '+', err), err);
    afficherResultat("7 - 3",  calculer(7,  3, '-', err), err);
    afficherResultat("7 * 3",  calculer(7,  3, '*', err), err);
    afficherResultat("7 / 3",  calculer(7,  3, '/', err), err);  // entiers → résultat double
    afficherResultat("7 / 0",  calculer(7,  0, '/', err), err);  // division par zéro

    // ── Surcharge double, double ──────────────────────────────────────────
    cout << "\n=== calculer(double, double) ===" << endl;
    afficherResultat("9.5 + 0.5", calculer(9.5, 0.5, '+', err), err);
    afficherResultat("9.5 / 0.0", calculer(9.5, 0.0, '/', err), err);

    // ── Surcharge int, double ─────────────────────────────────────────────
    cout << "\n=== calculer(int, double) ===" << endl;
    afficherResultat("4 * 2.5", calculer(4, 2.5, '*', err), err);

    // ── Table de multiplication ───────────────────────────────────────────
    cout << "\n=== Table de 7 ===" << endl;
    tableMultiplication(7);

    // ── Puissance récursive ───────────────────────────────────────────────
    cout << "\n=== Puissance ===" << endl;
    cout << "2^10 = " << puissance(2, 10) << endl;
    cout << "3^0  = " << puissance(3,  0) << endl;  // cas de base
    cout << "2^-1 = " << puissance(2, -1) << endl;  // exposant négatif

    return 0;
}

// ── Implémentations ──────────────────────────────────────────────────────────

// Logique partagée — évite la duplication entre les trois surcharges
static double appliquerOp(double a, double b, char op, bool& erreur) {
    erreur = false;
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0.0) { erreur = true; return 0.0; }
            return a / b;
        default:
            cerr << "Opérateur inconnu : " << op << endl;
            erreur = true;
            return 0.0;
    }
}

// Surcharge 1 : int, int
// Note : on convertit en double pour ne pas perdre la précision
double calculer(int a, int b, char op, bool& erreur) {
    return appliquerOp(static_cast<double>(a),
                       static_cast<double>(b), op, erreur);
}

// Surcharge 2 : double, double
double calculer(double a, double b, char op, bool& erreur) {
    return appliquerOp(a, b, op, erreur);
}

// Surcharge 3 : int, double (conversion implicite du int en double)
double calculer(int a, double b, char op, bool& erreur) {
    return appliquerOp(static_cast<double>(a), b, op, erreur);
}

// Table de multiplication (paramètre par défaut : limite = 10)
void tableMultiplication(int n, int limite) {
    cout << "Table de " << n << " :" << endl;
    for (int i = 1; i <= limite; i++) {
        cout << "  " << n << " × " << i << " = " << n * i << endl;
    }
}

// Puissance récursive
// Cas de base : exp == 0  → 1
// Récursion   : base * puissance(base, exp - 1)
// Exposant négatif : 1 / puissance(base, -exp)
double puissance(double base, int exp) {
    if (exp == 0)  return 1.0;
    if (exp <  0)  return 1.0 / puissance(base, -exp);
    return base * puissance(base, exp - 1);
}
