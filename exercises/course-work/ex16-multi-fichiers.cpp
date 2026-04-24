// ============================================================================
// Exercice 16 — Programmation multi-fichiers
// Thème : séparation header/source, include guards, compilation séparée.
// ============================================================================
//
// NOTE : Cet exercice est un fichier UNIQUE qui SIMULE la structure
//        multi-fichiers. Les commentaires montrent où couper le code
//        pour créer les vrais .h et .cpp séparés.
//
// CONSIGNES :
//   1. Comprendre la séparation déclaration (.h) / implémentation (.cpp).
//   2. Utiliser des include guards (#ifndef / #define / #endif).
//   3. Comprendre le rôle de chaque fichier dans la compilation.
//   4. Simuler un projet avec Calculatrice, Etudiant et utilitaires.
//
// CONCEPTS PRATIQUÉS :
//   - Fichiers d'en-tête (.h) vs fichiers source (.cpp)
//   - Include guards (#ifndef HEADER_H / #define HEADER_H / #endif)
//   - #pragma once (alternative moderne)
//   - Déclaration vs définition
//   - Compilation séparée (g++ -c ... / g++ -o ...)
//   - Dépendances et ordre d'inclusion
//
// ============================================================================
//
// STRUCTURE DU PROJET SIMULÉ :
//
//   projet/
//   ├── main.cpp           ← Point d'entrée
//   ├── calculatrice.h     ← Déclarations de la classe Calculatrice
//   ├── calculatrice.cpp   ← Implémentations de Calculatrice
//   ├── etudiant.h         ← Déclarations de la classe Etudiant
//   ├── etudiant.cpp       ← Implémentations d'Etudiant
//   ├── utils.h            ← Fonctions utilitaires (déclarations)
//   └── utils.cpp          ← Fonctions utilitaires (implémentations)
//
// COMPILATION :
//   g++ -c main.cpp calculatrice.cpp etudiant.cpp utils.cpp
//   g++ -o programme main.o calculatrice.o etudiant.o utils.o
//
//   Ou en une seule commande :
//   g++ -o programme main.cpp calculatrice.cpp etudiant.cpp utils.cpp
//
// ============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <numeric>
#include <algorithm>

using namespace std;

// ===========================================================================
// ======== FICHIER : utils.h ================================================
// ===========================================================================
// #ifndef UTILS_H
// #define UTILS_H

// #include <string>

namespace Utils {
    void afficherTitre(const string& titre);
    void afficherSeparateur(int longueur = 50);
    string majuscules(const string& s);
    bool estNombre(const string& s);
}

// #endif // UTILS_H

// ===========================================================================
// ======== FICHIER : utils.cpp ==============================================
// ===========================================================================
// #include "utils.h"
// #include <iostream>
// #include <algorithm>
// #include <cctype>

namespace Utils {
    void afficherTitre(const string& titre) {
        cout << endl;
        afficherSeparateur(titre.length() + 4);
        cout << "| " << titre << " |" << endl;
        afficherSeparateur(titre.length() + 4);
    }

    void afficherSeparateur(int longueur) {
        cout << string(longueur, '=') << endl;
    }

    string majuscules(const string& s) {
        string resultat = s;
        for (char& c : resultat) c = toupper(c);
        return resultat;
    }

    bool estNombre(const string& s) {
        if (s.empty()) return false;
        for (char c : s) {
            if (!isdigit(c) && c != '.' && c != '-') return false;
        }
        return true;
    }
}

// ===========================================================================
// ======== FICHIER : calculatrice.h =========================================
// ===========================================================================
// #ifndef CALCULATRICE_H
// #define CALCULATRICE_H

class Calculatrice {
private:
    double resultat;
    int nbOperations;

public:
    Calculatrice();

    // Opérations
    double additionner(double a, double b);
    double soustraire(double a, double b);
    double multiplier(double a, double b);
    double diviser(double a, double b);

    // Accesseurs
    double getDernierResultat() const;
    int getNbOperations() const;

    void reinitialiser();
    void afficherHistorique() const;
};

// #endif // CALCULATRICE_H

// ===========================================================================
// ======== FICHIER : calculatrice.cpp =======================================
// ===========================================================================
// #include "calculatrice.h"
// #include <iostream>
// #include <iomanip>

Calculatrice::Calculatrice() : resultat(0), nbOperations(0) {}

double Calculatrice::additionner(double a, double b) {
    resultat = a + b;
    nbOperations++;
    return resultat;
}

double Calculatrice::soustraire(double a, double b) {
    resultat = a - b;
    nbOperations++;
    return resultat;
}

double Calculatrice::multiplier(double a, double b) {
    resultat = a * b;
    nbOperations++;
    return resultat;
}

double Calculatrice::diviser(double a, double b) {
    if (b == 0) {
        cout << "Erreur : division par zéro !" << endl;
        return 0;
    }
    resultat = a / b;
    nbOperations++;
    return resultat;
}

double Calculatrice::getDernierResultat() const { return resultat; }
int Calculatrice::getNbOperations() const { return nbOperations; }

void Calculatrice::reinitialiser() {
    resultat = 0;
    nbOperations = 0;
}

void Calculatrice::afficherHistorique() const {
    cout << "Dernier résultat : " << fixed << setprecision(2)
         << resultat << "  (" << nbOperations << " opérations)" << endl;
}

// ===========================================================================
// ======== FICHIER : etudiant.h =============================================
// ===========================================================================
// #ifndef ETUDIANT_H
// #define ETUDIANT_H

// #include <string>
// #include <vector>

class EtudiantMF {  // MF = Multi-File (éviter conflit avec ex11)
private:
    string nom;
    string matricule;
    vector<double> notes;

public:
    EtudiantMF(const string& nom, const string& matricule);

