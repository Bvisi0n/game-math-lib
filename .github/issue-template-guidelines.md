# Issue Template Guidelines

This document defines the standard issue creation format for the GameMathLib repository.
It aligns with the GitHub `standard.yml` form and helps maintain consistent structure, labeling, and Copilot support.

---

## 🧩 Sections in Every Issue
Each issue must include the following fields:

### 1. **Type**
- Required dropdown.
- Options: `type:feature`, `type:test`, `type:bug`, `type:refactor`, `type:doc`, `type:cleanup`

### 2. **Status**
- Required dropdown.
- Options: `status:todo`, `status:active`, `status:blocked`

### 3. **Scope**
- Optional checklist (zero or more).
- Options: `scope:vector2d`, `scope:transform`, `scope:math`, `scope:test`, `scope:docs`, `scope:core`

### 4. **Description**
- Required.
- Summarizes the purpose of the issue.
- Include function/class names, expected behavior, edge case notes, or math references.

### 5. **Tasks**
- Optional checklist.
- Default items:
  - [ ] Implement logic
  - [ ] Write test(s)
  - [ ] Document in Doxygen

### 6. **Notes**
- Optional free-form field.
- Used for reasoning, constraints, references, or sketches.

---

## 🧠 When to Use Checklists vs Sub-Issues
- Prefer **checklists** inside a single issue when tasks are tightly related (e.g., feature + tests + doc).
- Create **sub-issues** only when:
  - Tests are delayed or decoupled.
  - Documentation is being handled separately.
  - Milestones, contributors, or time investment differ.

---

## 🛠️ Example Issue Template (Rendered)

```markdown
### 🧩 Type of Issue
- [x] feature

### 🚦 Status
- [x] todo

### 🗂️ Scope
- [x] scope:vector2d

---

### 🔧 Description
Implement Vector2D::Normalize with safe fallback for zero vectors. Result must preserve direction and return zero when length is zero.

---

### ✅ Tasks
- [ ] Add Vector2D::Normalize implementation
- [ ] Write tests: already normalized, negative input, zero vector
- [ ] Document behavior in Doxygen

---

### 💡 Notes
Uses inverse sqrt approximation (optional). Must clamp to epsilon threshold.