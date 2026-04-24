# C++ Debugging Guide

> A tool-agnostic reference for debugging C++ programs — concepts, strategies, and techniques that apply regardless of IDE.

---

## Table of Contents

- [Debugging Mindset](#debugging-mindset)
- [Print Debugging](#print-debugging)
- [Preprocessor Debug Macros](#preprocessor-debug-macros)
- [Using a Debugger (GDB / IDE)](#using-a-debugger-gdb--ide)
- [Common Bug Categories](#common-bug-categories)
- [Memory Errors](#memory-errors)
- [Sanitizers](#sanitizers)
- [Debugging Strategies](#debugging-strategies)
- [Reading Compiler Error Messages](#reading-compiler-error-messages)
- [Valgrind (Linux / WSL)](#valgrind-linux--wsl)

---

## Debugging Mindset

1. **Reproduce** — Make the bug happen reliably. What input triggers it?
2. **Isolate** — Narrow down which part of the code causes it
3. **Understand** — Read the code line by line; don't assume — verify
4. **Fix** — Change one thing at a time
5. **Verify** — Confirm the fix works and doesn't break something else

> "Debugging is twice as hard as writing the code in the first place." — Brian Kernighan

---

## Print Debugging

The simplest and most universal technique — insert output statements to trace execution.

```cpp
#include <iostream>

void processData(int arr[], int size) {
    std::cout << "[DEBUG] processData called, size = " << size << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "[DEBUG] arr[" << i << "] = " << arr[i] << std::endl;
        // ... processing logic
    }
    std::cout << "[DEBUG] processData finished" << std::endl;
}
```

### Tips

- Use a prefix like `[DEBUG]` so you can find and remove them later
- Print variable values **before and after** suspicious operations
- Use `std::cerr` instead of `std::cout` — it's unbuffered (output appears immediately, even if the program crashes)
- Flush output: `std::cout << "msg" << std::flush;` or use `std::endl`

---

## Preprocessor Debug Macros

Use macros to make debug output easy to enable/disable:

```cpp
#define DEBUG_MODE  // comment this line to disable all debug output

#ifdef DEBUG_MODE
    #define DEBUG(msg) std::cerr << "[DEBUG] " << __FILE__ << ":" << __LINE__ << " — " << msg << std::endl
#else
    #define DEBUG(msg)  // compiles to nothing
#endif
```

Usage:
```cpp
DEBUG("Value of x = " << x);
DEBUG("Entering loop");
```

> The `macros.h` file in this repo includes similar debug macros. See [`macros/macros.h`](../macros/macros.h).

### Useful built-in macros for debugging

| Macro | Expands to |
|---|---|
| `__FILE__` | Current source file name |
| `__LINE__` | Current line number |
| `__func__` | Current function name |
| `__DATE__` | Compilation date |
| `__TIME__` | Compilation time |

---

## Using a Debugger (GDB / IDE)

All major tools (GDB, Visual Studio, VS Code, Dev-C++) support these core operations:

### Key concepts

| Concept | What it does |
|---|---|
| **Breakpoint** | Pauses execution at a specific line |
| **Step Over** | Execute current line, skip function internals |
| **Step Into** | Enter the function called on the current line |
| **Step Out** | Run until the current function returns |
| **Continue** | Resume execution until the next breakpoint |
| **Watch** | Monitor a variable's value as you step through code |
| **Call Stack** | Shows the chain of function calls that led to the current point |

### When to use a debugger vs. print statements

| Situation | Best tool |
|---|---|
| Quick check of a value | Print / `DEBUG()` macro |
| Understanding control flow | Debugger (step through) |
| Infinite loop | Debugger (pause + inspect) |
| Crash / segmentation fault | Debugger (shows exact crash line + call stack) |
| Complex data structures | Debugger (watch window) |
| Intermittent bug | Conditional breakpoint |

### Tool-specific guides

- **GDB**: See [gpp-compilation.md](gpp-compilation.md#debugging-with-g)
- **Visual Studio**: See [visual-studio-notes.md](visual-studio-notes.md#debugging)
- **Dev-C++**: See [dev-cpp-notes.md](dev-cpp-notes.md#debugging)
- **VS Code**: See [vscode-cpp-notes.md](vscode-cpp-notes.md#launchjson--debugging)

---

## Common Bug Categories

### 1. Compile-time errors

The compiler catches these — code won't build.

| Error type | Example | Fix |
|---|---|---|
| Syntax error | Missing `;`, `}`, `)` | Read the error message — it points to the line |
| Type mismatch | Passing `string` to `int` param | Check function signatures |
| Undeclared identifier | Typo in variable name | Check spelling, scope, and `#include` |
| Missing include | Using `cout` without `<iostream>` | Add the necessary `#include` |

### 2. Linker errors

Code compiles but won't link into an executable.

| Error type | Example | Fix |
|---|---|---|
| Undefined reference | Function declared but not defined | Add the `.cpp` file to compilation |
| Multiple definitions | Function defined in header, included twice | Use include guards; move definitions to `.cpp` |

### 3. Runtime errors

Code compiles and links, but crashes or gives wrong results.

| Error type | Symptom | Tools |
|---|---|---|
| Segmentation fault | Program crashes | Debugger, AddressSanitizer |
| Array out of bounds | Garbage values or crash | Bounds checking, sanitizer |
| Infinite loop | Program hangs | Debugger pause, print statements |
| Logic error | Wrong output | Step through with debugger |
| Division by zero | Crash or undefined behavior | Validate inputs before division |

---

## Memory Errors

C++ gives you direct memory control — and direct memory bugs.

### Common memory issues

| Bug | Cause | Symptom |
|---|---|---|
| **Buffer overflow** | Writing past array/buffer bounds | Crash, data corruption, security vulnerability |
| **Use after free** | Accessing memory after `delete` | Garbage values, crash |
| **Double free** | Calling `delete` twice on same pointer | Crash |
| **Memory leak** | `new` without matching `delete` | Program uses more and more memory |
| **Dangling pointer** | Pointer to deallocated memory | Undefined behavior |
| **Uninitialized variable** | Reading a variable before assigning | Garbage values |

### Prevention

```cpp
// Always initialize variables
int count = 0;
int* ptr = nullptr;

// Check pointers before use
if (ptr != nullptr) {
    // safe to dereference
}

// Set pointers to nullptr after delete
delete ptr;
ptr = nullptr;

// Prefer stack allocation over heap when possible
int arr[100];  // stack — automatically cleaned up

// For dynamic memory, prefer smart pointers (modern C++)
// std::unique_ptr<int> p = std::make_unique<int>(42);
```

---

## Sanitizers

Compiler-built tools that instrument your code to catch bugs at runtime.

### AddressSanitizer (ASan) — catches memory errors

```bash
g++ -fsanitize=address -g main.cpp -o app
./app
```

Catches: buffer overflow, use-after-free, double-free, memory leaks, stack overflow.

### UndefinedBehaviorSanitizer (UBSan) — catches undefined behavior

```bash
g++ -fsanitize=undefined -g main.cpp -o app
./app
```

Catches: signed integer overflow, null pointer dereference, out-of-bounds array access, misaligned pointers.

### Combine both

```bash
g++ -fsanitize=address,undefined -g main.cpp -o app
```

> **Tip**: Always compile in debug mode (`-g`) when using sanitizers — the error messages include file names and line numbers.

---

## Debugging Strategies

### Binary search debugging

When you don't know where the bug is:

1. Add a print statement halfway through the suspect code
2. If the bug is before the print → search the first half
3. If the bug is after → search the second half
4. Repeat until you find the exact line

### Rubber duck debugging

Explain your code out loud, line by line, to an imaginary listener (or a rubber duck). You'll often catch the bug just by articulating what the code is supposed to do.

### Minimal reproduction

1. Copy the buggy code to a new file
2. Remove everything that's not related to the bug
3. Keep removing until the bug disappears — the last thing you removed is the culprit

### Check your assumptions

Ask yourself:
- What value do I **expect** this variable to have? → Print it and verify.
- Is this loop running the right number of times?
- Is this condition true when I think it is?
- Am I modifying the right variable? (Watch for copy vs. reference.)

---

## Reading Compiler Error Messages

### Anatomy of a g++ error

```
main.cpp:42:15: error: 'calculate' was not declared in this scope
         int result = calculate(x, y);
                      ^~~~~~~~~
```

| Part | Meaning |
|---|---|
| `main.cpp` | File name |
| `42` | Line number |
| `15` | Column number |
| `error:` | Severity (error = won't compile; warning = compiles but suspicious) |
| `'calculate' was not declared...` | Description of the problem |
| `^~~~~~~~~` | Points to the exact spot |

### Tips

- **Read the first error first** — later errors are often caused by the first one
- **Look at the line before** — missing semicolons are reported on the *next* line
- **Template errors** — can be very long. Read the first and last few lines; the middle is usually template expansion noise
- **"Did you mean...?"** — the compiler often suggests the correct name when you have a typo

---

## Valgrind (Linux / WSL)

> Valgrind is a powerful memory analysis tool. Available on Linux and via WSL (Windows Subsystem for Linux) on Windows.

### Install (Ubuntu / WSL)

```bash
sudo apt install valgrind
```

### Run with memory checking

```bash
g++ -g main.cpp -o app
valgrind --leak-check=full ./app
```

### What it detects

- Memory leaks (allocated but never freed)
- Invalid memory access (read/write out of bounds)
- Use of uninitialized values
- Double free / mismatched free

### Reading Valgrind output

```
==12345== Invalid read of size 4
==12345==    at 0x40052A: main (main.cpp:10)
==12345==  Address 0x5204048 is 0 bytes after a block of size 40 alloc'd
```

Translation: On line 10 of `main.cpp`, the program read 4 bytes right past the end of a 40-byte allocation (array index out of bounds).
