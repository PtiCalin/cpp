/* Fichier   : squelette.cpp
	Auteure  : Charlie Bouchard    
	Cours    : IFT1166 - Programmation orientée objet en C++    
	Trimestre: Hiver 2026
	But      : Squelette générique de programme C++
	Dernière mise à jour : 2026-02-27
*/

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>    
#include <cstdlib>
#include <functional>
#include <limits>
#include <stdexcept>
#include <utility>

// #include "methodes.h"
// #include "classes.h"
// #include "macros.h"

using namespace std;

/* ═══════════════════════════════════════════════════════════════
   MACROS
   ═══════════════════════════════════════════════════════════════ */
// --- Constantes ---
#define NOM_CONSTANTE valeur
// --- Macros de fonctions ---
#define NOM_MACRO(param)  ((param) * 2)

/* ═══════════════════════════════════════════════════════════════
   PROTOTYPES
   ═══════════════════════════════════════════════════════════════ */

type    nomFonction(type param1, type param2);
void    fonctionReference(type& paramRef);
void    fonctionTableau(const type tab[], int taille);
type    fonctionRetour(type param);

/* ═══════════════════════════════════════════════════════════════
   CLASSES
   ═══════════════════════════════════════════════════════════════ */

// ─── Classe de base ───────────────────────────────────────────

class Base {
private:
    type attribut1;
    type attribut2;

public:
    // Constructeur par défaut
    Base() : attribut1(valeur), attribut2(valeur) {}

    // Constructeur paramétré
    Base(type p1, type p2) : attribut1(p1), attribut2(p2) {}

    // Accesseurs
    type getAttribut1() const { return attribut1; }
    type getAttribut2() const { return attribut2; }

    // Mutateurs
    void setAttribut1(type val) { attribut1 = val; }
    void setAttribut2(type val) { attribut2 = val; }

    // Méthodes
    void afficher() const {
        cout << "attribut1: " << attribut1
             << ", attribut2: " << attribut2 << endl;
    }

    type calculer() const {
        return /* formule avec attribut1, attribut2 */;
    }

    // Surcharge de <<
    friend ostream& operator<<(ostream& os, const Base& obj) {
        os << "[" << obj.attribut1 << ", " << obj.attribut2 << "]";
        return os;
    }
};

// ─── Classe dérivée (héritage) ────────────────────────────────

class Derivee : public Base {
private:
    type attributSupp;

public:
    // Constructeur par défaut
    Derivee() : Base(), attributSupp(valeur) {}

    // Constructeur paramétré
    Derivee(type p1, type p2, type p3)
        : Base(p1, p2), attributSupp(p3) {}

    // Accesseur / Mutateur
    type getAttributSupp() const { return attributSupp; }
    void setAttributSupp(type val) { attributSupp = val; }

    // Redéfinition de méthode
    void afficher() const {
        Base::afficher();
        cout << "  attributSupp: " << attributSupp << endl;
    }

    // Méthode propre à la dérivée
    void methodeSpecifique() const {
        // ...
    }
};

// ─── Classe avec surcharge d'opérateurs ───────────────────────

class Operateurs {
private:
    type valeur;

public:
    Operateurs(type v = valeur_defaut) : valeur(v) {}

    type getValeur() const { return valeur; }

    // Arithmétique
    Operateurs operator+(const Operateurs& autre) const {
        return Operateurs(valeur + autre.valeur);
    }

    Operateurs operator-(const Operateurs& autre) const {
        return Operateurs(valeur - autre.valeur);
    }

    Operateurs operator*(const Operateurs& autre) const {
        return Operateurs(valeur * autre.valeur);
    }

    // Comparaison
    bool operator==(const Operateurs& autre) const {
        return valeur == autre.valeur;
    }

    bool operator<(const Operateurs& autre) const {
        return valeur < autre.valeur;
    }

    // Affichage
    friend ostream& operator<<(ostream& os, const Operateurs& obj) {
        os << obj.valeur;
        return os;
    }
};

