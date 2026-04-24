/* Fichier   : exemple-employes.cpp
	Auteure  : Charlie Bouchard    
	Cours    : IFT1166 - Programmation orientée objet en C++    
	Trimestre: Hiver 2026
	But      : Exemple de programme simple de gestion d'employés en C++
        - Employés d'une entreprise fictive
        - Affichage des informations sur les employés
        - Statistiques sur les employés (âge moyen, salaire total, etc.)
        - Recherches (employés par département, par poste, etc.)
        - Ajout et suppression d'employés
        - Mise à jour des informations d'employés
        - Tri et filtrage d'employés
        - Export des données d'employés (CSV, JSON)
        - Importation de données d'employés depuis un fichier
	Dernière mise à jour : 2026-02-27
*/

#include <iomanip>
#include <fstream>
#include <sstream>
#include "exemple-employes-data.h"

/* ═══════════════════════════════════════════════════════════════
   FONCTIONS UTILITAIRES
   ═══════════════════════════════════════════════════════════════ */

// Afficher un séparateur
void separateur(const string& titre) {
    cout << "\n══════════════════════════════════════════════════════" << endl;
    cout << "  " << titre << endl;
    cout << "══════════════════════════════════════════════════════" << endl;
}

/* ═══════════════════════════════════════════════════════════════
   FONCTIONS DE RECHERCHE
   ═══════════════════════════════════════════════════════════════ */

// Trouver un employé par ID
EmployeEntreprise* trouverEmploye(int id) {
    for (auto& e : employes) {
        if (e.idEmploye == id) return &e;
    }
    return nullptr;
}

// Trouver un département par ID
Departement* trouverDepartement(int id) {
    for (auto& d : departements) {
        if (d.idDepartement == id) return &d;
    }
    return nullptr;
}

// Trouver un projet par ID
Projet* trouverProjet(int id) {
    for (auto& p : projets) {
        if (p.idProjet == id) return &p;
    }
    return nullptr;
}

// Employés d'un département
vector<EmployeEntreprise*> employesParDepartement(int idDep) {
    vector<EmployeEntreprise*> resultats;
    for (auto& e : employes) {
        if (e.idDepartement == idDep && e.actif) resultats.push_back(&e);
    }
    return resultats;
}

// Employés par type de contrat
vector<EmployeEntreprise*> employesParContrat(const string& type) {
    vector<EmployeEntreprise*> resultats;
    for (auto& e : employes) {
        if (e.typeContrat == type && e.actif) resultats.push_back(&e);
    }
    return resultats;
}

// Recherche par nom ou prénom (partiel)
vector<EmployeEntreprise*> rechercherEmploye(const string& terme) {
    vector<EmployeEntreprise*> resultats;
    for (auto& e : employes) {
        if (e.nom.find(terme) != string::npos || e.prenom.find(terme) != string::npos) {
            resultats.push_back(&e);
        }
    }
    return resultats;
}

// Projets d'un employé (via affectations)
vector<Projet*> projetsEmploye(int idEmploye) {
    vector<Projet*> resultats;
    for (auto& a : affectations) {
        if (a.idEmploye == idEmploye && a.dateFin.empty()) {
            Projet* p = trouverProjet(a.idProjet);
            if (p) resultats.push_back(p);
        }
    }
    return resultats;
}

// Évaluations d'un employé
vector<Evaluation*> evaluationsEmploye(int idEmploye) {
    vector<Evaluation*> resultats;
    for (auto& ev : evaluations) {
        if (ev.idEmploye == idEmploye) resultats.push_back(&ev);
    }
    return resultats;
}

// Congés d'un employé
vector<Conge*> congesEmploye(int idEmploye) {
    vector<Conge*> resultats;
    for (auto& c : conges) {
        if (c.idEmploye == idEmploye) resultats.push_back(&c);
    }
    return resultats;
}

/* ═══════════════════════════════════════════════════════════════
   FONCTIONS STATISTIQUES
   ═══════════════════════════════════════════════════════════════ */

// Âge moyen des employés actifs
double ageMoyen() {
    double somme = 0;
    int n = 0;
    for (const auto& e : employes) {
        if (e.actif) { somme += e.age; n++; }
    }
    return n > 0 ? somme / n : 0;
}

