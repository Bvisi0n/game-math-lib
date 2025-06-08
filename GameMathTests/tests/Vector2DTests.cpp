#include "catch_amalgamated.hpp"
#include "GameMath/Vector2D.hpp"

#pragma region Constructor
    TEST_CASE("Vector2D::Vector2D - default values") {
        GameMath::Vector2D v;
        CHECK(v.x == Catch::Approx(0.0f));
        CHECK(v.y == Catch::Approx(0.0f));
    }
    TEST_CASE("Vector2D::Vector2D - parameterized values") {
        GameMath::Vector2D v(3.0f, 4.0f);
        CHECK(v.x == Catch::Approx(3.0f));
        CHECK(v.y == Catch::Approx(4.0f));
    }
#pragma endregion

#pragma region operator+
    TEST_CASE("Vector2D::operator+ - adds components") {
        GameMath::Vector2D a(2.0f, 3.0f);
        GameMath::Vector2D b(4.0f, 5.0f);
        GameMath::Vector2D result = a + b;
        CHECK(result.x == Catch::Approx(6.0f));
        CHECK(result.y == Catch::Approx(8.0f));
    }
#pragma endregion

#pragma region operator-
    TEST_CASE("Vector2D::operator- - subtracts components") {
        GameMath::Vector2D a(5.0f, 3.0f);
        GameMath::Vector2D b(2.0f, 1.0f);
        GameMath::Vector2D result = a - b;
        CHECK(result.x == Catch::Approx(3.0f));
        CHECK(result.y == Catch::Approx(2.0f));
    }
#pragma endregion

#pragma region operator*
    TEST_CASE("Vector2D::operator* - scales components") {
        GameMath::Vector2D v(1.5f, -2.0f);
        GameMath::Vector2D result = v * 2.0f;
        CHECK(result.x == Catch::Approx(3.0f));
        CHECK(result.y == Catch::Approx(-4.0f));
    }
#pragma endregion

#pragma region operator/
    TEST_CASE("Vector2D::operator/ - divides by scalar") {
        GameMath::Vector2D v(8.0f, 4.0f);
        GameMath::Vector2D result = v / 2.0f;
        CHECK(result.x == Catch::Approx(4.0f));
        CHECK(result.y == Catch::Approx(2.0f));
    }
    TEST_CASE("Vector2D::operator/ - zero scalar returns zero vector") {
        GameMath::Vector2D v(5.0f, -3.0f);
        GameMath::Vector2D result = v / 0.0f;
        CHECK(result.x == Catch::Approx(0.0f));
        CHECK(result.y == Catch::Approx(0.0f));
    }
    TEST_CASE("Vector2D::operator/ - divide by negative scalar") {
        GameMath::Vector2D v(4.0f, -8.0f);
        GameMath::Vector2D result = v / -2.0f;
        CHECK(result.x == Catch::Approx(-2.0f));
        CHECK(result.y == Catch::Approx(4.0f));
    }
#pragma endregion

#pragma region operator==
    TEST_CASE("Vector2D::operator== - exact match") {
        GameMath::Vector2D a(1.0f, 2.0f);
        GameMath::Vector2D b(1.0f, 2.0f);
        CHECK(a == b);
    }
    TEST_CASE("Vector2D::operator== - different component") {
        GameMath::Vector2D a(1.0f, 2.0f);
        GameMath::Vector2D c(1.0f, 2.0001f);
        CHECK_FALSE(a == c);
    }
#pragma endregion

#pragma region operator!=
    TEST_CASE("Vector2D::operator!= - different components") {
        GameMath::Vector2D a(1.0f, 2.0f);
        GameMath::Vector2D b(1.0f, 3.0f);
        CHECK(a != b);
    }
    TEST_CASE("Vector2D::operator!= - equal components") {
        GameMath::Vector2D a(1.0f, 2.0f);
        GameMath::Vector2D b(1.0f, 2.0f);
        CHECK_FALSE(a != b);
    }
#pragma endregion