// ─── Classe avec composition (vector) ─────────────────────────

class Conteneur {
private:
    string nom;
    vector<type> elements;

public:
    Conteneur(const string& nom) : nom(nom) {}

    void ajouter(type element) {
        elements.push_back(element);
    }

    bool retirer(int index) {
        if (index < 0 || index >= (int)elements.size()) return false;
        elements.erase(elements.begin() + index);
        return true;
    }

    type  getElement(int i) const { return elements[i]; }
    int   taille()          const { return elements.size(); }
    bool  estVide()         const { return elements.empty(); }

    void afficher() const {
        cout << nom << " (" << elements.size() << " éléments):" << endl;
        for (int i = 0; i < (int)elements.size(); i++)
            cout << "  [" << i << "] " << elements[i] << endl;
    }
};

/* ═══════════════════════════════════════════════════════════════
   IMPLÉMENTATION DES FONCTIONS
   ═══════════════════════════════════════════════════════════════ */

type nomFonction(type param1, type param2) {
    // Traitement
    return /* résultat */;
}

void fonctionReference(type& paramRef) {
    paramRef = /* nouvelle valeur */;
}

void fonctionTableau(const type tab[], int taille) {
    for (int i = 0; i < taille; i++) {
        // Traitement de tab[i]
    }
}

type fonctionRetour(type param) {
    if (/* condition */) {
        return /* valeur A */;
    }
    return /* valeur B */;
}

/* ═══════════════════════════════════════════════════════════════
   MAIN
   ═══════════════════════════════════════════════════════════════ */

int main() {

    // ─── Variables simples ───
    type variable = valeur;
    type tableau[] = {val1, val2, val3};
    int taille = sizeof(tableau) / sizeof(tableau[0]);

    // ─── Macros ───
    cout << NOM_CONSTANTE << endl;
    cout << NOM_MACRO(5) << endl;

    // ─── Fonctions libres ───
    type resultat = nomFonction(arg1, arg2);
    fonctionReference(variable);
    fonctionTableau(tableau, taille);

    // ─── Classe de base ───
    Base obj1;                        // Constructeur par défaut
    Base obj2(valeur1, valeur2);      // Constructeur paramétré

    obj1.setAttribut1(valeur);        // Mutateur
    type val = obj2.getAttribut1();   // Accesseur
    obj2.afficher();                  // Méthode
    cout << obj2 << endl;             // Surcharge <<

    // ─── Héritage ───
    Derivee objD(valeur1, valeur2, valeur3);
    objD.afficher();                  // Appel redéfini (Base::afficher + attributSupp)
    objD.methodeSpecifique();         // Méthode propre
    objD.getAttribut1();              // Hérité de Base

    // ─── Surcharge d'opérateurs ───
    Operateurs a(valeur1), b(valeur2);
    Operateurs somme = a + b;
    bool egal = (a == b);
    cout << a << " + " << b << " = " << somme << endl;

    // ─── Composition / vector ───
    Conteneur c("MonConteneur");
    c.ajouter(element1);
    c.ajouter(element2);
    c.afficher();
    c.retirer(0);

    // ─── Boucles courantes ───
    // for classique
    for (int i = 0; i < taille; i++) {
        // tableau[i]
    }

    // for-each
    for (type& elem : tableau) {
        // elem
    }

    // while
    int i = 0;
    while (i < taille) {
        // tableau[i]
        i++;
    }

    // ─── Conditions ───
    if (/* condition */) {
        // ...
    } else if (/* condition */) {
        // ...
    } else {
        // ...
    }

    switch (variable) {
        case valeur1: /* ... */ break;
        case valeur2: /* ... */ break;
        default:      /* ... */ break;
    }

    // ─── try/catch ───
    try {
        // Code risqué
    } catch (const exception& e) {
        cerr << "Erreur: " << e.what() << endl;
    }

    return 0;
}