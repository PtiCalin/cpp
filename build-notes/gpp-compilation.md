# g++ Compilation Notes

## Single file

```bash
g++ main.cpp -o app
./app
```

## Multi-file

```bash
g++ main.cpp employee.cpp file_io.cpp -o app
./app
```

## Compile with warnings

```bash
g++ -Wall -Wextra -Wpedantic main.cpp -o app
```
