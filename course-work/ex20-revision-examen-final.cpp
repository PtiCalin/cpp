// =============================================================================
// Exercices de révision — Examen final IFT1166
// Chapitres 11 à 18
// =============================================================================
// Ce fichier contient des exercices pratiques simulant le format de l'examen.
// Chaque section correspond à un type d'exercice de l'examen.
// =============================================================================

#include <iostream>
#include <cstring>
using namespace std;

// =============================================================================
// EXERCICE 4 — Sortie de programme (héritage + ligature dynamique)
// =============================================================================
// Pour chaque bloc, prédire la sortie AVANT de compiler.

// --- Bloc A : Ligature statique vs. dynamique ---
namespace BlocA {
    class Animal {
    public:
        virtual void parler() { cout << "..." << endl; }
        void manger()         { cout << "Animal mange" << endl; }
    };

    class Chat : public Animal {
    public:
        void parler() override { cout << "Miaou!" << endl; }
        void manger()          { cout << "Chat mange du poisson" << endl; }
    };

    void test() {
        cout << "=== Bloc A ===" << endl;
        Chat c;
        Animal* ptr = &c;

        ptr->parler();   // Quelle sortie ?
        ptr->manger();   // Quelle sortie ?

        c.parler();      // Quelle sortie ?
        c.manger();      // Quelle sortie ?
    }
    /*
     * Réponse attendue :
     * === Bloc A ===
     * Miaou!                (virtual → ligature dynamique → Chat::parler)
     * Animal mange           (pas virtual → ligature statique → Animal::manger)
     * Miaou!                (appel direct sur Chat)
     * Chat mange du poisson  (appel direct sur Chat)
     */
}

// --- Bloc B : Ordre constructeurs / destructeurs ---
namespace BlocB {
    class Base {
    public:
        Base()  { cout << "C.Base" << endl; }
        virtual ~Base() { cout << "D.Base" << endl; }
    };

    class Derivee : public Base {
    public:
        Derivee()  { cout << "C.Derivee" << endl; }
        ~Derivee() { cout << "D.Derivee" << endl; }
    };

    void test() {
        cout << "=== Bloc B ===" << endl;
        {
            Derivee d;
        }
        cout << "---" << endl;
        {
            Base* p = new Derivee();
            delete p;
        }
    }
    /*
     * Réponse attendue :
     * === Bloc B ===
     * C.Base
     * C.Derivee
     * D.Derivee
     * D.Base
     * ---
     * C.Base
     * C.Derivee
     * D.Derivee    (grâce au destructeur virtual)
     * D.Base
     */
}

// --- Bloc C : Membres statiques ---
namespace BlocC {
    class Compteur {
    public:
        static int nb;
        Compteur()  { nb++; }
        ~Compteur() { nb--; }
    };
    int Compteur::nb = 0;

    void test() {
        cout << "=== Bloc C ===" << endl;
        cout << Compteur::nb << endl;
        Compteur a;
        cout << Compteur::nb << endl;
        {
            Compteur b, c;
            cout << Compteur::nb << endl;
        }
        cout << Compteur::nb << endl;
    }
    /*
     * Réponse attendue :
     * === Bloc C ===
     * 0
     * 1
     * 3
     * 1
     */
}

// --- Bloc D : Polymorphisme avec classe abstraite ---
namespace BlocD {
    class Forme {
    public:
        virtual void dessiner() = 0;
        virtual ~Forme() {}
    };

    class Cercle : public Forme {
    public:
        void dessiner() override { cout << "O" << endl; }
    };

    class Carre : public Forme {
    public:
        void dessiner() override { cout << "[]" << endl; }
    };

    void afficherForme(Forme* f) {
        f->dessiner();
    }

    void test() {
        cout << "=== Bloc D ===" << endl;
        // Forme f;  // ERREUR : classe abstraite
        Cercle c;
        Carre  r;
        Forme* formes[] = { &c, &r, &c };
        for (int i = 0; i < 3; i++) {
            afficherForme(formes[i]);
        }
    }
    /*
     * Réponse attendue :
     * === Bloc D ===
     * O
     * []
     * O
     */
}


// =============================================================================
// EXERCICE 5 — Correction de bogues
// =============================================================================
// Chaque fonction contient une ou plusieurs erreurs.
// Identifier et corriger (en commentaire).

namespace Bogues {

    // --- Bogue 1 : Erreur de syntaxe ---
    /*
    class Etudiant {
        string nom;
        int note;
    public:
        Etudiant(string n, int note) {
            nom = n;
            note = note;   // BOGUE : auto-affectation, devrait être this->note = note;
        }
        void afficher() {
            cout << nom << " : " << note << endl;
        }
    }   // BOGUE : point-virgule manquant après }
    */

    // --- Bogue 2 : Fuite mémoire ---
    /*
    class Tableau {
        int* data;
        int taille;
    public:
        Tableau(int n) : taille(n) {
            data = new int[n];
        }
        // BOGUE : pas de destructeur → fuite mémoire
        // Correction :
        // ~Tableau() { delete [] data; }

        // BOGUE : pas de constructeur de recopie → copie superficielle
        // Correction :
        // Tableau(const Tableau& T) {
        //     taille = T.taille;
        //     data = new int[taille];
        //     for (int i = 0; i < taille; i++) data[i] = T.data[i];
        // }
    };
    */

    // --- Bogue 3 : Héritage et constructeur ---
    /*
    class Vehicule {
        double vitesse;
    public:
        Vehicule(double v) : vitesse(v) {}
    };

    class Avion : public Vehicule {
        int moteurs;
    public:
        Avion(int m, double v) {
            // BOGUE : pas d'appel au constructeur de Vehicule
            // Vehicule n'a pas de constructeur par défaut
            // Correction : Avion(int m, double v) : Vehicule(v), moteurs(m) {}
            moteurs = m;
        }
    };
    */

