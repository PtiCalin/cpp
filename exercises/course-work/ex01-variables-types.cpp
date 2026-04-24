// ============================================================================
// Exercice 01 — Variables et Types
// Thème : Déclarer, initialiser et manipuler les types fondamentaux.
// ============================================================================
//
// CONSIGNES :
//   1. Déclarer une variable de chaque type fondamental (int, double, char, bool, string).
//   2. Lire le nom, l'âge et la taille (en mètres) de l'utilisateur.
//   3. Calculer l'année de naissance approximative.
//   4. Afficher un résumé formaté.
//   5. Démontrer les conversions de type (int ↔ double, char ↔ int).
//
// CONCEPTS PRATIQUÉS :
//   - Types fondamentaux (int, double, char, bool, string)
//   - Entrée / sortie (cin, cout)
//   - static_cast<>
//   - Constantes (const)
//   - Opérateurs arithmétiques
//
// ============================================================================

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {

    // --- 1. Déclaration de variables de chaque type ---
    int age;
    double taille;
    char initiale;
    bool estEtudiant;
    string nom;

    const int ANNEE_COURANTE = 2026;

    // --- 2. Saisie utilisateur ---
    cout << "=== Fiche personnelle ===" << endl;
    cout << "Nom complet : ";
    getline(cin, nom);

    cout << "Initiale du prénom : ";
    cin >> initiale;

    cout << "Âge : ";
    cin >> age;

    cout << "Taille en mètres (ex: 1.75) : ";
    cin >> taille;

    cout << "Êtes-vous étudiant(e) ? (1 = oui, 0 = non) : ";
    cin >> estEtudiant;

    // --- 3. Calcul ---
    int anneeNaissance = ANNEE_COURANTE - age;
    double tailleEnCm = taille * 100.0;
    int codeAscii = static_cast<int>(initiale);

    // --- 4. Affichage formaté ---
    cout << "\n=== Résumé ===" << endl;
    cout << "Nom           : " << nom << endl;
    cout << "Initiale      : " << initiale << " (ASCII " << codeAscii << ")" << endl;
    cout << "Âge           : " << age << " ans" << endl;
    cout << "Année naiss.  : ~" << anneeNaissance << endl;
    cout << "Taille        : " << fixed << setprecision(2) << taille << " m ("
         << static_cast<int>(tailleEnCm) << " cm)" << endl;
    cout << "Étudiant(e)   : " << (estEtudiant ? "Oui" : "Non") << endl;

    // --- 5. Démonstration de conversions ---
    cout << "\n=== Conversions de type ===" << endl;

    double pi = 3.14159;
    int piTronque = static_cast<int>(pi);
    cout << "double " << pi << " → int " << piTronque << endl;

    int entier = 65;
    char lettre = static_cast<char>(entier);
    cout << "int " << entier << " → char '" << lettre << "'" << endl;

    float petitFloat = 3.14f;
    double grandDouble = static_cast<double>(petitFloat);
    cout << "float " << petitFloat << " → double " << grandDouble << endl;

    return 0;
}