#pragma region ClampLength
    // TODO: Uncomment when implementing Vector2D::ClampLength
    //TEST_CASE("Vector2D::ClampLength - within range remains unchanged") {
    //    GameMath::Vector2D v(3.0f, 4.0f); // length = 5
    //    v.ClampLength(2.0f, 6.0f);
    //    CHECK(v.Length() == Catch::Approx(5.0f));
    //}
    //TEST_CASE("Vector2D::ClampLength - clamps above max") {
    //    GameMath::Vector2D v(6.0f, 8.0f); // length = 10
    //    v.ClampLength(0.0f, 5.0f);
    //    CHECK(v.Length() == Catch::Approx(5.0f));
    //}
    //TEST_CASE("Vector2D::ClampLength - clamps below min") {
    //    GameMath::Vector2D v(0.3f, 0.4f); // length = 0.5
    //    v.ClampLength(1.0f, 10.0f);
    //    CHECK(v.Length() == Catch::Approx(1.0f));
    //}
    //TEST_CASE("Vector2D::ClampLength - zero vector stays zero") {
    //    GameMath::Vector2D v(0.0f, 0.0f);
    //    v.ClampLength(1.0f, 5.0f);
    //    CHECK(v.IsZero());
    //}
#pragma endregion

#pragma region DistanceTo
// TODO: Uncomment when implementing Vector2D::DistanceTo
//TEST_CASE("Vector2D::DistanceTo - standard case") {
//    GameMath::Vector2D a(0.0f, 0.0f);
//    GameMath::Vector2D b(3.0f, 4.0f);
//    CHECK(a.DistanceTo(b) == Catch::Approx(5.0f));
//}
//TEST_CASE("Vector2D::DistanceTo - reverse order yields same result") {
//    GameMath::Vector2D a(3.0f, 4.0f);
//    GameMath::Vector2D b(0.0f, 0.0f);
//    CHECK(a.DistanceTo(b) == Catch::Approx(5.0f));
//}
//TEST_CASE("Vector2D::DistanceTo - same point yields zero") {
//    GameMath::Vector2D a(1.0f, 1.0f);
//    CHECK(a.DistanceTo(a) == Catch::Approx(0.0f));
//}
//TEST_CASE("Vector2D::DistanceTo - diagonally aligned points") {
//    GameMath::Vector2D a(2.0f, 3.0f);
//    GameMath::Vector2D b(5.0f, 7.0f);
//    CHECK(a.DistanceTo(b) == Catch::Approx(5.0f));
//}
#pragma endregion

#pragma region Dot
    TEST_CASE("Vector2D::Dot - parallel vector") {
        GameMath::Vector2D a(1.0f, 2.0f);
        GameMath::Vector2D b(2.0f, 4.0f);
        CHECK(a.Dot(b) == Catch::Approx(10.0f));
    }
    TEST_CASE("Vector2D::Dot - perpendicular vector") {
        GameMath::Vector2D a(1.0f, 0.0f);
        GameMath::Vector2D b(0.0f, 1.0f);
        CHECK(a.Dot(b) == Catch::Approx(0.0f));
    }
    TEST_CASE("Vector2D::Dot - opposite vector") {
        GameMath::Vector2D a(1.0f, 0.0f);
        GameMath::Vector2D b(-1.0f, 0.0f);
        CHECK(a.Dot(b) == Catch::Approx(-1.0f));
    }
    TEST_CASE("Vector2D::Dot - nearly orthogonal vectors") {
        GameMath::Vector2D a(1.0f, 0.0f);
        GameMath::Vector2D b(1e-7f, 1.0f);
        CHECK(a.Dot(b) == Catch::Approx(1e-7f).epsilon(0.01f));
    }
#pragma endregion

#pragma region Equals
    TEST_CASE("Vector2D::Equals - exactly equal vectors") {
        GameMath::Vector2D a(1.0f, 2.0f);
        GameMath::Vector2D b(1.0f, 2.0f);
        CHECK(a.Equals(b));
    }
    TEST_CASE("Vector2D::Equals - within default tolerance") {
        GameMath::Vector2D a(1.0f, 2.0f);
        GameMath::Vector2D b(1.00001f, 2.00001f);
        CHECK(a.Equals(b));
    }
    TEST_CASE("Vector2D::Equals - outside tolerance") {
        GameMath::Vector2D a(1.0f, 2.0f);
        GameMath::Vector2D b(1.01f, 2.01f);
        CHECK_FALSE(a.Equals(b));
    }
    TEST_CASE("Vector2D::Equals - custom tolerance") {
        GameMath::Vector2D a(1.0f, 2.0f);
        GameMath::Vector2D b(1.01f, 2.01f);
        CHECK(a.Equals(b, 0.02f));
    }
    TEST_CASE("Vector2D::Equals - comparison with NaN components") {
        GameMath::Vector2D a(std::numeric_limits<float>::quiet_NaN(), 1.0f);
        GameMath::Vector2D b(0.0f, std::numeric_limits<float>::quiet_NaN());
        CHECK_FALSE(a.Equals(b));
        CHECK_FALSE(a.Equals(a));
    }
