/* Fichier   : classes.h 
	Auteure  : Charlie Bouchard    
	Cours    : IFT1166 - Programmation orientée objet en C++    
	Trimestre: Hiver 2026
	But      : Inventaire de classes définies par l'utilisateur
	Dernière mise à jour : 2026-02-26
*/

/*  TABLE DES MATIÈRES
    ══════════════════
     1. Mathématiques
     2. Géométrie
        2.1 Formes 2D
        2.2 Formes 3D
     3. Physique
        3.1 Vecteurs et forces
        3.2 Mécanique classique
        3.3 Électromagnétisme
        3.4 Oscillateurs et ondes
        3.5 Gravitation et astronomie
        3.6 Optique
     4. Chimie
        4.1 Atomes et éléments
        4.2 Molécules et réactions
        4.3 Solutions et concentrations
        4.4 Thermodynamique chimique
        4.5 Cinétique chimique
     5. Biologie
        5.1 Cellules et organites
     6. Informatique
        6.1 Structures de données
        6.2 Algorithmes
        6.3 Réseaux et systèmes d'exploitation
     7. Objets
        7.1 Objets de la vie quotidienne
        7.2 Outils et instruments
            7.2.1 Appareils de mesure
            7.2.2 Calculatrices
            7.2.3 Instruments de laboratoire
            7.2.4 Informatique et réseaux
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
#include "macros.h"

using namespace std;

/* ═══════════════════════════════════════════════════════════════
   1. MATHÉMATIQUES
   ═══════════════════════════════════════════════════════════════ */

    class Matrice {
    public:
        vector<vector<double>> elements;
        Matrice(int lignes, int colonnes) {
            elements.resize(lignes, vector<double>(colonnes, 0));
        }
        Matrice operator+(const Matrice& autre) const {
            int lignes = elements.size();
            int colonnes = elements[0].size();
            Matrice resultat(lignes, colonnes);
            for (int i = 0; i < lignes; i++) {
                for (int j = 0; j < colonnes; j++) {
                    resultat.elements[i][j] = elements[i][j] + autre.elements[i][j];
                }
            }
            return resultat;
        }
        Matrice operator*(const Matrice& autre) const {
            int lignesA = elements.size();
            int colonnesA = elements[0].size();
            int lignesB = autre.elements.size();
            int colonnesB = autre.elements[0].size();
            if (colonnesA != lignesB) throw invalid_argument("Incompatible pour multiplication");
            Matrice resultat(lignesA, colonnesB);
            for (int i = 0; i < lignesA; i++) {
                for (int j = 0; j < colonnesB; j++) {
                    for (int k = 0; k < colonnesA; k++) {
                        resultat.elements[i][j] += elements[i][k] * autre.elements[k][j];
                    }
                }
            }
            return resultat;
        }
    };

