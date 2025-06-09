# Contributing to GameMathLib

First off, thanks for taking the time to explore or build on GameMathLib!  
This project thrives on clean code, consistent structure, and mathematically correct behavior.

---

## 🛠️ Development Guidelines

- Write self-contained, readable C++17 code.
- Follow the documentation style in the [Doxygen Style Guide](.github/doxygen-style.md).
- Respect naming/layout rules defined in `.copilot/config.json` (e.g., PascalCase for classes).
- Place new functionality in logically separated files under `/src/`.
- Use `const`, `&`, and `value` parameters appropriately — check similar functions for consistency.

---

## ✅ Commit Style

Commits must follow the format defined in the [Commit Guidelines](.github/commit-guidelines.md):

```
[Action] [Scope] [Optional Context]

- [What was changed and why]
- [Where it happened and any test/doc additions]
```

```
Example:

Add GameMath::Vector2D::Perpendicular

- Added a method to compute the 90-degree rotated vector.
- Wrote 3 unit tests under #pragma region Perpendicular.
```

---

## 🧪 Writing Tests

Refer to the [Unit Test Guidelines](.github/unit-test-guidelines.md) for structure and clarity:

- One `TEST_CASE` per logical scenario
- Use `CHECK()` unless `REQUIRE()` is necessary
- Group tests by function using `#pragma region`
- Use tolerant comparisons for floats (`Equals()` or similar)

Run all tests before submitting changes.

---

## 🏷️ Issue Creation and Labeling

GameMathLib uses a **Markdown-based issue template** to streamline and standardize development.

- Use the built-in [issue template](.github/ISSUE_TEMPLATE/new-issue.md) to report bugs, propose features, or add tests/docs.
- Fill out all relevant fields (type, scope, description, tasks, notes).
- Give your issue a **clear and descriptive title** — avoid redundant tags. Labels will cover categorization.

### Labeling Rules

- Assign exactly **one** `type:` label (e.g., `type:feature`)
- Assign exactly **one** `status:` label (e.g., `status:todo`)
- Optionally add one or more `scope:` labels (e.g., `scope:vector2d`, `scope:test`)

See the [Label Guidelines](.github/label-guidelines.md) and [Issue Template Guidelines](.github/issue-template-guidelines.md) for complete rules.

---

## 📋 Reference Guides

All code contributions must follow the established project standards:

- [Commit Guidelines](.github/commit-guidelines.md)
- [Doxygen Style Guide](.github/doxygen-style.md)
- [Unit Test Guidelines](.github/unit-test-guidelines.md)
- [Label Guidelines](.github/label-guidelines.md)
- [Issue Template Guidelines](.github/issue-template-guidelines.md)

---

## 🙋 Contributions

GameMathLib is currently maintained as a solo portfolio project during my academic training.

Pull requests and external contributions are **not accepted at this time**.  
However, you're welcome to explore, fork, or study the repo for personal or educational use.

If this inspires your own math library, feel free to build on it!