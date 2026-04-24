# Théorie 06 — Héritage et Polymorphisme

> Chapitres 15–16 · IFT1166 · **Priorité maximale pour l'examen final**

---

## Table des matières

1. [Héritage — concepts fondamentaux](#1-héritage--concepts-fondamentaux)
2. [Syntaxe et structure](#2-syntaxe-et-structure)
3. [Constructeurs et destructeurs en héritage](#3-constructeurs-et-destructeurs-en-héritage)
4. [Contrôle des accès](#4-contrôle-des-accès)
5. [Redéfinition de méthodes](#5-redéfinition-de-méthodes)
6. [Compatibilité base ↔ dérivée](#6-compatibilité-base--dérivée)
7. [Fonctions virtuelles (ligature dynamique)](#7-fonctions-virtuelles-ligature-dynamique)
8. [Classes abstraites](#8-classes-abstraites)
9. [Règle de la Règle des Trois (en héritage)](#9-règle-des-trois-en-héritage)
10. [Pièges classiques à l'examen](#10-pièges-classiques-à-lexamen)

---

## 1. Héritage — concepts fondamentaux

### Pourquoi hériter ?

L'héritage permet de **réutiliser et spécialiser** du code existant sans le dupliquer.

| Relation | Mécanisme | Exemple |
|----------|-----------|---------|
| **EST-UN** (*is-a*) | Héritage | Un `Chien` est un `Animal` |
| **A-UN** (*has-a*) | Composition | Une `Voiture` a un `Moteur` |

> Règle pratique : si la phrase "X *est un* Y" est naturelle → héritage. Sinon → composition.

### Les deux visions

- **Descendante** (spécialisation) : partir d'une classe générale et l'enrichir.
- **Ascendante** (factorisation) : repérer des attributs communs et les extraire dans une base.

---

## 2. Syntaxe et structure

```cpp
class ClasseDeBase {
protected:
    double vitesse;
    int    nbPassagers;
public:
    ClasseDeBase(double v, int np);
    void affiche() const;
};

class ClasseDerivee : public ClasseDeBase {   // héritage public
private:
    int nbreMoteurs;
public:
    ClasseDerivee(int nm, double v, int np);
    void affiche() const;   // redéfinition
};
```

**La classe dérivée hérite :**
- Tous les **champs** de la base (publics + protégés).
- Toutes les **méthodes** de la base (sauf constructeurs, destructeurs, opérateur=).

---

## 3. Constructeurs et destructeurs en héritage

### Ordre d'appel

```
Création :   Constructeur BASE  →  Constructeur DÉRIVÉE
Destruction: Destructeur DÉRIVÉE  →  Destructeur BASE
```

### Appel explicite du constructeur de base

```cpp
// Liste d'initialisation obligatoire si la base n'a pas de constructeur par défaut
ClasseDerivee::ClasseDerivee(int nm, double v, int np)
    : ClasseDeBase(v, np),   // appel du constructeur base
      nbreMoteurs(nm)
{}
```

> Si aucun constructeur base n'est spécifié → le **constructeur par défaut** de la base est appelé.
> S'il n'existe pas → **erreur de compilation**.

### Constructeur de recopie (héritage)

```cpp
Avion::Avion(const Avion& a) : Vehicule(a) {   // a est converti en Vehicule
    nbreMoteurs = a.nbreMoteurs;
}
```

### Opérateur d'affectation (héritage)

```cpp
Avion& Avion::operator=(const Avion& a) {
    if (this != &a) {
        Vehicule::operator=(a);         // partie base
        nbreMoteurs = a.nbreMoteurs;    // partie dérivée
    }
    return *this;
}
```

---

## 4. Contrôle des accès

| Membre dans la base | Héritage `public` | Héritage `protected` | Héritage `private` |
|---------------------|:-----------------:|:--------------------:|:-----------------:|
| `public`            | `public`          | `protected`          | `private`         |
| `protected`         | `protected`       | `protected`          | `private`         |
| `private`           | inaccessible      | inaccessible         | inaccessible      |

**`protected` :** accessible à la classe elle-même **et** à ses dérivées. Invisible de l'extérieur.

### Tableau des accès directs

| Depuis                | `public` | `protected` | `private` |
|-----------------------|:--------:|:-----------:|:---------:|
| Classe elle-même      | ✓        | ✓           | ✓         |
| Classe dérivée        | ✓        | ✓           | ✗         |
| Code client (externe) | ✓        | ✗           | ✗         |

---

## 5. Redéfinition de méthodes

La dérivée peut **redéfinir** (masquer) une méthode de la base.

```cpp
void Avion::affiche() const {
    Vehicule::affiche();                          // appel version base
    cout << "Moteurs : " << nbreMoteurs << "\n";  // ajout dérivée
}
```

**Avec ligature statique (pas de `virtual`) :**
```cpp
Vehicule* ptr = new Avion(2, 800.0, 150);
ptr->affiche();  // → appelle Vehicule::affiche() (type DÉCLARÉ)
```

**Différence clé avec `virtual` :** voir section 7.

---

## 6. Compatibilité base ↔ dérivée

| Conversion | Autorisée ? | Remarque |
|------------|:-----------:|----------|
| Dérivée → Base (objet) | ✓ | Perte des membres excédentaires (slicing) |
| Base → Dérivée (objet) | ✗ | Erreur de compilation |
| `Derivee*` → `Base*`  | ✓ | Polymorphisme possible |
| `Base*` → `Derivee*`  | ⚠️ | Nécessite un cast explicite (dangereux) |
| `Derivee&` → `Base&`  | ✓ | Même règle que les pointeurs |

```cpp
Avion a(2, 800.0, 150);
Vehicule v = a;     // OK — slicing : nbreMoteurs perdu
Vehicule& rv = a;   // OK — référence polymorphique
Vehicule* pv = &a;  // OK — pointeur polymorphique
```

---

## 7. Fonctions virtuelles (ligature dynamique)

### Principe

```cpp
class Base {
public:
    virtual void f() { cout << "Base::f\n"; }
};

class Derivee : public Base {
public:
    void f() override { cout << "Derivee::f\n"; }
};

Base* ptr = new Derivee();
ptr->f();   // Avec virtual → "Derivee::f"  (type RÉEL)
            // Sans virtual → "Base::f"     (type DÉCLARÉ)
```

### Ligature statique vs. dynamique

| | Statique (défaut) | Dynamique (`virtual`) |
|---|---|---|
| Moment du choix | Compilation | Exécution |
| Basé sur | Type **déclaré** | Type **réel** de l'objet |
| Mot-clé | (aucun) | `virtual` |

### Ce qui peut (et ne peut pas) être `virtual`

| Oui ✓ | Non ✗ |
|-------|-------|
| Fonctions membres non statiques | Constructeurs |
| Destructeurs | Champs membres |
| Fonctions dans des classes dérivées | Fonctions statiques |

### Destructeur virtuel — règle obligatoire

Si une classe est conçue pour être héritée **et** que vous utilisez `delete` via un pointeur de base :

```cpp
class Base {
public:
    virtual ~Base() {}   // OBLIGATOIRE pour éviter les fuites mémoire
};
```

Sans `virtual` sur le destructeur → seul le destructeur de `Base` est appelé → **fuite mémoire**.

### `override` et `final` (C++11)

```cpp
class Derivee : public Base {
public:
    void f() override;  // erreur de compilation si f() n'existe pas dans Base
    void g() final;     // interdit toute redéfinition dans les sous-classes
};
```

---

## 8. Classes abstraites

### Définition

Une classe est **abstraite** si elle possède au moins une **fonction virtuelle pure** (`= 0`).

```cpp
class Forme {                              // classe abstraite
public:
    virtual double aire()    const = 0;   // pure virtuelle
    virtual double perimetre() const = 0; // pure virtuelle
    virtual void   affiche() const;       // virtuelle normale (optionnelle)
    virtual ~Forme() {}
};
```

**Règles :**
- On **ne peut pas** instancier une classe abstraite : `Forme f;` → **erreur**.
- Une classe dérivée qui ne redéfinit **pas toutes** les pures reste abstraite.
- On **peut** avoir un pointeur ou une référence vers une classe abstraite.

### Hiérarchie typique

```
     Forme (abstraite)
    /       |       \
Cercle   Rectangle  Triangle
```

```cpp
class Cercle : public Forme {
    double rayon;
public:
    Cercle(double r) : rayon(r) {}
    double aire()      const override { return 3.14159 * rayon * rayon; }
    double perimetre() const override { return 2 * 3.14159 * rayon; }
};
```

### Tableau polymorphique

```cpp
Forme* formes[3] = {
    new Cercle(5.0),
    new Rectangle(4.0, 6.0),
    new Triangle(3.0, 4.0, 5.0)
};

for (int i = 0; i < 3; i++) {
    formes[i]->affiche();   // appel polymorphique — type réel utilisé
    delete formes[i];       // destructeur virtuel → OK
}
```

---

## 9. Règle des Trois (en héritage)

Si la base définit l'un des trois → les dérivées aussi (en appelant la version de la base).

| Outil | Base | Dérivée |
|-------|------|---------|
| Destructeur | `~Base()` libère `Base::ptr` | `~Derivee()` libère `Derivee::ptr` |
| Constructeur de recopie | `Base(const Base&)` | `Derivee(const Derivee& d) : Base(d) { ... }` |
| Opérateur d'affectation | `Base& operator=(const Base&)` | Appel `Base::operator=(d)` en premier |

---

## 10. Pièges classiques à l'examen

| Piège | Explication |
|-------|-------------|
| Oublier `virtual` sur le destructeur | Fuite mémoire lors du `delete` via pointeur base |
| Appeler directement `affiche()` sans `virtual` | Ligature statique → toujours version base |
| Ne pas appeler la version base dans la redéfinition | Comportement incomplet |
| Instancier une classe abstraite | Erreur de compilation |
| Oublier l'appel au constructeur base | Constructeur par défaut appelé (ou erreur) |
| Slicing | Assigner un objet dérivé à un objet base perd les membres extra |

---

## Fichiers de cette section

| Fichier | Contenu |
|---------|---------|
| `README.md` | Ce guide théorique |
| `demo-heritage.cpp` | Exemple complet compilable : héritage, redéfinition, `virtual` |
| `demo-abstrait.cpp` | Hiérarchie avec classe abstraite et tableau polymorphique |

---

*Voir aussi :* [theory/05-programmation-objet/](../05-programmation-objet/) pour les prérequis sur les classes.
