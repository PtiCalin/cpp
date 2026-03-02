// ============================================================================
// Exercice 17 — STL : Conteneurs et algorithmes
// Thème : map, set, pair, sort personnalisé, lambda, itérateurs avancés.
// ============================================================================
//
// CONSIGNES :
//   1. Utiliser map<string, int> pour un dictionnaire fréquentiel.
//   2. Utiliser set<T> pour stocker des éléments uniques.
//   3. Utiliser pair<T1, T2> et structured bindings (C++17).
//   4. Trier avec un comparateur personnalisé (lambda).
//   5. Utiliser les algorithmes for_each, transform, all_of, any_of.
//   6. Challenge : annuaire téléphonique avec map et recherche.
//
// CONCEPTS PRATIQUÉS :
//   - map, multimap, set, multiset, pair
//   - Itérateurs (begin, end, rbegin, rend)
//   - Lambda expressions [](params) { body }
//   - sort avec comparateur personnalisé
//   - for_each, transform, count_if, all_of, any_of, none_of
//   - auto, range-based for avec structured bindings
//
// ============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iomanip>
#include <cctype>

using namespace std;

int main() {

    // -----------------------------------------------------------------------
    // PARTIE 1 : map — dictionnaire fréquentiel
    // -----------------------------------------------------------------------
    cout << "=== Partie 1 : map (compteur de mots) ===" << endl;

    string texte = "le chat mange le poisson le chat dort le poisson nage";
    map<string, int> frequences;

    // Compter les mots
    istringstream iss(texte);
    string mot;
    while (iss >> mot) {
        frequences[mot]++;   // [] crée l'entrée si elle n'existe pas
    }

    // Afficher
    cout << "Texte : \"" << texte << "\"" << endl;
    cout << "Fréquences :" << endl;
    for (const auto& paire : frequences) {
        cout << "  " << left << setw(12) << paire.first
             << " → " << paire.second << " fois" << endl;
    }

    // Recherche dans un map
    string cherche = "chat";
    auto it = frequences.find(cherche);
    if (it != frequences.end())
        cout << "\"" << cherche << "\" trouvé : " << it->second << " fois" << endl;

    cout << "Nombre de mots uniques : " << frequences.size() << endl;

    // -----------------------------------------------------------------------
    // PARTIE 2 : set — éléments uniques
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 2 : set ===" << endl;

    set<int> nombres;
    nombres.insert(42);
    nombres.insert(17);
    nombres.insert(42);   // doublon → ignoré
    nombres.insert(8);
    nombres.insert(99);
    nombres.insert(17);   // doublon → ignoré

    cout << "Éléments (triés, uniques) : ";
    for (int n : nombres) {
        cout << n << " ";
    }
    cout << "  (size=" << nombres.size() << ")" << endl;

    // Vérifier l'appartenance
    cout << "42 présent ? " << (nombres.count(42) ? "oui" : "non") << endl;
    cout << "50 présent ? " << (nombres.count(50) ? "oui" : "non") << endl;

    // Set de strings (tri alphabétique automatique)
    set<string> langages = {"C++", "Python", "Java", "C++", "Rust", "Python"};
    cout << "Langages : ";
    for (const string& l : langages) cout << l << " ";
    cout << endl;

    // -----------------------------------------------------------------------
    // PARTIE 3 : pair et structured bindings
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 3 : pair ===" << endl;

    pair<string, int> etudiant = make_pair("Alice", 92);
    cout << etudiant.first << " : " << etudiant.second << endl;

    // Avec auto
    auto coord = make_pair(3.14, 2.71);
    cout << "Coordonnées : (" << coord.first << ", " << coord.second << ")" << endl;

    // Parcours de map avec structured bindings (C++17)
    cout << "\nParcours avec auto& [clé, valeur] :" << endl;
    for (const auto& [mot, freq] : frequences) {
        cout << "  " << mot << " = " << freq << endl;
    }

    // -----------------------------------------------------------------------
    // PARTIE 4 : Tri personnalisé avec lambda
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 4 : Tri personnalisé ===" << endl;

    struct Personne {
        string nom;
        int age;
        double note;
    };

    vector<Personne> personnes = {
        {"Charlie", 22, 88.5},
        {"Alice", 25, 92.0},
        {"Bob", 20, 85.3},
        {"Diana", 23, 95.1},
        {"Eve", 21, 78.9}
    };

    // Tri par âge (ascendant)
    sort(personnes.begin(), personnes.end(),
         [](const Personne& a, const Personne& b) {
             return a.age < b.age;
         });

    cout << "Par âge :" << endl;
    for (const auto& p : personnes) {
        cout << "  " << left << setw(10) << p.nom
             << "âge=" << p.age << "  note=" << p.note << endl;
    }

    // Tri par note (descendant)
    sort(personnes.begin(), personnes.end(),
         [](const Personne& a, const Personne& b) {
             return a.note > b.note;
         });

    cout << "\nPar note (desc) :" << endl;
    for (const auto& p : personnes) {
        cout << "  " << left << setw(10) << p.nom
             << "note=" << p.note << endl;
    }

    // Tri par nom (alphabétique)
    sort(personnes.begin(), personnes.end(),
         [](const Personne& a, const Personne& b) {
             return a.nom < b.nom;
         });

    cout << "\nPar nom :" << endl;
    for (const auto& p : personnes) {
        cout << "  " << p.nom << endl;
    }

    // -----------------------------------------------------------------------
    // PARTIE 5 : Algorithmes avancés
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 5 : Algorithmes STL ===" << endl;

    vector<int> v = {3, 8, 15, 22, 7, 40, 11, 36, 5, 18};

    // for_each — appliquer une action
    cout << "for_each (×2) : ";
    for_each(v.begin(), v.end(), [](int& n) { n *= 2; });
    for (int n : v) cout << n << " ";
    cout << endl;

    // transform — créer un nouveau vecteur
    vector<int> carres(v.size());
    transform(v.begin(), v.end(), carres.begin(),
              [](int n) { return n * n; });
    cout << "transform (²)  : ";
    for (int n : carres) cout << n << " ";
    cout << endl;

    // count_if
    int nbPairs = count_if(v.begin(), v.end(),
                           [](int n) { return n % 2 == 0; });
    cout << "Nombres pairs  : " << nbPairs << endl;

    // all_of, any_of, none_of
    cout << "Tous positifs ? " << (all_of(v.begin(), v.end(),
        [](int n) { return n > 0; }) ? "oui" : "non") << endl;

    cout << "Au moins un > 50 ? " << (any_of(v.begin(), v.end(),
        [](int n) { return n > 50; }) ? "oui" : "non") << endl;

    cout << "Aucun négatif ? " << (none_of(v.begin(), v.end(),
        [](int n) { return n < 0; }) ? "oui" : "non") << endl;

    // accumulate avec lambda
    int somme = accumulate(v.begin(), v.end(), 0);
    int produit = accumulate(v.begin(), v.end(), 1,
                             [](int acc, int n) { return acc + n; });
    cout << "Somme : " << somme << endl;

    // -----------------------------------------------------------------------
    // PARTIE 6 : Annuaire téléphonique
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 6 : Annuaire téléphonique ===" << endl;

    map<string, vector<string>> annuaire;

    // Ajouter des contacts (certains avec plusieurs numéros)
    annuaire["Alice Tremblay"].push_back("514-555-0001");
    annuaire["Alice Tremblay"].push_back("438-555-0011");
    annuaire["Bob Martin"].push_back("514-555-0002");
    annuaire["Claire Dupont"].push_back("450-555-0003");
    annuaire["Claire Dupont"].push_back("514-555-0033");
    annuaire["Claire Dupont"].push_back("819-555-0333");
    annuaire["David Roy"].push_back("514-555-0004");

    // Afficher l'annuaire
    cout << "Annuaire complet :" << endl;
    for (const auto& [nom, numeros] : annuaire) {
        cout << "  " << left << setw(20) << nom << " : ";
        for (size_t i = 0; i < numeros.size(); i++) {
            if (i > 0) cout << ", ";
            cout << numeros[i];
        }
        cout << endl;
    }

    // Recherche
    string recherche = "Claire Dupont";
    auto itAnn = annuaire.find(recherche);
    if (itAnn != annuaire.end()) {
        cout << "\nRecherche \"" << recherche << "\" : "
             << itAnn->second.size() << " numéro(s)" << endl;
        for (const string& num : itAnn->second) {
            cout << "  → " << num << endl;
        }
    }

    // Supprimer un contact
    annuaire.erase("David Roy");
    cout << "\nAprès suppression de David Roy : "
         << annuaire.size() << " contacts." << endl;

    return 0;
}
