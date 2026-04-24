// ============================================================================
// Exercice 19 — Mini-projet intégré : Système de gestion de notes
// Thème : OOP complète, fichiers, STL, héritage — exercice de synthèse.
// ============================================================================
//
// CONSIGNES :
//   Ce mini-projet combine TOUS les concepts vus dans les exercices 1-18.
//   Il implémente un système de gestion de notes avec :
//     - Classes avec héritage (Personne → Etudiant, Professeur)
//     - Composition (Cours contient des Etudiants et un Professeur)
//     - Surcharge d'opérateurs (<< pour l'affichage)
//     - STL (vector, map, sort, algorithmes)
//     - Fichiers (sauvegarde/chargement)
//     - Mémoire dynamique (tableau de pointeurs polymorphiques)
//
// CONCEPTS PRATIQUÉS (SYNTHÈSE) :
//   - Héritage et polymorphisme
//   - Composition (has-a)
//   - Surcharge d'opérateurs
//   - STL (vector, map, sort, lambda)
//   - Fichiers (ofstream, ifstream)
//   - Encapsulation, constructeurs, destructeurs
//
// ============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

// ===========================================================================
// Classe de base : Personne
// ===========================================================================
class Personne {
protected:
    string nom;
    string prenom;
    string identifiant;

public:
    Personne(const string& prenom, const string& nom, const string& id)
        : nom(nom), prenom(prenom), identifiant(id) {}

    virtual ~Personne() {}

    string getNomComplet() const { return prenom + " " + nom; }
    string getId() const { return identifiant; }

    virtual string getRole() const = 0;

    virtual void afficher() const {
        cout << "[" << getRole() << "] " << getNomComplet()
             << " (" << identifiant << ")" << endl;
    }

    friend ostream& operator<<(ostream& os, const Personne& p) {
        os << "[" << p.getRole() << "] " << p.getNomComplet()
           << " (" << p.identifiant << ")";
        return os;
    }
};

// ===========================================================================
// Classe Etudiant (hérite de Personne)
// ===========================================================================
class Etudiant : public Personne {
private:
    map<string, double> notes;  // sigle du cours → note

public:
    Etudiant(const string& prenom, const string& nom, const string& matricule)
        : Personne(prenom, nom, matricule) {}

    string getRole() const override { return "Étudiant"; }

    void ajouterNote(const string& cours, double note) {
        if (note >= 0 && note <= 100) {
            notes[cours] = note;
        }
    }

    double getNote(const string& cours) const {
        auto it = notes.find(cours);
        return (it != notes.end()) ? it->second : -1.0;
    }

    double moyenneGenerale() const {
        if (notes.empty()) return 0;
        double somme = 0;
        for (const auto& [cours, note] : notes) {
            somme += note;
        }
        return somme / notes.size();
    }

    char lettre(const string& cours) const {
        double n = getNote(cours);
        if (n < 0) return '?';
        if (n >= 90) return 'A';
        if (n >= 80) return 'B';
        if (n >= 70) return 'C';
        if (n >= 60) return 'D';
        return 'F';
    }

    int nbCours() const { return static_cast<int>(notes.size()); }

    const map<string, double>& getNotes() const { return notes; }

    void afficher() const override {
        Personne::afficher();
        if (!notes.empty()) {
            for (const auto& [cours, note] : notes) {
                cout << "    " << left << setw(10) << cours
                     << fixed << setprecision(1) << note
                     << " (" << lettre(cours) << ")" << endl;
            }
            cout << "    Moyenne : " << fixed << setprecision(1)
                 << moyenneGenerale() << endl;
        }
    }
};

// ===========================================================================
// Classe Professeur (hérite de Personne)
// ===========================================================================
class Professeur : public Personne {
private:
    string departement;

public:
    Professeur(const string& prenom, const string& nom,
               const string& id, const string& dept)
        : Personne(prenom, nom, id), departement(dept) {}

    string getRole() const override { return "Professeur"; }
    string getDepartement() const { return departement; }

    void afficher() const override {
        Personne::afficher();
        cout << "    Département : " << departement << endl;
    }
};

// ===========================================================================
// Classe Cours (composition : Professeur + vector<Etudiant*>)
// ===========================================================================
class Cours {
private:
    string sigle;
    string titre;
    string session;
    Professeur* prof;           // association (pas propriétaire)
    vector<Etudiant*> inscrits; // association 1-N

public:
    Cours(const string& sigle, const string& titre,
          const string& session, Professeur* prof = nullptr)
        : sigle(sigle), titre(titre), session(session), prof(prof) {}

