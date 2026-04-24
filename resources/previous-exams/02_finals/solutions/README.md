# Guides de Solutions aux Examens Finaux — IFT1166

Ce dossier contient des **solutions guidées et commentées** pour les examens finaux d'IFT1166, chacun avec :

- ✓ **Solutions complètes** compilables
- ✓ **Explications détaillées** de chaque étape
- ✓ **Traces d'exécution** montrant le flux du code
- ✓ **Pièges courants** identifiés et expliqués
- ✓ **Points clés** à retenir pour chaque examen

---

## Index des Examens

### 2007 — Été
**Fichier :** `SOLUTION-2007-Ete-Commentee.cpp`

**Thèmes couverts :**
- Gestion de la mémoire (new/delete, fuites)
- Visibilité et héritage (public/private/protected)
- Récursivité et cas de base
- Structures LIFO (pile)
- Hiérarchie Vehicule et polymorphisme

**Compétences testées :**
- Diagnostiquer et corriger les erreurs de mémoire
- Comprendre la visibilité dans l'héritage
- Analyser la terminaison des fonctions récursives
- Utiliser des structures de données classiques

**Points pédagogiques clés :**
- Rule: new↔delete, new[]↔delete[]
- Héritage public vs. héritage privé : impact sur l'accès
- Cas de base OBLIGATOIRE pour toute récursion

---

### 2008 — Automne
**Fichier :** `SOLUTION-2008-Automne-Commentee.cpp`

**Thèmes couverts :**
- Classes avec attributs statiques
- Déclaration et instanciation d'objets
- Composition vs. héritage
- Surcharge d'opérateurs (+, *, <<, [])
- Constructeurs et destructeurs virtuels
- Chaînes de caractères (C-style et std::string)
- Pointeurs de fonction
- STL : vector, map

**Compétences testées :**
- Choisir entre composition et héritage
- Surcharger les opérateurs de manière correcte
- Gérer l'ordre construction/destruction dans les hiérarchies
- Manipuler des chaînes et des conteneurs STL

**Points pédagogiques clés :**
- Attributs statiques : partagés par TOUTES les instances
- Destructeur virtuel : essentiel pour polymorphe sûr
- Surcharge operator<< : toujours fonction amie (friend)
- strcmp vs. operator== : différentes approches

---

### 2009 — Automne
**Fichier :** `SOLUTION-2009-Automne-Commentee.cpp`

**Thèmes couverts :**
- Pointeurs vs. références
- Const-correctness
- Instanciation et accès (pile vs. heap)
- Copie profonde vs. superficielle
- Classes abstraites (virtual = 0)
- Polymorphisme avec vector et pointeurs
- Récursivité : factorielle, Fibonacci, recherche binaire
- STL : algorithmes (sort, find, reverse)

**Compétences testées :**
- Distinguer et utiliser correctement pointeurs/références
- Implémenter une copie profonde
- Concevoir une hiérarchie polymorphe
- Implémenter des algorithmes récursifs efficaces
- Utiliser les algorithmes STL

**Points pédagogiques clés :**
- Référence : immuable, toujours valide (jamais NULL)
- Pointeur : flexible, peut être NULL, réassignable
- Copie superficielle → double libération de mémoire (DANGER)
- Fibonacci naïf : O(2^n) → nécessite memoïsation

---

### 2010 — Été
**Fichier :** `SOLUTION-2010-Ete-Commentee.cpp`

**Thèmes couverts :**
- Const-correctness avancée
- Mémoire et calcul d'allocation
- Héritage multiple et problème du diamant
- Virtual inheritance
- Conteneurs et algorithmes (sort, find, binary_search)
- Programmation générique (templates)
- Patterns de design (Singleton, Factory, Observer)

**Compétences testées :**
- Modifier le code avec const correctness
- Calculer la mémoire utilisée
- Résoudre les ambiguïtés d'héritage multiple
- Utiliser les algorithmes STL génériques
- Reconnaître et appliquer des patterns de conception

**Points pédagogiques clés :**
- Héritage multiple : problème du diamant → virtual inheritance
- assert() : valider les préconditions
- Templates : réutilisabilité avec type-safety
- Patterns : Singleton (une instance), Factory (création), Observer (notification)

---

## Comment Utiliser Ces Solutions

### Pour l'auto-apprentissage :

1. **Avant de lire la solution :**
   - Résoudre l'exercice par vous-même
   - Identifier les domaines problématiques
   - Vérifier votre compréhension

