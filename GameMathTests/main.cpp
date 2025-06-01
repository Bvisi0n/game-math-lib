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
    #pragma region .operator+
    TEST_CASE("Vector2D operator+ adds components") {
        GameMath::Vector2D a(2.0f, 3.0f);
        GameMath::Vector2D b(4.0f, 5.0f);
        GameMath::Vector2D result = a + b;
        REQUIRE(result.x == Catch::Approx(6.0f));
        REQUIRE(result.y == Catch::Approx(8.0f));
    }
    #pragma endregion
    #pragma region .operator*
    TEST_CASE("Vector2D operator* scales both components") {
        GameMath::Vector2D v(1.5f, -2.0f);
        GameMath::Vector2D result = v * 2.0f;
        REQUIRE(result.x == Catch::Approx(3.0f));
        REQUIRE(result.y == Catch::Approx(-4.0f));
    }
    #pragma endregion
    #pragma region .operator==
    TEST_CASE("Vector2D operator== compares components with exact match") {
        GameMath::Vector2D a(1.0f, 2.0f);
        GameMath::Vector2D b(1.0f, 2.0f);
        GameMath::Vector2D c(1.0f, 2.0001f);
        REQUIRE(a == b);
        REQUIRE_FALSE(a == c);
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
#pragma endregion