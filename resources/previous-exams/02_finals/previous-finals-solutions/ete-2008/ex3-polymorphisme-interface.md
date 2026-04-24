# Exercice 3 (20 points) — Interface et polymorphisme

Code de reference:

```cpp
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

## 3.1
```cpp
UneInterface* x = new A();
x->methodeX(10);
```
**Incorrect**.

Pourquoi: `A` n'herite pas de `UneInterface`, conversion impossible de `A*` vers `UneInterface*`.

## 3.2
```cpp
UneInterface* y = new B();
y->methodeY(10);
```
**Incorrect**.

Pourquoi: type statique de `y` = `UneInterface*`, donc seules les methodes de `UneInterface` sont visibles (`methodeX`). `methodeY` n'existe pas dans l'interface.

## 3.3
```cpp
UneInterface* z = new B();
z->methodeX(10);
```
**Correct**.

Pourquoi: `B` implemente `methodeX`, et l'appel passe par l'interface (polymorphisme).

## 3.4
```cpp
UneInterface* w = new C();
w->methodeZ(10);
```
**Incorrect**.

Pourquoi: `w` est vu comme `UneInterface*`; `methodeZ` n'est pas dans `UneInterface`.

## 3.5
```cpp
UneInterface* q = new C();
q->methodeX(10);
```
**Correct**.

Pourquoi: `C` herite de `B`, qui fournit `methodeX` demandee par l'interface.

## Modele mental a retenir pour le final

1. Le **type statique du pointeur** determine ce qu'on peut appeler.
2. Le **type dynamique de l'objet** determine quelle implementation virtuelle s'execute.
3. Si une methode n'est pas dans l'interface/base, elle n'est pas appelable via un pointeur de base.
