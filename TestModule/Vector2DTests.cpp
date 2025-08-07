#include "catch_amalgamated.hpp"
#include "Vector2D.hpp"

#pragma region Constructor
    TEST_CASE("Vector2D::Vector2D - default values") {
        GameSystems::Math::Vector2D v;
        CHECK(v.x == Catch::Approx(0.0f));
        CHECK(v.y == Catch::Approx(0.0f));
    }
    TEST_CASE("Vector2D::Vector2D - parameterized values") {
        GameSystems::Math::Vector2D v(3.0f, 4.0f);
        CHECK(v.x == Catch::Approx(3.0f));
        CHECK(v.y == Catch::Approx(4.0f));
    }
#pragma endregion

#pragma region operator+
    TEST_CASE("Vector2D::operator+ - adds components") {
        GameSystems::Math::Vector2D a(2.0f, 3.0f);
        GameSystems::Math::Vector2D b(4.0f, 5.0f);
        GameSystems::Math::Vector2D result = a + b;
        CHECK(result.x == Catch::Approx(6.0f));
        CHECK(result.y == Catch::Approx(8.0f));
    }
#pragma endregion

#pragma region operator-
    TEST_CASE("Vector2D::operator- - subtracts components") {
        GameSystems::Math::Vector2D a(5.0f, 3.0f);
        GameSystems::Math::Vector2D b(2.0f, 1.0f);
        GameSystems::Math::Vector2D result = a - b;
        CHECK(result.x == Catch::Approx(3.0f));
        CHECK(result.y == Catch::Approx(2.0f));
    }
#pragma endregion

#pragma region operator*
    TEST_CASE("Vector2D::operator* - scales components") {
        GameSystems::Math::Vector2D v(1.5f, -2.0f);
        GameSystems::Math::Vector2D result = v * 2.0f;
        CHECK(result.x == Catch::Approx(3.0f));
        CHECK(result.y == Catch::Approx(-4.0f));
    }
#pragma endregion

#pragma region operator/
    TEST_CASE("Vector2D::operator/ - divides by scalar") {
        GameSystems::Math::Vector2D v(8.0f, 4.0f);
        GameSystems::Math::Vector2D result = v / 2.0f;
        CHECK(result.x == Catch::Approx(4.0f));
        CHECK(result.y == Catch::Approx(2.0f));
    }
    TEST_CASE("Vector2D::operator/ - zero scalar returns zero vector") {
        GameSystems::Math::Vector2D v(5.0f, -3.0f);
        GameSystems::Math::Vector2D result = v / 0.0f;
        CHECK(result.x == Catch::Approx(0.0f));
        CHECK(result.y == Catch::Approx(0.0f));
    }
    TEST_CASE("Vector2D::operator/ - divide by negative scalar") {
        GameSystems::Math::Vector2D v(4.0f, -8.0f);
        GameSystems::Math::Vector2D result = v / -2.0f;
        CHECK(result.x == Catch::Approx(-2.0f));
        CHECK(result.y == Catch::Approx(4.0f));
    }
#pragma endregion

#pragma region operator==
    TEST_CASE("Vector2D::operator== - exact match") {
        GameSystems::Math::Vector2D a(1.0f, 2.0f);
        GameSystems::Math::Vector2D b(1.0f, 2.0f);
        CHECK(a == b);
    }
    TEST_CASE("Vector2D::operator== - different component") {
        GameSystems::Math::Vector2D a(1.0f, 2.0f);
        GameSystems::Math::Vector2D c(1.0f, 2.0001f);
        CHECK_FALSE(a == c);
    }
#pragma endregion

#pragma region operator!=
    TEST_CASE("Vector2D::operator!= - different components") {
        GameSystems::Math::Vector2D a(1.0f, 2.0f);
        GameSystems::Math::Vector2D b(1.0f, 3.0f);
        CHECK(a != b);
    }
    TEST_CASE("Vector2D::operator!= - equal components") {
        GameSystems::Math::Vector2D a(1.0f, 2.0f);
        GameSystems::Math::Vector2D b(1.0f, 2.0f);
        CHECK_FALSE(a != b);
    }
#pragma endregion

