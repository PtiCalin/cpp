// ============================================================================
// SOLUTION — Carnet de contacts persistant
// ============================================================================
// Compiler : g++ -Wall -std=c++17 ex-contacts-solution.cpp -o ex-contacts
// Génère / lit : contacts.csv dans le répertoire courant
// ============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>  // transform
#include <iomanip>

using namespace std;

// ── Structure ────────────────────────────────────────────────────────────────

struct Contact {
    string nom;
    string telephone;
};

// ── Prototypes ────────────────────────────────────────────────────────────────
vector<Contact> chargerContacts   (const string& fichier);
void            sauvegarderContacts(const vector<Contact>& contacts, const string& fichier);
int             rechercherContact  (const vector<Contact>& contacts, const string& nom);
void            afficherTous       (const vector<Contact>& contacts);

// ── main ─────────────────────────────────────────────────────────────────────

int main() {

    const string FICHIER = "contacts.csv";

    // Charge les contacts existants (ou vecteur vide si fichier absent)
    vector<Contact> contacts = chargerContacts(FICHIER);

    int choix = 0;
    do {
        cout << "\n=== Carnet de contacts (" << contacts.size() << ") ===" << endl;
        cout << "[1] Afficher tous\n[2] Ajouter\n"
                "[3] Rechercher\n[4] Supprimer\n[5] Quitter\n";
        cout << "Choix : ";
        cin >> choix;
        cin.ignore();   // consomme le '\n' laissé par cin >>

        switch (choix) {
            case 1:
                afficherTous(contacts);
                break;

            case 2: {
                Contact c;
                cout << "Nom       : "; getline(cin, c.nom);
                cout << "Téléphone : "; getline(cin, c.telephone);
                if (!c.nom.empty()) {
                    contacts.push_back(c);
                    cout << "Contact ajouté." << endl;
                }
                break;
            }

            case 3: {
                string recherche;
                cout << "Nom à chercher : "; getline(cin, recherche);
                int idx = rechercherContact(contacts, recherche);
                if (idx >= 0)
                    cout << "Trouvé : " << contacts[idx].nom
                         << " — " << contacts[idx].telephone << endl;
                else
                    cout << "Aucun contact trouvé pour \"" << recherche << "\"." << endl;
                break;
            }

            case 4: {
                string nom;
                cout << "Nom à supprimer : "; getline(cin, nom);
                int idx = rechercherContact(contacts, nom);
                if (idx >= 0) {
                    cout << "Suppression de " << contacts[idx].nom << "." << endl;
                    // erase() : supprime l'élément à l'index idx
                    contacts.erase(contacts.begin() + idx);
                } else {
                    cout << "Contact introuvable." << endl;
                }
                break;
            }

            case 5:
                sauvegarderContacts(contacts, FICHIER);
                cout << contacts.size() << " contact(s) sauvegardé(s) dans "
                     << FICHIER << "." << endl;
                break;

            default:
                cout << "Choix invalide." << endl;
        }
    } while (choix != 5);

    return 0;
}

// ── Implémentations ──────────────────────────────────────────────────────────

// Charge les contacts depuis un CSV "nom,telephone\n"
// Retourne un vecteur vide si le fichier n'existe pas
vector<Contact> chargerContacts(const string& fichier) {
    vector<Contact> liste;
    ifstream f(fichier);
    if (!f.is_open()) return liste;   // fichier absent → liste vide

    string ligne;
    while (getline(f, ligne)) {
        if (ligne.empty()) continue;
        stringstream ss(ligne);
        Contact c;
        getline(ss, c.nom,       ',');
        getline(ss, c.telephone       );
        liste.push_back(c);
    }
    return liste;
}

// Sauvegarde en CSV (écrase le fichier existant)
void sauvegarderContacts(const vector<Contact>& contacts, const string& fichier) {
    ofstream f(fichier);   // mode par défaut = ios::trunc (écrase)
    if (!f) {
        cerr << "Erreur : impossible d'écrire dans " << fichier << endl;
        return;
    }
    for (const Contact& c : contacts) {
        f << c.nom << "," << c.telephone << "\n";
    }
}

// Retourne l'index du premier contact dont le nom contient 'nom'
// (insensible à la casse). Retourne -1 si non trouvé.
int rechercherContact(const vector<Contact>& contacts, const string& nom) {
    // Conversion en minuscules pour la comparaison
    string rechLower = nom;
    transform(rechLower.begin(), rechLower.end(), rechLower.begin(), ::tolower);

    for (int i = 0; i < static_cast<int>(contacts.size()); i++) {
        string nomLower = contacts[i].nom;
        transform(nomLower.begin(), nomLower.end(), nomLower.begin(), ::tolower);
        // find() retourne string::npos si absent
        if (nomLower.find(rechLower) != string::npos) return i;
    }
    return -1;
}

// Affiche tous les contacts avec mise en page
void afficherTous(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "  (aucun contact)" << endl;
        return;
    }
    cout << left << setw(25) << "Nom" << "Téléphone" << endl;
    cout << string(40, '-') << endl;
    for (const Contact& c : contacts) {
        cout << left << setw(25) << c.nom << c.telephone << endl;
    }
}
