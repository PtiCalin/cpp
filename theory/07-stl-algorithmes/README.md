# Théorie 07 — STL et Algorithmique

> Chapitres 17–18 · IFT1166

---

## Table des matières

1. [Standard Template Library — présentation](#1-standard-template-library)
2. [Structures séquentielles](#2-structures-séquentielles)
3. [Listes chaînées](#3-listes-chaînées)
4. [Pile (Stack)](#4-pile-stack)
5. [File (Queue)](#5-file-queue)
6. [Structures associatives — `map`](#6-structures-associatives--map)
7. [Récursivité](#7-récursivité)
8. [Techniques de recherche](#8-techniques-de-recherche)
9. [Algorithmes de tri](#9-algorithmes-de-tri)
10. [Complexité algorithmique](#10-complexité-algorithmique)

---

## 1. Standard Template Library

La STL regroupe **structures de données** + **algorithmes** génériques.

### Types de conteneurs

| Catégorie | Conteneurs | Accès |
|-----------|-----------|-------|
| **Séquentiel** | `vector`, `deque`, `list`, `array` | Ordre linéaire |
| **Associatif** | `map`, `set`, `multimap`, `multiset` | Par clé |
| **Adaptateur** | `stack`, `queue`, `priority_queue` | Interface restreinte |

### Tableau vs. Liste — comparaison

| Opération | Tableau (`vector`) | Liste (`list`) |
|-----------|:-----------------:|:--------------:|
| Accès par index | O(1) rapide | O(n) lent |
| Insertion en fin | O(1) amorti | O(1) |
| Insertion au milieu | O(n) décalage | O(1) |
| Suppression au milieu | O(n) décalage | O(1) |
| Occupation mémoire | Compacte | Overhead par nœud |

---

## 2. Structures séquentielles

### `vector<T>` — tableau dynamique redimensionnable

```cpp
#include <vector>
#include <algorithm>

vector<int> v = {3, 1, 4, 1, 5};

v.push_back(9);        // ajouter en fin
v.pop_back();          // supprimer le dernier
cout << v.size();      // nombre d'éléments
cout << v[2];          // accès par index (non vérifié)
cout << v.at(2);       // accès sécurisé (lance exception si OOB)
v.clear();             // vider

// Parcours par range-for (C++11)
for (const int& elem : v) {
    cout << elem << " ";
}

// Parcours avec index
for (int i = 0; i < (int)v.size(); i++) {
    cout << v[i] << " ";
}
```

### `string` — chaîne de caractères

```cpp
#include <string>

string s = "bonjour";
cout << s.length();        // 7
cout << s.size();          // idem
s += " monde";             // concaténation
s.append("!");             // idem
cout << s.find("monde");   // index (retourne string::npos si absent)
cout << s.substr(0, 7);    // "bonjour"
s[0] = 'B';                // modification caractère

// Comparaison
if (s == "Bonjour monde!")  cout << "égaux\n";
if (s < "z")                cout << "avant z\n";
```

---

## 3. Listes chaînées

### Simplement chaînée (implémentation manuelle)

```cpp
class Cellule {
public:
    int      valeur;
    Cellule* suivant;

    Cellule(int v, Cellule* s = nullptr) : valeur(v), suivant(s) {}
};

class Liste {
    Cellule* tete;
public:
    Liste() : tete(nullptr) {}

    ~Liste() {
        while (tete != nullptr) {
            Cellule* tmp = tete;
            tete = tete->suivant;
            delete tmp;
        }
    }

    // Ajouter en tête
    void ajouterTete(int val) {
        tete = new Cellule(val, tete);
    }

    // Afficher
    void afficher() const {
        for (Cellule* c = tete; c != nullptr; c = c->suivant)
            cout << c->valeur << " → ";
        cout << "null\n";
    }

    // Longueur
    int longueur() const {
        int count = 0;
        for (Cellule* c = tete; c != nullptr; c = c->suivant) count++;
        return count;
    }
};
```

### STL `list<T>` (doublement chaînée)

```cpp
#include <list>

list<int> l = {1, 2, 3};
l.push_front(0);     // ajouter en tête
l.push_back(4);      // ajouter en queue
l.pop_front();       // supprimer la tête
l.remove(3);         // supprimer toutes les occurrences de 3
```

---

## 4. Pile (Stack)

Structure **LIFO** — Last In, First Out.

```
push(a) push(b) push(c)   pop()    pop()
───────────────────────   ──────   ──────
   [c]                    [b]      [a]
   [b]     →    [c]   →   [a]  →   []
   [a]          [b]
                [a]
```

### STL `stack<T>`

```cpp
#include <stack>

stack<int> pile;
pile.push(10);
pile.push(20);
pile.push(30);

cout << pile.top();    // 30 (sommet, sans retirer)
pile.pop();            // retire 30
cout << pile.size();   // 2

while (!pile.empty()) {
    cout << pile.top() << " ";
    pile.pop();
}
// Sortie : 20 10
```

**Usages :** appels récursifs, évaluation d'expressions, retour arrière (undo).

---

## 5. File (Queue)

Structure **FIFO** — First In, First Out.

```
enqueue(a) enqueue(b)   dequeue()
──────────────────────   ─────────
  a → b                  b
  (a en tête)            (a sorti)
```

### STL `queue<T>`

```cpp
#include <queue>

queue<string> file;
file.push("Alice");
file.push("Bob");
file.push("Charlie");

cout << file.front();  // "Alice" (prochain à sortir)
cout << file.back();   // "Charlie" (dernier entré)
file.pop();            // retire "Alice"
```

---

## 6. Structures associatives — `map`

Dictionnaire clé → valeur, trié par clé.

```cpp
#include <map>

map<string, int> notes;
notes["Alice"] = 85;
notes["Bob"]   = 92;
notes["Eve"]   = 78;

// Accès
cout << notes["Alice"];   // 85
cout << notes["Zara"];    // 0 (crée l'entrée avec valeur par défaut !)

// Vérifier existence
if (notes.count("Bob") > 0) cout << "Bob existe\n";
if (notes.find("Bob") != notes.end()) cout << "Bob trouvé\n";

// Parcours (ordre alphabétique des clés)
for (const auto& paire : notes) {
    cout << paire.first << " : " << paire.second << "\n";
}

notes.erase("Eve");    // supprimer
cout << notes.size();  // 2
```

---

## 7. Récursivité

Une fonction récursive **s'appelle elle-même** et contient un **cas de base** (point d'arrêt).

### Structure obligatoire

```
1. Cas de base   → arrêt, résultat direct
2. Cas récursif  → réduction du problème + appel récursif
```

### Exemples fondamentaux

**Factorielle :**
```cpp
int factorielle(int n) {
    if (n <= 1) return 1;           // cas de base
    return n * factorielle(n - 1);  // appel récursif
}
// factorielle(5) = 5 × 4 × 3 × 2 × 1 = 120
```

**PGCD (Euclide) :**
```cpp
int pgcd(int a, int b) {
    if (b == 0) return a;       // cas de base
    return pgcd(b, a % b);      // réduction
}
// pgcd(48, 18) → pgcd(18, 12) → pgcd(12, 6) → pgcd(6, 0) → 6
```

**Fibonacci :**
```cpp
int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);   // deux appels récursifs (exponentiel !)
}
```

> Toujours possible de convertir récursif ↔ itératif. La récursivité est élégante mais peut être coûteuse en pile d'appels.

---

## 8. Techniques de recherche

### Recherche linéaire (séquentielle)

```cpp
int rechercheLineaire(const int tab[], int n, int cible) {
    for (int i = 0; i < n; i++) {
        if (tab[i] == cible) return i;
    }
    return -1;   // non trouvé
}
```

| Cas | Complexité |
|-----|:---------:|
| Meilleur | O(1) — premier élément |
| Moyen | O(n/2) |
| Pire | O(n) — absent ou dernier |

### Recherche dichotomique (tableau trié)

```cpp
int dichoto(const int tab[], int n, int cible) {
    int debut = 0, fin = n - 1;
    while (debut <= fin) {
        int milieu = (debut + fin) / 2;
        if (tab[milieu] == cible) return milieu;
        if (tab[milieu] < cible)  debut = milieu + 1;
        else                      fin   = milieu - 1;
    }
    return -1;
}
```

| Cas | Complexité |
|-----|:---------:|
| Meilleur | O(1) |
| Pire | O(log₂ n) |

**Prérequis :** tableau **trié**.

---

## 9. Algorithmes de tri

### Tri par sélection

Principe : trouver le plus petit, le placer en premier, répéter.

```cpp
void triSelection(int tab[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (tab[j] < tab[minIdx]) minIdx = j;
        }
        swap(tab[i], tab[minIdx]);
    }
}
// [8,6,9,3,1] → [1,6,9,3,8] → [1,3,9,6,8] → [1,3,6,9,8] → [1,3,6,8,9]
```

### Tri à bulles

Principe : comparer deux éléments consécutifs et permuter si désordonnés.

```cpp
void triBulles(int tab[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (tab[j] > tab[j+1]) swap(tab[j], tab[j+1]);
        }
    }
}
// [8,6,9,3,1] → [6,8,3,1,9] → [6,3,1,8,9] → ...
```

### Tri par insertion

Principe : insérer chaque élément à sa place dans la partie déjà triée.

```cpp
void triInsertion(int tab[], int n) {
    for (int i = 1; i < n; i++) {
        int cle = tab[i];
        int j   = i - 1;
        while (j >= 0 && tab[j] > cle) {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = cle;
    }
}
// Comme trier un paquet de cartes à la main
```

### Comparaison des tris

| Algorithme | Meilleur | Moyen | Pire | En place ? |
|------------|:--------:|:-----:|:----:|:----------:|
| Sélection | O(n²) | O(n²) | O(n²) | Oui |
| Bulles | O(n) | O(n²) | O(n²) | Oui |
| Insertion | O(n) | O(n²) | O(n²) | Oui |
| `std::sort` | O(n log n) | O(n log n) | O(n log n) | Oui |

---

## 10. Complexité algorithmique

| Notation | Nom | Exemple |
|----------|-----|---------|
| O(1) | Constante | Accès par index dans un tableau |
| O(log n) | Logarithmique | Recherche dichotomique |
| O(n) | Linéaire | Parcours de tableau |
| O(n log n) | Quasi-linéaire | `std::sort` |
| O(n²) | Quadratique | Tri par sélection/bulles |
| O(2ⁿ) | Exponentielle | Fibonacci naïf |

---

## Fichiers de cette section

| Fichier | Contenu |
|---------|---------|
| `README.md` | Ce guide théorique |
| `demo-stl.cpp` | `vector`, `string`, `map`, `stack`, récursivité, tris |

---

*Voir aussi :* [reference/stl-essentials.md](../../reference/stl-essentials.md) pour la référence rapide STL.
