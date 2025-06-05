#include "GameMath/Vector2D.hpp"
#include <cmath>

namespace GameMath {
    Vector2D::Vector2D(float x, float y)
        : x(x), y(y)
    {}

    Vector2D Vector2D::operator+(const Vector2D & other) const
    {
		return Vector2D(x + other.x, y + other.y);
    }

    Vector2D Vector2D::operator-(const Vector2D& other) const
    {
		return Vector2D(x - other.x, y - other.y);
    }

    Vector2D Vector2D::operator*(const float scalar) const
    {
		return Vector2D(x * scalar, y * scalar);
    }

    bool Vector2D::operator==(const Vector2D& other) const
    {
		return (x == other.x && y == other.y);
    }

    bool Vector2D::operator!=(const Vector2D& other) const
    {
        return (x != other.x || y != other.y);
    }

    float Vector2D::Dot(const Vector2D& other) const
    {
		return (x * other.x) + (y * other.y);
    }

    float Vector2D::Length() const
    {
        return std::sqrt(LengthSquared());
    }

    float Vector2D::LengthSquared() const
    {
		return (x * x) + (y * y);
    }

    Vector2D Vector2D::Normalized() const
    {
		float length = Length();
        if (length == 0.0f) {
            return Vector2D(0.0f, 0.0f);
		}
		return Vector2D(x / length, y / length);
    }

    bool Vector2D::IsNearlyZero(float tolerance) const
    {
        return LengthSquared() < tolerance * tolerance;
    }

    bool Vector2D::IsZero(float tolerance) const
    {
        return (std::abs(x) <= tolerance && std::abs(y) <= tolerance);
	}
}