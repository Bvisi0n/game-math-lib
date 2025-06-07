# Doxygen Comment Style Guide

This document defines the documentation style for functions and operators using Doxygen.  
It is optimized for use with Copilot and human readability in tooltips.

---

## ✅ Format

Use the following format:

```cpp
/** @brief [Short summary of what the function does]
    @param name: Description of the parameter.
    @return Description of what the function returns. */
```

---

## 🧩 Tag Rules

Only use these three tags, unless absolutely necessary:

- `@brief`: One-line summary of what the function does.
- `@param`: One per parameter. Always follow the name with a colon `:`.
- `@return`: Only if the function returns something meaningful.

---

## ✍️ Writing Guidelines

- Be **brief but clear** — avoid filler, focus on purpose and edge cases.
- Always write full sentences. Start with a capital and end with a period.
- **Explicit behavior must be documented**, such as:
  - Bitwise comparison (e.g., `operator==` vs. `Equals`)
  - Fallback logic (e.g., returning `(0, 0)` on divide by zero)
- Do **not** mention internal implementation (e.g., avoid `LengthSquared()` unless externally relevant).
- Keep line length readable, but multiline comments are fine if they stay concise.

---

## 💡 Examples

```cpp
/** @brief Adds two vectors component-wise.
    @param other: The vector to add.
    @return A new Vector2D representing the sum. */
Vector2D operator+(const Vector2D& other) const;

/** @brief Returns a 90° counter-clockwise rotated copy of this vector.
    @return A new Vector2D perpendicular to this one. */
Vector2D Perpendicular() const;

/** @brief Divides both vector components by a scalar value.
    @param scalar: The value to divide each component by.
    @return A new Vector2D. If scalar is zero, returns (0, 0). */
Vector2D operator/(const float scalar) const;
```

---

## 🧠 Notes

- Do not overdocument trivial constructors or getters.
- Keep style consistent across all headers.
- This file serves as a baseline for Copilot and contributors across all future projects.