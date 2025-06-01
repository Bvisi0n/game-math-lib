#include "GameMath/Vector2D.hpp"
#include <cmath>

namespace GameMath {

    Vector2D::Vector2D(float x, float y)
        : x(x), y(y)
    {}

    float Vector2D::Dot(const Vector2D& other) const
    {
		return (x * other.x) + (y * other.y);
    }

    float Vector2D::Length() const
    {
        return std::sqrt((x*x)+(y*y));
    }

    Vector2D Vector2D::Normalized() const
    {
		float length = Length();
        if (length == 0.0f) {
            return Vector2D(0.0f, 0.0f);
		}
		return Vector2D(x / length, y / length);
    }
}