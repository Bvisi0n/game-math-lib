# GameMathLib

**GameMathLib** is a lightweight, test-driven C++ math library focused on 2D vector operations for game development. It is modular, documented with Doxygen, and structured for easy integration into larger game engines or academic projects.

---

## ✨ Features

- Immutable `Vector2D` class with value-returning methods
- Common operations: addition, subtraction, scalar division
- Dot product, length, normalization, perpendicular
- Tolerance-based equality with `Equals()`
- Defensive fallback logic (e.g., normalize `(0, 0)` → `(0, 0)`)
- Operator overloading for intuitive usage
- Fully unit-tested using **Catch2**

---

## 🚀 Getting Started

Clone the repository and open the `.sln` in Visual Studio (Windows) or use CMake for cross-platform builds.

### Prerequisites
- C++17 compatible compiler
- [Catch2](https://github.com/catchorg/Catch2) (included via headers)

---

## 📚 Usage Example
```cpp
#include "Vector2D.hpp"

Vector2D a{3.0f, 4.0f};
Vector2D b = a.Normalized();

if (b.Equals(Vector2D{0.6f, 0.8f})) {
    // do something
}
```

---

## 🧭 Project Conventions

This project follows internal style and structure guides to ensure consistency during solo development.

- [Commit Guidelines](.github/commit-guidelines.md)
- [Doxygen Style Guide](.github/doxygen-style.md)
- [Unit Test Guidelines](.github/unit-test-guidelines.md)

These conventions are enforced through `.copilot/config.json` and reflected in all source, test, and documentation files.

---

## 📄 License
This project is licensed under the [MIT License](LICENSE).