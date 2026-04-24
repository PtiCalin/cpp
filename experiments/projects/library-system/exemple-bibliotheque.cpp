/* Fichier   : exemple-bibliotheque.cpp
	Auteure  : Charlie Bouchard    
	Cours    : IFT1166 - Programmation orientée objet en C++    
	Trimestre: Hiver 2026
	But      : Exemple de programme de gestion d'un réseau de bibliothèques en C++
        - Bibliotheques (etablissement)
        - Livres
        - Emprunts
        - Sections
        - Clients
        - Employes
        - Acquisitions
        - Statistiques
	Dernière mise à jour : 2026-02-27
*/

#include <iomanip>
#include "exemple-bibliotheque-data.h"

/* ═══════════════════════════════════════════════════════════════
   FONCTIONS UTILITAIRES DU SYSTÈME
   ═══════════════════════════════════════════════════════════════ */

// Afficher un séparateur
void separateur(const string& titre) {
    cout << "\n══════════════════════════════════════════════════════" << endl;
    cout << "  " << titre << endl;
    cout << "══════════════════════════════════════════════════════" << endl;
}

// Rechercher un livre par ID
LivreBiblio* trouverLivre(int id) {
    for (auto& l : livres) {
        if (l.idLivre == id) return &l;
    }
    return nullptr;
}

// Rechercher un client par ID
Client* trouverClient(int id) {
    for (auto& c : clients) {
        if (c.idClient == id) return &c;
    }
    return nullptr;
}

// Rechercher une section par ID
Section* trouverSection(int id) {
    for (auto& s : sections) {
        if (s.idSection == id) return &s;
    }
    return nullptr;
}

// Chercher des livres par genre
vector<LivreBiblio*> rechercherParGenre(const string& genre) {
    vector<LivreBiblio*> resultats;
    for (auto& l : livres) {
        if (l.genre.find(genre) != string::npos) {
            resultats.push_back(&l);
        }
    }
    return resultats;
}

// Chercher des livres par auteur
vector<LivreBiblio*> rechercherParAuteur(const string& auteur) {
    vector<LivreBiblio*> resultats;
    for (auto& l : livres) {
        if (l.auteur.find(auteur) != string::npos) {
            resultats.push_back(&l);
        }
    }
    return resultats;
}

// Emprunts actifs d'un client
vector<Emprunt*> empruntsActifsClient(int idClient) {
    vector<Emprunt*> resultats;
    for (auto& e : emprunts) {
        if (e.idClient == idClient && !e.retourne) {
            resultats.push_back(&e);
        }
    }
    return resultats;
}

// Historique d'emprunts d'un livre
vector<Emprunt*> historiqueEmpruntLivre(int idLivre) {
    vector<Emprunt*> resultats;
    for (auto& e : emprunts) {
        if (e.idLivre == idLivre) {
            resultats.push_back(&e);
        }
    }
    return resultats;
}

// Employés d'une bibliothèque
vector<Employe*> employesBibliotheque(int idBib) {
    vector<Employe*> resultats;
    for (auto& e : employes) {
        if (e.idBibliotheque == idBib) {
            resultats.push_back(&e);
        }
    }
    return resultats;
}

// Total des amendes impayées
double totalAmendesImpayees() {
    double total = 0;
    for (const auto& c : clients) {
        total += c.amendesImpayees;
    }
    for (const auto& e : emprunts) {
        if (!e.retourne && e.amende > 0) {
            total += e.amende;
        }
    }
    return total;
}

// Valeur totale du catalogue
double valeurTotaleCatalogue() {
    double total = 0;
    for (const auto& l : livres) {
        total += l.valeur;
    }
    return total;
}

// Livres les mieux notés (top N)
vector<LivreBiblio*> topLivresParNote(int n) {
    vector<LivreBiblio*> tous;
    for (auto& l : livres) tous.push_back(&l);
    sort(tous.begin(), tous.end(), [](const LivreBiblio* a, const LivreBiblio* b) {
        return a->note > b->note;
    });
    if ((int)tous.size() > n) tous.resize(n);
    return tous;
}

/* ═══════════════════════════════════════════════════════════════
   PROGRAMME PRINCIPAL
   ═══════════════════════════════════════════════════════════════ */

