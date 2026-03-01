/* Fichier   : file-handling.cpp    
    Auteure  : Charlie Bouchard    
    Cours    : IFT1969 - Programmation scientifique en langage C    
    Trimestre: Automne 2025    
    But      : Inventaire de fonctions de gestion de fichiers    
    Notes    :        
        - Nécessite C++17 pour <filesystem>        
        - Fonctions utilitaires pour lecture, écriture, copie, manipulation de fichiers
    Dernière mise à jour : 2026-02-27
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <algorithm>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <future>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <map>
#include <set>
#include <regex>
#include <functional>

using namespace std;
using namespace std::filesystem;
using namespace std::chrono;
using namespace std::this_thread;

/*  TABLE DES MATIÈRES
    ══════════════════
     1. Lecture de fichiers
        1.1 Lire un fichier complet
        1.2 Lire les lignes d'un fichier
        1.3 Lire un fichier binaire
        1.4 Lire un fichier CSV
        1.5 Lire les N premières / dernières lignes
        1.6 Lire une plage de lignes
     2. Écriture de fichiers
        2.1 Écrire dans un fichier
        2.2 Ajouter à un fichier
        2.3 Écrire des lignes dans un fichier
        2.4 Écrire un fichier binaire
        2.5 Écrire un fichier CSV
     3. Opérations sur les fichiers
        3.1 Copier un fichier
        3.2 Déplacer / renommer un fichier
        3.3 Supprimer un fichier
        3.4 Comparer deux fichiers
        3.5 Fusionner des fichiers
        3.6 Diviser un fichier
     4. Opérations sur les répertoires
        4.1 Lister les fichiers d'un répertoire
        4.2 Lister les fichiers récursivement
        4.3 Lister les sous-répertoires
        4.4 Créer un répertoire
        4.5 Supprimer un répertoire
        4.6 Copier un répertoire
     5. Informations sur les fichiers
        5.1 Vérifier l'existence
        5.2 Obtenir la taille
        5.3 Obtenir l'extension
        5.4 Obtenir le nom du fichier
        5.5 Obtenir le répertoire parent
        5.6 Obtenir le chemin absolu
        5.7 Obtenir la date de dernière modification
        5.8 Vérifier si c'est un fichier / répertoire
        5.9 Obtenir les permissions
     6. Recherche et remplacement
        6.1 Rechercher dans un fichier
        6.2 Rechercher avec regex
        6.3 Remplacer dans un fichier
        6.4 Rechercher des fichiers par nom
        6.5 Rechercher des fichiers par extension
        6.6 Rechercher des fichiers par contenu
     7. Statistiques de fichiers
        7.1 Compter les lignes
        7.2 Compter les mots
        7.3 Compter les caractères
        7.4 Compter les occurrences d'un mot
        7.5 Fréquence des mots
     8. Manipulation de chemins
        8.1 Joindre des chemins
        8.2 Normaliser un chemin
        8.3 Chemin relatif
        8.4 Changer l'extension
        8.5 Obtenir la racine du chemin
     9. Utilitaires avancés
        9.1 Créer un fichier temporaire
        9.2 Verrouiller un fichier (mutex)
        9.3 Surveiller un fichier pour modifications
        9.4 Calculer un checksum simple
        9.5 Sauvegarder avec horodatage
        9.6 Lire un fichier de configuration (clé=valeur)
        9.7 Écrire un fichier de configuration
*/

