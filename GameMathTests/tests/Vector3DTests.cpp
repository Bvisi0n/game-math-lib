#include "catch_amalgamated.hpp"
#include "GameMath/Vector3D.hpp"

#pragma region Constructor
    TEST_CASE("Vector3D::Vector3D - default values") {
        GameMath::Vector3D v;
        CHECK(v.x == Catch::Approx(0.0f));
        CHECK(v.y == Catch::Approx(0.0f));
        CHECK(v.z == Catch::Approx(0.0f));
    }
    TEST_CASE("Vector3D::Vector3D - parameterized values") {
        GameMath::Vector3D v(3.0f, 4.0f, 5.0f);
        CHECK(v.x == Catch::Approx(3.0f));
        CHECK(v.y == Catch::Approx(4.0f));
        CHECK(v.z == Catch::Approx(5.0f));
    }
#pragma endregion

#pragma region Length
    TEST_CASE("Vector3D::Length - zero vector") {
        GameMath::Vector3D v{ 0.0f, 0.0f, 0.0f };
        CHECK(v.Length() == Catch::Approx(0.0f));
    }
    TEST_CASE("Vector3D::Length - unit x") {
        GameMath::Vector3D v{ 1.0f, 0.0f, 0.0f };
        CHECK(v.Length() == Catch::Approx(1.0f));
    }
    TEST_CASE("Vector3D::Length - unit y") {
        GameMath::Vector3D v{ 0.0f, 1.0f, 0.0f };
        CHECK(v.Length() == Catch::Approx(1.0f));
    }
    TEST_CASE("Vector3D::Length - unit z") {
        GameMath::Vector3D v{ 0.0f, 0.0f, 1.0f };
        CHECK(v.Length() == Catch::Approx(1.0f));
    }
    TEST_CASE("Vector3D::Length - positive values") {
        GameMath::Vector3D v{ 3.0f, 4.0f, 12.0f };
        CHECK(v.Length() == Catch::Approx(13.0f));
    }
    TEST_CASE("Vector3D::Length - negative values") {
        GameMath::Vector3D v{ -3.0f, -4.0f, -12.0f };
        CHECK(v.Length() == Catch::Approx(13.0f));
    }
#pragma endregion

#pragma region LengthSquared
    TEST_CASE("Vector3D::LengthSquared - zero vector") {
        GameMath::Vector3D v{ 0.0f, 0.0f, 0.0f };
        CHECK(v.LengthSquared() == Catch::Approx(0.0f));
    }
    TEST_CASE("Vector3D::LengthSquared - unit x") {
        GameMath::Vector3D v{ 1.0f, 0.0f, 0.0f };
        CHECK(v.LengthSquared() == Catch::Approx(1.0f));
    }
    TEST_CASE("Vector3D::LengthSquared - general case") {
        GameMath::Vector3D v{ 3.0f, 4.0f, 12.0f };
        CHECK(v.LengthSquared() == Catch::Approx(169.0f));
    }
    TEST_CASE("Vector3D::LengthSquared - negative values") {
        GameMath::Vector3D v{ -3.0f, -4.0f, -12.0f };
        CHECK(v.LengthSquared() == Catch::Approx(169.0f));
    }
#pragma endregion
