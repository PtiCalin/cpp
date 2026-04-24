// demo-fichiers.cpp
// Démonstration : lecture/écriture fichier texte, CSV, gestion d'erreurs
// IFT1166 — ex15
// Compiler : g++ -Wall -std=c++17 demo-fichiers.cpp -o demo-fichiers

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// ─────────────────────────────────────────────
// Section 1 : écriture dans un fichier texte
// ─────────────────────────────────────────────
void ecrireFichier() {
    cout << "=== 1. Écriture fichier texte ===\n";

    ofstream f("notes.txt");
    if (!f) {
        cerr << "Erreur : impossible de créer notes.txt\n";
        return;
    }

    f << "Alice 88.5\n";
    f << "Bob 72.0\n";
    f << "Eve 95.5\n";
    f.close();

    cout << "Fichier notes.txt créé\n\n";
}

// ─────────────────────────────────────────────
// Section 2 : lecture d'un fichier texte
// ─────────────────────────────────────────────
void lireFichier() {
    cout << "=== 2. Lecture fichier texte ===\n";

    ifstream f("notes.txt");
    if (!f.is_open()) {
        cerr << "Erreur : notes.txt introuvable\n";
        return;
    }

    string nom;
    double note;
    int    nb = 0;
    double somme = 0.0;

    while (f >> nom >> note) {
        cout << nom << " : " << note << "\n";
        somme += note;
        nb++;
    }

    if (nb > 0)
        cout << "Moyenne du groupe : " << somme / nb << "\n";

    f.close();
    cout << "\n";
}

// ─────────────────────────────────────────────
// Section 3 : ajout en fin de fichier (append)
// ─────────────────────────────────────────────
void ajouterFichier() {
    cout << "=== 3. Ajout (append) ===\n";

    ofstream f("notes.txt", ios::app);
    f << "Charlie 81.0\n";
    f.close();

    cout << "Charlie ajouté\n\n";
}

// ─────────────────────────────────────────────
// Section 4 : lecture CSV
// ─────────────────────────────────────────────
struct Etudiant {
    string nom;
    double note;
    int    matricule;
};

void creerCSV() {
    ofstream f("etudiants.csv");
    f << "Alice,88.5,11111\n";
    f << "Bob,72.0,22222\n";
    f << "Eve,95.5,33333\n";
}

vector<Etudiant> lireCSV() {
    vector<Etudiant> liste;
    ifstream f("etudiants.csv");
    string ligne;

    while (getline(f, ligne)) {
        if (ligne.empty()) continue;
        stringstream ss(ligne);
        string nom, noteStr, matriculeStr;

        getline(ss, nom,          ',');
        getline(ss, noteStr,      ',');
        getline(ss, matriculeStr, ',');

        Etudiant e;
        e.nom       = nom;
        e.note      = stod(noteStr);
        e.matricule = stoi(matriculeStr);
        liste.push_back(e);
    }
    return liste;
}

void sectionCSV() {
    cout << "=== 4. Lecture CSV ===\n";
    creerCSV();

    vector<Etudiant> etudiants = lireCSV();
    for (const Etudiant& e : etudiants) {
        cout << e.matricule << " | " << e.nom
             << " | " << e.note << "\n";
    }
    cout << "\n";
}

// ─────────────────────────────────────────────
// Section 5 : lecture ligne par ligne (getline)
// ─────────────────────────────────────────────
void sectionGetline() {
    cout << "=== 5. Lecture par lignes ===\n";

    ofstream w("lignes.txt");
    w << "Première ligne\n";
    w << "Deuxième ligne avec espaces\n";
    w << "Troisième ligne\n";
    w.close();

    ifstream r("lignes.txt");
    string ligne;
    int num = 1;

    while (getline(r, ligne)) {
        cout << num++ << ": " << ligne << "\n";
    }
    cout << "\n";
}

int main() {
    ecrireFichier();
    lireFichier();
    ajouterFichier();

    cout << "=== Après ajout ===\n";
    lireFichier();

    sectionCSV();
    sectionGetline();

    return 0;
}
