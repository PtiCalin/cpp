// demo-classes.cpp
// Démonstration complète : classes, constructeurs, destructeur,
//   membres statiques, this, const, recopie profonde, opérateur=
// IFT1166 — Chapitres 11–14
// Compiler : g++ -Wall -std=c++17 demo-classes.cpp -o demo-classes

#include <iostream>
#include <cstring>
using namespace std;

// ─────────────────────────────────────────────
// Classe Compte — illustre les chapitres 11-13
// ─────────────────────────────────────────────
class Compte {
private:
    char   nom[25];
    double actif;
    static int nbComptes;      // partagé par tous les objets

public:
    // Constructeur avec argument par défaut
    Compte(const char* n = "Anonyme", double montant = 0.0) {
        strncpy(nom, n, 24);
        nom[24] = '\0';
        actif = montant;
        nbComptes++;
        cout << "[Compte+] " << nom << " créé\n";
    }

    // Destructeur
    ~Compte() {
        nbComptes--;
        cout << "[Compte-] " << nom << " détruit\n";
    }

    // Méthodes const (ne modifient pas l'objet)
    const char* getNom()   const { return nom; }
    double      getActif() const { return actif; }

    void afficher() const {
        cout << "  " << nom << " : " << actif << "$\n";
    }

    // Méthode non-const (modifie l'objet)
    void deposer(double montant) {
        actif += montant;
    }

    // Retourne *this pour les appels en cascade
    Compte& retirerSi(double montant) {
        if (actif >= montant) actif -= montant;
        return *this;   // this en action
    }

    // Méthode statique
    static int getNbComptes() { return nbComptes; }
};

// Initialisation du membre statique hors de la classe
int Compte::nbComptes = 0;


// ─────────────────────────────────────────────
// Classe Tableau — illustre copie profonde (chapitre 14)
// ─────────────────────────────────────────────
class Tableau {
private:
    int* tab;
    int  n;
public:
    // Constructeur
    explicit Tableau(int taille) : n(taille) {
        tab = new int[n]();   // () → initialise à 0
        cout << "[Tableau+] taille=" << n << "\n";
    }

    // Destructeur
    ~Tableau() {
        delete[] tab;
        cout << "[Tableau-] taille=" << n << "\n";
    }

    // Constructeur de recopie — copie PROFONDE
    Tableau(const Tableau& T) : n(T.n) {
        tab = new int[n];
        for (int i = 0; i < n; i++) tab[i] = T.tab[i];
        cout << "[Tableau recopie] n=" << n << "\n";
    }

    // Opérateur d'affectation — copie PROFONDE
    Tableau& operator=(const Tableau& T) {
        if (this != &T) {             // éviter l'auto-affectation
            delete[] tab;
            n   = T.n;
            tab = new int[n];
            for (int i = 0; i < n; i++) tab[i] = T.tab[i];
        }
        return *this;
    }

    // Accesseurs
    void   set(int i, int val) { if (i >= 0 && i < n) tab[i] = val; }
    int    get(int i)    const { return (i >= 0 && i < n) ? tab[i] : -1; }
    int    taille()      const { return n; }

    void afficher() const {
        cout << "  [";
        for (int i = 0; i < n; i++) {
            cout << tab[i];
            if (i < n - 1) cout << ", ";
        }
        cout << "]\n";
    }
};


int main() {
    // ── Comptes ──────────────────────────────
    cout << "=== Section 1 : Comptes ===\n";
    {
        Compte c1("Alice", 500.0);
        Compte c2("Bob", 300.0);
        Compte c3;                      // constructeur par défaut

        c1.afficher();
        c2.deposer(200.0);
        c2.afficher();

        // Appels en cascade via *this
        c1.retirerSi(100.0).retirerSi(50.0);
        c1.afficher();

        cout << "Nombre de comptes : " << Compte::getNbComptes() << "\n";
    }   // c1, c2, c3 détruits ici → nbComptes revient à 0
    cout << "Comptes après le bloc : " << Compte::getNbComptes() << "\n\n";

    // ── Tableau — copie profonde ──────────────
    cout << "=== Section 2 : Copie profonde ===\n";
    {
        Tableau t1(3);
        t1.set(0, 10); t1.set(1, 20); t1.set(2, 30);

        cout << "t1 : "; t1.afficher();

        // Constructeur de recopie
        Tableau t2(t1);
        t2.set(0, 99);   // modifier t2 ne doit PAS affecter t1

        cout << "t1 après modif de t2 : "; t1.afficher();  // toujours [10, 20, 30]
        cout << "t2 : ";                    t2.afficher();  // [99, 20, 30]

        // Opérateur d'affectation
        Tableau t3(5);
        t3 = t1;
        t3.set(2, 77);

        cout << "t1 après affectation t3=t1 et modif t3 : "; t1.afficher();
        cout << "t3 : "; t3.afficher();
    }

    return 0;
}
