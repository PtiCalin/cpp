# Théorie 01 — Fondements du C++

> Introduction au langage, structure d'un programme, modèle de compilation · IFT1166

---

## Table des matières

1. [Historique rapide](#1-historique-rapide)
2. [Structure d'un programme C++](#2-structure-dun-programme-c)
3. [Modèle de compilation](#3-modèle-de-compilation)
4. [Types fondamentaux](#4-types-fondamentaux)
5. [Opérateurs](#5-opérateurs)
6. [Entrées / Sorties standards](#6-entrées--sorties-standards)
7. [Espace de noms (`namespace`)](#7-espace-de-noms-namespace)

---

## 1. Historique rapide

| Année | Étape |
|-------|-------|
| 1972 | C (Dennis Ritchie, Bell Labs) |
| 1983 | C++ (Bjarne Stroustrup) — "C with Classes" |
| 1998 | C++98 — première norme ISO |
| 2011 | C++11 — modernisation majeure (lambdas, `auto`, move semantics) |
| 2014/17 | C++14, C++17 — améliorations incrémentales |
| 2020 | C++20 — concepts, ranges, coroutines |

C++ est un langage **multi-paradigme** : procédural, orienté objet, générique.

---

## 2. Structure d'un programme C++

```cpp
// commentaire ligne
/* commentaire bloc */

#include <iostream>   // directive préprocesseur — inclut la bibliothèque
using namespace std;  // rend visible le contenu de std (ok dans .cpp)

int main() {          // point d'entrée obligatoire
    cout << "Bonjour\n";
    return 0;         // 0 = succès
}
```

### Anatomie d'une instruction

```
cout << "Bonjour" << endl;
 │      │                │
 │      │                └── endl : flush + saut de ligne
 │      └── opérateur d'insertion
 └── objet flux de sortie
```

### Règles syntaxiques de base

- Chaque instruction se termine par `;`
- Les blocs sont délimités par `{ }` — **pas** par l'indentation
- C++ est **sensible à la casse** : `Var` ≠ `var` ≠ `VAR`
- Les commentaires n'ont aucun effet sur l'exécution

---

## 3. Modèle de compilation

```
Source (.cpp)
      │
      ▼
  Préprocesseur  ← directives #include, #define, #ifdef
      │
      ▼
   Compilateur   → fichier objet (.o / .obj)
      │
      ▼
    Éditeur de   ← bibliothèques standard
      liens
      │
      ▼
  Exécutable
```

### Commandes de compilation (g++)

```bash
# Compilation + édition de liens en une étape
g++ -Wall -std=c++17 programme.cpp -o programme

# Étapes séparées (multi-fichiers)
g++ -c fichier1.cpp   # → fichier1.o
g++ -c fichier2.cpp   # → fichier2.o
g++ fichier1.o fichier2.o -o programme
```

**Options importantes :**

| Option | Effet |
|--------|-------|
| `-Wall` | Active tous les avertissements courants |
| `-Wextra` | Avertissements supplémentaires |
| `-std=c++17` | Standard C++17 |
| `-g` | Symboles de débogage (pour GDB) |
| `-O2` | Optimisation niveau 2 |

---

## 4. Types fondamentaux

### Types entiers

| Type | Taille typique | Plage |
|------|:--------------:|-------|
| `bool` | 1 octet | `true` / `false` |
| `char` | 1 octet | −128 à 127 (ou 0 à 255) |
| `short` | 2 octets | −32 768 à 32 767 |
| `int` | 4 octets | −2,1 × 10⁹ à 2,1 × 10⁹ |
| `long` | 4 ou 8 octets | dépend de la plateforme |
| `long long` | 8 octets | ±9,2 × 10¹⁸ |

### Types réels

| Type | Taille | Précision |
|------|:------:|-----------|
| `float` | 4 octets | ~7 chiffres significatifs |
| `double` | 8 octets | ~15 chiffres significatifs |
| `long double` | 12–16 octets | ≥ 18 chiffres significatifs |

### Conversions implicites

```cpp
int    i = 3;
double d = i;     // int → double (sans perte)
int    j = 3.9;   // double → int (troncature : j = 3, pas d'arrondi)
```

### `auto` (C++11)

```cpp
auto x = 42;      // int
auto y = 3.14;    // double
auto s = "texte"; // const char*
```

---

## 5. Opérateurs

### Arithmétiques

| Opérateur | Signification |
|-----------|--------------|
| `+`, `-`, `*`, `/` | Opérations de base |
| `%` | Modulo (reste de la division entière) |
| `++`, `--` | Pré/post-incrémentation |

```cpp
cout << 17 % 5;   // 2
int a = 5;
cout << a++;      // affiche 5, puis a devient 6
cout << ++a;      // a devient 7, affiche 7
```

### Relationnels et logiques

| Catégorie | Opérateurs |
|-----------|-----------|
| Comparaison | `==`, `!=`, `<`, `>`, `<=`, `>=` |
| Logiques | `&&` (ET), `\|\|` (OU), `!` (NON) |

### Affectation composée

```cpp
x += 5;   // x = x + 5
x -= 2;   // x = x - 2
x *= 3;   // x = x * 3
x /= 4;   // x = x / 4
x %= 7;   // x = x % 7
```

---

## 6. Entrées / Sorties standards

```cpp
#include <iostream>
using namespace std;

int age;
cout << "Entrez votre âge : ";   // affichage sans saut
cin  >> age;                      // lecture d'un entier

double x, y;
cin >> x >> y;                    // lecture en chaîne

string nom;
getline(cin, nom);                // lire toute une ligne (espaces inclus)

// Formatage
cout << fixed;                    // notation décimale fixe
cout.precision(2);                // 2 décimales
cout << 3.14159;                  // → 3.14

cerr << "Erreur !\n";            // flux d'erreurs standard
```

---

## 7. Espace de noms (`namespace`)

```cpp
// Sans using namespace std :
std::cout << "Bonjour\n";
std::string nom = "Alice";

// Avec using namespace std (ok dans .cpp, jamais dans .h) :
using namespace std;
cout << "Bonjour\n";
string nom = "Alice";

// Importation sélective (bonne pratique en .h) :
using std::cout;
using std::string;
```

**Règle :** ne jamais utiliser `using namespace` dans un fichier d'en-tête (`.h` / `.hpp`) — cela pollue l'espace de noms de tous les fichiers qui l'incluent.

---

## Fichiers de cette section

| Fichier | Contenu |
|---------|---------|
| `README.md` | Ce guide théorique |
| `demo-fondements.cpp` | Programme démontrant types, opérateurs, I/O |

---

*Suite :* [theory/02-variables-controle-flux/](../02-variables-controle-flux/)
