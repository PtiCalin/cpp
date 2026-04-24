#include <cctype>
#include <iostream>
#include <string>

using namespace std;

// 5.1 Convertir en minuscules en place.
void ConvertirMinus(string& mot) {
    for (size_t i = 0; i < mot.length(); ++i) {
        mot[i] = static_cast<char>(tolower(static_cast<unsigned char>(mot[i])));
    }
}

// 5.2 Echange de deux elements d'un tableau de char.
void SwapElements(char tab[], int i, int j) {
    char temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
}

// 5.3 Conversion string -> char* (sans c_str).
char* ConvertirString(string mot) {
    size_t n = mot.length();
    char* resultat = new char[n + 1];

    for (size_t i = 0; i < n; ++i) {
        resultat[i] = mot[i];
    }
    resultat[n] = '\0';

    return resultat;
}

// 5.4 Tri par selection d'un mot.
string SortString(string mot) {
    ConvertirMinus(mot);

    char* tab = ConvertirString(mot);
    int n = static_cast<int>(mot.length());

    for (int i = 0; i < n - 1; ++i) {
        int idxMin = i;
        for (int j = i + 1; j < n; ++j) {
            if (tab[j] < tab[idxMin]) {
                idxMin = j;
            }
        }
        if (idxMin != i) {
            SwapElements(tab, i, idxMin);
        }
    }

    string trie(tab);
    delete[] tab;
    return trie;
}

class Cellule {
private:
    string valeur_;
    Cellule* prochain_;

public:
    Cellule(string v, Cellule* suivant) : valeur_(v), prochain_(suivant) {}

    Cellule* get_prochain() const {
        return prochain_;
    }

    void set_prochain(Cellule* suivant) {
        prochain_ = suivant;
    }

    string get_valeur() const {
        return valeur_;
    }
};

class Liste {
private:
    Cellule* tete_;
    Cellule* queue_;
    int longueur_;

public:
    Liste() : tete_(nullptr), queue_(nullptr), longueur_(0) {}

    Liste(const Liste& other) : tete_(nullptr), queue_(nullptr), longueur_(0) {
        Cellule* courant = other.tete_;
        while (courant != nullptr) {
            ajout_queue(courant->get_valeur());
            courant = courant->get_prochain();
        }
    }

    Liste& operator=(const Liste& other) {
        if (this == &other) {
            return *this;
        }

        efface();
        Cellule* courant = other.tete_;
        while (courant != nullptr) {
            ajout_queue(courant->get_valeur());
            courant = courant->get_prochain();
        }
        return *this;
    }

    ~Liste() {
        efface();
    }

    void ajout_tete(string x) {
        Cellule* n = new Cellule(x, tete_);
        tete_ = n;
        if (queue_ == nullptr) {
            queue_ = n;
        }
        ++longueur_;
    }

    void ajout_queue(string x) {
        Cellule* n = new Cellule(x, nullptr);
        if (queue_ == nullptr) {
            tete_ = n;
            queue_ = n;
        } else {
            queue_->set_prochain(n);
            queue_ = n;
        }
        ++longueur_;
    }

    void ajout_liste(const Liste& l) {
        for (int i = 0; i < l.getLongueur(); ++i) {
            ajout_queue(l.getElt(i));
        }
    }

    void affiche() {
        Cellule* courant = tete_;
        while (courant != nullptr) {
            cout << courant->get_valeur() << " ";
            courant = courant->get_prochain();
        }
        cout << endl;
    }

    void efface() {
        Cellule* courant = tete_;
        while (courant != nullptr) {
            Cellule* suivant = courant->get_prochain();
            delete courant;
            courant = suivant;
        }
        tete_ = nullptr;
        queue_ = nullptr;
        longueur_ = 0;
    }

    // 5.5
    int getLongueur() const {
        return longueur_;
    }

    // 5.6
    string getElt(int index) const {
        if (index < 0 || index >= longueur_) {
            return "";
        }

        Cellule* courant = tete_;
        int pos = 0;
        while (courant != nullptr && pos < index) {
            courant = courant->get_prochain();
            ++pos;
        }

        if (courant == nullptr) {
            return "";
        }
        return courant->get_valeur();
    }
};

bool sontAnagrammes(const string& a, const string& b) {
    return SortString(a) == SortString(b);
}

// 5.7 main complet
int main() {
    Liste MOTS;
    MOTS.ajout_queue("ami");
    MOTS.ajout_queue("Mai");
    MOTS.ajout_queue("Bonjour");
    MOTS.ajout_queue("Brisavion");
    MOTS.ajout_queue("BorisVian");

    Liste RESULTAT;

    for (int i = 0; i < MOTS.getLongueur(); ++i) {
        string mot = MOTS.getElt(i);

        bool dejaPresentParAnagramme = false;
        for (int j = 0; j < RESULTAT.getLongueur(); ++j) {
            if (sontAnagrammes(mot, RESULTAT.getElt(j))) {
                dejaPresentParAnagramme = true;
                break;
            }
        }

        if (!dejaPresentParAnagramme) {
            RESULTAT.ajout_queue(mot);
        }
    }

    cout << "La liste des mots: ";
    MOTS.affiche();

    cout << "La liste des anagrammes: ";
    RESULTAT.affiche();

    return 0;
}
