IFT1166 Trimestre Été, 2008: Examen Final 1/

## Trimestre Été, 2008

## Mohamed Lokbani

# IFT1166 – Examen Final –

Inscrivez tout de suite votre nom et le code permanent.

Nom: __________________________________| Prénom(s): _____________________________|

Signature: ______________________________| Code perm: ____________________________|

Date : mercredi 9 juillet 2008

Durée : 3 heures (de 17h30 à 20h30)

Local : Z-317 ; Pavillon Claire McNicoll

# Directives:

- Toute documentation est permise.
- Calculatrice **non** permise.
- Répondre directement sur le questionnaire.
- Les réponses **doivent être brèves, précises, claires**
    **et nettement présentées.**

1._____________________/20 (1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8)

2._____________________/15 (2.1, 2.2)

3._____________________/20 (3.1, 3.2, 3.3, 3.4, 3.5)

4._____________________/20 (4.1, 4.2)

5._____________________/25 (5.1, 5.2, 5.3, 5.4, 5.5, 5.6, 5.7)

Total:__________________/

```
Directives officielles
```
```
* Interdiction de toute communication
verbale pendant l'examen.
```
```
* Interdiction de quitter la salle
pendant la première heure.
```
```
* L'étudiant qui doit s'absenter après la
première heure remettra sa carte
d'étudiant au surveillant, l'absence ne
devant pas dépasser 5 minutes. Un
seul étudiant à la fois peut quitter la
salle.
```
```
* Toute infraction relative à une
fraude, un plagiat ou un copiage est
signalée par le surveillant au directeur
de département ou au professeur qui
suspend l'évaluation.
```
```
F.A.S
```

IFT1166 Trimestre Été, 2008: Examen Final 2/

**Exercice 1 (20 points)**

**1.1** Un destructeur est appelé dans le cas (cochez une ou plusieurs réponses) :
a. d’une variable locale qui quitte sa portée.
b. d’un appel à « delete ».
c. d’un appel à « delete [ ] ».
d. d’aucune des réponses précédentes.

**1.2** Peut-on détruire une instance d'une classe si le destructeur de la classe est déclaré privé?
(a) oui, il est possible de la détruire (b) non, il n’est pas possible de la détruire

**Pourquoi?**

**1.3** Définissez ce qu’est « la déclaration d’une classe ».

**1.4** Les membres d'une classe dérivée ont-ils accès à tous les membres de sa classe de base quelque soit leurs droits
d'accès?
(a) oui, ils ont accès (b) non, ils n’ont pas accès

**Pourquoi?**

**1.5** Le mot clé réservé « inline » devant une fonction est juste à titre indicatif pour le compilateur. Celui-ci peut en effet
décider en dernier lieu de l'utiliser ou non.

**Pourquoi?**


IFT1166 Trimestre Été, 2008: Examen Final 3/

**1.6** Écrire le prototype de la fonction « test » qui retourne un pointeur sur un double et qui accepte les 3 arguments
suivants : une chaîne de caractères du type « string » passée par référence, un caractère passé par valeur et initialisé par
défaut avec la lettre « w » et finalement un entier passé par pointeur et initialisé par défaut avec la valeur « NULL ».

**1.7** Citez les appels possibles à la fonction « test » précédemment définie (Q. 1.6).

**1.8** Soit les fichiers suivants :

```
en-tête source objet exécutable
a.h a.cpp a.o
test.cpp test.o test.exe
```
Nous avons déclaré dans le fichier « a.h » la méthode « affiche ». Cette dernière est appelée dans la fonction « main »
définie dans le fichier « test.cpp ».

a. Tout en expliquant brièvement votre réponse, que faudra-t-il ajouter dans le fichier « test.cpp » pour que ce dernier
compile sans problème?

b. Peut-on compiler le fichier « test.cpp » sans faire appel au fichier « a.cpp »?
(a) oui, c’est possible (b) non, ce n’est pas possible

**Pourquoi?**

c. Écrire la ligne de commandes (appelant à gcc) qui permet de générer le fichier exécutable à partir des fichiers objets.


IFT1166 Trimestre Été, 2008: Examen Final 4/

**Exercice 2 (15 points)** Soit la classe « A » :

```
01
02
03
04
05
06
07
```
```
class A{
public:
int x;
A() {
x = 5;
}
};
```
**2.1** Combien de fois est appelé le constructeur de la classe « A » dont la signature est « A( ) » dans le fragment de code
suivant :

```
01
02
03
04
05
06
```
```
A u;
A v;
A *x;
x = new A();
A y = u;
A *z = new A();
```
**Nombre de fois :**

**Pourquoi?**


IFT1166 Trimestre Été, 2008: Examen Final 5/

**2.2** Que va afficher en sortie le programme suivant qui compile et s’exécute correctement :

```
01
02
03
04
05
06
07
08
09
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
```
```
#include <iostream>
#include <string>
using namespace std;
class A{
public:
int x;
A() { x = 5;}
};
class B: public A {
public:
static int x;
B() { x++;}
B(int i) { x = x+i;}
B(string s) {x--;}
};
int B::x=10;
int main() {
B b1;
B b2(2008);
B b3("IFT1166");
cout << b1.x << " : " << b2.x << " : " << b3.x << endl;
return 0;
}
```
**Affichage produit avec vos explications :**


IFT1166 Trimestre Été, 2008: Examen Final 6/

**Exercice 3 (20 points)** Soit les définitions suivantes :

```
01
02
03
04
05
06
07
08
09
10
11
12
13
14
15
16
17
18
19
20
21
22
```
```
class UneInterface {
public:
virtual void methodeX(int c)=0;
};
class A {
public:
void methodeX(int c) {}
};
class B: public UneInterface {
public:
void methodeY(int c) {}
void methodeX(int c) {}
};
class C: public B {
public:
void methodeZ(int c) {}
};
```
Parmi les groupes suivants d’instructions lesquels compilent correctement?

**3.1 UneInterface* x = new A();
x->methodeX(10);**

correct^ incorrect^
**Pourquoi?**

**3.2 UneInterface* y = new B();
y->methodeY(10);**

correct incorrect
**Pourquoi?**


IFT1166 Trimestre Été, 2008: Examen Final 7/

**3.3 UneInterface* z = new B();
z->methodeX(10);**

correct incorrect
**Pourquoi?**

**3.4 UneInterface* w = new C();
w->methodeZ(10);**

correct incorrect
**Pourquoi?**

**3.5 UneInterface* q = new C();
q->methodeX(10);**

correct incorrect
**Pourquoi?**


IFT1166 Trimestre Été, 2008: Examen Final 8/

**Exercice 4 (20 points)** Un compteur est un objet défini par les propriétés suivantes :

- Il possède une valeur entière, positive ou nulle, nulle à sa création. Il ne peut varier que par pas de 1
    (incrémentation).
- Il possède aussi deux méthodes « incremente » et « getValeur » pour respectivement incrémenter la valeur
    entière et obtenir la valeur courante.

**4.1** Écrire la définition de la classe « Compteur » (y compris la définition des méthodes).

**4.2** Une pièce de monnaie est définie par ses deux cotés « pile » et « face ». Soit « UnExemple » une fonction sans
arguments et sans valeur de retour qui contient les instructions nécessaires pour réaliser ce qui suit :

- Lancer aléatoirement 100 fois une pièce de monnaie.
- En supposant que nous avons une chance sur deux d’avoir l’une des deux faces possibles (pile ou face avec
    donc 50/50 de chance) lors de chaque tirage, les compteurs sont mis à jour pour les cotés pile et face de la
    pièce en utilisant pour cela la classe « Compteur » de 4.1. Nous allons supposer qu’une valeur aléatoire égale
    à 0 correspond au coté « pile » et si elle est égale à 1 c’est le coté « face ».
- Afficher sur la sortie standard le résultat obtenu (le nombre de tirages « pile » et celui de « face ») après les
    100 tirages.

Vous pouvez supposer que nous avons inclus dans le programme tous les fichiers d’en-tête nécessaires.


- IFT1166 Trimestre Été, 2008: Examen Final 9/


IFT1166 Trimestre Été, 2008: Examen Final 10/

**Exercice 5 (25 points)
5.1** Écrivez le code de la fonction « ConvertirMinus » dont le prototype est :
void ConvertirMinus(string& mot);

Les caractères de l’argument « mot » sont convertis en minuscule en utilisant la fonction « tolower » définie dans la
librairie standard du langage et dont le prototype est : « int tolower(int c); ». Pour obtenir la taille de « mot », vous
pouvez faire appel à la méthode « length() » définie pour le type « string ».

**5.2** Écrivez le code de la fonction « SwapElements » dont le prototype est :
void SwapElements(char tab[], int i, int j);

Cette fonction permet d’échanger le contenu de « tab[i] » avec celui de « tab[j] ».

**5.3** Écrivez le code de la fonction « ConvertirString » dont le prototype est :
char* ConvertirString(string mot);

Cette méthode permet de convertir l’argument mot du type « string » vers « char* ». C’est l’équivalent de la méthode
« c_str() » dont l’utilisation dans ce cas est interdite.


IFT1166 Trimestre Été, 2008: Examen Final 11/

Pour cette question, on suppose que les méthodes décrites dans les questions « 5.1 », « 5.2 » et « 5.3 » sont déjà codées.

**5.4** Écrivez le code de la méthode « SortString » dont le prototype est :
string SortString(string mot);

Cette méthode retourne l’argument « mot » trié. Par exemple, pour le mot « billet », la méthode retourne « beillt ».
Utilisez l’algorithme de tri, « Tri par sélection » déjà vu en cours, qu’il faudra adapter à ce problème.


IFT1166 Trimestre Été, 2008: Examen Final 12/

Pour ce qui suit, on suppose que les méthodes décrites dans les questions « 5.1 », « 5.2 », « 5.3 » et « 5.4 » sont déjà
codées. Par ailleurs, vous avez en votre possession une variante des classes « Cellule » et « Liste » déjà utilisées en
cours :

```
01
02
03
04
05
06
07
08
09
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
```
```
class Cellule {
string valeur;
Cellule* prochain;
public:
// Constrcuteur
Cellule(string v, Cellule* suivant);
// Obtenir la valeur de son prochain
Cellule* get_prochain();
// Fixer la valeur de son prochain
void set_prochain(Cellule* suivant);
// Obtenir la valeur associée à la cellule
string get_valeur();
};
class Liste {
Cellule *tete, *queue;
int longueur;
public:
// Constructeur
Liste();
// Ajoute un élément au début
void ajout_tete(string x);
// Ajoute un élément à la fin
void ajout_queue(string x);
// Ajoute une autre liste à la fin
void ajout_liste(Liste *l);
// Affiche le contenu de la liste
void affiche();
// Efface tout le contenu de la liste
void efface();
// Retourne le nombre d'éléments dans la liste
int getLongueur();
// Retourne le ième élément de la liste
string getElt(int);
};
```
La variable « valeur » de la classe « Cellule » est maintenant du type « string » au lieu de « int ». Nous avons ajusté les
différentes méthodes des classes « Cellule » et « Liste » pour tenir compte de cette variante. Par ailleurs, nous avons
ajouté les deux méthodes « int getLongueur() » et « string getElt(int) » dans la classe « Liste ». Nous allons supposer
que toutes les méthodes des deux classes sont déjà définies.

**5.5** Écrivez la méthode « int getLongeur() »


IFT1166 Trimestre Été, 2008: Examen Final 13/

**5.6** Écrivez la méthode « string getElt(int) ». Cette méthode retourne une chaîne vide si l'index spécifié ne correspond à
aucun élément.
Note: le premier élément est à la position 0.

**5.7** Complétez le programme par une fonction « main » qui doit réaliser ce qui suit :

- Initialise la variable « MOTS » du type « Liste » avec les mots (dans cet ordre) « ami », « Mai », « Bonjour »,
Brisavion » et « BorisVian ».
- Retourne une liste « RESULTAT » où se trouve un exemplaire de chacune des valeurs de « MOTS » sauf celles qui
sont une anagramme d'un élément déjà dans « RESULTAT ». Pour mémoire une anagramme d’un mot est un mot
formé des mêmes lettres que le premier mais dans un ordre différent. Par exemple le mot « AMI » est une anagramme
de « MAI ».

Vous devez éviter les duplications! Ainsi donc, pour le précédent exemple, vous allez produire comme résultat la liste
de mots : « ami », « Bonjour », « Brisavion ».

- Et affiche en sortie les listes « MOTS » et « RESULTAT », comme suit :

La liste des mots: ami Mai Bonjour Brisavion BorisVian
La liste des anagrammes: ami Bonjour Brisavion

Note: si vous le jugez nécessaire, libre à vous de définir d'autres listes pour manipuler vos données.


IFT1166 Trimestre Été, 2008: Examen Final 14/

```
Bonnes vacances à toutes et à tous.
```

IFT1166 Trimestre Eté, 2007: Examen Final 1/

## Trimestre Eté, 2007

## Mohamed Lokbani

# IFT1166 – Examen Final –

Inscrivez tout de suite votre nom et le code permanent.

Nom: __________________________________| Prénom(s): _____________________________|

Signature: ______________________________| Code perm: ____________________________|

Date : mardi 3 juillet 2007

Durée : 3 heures (de 17h30 à 20h30)

Local : N-515 ; Pavillon Roger Gaudry

# Directives:

- Toute documentation permise.
- Calculatrice **non** permise.
- Répondre directement sur le questionnaire.
- Les réponses **doivent être brèves, précises et clairement présentées.**

### 1._____________________/20 (1.1, 1.2, 1.3, 1.4)

### 2._____________________/15 (2.1)

### 3._____________________/20 (3.1, 3.2)

### 4._____________________/15 (4.1)

### 5._____________________/30 (5.1, 5.2, 5.3, 5.4, 5.5, 5.6, 5.7, 5.8, 5.9)

Total:__________________/

