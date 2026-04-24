# Syntaxe C++ (Reference rapide)

## Structure minimale

```cpp
#include <iostream>

int main() {
    std::cout << "Hello" << std::endl;
    return 0;
}
```

## Fonctions

```cpp
int somme(int a, int b) {
    return a + b;
}
```

## Classe minimale

```cpp
class Point {
private:
    int x_;

public:
    Point(int x) : x_(x) {}
    int getX() const { return x_; }
};
```

## Heritage

```cpp
class Base {
public:
    virtual void f() {}
    virtual ~Base() = default;
};

class Derivee : public Base {
public:
    void f() override {}
};
```
