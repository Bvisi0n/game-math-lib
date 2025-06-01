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
    #pragma region GameMath::Vector2D.Length()
    TEST_CASE("Vector2D Length is correct for Pythagorean triple") {
        GameMath::Vector2D v(3.0f, 4.0f);
        REQUIRE(v.Length() == Catch::Approx(5.0f));
    }
    TEST_CASE("Vector2D Length is zero for zero vector") {
        GameMath::Vector2D v(0.0f, 0.0f);
        REQUIRE(v.Length() == Catch::Approx(0.0f));
    }
    #pragma endregion
#pragma endregion