```
Directives officielles
```
```
* Interdiction de toute communication
verbale pendant l'examen.
```
```
* Interdiction de quitter la salle
pendant la première heure.
```
```
* L'étudiant qui doit s'absenter après la
première heure remettra sa carte
d'étudiant au surveillant, l'absence ne
devant pas dépasser 5 minutes. Un
seul étudiant à la fois peut quitter la
salle.
```
```
* Toute infraction relative à une
fraude, un plagiat ou un copiage est
signalée par le surveillant au directeur
de département ou au professeur qui
suspend l'évaluation.
```
```
F.A.S
```

IFT1166 Trimestre Eté, 2007: Examen Final 2/

**Exercice 1 (20 points)
1.1** Expliquez brièvement la notion de « fuite de mémoire ».

**1.2** Écrivez les instructions correspondantes pour libérer l’espace mémoire alloué pour chacune des
instructions ci-dessous :

```
Allocation Libération
```
```
A
string *p = new string;
```
```
B
string *p = new string[3];
```
```
C
Temps *p = new Temps(12,0,0);
```
```
D
int *p = new int(33);
```
```
E
int *p = new int[33];
```
**1.3** Identifiez et corrigez les erreurs dans le programme suivant, s’il y’en a.

```
#include <iostream>
using namespace std;
int main() {
int *p1 = new int (5);
int *p2 = p1;
cout << "p1 pointe la valeur " << *p2 << endl;
delete [] p1;
delete p2;
return 0;
}
```

IFT1166 Trimestre Eté, 2007: Examen Final 3/

**1.4** Le programme suivant compile correctement mais se plante lors de l’exécution avec un message
« segmentation fault ». Il contient en effet 3 erreurs fondamentales reliées à la manière avec laquelle le
programme gère l’espace mémoire alloué. Trouvez ces erreurs et corrigez-les.

```
1 2 3 4 5 6 7 8 9
```
```
10
11
```
```
#include<iostream>
int main() {
using namespace std;
double* d = new double;
for(unsigned int i = 0; i < 3; i++) {
d[i] = 1.5 + i;
}
for(unsigned int i = 2; i >= 0; i--) {
cout << d[i] << endl;
}
}
```

IFT1166 Trimestre Eté, 2007: Examen Final 4/

**Exercice 2 (15 points)** Dites si les lignes mentionnées ci-dessous sont syntaxiquement correctes ou non.
Pour chacune des lignes incorrectes, indiquez la raison.

```
#include <iostream>
using namespace std;
class C {
private: int x;
protected: int y;
public: int z;
C(){x=0;y=0;z=0;}
};
class C1: public C {
private: int x1;
public: int y1;
C1(){x1=0;y1=0;}
};
class C2: private C {
private: int x2;
public: int y2;
C2(){x2=0;y2=0;}
};
int main() {
C1 o1;
C2 o2;
```
```
cout << o1.x << endl;
```
```
Correcte : Incorrecte :
Pourquoi :
```
```
cout << o2.y << endl;
```
```
Correcte : Incorrecte :
Pourquoi :
```
```
cout << o1.z << endl;
```
```
Correcte : Incorrecte :
Pourquoi :
```
```
cout << o1.x1 << endl;
```
```
Correcte : Incorrecte :
Pourquoi :
```
```
cout << o1.y1 << endl;
```
```
Correcte : Incorrecte :
Pourquoi :
```
```
cout << o2.z << endl;
```
```
Correcte : Incorrecte :
Pourquoi :
```
```
cout << o2.x2 << endl;
```
```
Correcte : Incorrecte :
Pourquoi :
```
```
cout << o2.y2 << endl;
```
```
Correcte : Incorrecte :
Pourquoi :
```
```
return 0;
}
```

IFT1166 Trimestre Eté, 2007: Examen Final 5/

**Exercice 3 (20 points)
3.1** Pour chacune des fonctions « f, m et g », justifiez si elle va s'exécuter correctement (la fonction
termine) ou non. Si elle s'exécute correctement, dites ce qu'elle calcule.

```
// f est appelée qu'avec des valeurs de n >= 0 par exemple f(3)
int f(int n){
if(n == 0)
return 1;
else
return f(n+1);
}
```
Exécution correcte et affichage en sortie : Exécution Incorrecte :
Pourquoi :

```
// m est appelée qu'avec des valeurs de n < 0 par exemple m(-3)
int m(int n){
if(n == 0)
return 0;
else {
int result = m(n-1);
result += n;
return result;
}
}
```
Exécution correcte et affichage en sortie : Exécution Incorrecte :
Pourquoi :

```
// g est appelée avec ("Il etait une fois un petit chaperon rouge",'t')
int g(char* p, char c){
return (*p)?(*p==c) + g(p+1,c):0;
}
```
Exécution correcte et affichage en sortie : Exécution Incorrecte :
Pourquoi :


IFT1166 Trimestre Eté, 2007: Examen Final 6/

**3.2** Expliquez les erreurs dans la fonction récursive ci-dessous et proposez une version corrigée (vous
devez donc coder une nouvelle version qu’en modifiant le corps de la fonction. L’en-tête doit rester la
même) :

```
double plus_grande_valeur(int nb, double *valeurs) {
int a, b;
a = plus_grande_valeur(nb/2, valeurs);
b = plus_grande_valeur(nb/2, valeurs + nb/2);
if(a >= b) return a;
else return b;
}
```

IFT1166 Trimestre Eté, 2007: Examen Final 7/12

**Exercice 4 (15 points)** Soit une classe « Pile » déjà définie et qui contient les méthodes suivantes :

```
// Elle permet d’empiler les éléments du type “char”
void push(char);
// Elle permet de dépiler les éléments. Elle retourne l’élément
char pop(void);
// Elle vérifie si la pile est vide. Retourne « true » si c’est
// le cas, sinon « false ».
bool estVide(void);
```
En utilisant la classe Pile définie précédemment, écrivez la fonction « verifBalance » qui vérifie si un
tableau de caractères contenant des parenthèses est bien « parenthésé ». Par exemple :

```
char par0[] = ""; // ok
char par1[] = "(()())"; // ok
char par2[] = "((((()(()())())())()))"; // ok
char par3[] = " ( (()())"; // incorrect. Manque )
char par4[] = "(()(())) ) "; // incorrect. Manque (
char par5[] = ")("; // incorrect. Manque ( et )
```
La signature de la méthode est comme suit :

```
bool verifBalance(char * str)
```
La fonction doit retourner « true » si le tableau est correctement balancé sinon « false » dans le cas
contraire.


IFT1166 Trimestre Eté, 2007: Examen Final 8/12


IFT1166 Trimestre Eté, 2007: Examen Final 9/12

**Exercice 5 (30 points)** Soit le fragment de code suivant :

**//=================
// Classe Vehicule
//=================**

class Vehicule {
public:
Vehicule(int nbRoues = 0);
virtual ~Vehicule();
virtual void Affiche() const;
int GetRoues() const;
void SetRoues(int Roues );
private:
int m_nbRoues;
};
Vehicule::Vehicule(int Roues){
m_nbRoues = Roues;
}
int Vehicule::GetRoues() const{
return m_nbRoues;
}
void Vehicule::SetRoues(int Roues){
m_nbRoues = Roues;
}
void Vehicule::Affiche() const{
cout << "Vehicule";
}
Vehicule::~Vehicule() {}

**//=================
// Moto class
//=================**

class Moto:public Vehicule{
public:
Moto(int Roues = 2);
~Moto();
};

**// Constructeur de Moto à compléter**

Moto::~Moto (){}

**//===================
// Classe Voiture
//===================**
class Voiture:public Vehicule {
public:
Voiture (int Roues = 4);
void Affiche() const;
};

**// Constructeur de Voiture à compléter**

void Voiture::Affiche() const{
cout << "Voiture";
}

```
//=============================
// Classe Parc de stationnement
//=============================
```
```
class Parc {
public:
Parc(int maxVehicules = 20);
~Parc();
int NbStationnes() const;
void Garer(Vehicule& v );
int TotalRoues() const;
void Affiche() const;
Parc(const Parc&);
Parc& operator=(const Parc&);
private:
int m_nbVehicules;
Vehicule **m_Vehicules;
};
// Constructeur de recopie et opérateur= sont
// déjà codés.
// Constructeur de Parc à compléter
// Destructeur de Parc à compléter
int Parc::NbStationnes() const {
return m_nbVehicules;
}
// Méthode Garer à compléter
// Elle stocke le véhicule (l’argument) dans
// le tableau m_Vehicules
// Méthode Affiche à compléter
// Elle affiche en sortie le type du véhicule
// et son nombre de roues
// Comme exemple de format d’affichage:
// Voiture:4
// Méthode ToTalRoues à compléter
// Elle retourne le nombre total de roues dans
// le parc de stationnement
```
```
//===================
// Fonction « main »
//===================
```
```
int main(){
Parc Parking;
Voiture chevy;
Voiture camry;
Moto harley(3);
Moto honda;
Parking.Garer(chevy);
Parking.Garer(honda);
Parking.Garer(harley);
Parking.Garer(camry);
Parking.Affiche( );
cout << endl;
cout << "Le parc contient : "\
<< Parking.TotalRoues() \
<< " Roues" << endl;
return 0;
}
```

IFT1166 Trimestre Eté, 2007: Examen Final 10/12

**5.1** Citez au moins deux instructions du programme qui forcent l'utilisation de la ligature dynamique par ce
dernier.

**5.2** Le programme contient-il une classe abstraite? Si oui, nommez-la.

**5.3** Nommez les classes qui dérivent de la classe « Vehicule ».

**5.4** La classe « Parc » peut-elle conceptuellement parlant devenir une classe de base pour les autres classes
du programme?

**5.5** Le compilateur va-t-il prévenir la classe « Voiture » pour redéfinir la méthode « GetRoues »?

**5.6** Le compilateur va laisser la classe « Voiture » redéfinir la méthode « GetRoues », mais ce n'est pas une
très bonne idée de le faire? Est-ce vrai?

**5.7** La méthode « SetRoues » ne peut être utilisée de manière polymorphique car ce n'est pas une méthode
virtuelle (ou virtuelle pure). Est-ce vrai?


IFT1166 Trimestre Eté, 2007: Examen Final 11/12

**5.8** Écrivez le code des méthodes suivantes :

```
(a) Constructeur de la classe « Moto »
```
```
(b) Constructeur de la classe « Voiture »
```
```
(c) Constructeur de la classe « Parc »
```
```
(d) Destructeur de la classe « Parc »
```
```
(e) Méthode « Garer » de la classe « Parc »
```

IFT1166 Trimestre Eté, 2007: Examen Final 12/12

```
(f) Méthode « Affiche » de la classe « Parc »
```
```
(g) Méthode « TotalRoue » de la classe « Parc »
```
**5.9** Tout en justifiant votre réponse que va afficher en sortie le précédent programme?


IFT1166 Trimestre Automne, 2005: Examen Final 1/11

## Trimestre Automne, 2005

## Mohamed Lokbani

# IFT1166 – Examen Final

Inscrivez tout de suite votre nom et code permanent.

Nom: __________________________________| Prénom(s): _____________________________|

Signature: ______________________________| Code perm: ____________________________|

Date : 10 décembre 2005

Durée: 2 heures et 45 minutes (de 09h30 à 12h15) Local: Z-317, du Pavillon Claire-McNicoll.

# Directives:

- Toute documentation permise.
- Calculatrice **non** permise.
- Répondre directement sur le questionnaire.
- Les réponses **doivent être brèves, précises et clairement présentées.**

### 1._____________________/15 (1.1, 1.2, 1.3, 1.4)

### 2._____________________/20 (2.1)

### 3._____________________/20 (3.1, 3.2, 3.3, 3.4)

### 4._____________________/15 (4.1, 4.2, 4.3, 4.4)

### 5_____________________ /30 (5.1, 5.2, 5.3)

Total:__________________/100

```
Directives officielles
```
```
* Interdiction de toute communication
verbale pendant l'examen.
```
```
* Interdiction de quitter la salle
pendant la première heure.
```
```
* L'étudiant qui doit s'absenter après la
première heure remet sa carte
d'étudiant au surveillant, l'absence ne
devant pas dépasser 5 minutes.
```
```
* Un seul étudiant à la fois peut quitter
la salle.
```
```
* Tout plagiat, copiage ou fraude
constitue une infraction et l'étudiant
qui commet ce délit se voit attribuer la
note F par le professeur.
```
```
F.A.S
```

IFT1166 Trimestre Automne, 2005: Examen Final 2/11

**Exercice 1 (15 points)
1.1** Un des gros problèmes dans le développement de logiciels est la réutilisation d'un travail déjà réalisé.
Expliquer brièvement comment la programmation par objets peut aider à solutionner ce problème de
réutilisation.

**1.2** Soit la classe de base (B) « class B{int a;}; ». Doit-on ajouter quelque chose de particulier au
niveau de cette classe de base pour que son membre privé « a » ne soit accessible qu’à partir d’une classe
dérivée (D)? Si oui, quoi au juste? (Expliquer votre réponse)

**1.3.** Que signifient les termes "une variable de classe" et "une méthode de classe"?


IFT1166 Trimestre Automne, 2005: Examen Final 3/11

**1.4.** Tout en justifiant votre réponse, quelle est la valeur de l'expression suivante pour a différent de b
(a!=b):

```
(((a<b)?a:b)+((a>b)?b:a))/2
```
```
A) La plus petite valeur de a et b?
```
```
B) La plus grande valeur de a et b?
```
```
C) La moyenne de a et b?
```
```
D) La somme de a et b?
```
La bonne réponse est __________ parce que ......


IFT1166 Trimestre Automne, 2005: Examen Final 4/11

**Exercice 2 (20 points)** Que va afficher en sortie le programme suivant qui compile et s’exécute
correctement :

