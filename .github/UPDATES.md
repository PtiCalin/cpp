# UPDATES

Changelog for **PtiCalin/cpp** — C++ Learning in Public.

---

## 2026-03-27

### Added

- **`.github/ISSUE_TEMPLATE/`** — Three issue form templates: Bug Report (`bug-report.yml`), New Content (`new-content.yml`), Question (`question.yml`), plus `config.yml` with blank issues enabled.
- **`.github/workflows/ci.yml`** — CI workflow: syntax-checks all `.cpp` files on push/PR to `main`.
- **`.github/workflows/label-sync.yml`** — Syncs repo labels from `.github/labels.yml`.
- **`.github/workflows/stale.yml`** — Auto-closes inactive issues/PRs (30 + 7 day grace period).
- **`.github/workflows/release-drafter.yml`** — Auto-drafts release notes from merged PRs.
- **`.github/release-drafter.yml`** — Release Drafter category config.
- **`.github/labels.yml`** — Label definitions (type, status, ROADMAP phase).
- **`.github/.gitmessage`** — Commit message template with type prefixes (`Add`, `Fix`, `Refactor`, etc.).
- **`CONTRIBUTING.md`** — Contribution guidelines, code style, commit conventions, and checklist.
- **`resources/RESSOURCES.md`** — Curated resource list: official references, tutorials, books, tools, community picks, topic deep dives, and community insights.
- **`resources/notes/`** — Blank reading-note files for every listed resource (13 files), linked from the resource tables.
- **`resources/` section in `ROADMAP.md`** — Cross-link to the resources page.

### Changed

- **`README.md`** — Rewritten as "C++ — Learning in Public": added motivation section, descriptive folder table, progress summary, link to `CONTRIBUTING.md` and related repos.
- **`ROADMAP.md`** — Added Resources section at the bottom.

---

## 2026-03-27

### Added

- **`resources/README.md`** — Initial resource page with official references, tutorials, books (including *C++ Essentials* by Sharam Hekmat), tools, and empty community/deep-dive tables.

### Changed

- **`README.md`** — Added IFT1166 / UdeM subtitle, related repositories table linking to TP2 assignment repo, and `resources/` to the structure list.

---

## 2026-03-02

### Added

- **`course-work/ex17-stl-algorithmes.cpp`** — STL algorithms exercise.
- **`course-work/ex18-constructeurs-avances.cpp`** — Advanced constructors exercise.
- **`course-work/ex19-projet-gestion-notes.cpp`** — Note management system project.
- **`cpp-cheatsheet.md`** — Quick-reference C++ cheatsheet.
- **`.github/pull_request_template.md`** — PR template with type-of-change checkboxes and checklist.

---

## 2026-02-28

### Added

- **`macros/macros.h`** — Full macro & constant library (unit conversions, math/physics/chemistry constants, geometry formulas, debug helpers, memory management).
- **`fundamentals/functions/methodes.h`** — ~1 500-line function library covering math, statistics, geometry, vectors, strings, arrays, sorting, combinatorics, number theory, conversion, validation, matrices, calculus, and optimization.
- **`oop/classes-basics/classes.h`** — ~1 300-line class inventory spanning mathematics, 2D/3D geometry, physics, electromagnetism, chemistry, biology, CS data structures, and everyday objects.
- **`file-handling/file-handling.cpp`** — ~1 000-line file I/O utility (reading, writing, directory ops, search/replace, statistics, path manipulation, advanced utilities). Requires C++17.
- **`clean-examples/squelette.cpp`** — Generic C++ program template (macros, prototypes, inheritance, operator overloading, composition, `main()`).
- **`projects/library-system/exemple-bibliotheque.cpp`** — Library network management example (search, loans, employees, finances, statistics).
- **`projects/employee-management/exemple-employes.cpp`** — Employee management system for TechNova Solutions Inc. (search, stats, CRUD, sorting, CSV/JSON export).
- **`course-work/ex01` – `ex16`** — IFT1166 course exercises covering variables, conditions, loops, functions, arrays, vectors, strings, pointers, dynamic memory, macros, classes, composition, operator overloading, inheritance/polymorphism, file I/O, and multi-file projects.
- **`build-notes/`** — Compilation and debugging guides for g++, Dev-C++, Visual Studio, and VS Code.
- **`UPDATES.md`** — This changelog.
- **`ROADMAP.md`** — 6-phase learning path with progress checkboxes.
- **`STYLEGUIDE.md`** — Naming, formatting, and commit conventions.

### Changed

- **`LICENSE`** — Replaced Unlicense with MIT License.
- **`README.md`** — Restructured as a learning-artifact landing page.
- Updated `README.md` files in `macros/`, `fundamentals/functions/`, `oop/classes-basics/`, `file-handling/`, `clean-examples/`, `projects/library-system/`, `projects/employee-management/` to describe newly added content.

---

> All source material originates from **IFT1166 — Programmation orientée objet en C++**, Université de Montréal, Hiver 2026.
