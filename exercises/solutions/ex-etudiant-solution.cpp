// ============================================================================
// SOLUTION — Classe Etudiant
// ============================================================================
// Compiler : g++ -Wall -std=c++17 ex-etudiant-solution.cpp -o ex-etudiant
// ============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <numeric>    // accumulate
#include <algorithm>  // min_element, max_element

using namespace std;

// ── Déclaration de la classe ──────────────────────────────────────────────────

class Etudiant {
private:
    // Membres privés : seule la classe peut les modifier directement
    string         nom;
    int            matricule;
    vector<double> notes;

public:
    // ── Constructeurs ─────────────────────────────────────────────────────
    // Liste d'initialisation : plus efficace qu'une affectation dans le corps
    Etudiant(const string& nom, int matricule)
        : nom(nom), matricule(matricule) {}

    // Constructeur par défaut : valeurs neutres
    Etudiant() : nom("Inconnu"), matricule(0) {}

    // ── Mutateurs ─────────────────────────────────────────────────────────
    void ajouterNote(double note) {
        // Validation à la frontière du système
        if (note < 0.0 || note > 100.0) {
            cerr << "  ⚠ Note invalide (" << note << ") ignorée." << endl;
            return;
        }
        notes.push_back(note);
    }

    // ── Accesseurs const ──────────────────────────────────────────────────
    // const après la signature : garantit que la méthode ne modifie pas l'objet
    string getNom()       const { return nom; }
    int    getMatricule() const { return matricule; }

    double moyenne() const {
        if (notes.empty()) return 0.0;
        // accumulate : somme tous les éléments (init = 0.0)
        double somme = accumulate(notes.begin(), notes.end(), 0.0);
        return somme / static_cast<int>(notes.size());
    }

    double noteMax() const {
        if (notes.empty()) return 0.0;
        return *max_element(notes.begin(), notes.end());
    }

    double noteMin() const {
        if (notes.empty()) return 0.0;
        return *min_element(notes.begin(), notes.end());
    }

    // Lettre selon le barème nord-américain
    char lettre() const {
        double moy = moyenne();
        if (moy >= 90) return 'A';
        if (moy >= 80) return 'B';
        if (moy >= 70) return 'C';
        if (moy >= 60) return 'D';
        return 'E';
    }

    void afficher() const {
        cout << "Étudiant : " << nom
             << " (#" << matricule << ")" << endl;
        if (notes.empty()) {
            cout << "  Aucune note enregistrée." << endl;
            return;
        }
        cout << fixed << setprecision(1);
        cout << "  Notes   : ";
        for (size_t i = 0; i < notes.size(); i++) {
            cout << notes[i];
            if (i < notes.size() - 1) cout << ", ";
        }
        cout << "\n  Moyenne : " << moyenne()
             << "  (" << lettre() << ")" << endl;
        cout << "  Min : " << noteMin()
             << "  Max : " << noteMax() << endl;
    }
};

// ── Surcharge de operator<< (bonus) ──────────────────────────────────────────
// Ami ou libre ? Ici libre : accède aux getters publics seulement
ostream& operator<<(ostream& os, const Etudiant& e) {
    os << "[" << e.getMatricule() << "] " << e.getNom()
       << " — moy: " << fixed << setprecision(1) << e.moyenne()
       << " (" << e.lettre() << ")";
    return os;
}

// ── main ─────────────────────────────────────────────────────────────────────

int main() {

    // ── Test 1 : étudiant avec des notes ─────────────────────────────────
    cout << "=== Test 1 : Alice ===" << endl;
    Etudiant alice("Alice Dupont", 11111);
    for (double n : {85.0, 92.0, 78.0, 88.0, 95.0})
        alice.ajouterNote(n);
    alice.afficher();

    // ── Test 2 : operator<< ───────────────────────────────────────────────
    cout << "\n=== Test 2 : operator<< ===" << endl;
    cout << alice << endl;

    // ── Test 3 : note invalide ────────────────────────────────────────────
    cout << "\n=== Test 3 : note invalide ===" << endl;
    alice.ajouterNote(105.0);   // doit afficher un avertissement
    alice.ajouterNote(-5.0);    // idem

    // ── Test 4 : étudiant sans notes ─────────────────────────────────────
    cout << "\n=== Test 4 : étudiant sans notes ===" << endl;
    Etudiant vide;
    vide.afficher();

    return 0;
}