```
1 2 3 4 5 6 7 8 9
```
```
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
```
```
#include <iostream>
using namespace std;
```
```
class A {
public:
A(){ cout << "CD-A-\n"; }
A(A &un_a){ cout << "CR-A-\n"; }
~A() { cout << "D-A-\n"; }
};
class B : A {
int bval;
public:
B() : bval(0){ cout << "CD-B-\n"; }
B(int i):bval(i) { cout << "Cint-B-\n"; }
B(B &un_b):bval(un_b.bval) { cout << "CR-B-\n"; }
~B() { cout << "D-B- " << bval << endl; }
};
void Test(A avar, B &bvar){
cout << "Dans Test\n";
}
int main(){
A avar;
B bvar(10);
cout << "Dans main\n";
Test(avar, bvar);
cout << "Quittes main\n";
return 0;
}
```
**Attention : vous devez expliquer et détailler votre réponse.**


IFT1166 Trimestre Automne, 2005: Examen Final 5/11

Exercice 2 (suite de votre réponse)


IFT1166 Trimestre Automne, 2005: Examen Final 6/11

**Exercice 3 (20 points)** Pour le fragment de code suivant, indiquer si les lignes 4 dernières lignes
provoquent une erreur à la compilation. S’il y a erreur, vous devez la commenter. Dans le cas contraire,
tout en expliquant votre réponse, vous devez donner l’affichage en sortie. À noter, que si une des lignes
provoque une erreur de compilation, cette dernière ne va pas planter le reste du programme. Après avoir
expliqué l’origine de l’erreur, vous pouvez la considérer comme en commentaire pour le reste du
programme. Ceci va vous permettre de vérifier les 4 lignes de manière indépendante.

```
#include <iostream>
```
```
using namespace std;
```
```
class B{};
class C{};
class BBB:public B{};
class CCC:public C{};
```
```
B &b1ref = * (new B);
B &b3ref = * (new BBB);
BBB bbb;
C &c1ref = * (new C);
C &c3ref = * (new CCC);
CCC ccc;
```
```
void fn(B,C){cout << "fn1" << endl;}
void fn(B,CCC){cout << "fn2" << endl;}
void fn(BBB,C){cout << "fn3" << endl;}
```
```
void foo()
{
fn(b1ref,c1ref); // Ligne -1-
fn(b1ref,c3ref); // Ligne -2-
fn(b3ref,c3ref); // Ligne -3-
fn(bbb,ccc); // Ligne -4-
}
```
**3.1** fn(b1ref,c1ref); // Ligne -1-

correcte incorrecte
Pourquoi (affichage en sortie)


IFT1166 Trimestre Automne, 2005: Examen Final 7/11

**3.2** fn(b1ref,c3ref); // Ligne -2-

(^) correcte incorrecte
Pourquoi (affichage en sortie)
**3.3** fn(b3ref,c3ref); // Ligne -3-
correcte incorrecte
Pourquoi (affichage en sortie)
**3.4** fn(bbb,ccc); // Ligne -4-
correcte incorrecte
Pourquoi (affichage en sortie)


IFT1166 Trimestre Automne, 2005: Examen Final 8/11

**Exercice 4 (15 points)** Soit la méthode suivante :

```
double caFaitQuoi(double a,int b){
if (b==0)
return 1;
else
return(a*caFaitQuoi(a,b-1));
}
```
**4.1** Cette méthode est elle récursive? (Expliquer brièvement pourquoi)

**4.2** Indiquer la valeur de « n » après l’exécution de chacune des instructions suivantes (on suppose que
« n » est déclaré entier) :

**Appel Résultat**
n = caFaitQuoi(0,2);

n = caFaitQuoi(2,4);

**4.3** Énoncer en une phrase **simple** ce que calcule cette méthode.

**4.4** La méthode « caFaitQuoi » butte sur un bug quand la valeur de « b » est négative. Expliquer pourquoi?
Modifier par la suite la méthode « caFaitQuoi » pour qu’elle produise un résultat correct quelle que soit la
valeur de « b » (b positif, nul ou négatif).


IFT1166 Trimestre Automne, 2005: Examen Final 9/11

**Exercice 5 (30 points)** Nous allons supposer l’implémentation suivante d’une liste chaînée de nombres
entiers :

```
struct ListeNoeud{
int info;
ListeNoeud * suiv;
ListeNoeud(int val,ListeNoeud *ptr):info(val),suiv(ptr){ }
};
```
**5.1** Si « x » est la plus petite valeur dans la liste ; la méthode « PremierMin », dont l’en-tête est donné ci-
dessous, retourne un pointeur vers la première occurrence de « x ». Si la liste est vide « PremierMin »
retourne une valeur nulle.
Par exemple, si « L » et « p » sont des variables « ListeNoeud* » :

```
Liste chaînée L Résultat suite à « p = PremierMin(L) »
```
ListeNoeud* PremierMin(ListeNoeud *liste){

}


IFT1166 Trimestre Automne, 2005: Examen Final 10/11

**5.2** Écrire la méthode « RetirerSuivant », dont l’en-tête est donné ci-dessous. Cette méthode accepte
l’argument « p », un pointeur non nul du type « ListeNoeud ». La méthode « RetirerSuivant » retire de la
liste le nœud qui suit le nœud pointé par « p » et libère en conséquence l’espace mémoire alloué. La
méthode « RetirerSuivant » n’a aucun effet si le nœud pointé par « p » est le dernier nœud de la liste.

```
Avant l’appel à RetirerSuivant(p) Après l’appel à RetirerSuivant(p)
```
(^)
void RetirerSuivant(ListeNoeud * ptr)
// précondition: ptr != NULL
{
}


IFT1166 Trimestre Automne, 2005: Examen Final 11/11

**5.3** Si « x » est la plus petite valeur dans la liste ; la méthode « RetirerDupMins » dont l’en-tête est donné
ci-dessous, élimine toutes les occurrences de « x » sauf la première occurrence de « x ». La méthode n’a
aucun effet si la liste est vide.

```
Liste L avant l’appel à RetirerDupMins(L) Liste L après l’appel à RetirerDupMins(L)
```
Dans l’écriture de “RetirerDupMins” vous pouvez faire appel aux deux méthodes « PremierMin »
et « RetirerSuivant » telles que décrites dans les questions (5.1 et 5.2), même si vous ne les avez pas codées
encore.

void RetireDupMins(ListeNoeud * liste){

}

```
Joyeuses Fêtes!
```

IFT1166 Hiver-2005: Final 1/10

## IFT1166 - Session Hiver, Final

## Mohamed Lokbani

# IFT1166 - FINAL

Inscrivez tout de suite votre nom et code permanent.

Nom: __________________________________| Prénom(s): _____________________________|

Signature: ______________________________| Code perm: ____________________________|

Date : 19 avril 2005

Durée: 2 heures et 45 minutes (de 18h30 à 21h15)
Local: Z-310, Pavillon Claire-McNicoll (ancienne aile Z).

# Directives:

- Toute documentation permise.
- Calculatrice **non** permise.
- Répondre directement sur le questionnaire.
- Les réponses **doivent être brèves, précises et clairement présentées.**
- Soyez **BREFS** et **PRÉCIS** dans vos réponses.

### 1._____________________/15 (1.1, 1.2, 1.3, 1.4)

### 2._____________________/20 (2.1)

### 3._____________________/15 (3.1)

4._____________________/20 (4.1 a, b ; 4.2 a, b)

5._____________________/30 (5.1)

Total:__________________/100

```
Directives officielles
```
```
* Interdiction de toute communication verbale pendant
l'examen.
```
```
* Interdiction de quitter la salle pendant la première
heure.
```
```
* L'étudiant qui doit s'absenter après la première heure
remet sa carte d'étudiant au surveillant, l'absence ne
devant pas dépasser 5 minutes.
```
```
* Un seul étudiant à la fois peut quitter la salle.
```
```
* Tout plagiat, copiage ou fraude constitue une
infraction et l'étudiant qui commet ce délit se voit
attribuer la note F par le professeur.
F.A.S
```

IFT1166 Hiver-2005: Final 2/10

**Question 1 (15 points)** Soit la classe mammifère, Mamf, suivante:

```
class Mamf{
public:
boolean ADesPattes(){
return true;
}
};
```
**1.1** Si vous devez créer la classe "Chien" qui hérite de Mamf , conceptuellement, est-ce que vous allez:
a) surcharger la méthode "ADesPattes"?
b) redéfinir la méthode "ADesPattes"?
c) utiliser la méthode "ADesPattes" telle quelle, par héritage?

```
(a) (b) (c)
Pourquoi? (Courte explication)
```
**1.2** En tenant compte de votre précédente réponse (1.1), implémenter la classe "Chien" en conséquence.

**1.3** Si vous devez créer la classe "Baleine " qui hérite de Mamf, conceptuellement, est-ce que vous allez:
a) surcharger la méthode "ADesPattes"?
b) redéfinir la méthode "ADesPattes"?
c) utiliser la méthode "ADesPattes" telle quelle, par héritage?

```
(a) (b) (c)
Pourquoi? (Courte explication)
```
**1.4** En tenant compte de votre précédente réponse (1.3), implémenter la classe "Baleine " en conséquence.


IFT1166 Hiver-2005: Final 3/10

**Question 2 (20 points)** Pour chacune des méthodes (incluant le constructeur) de la classe C, indiquer
si la compilation des méthodes de la classe C provoque des erreurs (y compris les warnings). Si oui dites
pourquoi et proposer une solution, si c’est possible.

```
1 #include<iostream>
2 using namespace std;
3 class C{
4 int x;
5 public:
6
C(int y) x(y) {};
```
```
correcte incorrecte
^
Pourquoi:
```
```
7 void f(const C &a) {
8 x = a.x;
9 }
```
```
correcte incorrecte
^
Pourquoi:
```
```
10 void g(C& a) const{
11 x = 10;
12 }
```
```
correcte incorrecte
^
Pourquoi:
```

IFT1166 Hiver-2005: Final 4/10

```
13 int h(int& y){
14 return y*0.5;
15 }
correcte incorrecte
^
Pourquoi:
```
```
16 int j(const int* y) const{
17 *y = 10;
18 }
```
```
correcte incorrecte
^
Pourquoi:
```
```
19 int k(const int& y) const{
20 y = 10;
21 }
```
```
correcte incorrecte
^
Pourquoi:
```
```
22 };
```

IFT1166 Hiver-2005: Final 5/10

**Question 3 (15 points)** Tout en justifiant votre réponse, que va afficher en sortie le programme
suivant, qui compile et s’exécute correctement.

```
1 #include <iostream>
2 using namespace std;
3
4 class Nombre {
5 public:
6 Nombre(int i) {
7 valeur=i;
8 };
9 Nombre operator- () {
10 cout<< "Moins " << valeur << endl;
11 return Nombre(-valeur);
12 };
13 friend ostream& operator<< (ostream &o, Nombre n);
14 int operator* () {
15 return valeur;
16 };
17 bool operator== (Nombre n) {
18 cout<< "Est-ce que " << valeur << " est égal à " << n.valeur << "?" <<endl;
19 return (valeur==n.valeur);
20 }
21 private:
22 int valeur;
23 };
24 ostream& operator<< (ostream &o, Nombre n) {
25 o<<*n;
26 return o;
27 }
28 int main() {
29 Nombre un(1), moins_un(-1);
30 if (-un == moins_un)
31 cout<< -un << " est équivalent à " << moins_un << endl;
32 else
33 cout<<"Comment ça se fait!"<<endl;
34
35 return 0;
36 }
```

IFT1166 Hiver-2005: Final 6/10


IFT1166 Hiver-2005: Final 7/10

**Question 4 (20 points)** On vous donne la tâche de réaliser un programme permettant de traiter un ensemble de
requêtes soumises par les employés de la compagnie « ift1166 inc. ». Si votre programme devait traiter les requêtes
reçues en utilisant les contraintes suivantes :

**4.1** « premier arrivé, premier servi » :

```
a) Tout en justifiant votre réponse, quel est le nom du conteneur STL le plus approprié pour traiter ce genre
de contrainte?
```
```
b) Quelles sont les méthodes de base, associées à ce type de conteneur? Donner un exemple simple
d'utilisation de ces méthodes (de base).
```
**4.2** Ordre alphabétique croissant du nom de la personne, de la liste des employés, ayant soumis la requête.

```
a) Tout en justifiant votre réponse, comment doit-on adapter le conteneur utilisé dans la question (4.1) pour
ce genre de contrainte?
```
```
b) Tout en justifiant votre réponse, écrire la déclaration d’un objet r une instance de ce type de conteneur.
```

IFT1166 Hiver-2005: Final 8/10

**Question 5 (30 points)** Écrire un programme qui réalise les opérations suivantes:

-1- Lit le contenu d'un fichier passé en argument. Ce fichier contient un certain nombre de mots, chacun se
trouvant sur une ligne séparée.

-2- Affiche en sortie:
a) Le nombre de mots répétés plus d'une fois,
b) Le mot le plus répété,
c) Le 10e mot lu, extrait de la liste des mots triée dans un ordre alphabétique croissant.

La forme des lettres dans un mot n’est pas un élément discriminant. Un mot écrit en majuscule ou en
minuscule, c’est exactement le même mot.

L'exécution du programme sera comme suit:
Si par exemple le fichier test.txt contient les
données suivantes:
exo5.exe test.txt

```
L'affichage en sortie sera alors:
```
```
Nombre de mots répétés: 4 mots
Le mot le plus répété: se
Le 10e mot = il
```
Le
soleil
se
couche
en
se
levant
Il
fait
beau
demain
il
est
venu
hier
se
couche
mais
fait
marquant

**Attention, les critères suivants sont des éléments très importants lors de la correction :**

- La simplicité de votre code,
- La clarté de sa présentation,
- L’utilisation des STL,
- L’utilisation des algorithmes de la STL,
- L’optimisation algorithmique de votre programme.

A titre d’exemple, l’utilisation uniquement de « boucles for, while etc. » pour résoudre cet exercice, ne va
pas vous permettre d’obtenir la note maximale, même si votre programme est « 100% correct »!


IFT1166 Hiver-2005: Final 9/10


IFT1166 Hiver-2005: Final 10/10


IFT1166 Hiver-2004 : Final 1/10

## IFT1166 - Session Hiver, Final

## Mohamed Lokbani

# IFT1166 - FINAL

Inscrivez tout de suite votre nom et code permanent.

Nom: __________________________________| Prénom(s): _____________________________|

