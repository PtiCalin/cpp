// ============================================================================
// Exercice 15 — Lecture et écriture de fichiers
// Thème : ifstream, ofstream, fstream, getline, fichiers texte et CSV.
// ============================================================================
//
// CONSIGNES :
//   1. Écrire du texte dans un fichier (ofstream).
//   2. Lire un fichier ligne par ligne (ifstream + getline).
//   3. Lire et parser un fichier CSV.
//   4. Ajouter du contenu à un fichier existant (app mode).
//   5. Lire/écrire des données structurées (sérialisation texte).
//   6. Challenge : système de carnet d'adresses persistant.
//
// CONCEPTS PRATIQUÉS :
//   - ofstream (écriture), ifstream (lecture), fstream (les deux)
//   - Modes : ios::out, ios::in, ios::app, ios::trunc
//   - getline, >> (extraction)
//   - Vérification d'erreurs (is_open, fail, eof)
//   - Sérialisation / désérialisation texte
//   - Manipulation de CSV avec stringstream
//
// ============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Structure pour les contacts
struct Contact {
    string nom;
    string telephone;
    string courriel;

    void afficher() const {
        cout << "  " << left << setw(20) << nom
             << setw(15) << telephone << courriel << endl;
    }
};

// ---- Prototypes -----------------------------------------------------------
void ecrireFichierTexte(const string& chemin);
void lireFichierTexte(const string& chemin);
void ecrireCSV(const string& chemin);
void lireCSV(const string& chemin);
void ajouterAFichier(const string& chemin, const string& ligne);
void sauvegarderContacts(const vector<Contact>& contacts, const string& chemin);
vector<Contact> chargerContacts(const string& chemin);

// ---- main -----------------------------------------------------------------
int main() {

    // -----------------------------------------------------------------------
    // PARTIE 1 : Écrire un fichier texte
    // -----------------------------------------------------------------------
    cout << "=== Partie 1 : Écriture ===" << endl;
    ecrireFichierTexte("ex15-sortie.txt");
    cout << "Fichier 'ex15-sortie.txt' créé." << endl;

    // -----------------------------------------------------------------------
    // PARTIE 2 : Lire un fichier texte
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 2 : Lecture ===" << endl;
    lireFichierTexte("ex15-sortie.txt");

    // -----------------------------------------------------------------------
    // PARTIE 3 : CSV
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 3 : CSV ===" << endl;
    ecrireCSV("ex15-notes.csv");
    cout << "Fichier 'ex15-notes.csv' créé." << endl;
    lireCSV("ex15-notes.csv");

    // -----------------------------------------------------------------------
    // PARTIE 4 : Mode ajout (append)
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 4 : Mode ajout ===" << endl;
    ajouterAFichier("ex15-sortie.txt", "--- Ligne ajoutée en mode append ---");
    ajouterAFichier("ex15-sortie.txt", "Encore une ligne !");
    cout << "Contenu après ajout :" << endl;
    lireFichierTexte("ex15-sortie.txt");

    // -----------------------------------------------------------------------
    // PARTIE 5-6 : Carnet d'adresses persistant
    // -----------------------------------------------------------------------
    cout << "\n=== Parties 5-6 : Carnet d'adresses ===" << endl;

    vector<Contact> contacts = {
        {"Charlie Bouchard", "514-555-0001", "charlie@example.com"},
        {"Alice Tremblay",   "514-555-0002", "alice@example.com"},
        {"Bob Martin",       "438-555-0003", "bob@example.com"},
        {"Claire Dupont",    "450-555-0004", "claire@example.com"},
        {"David Roy",        "514-555-0005", "david@example.com"}
    };

    // Sauvegarder
    sauvegarderContacts(contacts, "ex15-contacts.dat");
    cout << "Contacts sauvegardés dans 'ex15-contacts.dat'." << endl;

    // Charger
    vector<Contact> charges = chargerContacts("ex15-contacts.dat");
    cout << "\nContacts chargés (" << charges.size() << ") :" << endl;
    cout << "  " << left << setw(20) << "Nom" << setw(15) << "Téléphone"
         << "Courriel" << endl;
    cout << "  " << string(55, '-') << endl;
    for (const Contact& c : charges) {
        c.afficher();
    }

    // Ajouter un contact et re-sauvegarder
    charges.push_back({"Eve Gagnon", "819-555-0006", "eve@example.com"});
    sauvegarderContacts(charges, "ex15-contacts.dat");
    cout << "\nContact ajouté et re-sauvegardé (" << charges.size() << " contacts)." << endl;

    return 0;
}

