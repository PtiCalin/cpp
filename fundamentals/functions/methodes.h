/* Fichier   : methodes.h    
	Auteure  : Charlie Bouchard    
	Cours    : IFT1166 - Programmation orientée objet en C++    
	Trimestre: Hiver 2026
	But      : Inventaire de méthodes et fonctions
	Dernière mise à jour : 2026-02-26
*/

/*  TABLE DES MATIÈRES
    ══════════════════
     1. Mathématiques
        1.1 Fonctions mathématiques de base
        1.2 Manipulation de nombres
     1.3 Statistiques et probabilités
     1.4 Géométrie
        1.4.1 Aires
        1.4.2 Périmètres
        1.4.3 Volumes
        1.4.4 Trigonométrie
        1.4.5 Distances
        1.4.6 Transformations géométriques
     1.5 Opérations vectorielles
     1.6 Manipulation de chaînes de caractères
     1.7 Manipulation de tableaux
     1.8 Tri et recherche
     1.9 Calcul combinatoire
    1.10 Théorie des nombres
    1.11 Conversions d'unités
    1.12 Validation et vérification
    1.13 Manipulation de matrices
    1.14 Calcul différentiel et intégral
        1.14.1 Dérivées numériques
        1.14.2 Intégrales numériques
        1.14.3 Limites numériques
        1.14.4 Équations différentielles
        1.14.5 Séries et sommations
    1.15 Optimisation et méthodes numériques
        1.15.1 Recherche de racines
        1.15.2 Optimisation 1D
        1.15.3 Optimisation multivariable
        1.15.4 Interpolation
        1.15.5 Utilitaires d'analyse
    2. Physique
        2.1 Mécanique classique
        2.2 Électromagnétisme
        2.3 Thermodynamique
        2.4 Optique
        2.5 Astronomie
    3. Chimie
        3.1 Stœchiométrie
        3.2 Cinétique chimique
        3.3 Thermodynamique chimique
        3.4 Équilibre chimique
        3.5 Propriétés des solutions
    4. Biologie
        4.1 Génétique
        4.2 Écologie
        4.3 Physiologie
        4.4 Évolution
        4.5 Microbiologie
    5. Informatique
        5.1 Structures de données
        5.2 Algorithmes
        5.3 Réseaux et systèmes d'exploitation
    6. Objets
        6.1 Objets de la vie quotidienne
        6.2 Outils et instruments
            6.2.1 Appareils de mesure
            6.2.2 Calculatrices
            6.2.3 Instruments de laboratoire
            6.2.4 Informatique et réseaux
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

#include "classes.h"
#include "macros.h"

using namespace std;

/* ═══════════════════════════════════════════════════════════════
   1. FONCTIONS MATHÉMATIQUES DE BASE
   ═══════════════════════════════════════════════════════════════ */

    double calculerFactorielle(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        double result = 1;
        for (int i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }

    double calculerPuissance(double base, int exposant) {
        return pow(base, exposant);
    }

    double calculerLogarithme(double valeur, double base) {
        return log(valeur) / log(base);
    }

    double calculerExponentielle(double exponent) {
        return exp(exponent);
    }

    double calculerRacineCarree(double valeur) {
        return sqrt(valeur);
    }

    double calculerValeurAbsolue(double valeur) {
        return fabs(valeur);
    }

/* ═══════════════════════════════════════════════════════════════
   2. MANIPULATION DE NOMBRES
   ═══════════════════════════════════════════════════════════════ */

    int arrondir(double valeur) {
        return static_cast<int>(round(valeur));
    }

    int arrondirVersLeHaut(double valeur) {
        return static_cast<int>(ceil(valeur));
    }

    int arrondirVersLeBas(double valeur) {
        return static_cast<int>(floor(valeur));
    }

    double tronquer(double valeur, int decimales) {
        double facteur = pow(10, decimales);
        return floor(valeur * facteur) / facteur;
    }

    double genererNombreAleatoire(double min, double max) {
        return min + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (max - min)));
    }

/* ═══════════════════════════════════════════════════════════════
   3. STATISTIQUES ET PROBABILITÉS
   ═══════════════════════════════════════════════════════════════ */

    double calculerValeurMaximale(const vector<double>& valeurs) {
        return *max_element(valeurs.begin(), valeurs.end());
    }

    double calculerValeurMinimale(const vector<double>& valeurs) {
        return *min_element(valeurs.begin(), valeurs.end());
    }
    
    double calculerMoyenne(const vector<double>& valeurs) {
        double sum = 0;
        for (double valeur : valeurs) {
            sum += valeur;
        }
        return sum / valeurs.size();
    }

    double calculerMediane(vector<double> valeurs) {
        sort(valeurs.begin(), valeurs.end());
        size_t n = valeurs.size();
        if (n % 2 == 0) {
            return (valeurs[n / 2 - 1] + valeurs[n / 2]) / 2;
        } else {
            return valeurs[n / 2];
        }
    }

    double calculerEcartType(const vector<double>& valeurs) {
        double moyenne = calculerMoyenne(valeurs);
        double sum = 0;
        for (double valeur : valeurs) {
            sum += (valeur - moyenne) * (valeur - moyenne);
        }
        return sqrt(sum / valeurs.size());
    }

    double calculerVariance(const vector<double>& valeurs) {
        double moyenne = calculerMoyenne(valeurs);
        double sum = 0;
        for (double valeur : valeurs) {
            sum += (valeur - moyenne) * (valeur - moyenne);
        }
        return sum / valeurs.size();
    }

    double calculerCoefficientCorrelation(const vector<double>& x, const vector<double>& y) {
        double moyenneX = calculerMoyenne(x);
        double moyenneY = calculerMoyenne(y);
        double sumXY = 0;
        double sumX2 = 0;
        double sumY2 = 0;
        for (size_t i = 0; i < x.size(); ++i) {
            sumXY += (x[i] - moyenneX) * (y[i] - moyenneY);
            sumX2 += (x[i] - moyenneX) * (x[i] - moyenneX);
            sumY2 += (y[i] - moyenneY) * (y[i] - moyenneY);
        }
        return sumXY / sqrt(sumX2 * sumY2);
    }

    double régressionLinéraire(const vector<double>& x, const vector<double>& y, double valeurX) {
        double moyenneX = calculerMoyenne(x);
        double moyenneY = calculerMoyenne(y);
        double sumXY = 0;
        double sumX2 = 0;
        for (size_t i = 0; i < x.size(); ++i) {
            sumXY += (x[i] - moyenneX) * (y[i] - moyenneY);
            sumX2 += (x[i] - moyenneX) * (x[i] - moyenneX);
        }
        double pente = sumXY / sumX2;
        double intercept = moyenneY - pente * moyenneX;
        return intercept + pente * valeurX;
    }

    double calculerprobabilité(double succès, double échecs) {
        return succès / (succès + échecs);
    }
    
