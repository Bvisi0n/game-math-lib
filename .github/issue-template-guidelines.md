# Issue Template Guidelines

This document defines the standard issue creation format for the GameMathLib repository. It is based on a Markdown template (`new-issue.md`) that supports label-based workflows and clean formatting.

---

## 🧾 Format Overview

Each issue must follow a consistent structure using the Markdown template. The fields below ensure clarity and compatibility with labeling, commit standards, and Copilot suggestions.

### 1. **Title**

* Write a **clear and concise description** of the task.
* Do **not** include type, status, or scope in the title — labels cover that.
* Good examples:

  * `Fix Equals() comparison logic for float tolerance`
  * `Update docs for switch to .md issue template`
  * `Add test cases for Vector2D::Rotate()`

### 2. **Type** (`🧩 Type of Issue`)

* Manual text input — e.g., `type:feature`
* Valid options:

  * `type:feature`
  * `type:test`
  * `type:bug`
  * `type:refactor`
  * `type:doc`
  * `type:cleanup`

### 3. **Scope** (`🗂️ Scope`)

* Select one or more applicable scope labels:

  * `scope:vector2d`
  * `scope:transform`
  * `scope:math`
  * `scope:test`
  * `scope:docs`
  * `scope:core`

### 4. **Description** (`🔧 Description`)

* Explain what the issue is about.
* Mention functions, edge cases, goals, and expected behavior.

### 5. **Tasks** (`✅ Tasks`)

* Optional checklist.
* Helps track logic, testing, and documentation steps.
* Default:

  * [ ] Implement logic
  * [ ] Write tests
  * [ ] Add Doxygen comments

### 6. **Notes** (`💡 Notes`)

* Optional free-form space for equations, design ideas, or constraints.

---

## 🧠 Checklists vs Sub-Issues

Prefer **checklists** inside a single issue when tasks are tightly related.

Use **sub-issues** only when:

* Documentation or testing will be added later
* Milestones or contributors differ
* Tasks are too complex to track in one place

---

## 🛠️ Markdown Issue Template Example

```markdown
Title: Fix Equals() comparison logic for float tolerance

## 🧩 Type of Issue
- type:bug

## 🗂️ Scope
- scope:vector2d

---

## 🔧 Description
Current Equals() method uses `<` instead of `<=` for epsilon check, leading to unexpected false negatives when values are close.

---

## ✅ Tasks
- [ ] Adjust comparison logic
- [ ] Write regression test for borderline case
- [ ] Update Doxygen explanation for Equals()

---

## 💡 Notes
Affected by floating-point error margin. Use existing `IsZero()` behavior as reference.
```

---

## 🔗 Linking Commits to Issues

Whenever a commit completes or addresses an issue:

- Include `Closes #<issue_number>` in the commit message to auto-close the issue.
- Use `See #<issue_number>` for related work that doesn't fully resolve the issue yet.
- If you forget to reference the issue in the commit, **add a comment** to the issue with the commit hash manually:

```
Linked commit: 2f1e4d8
```

This practice ensures traceability between commits and issues, which is especially helpful for history reviews and Copilot context.