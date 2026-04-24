IFT1166 Automne-2K : Intra Page 1 sur 14

IFT1166 - Session Automne 2000, Intra

Mohamed Lokbani

Nom:___________________________________| Prénom(s):_____________________________|

Signature:_______________________________| Code perm:_____________________________|

Date: 18 octobre 2000

Durée: 2 heures (de 18h30 à 20h30) Local: Z-

Directives:

- Toute documentation permise.
- Calculatrice et ordinateur personnel prohibés.
- Répondre directement sur le questionnaire.

```
Bon courage!
```
Exercices Questions

### 1._____________________/15 A ~ B

### 2._____________________/15 A ~ B

### 3._____________________/25 A ~ B ~ C ~ D

### 4._____________________/20 A ~ B

### 5._____________________/25 A ~ B

Total:__________________/


IFT1166 Automne-2K : Intra Page 2 sur 14

Question 1 (15 points)

Q1.A- Que va afficher en sortie le fragment de code suivant:

for (int i=0;i<10;i++)

```
for (int j=0;j<5;j++)
if (i%2 && j%2) cout << "#";
```
Réponse:

Q1.B- Le fragment de code suivant est-il syntaxiquement correct?

double Z=2768.64758;

cout << setiosflags(ios::fixed | ios::showpoint)
<< setprecision(2) << Z << setw(10) << Z << int(Z) << endl;

oui, il est correct non, il n'est pas correct

pourquoi (dans le cas où la réponse est non)?

Dans le cas où la réponse est oui, indiquez l'affichage en sortie (représentez les espaces blancs par
)


IFT1166 Automne-2K : Intra Page 3 sur 14

Question 2 (15 points)

Indiquez si les fragments de code suivants génèrent au moins une erreur à la compilation. Si c'est

le cas expliquez la, dans le cas contraire indiquez ce qui sera affiché en sortie.

Q2.A-

```
namespace NS1 {
class T {};
void f(T x) {cout << "test1\n";}
}
using namespace NS1;
```
```
NS1::T param;
```
```
int main() {
f(param);
return 0;
}
```
oui, il y a au moins 1 erreur de compilation non, il n'y a pas d'erreurs à la compilation

Dans le cas où votre réponse est oui, expliquez l'erreur (ou les erreurs si plusieurs) de

compilation:

Dans le cas où votre réponse est non, indiquez que va afficher le programme en sortie:


IFT1166 Automne-2K : Intra Page 4 sur 14

Q2.B-

```
namespace NS2 {
class T {};
void f(T x) {cout << "test1\n";}
}
```
```
using namespace NS2;
```
```
void f(NS2::T x){cout << "test2\n";}
```
```
int main() {
NS2::T param;
f(param);
return 0;
}
```
oui, il y a au moins 1 erreur de compilation non, il n'y a pas d'erreurs à la compilation

Dans le cas où votre réponse est oui, expliquez l'erreur (ou les erreurs si plusieurs) de

compilation:

Dans le cas où votre réponse est non, indiquez que va afficher le programme en sortie:


IFT1166 Automne-2K : Intra Page 5 sur 14

Question 3 (25 points)

Soit le fragment de code suivant:

```
code no de ligne
```
```
class Class_a {
private:
int V_;
int W_;
public:
int V() const {
return V_;
}
void setV(int UneValeur=10) {
V_ = UneValeur;
}
Class_a(int a,int b):V_(a),W_(b){}
};
Class_a essai(2,3);
const Class_a test(4,5);
```
```
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
//
//
//
//
//
```
Q3.A- Lesquels des mots suivants sont des objets du type, des noms de membres données ou des

noms de méthodes de la classe Class_a:

```
essai test private public V_ W_ V setV UneValeur
```
objets

membres

données

méthodes

Q3.B- Indiquez les appels corrects (s'il en existe).

essai.V_; correct incorrect

Dans les deux cas, pourquoi?


IFT1166 Automne-2K : Intra Page 6 sur 14

essai.setV(); correct incorrect

Dans les deux cas, pourquoi?

essai.setV(25); correct incorrect

Dans les deux cas, pourquoi?

essai.test; correct incorrect

Dans les deux cas, pourquoi?

Q3.C- Si la fonction main devait accéder à la variable W_, sans la modifier, que pourrions-nous

faire?

- Déplacer W_ dans la partie public?

```
Pourquoi (justifiez votre réponse)?
```
```
oui non
```

IFT1166 Automne-2K : Intra Page 7 sur 14

- Définir une fonction private: int W() {return W_;}

```
Pourquoi (justifiez votre réponse)?
```
```
oui non
```
-Définir une fonction private: int W() const {return W_;}

```
Pourquoi (justifiez votre réponse)?
```
```
oui non
```
- Définir une fonction public: int W() {return W_;}

```
Pourquoi (justifiez votre réponse)?
```
```
oui non
```
- Définir une fonction public: int W() const {return W_;}

```
Pourquoi (justifiez votre réponse)?
```
```
oui non
```

IFT1166 Automne-2K : Intra Page 8 sur 14

Q3.D- L'appel à la fonction V à partir de essai, se fait comme suit:

essai.V; correct incorrect

Pourquoi (justifiez votre réponse)?

essai.V(); correct incorrect

Pourquoi (justifiez votre réponse)?

essai::V(); correct incorrect

Pourquoi (justifiez votre réponse)?

essai.V() const; correct incorrect

Pourquoi (justifiez votre réponse)?

essai(V); correct incorrect

Pourquoi (justifiez votre réponse)?


IFT1166 Automne-2K : Intra Page 9 sur 14

Question 4 (20 points)

Q4.A- Définissez ce qu'est la "déclaration d'une classe"?

Q4.B- Le dossier d'un étudiant comporte:

- son identité (nom et prénom, chacun en un seul mot),
- le programme auquel il est inscrit (libre, mathématique, physique, etc.),
- son code permanent,
- les notes obtenues pour ses:
    - travaux pratiques (tp1, tp2 et tp3),
    - examens (intra et final),
- sa note finale (sur 100),
- l'état de son passage au cours IFT1666 (succès ou échec).

Écrire la déclaration des classes nécessaire pour représenter l'énoncé précédent dans le langage

C++, en respectant les contraintes suivantes:

- le principe d'encapsulation,
- toutes les chaînes sont du type char* et les nombres du type double,
- vous devez représenter le problème en utilisant obligatoirement 2 classes,
- la partie interface devra accepter en entrée les informations relatives à l'étudiants (nom, prénom

```
etc.) et ne retourner en sortie que l'état de son passage au cours (succès ou échec).
```


IFT1166 Automne-2K : Intra Page 11 sur 14

Question 5 (25 points)

Un carré magique est un tableau de dimension (MxM) dont la somme des colonnes, la somme des

lignes et la somme des deux diagonales est la même. À titre d'exemple, le carré suivant est
magique:

```
816
357
```
```
492
```
```
Tableau Q
```
car pour toutes les directions indiquées par les flèches, la somme des nombres (somme magique)

est toujours égale à 15 (8+1+6, 8+3+4, 4+5+6, 8+5+2, etc.).

Q5.A- Écrire la définition de la fonction carre_magique qui prend en arguments:

- un tableau de pointeurs sur des entiers
- un entier N, qui vérifie si le carré (NxN) stocké dans les N premières lignes et N premières

```
colonnes du tableau (passé en argument) est un carré magique.
```
Cette fonction calcule la somme magique dans le cas ou le carré est magique sinon la somme la

plus élevée. Dans l'exemple du tableau Q5:

si N=3, le carré est magique et la somme magique est égale à 15.

si N=2, le carré n'est pas magique et la somme la plus élevée est égale à 13 (8+1, 8+3, 8+5, 1+5,

3+5,3+1).

Vous pouvez supposez que la valeur de N sera toujours inférieure ou égale à M.

Cette fonction retourne un booléen avec la valeur true si le carré est magique, false sinon.



IFT1166 Automne-2K : Intra Page 13 sur 14

Q5.B- Écrire un programme (fonction main etc.) qui utilise la fonction carre_magique avec le

tableau Q5 comme exemple. Le programme doit faire deux appels à carre_magique. Ces

appels correspondent aux cas où N=2 et N=3. Le programme devra afficher dans les deux cas,

dans l'ordre suivant:

- si le tableau, passé en argument pour la taille spécifiée, est un carré magique ou pas ; en se

```
basant pour cela sur la valeur retournée par la fonction carre_magique.
```
- la somme magique ou la somme la plus élevée telle que nous les avons décrites en Q5.A.

Modifier s'il le faut, la fonction carre_magique pour tenir compte de cet ordre d'affichage (pas
besoin de réécrire toute la fonction, inclure uniquement les lignes modifiées, si modification il y

a).


- IFT1166 Automne-2K : Intra Page 10 sur
- IFT1166 Automne-2K : Intra Page 12 sur
- IFT1166 Automne-2K : Intra Page 14 sur


IFT

Automne-2003 : Intra

1/

```
IFT1166 - Session Automne, Intra
```
```
Mohamed Lokbani
```
### IFT1166 - INTRA

```
Inscrivez tout de suite votre nom et code permanent.
Nom: __________________________________|
```
```
Prénom(s): _____________________________|
```
```
Signature: ______________________________|
```
```
Code perm: ____________________________|
```
- Directives: Durée: 2 heures (de 15h00 à 17h00) Local: N-515 du Pavillon Principal (P.P). Date : 25 octobre 2003
Toute documentation permise.
-
Calculatrice

```
non
permise.
```
-
Répondre directement sur le questionnaire.
-
Les réponses

```
doivent être clairement présentées.
```
```
1._____________________/
```
```
(1.1 ; 1.2 ; 1.3 ; 1.4 ; 1.5)
```
```
2._____________________/
```
```
(2.1 ; 2.2 ; 2.3 ; 2.4 ; 2.5 ; 2.6)
```
```
3._____________________/
```
```
(3.1 ; 3.2)
```
```
4._____________________/
```
```
(4.1)
```
```
5._____________________/
```
```
(5.1)
```
```
Total:__________________/
```
IFT

Automne-2003 : Intra

2/

```
Question 1 (15 points)
1.
Les tableaux en C++ commencent toujours par l’élément 0.
```
```
1.
```
(^) Écrire la déclaration d’une chaîne de caractères constante, initialisée avec votre nom et prénom.
1.
Lors du processus de compilation, un programme C++ est d’abord traité par ________________.

5. un optimisateur 4. un correcteur orthographique 3. un éditeur de liens 2. un chargeur 1. un préprocesseur

```
1.
```
(^) Avant d’utiliser une variable, elle doit être d’abord ______________.

5. aucune des précédentes réponses, préciser alors : ___________. 4. préprocessée. 3. imprimée. 2. définie. 1. incluse.

```
1.
```
(^) Il est parfaitement possible d’initialiser un tableau. Il suffit pour cela de donner les valeurs de ses
éléments, séparées par des ______________, entre ____________.
VRAI
FAUX


