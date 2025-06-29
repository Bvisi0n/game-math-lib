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

#pragma region Cross
TEST_CASE("Vector3D::Cross - orthogonal basis X × Y = Z") {
    GameMath::Vector3D x{ 1.0f, 0.0f, 0.0f };
    GameMath::Vector3D y{ 0.0f, 1.0f, 0.0f };
    GameMath::Vector3D expected{ 0.0f, 0.0f, 1.0f };
    CHECK(x.Cross(y).Equals(expected));
}
TEST_CASE("Vector3D::Cross - reversed operands Y × X = -Z") {
    GameMath::Vector3D y{ 0.0f, 1.0f, 0.0f };
    GameMath::Vector3D x{ 1.0f, 0.0f, 0.0f };
    GameMath::Vector3D expected{ 0.0f, 0.0f, -1.0f };
    CHECK(y.Cross(x).Equals(expected));
}
TEST_CASE("Vector3D::Cross - parallel vectors result in zero vector") {
    GameMath::Vector3D a{ 2.0f, 2.0f, 2.0f };
    GameMath::Vector3D b{ 4.0f, 4.0f, 4.0f }; // same direction
    CHECK(a.Cross(b).Equals(GameMath::Vector3D{ 0.0f, 0.0f, 0.0f }));
}
TEST_CASE("Vector3D::Cross - zero vector as input") {
    GameMath::Vector3D a{ 0.0f, 0.0f, 0.0f };
    GameMath::Vector3D b{ 1.0f, 2.0f, 3.0f };
    CHECK(a.Cross(b).Equals(GameMath::Vector3D{ 0.0f, 0.0f, 0.0f }));
}
TEST_CASE("Vector3D::Cross - general case") {
    GameMath::Vector3D a{ 1.0f, 2.0f, 3.0f };
    GameMath::Vector3D b{ 4.0f, 5.0f, 6.0f };
    GameMath::Vector3D expected{ -3.0f, 6.0f, -3.0f };
    CHECK(a.Cross(b).Equals(expected));
}
#pragma endregion

#pragma region Equals
TEST_CASE("GameMath::Vector3D::Equals - identical vectors") {
    GameMath::Vector3D v{ 1.0f, 2.0f, 3.0f };
    GameMath::Vector3D other{ 1.0f, 2.0f, 3.0f };
    CHECK(v.Equals(other));
}
TEST_CASE("GameMath::Vector3D::Equals - within tolerance") {
    GameMath::Vector3D v{ 1.00001f, 2.00001f, 3.00001f };
    GameMath::Vector3D other{ 1.00002f, 2.00002f, 3.00002f };
    CHECK(v.Equals(other));
}
TEST_CASE("GameMath::Vector3D::Equals - outside tolerance on x") {
    GameMath::Vector3D v{ 1.0f, 2.0f, 3.0f };
    GameMath::Vector3D other{ 1.001f, 2.0f, 3.0f };
    CHECK_FALSE(v.Equals(other));
}
TEST_CASE("GameMath::Vector3D::Equals - outside tolerance on y") {
    GameMath::Vector3D v{ 1.0f, 2.0f, 3.0f };
    GameMath::Vector3D other{ 1.0f, 2.001f, 3.0f };
    CHECK_FALSE(v.Equals(other));
}
TEST_CASE("GameMath::Vector3D::Equals - outside tolerance on z") {
    GameMath::Vector3D v{ 1.0f, 2.0f, 3.0f };
    GameMath::Vector3D other{ 1.0f, 2.0f, 3.001f };
    CHECK_FALSE(v.Equals(other));
}
TEST_CASE("GameMath::Vector3D::Equals - negative vs positive zero") {
    GameMath::Vector3D v{ -0.0f, 0.0f, -0.0f };
    GameMath::Vector3D other{ 0.0f, 0.0f, 0.0f };
    CHECK(v.Equals(other));
}
TEST_CASE("GameMath::Vector3D::Equals - custom tolerance") {
    GameMath::Vector3D v{ 1.0f, 2.0f, 3.0f };
    GameMath::Vector3D other{ 1.01f, 2.01f, 3.01f };
    CHECK(v.Equals(other, 0.02f));
}
TEST_CASE("GameMath::Vector3D::Equals - comparison with NaN components") {
    GameMath::Vector3D a{ std::numeric_limits<float>::quiet_NaN(), 1.0f, 2.0f };
    GameMath::Vector3D b{ 0.0f, 1.0f, std::numeric_limits<float>::quiet_NaN() };
    CHECK_FALSE(a.Equals(b));
    CHECK_FALSE(a.Equals(a));
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

#pragma region IsNearlyZero
TEST_CASE("Vector3D::IsNearlyZero - exact zero vector") {
    GameMath::Vector3D v(0.0f, 0.0f, 0.0f);
    CHECK(v.IsNearlyZero(0.00001f));
}
TEST_CASE("Vector3D::IsNearlyZero - very short vector") {
    GameMath::Vector3D v(0.0001f, 0.0001f, 0.0001f);
    CHECK(v.IsNearlyZero(0.001f));
}
TEST_CASE("Vector3D::IsNearlyZero - above threshold") {
    GameMath::Vector3D v(0.05f, 0.05f, 0.05f);
    CHECK_FALSE(v.IsNearlyZero(0.01f));
}
#pragma endregion

#pragma region IsZero
TEST_CASE("Vector3D::IsZero - exact zero") {
    GameMath::Vector3D v(0.0f, 0.0f, 0.0f);
    CHECK(v.IsZero());
}
TEST_CASE("Vector3D::IsZero - non-zero components") {
    GameMath::Vector3D v(0.1f, 0.0f, 0.0f);
    CHECK_FALSE(v.IsZero());
}
TEST_CASE("Vector3D::IsZero - near zero vector") {
    GameMath::Vector3D v(0.05f, 0.05f, 0.05f);
    CHECK(v.IsZero(0.1f));
}
TEST_CASE("Vector3D::IsZero - above threshold") {
    GameMath::Vector3D v(0.1f, 0.1f, 0.1f);
    CHECK_FALSE(v.IsZero(0.1f));
}
TEST_CASE("Vector3D::IsZero - matches strict when tolerance is 0") {
    GameMath::Vector3D v(0.0f, 0.0f, 0.0f);
    CHECK(v.IsZero(0.0f));
}
TEST_CASE("Vector3D::IsZero - tolerance boundary inclusive") {
    GameMath::Vector3D v(0.0577f, 0.0577f, 0.0577f); // ≈ 0.1f length
    CHECK(v.IsZero(0.1f));          // on boundary
    CHECK_FALSE(v.IsZero(0.0999f)); // just below
    CHECK(v.IsZero(0.1001f));       // just above
}
#pragma endregion