/* ═══════════════════════════════════════════════════════════════
   4. GÉOMÉTRIE
   ═══════════════════════════════════════════════════════════════ */

    // ─── 4.1 Aires ───
    
        double calculerAireCercle(double rayon) {
            return 3.14159 * rayon * rayon;
        }

        double calculerAireRectangle(double longueur, double largeur) {
            return longueur * largeur;
        }

        double calculerAireTriangle(double base, double hauteur) {
            return 0.5 * base * hauteur;
        }

        double calculerAirePolygoneRegulier(int nombreCotes, double longueurCote) {
            double apothem = longueurCote / (2 * tan(3.14159 / nombreCotes));
            return (nombreCotes * longueurCote * apothem) / 2;
        }

    // ─── 4.2 Périmètres ───

        double calculerCirconference(double rayon) {
            return 2 * 3.14159 * rayon;
        }

        double calculerPerimetreRectangle(double longueur, double largeur) {
            return 2 * (longueur + largeur);
        }

        double calculerPerimetreTriangle(double cote1, double cote2, double cote3) {
            return cote1 + cote2 + cote3;
        }

        double calculerPerimetrePolygoneRegulier(int nombreCotes, double longueurCote) {
            return nombreCotes * longueurCote;
        }

    // ─── 4.3 Volumes ───

        double calculerVolumeSphere(double rayon) {
            return (4.0 / 3.0) * 3.14159 * rayon * rayon * rayon;
        }

        double calculerVolumeCylindre(double rayon, double hauteur) {
            return 3.14159 * rayon * rayon * hauteur;
        }

        double calculerVolumeCone(double rayon, double hauteur) {
            return (1.0 / 3.0) * 3.14159 * rayon * rayon * hauteur;
        }

        double calculerVolumePyramide(double baseLongueur, double baseLargeur, double hauteur) {
            return (1.0 / 3.0) * baseLongueur * baseLargeur * hauteur;
        }

    // ─── 4.4 Trigonométrie ───

        double calculerPythagore(double cote1, double cote2) {
            return sqrt(cote1 * cote1 + cote2 * cote2);
        }

        double calculerSinus(double angle) {
            return sin(angle);
        }

        double calculerArcSinus(double rapport) {
            return asin(rapport);
        }

        double calculerCosinus(double angle) {
            return cos(angle);
        }

        double calculerArcCosinus(double rapport) {
            return acos(rapport);
        }

        double calculerTangente(double angle) {
            return tan(angle);
        }

        double calculerArcTangente(double rapport) {
            return atan(rapport);
        }

        double calculerAngleEntreVecteurs(double x1, double y1, double x2, double y2) {
            double dotProduct = x1 * x2 + y1 * y2;
            double magnitude1 = sqrt(x1 * x1 + y1 * y1);
            double magnitude2 = sqrt(x2 * x2 + y2 * y2);
            return acos(dotProduct / (magnitude1 * magnitude2));
        }

    // ─── 4.5 Distances ───

        double calculerDistanceEuclidienne(double x1, double y1, double x2, double y2) {
            return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        }

        double calculerDistanceEntrePoints3D(double x1, double y1, double z1, double x2, double y2, double z2) {
            return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1));
        }

    // ─── 4.6 Transformations géométriques ───

        void translationPoint(double& x, double& y, double deltaX, double deltaY) {
            x += deltaX;
            y += deltaY;
        }

        void faireTournerPoint(double& x, double& y, double angle) {
            double radians = angle * (3.14159 / 180);
            double cosAngle = cos(radians);
            double sinAngle = sin(radians);
            double newX = x * cosAngle - y * sinAngle;
            double newY = x * sinAngle + y * cosAngle;
            x = newX;
            y = newY;
        }

        void faireRedimensionnerPoint(double& x, double& y, double facteur) {
            x *= facteur;
            y *= facteur;
        }

        void faireSymetrieHorizontale(double& x, double& y) {
            y = -y;
        }

        void faireSymetrieVerticale(double& x, double& y) {
            x = -x;
        }

/* ═══════════════════════════════════════════════════════════════
   5. OPÉRATIONS VECTORIELLES
   ═══════════════════════════════════════════════════════════════ */

    vector<double> additionnerVecteurs(const vector<double>& v1, const vector<double>& v2) {
        vector<double> result(v1.size());
        for (size_t i = 0; i < v1.size(); ++i) {
            result[i] = v1[i] + v2[i];
        }
        return result;
    }

    vector<double> soustraireVecteurs(const vector<double>& v1, const vector<double>& v2) {
        vector<double> result(v1.size());
        for (size_t i = 0; i < v1.size(); ++i) {
            result[i] = v1[i] - v2[i];
        }
        return result;
    }

    double produitScalaire(const vector<double>& v1, const vector<double>& v2) {
        double result = 0;
        for (size_t i = 0; i < v1.size(); ++i) {
            result += v1[i] * v2[i];
        }
        return result;
    }

    double normeVecteur(const vector<double>& v) {
        double sum = 0;
        for (double component : v) {
            sum += component * component;
        }
        return sqrt(sum);
    }