/* ═══════════════════════════════════════════════════════════════
   2. GÉOMÉTRIE
   ═══════════════════════════════════════════════════════════════ */

    // ─── 2.1 Formes 2D ───

        class Point {
        public:
            double x;
            double y;
            Point(double x = 0, double y = 0) : x(x), y(y) {}
            double distance(const Point& autre) const {
                return sqrt(pow(x - autre.x, 2) + pow(y - autre.y, 2));
            }
        };

        class Rectangle {
        public:
            Point coinSupGauche;
            double largeur;
            double hauteur;
            Rectangle(const Point& coinSupGauche, double largeur, double hauteur)
                : coinSupGauche(coinSupGauche), largeur(largeur), hauteur(hauteur) {}
            double aire() const {
                return largeur * hauteur;
            }
            double perimetre() const {
                return 2 * (largeur + hauteur);
            }
        };

        class Cercle {
        public:
            Point centre;
            double rayon;
            Cercle(const Point& centre, double rayon) : centre(centre), rayon(rayon) {}
            double aire() const {
                return 3.14159 * rayon * rayon;
            }
            double circonference() const {
                return 2 * 3.14159 * rayon;
            }
        };

        class Triangle {
        public:
            Point sommet1;
            Point sommet2;
            Point sommet3;
            Triangle(const Point& sommet1, const Point& sommet2, const Point& sommet3)
                : sommet1(sommet1), sommet2(sommet2), sommet3(sommet3) {}
            double aire() const {
                double a = sommet1.distance(sommet2);
                double b = sommet2.distance(sommet3);
                double c = sommet3.distance(sommet1);
                double s = (a + b + c) / 2;
                return sqrt(s * (s - a) * (s - b) * (s - c));
            }
            double perimetre() const {
                return sommet1.distance(sommet2) + sommet2.distance(sommet3) + sommet3.distance(sommet1);
            }
        };

        class PolygoneRegulier {
        public:
            int nombreCotes;
            double longueurCote;
            PolygoneRegulier(int nombreCotes, double longueurCote)
                : nombreCotes(nombreCotes), longueurCote(longueurCote) {}
            double aire() const {
                return (nombreCotes * longueurCote * longueurCote) / (4 * tan(3.14159 / nombreCotes));
            }
            double perimetre() const {
                return nombreCotes * longueurCote;
            }
        };

    // ─── 2.2 Formes 3D ───

        class Point3D {
        public:
            double x;
            double y;
            double z;
            Point3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
            double distance(const Point3D& autre) const {
                return sqrt(pow(x - autre.x, 2) + pow(y - autre.y, 2) + pow(z - autre.z, 2));
            }
        };

        class Sphere {
        public:
            Point3D centre;
            double rayon;
            Sphere(const Point3D& centre, double rayon) : centre(centre), rayon(rayon) {}
            double aire() const {
                return 4 * 3.14159 * rayon * rayon;
            }
            double volume() const {
                return (4.0 / 3.0) * 3.14159 * rayon * rayon * rayon;
            }
        };

        class Cylindre {
        public:
            Point3D centreBase;
            double rayon;
            double hauteur;
            Cylindre(const Point3D& centreBase, double rayon, double hauteur)
                : centreBase(centreBase), rayon(rayon), hauteur(hauteur) {}
            double aire() const {
                return 2 * 3.14159 * rayon * (rayon + hauteur);
            }
            double volume() const {
                return 3.14159 * rayon * rayon * hauteur;
            }
        };

        class Cone {
        public:
            Point3D centreBase;
            double rayon;
            double hauteur;
            Cone(const Point3D& centreBase, double rayon, double hauteur)
                : centreBase(centreBase), rayon(rayon), hauteur(hauteur) {}
            double aire() const {
                double generatrice = sqrt(hauteur * hauteur + rayon * rayon);
                return 3.14159 * rayon * (rayon + generatrice);
            }
            double volume() const {
                return (1.0 / 3.0) * 3.14159 * rayon * rayon * hauteur;
            }
        };

        class PyramideBaseCarree {
        public:
            Point3D centreBase;
            double longueurBase;
            double largeurBase;
            double hauteur;
            PyramideBaseCarree(const Point3D& centreBase, double longueurBase, double largeurBase, double hauteur)
                : centreBase(centreBase), longueurBase(longueurBase), largeurBase(largeurBase), hauteur(hauteur) {}
            double aire() const {
                double base = longueurBase * largeurBase;
                double surfaceLaterale = 2 * (longueurBase * sqrt((largeurBase / 2) * (largeurBase / 2) + hauteur * hauteur) +
                                            largeurBase * sqrt((longueurBase / 2) * (longueurBase / 2) + hauteur * hauteur));
                return base + surfaceLaterale;
            }
            double volume() const {
                return (1.0 / 3.0) * longueurBase * largeurBase * hauteur;
            }
        };

        class PyramideBaseTriangulaire {
        public:
            Point3D centreBase;
            double coteBase;
            double hauteur;
            PyramideBaseTriangulaire(const Point3D& centreBase, double coteBase, double hauteur)
                : centreBase(centreBase), coteBase(coteBase), hauteur(hauteur) {}
            double aire() const {
                double base = (sqrt(3) / 4) * coteBase * coteBase;
                double surfaceLaterale = 3 * (0.5 * coteBase * sqrt((coteBase / 2) * (coteBase / 2) + hauteur * hauteur));
                return base + surfaceLaterale;
            }
            double volume() const {
                return (1.0 / 3.0) * (sqrt(3) / 4) * coteBase * coteBase * hauteur;
            }
        };

        class PyramideBasePolygoneRegulier {
        public:
            Point3D centreBase;
            int nombreCotesBase;
            double longueurCoteBase;
            double hauteur;
            PyramideBasePolygoneRegulier(const Point3D& centreBase, int nombreCotesBase, double longueurCoteBase, double hauteur)
                : centreBase(centreBase), nombreCotesBase(nombreCotesBase), longueurCoteBase(longueurCoteBase), hauteur(hauteur) {}
            double aire() const {
                double base = (nombreCotesBase * longueurCoteBase * longueurCoteBase) / (4 * tan(3.14159 / nombreCotesBase));
                double surfaceLaterale = (nombreCotesBase * longueurCoteBase * sqrt((longueurCoteBase / (2 * tan(3.14159 / nombreCotesBase))) * (longueurCoteBase / (2 * tan(3.14159 / nombreCotesBase))) + hauteur * hauteur)) / 2;
                return base + surfaceLaterale;
            }
            double volume() const {
                return (1.0 / 3.0) * ((nombreCotesBase * longueurCoteBase * longueurCoteBase) / (4 * tan(3.14159 / nombreCotesBase))) * hauteur;
            }
        };