/* ═══════════════════════════════════════════════════════════════
   1. LECTURE DE FICHIERS
   ═══════════════════════════════════════════════════════════════ */

    // ─── 1.1 Lire un fichier complet ───

        string lireFichier(const string& cheminFichier) {
            ifstream fichier(cheminFichier);
            if (!fichier.is_open()) {
                throw runtime_error("Impossible d'ouvrir le fichier : " + cheminFichier);
            }
            stringstream tampon;
            tampon << fichier.rdbuf();
            return tampon.str();
        }

    // ─── 1.2 Lire les lignes d'un fichier ───

        vector<string> lireLignes(const string& cheminFichier) {
            ifstream fichier(cheminFichier);
            if (!fichier.is_open()) {
                throw runtime_error("Impossible d'ouvrir le fichier : " + cheminFichier);
            }
            vector<string> lignes;
            string ligne;
            while (getline(fichier, ligne)) {
                lignes.push_back(ligne);
            }
            return lignes;
        }

    // ─── 1.3 Lire un fichier binaire ───

        vector<char> lireFichierBinaire(const string& cheminFichier) {
            ifstream fichier(cheminFichier, ios::binary | ios::ate);
            if (!fichier.is_open()) {
                throw runtime_error("Impossible d'ouvrir le fichier binaire : " + cheminFichier);
            }
            streamsize taille = fichier.tellg();
            fichier.seekg(0, ios::beg);
            vector<char> tampon(taille);
            if (!fichier.read(tampon.data(), taille)) {
                throw runtime_error("Erreur de lecture du fichier binaire : " + cheminFichier);
            }
            return tampon;
        }

    // ─── 1.4 Lire un fichier CSV ───

        vector<vector<string>> lireCSV(const string& cheminFichier, char delimiteur = ',') {
            ifstream fichier(cheminFichier);
            if (!fichier.is_open()) {
                throw runtime_error("Impossible d'ouvrir le fichier CSV : " + cheminFichier);
            }
            vector<vector<string>> donnees;
            string ligne;
            while (getline(fichier, ligne)) {
                vector<string> rangee;
                stringstream flux(ligne);
                string cellule;
                while (getline(flux, cellule, delimiteur)) {
                    rangee.push_back(cellule);
                }
                donnees.push_back(rangee);
            }
            return donnees;
        }

    // ─── 1.5 Lire les N premières / dernières lignes ───

        vector<string> lireNPremieresLignes(const string& cheminFichier, int n) {
            ifstream fichier(cheminFichier);
            if (!fichier.is_open()) {
                throw runtime_error("Impossible d'ouvrir le fichier : " + cheminFichier);
            }
            vector<string> lignes;
            string ligne;
            int compteur = 0;
            while (getline(fichier, ligne) && compteur < n) {
                lignes.push_back(ligne);
                compteur++;
            }
            return lignes;
        }

        vector<string> lireNDernieresLignes(const string& cheminFichier, int n) {
            vector<string> toutesLignes = lireLignes(cheminFichier);
            if (n >= (int)toutesLignes.size()) {
                return toutesLignes;
            }
            return vector<string>(toutesLignes.end() - n, toutesLignes.end());
        }

    // ─── 1.6 Lire une plage de lignes ───

        vector<string> lirePlageLignes(const string& cheminFichier, int debut, int fin) {
            // debut et fin sont inclusifs, indexés à partir de 1
            ifstream fichier(cheminFichier);
            if (!fichier.is_open()) {
                throw runtime_error("Impossible d'ouvrir le fichier : " + cheminFichier);
            }
            vector<string> lignes;
            string ligne;
            int numero = 1;
            while (getline(fichier, ligne)) {
                if (numero >= debut && numero <= fin) {
                    lignes.push_back(ligne);
                }
                if (numero > fin) break;
                numero++;
            }
            return lignes;
        }

/* ═══════════════════════════════════════════════════════════════
   2. ÉCRITURE DE FICHIERS
   ═══════════════════════════════════════════════════════════════ */

    // ─── 2.1 Écrire dans un fichier ───

        void ecrireFichier(const string& cheminFichier, const string& contenu) {
            ofstream fichier(cheminFichier);
            if (!fichier.is_open()) {
                throw runtime_error("Impossible d'ouvrir le fichier pour écriture : " + cheminFichier);
            }
            fichier << contenu;
        }

    // ─── 2.2 Ajouter à un fichier ───

        void ajouterAuFichier(const string& cheminFichier, const string& contenu) {
            ofstream fichier(cheminFichier, ios::app);
            if (!fichier.is_open()) {
                throw runtime_error("Impossible d'ouvrir le fichier pour ajout : " + cheminFichier);
            }
            fichier << contenu;
        }

    // ─── 2.3 Écrire des lignes dans un fichier ───

        void ecrireLignes(const string& cheminFichier, const vector<string>& lignes) {
            ofstream fichier(cheminFichier);
            if (!fichier.is_open()) {
                throw runtime_error("Impossible d'ouvrir le fichier pour écriture : " + cheminFichier);
            }
            for (const auto& ligne : lignes) {
                fichier << ligne << "\n";
            }
        }

        void ajouterLignes(const string& cheminFichier, const vector<string>& lignes) {
            ofstream fichier(cheminFichier, ios::app);
            if (!fichier.is_open()) {
                throw runtime_error("Impossible d'ouvrir le fichier pour ajout : " + cheminFichier);
            }
            for (const auto& ligne : lignes) {
                fichier << ligne << "\n";
            }
        }

    // ─── 2.4 Écrire un fichier binaire ───

        void ecrireFichierBinaire(const string& cheminFichier, const vector<char>& donnees) {
            ofstream fichier(cheminFichier, ios::binary);
            if (!fichier.is_open()) {
                throw runtime_error("Impossible d'ouvrir le fichier binaire pour écriture : " + cheminFichier);
            }
            fichier.write(donnees.data(), donnees.size());
        }

    // ─── 2.5 Écrire un fichier CSV ───

        void ecrireCSV(const string& cheminFichier, const vector<vector<string>>& donnees, char delimiteur = ',') {
            ofstream fichier(cheminFichier);
            if (!fichier.is_open()) {
                throw runtime_error("Impossible d'ouvrir le fichier CSV pour écriture : " + cheminFichier);
            }
            for (const auto& rangee : donnees) {
                for (size_t i = 0; i < rangee.size(); i++) {
                    if (i > 0) fichier << delimiteur;
                    fichier << rangee[i];
                }
                fichier << "\n";
            }
        }

