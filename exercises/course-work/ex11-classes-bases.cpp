// ============================================================================
// Exercice 11 — Classes : les bases
// Thème : déclaration de classe, membres privés/publics, constructeurs,
//         getters/setters, méthodes const, toString.
// ============================================================================
//
// CONSIGNES :
//   1. Créer une classe Rectangle (largeur, hauteur, aire, périmètre).
//   2. Créer une classe Etudiant (nom, matricule, notes, moyenne).
//   3. Créer une classe CompteBancaire (dépôt, retrait, solde).
//   4. Créer une classe Date (jour, mois, année, validation, affichage).
//   5. Démontrer l'encapsulation (private vs public).
//
// CONCEPTS PRATIQUÉS :
//   - class vs struct
//   - Membres privés (private) et publics (public)
//   - Constructeur par défaut et paramétré
//   - Getters / Setters
//   - Méthodes const
//   - this->
//   - Encapsulation
//
// ============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <numeric>

using namespace std;

// ===========================================================================
// Classe 1 : Rectangle
// ===========================================================================
class Rectangle {
private:
    double largeur;
    double hauteur;

public:
    // Constructeur par défaut
    Rectangle() : largeur(0), hauteur(0) {}

    // Constructeur paramétré
    Rectangle(double l, double h) : largeur(l), hauteur(h) {}

    // Getters
    double getLargeur() const { return largeur; }
    double getHauteur() const { return hauteur; }

    // Setters avec validation
    void setLargeur(double l) {
        if (l >= 0) largeur = l;
    }
    void setHauteur(double h) {
        if (h >= 0) hauteur = h;
    }

    // Méthodes const (ne modifient pas l'objet)
    double aire() const {
        return largeur * hauteur;
    }
    double perimetre() const {
        return 2 * (largeur + hauteur);
    }
    bool estCarre() const {
        return largeur == hauteur;
    }

    void afficher() const {
        cout << "Rectangle(" << largeur << " x " << hauteur
             << ") → aire=" << aire() << ", périmètre=" << perimetre()
             << (estCarre() ? " [carré]" : "") << endl;
    }
};

// ===========================================================================
// Classe 2 : Etudiant
// ===========================================================================
class Etudiant {
private:
    string nom;
    string matricule;
    vector<double> notes;

public:
    Etudiant(const string& nom, const string& matricule)
        : nom(nom), matricule(matricule) {}

    // Getters
    string getNom() const { return nom; }
    string getMatricule() const { return matricule; }
    int getNbNotes() const { return static_cast<int>(notes.size()); }

    // Ajouter une note (avec validation)
    void ajouterNote(double note) {
        if (note >= 0 && note <= 100) {
            notes.push_back(note);
        } else {
            cout << "Note invalide : " << note << endl;
        }
    }

    // Calculer la moyenne
    double moyenne() const {
        if (notes.empty()) return 0;
        double somme = accumulate(notes.begin(), notes.end(), 0.0);
        return somme / notes.size();
    }

    // Lettre correspondante
    char lettre() const {
        double m = moyenne();
        if (m >= 90) return 'A';
        if (m >= 80) return 'B';
        if (m >= 70) return 'C';
        if (m >= 60) return 'D';
        return 'F';
    }

    void afficher() const {
        cout << "Étudiant : " << nom << " (" << matricule << ")" << endl;
        cout << "  Notes  : ";
        for (double n : notes) cout << n << " ";
        cout << endl;
        cout << "  Moyenne: " << fixed << setprecision(1) << moyenne()
             << " (" << lettre() << ")" << endl;
    }
};

// ===========================================================================
// Classe 3 : CompteBancaire
// ===========================================================================
class CompteBancaire {
private:
    string titulaire;
    string numero;
    double solde;

public:
    CompteBancaire(const string& titulaire, const string& numero,
                   double soldeInitial = 0.0)
        : titulaire(titulaire), numero(numero), solde(soldeInitial) {}

    // Getters
    string getTitulaire() const { return titulaire; }
    string getNumero() const { return numero; }
    double getSolde() const { return solde; }

    // Opérations
    bool deposer(double montant) {
        if (montant > 0) {
            solde += montant;
            cout << "  + Dépôt de " << montant << "$" << endl;
            return true;
        }
        cout << "  ✗ Montant invalide." << endl;
        return false;
    }

    bool retirer(double montant) {
        if (montant > 0 && montant <= solde) {
            solde -= montant;
            cout << "  - Retrait de " << montant << "$" << endl;
            return true;
        }
        if (montant > solde) {
            cout << "  ✗ Fonds insuffisants !" << endl;
        } else {
            cout << "  ✗ Montant invalide." << endl;
        }
        return false;
    }

