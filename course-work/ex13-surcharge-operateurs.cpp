// ============================================================================
// Exercice 13 — Surcharge d'opérateurs
// Thème : operator+, operator==, operator<<, operator[], friend.
// ============================================================================
//
// CONSIGNES :
//   1. Créer une classe Fraction avec surcharge de +, -, *, ==, !=.
//   2. Surcharger << pour l'affichage avec cout.
//   3. Surcharger les opérateurs de comparaison (<, >, <=, >=).
//   4. Créer une classe Vecteur2D avec +, -, *, ==, <<.
//   5. Surcharger ++ (pré et post), [] et l'opérateur d'affectation =.
//   6. Démontrer l'utilisation de friend.
//
// CONCEPTS PRATIQUÉS :
//   - Surcharge d'opérateurs (membre et non-membre)
//   - Mot-clé friend
//   - operator<<, operator>>, operator+, operator==
//   - Pré-incrément (++obj) vs post-incrément (obj++)
//   - operator[] pour l'accès par indice
//   - Retour par référence vs par valeur
//
// ============================================================================

#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

// ===========================================================================
// Classe Fraction
// ===========================================================================
class Fraction {
private:
    int numerateur;
    int denominateur;

    // Réduire la fraction (PGCD)
    void reduire() {
        if (denominateur < 0) {
            numerateur = -numerateur;
            denominateur = -denominateur;
        }
        int g = pgcd(abs(numerateur), abs(denominateur));
        if (g > 1) {
            numerateur /= g;
            denominateur /= g;
        }
    }

    static int pgcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

public:
    Fraction(int num = 0, int den = 1) : numerateur(num), denominateur(den) {
        if (den == 0) {
            cout << "Erreur : dénominateur nul ! Mis à 1." << endl;
            denominateur = 1;
        }
        reduire();
    }

    // Getters
    int getNum() const { return numerateur; }
    int getDen() const { return denominateur; }

    // Valeur décimale
    double valeur() const {
        return static_cast<double>(numerateur) / denominateur;
    }

    // --- Opérateurs arithmétiques (membre) ---

    Fraction operator+(const Fraction& f) const {
        return Fraction(numerateur * f.denominateur + f.numerateur * denominateur,
                       denominateur * f.denominateur);
    }

    Fraction operator-(const Fraction& f) const {
        return Fraction(numerateur * f.denominateur - f.numerateur * denominateur,
                       denominateur * f.denominateur);
    }

    Fraction operator*(const Fraction& f) const {
        return Fraction(numerateur * f.numerateur,
                       denominateur * f.denominateur);
    }

    Fraction operator/(const Fraction& f) const {
        return Fraction(numerateur * f.denominateur,
                       denominateur * f.numerateur);
    }

    // Opérateur unaire -
    Fraction operator-() const {
        return Fraction(-numerateur, denominateur);
    }

    // --- Opérateurs de comparaison ---

    bool operator==(const Fraction& f) const {
        return numerateur == f.numerateur && denominateur == f.denominateur;
    }

    bool operator!=(const Fraction& f) const {
        return !(*this == f);
    }

    bool operator<(const Fraction& f) const {
        return numerateur * f.denominateur < f.numerateur * denominateur;
    }

    bool operator>(const Fraction& f) const {
        return f < *this;
    }

    bool operator<=(const Fraction& f) const {
        return !(f < *this);
    }

    bool operator>=(const Fraction& f) const {
        return !(*this < f);
    }

    // --- friend pour <<  et >> ---
    friend ostream& operator<<(ostream& os, const Fraction& f);
    friend istream& operator>>(istream& is, Fraction& f);
};

ostream& operator<<(ostream& os, const Fraction& f) {
    if (f.denominateur == 1)
        os << f.numerateur;
    else
        os << f.numerateur << "/" << f.denominateur;
    return os;
}

istream& operator>>(istream& is, Fraction& f) {
    char slash;
    is >> f.numerateur >> slash >> f.denominateur;
    f.reduire();
    return is;
}

// ===========================================================================
// Classe Vecteur2D
// ===========================================================================
class Vecteur2D {
private:
    double x, y;

public:
    Vecteur2D(double x = 0, double y = 0) : x(x), y(y) {}

    double getX() const { return x; }
    double getY() const { return y; }

    double norme() const {
        return sqrt(x * x + y * y);
    }

    // Addition
    Vecteur2D operator+(const Vecteur2D& v) const {
        return Vecteur2D(x + v.x, y + v.y);
    }

    // Soustraction
    Vecteur2D operator-(const Vecteur2D& v) const {
        return Vecteur2D(x - v.x, y - v.y);
    }

    // Produit scalaire
    double operator*(const Vecteur2D& v) const {
        return x * v.x + y * v.y;
    }

    // Multiplication par un scalaire (membre)
    Vecteur2D operator*(double s) const {
        return Vecteur2D(x * s, y * s);
    }

    // Égalité
    bool operator==(const Vecteur2D& v) const {
        return (abs(x - v.x) < 1e-9) && (abs(y - v.y) < 1e-9);
    }

