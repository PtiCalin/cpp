// ============================================================================
// Exercice 10 — Préprocesseur et macros
// Thème : #define, include guards, compilation conditionnelle, macros.
// ============================================================================
//
// CONSIGNES :
//   1. Définir des constantes symboliques avec #define.
//   2. Créer des macros fonctionnelles (avec et sans parenthèses).
//   3. Démontrer le piège classique des macros (effets de bord).
//   4. Utiliser la compilation conditionnelle (#ifdef, #ifndef, #if).
//   5. Utiliser les macros prédéfinies (__FILE__, __LINE__, __DATE__, etc.).
//   6. Comparer macros vs constexpr / inline.
//
// CONCEPTS PRATIQUÉS :
//   - #define, #undef
//   - #ifdef, #ifndef, #endif, #if, #elif, #else
//   - Macros fonctionnelles et pièges
//   - Macros prédéfinies (__FILE__, __LINE__, __DATE__, __TIME__)
//   - constexpr (alternative moderne)
//   - Include guards (concept)
//
// ============================================================================

#include <iostream>
#include <cmath>

using namespace std;

// ---- Constantes symboliques -----------------------------------------------
#define PI        3.14159265358979
#define TAILLE    10
#define NOM_APP   "Exercice 10 - Macros"
#define VERSION   2

// ---- Macros fonctionnelles ------------------------------------------------
#define CARRE(x)         ((x) * (x))
#define MAX(a, b)        ((a) > (b) ? (a) : (b))
#define MIN(a, b)        ((a) < (b) ? (a) : (b))
#define ABS(x)           ((x) >= 0 ? (x) : -(x))
#define EST_PAIR(n)      ((n) % 2 == 0)
#define ENTRE(x, lo, hi) ((x) >= (lo) && (x) <= (hi))

// ---- Macro d'affichage avec debug -----------------------------------------
#define DEBUG_MODE

#ifdef DEBUG_MODE
    #define LOG(msg) cout << "[DEBUG " << __FILE__ << ":" << __LINE__ << "] " << msg << endl
#else
    #define LOG(msg)  // ne fait rien en mode release
#endif

// ---- Compilation conditionnelle de plateforme -----------------------------
#if defined(_WIN32) || defined(_WIN64)
    #define PLATEFORME "Windows"
#elif defined(__linux__)
    #define PLATEFORME "Linux"
#elif defined(__APPLE__)
    #define PLATEFORME "macOS"
#else
    #define PLATEFORME "Inconnue"
#endif

int main() {

    // -----------------------------------------------------------------------
    // PARTIE 1 : Constantes symboliques
    // -----------------------------------------------------------------------
    cout << "=== Partie 1 : Constantes symboliques ===" << endl;
    cout << "Application : " << NOM_APP << endl;
    cout << "Version     : " << VERSION << endl;
    cout << "PI          : " << PI << endl;
    cout << "TAILLE      : " << TAILLE << endl;

    double rayon = 5.0;
    double aire = PI * CARRE(rayon);
    cout << "Aire (r=5)  : " << aire << endl;

    // -----------------------------------------------------------------------
    // PARTIE 2 : Macros fonctionnelles
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 2 : Macros fonctionnelles ===" << endl;
    cout << "CARRE(7)        = " << CARRE(7) << endl;
    cout << "MAX(10, 20)     = " << MAX(10, 20) << endl;
    cout << "MIN(10, 20)     = " << MIN(10, 20) << endl;
    cout << "ABS(-42)        = " << ABS(-42) << endl;
    cout << "EST_PAIR(6)     = " << EST_PAIR(6) << endl;
    cout << "EST_PAIR(7)     = " << EST_PAIR(7) << endl;
    cout << "ENTRE(5, 1, 10) = " << ENTRE(5, 1, 10) << endl;
    cout << "ENTRE(15, 1, 10)= " << ENTRE(15, 1, 10) << endl;

    // -----------------------------------------------------------------------
    // PARTIE 3 : Piège des macros
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 3 : Pièges ===" << endl;

    // Piège 1 : sans parenthèses
    // Si on avait défini :  #define MAUVAIS_CARRE(x) x * x
    // alors MAUVAIS_CARRE(3+1) donnerait 3+1*3+1 = 7 au lieu de 16 !

    // Avec nos parenthèses correctes :
    cout << "CARRE(3+1)     = " << CARRE(3 + 1) << "  (correct : 16)" << endl;

    // Piège 2 : effets de bord avec ++
    int i = 5;
    // Attention : CARRE(i++) évalue i++ deux fois → comportement indéfini
    // Il vaut mieux utiliser une variable temporaire :
    int tmp = i++;
    cout << "CARRE(5) via tmp = " << CARRE(tmp) << "  (i est maintenant " << i << ")" << endl;

    // -----------------------------------------------------------------------
    // PARTIE 4 : Compilation conditionnelle
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 4 : Compilation conditionnelle ===" << endl;
    cout << "Plateforme : " << PLATEFORME << endl;

#if VERSION >= 2
    cout << "Fonctionnalité v2 activée." << endl;
#else
    cout << "Version ancienne." << endl;
#endif

    // LOG utilise #ifdef DEBUG_MODE
    LOG("Ceci est un message de débogage");
    LOG("Valeur de i = " << i);

    // -----------------------------------------------------------------------
    // PARTIE 5 : Macros prédéfinies
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 5 : Macros prédéfinies ===" << endl;
    cout << "__FILE__     : " << __FILE__ << endl;
    cout << "__LINE__     : " << __LINE__ << endl;
    cout << "__DATE__     : " << __DATE__ << endl;
    cout << "__TIME__     : " << __TIME__ << endl;
    cout << "__cplusplus  : " << __cplusplus << endl;

#ifdef __GNUC__
    cout << "Compilateur GCC version " << __GNUC__ << "." << __GNUC_MINOR__ << endl;
#elif defined(_MSC_VER)
    cout << "Compilateur MSVC version " << _MSC_VER << endl;
#endif

    // -----------------------------------------------------------------------
    // PARTIE 6 : Alternatives modernes
    // -----------------------------------------------------------------------
    cout << "\n=== Partie 6 : constexpr vs #define ===" << endl;

    // #define PI 3.14159...      → pas de type, pas de portée
    // constexpr double PI = ...  → typé, scopé, déboguable

    constexpr double PI_MODERN = 3.14159265358979;
    constexpr int TAILLE_MODERN = 10;

    cout << "constexpr PI       = " << PI_MODERN << endl;
    cout << "constexpr TAILLE   = " << TAILLE_MODERN << endl;

    // inline remplace les macros fonctionnelles
    // inline int carre(int x) { return x * x; }
    // Avantage : type-safe, pas d'effets de bord

    auto carreLambda = [](int x) { return x * x; };
    cout << "Lambda carré(7)    = " << carreLambda(7) << endl;

    cout << "\nRésumé : " << endl;
    cout << "  - #define  → utile pour l'include guard et la compilation conditionnelle" << endl;
    cout << "  - constexpr → préférer pour les constantes" << endl;
    cout << "  - inline    → préférer pour les fonctions simples" << endl;

    // Nettoyage
    #undef PI
    #undef TAILLE
    // Après #undef, PI et TAILLE ne sont plus définis

    return 0;
}
