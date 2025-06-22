#include "GameMath/Vector2D.hpp"
#include <algorithm>
#include <cmath>
#include <cassert>

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

    Vector2D Vector2D::operator/(const float scalar) const
    {
		return (scalar != 0.0f) ? Vector2D(x / scalar, y / scalar) : Vector2D(0.0f, 0.0f);
    }

    bool Vector2D::operator==(const Vector2D& other) const
    {
		return (x == other.x && y == other.y);
    }

    bool Vector2D::operator!=(const Vector2D& other) const
    {
        return (x != other.x || y != other.y);
    }

    void Vector2D::ClampComponents(float minX, float maxX, float minY, float maxY)
    {
        assert(minX <= maxX && "ClampComponents: minX must be <= maxX");
        assert(minY <= maxY && "ClampComponents: minY must be <= maxY");
        x = std::clamp(x, minX, maxX);
        y = std::clamp(y, minY, maxY);
    }

    void Vector2D::ClampLength(float minLength, float maxLength)
    {
        assert(minLength <= maxLength && "ClampLength: minLength must be <= maxLength");
        float lenSq = LengthSquared();
        if (lenSq == 0.0f)
            return; // Do not modify zero vector
        float minSq = minLength * minLength;
        float maxSq = maxLength * maxLength;
        if (lenSq < minSq) {
            float scale = minLength / std::sqrt(lenSq);
            x *= scale;
            y *= scale;
        }
        else if (lenSq > maxSq) {
            float scale = maxLength / std::sqrt(lenSq);
            x *= scale;
            y *= scale;
        }
    }

    float Vector2D::Dot(const Vector2D& other) const
    {
		return (x * other.x) + (y * other.y);
    }

    bool Vector2D::Equals(const Vector2D& other, float tolerance) const
    {
		return (std::abs(x - other.x) <= tolerance && std::abs(y - other.y) <= tolerance);
    }

    float Vector2D::Length() const
    {
        return std::sqrt(LengthSquared());
    }

    float Vector2D::LengthSquared() const
    {
		return (x * x) + (y * y);
    }

    void Vector2D::Normalize()
    {
        float length = Length();
        if (length > 0.0f) {
            x /= length;
            y /= length;
        } else {
            x = 0.0f;
            y = 0.0f;
		}
    }

    Vector2D Vector2D::Normalized() const
    {
		float length = Length();
        if (length == 0.0f) {
            return Vector2D(0.0f, 0.0f);
		}
		return Vector2D(x / length, y / length);
    }

    Vector2D Vector2D::Perpendicular() const
    {
		return Vector2D(-y, x);
    }

    bool Vector2D::IsNearlyZero(float tolerance) const
    {
        return LengthSquared() < tolerance * tolerance;
    }

    bool Vector2D::IsZero(float tolerance) const
    {
        return (std::abs(x) <= tolerance && std::abs(y) <= tolerance);
	}

    void Vector2D::Truncate(float maxLength)
    {
        if (maxLength <= 0.0f || IsZero()) {
            x = 0.0f;
            y = 0.0f;
            return;
        }
        float lenSq = LengthSquared();
        float maxSq = maxLength * maxLength;
        if (lenSq > maxSq) {
            float scale = maxLength / std::sqrt(lenSq);
            x *= scale;
            y *= scale;
        }
    }
}