    string getSigle() const { return sigle; }
    string getTitre() const { return titre; }

    void setProf(Professeur* p) { prof = p; }

    bool inscrire(Etudiant* etu) {
        // Vérifier si déjà inscrit
        for (const auto* e : inscrits) {
            if (e->getId() == etu->getId()) return false;
        }
        inscrits.push_back(etu);
        return true;
    }

    void attribuerNote(const string& matricule, double note) {
        for (auto* etu : inscrits) {
            if (etu->getId() == matricule) {
                etu->ajouterNote(sigle, note);
                return;
            }
        }
        cout << "Étudiant " << matricule << " non trouvé." << endl;
    }

    double moyenneCours() const {
        if (inscrits.empty()) return 0;
        double somme = 0;
        int count = 0;
        for (const auto* etu : inscrits) {
            double n = etu->getNote(sigle);
            if (n >= 0) { somme += n; count++; }
        }
        return count > 0 ? somme / count : 0;
    }

    // Classement par note (descendant)
    vector<Etudiant*> classement() const {
        vector<Etudiant*> classe = inscrits;
        sort(classe.begin(), classe.end(),
             [this](const Etudiant* a, const Etudiant* b) {
                 return a->getNote(sigle) > b->getNote(sigle);
             });
        return classe;
    }

    int nbInscrits() const { return static_cast<int>(inscrits.size()); }

    // Statistiques
    void afficherStatistiques() const {
        if (inscrits.empty()) {
            cout << "  Aucun inscrit." << endl;
            return;
        }

        vector<double> notesVec;
        for (const auto* etu : inscrits) {
            double n = etu->getNote(sigle);
            if (n >= 0) notesVec.push_back(n);
        }

        if (notesVec.empty()) return;

        sort(notesVec.begin(), notesVec.end());
        double moy = accumulate(notesVec.begin(), notesVec.end(), 0.0) / notesVec.size();
        double mediane = notesVec[notesVec.size() / 2];

        int nbA = count_if(notesVec.begin(), notesVec.end(), [](double n) { return n >= 90; });
        int nbB = count_if(notesVec.begin(), notesVec.end(), [](double n) { return n >= 80 && n < 90; });
        int nbC = count_if(notesVec.begin(), notesVec.end(), [](double n) { return n >= 70 && n < 80; });
        int nbD = count_if(notesVec.begin(), notesVec.end(), [](double n) { return n >= 60 && n < 70; });
        int nbF = count_if(notesVec.begin(), notesVec.end(), [](double n) { return n < 60; });

        cout << fixed << setprecision(1);
        cout << "  Moyenne  : " << moy << endl;
        cout << "  Médiane  : " << mediane << endl;
        cout << "  Min      : " << notesVec.front() << endl;
        cout << "  Max      : " << notesVec.back() << endl;
        cout << "  Distribution : A=" << nbA << " B=" << nbB
             << " C=" << nbC << " D=" << nbD << " F=" << nbF << endl;
    }

    // Affichage
    void afficher() const {
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
        cout << sigle << " — " << titre << " (" << session << ")" << endl;
        if (prof) cout << "Prof : " << prof->getNomComplet() << endl;
        cout << "Inscrits : " << nbInscrits() << endl;
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

        auto classe = classement();
        int rang = 1;
        for (const auto* etu : classe) {
            double note = etu->getNote(sigle);
            cout << "  " << setw(3) << rang++ << ". "
                 << left << setw(22) << etu->getNomComplet()
                 << right << fixed << setprecision(1) << setw(6) << note
                 << " (" << etu->lettre(sigle) << ")" << endl;
        }

        cout << endl;
        afficherStatistiques();
    }

    // Sauvegarde
    void sauvegarder(const string& chemin) const {
        ofstream f(chemin);
        if (!f) { cerr << "Erreur sauvegarde." << endl; return; }

        f << sigle << endl;
        f << titre << endl;
        f << session << endl;
        f << inscrits.size() << endl;

        for (const auto* etu : inscrits) {
            double note = etu->getNote(sigle);
            f << etu->getId() << "," << etu->getNomComplet()
              << "," << note << endl;
        }

        f.close();
        cout << "Cours sauvegardé dans " << chemin << endl;
    }
};

