# Théorie 05 — Programmation orientée objet (Classes)

> Chapitres 11–14 · IFT1166

---

## Table des matières

1. [Concepts fondamentaux de la P.O.O.](#1-concepts-fondamentaux-de-la-poo)
2. [Définition d'une classe](#2-définition-dune-classe)
3. [Constructeurs](#3-constructeurs)
4. [Destructeur](#4-destructeur)
5. [Membres statiques](#5-membres-statiques)
6. [Fonctions membres — propriétés](#6-fonctions-membres--propriétés)
7. [Le pointeur `this`](#7-le-pointeur-this)
8. [Objets et méthodes `const`](#8-objets-et-méthodes-const)
9. [Durée de vie et outils par défaut](#9-durée-de-vie-et-outils-par-défaut)
10. [Constructeur de recopie (copie profonde vs. superficielle)](#10-constructeur-de-recopie)
11. [Opérateur d'affectation](#11-opérateur-daffectation)
12. [Composition (objet contenant un objet)](#12-composition)

---

## 1. Concepts fondamentaux de la P.O.O.

| Concept | Définition |
|---------|-----------|
| **Objet** | Entité avec des données (état) et des méthodes (comportement) |
| **Encapsulation** | Cacher les données et n'exposer qu'une interface publique |
| **Message** | Seul moyen de communiquer avec un objet (appel de méthode) |
| **Classe** | Modèle (moule) décrivant contenu et comportement |
| **Instance** | Objet particulier créé à partir d'une classe |
| **Héritage** | Construire une classe à partir d'une autre (voir section 06) |
| **Polymorphisme** | Même message → comportements différents selon l'objet |

### Critères de qualité (Bertrand Meyer)

| Critère | Signification |
|---------|--------------|
| Correct | Résultats conformes aux spécifications |
| Robuste | Fonctionne même hors conditions normales |
| Extensible | Facile à modifier si les besoins changent |
| Réutilisable | Utilisable dans d'autres projets |
| Efficace | Bonne utilisation des ressources |

---

## 2. Définition d'une classe

```cpp
class Compte {
private:                  // membres privés (par défaut dans class)
    char   nom[20];
    double actif;
    int    maxRetraits;

public:                   // interface publique
    Compte(const char* n, double montant, int max = 10);
    ~Compte();
    void   deposer(double montant);
    bool   retirer(double montant);
    double getActif() const;
    void   afficher() const;
};
```

**`class` vs. `struct` :**
| | `class` | `struct` |
|---|---|---|
| Accès par défaut | `private` | `public` |
| Usage idiomatique | Données + comportement | Données agrégées simples |

**Affectation entre objets :**
```cpp
Compte CA("Alice", 500.0);
Compte CB = CA;   // OK même si actif est private (affectation membre à membre)
CB.actif = 100;   // ERREUR : actif est private
```

---

## 3. Constructeurs

### Constructeur ordinaire

```cpp
Compte::Compte(const char* n, double montant, int max) {
    strncpy(nom, n, 19);
    nom[19] = '\0';
    actif       = montant;
    maxRetraits = max;
}

Compte c1("Bob", 200.0);          // avec arguments
Compte c2("Eve", 150.0, 5);       // avec argument par défaut remplacé
```

### Constructeur par défaut

```cpp
Compte c3;   // Utilise le constructeur par défaut
```

- Fourni **implicitement** si aucun constructeur n'est déclaré.
- **Masqué** dès qu'un constructeur explicite existe.
- Doit être déclaré explicitement si on en a besoin après avoir défini d'autres constructeurs.

### Surdéfinition (surcharge)

```cpp
class Compte {
public:
    Compte();                              // par défaut
    Compte(const char* n, double montant); // avec nom et montant
    Compte(double montant);                // avec montant seulement
};
```

### Liste d'initialisation (préférable)

```cpp
Compte::Compte(const char* n, double montant)
    : actif(montant), maxRetraits(10) {   // initialise avant le corps
    strncpy(nom, n, 19);
    nom[19] = '\0';
}
```

> La liste d'initialisation est **obligatoire** pour les membres `const`, les références, et les objets membres sans constructeur par défaut.

---

## 4. Destructeur

```cpp
class Tableau {
    double* tab;
    int     taille;
public:
    Tableau(int n);
    ~Tableau();           // un seul destructeur, pas de paramètre
};

Tableau::Tableau(int n) : taille(n) {
    tab = new double[n];
}

Tableau::~Tableau() {
    delete[] tab;         // libère la mémoire allouée par le constructeur
}
```

**Règles :**
- Un seul par classe (ne peut pas être surchargé).
- Appelé automatiquement à la fin de portée ou lors d'un `delete`.
- Ne retourne rien, pas de paramètre.
- Si aucun destructeur défini → destructeur vide fourni implicitement.

---

## 5. Membres statiques

```cpp
class Compte {
private:
    static int nbComptes;    // partagé par TOUS les objets
    double actif;
public:
    Compte(double a) : actif(a) { nbComptes++; }
    ~Compte()                  { nbComptes--; }
    static int getNbComptes()  { return nbComptes; }  // méthode statique
};

// Initialisation hors de la classe (obligatoire pour les champs statiques)
int Compte::nbComptes = 0;
```

**Accès :**
```cpp
Compte c1(100.0), c2(200.0);
cout << Compte::getNbComptes();  // 2 (via la classe)
cout << c1.getNbComptes();       // 2 (via un objet — équivalent)
```

**Méthode statique :** accès uniquement aux membres `static` (pas de `this`).

---

## 6. Fonctions membres — propriétés

| Propriété | Description |
|-----------|-------------|
| Surdéfinition | Plusieurs versions avec signatures différentes |
| Arguments par défaut | `void affiche(bool details = false)` |
| `public` / `private` | Contrôle l'accès de l'extérieur |
| `inline` | Corps dans la classe = automatiquement inline |

**Protection au niveau de la classe :**
```cpp
class Point {
    double x, y;
public:
    bool egal(const Point& p) const {
        return (x == p.x) && (y == p.y);  // p.x accessible — même classe
    }
};
```

**Modes de passage d'objets :**

| Mode | Copie locale ? | Déclaration | Appel |
|------|:--------------:|-------------|-------|
| Valeur | Oui | `bool egal(Point p)` | `a.egal(b)` |
| Pointeur | Non | `bool egal(const Point* p)` | `a.egal(&b)` |
| Référence | Non | `bool egal(const Point& p)` | `a.egal(b)` |

---

## 7. Le pointeur `this`

`this` est un pointeur implicite vers **l'objet courant** (receveur du message).

```cpp
class Compteur {
    int valeur;
public:
    Compteur& incrementer() {
        valeur++;
        return *this;    // retourne l'objet courant par référence
    }
};

Compteur c;
c.incrementer().incrementer().incrementer();  // appels en cascade
```

**Usages courants :**
- Appels en cascade (méthodes chaînées).
- Éviter l'auto-affectation dans `operator=`.
- Surcharge d'opérateurs qui doivent retourner l'objet modifié.

---

## 8. Objets et méthodes `const`

```cpp
class Point {
    double x, y;
public:
    double getX() const { return x; }    // const : n'modifie pas l'objet
    void   setX(double v) { x = v; }     // non-const : modifie l'objet
};

const Point p(3.0, 4.0);
p.getX();    // OK — méthode const
p.setX(5.0); // ERREUR — méthode non-const sur objet const
```

**Règle :** toute méthode qui ne modifie pas l'état de l'objet **devrait** être `const`.

---

## 9. Durée de vie et outils par défaut

C++ fournit automatiquement (si non définis) :

| Outil | Comportement par défaut |
|-------|------------------------|
| Constructeur par défaut | Corps vide (pas d'initialisation) |
| Destructeur | Corps vide |
| Constructeur de recopie | Copie bit à bit (superficielle) |
| Opérateur `=` | Affectation membre par membre (superficielle) |

> Dès que l'un de ces outils est déclaré explicitement, les autres **ne sont plus fournis automatiquement** (règle des Trois).

---

## 10. Constructeur de recopie

### Quand est-il appelé ?

1. `Compte B(A);`  — initialisation directe
2. `Compte B = A;` — initialisation par copie (**pas** une affectation)
3. Passage par valeur à une fonction.
4. Retour d'un objet par valeur.

### Copie superficielle vs. profonde

```cpp
// DANGER : deux objets partagent le même pointeur
class Tableau {
    int* tab;
    int  n;
public:
    Tableau(int taille) : n(taille) { tab = new int[n]; }
    // Copie superficielle par défaut → double delete → plantage !
};

// SOLUTION : copie profonde
Tableau::Tableau(const Tableau& T) : n(T.n) {
    tab = new int[n];
    for (int i = 0; i < n; i++) tab[i] = T.tab[i];
}
```

---

## 11. Opérateur d'affectation

```cpp
Tableau& Tableau::operator=(const Tableau& T) {
    if (this != &T) {           // 1. Éviter l'auto-affectation
        delete[] tab;           // 2. Libérer l'ancienne mémoire
        n   = T.n;              // 3. Copier la taille
        tab = new int[n];       // 4. Réallouer
        for (int i = 0; i < n; i++) tab[i] = T.tab[i];  // 5. Copier
    }
    return *this;               // 6. Retourner l'objet courant
}
```

**Différence recopie vs. affectation :**
```cpp
Tableau A(5);
Tableau B(A);    // constructeur de recopie (B n'existait pas)
Tableau C(3);
C = A;           // opérateur d'affectation (C existait déjà)
```

---

## 12. Composition

Un objet contient un autre objet en tant que membre.

```cpp
class Client {
    Compte c;       // objet membre
    int    nas;
public:
    Client(int nas, double montant)
        : c(montant), nas(nas) {}   // Compte est initialisé avant Client
};
```

**Ordre de construction :**
1. Membres (dans l'ordre de déclaration) → ici `Compte c` en premier.
2. Corps du constructeur de `Client`.

**Ordre de destruction :** inverse de la construction.

---

## Fichiers de cette section

| Fichier | Contenu |
|---------|---------|
| `README.md` | Ce guide théorique |
| `demo-classes.cpp` | Classes complètes : constructeurs, destructeur, statique, `this`, `const` |

---

*Voir aussi :* [theory/06-heritage-polymorphisme/](../06-heritage-polymorphisme/) pour la suite logique.
