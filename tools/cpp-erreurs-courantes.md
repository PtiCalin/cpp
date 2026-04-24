# Erreurs courantes (IFT1166)

## 1) Oublier `delete[]` apres `new[]`

Symptome: fuite memoire.

## 2) Copier une classe avec pointeur sans copie profonde

Symptome: double liberation, plantage aleatoire.

## 3) Oublier `virtual` sur le destructeur de base

Symptome: destruction partielle via pointeur de base.

## 4) Confondre initialisation et affectation

- `A b = a;` -> constructeur de recopie
- `b = a;` -> operateur `=`

## 5) Appeler une methode non visible via pointeur de base

Symptome: erreur de compilation meme si l'objet derive possede la methode.
