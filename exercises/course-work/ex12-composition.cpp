// ============================================================================
// Exercice 12 — Composition de classes
// Thème : classes contenant d'autres classes, relation « a un » (has-a).
// ============================================================================
//
// CONSIGNES :
//   1. Créer une classe Adresse (rue, ville, codePostal).
//   2. Créer une classe Personne qui CONTIENT une Adresse.
//   3. Créer une classe Moteur et une classe Voiture qui contient un Moteur.
//   4. Créer un Cours avec un vecteur d'Étudiants (composition 1-N).
//   5. Démontrer la construction en cascade (initialisation des membres).
//
// CONCEPTS PRATIQUÉS :
//   - Composition (objet membre)
//   - Relation « has-a »
//   - Liste d'initialisation avec objets membres
//   - Composition 1-1 et 1-N
//   - Constructeurs en cascade
//
// ============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <numeric>

using namespace std;

// ===========================================================================
// Classe Adresse
// ===========================================================================
class Adresse {
private:
    string rue;
    string ville;
    string codePostal;
    string province;

public:
    Adresse() : rue(""), ville(""), codePostal(""), province("") {}

    Adresse(const string& rue, const string& ville,
            const string& codePostal, const string& province = "QC")
        : rue(rue), ville(ville), codePostal(codePostal), province(province) {}

    // Getters
    string getRue() const { return rue; }
    string getVille() const { return ville; }
    string getCodePostal() const { return codePostal; }

    string toString() const {
        return rue + ", " + ville + " (" + province + ") " + codePostal;
    }

    void afficher() const {
        cout << toString();
    }
};

// ===========================================================================
// Classe Personne (contient une Adresse — composition 1-1)
// ===========================================================================
class Personne {
private:
    string nom;
    string prenom;
    int age;
    Adresse adresse;  // ← COMPOSITION : Personne « a une » Adresse

public:
    Personne(const string& prenom, const string& nom, int age,
             const Adresse& adresse)
        : nom(nom), prenom(prenom), age(age), adresse(adresse) {}

    // Getters
    string getNomComplet() const { return prenom + " " + nom; }
    int getAge() const { return age; }
    const Adresse& getAdresse() const { return adresse; }

    // Setter pour changer d'adresse (déménagement)
    void demenager(const Adresse& nouvelleAdresse) {
        adresse = nouvelleAdresse;
    }

    void afficher() const {
        cout << "Personne : " << getNomComplet() << " (" << age << " ans)" << endl;
        cout << "  Adresse : "; adresse.afficher(); cout << endl;
    }
};

// ===========================================================================
// Classe Moteur
// ===========================================================================
class Moteur {
private:
    double cylindree;  // en litres
    int chevaux;
    string type;       // "essence", "diesel", "électrique"

public:
    Moteur() : cylindree(0), chevaux(0), type("inconnu") {}
    Moteur(double cyl, int ch, const string& type)
        : cylindree(cyl), chevaux(ch), type(type) {}

    double getCylindree() const { return cylindree; }
    int getChevaux() const { return chevaux; }
    string getType() const { return type; }

    void afficher() const {
        cout << type << " " << cylindree << "L " << chevaux << "ch";
    }
};

// ===========================================================================
// Classe Voiture (contient un Moteur — composition 1-1)
// ===========================================================================
class Voiture {
private:
    string marque;
    string modele;
    int annee;
    Moteur moteur;  // ← COMPOSITION

public:
    Voiture(const string& marque, const string& modele, int annee,
            const Moteur& moteur)
        : marque(marque), modele(modele), annee(annee), moteur(moteur) {}

    void afficher() const {
        cout << annee << " " << marque << " " << modele << " [";
        moteur.afficher();
        cout << "]" << endl;
    }
};

// ===========================================================================
// Classe EtudiantSimple (pour la composition 1-N du Cours)
// ===========================================================================
class EtudiantSimple {
private:
    string nom;
    string matricule;
    double noteFinale;

public:
    EtudiantSimple(const string& nom, const string& mat, double note = 0)
        : nom(nom), matricule(mat), noteFinale(note) {}

    string getNom() const { return nom; }
    string getMatricule() const { return matricule; }
    double getNote() const { return noteFinale; }

    void setNote(double n) {
        if (n >= 0 && n <= 100) noteFinale = n;
    }

    void afficher() const {
        cout << "  " << left << setw(20) << nom
             << " (" << matricule << ")  Note: "
             << fixed << setprecision(1) << noteFinale << endl;
    }
};

// ===========================================================================
// Classe Cours (contient un vector<EtudiantSimple> — composition 1-N)
// ===========================================================================
class Cours {
private:
    string sigle;
    string titre;
    string session;
    vector<EtudiantSimple> etudiants;  // ← COMPOSITION 1-N

public:
    Cours(const string& sigle, const string& titre, const string& session)
        : sigle(sigle), titre(titre), session(session) {}

