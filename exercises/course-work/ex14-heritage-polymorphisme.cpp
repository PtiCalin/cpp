// ============================================================================
// Exercice 14 — Héritage et polymorphisme
// Thème : classe de base, classe dérivée, virtual, override, polymorphisme.
// ============================================================================
//
// CONSIGNES :
//   1. Créer une hiérarchie Forme → Cercle, Rectangle, Triangle.
//   2. Utiliser des méthodes virtuelles (aire, périmètre, afficher).
//   3. Démontrer le polymorphisme avec un tableau de Forme*.
//   4. Créer une hiérarchie Employe → Salarié, Horaire, Commissionnaire.
//   5. Utiliser le destructeur virtuel.
//   6. Démontrer protected, redéfinition et appel à la méthode parent.
//
// CONCEPTS PRATIQUÉS :
//   - Héritage (public)
//   - Constructeur de la classe dérivée (: Base(...))
//   - Méthodes virtuelles (virtual) et override
//   - Polymorphisme (pointeurs de base)
//   - Classe abstraite (= 0, méthode virtuelle pure)
//   - Destructeur virtuel
//   - protected
//
// ============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

// ===========================================================================
// Hiérarchie 1 : Formes géométriques (classe abstraite)
// ===========================================================================

class Forme {
protected:
    string nom;
    string couleur;

public:
    Forme(const string& nom, const string& couleur = "noir")
        : nom(nom), couleur(couleur) {}

    // DESTRUCTEUR VIRTUEL — indispensable pour le polymorphisme
    virtual ~Forme() {}

    // Méthodes virtuelles pures → classe ABSTRAITE
    virtual double aire() const = 0;
    virtual double perimetre() const = 0;

    // Méthode virtuelle avec implémentation par défaut
    virtual void afficher() const {
        cout << nom << " [" << couleur << "] "
             << "aire=" << fixed << setprecision(2) << aire()
             << " périmètre=" << perimetre() << endl;
    }

    string getNom() const { return nom; }
    string getCouleur() const { return couleur; }
};

// ---- Cercle ---------------------------------------------------------------
class Cercle : public Forme {
private:
    double rayon;

public:
    Cercle(double r, const string& couleur = "noir")
        : Forme("Cercle", couleur), rayon(r) {}

    double getRayon() const { return rayon; }

    double aire() const override {
        return M_PI * rayon * rayon;
    }

    double perimetre() const override {
        return 2 * M_PI * rayon;
    }

    void afficher() const override {
        cout << "Cercle(r=" << rayon << ") [" << couleur << "] "
             << "aire=" << fixed << setprecision(2) << aire()
             << " périmètre=" << perimetre() << endl;
    }
};

// ---- RectangleForme -------------------------------------------------------
class RectangleForme : public Forme {
private:
    double largeur, hauteur;

public:
    RectangleForme(double l, double h, const string& couleur = "noir")
        : Forme("Rectangle", couleur), largeur(l), hauteur(h) {}

    double aire() const override {
        return largeur * hauteur;
    }

    double perimetre() const override {
        return 2 * (largeur + hauteur);
    }

    void afficher() const override {
        cout << "Rectangle(" << largeur << "x" << hauteur << ") ["
             << couleur << "] aire=" << fixed << setprecision(2) << aire()
             << " périmètre=" << perimetre() << endl;
    }
};

// ---- Triangle -------------------------------------------------------------
class Triangle : public Forme {
private:
    double a, b, c;  // côtés

public:
    Triangle(double a, double b, double c, const string& couleur = "noir")
        : Forme("Triangle", couleur), a(a), b(b), c(c) {}

    double aire() const override {
        // Formule de Héron
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double perimetre() const override {
        return a + b + c;
    }

    void afficher() const override {
        cout << "Triangle(" << a << "," << b << "," << c << ") ["
             << couleur << "] aire=" << fixed << setprecision(2) << aire()
             << " périmètre=" << perimetre() << endl;
    }
};

// ===========================================================================
// Hiérarchie 2 : Employés
// ===========================================================================

class Employe {
protected:
    string nom;
    string poste;

public:
    Employe(const string& nom, const string& poste)
        : nom(nom), poste(poste) {}

    virtual ~Employe() {}

    // Méthode virtuelle pure
    virtual double salaire() const = 0;

    virtual void afficher() const {
        cout << left << setw(20) << nom << setw(15) << poste
             << "Salaire: " << fixed << setprecision(2) << salaire() << "$" << endl;
    }

    string getNom() const { return nom; }
};

// ---- Salarié (salaire fixe mensuel) --------------------------------------
class Salarie : public Employe {
private:
    double salaireMensuel;

public:
    Salarie(const string& nom, const string& poste, double salaireMensuel)
        : Employe(nom, poste), salaireMensuel(salaireMensuel) {}

    double salaire() const override {
        return salaireMensuel;
    }
};

// ---- Horaire (payé à l'heure) --------------------------------------------
class Horaire : public Employe {
private:
    double tauxHoraire;
    double heures;

public:
    Horaire(const string& nom, const string& poste,
            double taux, double heures)
        : Employe(nom, poste), tauxHoraire(taux), heures(heures) {}