#pragma region ClampComponents
    TEST_CASE("Vector2D::ClampComponents - x and y within range") {
        GameSystems::Math::Vector2D v(2.0f, 3.0f);
        v.ClampComponents(1.0f, 5.0f, 1.0f, 5.0f);
        CHECK(v.Equals(GameSystems::Math::Vector2D(2.0f, 3.0f)));
    }
    TEST_CASE("Vector2D::ClampComponents - x and y above max") {
        GameSystems::Math::Vector2D v(7.0f, 9.0f);
        v.ClampComponents(0.0f, 5.0f, 0.0f, 5.0f);
        CHECK(v.Equals(GameSystems::Math::Vector2D(5.0f, 5.0f)));
    }
    TEST_CASE("Vector2D::ClampComponents - x and y below min") {
        GameSystems::Math::Vector2D v(-4.0f, -3.0f);
        v.ClampComponents(-2.0f, 2.0f, -2.0f, 2.0f);
        CHECK(v.Equals(GameSystems::Math::Vector2D(-2.0f, -2.0f)));
    }
    TEST_CASE("Vector2D::ClampComponents - mixed clamping") {
        GameSystems::Math::Vector2D v(7.0f, -4.0f);
        v.ClampComponents(0.0f, 5.0f, -2.0f, 2.0f);
        CHECK(v.Equals(GameSystems::Math::Vector2D(5.0f, -2.0f)));
    }
    TEST_CASE("Vector2D::ClampComponents - clamp x only") {
        GameSystems::Math::Vector2D v(10.0f, 2.0f);
        v.ClampComponents(0.0f, 5.0f, 0.0f, 5.0f);
        CHECK(v.Equals(GameSystems::Math::Vector2D(5.0f, 2.0f)));
    }
    TEST_CASE("Vector2D::ClampComponents - clamp y only") {
        GameSystems::Math::Vector2D v(2.0f, -3.0f);
        v.ClampComponents(0.0f, 5.0f, 0.0f, 5.0f);
        CHECK(v.Equals(GameSystems::Math::Vector2D(2.0f, 0.0f)));
    }
    TEST_CASE("Vector2D::ClampComponents - values on boundary") {
        GameSystems::Math::Vector2D v(0.0f, 5.0f);
        v.ClampComponents(0.0f, 5.0f, 0.0f, 5.0f);
        CHECK(v.Equals(GameSystems::Math::Vector2D(0.0f, 5.0f))); // no change
    }
#pragma endregion

#pragma region ClampLength
    TEST_CASE("Vector2D::ClampLength - within range remains unchanged") {
        GameSystems::Math::Vector2D v(3.0f, 4.0f); // length = 5
        v.ClampLength(2.0f, 6.0f);
        CHECK(v.Length() == Catch::Approx(5.0f));
    }
    TEST_CASE("Vector2D::ClampLength - clamps above max") {
        GameSystems::Math::Vector2D v(6.0f, 8.0f); // length = 10
        v.ClampLength(0.0f, 5.0f);
        CHECK(v.Length() == Catch::Approx(5.0f));
    }
    TEST_CASE("Vector2D::ClampLength - clamps below min") {
        GameSystems::Math::Vector2D v(0.3f, 0.4f); // length = 0.5
        v.ClampLength(1.0f, 10.0f);
        CHECK(v.Length() == Catch::Approx(1.0f));
    }
    TEST_CASE("Vector2D::ClampLength - zero vector stays zero") {
        GameSystems::Math::Vector2D v(0.0f, 0.0f);
        v.ClampLength(1.0f, 5.0f);
        CHECK(v.IsZero());
    }
    TEST_CASE("Vector2D::ClampLength - min equals max clamps to exact length") {
        GameSystems::Math::Vector2D v(10.0f, 0.0f); // length = 10
        v.ClampLength(5.0f, 5.0f);
        CHECK(v.Length() == Catch::Approx(5.0f));
    }
#pragma endregion

