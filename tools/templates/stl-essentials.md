# STL Essentials

## Conteneurs de base

- `std::vector<T>`: tableau dynamique.
- `std::map<K, V>`: dictionnaire trie par cle.
- `std::set<T>`: ensemble trie sans doublons.
- `std::string`: chaine dynamique.

## Algorithmes frequents

```cpp
std::sort(v.begin(), v.end());
auto it = std::find(v.begin(), v.end(), valeur);
int s = std::accumulate(v.begin(), v.end(), 0);
```

## Iteration

```cpp
for (const auto& e : v) {
    // ...
}
```
