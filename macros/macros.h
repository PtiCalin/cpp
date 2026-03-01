/* Fichier   : macros.h    
	Auteure  : Charlie Bouchard    
	Cours    : IFT1166 - Programmation orientée objet en C++    
	Trimestre: Hiver 2026
	But      : Inventaire de macros et constantes
	Dernière mise à jour : 2026-02-26
*/

/*  TABLE DES MATIÈRES
    ══════════════════
     1. Conversion
        1.1 Temps
        1.2 Longueur
        1.3 Masse
        1.4 Angles
        1.5 Température
     2. Mathématiques
        2.1 Constantes mathématiques
        2.2 Valeurs trigonométriques
        2.3 Opérations de base
        2.4 Géométrie
     3. Physique
        3.1 Constantes physiques
        3.2 Formules physiques
     4. Chimie
        4.1 Constantes chimiques
        4.2 Masses molaires
        4.3 Formules chimiques
     5. Débogage et affichage
     6. Tableaux et limites
        6.1 Tailles et tableaux
        6.2 Limites numériques
     7. Gestion de la mémoire
*/

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>    
#include <cstdlib>
#include <functional>
#include <limits>
#include <stdexcept>
#include <utility>

#include "methodes.h"
#include "classes.h"

using namespace std;

/* ═══════════════════════════════════════════════════════════════
   1. CONVERSION
   ═══════════════════════════════════════════════════════════════ */

    // ─── 1.1 Temps ───

        #define JOURS_DANS_ANNEE 365.25
        #define MOIS_DANS_ANNEE 12
        #define SEMAINES_DANS_ANNEE 52
        #define HEURES_DANS_JOUR 24
        #define MINUTES_DANS_HEURE 60
        #define SECONDES_DANS_MINUTE 60

    // ─── 1.2 Longueur ───

        #define POUCES_DANS_PIED 12
        #define PIEDS_DANS_YARD 3
        #define POUCES_DANS_METRE 39.3701
        #define KM_DANS_MILE 1.60934

    // ─── 1.3 Masse ───

        #define KG_DANS_LIVRE 0.453592
        #define LITRES_DANS_GALLON 3.78541
        
    // ─── 1.4 Angles ───

        #define DEGRES_DANS_CERCLE 360
        #define RADIANS_DANS_CERCLE 2 * PI

    // ─── 1.5 Température ───
        #define CELSIUS_VERS_FAHRENHEIT(c) ((c) * 9.0 / 5.0 + 32)
        #define FAHRENHEIT_VERS_CELSIUS(f) (((f) - 32) * 5.0 / 9.0)
        #define CELSIUS_VERS_KELVIN(c) ((c) + 273.15)
        #define KELVIN_VERS_CELSIUS(k) ((k) - 273.15)
        #define FARENHEIT_VERS_KELVIN(f) (((f) - 32) * 5.0 / 9.0 + 273.15)
        #define KELVIN_VERS_FARENHEIT(k) (((k) - 273.15) * 9.0 / 5.0 + 32)
        
