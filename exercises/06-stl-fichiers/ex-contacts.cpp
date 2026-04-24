// ============================================================================
// Exercice — Carnet de contacts persistant
// ============================================================================
//
// CONSIGNES :
//   Implémenter un carnet de contacts qui survit entre les exécutions.
//
//   1. Définir une struct Contact { string nom; string telephone; }.
//   2. Écrire chargerContacts(fichier) → vector<Contact>
//        Lire un fichier CSV : "Nom,Téléphone" par ligne.
//        Retourner un vecteur vide si le fichier n'existe pas encore.
//   3. Écrire sauvegarderContacts(contacts, fichier) → void
//        Écrire chaque contact en CSV (une ligne par contact).
//   4. Écrire rechercherContact(contacts, nom) → int
//        Retourner l'index si trouvé, -1 sinon (recherche insensible à la casse).
//   5. Dans main(), boucle menu :
//        [1] Afficher tous les contacts
//        [2] Ajouter un contact
//        [3] Rechercher par nom
//        [4] Supprimer un contact
//        [5] Quitter (et sauvegarder)
//
// CONCEPTS PRATIQUÉS :
//   - struct
//   - vector<Contact>
//   - ifstream / ofstream
//   - getline, stringstream pour parser le CSV
//   - Boucle menu (switch ou if/else)
//   - Conversion en minuscules (tolower) pour la recherche
//
// FICHIER UTILISÉ : contacts.csv
//
// ============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>  // transform, tolower
#include <iomanip>

using namespace std;

// ── Structure ────────────────────────────────────────────────────────────────

struct Contact {
    string nom;
    string telephone;
};

// ── Prototypes ────────────────────────────────────────────────────────────────

// TODO : vector<Contact> chargerContacts(const string& fichier)
// TODO : void sauvegarderContacts(const vector<Contact>& contacts, const string& fichier)
// TODO : int  rechercherContact(const vector<Contact>& contacts, const string& nom)
// TODO : void afficherTous(const vector<Contact>& contacts)

// ── main ─────────────────────────────────────────────────────────────────────

int main() {

    const string FICHIER = "contacts.csv";

    // TODO 1 : charger les contacts depuis le fichier

    int choix = 0;
    do {
        cout << "\n=== Carnet de contacts ===" << endl;
        cout << "[1] Afficher tous\n[2] Ajouter\n[3] Rechercher\n[4] Supprimer\n[5] Quitter" << endl;
        cout << "Choix : ";
        cin >> choix;
        cin.ignore();

        switch (choix) {
            case 1:
                // TODO : afficherTous()
                break;
            case 2:
                // TODO : lire nom et téléphone, ajouter au vecteur
                break;
            case 3:
                // TODO : lire nom, appeler rechercherContact, afficher résultat
                break;
            case 4:
                // TODO : lire nom, chercher, supprimer avec erase()
                break;
            case 5:
                // TODO : sauvegarderContacts() puis confirmer
                break;
            default:
                cout << "Choix invalide." << endl;
        }
    } while (choix != 5);

    return 0;
}

// ── Implémentations ───────────────────────────────────────────────────────────

// TODO : implémenter chargerContacts
//        Conseil : getline(ss, nom, ',') puis getline(ss, tel)

// TODO : implémenter sauvegarderContacts

// TODO : implémenter rechercherContact
//        Conseil : convertir nom et contacts[i].nom en minuscules pour comparer

// TODO : implémenter afficherTous