#pragma region DistanceTo
    TEST_CASE("Vector2D::DistanceTo - standard Pythagorean case") {
        GameSystems::Math::Vector2D a(0.0f, 0.0f);
        GameSystems::Math::Vector2D b(3.0f, 4.0f);
        CHECK(a.DistanceTo(b) == Catch::Approx(5.0f));
    }
    TEST_CASE("Vector2D::DistanceTo - reverse order yields same result") {
        GameSystems::Math::Vector2D a(3.0f, 4.0f);
        GameSystems::Math::Vector2D b(0.0f, 0.0f);
        CHECK(a.DistanceTo(b) == Catch::Approx(5.0f));
    }
    TEST_CASE("Vector2D::DistanceTo - same point yields zero") {
        GameSystems::Math::Vector2D a(1.0f, 1.0f);
        CHECK(a.DistanceTo(a) == Catch::Approx(0.0f));
    }
    TEST_CASE("Vector2D::DistanceTo - diagonal case (non-axis-aligned)") {
        GameSystems::Math::Vector2D a(2.0f, 3.0f);
        GameSystems::Math::Vector2D b(5.0f, 7.0f);
        CHECK(a.DistanceTo(b) == Catch::Approx(5.0f));
    }
    TEST_CASE("Vector2D::DistanceTo - negative coordinates") {
        GameSystems::Math::Vector2D a(-3.0f, -4.0f);
        GameSystems::Math::Vector2D b(0.0f, 0.0f);
        CHECK(a.DistanceTo(b) == Catch::Approx(5.0f));
    }
    TEST_CASE("Vector2D::DistanceTo - pure horizontal delta") {
        GameSystems::Math::Vector2D a(0.0f, 0.0f);
        GameSystems::Math::Vector2D b(5.0f, 0.0f);
        CHECK(a.DistanceTo(b) == Catch::Approx(5.0f));
    }
    TEST_CASE("Vector2D::DistanceTo - pure vertical delta") {
        GameSystems::Math::Vector2D a(0.0f, 0.0f);
        GameSystems::Math::Vector2D b(0.0f, -5.0f);
        CHECK(a.DistanceTo(b) == Catch::Approx(5.0f));
    }
#pragma endregion

#pragma region Dot
    TEST_CASE("Vector2D::Dot - parallel vector") {
        GameSystems::Math::Vector2D a(1.0f, 2.0f);
        GameSystems::Math::Vector2D b(2.0f, 4.0f);
        CHECK(a.Dot(b) == Catch::Approx(10.0f));
    }
    TEST_CASE("Vector2D::Dot - perpendicular vector") {
        GameSystems::Math::Vector2D a(1.0f, 0.0f);
        GameSystems::Math::Vector2D b(0.0f, 1.0f);
        CHECK(a.Dot(b) == Catch::Approx(0.0f));
    }
    TEST_CASE("Vector2D::Dot - opposite vector") {
        GameSystems::Math::Vector2D a(1.0f, 0.0f);
        GameSystems::Math::Vector2D b(-1.0f, 0.0f);
        CHECK(a.Dot(b) == Catch::Approx(-1.0f));
    }
    TEST_CASE("Vector2D::Dot - nearly orthogonal vectors") {
        GameSystems::Math::Vector2D a(1.0f, 0.0f);
        GameSystems::Math::Vector2D b(1e-7f, 1.0f);
        CHECK(a.Dot(b) == Catch::Approx(1e-7f).epsilon(0.01f));
    }
#pragma endregion

#pragma region Equals
    TEST_CASE("Vector2D::Equals - exactly equal vectors") {
        GameSystems::Math::Vector2D a(1.0f, 2.0f);
        GameSystems::Math::Vector2D b(1.0f, 2.0f);
        CHECK(a.Equals(b));
    }
    TEST_CASE("Vector2D::Equals - within default tolerance") {
        GameSystems::Math::Vector2D a(1.0f, 2.0f);
        GameSystems::Math::Vector2D b(1.00001f, 2.00001f);
        CHECK(a.Equals(b));
    }
    TEST_CASE("Vector2D::Equals - outside tolerance") {
        GameSystems::Math::Vector2D a(1.0f, 2.0f);
        GameSystems::Math::Vector2D b(1.01f, 2.01f);
        CHECK_FALSE(a.Equals(b));
    }
    TEST_CASE("Vector2D::Equals - custom tolerance") {
        GameSystems::Math::Vector2D a(1.0f, 2.0f);
        GameSystems::Math::Vector2D b(1.01f, 2.01f);
        CHECK(a.Equals(b, 0.02f));
    }
    TEST_CASE("Vector2D::Equals - comparison with NaN components") {
        GameSystems::Math::Vector2D a(std::numeric_limits<float>::quiet_NaN(), 1.0f);
        GameSystems::Math::Vector2D b(0.0f, std::numeric_limits<float>::quiet_NaN());
        CHECK_FALSE(a.Equals(b));
        CHECK_FALSE(a.Equals(a));
    }
#pragma endregion

#pragma region IsNearlyZero
    TEST_CASE("Vector2D::IsNearlyZero - very short vector") {
        GameSystems::Math::Vector2D v(0.00001f, 0.00001f);
        CHECK(v.IsNearlyZero(0.0001f));
    }
    TEST_CASE("Vector2D::IsNearlyZero - above threshold") {
        GameSystems::Math::Vector2D v(0.09f, 0.09f);
        CHECK_FALSE(v.IsNearlyZero(0.1f));
    }
    TEST_CASE("Vector2D::IsNearlyZero - exact zero vector") {
        GameSystems::Math::Vector2D v(0.0f, 0.0f);
        CHECK(v.IsNearlyZero(0.00001f));
        CHECK(v.IsZero());
    }
