# Visual Studio Notes

> Microsoft Visual Studio (Community edition) — full-featured IDE for C++ on Windows.

---

## Table of Contents

- [Creating a Project](#creating-a-project)
- [Project Structure Best Practices](#project-structure-best-practices)
- [Building and Running](#building-and-running)
- [Keyboard Shortcuts](#keyboard-shortcuts)
- [Setting the C++ Standard](#setting-the-c-standard)
- [Adding Files to a Project](#adding-files-to-a-project)
- [Multi-File Projects](#multi-file-projects)
- [Debugging](#debugging)
- [IntelliSense Tips](#intellisense-tips)
- [Compiler Warnings Configuration](#compiler-warnings-configuration)
- [Common Issues and Fixes](#common-issues-and-fixes)

---

## Creating a Project

1. **File → New → Project**
2. Search for **Console App** (C++, Windows, Console)
3. Name the project and choose a location
4. Click **Create**

> Visual Studio generates a `main.cpp` with a "Hello World" template. Replace or modify it.

### Solution vs. Project

| Concept | What it is |
|---|---|
| **Solution** (`.sln`) | A container that can hold multiple projects |
| **Project** (`.vcxproj`) | A single build target (executable or library) |

---

## Project Structure Best Practices

```
MyProject/
├── MyProject.sln
└── MyProject/
    ├── MyProject.vcxproj
    ├── main.cpp
    ├── Employee.h          ← class declaration
    ├── Employee.cpp         ← class implementation
    ├── FileUtils.h
    └── FileUtils.cpp
```

- Keep class declaration in `.h`, method definitions in `.cpp`.
- Group related files using **Solution Explorer filters** (right-click → Add → New Filter).
- Name filters by feature/module: `Core`, `Models`, `Utils`, etc.

---

## Building and Running

| Action | Method |
|---|---|
| **Build Solution** | `Ctrl+Shift+B` or Build → Build Solution |
| **Run without debugging** | `Ctrl+F5` (keeps console open after exit) |
| **Run with debugging** | `F5` (stops at breakpoints) |
| **Rebuild all** | Build → Rebuild Solution |
| **Clean** | Build → Clean Solution |

### Build Configurations

| Configuration | Purpose |
|---|---|
| **Debug** | No optimization, includes debug symbols — use for development |
| **Release** | Optimized, no debug symbols — use for final builds |

Switch via the dropdown in the toolbar (next to the platform selector).

---

## Keyboard Shortcuts

### Essentials

| Shortcut | Action |
|---|---|
| `Ctrl+Shift+B` | Build Solution |
| `F5` | Start Debugging |
| `Ctrl+F5` | Start Without Debugging |
| `Shift+F5` | Stop Debugging |
| `F9` | Toggle Breakpoint |
| `F10` | Step Over |
| `F11` | Step Into |
| `Shift+F11` | Step Out |
| `Ctrl+K, Ctrl+C` | Comment selection |
| `Ctrl+K, Ctrl+U` | Uncomment selection |

### Navigation

| Shortcut | Action |
|---|---|
| `Ctrl+G` | Go to line number |
| `Ctrl+T` | Go to symbol/file/member |
| `F12` | Go to Definition |
| `Ctrl+F12` | Go to Declaration |
| `Shift+F12` | Find All References |
| `Ctrl+-` | Navigate back |
| `Ctrl+Shift+-` | Navigate forward |

### Editing

| Shortcut | Action |
|---|---|
| `Ctrl+D` | Duplicate line |
| `Ctrl+Shift+K` | Delete line |
| `Alt+Up/Down` | Move line up/down |
| `Ctrl+Space` | Trigger IntelliSense |
| `Ctrl+Shift+Space` | Show parameter info |
| `Ctrl+R, Ctrl+R` | Rename symbol |

---

## Setting the C++ Standard

1. **Right-click project** in Solution Explorer → **Properties**
2. Navigate to: **Configuration Properties → C/C++ → Language**
3. Set **C++ Language Standard** to:
   - `ISO C++17 (/std:c++17)` — recommended for this repo
   - `ISO C++20 (/std:c++20)` — for newer features
4. Click **Apply → OK**

> **Important**: Set this for **All Configurations** (dropdown at top of Properties window) so both Debug and Release use the same standard.

---

## Adding Files to a Project

### New file

1. Right-click the project in **Solution Explorer**
2. **Add → New Item** (`Ctrl+Shift+A`)
3. Choose **C++ File (.cpp)** or **Header File (.h)**
4. Name it and click **Add**

### Existing file

1. Right-click project → **Add → Existing Item** (`Shift+Alt+A`)
2. Browse to the file and click **Add**

> Files must be part of the project to be compiled. Simply placing a file in the folder is not enough.

---

## Multi-File Projects

### Header + Source pattern

**`Employee.h`** — declaration:
```cpp
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
private:
    std::string name;
    double salary;
public:
    Employee(const std::string& n, double s);
    std::string getName() const;
    double getSalary() const;
    void display() const;
};

#endif
```

**`Employee.cpp`** — implementation:
```cpp
#include "Employee.h"
#include <iostream>

Employee::Employee(const std::string& n, double s)
    : name(n), salary(s) {}

std::string Employee::getName() const { return name; }
double Employee::getSalary() const { return salary; }

void Employee::display() const {
    std::cout << name << " — $" << salary << std::endl;
}
```

**`main.cpp`** — usage:
```cpp
#include "Employee.h"

int main() {
    Employee e("Alice", 75000);
    e.display();
    return 0;
}
```

> Visual Studio automatically compiles all `.cpp` files in the project and links them together.

---

## Debugging

### Setting breakpoints

- Click in the **left margin** next to a line number (red dot appears)
- Or press `F9` on the current line

### During a debug session (`F5`)

| Action | Shortcut | Description |
|---|---|---|
| Step Over | `F10` | Execute current line, skip into functions |
| Step Into | `F11` | Enter the function on the current line |
| Step Out | `Shift+F11` | Run until the current function returns |
| Continue | `F5` | Resume until next breakpoint |
| Stop | `Shift+F5` | End the debug session |

### Watch & inspect variables

- **Hover** over a variable in code to see its value
- **Autos** window: shows variables used near the current line
- **Locals** window: shows all variables in the current scope
- **Watch** window: add custom expressions (`Add → Watch 1`)
- **Immediate Window** (`Ctrl+Alt+I`): type expressions to evaluate

### Conditional breakpoints

1. Right-click a breakpoint → **Conditions**
2. Enter a condition (e.g., `i == 42`)
3. The breakpoint only triggers when the condition is true

---

## IntelliSense Tips

| Feature | How to trigger |
|---|---|
| Auto-complete | Start typing (or `Ctrl+Space`) |
| Parameter info | `Ctrl+Shift+Space` inside function call parentheses |
| Quick info | Hover over any symbol |
| Error squiggles | Red = error, green = warning (hover for details) |

### If IntelliSense misbehaves

1. **Build → Clean Solution**, then **Build → Rebuild**
2. Close and reopen the solution
3. Delete the `.vs/` folder in the solution directory (IntelliSense cache)

---

## Compiler Warnings Configuration

1. Right-click project → **Properties**
2. **C/C++ → General → Warning Level**:
   - `Level3 (/W3)` — default, good baseline
   - `Level4 (/W4)` — stricter (recommended for learning)
   - `EnableAllWarnings (/Wall)` — everything (noisy, but thorough)
3. **C/C++ → General → Treat Warnings As Errors**: set to **Yes (/WX)** to enforce clean code

---

## Common Issues and Fixes

| Problem | Cause | Fix |
|---|---|---|
| Console closes immediately | Running with `F5` (debugging) | Use `Ctrl+F5` instead, or add `system("pause")` |
| `LNK2019: unresolved external symbol` | `.cpp` file not in the project, or function not defined | Ensure the `.cpp` is included in the project; check function signature matches declaration |
| `LNK2005: already defined` | Function defined in a header included by multiple files | Move definition to `.cpp`; keep only declaration in `.h` |
| `Cannot open include file` | Wrong path or file not in project | Check filename spelling; use `#include "file.h"` for local headers |
| `C4996: 'scanf' ... unsafe` | MSVC deprecation of C functions | Add `#define _CRT_SECURE_NO_WARNINGS` before includes, or use `scanf_s` |
| IntelliSense errors but builds fine | IntelliSense database out of date | Rebuild solution; delete `.vs/` folder if persistent |
| Precompiled header errors | `pch.h` expected but not used | Disable precompiled headers in project properties (C/C++ → Precompiled Headers → Not Using) |
