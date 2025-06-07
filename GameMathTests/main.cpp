#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "GameMath/Vector2D.hpp"

#pragma region GameMath::Vector2D
    #pragma region Constructor
    TEST_CASE("Vector2D default constructor sets x and y to 0") {
        GameMath::Vector2D v;
        REQUIRE(v.x == Catch::Approx(0.0f));
        REQUIRE(v.y == Catch::Approx(0.0f));
    }
    TEST_CASE("Vector2D parameterized constructor sets x and y correctly") {
        GameMath::Vector2D v(3.0f, 4.0f);
        REQUIRE(v.x == Catch::Approx(3.0f));
        REQUIRE(v.y == Catch::Approx(4.0f));
    }
    #pragma endregion
    #pragma region operator+
    TEST_CASE("Vector2D operator+ adds components") {
        GameMath::Vector2D a(2.0f, 3.0f);
        GameMath::Vector2D b(4.0f, 5.0f);
        GameMath::Vector2D result = a + b;
        REQUIRE(result.x == Catch::Approx(6.0f));
        REQUIRE(result.y == Catch::Approx(8.0f));
    }
    #pragma endregion
    #pragma region operator-
    TEST_CASE("Vector2D operator- subtracts components") {
        GameMath::Vector2D a(5.0f, 3.0f);
        GameMath::Vector2D b(2.0f, 1.0f);
        GameMath::Vector2D result = a - b;
        REQUIRE(result.x == Catch::Approx(3.0f));
        REQUIRE(result.y == Catch::Approx(2.0f));
    }
    #pragma endregion
    #pragma region operator*
    TEST_CASE("Vector2D operator* scales both components") {
        GameMath::Vector2D v(1.5f, -2.0f);
        GameMath::Vector2D result = v * 2.0f;
        REQUIRE(result.x == Catch::Approx(3.0f));
        REQUIRE(result.y == Catch::Approx(-4.0f));
    }
    #pragma endregion
    #pragma region operator/
    TEST_CASE("Vector2D operator/ divides both components by scalar") {
        GameMath::Vector2D v(8.0f, 4.0f);
        GameMath::Vector2D result = v / 2.0f;
        REQUIRE(result.x == Catch::Approx(4.0f));
        REQUIRE(result.y == Catch::Approx(2.0f));
    }
    TEST_CASE("Vector2D operator/ with zero scalar returns zero vector") {
        GameMath::Vector2D v(5.0f, -3.0f);
        GameMath::Vector2D result = v / 0.0f;
        REQUIRE(result.x == Catch::Approx(0.0f));
        REQUIRE(result.y == Catch::Approx(0.0f));
    }
    #pragma endregion
    #pragma region operator==
    TEST_CASE("Vector2D operator== compares components with exact match") {
        GameMath::Vector2D a(1.0f, 2.0f);
        GameMath::Vector2D b(1.0f, 2.0f);
        GameMath::Vector2D c(1.0f, 2.0001f);
        REQUIRE(a == b);
        REQUIRE_FALSE(a == c);
    }
    #pragma endregion
    #pragma region .operator!=
    TEST_CASE("Vector2D operator!= returns true for different components") {
        GameMath::Vector2D a(1.0f, 2.0f);
        GameMath::Vector2D b(1.0f, 3.0f);
        REQUIRE(a != b);
    }
    TEST_CASE("Vector2D operator!= returns false for equal components") {
        GameMath::Vector2D a(1.0f, 2.0f);
        GameMath::Vector2D b(1.0f, 2.0f);
        REQUIRE_FALSE(a != b);
    }
    #pragma endregion
    #pragma region .Dot()
    TEST_CASE("Vector2D Dot with parallel vector returns positive scalar") {
        GameMath::Vector2D a(1.0f, 2.0f);
        GameMath::Vector2D b(2.0f, 4.0f);
        REQUIRE(a.Dot(b) == Catch::Approx(10.0f));
    }
    TEST_CASE("Vector2D Dot with perpendicular vector returns zero") {
        GameMath::Vector2D a(1.0f, 0.0f);
        GameMath::Vector2D b(0.0f, 1.0f);
        REQUIRE(a.Dot(b) == Catch::Approx(0.0f));
    }
    TEST_CASE("Vector2D Dot with opposite vector returns negative scalar") {
        GameMath::Vector2D a(1.0f, 0.0f);
        GameMath::Vector2D b(-1.0f, 0.0f);
        REQUIRE(a.Dot(b) == Catch::Approx(-1.0f));
    }
    #pragma endregion
    #pragma region .Equals()
    TEST_CASE("Vector2D Equals returns true for exactly equal vectors") {
        GameMath::Vector2D a(1.0f, 2.0f);
        GameMath::Vector2D b(1.0f, 2.0f);
        REQUIRE(a.Equals(b));
    }
    TEST_CASE("Vector2D Equals returns true within default tolerance") {
        GameMath::Vector2D a(1.0f, 2.0f);
        GameMath::Vector2D b(1.00001f, 2.00001f);
        REQUIRE(a.Equals(b)); // using default 0.0001f
    }
    TEST_CASE("Vector2D Equals returns false outside of tolerance") {
        GameMath::Vector2D a(1.0f, 2.0f);
        GameMath::Vector2D b(1.01f, 2.01f);
        REQUIRE_FALSE(a.Equals(b));
    }
    TEST_CASE("Vector2D Equals works with custom tolerance") {
        GameMath::Vector2D a(1.0f, 2.0f);
        GameMath::Vector2D b(1.01f, 2.01f);
        REQUIRE(a.Equals(b, 0.02f));
    }
    #pragma endregion
    #pragma region .Length()
    TEST_CASE("Vector2D Length is correct for Pythagorean triple") {
        GameMath::Vector2D v(3.0f, 4.0f);
        REQUIRE(v.Length() == Catch::Approx(5.0f));
    }
    TEST_CASE("Vector2D Length is zero for zero vector") {
        GameMath::Vector2D v(0.0f, 0.0f);
        REQUIRE(v.Length() == Catch::Approx(0.0f));
    }
    #pragma endregion
    #pragma region .LengthSquared()
    TEST_CASE("Vector2D LengthSquared is correct for known input") {
        GameMath::Vector2D v(3.0f, 4.0f);
        REQUIRE(v.LengthSquared() == Catch::Approx(25.0f));
    }
    TEST_CASE("Vector2D LengthSquared is zero for zero vector") {
        GameMath::Vector2D v(0.0f, 0.0f);
        REQUIRE(v.LengthSquared() == Catch::Approx(0.0f));
    }
    #pragma endregion
    #pragma region .Normalized()
    TEST_CASE("Vector2D Normalized returns unit vector") {
        GameMath::Vector2D v(3.0f, 4.0f);
        GameMath::Vector2D n = v.Normalized();
        REQUIRE(n.Length() == Catch::Approx(1.0f).epsilon(0.0001f));
    }
    TEST_CASE("Vector2D Normalized of zero vector returns zero vector") {
        GameMath::Vector2D v(0.0f, 0.0f);
        GameMath::Vector2D n = v.Normalized();
        REQUIRE(n.x == Catch::Approx(0.0f));
        REQUIRE(n.y == Catch::Approx(0.0f));
    }
    #pragma endregion
    #pragma region .Perpendicular()
    TEST_CASE("Vector2D Perpendicular returns rotated vector 90 degrees counter-clockwise") {
        GameMath::Vector2D v(1.0f, 0.0f);
        GameMath::Vector2D perp = v.Perpendicular();
        REQUIRE(perp.x == Catch::Approx(0.0f));
        REQUIRE(perp.y == Catch::Approx(1.0f));
    }
    #pragma endregion
    #pragma region .IsNearlyZero()
    TEST_CASE("Vector2D IsNearlyZero returns true for very short vector") {
        GameMath::Vector2D v(0.00001f, 0.00001f);
        REQUIRE(v.IsNearlyZero(0.0001f));
    }
    TEST_CASE("Vector2D IsNearlyZero returns false for vector above threshold") {
        GameMath::Vector2D v(0.09f, 0.09f);
        REQUIRE_FALSE(v.IsNearlyZero(0.1f)); // Length = ~0.127
    }
    TEST_CASE("Vector2D IsNearlyZero matches IsZero for exact zero vector") {
        GameMath::Vector2D v(0.0f, 0.0f);
        REQUIRE(v.IsNearlyZero(0.00001f));
        REQUIRE(v.IsZero()); // confirms consistency
    }
    #pragma endregion
    #pragma region .IsZero()
    TEST_CASE("Vector2D IsZero returns true for (0,0)") {
        GameMath::Vector2D v(0.0f, 0.0f);
        REQUIRE(v.IsZero());
    }
    TEST_CASE("Vector2D IsZero returns false for non-zero components") {
        GameMath::Vector2D v(0.0f, 0.1f);
        REQUIRE_FALSE(v.IsZero());
    }
    TEST_CASE("Vector2D IsZero(tolerance) returns true for near-zero vector") {
        GameMath::Vector2D v(0.00001f, -0.00001f);
        REQUIRE(v.IsZero(0.0001f));
    }
    TEST_CASE("Vector2D IsZero(tolerance) returns false for above-threshold values") {
        GameMath::Vector2D v(0.01f, 0.0f);
        REQUIRE_FALSE(v.IsZero(0.0001f));
    }
    TEST_CASE("Vector2D IsZero(tolerance) matches strict IsZero when threshold is 0") {
        GameMath::Vector2D v(0.0f, 0.0f);
        REQUIRE(v.IsZero(0.0f));
        REQUIRE(v.IsZero()); // confirms exact version still works
    }
    #pragma endregion
#pragma endregion