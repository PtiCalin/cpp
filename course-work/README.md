# Course Work — Exercices pratiques

Recueil de **19 exercices** couvrant l'ensemble du programme IFT1166.  
Chaque fichier est **auto-suffisant** : consignes en commentaire + solution complète.

---

## Phase 1 — Fondations

| # | Fichier | Thème | Concepts clés |
|---|---------|-------|---------------|
| 01 | [ex01-variables-types.cpp](ex01-variables-types.cpp) | Variables et types | `int`, `double`, `char`, `bool`, `string`, `const`, `static_cast`, `cin/cout` |
| 02 | [ex02-conditions.cpp](ex02-conditions.cpp) | Conditions | `if/else`, `switch/case`, ternaire, opérateurs logiques |
| 03 | [ex03-boucles.cpp](ex03-boucles.cpp) | Boucles | `for`, `while`, `do-while`, boucles imbriquées, `break/continue` |
| 04 | [ex04-fonctions.cpp](ex04-fonctions.cpp) | Fonctions | Prototypes, valeur/référence/pointeur, surcharge, récursion |
| 05 | [ex05-tableaux.cpp](ex05-tableaux.cpp) | Tableaux C-style | Déclaration, parcours, tri à bulles, tableaux 2D |

## Phase 2 — Structures de données

| # | Fichier | Thème | Concepts clés |
|---|---------|-------|---------------|
| 06 | [ex06-vectors.cpp](ex06-vectors.cpp) | Vectors & STL | `vector`, itérateurs, `sort`, `find`, `accumulate`, range-for |
| 07 | [ex07-strings.cpp](ex07-strings.cpp) | Chaînes | `string`, `find`, `substr`, `stoi/stod`, `stringstream`, palindrome |
| 08 | [ex08-pointeurs.cpp](ex08-pointeurs.cpp) | Pointeurs & références | `&`, `*`, `->`, arithmétique, `const`, `nullptr` |
| 09 | [ex09-memoire-dynamique.cpp](ex09-memoire-dynamique.cpp) | Mémoire dynamique | `new/delete`, tableaux dynamiques, matrice 2D, fuites mémoire |

## Phase 3 — Préprocesseur & Macros

| # | Fichier | Thème | Concepts clés |
|---|---------|-------|---------------|
| 10 | [ex10-macros-preprocesseur.cpp](ex10-macros-preprocesseur.cpp) | Préprocesseur | `#define`, include guards, `#ifdef`, macros prédéfinies, `constexpr` |

## Phase 4 — Programmation orientée objet

| # | Fichier | Thème | Concepts clés |
|---|---------|-------|---------------|
| 11 | [ex11-classes-bases.cpp](ex11-classes-bases.cpp) | Classes : les bases | `class`, `private/public`, constructeurs, getters/setters, `const` |
| 12 | [ex12-composition.cpp](ex12-composition.cpp) | Composition | Relation « has-a », objets membres, composition 1-1 et 1-N |
| 13 | [ex13-surcharge-operateurs.cpp](ex13-surcharge-operateurs.cpp) | Surcharge d'opérateurs | `operator+`, `==`, `<<`, `[]`, `++`, `friend` |
| 14 | [ex14-heritage-polymorphisme.cpp](ex14-heritage-polymorphisme.cpp) | Héritage & polymorphisme | `virtual`, `override`, classe abstraite, destructeur virtuel |
| 18 | [ex18-constructeurs-avances.cpp](ex18-constructeurs-avances.cpp) | Constructeurs avancés | Copie, `operator=`, destructeur, Rule of Three, deep copy |

## Phase 5 — Fichiers & Architecture

| # | Fichier | Thème | Concepts clés |
|---|---------|-------|---------------|
| 15 | [ex15-fichiers.cpp](ex15-fichiers.cpp) | Fichiers I/O | `ifstream`, `ofstream`, `getline`, CSV, sérialisation |
| 16 | [ex16-multi-fichiers.cpp](ex16-multi-fichiers.cpp) | Multi-fichiers | Header/source, include guards, compilation séparée |

## Phase 6 — STL & Projet intégré

| # | Fichier | Thème | Concepts clés |
|---|---------|-------|---------------|
| 17 | [ex17-stl-algorithmes.cpp](ex17-stl-algorithmes.cpp) | STL avancée | `map`, `set`, `pair`, `sort` + lambda, `for_each`, `transform` |
| 19 | [ex19-projet-gestion-notes.cpp](ex19-projet-gestion-notes.cpp) | Projet de synthèse | Héritage, composition, STL, fichiers, polymorphisme — tout combiné |

## Révision — Examen final

| # | Fichier | Thème | Concepts clés |
|---|---------|-------|---------------|
| 20 | [ex20-revision-examen-final.cpp](ex20-revision-examen-final.cpp) | Révision examen | Sorties de programme, correction de bogues, codage (héritage + polymorphisme) |

Voir aussi : [Guide de révision complet](../resources/notes/examen-final-ift1166.md) (chapitres 11–18, terminologie, aide-mémoire).

---

## Comment utiliser

```bash
# Compiler un exercice
g++ -std=c++17 -o exo ex01-variables-types.cpp

# Exécuter
./exo        # Linux/macOS
.\exo.exe    # Windows
```

Chaque fichier commence par un bloc de commentaires contenant :
- **CONSIGNES** — les parties de l'exercice
- **CONCEPTS PRATIQUÉS** — la liste des notions couvertes

> **Astuce** — Essaie de résoudre les CONSIGNES avant de lire le code solution !
