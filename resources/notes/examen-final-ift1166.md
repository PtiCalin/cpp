# Examen final — IFT1166 (Chapitres 11 à 18)

> Guide de révision complet basé sur les notes de cours de M. Lokbani.
> Chapitres 11 à 18 inclusivement.

---

## Format de l'examen

| Exo | Type | Contenu |
|-----|------|---------|
| 1 | Correspondances | Terminologie liée à la P.O.O. |
| 2 | Vrai/Faux | Questions conceptuelles sur les classes (justification ≤ 2 lignes) |
| 3 | Choix multiples | Héritage, structures de données, algorithmique (chap. 17-18) |
| 4 | Sortie de programme | Analyse d'affichage (héritage + ligature dynamique) |
| 5 | Correction de bogues | Erreurs de syntaxe, logique et mémoire |
| 6 | Codage | Écriture complète de classes (héritage + ligature dynamique) |

**Conseil :** Le TP#03 constitue une excellente base de préparation.

**Vidéo complémentaire (héritage — IFT1169) :**
<https://classe.iro.umontreal.ca/w/d9EhWwPsDvjnEm6hM6eE2f>

---

## Chapitre 11 — Introduction à la programmation orientée objet

### 1. De la programmation procédurale à la P.O.O.

- **Programmation structurée** : décomposition en sous-programmes, approche descendante (Top-Down).
  - Limite : spécifications instables → fragilité du système.
  - Les fonctions spécialisées ne favorisent pas la réutilisation.

- **Approche orientée objet** : centrée sur les **données** et les mécanismes qui les structurent.
  - On manipule des objets sans se soucier de leur fabrication interne.

### 2. Critères de qualité d'un logiciel (B. Meyer)

| Critère | Description |
|---------|-------------|
| **Correct** | Produit exactement les résultats demandés par les spécifications |
| **Robuste** | Fonctionne bien même dans des conditions anormales |
| **Extensible** | Facile à adapter si les spécifications changent |
| **Réutilisable** | Utilisable intégralement ou en partie dans d'autres applications |
| **Compatible** | Combinable avec d'autres codes |
| **Portable** | Exécutable sur différentes plateformes |
| **Efficace** | Bonne utilisation des ressources (temps, mémoire) |

### 3. Concepts fondamentaux de la P.O.O.

#### Objet
- Entité fermée possédant **mémoire** et **capacité de traitement**.
- Composé de **données** (ce qu'il est) et de **méthodes** (ce qu'il peut faire).
- Deux parties : **interface** (publique) et **interne** (privée).

#### Encapsulation
- Regroupement de codes et de données.
- Dissimulation d'informations au monde extérieur.
- Avantages : meilleure modularité, meilleure sécurité, simplicité apparente.

#### Message
- Moyen **unique** de communication avec les objets.
- Contient : nom de l'objet destinataire, énoncé de la demande, arguments.

#### Polymorphisme
- Même message → réactions différentes selon l'objet.
- Même nom de fonction, plusieurs implantations.
- Exemple : `dessiner()` dans `CARRE`, `CERCLE`, `TRIANGLE`.

#### Classe et Instance
- **Classe** = modèle (moule) décrivant contenu et comportement.
- **Instance** = objet particulier fabriqué à partir du modèle.
- Analogie : `VARIABLE ↔ TYPE` en procédural, `OBJET ↔ CLASSE` en P.O.O.

#### Héritage
- Construire une classe à partir d'une ou plusieurs autres.
- **Classe de base** → **classes dérivées**.
- Vision descendante (enrichissement) et ascendante (factorisation).

### 4. Langages orientés objet — 3 principes

1. Encapsulation des données
2. Structure de classes
3. Héritage

---

## Chapitre 12 — Classes

### 1. Définition

```cpp
class compte {
private:           // par défaut dans une class
    char nom[20];
    double actif;
public:
    void initialise();
};
```

- `struct` → membres **publics** par défaut.
- `class` → membres **privés** par défaut.

### 2. Encapsulation

- Accès aux données `private` uniquement via les fonctions membres `public`.
- Les fonctions membres vérifient les données en entrée.
- Une fonction membre peut aussi être `private` (usage interne).
- Affectation d'objets `CB = CA;` → OK même si membres privés.
- Affectation membre à membre `CB.actif = CA.actif;` → Erreur si `actif` est `private`.

### 3. Constructeurs

