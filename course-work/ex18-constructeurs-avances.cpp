// ============================================================================
// Exercice 18 — Constructeurs avancés
// Thème : constructeur de copie, opérateur=, destructeur, règle des trois.
// ============================================================================
//
// CONSIGNES :
//   1. Créer une classe Tableau qui gère un tableau dynamique.
//   2. Implémenter le constructeur de copie (deep copy).
//   3. Implémenter l'opérateur d'affectation (operator=).
//   4. Implémenter le destructeur (~Tableau).
//   5. Démontrer le problème de la copie superficielle (shallow copy).
//   6. Implémenter la règle des trois (Rule of Three).
//
// CONCEPTS PRATIQUÉS :
//   - Constructeur par défaut, paramétré, de copie
//   - Destructeur (~)
//   - Opérateur d'affectation (operator=)
//   - Deep copy vs shallow copy
//   - Règle des trois (Rule of Three)
//   - this et auto-affectation
//
// ============================================================================

#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

// ===========================================================================
// Classe Tableau — gestion manuelle de mémoire dynamique
// ===========================================================================
class Tableau {
private:
    int* donnees;
    int taille;
    int capacite;

    void copierDepuis(const Tableau& autre) {
        taille = autre.taille;
        capacite = autre.capacite;
        donnees = new int[capacite];
        for (int i = 0; i < taille; i++) {
            donnees[i] = autre.donnees[i];
        }
    }

public:
    // --- Constructeur par défaut ---
    Tableau() : donnees(nullptr), taille(0), capacite(0) {
        cout << "  [Constructeur par défaut]" << endl;
    }

    // --- Constructeur paramétré ---
    explicit Tableau(int capacite)
        : donnees(new int[capacite]), taille(0), capacite(capacite) {
        cout << "  [Constructeur paramétré, capacité=" << capacite << "]" << endl;
        // Initialiser à zéro
        for (int i = 0; i < capacite; i++) donnees[i] = 0;
    }

    // --- Constructeur de COPIE (DEEP COPY) ---
    Tableau(const Tableau& autre) {
        cout << "  [Constructeur de copie]" << endl;
        copierDepuis(autre);
    }

    // --- Opérateur d'AFFECTATION ---
    Tableau& operator=(const Tableau& autre) {
        cout << "  [Opérateur d'affectation]" << endl;

        // Vérifier l'auto-affectation (t = t)
        if (this == &autre) {
            cout << "    (auto-affectation détectée, rien à faire)" << endl;
            return *this;
        }

        // Libérer l'ancien contenu
        delete[] donnees;

        // Copier le nouveau contenu
        copierDepuis(autre);

        return *this;
    }

    // --- DESTRUCTEUR ---
    ~Tableau() {
        cout << "  [Destructeur, taille=" << taille << "]" << endl;
        delete[] donnees;
        donnees = nullptr;
    }

    // --- Méthodes ---
    void ajouter(int valeur) {
        if (taille >= capacite) {
            // Redimensionner
            int nouvCapacite = (capacite == 0) ? 4 : capacite * 2;
            int* nouveau = new int[nouvCapacite];
            for (int i = 0; i < taille; i++) {
                nouveau[i] = donnees[i];
            }
            delete[] donnees;
            donnees = nouveau;
            capacite = nouvCapacite;
        }
        donnees[taille++] = valeur;
    }

    int obtenir(int index) const {
        if (index < 0 || index >= taille) {
            throw out_of_range("Indice hors limites");
        }
        return donnees[index];
    }

    void definir(int index, int valeur) {
        if (index < 0 || index >= taille) {
            throw out_of_range("Indice hors limites");
        }
        donnees[index] = valeur;
    }

    int getTaille() const { return taille; }
    int getCapacite() const { return capacite; }

    void afficher(const string& label = "") const {
        if (!label.empty()) cout << label << " ";
        cout << "[ ";
        for (int i = 0; i < taille; i++) {
            cout << donnees[i];
            if (i < taille - 1) cout << ", ";
        }
        cout << " ] (taille=" << taille << ", capacité=" << capacite << ")" << endl;
    }
};

