# Label Guidelines

This file defines the standard label system for the GameMathLib repository.  
Labels are divided into three groups: **type**, **status**, and **scope**.  
All issues must use at least one `type:` and `status:` label. `scope:` labels are optional but encouraged.
All colors are reusable across repositories for a consistent visual system.

---

## 🧩 Type Labels (Blue Spectrum)
Describes the nature of the task.

| Label           | Color     | Hex       | Use Case                                             |
|----------------|-----------|-----------|------------------------------------------------------|
| `type:feature` | Indigo    | `#1D76DB` | New functionality or method to implement             |
| `type:test`    | Soft Blue | `#6CA0DC` | Unit test for new or existing functionality          |
| `type:bug`     | Red       | `#D73A4A` | Fix incorrect behavior or logic                      |
| `type:refactor`| Yellow    | `#FBCA04` | Internal code change without external behavior change|
| `type:doc`     | Sky Blue  | `#C5DEF5` | Doxygen or documentation updates                     |
| `type:cleanup` | Sand      | `#F9D0C4` | Code or file removal, formatting, simplification     |

---

## 🚦 Status Labels (Green & Neutral)
Tracks progress of the issue.

| Label            | Color     | Hex       | Use Case                              |
|------------------|-----------|-----------|----------------------------------------|
| `status:todo`    | Light Gray| `#EEEEEE` | Planned, not started                   |
| `status:active`  | Green     | `#0E8A16` | Currently being worked on              |
| `status:blocked` | Dark Red  | `#B60205` | Waiting on another issue or decision   |
| `status:done`    | Teal      | `#1DD2AF` | Work is complete and merged/closed     |

---

## 🗂️ Scope Labels (Muted & Thematic)
Clarifies which part of the code/library the issue affects.

| Label              | Color         | Hex       | Use Case                                              |
|-------------------|---------------|-----------|-------------------------------------------------------|
| `scope:vector2d`   | Soft Green    | `#C2E0C6` | Core Vector2D class and related operations            |
| `scope:transform`  | Slate         | `#9FA8DA` | Matrix and transformation logic                       |
| `scope:math`       | Plum          | `#D4C5F9` | General mathematical logic or utility                 |
| `scope:test`       | Pale Orange   | `#FAD8C7` | Unit test coverage or test framework logic            |
| `scope:docs`       | Light Lavender| `#E6E6FA` | Doxygen, Readme, or markdown documentation            |
| `scope:core`       | Neutral Gray  | `#CCCCCC` | Global settings, tolerances, configs, shared headers  |

---

## ✅ Labeling Rules
- Each issue must have **one** `type:` label and **one** `status:` label.
- `scope:` labels are optional but help organize the board and filters.
- Label names are lowercase and prefix-based (`type:`, `status:`, `scope:`).

---

This label system is optimized for:
- ⚙️ Copilot context and structured code generation
- 📦 Clean solo and team workflows
- 🔁 Reuse across GameMathLib and future related repos