#pragma endregion

#pragma region IsNearlyZero
    TEST_CASE("Vector2D::IsNearlyZero - very short vector") {
        GameMath::Vector2D v(0.00001f, 0.00001f);
        CHECK(v.IsNearlyZero(0.0001f));
    }
    TEST_CASE("Vector2D::IsNearlyZero - above threshold") {
        GameMath::Vector2D v(0.09f, 0.09f);
        CHECK_FALSE(v.IsNearlyZero(0.1f));
    }
    TEST_CASE("Vector2D::IsNearlyZero - exact zero vector") {
        GameMath::Vector2D v(0.0f, 0.0f);
        CHECK(v.IsNearlyZero(0.00001f));
        CHECK(v.IsZero());
    }
#pragma endregion

#pragma region IsZero
    TEST_CASE("Vector2D::IsZero - exact zero") {
        GameMath::Vector2D v(0.0f, 0.0f);
        CHECK(v.IsZero());
    }
    TEST_CASE("Vector2D::IsZero - non-zero components") {
        GameMath::Vector2D v(0.0f, 0.1f);
        CHECK_FALSE(v.IsZero());
    }
    TEST_CASE("Vector2D::IsZero - near zero vector") {
        GameMath::Vector2D v(0.00001f, -0.00001f);
        CHECK(v.IsZero(0.0001f));
    }
    TEST_CASE("Vector2D::IsZero - above threshold") {
        GameMath::Vector2D v(0.01f, 0.0f);
        CHECK_FALSE(v.IsZero(0.0001f));
    }
    TEST_CASE("Vector2D::IsZero - matches strict when tolerance is 0") {
        GameMath::Vector2D v(0.0f, 0.0f);
        CHECK(v.IsZero(0.0f));
        CHECK(v.IsZero());
    }
    TEST_CASE("Vector2D::IsZero - tolerance boundary inclusive") {
        GameMath::Vector2D v(0.1f, 0.0f);
        CHECK(v.IsZero(0.1f));          // on boundary
        CHECK_FALSE(v.IsZero(0.0999f)); // just below
        CHECK(v.IsZero(0.1001f));       // just above
    }
#pragma endregion

#pragma region Length
    TEST_CASE("Vector2D::Length - Pythagorean triple") {
        GameMath::Vector2D v(3.0f, 4.0f);
        CHECK(v.Length() == Catch::Approx(5.0f));
    }
    TEST_CASE("Vector2D::Length - zero vector") {
        GameMath::Vector2D v(0.0f, 0.0f);
        CHECK(v.Length() == Catch::Approx(0.0f));
    }
#pragma endregion

#pragma region LengthSquared
    TEST_CASE("Vector2D::LengthSquared - known input") {
        GameMath::Vector2D v(3.0f, 4.0f);
        CHECK(v.LengthSquared() == Catch::Approx(25.0f));
    }
    TEST_CASE("Vector2D::LengthSquared - zero vector") {
        GameMath::Vector2D v(0.0f, 0.0f);
        CHECK(v.LengthSquared() == Catch::Approx(0.0f));
    }
#pragma endregion

#pragma region Normalize
    TEST_CASE("Vector2D::Normalize - standard case") {
        GameMath::Vector2D v{ 3.0f, 4.0f };
        v.Normalize();
        CHECK(v.Equals(GameMath::Vector2D{ 0.6f, 0.8f }));
    }
    TEST_CASE("Vector2D::Normalize - zero vector fallback") {
        GameMath::Vector2D v{ 0.0f, 0.0f };
        v.Normalize();
        CHECK(v.Equals(GameMath::Vector2D{ 0.0f, 0.0f }));
    }
    TEST_CASE("Vector2D::Normalize - already normalized") {
        GameMath::Vector2D v{ 1.0f, 0.0f };
        v.Normalize();
        CHECK(v.Equals(GameMath::Vector2D{ 1.0f, 0.0f }));
    }
    TEST_CASE("Vector2D::Normalize - negative direction") {
        GameMath::Vector2D v{ -5.0f, 0.0f };
        v.Normalize();
        CHECK(v.Equals(GameMath::Vector2D{ -1.0f, 0.0f }));
    }
    TEST_CASE("Vector2D::Normalize - very small vector") {
        GameMath::Vector2D v(1e-8f, -1e-8f);
        v.Normalize();
        float length = v.Length();
        CHECK(length == Catch::Approx(1.0f).epsilon(0.001f)); // Allow slight epsilon
    }