Signature: ______________________________| Code perm: ____________________________|

Date : 24 avril 2004

Durée: 2 heures 45 minutes (de 10h30 à 13h15)
Local: Z-330 du Pavillon Claire-McNicoll (ancienne aile Z).

# Directives:

- Toute documentation permise.
- Calculatrice **non** permise.
- Répondre directement sur le questionnaire.
- Les réponses **doivent être clairement présentées.**

### 1._____________________/11 (1.1 ; 1.2 ; 1.3 ; 1.4 ; 1.5)

### 2._____________________/18 (2.1 ; 2.2 ; 2.3 ; 2.4 ; 2.5 ; 2.6 ; 2.7)

### 3._____________________/17 (3.1 ; 3.2 ; 3.3 ; 3.4)

### 4._____________________/24 (4.1 ; 4.2 ; 4.3 ; 4.4 ; 4.5 ; 4.6 ; 4.7 ; 4.8)

### 5._____________________/17.5 (5.1)

### 6._____________________/12.5 (6.1)

Total:__________________/100

```
* Interdiction de toute communication verbale
pendant l'examen.
```
```
* Interdiction de quitter la salle pendant la
première heure.
```
```
* L'étudiant qui doit s'absenter après la première
heure remet sa carte d'étudiant au surveillant,
l'absence ne devant pas dépasser 5 minutes.
```
```
* Un seul étudiant à la fois peut quitter la salle.
```
```
* Tout plagiat, copiage ou fraude constitue une
infraction et l'étudiant qui commet ce délit se voit
attribuer la note F par le professeur.
```

IFT1166 Hiver-2004 : Final 2/10

**Question 1 (11 points)** Pour les besoins de cet exercice nous allons utiliser le scénario suivant:
Soit:

- deux modules A et B dont les classes (A et B) et les différentes méthodes associées sont définies dans les
fichiers: A.h/A.cpp et B.h/B.cpp.
- foo une des méthodes de la classe A et bar une des méthodes de la classe B.
- la méthode foo de la classe A fait appel à la méthode bar de la classe B.
- la méthode main est définie dans un fichier à part main.cpp

**1.1** Quelle(s) information(s) relative(s) à la classe B, doit-on ajouter dans le module A pour que ce dernier
compile correctement?

**1.2** Quel type de fichier est créé suite à la compilation du module A?

**1.3** Quelle est l'erreur générée si vous tentez de produire un exécutable à partir du module A uniquement?
Et quel a-t-elle était provoquée?

**1.4** Si vous commettez une erreur typographique et faites en sorte que foo appelle la méthode baf au lieu
de bar, quelle est l'erreur générée lors de la compilation du module A.

**1.5** Écrire les instructions relatives au compilateur gcc, permettant de réaliser l'édition de liens des 3
fichiers main.cpp, A.cpp et B.cpp; et qui génére en sortie l'exécutable exo1.exe


IFT1166 Hiver-2004 : Final 3/10

**Question 2 (18 points)** Soit la classe suivante:
class Noeud {
public:
string Value;
Noeud *Next;
};
Et le fragment de code suivant:
Noeud *Sommet;
Noeud TempNoeud;
Sommet = new Noeud;
Quel est le type des expressions suivantes (encercler la bonne réponse tout en justifiant votre réponse).

**2.1** TempNoeud.Next

string pointeur vers un string Noeud pointeur vers un Noeud pointeur d'un pointeur vers un Noeud illégal

**Courte explication :**

**2.2** (*Sommet).Value

string pointeur vers un string Noeud pointeur vers un Noeud pointeur d'un pointeur vers un Noeud illégal

**Courte explication :**

**2.3** &TempNoeud

string pointeur vers un string Noeud pointeur vers un Noeud pointeur d'un pointeur vers un Noeud illégal

**Courte explication :**

**2.4** Sommet->Next

string pointeur vers un string Noeud pointeur vers un Noeud pointeur d'un pointeur vers un Noeud illégal

**Courte explication :**

**2.5** &Sommet

string pointeur vers un string Noeud pointeur vers un Noeud pointeur d'un pointeur vers un Noeud illégal

**Courte explication :**

**2.6** Sommet.Value

string pointeur vers un string Noeud pointeur vers un Noeud pointeur d'un pointeur vers un Noeud illégal

**Courte explication :**

**2.7** *(Sommet->Next)

string pointeur vers un string Noeud pointeur vers un Noeud pointeur d'un pointeur vers un Noeud illégal

**Courte explication :**


IFT1166 Hiver-2004 : Final 4/10

**Question 3 (17 points)** Soit la classe suivante :
class IntList {
public:
// Construit une liste ayant n éléments.
// val est la valeur par défaut pour chacun des éléments.
IntegerList(int n = 10, int val = 0);
~IntegerList();

```
// Retourne le i e élément de la liste (version const)
int operator[](int i) const;
// Retourne le i e élément de la liste (version non const)
int& operator[](int i);
```
// Retourne le nombre d'éléments dans la liste
int GetSize() const;
private:
int taille; // Taille de la liste
int *ptr; // Un pointeur vers les éléments de la liste
};
Voici un fragment de code montrant comment est utilisée la classe IntList.

IntList C(6,2); // C est une liste ayant 6 éléments, chacun est initialisé à 2.
C[2] = 4; // le 3e élément vaut maintenant 4.

**3.1** Modifier la classe IntList pour lui permettre de supporter un type d'objets T générique. Soit
GenIntList<T> le nom de cette nouvelle classe.


IFT1166 Hiver-2004 : Final 5/10

**3.2** Le constructeur de la classe IntList est comme suit:

```
IntList::IntList(int n, int val) {
assert(n > 0);
taille = n;
ptr = new int [n];
for (int i = 0; i < n; ++i) {
ptr[i] = val;
}
}
```
Écrire le constructeur de la classe générique GenIntList<T>.

**3.3** Écrire l'instruction permettant d'instancier un objet maListe de classe GenIntList<T> ayant 8 éléments
chacun initialisé avec la valeur 3.

**3.4** Nous allons ajouter à la classe GenIntList l'opérateur de sortie operator<<. Ayant déjà pris
connaissance de toutes les informations précédement fournies, est-ce que vous êtes dans l'obligation de
déclarer cet opérateur ami de la classe GenIntList? Expliquer votre réponse.


IFT1166 Hiver-2004 : Final 6/10

**Question 4 (24 points)** Soit le fragment de code suivant:
class Oiseau {
public:
virtual void Parle()=0;
virtual void MangePoisson() {cout << "cela dépend" << endl;}
};
class Pigeon : public Oiseau {
public:
virtual void Parle() {cout << "Coo, Coo" << endl;}
};
class Aigle : public Oiseau {
public:
virtual void Parle() {cout << "Squawk, Squawk" << endl;}
virtual void MangePoissons() {cout << "J'adore le poisson!" << endl;}
void MangePigeons() {cout << "Un succulent morceau!" << endl;}
};
class TeteBlancheAigle : public Aigle {
public:
virtual void Parle() {cout << "Je suis un spécimen en danger!" << endl;}
};

```
// Fonctions non membres:
void AigleParle(Aigle aig) { aig.Parle();}
void MangeurPoissons(Oiseau *oies) { Oies->MangePoissons();}
```
Le corps de la méthode **main** est constitué des blocs d'instructions des questions **Q4.1** à **Q4.8**. Indiquez
pour chaque bloc, s'il est correct ou pas (en cochant la bonne case), et dites pourquoi. Si le bloc est
incorrect, corrigez l'erreur. Un bloc est dit incorrect, si au moins une des instructions lui appartenant est
incorrecte. Par incorrect, nous entendons qu'une des instructions du bloc en question, génère une erreur lors
de la compilation et/ou lors d'exécution.

**4.1** Oiseau *b0 = new Oiseau;
b0->MangePoissons();
**Pourquoi?** (Courte explication)

**4.2** Oiseau *b1 = new Eagle;
b1->MangePoissons();
**Pourquoi?** (Courte explication)

**4.3** Oiseau *b2 = new Eagle;
b2->MangePigeons();
**Pourquoi?** (Courte explication)

**Correct** (^)
**Incorrect** (^)
**Correct
Incorrect
Correct
Incorrect** (^)


IFT1166 Hiver-2004 : Final 7/10

**4.4** Aigle e1;
TeteBlancheAigle be1;
a) be1 = e1;
**Pourquoi?** (Courte explication)

b) e1 = be1;
**Pourquoi?** (Courte explication)

**4.5** TeteBlancheAigle be2;
AigleParle(be2);
**Pourquoi?** (Courte explication)

**4.6** TeteBlancheAigle be3;
be3.MangePigeons();
**Pourquoi?** (Courte explication)

**4.7** TeteBlancheAigle be4;
MangeurPoissons(&be4);
**Pourquoi?** (Courte explication)

**4.8** TeteBlancheAigle *be5 = new TeteBlancheAigle;
Pigeon *p1;
p1 = be5;
**Pourquoi?** (Courte explication)

**Correct** (^)
**Incorrect** (^)
**Correct** (^)
**Incorrect** (^)
**Correct** (^)
**Incorrect** (^)
**Correct
Incorrect
Correct
Incorrect
Correct** (^)
**Incorrect**


IFT1166 Hiver-2004 : Final 8/10

**Question 5 (17.5 points)** Le but de cet exercice est d'écrire la fonction Encodage. Cette fonction
accepte deux arguments du type string. Le premier est le nom du fichier en entrée et le seconde le nom du
fichier en sortie. Le fichier en entrée se trouve donc sur disque et contient une série de ligne chacune d'elle
contient deux champs. Le premier champ est une chaîne de caractères ne contenant aucun espace blanc,
alors que le deuxième champ est représenté par un seul caractère. Voici un exemple du format de ce fichier
d’entrée:

```
Nous x
Allons r
envoyer l
un g
message z
secret p
```
La fonction Encodage réalise les opérations suivantes:

1. Ouvre le fichier fourni en entrée.
2. Ouvre le fichier fourni en sortie.
3. Lit chacune des lignes du fichier d'entrée.
4. Pour chaque ligne elle effectue l'opération **ou exclusif** du premier champ avec le second
champ. Le ou exclusif est représenté par l'opérateur **^**.
5. Elle écrit uniquement le résultat de cette opération (le codage donc du premier champ) dans le
fichier de sortie.

La fonction Encodage retourne un des 3 statuts suivants:

```
enum StatutEncodage { ErrOuvFicIn, ErrOuvFicOut, EncodageOK };
```
La fonction retourne donc ErrOuvFicIn si le fichier spécifié en entrée ne peut-être ouvert, ErrOuvFicOut si
le fichier spécifié en sortie ne peut-être ouvert et finalement EncodageOk si elle a réussi l'opération
d'encodage des données fournies dans le fichier d'entrée. La déclaration de l'énumérateur StatutEncodage se
trouve dans le fichier encode.h


IFT1166 Hiver-2004 : Final 9/10


IFT1166 Hiver-2004 : Final 10/10

**Question 6 (12.5 points)** Écrire un programme qui demande en entrée une série de mots tant qu'il n'a
pas rencontré le mot clé **Fin**. Il doit afficher par la suite en sortie que les 3 premiers mots, obtenus après
avoir trié l'entrée lue par ordre alphabétique croissant. Vous devez utiliser les conteneurs STL et les
algorithmes appropriés et cela sans oublier d'inclure les fichiers d'entête appropriés.

```
Bonnes vacances!
```

IFT1166 Automne-2003 : Final 1/11

## IFT1166 - Session Automne, Final

## Mohamed Lokbani

# IFT1166 - Final

Inscrivez tout de suite votre nom et code permanent.

Nom: __________________________________| Prénom(s): _____________________________|

Signature: ______________________________| Code perm: ____________________________|

Date : 13 décembre 2003

Durée: 2 heures 45 minutes (de 12h30 à 15h15) Local: N-515 du Pavillon Principal (P.P).

```
Ce document contient 11 pages.
```
# Directives:

- Toute documentation permise.
- Calculatrice **non** permise.
- Répondre directement sur le questionnaire.
- Les réponses **doivent être clairement présentées.**

### 1._____________________/20 (1.1 ; 1.2 ; 1.3 ; 1.4 ; 1.5)

### 2._____________________/17 (2.1)

### 3._____________________/15 (3.1)

### 4._____________________/20 (4.1 ; 4.2 ; 4.3)

### 5._____________________/28 (5.1 ; 5.2 ; 5.3 ; 5.4 ; 5.5 ; 5.6)

Total:__________________/100


```
IFT1166 Automne-2003 : Final 2/11
```
**Question 1 (20 points)**

```
1.1 Nommer deux types de fichiers qu'on peut utiliser lorsqu'on effectue des opérations d'entrées et de
sorties.
```
```
1.2 Quelle est l'opération la plus importante lorsqu'on a fini de lire ou d'écrire dans un fichier? Qu'arrive-t-
il si on omet cette opération?
```
**1.3** Soit l’entrée suivante sur cin (ce que vous allez taper sur le clavier):

(espace)
E
x
a
m
e
n
(espace)
F
i
n
a
l
(espace)
I
F
T
1
1
6
6
(return)

```
Tout en expliquant votre réponse, quel sera l'affichage en sortie après l'exécution des instructions suivantes:
```
```
char Phrase[25];
cin >> Phrase;
cout << Phrase;
```
**1.4** Tout en expliquant votre réponse, quel est l'effet de l'instruction suivante?

```
cout << setw(3) << setprecision(2) << 3.14159265358979 << endl;
```

IFT1166 Automne-2003 : Final 3/11

**1.5** Soient les déclarations suivantes:

```
class A {
private:
int prive_a;
protected:
int protege_a;
public:
int public_a;
```
```
};
```
```
class B : private A {
...............
};
```
```
class C : protected A {
...............
};
```
```
class D : public A {
...............
};
```
Tout en expliquant votre réponse, préciser les droits d'accès aux classes dérivées B, C et D de chacune des
données membres de la classe de base A.


IFT1166 Automne-2003 : Final 4/11

