#include "catch_amalgamated.hpp"
#include "Matrix2D.hpp"

#pragma region Constructor
    TEST_CASE("Matrix2D – Default constructor produces identity matrix", "[Matrix2D]") {
        GameSystems::Math::Matrix2D m;

        REQUIRE(m.matrix[0][0] == Catch::Approx(1.0f));
        REQUIRE(m.matrix[0][1] == Catch::Approx(0.0f));
        REQUIRE(m.matrix[0][2] == Catch::Approx(0.0f));

        REQUIRE(m.matrix[1][0] == Catch::Approx(0.0f));
        REQUIRE(m.matrix[1][1] == Catch::Approx(1.0f));
        REQUIRE(m.matrix[1][2] == Catch::Approx(0.0f));

        REQUIRE(m.matrix[2][0] == Catch::Approx(0.0f));
        REQUIRE(m.matrix[2][1] == Catch::Approx(0.0f));
        REQUIRE(m.matrix[2][2] == Catch::Approx(1.0f));
    }
    TEST_CASE("Matrix2D – Constructor with identity = true also produces identity matrix", "[Matrix2D]") {
        GameSystems::Math::Matrix2D m(true);

        REQUIRE(m.matrix[0][0] == Catch::Approx(1.0f));
        REQUIRE(m.matrix[0][1] == Catch::Approx(0.0f));
        REQUIRE(m.matrix[0][2] == Catch::Approx(0.0f));

        REQUIRE(m.matrix[1][0] == Catch::Approx(0.0f));
        REQUIRE(m.matrix[1][1] == Catch::Approx(1.0f));
        REQUIRE(m.matrix[1][2] == Catch::Approx(0.0f));

        REQUIRE(m.matrix[2][0] == Catch::Approx(0.0f));
        REQUIRE(m.matrix[2][1] == Catch::Approx(0.0f));
        REQUIRE(m.matrix[2][2] == Catch::Approx(1.0f));
    }
    TEST_CASE("Matrix2D – Constructor with identity = false produces zero matrix", "[Matrix2D]") {
        GameSystems::Math::Matrix2D m(false);

        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                REQUIRE(m.matrix[row][col] == Catch::Approx(0.0f));
            }
        }
    }
    TEST_CASE("Matrix2D – Class compiles and is usable", "[Matrix2D]") {
        GameSystems::Math::Matrix2D m;
        (void)m; // just to ensure it compiles
    }
#pragma endregion