IFT

Automne-2003 : Intra

3/

```
Question 2 (20 points)
2.
Quel sont le nom et le type de la fonction membre suivante :
```
```
Data* Data::test(int i) const { .... }
```
```
2.
```
(^) L’instruction correspondante à «p égale à 5 » est « p==5 » ; écrire alors l’instruction qui correspond
2.3 à « z est plus petit que ou égale à 0 ou bien z est plus grand que 100 ».
Tout en expliquant votre réponse, quelle sera la valeur retournée par la fonction
foo
:
int foo(int j){
if(j==0){ int x=5;
x = 3 ; int x ;
return x ; }
}
2.
Tout en expliquant votre réponse, quelle sera la valeur retournée par la fonction
f :
void g(int& valeur){ int autre=0;
valeur=13;
int f(){ }
return autre; g(autre); int autre=42;
}
IFT
Automne-2003 : Intra
4/
2.
Tout en expliquant votre réponse, le code de la fonction suivante est-il correct?
int &Test( int &r, int i ) {
return r ; r = i*i ;
}
2.
Tout en expliquant votre réponse, le programme suivant est-il correct, si oui que va-t-il afficher en
sortie:
int main() { using namespace std ; #include <iostream>
if( p!=NULL ) { int *p = new int ;
cout << *p << endl ; delete q ; int *q = p ; *p = 99 ;
return 0 ; }
}


IFT

Automne-2003 : Intra

5/

```
Question 3 (20 points)
3.
Écrire une implantation possible de la fonction strlen qui renvoie la longueur d’une chaîne de
```
```
3.2 caractères (caractère nul final non compris).
Quelles modifications faudrait-il faire à la fonction précédente, si l’on voulait trouver le nombre
```
```
d’éléments non nuls consécutifs dans une table d’entiers désignée par un pointeur int*?
```
IFT

Automne-2003 : Intra

6/

```
Question 4 (20 points)
Que va afficher en sortie le programme suivant, qui compile et s’exécute correctement
```
```
.
```
```
} cout <<"sortie fct \n"; delete b; cout << "entrée fct \n"; void fct(exo1 a, exo1 * b) { } cout << "fin de main\n"; c = exo1(6,6); exo1 d = exo1(5,5); fct(a,adr); exo1 * adr=new exo1(4,4); exo1 c=a; exo1 b=exo1(2); exo1 a; cout << "début de main \n"; void fct(exo1, exo1 *); int main() { } cout << "destruction de (" << x << "," << y << ")\n"; exo1::~exo1() { } cout << "zone 2 : (" << x << "," << y << ")\n"; y = a.y; x = a.x; exo1::exo1(const exo1 & a) { }; ~exo1(); exo1 (const exo1 &); } cout << "zone 1 : (" << x << "," << y << ")\n"; y = ord; x = abs; exo1 ( int abs=0, int ord = 0 ) { public : int x,y; private : class exo1 { using namespace std; #include <iostream>
```

IFT

Automne-2003 : Intra

7/

IFT

Automne-2003 : Intra

8/

```
Question 5 (25 points)
Écrire la définition de la classe
```
```
MilTime
```
```
ainsi que toutes ses méthodes, qui permet de convertir un temps
```
```
minute et am/pm. Ainsi par exemple : de la représentation militaire (00h, 01h, ..., 21h, 22h, ... 23 heures) vers une représentation classique heure
```
```
Représentation internationale
```
```
Représentation américaine
```
```
hh:mm:ss
```
```
hh:mm:ss
```
```
00:00:
```
```
12:00:00 a.m
```
```
06:30:
```
```
6:30:30 a.m
```
```
12:00:
```
```
12:00:00 p.m
```
```
23:45:
```
```
11:45:00 p.m
```
```
La classe
```
```
MilTime
```
```
doit contenir entre autre:
```
- Une méthode set_data, dont les arguments sont utilisés pour initialiser les membres de la classe. - Un constructeur par défaut permettant d’initialiser les membres de la classe avec la valeur zéro.
Par ailleurs, cette méthode s’assurera de la validité du format de ses arguments.
- Une méthode pour afficher le temps dans la représentation américaine. - Une méthode pour afficher le temps dans la représentation internationale.

```
Attention Écrire un programme principal qui utilisera les différentes méthodes de votre classe.
```
```
: La conception de votre classe et votre programme doit être conforme aux principes de base de
```
```
la programmation orientée objet.
```

IFT

Automne-2003 : Intra

9/

IFT

Automne-2003 : Intra

10/


IFT1166 Automne - 2005: INTRA 1/

## Session Automne, 2005

## Mohamed Lokbani

# IFT1166 – INTRA

Inscrivez tout de suite votre nom et code permanent.

Nom: __________________________________| Prénom(s): _____________________________|

Signature: ______________________________| Code perm: ____________________________|

Date : 18 octobre 2005

Durée: 2 heures (de 16h30 à 18h30) Local: N-515 du Pavillon Roger-Gaudry.

# Directives:

- Toute documentation permise.
- Calculatrice **non** permise.
- Répondre directement sur le questionnaire.
- Les réponses **doivent être brèves, précises et clairement présentées.**

### 1._____________________/22 (1.1, 1.2, 1.3)

### 2._____________________/15 (2.1, 2.2, 2.3)

### 3._____________________/12 (3.1)

### 4._____________________/16 (4.1, 4.2, 4.3, 4.4)

### 5_____________________ /20 (5.1, 5.2)

### 6_____________________ /15 (6.1)

Total:__________________/


IFT1166 Automne - 2005: INTRA 2/10

**Exercice 1 (22 points)**

**1.1** Il existe toujours de multiples façons d’écrire un programme qui résout un certain problème. Un bon
programmeur ne se contente cependant pas d’écrire un programme qui fonctionne sans se soucier de la
lisibilité de son code et de l’élégance de sa solution. Pourquoi? Donnez trois raisons.

**1.2** Écrire en C++, les instructions nécessaires (pas un programme) pour afficher en sortie le texte suivant
en respectant le format d'affichage:

Deux idiots a la chasse, voient passer un deltaplane. Le premier epaule et tire
...
 "Bah tu l'as rate !!", commente le second.
 "Oui mais il a lache sa proie.", repond le premier.

Dans le texte : «  » correspond à une tabulation (un « TAB »), «  » à un saut de ligne et « _ » à un espace
blanc.


IFT1166 Automne - 2005: INTRA 3/10

**1.3.** Faire ce qui suit en C++:
a) Définir le nom de type « AddresseType » comme un tableau de 40 caractères.

```
b) Déclarer la variable « monAddresse » du type « AdresseType ».
```
```
c) Déclarer la variable « employesAdresses », un tableau de 100 éléments, où chaque élément
est du type « AdresseType ».
```
```
d) Expliquer pourquoi cette expression est incorrecte:
employesAddresses[6] = "9999 Rue Sans Fin";
```

IFT1166 Automne - 2005: INTRA 4/10

**Exercice 2 (15 points) Tout en justifiant votre réponse** , que vont afficher en sortie les différents
fragments de code qui compilent et s’exécutent correctement (dans un programme complet) :
**2.1**
x = 9;
y = 6;
z = 4;
if ((x < y)&&(y != 7)) cout << "A\n";
else if ((z < 7)||(y == 6))cout << "B\n";
else cout << "C\n";
cout << "D\n";
cout<<"E"<<endl;

**2.2**
int A[8]={1,2,4,6,7,7,2,1};
int i = 2;
while (i <= 5){
A[i] = A[i] - i;
i++;
}
for(i=0;i<8;i++){
cout << A[i] <<" ";
}


IFT1166 Automne - 2005: INTRA 5/10

**2.3**
int main(){
float num1;
num1 = 123.456;
cout << '|' << num1 << '|' << endl;
cout << setiosflags(ios::fixed);
cout << setiosflags(ios::showpoint);
cout << setprecision(2) << num1 << endl;
cout << '|' << setw(8) << num1 << '|' << endl;
cout << '|' << setw(1) << num1 << '|' << endl;
}


IFT1166 Automne - 2005: INTRA 6/10

**Exercice 3 (12 points)** Supposer les déclarations suivantes:

```
struct nourriture {
char nom[15];
int portion;
int calories;
};
```
Et soit la déclaration:
**struct nourriture repas[5];**

Expliquez la différence entre les expressions:
**repas[2].nom** (et) **repas->nom[2]**


IFT1166 Automne - 2005: INTRA 7/10

**Exercice 4 (16 points)** Soit le fragment de code suivant :
float a = 0.1;
float b = 0.3;
float c, *pa, *pb;

```
pa = &a;
*pa = 2 * a;
pb = &b;
c = 3 * (*pb - *pa);
```
En supposant que chaque nombre réel (un float) occupe 4 octets en mémoire, que l’adresse de la variable
« **a** » est « **0x1130** », l’adresse de la variable « **b** » est « **0x1134** » et finalement l’adresse de la variable
« **c** » est « **0x1138** ». **Tout en justifiant votre réponse** , répondre aux questions suivantes:

**4.1** Quelle est la valeur assignée à « **pa** »?

**4.2** Quelle est la valeur assignée à « ***pa** »?

**4.3** Quelle est la valeur assignée à « **&(*pa)** »?

**4.4** Quelle est la valeur assignée à « ***(&c)** »?


IFT1166 Automne - 2005: INTRA 8/10

**Exercice 5 (20 points)** Soit le programme suivant qui compile et s’exécute correctement :

#include <iostream>
using namespace std ;
const float num = 2.5;
void Test(float& a, int b){
float c;
c = a + num;
++a;
++b;
cout << "Les valeurs de a, b, et c dans Test sont: "\
<< a << ' ' << b << ' ' << c << endl;
}
int main(){
float r = 0;
int s, t;

s = 5;
t = 10;

cout << "Les valeurs de r, s, et t sont: "
<< r << ' ' << s << ' ' << t << endl;
Test(r, t);
cout << "Les valeurs de r, s, et t sont: "
<< r << ' ' << s << ' ' << t << endl;
Test(r, s);
cout << " Les valeurs de r, s, et t sont: "
<< r << ' ' << s << ' ' << t << endl;
}

**5.1** Que va afficher le programme en sortie?


IFT1166 Automne - 2005: INTRA 9/10

**5.2** Si la méthode « **main** » contenait aussi l’appel « **Test(t,r)** »,

// etc.
int main(){
float r = 0;
int s, t;

s = 5;
t = 10;
Test(t, r);
// etc.
}

Est-ce que le programme va compiler et s’exécuter correctement? Expliquer votre réponse.


IFT1166 Automne - 2005: INTRA 10/10

**Exercice 6 (15 points)** Écrivez une fonction **afficheTriangle(N,f,c1,c2)** qui affiche un

triangle de « **N** » lignes. Le triangle est rempli avec le caractère « **f** » et sa diagonale est une

alternance entre les caractères « **c1** » et « **c2** », en commençant par « **c1** » sur la première ligne.
N’oubliez pas de déclarer l’entête de la fonction (le type de retour, le nom, les paramètres).