/* ═══════════════════════════════════════════════════════════════
   6. MANIPULATION DE CHAÎNES DE CARACTÈRES
   ═══════════════════════════════════════════════════════════════ */

    string convertirEnMajuscules(const string& str) {
        string result = str;
        for (char& c : result) {
            c = toupper(c);
        }
        return result;
    }

    string convertirEnMinuscules(const string& str) {
        string result = str;
        for (char& c : result) {
            c = tolower(c);
        }
        return result;
    }

    string inverserChaine(const string& str) {
        string result = str;
        reverse(result.begin(), result.end());
        return result;
    }

    bool estPalindrome(const string& str) {
        string cleanedStr;
        for (char c : str) {
            if (isalnum(c)) {
                cleanedStr += tolower(c);
            }
        }
        string reversedStr = inverserChaine(cleanedStr);
        return cleanedStr == reversedStr;
    }

    int compterOccurrences(const string& str, char caractere) {
        int count = 0;
        for (char c : str) {
            if (c == caractere) {
                ++count;
            }
        }
        return count;
    }

    string remplacerCaractere(const string& str, char ancienCaractere, char nouveauCaractere) {
        string result = str;
        for (char& c : result) {
            if (c == ancienCaractere) {
                c = nouveauCaractere;
            }
        }
        return result;
    }

    string supprimerEspaces(const string& str) {
        string result;
        for (char c : str) {
            if (!isspace(c)) {
                result += c;
            }
        }
        return result;
    }

/* ═══════════════════════════════════════════════════════════════
   7. MANIPULATION DE TABLEAUX
   ═══════════════════════════════════════════════════════════════ */

    double sommeTableau(const vector<double>& tab) {
        double somme = 0;
        for (double val : tab) {
            somme += val;
        }
        return somme;
    }

    double produitTableau(const vector<double>& tab) {
        double produit = 1;
        for (double val : tab) {
            produit *= val;
        }
        return produit;
    }

    vector<double> fusionnerTableaux(const vector<double>& t1, const vector<double>& t2) {
        vector<double> resultat(t1);
        for (double val : t2) {
            resultat.push_back(val);
        }
        return resultat;
    }

    vector<double> supprimerDoublons(const vector<double>& tab) {
        vector<double> resultat;
        for (double val : tab) {
            bool existe = false;
            for (double r : resultat) {
                if (r == val) { existe = true; break; }
            }
            if (!existe) resultat.push_back(val);
        }
        return resultat;
    }

    vector<double> filtrerSuperieur(const vector<double>& tab, double seuil) {
        vector<double> resultat;
        for (double val : tab) {
            if (val > seuil) resultat.push_back(val);
        }
        return resultat;
    }

    vector<double> filtrerInferieur(const vector<double>& tab, double seuil) {
        vector<double> resultat;
        for (double val : tab) {
            if (val < seuil) resultat.push_back(val);
        }
        return resultat;
    }

    void inverserTableau(vector<double>& tab) {
        int debut = 0, fin = tab.size() - 1;
        while (debut < fin) {
            double temp = tab[debut];
            tab[debut] = tab[fin];
            tab[fin] = temp;
            debut++;
            fin--;
        }
    }

    int compterOccurrencesTableau(const vector<double>& tab, double valeur) {
        int count = 0;
        for (double val : tab) {
            if (val == valeur) count++;
        }
        return count;
    }

    void remplirTableau(vector<double>& tab, int taille, double valeur) {
        tab.clear();
        for (int i = 0; i < taille; i++) {
            tab.push_back(valeur);
        }
    }

    vector<double> extraireSousTableau(const vector<double>& tab, int debut, int fin) {
        vector<double> resultat;
        for (int i = debut; i <= fin && i < (int)tab.size(); i++) {
            resultat.push_back(tab[i]);
        }
        return resultat;
    }

/* ═══════════════════════════════════════════════════════════════
   8. TRI ET RECHERCHE
   ═══════════════════════════════════════════════════════════════ */

    void triBulle(vector<double>& tab) {
        int n = tab.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (tab[j] > tab[j + 1]) {
                    double temp = tab[j];
                    tab[j] = tab[j + 1];
                    tab[j + 1] = temp;
                }
            }
        }
    }

    void triSelection(vector<double>& tab) {
        int n = tab.size();
        for (int i = 0; i < n - 1; i++) {
            int indiceMin = i;
            for (int j = i + 1; j < n; j++) {
                if (tab[j] < tab[indiceMin]) {
                    indiceMin = j;
                }
            }
            double temp = tab[i];
            tab[i] = tab[indiceMin];
            tab[indiceMin] = temp;
        }
    }

    void triInsertion(vector<double>& tab) {
        int n = tab.size();
        for (int i = 1; i < n; i++) {
            double cle = tab[i];
            int j = i - 1;
            while (j >= 0 && tab[j] > cle) {
                tab[j + 1] = tab[j];
                j--;
            }
            tab[j + 1] = cle;
        }
    }

    int recherchLineaire(const vector<double>& tab, double valeur) {
        for (size_t i = 0; i < tab.size(); i++) {
            if (tab[i] == valeur) return i;
        }
        return -1;
    }

    int rechercheBinaire(const vector<double>& tab, double valeur) {
        int gauche = 0, droite = tab.size() - 1;
        while (gauche <= droite) {
            int milieu = (gauche + droite) / 2;
            if (tab[milieu] == valeur) return milieu;
            else if (tab[milieu] < valeur) gauche = milieu + 1;
            else droite = milieu - 1;
        }
        return -1;
    }

    bool estTrie(const vector<double>& tab) {
        for (size_t i = 1; i < tab.size(); i++) {
            if (tab[i] < tab[i - 1]) return false;
        }
        return true;
    }