    bool operator!=(const Vecteur2D& v) const {
        return !(*this == v);
    }

    // Pré-incrément (++v)
    Vecteur2D& operator++() {
        x += 1;
        y += 1;
        return *this;
    }

    // Post-incrément (v++)
    Vecteur2D operator++(int) {
        Vecteur2D ancien = *this;
        x += 1;
        y += 1;
        return ancien;
    }

    // Accès par indice []
    double& operator[](int i) {
        if (i == 0) return x;
        if (i == 1) return y;
        throw out_of_range("Indice invalide (0 ou 1)");
    }

    const double& operator[](int i) const {
        if (i == 0) return x;
        if (i == 1) return y;
        throw out_of_range("Indice invalide (0 ou 1)");
    }

    // friend pour scalaire * vecteur (ordre inversé)
    friend Vecteur2D operator*(double s, const Vecteur2D& v);
    friend ostream& operator<<(ostream& os, const Vecteur2D& v);
};

// Scalaire * vecteur (non-membre, friend)
Vecteur2D operator*(double s, const Vecteur2D& v) {
    return Vecteur2D(v.x * s, v.y * s);
}

ostream& operator<<(ostream& os, const Vecteur2D& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

// ===========================================================================
// main
// ===========================================================================
int main() {

    // -----------------------------------------------------------------------
    // PARTIE 1 : Fractions — arithmétique
    // -----------------------------------------------------------------------
    cout << "=== Partie 1 : Fractions ===" << endl;
    Fraction a(1, 2);   // 1/2
    Fraction b(2, 3);   // 2/3
    Fraction c(3, 6);   // = 1/2 après réduction

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << " (3/6 réduit)" << endl;

    cout << "a + b = " << (a + b) << endl;       // 7/6
    cout << "a - b = " << (a - b) << endl;       // -1/6
    cout << "a * b = " << (a * b) << endl;       // 1/3
    cout << "a / b = " << (a / b) << endl;       // 3/4
    cout << "-a    = " << (-a) << endl;           // -1/2
    cout << "a.valeur() = " << a.valeur() << endl;

    // -----------------------------------------------------------------------
    // PARTIE 2-3 : Fractions — comparaison et <<
    // -----------------------------------------------------------------------
    cout << "\n=== Parties 2-3 : Comparaisons ===" << endl;
    cout << "a == c ? " << (a == c ? "oui" : "non") << endl;  // oui (1/2 == 1/2)
    cout << "a != b ? " << (a != b ? "oui" : "non") << endl;  // oui
    cout << "a < b  ? " << (a < b ? "oui" : "non") << endl;   // oui
    cout << "b > a  ? " << (b > a ? "oui" : "non") << endl;   // oui

    // Saisie avec >>
    cout << "\nEntrez une fraction (ex: 3/4) : ";
    Fraction saisie;
    cin >> saisie;
    cout << "Vous avez entré : " << saisie << " = " << saisie.valeur() << endl;

    // -----------------------------------------------------------------------
    // PARTIE 4 : Vecteur2D
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 4 : Vecteur2D ===" << endl;
    Vecteur2D v1(3, 4);
    Vecteur2D v2(1, 2);

    cout << "v1 = " << v1 << "  norme = " << v1.norme() << endl;
    cout << "v2 = " << v2 << endl;
    cout << "v1 + v2 = " << (v1 + v2) << endl;
    cout << "v1 - v2 = " << (v1 - v2) << endl;
    cout << "v1 · v2 = " << (v1 * v2) << " (produit scalaire)" << endl;
    cout << "v1 * 3  = " << (v1 * 3) << endl;
    cout << "3 * v1  = " << (3 * v1) << endl;  // grâce à friend

    // -----------------------------------------------------------------------
    // PARTIE 5 : ++ et []
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 5 : ++ et [] ===" << endl;
    Vecteur2D v3(5, 10);
    cout << "v3       = " << v3 << endl;
    cout << "++v3     = " << (++v3) << endl;    // (6, 11)
    cout << "v3++     = " << (v3++) << endl;    // retourne (6, 11), v3 devient (7, 12)
    cout << "v3 après = " << v3 << endl;        // (7, 12)

    cout << "v3[0]    = " << v3[0] << endl;     // 7
    cout << "v3[1]    = " << v3[1] << endl;     // 12

    v3[0] = 99;
    cout << "Après v3[0]=99 : " << v3 << endl;

    // -----------------------------------------------------------------------
    // PARTIE 6 : Résumé friend
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 6 : Résumé friend ===" << endl;
    cout << "friend permet à une fonction NON-MEMBRE d'accéder aux" << endl;
    cout << "membres privés d'une classe." << endl;
    cout << "Cas d'usage typiques :" << endl;
    cout << "  1. operator<< et operator>> (le flux est à gauche)" << endl;
    cout << "  2. Opérateurs symétriques (5 * vecteur)" << endl;
    cout << "  3. Fonctions utilitaires proches de la classe" << endl;

    return 0;
}