// ---- Implémentations ------------------------------------------------------

void ecrireFichierTexte(const string& chemin) {
    ofstream fichier(chemin);  // ou ofstream fichier(chemin, ios::out);

    if (!fichier.is_open()) {
        cerr << "Erreur : impossible de créer " << chemin << endl;
        return;
    }

    fichier << "=== Exercice 15 — Fichiers ===" << endl;
    fichier << "Ligne 1 : Bonjour le monde !" << endl;
    fichier << "Ligne 2 : Ceci est un test d'écriture." << endl;
    fichier << "Ligne 3 : Nombres → " << 42 << " et " << 3.14 << endl;

    for (int i = 1; i <= 5; i++) {
        fichier << "Compteur : " << i << endl;
    }

    fichier.close();  // facultatif (le destructeur le fait)
}

void lireFichierTexte(const string& chemin) {
    ifstream fichier(chemin);

    if (!fichier.is_open()) {
        cerr << "Erreur : impossible d'ouvrir " << chemin << endl;
        return;
    }

    string ligne;
    int numLigne = 1;
    while (getline(fichier, ligne)) {
        cout << "  " << setw(3) << numLigne++ << " | " << ligne << endl;
    }

    fichier.close();
}

void ecrireCSV(const string& chemin) {
    ofstream fichier(chemin);
    if (!fichier) return;

    // En-tête
    fichier << "Nom,Matricule,Note1,Note2,Note3" << endl;

    // Données
    fichier << "Alice Tremblay,20251001,85,92,78" << endl;
    fichier << "Bob Martin,20251002,72,68,80" << endl;
    fichier << "Claire Dupont,20251003,95,88,91" << endl;
    fichier << "David Roy,20251004,60,55,63" << endl;

    fichier.close();
}

void lireCSV(const string& chemin) {
    ifstream fichier(chemin);
    if (!fichier) {
        cerr << "Erreur d'ouverture." << endl;
        return;
    }

    string ligne;

    // Lire l'en-tête
    getline(fichier, ligne);
    cout << "  En-tête : " << ligne << endl;
    cout << "  " << string(50, '-') << endl;

    // Lire les données
    while (getline(fichier, ligne)) {
        istringstream iss(ligne);
        string nom, matricule;
        double n1, n2, n3;
        char virgule;

        // Parser : "Nom,Matricule,N1,N2,N3"
        getline(iss, nom, ',');
        getline(iss, matricule, ',');
        iss >> n1 >> virgule >> n2 >> virgule >> n3;

        double moyenne = (n1 + n2 + n3) / 3.0;

        cout << "  " << left << setw(18) << nom
             << setw(12) << matricule
             << "Notes: " << n1 << ", " << n2 << ", " << n3
             << "  Moy: " << fixed << setprecision(1) << moyenne << endl;
    }

    fichier.close();
}

void ajouterAFichier(const string& chemin, const string& ligne) {
    ofstream fichier(chemin, ios::app);  // mode APPEND
    if (!fichier) {
        cerr << "Erreur d'ouverture." << endl;
        return;
    }
    fichier << ligne << endl;
    fichier.close();
}

void sauvegarderContacts(const vector<Contact>& contacts, const string& chemin) {
    ofstream fichier(chemin);
    if (!fichier) {
        cerr << "Erreur de sauvegarde." << endl;
        return;
    }

    // Première ligne : nombre de contacts
    fichier << contacts.size() << endl;

    for (const Contact& c : contacts) {
        // Un champ par ligne (évite les problèmes de délimiteurs)
        fichier << c.nom << endl;
        fichier << c.telephone << endl;
        fichier << c.courriel << endl;
    }

    fichier.close();
}

vector<Contact> chargerContacts(const string& chemin) {
    vector<Contact> contacts;
    ifstream fichier(chemin);

    if (!fichier) {
        cerr << "Erreur de chargement." << endl;
        return contacts;
    }

    int nb;
    fichier >> nb;
    fichier.ignore();  // ignorer le \n après le nombre

    for (int i = 0; i < nb; i++) {
        Contact c;
        getline(fichier, c.nom);
        getline(fichier, c.telephone);
        getline(fichier, c.courriel);
        contacts.push_back(c);
    }

    fichier.close();
    return contacts;
}