/* ═══════════════════════════════════════════════════════════════
   3. OPÉRATIONS SUR LES FICHIERS
   ═══════════════════════════════════════════════════════════════ */

    // ─── 3.1 Copier un fichier ───

        void copierFichier(const string& source, const string& destination) {
            if (!exists(source)) {
                throw runtime_error("Le fichier source n'existe pas : " + source);
            }
            copy_file(source, destination, copy_options::overwrite_existing);
        }

    // ─── 3.2 Déplacer / renommer un fichier ───

        void deplacerFichier(const string& source, const string& destination) {
            if (!exists(source)) {
                throw runtime_error("Le fichier source n'existe pas : " + source);
            }
            rename(path(source), path(destination));
        }

        void renommerFichier(const string& ancienNom, const string& nouveauNom) {
            deplacerFichier(ancienNom, nouveauNom);
        }

    // ─── 3.3 Supprimer un fichier ───

        void supprimerFichier(const string& cheminFichier) {
            if (!exists(cheminFichier)) {
                throw runtime_error("Le fichier n'existe pas : " + cheminFichier);
            }
            remove(path(cheminFichier));
        }

    // ─── 3.4 Comparer deux fichiers ───

        bool comparerFichiers(const string& chemin1, const string& chemin2) {
            // Retourne true si les deux fichiers ont un contenu identique
            string contenu1 = lireFichier(chemin1);
            string contenu2 = lireFichier(chemin2);
            return contenu1 == contenu2;
        }

        vector<int> trouverLignesDifferentes(const string& chemin1, const string& chemin2) {
            // Retourne les numéros de lignes (1-indexés) qui diffèrent
            vector<string> lignes1 = lireLignes(chemin1);
            vector<string> lignes2 = lireLignes(chemin2);
            vector<int> differences;
            size_t maxLignes = max(lignes1.size(), lignes2.size());
            for (size_t i = 0; i < maxLignes; i++) {
                string l1 = (i < lignes1.size()) ? lignes1[i] : "";
                string l2 = (i < lignes2.size()) ? lignes2[i] : "";
                if (l1 != l2) {
                    differences.push_back(i + 1);
                }
            }
            return differences;
        }

    // ─── 3.5 Fusionner des fichiers ───

        void fusionnerFichiers(const vector<string>& fichiersSources, const string& fichierDestination) {
            ofstream destination(fichierDestination);
            if (!destination.is_open()) {
                throw runtime_error("Impossible d'ouvrir le fichier destination : " + fichierDestination);
            }
            for (const auto& source : fichiersSources) {
                string contenu = lireFichier(source);
                destination << contenu;
            }
        }

    // ─── 3.6 Diviser un fichier ───

        void diviserFichierParLignes(const string& cheminFichier, int lignesParPartie,
                                      const string& prefixeSortie) {
            // Divise un fichier en plusieurs parties de N lignes chacune
            vector<string> lignes = lireLignes(cheminFichier);
            int partie = 1;
            for (size_t i = 0; i < lignes.size(); i += lignesParPartie) {
                string nomPartie = prefixeSortie + "_partie" + to_string(partie) + ".txt";
                ofstream fichierPartie(nomPartie);
                for (size_t j = i; j < i + lignesParPartie && j < lignes.size(); j++) {
                    fichierPartie << lignes[j] << "\n";
                }
                partie++;
            }
        }

        void diviserFichierParTaille(const string& cheminFichier, size_t tailleMaxOctets,
                                      const string& prefixeSortie) {
            // Divise un fichier binaire en parties de taille maximale donnée
            vector<char> donnees = lireFichierBinaire(cheminFichier);
            int partie = 1;
            for (size_t i = 0; i < donnees.size(); i += tailleMaxOctets) {
                string nomPartie = prefixeSortie + "_partie" + to_string(partie) + ".bin";
                size_t taille = min(tailleMaxOctets, donnees.size() - i);
                vector<char> partieData(donnees.begin() + i, donnees.begin() + i + taille);
                ecrireFichierBinaire(nomPartie, partieData);
                partie++;
            }
        }

