#include "GameMath/Vector3D.hpp"
#include <cmath>

namespace GameMath {
    Vector3D::Vector3D(float x, float y, float z)
        : x(x), y(y), z(z)
    {
    }

    Vector3D Vector3D::Cross(const Vector3D& other) const
    {
        return Vector3D(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    bool Vector3D::Equals(const Vector3D& other, float tolerance) const {
        return (std::abs(x - other.x) <= tolerance &&
            std::abs(y - other.y) <= tolerance &&
            std::abs(z - other.z) <= tolerance);
    }

    float Vector3D::Length() const {
        return std::sqrt(LengthSquared());
    }

    float Vector3D::LengthSquared() const {
        return x * x + y * y + z * z;
    }

    bool Vector3D::IsNearlyZero(float tolerance) const {
        return LengthSquared() < tolerance * tolerance;
    }

    bool Vector3D::IsZero(float tolerance) const {
        return LengthSquared() <= tolerance * tolerance;
    }
}