Exemple: l’appel « **afficheTriangle( 7, ’.’, ’+’, ’-’ );** » va afficher ceci:
**......+
.....-**

**....+
...-
..+**

**.-
+**

```
La simplicité de votre code et la clarté de sa présentation
sont des éléments importants de la notation
```

## IFT1166 A-99 : Intra 1

## IFT1166 - Session Automne, Intra

## Mohamed Lokbani

# IFT1166 - INTRA

Nom:___________________________________| Prénom(s):_____________________________|

Signature:_______________________________| Code perm:_____________________________|

Date:20 Octobre 1999

Durée: 2 heures (de 18h30: 20h:30) Local: 1360

# Directives:

- Il vous est permis d'utiliser un livre de votre choix.
- Les documents de cours ne sont pas autorisés.
- Ordinateurs personnels prohibés.
- Calculatrice (simple) permise.
- Répondre directement sur le questionnaire.

## - L'examen compte 14 pages incluant celle-ci.

Nota Bene: 21 Octobre 1999: cette version est une remise à jour de la version distribuée aux étudiants
durant l'intra. Cette version prend en compte les modifications apportées (très légères), durant l'Intra, à
quelques questions de l'examen.

### 1._____________________/20

### 2._____________________/20

### 3._____________________/5

### 4._____________________/25

### 5._____________________/30

Total:__________________/100


IFT1166 A-99 : Intra 2

Question 1 (20 points)

-1- Le message est le moyen unique de communiquer avec un objet. Que contient un tel message? (les
citer uniquement)

Réponse :

-2- Définissez l’instanciation.

Réponse :

-3- Citez les 3 principes de base qui permettent de dire qu’un langage donné est orienté objet? (sans les
expliquer)

Réponse :

-4- Quelles sont les deux façons d'écrire des commentaires en C++, et en quoi elles diffèrent l'une de
l'autre?

Réponse :

-5- Quelle est la différence entre les membres privés et les membres publics, au niveau de la visibilité?
Réponse :


IFT1166 A-99 : Intra 3

-6- Quel est le nom donné à la fonction membre appelée automatiquement lors de la création d'un
objet?
Réponse :

-7- Quelle est la différence entre les 2 déclarations suivantes :

const int * A;

### ET

int * const B;

Réponse :


IFT1166 A-99 : Intra 4

Question 2 (20 points)

Le programme suivant utilise la macro MAX pour calculer le maximum entre deux nombres.

### -1-

Indiquez le résultat de l’affichage, pour chaque fragments de code suivant:

#include <iostream.h>

#define MAX(a,b) ((a) > (b)? (a) : (b))

int main () {
int a =6,b=5,c=100;
cout << "a: " << a << " b: " << b << " c: " << c << endl;

Réponse :

```
c=MAX(a,b);
cout << "a: " << a << " b: " << b << " c: " << c << endl;
```
Réponse :

c=MAX(a++,b);
cout << "a: " << a << " b: " << b << " c: " << c << endl;

Réponse :

return 0;
}


IFT1166 A-99 : Intra 5

### -2-

Réécrivez la définition de la fonction MAX grâce a une fonction qui offre la rapidité de la macro ci-
dessus, mais sans les possibilités de calculs incorrects.

Réponse :

### -3-

À l’aide de cette nouvelle fonction, donnez le résultat d’affichage des deux fragments de code suivants:

```
c=MAX(a,b);
cout << "a: " << a << " b: " << b << " c: " << c << endl;
```
Réponse :

```
c=MAX(a++,b);
cout << "a: " << a << " b: " << b << " c: " << c << endl;
```
Réponse :


IFT1166 A-99 : Intra 6

Question 3 (5 points)

Le fragment de code contient une erreur. Identifiez-la et expliquez la :

namespace exemple {
void affiche(int ,int );
// ...
}

namespace test {
void affiche(int );
// ....
}

using exemple::affiche;

affiche(230);

Réponse :

Question 4 (25 points)

Le programme suivant gère un parc automobile.

### -1-

Ce programme comporte 5 erreurs de compilation. Pour chaque erreur, indiquez sur quelle ligne elle
apparaît et corrigez-la.


IFT1166 A-99 : Intra 7

1) #include <iostream.h>
2) #include <string.h>

3) class voiture {
4) private:
5) char *nom; // nom du vehicule
6) int annee; // annee du vehicule
7) static int total = 0; //nombre de vehicules
8) public:
9) voiture(char* val="",int x=0); //constructeur initialisateur
10) ~voiture(); // destructeur
11) voiture(const voiture); // constructeur de recopie
12) void affiche();
13) static void print();
14) };
15)
16)
17)
18) voiture::voiture(char* cp,int x)
19) {
20) nom = new char[strlen(cp)+1];
21) annee = x;
22) strcpy(nom,cp);
23) total++;
24) cout << "C" << endl;
25) }
26)
27) voiture::~voiture()
28) {
29) delete nom;
30) total--;
31) cout << "D" << endl;
32) }
33)
34) voiture::voiture(const voiture& car):nom(new char[strlen(car.nom)+1])
35) {
36) strcpy(nom,car.nom);
37) annee = car.annee;
38) total++;
39) cout << "R" << endl;
40) }
41)
42) void voiture::affiche()
43) {
44) cout << "nom : " << nom << " annee: " << annee << endl;
45) cout << "nombre de voitures dans le parc: " << total << endl;
46) }
47)
48) void voiture::print()
49) {
50) cout << "nombre de voitures dans le parc: " << total << endl;
51) cout << "nom: " << nom << endl;
52) }
53)
54) int main()
55) {
56) voiture.print();
57) voiture honda;
58) voiture volkswagen("beatle",1985);
59) voiture usagee("jetta",1980) = volkswagen;
60) usagee.affiche();
61) voiture::print();
62) return 0;
63) }


IFT1166 A-99 : Intra 8

Réponse :

Erreur 1:
Ligne:

Correction:

Erreur 2:
Ligne:

Correction:

Erreur 3:
Ligne:

Correction:

Erreur 4:
Ligne:

Correction:

Erreur 5:
Ligne:

Correction:


IFT1166 A-99 : Intra 9

### -2-

Supposez que le programme compile correctement, indiquez le résultat de l'affichage.

Réponse :


IFT1166 A-99 : Intra 10

Question 5 (30 points)

Pour représenter un rationnel (à partir d'entiers), vous devez définir une classe contenant un numérateur
entier et un dénominateur entier.

Un objet r de la classe Rationnel sera interprété comme représentant le nombre
r_numerateur/r_denominateur. Par exemple, si l'on déclare:

Rationnel r1(2, 1), r2(6, 3), r3(4, 3);

alors les objets r1, r2 et r3 représentent respectivement 2/1, 6/3 et 4/3. r1 et r2 représentent alors le
même nombre rationnel, mais r3 < r1 et r3 < r2.

Vous pouvez supposer que le dénominateur n'est pas nul et que le rationnel est tout le temps positif.

Nous désirons effectuer les opérations suivantes sur les deux rationnels r1(a,b) et r2(c,d):

- l'addition: r1+r2; retourne un rationnel.

L'addition de deux rationnels est définie ainsi:

r3 = r1 + r2 = ((a*d )+ (b*c)) / (b*d)

- la multiplication: r1*r2; retourne un rationnel.

La multiplication de deux rationnels est définie ainsi:

r3 = r1 * r2 = (a*c) / (b*d)

- le test d'égalité: r1==r2; retourne vrai, si r1=r2 (c'est à dire: a/b == c/d) ; sinon faux.
- le test de supériorité: r1>r2; retourne vrai si r1>r2 (c'est à dire: a/b > c/d), sinon faux.

En plus de ces opérations, il nous faudra une fonction pour afficher un rationnel sous la forme suivante:

r_numerateur/r_denominateur

Écrire la classe Rationnel et les fonctions membres citées plus haut, y compris le constructeur, pour
pouvoir déclarer un rationnel sous la forme:

Rationnel r1(2, 1);

N'utilisez pas la technique de surcharge des opérateurs.


IFT1166 A-99 : Intra 11

Réponse :


IFT1166 A-99 : Intra 12


IFT1166 A-99 : Intra 13


IFT1166 A-99 : Intra 14


IFT1166 Été-2K : Intra Page 1 sur 13

## IFT1166 - Session Été 2000, Intra

## Mohamed Lokbani

Nom:___________________________________| Prénom(s):_____________________________|

Signature:_______________________________| Code perm:_____________________________|

Date:30 mai 2000

Durée:2 heures (de 19h30 à 21h30) Local: P-310

## Directives:

- Il vous est permis d'utiliser un livre de votre choix.
- Les documents de cours ne sont pas autorisés (y compris mes e-notes disponibles sur la page web
    du cours ou à la bibliothèque Math/Info).
- Ordinateurs personnels prohibés.
- Calculatrice (simple) permise.
- Répondre directement sur le questionnaire.

```
Bon courage!
```
Les niveaux de difficulté des questions posées:

# * (la plus facile) ...à... *** (la plus difficile)

### 1._____________________/10

### 2._____________________/20

### 3._____________________/16

### 4._____________________/24

### 5._____________________/30

Total:__________________/100


IFT1166 Été-2K : Intra Page 2 sur 13

# Question 1 (10 points) (*)

Écrire la définition de la fonction Qnum1, qui n'accepte aucun argument et ne retourne aucune

## valeur, dont la tâche est d'afficher la figure suivante (représentant la lettre i). Il n'y a pas de

contraintes sur la démarche à suivre, seul le résultat compte.

### #######

### ### ###

### #######

### ### ###

### ### ###

### ### ###

### #######


IFT1166 Été-2K : Intra Page 3 sur 13

## Question 2 (20 points)

# Q2.A Définissez ce que c'est le "polymorphisme", et donnez un exemple. (*)

# Q2.B Définissez ce que c'est "une copie superficielle", et donnez un exemple. (*)


IFT1166 Été-2K : Intra Page 4 sur 13

# Q2.C Le destructeur a-t-il un type de retour? (*)

oui, il a un type de retour. ; non, il n'a pas un type de retour.

si la réponse est oui, lequel?

Q2.D Écrire le prototype de la fonction exemple qui retourne un pointeur sur un entier et qui

accepte les 3 arguments suivants: une chaîne de caractères, un caractère passé par valeur, un

# entier passé par référence. (*)

# Q2.E Soit la déclaration suivante: (**)

```
const char *chaine = "IFT1166";
```
Les instructions suivantes génèrent-elles une erreur à la compilation?

Q2.E.1. *(chaine++);

oui, elle génère une err. de compil. ; non, elle ne génère pas une err. de compil.

justifiez votre choix (pourquoi)?

Q2.E.2. (*chaine)++;

oui, elle génère une err. de compil. ; non, elle ne génère pas une err. de compil.

justifiez votre choix (pourquoi)?


```
IFT1166 Été-2K : Intra Page 5 sur 13
```
# Question 3 (16 points) (**)

```
Tout en développant votre réponse sur la feuille d'examen, indiquer ce qu'écrit en sortie, le
programme suivant:
```
### // --------------------------------------------------------------------

```
( 1) #include <iostream.h>
```
```
(2)intA=2;
(3)intB=3;
```
```
(4)void fonction()
(5){
(6) intB=9;
( 7) while (B > 7)
(8) {
(9) intA=B;
(10) A++;
(11) B--;
(12) }
```
(13) cout << "A= " << A << " B= " << B << endl; A= B=

```
(14)}
```
```
(15)void uneAutre()
(16){
(17) intA=B;
(18) A++;
(19) B = 6;
(20)}
```
```
(21)int main()
(22){
```
(23) cout << "A= " << A << " B= " << B << endl; A= B=

```
(24) fonction();
```
(25) cout << "A= " << A << " B= " << B << endl; A= B=

```
(26) A = 11;
(27) intB=12;
```
```
(28) uneAutre();
```
(29) cout << "A= " << A << " B= " << B << endl; A= B=

```
(30) return 0;
(31)}
// --------------------------------------------------------------------
```

```
IFT1166 Été-2K : Intra Page 6 sur 13
```
# Question 4 (24 points) (***)

```
Tout en développant votre réponse sur la feuille d'examen, indiquer ce qu'écrit en sortie, le
programme suivant:
```
### // --------------------------------------------------------------------

```
( 1) #include <iostream.h>
```
```
(2)int uneFonction(int a, int & b,int *c)
(3){
( 4) a += 1;
( 5) b += 3;
(6) *c+=4;
```
```
( 7) return a+b+(*c);
(8)}
```
```
(9)int main() {
```
```
(10) inta=3,b=4,c=5;
```
(11) cout << "sortie:" << uneFonction(a,b,&c) << endl; sortie:

```
(12) cout << "a= " << a << " b= " << b << " c= " << c << endl;
```
```
a= b= c=
```
```
(13) a = 3,b=4,c=5;
```
(14) cout << "sortie:" << uneFonction(b,c,&a) << endl; sortie:

```
(15) cout << "a= " << a << " b= " << b << " c= " << c << endl;
```
```
a= b= c=
```
```
(16) a = 3, b = 4,c=5;
```
(17) cout << "sortie:" << uneFonction(a,a,&a) << endl; sortie:

```
(18) cout << "a= " << a << " b= " << b << " c= " << c << endl;
```
```
a= b= c=
```
```
(19) return 0;
(20)}
// --------------------------------------------------------------------
```

IFT1166 Été-2K : Intra Page 7 sur 13

Question 5 (30 points)

Soit la fonction main suivante:

### // --------------------------------------------------------------------

```
(1)int main() {
```
```
( 2) Question5 x; // chaîne vide
```
```
( 3) x.affiche();
( 4) x.affichageRenverse();
```
```
( 5) Question5 y("bateau");
```
```
( 6) y.affiche();
( 7) y.affichageRenverse();
```
```
( 8) Question5z=y;
```
```
( 9) z.affiche();
(10) z.affichageRenverse();
```
```
(11) if (z.compare("bateau"))
(12) cout << "identique\n";
(13) else cout << "different\n";
```
```
(14) return 0;
```
### (15) }

### // --------------------------------------------------------------------

La fonction main utilise la classe Question5, qui contient entre autre les éléments suivants:

donnée membre private:

```
char *nom : le nom d'une chaîne de caractères.
```
fonctions membres public:

```
affiche : permet d'afficher sur la sortie standard, la donnée nom, membre de la classe
```
Question5. Cette fonction n'accepte aucun argument, et elle ne retourne rien.

```
affichageRenverse : permet d'afficher la donnée nom, membre de la classe
```
Question5, à l'envers (ex. pour la chaîne soleil, nous obtiendrons suite à l'appel de cette

fonction, la chaîne lielos). Cette fonction n'accepte aucun argument, et elle ne retourne rien.