/* ═══════════════════════════════════════════════════════════════
   4. OPÉRATIONS SUR LES RÉPERTOIRES
   ═══════════════════════════════════════════════════════════════ */

    // ─── 4.1 Lister les fichiers d'un répertoire ───

        vector<string> listerFichiers(const string& cheminRepertoire) {
            vector<string> fichiers;
            for (const auto& entree : directory_iterator(cheminRepertoire)) {
                if (entree.is_regular_file()) {
                    fichiers.push_back(entree.path().string());
                }
            }
            return fichiers;
        }

    // ─── 4.2 Lister les fichiers récursivement ───

        vector<string> listerFichiersRecursivement(const string& cheminRepertoire) {
            vector<string> fichiers;
            for (const auto& entree : recursive_directory_iterator(cheminRepertoire)) {
                if (entree.is_regular_file()) {
                    fichiers.push_back(entree.path().string());
                }
            }
            return fichiers;
        }

    // ─── 4.3 Lister les sous-répertoires ───

        vector<string> listerSousRepertoires(const string& cheminRepertoire) {
            vector<string> repertoires;
            for (const auto& entree : directory_iterator(cheminRepertoire)) {
                if (entree.is_directory()) {
                    repertoires.push_back(entree.path().string());
                }
            }
            return repertoires;
        }

        vector<string> listerSousRepertoiresRecursivement(const string& cheminRepertoire) {
            vector<string> repertoires;
            for (const auto& entree : recursive_directory_iterator(cheminRepertoire)) {
                if (entree.is_directory()) {
                    repertoires.push_back(entree.path().string());
                }
            }
            return repertoires;
        }

    // ─── 4.4 Créer un répertoire ───

        void creerRepertoire(const string& cheminRepertoire) {
            if (!create_directory(cheminRepertoire)) {
                // Le répertoire existe peut-être déjà
                if (!is_directory(cheminRepertoire)) {
                    throw runtime_error("Impossible de créer le répertoire : " + cheminRepertoire);
                }
            }
        }

        void creerRepertoiresRecursivement(const string& cheminRepertoire) {
            create_directories(cheminRepertoire);
        }

    // ─── 4.5 Supprimer un répertoire ───

        void supprimerRepertoire(const string& cheminRepertoire) {
            if (!exists(cheminRepertoire)) {
                throw runtime_error("Le répertoire n'existe pas : " + cheminRepertoire);
            }
            remove_all(path(cheminRepertoire));
        }

    // ─── 4.6 Copier un répertoire ───

        void copierRepertoire(const string& source, const string& destination) {
            if (!exists(source)) {
                throw runtime_error("Le répertoire source n'existe pas : " + source);
            }
            copy(source, destination, copy_options::recursive | copy_options::overwrite_existing);
        }

/* ═══════════════════════════════════════════════════════════════
   5. INFORMATIONS SUR LES FICHIERS
   ═══════════════════════════════════════════════════════════════ */

    // ─── 5.1 Vérifier l'existence ───

        bool fichierExiste(const string& cheminFichier) {
            return exists(cheminFichier);
        }

    // ─── 5.2 Obtenir la taille ───

        uintmax_t obtenirTailleFichier(const string& cheminFichier) {
            // Retourne la taille en octets
            if (!exists(cheminFichier)) {
                throw runtime_error("Le fichier n'existe pas : " + cheminFichier);
            }
            return file_size(cheminFichier);
        }

        string obtenirTailleFichierFormatee(const string& cheminFichier) {
            // Retourne la taille formatée (Ko, Mo, Go)
            uintmax_t taille = obtenirTailleFichier(cheminFichier);
            stringstream flux;
            flux << fixed << setprecision(2);
            if (taille < 1024) {
                flux << taille << " octets";
            } else if (taille < 1024 * 1024) {
                flux << (double)taille / 1024 << " Ko";
            } else if (taille < 1024ULL * 1024 * 1024) {
                flux << (double)taille / (1024 * 1024) << " Mo";
            } else {
                flux << (double)taille / (1024ULL * 1024 * 1024) << " Go";
            }
            return flux.str();
        }

    // ─── 5.3 Obtenir l'extension ───

        string obtenirExtension(const string& cheminFichier) {
            return path(cheminFichier).extension().string();
        }

    // ─── 5.4 Obtenir le nom du fichier ───

        string obtenirNomFichier(const string& cheminFichier) {
            return path(cheminFichier).filename().string();
        }

        string obtenirNomSansExtension(const string& cheminFichier) {
            return path(cheminFichier).stem().string();
        }

    // ─── 5.5 Obtenir le répertoire parent ───

        string obtenirRepertoireParent(const string& cheminFichier) {
            return path(cheminFichier).parent_path().string();
        }

    // ─── 5.6 Obtenir le chemin absolu ───

        string obtenirCheminAbsolu(const string& cheminFichier) {
            return absolute(cheminFichier).string();
        }

        string obtenirCheminCanonique(const string& cheminFichier) {
            return canonical(cheminFichier).string();
        }

    // ─── 5.7 Obtenir la date de dernière modification ───

        string obtenirDateModification(const string& cheminFichier) {
            if (!exists(cheminFichier)) {
                throw runtime_error("Le fichier n'existe pas : " + cheminFichier);
            }
            auto tempsModif = last_write_time(cheminFichier);
            auto tempsSysteme = time_point_cast<system_clock::duration>(
                tempsModif - file_time_type::clock::now() + system_clock::now()
            );
            time_t temps = system_clock::to_time_t(tempsSysteme);
            stringstream flux;
            flux << put_time(localtime(&temps), "%Y-%m-%d %H:%M:%S");
            return flux.str();
        }

    // ─── 5.8 Vérifier si c'est un fichier / répertoire ───

        bool estFichier(const string& chemin) {
            return is_regular_file(chemin);
        }

        bool estRepertoire(const string& chemin) {
            return is_directory(chemin);
        }

        bool estLienSymbolique(const string& chemin) {
            return is_symlink(chemin);
        }

        bool estFichierVide(const string& cheminFichier) {
            return is_regular_file(cheminFichier) && file_size(cheminFichier) == 0;
        }

    // ─── 5.9 Obtenir les permissions ───

        string obtenirPermissions(const string& cheminFichier) {
            if (!exists(cheminFichier)) {
                throw runtime_error("Le fichier n'existe pas : " + cheminFichier);
            }
            auto perms = status(cheminFichier).permissions();
            string resultat;
            resultat += (perms & perms::owner_read)   != perms::none ? "r" : "-";
            resultat += (perms & perms::owner_write)  != perms::none ? "w" : "-";
            resultat += (perms & perms::owner_exec)   != perms::none ? "x" : "-";
            resultat += (perms & perms::group_read)   != perms::none ? "r" : "-";
            resultat += (perms & perms::group_write)  != perms::none ? "w" : "-";
            resultat += (perms & perms::group_exec)   != perms::none ? "x" : "-";
            resultat += (perms & perms::others_read)  != perms::none ? "r" : "-";
            resultat += (perms & perms::others_write) != perms::none ? "w" : "-";
            resultat += (perms & perms::others_exec)  != perms::none ? "x" : "-";
            return resultat;
        }

