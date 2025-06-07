# Commit Message Guidelines

Use the following format:

```
[Action] [Scope] [Optional Context]

- [Short summary of what was done]
- [Where the change occurred]
- [Any tests, docs, edge case notes (optional)]
```

---

## ✅ Example Commits

```
Add GameMath::Vector2D::Equals

- Implemented tolerant comparison using per-component threshold.
- Added 4 test cases in main.cpp.
- Documented intended usage in Doxygen.

Fix GameMath::Vector2D::IsZero

- Changed `<` to `<=` to handle exact zero values correctly.
- Confirmed all IsZero-related tests now pass.

Document GameMath::Vector2D

- Reworded Doxygen for IsZero() and Equals() for clarity and consistency.

Refactor GameMath::Vector2D operators

- Unified naming and formatting for equality-related functions.
- No functional changes.
```

---

## 🧩 Recommended Action Verbs

| Action      | When to Use                                 |
|-------------|----------------------------------------------|
| `Add`       | New function, file, test, or concept         |
| `Fix`       | Resolve bug or behavioral issue              |
| `Update`    | Modify existing behavior                     |
| `Refactor`  | Code change without behavior change          |
| `Remove`    | Deleted logic or file                        |
| `Document`  | Comment or documentation-related changes     |
| `Test`      | Added/modified test logic                    |

---

## 📦 Recommended Scopes

| Scope Type  | Examples                                     |
|-------------|----------------------------------------------|
| Class       | `GameMath::Vector2D`                         |
| Function    | `GameMath::Vector2D::IsZero`                 |
| File        | `Vector2D.cpp`, `main.cpp`                   |
| Subsystem   | `UnitTests`, `Doxygen`, `Benchmark`          |

---

## 💡 Tips

- Be concise but informative.
- Prefer lowercase verbs in list items.
- Keep consistent spacing and casing in scopes.

---

You can now use this style for all commits across the project.