#pragma endregion

#pragma region Normalized
    TEST_CASE("Vector2D::Normalized - unit vector") {
        GameMath::Vector2D v(3.0f, 4.0f);
        GameMath::Vector2D n = v.Normalized();
        CHECK(n.Length() == Catch::Approx(1.0f).epsilon(0.0001f));
    }
    TEST_CASE("Vector2D::Normalized - zero vector") {
        GameMath::Vector2D v(0.0f, 0.0f);
        GameMath::Vector2D n = v.Normalized();
        CHECK(n.x == Catch::Approx(0.0f));
        CHECK(n.y == Catch::Approx(0.0f));
    }
#pragma endregion

#pragma region Perpendicular
    TEST_CASE("Vector2D::Perpendicular - rotates 90 degrees") {
        GameMath::Vector2D v(1.0f, 0.0f);
        GameMath::Vector2D perp = v.Perpendicular();
        CHECK(perp.x == Catch::Approx(0.0f));
        CHECK(perp.y == Catch::Approx(1.0f));
    }
    TEST_CASE("Vector2D::Perpendicular - zero vector") {
        GameMath::Vector2D v(0.0f, 0.0f);
        GameMath::Vector2D perp = v.Perpendicular();
        CHECK(perp.x == Catch::Approx(0.0f));
        CHECK(perp.y == Catch::Approx(0.0f));
    }
#pragma endregion

#pragma region SnapToGrid
    // TODO: Uncomment when implementing Vector2D::SnapToGrid
    //TEST_CASE("Vector2D::SnapToGrid - snaps positive values") {
    //    GameMath::Vector2D v(3.6f, 7.2f);
    //    v.SnapToGrid(1.0f);
    //    CHECK(v.Equals(GameMath::Vector2D(4.0f, 7.0f)));
    //}
    //TEST_CASE("Vector2D::SnapToGrid - snaps negative values") {
    //    GameMath::Vector2D v(-2.7f, -5.1f);
    //    v.SnapToGrid(1.0f);
    //    CHECK(v.Equals(GameMath::Vector2D(-3.0f, -5.0f)));
    //}
    //TEST_CASE("Vector2D::SnapToGrid - works with fractional cell size") {
    //    GameMath::Vector2D v(1.24f, 3.76f);
    //    v.SnapToGrid(0.5f);
    //    CHECK(v.Equals(GameMath::Vector2D(1.0f, 4.0f)));
    //}
    //TEST_CASE("Vector2D::SnapToGrid - zero cell size leaves vector unchanged") {
    //    GameMath::Vector2D v(3.1f, 5.9f);
    //    v.SnapToGrid(0.0f);
    //    CHECK(v.Equals(GameMath::Vector2D(3.1f, 5.9f)));
    //}
#pragma endregion

#pragma region Truncate
    // TODO: Uncomment when implementing Vector2D::Truncate
    //TEST_CASE("Vector2D::Truncate - vector longer than max gets shortened") {
    //    GameMath::Vector2D v(6.0f, 8.0f); // length = 10
    //    v.Truncate(5.0f);
    //    CHECK(v.Length() == Catch::Approx(5.0f));
    //}
    //TEST_CASE("Vector2D::Truncate - vector shorter than max remains unchanged") {
    //    GameMath::Vector2D v(3.0f, 4.0f); // length = 5
    //    v.Truncate(10.0f);
    //    CHECK(v.Length() == Catch::Approx(5.0f));
    //}
    //TEST_CASE("Vector2D::Truncate - zero vector remains zero") {
    //    GameMath::Vector2D v(0.0f, 0.0f);
    //    v.Truncate(5.0f);
    //    CHECK(v.IsZero());
    //}
    //TEST_CASE("Vector2D::Truncate - negative max value treated as zero") {
    //    GameMath::Vector2D v(3.0f, 4.0f); // length = 5
    //    v.Truncate(-1.0f);
    //    CHECK(v.IsZero());
    //}
#pragma endregion