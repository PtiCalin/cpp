# Build Notes

Guides and reference documentation for compiling, building, running, and debugging C++ programs with various tools.

---

## Contents

| Guide | Description |
|---|---|
| [gpp-compilation.md](gpp-compilation.md) | **g++ (GNU C++ Compiler)** — flags, warnings, optimization, standards, linking, Makefiles |
| [visual-studio-notes.md](visual-studio-notes.md) | **Visual Studio** — project setup, shortcuts, debugging, IntelliSense, compiler config |
| [dev-cpp-notes.md](dev-cpp-notes.md) | **Dev-C++** — lightweight IDE setup, compiler settings, shortcuts, debugging |
| [vscode-cpp-notes.md](vscode-cpp-notes.md) | **VS Code** — extensions, tasks.json, launch.json, IntelliSense, terminal workflow |
| [debugging-guide.md](debugging-guide.md) | **Debugging** — tool-agnostic strategies, sanitizers, memory errors, reading error messages |

---

## Quick Reference — Which Tool to Use?

| Scenario | Recommended |
|---|---|
| University lab (lightweight, Windows) | Dev-C++ |
| Full IDE with integrated debugger | Visual Studio |
| Lightweight editor + terminal | VS Code + g++ |
| Linux / WSL / macOS command line | g++ + GDB |
| Quick single-file test | Any IDE or `g++ file.cpp -o app && ./app` |

## Quick Compile Command

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic -g main.cpp -o app
```

> See individual guides above for detailed instructions per tool.