/* ═══════════════════════════════════════════════════════════════
   6. RECHERCHE ET REMPLACEMENT
   ═══════════════════════════════════════════════════════════════ */

    // ─── 6.1 Rechercher dans un fichier ───

        vector<int> rechercherDansFichier(const string& cheminFichier, const string& texte) {
            // Retourne les numéros de lignes (1-indexés) contenant le texte
            vector<string> lignes = lireLignes(cheminFichier);
            vector<int> resultats;
            for (size_t i = 0; i < lignes.size(); i++) {
                if (lignes[i].find(texte) != string::npos) {
                    resultats.push_back(i + 1);
                }
            }
            return resultats;
        }

    // ─── 6.2 Rechercher avec regex ───

        vector<pair<int, string>> rechercherAvecRegex(const string& cheminFichier, const string& motif) {
            // Retourne les paires (numéro de ligne, contenu) correspondant au motif
            vector<string> lignes = lireLignes(cheminFichier);
            vector<pair<int, string>> resultats;
            regex expression(motif);
            for (size_t i = 0; i < lignes.size(); i++) {
                if (regex_search(lignes[i], expression)) {
                    resultats.push_back({i + 1, lignes[i]});
                }
            }
            return resultats;
        }

    // ─── 6.3 Remplacer dans un fichier ───

        int remplacerDansFichier(const string& cheminFichier, const string& ancien, const string& nouveau) {
            // Remplace toutes les occurrences et retourne le nombre de remplacements
            string contenu = lireFichier(cheminFichier);
            int compteur = 0;
            size_t pos = 0;
            while ((pos = contenu.find(ancien, pos)) != string::npos) {
                contenu.replace(pos, ancien.length(), nouveau);
                pos += nouveau.length();
                compteur++;
            }
            ecrireFichier(cheminFichier, contenu);
            return compteur;
        }

        int remplacerAvecRegex(const string& cheminFichier, const string& motif,
                                const string& remplacement) {
            string contenu = lireFichier(cheminFichier);
            regex expression(motif);
            string nouveauContenu = regex_replace(contenu, expression, remplacement);
            int compteur = 0;
            // Compter les remplacements en comparant les longueurs (approximation)
            auto it = sregex_iterator(contenu.begin(), contenu.end(), expression);
            auto fin = sregex_iterator();
            compteur = distance(it, fin);
            ecrireFichier(cheminFichier, nouveauContenu);
            return compteur;
        }

    // ─── 6.4 Rechercher des fichiers par nom ───

        vector<string> rechercherFichiersParNom(const string& cheminRepertoire,
                                                 const string& nomRecherche, bool recursif = true) {
            vector<string> resultats;
            if (recursif) {
                for (const auto& entree : recursive_directory_iterator(cheminRepertoire)) {
                    if (entree.is_regular_file() &&
                        entree.path().filename().string().find(nomRecherche) != string::npos) {
                        resultats.push_back(entree.path().string());
                    }
                }
            } else {
                for (const auto& entree : directory_iterator(cheminRepertoire)) {
                    if (entree.is_regular_file() &&
                        entree.path().filename().string().find(nomRecherche) != string::npos) {
                        resultats.push_back(entree.path().string());
                    }
                }
            }
            return resultats;
        }

    // ─── 6.5 Rechercher des fichiers par extension ───

        vector<string> rechercherFichiersParExtension(const string& cheminRepertoire,
                                                       const string& extension, bool recursif = true) {
            vector<string> resultats;
            if (recursif) {
                for (const auto& entree : recursive_directory_iterator(cheminRepertoire)) {
                    if (entree.is_regular_file() && entree.path().extension().string() == extension) {
                        resultats.push_back(entree.path().string());
                    }
                }
            } else {
                for (const auto& entree : directory_iterator(cheminRepertoire)) {
                    if (entree.is_regular_file() && entree.path().extension().string() == extension) {
                        resultats.push_back(entree.path().string());
                    }
                }
            }
            return resultats;
        }

    // ─── 6.6 Rechercher des fichiers par contenu ───

        vector<string> rechercherFichiersParContenu(const string& cheminRepertoire,
                                                     const string& texte, bool recursif = true) {
            vector<string> resultats;
            vector<string> fichiers = recursif
                ? listerFichiersRecursivement(cheminRepertoire)
                : listerFichiers(cheminRepertoire);
            for (const auto& fichier : fichiers) {
                try {
                    string contenu = lireFichier(fichier);
                    if (contenu.find(texte) != string::npos) {
                        resultats.push_back(fichier);
                    }
                } catch (...) {
                    // Ignorer les fichiers illisibles (binaires, etc.)
                }
            }
            return resultats;
        }

