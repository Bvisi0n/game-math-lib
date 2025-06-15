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