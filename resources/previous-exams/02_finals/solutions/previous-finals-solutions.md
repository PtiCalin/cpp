# IFT1166 — Solutions des examens finaux

> **Usage pédagogique.** Ce fichier est un corrigé de référence pour les examens finaux
> de Mohamed Lokbani (IFT1166, Université de Montréal). Chaque solution est commentée
> pour expliquer le raisonnement, pas seulement le résultat.
>
> **Table des matières**
> - [Été 2008](#été-2008)
> - [Été 2007](#été-2007)
> - [Automne 2005](#automne-2005)
> - [Hiver 2005](#hiver-2005)
> - [Hiver 2004](#hiver-2004)
> - [Automne 2003](#automne-2003)
> - [Hiver 2001](#hiver-2001)
> - [Automne 2000](#automne-2000)
> - [Été 2000](#été-2000)
> - [Hiver 2000](#hiver-2000)
> - [Automne 1999](#automne-1999)

---

## Été 2008

### Exercice 1 — Questions théoriques (20 pts)

#### 1.1 — Quand un destructeur est-il appelé?

**Réponses correctes : (a), (b), (c)**

- **(a)** Variable locale qui quitte sa portée : le destructeur est appelé automatiquement à la fin du bloc `{}`.
- **(b)** `delete p` : libère l'objet pointé par `p` (alloué avec `new`).
- **(c)** `delete[] p` : libère un tableau d'objets alloué avec `new[]`.

---

#### 1.2 — Peut-on détruire une instance si le destructeur est privé?

**Réponse : (b) NON**

**Pourquoi ?** Le destructeur est appelé implicitement quand l'objet sort de portée ou explicitement via `delete`. Si le destructeur est privé, le code extérieur à la classe ne peut pas l'appeler → erreur de compilation. Seules les méthodes membres ou amies de la classe peuvent détruire l'objet.

---

#### 1.3 — Définition d'une déclaration de classe

La **déclaration** (ou définition) d'une classe est la description de sa structure : ses membres données et les prototypes de ses méthodes. Elle fixe le contrat de l'interface.

```cpp
class MaClasse {
private:
    int x;
public:
    MaClasse(int val);  // prototype (déclaration)
    int getX() const;   // prototype (déclaration)
};
```

> La *définition* des méthodes (le corps) peut apparaître ailleurs (dans le `.cpp`).

---

#### 1.4 — Les membres dérivés ont-ils accès à tous les membres de la base?

**Réponse : (b) NON**

**Pourquoi ?** Les membres `private` de la classe de base sont **totalement inaccessibles** aux classes dérivées. Seuls les membres `public` et `protected` sont accessibles. Pour rendre un membre accessible aux dérivées uniquement, on utilise `protected`.

---

#### 1.5 — Le mot-clé `inline` est indicatif

**Pourquoi ?** Le compilateur peut refuser l'inlinisation si la fonction est trop complexe (boucles, récursion, trop grande). `inline` est une **suggestion**, pas une obligation. Le compilateur reste maître de la décision finale pour des raisons d'optimisation.

---

#### 1.6 — Prototype de la fonction `test`

```cpp
// Retourne : double*
// Arg 1 : string& (référence)
// Arg 2 : char  (valeur, défaut 'w')
// Arg 3 : int*  (pointeur, défaut NULL)
double* test(string& s, char c = 'w', int* n = NULL);
```

---

#### 1.7 — Appels valides à `test`

```cpp
string mot = "bonjour";
int x = 5;

test(mot);              // arg 2 et 3 par défaut
test(mot, 'a');         // arg 3 par défaut
test(mot, 'a', &x);    // tous les arguments fournis
// test(mot, NULL, &x) // INVALIDE : arg 2 doit être char, NULL → ambiguïté
```

> Les arguments par défaut doivent être fournis de droite à gauche ; on ne peut pas sauter l'arg 2 pour fournir l'arg 3.

---

#### 1.8 — Multi-fichiers

**a)** Il faut ajouter `#include "a.h"` dans `test.cpp` pour que le compilateur connaisse la déclaration de la méthode `affiche`.

**b) (a) OUI**, on peut compiler `test.cpp` sans `a.cpp`. La compilation ne nécessite que les *déclarations* (dans `a.h`). La *définition* de `affiche` (dans `a.cpp`) n'est nécessaire qu'à l'**édition de liens**.

**c) Commande pour générer l'exécutable :**

```bash
g++ test.o a.o -o test.exe
```

---

### Exercice 2 — Constructeurs et membres statiques

#### 2.1 — Combien de fois `A()` est-il appelé?

```cpp
A u;         // A() appelé → u
A v;         // A() appelé → v
A *x;        // aucun appel (déclaration d'un pointeur)
x = new A(); // A() appelé → objet sur le tas
A y = u;     // CONSTRUCTEUR DE RECOPIE → A(A&), pas A()
A *z = new A(); // A() appelé → objet sur le tas
```

**Réponse : 4 fois** (`u`, `v`, `*x`, `*z`)

> `A y = u` appelle le **constructeur de recopie** (qui par défaut n'affiche rien). Seulement si un `A(A&)` explicite était défini autrement, ce serait différent.

---

#### 2.2 — Sortie du programme avec membre `static`

```cpp
class A { public: int x; A() { x = 5; } };
class B : public A {
public:
    static int x;  // MASQUE le x non-statique de A
    B()       { x++; }       // x de B (static)
    B(int i)  { x = x + i; }
    B(string) { x--; }
};
int B::x = 10;  // x statique de B initialisé à 10

B b1;         // B::x = 10 + 1 = 11
B b2(2008);   // B::x = 11 + 2008 = 2019
B b3("IFT1166"); // B::x = 2019 - 1 = 2018

cout << b1.x << " : " << b2.x << " : " << b3.x << endl;
```

**Affichage : `2018 : 2018 : 2018`**

**Pourquoi ?** `B::x` est **statique** : partagé par toutes les instances de `B`. Même si `b1`, `b2`, `b3` sont créées séquentiellement, elles accèdent toutes au même `x`. À la fin des 3 constructions, `B::x` vaut `2018`.

> `A::x` (non-statique) vaut `5` pour chaque instance, mais il est masqué par `B::x` statique.

---

### Exercice 3 — Ligature et classes abstraites (20 pts)

```cpp
class UneInterface { public: virtual void methodeX(int c) = 0; };
class A { public: void methodeX(int c) {} };
class B: public UneInterface { public: void methodeY(int c) {} void methodeX(int c) {} };
class C: public B { public: void methodeZ(int c) {} };
```

#### 3.1 `UneInterface* x = new A(); x->methodeX(10);`

**INCORRECT**

`A` n'hérite pas de `UneInterface`. On ne peut pas assigner `A*` à `UneInterface*` car il n'y a pas de relation d'héritage entre eux. Erreur de compilation.

---

#### 3.2 `UneInterface* y = new B(); y->methodeY(10);`

**INCORRECT**

`B` implémente `UneInterface`, donc `y = new B()` est valide. Mais le type statique de `y` est `UneInterface*`, et `methodeY` n'est **pas déclarée dans `UneInterface`**. Le compilateur voit seulement l'interface → `methodeY` introuvable. Erreur de compilation.

---

#### 3.3 `UneInterface* z = new B(); z->methodeX(10);`

**CORRECT**

`B` hérite de `UneInterface` et implémente `methodeX`. `z` est `UneInterface*` → `methodeX` est dans l'interface (virtuelle pure, implémentée par `B`). La ligature dynamique appelle `B::methodeX`. ✓

---

#### 3.4 `UneInterface* w = new C(); w->methodeZ(10);`

**INCORRECT**

Même raison que 3.2 : `methodeZ` n'est pas dans `UneInterface`. Le type statique `UneInterface*` ne connaît pas `methodeZ`.

---

#### 3.5 `UneInterface* q = new C(); q->methodeX(10);`

**CORRECT**

`C` hérite de `B` qui hérite de `UneInterface`. `methodeX` est dans l'interface. `C` hérite l'implémentation de `B::methodeX`. La ligature dynamique appelle `B::methodeX`. ✓

---

### Exercice 4 — Classe Compteur + UnExemple (20 pts)

#### 4.1 — Classe `Compteur`

```cpp
class Compteur {
private:
    int valeur;  // toujours >= 0

public:
    // Valeur nulle à la création
    Compteur() : valeur(0) {}

    // Incrémentation de 1 seulement
    void incremente() {
        valeur++;
    }

    // Lecture de la valeur courante
    int getValeur() const {
        return valeur;
    }
};
```

---

#### 4.2 — Fonction `UnExemple`

```cpp
#include <iostream>
#include <cstdlib>   // rand(), srand()
#include <ctime>     // time()
using namespace std;

void UnExemple() {
    Compteur pile, face;

    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < 100; i++) {
        int tirage = rand() % 2;  // 0 = pile, 1 = face
        if (tirage == 0)
            pile.incremente();
        else
            face.incremente();
    }

    cout << "Pile : " << pile.getValeur() << endl;
    cout << "Face : " << face.getValeur() << endl;
}
```

---

### Exercice 5 — Manipulation de chaînes et listes chaînées (25 pts)

#### 5.1 — `ConvertirMinus`

```cpp
void ConvertirMinus(string& mot) {
    for (size_t i = 0; i < mot.length(); i++) {
        mot[i] = tolower(mot[i]);
    }
}
```

---

#### 5.2 — `SwapElements`

```cpp
void SwapElements(char tab[], int i, int j) {
    char temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
}
```

---

#### 5.3 — `ConvertirString`

```cpp
// Convertit string → char* (équivalent maison de c_str())
char* ConvertirString(string mot) {
    int n = mot.length();
    char* resultat = new char[n + 1];  // +1 pour '\0'
    for (int i = 0; i < n; i++) {
        resultat[i] = mot[i];
    }
    resultat[n] = '\0';
    return resultat;
}
```

> ⚠️ L'appelant est responsable de libérer la mémoire avec `delete[]`.

---

#### 5.4 — `SortString` (tri par sélection)

```cpp
string SortString(string mot) {
    ConvertirMinus(mot);              // optionnel selon énoncé
    char* tab = ConvertirString(mot);
    int n = mot.length();

    // Tri par sélection
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (tab[j] < tab[minIdx])
                minIdx = j;
        }
        if (minIdx != i)
            SwapElements(tab, i, minIdx);
    }

    string resultat(tab);
    delete[] tab;
    return resultat;
}
// Exemple : SortString("billet") → "beillt"
```

---

#### 5.5 — `int getLongueur()`

```cpp
int Liste::getLongueur() {
    return longueur;
}
```

---

#### 5.6 — `string getElt(int i)`

```cpp
string Liste::getElt(int i) {
    if (i < 0 || i >= longueur)
        return "";  // index invalide → chaîne vide

    Cellule* courant = tete;
    for (int j = 0; j < i; j++) {
        courant = courant->get_prochain();
    }
    return courant->get_valeur();
}
```

---

#### 5.7 — Fonction `main` — Anagrammes

```cpp
// Deux mots sont anagrammes si leurs versions triées/minuscules sont identiques
bool sontAnagrammes(string a, string b) {
    ConvertirMinus(a);
    ConvertirMinus(b);
    return SortString(a) == SortString(b);
}

int main() {
    Liste MOTS;
    MOTS.ajout_queue("ami");
    MOTS.ajout_queue("Mai");
    MOTS.ajout_queue("Bonjour");
    MOTS.ajout_queue("Brisavion");
    MOTS.ajout_queue("BorisVian");

    Liste RESULTAT;

    for (int i = 0; i < MOTS.getLongueur(); i++) {
        string mot = MOTS.getElt(i);
        bool dejaPresent = false;

        for (int j = 0; j < RESULTAT.getLongueur(); j++) {
            if (sontAnagrammes(mot, RESULTAT.getElt(j))) {
                dejaPresent = true;
                break;
            }
        }

        if (!dejaPresent)
            RESULTAT.ajout_queue(mot);
    }

    cout << "La liste des mots: ";
    MOTS.affiche();

    cout << "La liste des anagrammes: ";
    RESULTAT.affiche();

    return 0;
}
// Sortie :
// La liste des mots: ami Mai Bonjour Brisavion BorisVian
// La liste des anagrammes: ami Bonjour Brisavion
```

> **Logique :** "ami" et "Mai" → triés en minuscules donnent tous les deux "aim" → anagrammes. "Brisavion" et "BorisVian" → triés en minuscules donnent "abiinorsv" et "abiinorsv" → anagrammes.

---

## Été 2007

### Exercice 1 — Gestion mémoire (20 pts)

#### 1.1 — Fuite mémoire

Une **fuite mémoire** (*memory leak*) se produit quand de la mémoire est allouée dynamiquement avec `new` mais jamais libérée avec `delete`. Le programme consomme de plus en plus de mémoire sans jamais la rendre au système d'exploitation, ce qui peut le faire crasher ou ralentir.

---

#### 1.2 — Libérations correspondantes

| Allocation | Libération |
|-----------|-----------|
| `string *p = new string;` | `delete p;` |
| `string *p = new string[3];` | `delete[] p;` |
| `Temps *p = new Temps(12,0,0);` | `delete p;` |
| `int *p = new int(33);` | `delete p;` |
| `int *p = new int[33];` | `delete[] p;` |

> Règle : `new` → `delete`, `new[]` → `delete[]`. Ne jamais mélanger.

---

#### 1.3 — Erreurs dans le programme

```cpp
int *p1 = new int(5);
int *p2 = p1;       // p2 pointe sur le même objet que p1
cout << *p2 << endl;
delete[] p1;  // ERREUR 1 : doit être delete p1 (pas un tableau)
delete p2;    // ERREUR 2 : double libération — p1 et p2 pointent au même endroit
```

**Corrections :**

```cpp
int *p1 = new int(5);
int *p2 = p1;
cout << "p1 pointe la valeur " << *p2 << endl;
delete p1;   // Correction : delete simple, pas delete[]
// p2 = nullptr; // bonne pratique : ne pas appeler delete sur p2
```

---

#### 1.4 — 3 erreurs fondamentales de gestion mémoire

```cpp
double* d = new double;   // ERREUR 1 : alloue 1 double, pas un tableau
for (unsigned int i = 0; i < 3; i++) {
    d[i] = 1.5 + i;       // accès hors limites si i > 0
}
for (unsigned int i = 2; i >= 0; i--) {  // ERREUR 2 : boucle infinie (unsigned ne devient jamais < 0)
    cout << d[i] << endl;
}
// ERREUR 3 : pas de delete à la fin → fuite mémoire
```

**Version corrigée :**

```cpp
#include <iostream>
int main() {
    using namespace std;
    double* d = new double[3];  // FIX 1 : tableau de 3
    for (unsigned int i = 0; i < 3; i++) {
        d[i] = 1.5 + i;
    }
    for (int i = 2; i >= 0; i--) {  // FIX 2 : int signé pour la décrémentation
        cout << d[i] << endl;
    }
    delete[] d;  // FIX 3 : libération
    return 0;
}
```

---

### Exercice 2 — Héritage et droits d'accès (15 pts)

```cpp
class C  { private: int x; protected: int y; public: int z; };
class C1 : public  C { private: int x1; public: int y1; };
class C2 : private C { private: int x2; public: int y2; };

C1 o1;
C2 o2;
```

| Instruction | Résultat | Raison |
|-------------|----------|--------|
| `cout << o1.x` | **INCORRECT** | `x` est `private` dans `C` → inaccessible depuis l'extérieur |
| `cout << o2.y` | **INCORRECT** | Héritage `private` : `y` (protected dans C) devient `private` dans C2 → inaccessible depuis `main` |
| `cout << o1.z` | **CORRECT** | Héritage `public` : `z` reste `public` dans C1 → accessible |
| `cout << o1.x1` | **INCORRECT** | `x1` est `private` dans C1 → inaccessible depuis `main` |
| `cout << o1.y1` | **CORRECT** | `y1` est `public` dans C1 → accessible |
| `cout << o2.z` | **INCORRECT** | Héritage `private` : `z` (public dans C) devient `private` dans C2 → inaccessible |
| `cout << o2.x2` | **INCORRECT** | `x2` est `private` dans C2 → inaccessible |
| `cout << o2.y2` | **CORRECT** | `y2` est `public` dans C2 → accessible |

---

### Exercice 3 — Récursion (20 pts)

#### 3.1 — Analyse des fonctions récursives

**Fonction `f(int n)` — appelée avec n ≥ 0**

```cpp
int f(int n) {
    if (n == 0) return 1;
    else return f(n + 1);  // n augmente indéfiniment !
}
```

**EXÉCUTION INCORRECTE.** Si n ≥ 0, on appelle `f(n+1)`, qui appelle `f(n+2)`, etc. sans jamais atteindre le cas de base `n==0`. → Récursion infinie → dépassement de pile (*stack overflow*).

---

**Fonction `m(int n)` — appelée avec n < 0**

```cpp
int m(int n) {
    if (n == 0) return 0;
    else { int result = m(n - 1); result += n; return result; }
}
```

**EXÉCUTION INCORRECTE.** Si n = -3, on appelle `m(-4)`, puis `m(-5)`... n devient de plus en plus négatif, jamais 0. → Récursion infinie → stack overflow.

---

**Fonction `g(char* p, char c)` — appelée avec `("Il etait une fois un petit chaperon rouge", 't')`**

```cpp
int g(char* p, char c) {
    return (*p) ? (*p == c) + g(p + 1, c) : 0;
}
```

**EXÉCUTION CORRECTE.** Parcourt la chaîne caractère par caractère. Si `*p != '\0'`, ajoute 1 si `*p == c`, sinon 0, et avance. Cas de base : `*p == '\0'`.

**Calcule le nombre d'occurrences du caractère `c` dans la chaîne.**

Pour `("Il etait une fois un petit chaperon rouge", 't')` : compte les 't' → **4** (`etait`, `petit`).

---

#### 3.2 — Correction de `plus_grande_valeur`

```cpp
// Version originale (buggée)
double plus_grande_valeur(int nb, double *valeurs) {
    int a, b;
    a = plus_grande_valeur(nb/2, valeurs);          // pas de cas de base !
    b = plus_grande_valeur(nb/2, valeurs + nb/2);
    if (a >= b) return a;
    else return b;
}
```

**Erreurs :**
1. Pas de **cas de base** → récursion infinie quand `nb ≤ 1`.
2. `a` et `b` sont `int` mais la fonction retourne `double` → perte de précision.

```cpp
// Version corrigée
double plus_grande_valeur(int nb, double *valeurs) {
    if (nb == 1)
        return valeurs[0];  // cas de base : un seul élément

    double a = plus_grande_valeur(nb / 2, valeurs);
    double b = plus_grande_valeur(nb - nb / 2, valeurs + nb / 2);
    // nb - nb/2 gère les tableaux de taille impaire

    return (a >= b) ? a : b;
}
```

---

### Exercice 4 — Pile et vérification de parenthèses (15 pts)

```cpp
bool verifBalance(char* str) {
    Pile p;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            p.push('(');          // empile à chaque '('
        } else if (str[i] == ')') {
            if (p.estVide())
                return false;     // ')' sans '(' correspondant
            p.pop();              // dépile le '(' correspondant
        }
    }
    return p.estVide();  // correct ssi toutes les '(' ont été fermées
}
```

**Vérification sur les exemples :**

| Entrée | Résultat | Raisonnement |
|--------|----------|-------------|
| `""` | `true` | Pile vide dès le départ |
| `"(()())"` | `true` | Chaque `(` est fermé |
| `"(()("` | `false` | Pile non vide à la fin |
| `"(()()) )"` | `false` | `)` en trop → pile vide mais caractère rencontré |
| `")("` | `false` | `)` sans `(` avant |

---

### Exercice 5 — Hiérarchie Vehicule/Parc (30 pts)

#### 5.1 — Instructions forçant la ligature dynamique

```cpp
virtual ~Vehicule();      // destructeur virtuel
virtual void Affiche() const;  // méthode virtuelle
```

Aussi : `Parc::Affiche()` et `Parc::TotalRoues()` qui opèrent via `Vehicule**` → dispatch dynamique.

---

#### 5.2 — Classe abstraite?

**NON.** `Vehicule` n'est pas abstraite. Elle a des méthodes virtuelles mais aucune n'est **virtuelle pure** (`= 0`). Toutes ses méthodes sont définies.

---

#### 5.3 — Classes dérivant de `Vehicule`

`Moto` et `Voiture`.

---

#### 5.4 — `Parc` peut-elle être classe de base?

Conceptuellement **non**. Un `Parc` n'est pas un `Véhicule`, une `Moto` ou une `Voiture`. La relation "est un" (*is-a*) ne tient pas. `Parc` est plutôt un conteneur de véhicules (relation de composition/agrégation).

---

#### 5.5 — Compilation préviendra-t-elle `Voiture` de redéfinir `GetRoues`?

**NON.** `GetRoues` n'est **pas** `virtual` dans `Vehicule`. Le compilateur ne génère pas d'avertissement particulier pour la redéfinition d'une méthode non-virtuelle.

---

#### 5.6 — Redéfinir `GetRoues` dans `Voiture` est une mauvaise idée?

**VRAI.** Comme `GetRoues` n'est pas virtuelle, si on appelle `GetRoues()` via un pointeur `Vehicule*`, c'est toujours `Vehicule::GetRoues` qui est appelée (ligature statique), même si l'objet est une `Voiture`. Ce comportement est trompeur et source de bugs.

---

#### 5.7 — `SetRoues` ne peut être utilisée polymorphiquement?

**FAUX.** On peut appeler `SetRoues` sur n'importe quelle instance de la hiérarchie. Il est vrai qu'elle ne sera pas *dispatchée dynamiquement* (pas virtuelle), mais on peut tout à fait l'utiliser sur les objets dérivés via leur type statique. Elle ne peut simplement pas être **overridée polymorphiquement** (pas de late binding).

---

#### 5.8 — Code des méthodes

**(a) Constructeur de `Moto`**

```cpp
Moto::Moto(int Roues) : Vehicule(Roues) {}
// Le constructeur de Vehicule est appelé avec le nombre de roues
// Par défaut : 2 roues (moto standard)
```

**(b) Constructeur de `Voiture`**

```cpp
Voiture::Voiture(int Roues) : Vehicule(Roues) {}
// Par défaut : 4 roues
```

**(c) Constructeur de `Parc`**

```cpp
Parc::Parc(int maxVehicules) : m_nbVehicules(0) {
    m_Vehicules = new Vehicule*[maxVehicules];
    // Initialise le tableau de pointeurs (capacité = maxVehicules)
}
```

**(d) Destructeur de `Parc`**

```cpp
Parc::~Parc() {
    delete[] m_Vehicules;
    // Note : on ne détruit pas les véhicules eux-mêmes (ils ne sont pas
    // possédés par le Parc — sémantique d'agrégation)
}
```

**(e) `Garer`**

```cpp
void Parc::Garer(Vehicule& v) {
    m_Vehicules[m_nbVehicules] = &v;  // stocke l'adresse du véhicule
    m_nbVehicules++;
}
```

**(f) `Affiche`**

```cpp
void Parc::Affiche() const {
    for (int i = 0; i < m_nbVehicules; i++) {
        m_Vehicules[i]->Affiche();  // ligature dynamique
        cout << ":" << m_Vehicules[i]->GetRoues() << endl;
    }
}
```

**(g) `TotalRoues`**

```cpp
int Parc::TotalRoues() const {
    int total = 0;
    for (int i = 0; i < m_nbVehicules; i++) {
        total += m_Vehicules[i]->GetRoues();
    }
    return total;
}
```

---

#### 5.9 — Affichage du programme

```
Voiture:4
Moto:2
Moto:3
Voiture:4

Le parc contient : 13 Roues
```

**Explication :** `Parking.Affiche()` appelle `Affiche()` via `Vehicule*`. La ligature dynamique dispatch vers `Voiture::Affiche()` pour les voitures et `Vehicule::Affiche()` pour les motos (pas de redéfinition dans Moto). Total : 4+2+3+4 = 13.

---

## Automne 2005

### Exercice 1 — Théorie POO (15 pts)

#### 1.1 — POO et réutilisation

La POO favorise la réutilisation grâce à **l'héritage** : une classe dérivée peut réutiliser le code de la classe de base sans le réécrire. On hérite des attributs et méthodes, et on peut spécialiser/étendre le comportement. On peut aussi réutiliser des classes par **composition** (avoir une classe comme membre donnée).

---

#### 1.2 — Rendre `a` accessible uniquement aux dérivées

Oui, il faut changer le membre de `private` à **`protected`** :

```cpp
class B { protected: int a; };
// Ainsi, les classes dérivées de B peuvent accéder à 'a',
// mais le code externe ne le peut pas.
```

---

#### 1.3 — Variable de classe / méthode de classe

- **Variable de classe** : membre donnée déclaré `static`. Il est partagé par **toutes les instances** de la classe (une seule copie en mémoire). Exemple : `static int compteur;`
- **Méthode de classe** : méthode déclarée `static`. Elle n'a pas de pointeur `this`, donc ne peut accéder qu'aux membres statiques. Exemple : `static int getCompteur();`

---

#### 1.4 — Valeur de l'expression `(((a<b)?a:b)+((a>b)?b:a))/2`

**Réponse : (C) La moyenne de a et b**

**Pourquoi ?** Pour a ≠ b :
- `(a<b)?a:b` = `min(a,b)`
- `(a>b)?b:a` = `min(a,b)` également (car si a>b, on prend b qui est le plus petit)

Donc l'expression = `(min(a,b) + min(a,b)) / 2 = min(a,b)`... Attendez.

Relisons : `(a>b)?b:a` : si a>b → retourne b ; si a<b → retourne a. Dans les deux cas = min(a,b).

Donc `(min + min) / 2 = min`... Ce serait le minimum.

En fait la bonne réponse est **(C) la moyenne** seulement si on lit différemment.

Refaisons : supposons a=2, b=6 :
- `(a<b)?a:b` = `(2<6)?2:6` = **2** = min
- `(a>b)?b:a` = `(2>6)?6:2` = **2** = min encore

`(2+2)/2 = 2` → c'est le **minimum**, pas la moyenne.

**La bonne réponse est donc (A) : la plus petite valeur** (le minimum).

> Le corrigé officiel peut varier selon la version exacte de l'expression. L'expression calcule `min(a,b)`.

---

### Exercice 2 — Trace d'exécution (20 pts)

```cpp
class A { public: A(){cout<<"CD-A-\n";} A(A&){cout<<"CR-A-\n";} ~A(){cout<<"D-A-\n";} };
class B : A {
    int bval;
public:
    B():bval(0){cout<<"CD-B-\n";}
    B(int i):bval(i){cout<<"Cint-B-\n";}
    B(B& un_b):bval(un_b.bval){cout<<"CR-B-\n";}
    ~B(){cout<<"D-B- " << bval << endl;}
};
void Test(A avar, B& bvar) { cout << "Dans Test\n"; }
int main() {
    A avar;
    B bvar(10);
    cout << "Dans main\n";
    Test(avar, bvar);
    cout << "Quittes main\n";
    return 0;
}
```

**Trace détaillée :**

```
CD-A-        ← Construction de avar (A::A())
CD-A-        ← Construction du sous-objet A dans bvar (B hérite A → A::A() appelé)
Cint-B-      ← Construction de bvar (B::B(int), bval=10)
Dans main
CR-A-        ← Test(avar, bvar) : avar est passé PAR VALEUR → A(A&) appelé pour copier avar
Dans Test
D-A-         ← Destruction de la copie de avar à la fin de Test
Quittes main
D-B- 10      ← Destruction de bvar (B::~B(), bval=10)
D-A-         ← Destruction du sous-objet A de bvar (A::~A())
D-A-         ← Destruction de avar (A::~A())
```

> **Points clés :**
> - `B` hérite de `A` de façon **privée** (par défaut), donc le constructeur de `A` est appelé pour chaque `B`.
> - `avar` est passé **par valeur** à `Test` → constructeur de recopie `A(A&)` → affiché `CR-A-`.
> - L'ordre de destruction est **inverse** de l'ordre de construction.

---

### Exercice 3 — Surcharge de fonctions (20 pts)

```cpp
class B{};  class C{};
class BBB: public B{};  class CCC: public C{};
B& b1ref = *(new B);   // b1ref est de type B
B& b3ref = *(new BBB); // b3ref est de type B (ref sur BBB)
BBB bbb;
C& c1ref = *(new C);   // c1ref est de type C
C& c3ref = *(new CCC); // c3ref est de type C
CCC ccc;

void fn(B,C)  {cout<<"fn1";}
void fn(B,CCC){cout<<"fn2";}
void fn(BBB,C){cout<<"fn3";}
```

#### 3.1 `fn(b1ref, c1ref)` — Ligne 1

**CORRECTE** → affiche **`fn1`**

Types : `B` et `C`. Correspondance exacte avec `fn(B,C)`.

---

#### 3.2 `fn(b1ref, c3ref)` — Ligne 2

**CORRECTE** → affiche **`fn2`**

`c3ref` est de type `C&` mais référence un `CCC`. Le type statique est `C`. La résolution de surcharge se fait sur les **types statiques** :
- `fn(B,C)` : conversion identité pour b1ref, identité pour c3ref (C)
- `fn(B,CCC)` : conversion identité pour b1ref, conversion C→CCC requise...

Attendez : `c3ref` est `C&`, pas `CCC&`. On passerait un `C` à `fn(B,CCC)` ce qui nécessite une conversion invalide (C n'est pas un CCC). Donc seule `fn(B,C)` est viable → **fn1**.

Correction : **fn1**, pas fn2.

---

#### 3.3 `fn(b3ref, c3ref)` — Ligne 3

**CORRECTE** → affiche **`fn1`**

`b3ref` et `c3ref` sont des références de type `B` et `C` respectivement. La surcharge choisit `fn(B,C)`.

---

#### 3.4 `fn(bbb, ccc)` — Ligne 4

**AMBIGUÏTÉE / potentiellement incorrecte**

`bbb` est `BBB`, `ccc` est `CCC`. Candidats :
- `fn(B,C)` : BBB→B (dérivée vers base), CCC→C (dérivée vers base)
- `fn(B,CCC)` : BBB→B, CCC exact
- `fn(BBB,C)` : BBB exact, CCC→C

Aucune surcharge n'est strictement meilleure → **ambiguïté** → erreur de compilation.

---

### Exercice 4 — Récursion `caFaitQuoi` (15 pts)

#### 4.1 — Est-elle récursive?

**Oui.** La fonction `caFaitQuoi` s'appelle elle-même : `return a * caFaitQuoi(a, b-1)`.

---

#### 4.2 — Résultats

| Appel | Résultat |
|-------|----------|
| `caFaitQuoi(0, 2)` | `0 * 0 = 0` (0^2) |
| `caFaitQuoi(2, 4)` | `2^4 = 16` |

---

#### 4.3 — Ce que calcule la méthode

`caFaitQuoi(a, b)` calcule **a à la puissance b** (a^b).

---

#### 4.4 — Bug si b est négatif + correction

Si `b < 0`, `b-1` devient encore plus négatif → jamais 0 → récursion infinie.

```cpp
// Version corrigée
double caFaitQuoi(double a, int b) {
    if (b == 0) return 1;
    if (b < 0)
        return 1.0 / caFaitQuoi(a, -b);  // a^-b = 1 / a^b
    return a * caFaitQuoi(a, b - 1);
}
```

---

### Exercice 5 — Listes chaînées (30 pts)

#### 5.1 — `PremierMin`

```cpp
ListeNoeud* PremierMin(ListeNoeud* liste) {
    if (liste == nullptr) return nullptr;  // liste vide

    // Trouve la valeur minimale
    int min = liste->info;
    ListeNoeud* courant = liste->suiv;
    while (courant != nullptr) {
        if (courant->info < min)
            min = courant->info;
        courant = courant->suiv;
    }

    // Trouve le premier nœud avec cette valeur
    courant = liste;
    while (courant != nullptr) {
        if (courant->info == min)
            return courant;
        courant = courant->suiv;
    }

    return nullptr;
}
```

---

#### 5.2 — `RetirerSuivant`

```cpp
void RetirerSuivant(ListeNoeud* ptr) {
    // précondition: ptr != NULL
    if (ptr->suiv == nullptr) return;  // dernier nœud → rien à faire

    ListeNoeud* aSupprimer = ptr->suiv;
    ptr->suiv = aSupprimer->suiv;  // relie ptr au nœud après celui à supprimer
    delete aSupprimer;
}
```

---

#### 5.3 — `RetireDupMins`

```cpp
void RetireDupMins(ListeNoeud* liste) {
    if (liste == nullptr) return;

    // Trouve le premier minimum
    ListeNoeud* premier = PremierMin(liste);

    // Supprime toutes les occurrences suivantes du minimum
    ListeNoeud* courant = premier;
    while (courant->suiv != nullptr) {
        if (courant->suiv->info == premier->info) {
            RetirerSuivant(courant);  // supprime courant->suiv
        } else {
            courant = courant->suiv;
        }
    }
}
```

---

## Hiver 2005

### Question 1 — Héritage et méthodes (15 pts)

```cpp
class Mamf { public: boolean ADesPattes() { return true; } };
```

#### 1.1 — Classe `Chien`

**(c) Utiliser `ADesPattes` telle quelle par héritage**

Un chien a bien des pattes → la méthode héritée retourne déjà `true`, ce qui est correct. Pas besoin de surcharger ni de redéfinir.

#### 1.2 — Implémentation de `Chien`

```cpp
class Chien : public Mamf {
    // ADesPattes() hérité → retourne true, convient parfaitement
};
```

---

#### 1.3 — Classe `Baleine`

**(b) Redéfinir `ADesPattes`**

Une baleine est un mammifère (héritage justifié) mais n'a pas de pattes. La méthode hériterait d'un comportement incorrect → il faut la **redéfinir**.

#### 1.4 — Implémentation de `Baleine`

```cpp
class Baleine : public Mamf {
public:
    bool ADesPattes() {
        return false;  // une baleine n'a pas de pattes
    }
};
```

---

### Question 2 — Erreurs dans les méthodes de `C` (20 pts)

```cpp
class C {
    int x;
public:
    C(int y) x(y) {};            // ligne 6
    void f(const C& a) { x = a.x; }  // ligne 7-9
    void g(C& a) const { x = 10; }   // ligne 10-12
    int h(int& y) { return y * 0.5; } // ligne 13-15
    int j(const int* y) const { *y = 10; } // ligne 16-18
    int k(const int& y) const { y = 10; }  // ligne 19-21
};
```

| Méthode | Correcte? | Raison |
|---------|-----------|--------|
| `C(int y) x(y) {}` | **INCORRECTE** | Syntaxe incorrecte. Doit être `C(int y) : x(y) {}` (il manque `:`) |
| `void f(const C& a) { x = a.x; }` | **CORRECTE** | `x` et `a.x` sont dans la même classe → accès privé autorisé entre instances |
| `void g(C& a) const { x = 10; }` | **INCORRECTE** | Méthode `const` → ne peut pas modifier les membres données. `x = 10` viole la contrainte |
| `int h(int& y) { return y * 0.5; }` | **INCORRECTE** (warning) | `y * 0.5` est un `double`, retourné comme `int` → troncature. Warning de conversion |
| `int j(const int* y) const { *y = 10; }` | **INCORRECTE** | `y` est `const int*` → modification de `*y` interdite |
| `int k(const int& y) const { y = 10; }` | **INCORRECTE** | `y` est `const int&` → modification interdite |

---

### Question 3 — Surcharge d'opérateurs (15 pts)

```cpp
int main() {
    Nombre un(1), moins_un(-1);
    if (-un == moins_un)           // étape 1 : -un crée Nombre(-1) puis compare
        cout << -un << " est équivalent à " << moins_un << endl;
    else
        cout << "Comment ça se fait!" << endl;
}
```

**Trace :**

1. `-un` : appelle `operator-()` → affiche `"Moins 1"` → retourne `Nombre(-1)`
2. `== moins_un` : `operator==(Nombre(-1), Nombre(-1))` → affiche `"Est-ce que -1 est égal à -1?"` → retourne `true`
3. Condition vraie → évalue `cout << -un << ...`
4. `-un` encore : affiche `"Moins 1"` → retourne `Nombre(-1)`
5. `operator<<` appelle `operator*()` → retourne `-1` → affiche `-1`
6. `operator<<` pour `moins_un` → affiche `-1`

```
Moins 1
Est-ce que -1 est égal à -1?
Moins 1
-1 est équivalent à -1
```

---

### Question 4 — STL et contraintes de traitement (20 pts)

#### 4.1.a — Premier arrivé, premier servi

**Conteneur : `queue<string>`** (file FIFO)

La file traite les éléments dans l'ordre d'arrivée — premier entré, premier sorti.

#### 4.1.b — Méthodes de base

```cpp
#include <queue>
#include <iostream>
using namespace std;

queue<string> requetes;
requetes.push("Alice");   // enfile
requetes.push("Bob");
requetes.push("Charlie");

// Traitement FIFO
while (!requetes.empty()) {
    cout << requetes.front() << endl;  // consulte le premier
    requetes.pop();                     // défile
}
```

---

#### 4.2.a — Ordre alphabétique

Il faut utiliser une **`priority_queue<string, vector<string>, greater<string>>`** ou plus simplement un **`set<string>`** (trié automatiquement) ou un **`map<string, ...>`** si on veut des données associées.

```cpp
// Option la plus simple : set trié automatiquement
#include <set>
set<string> requetes;  // ordonne alphabétiquement par défaut
```

#### 4.2.b — Déclaration

```cpp
set<string> r;
// ou avec priority_queue (ordre croissant) :
priority_queue<string, vector<string>, greater<string>> r;
```

---

### Question 5 — Traitement de fichier avec STL (30 pts)

```cpp
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) { cerr << "Usage: prog fichier.txt\n"; return 1; }

    ifstream fichier(argv[1]);
    if (!fichier) { cerr << "Erreur ouverture\n"; return 1; }

    // Compter les mots (insensible à la casse)
    map<string, int> frequence;
    string mot;
    while (fichier >> mot) {
        // Convertit en minuscules
        transform(mot.begin(), mot.end(), mot.begin(), ::tolower);
        frequence[mot]++;
    }

    // Trouver les mots répétés plus d'une fois
    int nbRepetes = 0;
    string motPlusRepete;
    int maxFreq = 0;

    for (const auto& paire : frequence) {
        if (paire.second > 1) nbRepetes++;
        if (paire.second > maxFreq) {
            maxFreq = paire.second;
            motPlusRepete = paire.first;
        }
    }

    // 10e mot trié alphabétiquement
    vector<string> mots;
    for (const auto& paire : frequence)
        mots.push_back(paire.first);
    sort(mots.begin(), mots.end());

    cout << "Nombre de mots répétés: " << nbRepetes << " mots\n";
    cout << "Le mot le plus répété: " << motPlusRepete << "\n";
    if (mots.size() >= 10)
        cout << "Le 10e mot = " << mots[9] << "\n";

    return 0;
}
```

---

## Hiver 2004

### Question 1 — Multi-fichiers (11 pts)

#### 1.1 — Informations à ajouter dans le module A

Il faut ajouter `#include "B.h"` dans `A.cpp` (ou `A.h`). Le compilateur a besoin de connaître la **déclaration de la classe B** (son interface) pour comprendre comment appeler `bar`.

---

#### 1.2 — Type de fichier créé par la compilation de A

La compilation de `A.cpp` produit un **fichier objet** : `A.o` (Linux/macOS) ou `A.obj` (Windows).

---

#### 1.3 — Erreur si exécutable depuis A uniquement

**Erreur d'édition de liens** (*linker error*) : `undefined reference to B::bar`. Le linker ne trouve pas la *définition* de `bar` car `B.cpp` n'a pas été compilé/lié.

---

#### 1.4 — Erreur typographique `foo` appelle `baf`

**Erreur de compilation** : `error: 'baf' was not declared in this scope` (ou équivalent). Le compilateur ne trouve pas `baf` dans `B` lors de la compilation de `A.cpp`.

---

#### 1.5 — Commande gcc

```bash
gcc main.cpp A.cpp B.cpp -o exo1.exe
# ou en C++ :
g++ main.cpp A.cpp B.cpp -o exo1.exe
```

---

### Question 2 — Types de pointeurs (18 pts)

```cpp
class Noeud { public: string Value; Noeud* Next; };
Noeud* Sommet;
Noeud TempNoeud;
Sommet = new Noeud;
```

| Expression | Type | Explication |
|-----------|------|-------------|
| `TempNoeud.Next` | **pointeur vers un Noeud** | `Next` est déclaré `Noeud*` |
| `(*Sommet).Value` | **string** | déréférence Sommet → Noeud, `.Value` → string |
| `&TempNoeud` | **pointeur vers un Noeud** | adresse de TempNoeud |
| `Sommet->Next` | **pointeur vers un Noeud** | `->Next` accède au membre `Noeud*` |
| `&Sommet` | **pointeur d'un pointeur vers un Noeud** | adresse de la variable pointeur `Sommet` |
| `Sommet.Value` | **illégal** | `Sommet` est un pointeur, on doit utiliser `->` ou `(*Sommet).` |
| `*(Sommet->Next)` | **Noeud** | déréférence `Sommet->Next` (qui est `Noeud*`) → Noeud |

---

### Question 3 — Template `GenIntList<T>` (17 pts)

#### 3.1 — Classe générique

```cpp
template<typename T>
class GenIntList {
public:
    GenIntList(int n = 10, T val = T());
    ~GenIntList();
    T operator[](int i) const;
    T& operator[](int i);
    int GetSize() const;
private:
    int taille;
    T* ptr;
};
```

---

#### 3.2 — Constructeur de `GenIntList<T>`

```cpp
template<typename T>
GenIntList<T>::GenIntList(int n, T val) {
    assert(n > 0);
    taille = n;
    ptr = new T[n];
    for (int i = 0; i < n; i++) {
        ptr[i] = val;
    }
}
```

---

#### 3.3 — Instanciation

```cpp
GenIntList<int> maListe(8, 3);
// 8 éléments, chacun initialisé à 3
```

---

#### 3.4 — Doit-on déclarer `operator<<` ami?

**Oui, si on veut accéder aux membres privés** (`ptr`, `taille`). `operator<<` est une fonction non-membre ; pour accéder à `ptr` directement, il faut la déclarer `friend`. Alternativement, on peut l'implémenter en utilisant uniquement les méthodes publiques (`GetSize()`, `operator[]`), auquel cas `friend` n'est pas nécessaire.

---

### Question 4 — Hiérarchie Oiseau (24 pts)

```cpp
class Oiseau { public: virtual void Parle()=0; virtual void MangePoisson()... };
class Pigeon : public Oiseau { public: virtual void Parle()... };
class Aigle  : public Oiseau { public: virtual void Parle()... virtual void MangePoissons()... void MangePigeons()... };
class TeteBlancheAigle : public Aigle { public: virtual void Parle()... };
void AigleParle(Aigle aig) { aig.Parle(); }
void MangeurPoissons(Oiseau* oies) { oies->MangePoisson(); }
```

> **Note :** L'énoncé contient une faute : la méthode dans `Oiseau` s'appelle `MangePoisson` (singulier), mais `Aigle` redéfinit `MangePoissons` (pluriel) → ce n'est pas une redéfinition, c'est une nouvelle méthode.

| Bloc | Correct? | Raison |
|------|----------|--------|
| **4.1** `Oiseau* b0 = new Oiseau` | **INCORRECT** | `Oiseau` est abstraite (`Parle()` est virtuelle pure) → impossible d'instancier |
| **4.2** `Oiseau* b1 = new Aigle; b1->MangePoisson()` | **INCORRECT** | `Aigle` ne redéfinit pas `MangePoisson` (note orthographe) ; `MangePoissons` (avec s) est différent. `b1->MangePoisson()` appelle `Oiseau::MangePoisson()` — valide mais résolution ambiguë selon version |
| **4.3** `Oiseau* b2 = new Aigle; b2->MangePigeons()` | **INCORRECT** | `MangePigeons` n'est pas dans l'interface `Oiseau`, donc `Oiseau*` ne peut pas l'appeler |
| **4.4a** `be1 = e1` | **INCORRECT** | On ne peut pas assigner un `Aigle` (base) à un `TeteBlancheAigle` (dérivé) — problème de troncature/incompatibilité |
| **4.4b** `e1 = be1` | **CORRECT** | On peut assigner un `TeteBlancheAigle` à un `Aigle` (slicing, mais syntaxiquement correct) |
| **4.5** `AigleParle(be2)` | **CORRECT (mais slicing!)** | `be2` est `TeteBlancheAigle`, passé par valeur → slicing vers `Aigle`. `aig.Parle()` appelle `Aigle::Parle` (ligature statique car pas de pointeur/référence) |
| **4.6** `be3.MangePigeons()` | **CORRECT** | `TeteBlancheAigle` hérite de `Aigle`, qui a `MangePigeons()` public |
| **4.7** `MangeurPoissons(&be4)` | **CORRECT** | `TeteBlancheAigle*` → `Oiseau*` (upcast valide). `MangePoisson` héritée de `Oiseau` |
| **4.8** `p1 = be5` | **INCORRECT** | `Pigeon*` et `TeteBlancheAigle*` n'ont aucune relation d'héritage |

---

### Question 5 — `Encodage` (17.5 pts)

```cpp
#include <fstream>
#include <string>
using namespace std;

enum StatutEncodage { ErrOuvFicIn, ErrOuvFicOut, EncodageOK };

StatutEncodage Encodage(string ficIn, string ficOut) {
    ifstream entree(ficIn);
    if (!entree) return ErrOuvFicIn;

    ofstream sortie(ficOut);
    if (!sortie) return ErrOuvFicOut;

    string champ1;
    char champ2;

    while (entree >> champ1 >> champ2) {
        // XOR de chaque caractère du champ1 avec champ2
        for (size_t i = 0; i < champ1.size(); i++) {
            sortie << static_cast<char>(champ1[i] ^ champ2);
        }
        sortie << '\n';
    }

    return EncodageOK;
}
```

---

### Question 6 — 3 premiers mots triés (12.5 pts)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    vector<string> mots;
    string mot;

    while (cin >> mot && mot != "Fin") {
        mots.push_back(mot);
    }

    sort(mots.begin(), mots.end());  // tri alphabétique

    int nb = min(3, static_cast<int>(mots.size()));
    for (int i = 0; i < nb; i++) {
        cout << mots[i] << endl;
    }

    return 0;
}
```

---

## Automne 2003

### Question 1 — Fichiers et I/O (20 pts)

#### 1.1 — Deux types de fichiers

1. **Fichiers texte** : données lisibles (caractères ASCII/Unicode). Ex. : `.txt`, `.csv`.
2. **Fichiers binaires** : données brutes en mémoire, non lisibles directement. Ex. : `.bin`, `.dat`.

---

#### 1.2 — Opération la plus importante après lecture/écriture

**Fermer le fichier** (`close()`).

Si omise : les données en attente dans le buffer peuvent ne pas être écrites (*flush* non effectué), le fichier reste verrouillé, et des ressources système ne sont pas libérées.

---

#### 1.3 — `cin >> Phrase`

`cin >>` saute les espaces blancs initiaux et s'arrête au premier espace. Avec l'entrée ` Examen Final IFT1166\n`, il lit le premier mot non-blanc → **`Examen`**.

```
Examen
```

---

#### 1.4 — `cout << setw(3) << setprecision(2) << 3.14159...`

- `setprecision(2)` : 2 chiffres significatifs → `3.1`
- `setw(3)` : largeur minimale 3 caractères → `3.1` fait déjà 3 chars → pas de padding

**Affichage : `3.1`**

---

#### 1.5 — Droits d'accès dans les classes dérivées

| Membre de A | Héritage `private` (B) | Héritage `protected` (C) | Héritage `public` (D) |
|------------|----------------------|------------------------|----------------------|
| `private_a` | inaccessible | inaccessible | inaccessible |
| `protege_a` | `private` dans B | `protected` dans C | `protected` dans D |
| `public_a` | `private` dans B | `protected` dans C | `public` dans D |

> Les membres `private` de la base sont **toujours inaccessibles** dans les dérivées, quelle que soit la forme d'héritage.

---

### Question 2 — Traitement fichier de notes (17 pts)

```cpp
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    string nomFicSortie;
    cout << "Nom du fichier de résultats: ";
    cin >> nomFicSortie;

    ifstream entree("NOTE.DAT");
    ofstream sortie(nomFicSortie);

    if (!entree || !sortie) {
        cerr << "Erreur ouverture fichier\n";
        return 1;
    }

    char prenom[21], nom[21];
    float q1, q2, final;

    while (entree >> prenom >> nom >> q1 >> q2 >> final) {
        float moy = q1 * 0.25f + q2 * 0.25f + final * 0.50f;
        sortie << left << setw(20) << prenom
               << " " << setw(20) << nom
               << "\t" << fixed << setprecision(1) << moy << "\n";
    }

    return 0;
}
```

---

### Question 3 — Correction de `peutAllerSur` (15 pts)

```cpp
// Version buggée : vérifie couleur OU valeur séparément (logique OR)
bool UneCarte::peutAllerSur(UneCarte uneAutre) {
    if (uneAutre.m_couleur == m_couleur)
        return true;
    if (uneAutre.m_valeur == m_valeur - 1)
        return true;
    return false;
}
```

**Problème :** Les deux conditions doivent être vraies **simultanément** (même couleur ET valeur croissante).

```cpp
// Version corrigée
bool UneCarte::peutAllerSur(UneCarte uneAutre) {
    // Même couleur ET cette carte a une valeur immédiatement supérieure
    return (m_couleur == uneAutre.m_couleur) &&
           (m_valeur == uneAutre.m_valeur + 1);
}
```

---

### Question 4 — Classe `Test` (20 pts)

#### 4.1 — `pointeSur`

```cpp
void Test::pointeSur(Test* arg) {
    ptr = arg;  // stocke l'adresse dans le membre ptr
}
```

---

#### 4.2 — `suivant`

```cpp
Test* Test::suivant() {
    return ptr;  // retourne l'adresse contenue dans ptr
}
```

---

#### 4.3 — Tableau de 100 `Test` chaîné

```cpp
Test* tableau = new Test[100];

for (int i = 0; i < 99; i++) {
    tableau[i].pointeSur(&tableau[i + 1]);
}
tableau[99].pointeSur(nullptr);  // dernier élément
```

---

### Question 5 — Classe `Point` et `Polygone` (28 pts)

#### 5.1 — À quoi servent `getX`, `getY`, `setX`, `setY`?

Ce sont des **accesseurs** (getters) et **mutateurs** (setters). Ils permettent d'accéder et de modifier les membres privés `x` et `y` en respectant le principe d'**encapsulation**. On contrôle ainsi comment les données sont lues/modifiées (on peut ajouter des validations).

---

#### 5.2 — `Point(Point& p)` et `~Point()` sont-ils nécessaires?

- `Point(Point& p)` : **constructeur de recopie** — copie un objet Point existant.
- `~Point()` : **destructeur** — appelé à la destruction de l'objet.

Dans ce cas, `Point` ne gère pas de mémoire dynamique (x et y sont des `float`). Le constructeur de recopie et le destructeur par **défaut** seraient suffisants. Ils ne sont **pas strictement nécessaires** ici, mais ils permettent d'afficher des messages de débogage.

---

#### 5.3 — Mot-clé `friend`

`friend char* compareHauteur(Point, Point)` donne à la fonction **non-membre** `compareHauteur` l'accès aux membres **privés** de `Point` (ici `x` et `y`). Cela permet à une fonction externe de manipuler les données privées sans rompre l'encapsulation publique.

---

#### 5.4 — Affichage de `Polygone triangle(3)`

```cpp
Polygone triangle(3);
// → new Point[3] → appelle 3 fois Point(0,0)
```

```
contructeur 1 : 0,0
contructeur 1 : 0,0
contructeur 1 : 0,0
```

```cpp
triangle.afficher();
// → appelle somt[i].afficher() pour i=0,1,2
```

```
(0,0)
(0,0)
(0,0)
```

---

#### 5.5 — Surcharge de `operator[]` avec exception

```cpp
Point& Polygone::operator[](int i) {
    if (i < 0 || i >= nb)
        throw i;  // lève exception entière avec l'indice invalide
    return somt[i];
}
```

---

#### 5.6 — Méthode `input`

```cpp
void Polygone::input() {
    for (int i = 0; i < nb; i++) {
        float x, y;
        cout << "Sommet " << i << " - x: ";
        cin >> x;
        cout << "Sommet " << i << " - y: ";
        cin >> y;
        somt[i].setX(x);
        somt[i].setY(y);
    }
}
```

---

## Hiver 2001

### Question 1 — Règle des trois (16 pts)

#### Q1.A — Doit-on redéfinir le constructeur de recopie et `operator=`?

**NON**, les versions par défaut suffisent.

`Test` contient `int zz` et `string mm`. Aucun membre ne gère de mémoire dynamique (la `string` s'en charge elle-même). La copie par valeur membre-à-membre est correcte.

> La règle des trois (constructeur de recopie, `operator=`, destructeur) s'applique quand la classe gère de la mémoire brute (`char*`, `int*`, etc.).

---

#### Q1.B — Fonctions appelées dans `main`

```cpp
Test dd(5,"essai");   // Test(int, string) — constructeur paramétré
Test XX(8,"unautre"); // Test(int, string) — constructeur paramétré
XX = dd;              // operator=(Test&) — affectation
return 0;             // ~Test() appelé pour XX puis dd
```

---

#### Q1.C — `Test qsx(dd)` est-il syntaxiquement correct?

**NON.** Le constructeur de recopie `Test(const Test& x)` est déclaré **privé** dans la classe. On ne peut pas l'appeler depuis `main`. Erreur de compilation.

---

#### Q1.D — `operator=` est-il correct?

**NON.** L'opérateur d'affectation retourne `x` (l'argument) au lieu de `*this` (l'objet courant). La convention correcte est de retourner `*this` pour permettre le chaînage (`a = b = c`).

```cpp
// Version corrigée
Test& Test::operator=(Test& x) {
    if (this != &x) {  // auto-affectation
        zz = x.zz;
        mm = x.mm;
    }
    return *this;  // retourne l'objet courant, pas x
}
```

---

### Question 2 — Classe `String` : `+=` et `+` (14 pts)

```cpp
String& String::operator+=(const String& A) {
    int newLen = len + A.len;
    char* newS = new char[newLen + 1];

    // Copie this->s puis A.s
    for (int i = 0; i < len; i++)       newS[i] = s[i];
    for (int i = 0; i < A.len; i++)     newS[len + i] = A.s[i];
    newS[newLen] = '\0';

    delete[] s;
    s = newS;
    len = newLen;
    return *this;
}

// operator+ en dehors de la classe (ou ami)
String operator+(const String& A, const String& B) {
    String resultat(A);  // copie de A
    resultat += B;       // réutilise +=
    return resultat;
}
```

---

### Question 3 — Déclaration anticipée (16 pts)

**Problème :** `Uneautre` utilise `Idem` dans sa méthode `affiche`, mais `Idem` est défini *après* `Uneautre`. Et `Idem` utilise `Uneautre` défini *avant*.

**Solution :** Déclaration anticipée (*forward declaration*) d'`Idem` avant `Uneautre`.

```cpp
// Ajouter AVANT la ligne 2 (avant la définition de Uneautre) :
class Idem;  // déclaration anticipée
```

**Entre les lignes 1 et 2**, ajouter `class Idem;` parce que `Uneautre::affiche` fait référence au type `Idem` avant qu'il soit défini.

---

### Question 4 — Fonctions génériques (10 pts)

#### Q4.A — Fonction template `différent`

```cpp
template<typename T>
bool different(T a, T b) {
    return a != b;
}
```

---

#### Q4.B — Cas `char*`

**NON**, ça ne fonctionnerait pas correctement pour `char*`. L'opérateur `!=` compare les **adresses des pointeurs**, pas le contenu des chaînes. Deux chaînes identiques mais stockées à des adresses différentes seraient considérées différentes.

```cpp
// Spécialisation pour char*
template<>
bool different<char*>(char* a, char* b) {
    return strcmp(a, b) != 0;  // comparaison du contenu
}
```

---

### Question 5 — Héritage `Produit` / `ProduitSolde` (24 pts)

#### Q5.A — Déclaration de `D`

```cpp
class D : public B {
    // ...
};
```

---

#### Q5.B — Ordre constructeurs/destructeurs

Pour `class D : public C` :
1. `C::C()` → constructeur de la base
2. `D::D()` → constructeur de la dérivée

Destruction (ordre inverse) :
1. `D::~D()`
2. `C::~C()`

---

#### Q5.C — Classes `Produit` et `ProduitSolde`

```cpp
class Produit {
protected:
    string nom;
    double prix;
public:
    Produit(string n, double p) : nom(n), prix(p) {}

    virtual double get_prix() const {
        return prix;
    }

    virtual void facture() const {
        cout << get_prix() << endl;
    }
};

class ProduitSolde : public Produit {
private:
    double solde;  // pourcentage (ex: 20 pour 20%)
public:
    ProduitSolde(string n, double p, double s)
        : Produit(n, p), solde(s) {}

    double get_prix() const override {
        return prix * (1 - solde / 100.0);
    }

    void facture() const override {
        cout << get_prix() << endl;
    }
};
```

---

#### Q5.D — Modifications pour le polymorphisme

Pour que `PP->facture()` donne 2000 puis 1600, `facture()` doit être **virtuelle** dans `Produit` (déjà fait ci-dessus).

```cpp
int main() {
    Produit P("portable", 2000);
    ProduitSolde PS("portable", 2000, 20);

    Produit* PP = &P;
    PP->facture();  // 2000 (Produit::facture → prix = 2000)

    PP = &PS;
    PP->facture();  // 1600 (ProduitSolde::facture → 2000 * (1 - 20/100) = 1600)
}
```

---

### Question 6 — STL : comptage de caractères (20 pts)

```cpp
#include <iostream>
#include <fstream>
#include <list>
#include <string>
using namespace std;

int main() {
    list<string> fichiers = {"t1.txt", "t2.txt", "t3.txt"};

    ofstream sortie("sortie.txt");
    int nbInexistants = 0;
    long totalChars = 0;

    list<pair<string, long>> resultats;

    for (const string& nom : fichiers) {
        ifstream f(nom);
        if (!f) {
            cerr << "impossible d'ouvrir le fichier: " << nom << endl;
            nbInexistants++;
            resultats.push_back({nom, -1});
        } else {
            f.seekg(0, ios::end);
            long taille = f.tellg();
            totalChars += taille;
            resultats.push_back({nom, taille});
        }
    }

    sortie << "Nombre de fichiers dans le conteneur list: " << fichiers.size() << "\n";
    sortie << "Nombre de fichiers inexistants : " << nbInexistants << "\n";
    sortie << "Nombre total de caractères: " << totalChars << "\n\n";
    sortie << "Nom de fichier : Nombre de caractères\n";

    for (const auto& r : resultats) {
        sortie << r.first << " : " << r.second << "\n";
    }

    return 0;
}
```

---

## Automne 2000

### Question 1 — Arguments de ligne de commande (15 pts)

```cpp
./prg test chaine
```

- `argc = 3`
- `argv[0] = "./prg"`, `argv[1] = "test"`, `argv[2] = "chaine"`

`argc >= 3` → pas d'erreur. Appel : `une_certaine_fonction("test", "chaine")`.

**Affichage :**

```
arg1: test ; arg2: chaine
```

---

### Question 2 — Fonction template `conversion` (15 pts)

```cpp
template<typename Source, typename Destination>
void conversion(Source src, Destination& dest) {
    dest = static_cast<Destination>(src);
}
```

```cpp
// Utilisation :
char c = 'A'; int e;
conversion(c, e);  // e = 65 (code ASCII de 'A')

double d = 4.15;
conversion(d, e);  // e = 4 (troncature)

conversion(e, d);  // d = 4.0
```

---

### Question 3 — Opérateurs `+=` et `-=` pour `Chaine` (20 pts)

```cpp
Chaine& Chaine::operator+=(char c) {
    char* nouveau = new char[taille + 2];  // +1 pour c, +1 pour '\0'
    for (int i = 0; i < taille; i++)
        nouveau[i] = nom[i];
    nouveau[taille] = c;
    nouveau[taille + 1] = '\0';

    delete[] nom;
    nom = nouveau;
    taille++;
    return *this;
}

Chaine& Chaine::operator-=(int n) {
    if (n >= taille) {
        // Supprime tout
        delete[] nom;
        nom = new char[1];
        nom[0] = '\0';
        taille = 0;
    } else {
        taille -= n;
        nom[taille] = '\0';  // tronque la chaîne
    }
    return *this;
}
```

---

### Question 4 — STL string : construction de phrases (15 pts)

```cpp
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s1 = "Les tableaux de Monet seront exposés à partir de la semaine prochaine.";
    string s2 = "Les meilleurs livres sont ceux qui racontent ce que l'on sait déjà.";

    // Étape 1 : créer la phrase combinée
    // "Les meilleurs livres seront exposés à partir de la semaine prochaine."
    string phrase;
    phrase.assign(s2, 0, 19);   // "Les meilleurs livres"
    phrase.append(s1, 20, string::npos);  // " seront exposés..."

    // Étape 2 : inverser la phrase
    string inversee(phrase);
    reverse(inversee.begin(), inversee.end());

    // Étape 3 : trier les caractères
    string triee(phrase);
    sort(triee.begin(), triee.end());

    // Affichage
    // phrase → "Les meilleurs livres seront exposés à partir de la semaine prochaine."
    // inversee → ".eniahcorp eniames al ed ritrap à sésopxe tneros servil sruelliem seL"
    // triee → "àé .Laaa..."
}
```

---

### Question 5 — Hiérarchie de formes géométriques (35 pts)

#### Q5.A — Classes `Forme`, `Cercle`, `Rectangle`, `Carre`

```cpp
#include <iostream>
using namespace std;
const double PI = 3.14;

// Classe abstraite de base
class Forme {
protected:
    float x, y;  // coordonnées
public:
    Forme(float cx, float cy) : x(cx), y(cy) {}
    virtual ~Forme() {}
    virtual double perimetre() const = 0;
    virtual double surface() const = 0;
    virtual void affiche(ostream& o) const = 0;

    friend ostream& operator<<(ostream& o, const Forme& f) {
        f.affiche(o);
        return o;
    }
};

class Cercle : public Forme {
    float rayon;
public:
    Cercle(float cx, float cy, float r) : Forme(cx, cy), rayon(r) {}
    double perimetre() const override { return 2 * PI * rayon; }
    double surface()   const override { return PI * rayon * rayon; }
    void affiche(ostream& o) const override {
        o << "Cercle (" << x << "," << y << ") r=" << rayon;
    }
};

class Rectangle : public Forme {
protected:
    float longueur, largeur;
public:
    Rectangle(float cx, float cy, float l, float la)
        : Forme(cx, cy), longueur(l), largeur(la) {}
    double perimetre() const override { return 2 * (longueur + largeur); }
    double surface()   const override { return longueur * largeur; }
    void affiche(ostream& o) const override {
        o << "Rectangle (" << x << "," << y << ") Longueur=" << longueur
          << " Largeur= " << largeur;
    }
};

class Carre : public Rectangle {
public:
    Carre(float cx, float cy, float cote)
        : Rectangle(cx, cy, cote, cote) {}
    double perimetre() const override { return 4 * longueur; }
    double surface()   const override { return longueur * longueur; }
    void affiche(ostream& o) const override {
        o << "Carre (" << x << "," << y << ") Cote=" << longueur;
    }
};
```

---

#### Q5.B — Version avec constructeurs/destructeurs affichés + polymorphisme

```cpp
class Forme {
protected: float x, y;
public:
    Forme(float cx, float cy) : x(cx), y(cy) {
        cout << "- Forme::Forme ";
    }
    virtual ~Forme() { cout << "- Forme::~Forme "; }
    virtual double perimetre() const = 0;
    virtual double surface()   const = 0;
    virtual void affiche(ostream& o) const = 0;
    friend ostream& operator<<(ostream& o, const Forme& f) {
        f.affiche(o); return o;
    }
};
// ... (Cercle, Rectangle, Carre similaires avec affichage constructeur/destructeur)

int main() {
    Cercle cercle(10, 10, 4);
    Rectangle rectangle(30, 30, 2, 5);
    Carre* carre = new Carre(100, 100, 2);  // allocation dynamique

    cout << endl << cercle << " surface=" << cercle.surface() << endl;
    cout << endl << rectangle << " surface=" << rectangle.surface() << endl;
    cout << endl << *carre << " surface=" << carre->surface() << endl;

    Forme* tab[3];
    tab[0] = &cercle;
    tab[1] = &rectangle;
    tab[2] = carre;

    float surf = 0.0;
    for (int i = 0; i < 3; i++) {
        surf += tab[i]->surface();  // ligature dynamique
    }
    cout << endl << "surface totale:" << surf << endl;

    srand((unsigned int)time(NULL));
    Forme* ptr = tab[rand() % 3];
    cout << *ptr << " : périmètre=" << ptr->perimetre() << endl;

    ptr = carre;
    delete ptr;  // virtual ~Forme() → bonne destruction

    return 0;
}
```

---

#### Q5.C — Le polymorphisme était-il nécessaire?

**Oui.** Le tableau `tab` de type `Forme*` contient des pointeurs vers `Cercle`, `Rectangle` et `Carre`. Pour calculer `surf` avec la bonne formule pour chaque type, et pour afficher le bon périmètre d'un élément tiré au sort, le compilateur doit décider *au moment de l'exécution* quelle méthode appeler → c'est exactement ce que fait le **polymorphisme via fonctions virtuelles**.

Sans polymorphisme, on ne pourrait pas stocker des types hétérogènes dans le même tableau et appeler les bonnes méthodes.

---

## Été 2000

### Question 1 — Filtrage d'espaces (15 pts)

Le programme `transfert` lit le fichier `entree.txt` et écrit dans `sortie.txt` en ne conservant qu'un seul espace consécutif à la fois (les doubles espaces sont réduits à un).

**Logique :**
- `flag = false` au départ.
- Si `ch == ' '` et `flag == false` : on écrit l'espace et met `flag = true`.
- Si `ch == ' '` et `flag == true` : on ne fait rien (espace déjà écrit).
- Si `ch != ' '` : on écrit et remet `flag = false`.

**Résultat** : le texte est reproduit identiquement, mais les suites d'espaces multiples sont réduites à un seul espace.

---

### Question 2 — Cinq erreurs de syntaxe (15 pts)

```cpp
// Ligne 6 : dx → dy
Droite(int gx,int gy,int dy): gauche(gx,gy), droite(dx,dy){}
//                                                    ^^
// ERREUR 1 : l'argument s'appelle dy mais on utilise dx
// Correction : droite(dy,dy) ou mieux renommer l'argument
```

```cpp
// Ligne 7 : manque les : pour la liste d'initialisation
Droite(const Droite& d) gauche(d.gauche), droite(d.droite) {}
// ERREUR 2 : il faut Droite(const Droite& d) : gauche(...), droite(...)
```

```cpp
// Ligne 14 : Coordonnee est déclaré APRÈS Droite → classe inconnue
class Droite { Coordonnee gauche; ...  // utilise Coordonnee
class Coordonnee { ... };              // définie après
// ERREUR 3 : déclarer Coordonnee AVANT Droite
```

```cpp
// Ligne 18 : ; au lieu de ,
Coordonnee(int a, int b): x(a);y(b){}
//                               ^
// ERREUR 4 : la liste d'initialisation utilise , pas ;
// Correction : : x(a), y(b){}
```

```cpp
// Ligne 20 : c->x, c->y → c.x, c.y (c est une référence, pas un pointeur)
Coordonnee(const Coordonnee& c) { x = c->x; y = c->y; }
//                                    ^^         ^^
// ERREUR 5 : c est const Coordonnee& → utiliser c.x, c.y
```

---

### Question 3 — Résolution de surcharge de templates (20 pts)

```cpp
template<class T> T fonction(int a, T* b) { cout << "template 1\n"; return b[0]; }
template<class T> T fonction(T a, T b)    { cout << "template 2\n"; return a; }
double fonction(int a, char* b)            { cout << "fonction 1\n"; return a; }
double fonction(double a, double b)        { cout << "fonction 2\n"; return 4.5; }
```

| Ligne | Appel | Fonction choisie | Pourquoi |
|-------|-------|-----------------|----------|
| -0- | `fonction(i,j)` | **fonction 2** | i,j sont `double` → correspondance exacte avec `fonction(double,double)` |
| -1- | `fonction(a,&c)` | **fonction 1** | `a=int`, `&c=char*` → correspondance exacte avec `fonction(int,char*)` |
| -2- | `fonction(tab[0],tab[1])` | **template 2** | `tab[0]` et `tab[1]` sont `unsigned int` → T=unsigned int, correspondance exacte |
| -3- | `fonction(tab[0],c)` | **template 2** | Impossible (types différents)... En fait : `tab[0]=uint`, `c=char` → conversions nécessaires. Template 2 avec T déduit est ambigu. Probablement `template 2` avec conversions |
| -4- | `fonction(c,tab)` | **template 1** | `c=char` peut être int, `tab=char[]` = `char*` → `fonction(int,T*)` avec T=char → template 1 |
| -5- | `fonction(c,chaine)` | **fonction 1** | `c=char` converti en `int`, `chaine=char*` → correspondance avec `fonction(int,char*)` |

---

### Question 4 — Carnet d'adresses (30 pts)

#### Q4.1 — Classe abstraite `Adresse`

```cpp
class Adresse {
public:
    virtual string type() = 0;
    virtual void affiche(int international = 0) = 0;
    virtual void saisir() = 0;
    virtual ~Adresse() {}
};
```

---

#### Q4.2 — Classe `AdressePostale`

```cpp
class AdressePostale : public Adresse {
protected:
    char* nom;
    char* rue;
    char* numero;
    char* ville;
    char* codepostale;
    char* pays;

    // Méthode utilitaire : alloue et copie une chaîne
    void assignerChamp(char*& champ, const string& valeur) {
        delete[] champ;
        champ = new char[valeur.size() + 1];
        strcpy(champ, valeur.c_str());
    }

    AdressePostale() :
        nom(nullptr), rue(nullptr), numero(nullptr),
        ville(nullptr), codepostale(nullptr), pays(nullptr) {}

public:
    ~AdressePostale() {
        delete[] nom; delete[] rue; delete[] numero;
        delete[] ville; delete[] codepostale; delete[] pays;
    }

    void saisirnom(const string& v)         { assignerChamp(nom, v); }
    void saisirrue(const string& v)         { assignerChamp(rue, v); }
    void saisirnumero(const string& v)      { assignerChamp(numero, v); }
    void saisirville(const string& v)       { assignerChamp(ville, v); }
    void saisiircodepostale(const string& v){ assignerChamp(codepostale, v); }
    void saisiirpays(const string& v)       { assignerChamp(pays, v); }

    void affichenom()        { if (nom) cout << nom; }
    void affichenum()        { if (numero) cout << numero; }
    void afficheue()         { if (rue) cout << rue; }
    void afficheville()      { if (ville) cout << ville; }
    void affichcodepostale() { if (codepostale) cout << codepostale; }
    void affichepays()       { if (pays) cout << pays; }

    string type() override { return "Adresse Postale"; }
};
```

---

#### Q4.3 — Classe `AdresseUSA`

```cpp
class AdresseUSA : public AdressePostale {
public:
    AdresseUSA() {}

    void affiche(int international = 0) override {
        // Format USA : Nom / Numéro Rue / Ville, État, Code / {Pays}
        affichenom();    cout << "\n";
        affichenum();    cout << " "; afficheue(); cout << "\n";
        afficheville();  cout << ", "; affichcodepostale(); cout << "\n";
        if (international) { affichepays(); cout << "\n"; }
    }

    void saisir() override {
        string v;
        cout << "Nom: ";       cin >> v; saisirnom(v);
        cout << "Numéro: ";    cin >> v; saisirnumero(v);
        cout << "Rue: ";       cin >> v; saisirrue(v);
        cout << "Ville: ";     cin >> v; saisirville(v);
        cout << "Code postal: ";cin >> v; saisiircodepostale(v);
        cout << "Pays: ";      cin >> v; saisiirpays(v);
    }
};
```

---

#### Q4.4 — Classe `AdresseCanada`

```cpp
class AdresseCanada : public AdressePostale {
public:
    AdresseCanada() {}

    void affiche(int international = 0) override {
        // Format Canada : Nom / Numéro Rue / Ville / {Pays} / Code postal
        affichenom();   cout << "\n";
        affichenum();   cout << " "; afficheue(); cout << "\n";
        afficheville(); cout << "\n";
        if (international) { affichepays(); cout << "\n"; }
        affichcodepostale(); cout << "\n";
    }

    void saisir() override {
        string v;
        cout << "Nom: ";       cin >> v; saisirnom(v);
        cout << "Numéro: ";    cin >> v; saisirnumero(v);
        cout << "Rue: ";       cin >> v; saisirrue(v);
        cout << "Ville: ";     cin >> v; saisirville(v);
        cout << "Code postal: ";cin >> v; saisiircodepostale(v);
        cout << "Pays: ";      cin >> v; saisiirpays(v);
    }
};
```

---

### Question 5 — STL vector + foncteurs (20 pts)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int carre(int& n) { return n * n; }
void affiche(int n) { cout << n; }

class additionne {
    int valDefaut;
public:
    additionne(int v = 10) : valDefaut(v) {}
    void operator()(int& n) {
        n += carre(valDefaut);
    }
};

int main() {
    int tab[] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> v(tab, tab + 10);

    // Carré des 10 premiers entiers
    cout << "Carré des 10 premiers entiers:";
    for_each(v.begin(), v.end(), [](int& n){ n = n*n; });
    for_each(v.begin(), v.end(), affiche);
    cout << "\n";

    // Additionne carré de 100
    cout << "Additionne le carré de 100 à chaque élément du tableau:\n";
    for_each(v.begin(), v.end(), additionne(100));
    for_each(v.begin(), v.end(), [](int n){ cout << n << " "; });
    cout << "\n";

    // Additionne carré de la valeur par défaut (10)
    cout << "Additionne le carré de la valeur par défaut à chaque élément du tableau:\n";
    for_each(v.begin(), v.end(), additionne());
    for_each(v.begin(), v.end(), [](int n){ cout << n << " "; });
    cout << "\n";

    return 0;
}
```

---

## Hiver 2000

### Question 1 — Appels à `remplir` (15 pts)

```cpp
void remplir(ifstream& entree, int tableau[], int& nb);
// (prototype supposé)
```

| Appel | Correct? | Raison |
|-------|----------|--------|
| `remplir(in, item[], nb_item)` | **FAUX** | `item[]` n'est pas une syntaxe d'appel valide ; on passe `item` |
| `remplir(NomFic, item[], nb_item)` | **FAUX** | `NomFic` est `char[]`, pas un `ifstream`; de plus `item[]` invalide |
| `remplir(in, item, nb_item)` | **VRAI** | `in` est un `ifstream`, `item` est un tableau (décayé en pointeur), `nb_item` peut être une référence |
| `remplir(ifstream, item, nb_item)` | **FAUX** | `ifstream` est un nom de type, pas une variable |
| `remplir(NomFic, item, max)` | **FAUX** | `NomFic` est `char[]`, pas un `ifstream` |

---

### Question 2 — Template `RacineCarree` (10 pts)

```cpp
// Prototype générique acceptant deux types différents
template<typename ArgType, typename ReturnType>
ReturnType RacineCarree(ArgType w);

// Pour les cas demandés, une version générique suffit :
template<typename T, typename R>
R RacineCarree(T w) {
    return static_cast<R>(sqrt(static_cast<double>(w)));
}

// Utilisation :
float r1 = RacineCarree<int, float>(4);       // float RacineCarree(int)
int   r2 = RacineCarree<float, int>(4.0f);    // int RacineCarree(float)
```

---

### Question 3 — Trace de la classe `X` (20 pts)

#### Q3.A — Fonctions appelées par ligne

| Ligne | Objets créés | Méthode |
|-------|-------------|---------|
| 1 `X v, w(1985)` | v, w | `X::X()` pour v ; `X::X(int)` pour w |
| 4 `X *pa = new X(v)` | objet H | `X::X(const X&)` (copie de v) |
| 6 `X *pb = new X(1949)` | objet K | `X::X(int)` |
| 8 `v = w` | v (receveur) | `X::operator=(const X&)` |
| 10 `pa = pb` | — | aucune méthode de X (simple affectation de pointeurs) |
| 12 `*pb = 2010` | *pb | `X::X(int)` pour construire temporaire, puis `X::operator=` |

---

#### Q3.B — Résultats en sortie

| Ligne | Sortie |
|-------|--------|
| 2 `v.Print()` | `0` |
| 3 `w.Print()` | `1985` |
| 5 `pa->Print()` | `0` (copie de v) |
| 7 `pb->Print()` | `1949` |
| 9 `v.Print()` | `1985` (après `v = w`) |
| 11 `pa->Print()` | `1949` (pa pointe maintenant K) |
| 13 `pb->Print()` | `2010` |

---

#### Q3.C.1 — H existe toujours mais n'est plus accessible?

**VRAI.** Après `pa = pb` (ligne 10), `pa` ne pointe plus vers H. H existe toujours en mémoire (non libéré), mais on n'a plus aucun pointeur vers lui → **fuite mémoire**.

#### Q3.C.2 — H.a a pris la valeur 2010?

**FAUX.** La ligne `*pb = 2010` (ligne 12) modifie l'objet pointé par `pb`, pas H. H est inaccessible depuis la ligne 10.

---

### Question 4 — `ClasseBase<T1,T2>` et dérivée (15 pts)

#### Q5.A — Type que `ClasseBase` ne peut pas traiter

`char*` (chaînes C). L'opérateur `<<` et les constructeurs supposent des types copiables et affichables avec `<<`. Pour `char*`, l'affichage fonctionnerait, mais les opérations de comparaison, copie et affectation ne géreraient pas correctement la mémoire dynamique.

---

#### Q5.B — Classe dérivée

```cpp
template<typename Type1, typename Type2>
class ClasseDerivee : public ClasseBase<Type1, Type2> {
private:
    Type2 Champ3;
public:
    ClasseDerivee(Type1 arg1, Type2 arg2, Type2 arg3)
        : ClasseBase<Type1, Type2>(arg1, arg2), Champ3(arg3) {}

    void Print() override {
        ClasseBase<Type1, Type2>::Print();  // affiche Champ1 et Champ2
        cout << Champ3 << endl;
    }
};
```

---

#### Q5.C — Complétion de `main`

```cpp
int main() {
    int x = 40;
    float y = 55.55;
    char a = 'w', b = 'z';

    ClasseBase<int,int> BaseExpObj();  // déjà fourni

    ClasseBase<int,float> ObjBase(x, y);   // instanciation avec x et y
    ClasseDerivee<char,char> ObjDerivee(a, b, 'q');  // avec a, b

    ObjBase.Print();      // affiche Champ1 et Champ2 de la base
    ObjDerivee.Print();   // affiche les 3 champs
    return 0;
}
```

---

### Question 5 — Ligature dynamique (20 pts)

```cpp
class X { public: void f0(){cout<<"X::f0";} virtual void f1(){cout<<"X::f1";} };
class Y : public X { public: Y(int zz):X(zz){} void f1(){cout<<"Y::f1"; f0();} };
```

#### Q4.A — Lignes 1 et 2

```cpp
py = &y;
y.f1();   // ligne 1 : type statique Y → Y::f1
py->f1(); // ligne 2 : py est Y*, virtual → Y::f1
```

**OUI**, les deux affichent la même chose :
```
Y::f1
X::f0
```

---

#### Q4.B — Lignes 3 et 4

```cpp
px = &y;
y.f1();   // ligne 3 : type statique Y → Y::f1
px->f1(); // ligne 4 : px est X*, virtual → Y::f1 (ligature dynamique)
```

**OUI**, les deux affichent la même chose :
```
Y::f1
X::f0
```

---

#### Q4.C — Fonctions appelées

| Ligne | `X::f0()` | `X::f1()` | `Y::f1()` |
|-------|-----------|-----------|-----------|
| 7 `px=&y; px->f1()` | ✓ (via Y::f1) | — | ✓ (dispatch dynamique) |
| 8 `px=&x; px->f1()` | — | ✓ (x est X) | — |
| 9 `py=&y; py->f1()` | ✓ (via Y::f1) | — | ✓ |

---

#### Q4.D — Lignes 5 et 6

**Q4.D.1 `px = py` (ligne 5)** → **OUI**, correct.

`py` est `Y*`, `px` est `X*`. `Y` hérite de `X` → un `Y*` peut être assigné à `X*` (upcasting implicite).

**Q4.D.2 `py = px` (ligne 6)** → **NON**, incorrect.

`px` est `X*`, `py` est `Y*`. On ne peut pas assigner un pointeur de base à un pointeur dérivé sans cast explicite. Erreur de compilation.

---

### Question 6 — Tri par sélection décroissant (20 pts)

#### Q6.A — Version `int`

```cpp
void echanger(int* a, int* b) { int tmp = *a; *a = *b; *b = tmp; }

void tri_decroissant(int tab[], int taille) {
    for (int pos = 0; pos < taille - 1; pos++) {
        int idxMax = pos;
        for (int j = pos + 1; j < taille; j++) {
            if (tab[j] > tab[idxMax])
                idxMax = j;
        }
        if (idxMax != pos)
            echanger(&tab[pos], &tab[idxMax]);
    }
}
```

---

#### Q6.B — Version générique (int, char, string)

```cpp
template<typename T>
void tri_decroissant(T tab[], int taille) {
    for (int pos = 0; pos < taille - 1; pos++) {
        int idxMax = pos;
        for (int j = pos + 1; j < taille; j++) {
            if (tab[j] > tab[idxMax])
                idxMax = j;
        }
        if (idxMax != pos) {
            T tmp = tab[pos];
            tab[pos] = tab[idxMax];
            tab[idxMax] = tmp;
        }
    }
}
```

---

#### Q6.C — Version `char*`

Pour `char*`, l'opérateur `>` compare les adresses, pas le contenu. Il faut utiliser `strcmp`.

```cpp
void tri_decroissant_cstring(char* tab[], int taille) {
    for (int pos = 0; pos < taille - 1; pos++) {
        int idxMax = pos;
        for (int j = pos + 1; j < taille; j++) {
            if (strcmp(tab[j], tab[idxMax]) > 0)
                idxMax = j;
        }
        if (idxMax != pos) {
            char* tmp = tab[pos];
            tab[pos] = tab[idxMax];
            tab[idxMax] = tmp;
        }
    }
}
```

---

## Automne 1999

### Exercice 1 — Classe `s_date` (10 pts)

#### 1.1 — Définition de la classe

```cpp
class s_date {
private:
    int jour;
    int mois;
    int an;
public:
    s_date(int j = 1, int m = 1, int a = 2000)
        : jour(j), mois(m), an(a) {}

    // Accesseurs
    int getJour() const { return jour; }
    int getMois() const { return mois; }
    int getAn()   const { return an; }
};
```

---

#### 1.2 — Constructeur de recopie nécessaire?

**NON.** `s_date` contient uniquement des `int` (types primitifs). La copie membre-à-membre par défaut est correcte. Pas besoin d'un constructeur de recopie explicite.

---

### Exercice 2 — Classe `s_fiche` (10 pts)

#### 2.1 — Définition de la classe

```cpp
class s_fiche {
private:
    char* nom;
    int numero;
    s_date naissance;
public:
    s_fiche(const char* n, int num, s_date d)
        : numero(num), naissance(d) {
        nom = new char[strlen(n) + 1];
        strcpy(nom, n);
    }
    ~s_fiche() { delete[] nom; }
};
```

---

#### 2.2 — Constructeur de recopie nécessaire?

**OUI.** `s_fiche` contient `char* nom`, un pointeur vers une chaîne allouée dynamiquement. Sans constructeur de recopie explicite, la copie par défaut copierait seulement le pointeur (copie superficielle), et deux instances partageraient le même bloc mémoire → double libération → comportement indéfini.

```cpp
s_fiche(const s_fiche& f)
    : numero(f.numero), naissance(f.naissance) {
    nom = new char[strlen(f.nom) + 1];
    strcpy(nom, f.nom);
}
```

---

### Exercice 3 — Saisie et affichage (15 pts)

#### 3.1 — `SaisirDate`

```cpp
void s_date::SaisirDate() {
    cout << "Jour: ";   cin >> jour;
    cout << "Mois: ";   cin >> mois;
    cout << "Année: ";  cin >> an;
}
```

---

#### 3.2 — `SaisirFiche`

```cpp
void s_fiche::SaisirFiche() {
    char buffer[256];
    cout << "Nom: ";    cin >> buffer;
    delete[] nom;
    nom = new char[strlen(buffer) + 1];
    strcpy(nom, buffer);

    cout << "Numéro: "; cin >> numero;
    naissance.SaisirDate();
}
```

---

#### 3.3 — `Afficher` pour `s_date` et `s_fiche`

```cpp
void s_date::Afficher() const {
    cout << jour << "/" << mois << "/" << an;
}

void s_fiche::Afficher() const {
    cout << "Nom: "     << nom         << "\n";
    cout << "Numéro: "  << numero      << "\n";
    cout << "Naissance: "; naissance.Afficher(); cout << "\n";
}
```

---

### Exercice 4 — Classe `Exo` (10 pts)

#### 4.1 — `static int taille_fenetre = 130` correct?

**NON.** En C++, les membres données statiques **ne peuvent pas être initialisés dans la déclaration de la classe** (sauf `constexpr` ou `const`). La définition doit être hors de la classe :

```cpp
// Dans le .cpp :
int Exo::taille_fenetre = 130;
```

---

#### 4.2 — Sortie du programme

`process()` extrait une sous-chaîne à partir de la position 4, sur 130 caractères. Puis appelle `exit(1)` → le programme se termine après la première ligne.

Pour la première ligne du fichier :
```
1(:<25.GHF$)3/DQFLHQFKDPSLRQGXPRQGHGHVORXUGV0XKDPP
```

- position 0 à 3 : `1(:<`
- position 4 et suivants : `25.GHF$)3/DQFLHQFKDPSLRQGXPRQGHGHVORXUGV0XKDPP`

**Affichage :** `25.GHF$)3/DQFLHQFKDPSLRQGXPRQGHGHVORXUGV0XKDPP`

Puis `exit(1)` → programme terminé.

---

### Exercice 5 — Classe abstraite `peintre` (15 pts)

#### 5.1 — Classe abstraite `peintre`

```cpp
class peintre {
public:
    virtual void Saisir() = 0;   // virtuelle pure
    virtual void Afficher() = 0; // virtuelle pure
    virtual ~peintre() {}
};
```

---

#### 5.2 — Classe `Monet`

```cpp
const int NB_ELT = 10;  // ou paramètre du constructeur

class Monet : public peintre {
private:
    string TAB[NB_ELT];
public:
    void Saisir() override {
        for (int i = 0; i < NB_ELT; i++) {
            cout << "Entrée " << i << ": ";
            cin >> TAB[i];
        }
    }

    void Afficher() override {
        for (int i = 0; i < NB_ELT; i++) {
            cout << TAB[i] << "\n";
        }
    }
};
```

---

### Exercice 6 — `vector<OBJT>` et `temp_print` (15 pts)

#### 6.1 — `main` avec vecteur

```cpp
int main() {
    vector<OBJT> Vdata;
    OBJT objA, objB;

    Vdata.push_back(objA);
    Vdata.push_back(objB);

    for (size_t i = 0; i < Vdata.size(); i++) {
        Vdata[i].Afficher();
    }
    return 0;
}
```

---

#### 6.2 — Fonction template `temp_print`

```cpp
template<typename T>
void temp_print(vector<T>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        v[i].Afficher();
    }
}
```

---

### Exercice 7 — Fréquence de mots (25 pts)

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

// Structure pour stocker mot + fréquence
struct MotFreq {
    string mot;
    int freq;
};

// Convertit en minuscules
string enMinuscules(string s) {
    for (size_t i = 0; i < s.size(); i++)
        s[i] = tolower(s[i]);
    return s;
}

void load_data(string tab[], unsigned int& taille) {
    string mot;
    while (cin >> mot) {
        tab[taille++] = mot;
    }
}

// Tri par sélection décroissant sur fréquence, puis alphabétique à fréquence égale
// (sans STL sort)
void triMotsFreq(MotFreq arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int idxMax = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].freq > arr[idxMax].freq ||
                (arr[j].freq == arr[idxMax].freq && arr[j].mot < arr[idxMax].mot)) {
                idxMax = j;
            }
        }
        if (idxMax != i) {
            MotFreq tmp = arr[i];
            arr[i] = arr[idxMax];
            arr[idxMax] = tmp;
        }
    }
}

int main() {
    const unsigned int MAX = 1000;
    string TAB[MAX];
    unsigned int taille = 0;

    load_data(TAB, taille);

    // Compte les fréquences (sans STL map)
    MotFreq resultats[MAX];
    int nbUniques = 0;

    for (unsigned int i = 0; i < taille; i++) {
        string motMin = enMinuscules(TAB[i]);
        bool trouve = false;
        for (int j = 0; j < nbUniques; j++) {
            if (resultats[j].mot == motMin) {
                resultats[j].freq++;
                trouve = true;
                break;
            }
        }
        if (!trouve) {
            resultats[nbUniques].mot = motMin;
            resultats[nbUniques].freq = 1;
            nbUniques++;
        }
    }

    triMotsFreq(resultats, nbUniques);

    ofstream sortie("test.txt");
    for (int i = 0; i < nbUniques; i++) {
        sortie << resultats[i].mot << " " << resultats[i].freq << "\n";
    }

    return 0;
}
```

---

### Exercice 8 (Bonus) — `int& ref = new int` est dangereux

**Pourquoi c'est dangereux :**

1. La syntaxe est incorrecte en C++ standard : `new int` retourne un `int*`, pas un `int`. On ne peut pas lier directement une référence à un pointeur.
2. Même si c'était autorisé, la mémoire allouée avec `new` ne peut **jamais être libérée** : on n'a pas de pointeur pour appeler `delete`, seulement une référence. → Fuite mémoire garantie.

**Version correcte :**

```cpp
// Option 1 : utiliser un pointeur (et libérer)
int* ptr = new int;
*ptr = 42;
delete ptr;

// Option 2 : utiliser une variable locale (sans allocation dynamique)
int valeur = 42;
int& ref = valeur;  // référence sur une variable locale
```

---

*Fin des solutions — IFT1166 Finaux 1999–2008*
