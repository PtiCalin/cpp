// ============================================================================
// Exercice — Hiérarchie d'animaux (héritage et polymorphisme)
// ============================================================================
//
// CONSIGNES :
//   Construire la hiérarchie de classes suivante :
//
//   Animal (classe abstraite)
//     ├─ Chien
//     ├─ Chat
//     └─ Oiseau
//
//   Classe Animal :
//     - Attributs protégés : string nom, int age
//     - Constructeur : Animal(string nom, int age)
//     - DESTRUCTEUR VIRTUEL
//     - Méthode virtuelle pure  : virtual string parler() const = 0
//     - Méthode virtuelle pure  : virtual string type() const = 0
//     - Méthode virtuelle       : virtual void decrire() const
//       → affiche "Je suis [type], je m'appelle [nom], j'ai [age] ans."
//     - Getters : getNom(), getAge()
//
//   Chien, Chat, Oiseau :
//     - Héritent de Animal
//     - Implémentent parler() :
//         Chien  → "Woof!"
//         Chat   → "Miaou!"
//         Oiseau → "Cui-cui!"
//     - Implémentent type() :
//         Chien  → "Chien"
//         Chat   → "Chat"
//         Oiseau → "Oiseau"
//
//   Dans main() :
//     1. Créer un vector<Animal*> avec au moins un de chaque type.
//     2. Boucler et appeler parler() et decrire() via le pointeur de base.
//     3. Libérer la mémoire (delete via le pointeur de base → vérifie virtual ~Animal).
//     4. Démontrer la différence static vs dynamic binding :
//          Animal* a = new Chien("Rex", 3);
//          a->parler();         // dynamic  → "Woof!"
//          // (comparer avec un objet par valeur pour montrer le slicing)
//
// CONCEPTS PRATIQUÉS :
//   - class abstraite (méthode virtuelle pure = 0)
//   - virtual, override
//   - Destructeur virtuel
//   - Polymorphisme via vector<Animal*>
//   - Ligature dynamique vs statique
//   - Slicing (si Animal par valeur)
//
// ============================================================================

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ── Classe de base ────────────────────────────────────────────────────────

class Animal {
protected:
    // TODO : attributs nom, age

public:
    // TODO : constructeur
    // TODO : destructeur virtuel
    // TODO : virtual string parler() const = 0
    // TODO : virtual string type() const = 0
    // TODO : virtual void   decrire() const  (avec implémentation)
    // TODO : getters
};

// ── Classes dérivées ──────────────────────────────────────────────────────

class Chien : public Animal {
public:
    // TODO
};

class Chat : public Animal {
public:
    // TODO
};

class Oiseau : public Animal {
public:
    // TODO
};

// ── main ─────────────────────────────────────────────────────────────────

int main() {

    // TODO 1 : créer vector<Animal*> et y ajouter Chien, Chat, Oiseau (new)

    // TODO 2 : boucler — appeler decrire() et parler() pour chaque animal

    // TODO 3 : libérer la mémoire (delete ptr, vider le vecteur)

    // TODO 4 : démonstration ligature statique vs dynamique
    //   Animal* a = new Chien("Rex", 3);
    //   cout << a->parler() ...   → dynamique : Woof!
    //   delete a;

    return 0;
}
