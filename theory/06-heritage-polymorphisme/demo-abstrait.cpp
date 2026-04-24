// demo-abstrait.cpp
// Démonstration : classe abstraite, fonctions virtuelles pures, tableau polymorphique
// IFT1166 — Chapitre 16
// Compiler : g++ -Wall -std=c++17 demo-abstrait.cpp -o demo-abstrait

#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979;

// ─────────────────────────────────────────────
// Classe ABSTRAITE : Forme
// ─────────────────────────────────────────────
class Forme {
public:
    // Fonctions virtuelles pures → classe abstraite
    virtual double aire()       const = 0;
    virtual double perimetre()  const = 0;
    virtual string nom()        const = 0;

    // Méthode concrète partagée (utilise les pures)
    void affiche() const {
        cout << nom()
             << " | Aire=" << aire()
             << " | Périmètre=" << perimetre() << "\n";
    }

    // Destructeur virtuel obligatoire
    virtual ~Forme() {}
};

// ─────────────────────────────────────────────
// Classe dérivée : Cercle
// ─────────────────────────────────────────────
class Cercle : public Forme {
    double rayon;
public:
    explicit Cercle(double r) : rayon(r) {}

    double aire()      const override { return PI * rayon * rayon; }
    double perimetre() const override { return 2.0 * PI * rayon; }
    string nom()       const override { return "Cercle(r=" + to_string(rayon) + ")"; }
};

// ─────────────────────────────────────────────
// Classe dérivée : Rectangle
// ─────────────────────────────────────────────
class Rectangle : public Forme {
    double largeur, hauteur;
public:
    Rectangle(double l, double h) : largeur(l), hauteur(h) {}

    double aire()      const override { return largeur * hauteur; }
    double perimetre() const override { return 2.0 * (largeur + hauteur); }
    string nom()       const override {
        return "Rectangle(" + to_string(largeur) + "x" + to_string(hauteur) + ")";
    }
};

// ─────────────────────────────────────────────
// Classe dérivée : Triangle rectangle
// ─────────────────────────────────────────────
class TriangleRect : public Forme {
    double base, hauteur;
public:
    TriangleRect(double b, double h) : base(b), hauteur(h) {}

    double aire()      const override { return 0.5 * base * hauteur; }
    double perimetre() const override {
        double hyp = sqrt(base * base + hauteur * hauteur);
        return base + hauteur + hyp;
    }
    string nom() const override {
        return "TriangleRect(" + to_string(base) + "x" + to_string(hauteur) + ")";
    }
};

// ─────────────────────────────────────────────
// Classe partiellement abstraite : FormeColoree
// Ne définit pas perimetre() → reste abstraite
// ─────────────────────────────────────────────
class FormeColoree : public Forme {
protected:
    string couleur;
public:
    explicit FormeColoree(const string& c) : couleur(c) {}
    string nom() const override { return "FormeColoree [" + couleur + "]"; }
    // perimetre() toujours pure → FormeColoree reste abstraite
    // FormeColoree fc("rouge");  → ERREUR : classe abstraite
};

// ─────────────────────────────────────────────
// main
// ─────────────────────────────────────────────
int main() {
    // Forme f;   → ERREUR de compilation : classe abstraite

    // Tableau polymorphique de pointeurs vers Forme
    const int N = 4;
    Forme* tableau[N] = {
        new Cercle(5.0),
        new Rectangle(4.0, 6.0),
        new TriangleRect(3.0, 4.0),
        new Cercle(1.0)
    };

    cout << "=== Affichage polymorphique ===\n";
    for (int i = 0; i < N; i++) {
        tableau[i]->affiche();
    }

    // Trouver la plus grande aire
    int maxIdx = 0;
    for (int i = 1; i < N; i++) {
        if (tableau[i]->aire() > tableau[maxIdx]->aire())
            maxIdx = i;
    }
    cout << "\nPlus grande aire : " << tableau[maxIdx]->nom()
         << " = " << tableau[maxIdx]->aire() << "\n";

    // Libération via destructeur virtuel
    for (int i = 0; i < N; i++) {
        delete tableau[i];
    }

    return 0;
}
