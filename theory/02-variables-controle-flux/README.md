# Théorie 02 — Variables, Conditions et Boucles

> Structures de contrôle de flux · IFT1166

---

## Table des matières

1. [Variables — déclaration et portée](#1-variables--déclaration-et-portée)
2. [Constantes](#2-constantes)
3. [Structure `if` / `else`](#3-structure-if--else)
4. [Opérateur ternaire](#4-opérateur-ternaire)
5. [Structure `switch`](#5-structure-switch)
6. [Boucle `while`](#6-boucle-while)
7. [Boucle `do...while`](#7-boucle-dowhile)
8. [Boucle `for`](#8-boucle-for)
9. [Range-for (C++11)](#9-range-for-c11)
10. [`break` et `continue`](#10-break-et-continue)
11. [Tableaux de base](#11-tableaux-de-base)

---

## 1. Variables — déclaration et portée

```cpp
int x;              // déclaration (valeur indéfinie)
int y = 10;         // déclaration + initialisation
int z{20};          // initialisation par accolades (C++11, préférable)
auto w = 3.14;      // type déduit automatiquement → double
```

### Portée (scope)

```cpp
int a = 1;          // portée globale — éviter sauf pour constantes

int main() {
    int b = 2;      // portée bloc main
    {
        int c = 3;  // portée bloc interne
        cout << a << b << c;  // OK : a, b, c accessibles
    }
    // cout << c;   // ERREUR : c hors portée
    return 0;
}
```

**Règle :** déclarer les variables au plus près de leur utilisation.

---

## 2. Constantes

```cpp
// const — valeur fixée à la compilation (C traditionnel)
const double PI    = 3.14159;
const int    TAILLE = 100;

// constexpr — expression constante évaluable à la compilation (C++11)
constexpr int MAX = 200;
constexpr double RACINE2 = 1.41421;

// #define — substitution texte par le préprocesseur (éviter en C++ moderne)
#define LIMITE 50   // pas de type, pas de portée
```

**Préférer `const` et `constexpr` à `#define`** : typage, portée, débogage.

---

## 3. Structure `if` / `else`

```cpp
int x = 15;

if (x > 10) {
    cout << "Supérieur à 10\n";
} else if (x > 5) {
    cout << "Entre 6 et 10\n";
} else {
    cout << "5 ou moins\n";
}
```

**Pièges courants :**

```cpp
// ERREUR classique : = au lieu de ==
if (x = 5) { ... }   // affectation, pas comparaison ! Toujours vrai si x≠0

// Protection : "Yoda condition" (moins courant en C++ moderne)
if (5 == x) { ... }  // erreur de compilation si on écrit 5 = x par accident
```

### Court-circuit

```cpp
if (ptr != nullptr && ptr->valeur > 0) {
    // ptr est vérifié en premier → pas de déréférencement nul
}
```

---

## 4. Opérateur ternaire

```cpp
// condition ? valeur_si_vrai : valeur_si_faux
int max = (a > b) ? a : b;
string resultat = (note >= 60) ? "Réussi" : "Échoué";
```

---

## 5. Structure `switch`

```cpp
int choix = 2;

switch (choix) {
    case 1:
        cout << "Option 1\n";
        break;
    case 2:
    case 3:                        // groupement : 2 ou 3 → même bloc
        cout << "Option 2 ou 3\n";
        break;
    default:
        cout << "Option inconnue\n";
        break;
}
```

**Règles :**
- `switch` sur : `int`, `char`, `enum` — **pas** sur `string` ni `double`.
- Sans `break` → **fall-through** (exécution du cas suivant aussi).
- `default` optionnel mais recommandé.

---

## 6. Boucle `while`

```cpp
int i = 0;
while (i < 5) {
    cout << i << " ";
    i++;
}
// Sortie : 0 1 2 3 4
```

**Quand utiliser :** quand le nombre d'itérations n'est pas connu à l'avance.

---

## 7. Boucle `do...while`

```cpp
int n;
do {
    cout << "Entrez un nombre positif : ";
    cin >> n;
} while (n <= 0);
// Exécution garantie au moins une fois
```

**Quand utiliser :** validation de saisie, menu interactif.

---

## 8. Boucle `for`

```cpp
// for (initialisation ; condition ; incrément)
for (int i = 0; i < 10; i++) {
    cout << i << " ";
}

// Comptage décroissant
for (int i = 9; i >= 0; i--) {
    cout << i << " ";
}

// Boucle infinie (sortie par break)
for (;;) {
    // ...
    if (conditionSortie) break;
}
```

---

## 9. Range-for (C++11)

Parcours direct d'une collection (tableau, vector, string...).

```cpp
int tab[] = {10, 20, 30, 40};
for (int x : tab) {
    cout << x << " ";
}

// Par référence pour modification
for (int& x : tab) {
    x *= 2;
}

// Par référence const pour lecture (évite la copie)
vector<string> noms = {"Alice", "Bob", "Eve"};
for (const string& nom : noms) {
    cout << nom << "\n";
}
```

---

## 10. `break` et `continue`

```cpp
// break : quitter la boucle immédiatement
for (int i = 0; i < 10; i++) {
    if (i == 5) break;
    cout << i << " ";
}
// Sortie : 0 1 2 3 4

// continue : passer à l'itération suivante
for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) continue;   // sauter les pairs
    cout << i << " ";
}
// Sortie : 1 3 5 7 9
```

---

## 11. Tableaux de base

```cpp
// Déclaration et initialisation
int tab[5] = {10, 20, 30, 40, 50};
int zéros[100] = {};            // initialise tout à 0
double vals[] = {1.1, 2.2, 3.3}; // taille déduite : 3

// Accès (index 0 à n-1)
cout << tab[0];   // 10 (premier)
cout << tab[4];   // 50 (dernier)
// tab[5]         → undefined behavior (hors limites)

// Parcours
int n = 5;
for (int i = 0; i < n; i++) {
    cout << tab[i] << " ";
}

// Tableau 2D
int matrice[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};
cout << matrice[1][2];   // 7
```

---

## Fichiers de cette section

| Fichier | Contenu |
|---------|---------|
| `README.md` | Ce guide théorique |
| `demo-controle-flux.cpp` | Conditions, boucles, tableaux en action |

---

*Précédent :* [theory/01-fondements-cpp/](../01-fondements-cpp/) · *Suite :* [theory/03-fonctions-modularite/](../03-fonctions-modularite/)