**Question 2 (17 points)** Le fichier NOTE.DAT contient les notes d’un étudiant. Chaque ligne compte 5
informations : le nom et le prénom de l’étudiant, sa note au quiz 1 sur 20 (pondération 25%), sa note au
quiz 2 sur 20 (pondération 25%) et sa note à l’examen final sur 20 (pondération 50%).

Écrire un programme qui demande à l’usager le nom du fichier de résultat et qui écrira dans celui-ci le nom
de l’étudiant suivi de sa moyenne sur 20.

Voici un exemple du fichier NOTE.DAT:

```
Michel Albert 14.7 15.6 14.9
```
```
Prénom
Max 20
caractères
```
```
espace Nom
Max 20
caractères
```
```
tabulation float tabulation float tabulation float
```
La moyenne de Michel est calculée comme suit :

```
Moy = 14.7x0.25 + 15.6x0.25 + 14.9x0.5 = 15.0
```
Le fichier de résultat qui doit être fourni par l’usager aura la forme suivante :

```
Michel Albert 15.0
```
```
Prénom
Max 20
caractères
```
```
espace Nom
Max 20
caractères
```
```
tabulation float
```

IFT1166 Automne-2003 : Final 5/11


IFT1166 Automne-2003 : Final 6/11

**Question 3 (15 points)** Soit les fragments d'un programme :

```
enum COULEUR {PIQUE, COEUR, CARREAU, TREFLE, INCONNUE};
```
```
class UneCarte {
public:
int m_valeur;
COULEUR m_couleur;
void initialise(int v = 0, COULEUR c = INCONNUE);
bool peutAllerSur(UneCarte uneAutre);
};
void UneCarte::initialise(int v, COULEUR c){
m_valeur = v;
m_couleur = c;
}
```
La fonction peutAllerSur() doit renvoyer une valeur booléenne indiquant si la carte au titre de laquelle elle
est invoquée peut être placée sur celle qui lui est transmise comme paramètre en respectant les règles
suivantes :

- une carte ne peut être placée sur une autre que si elles sont de la même COULEUR ;
- les cartes doivent s'empiler dans l'ordre de valeur croissant (pour simplifier, les valets, dames et rois
    sont respectivement représentés par des cartes de valeur 11, 12 et 13).

Le programmeur chargé de définir cette fonction a produit le code suivant :

```
bool UneCarte::peutAllerSur(UneCarte uneAutre){
```
```
if (uneAutre.m_couleur == m_couleur)
return true;
if (uneAutre.m_valeur == m_valeur – 1)
return true;
return false;
}
```
**3.1** Pouvez-vous corriger la logique de cette fonction de façon à ce qu'elle produise le résultat qu'on attend
d'elle?


IFT1166 Automne-2003 : Final 7/11

**Question 4 (20 points)** Soit la classe Test définie comme suit:

```
class Test {
public:
double valeur;
Test* ptr;
Test* suivant();
void pointeSur(T *arg);
};
```
**4.1** Comment peut-on définir la fonction pointeSur pour qu'elle stocke l'adresse qui lui est transmise
dans le membre ptr de l'instance au titre de laquelle elle est invoquée?

**4.2** Comment peut-on définir la fonction membre suivant pour qu'elle renvoie l'adresse contenue dans le
membre ptr de l'instance au titre de laquelle elle est invoquée?

**4.3** Ecrire un fragment de code qui crée un tableau de 100 instances de Test et utilise la fonction
pointeSur pour stocker dans le membre ptr de chacun des 99 premiers éléments du tableau l'adresse de
l'élément suivant (Le membre ptr du 100e élément pourrait recevoir une valeur nulle).


IFT1166 Automne-2003 : Final 8/11

**Question 5 (28 points)** Soit le fichier Exo5.cpp, qui est syntaxiquement correct:

```
#include <iostream>
```
```
using namespace std;
```
```
class Point {
float x,y;
```
```
public :
Point(float a=0, float b=0) {
x=a;
y=b;
cout << "contructeur 1 : "<< x <<","<< y <<"\n";
}
Point(Point & p){
x=p.x;
y=p.y;
cout << "contructeur 2 : "<< x <<","<< y <<"\n";
}
~Point(){
cout << "destructeur : "<< x <<","<< y <<"\n";
}
float getX() {
return x;
}
float getY() {
return y;
}
void setX(float z){
x=z;
}
void setY(float z){
y=z;
}
```
```
// Déplace le point à droite horizontalement d'une distance d
void deplacerADroite(float d) throw (float) {
if (d>=0) {
x=x+d;
}
else {
throw (d); // si d<0 il ne s'agit pas d'un déplacement à droite!
}
}
void afficher(){
cout << "(" <<x <<"," <<y <<")\n";
}
friend char * compareHauteur(Point,Point);
};
char * compareHauteur(Point a,Point b) {
if (a.y<b.y) {
return " le premier est plus bas \n";
}
else if (a.y>b.y){
return " le second est plus bas \n";
}
else {
return " les deux sont à la même hauteur \n";
}
}
```

IFT1166 Automne-2003 : Final 9/11

**5.1** À quoi servent les fonctions getX , getY, setX et setY?

**5.2** A quoi servent les fonction membres **Point(Point & p)** et **~Point()**? Sont-elles nécessaires dans
le cas de la classe Point? Pourquoi?

**5.3** Que signifie le mot clé **friend** devant le prototype de la fonction **compareHauteur**? À quoi cela
sert-il?


IFT1166 Automne-2003 : Final 10/11

**5.4** On considère la classe Polygone suivante (un polygone est caractérisé par son nombre de sommets et
par ses sommets, stockés dans un tableau). On utilise la classe Point définie précédemment et l'on suppose
que les deux classes sont définies dans un même fichier.

```
class Polygone {
int nb; // nombre de sommets
Point* somt; //tableau des sommets
public :
Polygone(int n=0){
nb=n;
somt=new Point[nb];
}
void afficher(){
for (int i=0;i<nb;i++) {
somt[i].afficher();
}
}
};
```
Dites ce qui s'affiche à la suite des deux instructions suivantes :

```
Polygone triangle(3);
triangle.afficher();
```

IFT1166 Automne-2003 : Final 11/11

**5.5** Ecrivez la surcharge de l'opérateur d'indexation [ ] qui retourne le ième Point du polygone. Cet
opérateur lèvera une exception du type entier qui renverra l'indice demandé quand celui-ci n'est pas valide
(i.e. est négatif ou supérieur au nombre de sommets).

**5.6** Définir la méthode input membre de la classe Polygone qui permet de mettre à jour les abscisses (X)
et les ordonnées (Y) des différents sommets de ce polygone.

**BONNES FÊTES!**


IFT1166 Hiver-2001 : Final Page 1 sur 12

IFT1166 - Session Hiver 2001, Final

Mohamed Lokbani

Nom:___________________________________| Prénom(s):_____________________________|

Signature:_______________________________| Code perm:_____________________________|

Date: 21 avril 2001

Durée: 3 heures (de 13h30 à 16h30) Local: Z-210

Directives:

- Toute documentation permise.
- Calculatrice et ordinateur personnel prohibés.
- Répondre directement sur le questionnaire.

```
Bon courage!
```
Exercices
Questions

1._____________________/16 A ~ B ~ C ~ D

2._____________________/14 A

3._____________________/16 A

4._____________________/10 A ~ B

5._____________________/24 A ~ B~ C~ D

### 6._____________________/20 A


IFT1166 Hiver-2001 : Final Page 2 sur 12

Question 1 (16 points)

Soit la classe Test suivante :

```
#include <iostream.h>
#include <string>
```
```
class Test {
int zz;
string mm;
Test(const Test& x) {};
```
```
public:
Test(int yy, string hh):zz(yy),mm(hh){}
~Test() {}
Test& operator=(Test& x) {
zz = x.zz;
mm = x.mm;
return x;
}
};
```
Q1.A- La classe Test doit-elle redéfinir le constructeur de recopie et l’opérateur d’affectation, où
bien ceux par défaut, fournis par le langage, sont suffisants? OUI/NON et Pourquoi?

Q1.B- Quelles sont les fonctions membres de la classe Test, qui seront appelées dans la
fonction suivante :

```
int main() {
Test dd(5,"essai"),XX(8,"unautre");
XX = dd;
return 0;
}
```
Nommer les fonctions (méthodes) et expliquer pourquoi?


IFT1166 Hiver-2001 : Final Page 3 sur 12

Q1.C- En vous basant sur la définition de la classe Test, la fonction suivante est-elle
syntaxiquement correcte? OUI/NON et Pourquoi?

```
int main() {
Test dd(45,"encore");
Test qsx(dd);
return 0;
}
```
Q1.D- La définition de l'opérateur d'affectation de la classe Test est-elle correcte? OUI/NON et
Pourquoi?

Dans le cas où vous répondez par NON (écriture incorrecte), réécrivez l'opérateur d'affectation de
la classe Test.


IFT1166 Hiver-2001 : Final Page 4 sur 12

Question 2 (14 points)

Compléter la classe suivante :

```
#include <iostream.h>
#include <string>
```
```
class String {
char* s;
int len;
```
```
public:
// déjà fournies donc à ne pas écrire
int get_taille(); // retourne la taille
```
```
String(); // initilise à zéro/NULL les éléments de String.
String(const char*);
~String();
String(const String&);
String& operator=(const String&);
void affiche(); // affiche les éléments de String
```
```
// deux opérateurs non fournis qu'il faudra écrire (définir).
/*
operator+=(const String& A);
```
```
operator+(const String& A, const String& B);
*/
```
```
};
```
Écrivez la définition des opérateurs += et + pour que :

```
String Z, X("to"), B("to"); // des objets
X+=B; // <= Pour permettre cette opération
X.affiche(); // en sortie : toto
```
```
Z = X+B; // <= Pour permettre cette opération
Z.affiche(); // en sortie : toto
```

IFT1166 Hiver-2001 : Final Page 5 sur 12


IFT1166 Hiver-2001 : Final Page 6 sur 12

Question 3 (16 points)

Tout en justifiant votre réponse, a jouter les lignes manquantes nécessaires pour que le
programme suivant puisse s’exécuter correctement.

1 2 3 4 5 6 7 8 9

10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27

```
#include <iostream.h>
```
```
class Uneautre {
int elt;
public:
Uneautre(int i):elt(i) {}
void affiche(Idem x) {
cout << elt << " " << x.elt << endl;
}
};
```
```
class Idem{
int elt;
public:
Idem(int i):elt(i) {}
void affiche(Uneautre y) {
cout << elt << " " << y.elt << endl;
}
};
```
```
int main() {
```
```
Idem zz(55);
Uneautre ww(66);
```
```
zz.affiche(ww);
ww.affiche(zz);
```
```
return 0;
}
```
Forme de réponse : entre les lignes? et? il faudra ajouter ... parce que ...


IFT1166 Hiver-2001 : Final Page 7 sur 12

Question 4 (10 points)

Q4.A- Écrire une fonction générique (template) qui accepte deux arguments du type T et qui
retourne un booléen qui prend la valeur:

- vraie si le premier argument est différent du second,
- faux dans le cas contraire.

Q4.B- Cette fonction générique permet-elle de traiter correctement le cas où T est du type char*?
(OUI/NON et pourquoi?)

Dans le cas où vous répondez par NON (ne peut pas traiter correctement le type char*), écrivez
une fonction spécifiquement pour ce cas.


IFT1166 Hiver-2001 : Final Page 8 sur 12

Question 5 (24 points)

Q5.A- Écrire la déclaration d’une classe D qui dérive par héritage public de la classe de base B.

Q5.B- Si une classe D, dérive par héritage public de la classe de base C, est créée puis plus tard

détruite, quel est l’ordre d’appel des constructeurs et des destructeurs des classes D et C?

Q5.C- Soit la classe de base Produit et la classe ProduitSolde qui dérive par héritage public
de la classe de base.
La classe Produit contient les membres données suivants : nom (string) et prix (double).
La classe ProduitSolde contient le pourcentage du solde : solde (double) par exemple
10(%), 20(%) etc.

Écrire les classes Produit et ProduitSolde en respectant les critères suivant :

- principe d’encapsulation des données,
- la classe dérivée doit accéder à tous les membres de la classe de base,
- les classes de base et dérivée doivent contenir au moins les méthodes suivantes :
    facture : retourne le nom du produit et son prix,
    get_prix : retourne le prix du produit (soldé dans le cas de la classe dérivée),
    les constructeurs nécessaires pour initialiser les membres données.


IFT1166 Hiver-2001 : Final Page 9 sur 12


IFT1166 Hiver-2001 : Final Page 10 sur 12

Q5.D- Comment faudrait-il modifier le contenu des classes de base ( Produit) et dérivée
(ProduitSolde), pour que la foncti on main suivante puisse donner l es résultats en
commentaires.

```
int main(){
```
```
Produit P("portable",2000);
ProduitSolde PS("portable",2000,20);
```
```
Produit* PP = &P;
PP->facture(); // résultat attendu: 2000
PP = &PS;
PP->facture(); // résultat attendu: 1600
```
```
return 0;
}
```

IFT1166 Hiver-2001 : Final Page 11 sur 12

Question 6 (20 points)

Soit le conteneur list de la STL, contenant les noms de 3 fichiers (string) "t1.txt",
"t2.txt" et "t3.txt".

Écrire un programme qui permet de réaliser ce qui suit:

- compter le nombre de caractères dans chacun des fichiers du conteneur list.
- si un des fichiers du conteneur list est inexistant, un message d’erreur devra s’afficher à
    l’écran. Par exemple, si "t1.txt" n’existe pas:

```
"impossible d’ouvrir le fichier: t1.txt"
```
```
et par la suite, le programme devra poursuivre le traitement des autres fichiers.
```
- le résultat doit être écrit dans le fichier "sortie.txt" sous le format suivant:

```
Nombre de fichiers dans le conteneur list: 3
Nombre de fichiers inexistants : 1
Nombre total de caractères: 810
```
```
Nom de fichier : Nombre de caractères
t1.txt : -1
t2.txt : 560
t3.txt : 250
```
où –1, 560 et 250 r eprésentent respectivement le nombre de caractères dans les fichiers

