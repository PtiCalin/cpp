// ============================================================================
// SOLUTION — Hiérarchie d'animaux (héritage et polymorphisme)
// ============================================================================
// Compiler : g++ -Wall -std=c++17 ex-animaux-solution.cpp -o ex-animaux
// ============================================================================

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ── Classe de base abstraite ─────────────────────────────────────────────────

class Animal {
protected:
    // protected : accessible aux classes dérivées, pas à l'extérieur
    string nom;
    int    age;

public:
    Animal(const string& nom, int age) : nom(nom), age(age) {}

    // DESTRUCTEUR VIRTUEL — indispensable quand on delete via un pointeur de base
    // Sans cela : undefined behaviour (seul ~Animal est appelé, pas ~Chien etc.)
    virtual ~Animal() {}

    // Méthodes virtuelles PURES (= 0) → classe abstraite, non instanciable
    virtual string parler() const = 0;
    virtual string type()   const = 0;

    // Méthode virtuelle avec implémentation par défaut — les dérivées peuvent
    // la redéfinir ou s'en contenter
    virtual void decrire() const {
        cout << "Je suis un(e) " << type()
             << ", je m'appelle " << nom
             << ", j'ai " << age << " an(s)."
             << " Je dis : " << parler() << endl;
    }

    string getNom() const { return nom; }
    int    getAge() const { return age; }
};

// ── Classes dérivées ──────────────────────────────────────────────────────────

class Chien : public Animal {
public:
    // Délégation au constructeur de base via la liste d'initialisation
    Chien(const string& nom, int age) : Animal(nom, age) {}

    // override : le compilateur vérifie que la signature correspond bien à virtual
    string parler() const override { return "Woof!";    }
    string type()   const override { return "Chien";    }
};

class Chat : public Animal {
public:
    Chat(const string& nom, int age) : Animal(nom, age) {}
    string parler() const override { return "Miaou!";   }
    string type()   const override { return "Chat";     }
};

class Oiseau : public Animal {
public:
    Oiseau(const string& nom, int age) : Animal(nom, age) {}
    string parler() const override { return "Cui-cui!"; }
    string type()   const override { return "Oiseau";   }
};

// ── main ─────────────────────────────────────────────────────────────────────

int main() {

    // ── Polymorphisme via vector<Animal*> ─────────────────────────────────
    // On stocke des pointeurs de TYPE BASE, mais qui pointent sur des DÉRIVÉES
    vector<Animal*> animaux;
    animaux.push_back(new Chien ("Rex",    3));
    animaux.push_back(new Chat  ("Mimi",   5));
    animaux.push_back(new Oiseau("Tweety", 2));
    animaux.push_back(new Chien ("Buddy",  1));

    cout << "=== Tous les animaux ===" << endl;
    for (Animal* a : animaux) {
        // LIGATURE DYNAMIQUE : l'appel résout au type RÉEL à l'exécution
        // même si le pointeur est de type Animal*
        a->decrire();
    }

    // ── Libération ───────────────────────────────────────────────────────
    // delete via pointeur de base → le destructeur virtuel garantit que
    // le destructeur de la bonne dérivée est appelé en premier
    for (Animal* a : animaux) delete a;
    animaux.clear();

    // ── Ligature statique vs dynamique ───────────────────────────────────
    cout << "\n=== Ligature statique vs dynamique ===" << endl;

    Animal* ptr = new Chien("Max", 4);

    // DYNAMIQUE : résolution à l'exécution → "Chien" et "Woof!"
    cout << "Via pointeur Animal* (dynamique) : " << ptr->parler() << endl;

    delete ptr;

    // SLICING : si on copie un dérivé dans un objet de base par valeur,
    // on perd la partie dérivée → impossible ici car Animal est abstraite,
    // mais avec une base concrète cela donnerait le comportement de la base.
    // Explication conceptuelle :
    cout << "\n[Note slicing]" << endl;
    cout << "Animal par valeur = copie superficielle du sous-objet Animal." << endl;
    cout << "Les méthodes virtuelles appelées seraient celles d'Animal, "
         << "pas de Chien." << endl;

    return 0;
}