/* ═══════════════════════════════════════════════════════════════
   3. PHYSIQUE
   ═══════════════════════════════════════════════════════════════ */

    // ─── 3.1 Vecteurs et forces ───

        class Vitesse {
        public:
            double x;
            double y;
            double z;
            Vitesse(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
        };

        class Acceleration {
        public:
            double x;
            double y;
            double z;
            Acceleration(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
        };

        class Force {
        public:
            double x;
            double y;
            double z;
            Force(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
        };

    // ─── 3.2 Mécanique classique ───

        class Particule {
        public:
            Point3D position;
            Vitesse vitesse;
            double masse;
            Particule(const Point3D& position, const Vitesse& vitesse, double masse)
                : position(position), vitesse(vitesse), masse(masse) {}
            void appliquerForce(const Force& force, double duree) {
                Acceleration accel = {force.x / masse, force.y / masse, force.z / masse};
                vitesse.x += accel.x * duree;
                vitesse.y += accel.y * duree;
                vitesse.z += accel.z * duree;
                position.x += vitesse.x * duree;
                position.y += vitesse.y * duree;
                position.z += vitesse.z * duree;
            }
        };

        class SystemeParticules {
        public:
            vector<Particule> particules;
            void ajouterParticule(const Particule& particule) {
                particules.push_back(particule);
            }
            void appliquerForceGlobal(const Force& force, double duree) {
                for (Particule& particule : particules) {
                    particule.appliquerForce(force, duree);
                }
            }
        };

    // ─── 3.3 Électromagnétisme ───

        class LoiOhm {
        public:
            double resistance;
            LoiOhm(double resistance) : resistance(resistance) {}
            double calculerCourant(double tension) const {
                return tension / resistance;
            }
        };

        class LoiCoulomb {
        public:
            double constante;
            LoiCoulomb(double constante) : constante(constante) {}
            double calculerForce(double charge1, double charge2, double distance) const {
                return constante * (charge1 * charge2) / (distance * distance);
            }
        };

        class LoiFaraday {
        public:
            double coefficient;
            LoiFaraday(double coefficient) : coefficient(coefficient) {}
            double calculerTension(double variationFlux, double duree) const {
                return -coefficient * (variationFlux / duree);
            }
        };

        class LoiAmpere {
        public:
            double permeabilite;
            LoiAmpere(double permeabilite) : permeabilite(permeabilite) {}
            double calculerChampMagnetique(double courant, double distance) const {
                return (permeabilite * courant) / (2 * 3.14159 * distance);
            }
        };

        class ChampElectrique {
        public:
            Point3D centre;
            double charge;
            ChampElectrique(const Point3D& centre, double charge) : centre(centre), charge(charge) {}
            Force calculerForce(const Particule& particule) const {
                double k = 8.98755e9; // Constante de Coulomb
                double distance = centre.distance(particule.position);
                double forceMagnitude = k * charge * particule.masse / (distance * distance);
                return {forceMagnitude * (centre.x - particule.position.x) / distance,
                        forceMagnitude * (centre.y - particule.position.y) / distance,
                        forceMagnitude * (centre.z - particule.position.z) / distance};
            }
        };

        class ChampMagnetique {
        public:
            Point3D centre;
            double intensite;
            ChampMagnetique(const Point3D& centre, double intensite) : centre(centre), intensite(intensite) {}
            Force calculerForce(const Particule& particule) const {
                // Force de Lorentz : F = q * v x B
                double q = particule.masse; // Supposons que la charge est proportionnelle à la masse
                return {q * (particule.vitesse.y * intensite - particule.vitesse.z * 0),
                        q * (particule.vitesse.z * intensite - particule.vitesse.x * 0),
                        q * (particule.vitesse.x * intensite - particule.vitesse.y * 0)};
            }
        };

        class ChampElectromagnetique {
        public:
            ChampElectrique champE;
            ChampMagnetique champB;
            ChampElectromagnetique(const ChampElectrique& champE, const ChampMagnetique& champB)
                : champE(champE), champB(champB) {}
            Force calculerForce(const Particule& particule) const {
                Force forceE = champE.calculerForce(particule);
                Force forceB = champB.calculerForce(particule);
                return {forceE.x + forceB.x, forceE.y + forceB.y, forceE.z + forceB.z};
            }
        };

    // ─── 3.4 Oscillateurs et ondes ───

        class OscillateurHarmonique {
        public:
            double masse;
            double raideur;
            double amplitude;
            double frequence;
            OscillateurHarmonique(double masse, double raideur, double amplitude)
                : masse(masse), raideur(raideur), amplitude(amplitude) {
                frequence = sqrt(raideur / masse) / (2 * 3.14159);
            }
            double position(double temps) const {
                return amplitude * cos(2 * 3.14159 * frequence * temps);
            }
        };

        class PenduleSimple {
        public:
            double longueur;
            double masse;
            double amplitude;
            double frequence;
            PenduleSimple(double longueur, double masse, double amplitude)
                : longueur(longueur), masse(masse), amplitude(amplitude) {
                frequence = sqrt(9.81 / longueur) / (2 * 3.14159);
            }
            double position(double temps) const {
                return amplitude * cos(2 * 3.14159 * frequence * temps);
            }
        };

    // ─── 3.5 Gravitation et astronomie ───

        class SystemeSolaire {
        public:
            vector<Cercle> planètes;
            void ajouterPlanète(const Cercle& planète) {
                planètes.push_back(planète);
            }
            void afficherPlanètes() const {
                for (const Cercle& planète : planètes) {
                    cout << "Planète avec rayon " << planète.rayon << " et centre (" << planète.centre.x << ", " << planète.centre.y << ")" << endl;
                }
            }
        };

        class ChampGravitationnel {
        public:
            Point3D centre;
            double masse;
            ChampGravitationnel(const Point3D& centre, double masse) : centre(centre), masse(masse) {}
            Point3D calculerForce(const Particule& particule) const {
                double G = 6.67430e-11; // Constante gravitationnelle
                double distance = centre.distance(particule.position);
                double forceMagnitude = G * masse * particule.masse / (distance * distance);
                return {forceMagnitude * (centre.x - particule.position.x) / distance,
                        forceMagnitude * (centre.y - particule.position.y) / distance,
                        forceMagnitude * (centre.z - particule.position.z) / distance};
            }
        };

    // ─── 3.6 Optique ───

        class Lentille {
        public:
            double distanceFocale;
            Lentille(double distanceFocale) : distanceFocale(distanceFocale) {}
            double calculerImage(double distanceObjet) const {
                return 1 / (1 / distanceFocale - 1 / distanceObjet);
            }
        };

        class Miroir {
        public:
            double distanceFocale;
            Miroir(double distanceFocale) : distanceFocale(distanceFocale) {}
            double calculerImage(double distanceObjet) const {
                return 1 / (1 / distanceFocale - 1 / distanceObjet);
            }
        };

        class Prisme {
        public:
            double indiceRefraction;
            Prisme(double indiceRefraction) : indiceRefraction(indiceRefraction) {}
            double calculerAngleRefraction(double angleIncidence) const {
                return asin(sin(angleIncidence) / indiceRefraction);
            }
        };

        class FibreOptique {
        public:
            double indiceRefractionNoyau;
            double indiceRefractionGaine;
            FibreOptique(double indiceRefractionNoyau, double indiceRefractionGaine)
                : indiceRefractionNoyau(indiceRefractionNoyau), indiceRefractionGaine(indiceRefractionGaine) {}
            bool estGuidageTotal(double angleIncidence) const {
                return asin(sin(angleIncidence) / indiceRefractionNoyau) > asin(sin(angleIncidence) / indiceRefractionGaine);
            }
        };

        class ReseauDiffraction {
        public:
            double espacement;
            ReseauDiffraction(double espacement) : espacement(espacement) {}
            double calculerAngleDiffraction(double longueurOnde, int ordre) const {
                return asin(ordre * longueurOnde / espacement);
            }
        };

        class Interferometre {
        public:
            double distanceEntreBras;
            Interferometre(double distanceEntreBras) : distanceEntreBras(distanceEntreBras) {}
            double calculerFrangeInterference(double longueurOnde) const {
                return (longueurOnde * distanceEntreBras) / (2 * distanceEntreBras);
            }
        };

/* ═══════════════════════════════════════════════════════════════
   4. CHIMIE
   ═══════════════════════════════════════════════════════════════ */

    // ─── 4.1 Atomes et éléments ───

        class Atome {
        public:
            string symbole;
            int numeroAtomique;
            double masseAtomique;
            int nombreElectrons;
            Atome(const string& symbole, int numeroAtomique, double masseAtomique, int nombreElectrons)
                : symbole(symbole), numeroAtomique(numeroAtomique),
                  masseAtomique(masseAtomique), nombreElectrons(nombreElectrons) {}
            int charge() const {
                return numeroAtomique - nombreElectrons;
            }
            bool estIon() const {
                return charge() != 0;
            }
            string configurationSimplifiee() const {
                int e = nombreElectrons;
                string config = "";
                int couches[] = {2, 8, 8, 18, 18, 32};
                int n = 1;
                for (int i = 0; i < 6 && e > 0; i++) {
                    int maximum = couches[i];
                    int dans = (e > maximum) ? maximum : e;
                    config += to_string(n) + ":" + to_string(dans) + " ";
                    e -= dans;
                    n++;
                }
                return config;
            }
        };

        class Element {
        public:
            string nom;
            string symbole;
            int numeroAtomique;
            double masseMolaire;
            double electronegativite;
            Element(const string& nom, const string& symbole, int numeroAtomique,
                    double masseMolaire, double electronegativite)
                : nom(nom), symbole(symbole), numeroAtomique(numeroAtomique),
                  masseMolaire(masseMolaire), electronegativite(electronegativite) {}
            bool estMetal() const {
                return electronegativite < 1.8;
            }
            bool estNonMetal() const {
                return electronegativite >= 2.5;
            }
        };

    // ─── 4.2 Molécules et réactions ───

        class Molecule {
        public:
            string formule;
            double masseMolaire;
            vector<Atome> atomes;
            Molecule(const string& formule, double masseMolaire)
                : formule(formule), masseMolaire(masseMolaire) {}
            void ajouterAtome(const Atome& atome) {
                atomes.push_back(atome);
            }
            int nombreAtomes() const {
                return atomes.size();
            }
            double calculerMoles(double masseGrammes) const {
                return masseGrammes / masseMolaire;
            }
            double calculerMasse(double moles) const {
                return moles * masseMolaire;
            }
        };

        class ReactionChimique {
        public:
            vector<Molecule> reactifs;
            vector<Molecule> produits;
            vector<int> coeffReactifs;
            vector<int> coeffProduits;
            void ajouterReactif(const Molecule& mol, int coeff = 1) {
                reactifs.push_back(mol);
                coeffReactifs.push_back(coeff);
            }
            void ajouterProduit(const Molecule& mol, int coeff = 1) {
                produits.push_back(mol);
                coeffProduits.push_back(coeff);
            }
            double reactifLimitant(const vector<double>& molesReactifs) const {
                double minRapport = 1e18;
                for (int i = 0; i < (int)molesReactifs.size(); i++) {
                    double rapport = molesReactifs[i] / coeffReactifs[i];
                    if (rapport < minRapport) minRapport = rapport;
                }
                return minRapport;
            }
        };

    // ─── 4.3 Solutions et concentrations ───

        class Solution {
        public:
            string solute;
            double concentration; // mol/L
            double volume;        // L
            Solution(const string& solute, double concentration, double volume)
                : solute(solute), concentration(concentration), volume(volume) {}
            double quantiteMoles() const {
                return concentration * volume;
            }
            double masseSolute(double masseMolaire) const {
                return quantiteMoles() * masseMolaire;
            }
            Solution diluer(double nouveauVolume) const {
                double nouvelleConc = (concentration * volume) / nouveauVolume;
                return Solution(solute, nouvelleConc, nouveauVolume);
            }
            Solution melanger(const Solution& autre) const {
                double molesTotal = quantiteMoles() + autre.quantiteMoles();
                double volumeTotal = volume + autre.volume;
                return Solution(solute, molesTotal / volumeTotal, volumeTotal);
            }
        };

        class AcideBase {
        public:
            string nom;
            double ka;
            bool estAcide;
            AcideBase(const string& nom, double ka, bool estAcide)
                : nom(nom), ka(ka), estAcide(estAcide) {}
            double pKa() const {
                return -log10(ka);
            }
            double calculerPH(double concentration) const {
                if (estAcide) {
                    return 0.5 * (pKa() - log10(concentration));
                } else {
                    return 14.0 - 0.5 * (pKa() - log10(concentration));
                }
            }
        };

    // ─── 4.4 Thermodynamique chimique ───

        class ReactionThermodynamique {
        public:
            double enthalpie;   // kJ/mol
            double entropie;    // J/(mol*K)
            double temperature; // K
            ReactionThermodynamique(double enthalpie, double entropie, double temperature)
                : enthalpie(enthalpie), entropie(entropie), temperature(temperature) {}
            double energieGibbs() const {
                return enthalpie - temperature * (entropie / 1000.0);
            }
            bool estSpontanee() const {
                return energieGibbs() < 0;
            }
            double constanteEquilibre() const {
                double dG = energieGibbs() * 1000.0;
                return exp(-dG / (8.314 * temperature));
            }
        };

        class Calorimetrie {
        public:
            double masseSolution;     // g
            double capaciteThermique; // J/(g*C)
            double deltaTemperature;  // C
            Calorimetrie(double masse, double capacite, double deltaT)
                : masseSolution(masse), capaciteThermique(capacite), deltaTemperature(deltaT) {}
            double chaleurDegagee() const {
                return masseSolution * capaciteThermique * deltaTemperature;
            }
            double enthalpieReaction(double moles) const {
                return -chaleurDegagee() / moles / 1000.0;
            }
        };

    // ─── 4.5 Cinétique chimique ───

        class ReactionCinetique {
        public:
            double constanteVitesse;
            int ordre;
            ReactionCinetique(double k, int ordre)
                : constanteVitesse(k), ordre(ordre) {}
            double vitesse(double concentration) const {
                return constanteVitesse * pow(concentration, ordre);
            }
            double demiVie(double concentrationInitiale = 1.0) const {
                switch (ordre) {
                    case 0: return concentrationInitiale / (2 * constanteVitesse);
                    case 1: return log(2) / constanteVitesse;
                    case 2: return 1.0 / (constanteVitesse * concentrationInitiale);
                    default: return -1;
                }
            }
            double concentrationATemps(double c0, double temps) const {
                switch (ordre) {
                    case 0: return c0 - constanteVitesse * temps;
                    case 1: return c0 * exp(-constanteVitesse * temps);
                    case 2: return 1.0 / (1.0 / c0 + constanteVitesse * temps);
                    default: return -1;
                }
            }
        };

        class EquationArrhenius {
        public:
            double facteurPreExponentiel; // A
            double energieActivation;     // Ea en J/mol
            EquationArrhenius(double A, double Ea)
                : facteurPreExponentiel(A), energieActivation(Ea) {}
            double constanteVitesse(double temperature) const {
                return facteurPreExponentiel * exp(-energieActivation / (8.314 * temperature));
            }
            double calculerEa(double k1, double T1, double k2, double T2) const {
                return 8.314 * log(k2 / k1) / (1.0 / T1 - 1.0 / T2);
            }
        };

/* ═══════════════════════════════════════════════════════════════
   5. BIOLOGIE
   ═══════════════════════════════════════════════════════════════ */

    // ─── 5.1 Cellules et organites ───

        class Organite {
        public:
            string nom;
            string fonction;
            double tailleMicrons;
            Organite(const string& nom, const string& fonction, double tailleMicrons)
                : nom(nom), fonction(fonction), tailleMicrons(tailleMicrons) {}
        };

        class Cellule {
        public:
            string type; // "procaryote" ou "eucaryote"
            double tailleMicrons;
            vector<Organite> organites;
            Cellule(const string& type, double tailleMicrons)
                : type(type), tailleMicrons(tailleMicrons) {}
            void ajouterOrganite(const Organite& organite) {
                organites.push_back(organite);
            }
            int nombreOrganites() const {
                return organites.size();
            }
            bool estEucaryote() const {
                return type == "eucaryote";
            }
        };

        class ADN {
        public:
            string sequence; // A, T, C, G
            ADN(const string& sequence) : sequence(sequence) {}
            int longueur() const {
                return sequence.length();
            }
            string complementaire() const {
                string comp = "";
                for (char base : sequence) {
                    switch (base) {
                        case 'A': comp += 'T'; break;
                        case 'T': comp += 'A'; break;
                        case 'C': comp += 'G'; break;
                        case 'G': comp += 'C'; break;
                        default: comp += '?'; break;
                    }
                }
                return comp;
            }
            string transcrireARN() const {
                string arn = "";
                for (char base : sequence) {
                    switch (base) {
                        case 'A': arn += 'U'; break;
                        case 'T': arn += 'A'; break;
                        case 'C': arn += 'G'; break;
                        case 'G': arn += 'C'; break;
                        default: arn += '?'; break;
                    }
                }
                return arn;
            }
            double contenuGC() const {
                int gc = 0;
                for (char base : sequence) {
                    if (base == 'G' || base == 'C') gc++;
                }
                return (double)gc / sequence.length() * 100.0;
            }
        };

        class Population {
        public:
            string espece;
            int taille;
            double tauxCroissance;
            Population(const string& espece, int taille, double tauxCroissance)
                : espece(espece), taille(taille), tauxCroissance(tauxCroissance) {}
            double tailleApresGenerations(int generations) const {
                return taille * pow(1 + tauxCroissance, generations);
            }
            double tempsDoublement() const {
                return log(2) / log(1 + tauxCroissance);
            }
        };

/* ═══════════════════════════════════════════════════════════════
   6. INFORMATIQUE
   ═══════════════════════════════════════════════════════════════ */

    // ─── 6.1 Structures de données ───

        class Noeud {
        public:
            int valeur;
            Noeud* suivant;
            Noeud(int valeur) : valeur(valeur), suivant(nullptr) {}
        };

        class ListeChainee {
        public:
            Noeud* tete;
            int taille;
            ListeChainee() : tete(nullptr), taille(0) {}
            void ajouterDebut(int valeur) {
                Noeud* nouveau = new Noeud(valeur);
                nouveau->suivant = tete;
                tete = nouveau;
                taille++;
            }
            void ajouterFin(int valeur) {
                Noeud* nouveau = new Noeud(valeur);
                if (!tete) { tete = nouveau; taille++; return; }
                Noeud* courant = tete;
                while (courant->suivant) courant = courant->suivant;
                courant->suivant = nouveau;
                taille++;
            }
            bool rechercher(int valeur) const {
                Noeud* courant = tete;
                while (courant) {
                    if (courant->valeur == valeur) return true;
                    courant = courant->suivant;
                }
                return false;
            }
            void afficher() const {
                Noeud* courant = tete;
                while (courant) {
                    cout << courant->valeur << " -> ";
                    courant = courant->suivant;
                }
                cout << "nullptr" << endl;
            }
        };

        class Pile {
        public:
            vector<int> elements;
            void empiler(int valeur) {
                elements.push_back(valeur);
            }
            int depiler() {
                if (elements.empty()) throw runtime_error("Pile vide");
                int val = elements.back();
                elements.pop_back();
                return val;
            }
            int sommet() const {
                if (elements.empty()) throw runtime_error("Pile vide");
                return elements.back();
            }
            bool estVide() const {
                return elements.empty();
            }
            int taille() const {
                return elements.size();
            }
        };

        class File {
        public:
            vector<int> elements;
            void enfiler(int valeur) {
                elements.push_back(valeur);
            }
            int defiler() {
                if (elements.empty()) throw runtime_error("File vide");
                int val = elements.front();
                elements.erase(elements.begin());
                return val;
            }
            int premier() const {
                if (elements.empty()) throw runtime_error("File vide");
                return elements.front();
            }
            bool estVide() const {
                return elements.empty();
            }
            int taille() const {
                return elements.size();
            }
        };

        class NoeudArbre {
        public:
            int valeur;
            NoeudArbre* gauche;
            NoeudArbre* droite;
            NoeudArbre(int valeur) : valeur(valeur), gauche(nullptr), droite(nullptr) {}
        };

        class ArbreBinaire {
        public:
            NoeudArbre* racine;
            ArbreBinaire() : racine(nullptr) {}
            void inserer(int valeur) {
                racine = insererRecursif(racine, valeur);
            }
            bool rechercher(int valeur) const {
                return rechercherRecursif(racine, valeur);
            }
            void afficherInOrdre() const {
                parcourir(racine);
                cout << endl;
            }
        private:
            NoeudArbre* insererRecursif(NoeudArbre* noeud, int valeur) {
                if (!noeud) return new NoeudArbre(valeur);
                if (valeur < noeud->valeur) noeud->gauche = insererRecursif(noeud->gauche, valeur);
                else if (valeur > noeud->valeur) noeud->droite = insererRecursif(noeud->droite, valeur);
                return noeud;
            }
            bool rechercherRecursif(NoeudArbre* noeud, int valeur) const {
                if (!noeud) return false;
                if (valeur == noeud->valeur) return true;
                if (valeur < noeud->valeur) return rechercherRecursif(noeud->gauche, valeur);
                return rechercherRecursif(noeud->droite, valeur);
            }
            void parcourir(NoeudArbre* noeud) const {
                if (!noeud) return;
                parcourir(noeud->gauche);
                cout << noeud->valeur << " ";
                parcourir(noeud->droite);
            }
        };

    // ─── 6.2 Algorithmes ───

        class AlgorithmeTri {
        public:
            static void triBulle(vector<int>& v) {
                int n = v.size();
                for (int i = 0; i < n - 1; i++)
                    for (int j = 0; j < n - i - 1; j++)
                        if (v[j] > v[j + 1]) swap(v[j], v[j + 1]);
            }
            static void triSelection(vector<int>& v) {
                int n = v.size();
                for (int i = 0; i < n - 1; i++) {
                    int minIdx = i;
                    for (int j = i + 1; j < n; j++)
                        if (v[j] < v[minIdx]) minIdx = j;
                    swap(v[i], v[minIdx]);
                }
            }
            static void triInsertion(vector<int>& v) {
                int n = v.size();
                for (int i = 1; i < n; i++) {
                    int cle = v[i];
                    int j = i - 1;
                    while (j >= 0 && v[j] > cle) {
                        v[j + 1] = v[j];
                        j--;
                    }
                    v[j + 1] = cle;
                }
            }
        };

        class AlgorithmeRecherche {
        public:
            static int rechercheLineaire(const vector<int>& v, int cible) {
                for (int i = 0; i < (int)v.size(); i++)
                    if (v[i] == cible) return i;
                return -1;
            }
            static int rechercheBinaire(const vector<int>& v, int cible) {
                int gauche = 0, droite = v.size() - 1;
                while (gauche <= droite) {
                    int milieu = (gauche + droite) / 2;
                    if (v[milieu] == cible) return milieu;
                    if (v[milieu] < cible) gauche = milieu + 1;
                    else droite = milieu - 1;
                }
                return -1;
            }
        };

    // ─── 6.3 Réseaux et systèmes d'exploitation ───

        class Processus {
        public:
            int pid;
            string nom;
            int priorite;
            string etat;
            Processus(int pid, const string& nom, int priorite)
                : pid(pid), nom(nom), priorite(priorite), etat("pret") {}
            void executer() { etat = "en_execution"; }
            void bloquer() { etat = "bloque"; }
            void terminer() { etat = "termine"; }
            void debloquer() { etat = "pret"; }
        };

        class SystemeExploitation {
        public:
            string nom;
            vector<Processus> processus;
            int prochainPID;
            SystemeExploitation(const string& nom) : nom(nom), prochainPID(1) {}
            void creerProcessus(const string& nomProc, int priorite) {
                processus.push_back(Processus(prochainPID++, nomProc, priorite));
            }
            void afficherProcessus() const {
                cout << "=== " << nom << " ===" << endl;
                for (const Processus& p : processus) {
                    cout << "PID: " << p.pid << " | " << p.nom
                         << " | Priorite: " << p.priorite
                         << " | Etat: " << p.etat << endl;
                }
            }
        };

/* ═══════════════════════════════════════════════════════════════
   7. OBJETS
   ═══════════════════════════════════════════════════════════════ */

    // ─── 7.1 Objets de la vie quotidienne ───

    class CompteBancaire {
    public:
        string titulaire;
        double solde;
        CompteBancaire(const string& titulaire, double solde = 0) : titulaire(titulaire), solde(solde) {}
        void deposer(double montant) {
            solde += montant;
        }
        void retirer(double montant) {
            if (montant > solde) throw invalid_argument("Fonds insuffisants");
            solde -= montant;
        }
    };

    class Livre {
    public:
        string titre;
        string auteur;
        int anneePublication;
        Livre(const string& titre, const string& auteur, int anneePublication)
            : titre(titre), auteur(auteur), anneePublication(anneePublication) {}
    };

    class Voiture {
    public:
        string marque;
        string modele;
        int annee;
        Voiture(const string& marque, const string& modele, int annee)
            : marque(marque), modele(modele), annee(annee) {}
    };

    class Smartphone {
    public:
        string marque;
        string modele;
        double tailleEcran;
        Smartphone(const string& marque, const string& modele, double tailleEcran)
            : marque(marque), modele(modele), tailleEcran(tailleEcran) {}
    };

    class Ordinateur {
    public:
        string marque;
        string modele;
        double tailleEcran;
        Ordinateur(const string& marque, const string& modele, double tailleEcran)
            : marque(marque), modele(modele), tailleEcran(tailleEcran) {}
    };

    class Maison {
    public:
        string adresse;
        int nombrePieces;
        double superficie;
        Maison(const string& adresse, int nombrePieces, double superficie)
            : adresse(adresse), nombrePieces(nombrePieces), superficie(superficie) {}
    };

    class Personne {
    public:
        string nom;
        int age;
        string profession;
        Personne(const string& nom, int age, const string& profession)
            : nom(nom), age(age), profession(profession) {}
    };

    // ─── 7.2 Outils et instruments ───

        // ─── 7.2.1 Appareils de mesure ───

        class Barometre {
        public:
            double pression;
            Barometre(double pression = 1013.25) : pression(pression) {}
            void mesurerPression(double nouvellePression) {
                pression = nouvellePression;
            }
        };

        class Thermometre {
        public:
            double temperature;
            Thermometre(double temperature = 20.0) : temperature(temperature) {}
            void mesurerTemperature(double nouvelleTemperature) {
                temperature = nouvelleTemperature;
            }
        };

        class Horloge {
        public:
            int heures;
            int minutes;
            int secondes;
            Horloge(int heures = 0, int minutes = 0, int secondes = 0) : heures(heures), minutes(minutes), secondes(secondes) {}
            void afficherHeure() const {
                cout << (heures < 10 ? "0" : "") << heures << ":"
                    << (minutes < 10 ? "0" : "") << minutes << ":"
                    << (secondes < 10 ? "0" : "") << secondes << endl;
            }
        };

        // ─── 7.2.2 Calculatrices ───

        class CalculatriceSimple {
        public:
            double addition(double a, double b) const {
                return a + b;
            }
            double soustraction(double a, double b) const {
                return a - b;
            }
            double multiplication(double a, double b) const {
                return a * b;
            }
            double division(double a, double b) const {
                if (b == 0) throw invalid_argument("Division par zéro");
                return a / b;
            }
        };

        class CalculatriceScientifique : public CalculatriceSimple {
        public:
            double puissance(double base, double exposant) const {
                return pow(base, exposant);
            }
            double racineCarree(double a) const {
                if (a < 0) throw invalid_argument("Nombre négatif pour racine carrée");
                return sqrt(a);
            }
            double logarithme(double a) const {
                if (a <= 0) throw invalid_argument("Nombre non positif pour logarithme");
                return log(a);
            }
        };

        // ─── 7.2.3 Instruments de laboratoire ───

        class Titrateur {
        public:
            double volumeAcide;
            double concentrationAcide;
            Titrateur(double volumeAcide = 0, double concentrationAcide = 0) : volumeAcide(volumeAcide), concentrationAcide(concentrationAcide) {}
        };

        class Burette {
        public:
            double volumeBase;
            double concentrationBase;
            Burette(double volumeBase = 0, double concentrationBase = 0) : volumeBase(volumeBase), concentrationBase(concentrationBase) {}
        };

        class PHmetre {
        public:
            double pH;
            PHmetre(double pH = 7.0) : pH(pH) {}
        };

        class Balance {
        public:
            double masse;
            Balance(double masse = 0) : masse(masse) {}
        };

        class Spectrometre {
        public:
            double longueurOnde;
            Spectrometre(double longueurOnde = 0) : longueurOnde(longueurOnde) {}
        };

        // ─── 7.2.4 Informatique et réseaux ───

        class Compilateur {
        public:
            string langage;
            Compilateur(const string& langage) : langage(langage) {}
            void compiler(const string& codeSource) {
                cout << "Compilation du code source en " << langage << "..." << endl;
                cout << "Compilation réussie!" << endl;
            }
        };

        class ReseauSocial {
        public:
            string nom;
            vector<Personne> utilisateurs;
            ReseauSocial(const string& nom) : nom(nom) {}
            void ajouterUtilisateur(const Personne& personne) {
                utilisateurs.push_back(personne);
            }
            void afficherUtilisateurs() const {
                for (const Personne& utilisateur : utilisateurs) {
                    cout << "Utilisateur: " << utilisateur.nom << ", Age: " << utilisateur.age << ", Profession: " << utilisateur.profession << endl;
                }
            }
        };

        class ServeurWeb {
        public:
            string adresseIP;
            ServeurWeb(const string& adresseIP) : adresseIP(adresseIP) {}
            void hébergerSite(const string& nomSite) {
                cout << "Hébergement du site " << nomSite << " sur le serveur " << adresseIP << "..." << endl;
                cout << "Site hébergé avec succès!" << endl;
            }
        };

        class BaseDeDonnees {
        public:
            string nom;
            vector<string> tables;
            BaseDeDonnees(const string& nom) : nom(nom) {}
            void ajouterTable(const string& nomTable) {
                tables.push_back(nomTable);
            }
            void afficherTables() const {
                cout << "Base de données: " << nom << endl;
                for (const string& table : tables) {
                    cout << "Table: " << table << endl;
                }
            }
        };

        class Routeur {
        public:
            string adresseIP;
            Routeur(const string& adresseIP) : adresseIP(adresseIP) {}
            void acheminerPaquet(const string& destination) {
                cout << "Acheminement du paquet vers " << destination << " via le routeur " << adresseIP << "..." << endl;
                cout << "Paquet acheminé avec succès!" << endl;
            }
        };