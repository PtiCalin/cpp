# VS Code for C++ Notes

> Visual Studio Code — lightweight editor with powerful C++ support via extensions.

---

## Table of Contents

- [Setup](#setup)
- [Essential Extensions](#essential-extensions)
- [Configuring the Compiler](#configuring-the-compiler)
- [Building and Running](#building-and-running)
- [tasks.json — Build Automation](#tasksjson--build-automation)
- [launch.json — Debugging](#launchjson--debugging)
- [Keyboard Shortcuts](#keyboard-shortcuts)
- [IntelliSense Configuration](#intellisense-configuration)
- [Multi-File Projects](#multi-file-projects)
- [Terminal Workflow](#terminal-workflow)
- [Common Issues and Fixes](#common-issues-and-fixes)

---

## Setup

### 1. Install VS Code

Download from [code.visualstudio.com](https://code.visualstudio.com/)

### 2. Install a C++ compiler

**Windows (MinGW via MSYS2):**
1. Install [MSYS2](https://www.msys2.org/)
2. In MSYS2 terminal:
   ```bash
   pacman -S mingw-w64-ucrt-x86_64-gcc
   ```
3. Add to PATH: `C:\msys64\ucrt64\bin`

**Windows (alternative — standalone MinGW):**
- Download from [winlibs.com](https://winlibs.com/) and add `bin/` to PATH

**Verify installation:**
```powershell
g++ --version
```

### 3. Install extensions (see below)

---

## Essential Extensions

| Extension | ID | Purpose |
|---|---|---|
| **C/C++** | `ms-vscode.cpptools` | IntelliSense, debugging, code browsing |
| **C/C++ Extension Pack** | `ms-vscode.cpptools-extension-pack` | Bundles C/C++ + CMake tools |
| **Code Runner** | `formulahendry.code-runner` | Quick compile & run with one click |

### Optional but recommended

| Extension | Purpose |
|---|---|
| **Error Lens** | Show errors/warnings inline next to the code |
| **Better Comments** | Colored comment annotations |
| **GitLens** | Enhanced Git integration |
| **Markdown Preview Enhanced** | Better markdown rendering (for this repo's docs) |

---

## Configuring the Compiler

### c_cpp_properties.json

Press `Ctrl+Shift+P` → **C/C++: Edit Configurations (JSON)**

```json
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**"
            ],
            "defines": [],
            "compilerPath": "C:/msys64/ucrt64/bin/g++.exe",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "windows-gcc-x64"
        }
    ],
    "version": 4
}
```

> Adjust `compilerPath` to match your g++ installation.

---

## Building and Running

### Quick method — using the terminal

```powershell
g++ -std=c++17 -Wall -Wextra -g main.cpp -o app.exe; .\app.exe
```

### Using Code Runner (extension)

- Open a `.cpp` file
- Click the **▷ Play** button in the top-right corner
- Or press `Ctrl+Alt+N`

### Using tasks (recommended for multi-file projects)

Press `Ctrl+Shift+B` to run the build task (configure below).

---

## tasks.json — Build Automation

Create `.vscode/tasks.json` in your workspace:

### Single-file build task

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Build active file",
            "type": "cppbuild",
            "command": "g++",
            "args": [
                "-std=c++17",
                "-Wall",
                "-Wextra",
                "-Wpedantic",
                "-g",
                "${file}",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}.exe"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": ["$gcc"],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}
```

### Multi-file build task

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Build project",
            "type": "cppbuild",
            "command": "g++",
            "args": [
                "-std=c++17",
                "-Wall",
                "-Wextra",
                "-Wpedantic",
                "-g",
                "main.cpp",
                "employee.cpp",
                "file_io.cpp",
                "-o",
                "app.exe"
            ],
            "options": {
                "cwd": "${workspaceFolder}"
            },
            "problemMatcher": ["$gcc"],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}
```

Build with `Ctrl+Shift+B`.

---

## launch.json — Debugging

Create `.vscode/launch.json`:

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Debug active file",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}/${fileBasenameNoExtension}.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": true,
            "MIMode": "gdb",
            "miDebuggerPath": "C:/msys64/ucrt64/bin/gdb.exe",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "Build active file"
        }
    ]
}
```

Debug with `F5`. Make sure the `preLaunchTask` matches a task label in `tasks.json`.

---

## Keyboard Shortcuts

### Build & Debug

| Shortcut | Action |
|---|---|
| `Ctrl+Shift+B` | Run build task |
| `F5` | Start debugging |
| `Ctrl+F5` | Run without debugging |
| `Shift+F5` | Stop debugging |
| `F9` | Toggle breakpoint |
| `F10` | Step Over |
| `F11` | Step Into |
| `Shift+F11` | Step Out |

### Navigation

| Shortcut | Action |
|---|---|
| `Ctrl+P` | Quick open file by name |
| `Ctrl+Shift+P` | Command Palette |
| `Ctrl+G` | Go to line |
| `F12` | Go to Definition |
| `Alt+F12` | Peek Definition (inline) |
| `Shift+F12` | Find All References |
| `Ctrl+Shift+O` | Go to Symbol in file |
| `Ctrl+T` | Go to Symbol in workspace |

### Editing

| Shortcut | Action |
|---|---|
| `Ctrl+D` | Select next occurrence |
| `Ctrl+Shift+K` | Delete line |
| `Alt+Up/Down` | Move line up/down |
| `Ctrl+/` | Toggle line comment |
| `Ctrl+Shift+A` | Toggle block comment |
| `Ctrl+Space` | Trigger IntelliSense |
| `F2` | Rename symbol |
| `Ctrl+Shift+I` | Format document |

### Terminal

| Shortcut | Action |
|---|---|
| `` Ctrl+` `` | Toggle integrated terminal |
| `` Ctrl+Shift+` `` | New terminal instance |

---

## IntelliSense Configuration

If IntelliSense shows errors for headers or standard library:

1. `Ctrl+Shift+P` → **C/C++: Edit Configurations (UI)**
2. Set **Compiler path** to your g++ (e.g., `C:/msys64/ucrt64/bin/g++.exe`)
3. Set **C++ standard** to `c++17`
4. Set **IntelliSense mode** to `windows-gcc-x64`

### Include paths for this repo

If your file includes headers from other folders (e.g., `#include "macros.h"`), add those paths:

```json
"includePath": [
    "${workspaceFolder}/**",
    "${workspaceFolder}/macros",
    "${workspaceFolder}/fundamentals/functions",
    "${workspaceFolder}/oop/classes-basics"
]
```

---

## Multi-File Projects

### Option 1 — List all `.cpp` in tasks.json

Explicitly list every source file in the `args` array (shown above).

### Option 2 — Wildcard compile (all `.cpp` in current folder)

In the terminal:
```powershell
g++ -std=c++17 -Wall -Wextra -g *.cpp -o app.exe
```

### Option 3 — Use a Makefile

See the [Makefile section in gpp-compilation.md](gpp-compilation.md#makefiles), then run:
```powershell
make
```

---

## Terminal Workflow

VS Code's integrated terminal is the fastest way to compile and run:

```powershell
# Navigate to the file's directory
cd projects\employee-management

# Compile
g++ -std=c++17 -Wall -Wextra -g exemple-employes.cpp -o employes.exe

# Run
.\employes.exe
```

> **Tip**: Use the **Up arrow** to recall the last command — avoids retyping.

---

## Common Issues and Fixes

| Problem | Cause | Fix |
|---|---|---|
| `g++ : The term 'g++' is not recognized` | g++ not in PATH | Add MinGW `bin/` to system PATH; restart VS Code |
| IntelliSense squiggles but code compiles | Wrong IntelliSense config | Set correct compiler path and C++ standard in `c_cpp_properties.json` |
| `#include errors detected` (green squiggle) | Include path not configured | Add the folder to `includePath` in `c_cpp_properties.json` |
| Breakpoints not hit during debugging | Not compiled with `-g` | Add `-g` to build args in `tasks.json` |
| `preLaunchTask 'X' not found` | Task label mismatch | Ensure `preLaunchTask` in `launch.json` matches a `label` in `tasks.json` |
| Terminal encoding issues (accented chars) | PowerShell UTF-8 not enabled | Run `chcp 65001` in terminal, or add to PowerShell profile |
| Code Runner runs old code | File not saved before running | Enable **Settings → Code Runner: Save File Before Run** |
