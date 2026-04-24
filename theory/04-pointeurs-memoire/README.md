# Théorie 04 — Pointeurs et Mémoire dynamique

> Chapitres correspondants aux ex08–ex09 · IFT1166

---

## Table des matières

1. [Pointeurs — fondamentaux](#1-pointeurs--fondamentaux)
2. [Arithmétique des pointeurs](#2-arithmétique-des-pointeurs)
3. [Pointeurs et tableaux](#3-pointeurs-et-tableaux)
4. [Références](#4-références)
5. [Pointeurs vs. références](#5-pointeurs-vs-références)
6. [Mémoire dynamique — `new` et `delete`](#6-mémoire-dynamique--new-et-delete)
7. [Pointeurs et classes](#7-pointeurs-et-classes)
8. [Fuites mémoire et bonnes pratiques](#8-fuites-mémoire-et-bonnes-pratiques)
9. [RAII — gestion automatique des ressources](#9-raii--gestion-automatique-des-ressources)

---

## 1. Pointeurs — fondamentaux

Un pointeur est une variable qui **contient une adresse mémoire**.

```
Mémoire :
┌───────┬───────┬───────────┐
│ adr 0 │ adr 4 │  adr 8    │
│  42   │ (ptr) │    ...    │
└───────┴───────┴───────────┘
          ptr = 0x0 (adresse de la case 0)
```

### Déclaration et opérateurs fondamentaux

| Opérateur | Nom | Signification |
|-----------|-----|--------------|
| `*`  (décl.) | Type pointeur | `int* ptr;` — ptr est un pointeur vers int |
| `&`  (unaire) | Adresse de | `ptr = &x;` — ptr reçoit l'adresse de x |
| `*`  (unaire) | Déréférencement | `*ptr = 5;` — modifie la valeur pointée |

```cpp
int  x   = 42;
int* ptr = &x;      // ptr pointe vers x

cout << x;          // 42 — valeur de x
cout << &x;         // adresse de x (ex : 0x61fe08)
cout << ptr;        // même adresse
cout << *ptr;       // 42 — déréférencement

*ptr = 100;         // modifie x via le pointeur
cout << x;          // 100
```

### Pointeur nul

```cpp
int* p = nullptr;   // C++11 (préférer à NULL ou 0)

if (p != nullptr) {
    *p = 5;         // OK seulement si p est valide
}
```

---

## 2. Arithmétique des pointeurs

```cpp
int tab[5] = {10, 20, 30, 40, 50};
int* p = tab;   // p pointe sur tab[0]

cout << *p;      // 10
p++;             // avance de sizeof(int) octets
cout << *p;      // 20
cout << *(p+2);  // 40
```

**Règle :** `p + n` avance de `n * sizeof(*p)` octets en mémoire.

**Différence de pointeurs :**
```cpp
int* debut = &tab[0];
int* fin   = &tab[4];
ptrdiff_t dist = fin - debut;  // 4 (nombre d'éléments, pas d'octets)
```

---

## 3. Pointeurs et tableaux

Un tableau **se convertit implicitement** en pointeur vers son premier élément.

```cpp
int tab[5] = {1, 2, 3, 4, 5};

// Les deux formes sont équivalentes :
cout << tab[2];    // notation tableau
cout << *(tab+2);  // notation pointeur
```

**Passage en paramètre :**
```cpp
// Ces déclarations sont équivalentes :
void affiche(int* tab, int n);
void affiche(int tab[], int n);

// La taille se perd → toujours passer n en paramètre
```

---

## 4. Références

Une référence est un **alias** permanent pour une variable existante.

```cpp
int  x = 10;
int& r = x;    // r est un alias de x (doit être initialisée à la déclaration)

r = 20;        // modifie x
cout << x;     // 20

int& ref;      // ERREUR : une référence doit être initialisée
```

### Références en paramètre

```cpp
// Passage par valeur — copie locale
void incrementerVal(int n) { n++; }

// Passage par référence — modifie l'original
void incrementerRef(int& n) { n++; }

// Passage par référence const — lecture seule, pas de copie
void afficher(const string& s) { cout << s; }
```

---

## 5. Pointeurs vs. références

| Caractéristique | Pointeur | Référence |
|----------------|---------|-----------|
| Peut être nul | Oui (`nullptr`) | Non (toujours liée) |
| Peut être réassigné | Oui | Non |
| Syntaxe d'accès | `*p`, `p->membre` | `r`, `r.membre` |
| Arithmétique | Oui | Non |
| Initialisation obligatoire | Non | Oui |

**Règle de choix :**
- Préférer les **références** pour les paramètres de fonctions (plus sûr, plus lisible).
- Utiliser les **pointeurs** quand la valeur nulle est possible ou quand il faut changer de cible.

---

## 6. Mémoire dynamique — `new` et `delete`

### Allocation d'un objet simple

```cpp
int* p = new int(42);   // alloue et initialise à 42
cout << *p;             // 42
delete p;               // libère la mémoire
p = nullptr;            // bonne pratique : éviter les dangling pointers
```

### Allocation d'un tableau

```cpp
int n = 10;
int* tab = new int[n];  // alloue un tableau de n entiers

for (int i = 0; i < n; i++) tab[i] = i * i;

delete[] tab;           // OBLIGATOIRE : [] pour les tableaux
tab = nullptr;
```

**Règle d'or :** chaque `new` doit avoir exactement un `delete`. Chaque `new[]` doit avoir un `delete[]`.

### Allocation d'objets

```cpp
class Point {
    double x, y;
public:
    Point(double px, double py) : x(px), y(py) {}
    void afficher() const { cout << "(" << x << ", " << y << ")\n"; }
};

Point* p = new Point(3.0, 4.0);
p->afficher();   // notation flèche pour accès via pointeur
delete p;
```

---

## 7. Pointeurs et classes

### Opérateur `->` (flèche)

```cpp
Point* p = new Point(1.0, 2.0);

// Les deux formes sont équivalentes :
(*p).afficher();  // déréférencement puis accès
p->afficher();    // opérateur flèche (préférable)
```

### Tableau d'objets dynamique

```cpp
int n = 3;
Point* points = new Point[n] {
    Point(0,0), Point(1,1), Point(2,2)
};

for (int i = 0; i < n; i++) points[i].afficher();

delete[] points;
```

---

## 8. Fuites mémoire et bonnes pratiques

### Fuite mémoire (memory leak)

```cpp
void mauvaiseFonction() {
    int* p = new int(5);
    // oubli de delete p → fuite mémoire à chaque appel
}

void bonneFonction() {
    int* p = new int(5);
    // ... utilisation ...
    delete p;           // libération avant sortie
    p = nullptr;
}
```

### Double delete (undefined behavior)

```cpp
int* p = new int(5);
delete p;
delete p;   // ERREUR : comportement indéfini (crash probable)
```

### Pointeur pendant (dangling pointer)

```cpp
int* p = new int(5);
delete p;
cout << *p;  // ERREUR : p pointe vers mémoire libérée
p = nullptr; // bonne pratique après delete
```

### Checklist mémoire sûre

- [ ] Chaque `new` a un `delete` correspondant
- [ ] Chaque `new[]` a un `delete[]` correspondant
- [ ] Mettre le pointeur à `nullptr` après `delete`
- [ ] Vérifier qu'un pointeur n'est pas `nullptr` avant déréférencement
- [ ] Ne jamais retourner l'adresse d'une variable locale

---

## 9. RAII — gestion automatique des ressources

**RAII** (Resource Acquisition Is Initialization) : lier la durée de vie d'une ressource à celle d'un objet.

```cpp
class TableauRAII {
    int* data;
    int  n;
public:
    explicit TableauRAII(int taille) : n(taille), data(new int[taille]()) {}
    ~TableauRAII() { delete[] data; }  // libération automatique

    // Désactiver la copie superficielle :
    TableauRAII(const TableauRAII&) = delete;
    TableauRAII& operator=(const TableauRAII&) = delete;

    int& operator[](int i) { return data[i]; }
};

{
    TableauRAII t(10);   // allocation
    t[0] = 42;
}   // t détruit ici → delete[] appelé automatiquement
```

En C++ moderne, préférer `std::vector<int>` ou `std::unique_ptr<int[]>` aux tableaux dynamiques manuels.

---

## Fichiers de cette section

| Fichier | Contenu |
|---------|---------|
| `README.md` | Ce guide théorique |
| `demo-pointeurs.cpp` | Pointeurs, arithmétique, références, dynamique, RAII |

---

*Voir aussi :* [theory/05-programmation-objet/](../05-programmation-objet/) pour les pointeurs dans le contexte des classes.