// ===========================================================================
// main — Démonstration complète
// ===========================================================================
int main() {

    cout << "╔══════════════════════════════════════════════╗" << endl;
    cout << "║  EXERCICE 19 — SYSTÈME DE GESTION DE NOTES  ║" << endl;
    cout << "╚══════════════════════════════════════════════╝" << endl;

    // -----------------------------------------------------------------------
    // Créer le professeur
    // -----------------------------------------------------------------------
    Professeur prof("Jean", "Vaucher", "VAUJ01", "DIRO");

    // -----------------------------------------------------------------------
    // Créer les étudiants
    // -----------------------------------------------------------------------
    vector<Etudiant*> etudiants;
    etudiants.push_back(new Etudiant("Charlie", "Bouchard",  "BOUC2501"));
    etudiants.push_back(new Etudiant("Alice",   "Tremblay",  "TREA2502"));
    etudiants.push_back(new Etudiant("Bob",     "Martin",    "MARB2503"));
    etudiants.push_back(new Etudiant("Claire",  "Dupont",    "DUPC2504"));
    etudiants.push_back(new Etudiant("David",   "Roy",       "ROYD2505"));
    etudiants.push_back(new Etudiant("Eve",     "Gagnon",    "GAGE2506"));
    etudiants.push_back(new Etudiant("Frank",   "Lavoie",    "LAVF2507"));
    etudiants.push_back(new Etudiant("Grace",   "Pelletier", "PELG2508"));

    // -----------------------------------------------------------------------
    // Créer le cours et inscrire les étudiants
    // -----------------------------------------------------------------------
    Cours ift1166("IFT1166", "Programmation OO en C++", "Hiver 2026", &prof);

    for (auto* etu : etudiants) {
        ift1166.inscrire(etu);
    }

    // Attribuer des notes
    ift1166.attribuerNote("BOUC2501", 92.5);
    ift1166.attribuerNote("TREA2502", 85.0);
    ift1166.attribuerNote("MARB2503", 78.3);
    ift1166.attribuerNote("DUPC2504", 91.2);
    ift1166.attribuerNote("ROYD2505", 67.8);
    ift1166.attribuerNote("GAGE2506", 73.5);
    ift1166.attribuerNote("LAVF2507", 55.0);
    ift1166.attribuerNote("PELG2508", 88.9);

    // -----------------------------------------------------------------------
    // Afficher le cours complet
    // -----------------------------------------------------------------------
    cout << endl;
    ift1166.afficher();

    // -----------------------------------------------------------------------
    // Polymorphisme — afficher toutes les personnes
    // -----------------------------------------------------------------------
    cout << "\n=== Polymorphisme ===" << endl;
    vector<Personne*> personnes;
    personnes.push_back(&prof);
    for (auto* etu : etudiants) personnes.push_back(etu);

    for (const Personne* p : personnes) {
        cout << *p << endl;  // utilise operator<<
    }

    // -----------------------------------------------------------------------
    // Recherche et filtrage (STL)
    // -----------------------------------------------------------------------
    cout << "\n=== Étudiants avec A (≥90) ===" << endl;
    for (const auto* etu : etudiants) {
        if (etu->getNote("IFT1166") >= 90) {
            cout << "  ⭐ " << etu->getNomComplet() << " : "
                 << etu->getNote("IFT1166") << endl;
        }
    }

    cout << "\n=== Étudiants en échec (<60) ===" << endl;
    for (const auto* etu : etudiants) {
        if (etu->getNote("IFT1166") < 60) {
            cout << "  ⚠  " << etu->getNomComplet() << " : "
                 << etu->getNote("IFT1166") << endl;
        }
    }

    // -----------------------------------------------------------------------
    // Sauvegarde dans un fichier
    // -----------------------------------------------------------------------
    cout << endl;
    ift1166.sauvegarder("ex19-notes-ift1166.txt");

    // -----------------------------------------------------------------------
    // Fiches individuelles
    // -----------------------------------------------------------------------
    cout << "\n=== Fiche individuelle ===" << endl;
    etudiants[0]->afficher();

    // -----------------------------------------------------------------------
    // Nettoyage mémoire
    // -----------------------------------------------------------------------
    for (auto* etu : etudiants) delete etu;
    etudiants.clear();

    cout << "\n✓ Programme terminé — mémoire libérée." << endl;

    return 0;
}
