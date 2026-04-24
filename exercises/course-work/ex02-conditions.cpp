// ============================================================================
// Exercice 02 — Conditions et logique
// Thème : Maîtriser if/else, switch, opérateurs logiques et ternaire.
// ============================================================================
//
// CONSIGNES :
//   1. Lire une note sur 100 et afficher la lettre correspondante (A–F).
//   2. Lire un mois (1–12) et afficher la saison avec switch.
//   3. Lire un année et déterminer si elle est bissextile.
//   4. Calculateur d'IMC avec catégorie.
//   5. Mini-quiz vrai/faux (3 questions, score final).
//
// CONCEPTS PRATIQUÉS :
//   - if / else if / else
//   - switch / case / default / break
//   - Opérateurs logiques (&&, ||, !)
//   - Opérateur ternaire (? :)
//   - Imbrication de conditions
//
// ============================================================================

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {

    // -----------------------------------------------------------------------
    // PARTIE 1 : Note → Lettre
    // -----------------------------------------------------------------------
    cout << "=== Partie 1 : Conversion note → lettre ===" << endl;
    double note;
    cout << "Entrez une note sur 100 : ";
    cin >> note;

    char lettre;
    if (note >= 90)      lettre = 'A';
    else if (note >= 80) lettre = 'B';
    else if (note >= 70) lettre = 'C';
    else if (note >= 60) lettre = 'D';
    else if (note >= 50) lettre = 'E';
    else                 lettre = 'F';

    string mention = (note >= 90) ? "Excellent !" :
                     (note >= 70) ? "Bien"        : "À améliorer";

    cout << "Note : " << note << "/100 → " << lettre << " (" << mention << ")" << endl;

    // -----------------------------------------------------------------------
    // PARTIE 2 : Mois → Saison (switch)
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 2 : Mois → Saison ===" << endl;
    int mois;
    cout << "Entrez un mois (1–12) : ";
    cin >> mois;

    switch (mois) {
        case 12: case 1: case 2:
            cout << "Hiver" << endl;
            break;
        case 3: case 4: case 5:
            cout << "Printemps" << endl;
            break;
        case 6: case 7: case 8:
            cout << "Été" << endl;
            break;
        case 9: case 10: case 11:
            cout << "Automne" << endl;
            break;
        default:
            cout << "Mois invalide!" << endl;
    }

    // -----------------------------------------------------------------------
    // PARTIE 3 : Année bissextile
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 3 : Année bissextile ===" << endl;
    int annee;
    cout << "Entrez une année : ";
    cin >> annee;

    bool bissextile = (annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0);
    cout << annee << (bissextile ? " EST" : " N'EST PAS") << " une année bissextile." << endl;

    // -----------------------------------------------------------------------
    // PARTIE 4 : Calculateur d'IMC
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 4 : Calculateur d'IMC ===" << endl;
    double poids, taille;
    cout << "Poids (kg) : ";
    cin >> poids;
    cout << "Taille (m) : ";
    cin >> taille;

    if (taille <= 0 || poids <= 0) {
        cout << "Valeurs invalides!" << endl;
    } else {
        double imc = poids / (taille * taille);
        cout << fixed << setprecision(1);
        cout << "IMC = " << imc << " → ";

        if (imc < 18.5)      cout << "Insuffisance pondérale" << endl;
        else if (imc < 25.0) cout << "Poids normal" << endl;
        else if (imc < 30.0) cout << "Surpoids" << endl;
        else                  cout << "Obésité" << endl;
    }

    // -----------------------------------------------------------------------
    // PARTIE 5 : Mini-quiz vrai/faux
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 5 : Quiz Vrai/Faux ===" << endl;
    int score = 0;
    int reponse;

    cout << "1. C++ a été créé par Bjarne Stroustrup (1=Vrai, 0=Faux) : ";
    cin >> reponse;
    if (reponse == 1) { cout << "Correct!" << endl; score++; }
    else               cout << "Faux! C'est Bjarne Stroustrup (1979)." << endl;

    cout << "2. Un int occupe toujours exactement 4 octets (1=Vrai, 0=Faux) : ";
    cin >> reponse;
    if (reponse == 0) { cout << "Correct! C'est 'au moins 2 octets', souvent 4." << endl; score++; }
    else               cout << "Faux! La taille dépend de la plateforme." << endl;

    cout << "3. 'else if' est un mot-clé unique en C++ (1=Vrai, 0=Faux) : ";
    cin >> reponse;
    if (reponse == 0) { cout << "Correct! C'est 'else' suivi d'un 'if'." << endl; score++; }
    else               cout << "Faux! Ce sont deux mots-clés séparés." << endl;

    cout << "\nScore final : " << score << "/3" << endl;

    return 0;
}