// ===========================================================================
// main
// ===========================================================================
int main() {

    // -----------------------------------------------------------------------
    // PARTIE 1 : Constructeurs
    // -----------------------------------------------------------------------
    cout << "=== Partie 1 : Constructeurs ===" << endl;

    Tableau t1(5);
    t1.ajouter(10);
    t1.ajouter(20);
    t1.ajouter(30);
    t1.afficher("t1 :");

    // -----------------------------------------------------------------------
    // PARTIE 2 : Constructeur de copie
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 2 : Constructeur de copie ===" << endl;

    Tableau t2(t1);  // appelle le constructeur de copie
    t2.afficher("t2 (copie de t1) :");

    // Modifier t2 ne doit PAS modifier t1 (deep copy)
    t2.definir(0, 999);
    t1.afficher("t1 après modif t2 :");
    t2.afficher("t2 après modif    :");
    cout << "→ t1 n'a PAS changé (deep copy correcte)" << endl;

    // -----------------------------------------------------------------------
    // PARTIE 3 : Opérateur d'affectation
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 3 : Opérateur d'affectation ===" << endl;

    Tableau t3(3);
    t3.ajouter(100);
    t3.ajouter(200);
    t3.afficher("t3 avant affectation :");

    t3 = t1;  // appelle operator=
    t3.afficher("t3 après t3 = t1     :");
    t1.afficher("t1 inchangé          :");

    // Auto-affectation
    cout << "\nAuto-affectation :" << endl;
    t3 = t3;
    t3.afficher("t3 après t3 = t3     :");

    // -----------------------------------------------------------------------
    // PARTIE 4 : Deep Copy vs Shallow Copy
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 4 : Deep vs Shallow Copy ===" << endl;
    cout << "PROBLÈME de la copie superficielle (shallow copy) :" << endl;
    cout << "  Si on ne définit pas de constructeur de copie," << endl;
    cout << "  le compilateur copie les POINTEURS (pas les données)." << endl;
    cout << "  → Les deux objets pointent vers la MÊME mémoire." << endl;
    cout << "  → Modifier l'un modifie l'autre." << endl;
    cout << "  → Le destructeur libère la même mémoire DEUX FOIS → crash !" << endl;
    cout << endl;
    cout << "SOLUTION : Deep copy (copie profonde)" << endl;
    cout << "  → Allouer un NOUVEAU bloc de mémoire." << endl;
    cout << "  → Copier les VALEURS une par une." << endl;
    cout << "  → Chaque objet possède sa propre mémoire." << endl;

    // -----------------------------------------------------------------------
    // PARTIE 5 : Redimensionnement automatique
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 5 : Redimensionnement ===" << endl;
    Tableau t4;
    for (int i = 1; i <= 10; i++) {
        t4.ajouter(i * 10);
        if (i <= 5 || i == 10) {
            t4.afficher("  ");
        }
    }

    // -----------------------------------------------------------------------
    // PARTIE 6 : Règle des Trois
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 6 : Règle des Trois ===" << endl;
    cout << "Si une classe gère des ressources (mémoire dynamique," << endl;
    cout << "fichiers, connexions), elle DOIT définir les trois :" << endl;
    cout << "  1. Constructeur de copie      → Tableau(const Tableau&)" << endl;
    cout << "  2. Opérateur d'affectation     → operator=(const Tableau&)" << endl;
    cout << "  3. Destructeur                 → ~Tableau()" << endl;
    cout << endl;
    cout << "En C++11, on ajoute aussi (Règle des Cinq) :" << endl;
    cout << "  4. Constructeur de déplacement → Tableau(Tableau&&)" << endl;
    cout << "  5. Opérateur de déplacement    → operator=(Tableau&&)" << endl;

    // Les destructeurs seront appelés automatiquement ici
    cout << "\n--- Fin du programme (destructeurs) ---" << endl;

    return 0;
}
