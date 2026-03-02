// ============================================================================
// Exercice 07 — Chaînes de caractères (string)
// Thème : manipulation de strings, recherche, extraction, conversion.
// ============================================================================
//
// CONSIGNES :
//   1. Opérations de base (longueur, concaténation, comparaison).
//   2. Accès aux caractères, itération, modification.
//   3. Fonctions de recherche (find, rfind, substr).
//   4. Fonctions de transformation (toupper, tolower, insert, erase, replace).
//   5. Conversion string ↔ nombres (stoi, stod, to_string).
//   6. Challenge : analyser une phrase (compter mots, inverser, palindrome).
//
// CONCEPTS PRATIQUÉS :
//   - string (constructeur, size, length, empty, at, [], append, +, ==)
//   - find, rfind, find_first_of, substr, npos
//   - insert, erase, replace
//   - cctype : toupper, tolower, isalpha, isdigit
//   - stoi, stod, to_string
//   - getline, stringstream
//
// ============================================================================

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {

    // -----------------------------------------------------------------------
    // PARTIE 1 : Opérations de base
    // -----------------------------------------------------------------------
    cout << "=== Partie 1 : Opérations de base ===" << endl;
    string prenom = "Charlie";
    string nom    = "Bouchard";
    string vide;

    cout << "Prénom      : " << prenom << endl;
    cout << "Longueur    : " << prenom.length() << endl;
    cout << "Taille      : " << prenom.size() << endl;
    cout << "Vide ?      : " << (vide.empty() ? "oui" : "non") << endl;

    // Concaténation
    string complet = prenom + " " + nom;
    cout << "Complet (+) : " << complet << endl;

    string salut = "Bonjour, ";
    salut.append(prenom);
    salut += " !";
    cout << "Append      : " << salut << endl;

    // Comparaison
    string a = "abc", b = "abd";
    cout << "\"abc\" == \"abd\" ? " << (a == b ? "oui" : "non") << endl;
    cout << "\"abc\" <  \"abd\" ? " << (a < b  ? "oui" : "non") << endl;
    cout << "compare()   : " << a.compare(b) << endl;

    // -----------------------------------------------------------------------
    // PARTIE 2 : Accès aux caractères
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 2 : Accès aux caractères ===" << endl;
    string mot = "Bonjour";

    cout << "Premier (at) : " << mot.at(0) << endl;
    cout << "Dernier ([]) : " << mot[mot.size() - 1] << endl;

    // Itération caractère par caractère
    cout << "Caractères   : ";
    for (char c : mot) {
        cout << c << " ";
    }
    cout << endl;

    // Modifier un caractère
    mot[0] = 'b';
    cout << "Modifié      : " << mot << endl;

    // -----------------------------------------------------------------------
    // PARTIE 3 : Recherche et extraction
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 3 : Recherche et extraction ===" << endl;
    string phrase = "Les cours de C++ sont passionnants et formateurs.";

    // find
    size_t pos = phrase.find("C++");
    if (pos != string::npos)
        cout << "\"C++\" trouvé à la position " << pos << endl;

    // rfind (dernière occurrence)
    pos = phrase.rfind("s");
    cout << "Dernier 's' à la position " << pos << endl;

    // find_first_of
    pos = phrase.find_first_of("aeiou");
    cout << "Première voyelle à la position " << pos
         << " ('" << phrase[pos] << "')" << endl;

    // substr
    string extrait = phrase.substr(15, 3);  // "C++"
    cout << "Extrait (15,3) : \"" << extrait << "\"" << endl;

    // Couper au premier espace
    string premierMot = phrase.substr(0, phrase.find(' '));
    cout << "Premier mot    : \"" << premierMot << "\"" << endl;

    // -----------------------------------------------------------------------
    // PARTIE 4 : Transformation
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 4 : Transformation ===" << endl;

    // Majuscules / minuscules
    string original = "Hello World";
    string majuscules = original;
    string minuscules = original;

    for (char& c : majuscules) c = toupper(c);
    for (char& c : minuscules) c = tolower(c);

    cout << "Original    : " << original << endl;
    cout << "MAJUSCULES  : " << majuscules << endl;
    cout << "minuscules  : " << minuscules << endl;

    // insert
    string texte = "Bonjour monde";
    texte.insert(8, "beau ");
    cout << "Insert      : " << texte << endl;

    // erase
    texte.erase(8, 5);  // enlève "beau "
    cout << "Erase       : " << texte << endl;

    // replace
    texte.replace(8, 5, "univers");
    cout << "Replace     : " << texte << endl;

    // -----------------------------------------------------------------------
    // PARTIE 5 : Conversions
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 5 : Conversions ===" << endl;

    // string → nombre
    string sEntier = "42";
    string sDecimal = "3.14159";

    int entier = stoi(sEntier);
    double decimal = stod(sDecimal);
    cout << "stoi(\"42\")      = " << entier << endl;
    cout << "stod(\"3.14159\") = " << decimal << endl;

    // nombre → string
    string fromInt = to_string(2025);
    string fromDbl = to_string(9.81);
    cout << "to_string(2025) = \"" << fromInt << "\"" << endl;
    cout << "to_string(9.81) = \"" << fromDbl << "\"" << endl;

    // Classification de caractères
    cout << "\nClassification :" << endl;
    string test = "A1 b!";
    for (char c : test) {
        cout << "  '" << c << "' : "
             << (isalpha(c) ? "lettre " : "")
             << (isdigit(c) ? "chiffre " : "")
             << (isspace(c) ? "espace " : "")
             << (ispunct(c) ? "ponctuation " : "")
             << (isupper(c) ? "MAJUSCULE " : "")
             << (islower(c) ? "minuscule " : "")
             << endl;
    }

    // -----------------------------------------------------------------------
    // PARTIE 6 : Challenge — Analyse de phrase
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 6 : Analyse de phrase ===" << endl;

    // Compter les mots avec stringstream
    string texteAnalyse = "Le renard brun rapide saute par-dessus le chien paresseux";
    istringstream iss(texteAnalyse);
    string motCourant;
    int compteurMots = 0;
    while (iss >> motCourant) {
        compteurMots++;
    }
    cout << "Phrase : \"" << texteAnalyse << "\"" << endl;
    cout << "Nombre de mots : " << compteurMots << endl;

    // Inverser une chaîne
    string aInverser = "Bonjour";
    string inverse(aInverser.rbegin(), aInverser.rend());
    cout << "\"" << aInverser << "\" inversé = \"" << inverse << "\"" << endl;

    // Vérifier si palindrome
    auto estPalindrome = [](const string& s) -> bool {
        string nettoye;
        for (char c : s) {
            if (isalpha(c)) nettoye += tolower(c);
        }
        string rev(nettoye.rbegin(), nettoye.rend());
        return nettoye == rev;
    };

    string tests[] = {"kayak", "Bonjour", "A man a plan a canal Panama", "racecar"};
    for (const string& t : tests) {
        cout << "\"" << t << "\" est palindrome ? "
             << (estPalindrome(t) ? "Oui" : "Non") << endl;
    }

    return 0;
}