**Définition :**
- Méthode appelée à la **création** de l'objet.
- Sert à **initialiser** l'objet.
- Ne retourne rien (pas de `void`), est `public`, porte le même nom que la classe.

```cpp
class compte {
public:
    compte(const char*, double);  // constructeur
};

compte CA("Fred", 100.50);  // déclaration + initialisation
```

**Constructeur par défaut :**
- Existe implicitement si aucun constructeur n'est défini.
- Si un constructeur explicite existe → le constructeur par défaut est **masqué**.
- `compte CB;` → Erreur si seul un constructeur avec arguments existe.

**Surdéfinition :**
```cpp
compte(const char* chaine, double argent = 390, int max = 1000);
compte(double argent, int max, const char* chaine);
```

**Surdéfinition + constructeur par défaut :**
```cpp
class compte {
public:
    compte(char*, double, int);  // constructeur
    compte();                    // constructeur par défaut explicite
};
```

### 4. Destructeur

- Un seul par classe (non surchargeable).
- Appelé automatiquement quand l'objet disparaît (fin de bloc, `delete`).
- Syntaxe : `~nom_de_la_classe();`
- Pas de retour de type.
- Utilité principale : **libérer la mémoire** allouée par le constructeur.

```cpp
tableau::~tableau() {
    delete [] tab;
}
```

### 5. Membres statiques

- Champ `static` = partagé par **tous** les objets de la classe.
- Un seul exemplaire pour toute la classe.
- Initialisation obligatoire : `int compte::nbcomptes = 0;`
- Accès : `compte::nbcomptes`, `A.nbcomptes`, `B.nbcomptes` (3 manières équivalentes).

---

## Chapitre 13 — Propriétés des fonctions membres

### 1. Fonctions membres

- Peuvent être : surdéfinies, avec arguments par défaut, `public`/`private`, `inline`.
- Accès à **tous** les membres de **tous** les objets de la classe.
- Protection au niveau de la **classe**, pas des instances.

### 2. Fonctions `inline`

