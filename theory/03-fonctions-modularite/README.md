# Théorie 03 — Fonctions et Modularité

> Fonctions, surcharge, paramètres par défaut, en-têtes · IFT1166

---

## Table des matières

1. [Fonctions — anatomie](#1-fonctions--anatomie)
2. [Déclaration vs. définition (prototype)](#2-déclaration-vs-définition-prototype)
3. [Modes de passage de paramètres](#3-modes-de-passage-de-paramètres)
4. [Arguments par défaut](#4-arguments-par-défaut)
5. [Surcharge de fonctions](#5-surcharge-de-fonctions)
6. [Fonctions `inline`](#6-fonctions-inline)
7. [Récursivité (bases)](#7-récursivité-bases)
8. [Portée et durée de vie](#8-portée-et-durée-de-vie)
9. [Fichiers d'en-tête et multi-fichiers](#9-fichiers-den-tête-et-multi-fichiers)
10. [Include guards](#10-include-guards)

---

## 1. Fonctions — anatomie

```
type_retour nom_fonction(type1 param1, type2 param2) {
    // corps
    return valeur;
}
```

```cpp
// Exemple complet
double aire_rectangle(double largeur, double hauteur) {
    return largeur * hauteur;
}

int main() {
    double a = aire_rectangle(5.0, 3.0);  // appel
    cout << "Aire = " << a << "\n";
    return 0;
}
```

**`void` :** type de retour quand la fonction ne retourne rien.

```cpp
void afficher_separateur() {
    cout << "──────────────\n";
}
```

---

## 2. Déclaration vs. définition (prototype)

Sans prototype, une fonction doit être définie **avant** son premier appel.

```cpp
// SANS prototype — ordre obligatoire
double carre(double x) { return x * x; }  // définition en premier

int main() {
    cout << carre(5.0);  // appel après
}
```

```cpp
// AVEC prototype — ordre libre
double carre(double x);   // déclaration (prototype) — dans les .h

int main() {
    cout << carre(5.0);  // appel avant la définition
}

double carre(double x) {  // définition peut être après
    return x * x;
}
```

---

## 3. Modes de passage de paramètres

| Mode | Copie locale ? | Modification de l'original ? | Syntaxe |
|------|:--------------:|:----------------------------:|---------|
| Par valeur | Oui | Non | `f(int x)` |
| Par référence | Non | **Oui** | `f(int& x)` |
| Par référence const | Non | Non | `f(const int& x)` |
| Par pointeur | Non | Oui (via `*`) | `f(int* x)` |

```cpp
void parValeur(int x)        { x = 99; }             // original inchangé
void parRef(int& x)          { x = 99; }             // original modifié
void parConstRef(const int& x) { cout << x; }        // lecture seule

// Recommandation : passer les objets lourds par const reference
void afficher(const string& s) { cout << s; }        // pas de copie
void modifier(string& s)       { s = "modifié"; }    // modifie l'original
```

**Retour par valeur, référence ou pointeur :**

```cpp
// Par valeur — copie retournée (OK pour types simples)
double calculer() { return 42.0; }

// DANGER : retourner une référence vers une variable locale
int& mauvais() {
    int local = 5;
    return local;  // ERREUR : local détruit à la fin de la fonction
}

// OK : retourner une référence vers une variable de durée de vie plus longue
int& accesElement(int tab[], int i) { return tab[i]; }
```

---

## 4. Arguments par défaut

```cpp
// Valeurs par défaut dans la déclaration (prototype) ou la définition
void afficher(int val, bool detaille = false, char sep = '\n');

// Appels valides
afficher(42);                // val=42, detaille=false, sep='\n'
afficher(42, true);          // val=42, detaille=true, sep='\n'
afficher(42, true, ' ');     // val=42, detaille=true, sep=' '
```

**Règle :** les arguments par défaut s'ajoutent **de droite à gauche**. Un paramètre avec valeur par défaut ne peut pas être suivi d'un paramètre sans valeur par défaut.

---

## 5. Surcharge de fonctions

Plusieurs fonctions peuvent avoir le **même nom** si leurs **listes de paramètres diffèrent** (type ou nombre).

```cpp
int    maximum(int a, int b)    { return (a > b) ? a : b; }
double maximum(double a, double b) { return (a > b) ? a : b; }
int    maximum(int a, int b, int c) { return maximum(maximum(a,b), c); }

cout << maximum(3, 7);        // version int
cout << maximum(3.5, 2.1);    // version double
cout << maximum(1, 5, 3);     // version 3 arguments
```

**Le type de retour seul ne suffit pas** à différencier deux surcharges.

---

## 6. Fonctions `inline`

Suggestion au compilateur de substituer l'appel par le corps de la fonction (évite l'overhead d'appel pour les petites fonctions).

```cpp
inline double carre(double x) { return x * x; }

// Automatiquement inline si définie dans la classe :
class Cercle {
    double r;
public:
    double aire() const { return 3.14159 * r * r; }  // inline implicite
};
```

**Avantage :** légèrement plus rapide pour les petites fonctions.
**Inconvénient :** code potentiellement plus volumineux.

---

## 7. Récursivité (bases)

```cpp
// Factorielle récursive
int factorielle(int n) {
    if (n <= 0) return 1;           // cas de base
    return n * factorielle(n - 1);  // appel récursif
}

// Trace de factorielle(4) :
// f(4) → 4 × f(3)
//              → 3 × f(2)
//                   → 2 × f(1)
//                        → 1 × f(0) = 1
//                   = 2
//              = 6
//         = 24
```

Voir section complète dans [theory/07-stl-algorithmes/](../07-stl-algorithmes/).

---

## 8. Portée et durée de vie

| Classe | Portée | Durée de vie |
|--------|--------|-------------|
| **Automatique** (locale) | Bloc `{}` | Jusqu'à la fin du bloc |
| **Statique locale** | Bloc `{}` | Toute l'exécution (1 instance) |
| **Globale** | Fichier | Toute l'exécution |

```cpp
void compteur() {
    static int count = 0;  // initialisé une seule fois, persiste entre appels
    count++;
    cout << "Appel #" << count << "\n";
}

compteur();  // Appel #1
compteur();  // Appel #2
```

---

## 9. Fichiers d'en-tête et multi-fichiers

Structure recommandée pour un projet multi-fichiers :

```
projet/
├── main.cpp          ← point d'entrée
├── geometrie.h       ← déclarations (prototypes, classes)
└── geometrie.cpp     ← définitions (implémentations)
```

**`geometrie.h` :**
```cpp
#pragma once          // include guard moderne

double aire_cercle(double rayon);
double aire_rectangle(double l, double h);
```

**`geometrie.cpp` :**
```cpp
#include "geometrie.h"
#include <cmath>

double aire_cercle(double rayon)       { return M_PI * rayon * rayon; }
double aire_rectangle(double l, double h) { return l * h; }
```

**`main.cpp` :**
```cpp
#include <iostream>
#include "geometrie.h"   // guillemets pour les .h locaux

int main() {
    std::cout << aire_cercle(5.0) << "\n";
}
```

**Compilation :**
```bash
g++ main.cpp geometrie.cpp -o projet
```

---

## 10. Include guards

Évitent l'inclusion multiple du même en-tête.

```cpp
// Méthode classique
#ifndef GEOMETRIE_H
#define GEOMETRIE_H

// ... déclarations ...

#endif  // GEOMETRIE_H
```

```cpp
// Méthode moderne (pragma once — non standard mais universelle)
#pragma once

// ... déclarations ...
```

**Règle :** toujours protéger les fichiers `.h` avec un include guard.

---

## Fichiers de cette section

| Fichier | Contenu |
|---------|---------|
| `README.md` | Ce guide théorique |
| `demo-fonctions.cpp` | Prototypes, surcharge, passage par référence, récursivité |

---

*Précédent :* [theory/02-variables-controle-flux/](../02-variables-controle-flux/) · *Suite :* [theory/04-pointeurs-memoire/](../04-pointeurs-memoire/)
