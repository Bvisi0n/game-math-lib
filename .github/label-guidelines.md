# Label Guidelines

This file defines the standard label system for the GameMathLib repository.  
Labels are divided into three groups: **type**, **status**, and **scope**.  
All issues must use at least one `type:` and `status:` label. `scope:` labels are optional but encouraged.  
All colors are reused consistently across repositories for visual structure and clarity.

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
| `scope:vector2d`   | Soft Green    | `#C2E0C6` | 2D vector math core module                            |
| `scope:vector3d`   | Soft Blue     | `#BFDADC` | 3D vector math and operations                         |
| `scope:matrix`     | Light Lavender| `#E6CCFF` | 2D/3D matrix transformations                          |
| `scope:conversion` | Pale Yellow   | `#FFF5B1` | Coordinate and type-safe value conversions            |
| `scope:animation`  | Warm Orange   | `#FFD8B1` | Time-based math, interpolation, Bézier, splines       |
| `scope:geometric`  | Light Brown   | `#DCC6AE` | Geometric algebra — rotors, bivectors, etc.           |
| `scope:test`       | Pale Orange   | `#FAD8C7` | Unit test coverage or test framework logic            |
| `scope:docs`       | Lavender Gray | `#E6E6FA` | Markdown, Doxygen, or documentation updates           |
| `scope:core`       | Neutral Gray  | `#CCCCCC` | Shared constants, global tolerances, config headers   |

---

## ✅ Labeling Rules

- Each issue must have **exactly one** `type:` label and **one** `status:` label.
- `scope:` labels are optional but encouraged for organization and filtering.
- All labels are lowercase and use a consistent prefix (`type:`, `status:`, `scope:`).
- Colors are selected to avoid confusion between categories while staying readable.

---

This label system is optimized for:

- ⚙️ Copilot context and structured AI assistance
- 📦 Clean solo and team workflows
- 🧭 Milestone tracking and scope filtering
- 🧪 Reliable test coverage insights