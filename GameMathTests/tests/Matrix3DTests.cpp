#include "catch_amalgamated.hpp"
#include "GameMath/Matrix3D.hpp"

#pragma region Constructor
    TEST_CASE("Matrix3D – Default constructor produces identity matrix", "[Matrix3D]") {
        GameMath::Matrix3D m;

        REQUIRE(m.matrix[0][0] == Catch::Approx(1.0f));
        REQUIRE(m.matrix[0][1] == Catch::Approx(0.0f));
        REQUIRE(m.matrix[0][2] == Catch::Approx(0.0f));
        REQUIRE(m.matrix[0][3] == Catch::Approx(0.0f));

        REQUIRE(m.matrix[1][0] == Catch::Approx(0.0f));
        REQUIRE(m.matrix[1][1] == Catch::Approx(1.0f));
        REQUIRE(m.matrix[1][2] == Catch::Approx(0.0f));
        REQUIRE(m.matrix[1][3] == Catch::Approx(0.0f));

        REQUIRE(m.matrix[2][0] == Catch::Approx(0.0f));
        REQUIRE(m.matrix[2][1] == Catch::Approx(0.0f));
        REQUIRE(m.matrix[2][2] == Catch::Approx(1.0f));
        REQUIRE(m.matrix[2][3] == Catch::Approx(0.0f));

        REQUIRE(m.matrix[3][0] == Catch::Approx(0.0f));
        REQUIRE(m.matrix[3][1] == Catch::Approx(0.0f));
        REQUIRE(m.matrix[3][2] == Catch::Approx(0.0f));
        REQUIRE(m.matrix[3][3] == Catch::Approx(1.0f));
    }
    TEST_CASE("Matrix3D – Constructor with identity = true also produces identity matrix", "[Matrix3D]") {
        GameMath::Matrix3D m(true);

        for (int row = 0; row < 4; ++row) {
            for (int col = 0; col < 4; ++col) {
                float expected = (row == col) ? 1.0f : 0.0f;
                REQUIRE(m.matrix[row][col] == Catch::Approx(expected));
            }
        }
    }
    TEST_CASE("Matrix3D – Constructor with identity = false produces zero matrix", "[Matrix3D]") {
        GameMath::Matrix3D m(false);

        for (int row = 0; row < 4; ++row) {
            for (int col = 0; col < 4; ++col) {
                REQUIRE(m.matrix[row][col] == Catch::Approx(0.0f));
            }
        }
    }
    TEST_CASE("Matrix3D – Class compiles and is usable", "[Matrix3D]") {
        GameMath::Matrix3D m;
        (void)m; // dummy usage to prevent unused variable warning
    }
#pragma endregion