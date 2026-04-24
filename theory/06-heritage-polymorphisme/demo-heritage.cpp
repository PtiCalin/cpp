// demo-heritage.cpp
// Démonstration : héritage public, redéfinition, constructeurs, virtual
// IFT1166 — Chapitre 15-16
// Compiler : g++ -Wall -std=c++17 demo-heritage.cpp -o demo-heritage

#include <iostream>
#include <string>
using namespace std;

// ─────────────────────────────────────────────
// Classe de BASE
// ─────────────────────────────────────────────
class Vehicule {
protected:
    double vitesse;      // accessible aux dérivées
    int    nbPassagers;
private:
    string marque;       // inaccessible aux dérivées directement
public:
    // Constructeur
    Vehicule(const string& m, double v, int np)
        : marque(m), vitesse(v), nbPassagers(np) {
        cout << "[Vehicule] Constructeur appelé pour " << marque << "\n";
    }

    // Destructeur virtuel — OBLIGATOIRE si polymorphisme avec delete
    virtual ~Vehicule() {
        cout << "[Vehicule] Destructeur appelé pour " << marque << "\n";
    }

    // Méthode normale (ligature statique si pas virtual)
    void affiche() const {
        cout << "Marque=" << marque
             << " Vitesse=" << vitesse
             << " Passagers=" << nbPassagers << "\n";
    }

    // Méthode virtuelle (ligature dynamique)
    virtual string type() const {
        return "Vehicule";
    }

    double getVitesse()     const { return vitesse; }
    int    getNbPassagers() const { return nbPassagers; }
    string getMarque()      const { return marque; }
};

// ─────────────────────────────────────────────
// Classe DÉRIVÉE 1 : Avion
// ─────────────────────────────────────────────
class Avion : public Vehicule {
private:
    int nbreMoteurs;
public:
    // Constructeur : appel obligatoire au constructeur base
    Avion(const string& m, int nm, double v, int np)
        : Vehicule(m, v, np), nbreMoteurs(nm) {
        cout << "[Avion] Constructeur appelé\n";
    }

    ~Avion() override {
        cout << "[Avion] Destructeur appelé\n";
    }

    // Redéfinition (masquage) de affiche — appel version base +  ajout
    void affiche() const {
        Vehicule::affiche();               // appel version base
        cout << "  Moteurs=" << nbreMoteurs << "\n";
    }

    // Override de la méthode virtuelle
    string type() const override {
        return "Avion";
    }
};

// ─────────────────────────────────────────────
// Classe DÉRIVÉE 2 : Voiture
// ─────────────────────────────────────────────
class Voiture : public Vehicule {
private:
    int nbPortes;
public:
    Voiture(const string& m, double v, int np, int p)
        : Vehicule(m, v, np), nbPortes(p) {
        cout << "[Voiture] Constructeur appelé\n";
    }

    ~Voiture() override {
        cout << "[Voiture] Destructeur appelé\n";
    }

    void affiche() const {
        Vehicule::affiche();
        cout << "  Portes=" << nbPortes << "\n";
    }

    string type() const override {
        return "Voiture";
    }
};

// ─────────────────────────────────────────────
// Démontre la ligature statique vs. dynamique
// ─────────────────────────────────────────────
void demoLigature() {
    cout << "\n=== Ligature statique vs. dynamique ===\n";

    Avion a("Airbus", 4, 900.0, 300);

    // Ligature STATIQUE : type déclaré = Vehicule → Vehicule::type()
    Vehicule* pv = &a;
    cout << "Via Vehicule* (statique sur affiche()) : ";
    pv->affiche();   // → Vehicule::affiche() (pas virtual)

    // Ligature DYNAMIQUE : type() est virtual → Avion::type()
    cout << "Via Vehicule* (dynamique sur type())  : " << pv->type() << "\n";
}

// ─────────────────────────────────────────────
// Démontre le polymorphisme avec tableau de pointeurs
// ─────────────────────────────────────────────
void demoPolymorphisme() {
    cout << "\n=== Polymorphisme : tableau de Vehicule* ===\n";

    const int N = 3;
    Vehicule* garage[N] = {
        new Vehicule("Generique", 60.0, 1),
        new Avion("Boeing", 2, 800.0, 180),
        new Voiture("Toyota", 120.0, 4, 4)
    };

    for (int i = 0; i < N; i++) {
        cout << "Type réel : " << garage[i]->type() << "\n";
    }

    // Libération — destructeur virtuel garantit la chaîne complète
    for (int i = 0; i < N; i++) {
        delete garage[i];
    }
}

// ─────────────────────────────────────────────
// Démontre le slicing (danger de l'affectation objet)
// ─────────────────────────────────────────────
void demoSlicing() {
    cout << "\n=== Slicing ===\n";

    Avion a("Concorde", 4, 2100.0, 100);

    // Affectation à un objet base → slicing : nbreMoteurs perdu
    Vehicule v = a;                // membres Avion tronqués
    cout << "type() via objet Vehicule : " << v.type() << "\n";  // "Vehicule"

    // Pointeur/référence → pas de slicing
    Vehicule& rv = a;
    cout << "type() via Vehicule&     : " << rv.type() << "\n";  // "Avion"
}

int main() {
    demoLigature();
    demoPolymorphisme();
    demoSlicing();

    return 0;
}
