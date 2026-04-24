// demo-stl.cpp
// Démonstration : vector, string, map, stack, récursivité, tris
// IFT1166 — Chapitres 17-18
// Compiler : g++ -Wall -std=c++17 demo-stl.cpp -o demo-stl

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

// ─────────────────────────────────────────────
// Section 1 : vector<int>
// ─────────────────────────────────────────────
void sectionVector() {
    cout << "=== 1. vector<int> ===\n";
    vector<int> v = {5, 3, 8, 1, 4};

    v.push_back(7);
    cout << "Taille : " << v.size() << "\n";
    cout << "Éléments : ";
    for (const int& x : v) cout << x << " ";
    cout << "\n";

    sort(v.begin(), v.end());
    cout << "Trié    : ";
    for (const int& x : v) cout << x << " ";
    cout << "\n\n";
}

// ─────────────────────────────────────────────
// Section 2 : string
// ─────────────────────────────────────────────
void sectionString() {
    cout << "=== 2. string ===\n";
    string s = "bonjour";
    cout << "Longueur : " << s.length() << "\n";
    cout << "Majuscule (manuel) : ";
    for (char& c : s) cout << (char)(c - 32 * (c >= 'a' && c <= 'z'));
    cout << "\n";

    // Recherche
    string phrase = "le chat mange";
    size_t pos = phrase.find("chat");
    if (pos != string::npos)
        cout << "\"chat\" trouvé à l'index " << pos << "\n";

    cout << "Sous-chaîne [3,4] : " << phrase.substr(3, 4) << "\n\n";
}

// ─────────────────────────────────────────────
// Section 3 : map<string, int>
// ─────────────────────────────────────────────
void sectionMap() {
    cout << "=== 3. map<string, int> ===\n";
    map<string, int> notes;
    notes["Alice"] = 88;
    notes["Bob"]   = 72;
    notes["Eve"]   = 95;

    // Parcours trié par clé
    for (const auto& p : notes)
        cout << p.first << " : " << p.second << "\n";

    // Recherche sécurisée
    if (notes.count("Bob"))
        cout << "Note de Bob : " << notes["Bob"] << "\n";
    if (notes.find("Zara") == notes.end())
        cout << "Zara introuvable\n";

    notes.erase("Bob");
    cout << "Après suppression Bob : " << notes.size() << " entrées\n\n";
}

// ─────────────────────────────────────────────
// Section 4 : stack et queue
// ─────────────────────────────────────────────
void sectionPileFile() {
    cout << "=== 4. Pile (LIFO) ===\n";
    stack<int> pile;
    for (int x : {1, 2, 3, 4, 5}) pile.push(x);
    cout << "Dépilement : ";
    while (!pile.empty()) {
        cout << pile.top() << " ";
        pile.pop();
    }
    cout << "\n";

    cout << "=== 4b. File (FIFO) ===\n";
    queue<string> file;
    for (const string& s : {"Alice", "Bob", "Charlie"}) file.push(s);
    cout << "Défilement : ";
    while (!file.empty()) {
        cout << file.front() << " ";
        file.pop();
    }
    cout << "\n\n";
}

// ─────────────────────────────────────────────
// Section 5 : récursivité
// ─────────────────────────────────────────────
int factorielle(int n) {
    if (n <= 1) return 1;
    return n * factorielle(n - 1);
}

int pgcd(int a, int b) {
    if (b == 0) return a;
    return pgcd(b, a % b);
}

void sectionRecursivite() {
    cout << "=== 5. Récursivité ===\n";
    cout << "5! = " << factorielle(5) << "\n";
    cout << "7! = " << factorielle(7) << "\n";
    cout << "pgcd(48, 18) = " << pgcd(48, 18) << "\n\n";
}

// ─────────────────────────────────────────────
// Section 6 : recherche dichotomique
// ─────────────────────────────────────────────
int dichoto(const int tab[], int n, int cible) {
    int debut = 0, fin = n - 1;
    while (debut <= fin) {
        int milieu = (debut + fin) / 2;
        if (tab[milieu] == cible)  return milieu;
        if (tab[milieu] < cible)   debut = milieu + 1;
        else                        fin   = milieu - 1;
    }
    return -1;
}

void sectionRecherche() {
    cout << "=== 6. Recherche dichotomique ===\n";
    int tab[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = 10;
    cout << "Tableau : ";
    for (int i = 0; i < n; i++) cout << tab[i] << " ";
    cout << "\n";
    cout << "Index de 23 : " << dichoto(tab, n, 23) << "\n";   // 5
    cout << "Index de 99 : " << dichoto(tab, n, 99) << "\n\n"; // -1
}

// ─────────────────────────────────────────────
// Section 7 : tris
// ─────────────────────────────────────────────
void afficherTab(const int tab[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << tab[i];
        if (i < n - 1) cout << ",";
    }
    cout << "]";
}

void triSelection(int tab[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (tab[j] < tab[minIdx]) minIdx = j;
        swap(tab[i], tab[minIdx]);
    }
}

void triBulles(int tab[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (tab[j] > tab[j+1]) swap(tab[j], tab[j+1]);
}

void sectionTris() {
    cout << "=== 7. Tris ===\n";

    int a[] = {8, 6, 9, 3, 1};
    int b[] = {8, 6, 9, 3, 1};
    int n = 5;

    cout << "Avant : "; afficherTab(a, n); cout << "\n";

    triSelection(a, n);
    cout << "Tri sélection : "; afficherTab(a, n); cout << "\n";

    triBulles(b, n);
    cout << "Tri bulles     : "; afficherTab(b, n); cout << "\n";
}

int main() {
    sectionVector();
    sectionString();
    sectionMap();
    sectionPileFile();
    sectionRecursivite();
    sectionRecherche();
    sectionTris();
    return 0;
}
