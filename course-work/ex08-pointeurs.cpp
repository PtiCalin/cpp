// ============================================================================
// Exercice 08 — Pointeurs et références
// Thème : adresse-mémoire, déréférencement, opérateur ->, nullptr, arithmétique.
// ============================================================================
//
// CONSIGNES :
//   1. Déclarer des pointeurs, afficher adresses et valeurs.
//   2. Comparer référence et pointeur (alias vs adresse).
//   3. Passer des pointeurs aux fonctions (modifier la valeur pointée).
//   4. Pointer sur un tableau et parcourir avec l'arithmétique de pointeurs.
//   5. Pointeurs constants (const int*, int* const, const int* const).
//   6. nullptr et vérification de validité.
//
// CONCEPTS PRATIQUÉS :
//   - Opérateurs & (adresse-de) et * (déréférencement)
//   - Pointeur vs référence
//   - Passage de pointeur à fonction
//   - Arithmétique de pointeurs (p++, p+i, p-q)
//   - Qualificateurs const avec pointeurs
//   - nullptr (C++11)
//
// ============================================================================

#include <iostream>
#include <iomanip>

using namespace std;

// ---- Prototypes -----------------------------------------------------------
void doubler(int* p);
void echanger(int* a, int* b);
void afficherTableau(const int* debut, int taille);

// ---- main -----------------------------------------------------------------
int main() {

    // -----------------------------------------------------------------------
    // PARTIE 1 : Bases des pointeurs
    // -----------------------------------------------------------------------
    cout << "=== Partie 1 : Bases des pointeurs ===" << endl;

    int x = 42;
    int* px = &x;   // px pointe sur x

    cout << "x      = " << x << endl;
    cout << "&x     = " << &x << endl;
    cout << "px     = " << px << "  (adresse stockée)" << endl;
    cout << "*px    = " << *px << "  (déréférencement)" << endl;

    *px = 100;  // modifier via le pointeur
    cout << "Après *px = 100 : x = " << x << endl;

    // Taille d'un pointeur
    cout << "sizeof(px)  = " << sizeof(px) << " octets" << endl;
    cout << "sizeof(int) = " << sizeof(int) << " octets" << endl;

    // -----------------------------------------------------------------------
    // PARTIE 2 : Référence vs pointeur
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 2 : Référence vs Pointeur ===" << endl;

    int a = 10;
    int& refA = a;     // référence (alias)
    int* ptrA = &a;    // pointeur

    cout << "a       = " << a << endl;
    cout << "refA    = " << refA << "  (même objet)" << endl;
    cout << "*ptrA   = " << *ptrA << "  (déréférencement)" << endl;
    cout << "&a      = " << &a << endl;
    cout << "&refA   = " << &refA << "  (même adresse !)" << endl;

    refA = 20;
    cout << "Après refA=20 : a=" << a << endl;

    *ptrA = 30;
    cout << "Après *ptrA=30 : a=" << a << endl;

    // Note : une référence ne peut PAS être réaffectée
    //        un pointeur peut pointer ailleurs

    // -----------------------------------------------------------------------
    // PARTIE 3 : Pointeurs en paramètre
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 3 : Fonctions avec pointeurs ===" << endl;

    int n = 7;
    cout << "n avant doubler : " << n << endl;
    doubler(&n);
    cout << "n après doubler : " << n << endl;

    int p = 10, q = 20;
    cout << "Avant échanger : p=" << p << ", q=" << q << endl;
    echanger(&p, &q);
    cout << "Après échanger : p=" << p << ", q=" << q << endl;

    // -----------------------------------------------------------------------
    // PARTIE 4 : Pointeurs et tableaux
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 4 : Pointeurs et tableaux ===" << endl;

    int tab[] = {10, 20, 30, 40, 50};
    int taille = sizeof(tab) / sizeof(tab[0]);

    // Le nom du tableau est un pointeur vers le premier élément
    cout << "tab       = " << tab << endl;
    cout << "&tab[0]   = " << &tab[0] << "  (même chose)" << endl;
    cout << "*tab      = " << *tab << endl;
    cout << "*(tab+2)  = " << *(tab + 2) << "  (= tab[2])" << endl;

    // Parcours avec arithmétique de pointeurs
    cout << "Parcours par pointeur : ";
    for (int* p = tab; p < tab + taille; p++) {
        cout << *p << " ";
    }
    cout << endl;

    // Affichage via fonction
    cout << "Via fonction  : ";
    afficherTableau(tab, taille);

    // Distance entre pointeurs
    int* debut = &tab[0];
    int* fin   = &tab[4];
    cout << "Distance (fin - debut) = " << (fin - debut) << " éléments" << endl;

    // -----------------------------------------------------------------------
    // PARTIE 5 : Pointeurs et const
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 5 : const et pointeurs ===" << endl;

    int val1 = 100, val2 = 200;

    // 1) Pointeur vers constant : on ne peut pas modifier *p
    const int* pc = &val1;
    cout << "const int* pc → *pc = " << *pc << endl;
    // *pc = 999;       // ERREUR : ne peut pas modifier la valeur
    pc = &val2;         // OK : on peut changer l'adresse
    cout << "pc pointe maintenant sur val2 → *pc = " << *pc << endl;

    // 2) Pointeur constant : on ne peut pas changer l'adresse
    int* const cp = &val1;
    cout << "int* const cp → *cp = " << *cp << endl;
    *cp = 999;          // OK : on peut modifier la valeur
    // cp = &val2;      // ERREUR : ne peut pas changer l'adresse
    cout << "Après *cp=999 → val1 = " << val1 << endl;

    // 3) Les deux : const int* const
    const int* const cpc = &val2;
    cout << "const int* const → *cpc = " << *cpc << endl;
    // *cpc = 1;        // ERREUR
    // cpc = &val1;     // ERREUR

    // -----------------------------------------------------------------------
    // PARTIE 6 : nullptr
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 6 : nullptr ===" << endl;

    int* pNull = nullptr;  // C++11 : préférer nullptr à NULL ou 0

    if (pNull == nullptr) {
        cout << "pNull est nul (nullptr)." << endl;
    }

    // Toujours vérifier avant de déréférencer
    if (pNull != nullptr) {
        cout << *pNull << endl;
    } else {
        cout << "Protection : on ne déréférence pas un nullptr !" << endl;
    }

    // Bonne pratique : remettre à nullptr après delete
    int* pDyn = new int(42);
    cout << "pDyn = " << *pDyn << endl;
    delete pDyn;
    pDyn = nullptr;  // évite un dangling pointer
    cout << "pDyn remis à nullptr après delete." << endl;

    return 0;
}

// ---- Implémentations ------------------------------------------------------

void doubler(int* p) {
    if (p != nullptr) {
        *p *= 2;
    }
}

void echanger(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void afficherTableau(const int* debut, int taille) {
    for (int i = 0; i < taille; i++) {
        cout << *(debut + i) << " ";
    }
    cout << endl;
}