/* ═══════════════════════════════════════════════════════════════
   2. MATHÉMATIQUES
   ═══════════════════════════════════════════════════════════════ */

    // ─── 2.1 Constantes mathématiques ───

            #define PI 3.14159
            #define EULER 2.71828
            #define PHI 1.61803
            #define TAU 6.28318
            #define SQRT2 1.41421
            #define SQRT3 1.73205
            #define LOG10E 0.43429

    // ─── 2.2 Valeurs trigonométriques ───

            #define SIN30 0.5
            #define COS30 0.86603
            #define TAN30 0.57735
            #define SIN45 0.70711
            #define COS45 0.70711
            #define TAN45 1.0
            #define SIN60 0.86603
            #define COS60 0.5
            #define TAN60 1.73205
            #define SIN90 1.0
            #define COS90 0.0
            #define TAN90 INFINITY

    // ─── 2.3 Opérations de base ───
            #define CARRE(x) ((x) * (x))
            #define CUBE(x) ((x) * (x) * (x))
            #define PUISSANCE(x, n) (pow((x), (n)))
            #define FACTORIELLE(n) (calculerFactorielle(n))
            #define LOGARITHME(x, base) (calculerLogarithme((x), (base)))
            #define EXPONENTIELLE(x) (calculerExponentielle(x))
            #define SIGNE(x) ((x) > 0 ? 1 : ((x) < 0 ? -1 : 0))
            #define SWAP(a, b) { auto temp = (a); (a) = (b); (b) = temp; }
            #define ENTRE(x, lo, hi) ((x) >= (lo) && (x) <= (hi))
            #define EST_PAIR(n) ((n) % 2 == 0)
            #define EST_IMPAIR(n) ((n) % 2 != 0)
            #define ARRONDIR(x) ((int)((x) + 0.5))
            #define PLAFOND(x) ((int)(x) + ((x) > (int)(x) ? 1 : 0))
            #define PLANCHER(x) ((int)(x))
            #define POURCENTAGE(partie, total) (((partie) * 100.0) / (total))

    // ─── 2.4 Géométrie ───

            #define AIRE_CERCLE(r) (PI * CARRE(r))
            #define PERIMETRE_CERCLE(r) (2 * PI * (r))
            #define AIRE_RECTANGLE(l, w) ((l) * (w))
            #define PERIMETRE_RECTANGLE(l, w) (2 * ((l) + (w)))
            #define AIRE_TRIANGLE(b, h) (0.5 * (b) * (h))
            #define VOLUME_SPHERE(r) ((4.0 / 3.0) * PI * CUBE(r))
            #define SURFACE_SPHERE(r) (4 * PI * CARRE(r))
            #define VOLUME_CYLINDRE(r, h) (PI * CARRE(r) * (h))
            #define VOLUME_CONE(r, h) ((1.0 / 3.0) * PI * CARRE(r) * (h))
            #define HYPOTHENUSE(a, b) (sqrt(CARRE(a) + CARRE(b)))
            #define DISTANCE_2D(x1, y1, x2, y2) (sqrt(CARRE((x2)-(x1)) + CARRE((y2)-(y1))))
            #define DISTANCE_3D(x1, y1, z1, x2, y2, z2) (sqrt(CARRE((x2)-(x1)) + CARRE((y2)-(y1)) + CARRE((z2)-(z1))))
            #define ANGLE_ENTRE_VECTEURS(x1, y1, x2, y2) (acos(((x1)*(x2) + (y1)*(y2)) / (sqrt(CARRE(x1) + CARRE(y1)) * sqrt(CARRE(x2) + CARRE(y2)))))
            #define PYTHAGORE(a, b) (sqrt(CARRE(a) + CARRE(b)))

/* ═══════════════════════════════════════════════════════════════
   3. PHYSIQUE
   ═══════════════════════════════════════════════════════════════ */

    // ─── 3.1 Constantes physiques ───

            #define GRAVITE_SUR_TERRE 9.81
            #define VITESSE_LUMIERE 299792458
            #define PLANCK 6.62607015e-34
            #define GAS_CONSTANT 8.314462618
            #define BOLTZMANN 1.380649e-23
            #define FARADAY 96485.33212

    // ─── 3.2 Formules physiques ───

            #define VITESSE(distance, temps) ((distance) / (temps))
            #define ACCELERATION(vf, vi, temps) (((vf) - (vi)) / (temps))
            #define FORCE(masse, acceleration) ((masse) * (acceleration))
            #define ENERGIE_CINETIQUE(masse, vitesse) (0.5 * (masse) * CARRE(vitesse))
            #define ENERGIE_POTENTIELLE(masse, hauteur) ((masse) * GRAVITE_SUR_TERRE * (hauteur))
            #define TRAVAIL(force, distance) ((force) * (distance))
            #define PUISSANCE(travail, temps) ((travail) / (temps))
            #define PRESSION(force, surface) ((force) / (surface))
            #define DENSITE(masse, volume) ((masse) / (volume))
            #define QUANTITE_MOUVEMENT(masse, vitesse) ((masse) * (vitesse))
            #define FREQUENCE(periode) (1.0 / (periode))
            #define PERIODE(frequence) (1.0 / (frequence))
            #define LOI_OHM_V(i, r) ((i) * (r))
            #define LOI_OHM_I(v, r) ((v) / (r))
            #define LOI_OHM_R(v, i) ((v) / (i))
            #define PUISSANCE_ELECTRIQUE(v, i) ((v) * (i))

