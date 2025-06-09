# GameMathLib

**GameMathLib** is a modular, test-driven C++ math library designed for game development and animation systems.  
It is lightweight, header-based, and structured for easy integration into custom engines or academic projects.

---

## ✨ Current Scope

The library is structured around progressive math modules.  
Each module is fully unit-tested, Doxygen-documented, and adheres to a strict style and contribution workflow.

✅ **Available now**  
🔧 **Planned / in development**

| Module       | Status     | Description                                 |
|--------------|------------|---------------------------------------------|
| `Vector2D`   | 🧪 In progress | Foundational 2D vector math                |
| `Vector3D`   | 🔧 Planned  | Core 3D vector operations                    |
| `Matrix2D/3D`| 🔧 Planned  | Transformations, rotations, projections     |
| `Conversions`| 🔧 Planned  | Type-safe transforms (Vec2↔Vec3, polar↔cartesian) |
| `Animation`  | 🔧 Planned  | Time-based math, interpolation, splines     |
| `GeometricAlgebra` | 🔧 Optional | Advanced structure for rotors, bivectors |

---

## 📦 Features (Implemented so far)

- Constructors (default and parameterized)
- Arithmetic operators: `+`, `-`, `*`, `/`
- Dot product and length calculations
- Tolerance-based equality check via `Equals()`
- Defensive zero handling in normalization
- Perpendicular vector calculation
- Comparison operators `==` and `!=`
- Unit tests for all implemented features using **Catch2**
- Doxygen documentation with consistent style

---

## 🧭 Project Philosophy

GameMathLib aims to balance readability, mathematical correctness, and performance without sacrificing maintainability.  
It's used to demonstrate modern C++ workflows, clean test-driven development, and AI-assisted tooling integration.

---

## 🧰 Project Conventions

- Written in **modern C++17**, organized as a header-based static library
- File structure follows: one class or concept per source file
- Unit tests use **Catch2** and are grouped using `#pragma region`
- Assertion style: `CHECK()` preferred over `REQUIRE()` unless critical
- Project conventions are standardized across:
  - [Commit Guidelines](.github/commit-guidelines.md)
  - [Doxygen Style](.github/doxygen-style.md)
  - [Unit Test Guidelines](.github/unit-test-guidelines.md)
  - [Label System](.github/label-guidelines.md)
  - [Issue Template Guidelines](.github/issue-template-guidelines.md)
- Issue tracking uses a [Markdown-based issue template](.github/ISSUE_TEMPLATE/new-issue.md) with structured fields and label-driven categorization
- Internal coding style enforced via `.copilot/config.json`

---

## 🤖 AI & Tooling Disclosure

This project uses GitHub Copilot and ChatGPT as drafting assistants for test generation, naming, and structural guidance.  
All content is reviewed manually. See [AI Disclosure](#ai--tooling-disclosure).

---

## 📄 License

This project is licensed under the [MIT License](LICENSE.md).