/* ═══════════════════════════════════════════════════════════════
   7. STATISTIQUES DE FICHIERS
   ═══════════════════════════════════════════════════════════════ */

    // ─── 7.1 Compter les lignes ───

        int compterLignes(const string& cheminFichier) {
            ifstream fichier(cheminFichier);
            if (!fichier.is_open()) {
                throw runtime_error("Impossible d'ouvrir le fichier : " + cheminFichier);
            }
            int compteur = 0;
            string ligne;
            while (getline(fichier, ligne)) {
                compteur++;
            }
            return compteur;
        }

        int compterLignesNonVides(const string& cheminFichier) {
            vector<string> lignes = lireLignes(cheminFichier);
            int compteur = 0;
            for (const auto& ligne : lignes) {
                // Vérifier si la ligne contient au moins un caractère non-espace
                bool vide = true;
                for (char c : ligne) {
                    if (!isspace(c)) { vide = false; break; }
                }
                if (!vide) compteur++;
            }
            return compteur;
        }

    // ─── 7.2 Compter les mots ───

        int compterMots(const string& cheminFichier) {
            ifstream fichier(cheminFichier);
            if (!fichier.is_open()) {
                throw runtime_error("Impossible d'ouvrir le fichier : " + cheminFichier);
            }
            int compteur = 0;
            string mot;
            while (fichier >> mot) {
                compteur++;
            }
            return compteur;
        }

    // ─── 7.3 Compter les caractères ───

        int compterCaracteres(const string& cheminFichier, bool inclureEspaces = true) {
            string contenu = lireFichier(cheminFichier);
            if (inclureEspaces) {
                return contenu.length();
            }
            int compteur = 0;
            for (char c : contenu) {
                if (!isspace(c)) compteur++;
            }
            return compteur;
        }

    // ─── 7.4 Compter les occurrences d'un mot ───

        int compterOccurrencesDansFichier(const string& cheminFichier, const string& mot) {
            string contenu = lireFichier(cheminFichier);
            int compteur = 0;
            size_t pos = 0;
            while ((pos = contenu.find(mot, pos)) != string::npos) {
                compteur++;
                pos += mot.length();
            }
            return compteur;
        }

    // ─── 7.5 Fréquence des mots ───

        map<string, int> frequenceMots(const string& cheminFichier) {
            ifstream fichier(cheminFichier);
            if (!fichier.is_open()) {
                throw runtime_error("Impossible d'ouvrir le fichier : " + cheminFichier);
            }
            map<string, int> frequence;
            string mot;
            while (fichier >> mot) {
                // Convertir en minuscules et supprimer la ponctuation
                string motNettoye;
                for (char c : mot) {
                    if (isalnum(c)) {
                        motNettoye += tolower(c);
                    }
                }
                if (!motNettoye.empty()) {
                    frequence[motNettoye]++;
                }
            }
            return frequence;
        }