2. **En lisant la solution :**
   - Suivre les traces d'exécution (elles montrent le flux)
   - Comprendre le "pourquoi", pas juste le "comment"
   - Identifier les pièges courants
   - Noter les patterns réutilisables

3. **Après la lecture :**
   - Couvrir la solution et réécrire de mémoire
   - Tester votre code
   - Adapter le pattern à d'autres problèmes

### Pour la révision d'examen :

- Parcourir les **Points clés à retenir** à la fin de chaque fichier
- Revoir les **traces d'exécution** pour vérifier votre compréhension
- Pratiquer les **pièges courants** identifiés dans chaque section

---

## Commandes de Compilation et Exécution

Chaque fichier de solution est **compilable seul** avec :

```bash
# Compiler
g++ -Wall -Wextra -std=c++17 SOLUTION-AAAA-Xx-Commentee.cpp -o solution

# Exécuter
./solution
```

Ou avec le compilateur MSVC :

```bash
cl /std:c++17 /EHsc SOLUTION-AAAA-Xx-Commentee.cpp
./SOLUTION-AAAA-Xx-Commentee.exe
```

---

## Structure Pédagogique de Chaque Solution

```
┌─────────────────────────────────────────┐
│ EXERCISE N — Titre                      │
├─────────────────────────────────────────┤
│ N.1 — Sous-question                     │
│ ─────────────────────────────────────────│
│ RÉPONSE : ...                           │
│ Trace : ...                             │
│                                         │
│ N.2 — Sous-question                     │
│ ...                                     │
└─────────────────────────────────────────┘

POINTS CLÉS À RETENIR
┌─────────────────────────────────────────┐
│ 1. Concept A                            │
│ 2. Concept B                            │
│ 3. Piège courant                        │
└─────────────────────────────────────────┘
```

---

## Progression Recommandée

**Ordre suggéré pour réviser :**

1. **Commencer par 2007 Été** → fondations (mémoire, héritage, récursion)
2. **Puis 2008 Automne** → classes avancées, surcharge, STL
3. **Puis 2009 Automne** → polymorphisme, pointeurs vs. références
4. **Finir par 2010 Été** → concepts avancés, patterns, héritage multiple

---

## Sujets Transversaux Révisés

| Sujet | 2007 | 2008 | 2009 | 2010 | Priorité |
|-------|------|------|------|------|----------|
| Mémoire | ✓ | ✓ | ✓ | ✓ | **HAUTE** |
| Héritage | ✓ | ✓ | ✓ | ✓ | **HAUTE** |
| Polymorphisme | ✓ | ✓ | ✓ | ✓ | **HAUTE** |
| Récursion | ✓ | ✗ | ✓ | ✗ | Moyenne |
| STL | ✗ | ✓ | ✓ | ✓ | Moyenne |
| Const | ✗ | ✓ | ✓ | ✓ | Moyenne |
| Patterns | ✗ | ✗ | ✗ | ✓ | Basse |

---

## Notes Importantes

- **Compilabilité :** Chaque solution est un programme C++ **compilable standalone**
- **Exécution :** Les solutions ne produisent pas d'interactivité (elles affichent des résultats et commentaires)
- **Portabilité :** Code écrit en C++17, compatible avec g++ et MSVC
- **Langue :** Commentaires en français (French); variable/function names en anglais-français mélangé

---

## Questions Fréquentes

**Q: Puis-je compiler et exécuter ces fichiers ?**
> Oui ! Chaque fichier est un programme C++ complet et compilable.

**Q: Pourquoi certaines fonctions ne font rien au runtime ?**
> Les solutions montrent du code compilable mais l'accent est mis sur le code lui-même
> (structure, correction, pattern) plutôt que sur l'affichage du résultat.

**Q: Comment puis-je tester si ma solution est correcte ?**
> Suivre les traces d'exécution line-by-line et comparer votre output mental avec celui indiqué.

**Q: Quels topics devrais-je repasser les examen ?**
> Voir le tableau "Sujets Transversaux" pour une vue d'ensemble de ce qui revient souvent.

---

## Ressources Complémentaires

- **Cheatsheet C++ :** `../../cpp-cheatsheet.md`
- **Notions de base :** `../../fundamentals/`
- **Programmation orientée objet :** `../../oop/`
- **Ressources externes :** `../../resources/RESSOURCES.md`

---

**Dernière mise à jour :** Hiver 2026  
**Cours :** IFT1166 — Programmation orientée objet en C++  
**Université :** Université de Montréal
