# Unit Test Guidelines

These guidelines define how unit tests are written and organized within this project.

---

## 📆 Structure

- Each function should have one or more `TEST_CASE`s.
- Each `TEST_CASE` must test **exactly one scenario**.
- No shared state between tests — every case must be **fully independent**.
- Use `#pragma region` to logically group test cases by function.

```cpp
#pragma region Normalize

TEST_CASE("Vector2D::Normalize - zero vector") {
    Vector2D v{0.0f, 0.0f};
    v.Normalize();
    CHECK(v.Equals(Vector2D{0.0f, 0.0f}));
}

#pragma endregion
```

---

## 🧪 CHECK vs REQUIRE

| Use         | When to apply                                 |
|-------------|------------------------------------------------|
| `CHECK()`   | For standard assertions (multiple allowed)     |
| `REQUIRE()` | Only for essential preconditions that would make further tests irrelevant if failed |

---

## ✍️ Naming TEST_CASEs

- Format: `Vector2D::FunctionName - scenario description`
- Example: `"Vector2D::Normalize - zero vector"`
- Keep descriptions short and specific (`"already normalized"`, `"negative x"`, etc.)

---

## 💡 Extra Tips

- Always test edge cases (zero, negative input, already normalized, etc.)
- Use `Equals()` or floating-point tolerant comparisons
- Avoid logic inside tests (no loops, branches) unless absolutely necessary

---

## 🧠 Why This Style?

- Easier debugging (a failed test clearly reports the scenario)
- Helps Copilot generate focused and predictable suggestions
- Matches Clean Code principles (single responsibility, low coupling)