/* ═══════════════════════════════════════════════════════════════
   8. MANIPULATION DE CHEMINS
   ═══════════════════════════════════════════════════════════════ */

    // ─── 8.1 Joindre des chemins ───

        string joindreChemin(const string& chemin1, const string& chemin2) {
            return (path(chemin1) / path(chemin2)).string();
        }

        string joindreChemin(const string& chemin1, const string& chemin2, const string& chemin3) {
            return (path(chemin1) / path(chemin2) / path(chemin3)).string();
        }

    // ─── 8.2 Normaliser un chemin ───

        string normaliserChemin(const string& chemin) {
            return path(chemin).lexically_normal().string();
        }

    // ─── 8.3 Chemin relatif ───

        string cheminRelatif(const string& chemin, const string& base) {
            return path(chemin).lexically_relative(base).string();
        }

    // ─── 8.4 Changer l'extension ───

        string changerExtension(const string& cheminFichier, const string& nouvelleExtension) {
            path p(cheminFichier);
            return p.replace_extension(nouvelleExtension).string();
        }

    // ─── 8.5 Obtenir la racine du chemin ───

        string obtenirRacineChemin(const string& chemin) {
            return path(chemin).root_path().string();
        }

/* ═══════════════════════════════════════════════════════════════
   9. UTILITAIRES AVANCÉS
   ═══════════════════════════════════════════════════════════════ */

    // ─── 9.1 Créer un fichier temporaire ───

        string creerFichierTemporaire(const string& prefixe = "temp", const string& extension = ".tmp") {
            string nomFichier = prefixe + "_" +
                to_string(system_clock::now().time_since_epoch().count()) + extension;
            string cheminComplet = (temp_directory_path() / nomFichier).string();
            ofstream fichier(cheminComplet);
            if (!fichier.is_open()) {
                throw runtime_error("Impossible de créer le fichier temporaire : " + cheminComplet);
            }
            fichier.close();
            return cheminComplet;
        }

    // ─── 9.2 Verrouiller un fichier (mutex) ───

        mutex mutexFichier;

        string lireFichierAvecVerrou(const string& cheminFichier) {
            lock_guard<mutex> verrou(mutexFichier);
            return lireFichier(cheminFichier);
        }

        void ecrireFichierAvecVerrou(const string& cheminFichier, const string& contenu) {
            lock_guard<mutex> verrou(mutexFichier);
            ecrireFichier(cheminFichier, contenu);
        }

    // ─── 9.3 Surveiller un fichier pour modifications ───

        void surveillerFichier(const string& cheminFichier,
                                function<void(const string&)> callback,
                                int intervalleMs = 1000, int dureeMaxMs = 60000) {
            // Surveille un fichier et appelle le callback si modifié
            if (!exists(cheminFichier)) {
                throw runtime_error("Le fichier n'existe pas : " + cheminFichier);
            }
            auto dernierTemps = last_write_time(cheminFichier);
            int tempsEcoule = 0;
            while (tempsEcoule < dureeMaxMs) {
                sleep_for(milliseconds(intervalleMs));
                tempsEcoule += intervalleMs;
                auto tempsActuel = last_write_time(cheminFichier);
                if (tempsActuel != dernierTemps) {
                    dernierTemps = tempsActuel;
                    callback(cheminFichier);
                }
            }
        }

    // ─── 9.4 Calculer un checksum simple ───

        unsigned long calculerChecksum(const string& cheminFichier) {
            // Checksum simple (somme des octets modulo 2^32)
            vector<char> donnees = lireFichierBinaire(cheminFichier);
            unsigned long checksum = 0;
            for (unsigned char octet : donnees) {
                checksum = (checksum + octet) % 4294967296UL;
            }
            return checksum;
        }

        string calculerChecksumHex(const string& cheminFichier) {
            unsigned long cs = calculerChecksum(cheminFichier);
            stringstream flux;
            flux << hex << uppercase << setw(8) << setfill('0') << cs;
            return flux.str();
        }

    // ─── 9.5 Sauvegarder avec horodatage ───

        string sauvegarderAvecHorodatage(const string& cheminFichier) {
            // Crée une copie du fichier avec un horodatage dans le nom
            if (!exists(cheminFichier)) {
                throw runtime_error("Le fichier n'existe pas : " + cheminFichier);
            }
            auto maintenant = system_clock::now();
            time_t temps = system_clock::to_time_t(maintenant);
            stringstream flux;
            flux << put_time(localtime(&temps), "%Y%m%d_%H%M%S");

            path p(cheminFichier);
            string nomSauvegarde = p.stem().string() + "_" + flux.str() + p.extension().string();
            string cheminSauvegarde = (p.parent_path() / nomSauvegarde).string();
            copierFichier(cheminFichier, cheminSauvegarde);
            return cheminSauvegarde;
        }

    // ─── 9.6 Lire un fichier de configuration (clé=valeur) ───

        map<string, string> lireConfiguration(const string& cheminFichier, char delimiteur = '=') {
            // Lit un fichier de configuration au format clé=valeur
            // Ignore les lignes vides et les commentaires (commençant par # ou ;)
            map<string, string> config;
            vector<string> lignes = lireLignes(cheminFichier);
            for (const auto& ligne : lignes) {
                // Ignorer les lignes vides
                if (ligne.empty()) continue;
                // Ignorer les commentaires
                char premier = ' ';
                for (char c : ligne) {
                    if (!isspace(c)) { premier = c; break; }
                }
                if (premier == '#' || premier == ';') continue;

                size_t pos = ligne.find(delimiteur);
                if (pos != string::npos) {
                    string cle = ligne.substr(0, pos);
                    string valeur = ligne.substr(pos + 1);
                    // Supprimer les espaces autour de la clé et de la valeur
                    while (!cle.empty() && isspace(cle.back())) cle.pop_back();
                    while (!cle.empty() && isspace(cle.front())) cle.erase(cle.begin());
                    while (!valeur.empty() && isspace(valeur.back())) valeur.pop_back();
                    while (!valeur.empty() && isspace(valeur.front())) valeur.erase(valeur.begin());
                    config[cle] = valeur;
                }
            }
            return config;
        }

    // ─── 9.7 Écrire un fichier de configuration ───

        void ecrireConfiguration(const string& cheminFichier, const map<string, string>& config,
                                  char delimiteur = '=') {
            ofstream fichier(cheminFichier);
            if (!fichier.is_open()) {
                throw runtime_error("Impossible d'ouvrir le fichier de configuration : " + cheminFichier);
            }
            for (const auto& paire : config) {
                fichier << paire.first << " " << delimiteur << " " << paire.second << "\n";
            }
        }