/* ═══════════════════════════════════════════════════════════════
   4. CHIMIE
   ═══════════════════════════════════════════════════════════════ */

    // ─── 4.1 Constantes chimiques ───

            #define ELEMENTS_TABLEAU_PERIODIQUE 118
            #define MOLECULES_DANS_MOL 6.02214076e23
            #define AVOGADRO 6.02214076e23
            #define MASSE_ELECTRON 9.10938356e-31
            #define MASSE_PROTON 1.6726219e-27
            #define MASSE_NEUTRON 1.674927471e-27

    // ─── 4.2 Masses molaires (en g/mol) ───

            #define MASSE_MOLAIRE_OXYGENE 15.999
            #define MASSE_MOLAIRE_CARBONE 12.011
            #define MASSE_MOLAIRE_HYDROGENE 1.008
            #define MASSE_MOLAIRE_NITROGENE 14.007
            #define MASSE_MOLAIRE_SOUFRE 32.06
            #define MASSE_MOLAIRE_PHOSPHORE 30.974
            #define MASSE_MOLAIRE_SILICIUM 28.085
            #define MASSE_MOLAIRE_POTASSIUM 39.098
            #define MASSE_MOLAIRE_SODIUM 22.990
            #define MASSE_MOLAIRE_CHLORE 35.45
            #define MASSE_MOLAIRE_CALCIUM 40.078
            #define MASSE_MOLAIRE_MAGNESIUM 24.305
            #define MASSE_MOLAIRE_FER 55.845
            #define MASSE_MOLAIRE_CUIVRE 63.546
            #define MASSE_MOLAIRE_ZINC 65.38
            #define MASSE_MOLAIRE_ARGENT 107.868
            #define MASSE_MOLAIRE_OR 196.967
            #define MASSE_MOLAIRE_PLOMB 207.2
            #define MASSE_MOLAIRE_URANIUM 238.02891

    // ─── 4.3 Formules chimiques ───

            #define MOLES(masse, masseMolaire) ((masse) / (masseMolaire))
            #define MASSE_DEPUIS_MOLES(moles, masseMolaire) ((moles) * (masseMolaire))
            #define NOMBRE_PARTICULES(moles) ((moles) * AVOGADRO)
            #define CONCENTRATION(moles, volume) ((moles) / (volume))
            #define PH(concentration_H) (-log10(concentration_H))
            #define POH(concentration_OH) (-log10(concentration_OH))
            #define PH_DEPUIS_POH(pOH) (14.0 - (pOH))
            #define LOI_GAZ_PARFAIT_P(n, T, V) ((n) * GAS_CONSTANT * (T) / (V))
            #define LOI_GAZ_PARFAIT_V(n, T, P) ((n) * GAS_CONSTANT * (T) / (P))
            #define LOI_GAZ_PARFAIT_T(n, P, V) ((P) * (V) / ((n) * GAS_CONSTANT))



/* ═══════════════════════════════════════════════════════════════
   5. DÉBOGAGE ET AFFICHAGE
   ═══════════════════════════════════════════════════════════════ */

        #define AFFICHER(x) cout << #x << " = " << (x) << endl
        #define AFFICHER2(x, y) cout << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
        #define AFFICHER_TABLEAU(tab, n) for(int _i=0; _i<(n); _i++) cout << (tab)[_i] << " "; cout << endl
        #define SEPARATEUR cout << "----------------------------------------" << endl
        #define SAUT_LIGNE cout << endl
        #define TITRE(texte) cout << "\n=== " << (texte) << " ===" << endl
        #define ERREUR(texte) cerr << "Erreur: " << (texte) << endl

/* ═══════════════════════════════════════════════════════════════
   6. TABLEAUX ET LIMITES
   ═══════════════════════════════════════════════════════════════ */

    // ─── 6.1 Tailles et tableaux ───

        #define TAILLE_TABLEAU(arr) (sizeof(arr) / sizeof((arr)[0]))
        #define DANS_LIMITES(index, taille) ((index) >= 0 && (index) < (taille))
        #define INITIALISER_TABLEAU(arr, val) for(size_t _i=0; _i<TAILLE_TABLEAU(arr); _i++) (arr)[_i] = (val)
        #define AFFICHER_MATRICE(mat, rows, cols) for(size_t _i=0; _i<(rows); _i++) { for(size_t _j=0; _j<(cols); _j++) cout << (mat)[_i][_j] << " "; cout << endl; }

    // ─── 6.2 Limites numériques ───

        #define INT_MIN_VAL (-2147483648)
        #define INT_MAX_VAL 2147483647
        #define DOUBLE_EPSILON 1e-10
        #define FLOAT_EPSILON 1e-6
        #define TOLERANCE_DEFAUT 1e-8
        #define INFINI numeric_limits<double>::infinity()

/* ═══════════════════════════════════════════════════════════════
   7. GESTION DE LA MÉMOIRE
   ═══════════════════════════════════════════════════════════════ */

        #define ALLOUER(type, n) (new type[n])
        #define DEALLOUER(ptr) { delete[] (ptr); (ptr) = nullptr; }
        #define ALLOUER_OBJET(type) (new type())
        #define DEALLOUER_OBJET(ptr) { delete (ptr); (ptr) = nullptr; }
        #define ALLOUER_MATRICE(type, rows, cols) (new type*[rows] { for(size_t _i=0; _i<(rows); _i++) (new type[cols]) })
        #define DEALLOUER_MATRICE(mat, rows) { for(size_t _i=0; _i<(rows); _i++) delete[] (mat)[_i]; delete[] (mat); (mat) = nullptr; }