/* ═══════════════════════════════════════════════════════════════
   9. CALCUL COMBINATOIRE
   ═══════════════════════════════════════════════════════════════ */

    double combinaison(int n, int k) {
        if (k < 0 || k > n) return 0;
        if (k == 0 || k == n) return 1;
        // Optimisation : C(n,k) = C(n, n-k)
        if (k > n - k) k = n - k;
        double resultat = 1;
        for (int i = 0; i < k; i++) {
            resultat *= (n - i);
            resultat /= (i + 1);
        }
        return resultat;
    }

    double arrangement(int n, int k) {
        if (k < 0 || k > n) return 0;
        double resultat = 1;
        for (int i = 0; i < k; i++) {
            resultat *= (n - i);
        }
        return resultat;
    }

    double permutation(int n) {
        return calculerFactorielle(n);
    }

    double permutationAvecRepetition(int n, const vector<int>& repetitions) {
        double denominateur = 1;
        for (int r : repetitions) {
            denominateur *= calculerFactorielle(r);
        }
        return calculerFactorielle(n) / denominateur;
    }

    double combinaisonAvecRepetition(int n, int k) {
        // C(n+k-1, k)
        return combinaison(n + k - 1, k);
    }

    double nombreDerangements(int n) {
        // Nombre de permutations sans point fixe (formule des sous-factorielles)
        if (n == 0) return 1;
        if (n == 1) return 0;
        double resultat = 0;
        for (int i = 0; i <= n; i++) {
            double terme = calculerFactorielle(n - i);
            if (i % 2 == 0)
                resultat += terme;
            else
                resultat -= terme;
        }
        return resultat;
    }

    double nombreCatalan(int n) {
        // C_n = C(2n, n) / (n + 1)
        return combinaison(2 * n, n) / (n + 1);
    }

    double coefficientBinomial(int n, int k) {
        // Version qui accepte aussi n négatif (formule généralisée)
        if (k < 0) return 0;
        double resultat = 1;
        for (int i = 0; i < k; i++) {
            resultat *= (n - i);
            resultat /= (i + 1);
        }
        return resultat;
    }

    vector<vector<double>> trianglePascal(int nLignes) {
        vector<vector<double>> triangle(nLignes);
        for (int i = 0; i < nLignes; i++) {
            triangle[i].resize(i + 1);
            triangle[i][0] = 1;
            triangle[i][i] = 1;
            for (int j = 1; j < i; j++) {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
        return triangle;
    }

    double nombreStirlingDeuxiemeEspece(int n, int k) {
        // Nombre de partitions de n éléments en k sous-ensembles non vides
        if (n == 0 && k == 0) return 1;
        if (n == 0 || k == 0 || k > n) return 0;
        double somme = 0;
        for (int j = 0; j <= k; j++) {
            double terme = combinaison(k, j) * pow(j, n);
            if ((k - j) % 2 == 0)
                somme += terme;
            else
                somme -= terme;
        }
        return somme / calculerFactorielle(k);
    }

    double nombreBell(int n) {
        // Nombre total de partitions d'un ensemble de n éléments
        double somme = 0;
        for (int k = 0; k <= n; k++) {
            somme += nombreStirlingDeuxiemeEspece(n, k);
        }
        return somme;
    }

    double principeInclusionExclusion(const vector<double>& taillesEnsembles,
                                       const vector<double>& taillesIntersections2,
                                       double tailleIntersectionTotale) {
        // Pour 2 ou 3 ensembles : |A∪B∪...| = Σ|Ai| - Σ|Ai∩Aj| + |A∩B∩C|...
        double somme = 0;
        for (double t : taillesEnsembles) somme += t;
        for (double t : taillesIntersections2) somme -= t;
        somme += tailleIntersectionTotale;
        return somme;
    }

/* ═══════════════════════════════════════════════════════════════
   10. THÉORIE DES NOMBRES
   ═══════════════════════════════════════════════════════════════ */

    bool estPremier(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }

    int pgcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int ppcm(int a, int b) {
        return (a / pgcd(a, b)) * b;
    }

    int fibonacci(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        int a = 0, b = 1;
        for (int i = 2; i <= n; i++) {
            int temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }

    bool estPair(int n) {
        return n % 2 == 0;
    }

    bool estImpair(int n) {
        return n % 2 != 0;
    }

    int sommeChiffres(int n) {
        int somme = 0;
        n = abs(n);
        while (n > 0) {
            somme += n % 10;
            n /= 10;
        }
        return somme;
    }

    int nombreChiffres(int n) {
        if (n == 0) return 1;
        int count = 0;
        n = abs(n);
        while (n > 0) {
            count++;
            n /= 10;
        }
        return count;
    }

    int inverserNombre(int n) {
        int resultat = 0;
        bool negatif = n < 0;
        n = abs(n);
        while (n > 0) {
            resultat = resultat * 10 + n % 10;
            n /= 10;
        }
        return negatif ? -resultat : resultat;
    }

    vector<int> trouverDiviseurs(int n) {
        vector<int> diviseurs;
        n = abs(n);
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) diviseurs.push_back(i);
        }
        return diviseurs;
    }

    bool estParfait(int n) {
        if (n <= 1) return false;
        int somme = 0;
        for (int i = 1; i < n; i++) {
            if (n % i == 0) somme += i;
        }
        return somme == n;
    }

/* ═══════════════════════════════════════════════════════════════
   11. CONVERSIONS D'UNITÉS
   ═══════════════════════════════════════════════════════════════ */

    double celsiusVersFahrenheit(double celsius) {
        return celsius * 9.0 / 5.0 + 32;
    }

    double fahrenheitVersCelsius(double fahrenheit) {
        return (fahrenheit - 32) * 5.0 / 9.0;
    }

    double degreVersRadian(double degre) {
        return degre * 3.14159 / 180.0;
    }

    double radianVersDegre(double radian) {
        return radian * 180.0 / 3.14159;
    }

    double kmVersMiles(double km) {
        return km * 0.621371;
    }

    double milesVersKm(double miles) {
        return miles / 0.621371;
    }

    double kgVersLivres(double kg) {
        return kg * 2.20462;
    }

    double livresVersKg(double livres) {
        return livres / 2.20462;
    }

    string decimalVersBinaire(int n) {
        if (n == 0) return "0";
        string binaire = "";
        bool negatif = n < 0;
        n = abs(n);
        while (n > 0) {
            binaire = (n % 2 == 0 ? "0" : "1") + binaire;
            n /= 2;
        }
        return negatif ? "-" + binaire : binaire;
    }

    int binaireVersDecimal(const string& binaire) {
        int resultat = 0;
        int puissance = 1;
        for (int i = binaire.size() - 1; i >= 0; i--) {
            if (binaire[i] == '1') resultat += puissance;
            puissance *= 2;
        }
        return resultat;
    }

    string decimalVersHexadecimal(int n) {
        if (n == 0) return "0";
        string hex = "";
        const char hexChiffres[] = "0123456789ABCDEF";
        bool negatif = n < 0;
        n = abs(n);
        while (n > 0) {
            hex = hexChiffres[n % 16] + hex;
            n /= 16;
        }
        return negatif ? "-" + hex : hex;
    }

/* ═══════════════════════════════════════════════════════════════
   12. VALIDATION ET VÉRIFICATION
   ═══════════════════════════════════════════════════════════════ */

    bool estDansIntervalle(double valeur, double min, double max) {
        return valeur >= min && valeur <= max;
    }

    bool estEntierPositif(int n) {
        return n > 0;
    }

    bool estChiffreNumerique(char c) {
        return c >= '0' && c <= '9';
    }

    bool estLettre(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    bool chaineEstNumerique(const string& str) {
        if (str.empty()) return false;
        size_t debut = 0;
        if (str[0] == '-' || str[0] == '+') debut = 1;
        bool pointTrouve = false;
        for (size_t i = debut; i < str.size(); i++) {
            if (str[i] == '.' && !pointTrouve) {
                pointTrouve = true;
            } else if (!isdigit(str[i])) {
                return false;
            }
        }
        return debut < str.size();
    }

    bool chaineEstAlphabetique(const string& str) {
        for (char c : str) {
            if (!isalpha(c) && !isspace(c)) return false;
        }
        return !str.empty();
    }

    bool chaineEstVide(const string& str) {
        for (char c : str) {
            if (!isspace(c)) return false;
        }
        return true;
    }

    bool estAnneeBissextile(int annee) {
        return (annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0);
    }

/* ═══════════════════════════════════════════════════════════════
   13. MANIPULATION DE MATRICES
   ═══════════════════════════════════════════════════════════════ */

    vector<vector<double>> creerMatrice(int lignes, int colonnes, double valeur) {
        return vector<vector<double>>(lignes, vector<double>(colonnes, valeur));
    }

    vector<vector<double>> additionnerMatrices(const vector<vector<double>>& m1,
                                                const vector<vector<double>>& m2) {
        int lignes = m1.size(), colonnes = m1[0].size();
        vector<vector<double>> resultat = creerMatrice(lignes, colonnes, 0);
        for (int i = 0; i < lignes; i++) {
            for (int j = 0; j < colonnes; j++) {
                resultat[i][j] = m1[i][j] + m2[i][j];
            }
        }
        return resultat;
    }

    vector<vector<double>> soustraireMatrices(const vector<vector<double>>& m1,
                                               const vector<vector<double>>& m2) {
        int lignes = m1.size(), colonnes = m1[0].size();
        vector<vector<double>> resultat = creerMatrice(lignes, colonnes, 0);
        for (int i = 0; i < lignes; i++) {
            for (int j = 0; j < colonnes; j++) {
                resultat[i][j] = m1[i][j] - m2[i][j];
            }
        }
        return resultat;
    }

    vector<vector<double>> multiplierMatrices(const vector<vector<double>>& m1,
                                               const vector<vector<double>>& m2) {
        int lignes = m1.size(), colonnesM1 = m1[0].size(), colonnesM2 = m2[0].size();
        vector<vector<double>> resultat = creerMatrice(lignes, colonnesM2, 0);
        for (int i = 0; i < lignes; i++) {
            for (int j = 0; j < colonnesM2; j++) {
                for (int k = 0; k < colonnesM1; k++) {
                    resultat[i][j] += m1[i][k] * m2[k][j];
                }
            }
        }
        return resultat;
    }

    vector<vector<double>> transposerMatrice(const vector<vector<double>>& matrice) {
        int lignes = matrice.size(), colonnes = matrice[0].size();
        vector<vector<double>> resultat = creerMatrice(colonnes, lignes, 0);
        for (int i = 0; i < lignes; i++) {
            for (int j = 0; j < colonnes; j++) {
                resultat[j][i] = matrice[i][j];
            }
        }
        return resultat;
    }

    void afficherMatrice(const vector<vector<double>>& matrice) {
        for (const auto& ligne : matrice) {
            for (double val : ligne) {
                cout << val << "\t";
            }
            cout << endl;
        }
    }

    bool estMatriceCarree(const vector<vector<double>>& matrice) {
        return matrice.size() == matrice[0].size();
    }

    double tracerMatrice(const vector<vector<double>>& matrice) {
        double trace = 0;
        for (size_t i = 0; i < matrice.size(); i++) {
            trace += matrice[i][i];
        }
        return trace;
    }

/* ═══════════════════════════════════════════════════════════════
   14. CALCUL DIFFÉRENTIEL ET INTÉGRAL
   ═══════════════════════════════════════════════════════════════ */

    // ─── 14.1 Dérivées numériques ───

        double derivee(function<double(double)> f, double x, double h = 1e-8) {
            // Différence centrée : f'(x) ≈ (f(x+h) - f(x-h)) / 2h
            return (f(x + h) - f(x - h)) / (2 * h);
        }

        double deriveeSeconde(function<double(double)> f, double x, double h = 1e-5) {
            // f''(x) ≈ (f(x+h) - 2f(x) + f(x-h)) / h²
            return (f(x + h) - 2 * f(x) + f(x - h)) / (h * h);
        }

        double deriveeNieme(function<double(double)> f, double x, int n, double h = 1e-4) {
            // Dérivée n-ième par différences finies
            if (n == 0) return f(x);
            if (n == 1) return derivee(f, x, h);
            auto fPrime = [&](double t) { return derivee(f, t, h); };
            return deriveeNieme(fPrime, x, n - 1, h);
        }

        double deriveePartielleX(function<double(double, double)> f, double x, double y, double h = 1e-8) {
            return (f(x + h, y) - f(x - h, y)) / (2 * h);
        }

        double deriveePartielleY(function<double(double, double)> f, double x, double y, double h = 1e-8) {
            return (f(x, y + h) - f(x, y - h)) / (2 * h);
        }

        vector<double> gradient(function<double(double, double)> f, double x, double y, double h = 1e-8) {
            return { deriveePartielleX(f, x, y, h), deriveePartielleY(f, x, y, h) };
        }

    // ─── 14.2 Intégrales numériques ───

        double integraleRectanglesGauches(function<double(double)> f, double a, double b, int n = 1000) {
            double dx = (b - a) / n;
            double somme = 0;
            for (int i = 0; i < n; i++) {
                somme += f(a + i * dx);
            }
            return somme * dx;
        }

        double integraleRectanglesDroits(function<double(double)> f, double a, double b, int n = 1000) {
            double dx = (b - a) / n;
            double somme = 0;
            for (int i = 1; i <= n; i++) {
                somme += f(a + i * dx);
            }
            return somme * dx;
        }

        double integralePointMilieu(function<double(double)> f, double a, double b, int n = 1000) {
            double dx = (b - a) / n;
            double somme = 0;
            for (int i = 0; i < n; i++) {
                somme += f(a + (i + 0.5) * dx);
            }
            return somme * dx;
        }

        double integraleTrapezes(function<double(double)> f, double a, double b, int n = 1000) {
            // Méthode des trapèzes
            double dx = (b - a) / n;
            double somme = (f(a) + f(b)) / 2.0;
            for (int i = 1; i < n; i++) {
                somme += f(a + i * dx);
            }
            return somme * dx;
        }

        double integraleMonteCarl(function<double(double)> f, double a, double b, int n = 100000) {
            // Intégration par Monte Carlo
            double somme = 0;
            for (int i = 0; i < n; i++) {
                double x = a + static_cast<double>(rand()) / RAND_MAX * (b - a);
                somme += f(x);
            }
            return (b - a) * somme / n;
        }

    // ─── 14.3 Limites numériques ───

        double limiteNumerique(function<double(double)> f, double x0, double h = 1e-10) {
            // Approximation de lim f(x) quand x -> x0
            return (f(x0 + h) + f(x0 - h)) / 2.0;
        }

    // ─── 14.4 Équations différentielles ───

        vector<pair<double, double>> euler(function<double(double, double)> dydx,
                                            double x0, double y0, double xFinal, int n = 1000) {
            // Méthode d'Euler pour résoudre y' = f(x, y)
            double dx = (xFinal - x0) / n;
            vector<pair<double, double>> points;
            double x = x0, y = y0;
            points.push_back({x, y});
            for (int i = 0; i < n; i++) {
                y = y + dx * dydx(x, y);
                x = x + dx;
                points.push_back({x, y});
            }
            return points;
        }

        vector<pair<double, double>> rungeKutta4(function<double(double, double)> dydx,
                                                double x0, double y0, double xFinal, int n = 1000) {
            // Méthode de Runge-Kutta d'ordre 4
            double dx = (xFinal - x0) / n;
            vector<pair<double, double>> points;
            double x = x0, y = y0;
            points.push_back({x, y});
            for (int i = 0; i < n; i++) {
                double k1 = dx * dydx(x, y);
                double k2 = dx * dydx(x + dx / 2, y + k1 / 2);
                double k3 = dx * dydx(x + dx / 2, y + k2 / 2);
                double k4 = dx * dydx(x + dx, y + k3);
                y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
                x = x + dx;
                points.push_back({x, y});
            }
            return points;
        }

    // ─── 14.5 Séries et sommations ───

    double sommeSerie(function<double(int)> terme, int debut, int fin) {
        double somme = 0;
        for (int i = debut; i <= fin; i++) {
            somme += terme(i);
        }
        return somme;
    }

    double produitSerie(function<double(int)> terme, int debut, int fin) {
        double produit = 1;
        for (int i = debut; i <= fin; i++) {
            produit *= terme(i);
        }
        return produit;
    }

    double serieArithmetique(double premier, double raison, int n) {
        // Somme des n premiers termes : a + (a+r) + (a+2r) + ... = n/2 * (2a + (n-1)r)
        return n / 2.0 * (2 * premier + (n - 1) * raison);
    }

    double serieArithmetiqueInverse(double premier, double raison, int n) {
        // Somme des n premiers termes inverses : 1/a + 1/(a+r) + ... (approximé par la somme des inverses)
        double somme = 0;
        for (int i = 0; i < n; i++) {
            somme += 1.0 / (premier + i * raison);
        }
        return somme;
    }

    double serieHarmonique(int n) {
        // Somme des n premiers termes de la série harmonique : H_n = 1 + 1/2 + 1/3 + ... + 1/n
        double somme = 0;
        for (int i = 1; i <= n; i++) {
            somme += 1.0 / i;
        }
        return somme;
    }

    double serieGeometrique(double premier, double raison, int n) {
        // Somme des n premiers termes : a * (1 - r^n) / (1 - r)
        if (raison == 1) return premier * n;
        return premier * (1 - pow(raison, n)) / (1 - raison);
    }

    double serieTaylorExp(double x, int termes = 20) {
        // e^x = Σ x^n / n!
        double somme = 0;
        for (int n = 0; n < termes; n++) {
            somme += pow(x, n) / calculerFactorielle(n);
        }
        return somme;
    }

    double serieTaylorSin(double x, int termes = 15) {
        // sin(x) = Σ (-1)^n * x^(2n+1) / (2n+1)!
        double somme = 0;
        for (int n = 0; n < termes; n++) {
            double signe = (n % 2 == 0) ? 1 : -1;
            somme += signe * pow(x, 2 * n + 1) / calculerFactorielle(2 * n + 1);
        }
        return somme;
    }

    double serieTaylorCos(double x, int termes = 15) {
        // cos(x) = Σ (-1)^n * x^(2n) / (2n)!
        double somme = 0;
        for (int n = 0; n < termes; n++) {
            double signe = (n % 2 == 0) ? 1 : -1;
            somme += signe * pow(x, 2 * n) / calculerFactorielle(2 * n);
        }
        return somme;
    }

    double serieTaylorLn(double x, int termes = 100) {
        // ln(1+x) = Σ (-1)^(n+1) * x^n / n  pour |x| <= 1
        double somme = 0;
        for (int n = 1; n <= termes; n++) {
            double signe = (n % 2 == 1) ? 1 : -1;
            somme += signe * pow(x, n) / n;
        }
        return somme;
    }

    double serieTaylorArctan(double x, int termes = 100) {
        // arctan(x) = Σ (-1)^n * x^(2n+1) / (2n+1) pour |x| <= 1
        double somme = 0;
        for (int n = 0; n < termes; n++) {
            double signe = (n % 2 == 0) ? 1 : -1;
            somme += signe * pow(x, 2 * n + 1) / (2 * n + 1);
        }
        return somme;
    }

    double sommeGeometriqueInfinie(double premier, double raison) {
        // Somme à l'infini : a / (1 - r) pour |r| < 1
        if (fabs(raison) >= 1) return NAN;  // Diverge
        return premier / (1 - raison);
    }

    double sommePythagoriciennes(int n) {
        // Somme des inverses des carrés : Σ 1/n^2 pour n=1 à ∞ (approximé par un nombre fini de termes)
        double somme = 0;
        for (int i = 1; i <= n; i++) {
            somme += 1.0 / (i * i);
        }
        return somme;
    }

    double serieRiemannZeta(double s, int termes = 100000) {
        // ζ(s) = Σ 1/n^s pour n=1 à ∞ (approximé par un nombre fini de termes)
        double somme = 0;
        for (int n = 1; n <= termes; n++) {
            somme += 1.0 / pow(n, s);
        }
        return somme;
    }


/* ═══════════════════════════════════════════════════════════════
   15. OPTIMISATION ET MÉTHODES NUMÉRIQUES
   ═══════════════════════════════════════════════════════════════ */

    // ─── 15.1 Recherche de racines ───

        double methodeBisection(function<double(double)> f, double a, double b,
                                double tolerance = 1e-10, int maxIterations = 1000) {
            // Trouve x tel que f(x) = 0 dans [a, b] (f(a) et f(b) de signes opposés)
            for (int i = 0; i < maxIterations; i++) {
                double milieu = (a + b) / 2.0;
                if (fabs(f(milieu)) < tolerance || (b - a) / 2.0 < tolerance)
                    return milieu;
                if (f(milieu) * f(a) < 0)
                    b = milieu;
                else
                    a = milieu;
            }
            return (a + b) / 2.0;
        }

        double methodeNewtonRaphson(function<double(double)> f, double x0,
                                    double tolerance = 1e-10, int maxIterations = 1000) {
            // Trouve x tel que f(x) = 0 par la méthode de Newton
            double x = x0;
            for (int i = 0; i < maxIterations; i++) {
                double fx = f(x);
                double fpx = derivee(f, x);
                if (fabs(fpx) < 1e-15) break;  // Dérivée trop proche de zéro
                double xNouveau = x - fx / fpx;
                if (fabs(xNouveau - x) < tolerance) return xNouveau;
                x = xNouveau;
            }
            return x;
        }

        double methodeSecante(function<double(double)> f, double x0, double x1,
                            double tolerance = 1e-10, int maxIterations = 1000) {
            for (int i = 0; i < maxIterations; i++) {
                double fx0 = f(x0), fx1 = f(x1);
                if (fabs(fx1 - fx0) < 1e-15) break;
                double x2 = x1 - fx1 * (x1 - x0) / (fx1 - fx0);
                if (fabs(x2 - x1) < tolerance) return x2;
                x0 = x1;
                x1 = x2;
            }
            return x1;
        }

        double methodePointFixe(function<double(double)> g, double x0,
                                double tolerance = 1e-10, int maxIterations = 1000) {
            // Résout x = g(x) par itération
            double x = x0;
            for (int i = 0; i < maxIterations; i++) {
                double xNouveau = g(x);
                if (fabs(xNouveau - x) < tolerance) return xNouveau;
                x = xNouveau;
            }
            return x;
        }

    // ─── 15.2 Optimisation 1D ───

        double rechercheMinSectionDoree(function<double(double)> f, double a, double b,
                                        double tolerance = 1e-10, int maxIterations = 1000) {
            // Recherche du minimum par la méthode de la section dorée
            const double phi = (sqrt(5) - 1) / 2.0;  // ≈ 0.618
            double c = b - phi * (b - a);
            double d = a + phi * (b - a);
            for (int i = 0; i < maxIterations; i++) {
                if (fabs(b - a) < tolerance) break;
                if (f(c) < f(d))
                    b = d;
                else
                    a = c;
                c = b - phi * (b - a);
                d = a + phi * (b - a);
            }
            return (a + b) / 2.0;
        }

        double rechercheMaxSectionDoree(function<double(double)> f, double a, double b,
                                        double tolerance = 1e-10, int maxIterations = 1000) {
            auto fNeg = [&](double x) { return -f(x); };
            return rechercheMinSectionDoree(fNeg, a, b, tolerance, maxIterations);
        }

    // ─── 15.3 Optimisation multivariable ───

        pair<double, double> descenteGradient2D(function<double(double, double)> f,
                                                double x0, double y0,
                                                double tauxApprentissage = 0.01,
                                                double tolerance = 1e-10,
                                                int maxIterations = 10000) {
            double x = x0, y = y0;
            for (int i = 0; i < maxIterations; i++) {
                vector<double> grad = gradient(f, x, y);
                double newX = x - tauxApprentissage * grad[0];
                double newY = y - tauxApprentissage * grad[1];
                if (fabs(newX - x) < tolerance && fabs(newY - y) < tolerance)
                    break;
                x = newX;
                y = newY;
            }
            return {x, y};
        }

        double methodeNewton2D(function<double(double)> f, double x0,
                                double tolerance = 1e-10, int maxIterations = 1000) {
            // Trouve le minimum en résolvant f'(x) = 0 avec Newton
            double x = x0;
            for (int i = 0; i < maxIterations; i++) {
                double fp = derivee(f, x);
                double fpp = deriveeSeconde(f, x);
                if (fabs(fpp) < 1e-15) break;
                double xNouveau = x - fp / fpp;
                if (fabs(xNouveau - x) < tolerance) return xNouveau;
                x = xNouveau;
            }
            return x;
        }

    // ─── 15.4 Interpolation ───

        double interpolationLineaire(double x0, double y0, double x1, double y1, double x) {
            return y0 + (y1 - y0) * (x - x0) / (x1 - x0);
        }

        double interpolationLagrange(const vector<double>& xs, const vector<double>& ys, double x) {
            double resultat = 0;
            int n = xs.size();
            for (int i = 0; i < n; i++) {
                double terme = ys[i];
                for (int j = 0; j < n; j++) {
                    if (j != i) {
                        terme *= (x - xs[j]) / (xs[i] - xs[j]);
                    }
                }
                resultat += terme;
            }
            return resultat;
        }

        double interpolationSpline(const vector<double>& xs, const vector<double>& ys, double x) {
            // Implémentation d'une interpolation spline cubique (simplifiée)
            int n = xs.size();
            if (n < 2) return NAN;
            // Trouver l'intervalle [xs[i], xs[i+1]] contenant x
            int i = 0;
            while (i < n - 1 && xs[i + 1] < x) i++;
            if (i == n - 1) return ys[n - 1];  // x est au-delà de la dernière valeur
            if (i == 0) return ys[0];          // x est avant la première valeur
            // Interpolation linéaire comme approximation simple
            return interpolationLineaire(xs[i], ys[i], xs[i + 1], ys[i + 1], x);
        }

    // ─── 15.5 Utilitaires d'analyse ───

        bool estCroissante(function<double(double)> f, double x, double h = 1e-8) {
            return derivee(f, x, h) > 0;
        }

        bool estDecroissante(function<double(double)> f, double x, double h = 1e-8) {
            return derivee(f, x, h) < 0;
        }

        bool estConcaveVersLeHaut(function<double(double)> f, double x, double h = 1e-5) {
            return deriveeSeconde(f, x, h) > 0;
        }

        bool estConcaveVersLeBas(function<double(double)> f, double x, double h = 1e-5) {
            return deriveeSeconde(f, x, h) < 0;
        }

        vector<double> trouverRacinesDansIntervalle(function<double(double)> f,
                                                    double a, double b, int divisions = 1000,
                                                    double tolerance = 1e-10) {
            // Balaye [a, b] et identifie les racines par changement de signe
            vector<double> racines;
            double dx = (b - a) / divisions;
            for (int i = 0; i < divisions; i++) {
                double x1 = a + i * dx;
                double x2 = x1 + dx;
                if (f(x1) * f(x2) < 0) {
                    double racine = methodeBisection(f, x1, x2, tolerance);
                    racines.push_back(racine);
                }
            }
            return racines;
        }

        vector<double> trouverExtremumsDansIntervalle(function<double(double)> f,
                                                    double a, double b, int divisions = 1000,
                                                    double tolerance = 1e-10) {
            // Balaye [a, b] et identifie les extremums par changement de signe de la dérivée
            vector<double> extremums;
            double dx = (b - a) / divisions;
            for (int i = 0; i < divisions; i++) {
                double x1 = a + i * dx;
                double x2 = x1 + dx;
                if (derivee(f, x1) * derivee(f, x2) < 0) {
                    double extremum = methodeBisection([&](double x) { return derivee(f, x); }, x1, x2, tolerance);
                    extremums.push_back(extremum);
                }
            }
            return extremums;
        }