/* ═══════════════════════════════════════════════════════════════
   PROGRAMME PRINCIPAL (exemples d'utilisation)
   ═══════════════════════════════════════════════════════════════ */

int main() {
    try {
        // ── Écriture et lecture de base ──
        string cheminFichier = "exemple.txt";
        string contenu = "Bonjour, le monde!\nDeuxième ligne.\nTroisième ligne.";

        ecrireFichier(cheminFichier, contenu);
        cout << "Contenu du fichier :" << endl;
        cout << lireFichier(cheminFichier) << endl;
        cout << endl;

        // ── Lecture par lignes ──
        vector<string> lignes = lireLignes(cheminFichier);
        cout << "Nombre de lignes : " << lignes.size() << endl;
        for (size_t i = 0; i < lignes.size(); i++) {
            cout << "  Ligne " << (i + 1) << " : " << lignes[i] << endl;
        }
        cout << endl;

        // ── Ajout au fichier ──
        ajouterAuFichier(cheminFichier, "\nQuatrième ligne ajoutée.");
        cout << "Après ajout :" << endl;
        cout << lireFichier(cheminFichier) << endl;
        cout << endl;

        // ── Statistiques ──
        cout << "Lignes : " << compterLignes(cheminFichier) << endl;
        cout << "Mots   : " << compterMots(cheminFichier) << endl;
        cout << "Chars  : " << compterCaracteres(cheminFichier) << endl;
        cout << "Taille : " << obtenirTailleFichierFormatee(cheminFichier) << endl;
        cout << endl;

        // ── Recherche ──
        vector<int> lignesTrouvees = rechercherDansFichier(cheminFichier, "ligne");
        cout << "Lignes contenant 'ligne' : ";
        for (int num : lignesTrouvees) {
            cout << num << " ";
        }
        cout << endl;

        // ── Remplacement ──
        int nbRemplacements = remplacerDansFichier(cheminFichier, "ligne", "rangée");
        cout << "Remplacements effectués : " << nbRemplacements << endl;
        cout << "Après remplacement :" << endl;
        cout << lireFichier(cheminFichier) << endl;
        cout << endl;

        // ── Informations sur le fichier ──
        cout << "Extension    : " << obtenirExtension(cheminFichier) << endl;
        cout << "Nom          : " << obtenirNomFichier(cheminFichier) << endl;
        cout << "Nom (sans ext): " << obtenirNomSansExtension(cheminFichier) << endl;
        cout << "Chemin absolu: " << obtenirCheminAbsolu(cheminFichier) << endl;
        cout << "Existe       : " << (fichierExiste(cheminFichier) ? "Oui" : "Non") << endl;
        cout << endl;

        // ── Lister les fichiers du répertoire courant ──
        cout << "Fichiers dans le répertoire courant :" << endl;
        vector<string> fichiers = listerFichiers(".");
        for (const auto& f : fichiers) {
            cout << " - " << f << endl;
        }
        cout << endl;

        // ── Copie et suppression ──
        string cheminCopie = "exemple_copie.txt";
        copierFichier(cheminFichier, cheminCopie);
        cout << "Copie créée : " << cheminCopie << endl;
        cout << "Fichiers identiques : " << (comparerFichiers(cheminFichier, cheminCopie) ? "Oui" : "Non") << endl;

        // Nettoyage
        supprimerFichier(cheminFichier);
        supprimerFichier(cheminCopie);
        cout << "Fichiers supprimés." << endl;

    } catch (const exception& e) {
        cerr << "Erreur : " << e.what() << endl;
    }

    return 0;
}