int main() {
    cout << fixed << setprecision(2);

    // ── 1. Bibliothèques ──
    separateur("BIBLIOTHÈQUES (Établissements)");
    for (const auto& b : bibliotheques) {
        b.afficher();
    }

    // ── 2. Sections ──
    separateur("SECTIONS");
    for (const auto& s : sections) {
        s.afficher();
    }

    // ── 3. Catalogue de livres ──
    separateur("CATALOGUE DE LIVRES (" + to_string(livres.size()) + " titres)");
    for (const auto& l : livres) {
        l.afficher();
    }

    // ── 4. Clients ──
    separateur("CLIENTS (" + to_string(clients.size()) + " inscrits)");
    for (const auto& c : clients) {
        c.afficher();
    }

    // ── 5. Employés ──
    separateur("EMPLOYÉS (" + to_string(employes.size()) + " membres du personnel)");
    for (const auto& e : employes) {
        e.afficher();
    }

    // ── 6. Emprunts actifs ──
    separateur("EMPRUNTS EN COURS");
    int nbActifs = 0;
    for (const auto& e : emprunts) {
        if (!e.retourne) {
            e.afficher();
            nbActifs++;
        }
    }
    cout << "\n  Total emprunts actifs : " << nbActifs << endl;

    // ── 7. Emprunts retournés (historique) ──
    separateur("HISTORIQUE DES RETOURS");
    int nbRetournes = 0;
    for (const auto& e : emprunts) {
        if (e.retourne) {
            e.afficher();
            nbRetournes++;
        }
    }
    cout << "\n  Total retours enregistrés : " << nbRetournes << endl;

    // ── 8. Acquisitions ──
    separateur("ACQUISITIONS (" + to_string(acquisitions.size()) + " entrées)");
    for (const auto& a : acquisitions) {
        a.afficher();
    }

    // ── 9. Statistiques mensuelles ──
    separateur("STATISTIQUES MENSUELLES");
    for (const auto& s : statistiques) {
        s.afficher();
    }

    // ── 10. Recherches et analyses ──
    separateur("ANALYSES ET RECHERCHES");

    // Top 10 livres par note
    cout << "\n  ── Top 10 livres les mieux notés ──" << endl;
    auto top10 = topLivresParNote(10);
    for (int i = 0; i < (int)top10.size(); i++) {
        cout << "    " << (i + 1) << ". \"" << top10[i]->titre
             << "\" (" << top10[i]->note << "/5)" << endl;
    }

    // Recherche par genre : Science-fiction
    cout << "\n  ── Livres de Science-fiction ──" << endl;
    auto sf = rechercherParGenre("Science-fiction");
    for (auto* l : sf) {
        cout << "    - \"" << l->titre << "\" par " << l->auteur << endl;
    }

    // Emprunts actifs d'un client
    cout << "\n  ── Emprunts actifs de Isabelle Côté (client #7) ──" << endl;
    auto empIsabelle = empruntsActifsClient(7);
    for (auto* e : empIsabelle) {
        LivreBiblio* l = trouverLivre(e->idLivre);
        cout << "    - \"" << (l ? l->titre : "?") << "\" (retour prévu: "
             << e->dateRetourPrevue << ")" << endl;
    }

    // Employés de la bibliothèque Ulaval
    cout << "\n  ── Employés de la Bibliothèque de l'Université Laval ──" << endl;
    auto empUlaval = employesBibliotheque(4);
    for (auto* e : empUlaval) {
        cout << "    - " << e->prenom << " " << e->nom
             << " (" << e->poste << ")" << endl;
    }

    // Résumé financier
    separateur("RÉSUMÉ FINANCIER");
    cout << "  Valeur totale du catalogue : " << valeurTotaleCatalogue() << " $" << endl;
    cout << "  Amendes impayées totales   : " << totalAmendesImpayees() << " $" << endl;

    double totalAcquisitions = 0;
    for (const auto& a : acquisitions) {
        totalAcquisitions += a.coutAchat * a.quantite;
    }
    cout << "  Investissement acquisitions: " << totalAcquisitions << " $" << endl;

    double masseSalariale = 0;
    for (const auto& e : employes) {
        masseSalariale += e.salaireAnnuel;
    }
    cout << "  Masse salariale annuelle   : " << masseSalariale << " $" << endl;

    // Résumé global
    separateur("RÉSUMÉ GLOBAL");
    cout << "  Bibliothèques : " << bibliotheques.size() << endl;
    cout << "  Sections      : " << sections.size() << endl;
    cout << "  Livres        : " << livres.size() << endl;
    cout << "  Clients       : " << clients.size() << endl;
    cout << "  Employés      : " << employes.size() << endl;
    cout << "  Emprunts      : " << emprunts.size()
         << " (" << nbActifs << " actifs, " << nbRetournes << " retournés)" << endl;
    cout << "  Acquisitions  : " << acquisitions.size() << endl;
    cout << "  Statistiques  : " << statistiques.size() << " entrées mensuelles" << endl;

    return 0;
}