// Salaire moyen des employés actifs
double salaireMoyen() {
    double somme = 0;
    int n = 0;
    for (const auto& e : employes) {
        if (e.actif && e.salaireAnnuel > 0) { somme += e.salaireAnnuel; n++; }
    }
    return n > 0 ? somme / n : 0;
}

// Masse salariale totale
double masseSalariale() {
    double total = 0;
    for (const auto& e : employes) {
        if (e.actif) total += e.salaireAnnuel;
    }
    return total;
}

// Performance moyenne
double performanceMoyenne() {
    double somme = 0;
    int n = 0;
    for (const auto& e : employes) {
        if (e.actif && e.evaluationPerf > 0) { somme += e.evaluationPerf; n++; }
    }
    return n > 0 ? somme / n : 0;
}

// Expérience moyenne
double experienceMoyenne() {
    double somme = 0;
    int n = 0;
    for (const auto& e : employes) {
        if (e.actif) { somme += e.anneesExperience; n++; }
    }
    return n > 0 ? somme / n : 0;
}

// Répartition par sexe
void repartitionSexe(int& nbH, int& nbF, int& nbAutre) {
    nbH = nbF = nbAutre = 0;
    for (const auto& e : employes) {
        if (!e.actif) continue;
        if (e.sexe == "M") nbH++;
        else if (e.sexe == "F") nbF++;
        else nbAutre++;
    }
}

// Top N employés par performance
vector<EmployeEntreprise*> topPerformance(int n) {
    vector<EmployeEntreprise*> actifs;
    for (auto& e : employes) {
        if (e.actif) actifs.push_back(&e);
    }
    sort(actifs.begin(), actifs.end(), [](const EmployeEntreprise* a, const EmployeEntreprise* b) {
        return a->evaluationPerf > b->evaluationPerf;
    });
    if ((int)actifs.size() > n) actifs.resize(n);
    return actifs;
}

// Top N employés par salaire
vector<EmployeEntreprise*> topSalaires(int n) {
    vector<EmployeEntreprise*> actifs;
    for (auto& e : employes) {
        if (e.actif) actifs.push_back(&e);
    }
    sort(actifs.begin(), actifs.end(), [](const EmployeEntreprise* a, const EmployeEntreprise* b) {
        return a->salaireAnnuel > b->salaireAnnuel;
    });
    if ((int)actifs.size() > n) actifs.resize(n);
    return actifs;
}

/* ═══════════════════════════════════════════════════════════════
   FONCTIONS D'AJOUT ET SUPPRESSION
   ═══════════════════════════════════════════════════════════════ */

// Ajouter un employé
void ajouterEmploye(const EmployeEntreprise& emp) {
    employes.push_back(emp);
    // Mettre à jour le compteur du département
    Departement* dep = trouverDepartement(emp.idDepartement);
    if (dep) dep->nbEmployes++;
    cout << "  ✓ Employé ajouté : " << emp.prenom << " " << emp.nom << endl;
}

// Désactiver un employé (suppression logique)
bool desactiverEmploye(int id) {
    EmployeEntreprise* emp = trouverEmploye(id);
    if (emp && emp->actif) {
        emp->actif = false;
        emp->salaireAnnuel = 0;
        emp->heuresParSemaine = 0;
        Departement* dep = trouverDepartement(emp->idDepartement);
        if (dep) dep->nbEmployes--;
        cout << "  ✓ Employé désactivé : " << emp->prenom << " " << emp->nom << endl;
        return true;
    }
    cout << "  ✗ Employé introuvable ou déjà inactif." << endl;
    return false;
}

/* ═══════════════════════════════════════════════════════════════
   FONCTIONS DE MISE À JOUR
   ═══════════════════════════════════════════════════════════════ */