```
compare : une fonction booléenne permettant de comparer si la chaîne nom (membre de
```
la classe Question5) est identique à la chaîne passée en argument. Cette fonction accepte donc,

un seul argument du type chaîne de caractères et elle retourne true, si c'est vrai i.e. les deux

chaînes sont identiques ; sinon false i.e. les deux chaînes sont différentes.


IFT1166 Été-2K : Intra Page 8 sur 13

Q5.1 La classe Question5 doit-elle avoir un Constructeur de Recopie (CR) explicite, ou celui

# par défaut est suffisant? (*)

oui, elle doit avoir un CR explicite ; non, elle ne doit pas avoir un CR explicite

pourquoi (justifiez votre réponse)?

Q5.2 Indiquer, parmi les lignes de la fonction main mentionnées dans le tableau ci-dessous, où

est appelé le constructeur de recopie (explicite ou par défaut) de la classe Question5, en

indiquant à chaque fois le nom de l'objet crée (si plusieurs objets sont crées pour une même ligne,

# indiquez-les tous). (*)

lignes (voir page 7) àààà 25811

constructeur de recopie

# Q5.3 Écrire la définition de la classe Question5, telle que décrite précédemment. (***)


IFT1166 Été-2K : Intra Page 9 sur 13


IFT1166 Été-2K : Intra Page 10 sur 13


IFT1166 Été-2K : Intra Page 11 sur 13

Q5.4 En utilisant la classe Question5 décrite au début de cet exercice, indiquez si la fonction

main suivante compile correctement ou non. Si elle ne compile pas, indiquez pourquoi. (détaillez

# votre réponse)? (**)

### // --------------------------------------------------------------------

```
(1)int main() {
```
```
( 2) Question5 y("bateau");
( 3) y.affiche();
( 4) y.affichageRenverse();
```
```
( 5) Question5z=y;
( 6) z.affiche();
( 7) z.affichageRenverse();
```
```
( 8) if (z.compare(y.nom))
( 9) cout << "identique\n";
(10) else cout << "different\n";
```
```
(11) return 0;
```
(12)}
// --------------------------------------------------------------------


IFT1166 Été-2K : Intra Page 12 sur 13

Q5.5 Une autre fonction compare est introduite dans la classe Question5. Définissez cette

fonction compare (en respectant le principe de l'encapsulation), qui permet de comparer les noms

de deux objets. Cette fonction accepte un seul argument du type Question5 ; et elle retourne

true, si les noms des deux objets sont identiques ; sinon false. La fonction main suivante

## montre un exemple d'utilisation de cette fonction compare (pas besoin de réécrire toute la

## définition de la classe Question5, uniquement les ajouts/modifications, s'il y en a).

# (***)

```
(1) int main() {
(2)
(3) Question5 x("navire");
(4) Question5 y("bateau");
```
```
(5) if (x.compare(y))
(6) cout << "identique\n";
(7) else cout << "different\n";
```
```
(8) return 0;
(9) }
```

IFT1166 Été-2K : Intra Page 13 sur 13


IFT1166 Trimestre Eté, 2007: Examen Intra 1/10

## Trimestre Eté, 2007

## Mohamed Lokbani

# IFT1166 – Examen Intra –

Inscrivez tout de suite votre nom et le code permanent.

Nom: __________________________________| Prénom(s): _____________________________|

Signature: ______________________________| Code perm: ____________________________|

Date : mardi 29 mai 2007

Durée : 2 heures (de 17h30 à 19h30)

Local : N-515 ; Pavillon Roger Gaudry

# Directives:

- Toute documentation permise.
- Calculatrice **non** permise.
- Répondre directement sur le questionnaire.
- Les réponses **doivent être brèves, précises et clairement présentées.**

### 1._____________________/25 (1.1, 1.2, 1.3, 1.4)

### 2._____________________/15 (2.1)

### 3._____________________/15 (3.1, 3.2, 3.3, 3.4)

### 4._____________________/20 (4.1, 4.2, 4.3, 4.4, 4.5)

### 5._____________________/25 (5.1, 5.2, 5.3)

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
### F.A.S


IFT1166 Trimestre Eté, 2007: Examen Intra 2/10

**Exercice 1 (25 points)
1.1** Expliquez brièvement les différences entre le fichier « test.o » produit par la commande « g++ -c
test.cpp –o test.o » et le fichier « test.exe » produit par la commande « g++ test.o –o test.exe ».

**1.2** Tout en expliquant brièvement votre réponse, que va retourner la commande « sizeof » pour les deux
cas suivants :

char Couleur[ ] = "violet";
sizeof(Couleur) : __________

```
char *pCouleur = "jaune";
sizeof(pCouleur) : __________
```
**1.3** Soit les déclarations suivantes :

double racine = 1.414213562, micro = 1.234e-9, mega = 1.234e9 ;

Tout en expliquant brièvement votre réponse, que vont-elles afficher en sortie les deux instructions
suivantes, indépendantes l’une de l’autre :

a)
cout << scientific << '\t' << racine << '\t' << micro << '\t' << mega << endl ;


IFT1166 Trimestre Eté, 2007: Examen Intra 3/10

b)
cout << fixed << '\t' << racine << '\t' << micro << '\t' << mega << endl ;

**1.4** Soit la fonction « Test » suivante :

```
void Test( int& intVal, double doubleVal ) {
intVal = intVal * 2;
doubleVal = double (intVal) + 3.5;
}
```
Que va afficher en sortie le fragment de code suivant :

```
int unInt = 20;
float unDble = 4.8;
Test(unInt, unDble);
cout << "unInt = " << unInt << " et unDble = " << unDble << endl;
```
(a) unInt = 20 et unDble = 43.5 (b) unInt = 40 et unDble = 4.8
(c) unInt = 20 et unDble = 4.8 (d) unInt = 40 et unDble = 43.5
(e) Aucune de ces réponses

Un seul choix possible, accompagné d’une courte explication (pourquoi celui-ci mais pas un des autres)


IFT1166 Trimestre Eté, 2007: Examen Intra 4/10

**Exercice 2 (15 points)** Soit la variable « n » du type « int » ayant une valeur initiale donnée. Écrivez les
instructions booléennes suivantes :

// « n » est entre 5 et 15, sachant que n peut être égal aussi à 5 ou 15

bool a = ;

// « n » n’est pas entre 5 et 15, sachant que n ne peut pas être égal à 5 ou 15
// (interdiction d’utiliser l’opérateur de négation «! »)

bool a = ;

// « n » est un nombre pair

bool a = ;

// « n » est un nombre impair (interdiction d’utiliser l’opérateur de négation «! »)

bool a = ;

// « n » n’est pas divisible par le nombre « 5 » (interdiction d’utiliser l’opérateur de
// négation «! »)

bool a = ;


IFT1166 Trimestre Eté, 2007: Examen Intra 5/10

**Exercice 3 (15 points)** Soit le fragment de code suivant :

bool a,b,c,d;

// fragment de code pour initialiser les variables « a », « b », « c » et « d » ...