    void ajouterNote(double note);
    double moyenne() const;
    double noteMax() const;
    double noteMin() const;
    char lettre() const;

    string getNom() const;
    string getMatricule() const;
    int getNbNotes() const;

    void afficher() const;
};

// #endif // ETUDIANT_H

// ===========================================================================
// ======== FICHIER : etudiant.cpp ===========================================
// ===========================================================================
// #include "etudiant.h"
// #include <iostream>
// #include <iomanip>
// #include <numeric>
// #include <algorithm>

EtudiantMF::EtudiantMF(const string& nom, const string& matricule)
    : nom(nom), matricule(matricule) {}

void EtudiantMF::ajouterNote(double note) {
    if (note >= 0 && note <= 100) {
        notes.push_back(note);
    } else {
        cout << "Note invalide : " << note << endl;
    }
}

double EtudiantMF::moyenne() const {
    if (notes.empty()) return 0;
    return accumulate(notes.begin(), notes.end(), 0.0) / notes.size();
}

double EtudiantMF::noteMax() const {
    if (notes.empty()) return 0;
    return *max_element(notes.begin(), notes.end());
}

double EtudiantMF::noteMin() const {
    if (notes.empty()) return 0;
    return *min_element(notes.begin(), notes.end());
}

char EtudiantMF::lettre() const {
    double m = moyenne();
    if (m >= 90) return 'A';
    if (m >= 80) return 'B';
    if (m >= 70) return 'C';
    if (m >= 60) return 'D';
    return 'F';
}

string EtudiantMF::getNom() const { return nom; }
string EtudiantMF::getMatricule() const { return matricule; }
int EtudiantMF::getNbNotes() const { return static_cast<int>(notes.size()); }

void EtudiantMF::afficher() const {
    cout << left << setw(20) << nom << " (" << matricule << ")  "
         << "Moy: " << fixed << setprecision(1) << moyenne()
         << " (" << lettre() << ")  "
         << "Min: " << noteMin() << "  Max: " << noteMax() << endl;
}

// ===========================================================================
// ======== FICHIER : main.cpp ===============================================
// ===========================================================================
// #include "calculatrice.h"
// #include "etudiant.h"
// #include "utils.h"
// #include <iostream>

int main() {

    // -----------------------------------------------------------------------
    // PARTIE 1 : Utilitaires
    // -----------------------------------------------------------------------
    Utils::afficherTitre("EXERCICE 16 : MULTI-FICHIERS");

    cout << "Majuscules : " << Utils::majuscules("bonjour") << endl;
    cout << "estNombre(\"42\")   : " << Utils::estNombre("42") << endl;
    cout << "estNombre(\"abc\")  : " << Utils::estNombre("abc") << endl;

    // -----------------------------------------------------------------------
    // PARTIE 2 : Calculatrice
    // -----------------------------------------------------------------------
    Utils::afficherTitre("CALCULATRICE");

    Calculatrice calc;
    cout << "10 + 5 = " << calc.additionner(10, 5) << endl;
    cout << "10 - 3 = " << calc.soustraire(10, 3) << endl;
    cout << "6 * 7  = " << calc.multiplier(6, 7) << endl;
    cout << "15 / 4 = " << calc.diviser(15, 4) << endl;
    cout << "10 / 0 = "; calc.diviser(10, 0);
    calc.afficherHistorique();

    // -----------------------------------------------------------------------
    // PARTIE 3 : Étudiants
    // -----------------------------------------------------------------------
    Utils::afficherTitre("ÉTUDIANTS");

    vector<EtudiantMF> etudiants;

    EtudiantMF e1("Alice Tremblay", "20251001");
    e1.ajouterNote(85); e1.ajouterNote(92); e1.ajouterNote(78);
    etudiants.push_back(e1);

    EtudiantMF e2("Bob Martin", "20251002");
    e2.ajouterNote(72); e2.ajouterNote(68); e2.ajouterNote(80);
    etudiants.push_back(e2);

    EtudiantMF e3("Claire Dupont", "20251003");
    e3.ajouterNote(95); e3.ajouterNote(88); e3.ajouterNote(91);
    etudiants.push_back(e3);

    for (const EtudiantMF& e : etudiants) {
        e.afficher();
    }

    // -----------------------------------------------------------------------
    // PARTIE 4 : Notes de compilation
    // -----------------------------------------------------------------------
    Utils::afficherTitre("NOTES DE COMPILATION");

    cout << "Pour compiler un projet multi-fichiers :" << endl;
    cout << endl;
    cout << "  Méthode 1 (une seule commande) :" << endl;
    cout << "    g++ -o programme main.cpp calculatrice.cpp etudiant.cpp utils.cpp" << endl;
    cout << endl;
    cout << "  Méthode 2 (compilation séparée) :" << endl;
    cout << "    g++ -c main.cpp           → main.o" << endl;
    cout << "    g++ -c calculatrice.cpp    → calculatrice.o" << endl;
    cout << "    g++ -c etudiant.cpp        → etudiant.o" << endl;
    cout << "    g++ -c utils.cpp           → utils.o" << endl;
    cout << "    g++ -o programme main.o calculatrice.o etudiant.o utils.o" << endl;
    cout << endl;
    cout << "  Include Guard Pattern :" << endl;
    cout << "    #ifndef MON_HEADER_H" << endl;
    cout << "    #define MON_HEADER_H" << endl;
    cout << "    // ... déclarations ..." << endl;
    cout << "    #endif" << endl;
    cout << endl;
    cout << "  Alternative moderne : #pragma once" << endl;

    return 0;
}
