// ============================================================================
// Exercice — Classe Etudiant
// ============================================================================
//
// CONSIGNES :
//   Implémenter la classe Etudiant avec les spécifications suivantes.
//
//   Attributs privés :
//     - string  nom
//     - int     matricule
//     - vector<double> notes
//
//   Constructeurs :
//     - Etudiant(string nom, int matricule)
//     - Etudiant() — constructeur par défaut (nom = "Inconnu", matricule = 0)
//
//   Méthodes publiques :
//     - void   ajouterNote(double note)    — valider 0 ≤ note ≤ 100
//     - double moyenne() const             — 0 si aucune note
//     - double noteMax() const
//     - double noteMin() const
//     - char   lettre() const              — A(≥90) B(≥80) C(≥70) D(≥60) E(<60)
//     - void   afficher() const            — résumé complet
//     - string getNom() const
//     - int    getMatricule() const
//
//   Bonus :
//     - surcharger operator<< pour afficher avec cout << etudiant
//
// CONCEPTS PRATIQUÉS :
//   - class, private, public
//   - Constructeur + liste d'initialisation
//   - vector<double> membre
//   - Méthodes const
//   - Validation dans les setters/méthodes
//   - operator<<  (bonus)
//
// ============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <numeric>   // accumulate
#include <algorithm> // min_element, max_element

using namespace std;

// ── Déclaration de la classe ─────────────────────────────────────────────────

class Etudiant {
private:
    // TODO : déclarer les attributs

public:
    // TODO : constructeur paramétré
    // TODO : constructeur par défaut

    // TODO : ajouterNote()
    // TODO : moyenne() const
    // TODO : noteMax() const
    // TODO : noteMin() const
    // TODO : lettre() const
    // TODO : afficher() const
    // TODO : getNom() const
    // TODO : getMatricule() const
};

// Bonus : TODO operator<<

// ── main ────────────────────────────────────────────────────────────────────

int main() {

    // Test 1 : créer un étudiant, ajouter des notes, afficher
    Etudiant alice("Alice Dupont", 11111);
    // TODO : ajouter des notes : 85, 92, 78, 88, 95
    // TODO : appeler afficher()

    // Test 2 : noter la moyenne, la lettre
    // TODO

    // Test 3 : tenter d'ajouter une note invalide (ex: 105)
    // TODO

    // Test 4 : étudiant sans notes
    Etudiant vide;
    // TODO : appeler afficher()

    return 0;
}