- Définie **dans** la classe → automatiquement `inline`.
- Définie à l'extérieur → mot clé `inline` requis.
- Avantage : un peu plus rapide.
- Inconvénient : code plus volumineux, définition visible (problème d'encapsulation).

### 3. Méthodes statiques

- Une copie par classe (pas par objet).
- Accès **seulement** aux membres `static`.
- Appelables même sans objet : `compte::fonction_static();`

### 4. Passage d'objets

| Mode | Copie locale ? | Syntaxe déclaration | Syntaxe appel |
|------|---------------|---------------------|---------------|
| Valeur | Oui | `bool egal(const point)` | `a.egal(b)` |
| Pointeur | Non | `bool egal(const point*)` | `a.egal(&b)` |
| Référence | Non | `bool egal(const point&)` | `a.egal(b)` |

### 5. Retour d'objet

- **Par valeur** : objet local copié puis détruit → OK.
- **Par référence** : attention, objet local détruit → référence vide → **Erreur**.
- Référence sur objet **non local** → OK.

### 6. `this`

- Donne l'adresse de l'objet receveur (objet appelant).
- Utilisable par les méthodes **non statiques**.
- Utile pour : surcharge d'opérateurs, appels en cascade, éviter auto-affectation.

### 7. Objets et méthodes `const`

- Objet `const` → seules les méthodes `const` peuvent le manipuler.
- Méthode `const` → garantit que l'objet receveur **ne sera pas modifié**.
- Syntaxe : `void affiche() const { ... }`

---

## Chapitre 14 — Construction, destruction, initialisation et recopie

### 1. Les outils par défaut (C++ fournit)

| Outil | Standard |
|-------|----------|
| Constructeur sans argument | C++03 |
| Destructeur | C++03 |
| Constructeur de recopie | C++03 |
| Opérateur d'affectation | C++03 |
| Constructeur de déplacement (move) | C++11 |
| Opérateur d'affectation par déplacement (move) | C++11 |

### 2. Durée de vie d'un objet

```
Création ──────── Vie ──────── Mort
```

- **Création** : déclaration (auto/static) ou `new` (dynamique).
- **Mort** : fin de portée (auto/static) ou `delete` (dynamique).

### 3. Constructeur de recopie

**Prototype :** `nom_classe(const nom_classe&);`

**Appelé dans 3 situations :**
1. Initialisation d'un objet : `compte B(C);` ou `compte B = C;`
2. Passage par valeur à une fonction.
3. Retour de fonction par valeur.

**Attention :** Différencier recopie et affectation :
```cpp
compte B = C;  // recopie (B n'existe pas encore)
compte B;
B = C;         // affectation (B existe déjà)
```

**Copie superficielle vs. profonde :**
- Par défaut → copie **bit à bit** (superficielle) → dangereux avec des pointeurs !
- Deux pointeurs pointent le même endroit → double `delete` → **Segmentation fault**.
- Solution : définir un constructeur de recopie qui fait une **copie profonde** (allocation + recopie).

```cpp
test(const test& T) {
    ptr = new int(*T.ptr);  // copie profonde
}
```

### 4. Opérateur d'affectation

- Par défaut : affectation membre par membre (superficielle).
- Doit être une fonction membre.
- Signature : `x& operator=(const x&)`
- Vérifier l'auto-affectation : `if (this != &T)`
- Libérer l'ancienne mémoire avant de réallouer.

```cpp
tableau& operator=(const tableau& T) {
    if (this != &T) {
        delete [] tab;
        tab = new double[n = T.n];
        recopie_elt(T);
    }
    return *this;
}
```

### 5. Lvalue / Rvalue (C++11)

- **Lvalue** : accessible via son adresse (`&`), a un emplacement mémoire identifiable.
- **Rvalue** : temporaire, pas de nom, détruite immédiatement après utilisation.
- `&&` : référence rvalue → capture une valeur temporaire.
- `std::move()` : convertit une lvalue en rvalue.

### 6. Constructeur de déplacement (move constructor)

```cpp
tableau(tableau&& T) {
    mData = T.mData;       // vol des ressources
    mTaille = T.mTaille;
    T.mData = nullptr;     // nettoyage de la source
    T.mTaille = 0;
}
```

### 7. Opérateur= de déplacement (move assignment)

```cpp
tableau& operator=(tableau&& T) {
    if (this != &T) {
        delete [] mData;       // libérer l'ancien
        mData = T.mData;       // voler les ressources
        mTaille = T.mTaille;
        T.mData = nullptr;     // nettoyer la source
        T.mTaille = 0;
    }
    return *this;
}
```

### 8. Objet contenant un objet (composition)

```cpp
class client {
    compte c;
    int nas;
public:
    client(int m, double v) : c(v), nas(m) {}
};
```
- Le constructeur de `compte` est appelé **avant** l'initialisation des autres membres de `client`.

---

## Chapitre 15 — Héritage

### 1. Généralités

- 3e paradigme de la P.O.O. (après encapsulation et structure de classes).
- Relation **EST-UN** : un chat *est un* animal. ≠ **A-UN** (composition) : une voiture *a un* moteur.
- Peut être **simple** ou **multiple**.

### 2. Syntaxe

```cpp
class classe_derivee : protection classe_de_base { /* ... */ };
```

### 3. Classe dérivée

- Contient les données membres de la classe de base.
- Peut en posséder de nouvelles.
- Possède (a priori) les méthodes de sa classe de base.
- Peut **redéfinir** (masquer) certaines méthodes.
- Peut posséder de nouvelles méthodes.

### 4. Accès aux membres hérités (héritage `public`)

- Accès aux membres **publics** de la base → OK.
- Accès aux membres **privés** de la base → **Erreur**.

### 5. Redéfinition de fonctions membres

```cpp
void avion::affiche() {
    vehicule::affiche();  // appel de la version de base
    cout << "nbre_moteurs: " << nbre_moteurs << endl;
}
```

### 6. Constructeurs et destructeurs

- Constructeur de la **base** appelé **avant** celui de la dérivée.
- Destructeur de la **base** appelé **après** celui de la dérivée.

```cpp
avion(int nm, double v, int np) : vehicule(v, np) {
    nbre_moteurs = nm;
}
```

- Si la base a un constructeur explicite → la dérivée **doit** appeler un constructeur de la base.
- Si non spécifié → constructeur **par défaut** de la base est appelé (erreur s'il n'existe pas).

### 7. Contrôle des accès

| Membre dans la base | Héritage `public` | Héritage `protected` | Héritage `private` |
|---------------------|-------------------|----------------------|--------------------|
| `public` | `public` | `protected` | `private` |
| `protected` | `protected` | `protected` | `private` |
| `private` | `private` | `private` | `private` |

- `protected` : accessible aux fonctions de la base **et** des classes dérivées.

### 8. Constructeur de recopie (héritage)

```cpp
avion::avion(const avion& a2) : vehicule(a2) {  // a2 converti en vehicule
    nbre_moteurs = a2.nbre_moteurs;
}
```

### 9. Opérateur d'affectation (héritage)

```cpp
avion& avion::operator=(const avion& a2) {
    if (this != &a2) {
        vehicule::operator=(a2);  // appel explicite base
        nbre_moteurs = a2.nbre_moteurs;
    }
    return *this;
}
```

### 10. Compatibilité base ↔ dérivée

| Conversion | Résultat |
|------------|----------|
| Dérivée → Base | OK (on perd les membres excédentaires) |
| Base → Dérivée | **Erreur** |
| Dérivée* → Base* | OK |
| Base* → Dérivée* | Acceptée avec **cast explicite** (dangereux) |

---

## Chapitre 16 — Fonctions virtuelles et classes abstraites

### 1. Ligature statique vs. dynamique

- **Statique** (par défaut) : choix de la fonction au moment de la **compilation** (type déclaré).
- **Dynamique** : choix de la fonction au moment de l'**exécution** (type réel) → mot clé `virtual`.

### 2. Fonction `virtual`

```cpp
class X {
public:
    virtual void f() { cout << "x:f\n"; }
};

class Y : public X {
public:
    void f() { cout << "y:f\n"; }
};

X* ptr = &b;  // b est de type Y
ptr->f();     // Avec virtual → "y:f" ; Sans virtual → "x:f"
```

### 3. Polymorphisme

- Même appel `ptr->f()` → résultats différents selon la classe **réellement pointée**.

### 4. Qui peut être `virtual` ?

| Oui | Non |
|-----|-----|
| Fonctions membres non statiques | Champs membres |
| Destructeurs | Constructeurs |

### 5. Classes abstraites

- Contient au moins une **fonction virtuelle pure** (`= 0`).
- **Impossible** d'instancier un objet d'une classe abstraite.
- Les classes dérivées **doivent** définir les fonctions virtuelles pures.

```cpp
class X {
    virtual void affiche() = 0;  // fonction virtuelle pure
};

class Y : public X {
    void affiche() { cout << "Y:f\n"; }  // obligatoire
};
```

---

## Chapitre 17 — Structures de données élémentaires

### 1. Types de collections

| Type | Accès | Exemples |
|------|-------|----------|
| **Séquentiel** | Linéaire (ordre) | Tableau, file (deque), liste |
| **Associatif** | Par clés | Dictionnaire (`map`) |
| **Adaptateur** | Réglementé | Pile (`stack`), file (`queue`), file prioritaire |

### 2. Tableau vs. Liste

| Opération | Tableau | Liste |
|-----------|---------|-------|
| Accès par index | Rapide | Lent (parcours séquentiel) |
| Insertion/Suppression en fin | Rapide | Rapide |
| Insertion/Suppression au milieu | Lent (décalage) | Rapide (modification de pointeurs) |

### 3. Listes chaînées

- **Simplement chaînée** : chaque élément pointe vers le suivant.
- **Doublement chaînée** : chaque élément pointe vers le suivant **et** le précédent.

**Composantes d'un élément :**
```cpp
class Cellule {
    int valeur;
    Cellule* prochain;
public:
    Cellule(int v, Cellule* suivant);
    Cellule* get_prochain();
    void set_prochain(Cellule* suivant);
    int get_valeur();
};
```

**Opérations :** ajouter à la tête, longueur, trouver le n-ième, concaténer, ajouter en queue, enlever par valeur.

### 4. Pile (Stack)

- Structure **LIFO** (Last In First Out).
- Opérations : `push` (empiler) et `pop` (dépiler).

```
push c    push d    pop
  b          c         c
  a    →   b    →   b    →   b
           a         a         a
```

### 5. STL

- Standard Template Library : structures de données + algorithmes.
- Étude détaillée dans un cours avancé C++.

---

## Chapitre 18 — Algorithmique de base

### 1. Récursivité

- Fonction qui **s'appelle elle-même**.
- Doit contenir un **point d'arrêt** (cas de base).

**Factorielle — itérative :**
```cpp
int factorielle(int n) {
    int resultat = 1;
    for (int i = 1; i <= n; i++) resultat *= i;
    return resultat;
}
```

**Factorielle — récursive :**
```cpp
int factorielle(int n) {
    if (n <= 1) return 1;
    return n * factorielle(n - 1);
}
```

**PGCD — récursif :**
```cpp
int pgcd(int a, int b) {
    if (b == 0) return a;
    return pgcd(b, a % b);
}
```

- Toujours possible de transformer récursif ↔ itératif.
- Récursivité : concise, mais peut être coûteuse en mémoire (pile d'appels).

### 2. Techniques de recherche

**Recherche linéaire (séquentielle) :**
- Parcours un à un → complexité $O(n)$.
- Meilleur cas : $O(1)$, pire cas : $O(n)$.

**Recherche dichotomique (tableau trié) :**
- Diviser en deux à chaque étape.
- Complexité : $O(\log_2 n)$.

```
Calculer milieu = (deb + fin) / 2
Si x == t[milieu] → trouvé
Si t[milieu] > x → chercher dans t[deb, milieu[
Sinon → chercher dans t[milieu+1, fin[
```

### 3. Algorithmes de tri

#### Tri par sélection
1. Trouver le **plus petit** élément.
2. L'échanger avec le premier.
3. Recommencer avec le reste du tableau.

```
[8, 6, 9, 3, 1] → [1, 6, 9, 3, 8] → [1, 3, 9, 6, 8] → [1, 3, 6, 9, 8] → [1, 3, 6, 8, 9]
```

#### Tri à bulles
1. Comparer deux éléments **consécutifs**.
2. Permuter si pas dans l'ordre.
3. Le plus grand se retrouve en dernier.
4. Recommencer avec les $n-1$ éléments restants.

```
[8, 6, 9, 3, 1] → [6, 8, 3, 1, 9] → [6, 3, 1, 8, 9] → [3, 1, 6, 8, 9] → [1, 3, 6, 8, 9]
```

#### Tri par insertion
1. Prendre le $i$-ème élément.
2. L'insérer **à sa place** dans la partie déjà triée.
3. Comme trier un paquet de cartes.

```
[8, 6, 9, 3, 1] → [6, 8, 9, 3, 1] → [6, 8, 9, 3, 1] → [3, 6, 8, 9, 1] → [1, 3, 6, 8, 9]
```

---

## Aide-mémoire rapide pour l'examen

### Terminologie essentielle (Exo 1)

| Terme | Définition |
|-------|-----------|
| Classe | Modèle décrivant contenu (données) et comportement (méthodes) |
| Objet / Instance | Entité concrète fabriquée à partir d'une classe |
| Encapsulation | Regroupement données + méthodes, dissimulation au monde extérieur |
| Héritage | Construire une classe à partir d'une autre (relation EST-UN) |
| Polymorphisme | Même message, comportements différents selon l'objet |
| Classe abstraite | Classe avec au moins une fonction virtuelle pure (`= 0`) |
| Constructeur | Méthode d'initialisation, même nom que la classe, pas de retour |
| Destructeur | Méthode de nettoyage `~Classe()`, appelée à la mort de l'objet |
| Constructeur de recopie | `Classe(const Classe&)` — copie profonde si pointeurs |
| `virtual` | Force la ligature dynamique (choix de méthode à l'exécution) |
| `this` | Pointeur vers l'objet receveur |
| `static` (membre) | Partagé par tous les objets de la classe |
| `protected` | Accessible à la classe et ses dérivées |
| Ligature statique | Résolution au moment de la compilation |
| Ligature dynamique | Résolution au moment de l'exécution |
| LIFO | Last In First Out (pile) |
| Récursivité | Fonction qui s'appelle elle-même avec un point d'arrêt |
| Dichotomie | Recherche par division successive en deux |

### Points pièges courants (Exo 2 / Exo 5)

1. Oublier le `;` après la déclaration d'une classe.
2. `private` par défaut dans une `class`, `public` par défaut dans un `struct`.
3. Constructeur explicite → masque le constructeur par défaut.
4. Copie superficielle de pointeurs → double `delete` → crash.
5. Retourner une référence à un objet local → **dangereux**.
6. `virtual` sur le destructeur → **indispensable** si héritage avec pointeurs de base.
7. Classe abstraite → impossible à instancier.
8. `static` ne peut pas accéder aux membres non-`static`.
9. Ordre constructeurs : base → dérivée. Ordre destructeurs : dérivée → base.
10. `operator=` doit vérifier l'auto-affectation (`this != &T`).
