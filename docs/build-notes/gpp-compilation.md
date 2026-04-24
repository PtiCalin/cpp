# g++ Compilation Notes

> The GNU C++ compiler — available on Linux, macOS, and Windows (via MinGW / MSYS2).

---

## Table of Contents

- [Basic Compilation](#basic-compilation)
- [Multi-File Compilation](#multi-file-compilation)
- [Warning Flags](#warning-flags)
- [Optimization Levels](#optimization-levels)
- [C++ Standard Selection](#c-standard-selection)
- [Debugging with g++](#debugging-with-g)
- [Preprocessor Options](#preprocessor-options)
- [Linking Libraries](#linking-libraries)
- [Useful Flag Combinations](#useful-flag-combinations)
- [Common Errors and Fixes](#common-errors-and-fixes)
- [Makefiles](#makefiles)

---

## Basic Compilation

### Compile and run a single file

```bash
g++ main.cpp -o app
./app            # Linux / macOS
.\app.exe        # Windows (MinGW)
```

### Compile only (no linking) — produces `.o` object file

```bash
g++ -c main.cpp            # → main.o
```

### Link object files into executable

```bash
g++ main.o helper.o -o app
```

---

## Multi-File Compilation

### All sources at once

```bash
g++ main.cpp employee.cpp file_io.cpp -o app
```

### Step by step (useful for large projects)

```bash
g++ -c main.cpp            # → main.o
g++ -c employee.cpp        # → employee.o
g++ -c file_io.cpp         # → file_io.o
g++ main.o employee.o file_io.o -o app
```

> **Why step by step?** When you change only one file, you only need to recompile that file and re-link — saves time on large projects.

### With header search paths

```bash
g++ -I./include main.cpp -o app     # search headers in ./include/
```

---

## Warning Flags

| Flag | Description |
|---|---|
| `-Wall` | Enable most common warnings |
| `-Wextra` | Extra warnings beyond `-Wall` |
| `-Wpedantic` | Strict ISO C++ compliance warnings |
| `-Werror` | Treat all warnings as errors (won't compile until fixed) |
| `-Wshadow` | Warn when a variable shadows another |
| `-Wconversion` | Warn on implicit type conversions that may lose data |
| `-Wuninitialized` | Warn about uninitialized variables |
| `-Wold-style-cast` | Warn on C-style casts in C++ code |
| `-Wnon-virtual-dtor` | Warn when a class with virtual functions lacks a virtual destructor |

### Recommended minimum for learning

```bash
g++ -Wall -Wextra -Wpedantic main.cpp -o app
```

### Strict mode (catch everything)

```bash
g++ -Wall -Wextra -Wpedantic -Werror -Wshadow -Wconversion main.cpp -o app
```

---

## Optimization Levels

| Flag | Level | Use case |
|---|---|---|
| `-O0` | None (default) | Debugging — no optimization, fast compilation |
| `-O1` | Basic | Light optimization without major compile-time cost |
| `-O2` | Standard | Good balance of speed and compile time |
| `-O3` | Aggressive | Maximum performance (may increase binary size) |
| `-Os` | Size | Optimize for smallest binary |
| `-Og` | Debug-friendly | Optimizations that don't interfere with debugging |

```bash
g++ -O2 main.cpp -o app       # Standard optimization
g++ -Og -g main.cpp -o app    # Debug-friendly optimization + debug symbols
```

---

## C++ Standard Selection

| Flag | Standard | Notes |
|---|---|---|
| `-std=c++11` | C++11 | Lambda, `auto`, range-for, smart pointers |
| `-std=c++14` | C++14 | Generic lambdas, `make_unique` |
| `-std=c++17` | C++17 | `filesystem`, structured bindings, `optional` |
| `-std=c++20` | C++20 | Concepts, ranges, coroutines, `<format>` |
| `-std=c++23` | C++23 | Latest features (compiler support varies) |

```bash
g++ -std=c++17 main.cpp -o app
```

> **For this repo**: `file-handling.cpp` uses `<filesystem>` and requires **C++17** minimum.

---

## Debugging with g++

### Compile with debug symbols

```bash
g++ -g main.cpp -o app
```

### Use GDB (GNU Debugger)

```bash
gdb ./app
```

**Essential GDB commands:**

| Command | Action |
|---|---|
| `run` | Start the program |
| `break main` | Set breakpoint at `main()` |
| `break file.cpp:42` | Set breakpoint at line 42 |
| `next` (`n`) | Step over (execute line, skip into functions) |
| `step` (`s`) | Step into (enter function calls) |
| `print x` | Print the value of variable `x` |
| `backtrace` (`bt`) | Show the call stack |
| `continue` (`c`) | Resume execution until next breakpoint |
| `quit` | Exit GDB |

### AddressSanitizer (catch memory bugs at runtime)

```bash
g++ -fsanitize=address -g main.cpp -o app
./app
```

### UndefinedBehaviorSanitizer

```bash
g++ -fsanitize=undefined -g main.cpp -o app
```

---

## Preprocessor Options

| Flag | Description |
|---|---|
| `-D NAME` | Define macro `NAME` (like `#define NAME`) |
| `-D NAME=value` | Define macro with value |
| `-U NAME` | Undefine macro |
| `-E` | Preprocess only (outputs expanded source to stdout) |

```bash
g++ -DDEBUG main.cpp -o app               # compile with DEBUG defined
g++ -E main.cpp > preprocessed.cpp        # see preprocessor output
```

---

## Linking Libraries

```bash
g++ main.cpp -lm -o app                   # link math library
g++ main.cpp -lstdc++fs -o app             # link filesystem (pre-GCC 9)
g++ main.cpp -L./lib -lmylib -o app        # search in ./lib/ for libmylib.a
```

| Flag | Description |
|---|---|
| `-l<name>` | Link library `lib<name>.a` or `lib<name>.so` |
| `-L<path>` | Add directory to library search path |
| `-static` | Force static linking |

---

## Useful Flag Combinations

### Daily development

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic -g main.cpp -o app
```

### Release build

```bash
g++ -std=c++17 -O2 -DNDEBUG main.cpp -o app
```

### Memory debugging

```bash
g++ -std=c++17 -Wall -Wextra -g -fsanitize=address,undefined main.cpp -o app
```

---

## Common Errors and Fixes

| Error message | Likely cause | Fix |
|---|---|---|
| `undefined reference to 'func()'` | Function declared but not defined / not linked | Add the `.cpp` file containing the definition to the compile command |
| `no such file or directory: header.h` | Header not found | Check the path; use `-I` to add include directory |
| `multiple definition of 'func()'` | Function defined in a header included by multiple files | Move definition to `.cpp`, keep only declaration in `.h` |
| `expected ';' before ...` | Missing semicolon | Check the previous line (often after a class or struct definition) |
| `use of undeclared identifier` | Variable/function not in scope | Check spelling, includes, and namespace |
| `cannot convert 'X' to 'Y'` | Type mismatch | Use explicit cast or fix the types |
| `no matching function for call` | Wrong argument types or count | Check the function signature |

---

## Makefiles

A `Makefile` automates compilation so you don't retype long commands.

### Minimal Makefile

```makefile
CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -g
SRCS     = main.cpp employee.cpp file_io.cpp
OBJS     = $(SRCS:.cpp=.o)
TARGET   = app

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
```

### Usage

```bash
make            # build
make clean      # remove compiled files
```

> **Note:** Makefile recipes (the indented lines) must use **tabs**, not spaces.