#pragma endregion

#pragma region IsZero
    TEST_CASE("Vector2D::IsZero - exact zero") {
        GameSystems::Math::Vector2D v(0.0f, 0.0f);
        CHECK(v.IsZero());
    }
    TEST_CASE("Vector2D::IsZero - non-zero components") {
        GameSystems::Math::Vector2D v(0.0f, 0.1f);
        CHECK_FALSE(v.IsZero());
    }
    TEST_CASE("Vector2D::IsZero - near zero vector") {
        GameSystems::Math::Vector2D v(0.00001f, -0.00001f);
        CHECK(v.IsZero(0.0001f));
    }
    TEST_CASE("Vector2D::IsZero - above threshold") {
        GameSystems::Math::Vector2D v(0.01f, 0.0f);
        CHECK_FALSE(v.IsZero(0.0001f));
    }
    TEST_CASE("Vector2D::IsZero - matches strict when tolerance is 0") {
        GameSystems::Math::Vector2D v(0.0f, 0.0f);
        CHECK(v.IsZero(0.0f));
        CHECK(v.IsZero());
    }
    TEST_CASE("Vector2D::IsZero - tolerance boundary inclusive") {
        GameSystems::Math::Vector2D v(0.1f, 0.0f);
        CHECK(v.IsZero(0.1f));          // on boundary
        CHECK_FALSE(v.IsZero(0.0999f)); // just below
        CHECK(v.IsZero(0.1001f));       // just above
    }
#pragma endregion

#pragma region Length
    TEST_CASE("Vector2D::Length - Pythagorean triple") {
        GameSystems::Math::Vector2D v(3.0f, 4.0f);
        CHECK(v.Length() == Catch::Approx(5.0f));
    }
    TEST_CASE("Vector2D::Length - zero vector") {
        GameSystems::Math::Vector2D v(0.0f, 0.0f);
        CHECK(v.Length() == Catch::Approx(0.0f));
    }
#pragma endregion

#pragma region LengthSquared
    TEST_CASE("Vector2D::LengthSquared - known input") {
        GameSystems::Math::Vector2D v(3.0f, 4.0f);
        CHECK(v.LengthSquared() == Catch::Approx(25.0f));
    }
    TEST_CASE("Vector2D::LengthSquared - zero vector") {
        GameSystems::Math::Vector2D v(0.0f, 0.0f);
        CHECK(v.LengthSquared() == Catch::Approx(0.0f));
    }
#pragma endregion

#pragma region Normalize
    TEST_CASE("Vector2D::Normalize - standard case") {
        GameSystems::Math::Vector2D v{ 3.0f, 4.0f };
        v.Normalize();
        CHECK(v.Equals(GameSystems::Math::Vector2D{ 0.6f, 0.8f }));
    }
    TEST_CASE("Vector2D::Normalize - zero vector fallback") {
        GameSystems::Math::Vector2D v{ 0.0f, 0.0f };
        v.Normalize();
        CHECK(v.Equals(GameSystems::Math::Vector2D{ 0.0f, 0.0f }));
    }
    TEST_CASE("Vector2D::Normalize - already normalized") {
        GameSystems::Math::Vector2D v{ 1.0f, 0.0f };
        v.Normalize();
        CHECK(v.Equals(GameSystems::Math::Vector2D{ 1.0f, 0.0f }));
    }
    TEST_CASE("Vector2D::Normalize - negative direction") {
        GameSystems::Math::Vector2D v{ -5.0f, 0.0f };
        v.Normalize();
        CHECK(v.Equals(GameSystems::Math::Vector2D{ -1.0f, 0.0f }));
    }
    TEST_CASE("Vector2D::Normalize - very small vector") {
        GameSystems::Math::Vector2D v(1e-8f, -1e-8f);
        v.Normalize();
        float length = v.Length();
        CHECK(length == Catch::Approx(1.0f).epsilon(0.001f)); // Allow slight epsilon
    }
#pragma endregion

#pragma region Normalized
    TEST_CASE("Vector2D::Normalized - unit vector") {
        GameSystems::Math::Vector2D v(3.0f, 4.0f);
        GameSystems::Math::Vector2D n = v.Normalized();
        CHECK(n.Length() == Catch::Approx(1.0f).epsilon(0.0001f));
    }
    TEST_CASE("Vector2D::Normalized - zero vector") {
        GameSystems::Math::Vector2D v(0.0f, 0.0f);
        GameSystems::Math::Vector2D n = v.Normalized();
        CHECK(n.x == Catch::Approx(0.0f));
        CHECK(n.y == Catch::Approx(0.0f));
    }