    double salaire() const override {
        // Temps supplémentaire après 40h (1.5×)
        if (heures <= 40)
            return tauxHoraire * heures;
        else
            return tauxHoraire * 40 + tauxHoraire * 1.5 * (heures - 40);
    }

    void afficher() const override {
        Employe::afficher();   // appel à la méthode parent
        cout << "           " << heures << "h @ " << tauxHoraire << "$/h" << endl;
    }
};

// ---- Commissionnaire (salaire de base + commission) ----------------------
class Commissionnaire : public Employe {
private:
    double salaireBase;
    double ventes;
    double tauxCommission;  // ex: 0.10 = 10%

public:
    Commissionnaire(const string& nom, const string& poste,
                    double base, double ventes, double taux)
        : Employe(nom, poste), salaireBase(base),
          ventes(ventes), tauxCommission(taux) {}

    double salaire() const override {
        return salaireBase + ventes * tauxCommission;
    }

    void afficher() const override {
        Employe::afficher();
        cout << "           Base: " << salaireBase << "$ + "
             << (tauxCommission * 100) << "% de " << ventes << "$" << endl;
    }
};

// ===========================================================================
// main
// ===========================================================================
int main() {

    // -----------------------------------------------------------------------
    // PARTIE 1-2 : Formes avec méthodes virtuelles
    // -----------------------------------------------------------------------
    cout << "=== Parties 1-2 : Formes géométriques ===" << endl;

    Cercle c(5.0, "rouge");
    RectangleForme r(4.0, 6.0, "bleu");
    Triangle t(3.0, 4.0, 5.0, "vert");

    c.afficher();
    r.afficher();
    t.afficher();

    // -----------------------------------------------------------------------
    // PARTIE 3 : Polymorphisme (tableau de Forme*)
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 3 : Polymorphisme ===" << endl;

    // On ne peut PAS créer un objet Forme directement (abstraite)
    // Forme f("test");  // ERREUR !

    vector<Forme*> formes;
    formes.push_back(new Cercle(3.0, "jaune"));
    formes.push_back(new RectangleForme(5.0, 2.0, "violet"));
    formes.push_back(new Triangle(5.0, 5.0, 5.0, "orange"));
    formes.push_back(new Cercle(10.0, "blanc"));
    formes.push_back(new RectangleForme(8.0, 8.0, "gris"));

    // Parcours polymorphique — chaque forme appelle SA version de afficher
    cout << "Toutes les formes :" << endl;
    for (const Forme* f : formes) {
        cout << "  ";
        f->afficher();
    }

    // Calculer l'aire totale
    double aireTotal = 0;
    for (const Forme* f : formes) {
        aireTotal += f->aire();
    }
    cout << "\nAire totale : " << fixed << setprecision(2) << aireTotal << endl;

    // Libérer la mémoire
    for (Forme* f : formes) {
        delete f;  // le destructeur virtuel garantit le bon destructeur
    }
    formes.clear();

    // -----------------------------------------------------------------------
    // PARTIE 4 : Employés
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 4 : Employés ===" << endl;

    vector<Employe*> employes;
    employes.push_back(new Salarie("Alice Tremblay", "Directrice", 5000.0));
    employes.push_back(new Horaire("Bob Martin", "Technicien", 25.0, 45.0));
    employes.push_back(new Commissionnaire("Claire Dupont", "Vendeuse",
                                           2000.0, 15000.0, 0.10));
    employes.push_back(new Horaire("David Roy", "Caissier", 18.0, 35.0));

    double masseSalariale = 0;
    for (const Employe* e : employes) {
        e->afficher();
        masseSalariale += e->salaire();
    }
    cout << "\nMasse salariale totale : " << fixed << setprecision(2)
         << masseSalariale << "$" << endl;

    for (Employe* e : employes) delete e;

    // -----------------------------------------------------------------------
    // PARTIE 5-6 : Destructeur virtuel et protected
    // -----------------------------------------------------------------------
    cout << "\n=== Parties 5-6 : Notes importantes ===" << endl;
    cout << "1. DESTRUCTEUR VIRTUEL :" << endl;
    cout << "   Sans 'virtual ~Forme()', delete sur un Forme*" << endl;
    cout << "   n'appellerait PAS le destructeur de Cercle → fuite mémoire !" << endl;
    cout << endl;
    cout << "2. PROTECTED :" << endl;
    cout << "   Les membres 'protected' sont accessibles dans les classes" << endl;
    cout << "   dérivées mais PAS depuis l'extérieur." << endl;
    cout << "   Ex: 'nom' et 'couleur' sont utilisables dans Cercle." << endl;
    cout << endl;
    cout << "3. APPEL AU PARENT :" << endl;
    cout << "   Employe::afficher() dans Horaire::afficher() appelle" << endl;
    cout << "   la version de base avant d'ajouter les détails." << endl;

    return 0;
}