    // --- Bogue 4 : Opérateur d'affectation incorrect ---
    /*
    class Buffer {
        char* data;
        int taille;
    public:
        Buffer(int n) : taille(n) { data = new char[n]; }
        ~Buffer() { delete [] data; }

        Buffer& operator=(const Buffer& B) {
            // BOGUE 1 : pas de test d'auto-affectation
            // BOGUE 2 : pas de libération de l'ancienne mémoire
            data = new char[taille = B.taille];
            for (int i = 0; i < taille; i++) data[i] = B.data[i];
            return *this;
            // Correction :
            // if (this != &B) {
            //     delete [] data;
            //     data = new char[taille = B.taille];
            //     for (int i = 0; i < taille; i++) data[i] = B.data[i];
            // }
            // return *this;
        }
    };
    */
}


// =============================================================================
// EXERCICE 6 — Codage (héritage + ligature dynamique)
// =============================================================================
// Consigne : Implémenter la hiérarchie de classes décrite ci-dessous.

/*
 * ÉNONCÉ :
 *
 * Créer une hiérarchie pour un système de gestion de comptes bancaires :
 *
 * 1. Classe abstraite « Compte » :
 *    - Données : titulaire (char[50]), solde (double)
 *    - Constructeur paramétré
 *    - Méthode virtuelle pure : void afficher() const
 *    - Méthode : double getSolde() const
 *    - Méthode : void deposer(double montant)
 *    - Méthode virtuelle : bool retirer(double montant)
 *      → Retrait refusé si montant > solde
 *    - Destructeur virtuel
 *
 * 2. Classe « CompteCourant » héritant de Compte :
 *    - Données : fraisMensuels (double)
 *    - Redéfinir afficher() pour montrer aussi les frais
 *    - Redéfinir retirer() pour appliquer des frais de 1.50$ par retrait
 *
 * 3. Classe « CompteEpargne » héritant de Compte :
 *    - Données : tauxInteret (double)
 *    - Redéfinir afficher() pour montrer aussi le taux
 *    - Ajouter : void appliquerInteret()
 *      → solde += solde * tauxInteret
 *
 * 4. Dans main() :
 *    - Créer un tableau de Compte* contenant les deux types
 *    - Appeler afficher() sur chaque (polymorphisme)
 *    - Effectuer des dépôts et retraits
 *    - Libérer la mémoire
 */

// --- SOLUTION ---

class Compte {
protected:
    char titulaire[50];
    double solde;
public:
    Compte(const char* nom, double s) : solde(s) {
        strncpy(titulaire, nom, 49);
        titulaire[49] = '\0';
    }

    virtual void afficher() const = 0;

    double getSolde() const { return solde; }

    void deposer(double montant) {
        if (montant > 0) solde += montant;
    }

    virtual bool retirer(double montant) {
        if (montant > solde || montant <= 0) return false;
        solde -= montant;
        return true;
    }

    virtual ~Compte() {}
};

class CompteCourant : public Compte {
    double fraisMensuels;
public:
    CompteCourant(const char* nom, double s, double frais)
        : Compte(nom, s), fraisMensuels(frais) {}

    void afficher() const override {
        cout << "[Courant] " << titulaire
             << " | Solde: " << solde
             << "$ | Frais: " << fraisMensuels << "$/mois" << endl;
    }

    bool retirer(double montant) override {
        double total = montant + 1.50;
        if (total > solde || montant <= 0) return false;
        solde -= total;
        return true;
    }
};

class CompteEpargne : public Compte {
    double tauxInteret;
public:
    CompteEpargne(const char* nom, double s, double taux)
        : Compte(nom, s), tauxInteret(taux) {}

    void afficher() const override {
        cout << "[Epargne] " << titulaire
             << " | Solde: " << solde
             << "$ | Taux: " << tauxInteret * 100 << "%" << endl;
    }

    void appliquerInteret() {
        solde += solde * tauxInteret;
    }
};


// =============================================================================
// main — Exécution des exercices
// =============================================================================

int main() {
    // --- Exercice 4 : Sorties de programme ---
    BlocA::test();
    cout << endl;
    BlocB::test();
    cout << endl;
    BlocC::test();
    cout << endl;
    BlocD::test();
    cout << endl;

    // --- Exercice 6 : Codage ---
    cout << "=== Exercice 6 : Comptes ===" << endl;

    const int NB = 3;
    Compte* comptes[NB];
    comptes[0] = new CompteCourant("Alice", 1500.0, 4.95);
    comptes[1] = new CompteEpargne("Bob", 5000.0, 0.025);
    comptes[2] = new CompteCourant("Charlie", 200.0, 3.95);

    // Affichage polymorphique
    for (int i = 0; i < NB; i++) {
        comptes[i]->afficher();
    }

    cout << endl;

    // Opérations
    comptes[0]->deposer(500.0);
    comptes[1]->deposer(1000.0);

    if (comptes[2]->retirer(50.0))
        cout << "Retrait de 50$ OK" << endl;
    else
        cout << "Retrait refuse" << endl;

    // Intérêts sur l'épargne (cast nécessaire)
    CompteEpargne* ep = dynamic_cast<CompteEpargne*>(comptes[1]);
    if (ep) ep->appliquerInteret();

    cout << endl;
    for (int i = 0; i < NB; i++) {
        comptes[i]->afficher();
    }

    // Libération mémoire
    for (int i = 0; i < NB; i++) {
        delete comptes[i];
    }

    return 0;
}