// Augmenter le salaire d'un employé (pourcentage)
bool augmenterSalaire(int id, double pourcentage) {
    EmployeEntreprise* emp = trouverEmploye(id);
    if (emp && emp->actif) {
        double ancien = emp->salaireAnnuel;
        emp->salaireAnnuel *= (1 + pourcentage / 100.0);
        emp->tauxHoraire = emp->salaireAnnuel / (emp->heuresParSemaine * 52.0);
        cout << "  ✓ Salaire de " << emp->prenom << " " << emp->nom
             << " : " << ancien << "$ → " << emp->salaireAnnuel << "$ (+"
             << pourcentage << "%)" << endl;
        return true;
    }
    return false;
}

// Changer de département
bool changerDepartement(int idEmploye, int nouveauDep) {
    EmployeEntreprise* emp = trouverEmploye(idEmploye);
    if (emp && emp->actif) {
        Departement* ancien = trouverDepartement(emp->idDepartement);
        Departement* nouveau = trouverDepartement(nouveauDep);
        if (ancien) ancien->nbEmployes--;
        if (nouveau) nouveau->nbEmployes++;
        emp->idDepartement = nouveauDep;
        cout << "  ✓ " << emp->prenom << " " << emp->nom
             << " transféré au département #" << nouveauDep << endl;
        return true;
    }
    return false;
}

/* ═══════════════════════════════════════════════════════════════
   FONCTIONS DE TRI ET FILTRAGE
   ═══════════════════════════════════════════════════════════════ */

// Trier par nom
vector<EmployeEntreprise*> trierParNom() {
    vector<EmployeEntreprise*> liste;
    for (auto& e : employes) if (e.actif) liste.push_back(&e);
    sort(liste.begin(), liste.end(), [](const EmployeEntreprise* a, const EmployeEntreprise* b) {
        return a->nom < b->nom || (a->nom == b->nom && a->prenom < b->prenom);
    });
    return liste;
}

// Trier par salaire (décroissant)
vector<EmployeEntreprise*> trierParSalaire() {
    vector<EmployeEntreprise*> liste;
    for (auto& e : employes) if (e.actif) liste.push_back(&e);
    sort(liste.begin(), liste.end(), [](const EmployeEntreprise* a, const EmployeEntreprise* b) {
        return a->salaireAnnuel > b->salaireAnnuel;
    });
    return liste;
}

// Trier par âge
vector<EmployeEntreprise*> trierParAge() {
    vector<EmployeEntreprise*> liste;
    for (auto& e : employes) if (e.actif) liste.push_back(&e);
    sort(liste.begin(), liste.end(), [](const EmployeEntreprise* a, const EmployeEntreprise* b) {
        return a->age < b->age;
    });
    return liste;
}

// Filtrer par tranche de salaire
vector<EmployeEntreprise*> filtrerParSalaire(double min, double max) {
    vector<EmployeEntreprise*> resultats;
    for (auto& e : employes) {
        if (e.actif && e.salaireAnnuel >= min && e.salaireAnnuel <= max) {
            resultats.push_back(&e);
        }
    }
    return resultats;
}

// Filtrer par niveau d'études
vector<EmployeEntreprise*> filtrerParEtudes(const string& niveau) {
    vector<EmployeEntreprise*> resultats;
    for (auto& e : employes) {
        if (e.actif && e.niveauEtudes == niveau) resultats.push_back(&e);
    }
    return resultats;
}

/* ═══════════════════════════════════════════════════════════════
   FONCTIONS D'EXPORTATION
   ═══════════════════════════════════════════════════════════════ */

// Exporter en CSV
void exporterCSV(const string& nomFichier) {
    ofstream fichier(nomFichier);
    if (!fichier.is_open()) {
        cout << "  ✗ Impossible d'ouvrir " << nomFichier << endl;
        return;
    }
    fichier << "ID,Nom,Prenom,Age,Sexe,Poste,Departement,Contrat,Salaire,Performance,Actif" << endl;
    for (const auto& e : employes) {
        fichier << e.idEmploye << ","
                << e.nom << ","
                << e.prenom << ","
                << e.age << ","
                << e.sexe << ","
                << e.poste << ","
                << e.idDepartement << ","
                << e.typeContrat << ","
                << e.salaireAnnuel << ","
                << e.evaluationPerf << ","
                << (e.actif ? "Oui" : "Non") << endl;
    }
    fichier.close();
    cout << "  ✓ Export CSV : " << nomFichier << " (" << employes.size() << " employés)" << endl;
}

