# C++ Cheatsheet

> Quick reference for every essential C++ concept covered in this repository.
> Source: **IFT1166 — Programmation orientée objet en C++**, Université de Montréal, Hiver 2026.

---

## Table of Contents

1. [Program Structure](#1-program-structure)
2. [Variables & Data Types](#2-variables--data-types)
3. [Operators](#3-operators)
4. [Control Flow](#4-control-flow)
5. [Functions](#5-functions)
6. [Arrays & Vectors](#6-arrays--vectors)
7. [Strings](#7-strings)
8. [Pointers & References](#8-pointers--references)
9. [Dynamic Memory](#9-dynamic-memory)
10. [Preprocessor & Macros](#10-preprocessor--macros)
11. [Object-Oriented Programming](#11-object-oriented-programming)
12. [Operator Overloading](#12-operator-overloading)
13. [Inheritance & Polymorphism](#13-inheritance--polymorphism)
14. [File I/O](#14-file-io)
15. [Error Handling](#15-error-handling)
16. [STL Essentials](#16-stl-essentials)
17. [Useful Standard Library Headers](#17-useful-standard-library-headers)
18. [Multi-File Projects](#18-multi-file-projects)
19. [Compilation Quick Reference](#19-compilation-quick-reference)

---

## 1. Program Structure

```cpp
#include <iostream>       // standard library headers
#include "myheader.h"     // local project headers

using namespace std;

// Function prototypes
int maFonction(int param);

// Main entry point
int main() {
    cout << "Hello, World!" << endl;
    return 0;
}

// Function implementations
int maFonction(int param) {
    return param * 2;
}
```

> See [`squelette.cpp`](clean-examples/squelette.cpp) for a full template with macros, classes, and functions.

---

## 2. Variables & Data Types

### Fundamental types

| Type | Size (typical) | Example |
|---|---|---|
| `bool` | 1 byte | `true`, `false` |
| `char` | 1 byte | `'A'`, `'\n'` |
| `int` | 4 bytes | `42`, `-7` |
| `float` | 4 bytes | `3.14f` |
| `double` | 8 bytes | `3.14159265` |
| `string` | varies | `"hello"` (needs `<string>`) |

### Declaration & initialization

```cpp
int x = 10;                  // C-style
int y(20);                   // constructor-style
int z{30};                   // brace initialization (C++11)
auto w = 40;                 // type deduction (C++11)
const double PI = 3.14159;   // constant — cannot be modified
```

### Type casting

```cpp
double d = 3.7;
int i = static_cast<int>(d);     // explicit cast → 3
int j = (int)d;                  // C-style cast (avoid in C++)
```

---

## 3. Operators

### Arithmetic

| Op | Meaning | Example |
|---|---|---|
| `+` `-` `*` `/` | Basic math | `a + b` |
| `%` | Modulo (integers) | `7 % 3` → `1` |
| `++` `--` | Increment / decrement | `i++`, `--j` |

### Comparison & Logical

| Op | Meaning | Op | Meaning |
|---|---|---|---|
| `==` | Equal | `&&` | AND |
| `!=` | Not equal | `\|\|` | OR |
| `<` `>` `<=` `>=` | Relational | `!` | NOT |

### Ternary

```cpp
int max = (a > b) ? a : b;
```

### Assignment shortcuts

```cpp
x += 5;    // x = x + 5
x -= 3;    // x = x - 3
x *= 2;    // x = x * 2
x /= 4;    // x = x / 4
x %= 2;    // x = x % 2
```

---

## 4. Control Flow

### if / else if / else

```cpp
if (x > 0) {
    cout << "positif";
} else if (x < 0) {
    cout << "négatif";
} else {
    cout << "zéro";
}
```

### switch / case

```cpp
switch (choix) {
    case 1:
        cout << "Option 1";
        break;
    case 2:
        cout << "Option 2";
        break;
    default:
        cout << "Autre";
}
```

### Loops

```cpp
// for — classic
for (int i = 0; i < n; i++) {
    cout << i;
}

// for — range-based (C++11)
for (const auto& elem : monVecteur) {
    cout << elem;
}

// while
while (condition) {
    // ...
}

// do-while (runs at least once)
do {
    // ...
} while (condition);
```

### Loop control

```cpp
break;       // exit the loop immediately
continue;    // skip to the next iteration
```

---

## 5. Functions

### Basic syntax

```cpp
// Prototype (declaration)
double calculer(double x, double y);

// Implementation (definition)
double calculer(double x, double y) {
    return x * y;
}
```

### Parameter passing

```cpp
void parValeur(int x);                 // copy — original unchanged
void parReference(int& x);             // alias — modifies original
void parReferenceConst(const int& x);  // read-only alias — no copy, no modification
void parPointeur(int* ptr);            // via address
void avecTableau(const int arr[], int taille);  // arrays decay to pointers
```

### Default parameters

```cpp
double calculerAire(double r, double pi = 3.14159) {
    return pi * r * r;
}
// calculerAire(5)      → uses default pi
// calculerAire(5, 3.0) → overrides pi
```

### Function overloading

```cpp
int     additionner(int a, int b);
double  additionner(double a, double b);
string  additionner(string a, string b);
// Compiler picks the right one based on argument types
```

### Lambda expressions (C++11)

```cpp
auto carre = [](int x) { return x * x; };
cout << carre(5);  // 25

// With capture
int facteur = 3;
auto multiplier = [facteur](int x) { return x * facteur; };

// In sort()
sort(vec.begin(), vec.end(), [](int a, int b) { return a > b; });
```

### `std::function` (for callbacks)

```cpp
#include <functional>
double calculerDerivee(function<double(double)> f, double x) {
    double h = 1e-7;
    return (f(x + h) - f(x - h)) / (2 * h);
}
// Usage:
calculerDerivee([](double x) { return x * x; }, 3.0);
```

> See [`methodes.h`](fundamentals/functions/methodes.h) for 150+ function examples.

---

## 6. Arrays & Vectors

### C-style arrays

```cpp
int arr[5] = {1, 2, 3, 4, 5};
int taille = sizeof(arr) / sizeof(arr[0]);  // → 5

// Iterate
for (int i = 0; i < taille; i++) {
    cout << arr[i] << " ";
}
```

### 2D arrays

```cpp
int matrice[3][4];
matrice[0][0] = 1;

for (int i = 0; i < 3; i++)
    for (int j = 0; j < 4; j++)
        cout << matrice[i][j];
```

### `vector` (dynamic array)

```cpp
#include <vector>

vector<int> v;               // empty
vector<int> v2(10, 0);       // 10 elements, all 0
vector<int> v3 = {1, 2, 3};  // initializer list

v.push_back(42);             // add to end
v.pop_back();                // remove last
v.size();                    // element count
v.empty();                   // true if size == 0
v.erase(v.begin() + 2);     // remove element at index 2
v[0];                        // access by index
v.at(0);                     // access with bounds checking

// 2D vector
vector<vector<double>> matrice(3, vector<double>(4, 0.0));
```

### Common operations

```cpp
#include <algorithm>

sort(v.begin(), v.end());                           // ascending
sort(v.begin(), v.end(), greater<int>());            // descending
reverse(v.begin(), v.end());
auto it = find(v.begin(), v.end(), 42);              // search
auto maxIt = max_element(v.begin(), v.end());
auto minIt = min_element(v.begin(), v.end());
```

---

## 7. Strings

```cpp
#include <string>

string s = "Bonjour";
string s2 = s + " monde";        // concatenation
int len = s.length();             // or s.size()
char c = s[0];                    // 'B'
string sub = s.substr(0, 3);     // "Bon"

// Searching
size_t pos = s.find("jour");     // 3 (or string::npos if not found)
if (s.find("xyz") != string::npos) { /* found */ }

// Modification
s.replace(0, 3, "Sal");          // "Salour"
s.erase(3, 2);                   // remove 2 chars starting at index 3
s.insert(3, "ut ");              // insert at position
s.append("!");                   // add to end

// Conversion
int n = stoi("42");              // string → int
double d = stod("3.14");         // string → double
string ns = to_string(42);      // int → string

// Character checks
#include <cctype>
isupper(c)    isalpha(c)    isdigit(c)    isspace(c)
toupper(c)    tolower(c)
```

---

## 8. Pointers & References

### Pointers

```cpp
int x = 10;
int* ptr = &x;        // ptr holds the address of x
cout << *ptr;          // dereference → 10
*ptr = 20;             // modifies x through ptr

int* nul = nullptr;    // null pointer (C++11)
if (ptr != nullptr) {  // always check before dereferencing
    cout << *ptr;
}
```

### Arrow operator (for pointer to struct/class)

```cpp
struct Personne { string nom; };

Personne p = {"Alice"};
Personne* ptr = &p;
cout << ptr->nom;      // same as (*ptr).nom
```

### References

```cpp
int x = 10;
int& ref = x;     // ref is an alias for x
ref = 20;          // x is now 20

// References can't be null, can't be reassigned, must be initialized
```

> See [`classes.h`](oop/classes-basics/classes.h) — `ListeChainee` and `ArbreBinaire` use pointer-based data structures.

---

## 9. Dynamic Memory

### `new` and `delete`

```cpp
// Single object
int* ptr = new int(42);
delete ptr;
ptr = nullptr;            // good practice

// Array
int* arr = new int[100];
delete[] arr;
arr = nullptr;

// Object
Personne* p = new Personne("Alice");
delete p;
p = nullptr;
```

### Memory management macros (from this repo)

```cpp
// Defined in macros.h:
ALLOUER(int, 100)          // new int[100]
DEALLOUER(ptr)             // delete[] ptr; ptr = nullptr
ALLOUER_OBJET(Personne)   // new Personne
DEALLOUER_OBJET(ptr)       // delete ptr; ptr = nullptr
```

> **Rule of thumb**: every `new` must have a matching `delete`. Every `new[]` must have a `delete[]`.

---

## 10. Preprocessor & Macros

### Constants

```cpp
#define PI 3.14159265
#define TAILLE_MAX 100
```

### Function-like macros

```cpp
#define CARRE(x)       ((x) * (x))
#define MAX(a, b)      ((a) > (b) ? (a) : (b))
#define SWAP(a, b)     { auto temp = a; a = b; b = temp; }
```

> Always wrap parameters in parentheses to avoid operator-precedence bugs.

### Conditional compilation

```cpp
#define DEBUG_MODE

#ifdef DEBUG_MODE
    #define DEBUG(msg) cerr << "[DEBUG] " << msg << endl
#else
    #define DEBUG(msg)    // compiles to nothing
#endif
```

### Stringification

```cpp
#define AFFICHER(x) cout << #x << " = " << (x) << endl
// AFFICHER(total)  →  cout << "total" << " = " << (total) << endl
```

### Include guards (for header files)

```cpp
#ifndef MON_HEADER_H
#define MON_HEADER_H

// ... declarations ...

#endif
```

> See [`macros.h`](macros/macros.h) for a full macro library (conversion, math, physics, chemistry, debug, memory).

---

## 11. Object-Oriented Programming

### Class basics

```cpp
class Rectangle {
private:                           // accessible only within the class
    double largeur;
    double hauteur;

public:                            // accessible from outside
    // Default constructor
    Rectangle() : largeur(0), hauteur(0) {}

    // Parameterized constructor (with initializer list)
    Rectangle(double l, double h) : largeur(l), hauteur(h) {}

    // Getters (const — don't modify the object)
    double getLargeur() const { return largeur; }
    double getHauteur() const { return hauteur; }

    // Setters
    void setLargeur(double l) { largeur = l; }
    void setHauteur(double h) { hauteur = h; }

    // Methods
    double aire() const { return largeur * hauteur; }
    double perimetre() const { return 2 * (largeur + hauteur); }

    // Display
    void afficher() const {
        cout << largeur << " x " << hauteur << endl;
    }
};
```

### Constructors

```cpp
// Default constructor
MaClasse();

// Parameterized constructor
MaClasse(int a, double b);

// Initializer list (preferred — more efficient)
MaClasse(int a, double b) : attributA(a), attributB(b) {}

// Default parameter values
Point(double x = 0, double y = 0) : x(x), y(y) {}
```

### Composition (class contains another class)

```cpp
class Cercle {
private:
    Point centre;       // ← contains a Point object
    double rayon;
public:
    Cercle(Point c, double r) : centre(c), rayon(r) {}
    double aire() const { return 3.14159 * rayon * rayon; }
};
```

### Static members

```cpp
class AlgorithmeTri {
public:
    static void triBulle(vector<int>& v) {
        // ... sorting logic ...
    }
};

// Call without an instance:
AlgorithmeTri::triBulle(monVecteur);
```

> See [`classes.h`](oop/classes-basics/classes.h) for 50+ class examples.

---

## 12. Operator Overloading

```cpp
class Matrice {
private:
    vector<vector<double>> elements;
    int lignes, colonnes;
public:
    // Arithmetic operators (return new object)
    Matrice operator+(const Matrice& autre) const {
        Matrice resultat(lignes, colonnes);
        for (int i = 0; i < lignes; i++)
            for (int j = 0; j < colonnes; j++)
                resultat.elements[i][j] = elements[i][j] + autre.elements[i][j];
        return resultat;
    }

    // Comparison operator
    bool operator==(const Matrice& autre) const {
        return elements == autre.elements;
    }

    bool operator<(const Matrice& autre) const {
        return lignes * colonnes < autre.lignes * autre.colonnes;
    }

    // Stream insertion (must be friend for lhs = ostream)
    friend ostream& operator<<(ostream& os, const Matrice& m) {
        for (auto& ligne : m.elements) {
            for (auto& val : ligne)
                os << val << " ";
            os << endl;
        }
        return os;
    }
};
```

### Common overloadable operators

| Category | Operators |
|---|---|
| Arithmetic | `+`, `-`, `*`, `/`, `%` |
| Comparison | `==`, `!=`, `<`, `>`, `<=`, `>=` |
| Assignment | `+=`, `-=`, `*=`, `/=` |
| Stream | `<<` (output), `>>` (input) — typically as `friend` |
| Subscript | `[]` |
| Function call | `()` |

---

## 13. Inheritance & Polymorphism

### Basic inheritance

```cpp
class Base {
protected:              // accessible by derived classes
    int valeur;
public:
    Base(int v) : valeur(v) {}
    void afficher() const { cout << "Base: " << valeur << endl; }
};

class Derivee : public Base {
private:
    string extra;
public:
    // Call parent constructor in initializer list
    Derivee(int v, string e) : Base(v), extra(e) {}

    // Override parent method
    void afficher() const {
        Base::afficher();                      // call parent version
        cout << "Extra: " << extra << endl;    // add own behavior
    }
};
```

### Access specifiers in inheritance

| Specifier | In derived class |
|---|---|
| `public` | `public` stays `public`, `protected` stays `protected` |
| `protected` | Both become `protected` |
| `private` | Both become `private` |

### Usage

```cpp
Derivee d(42, "bonus");
d.afficher();          // calls Derivee::afficher() → then Base::afficher()
```

> See [`squelette.cpp`](clean-examples/squelette.cpp) — `Derivee : public Base` with method redefinition.
> See [`classes.h`](oop/classes-basics/classes.h) — `CalculatriceScientifique : public CalculatriceSimple`.

---

## 14. File I/O

### Reading a file

```cpp
#include <fstream>
#include <string>

// Read entire file
ifstream fichier("data.txt");
if (fichier.is_open()) {
    string ligne;
    while (getline(fichier, ligne)) {
        cout << ligne << endl;
    }
    fichier.close();
}
```

### Writing to a file

```cpp
// Overwrite
ofstream fichier("output.txt");
fichier << "Ligne 1" << endl;
fichier << "Ligne 2" << endl;
fichier.close();

// Append
ofstream fichierAppend("output.txt", ios::app);
fichierAppend << "Ligne ajoutée" << endl;
fichierAppend.close();
```

### Binary files

```cpp
// Write binary
ofstream out("data.bin", ios::binary);
int val = 42;
out.write(reinterpret_cast<char*>(&val), sizeof(val));
out.close();

// Read binary
ifstream in("data.bin", ios::binary);
int result;
in.read(reinterpret_cast<char*>(&result), sizeof(result));
in.close();
```

### CSV

```cpp
// Read CSV
ifstream csv("data.csv");
string ligne;
while (getline(csv, ligne)) {
    stringstream ss(ligne);
    string cellule;
    while (getline(ss, cellule, ',')) {
        cout << cellule << " | ";
    }
    cout << endl;
}
```

### C++17 filesystem

```cpp
#include <filesystem>
namespace fs = std::filesystem;

fs::exists("file.txt");              // check existence
fs::file_size("file.txt");           // file size in bytes
fs::copy_file("a.txt", "b.txt");     // copy
fs::rename("old.txt", "new.txt");    // move/rename
fs::remove("file.txt");              // delete
fs::create_directory("dossier");     // create directory

// List files in directory
for (auto& entry : fs::directory_iterator("dossier")) {
    cout << entry.path() << endl;
}
```

> See [`file-handling.cpp`](file-handling/file-handling.cpp) for 60+ file I/O utilities.

---

## 15. Error Handling

### try / catch / throw

```cpp
#include <stdexcept>

double diviser(double a, double b) {
    if (b == 0)
        throw invalid_argument("Division par zéro!");
    return a / b;
}

int main() {
    try {
        double resultat = diviser(10, 0);
    } catch (const invalid_argument& e) {
        cerr << "Erreur: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Erreur générale: " << e.what() << endl;
    }
}
```

### Common exception types

| Type | Use case |
|---|---|
| `runtime_error` | General runtime failures |
| `invalid_argument` | Bad function argument |
| `out_of_range` | Index/value out of range |
| `logic_error` | Programming logic error |
| `exception` | Base class — catches all standard exceptions |

---

## 16. STL Essentials

### Containers

| Container | Description | Access | Example |
|---|---|---|---|
| `vector<T>` | Dynamic array | `[]`, `.at()` | `vector<int> v = {1,2,3};` |
| `pair<T1,T2>` | Two-value tuple | `.first`, `.second` | `pair<int,string> p = {1, "a"};` |
| `map<K,V>` | Key-value store (sorted) | `[key]` | `map<string,int> m;` |
| `string` | Character sequence | `[]`, `.at()` | `string s = "hello";` |

### Algorithms (`<algorithm>`)

```cpp
sort(v.begin(), v.end());                          // sort ascending
sort(v.begin(), v.end(), greater<int>());           // sort descending
sort(v.begin(), v.end(), [](int a, int b) {         // custom comparator (lambda)
    return a > b;
});

reverse(v.begin(), v.end());
auto it = find(v.begin(), v.end(), target);
int cnt = count(v.begin(), v.end(), target);
auto maxIt = max_element(v.begin(), v.end());
auto minIt = min_element(v.begin(), v.end());
```

### Iterators

```cpp
for (auto it = v.begin(); it != v.end(); ++it) {
    cout << *it << " ";
}
// Equivalent to range-based for:
for (const auto& elem : v) {
    cout << elem << " ";
}
```

### I/O Manipulators (`<iomanip>`)

```cpp
cout << fixed << setprecision(2) << 3.14159;   // "3.14"
cout << setw(10) << setfill('.') << 42;          // "........42"
cout << hex << 255;                              // "ff"
cout << boolalpha << true;                       // "true"
```

---

## 17. Useful Standard Library Headers

| Header | What it provides |
|---|---|
| `<iostream>` | `cin`, `cout`, `cerr`, `endl` |
| `<fstream>` | `ifstream`, `ofstream` (file I/O) |
| `<sstream>` | `stringstream` (string parsing/building) |
| `<string>` | `string` class |
| `<vector>` | `vector<T>` (dynamic arrays) |
| `<map>` | `map<K,V>` (sorted key-value pairs) |
| `<algorithm>` | `sort`, `find`, `reverse`, `max_element`, etc. |
| `<cmath>` | `pow`, `sqrt`, `sin`, `cos`, `log`, `exp`, `fabs`, `ceil`, `floor`, `round` |
| `<cstdlib>` | `rand`, `srand`, `abs`, `system` |
| `<cctype>` | `toupper`, `tolower`, `isdigit`, `isalpha`, `isspace` |
| `<iomanip>` | `setprecision`, `setw`, `setfill`, `fixed`, `hex` |
| `<stdexcept>` | `runtime_error`, `invalid_argument`, `out_of_range` |
| `<functional>` | `function<>`, `greater<>` |
| `<regex>` | `regex`, `regex_search`, `regex_replace` |
| `<filesystem>` | `path`, `exists`, `directory_iterator` (C++17) |
| `<chrono>` | `system_clock`, `milliseconds`, `duration_cast` |
| `<thread>` | `sleep_for`, `thread` |
| `<mutex>` | `mutex`, `lock_guard` |

---

## 18. Multi-File Projects

### Structure

```
project/
├── main.cpp           ← entry point
├── Employee.h         ← class declaration
├── Employee.cpp       ← class implementation
├── utils.h            ← utility function prototypes
└── utils.cpp          ← utility function implementations
```

### Header file (`.h`) — declaration only

```cpp
// Employee.h
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
private:
    std::string nom;
    double salaire;
public:
    Employee(const std::string& n, double s);
    std::string getNom() const;
    double getSalaire() const;
    void afficher() const;
};

#endif
```

### Source file (`.cpp`) — implementation

```cpp
// Employee.cpp
#include "Employee.h"
#include <iostream>

Employee::Employee(const std::string& n, double s)
    : nom(n), salaire(s) {}

std::string Employee::getNom() const { return nom; }
double Employee::getSalaire() const { return salaire; }

void Employee::afficher() const {
    std::cout << nom << " — $" << salaire << std::endl;
}
```

### Main file

```cpp
// main.cpp
#include "Employee.h"

int main() {
    Employee e("Alice", 75000);
    e.afficher();
    return 0;
}
```

> **Key rules:**
> - Never put `using namespace std;` in headers — use `std::` prefix
> - Always use include guards (`#ifndef` / `#define` / `#endif`)
> - Only `#include` what you need

---

## 19. Compilation Quick Reference

### g++ commands

```bash
# Single file
g++ -std=c++17 -Wall -Wextra -g main.cpp -o app

# Multi-file
g++ -std=c++17 -Wall -Wextra -g main.cpp Employee.cpp utils.cpp -o app

# With sanitizers (memory debugging)
g++ -std=c++17 -g -fsanitize=address,undefined main.cpp -o app
```

### Key flags

| Flag | Purpose |
|---|---|
| `-std=c++17` | Use C++17 standard |
| `-Wall -Wextra` | Enable warnings |
| `-g` | Debug symbols |
| `-O2` | Optimization |
| `-o name` | Output filename |
| `-I./path` | Add include directory |
| `-fsanitize=address` | Memory error detection |

### IDE shortcuts

| Action | Visual Studio | Dev-C++ | VS Code |
|---|---|---|---|
| Build | `Ctrl+Shift+B` | `F9` | `Ctrl+Shift+B` |
| Run | `Ctrl+F5` | `F10` | `Ctrl+F5` |
| Build & Run | — | `F11` | — |
| Debug | `F5` | `F7` | `F5` |
| Toggle breakpoint | `F9` | `F5` | `F9` |
| Step Over | `F10` | `F8` | `F10` |
| Step Into | `F11` | `Shift+F8` | `F11` |

> See [`build-notes/`](build-notes/) for full tool-specific guides.

---

## Quick Patterns Reference

| Pattern | Syntax |
|---|---|
| Include guard | `#ifndef X_H` / `#define X_H` / `#endif` |
| Initializer list | `MaClasse(int a) : attr(a) {}` |
| `const` method | `double aire() const { ... }` |
| Range-based for | `for (const auto& e : v) { ... }` |
| Lambda | `[capture](params) { body }` |
| Smart pointer | `unique_ptr<T> p = make_unique<T>(args);` |
| Friend function | `friend ostream& operator<<(ostream&, const T&);` |
| Pass by const ref | `void f(const vector<int>& v)` |
| Ternary | `(cond) ? valeurVrai : valeurFaux` |
| Null pointer | `nullptr` |

---

> **Full source files**: [`macros.h`](macros/macros.h) · [`methodes.h`](fundamentals/functions/methodes.h) · [`classes.h`](oop/classes-basics/classes.h) · [`file-handling.cpp`](file-handling/file-handling.cpp) · [`squelette.cpp`](clean-examples/squelette.cpp)
