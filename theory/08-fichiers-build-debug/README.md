# Théorie 08 — Fichiers, Multi-fichiers et Débogage

> Fichiers I/O, compilation séparée, débogage · IFT1166 ex15–ex16

---

## Table des matières

1. [Fichiers texte — lecture et écriture](#1-fichiers-texte--lecture-et-écriture)
2. [Fichiers binaires](#2-fichiers-binaires)
3. [Gestion des erreurs fichier](#3-gestion-des-erreurs-fichier)
4. [Fichiers CSV](#4-fichiers-csv)
5. [Architecture multi-fichiers](#5-architecture-multi-fichiers)
6. [Débogage courant](#6-débogage-courant)
7. [Erreurs fréquentes et solutions](#7-erreurs-fréquentes-et-solutions)

---

## 1. Fichiers texte — lecture et écriture

### En-têtes nécessaires

```cpp
#include <fstream>   // ifstream, ofstream, fstream
#include <string>
#include <sstream>   // stringstream
```

### Écriture dans un fichier

```cpp
#include <fstream>
using namespace std;

ofstream fichier("donnees.txt");   // ouvre en écriture (écrase si existant)

if (!fichier) {
    cerr << "Impossible d'ouvrir le fichier\n";
    return 1;
}

fichier << "Alice" << " " << 85 << "\n";
fichier << "Bob"   << " " << 72 << "\n";
fichier.close();   // bonne pratique même si le destructeur ferme aussi
```

**Mode d'ouverture :**

| Mode | Comportement |
|------|-------------|
| `ios::out` | Écriture (défaut pour `ofstream`) — écrase |
| `ios::app` | Ajout en fin de fichier |
| `ios::in` | Lecture (défaut pour `ifstream`) |
| `ios::binary` | Mode binaire |
| `ios::trunc` | Tronque le fichier existant |

```cpp
// Ajout (ne pas écraser)
ofstream fichier("log.txt", ios::app);
```

### Lecture ligne par ligne

```cpp
#include <fstream>
#include <string>

ifstream fichier("donnees.txt");
string ligne;

while (getline(fichier, ligne)) {
    cout << ligne << "\n";
}
```

### Lecture mot par mot

```cpp
ifstream fichier("nombres.txt");
int val;

while (fichier >> val) {
    cout << val << " ";
}
```

### Lecture mixte (problème fréquent)

```cpp
// Après cin >> n, il reste '\n' dans le buffer → getline() lit une chaîne vide
int n;
cin >> n;
cin.ignore();        // consommer le '\n' résiduel
string ligne;
getline(cin, ligne); // maintenant lit correctement
```

---

## 2. Fichiers binaires

```cpp
struct Etudiant {
    char   nom[30];
    double moyenne;
    int    matricule;
};

// Écriture binaire
ofstream bin("etudiants.bin", ios::binary);
Etudiant e1 = {"Alice", 88.5, 12345};
bin.write(reinterpret_cast<const char*>(&e1), sizeof(e1));
bin.close();

// Lecture binaire
ifstream binIn("etudiants.bin", ios::binary);
Etudiant e2;
binIn.read(reinterpret_cast<char*>(&e2), sizeof(e2));
cout << e2.nom << " " << e2.moyenne << "\n";
```

---

## 3. Gestion des erreurs fichier

```cpp
ifstream fichier("inexistant.txt");

if (!fichier.is_open()) {
    cerr << "Erreur : fichier introuvable\n";
    return 1;
}

if (fichier.fail()) cerr << "Erreur de lecture\n";
if (fichier.eof())  cout << "Fin du fichier atteinte\n";
if (fichier.bad())  cerr << "Erreur système grave\n";

fichier.clear();    // réinitialiser les flags d'erreur
```

---

## 4. Fichiers CSV

```cpp
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

// Lire un CSV : "Alice,88.5,12345"
ifstream fichier("etudiants.csv");
string ligne;

while (getline(fichier, ligne)) {
    stringstream ss(ligne);
    string nom, moyStr, matriculeStr;

    getline(ss, nom,        ',');  // lire jusqu'à la prochaine virgule
    getline(ss, moyStr,     ',');
    getline(ss, matriculeStr, ',');

    double moy       = stod(moyStr);
    int    matricule = stoi(matriculeStr);

    cout << nom << " | " << moy << " | " << matricule << "\n";
}
```

---

## 5. Architecture multi-fichiers

### Structure recommandée

```
projet/
├── main.cpp          ← #include "etudiant.h" + logique principale
├── etudiant.h        ← déclaration de la classe Etudiant
├── etudiant.cpp      ← définition des méthodes
├── utilitaires.h     ← fonctions helpers
└── utilitaires.cpp   ← implémentation des helpers
```

### `etudiant.h`

```cpp
#pragma once
#include <string>

class Etudiant {
private:
    std::string nom;
    double      moyenne;
public:
    Etudiant(const std::string& n, double m);
    std::string getNom()     const;
    double      getMoyenne() const;
    void        afficher()   const;
};
```

### `etudiant.cpp`

```cpp
#include "etudiant.h"
#include <iostream>
using namespace std;

Etudiant::Etudiant(const string& n, double m)
    : nom(n), moyenne(m) {}

string Etudiant::getNom()     const { return nom; }
double Etudiant::getMoyenne() const { return moyenne; }

void Etudiant::afficher() const {
    cout << nom << " : " << moyenne << "\n";
}
```

### `main.cpp`

```cpp
#include <iostream>
#include "etudiant.h"
using namespace std;

int main() {
    Etudiant e("Alice", 88.5);
    e.afficher();
    return 0;
}
```

### Compilation

```bash
# Toutes les sources d'un coup
g++ -Wall -std=c++17 main.cpp etudiant.cpp -o projet

# En deux étapes (recompilation partielle)
g++ -c etudiant.cpp   # → etudiant.o
g++ -c main.cpp       # → main.o
g++ main.o etudiant.o -o projet
```

---

## 6. Débogage courant

### Messages `cerr`

```cpp
cerr << "[DEBUG] valeur de x = " << x << "\n";   // vers stderr
```

### Assertions

```cpp
#include <cassert>

assert(ptr != nullptr);    // arrête le programme si faux (mode debug)
assert(n > 0);
```

### Erreurs de compilation fréquentes

| Message | Cause probable |
|---------|---------------|
| `undefined reference to` | Fichier `.cpp` non inclus dans la compilation |
| `multiple definition of` | Définition dans un `.h` inclus plusieurs fois |
| `expected ';' before '}'` | Point-virgule manquant après `}` de classe |
| `no matching function for call to` | Surcharge introuvable, mauvais type d'argument |
| `cannot convert ... to ...` | Conversion invalide ou implicite non autorisée |

---

## 7. Erreurs fréquentes et solutions

| Erreur | Symptôme | Solution |
|--------|----------|---------|
| Fichier non fermé | Données perdues / incomplètes | `fichier.close()` ou RAII avec objet local |
| `getline` lit une chaîne vide | Après `cin >>` | `cin.ignore()` avant `getline` |
| Double include | Erreur de redéfinition | `#pragma once` ou include guards |
| Définition dans `.h` | `multiple definition` à l'édition de liens | Mettre les définitions dans `.cpp` |
| Oublier `std::` dans `.h` | Pollution de l'espace de noms | Ne pas écrire `using namespace std;` dans `.h` |

---

## Fichiers de cette section

| Fichier | Contenu |
|---------|---------|
| `README.md` | Ce guide théorique |
| `demo-fichiers.cpp` | Lecture, écriture, CSV, gestion d'erreurs |

---

*Voir aussi :* [reference/compilation-debug.md](../../reference/compilation-debug.md) pour les commandes g++ et les drapeaux.