if (a && b)
if (!c || !d)
cout << "un" << endl;
else if (d)
cout << "deux" << endl;
else
cout << "trois" << endl;
else if (c != d)
cout << "quatre" << endl;
else if (c)
cout << "cinq" << endl;
else
cout << "six" << endl;

**3.1** Le programme va-il afficher, peu importe les valeurs de « a », « b », « c » et « d », un résultat en
sortie?
(a) vrai (b) faux (c) pas de sens

Un seul choix possible, accompagné d’une courte explication (pourquoi celui-ci mais pas un des autres)

**3.2** Quel est l’ensemble de valeurs « a », « b », « c » et « d » qui va permettre l’affichage de la chaîne
« **un** »?
a b c d
(1i) true true true true
(2i) true true true false
(3i) true true false true
(4i) true true false false

(a) Toutes les combinaisons (b) Les combinaisons (1i) et (2i) uniquement
(c) Les combinaisons (1i), (2i), (3i) uniquement (d) Les combinaisons (2i) et (3i) uniquement
(e) Les combinaisons (2i), (3i), (4i) uniquement (f) Aucune de ces combinaisons

Un seul choix possible, accompagné d’une courte explication (pourquoi celui-ci mais pas un des autres)


IFT1166 Trimestre Eté, 2007: Examen Intra 6/10

**3.3** Quel est l’ensemble de valeurs « a », « b », « c » et « d » qui va permettre l’affichage de la chaîne
« **trois** »?
a b c d
(1i) true true true true
(2i) true true true false
(3i) true true false true
(4i) true true false false

(a) Toutes les combinaisons (b) Les combinaisons (1i) et (2i) uniquement
(c) Les combinaisons (1i), (2i), (3i) uniquement (d) Les combinaisons (2i) et (3i) uniquement
(e) Les combinaisons (1i), (3i), (4i) uniquement (f) Aucune de ces combinaisons

Un seul choix possible, accompagné d’une courte explication (pourquoi celui-ci mais pas un des autres)

**3.4** Quel est l’ensemble de valeurs « a », « b », « c » et « d » qui va permettre l’affichage de la chaîne
« **quatre** »?
a b c d
(1i) true false true true
(2i) false true false true
(3i) false true true false
(4i) false false false false

(a) Toutes les combinaisons (b) Les combinaisons (1i) et (2i) uniquement
(c) Les combinaisons (1i), (2i), (3i) uniquement (d) Les combinaisons (2i) et (3i) uniquement
(e) Les combinaisons (1i), (3i), (4i) uniquement (f) Aucune de ces combinaisons

Un seul choix possible, accompagné d’une courte explication (pourquoi celui-ci mais pas un des autres)


IFT1166 Trimestre Eté, 2007: Examen Intra 7/10

**Exercice 4 (20 points)** La fonction suivante permet de chercher l’élément le plus grand dans un tableau :

int maxEntree(const int* const Data, int Sz) {
if ( Data == NULL || Sz <= 0 ) return -1;
int Compteur = 1;

// initialiser « unptr » pour pointer le premier élément
// du tableau
const int *unptr = **_______________** ;

// initialiser ptrcourant pour pointer le second élément
// du tableau sans modifier les autres variables
const int *ptrcourant = **________________** ;

for ( ; Compteur < Sz; **______________** ) {
if ( **________________** )
unptr = ptrcourant;
}
return ( **_____________________** );
}

```
//1
//2
//3
```
```
//4
```
```
//5
```
```
//6
//7
//8
```
```
//9
```
**4.1** Complétez la ligne « **4** » du programme

(a) Data (b) *Data
(c) &Data (d) Data[0]

Un seul choix possible, accompagné d’une courte explication (pourquoi celui-ci mais pas un des autres)

**4.2** Complétez la ligne « **5** » du programme

(a) unptr (b) unptr++
(c) Data++ (d) &Data[1]
(e) Data[1]

Un seul choix possible, accompagné d’une courte explication (pourquoi celui-ci mais pas un des autres)


IFT1166 Trimestre Eté, 2007: Examen Intra 8/10

**4.3** Complétez la ligne « **6** » du programme ( **attention : cette question est dépendante de la question 4.4** )

(a) Compteur++ (b) ptrcourant++
(c) Compteur++, ptrcourant++ (d) Doit être laissée vide

Un seul choix possible, accompagné d’une courte explication (pourquoi celui-ci mais pas un des autres)

**4.4** Complétez la ligne « **7** » du programme

(a) ptrcourant > unptr (b) &ptrcourant > &unptr
(c) *ptrcourant > *unptr (d) *ptrcourant < *unptr

Un seul choix possible, accompagné d’une courte explication (pourquoi celui-ci mais pas un des autres)

**4.5** Complétez la ligne « **9** » du programme

(a) *unptr (b) &unptr
(c) unptr (d) Doit être laissée vide

Un seul choix possible, accompagné d’une courte explication (pourquoi celui-ci mais pas un des autres)


IFT1166 Trimestre Eté, 2007: Examen Intra 9/10

**Exercice 5 (25 points)** Le fragment de code suivant déclare et initialise deux structures identiques
« UnTruc1 » et « UnTruc2 ». Il appelle la méthode « doublerA » pour doubler la valeur des membres de la
structure « UnTruc1 » et la méthode « doublerB » pour doubler la valeur des membres de la structure
« UnTruc2 ». Le but de cet exercice est de comparer ces deux approches.

typedef struct {
int x;
int y;
} UnTruc;

int main(){
UnTruc UnTruc1, UnTruc2;
UnTruc1.x = UnTruc2.x = 10;
UnTruc1.y = UnTruc2.y = 250;
UnTruc1 = doublerA(UnTruc1);
doublerB(&UnTruc2);
cout << "UnTruc1.x = " << UnTruc1.x << ", UnTruc2.x = " << UnTruc2.x << endl;
cout << "UnTruc1.y = " << UnTruc1.y << ", UnTruc2.y = " << UnTruc2.y << endl;
return 0;
}

Quand le programme est complété et exécuté, il produit l’affichage suivant en sortie :

UnTruc1.x = 20, UnTruc2.x = 20
UnTruc1.y = 500, UnTruc2.y = 500

**5.1** Quel est la fonction « doublerA » ou « doublerB » qui consomme le plus de temps et d’espace?
Expliquez pourquoi?

**5.2** Complétez le programme en écrivant le code complet des fonctions « doublerA » et « doublerB » ainsi
que leur prototype.


IFT1166 Trimestre Eté, 2007: Examen Intra 10/10

**5.3** Soit le fragment de code suivant :

UnTruc *faireUnTruc(int a, int b){
UnTruc UnTruc;
UnTruc.x = a;
UnTruc.y = b;
return &UnTruc;
}
int main(){
UnTruc *p;
p = faireUnTruc(5, 50);
cout << "p->x = " << p->x << ", p->y = " << p->y << endl;
}

```
typedef struct {
int x;
int y;
} UnTruc;
```
Le programmeur a eu comme intention d’utiliser la fonction « faireUnTruc » pour créer une structure dont
ses paramètres vont être initialisés avec les paramètres passés en argument de la fonction i.e. « a » et « b » ;
et de retourner un pointeur vers cette nouvelle structure créée. Cette nouvelle structure sera accessible
ailleurs dans le programme comme dans la méthode « main ». Ainsi le programme pourrait afficher en
sortie :

p->x = 5, p->y = 50

Cependant il y a un problème mémoire avec la fonction « faireUnTruc »! Heureusement que le
compilateur « g++ » l’a repéré et il nous a affiché un message d’avertissement au moment de la
compilation du programme.
Décrivez la nature du problème et récrivez le cœur de la fonction « faireUnTruc » pour corriger ce
problème. Attention l’entête de la fonction « faireUnTruc » doit rester la même.


IFT1166 Trimestre Été, 2008: Examen Intra 1/10

## Trimestre Été, 2008

## Mohamed Lokbani

# IFT1166 – Examen Intra –

Inscrivez tout de suite votre nom et le code permanent.

Nom: __________________________________| Prénom(s): _____________________________|

Signature: ______________________________| Code perm: ____________________________|

Date : mercredi 4 juin 2008

Durée : 2 heures (de 17h30 à 19h30)

Local : Z-317 ; Pavillon Claire McNicoll

# Directives:

- Toute documentation permise.
- Calculatrice **non** permise.
- Répondre directement sur le questionnaire.
- Les réponses **doivent être brèves, précises, claires**
    **et nettement présentées.**

### 1._____________________/08 (1.1, 1.2, 1.3, 1.4)

### 2._____________________/20 (2.1, 2.2, 2.3, 2.4)

### 3._____________________/12 (3.1, 3.2, 3.3, 3.4)

### 4._____________________/20 (4.1, 4.2)

### 5._____________________/20 (5.1, 5.2)

### 6._____________________/20 (6.1)

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
### F.A.S


IFT1166 Trimestre Été, 2008: Examen Intra 2/10

**Exercice 1 (08 points)** Encerclez la bonne réponse et donnez une courte explication.

**1.1** [Vrai | Faux] Le langage C++ est apparu après le langage Java?

**1.2** [Vrai | Faux] Pour utiliser le manipulateur de flux « setprecision() », il faudra inclure le fichier d’en-
tête « iostream »?

**1.3** [Vrai | Faux] L’expression à évaluer dans l’instruction de contrôle « switch » peut avoir n’importe quel
type?

**1.4** [Vrai | Faux] Nous ne pouvons passer un paramètre à une fonction que de deux manières différentes?

**Exercice 2 (20 points)** Tout ce qui suit est syntaxiquement correct (compile et s’exécute correctement)

**2.1** À l’aide d’un exemple, expliquez le rôle joué par la macro suivante :

(^01) #define A(x) ((x==0)?0:1)


IFT1166 Trimestre Été, 2008: Examen Intra 3/10

**2.2** Tout en détaillant votre réponse, que va afficher en sortie le fragment suivant :

```
01
02
03
04
05
06
```
```
enum Semaine {Lu, Mar, Mer, Je, Ve, Sa, Di};
Semaine a[] = { Mer, Je, Mar, Di, Ve };
for (int i = 0; i < 5; i++)
a[i] = a[a[i]];
for (int i = 0; i < 5; i++)
cout << "a[" << i << "]= " << a[i] << endl;
```
**2.3** À l’aide d’un exemple, quel est le rôle joué par cette macro?

(^01) #define B(x,i) ((x)|(1<<(i)))
**2.4** Tout en détaillant votre réponse, à quoi sert la fonction suivante :
01
02
03
04
05
06
int A(const char *s1, const char *s2) {
while ((*s1 != ’\0’) && (*s1 == *s2)) {
s1++; s2++;
}
return *s1 - *s2;
}


IFT1166 Trimestre Été, 2008: Examen Intra 4/10

**Exercice 3 (12 points)** Soit « x » un nombre non signé initialisé avec la valeur « 5 ». Ce nombre est
représenté comme suit sur 1 octet : « 00000101 ». Tout en développant votre réponse, dites ce que vont
afficher en sortie les fragments de code suivants :

