# Dev-C++ Notes

> Dev-C++ (Embarcadero / Bloodshed) — lightweight C/C++ IDE for Windows, bundled with MinGW g++.

---

## Table of Contents

- [Installation](#installation)
- [Creating a Project](#creating-a-project)
- [Single-File Programs](#single-file-programs)
- [Multi-File Projects](#multi-file-projects)
- [Compiler Settings](#compiler-settings)
- [Keyboard Shortcuts](#keyboard-shortcuts)
- [Debugging](#debugging)
- [Common Issues and Fixes](#common-issues-and-fixes)

---

## Installation

1. Download **Embarcadero Dev-C++** from [GitHub releases](https://github.com/Embarcadero/Dev-Cpp/releases) or the [official site](https://www.embarcadero.com/free-tools/dev-cpp)
2. Run the installer — it includes **MinGW (g++)** by default
3. On first launch, choose language and accept the default settings

> **Tip**: If you already have MinGW installed separately (e.g., via MSYS2), you can point Dev-C++ to that compiler in **Tools → Compiler Options → Directories**.

---

## Creating a Project

### New console project

1. **File → New → Project** (`Ctrl+Shift+N`)
2. Select **Console Application**
3. Choose **C++ Project**
4. Name the project and pick a save location
5. Click **OK** — Dev-C++ creates a `main.cpp` with a basic template

### Project files

| File | Purpose |
|---|---|
| `*.dev` | Dev-C++ project file (stores settings, file list) |
| `*.cpp` | Source code files |
| `*.h` | Header files |
| `*.o` | Compiled object files (auto-generated) |
| `*.exe` | Final executable |

---

## Single-File Programs

For quick tests, you don't need a project:

1. **File → New → Source File** (`Ctrl+N`)
2. Write your code
3. **Save** (`Ctrl+S`) — must save before compiling
4. **Execute → Compile & Run** (`F11`)

---

## Multi-File Projects

### Adding files to a project

1. **Project → Add to Project** or right-click in the Project pane → **Add to Project**
2. Browse and select existing `.cpp` / `.h` files
3. Alternatively: **File → New → Source File**, then save it in the project folder

### Recommended structure

```
MyProject/
├── MyProject.dev      ← project file
├── main.cpp           ← entry point
├── Employee.h         ← class declaration
├── Employee.cpp       ← class implementation
├── FileUtils.h
└── FileUtils.cpp
```

### Include guards in headers

```cpp
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
    // ...
};

#endif
```

> Dev-C++ compiles all `.cpp` files listed in the project automatically. Headers are included via `#include "Employee.h"`.

---

## Compiler Settings

### Access compiler options

**Tools → Compiler Options** (or **Execution → Compiler Options** depending on version)

### Enable C++17

1. Go to **Compiler Options**
2. In **General** tab, check "Add the following commands when calling the compiler"
3. Add: `-std=c++17`

### Enable warnings

Add these flags in the same field:

```
-Wall -Wextra -Wpedantic
```

### Full recommended flags for learning

```
-std=c++17 -Wall -Wextra -Wpedantic -g
```

| Flag | Purpose |
|---|---|
| `-std=c++17` | Use C++17 standard |
| `-Wall -Wextra` | Enable comprehensive warnings |
| `-Wpedantic` | Strict ISO compliance |
| `-g` | Include debug symbols for the debugger |

---

## Keyboard Shortcuts

### Build & Run

| Shortcut | Action |
|---|---|
| `F9` | Compile |
| `F10` | Run |
| `F11` | Compile & Run |
| `F12` | Rebuild All |
| `Ctrl+F11` | Clean & Compile |

### Editing

| Shortcut | Action |
|---|---|
| `Ctrl+N` | New file |
| `Ctrl+S` | Save |
| `Ctrl+Shift+S` | Save All |
| `Ctrl+Space` | Code completion |
| `Ctrl+G` | Go to line |
| `Ctrl+F` | Find |
| `Ctrl+H` | Find & Replace |
| `Ctrl+/` | Toggle comment |
| `Tab` | Indent |
| `Shift+Tab` | Unindent |

### Debugging

| Shortcut | Action |
|---|---|
| `F5` | Toggle breakpoint |
| `F7` | Debug (start/continue) |
| `F8` | Step Over (next line) |
| `Shift+F8` | Step Into (enter function) |
| `Ctrl+F7` | Stop debugging |

---

## Debugging

### Prerequisites

- Compile with **`-g`** flag (adds debug symbols)
- Set flag in **Tools → Compiler Options** → add `-g`

### Setting breakpoints

- Click in the **left gutter** beside a line number (or press `F5` on a line)
- A red/blue marker appears

### Starting a debug session

1. **Execute → Debug** (`F7`)
2. Use **F8** to step over, **Shift+F8** to step into
3. Check the **Debug** pane at the bottom for:
   - **Watches**: add variable names to monitor their values
   - **Call Stack**: see the current function chain
   - **Breakpoints**: manage all breakpoints

### Adding watches

1. During debugging, go to the **Debug** tab
2. Click **Add Watch** (or right-click → Add Watch)
3. Type the variable name (e.g., `count`, `employee.name`)

> **Note**: Dev-C++ uses GDB under the hood, so all GDB commands work in the debug console.

---

## Common Issues and Fixes

| Problem | Cause | Fix |
|---|---|---|
| Console window closes instantly | Program finishes before you can read output | Add `system("pause");` before `return 0;`, or use `F11` which pauses automatically |
| `g++ not found` | MinGW not installed or not in PATH | Reinstall Dev-C++, or set compiler path in **Tools → Compiler Options → Directories** |
| "Permission denied" when compiling | Previous `.exe` is still running | Close the running program, then recompile |
| Debugger doesn't stop at breakpoints | Missing `-g` flag | Add `-g` in **Tools → Compiler Options** |
| `#include <filesystem>` fails | Default MinGW may be too old for C++17 filesystem | Update MinGW or install MSYS2 with a recent g++ (≥ 9.x) |
| Autocomplete not working | Feature is basic in Dev-C++ | Consider VS Code for better IntelliSense; or use Ctrl+Space |
| Source file not compiling | File not added to project | Ensure file is listed in **Project → Project Options → Files** |
| Encoding issues (accented characters) | File encoding mismatch | Save as UTF-8: **Edit → File Properties → UTF-8** |

---

## Tips for IFT1166 Students

- Dev-C++ is often used in university labs because it's lightweight and portable
- Save your project (`.dev`) alongside your source files for easy reopening
- Use **F11** (Compile & Run) as your main workflow — it saves, compiles, and runs in one step
- If you're working on a multi-file project from this repo, create a project and **Add to Project** all the `.cpp` files
- For headers like `macros.h`, `methodes.h`, `classes.h` — add them to the project for IntelliSense, but they don't need separate compilation
