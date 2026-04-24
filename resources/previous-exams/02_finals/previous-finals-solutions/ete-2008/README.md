# Solutions commentees — IFT1166 Examen Final (Ete 2008)

Objectif: separer chaque exercice dans son propre fichier avec solution complete et commentaires utiles pour reviser vite avant le final.

## Fichiers

- `ex1-theorie.md` : Reponses courtes 1.1 a 1.8 (destructeur, inline, compilation multi-fichiers)
- `ex2-constructeurs-static.cpp` : Exercice 2.1 et 2.2 avec explications + verification par execution
- `ex3-polymorphisme-interface.md` : Analyse de compilation 3.1 a 3.5
- `ex4-compteur-piece.cpp` : Classe `Compteur` + simulation de 100 lancers
- `ex5-anagrammes-liste.cpp` : Solutions 5.1 a 5.7 (fonctions + listes + main)

## Strategie de revision (ce soir)

1. Commence par `ex3-polymorphisme-interface.md` (tres frequents a l'examen).
2. Fais ensuite `ex1-theorie.md` pour les points faciles et rapides.
3. Compile et execute `ex2-constructeurs-static.cpp` puis `ex4-compteur-piece.cpp`.
4. Termine par `ex5-anagrammes-liste.cpp` (exercice long, tres formateur).

## Compilation rapide (Windows / g++)

```bash
g++ -std=c++17 ex2-constructeurs-static.cpp -o ex2
g++ -std=c++17 ex4-compteur-piece.cpp -o ex4
g++ -std=c++17 ex5-anagrammes-liste.cpp -o ex5
```