"t1.txt" ; "t2.txt" et "t3.txt". Pour un fichier inexistant (dans cet exemple
"t1.txt"), il lui est associé la valeur –1. 810 étant la somme de 560 et 250.


IFT1166 Hiver-2001 : Final Page 12 sur 12


IFT1166 Automne-2K : Final Page 1 sur 6

IFT1166 - Session Automne 2000, Final

Mohamed Lokbani

Date: 20 décembre 2000 Durée: 3 heures (de 18h30 à 21h30) Local: Z-210

Directives:

- Toute documentation permise.
- Calculatrice et ordinateurs personnels prohibés.

L'examen compte: 6 pages (incluant celle-ci) et 5 exercices.

```
Bon courage!
```
Question 1 (15 points)

Que va afficher le programme suivant en sortie suite à cet appel (supposé que la version
executable du programme se nomme prg):

./prg test chaine

#include <iostream.h>

void une_certaine_fonction(char* arg1,char* arg2){
cout << "arg1: "<< arg1 << " ; arg2: " << arg2 << endl;
}
int main(int argc, char* argv[]) {

```
if (argc < 3) {
cerr << "Manque un ou plusieurs arguments" << endl;
cerr << "Commande: ./prg arg1 arg2" << endl;
exit(1);
}
une_certaine_fonction(argv[1],argv[2]);
```
return 0;
}


IFT1166 Automne-2K : Final Page 2 sur 6

Question 2 (15 points)
En tenant compte de la fonction main suivante, écrire la fonction générique conversion qui
permet de convertir un caractère (char) en un entier (int), convertir un réel (double) en un

entier (int) et convertir un entier (int) en un réel (double).

int main() {

```
char c = 'A';
int e;
```
```
conversion(c,e);
cout << c <<";"<<e<<endl; // devrait afficher:A;65
```
```
double d=4.15;
```
```
conversion(d,e);
cout << d <<";"<<e<<endl; // devrait afficher: 4.15 ; 4
```
```
conversion(e,d);
cout << d <<";"<<e<<endl; // devrait afficher:4;4
```
```
return 0;
```
}

Question 3 (20 points)

Soit la classe suivante:

class Chaine{
char* nom;
int taille;
public:
// supposez que les 4 fonctionnalités suivantes sont disponibles
Chaine(char*);
Chaine(const Chaine&);
Chaine& operator=(const Chaine&);
ostream& operator<<(ostream& out,const Chaine&);
};

Complétez la classe Chaine par les opérateurs suivants:

operator+=(char): pour ajouter un caractère à la fin du membre de la classe Chaine: nom. Par exemple si
l'objet x, instance de la classe Chaine, contient au départ la chaîne test alors:

```
x+=('e');
cout << x;
```
affichera teste en sortie.

operator-=(int): pour retirer un certain nombre de caractères de la fin du membre de la classe Chaine:
nom. Par exemple si l'objet x, instance de la classe Chaine, contient au départ la chaîne teste alors:

```
x-=(2);
cout << x;
```
affichera tes en sortie.


IFT1166 Automne-2K : Final Page 3 sur 6

Question 4 (15 points)

En utilisant uniquement les 4 fonctions append, assign, sort et reverse de la STL et de la
classe string ; écrivez un programme qui en acceptant les deux chaînes de caractères suivantes

(type string):

"Les tableaux de Monet seront exposés à partir de la semaine
prochaine."

"Les meilleurs livres sont ceux qui racontent ce que l'on sait déjà."

D'abord crée la phrase suivante (du type string):

"Les meilleurs livres seront exposés à partir de la semaine prochaine."

puis à partir de cette phrase génère les deux phrases suivantes (du type string):

".eniahcorp eniames al ed ritrap à sésopxe tnores servil sruelliem seL"

"àé .Laaaacdeeeeeeeeeehiiiiillllmmnnnoooppprrrrrrsssssssttuvx"

Note:

Vous ne devez pas utiliser les structures de contrôle (if, for, while, do/while etc.) ni les itérateurs.


IFT1166 Automne-2K : Final Page 4 sur 6

Question 5 (35 points)

On définit une hiérarchie de formes géométriques comportant le cercle, le triangle, et le carré.
Chaque forme est représentée dans le plan par ses coordonnées (x,y). Pour chaque forme on veut
connaître son périmètre et sa surface.

forme périmètre surface
cercle 2 * 3.14 * rayon 3.14 * rayon * rayon
rectangle 2 * (largueur + longueur) largueur * longueur
carré 4 * coté coté * coté

Q5.A Écrire les classes nécessaires à l'implémentation de la hiérarchie suivante: La classe
Cercle dérive publiquement de la classe Forme, la classe Rectangle dérive publiquement de la
classe Forme, et finalement la classe Carre dérive publiquement de la classe Rectangle ; en
vous basant pour cela de la fonction main ci-jointe ainsi que du résultat obtenu après exécution du
programme.

Exemple

Soit la déclaration suivant: Cercle cercle(10,10,4); cercle est un objet dont les
cordonnées dans le plan sont (10,10), son rayon est 4, son périmètre est égal à 25.12 (2*3.14*4) et
sa surface est égale à 50.24 (3.14*4*4).

Fonction principale main

int main() {

```
Cercle cercle(10,10,4);
cout << endl << cercle << " surface=" << cercle.surface() << endl;
cout << cercle << " perimetre=" << cercle.perimetre() << endl <<
endl;
```
```
Rectangle rectangle(30,30,2,5);
cout << rectangle << " surface=" << rectangle.surface() << endl;
cout << rectangle << " perimetre=" << rectangle.perimetre() << endl
<< endl;
```
```
Carre carre(100,100,2);
cout << carre << " surface=" << carre.surface() << endl;
cout << carre << " perimetre=" << carre.perimetre() << endl << endl;
```
return 0;
}

Sortie après exécution du programme

Cercle (10,10) r=4 surface=50.24
Cercle (10,10) r=4 perimetre=25.12

Rectangle (30,30) Longueur=2 Largeur= 5 surface=10
Rectangle (30,30) Longueur=2 Largeur= 5 perimetre=14

Carre (100,100) Cote=2 surface=4
Carre (100,100) Cote=2 perimetre=8


```
IFT1166 Automne-2K : Final Page 5 sur 6
```
```
Q5.B Modifiez le contenu des classes précédemment définies pour tenir compte de la fonction main
suivante, qu'il faudra compléter, et de la sortie obtenue (voir page suivante) suite à l'exécution du
programme.
```
```
Chaque méthode nécessitant des modifications doit être réécrite complètement.
```
```
int main() {
```
```
Cercle cercle(10,10,4);
cout << endl << cercle << " surface=" << cercle.surface() << endl;
```
```
Rectangle rectangle(30,30,2,5);
cout << endl << rectangle << " surface=" <<\
rectangle.surface() << endl;
```
```
// à faire: allocation dynamique d'un carré(100,100,2):
............................................................................................................................................................
```
```
cout << endl << *carre << " surface=" << carre->surface() << endl;
```
```
.................................... tab[3]; // déclaration du tableau tab à compléter
// devant contenir ce qui suit:
```
```
tab[0] = &cercle;
tab[1] = &rectangle;
tab[2] = carre;
```
```
float surf=0.0;
```
```
for (int i=0; i<3; i++) {
```
```
// à faire: surf calcule la somme totale des surfaces
```
```
surf += ............................................................................................................................................................;
```
```
}
cout << endl << "surface totale:"<<surf << endl << endl;
cout << "périmètre d'une forme tirée au hasard" << endl;
```
```
srand((unsigned int) time(NULL));
```
```
// à faire: définition de ptr: un pointeur qui pointe un des
// éléments du tableau tab. L'élément est choisi au hasard.
................................................ ptr = tab[rand()%3];
```
```
// à faire: compléter les deux champs, basez-vous pour cela sur
// l'affichage en sortie (voir plus bas).
```
```
cout << ..............................................................................<< " : périmètre="\
<< .................................................................. << endl << endl;
```
```
cout << "destruction de carré alloué dynamiquement" << endl;
```
```
ptr = carre;
delete ptr;
cout << endl;
```
```
return 0;
```
```
}
```
2

3

6

5

4

1


IFT1166 Automne-2K : Final Page 6 sur 6

Sortie Q5.B après exécution du programme

- Forme::Forme -- Cercle::Cercle -
Cercle (10,10) r=4 surface=50.24
- Forme::Forme -- Rectangle::Rectangle -
Rectangle (30,30) Longueur=2 Largeur= 5 surface=10
- Forme::Forme -- Rectangle::Rectangle -- Carre::Carre -
Carre (100,100) Cote=2 surface=4

surface totale : 64.24

périmètre d'une forme tirée au hasard
Rectangle (30,30) Longueur=2 Largeur= 5 : périmètre=14

destruction de carré alloué dynamiquement

- Carre::~Carre -- Rectangle::~Rectangle -- Forme::~Forme -
- Rectangle::~Rectangle -- Forme::~Forme -
- Cercle::~Cercle -- Forme::~Forme -

Q5.C Dans votre réponse à la question précédente (Q5.B) était-il nécessaire d'utiliser le
polymorphisme? Expliquez.

-------------------------------------- Fin de l'examen -------------------------------------------------


IFT1166 Été-2K : Final Page 1 sur 16

IFT1166 - Session Été 2000, Final

Mohamed Lokbani

Nom:___________________________________| Prénom(s):_____________________________|

Signature:_______________________________| Code perm:_____________________________|

Date: 27 juin 2000

Durée: 3 heures (de 18h30 à 21h30) Local: P-310

Directives:

- Toute documentation permise.
- Calculatrice et ordinateurs personnels prohibés.
- Répondre directement sur le questionnaire.

```
Bon courage!
```
### 1._____________________/15 Q1

2._____________________/15 Q2: Er1, Er2, Er3, Er4, Er5

3._____________________/20 Q3: li1, li2, li3, li4, li5

4._____________________/30 Q4: 4.1, 4.2, 4.3, 4.4

5._____________________/20 Q5

Total:__________________/100

Bonus._________________/10 B


IFT1166 Été-2K : Final Page 2 sur 16

Question 1 (15 points)

Soit le programme suivant, qui compile et s'exécute correctement:

// début
#include <iostream.h>
void transfert(ifstream *entree,ofstream *sortie){
char ch;
bool flag = false;
while (entree->get(ch)) {
if(ch==''&&!flag) {
flag = true;
*sortie << ch;
} else if (ch != ' ') {
flag = false;
*sortie << ch;
}
}
}
int main() {
ifstream ficentree("entree.txt");
ofstream ficsortie("sortie.txt");

```
transfert(&ficentree,&ficsortie);
```
return 0;
}
// fin

Tout en développant votre réponse sur la feuille d'examen, indiquez ce que va contenir le fichier
sortie.txt après exécution du programme précédent, si le fichier entree.txt contient:

Deux+équipesdefootball,composéeschacunedeonzevachesportantdos
sardnumérotéettrottinantsurunfauxprédecouleurorangesituéle
longdel'autorouteentreAmsterdametUtrecht,ontprovoquéun
embouteillagedeplusdedouzekilomètresmardi.

Note:  représente un espace blanc.  représente une fin de ligne. Ils doivent être représentés dans votre
réponse, si nécessaire.


IFT1166 Été-2K : Final Page 3 sur 16

Question 2 (15 points)

Soit le programme suivant:

// début
1) #include <iostream.h>

2) class Droite {
3) Coordonnee gauche; // extrémité gauche
4) Coordonnee droite; // extrémité droite
5) public:
6) Droite(int gx,int gy,int dy):gauche(gx,gy),droite(dx,dy){}
7) Droite(const Droite& d)gauche(d.gauche),droite(d.droite) {}
8) bool operator==(const Droite& d2){
9) if ((gauche==d2.gauche) && (droite==d2.droite))
10) return true;
11) return false;
12) }
13) };
14) class Coordonnee {
15) int x;
16) int y;
17) public:
18) Coordonnee(int a, int b): x(a);y(b){}
19) Coordonnee(const Coordonnee& c) {
20) x = c->x; y = c->y;
21) }
22) bool operator==(const Coordonnee& c) {
23) if ((x==c.x) && (y==c.y)) return true;
24) return false;
25) }
26) };
27) int main() {
28) Droite d1(2,3,4,5);
29) Droite d2(7,8,9,10);
30) Droite d3(d1);
31) cout << (d1==d3) << (d2==d3) << (d1==d2) << endl;
32) return 0;
33) }
// fin

Le programme contient 5 erreurs de syntaxe. Indiquez les et indiquez la correction qu'il faudra apporter. À
signaler les numéro de lignes ne font pas partie du programme, elles sont la à titre indicatif. Des erreurs sur
une même ligne compte pour une seule erreur.

Erreur 1:


IFT1166 Été-2K : Final Page 4 sur 16

Erreur 2:

Erreur 3:

Erreur 4:

Erreur 5:


IFT1166 Été-2K : Final Page 5 sur 16

Question 3 (20 points)

Soit le programme suivant, qui compile et s'exécute correctement:

// début
#include <iostream.h>

template <class T> T fonction(int a,T* b) {
cout << "template 1\n";
return b[0];
}
template <class T> T fonction(T a,T b) {
cout << "template 2\n";
return a;
}
double fonction(int a,char* b) {
cout << "fonction 1\n";
return a;
}
double fonction(double a,double b) {
double x=4.5;
cout << "fonction 2\n";
return x;
}
int main() {
char c;
char chaine[20];
unsigned int tab[20];
int a;
double i,j;

```
fonction(i,j); // ligne -0-
fonction(a,&c); //ligne -1-
```
```
a = fonction(tab[0],tab[1]); //ligne -2-
```
```
fonction(tab[0],c); //ligne -3-
```
```
fonction(c,tab); //ligne -4-
```
```
fonction(c,chaine); //ligne -5-
```
return 0;
}
// fin

