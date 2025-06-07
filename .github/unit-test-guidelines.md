# GameMathLib — Unit Test Style Guide

Deze richtlijnen definiëren hoe unit tests worden geschreven en georganiseerd binnen dit project.

---

## 📆 Structuur

- Elke functie krijgt één of meerdere `TEST_CASE`s.
- Één `TEST_CASE` test **exact één scenario**.
- Geen gedeelde state tussen tests — elke case is **volledig onafhankelijk**.
- Gebruik `#pragma region` om testgroepen per functie logisch te groeperen.

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

| Gebruik      | Situatie                                  |
|--------------|--------------------------------------------|
| `CHECK()`    | Voor alle normale assertions (meerdere per test mogelijk) |
| `REQUIRE()`  | Alleen bij essentiële voorwaarden waarbij verdere checks zinloos zijn |

---

## ✍️ Naamgeving van TEST_CASE

- Formaat: `Vector2D::FunctionName - scenario beschrijving`
- Voorbeeld: `"Vector2D::Normalize - zero vector"`
- Houd beschrijvingen kort, maar specifiek (`"already normalized"`, `"negative x"`, enz.)

---

## 💡 Extra tips

- Test ook randgevallen (zero, negative, already normalized, etc.)
- Gebruik `Equals()` of vergelijkingsmethodes met toleranties voor floats
- Zet geen logica in tests (geen loops, branches) tenzij noodzakelijk

---

## 🧠 Waarom deze stijl?

- Beter voor debugging (failing test zegt exact wat misloopt)
- Makkelijk voor Copilot om juiste testcase te suggereren
- Past bij Clean Code principes (single responsibility, low coupling)