**3.1** unsigned char c = 5;
(c << 2) << endl;

**3.2** unsigned char c = 5;
unsigned char x = ~c;
cout << (int) x << endl;

**3.3** unsigned char c = 5;
cout << (c & 2) << endl;

**3.4** unsigned char c = 5;
cout << (c | 12) << endl;


IFT1166 Trimestre Été, 2008: Examen Intra 5/10

**Exercice 4 (20 points)** Tout en développant votre réponse, que vont afficher en sortie les fragments de
code suivants qui compilent et s’exécutent correctement (dans un programme complet).

### 4.1

```
01
02
03
04
```
```
char s[]="CHAINE", *p=s+3;
cout << p << endl;
cout << p[-1] << endl;
cout << --*++p << endl;
```
### 4.2

```
01
02
03
04
05
06
07
08
```
```
int a[4]={10,20,30,40};
cout << a[1/2] << endl;
int* ptr=a+1;
cout << a-ptr << endl;
cout << ptr[1] << endl;
const int& r = *ptr;
cout << r+1 << endl;
cout << --*++ptr << endl;
```

IFT1166 Trimestre Été, 2008: Examen Intra 6/10

**Exercice 5 (20 points)** Le programme suivant compile correctement. Mais lors de son exécution, il
plante royalement et affiche en sortie le message suivant « Segmentation fault (core dumped) ». Ce
message correspond à un incident de segmentation.

**5.1** Expliquez brièvement l’une des causes d’une telle erreur.