Le compilateur va associer à chaque fonction appelée entre les lignes 0 et 5, une fonction classique ou une
fonction instanciée à partir d'une fonction générique. À titre d'exemple, pour la ligne 0, la fonction prise en
considération sera celle qui affichera en sortie "fonction 2":

ligne -0- fonction(i,j);
Résultat affiché: fonction 2
Pourquoi? blablabla ...

En suivant le même principe, complétez ce qui suit:


IFT1166 Été-2K : Final Page 6 sur 16

ligne -1- fonction(a,&c);
Résultat affiché:
Pourquoi?

ligne -2- a = fonction(tab[0],tab[1]);
Résultat affiché:
Pourquoi?

ligne -3- fonction(tab[0],c);
Résultat affiché:
Pourquoi?

ligne -4- fonction(c,tab);
Résultat affiché:
Pourquoi?

ligne -5- fonction(c,chaine);
Résultat affiché:
Pourquoi?


IFT1166 Été-2K : Final Page 7 sur 16

Question 4 (30 points)

Dans cette exercice vous allez programmer une représentation d'un carnet d'adresses postales. Une adresse
postale, peut avoir différents formats ; par exemple, pour un envoi international du Canada vers les USA,
nous devons préciser le pays receveur de la lettre (ici USA) alors que pour un envoi à l'intérieur du Canada
cela n'est pas nécessaire. Le format d'écriture de l'adresse est, quant à lui, dépendant du pays expéditeur.
Une représentation simplifiée de ce format est comme suit:

```
à partir des USA à partir du Canada
```
```
Nom de la personne
Numéro et le nom de la rue
Ville, État, et Code postal
{Pays}
```
```
Nom de la personne
Numéro et le nom de la rue
Ville
{Pays}
Code postal
```
```
tableau -1-
```
Les { } indiquant un affichage optionnel: i.e. le pays ne sera pas nécessairement affiché pour un envoi
interne.

Techniquement, ce carnet sera représenté par 4 classes, comme le montre le schéma d'héritage suivant:

```
figure -1-
```
Q4.1 Définir la classe abstraite Adresse qui contient parmi ses membres les 3 fonctions virtuelles pures
et publiques suivantes:

- type: sans argument, et qui retourne une chaîne de caractères spécifiant le type d'adresse auquel nous
avons affaire (adresse postale, adresse courriel etc.).
- affiche: accepte un argument du type int et ne retourne rien. L'argument permet de spécifier si on a
affaire à un envoi international, si c'est le cas, le pays destinataire sera affiché. Par défaut cet argument
prendra la valeur 0, pour signifier que c'est un envoi intérieur. Cette fonction sert à afficher l'adresse postale
comme indiqué dans le tableau -1-.
- saisir: sans argument et qui ne retourne aucune valeur. Cette fonction permet de saisir des données du
clavier.

```
Adresse
```
```
Adresse Postale
```
```
AdresseUSA AdresseCanada
```
```
classe asbtraite
```

IFT1166 Été-2K : Final Page 8 sur 16

Q4.2 Définir la classe AdressePostale qui dérive publiquement de la classe Adresse, et qui doit respecter
les contraintes suivantes:

- le principe d'encapsulation des données doit être respecté.
- le constructeur doit être accessible que par les classes dérivées.
- AdressePostale doit contenir les membres données suivants:

```
char* nom; // nom de la personne char* rue; // nom de la rue
char* numero; // numéro de la maison char* ville; // nom de la ville
char* codepostale; // le code postale char* pays; // nom du pays
```
- pour chaque membre donnée, vous devez définir deux méthodes:

```
saisir: accepte un argument du type chaîne de caractères et ne retourne rien. Cette fonction
permet de passer l'information au membre donnée. À titre d'exemple pour le membre donnée nom,
cette fonction portera le nom de: saisirnom (pour numero: saisirnumero etc.). Au total
vous devez écrire 6 fonctions "saisir". Lors de la correction, il sera tenu compte de l'optimisation de
votre code.
```
```
affiche: sans argument ne retourne rien. Cette fonction permet d'afficher l'information sur le
membre donnée concerné. À titre d'exemple pour le membre donnée nom, cette fonction portera le
nom de: affichenom (pour numero: affichenumero etc.). Au total vous devez écrire 6
fonctions "affiche".
```
- la définition de la fonction type, décrite en Q4.1.


IFT1166 Été-2K : Final Page 9 sur 16


IFT1166 Été-2K : Final Page 10 sur 16


IFT1166 Été-2K : Final Page 11 sur 16

De la classe AdressePostale vont dériver deux classes: AdresseCanada et AdresseUSA (voir
figure -1-, à la page 8).

Q4.3. Écrire la définition de la classe AdresseUSA. Parmi ses fonctions membres, les fonctions:
affiche et saisir décrites en Q4.1 et en tableau -1- et que vous devez définir à ce niveau.


IFT1166 Été-2K : Final Page 12 sur 16

Q4.4. Écrire la définition de la classe AdresseCanada. Parmi ses fonctions membres, les fonctions:
affiche et saisir décrites en Q4.1 et en tableau -1- et que vous devez définir à ce niveau.


IFT1166 Été-2K : Final Page 13 sur 16

Question 5 (20 points)

En utilisant les STL, écrire un programme qui manipule un vecteur d'entiers. Votre programme doit:

* déclarer le tableau suivant:

int tab[] = {1,2,3,4,5,6,7,8,9,10};

* définir ce qui suit:

- 2 fonctions globales:
    carre: elle permet de calculer le carré d'un entier passé par référence, et retourne le résultat.
    affiche elle permet d'afficher sur la sortie standard un entier, passé en argument.
- une classe:
    additionne: suite à son appel à travers l'opérateur d'appel de fonction (), elle modifie la valeur
    d'un entier en lui additionnant le carré d'une valeur entière donnée (par défaut égale à 10), passée en
    paramètre. Le carré de cette valeur est calculé en utilisant la fonction carre précédemment définie.
- la fonction principale:
    main: elle utilise la classe et les fonctions globales pour manipuler le tableau tab, en s'aidant dans
    cette tache de la batterie d'algorithmes définis dans les STL.

* afficher en sortie, après l'avoir exécuté, le résultat suivant:

Carré des 10 premiers entiers:149162536496481100
Additionne le carré de 100 à chaque élément du tableau:
10001 10004 10009 10016 10025 10036 10049 10064 10081 10100
Additionne le carré de la valeur par défaut à chaque élément du tableau:
10101 10104 10109 10116 10125 10136 10149 10164 10181 10200

Dans cet exercice, il vous est interdit d'utiliser les structures de contrôle suivantes: if, while, for,
do/while, swtich/case, break, continue.


IFT1166 Été-2K : Final Page 14 sur 16


IFT1166 Été-2K : Final Page 15 sur 16

Bonus (10 points)

Par de simples opérations mathématiques sur des entiers non signés (unsigned int), vous allez définir les
outils nécessaires pour lever les exception: overflow et underflow.

- Ces exceptions vont agir sur les 3 fonctions mathématiques suivantes:
    add: additionne deux entiers non signés passés en argument (i.e. a+b), et retourne le résultat de
       l'opération. Cette fonction peut lever que l'exception du type overflow si le résultat de l'opération
       d'addition est inférieur au premier argument (i.e. a) ou bien au second argument (i.e. b).
    sous: soustrait deux entiers non signés passés en argument (i.e. a-b), et retourne le résultat de
       l'opération. Cette fonction peut lever que l'exception du type underflow si le résultat de l'opération
       d'addition est supérieur au premier argument (i.e. a).
    calc: calcul une simple opération mathématique (i.e. a+(b-c)) en utilisant 3 entiers non signés
       passés en argument, et retourne le résultat. Cette opération mathématique est calculée en utilisant
       pour cela les fonctions préalablement citées (add et sous). Cette fonction lèvera les deux types
       d'exception précédemment définies: overflow et underflow.
- Chaque exception sera représentée par une structure, ayant les deux membres suivants:
    fonctmath: nom de la fonction mathématique qui a levé l'exception (ex. add, sous, ou calc).
    msgexp: message signalant que l'exception (son nom) a été levée par la fonction mathématique (son
       nom), ex.: "overflow dans add", "underflow dans sous".

Vote tache consiste à définir l'ensemble des fonctions et des structures précédemment décrites et complétez
la fonction main suivante:

```
int main() {
unsigned int a=23,b=34,c=45;
try {
unsigned int resultat = calc(a,b,c);
cout << "le résultat est: " << resultat << endl;
return 0;
}
// à compléter par vous ...
```
```
}
```

IFT1166 Été-2K : Final Page 16 sur 16


IFT1166 H-2K : Final Page 1 sur 13

IFT1166 - Session Hiver 2000, Final

Mohamed Lokbani

Nom:___________________________________| Prénom(s):_____________________________|

Signature:_______________________________| Code perm:_____________________________|

Date:19 avril 2000

Durée: 3 heures (de 18h30 à 21h30) Local: B-2285

Directives:

- Il vous est permis d'utiliser un livre de votre choix.
- Les documents de cours ne sont pas autorisés (y compris mes e-notes disponibles sur la page web
    du cours ou à la bibliothèque Math/Info).
- Ordinateurs personnels prohibés.
- Calculatrice (simple) permise.
- Répondre directement sur le questionnaire.

```
Bon courage!
```
1._____________________/15

2._____________________/10

3._____________________/20

4._____________________/15

5._____________________/20

6._____________________/20

Total:__________________/100

Bonus._________________/10


IFT1166 H-2K : Final Page 2 sur 13

Question 1 (15 points)

La fonction remplir(...), lit des entiers d'un fichier et les range dans un tableau d'entiers. La
fonction remplir() a 3 arguments:

1. un stream ouvert en lecture,
2. un tableau d'entiers,
3. un entier indiquant le nombre d'éléments lus.

Supposez que le code suivant a été exécuté avec succès:

```
const int max = 100; // le nombre maximal d'éléments
int item[max]; // le tableau des éléments
int nb_item = 0; // le nombre d'éléments
char NomFic[80]; // le nom de fichier
cin >> NomFic; // lecture du nom de fichier
ifstream in(NomFic); // flux en entrée associé au fichier NomFic
```
Lequel des appels suivants est correct? et pourquoi? (vous pouvez choisir une ou plusieurs
réponses).

Q1.A- remplir(in, item[], nb_item);

vrai faux

pourquoi?

Q1.B- remplir(NomFic, item[], nb_item);

vrai faux

pourquoi?

Q1.C- remplir(in, item, nb_item);

vrai faux

pourquoi?


IFT1166 H-2K : Final Page 3 sur 13

Q1.D- remplir(ifstream, item, nb_item);

vrai faux

pourquoi?

Q1.E- remplir(NomFic, item, max);

vrai faux

pourquoi?

Question 2 (10 points)

Étant donné la fonction:

float RacineCarree(float w)
{
// calcule la racine carrée avec sqrt, et retourne le résultat.
}
Écrire le prototype de la fonction générique (Template) RacineCarree permettant de traiter les
combinaisons suivantes:

```
Type en Argument Type de retour
int
int
float
float
float
double
```
```
int
float
int
float
double
float
```

IFT1166 H-2K : Final Page 4 sur 13

Question 3 (20 points)

Soit le programme suivant:

```
#include <iostream.h>
```
```
class X {
public:
X() {a = 0;}
X(int valeur):a(valeur) {}
X(const X& zz) {a = zz.a;}
X& operator=(const X& zz) {
if (this!=&zz) {
a = zz.a;
}
return *this;
}
void Print() const {
cout << a << endl;
}
private:
int a;
};
```
```
int main() {
```
```
X v,w(1985); // ligne: 1
```
```
v.Print(); // ligne: 2
w.Print(); // ligne: 3
```
```
X *pa = new X(v); // ligne: 4
pa->Print(); // ligne: 5
```
```
X *pb = new X(1949); // ligne: 6
pb->Print(); // ligne: 7
```
```
v = w; // ligne: 8
v.Print(); // ligne: 9
```
```
pa = pb; // ligne: 10
pa->Print(); // ligne: 11
```
```
*pb = 2010; // ligne: 12
pb->Print(); // ligne: 13
```
```
return 0; // ligne: 14
```
```
}
```

IFT1166 H-2K : Final Page 5 sur 13

Q3.A- Donner les lignes de la fonction main où sont appelées les fonctions membres de la classe
X, en indiquant à chaque fois le nom de l'objet crée (ou receveur). (Si plusieurs objets sont créés
pour une même ligne, indiquez-les tous).

```
ligne 1 ligne 4 ligne 6 ligne 8 ligne 10 ligne 12
```
```
X::X()
```
```
X::X(int)
```
```
X::X(const X&)
```
```
X::operator=(const X&)
```
Q3.B- Donner les résultats obtenus en sortie après l'appel des lignes suivantes, de la fonction
main:

```
ligne 2 ligne 3 ligne 5 ligne 7 ligne 9 ligne 11 ligne 13
```
sortie

Soit H le nom de l'objet crée à la ligne 4. Sur cette même ligne (4), H est accessible par le pointeur

pa. Après avoir exécuté la ligne 10, et avant d'avoir exécuté la ligne 11:

Q3.C.1- H existe toujours mais n'est plus accessible?

vrai faux

pourquoi?

Q3.C.2- H existe et H.a a pris la valeur 2010?

vrai faux

pourquoi?


IFT1166 H-2K : Final Page 6 sur 13

Question 4 (15 points)

Soit la classe générique (Template) suivante:

```
template<class Type1, class Type2>
class ClasseBase
{
protected:
Type1 Champ1;
Type2 Champ2;
public:
ClasseBase() {}
ClasseBase(Type1 arg1, Type2 arg2) :
Champ1(arg1), Champ2(arg2) {}
virtual void Print()
{ cout << Champ1 <<''<<Champ2 << endl; }
};
```
Q5.A- En fonction de la précédente définition de la classe template
ClasseBase<Type1,Type2>, citez au moins un type qu'elle ne pourra pas traiter correctement
(justifiez votre réponse).

Q5.B- Écrire la définition d'une classe dérivée ClasseDerivee, qui dérive publiquement de la
classe de base ClasseBase et qui contient les membres suivants:

