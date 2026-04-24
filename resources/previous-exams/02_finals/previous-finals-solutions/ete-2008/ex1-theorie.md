# Exercice 1 (20 points) — Solutions courtes

## 1.1 Destructeur appele dans quels cas?
Reponses correctes: **a, b, c**.

- a) Une variable locale quitte sa portee: oui.
- b) Appel a `delete`: oui.
- c) Appel a `delete[]`: oui.

## 1.2 Peut-on detruire une instance si le destructeur est prive?
Reponse generale: **non**, pas depuis l'exterieur de la classe.

Pourquoi: le destructeur prive n'est accessible qu'aux methodes amies ou membres de la classe. Donc un code externe ne peut ni detruire un objet automatique en fin de portee, ni faire `delete` dessus (sauf contexte ami).

## 1.3 Declaration d'une classe
Definition concise: la declaration d'une classe specifie son interface et sa structure (membres donnees et fonctions membres), ainsi que les droits d'acces (`public`, `protected`, `private`).

## 1.4 Une classe derivee accede-t-elle a tous les membres de base?
Reponse: **non**.

Pourquoi: les membres `private` de la base ne sont pas accessibles directement dans la derivee. Les membres `public` et `protected` sont accessibles selon le mode d'heritage.

## 1.5 `inline` est-il juste indicatif?
Reponse: **oui**.

Pourquoi: `inline` est une suggestion au compilateur. Le compilateur peut inliner ou non selon optimisation, taille de fonction, contexte d'appel, etc.

## 1.6 Prototype de `test`
On veut: retour `double*`, arguments:
- `string&` par reference
- `char` par valeur avec defaut `'w'`
- `int*` avec defaut `NULL`

Prototype:

```cpp
double* test(std::string& s, char c = 'w', int* p = NULL);
```

## 1.7 Appels possibles a `test`
Si `std::string mot; int x = 10; int* px = &x;`

```cpp
test(mot);
test(mot, 'a');
test(mot, 'z', px);
test(mot, 'z', NULL);
```

## 1.8 Multi-fichiers (`a.h`, `a.cpp`, `test.cpp`)
### a) Que faut-il ajouter dans `test.cpp`?
Il faut inclure l'en-tete pour connaitre la declaration de `affiche`:

```cpp
#include "a.h"
```

### b) Peut-on compiler `test.cpp` sans `a.cpp`?
**Oui pour la compilation vers objet** (`test.o`), car seule la declaration est necessaire.

**Non pour l'edition de liens finale**, car la definition de `affiche` est dans `a.cpp`/`a.o`.

### c) Ligne de commande pour generer l'executable depuis les objets

```bash
g++ a.o test.o -o test.exe
```