    bool transferer(CompteBancaire& destinataire, double montant) {
        if (retirer(montant)) {
            destinataire.deposer(montant);
            cout << "  → Transfert de " << montant << "$ vers "
                 << destinataire.getTitulaire() << endl;
            return true;
        }
        return false;
    }

    void afficher() const {
        cout << "Compte " << numero << " (" << titulaire << ")"
             << " → Solde : " << fixed << setprecision(2) << solde << "$" << endl;
    }
};

// ===========================================================================
// Classe 4 : Date
// ===========================================================================
class Date {
private:
    int jour, mois, annee;

    bool estBissextile() const {
        return (annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0);
    }

    int joursParMois() const {
        int jours[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (mois == 2 && estBissextile()) return 29;
        return jours[mois];
    }

    bool estValide() const {
        if (mois < 1 || mois > 12) return false;
        if (jour < 1 || jour > joursParMois()) return false;
        return true;
    }

public:
    Date() : jour(1), mois(1), annee(2000) {}
    Date(int j, int m, int a) : jour(j), mois(m), annee(a) {
        if (!estValide()) {
            cout << "Date invalide ! Remise à 01/01/2000." << endl;
            jour = 1; mois = 1; annee = 2000;
        }
    }

    // Getters
    int getJour() const { return jour; }
    int getMois() const { return mois; }
    int getAnnee() const { return annee; }

    // Affichage
    void afficher() const {
        cout << setfill('0') << setw(2) << jour << "/"
             << setw(2) << mois << "/" << setw(4) << annee
             << setfill(' ');
    }

    // Comparaison simple
    bool estAvant(const Date& autre) const {
        if (annee != autre.annee) return annee < autre.annee;
        if (mois != autre.mois)   return mois < autre.mois;
        return jour < autre.jour;
    }
};

// ===========================================================================
// main
// ===========================================================================
int main() {

    // -----------------------------------------------------------------------
    // PARTIE 1 : Rectangle
    // -----------------------------------------------------------------------
    cout << "=== Partie 1 : Rectangle ===" << endl;
    Rectangle r1;
    Rectangle r2(5.0, 3.0);
    Rectangle carre(4.0, 4.0);

    r1.setLargeur(10);
    r1.setHauteur(7);

    r1.afficher();
    r2.afficher();
    carre.afficher();

    // -----------------------------------------------------------------------
    // PARTIE 2 : Étudiant
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 2 : Étudiant ===" << endl;
    Etudiant etu("Alice Tremblay", "20251234");
    etu.ajouterNote(85);
    etu.ajouterNote(92);
    etu.ajouterNote(78);
    etu.ajouterNote(95);
    etu.ajouterNote(88);
    etu.afficher();

    Etudiant etu2("Bob Martin", "20259876");
    etu2.ajouterNote(55);
    etu2.ajouterNote(62);
    etu2.ajouterNote(58);
    etu2.afficher();

    // -----------------------------------------------------------------------
    // PARTIE 3 : Compte bancaire
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 3 : Compte bancaire ===" << endl;
    CompteBancaire c1("Alice", "CA-001", 1000.0);
    CompteBancaire c2("Bob", "CA-002", 500.0);

    c1.afficher();
    c2.afficher();

    cout << endl;
    c1.deposer(250.0);
    c1.retirer(100.0);
    c1.retirer(2000.0);  // insuffisant
    c1.transferer(c2, 300.0);

    cout << endl;
    c1.afficher();
    c2.afficher();

    // -----------------------------------------------------------------------
    // PARTIE 4 : Date
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 4 : Date ===" << endl;
    Date d1(15, 6, 2025);
    Date d2(29, 2, 2024);  // 2024 est bissextile → valide
    Date d3(29, 2, 2023);  // 2023 n'est pas bissextile → invalide

    cout << "d1 = "; d1.afficher(); cout << endl;
    cout << "d2 = "; d2.afficher(); cout << endl;
    cout << "d3 = "; d3.afficher(); cout << endl;

    cout << "d1 avant d2 ? " << (d1.estAvant(d2) ? "oui" : "non") << endl;
    cout << "d2 avant d1 ? " << (d2.estAvant(d1) ? "oui" : "non") << endl;

    // -----------------------------------------------------------------------
    // PARTIE 5 : Encapsulation
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 5 : Encapsulation ===" << endl;
    cout << "Les données sont PRIVÉES :" << endl;
    cout << "  etu.getNom()       → " << etu.getNom() << endl;
    cout << "  etu.getMatricule() → " << etu.getMatricule() << endl;
    // etu.nom = "Hack";  // ERREUR : 'nom' est private
    cout << "  etu.nom = \"Hack\" → ERREUR de compilation (private)" << endl;
    cout << "  On doit passer par les getters/setters → encapsulation !" << endl;

    return 0;
}
