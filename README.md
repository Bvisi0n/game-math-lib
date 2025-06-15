# GameMathLib

**GameMathLib** is a modular, test-driven C++ math library designed for game development and animation systems.  
It is lightweight, header-based, and structured for easy integration into custom engines or academic projects.

---

## ✨ Current Scope

The library is structured around progressive math modules.  
Each module is fully unit-tested, Doxygen-documented, and adheres to a strict style and contribution workflow.

✅ **Available now**  
🔧 **Planned / in development**

| Module                                | Status         | Description                                                       |
|---------------------------------------|----------------|-------------------------------------------------------------------|
| `Vector2D` Core Module                | ✅ Complete    | Foundational 2D vector math (normalization, dot, equality, etc.)  |
| `Vector3D` Core Module                | 🧪 In progress | Core 3D vector operations and directional math                    |
| `Matrix2D/3D` Transform Module        | 🧪 In progress | Matrix-based transformations, projections, and view logic         |
| `Quaternion` Module                   | 🔧 Planned     | Quaternion rotation, slerp, interpolation, and conversion         |
| `Vector2D` Utility Extensions         | 🔧 Planned     | Snapping, clamping, projections, geometric reasoning in 2D        |
| `Vector3D` Utility Extensions         | 🔧 Planned     | 3D equivalents for vector utilities and analysis                  |
| `Conversions` Module                  | 🔧 Planned     | Type-safe transforms (Vec2↔Vec3, radians↔degrees, polar↔cartesian)|
| `Animation Math` Module               | 🔧 Planned     | Time-based math, interpolation, Bézier, and parametric movement   |
| `Geometric Algebra` Module            | 🔧 Planned     | Advanced algebra for rotors, bivectors, and unified operations    |
| `Collision & Intersections` Module    | 🔧 Planned     | AABB, raycasting, overlap tests, velocity-aware collision checks  |
| `Scene Graph & View Transform` Module | 🔧 Planned     | Hierarchical transforms, camera systems, and scene control        |

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