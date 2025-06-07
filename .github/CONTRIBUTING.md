# Contributing to GameMathLib

First off, thanks for taking the time to contribute! This project thrives on clean code, consistent structure, and mathematically correct behavior.

---

## 🛠️ Development Guidelines

- Write self-contained, readable C++17 code.
- Follow the function and operator styles outlined in [Doxygen Style Guide](.github/doxygen-style.md).
- Use the naming and layout standards from `.copilot/config.json` (e.g., PascalCase for classes).
- Place new features in logically separated files under `/src/`.
- Use `const`, `&`, and `value` parameters appropriately — see existing code as reference.

---

## ✅ Commit Style

Follow the commit message structure defined in the [Commit Guidelines](.github/commit-guidelines.md):

```
[Action] [Scope] [Optional Context]

- [What was changed and why]
- [Where it happened and any test/doc additions]
```

Examples:
```
Add GameMath::Vector2D::Perpendicular
- Added a method to compute the 90-degree rotated vector.
- Wrote 3 unit tests under #pragma region Perpendicular.
```

---

## 🧪 Writing Tests

Refer to the [Unit Test Guidelines](.github/unit-test-guidelines.md) for structure, naming, and assertion rules. Summary:

- One `TEST_CASE` per logical scenario
- Use `CHECK()` unless `REQUIRE()` is absolutely necessary
- Group by function using `#pragma region`
- Use tolerant comparisons for floats (`Equals()`)

Run tests locally before submitting a PR.

---

## 📋 Reference Guides

- [Commit Guidelines](.github/commit-guidelines.md)
- [Doxygen Style Guide](.github/doxygen-style.md)
- [Unit Test Guidelines](.github/unit-test-guidelines.md)

---

## 🙋 Contributions

GameMathLib is currently maintained as a solo project during my academic training.

You're welcome to explore or clone the repository for personal or educational use,  
but pull requests and external contributions are **not accepted at this time**.

If you're inspired to build on it, feel free to fork it and create your own version!