// Exporter en JSON
void exporterJSON(const string& nomFichier) {
    ofstream fichier(nomFichier);
    if (!fichier.is_open()) {
        cout << "  ✗ Impossible d'ouvrir " << nomFichier << endl;
        return;
    }
    fichier << "[" << endl;
    for (int i = 0; i < (int)employes.size(); i++) {
        const auto& e = employes[i];
        fichier << "  {" << endl;
        fichier << "    \"id\": " << e.idEmploye << "," << endl;
        fichier << "    \"nom\": \"" << e.nom << "\"," << endl;
        fichier << "    \"prenom\": \"" << e.prenom << "\"," << endl;
        fichier << "    \"age\": " << e.age << "," << endl;
        fichier << "    \"sexe\": \"" << e.sexe << "\"," << endl;
        fichier << "    \"poste\": \"" << e.poste << "\"," << endl;
        fichier << "    \"departement\": " << e.idDepartement << "," << endl;
        fichier << "    \"contrat\": \"" << e.typeContrat << "\"," << endl;
        fichier << "    \"salaire\": " << e.salaireAnnuel << "," << endl;
        fichier << "    \"performance\": " << e.evaluationPerf << "," << endl;
        fichier << "    \"actif\": " << (e.actif ? "true" : "false") << endl;
        fichier << "  }" << (i < (int)employes.size() - 1 ? "," : "") << endl;
    }
    fichier << "]" << endl;
    fichier.close();
    cout << "  ✓ Export JSON : " << nomFichier << " (" << employes.size() << " employés)" << endl;
}

// Importer depuis un CSV
int importerCSV(const string& nomFichier) {
    ifstream fichier(nomFichier);
    if (!fichier.is_open()) {
        cout << "  ✗ Impossible d'ouvrir " << nomFichier << endl;
        return 0;
    }
    string ligne;
    getline(fichier, ligne); // sauter l'en-tête
    int count = 0;
    while (getline(fichier, ligne)) {
        // Lecture basique ligne CSV (simplifié)
        cout << "  → Ligne lue : " << ligne << endl;
        count++;
    }
    fichier.close();
    cout << "  ✓ Import CSV : " << count << " lignes lues depuis " << nomFichier << endl;
    return count;
}

/* ═══════════════════════════════════════════════════════════════
   PROGRAMME PRINCIPAL
   ═══════════════════════════════════════════════════════════════ */