    // Ajouter un étudiant
    void inscrire(const EtudiantSimple& etu) {
        etudiants.push_back(etu);
    }

    // Trouver un étudiant par matricule
    EtudiantSimple* trouver(const string& matricule) {
        for (auto& e : etudiants) {
            if (e.getMatricule() == matricule) return &e;
        }
        return nullptr;
    }

    // Moyenne du cours
    double moyenneCours() const {
        if (etudiants.empty()) return 0;
        double somme = 0;
        for (const auto& e : etudiants) somme += e.getNote();
        return somme / etudiants.size();
    }

    // Nombre d'inscrits
    int nbInscrits() const { return static_cast<int>(etudiants.size()); }

    void afficher() const {
        cout << sigle << " — " << titre << " (" << session << ")" << endl;
        cout << "Inscrits : " << nbInscrits() << endl;
        for (const auto& e : etudiants) {
            e.afficher();
        }
        if (!etudiants.empty()) {
            cout << "  Moyenne du cours : " << fixed << setprecision(1)
                 << moyenneCours() << endl;
        }
    }
};

// ===========================================================================
// main
// ===========================================================================
int main() {

    // -----------------------------------------------------------------------
    // PARTIE 1-2 : Personne + Adresse
    // -----------------------------------------------------------------------
    cout << "=== Parties 1-2 : Personne avec Adresse ===" << endl;

    Adresse adr1("2900 Boul. Édouard-Montpetit", "Montréal", "H3T 1J4");
    Adresse adr2("123 Rue Principale", "Québec", "G1K 2A1");

    Personne p1("Charlie", "Bouchard", 22, adr1);
    Personne p2("Alice", "Tremblay", 25, adr2);

    p1.afficher();
    p2.afficher();

    // Déménagement
    cout << "\n--- Déménagement ---" << endl;
    Adresse nouvAdr("456 Av. du Parc", "Montréal", "H2W 1S6");
    p1.demenager(nouvAdr);
    p1.afficher();

    // -----------------------------------------------------------------------
    // PARTIE 3 : Voiture + Moteur
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 3 : Voiture avec Moteur ===" << endl;

    Moteur m1(2.0, 150, "essence");
    Moteur m2(0.0, 300, "électrique");
    Moteur m3(3.0, 250, "diesel");

    Voiture v1("Toyota", "Corolla", 2023, m1);
    Voiture v2("Tesla", "Model 3", 2024, m2);
    Voiture v3("BMW", "X5", 2022, m3);

    v1.afficher();
    v2.afficher();
    v3.afficher();

    // -----------------------------------------------------------------------
    // PARTIE 4 : Cours avec Étudiants (1-N)
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 4 : Cours avec Étudiants ===" << endl;

    Cours ift1166("IFT1166", "Programmation orientée objet en C++", "Hiver 2026");

    ift1166.inscrire(EtudiantSimple("Charlie Bouchard", "20251001", 92.5));
    ift1166.inscrire(EtudiantSimple("Alice Tremblay",   "20251002", 85.0));
    ift1166.inscrire(EtudiantSimple("Bob Martin",       "20251003", 78.3));
    ift1166.inscrire(EtudiantSimple("Claire Dupont",    "20251004", 91.2));
    ift1166.inscrire(EtudiantSimple("David Roy",        "20251005", 67.8));

    ift1166.afficher();

    // Modifier la note d'un étudiant
    cout << "\n--- Modification de note ---" << endl;
    EtudiantSimple* etu = ift1166.trouver("20251003");
    if (etu) {
        cout << "Ancienne note de " << etu->getNom() << " : " << etu->getNote() << endl;
        etu->setNote(82.0);
        cout << "Nouvelle note : " << etu->getNote() << endl;
    }

    cout << "\nNouvelle moyenne du cours : " << fixed << setprecision(1)
         << ift1166.moyenneCours() << endl;

    // -----------------------------------------------------------------------
    // PARTIE 5 : Construction en cascade
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 5 : Construction en cascade ===" << endl;
    cout << "Quand on construit une Personne :" << endl;
    cout << "  1. Le constructeur d'Adresse est appelé d'abord" << endl;
    cout << "  2. Puis le constructeur de Personne utilise l'Adresse" << endl;
    cout << "  3. Les membres sont initialisés dans l'ordre de déclaration" << endl;

    // Construction inline (en une seule expression)
    Personne directe("Marc", "Gagnon", 30,
                     Adresse("789 Rue Sherbrooke", "Montréal", "H2L 1K2"));
    directe.afficher();

    return 0;
}
