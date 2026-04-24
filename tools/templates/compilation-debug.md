# Compilation et Debug

## Compilation recommandee

```bash
g++ -Wall -Wextra -Wpedantic -std=c++17 fichier.cpp -o programme
```

## Multi-fichiers

```bash
g++ -Wall -Wextra -std=c++17 main.cpp module.cpp -o programme
```

## Debug (gdb)

```bash
g++ -g -std=c++17 fichier.cpp -o programme
gdb ./programme
```

## Routine de correction

1. Corriger d'abord les erreurs de compilation.
2. Activer les warnings stricts.
3. Reproduire le bug avec un petit cas test.
4. Valider la correction avec 2-3 cas limites.
