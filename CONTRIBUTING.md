# Contributing

> This is a personal learning repository for **IFT1166 — Programmation orientée objet en C++** (Université de Montréal, Hiver 2026). Contributions, suggestions, and feedback are welcome!

---

## How to Contribute

### Report a Bug or Suggestion

Open an [issue](https://github.com/PtiCalin/cpp/issues/new/choose) using one of the provided templates:

- **Bug Report** — code that doesn't compile or behaves incorrectly.
- **New Content** — suggest examples, topics, or projects to add.
- **Question** — ask a C++ question or flag something to revisit.

### Submit a Pull Request

1. Fork the repository.
2. Create a branch from `main` (`git checkout -b your-branch-name`).
3. Make your changes following the guidelines below.
4. Open a pull request — the PR template will guide you.

---

## Guidelines

### Repository Structure

Each concept lives in its own folder:

```
topic-folder/
├── README.md          # Concise notes on the concept
├── example.cpp        # Small runnable example
└── ...
```

- One concept per folder, one focused example per file.
- Keep `main()` minimal — delegate to functions and classes.
- Place exploratory code in `experiments/` first, then move to the proper folder once cleaned up.

### Code Style

Follow the project [STYLEGUIDE.md](STYLEGUIDE.md):

- `snake_case` for variables and functions.
- `PascalCase` for class names.
- `UPPER_CASE` for macros and constants.
- 4 spaces indentation, one statement per line.
- Comments explain **why**, not **what**.

### Commit Messages

Use the project commit template (`.gitmessage`):

```
<type>: <short summary>

<optional body — explain why, not what>
```

**Types:** `Add`, `Fix`, `Refactor`, `Document`, `Update`, `Remove`, `Style`

Examples:
```
Add: array sorting examples in fundamentals/
Fix: off-by-one error in file-handling.cpp
Document: update ROADMAP Phase 3 checkboxes
```

### Checklist Before Submitting

- [ ] Code compiles without errors (`g++ -Wall -Wextra`)
- [ ] Files are placed in the correct folder
- [ ] Related `README.md` files have been updated
- [ ] `UPDATES.md` has been updated (if applicable)
- [ ] No secrets, credentials, or personal data included

---

## License

By contributing, you agree that your contributions will be licensed under the [MIT License](LICENSE).
