# Workspace Migration to New Pedagogical Structure

This script migrates legacy top-level folders into the new SQL-style architecture.

## Script

- `migrate-workspace-to-new-structure.ps1`

## What gets moved

- `fundamentals` -> `theory/01-fondements-cpp/fundamentals`
- `macros` -> `theory/01-fondements-cpp/macros`
- `modular-programming` -> `theory/03-fonctions-modularite/modular-programming`
- `oop` -> `theory/05-programmation-objet/oop`
- `file-handling` -> `theory/08-fichiers-build-debug/file-handling`
- `build-notes` -> `resources/build-notes`
- `course-work` -> `exercises/course-work`
- `clean-examples` -> `tools/templates/clean-examples`
- `experiments` -> `examples/modern-cpp/experiments`
- `refactored` -> `examples/modern-cpp/refactored`

## Run (dry-run first)

```powershell
cd tools/scripts
powershell -ExecutionPolicy Bypass -File .\migrate-workspace-to-new-structure.ps1 -DryRun
```

## Run (real migration)

```powershell
cd tools/scripts
powershell -ExecutionPolicy Bypass -File .\migrate-workspace-to-new-structure.ps1
```

## Safety behavior

- If destination already exists, script stops with error.
- Missing source folders are skipped.
- Parent folders are auto-created.