#pragma endregion

#pragma region Perpendicular
    TEST_CASE("Vector2D::Perpendicular - rotates 90 degrees") {
        GameSystems::Math::Vector2D v(1.0f, 0.0f);
        GameSystems::Math::Vector2D perp = v.Perpendicular();
        CHECK(perp.x == Catch::Approx(0.0f));
        CHECK(perp.y == Catch::Approx(1.0f));
    }
    TEST_CASE("Vector2D::Perpendicular - zero vector") {
        GameSystems::Math::Vector2D v(0.0f, 0.0f);
        GameSystems::Math::Vector2D perp = v.Perpendicular();
        CHECK(perp.x == Catch::Approx(0.0f));
        CHECK(perp.y == Catch::Approx(0.0f));
    }
#pragma endregion

#pragma region SnapToGrid
    TEST_CASE("Vector2D::SnapToGrid - snaps positive values") {
        GameSystems::Math::Vector2D v(3.6f, 7.2f);
        v.SnapToGrid(1.0f);
        CHECK(v.Equals(GameSystems::Math::Vector2D(4.0f, 7.0f)));
    }
    TEST_CASE("Vector2D::SnapToGrid - snaps negative values") {
        GameSystems::Math::Vector2D v(-2.7f, -5.1f);
        v.SnapToGrid(1.0f);
        CHECK(v.Equals(GameSystems::Math::Vector2D(-3.0f, -5.0f)));
    }
    TEST_CASE("Vector2D::SnapToGrid - works with fractional grid size") {
        GameSystems::Math::Vector2D v(1.24f, 3.76f);
        v.SnapToGrid(0.5f);
        CHECK(v.Equals(GameSystems::Math::Vector2D(1.0f, 4.0f)));
    }
    TEST_CASE("Vector2D::SnapToGrid - zero grid size leaves vector unchanged") {
        GameSystems::Math::Vector2D v(3.1f, 5.9f);
        v.SnapToGrid(0.0f);
        CHECK(v.Equals(GameSystems::Math::Vector2D(3.1f, 5.9f)));
    }
    TEST_CASE("Vector2D::SnapToGrid - grid-aligned input remains unchanged") {
        GameSystems::Math::Vector2D v(2.0f, -3.5f);
        v.SnapToGrid(0.5f);
        CHECK(v.Equals(GameSystems::Math::Vector2D(2.0f, -3.5f)));
    }
    TEST_CASE("Vector2D::SnapToGrid - negative grid size handled safely") {
        GameSystems::Math::Vector2D v(1.24f, 3.76f);
        v.SnapToGrid(-0.5f);
        CHECK(v.Equals(GameSystems::Math::Vector2D(1.0f, 4.0f)));
    }
    TEST_CASE("Vector2D::SnapToGrid - very small grid size approximates original") {
        GameSystems::Math::Vector2D v(2.345678f, -1.234567f);
        v.SnapToGrid(1e-7f);
        CHECK(v.Equals(GameSystems::Math::Vector2D(2.345678f, -1.234567f)));
    }
    TEST_CASE("Vector2D::SnapToGrid - extremely large grid size snaps to origin") {
        GameSystems::Math::Vector2D v(123.456f, 789.123f);
        v.SnapToGrid(1e10f);
        CHECK(v.Equals(GameSystems::Math::Vector2D(0.0f, 0.0f)));
    }
#pragma endregion

#pragma region Truncate
    TEST_CASE("Vector2D::Truncate - vector longer than max gets shortened") {
        GameSystems::Math::Vector2D v(6.0f, 8.0f); // length = 10
        v.Truncate(5.0f);
        CHECK(v.Length() == Catch::Approx(5.0f));
    }
    TEST_CASE("Vector2D::Truncate - vector shorter than max remains unchanged") {
        GameSystems::Math::Vector2D v(3.0f, 4.0f); // length = 5
        v.Truncate(10.0f);
        CHECK(v.Length() == Catch::Approx(5.0f));
    }
    TEST_CASE("Vector2D::Truncate - zero vector remains zero") {
        GameSystems::Math::Vector2D v(0.0f, 0.0f);
        v.Truncate(5.0f);
        CHECK(v.IsZero());
    }
    TEST_CASE("Vector2D::Truncate - negative max value treated as zero") {
        GameSystems::Math::Vector2D v(3.0f, 4.0f); // length = 5
        v.Truncate(-1.0f);
        CHECK(v.IsZero());
    }
#pragma endregion