- un membre donnée Champ3 du type Type2
- un seul constructeur
- une fonction Print() pour afficher les membres données de la classe de base et de la classe
dérivée.


IFT1166 H-2K : Final Page 7 sur 13

Q5.C- Complétez la fonction main suivante:

```
int main()
{
int x = 40;
float y = 55.55;
char a = 'w', b='z';
```
```
// À titre d'exemple
// création (instantiation) de l'objet BaseExpObj du type
// ClasseBase<int,int> et cela sans arguments.
```
```
ClasseBase<int,int> BaseExpObj();
```
```
// À ÉCRIRE
// création (instantiation) de l'objet ObjBase du type ClasseBase
// avec les valeurs x et y comme arguments.
```
```
// À ÉCRIRE
// création (instantiation) de l'objet ObjDerivee du type ClasseDerivee,
// avec les valeurs a,b comme arguments.
```
```
// À ÉCRIRE
// appel de la fonction Print de la classe de base sur l'objet ObjBase.
```
```
// À ÉCRIRE
// appel de la fonction Print de la classe dérivée sur l'objet ObjDerivee
```
```
return 0;
}
```

IFT1166 H-2K : Final Page 8 sur 13

Question 5 (20 points)

Soit le programme suivant:

```
#include <iostream.h>
```
```
class X {
public:
int a;
```
```
X(int valeur):a(valeur) {}
void f0() {
cout << "X::f0" << endl;
}
virtual void f1() {
cout << "X::f1" << endl;
}
};
```
```
class Y:public X {
public:
Y(int zz):X(zz) {}
void f1() {
cout << "Y::f1" << endl;
f0();
}
};
```
```
int main() {
```
```
X x(0);
Y y(1);
```
```
X *px;
Y *py;
```
```
py = &y;
y.f1(); // ligne 1
py->f1(); // ligne 2
```
```
px = &y;
y.f1(); // ligne 3
px->f1(); // ligne 4
```
```
// px = py; // ligne 5
// py = px; // ligne 6
```
```
px = &y;px->f1(); // ligne 7
```
```
px = &x;px->f1(); // ligne 8
```
```
py = &y;py->f1(); // ligne 9
```
```
return 0;
}
```

IFT1166 H-2K : Final Page 9 sur 13

Q4.A- Les lignes 1 et 2 écrivent-elles la même chose?

oui non

qu'est ce qu'elles affichent?

Q4.B- Les lignes 3 et 4 écrivent-elles la même chose?

oui non

qu'est ce qu'elles affichent?

Q4.C- Indiquer toutes les fonctions qui seront appelées aux lignes suivantes:

```
X::f0() X::f1()
```
```
ligne 7
```
```
ligne 8
```
```
ligne 9
```
Q4.D- Que se passe-t-il si on enlève les commentaires des lignes 5 et 6? Les transformations
polymorphiques (conversions de types) sont-elles correctes?

Q4.D.1- px = py; // ligne 5

oui non

pourquoi?

Q4.D.2- py = px; // ligne 6

oui non

pourquoi?


IFT1166 H-2K : Final Page 10 sur 13

Question 6 (20 points)

Cet exercice à pour but de vous faire programmer une méthode de tri. L'algorithme que vous
devez programmer triera les éléments d'un tableau dans un ordre décroissant. Pour chaque
position du tableau, vous devez exécuter les deux opérations suivantes:

1- la recherche dans le tableau de l'élément le plus grand (emax),

2- la permutation de emax avec l'élément pointé par la position courante.

Soit le tableau tab des entiers contenant ce qui suit: int tab[5] = {7,6,8,2,5};

La table suivante illustre le fonctionnement de ce tri pour le tableau tab

```
tab position emax
76825 0 8
8 6725 17
87625 26
87625 35
87652 42
```
Dans la colonne tab, les éléments en caractères gras, représentent les éléments déjà triée.

résultat du tri: {8,7,6,5,2}

Q6.A
Écrire une fonction permettant de trier un tableau d'entiers tab de dimension taille, en
utilisant pour cela ces consignes de programmation:

-1- vous devez utiliser l'algorithme de tri précédemment expliqué.
-2- vous ne devez pas utiliser d'autre tableau que le tableau original pour réaliser le tri.
-3- vous pouvez si vous le souhaiter découper votre code en plusieurs fonctions.
-4- vous ne devez pas utiliser les STL.


IFT1166 H-2K : Final Page 11 sur 13

Q6.B Modifier votre fonction afin de permettre de trier aussi bien le type int, le type char et
le type string.


IFT1166 H-2K : Final Page 12 sur 13

Q6.C Modifier votre fonction de tri afin de permettre de trier le type char*. À titre d'exemple
d'un tableau char*:

char* tab[5]={"safran","voile","foc","gouvernail","catamaran"};


IFT1166 H-2K : Final Page 13 sur 13

```
Bonus
(10 points)
```
Pour obtenir le bonus, il faut que vous répondiez (correctement!) à toutes les questions de
l'exercice de votre choix. Donc du 0 ou 10.

Question Bonus (10 points)

Soit le programme suivant:

```
#include <iostream.h>
#include <algorithm>
#include <functional>
```
```
using namespace std;
```
```
class f_pair:public unary_function <unsigned int,bool> {
public:
bool operator() (unsigned int n) const {return n%2 == 0;}
};
```
```
int main() {
```
```
int tab[] = {1,2,3,4,5,6,7};
```
```
int n = count_if(tab,tab+5,f_pair()); // ligne 1
cout << n << endl; // ligne 2
return 0;
}
```
QB.1- Expliquez le but du programme précédent.

QB.2- Donner le contenu de n affiché en sortie après exécution de la ligne 2. (justifier votre
réponse)

QB.3- En utilisant un appel à la fonction count_if de la même manière qu'à la ligne 1, écrivez
l'instruction qui permet de réaliser l'inverse de ce que fait la ligne 1 (inverse du critère):
n = count_if(tab,tab+5,le_critère_à_compléter).

QB.4 Et que va valoir n dans ce cas?


### 1/6

## IFT1166 - Session Automne 1999 Mohamed Lokbani

## FINAL

## Date:15 Décembre 1999 Durée: 3 heures (de 18h30: 21h30) Local: B-2285

## Directives:

## - Il vous est permis d’utiliser un livre de votre choix.

## - Les documents de cours ne sont pas autorisés.

## - Ordinateurs personnels prohibés.

## - Calculatrice non programmable permise.

## L'examen compte:

## 6 pages incluant celle-ci.

## 7 exercices obligatoires et un (1) exercice (exercice 8) optionnel (bonus).

## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

# Exercice 1 (10 Points)

## Question -1.1-

Écrire la définition de la classe s_date correspondant à la structure suivante:

struct s_date {
private:
int jour; // le jour de naissance de la personne
int mois; // le mois de naissance
int an; // l'année de naissance
};

## Question -1.2-

Dans le cas où la fonction main fait appel à un constructeur de recopie de la classe s_date, la classe
s_date doit-elle avoir un constructeur de recopie explicite (justifiez votre réponse)? Si la réponse est oui,
écrire la définition du constructeur de recopie explicite pour la classe s_date.


### 2/6

# Exercice 2 (10 Points)

## Question -2.1-

Écrire la définition de la classe s_fiche correspondant à la structure suivante:

struct s_fiche {
private:
char *nom; // le nom de la personne
int numero; // son numéro d'assurance sociale
struct s_date naissance; // sa date de naissance
};
Pour la structure s_date, vous devez utiliser la classe s_date définie dans l'exercice 1.

## Question -2.2-

Dans le cas où la fonction main fait appel à un constructeur de recopie de la classe s_fiche, la classe
s_fiche doit-elle avoir un constructeur de recopie explicite (justifiez votre réponse)? Si la réponse est
oui, écrire la définition du constructeur de recopie explicite pour la classe s_fiche.

# Exercice 3 (15 Points)

## Question -3.1-

Le format en entrée étant libre mais en respectant quand même le type des données à saisir, écrire la
définition de la fonction SaisirDate membre de la classe s_date déjà définie dans l'exercice 1. Cette
fonction a comme rôle de saisir, à partir de l'entrée standard, puis de remplir les champs privés de la classe
s_date.

## Question -3.2-

Le format en entrée étant libre mais en respectant quand même le type des données à saisir, écrire la
définition de la fonction SaisirFiche comme membre de la classe s_fiche déjà définie dans
l'exercice 2. Cette fonction a comme rôle de saisir, à partir de l'entrée standard, puis de remplir les champs
privés de la classe s_fiche.

## Question -3.3-

Le format d'affichage en sortie étant libre, écrire la(les) définition(s) de la fonction Afficher
nécessaire(s) pour afficher, sur la sortie standard, les informations suivantes issues des deux classes
s_date (déjà définie dans l'exercice 1) et s_fiche (déjà définie dans l'exercice 2):

// Nom de la personne
// Numéro son assurance sociale
// Date de Naissance i.e. jour/mois/année


### 3/6

# Exercice 4 (10 Points)

Soit le programme suivant:

#include <fstream>
#include <string>

class Exo {
private:
ifstream *entree;
static int taille_fenetre = 130; //question -4.1-
string chaine;
public:
Exo(char *fichier_in);
void process(){
string xs("");
if (chaine.size() > 4){
xs.assign(chaine,4,taille_fenetre);
}
cout << xs << endl;
exit(1);
}
~Exo() {
entree->close();
}
};
Exo::Exo(char *fichier) {
entree = new ifstream(fichier,ios::in);
if ((*entree)) {
while (getline((*entree),chaine)) {
process();
}
cout << "Ok!\n";
} else {
cout << "probleme d’ouverture fichier\n";
exit(1);
}
}
int main() {
Exo C("test.txt"); // question -4.2-
return 0;
}

## Question -4.1-

La ligne de code suivante est-elle correcte (élaborez)? Dans le cas contraire, corrigez la.

static int taille_fenetre = 130;

## Question -4.2-

Supposez que le programme compile correctement, écrire la sortie du programme dans le cas où le fichier
test.txt contient le texte suivant (l'espace blanc dans le texte est représenté par ce symbole: ):

1(:<25.GHF$)3/DQFLHQFKDPSLRQGXPRQGHGHVORXUGV0XKDPP
ad$OLTXLVHWDLWOXLPHPHDXWRSURFODPHFRPPHOHSOXVJUDQGDHWH
designeFKDPSLRQGXVLHFOHSDUOHPDJD]LQHVSHFLDOLVHDPHULFDLQ6SRUWV
,OOXVWUDWHGDXFRXUVGXQHFHUHPRQLHPHUFUHGLVRLUD1HZ<RUN


### 4/6

# Exercice 5 (15 Points)

## Question -5.1-

Écrire la définition classe abstraite peintre qui contient deux fonctions virtuelles pures: Saisir et
Afficher.

## Question -5.2-

Écrire la définition de la classe Monet qui dérive "publiquement" de la classe peintre, et a comme
membres privés un tableau TAB contenant NB_ELT éléments du type string.

# Exercice 6 (15 Points)

## Question -6.1-

Écrire une fonction main permettant de faire ce qui suit:

Soit Vdata un conteneur séquentiel vector de la librairie standard (Standard Template Library). Écrire
le code nécessaire permettant de déclarer puis de remplir ce conteneur avec les objets objA et objB (dans
l'ordre), du type OBJT. Par la suite, afficher sur la sortie standard le contenu de ce vecteur en utilisant pour
cela une fonction Afficher membre public de la classe OBJT.

## Question -6.2-

En vous inspirant de la question précédente, écrire le patron de fonctions (fonction template)
temp_print(.........) qui lorsqu'elle est appliquée à un vecteur d'éléments du type T, elle se charge
d'imprimer sur la sortie standard le contenu de ce vecteur. Par vecteur on entend la structure vector de la
librairie standard (Standard Template Library). Vous pouvez supposer que la classe T possède une fonction
membre Afficher.

Pour ce cas-ci, l'utilisation d'une telle fonction sur l'exemple de la question -1- sera comme suit:

int main() {

```
// votre code ............
```
```
temp_print(Vdata);
```
```
return 0;
```
}


### 5/6

# Exercice 7 (25 Points)

Soit un tableau TAB contenant NB_ELT éléments: des mots, du type string. Chaque mot peut être écrit
en majuscules et/ou en minuscules (sans accents). Écrire un programme permettant de réaliser les tâches
suivantes:

Charger les données à la manière du TP1, à travers la fonction load_data, dont le prototype est comme
suit:

void load_data (string tab[], unsigned int & taille);

La fonction load_data permet d’initialiser un tableau tab où chaque élément est du type string.
L'initialisation du tableau, vous permettra de réaliser la tache de saisie des données initiales de manière
simple. La variable taille est une référence à la taille du tableau. Elle indique le nombre d'éléments dans
le tableau après remplissage.

Calculer la fréquence d'apparition de chaque mot dans le tableau TAB.

Afficher les mots et leur fréquence respective dans un fichier test.txt, dans un ordre décroissant par
rapport à la fréquence d'apparition. Dans le cas ou deux mots ont la même fréquence, affichez ces mots
dans un ordre croissant alphabétique (devoir vient avant livre).

Nous considérons que deux mots sont identiques s'ils ne différent que par le fait que certains de leur
caractères sont en majuscule et minuscule (devoir ou Devoir ou DEVOIR sont considérés ici comme
identiques, le même mot).

L'utilisation de la librairie standard est interdite (pas de STL), de même que pour le programme de tri (sort)
de la librairie: vous devez en écrire un.

Exemple

Pour le tableau suivant,

### LIVRE

cahier
devoir
livre
Devoir

taille vaut 5 , et le fichier resultat.txt, obtenu suite à l'exécution de votre programme, contient ce
qui suit:

devoir 2
livre 2
cahier 1


### 6/6

# Exercice 8 - optionnel - n’est pas obligatoire - (Bonus 5 Points)

La ligne suivante est dangereuse lors de son utilisation dans un programme. Expliquer les raisons, et
réécrivez la d’une autre manière.

int & ref = new int;

# BONNES FÊTES!