int main() {
    cout << fixed << setprecision(2);

    cout << "\n╔══════════════════════════════════════════════════════╗" << endl;
    cout << "║   SYSTÈME DE GESTION — TechNova Solutions Inc.      ║" << endl;
    cout << "╚══════════════════════════════════════════════════════╝" << endl;

    // ── 1. Départements ──
    separateur("DÉPARTEMENTS (" + to_string(departements.size()) + ")");
    for (const auto& d : departements) {
        d.afficher();
    }

    // ── 2. Liste des employés ──
    separateur("EMPLOYÉS ACTIFS (" + to_string(employes.size()) + " au total)");
    int nbActifs = 0;
    for (const auto& e : employes) {
        if (e.actif) { e.afficher(); nbActifs++; }
    }
    cout << "\n  Employés actifs : " << nbActifs << " / " << employes.size() << endl;

    // ── 3. Fiche détaillée d'un employé ──
    separateur("FICHE DÉTAILLÉE — Sophie Tremblay (#6)");
    EmployeEntreprise* sophie = trouverEmploye(6);
    if (sophie) sophie->afficherDetaille();

    // ── 4. Employés par département ──
    separateur("EMPLOYÉS PAR DÉPARTEMENT");
    for (const auto& dep : departements) {
        cout << "\n  ── " << dep.nom << " ──" << endl;
        auto empDep = employesParDepartement(dep.idDepartement);
        for (auto* e : empDep) {
            cout << "    - " << e->prenom << " " << e->nom
                 << " (" << e->poste << ") — " << e->salaireAnnuel << "$/an" << endl;
        }
    }

    // ── 5. Projets ──
    separateur("PROJETS (" + to_string(projets.size()) + ")");
    for (const auto& p : projets) {
        p.afficher();
    }

    // ── 6. Affectations par projet ──
    separateur("AFFECTATIONS AUX PROJETS EN COURS");
    for (const auto& p : projets) {
        if (p.statut == "En cours") {
            cout << "\n  ── " << p.nom << " ──" << endl;
            for (const auto& a : affectations) {
                if (a.idProjet == p.idProjet && a.dateFin.empty()) {
                    EmployeEntreprise* emp = trouverEmploye(a.idEmploye);
                    cout << "    - " << (emp ? emp->prenom + " " + emp->nom : "?")
                         << " | " << a.role
                         << " | " << a.heuresParSemaine << "h/sem" << endl;
                }
            }
        }
    }

    // ── 7. Évaluations ──
    separateur("ÉVALUATIONS DE PERFORMANCE 2025 (" + to_string(evaluations.size()) + ")");
    for (const auto& ev : evaluations) {
        ev.afficher();
    }

    // ── 8. Congés ──
    separateur("CONGÉS ET ABSENCES (" + to_string(conges.size()) + ")");
    for (const auto& c : conges) {
        c.afficher();
    }

    // ── 9. Formations ──
    separateur("FORMATIONS OFFERTES (" + to_string(formations.size()) + ")");
    for (const auto& f : formations) {
        f.afficher();
    }

    // ── 10. Statistiques ──
    separateur("STATISTIQUES GLOBALES");
    int nbH, nbF, nbAutre;
    repartitionSexe(nbH, nbF, nbAutre);
    cout << "  Employés actifs      : " << nbActifs << endl;
    cout << "  Répartition H/F      : " << nbH << " hommes / " << nbF << " femmes" << endl;
    cout << "  Âge moyen            : " << ageMoyen() << " ans" << endl;
    cout << "  Expérience moyenne   : " << experienceMoyenne() << " ans" << endl;
    cout << "  Salaire moyen        : " << salaireMoyen() << " $/an" << endl;
    cout << "  Masse salariale      : " << masseSalariale() << " $/an" << endl;
    cout << "  Performance moyenne  : " << performanceMoyenne() << " /10" << endl;

    // ── 11. Top 10 performance ──
    separateur("TOP 10 — PERFORMANCE");
    auto top10Perf = topPerformance(10);
    for (int i = 0; i < (int)top10Perf.size(); i++) {
        cout << "    " << (i + 1) << ". " << top10Perf[i]->prenom << " " << top10Perf[i]->nom
             << " — " << top10Perf[i]->evaluationPerf << "/10"
             << " (" << top10Perf[i]->poste << ")" << endl;
    }

    // ── 12. Top 10 salaires ──
    separateur("TOP 10 — SALAIRES");
    auto top10Sal = topSalaires(10);
    for (int i = 0; i < (int)top10Sal.size(); i++) {
        cout << "    " << (i + 1) << ". " << top10Sal[i]->prenom << " " << top10Sal[i]->nom
             << " — " << top10Sal[i]->salaireAnnuel << "$/an"
             << " (" << top10Sal[i]->poste << ")" << endl;
    }

    // ── 13. Recherches ──
    separateur("RECHERCHES");

    // Recherche par nom
    cout << "\n  ── Recherche « Gagnon » ──" << endl;
    auto resGagnon = rechercherEmploye("Gagnon");
    for (auto* e : resGagnon) {
        cout << "    - " << e->prenom << " " << e->nom
             << " (Dép. #" << e->idDepartement << ", " << e->poste << ")" << endl;
    }

    // Stagiaires
    cout << "\n  ── Stagiaires ──" << endl;
    auto stagiaires = employesParContrat("Stagiaire");
    for (auto* e : stagiaires) {
        cout << "    - " << e->prenom << " " << e->nom
             << " — " << e->poste << " | " << e->salaireAnnuel << "$/an" << endl;
    }

    // Employés avec doctorat
    cout << "\n  ── Employés avec Doctorat ──" << endl;
    auto doctorats = filtrerParEtudes("Doctorat");
    for (auto* e : doctorats) {
        cout << "    - " << e->prenom << " " << e->nom
             << " — " << e->poste << " | " << e->salaireAnnuel << "$/an" << endl;
    }

    // Salaires entre 80k et 100k
    cout << "\n  ── Salaires entre 80 000$ et 100 000$ ──" << endl;
    auto tranche = filtrerParSalaire(80000, 100000);
    for (auto* e : tranche) {
        cout << "    - " << e->prenom << " " << e->nom
             << " — " << e->salaireAnnuel << "$ (" << e->poste << ")" << endl;
    }

    // Projets d'un employé
    cout << "\n  ── Projets actifs de Sophie Tremblay (#6) ──" << endl;
    auto projetsSophie = projetsEmploye(6);
    for (auto* p : projetsSophie) {
        cout << "    - " << p->nom << " (" << p->statut << ")" << endl;
    }

    // ── 14. Tri ──
    separateur("TRI PAR NOM (ALPHABÉTIQUE)");
    auto parNom = trierParNom();
    for (int i = 0; i < min((int)parNom.size(), 15); i++) {
        cout << "    " << parNom[i]->nom << ", " << parNom[i]->prenom
             << " — " << parNom[i]->poste << endl;
    }
    if ((int)parNom.size() > 15) {
        cout << "    ... et " << (parNom.size() - 15) << " autres employés" << endl;
    }

    // ── 15. Ajout d'un employé ──
    separateur("AJOUT D'UN NOUVEL EMPLOYÉ");
    EmployeEntreprise nouveau(63, "Tremblay", "Léa", "2002-04-10", 23, "F",
        "lea.tremblay@technova.ca", "(514) 555-0090", "450 rue Saint-Paul, Montréal",
        "Développeuse junior", 2, "2026-02-27", "Permanent", 66000, 31.73, 40, 10,
        "Baccalauréat", 1, 0.0, true, "Sophie Tremblay");
    ajouterEmploye(nouveau);

    // ── 16. Augmentation de salaire ──
    separateur("AUGMENTATION DE SALAIRE");
    augmenterSalaire(7, 5.0);   // David Nguyen +5%
    augmenterSalaire(17, 8.0);  // Julie Martin +8% (promotion)

    // ── 17. Désactivation d'un employé ──
    separateur("DÉSACTIVATION D'UN EMPLOYÉ");
    desactiverEmploye(35);  // Louis Perron (contractuel fini)

    // ── 18. Export ──
    separateur("EXPORTATION DES DONNÉES");
    exporterCSV("employes_export.csv");
    exporterJSON("employes_export.json");

    // ── 19. Résumé financier ──
    separateur("RÉSUMÉ FINANCIER");
    cout << "  Masse salariale totale      : " << masseSalariale() << " $/an" << endl;

    double budgetTotal = 0;
    for (const auto& d : departements) budgetTotal += d.budget;
    cout << "  Budget total départements   : " << budgetTotal << " $/an" << endl;

    double budgetProjets = 0, depensesProjets = 0;
    for (const auto& p : projets) {
        budgetProjets += p.budget;
        depensesProjets += p.depenses;
    }
    cout << "  Budget total projets        : " << budgetProjets << " $" << endl;
    cout << "  Dépenses projets à ce jour  : " << depensesProjets << " $" << endl;
    cout << "  Taux utilisation projets    : " << (budgetProjets > 0 ? depensesProjets / budgetProjets * 100 : 0) << " %" << endl;

    double coutFormations = 0;
    for (const auto& f : formations) coutFormations += f.cout;
    cout << "  Investissement formations    : " << coutFormations << " $" << endl;

    // ── 20. Résumé global ──
    separateur("RÉSUMÉ GLOBAL — TechNova Solutions Inc.");
    cout << "  Départements    : " << departements.size() << endl;
    cout << "  Employés        : " << employes.size()
         << " (" << nbActifs << " actifs)" << endl;
    cout << "  Projets         : " << projets.size() << endl;
    cout << "  Affectations    : " << affectations.size() << endl;
    cout << "  Évaluations     : " << evaluations.size() << endl;
    cout << "  Congés          : " << conges.size() << endl;
    cout << "  Formations      : " << formations.size() << endl;

    return 0;
}