**5.2** Tout en développant votre réponse, corrigez les différentes erreurs conceptuelles pour que le
programme puisse s'exécuter correctement et faire ce qu’il est supposé i.e. déclarer une structure, initialiser
les éléments de la structure et afficher ces éléments en sortie. Vous pouvez inclure de nouvelles instructions
si vous le jugez nécessaire. Dans ce cas, précisez entre quelles lignes.

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
```
```
using namespace std;
```
```
typedef struct {
char *nom;
char *prenom;
int age;
} type_fiche;
```
```
int main(){
type_fiche *fiche=NULL;
```
```
fiche->nom = new char;
```
```
strcpy(fiche->nom, "Sasseur");
```
```
strcpy(fiche->prenom, "Marlene");
```
```
fiche->age = 3;
```
```
cout << "Nom: " << fiche->nom << endl;
cout << "Prenom: " << fiche->prenom << endl;
cout << "Age: " << fiche->age << endl;
```
```
return 0;
}
```

IFT1166 Trimestre Été, 2008: Examen Intra 7/10


IFT1166 Trimestre Été, 2008: Examen Intra 8/10

**Exercice 6 (20 points)** Écrivez un programme C++ qui réalise ce qui suit :
1- Il inverse d’abord l’ordre des arguments entrés sur la ligne de commandes sauf l’argument « 0 » qui
représente le nom du programme. Par exemple si la ligne de commandes contenait la suite [arg1, arg2,
arg3, arg4], le résultat sera [arg4, arg3, arg2, arg1].
2- Il inverse par la suite l’ordre des caractères pour chaque argument. Par exemple si l’argument 3
contenait la chaîne « exemple », le résultat sera « elpmexe ».
3- Une fonction « main » pour tester ces fonctionnalités.

Vous ne pouvez utiliser aucune fonction de la librairie « C » (par extension « C++ ») permettant de
manipuler les chaînes de caractères. Vous devez réinventer la roue s’il le faut!


IFT1166 Trimestre Été, 2008: Examen Intra 9/10


IFT1166 Trimestre Été, 2008: Examen Intra 10/10


IFT1166 H-2K : Intra 1/14

## IFT1166 - Session Hiver, Intra

## Mohamed Lokbani

# IFT1166 - INTRA

Nom:___________________________________| Prénom(s):_____________________________|

Signature:_______________________________| Code perm:_____________________________|

Date:16 Février 2K

Durée: 2 heures (de 18h30 à 20h30) Local: P-310

# Directives:

- Il vous est permis d'utiliser un livre de votre choix.
- Les documents de cours ne sont pas autorisés.
- Ordinateurs personnels prohibés.
- Calculatrice (simple) permise.
- Répondre directement sur le questionnaire.

### 1._____________________/20

### 2._____________________/10

### 3._____________________/20

### 4._____________________/20

### 5._____________________/30

Total:__________________/100


IFT1166 H-2K : Intra 2/14

Question 1 (20 points)

-Q1.1- Définir l'encapsulation.

-Q1.2- La déclaration suivante est-elle valide?

double f(double z=10.7,char* s);

vrai faux

Dans le cas ou c'est faux, pourquoi?

-Q1.3- Quel est le rôle d'un constructeur?


IFT1166 H-2K : Intra 3/14

-Q1.4- Quand et pourquoi faut-il définir votre propre constructeur de recopie, au lieu de se contenter du
constructeur de recopie par défaut?

-Q1.5- Quand un destructeur n'est pas appelé? (cochez une ou plusieurs réponses, pas besoin de
justifications)

a. une variable locale quitte sa portée

b. delete

c. delete [ ]

d. aucune des précédentes réponses.

-Q1.6- Vers quoi pointe le pointeur "this"?


IFT1166 H-2K : Intra 4/14

- Q1.7- Dans les déclarations suivantes, quels sont les expressions vraies, si Ptr1 et Ptr2 pointe vers le
même objet, et pourquoi? (cochez une ou plusieurs réponses)

a. Ptr1 == Ptr2

vrai faux

pourquoi?

b. *Ptr1 == *Ptr2

vrai faux

pourquoi?

c. *(Ptr1 == *Ptr2)

vrai faux

pourquoi?

d. &Ptr1 == &Ptr2

vrai faux

pourquoi?


IFT1166 H-2K : Intra 5/14

## Question 2 (10 points)

Que vont afficher les déclarations suivantes, en cas d'erreur de syntaxe, expliquez l'erreur et corrigez-la.

# Représentez le retour à la ligne (retour chariot) par le signe ↙↙↙↙:

## a. cout << "Message:\n\"Bonjour!\"\n";

## b. cout << "Message:" << endl << "Bonjour!" << endl;

## c. cout << "Message:\n\"Bonjour!\n";

## d. cout << "Message:\n"Bonjour!"" << endl;

## e. cout << "\Message:\" << endl << "\Bonjour!\" << endl;


IFT1166 H-2K : Intra 6/14

Question 3 (20 points)

- Q3.1-

Tout en développant votre réponse sur la feuille d'examen, indiquez le résultat du programme suivant.

#include <iostream.h>

```
void f(int& x, int& y)
{
x+=10;
y-=5;
}
```
```
int main()
{
intx=8;
inty=9;
```
```
f(x,y);
cout << x <<''<<y<<endl;
```
```
f(y,x);
cout << x <<''<<y<<endl;
```
```
return 0;
}
```

IFT1166 H-2K : Intra 7/14

- Q3.2-

Tout en développant votre réponse sur la feuille d'examen, indiquez le résultat du programme suivant.

#include <iostream.h>

void f(int& x, int* y) {
x+=20;
*y -= 10;
}

void f(int* x, int y) {
*x += 20;
y-=10;
}

int main() {
intx=8;
inty=9;

```
f(x,&y);
cout << x <<''<<y<<endl;
```
```
f(&y,x);
cout << x <<''<<y<<endl;
```
return 0;
}


```
IFT1166 H-2K : Intra 8/14
```
Question 4 (20 points)

```
Soit le programme suivant:
```
```
#include <iostream.h>
```
```
class Z {
public:
Z(int x) {
v=x;
cout << "constructeur" << endl;
}
Z(const Z& D) {
v = D.v;
cout << "recopie" << endl;
}
~Z() {
cout << "destructeur" << endl;
}
private:
int v;
};
```
```
int main() {
```
```
Z r(3); // (a)
Z *pz = new Z(18); // (b)
```
```
delete pz; // (c)
```
```
Z t(r); // (d)
Zs=r;//(e)
```
```
// r.v = 200; (f)
```
```
return 0;
}// (g)
```
```
-Q4.1- Donner les lignes de la fonction main où sont appelés les constructeurs de Z, en indiquant à chaque
fois le nom de l'objet crée (si plusieurs objets sont crées pour une même ligne, indiquez-les tous):
```
```
(a) (b) (c) (d) (e) (f) (g)
```
```
Z::Z(int)
```
```
Z::Z(const Z&)
```
```
lignes
```
constructeurs


IFT1166 H-2K : Intra 9/14

-Q4.2- Indiquer les lignes de la fonction main, où est appelé le destructeur de Z, en indiquant à chaque
fois le nom de l'objet détruit (si plusieurs objets sont détruits pour une même ligne, indiquez-les tous).

(a) (b) (c) (d) (e) (f) (g)

-Q4.3- Indiquer ce qu'écrit le programme en sortie:

-Q4.4- Que se passe-t-il si on enlève les commentaires de la ligne (f) du programme précédent (détaillez
vôtre réponse)?


IFT1166 H-2K : Intra 10/14

Question 5 (30 points)

La classe Instrument contient ce qui suit:

données membres private:

```
char* nom; // nom de l'instrument
double prix; // le prix de l'instrument
```
fonctions membres public:

```
affiche : permet d'afficher les données membres de la classe Instrument.
```
```
meme_prix: une fonction booléenne permettant de comparer si deux Instruments coûtent le
même prix. Elle retourne true, si c'est vrai, sinon false dans le cas contraire.
```
Q5.1 Écrire la définition de la classe Instrument, pour permettre les opérations décrites dans le main
suivant:

int main() {

```
Instrument A("Saxophone",750.80);
```
```
InstrumentB=A;
```
```
B.affiche();
```
```
Instrument C("Guitare",380.95);
```
```
if (C.meme_prix(B)){
cout << "la guitare/le saxophone, meme prix!\n";
} else {
cout << "la guitare/le saxophone, prix different!\n";
}
```
return 0;
}

Q5.2 Tout en tenant compte de la définition de votre fonction affiche de la classe Instrument,
indiquez le résultat de l'affichage.


IFT1166 H-2K : Intra 11/14


IFT1166 H-2K : Intra 12/14


IFT1166 H-2K : Intra 13/14


IFT1166 H-2K : Intra 14/14


IFT1166 Hiver-2001 : Intra Page 1 sur 12

IFT1166 - Session Hiver 2001, Intra

Mohamed Lokbani

Nom:___________________________________| Prénom(s):_____________________________|

Signature:_______________________________| Code perm:_____________________________|

Date: 20 février 2001

Durée: 2 heures (de 18h30 à 20h30) Local: E-310

Directives:

- Toute documentation permise.
- Calculatrice et ordinateur personnel prohibés.
- Répondre directement sur le questionnaire.

```
Bon courage!
```
Exercices Questions

### 1._____________________/15 A ~ B ~ C ~ D ~ E

### 2._____________________/15 A

### 3._____________________/20 A~ B ~ C

### 4._____________________/21 A

### 5._____________________/29 A ~ B~ C~ D~ E~ F

Total:__________________/100


IFT1166 Hiver-2001 : Intra Page 2 sur 12

Question 1 (15 points)

Q1.A- Quelle est la différence entre struct et class?

Q1.B- Un constructeur peut-il retourner une valeur? OUI NON

Pourquoi?

Q1.C- Peut-on créer une instance d'une classe si la classe n'a que des constructeurs privés?
OUI NON

Pourquoi?

Q1.D- Les membres d'une classe ont-ils accès aux autres membres de la classe quelque soit leur

droits d'accès?

OUI NON

Pourquoi?

Q1.E- Qu'est-ce qu'une fonction membre qualifiée const? Pour quels types d'objets (const ; non

const) peut-on l'appeler?


IFT1166 Hiver-2001 : Intra Page 3 sur 12

Question 2 (15 points)

Soit le fragment de code suivant:

char *p; // ligne -1-
const char *q; // ligne -2-

char &r; // ligne -3-
char t[10]; // ligne -4-

q = p; // ligne -5-
r = p; // ligne -6-

char &s = *p; // ligne -7-
p = &s; // ligne -8-

s = p; // ligne -9-
p = s; // ligne -10-

s = *p; // ligne -11-
*p = s; // ligne -12-

t = p; // ligne -13-
p = t; // ligne -14-
*t = *p; // ligne -15-

Indiquez, pour chacune des lignes précédentes:

Lignes syntaxiquement correctes (encerclez les correctes):

```
123456789101112131415
```
Lignes syntaxiquement incorrectes (barrez les incorrectes):

```
123456789101112131415
```
Dans le cas des lignes incorrectes, dites pourquoi ces lignes sont syntaxiquement incorrectes et

corrigez-les.


IFT1166 Hiver-2001 : Intra Page 4 sur 12

Question 3 (20 points)

Soit le fragment de code suivant:

#include <iostream.h>

#define CALCUL(x,y) (x+y*2)

int main() {

```
int i = CALCUL(3,5);
cout << "valeur de i: " << i;
```
int j = CALCUL(3, 2+3);
cout << " ; valeur de j: " << j << endl;
return 0;
}

Q3.A- Indiquez ce qu'écrit en sortie le programme précédent.

Q3.B- La macro CALCUL provoque-t-elle une erreur de calcul?

OUI NON

Pourquoi?

Q3.C- Dans le cas où la macro CALCUL provoque effectivement une erreur de calcul, proposez
deux solutions pour corriger le problème.

```
Proposition -1- Proposition -2-
```

IFT1166 Hiver-2001 : Intra Page 5 sur 12

Question 4 (21 points)

Tout en développant votre réponse sur page suivante, indiquer ce qu'écrit en sortie, le programme

suivant:

#include <iostream.h>

void change (int&, int&);
void melange (int, int&);

int main (){

```
int numl = 4;
int num2 = 4;
```
```
cout << numl <<""<<num2 << "\n";
```
```
change (numl, num2);
```
```
cout << numl <<""<<num2 << "\n";
```
return 0;
}

void change (int& val1, int& val2){

```
cout << val1 <<""<<val2 << "\n";
```
```
melange (val1, val2);
```
```
cout << val1 <<""<<val2 << "\n";
```
```
melange (val2, val1);
```
```
cout << val1 <<""<<val2 << "\n";
```
### }

void melange (int val1, int& val2){

```
cout << val1 <<""<<val2 << "\n";
```
```
val1 = val1 - 1;
val2 = val2 - 1;
```
```
cout << val1 <<""<<val2 << "\n";
```
}

```
Réponse
```
```
num1: num2:
```
```
num1: num2:
```
```
val1: val2:
```
```
val1: val2:
```
```
val1: val2:
```
```
val1: val2:
```
```
val1: val2:
```

IFT1166 Hiver-2001 : Intra Page 6 sur 12


IFT1166 Hiver-2001 : Intra Page 7 sur 12

Question 5 (29 points)

Soit le programme suivant:

#include <iostream.h>

typedef enum SEXE {feminin, masculin};
char* tab_sexe[] = {"feminin","masculin"};

typedef struct date {
int jour;
int mois;
int annee;
} DATE;

typedef struct gene {
DATE date_naiss;
DATE date_mort;
} GENE;

typedef struct musicien {
char *prenom;
char *nom;
SEXE sexe;
GENE sadate;
} Musicien;

void affiche(Musicien chef[],int taille) {

for (int i=0; i<taille; i++){
cout << "nom: " << chef[i].nom << endl;
cout << "prenom: " << chef[i].prenom << endl;
cout << "sexe: " << tab_sexe[chef[i].sexe] << endl;
cout << "Naissance (j/m/a): "
<< chef[i].sadate.date_naiss.jour << "/"
<< chef[i].sadate.date_naiss.mois << "/"
<< chef[i].sadate.date_naiss.annee << endl;
cout << "Deces (j/m/a): "
<< chef[i].sadate.date_mort.jour << "/"
<< chef[i].sadate.date_mort.mois << "/"
<< chef[i].sadate.date_mort.annee << endl;
}
}

int main(){
Musicien MJazz[6] = {
{"Louis", "Armstrong",masculin,{{4,8,1901},{6,7,1971}}},
{"Ella", "Fitzgerald",feminin,{{25,4,1917},{15,6,1996}}},
{"Miles", "Davis",masculin,{{26,5,1926},{28,9,1991}}},
{"Duke", "Ellington",masculin,{{29,4,1899},{24,5,1974}}},
{"Charles", "Mingus",masculin,{{22,4,1922},{5,1,1979}}},
{"Charlie", "Parker",masculin,{{29,8,1920},{12,3,1955}}},
};
affiche(MJazz,6);
return 0;
}


IFT1166 Hiver-2001 : Intra Page 8 sur 12

Q5.A- Tout en préservant le format d'affichage en sortie obtenu suite à l'appel de la fonction

affiche dans la fonction main, écrire la définition de la fonction affiche spécifique pour

chaque structure.

affiche de date

affiche de gene

affiche de musicien


IFT1166 Hiver-2001 : Intra Page 9 sur 12

Q5.B- Réécrire la fonction affiche globale pour tenir compte des modifications apportées dans la

question Q5.A.

Q5.C- Écrire les classes date, gene et musicien, en tenant compte des contraintes suivants:

- uniquement la déclaration des classes (pas besoin de définir les méthodes).
- principe d'encapsulation des données.


IFT1166 Hiver-2001 : Intra Page 10 sur 12


IFT1166 Hiver-2001 : Intra Page 11 sur 12

Q5.D- écrire la définition des constructeurs des classes date, gene et musicien.

date

gene

musicien


IFT1166 Hiver-2001 : Intra Page 12 sur 12

Q5. E- Réécrire la fonction main pour tenir compte de toutes les modifications apportées

auparavant.

Q6. F- Réécrire la fonction affiche globale.


IFT1166 Hiver-2004 : Intra 1/12

## IFT1166 - Session Hiver, Intra

## Mohamed Lokbani

# IFT1166 - INTRA

Inscrivez tout de suite votre nom et code permanent.

Nom: __________________________________| Prénom(s): _____________________________|

Signature: ______________________________| Code perm: ____________________________|

Date : 28 février 2004

Durée: 2 heures (de 10h30 à 12h30) Local: Z-330 du Pavillon Claire-McNicoll (ancienne aile Z).

# Directives:

- Toute documentation permise.
- Calculatrice non permise.
- Répondre directement sur le questionnaire.
- Les réponses doivent être clairement présentées.

### 1._____________________/15 (1.1 ; 1.2 ; 1.3 ; 1.4 ; 1.5)

### 2._____________________/15 (2.1 ; 2.2 ; 2.3 ; 2.4 ; 2.5 ; 2.6 ; 2.7 ; 2.8)

### 3._____________________/20 (3.1 ; 3.2 ; 3.3 ; 3.4)

### 4._____________________/20 (4.1)

### 5._____________________/30 (5.1)

Total:__________________/100


IFT1166 Hiver-2004 : Intra 2/12

Question 1 (15 points)

1.1 Où sont fixées les valeurs des paramètres par défaut? Dans la déclaration ou dans la définition des
fonctions? Pourquoi?

1.2 Quelles différences y a-t-il entre un passage par valeur, un passage par adresse et un passage par
référence pour la valeur de retour d'une fonction?

1.3 Quand passe-t-on un paramètre par référence? Quand passe-t-on un paramètre par référence
constante?

1.4 Pourquoi faut-il préférer le compilateur au préprocesseur?

1.5 Quelle différence y a-t-il entre une copie profonde et une copie superficielle?


IFT1166 Hiver-2004 : Intra 3/12

Question 2 (15 points) Soit le fragment de code suivant:

```
namespace Noir {
int j;
void print(int);
char ch;
}
namespace Blanc {
int j;
void print(int);
double vision;
}
```
```
int j;
```
void UneFonction() {
using namespace Noir;
using namespace Blanc;
j = 0; // -1-
print(5); // -2-
ch = 'a'; // -3-
vision = 7.65; // -4-
int j = 10; // -5-
::j = 5; // -6-
Blanc::j = 5; // -7-
Noir::print(j); // -8-
}
Tout en justifiant votre réponse, dites si les appels -1- à -8- sont corrects ou pas? (Chaque question est
indépendante.)

2.1 j = 0;
Correct Incorrect

Pourquoi? (Courte explication)

2.2 print(5);

Correct Incorrect

Pourquoi? (Courte explication)

2.3 ch = 'a';
Correct Incorrect

Pourquoi? (Courte explication)


IFT1166 Hiver-2004 : Intra 4/12

2.4 vision = 7.65;
Correct Incorrect

Pourquoi? (Courte explication)

2.5 int j = 10;
Correct Incorrect

Pourquoi? (Courte explication)

2.6 ::j = 5;
Correct Incorrect

Pourquoi? (Courte explication)

2.7 Blanc::j = 5;
Correct Incorrect

Pourquoi? (Courte explication)

2.8 Noir::print(j);
Correct Incorrect

Pourquoi? (Courte explication)


IFT1166 Hiver-2004 : Intra 5/12

Question 3 (20 points)

3.1 Tout en justifiant votre réponse, que va afficher en sortie le programme suivant, qui compile et
s’exécute correctement.

```
#include <iostream>
void sosie(int) ;
void sosie(double) ;
```
```
using namespace std ;
```
```
int main() {
int n = 5;
double x = 2.5 ;
sosie(n) ;
sosie(x) ;
return 0 ;
}
void sosie (int a) { // sosie -1-
cout << "sosie 1 a = " << a << endl;
}
void sosie (double a) { // sosie -2-
cout << "sosie 2 a = " << a << endl;
}
```
3.2 Tout en justifiant votre réponse, quelle fonction sosie, du précédent programme, est appelée dans les
cas suivants?
char c ; float y ;

sosie (c);

sosie (y);

sosie ('d');

```
sosie -1-
```
sosie -2- (^)
sosie -1- (^)
sosie -2- (^)
sosie -1-
sosie -2-


IFT1166 Hiver-2004 : Intra 6/12

3.3 Quelle fonction est appelée avec ces déclarations?

void affiche (char*) ; // affiche -1-
void affiche (void*) ; // affiche -2-
char *py ; double *px ;

affiche (py);

affiche (px);

3.4 Quelle fonction est appelée avec ces déclarations?

void choix (int &) ; // choix -1-
void choix (const int &) ; // choix -2-
int n=3 ; const int p=5 ;

choix (n);

choix (p);

choix (12);

affiche -1- (^)
affiche -2- (^)
affiche -1- (^)
affiche -2- (^)
choix -1- (^)
choix -2- (^)
choix -1-
choix -2-
choix -1-
choix -2- (^)


IFT1166 Hiver-2004 : Intra 7/12

Question 4 (20 points)

Cette classe contient des erreurs de syntaxe et des avertissements ("warnings"). Indiquez-les et précisez les,
puis proposez une correction possible. Les numéros de ligne qui figurent au début de chaque ligne ne font
pas partie du code et servent à identifier clairement les erreurs.

### 1 2 3 4 5 6 7 8 9

### 10

### 11

### 12

### 13

### 14

### 15

### 16

### 17

### 18

### 19

### 20

```
class VivementCeSoir {
```
```
int i = 19;
int k;
int j = 15.2;
```
```
public
int uneFonction (int i) {
int j;
k = i;
if (k<2) return 3;
cout << "j=" << j << endl;
}
```
```
int uneAutre () {
cout << "k=" << k << endl;
int i = 15;
if (i>15) return 5;
else {
for (int i=0; i<15; i++) k++;
}
}
}
```

IFT1166 Hiver-2004 : Intra 8/12


IFT1166 Hiver-2004 : Intra 9/12

Question 5 (30 points)

Cet exercice a pour but l'implantation d'un type abstrait Ensemble en C++. Vous allez pour cela concevoir
quelques méthodes de la classe Ensemble et un (ou plusieurs) fragment de programme permettant de
tester ces méthodes.
Les seuls ensembles considérés ici sont des ensembles d'entiers. Un ensemble est représenté par un tableau
d'entiers (ensemble) dont le nombre maximal d'éléments est spécifié par l'utilisateur de la classe au moment
de la création d'un objet de type Ensemble. Par exemple l'ensemble {10, 1234, 56} est représenté par une
table d'entiers dont le premier élément (indice 0) est 10, le deuxième élément (indice 1) est 1234 et le
troisième élément (indice 2) est 56.

Il vous est demandé de concevoir les méthodes suivantes:

- boolean appartient(int element): Cette méthode retourne vrai si l'élément passé en argument (ici element)
appartient à l'ensemble; faux sinon.
- int getSize(): Cette méthode retourne le nombre d'éléments contenus dans l'ensemble.
- void ajouter(int element): Cette méthode permet d'ajouter l'élément (element) dans l'ensemble s'il n'existe
pas déjà.
- Ensemble union(Ensemble e): Cette méthode crée un nouvel ensemble constitué de l'union de l'ensemble
«appellant » avec celui passé en argument.

Vous pouvez ajouter autant de données et de méthodes membres que vous le souhaitez.

Attention : Il ne vous est pas permis d’utiliser les fonctionnalités de la bibliothèque STL.


IFT1166 Hiver-2004 : Intra 10/12


IFT1166 Hiver-2004 : Intra 11/12


IFT1166 Hiver-2004 : Intra 12/12


IFT1166 Hiver-2005: Intra 1/10

## IFT1166 - Session Hiver, Intra

## Mohamed Lokbani

# IFT1166 - INTRA

Inscrivez tout de suite votre nom et code permanent.

Nom: __________________________________| Prénom(s): _____________________________|

Signature: ______________________________| Code perm: ____________________________|

Date : 8 mars 2005

Durée: 2 heures (de 18h30 à 20h30) Local: Z-330 du Pavillon Claire-McNicoll (ancienne aile Z).

# Directives:

- Toute documentation permise.
- Calculatrice **non** permise.
- Répondre directement sur le questionnaire.
- Les réponses **doivent être brèves, précises et clairement présentées.**

1._____________________/15 (1.1 a, b ; 1.2 a, b)

### 2._____________________/15 (2.1, 2.2, 2.3, 2.4, 2.5)

### 3._____________________/20 (3.1)

### 4._____________________/15 (4.1)

### 5._____________________/35 (5.1)

Total:__________________/100


IFT1166 Hiver-2005: Intra 2/10

**Question 1 (15 points)** Soit la fonction suivante :

```
int& UneFonction(int &k) {
return k;
}
```
**1.1** Soit la déclaration « int i = 20 ; ».

```
a) Quelle sera la valeur de la variable i après l’exécution du code suivant :
UneFonction(i)=42;
```
```
i =
Pourquoi? (Courte explication)
```
```
b) L’instruction suivante est-elle correcte? Si oui, que fait-elle au juste?
UneFonction(i)++;
```
```
Correct Incorrect
```
```
Pourquoi? (Courte explication)
```
**1.2** Supposer maintenant que le prototype de la fonction « UneFonction » est comme suit :

**int& UneFonction(int k)** ; le code de la fonction reste le même. Sachant aussi que « int g =
52; »

```
a) Quelle sera la valeur de la variable j dans ce qui suit :
int j = UneFonction(g);
```
```
j =
Pourquoi? (Courte explication)
```

IFT1166 Hiver-2005: Intra 3/10

```
b) L’instruction suivante est-elle correcte? Si oui, que fait-elle au juste?
int j = UneFonction(g)++;
```
```
Correct Incorrect
j =
Pourquoi? (Courte explication)
```
**Question 2 (15 points)** Soient les deux fonctions :

**Test -1- Test -2-**
void Test(char *msg, int cnt = 3, char *post = "!"){
cout << msg;
while(cnt--) cout << post;
cout << endl;
}

```
void Test(char *msg, char *post){
Test(msg, 3, post);
}
```
Tout en justifiant votre réponse, quelle fonction « Test - ?-» est appelée dans les cas 4.1, 4.2 et 4.3. Et que
va-t-elle afficher en sortie?

**2.1** Test("Salut");

**2.2** Test("Huh","?");

```
Test -1-
```
**Test -2-** (^)
**Test -1-** (^)
**Test -2-** (^)


IFT1166 Hiver-2005: Intra 4/10

**2.3** Test("Arrrggggg", 5, "h");

**2.4** Est-ce que la fonction « Test-2- » est une fonction récursive?

**2.5** Que se passera-t-il pour l’appel « Test("Salut"); » si on changeait le prototype de « Test -2- »

comme suit : void Test(char *msg, char *post = "!")?

**Test -1-** (^)
**Test -2-** (^)


IFT1166 Hiver-2005: Intra 5/10

**Question 3 (20 points)** Identifier **toutes** les erreurs de **syntaxe** et de **logique** dans le code suivant.

```
1 include <iostream,h>
2
3 typedef true = 1;
4 typedef false = 0;
5 const int Boolean;
6
7 vold main(){
8 char quitter;
9 char montab{20};
10
11 while (quitter = false) {
12 cout << "Entrer q pour quitter ou c pour continuer" << endl;
13 cin >> quiltter;
14
15 if (quitter != q) init_arr(montab);
16 else compteur++;
17 }
18 cout << Compte " << compteur << " passes " endl;
19 }
20
21 int init_arr(char arr[20]);
22
23 int init_arr(char arr[20]);{
24 int arr = 7;
25 for (int ascii = 32; ascii < 52; ascii++) {
26 arr[i] = char(ascii);
27 }
28 return(arr);
29 }
```
Les réponses doivent être sous cette forme :

Ligne No : ...............
Erreur : ..................
Courte explication et suggestion de solution si c’est possible: .................................................


IFT1166 Hiver-2005: Intra 6/10


IFT1166 Hiver-2005: Intra 7/10

**Question 4 (15 points)** On suppose les déclarations suivantes :

```
const int MAXSIZE = 80;
```
```
typedef char StringTab[MAXSIZE];
```
```
typedef struct {
StringTab chaine;
int taille_actuelle;
} StringType;
```
```
void StringEncrypte(StringType str1, StringType str2);
```
Vous devez écrire le code de la fonction **StringEncrypte** , qui crypte chacun des caractères du premier
argument, **str1** , de la manière suivante :

Pour tout **i** , la nouvelle valeur de **str1[i]** sera égale à :
**char ((int(str1[i]) + int(str2[i])) % 128)**.

Si la chaîne **str1** est plus longue que la chaîne **str2** , le caractère espace blanc prendra la place des
caractères manquants de **str2**.


IFT1166 Hiver-2005: Intra 8/10

**Question 5 (35 points)** Écrire un programme complet en C++ qui calcule les diviseurs positifs d’un
nombre entier. Le résultat sera affiché sur une seule colonne et par ordre décroissant.

Au lancement, le programme doit décrire comment il doit être utilisé. Par la suite, il demande à l’usager
d’entrée un nombre entier. Le programme doit permettre à l'utilisateur de répéter ce processus autant de fois
qu’il désire. Le programme se comporte comme suit, si :

-1- L’utilisateur entre un nombre entier négatif ou nul. Dans ce cas, vous devez indiquer à l’utilisateur que
les valeurs entrées sont erronés et que vous n’acceptez que des valeurs positives. Puis vous donnez la
chance encore une fois à l’usager d’entrer une valeur correcte. Vous bouclez sur ce problème tant qu’il n’a
pas inséré une valeur correcte.

-2- Après avoir entré une valeur positive non nulle, puis calculé les diviseurs de cette valeur ; le programme
peut demander à l’usager s’il veut entrer une nouvelle valeur ou terminer le programme. La réponse doit
être du style **O** ou **o** (pour oui) et **N** ou **n** (pour non). Si l’usager entre par exemple le caractère « g », vous
devez l’informer que vous n’acceptez comme réponse que les lettres **O** , **o** , **N** , ou **n**.

L’algorithmique pour calculer les diviseurs d’un nombre est toute simple :

Soient **x** et **y** deux variables de type **int**. L'expression **x%y** retourne le reste de la division entière de **x** par
**y**. Pour calculer les diviseurs de **x** , on essaie de diviser **x** par tous les entiers compris entre **1** et **x**. Si le
reste de la division **x/y** est nul, alors l’entier **y** est un diviseur de **x**. Par exemple, les diviseurs de **60** sont :

**{1 2 3 4 5 6 10 12 15 20 30 60}**. L’entier **25** n’est pas un diviseur de **60** car le reste de la
division de **60/25** n’est pas nul.

```
La simplicité de votre code et la clarté de sa présentation
sont des éléments importants de la notation
```

IFT1166 Hiver-2005: Intra 9/10


IFT1166 Hiver-2005: Intra 10/10


