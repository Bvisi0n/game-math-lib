# Commit Message Guidelines

Use the following format:

```
[Action] [Scope] [Optional Context]

- [Short summary of what was done]
- [Where the change occurred]
- [Any tests, docs, edge case notes (optional)]
- Closes #<issue_number> (if applicable)
```

If the commit is related to an issue but **not yet closing it**, reference the issue manually in the message (`See #12`) or add a comment with the commit hash in the issue thread.

---

## ✅ Example Commits

```
Add GameMath::Vector2D::Equals

- Implemented tolerant comparison using per-component threshold.
- Added 4 test cases in main.cpp.
- Documented intended usage in Doxygen.
- Closes #12

Fix GameMath::Vector2D::IsZero

- Changed `<` to `<=` to handle exact zero values correctly.
- Confirmed all IsZero-related tests now pass.
- Closes #15

Document GameMath::Vector2D

- Reworded Doxygen for IsZero() and Equals() for clarity and consistency.
- See #18

Refactor GameMath::Vector2D operators

- Unified naming and formatting for equality-related functions.
- No functional changes.
- Closes #20
```

---

## 🧩 Recommended Action Verbs

| Action     | When to Use                              |
| ---------- | ---------------------------------------- |
| `Add`      | New function, file, test, or concept     |
| `Fix`      | Resolve bug or behavioral issue          |
| `Update`   | Modify existing behavior                 |
| `Refactor` | Code change without behavior change      |
| `Remove`   | Deleted logic or file                    |
| `Document` | Comment or documentation-related changes |
| `Test`     | Added/modified test logic                |

---

## 📦 Recommended Scopes

| Scope Type | Examples                            |
| ---------- | ----------------------------------- |
| Class      | `GameMath::Vector2D`                |
| Function   | `GameMath::Vector2D::IsZero`        |
| File       | `Vector2D.cpp`, `main.cpp`          |
| Subsystem  | `UnitTests`, `Doxygen`, `Benchmark` |

---

## 💡 Tips

* Be concise but informative.
* Prefer lowercase verbs in list items.
* Keep consistent spacing and casing in scopes.
* Always link to a related issue if one exists (Closes # or See #).

---

This convention improves traceability between issues and commits, and helps future contributors understand intent quickly.