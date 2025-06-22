#include "GameMath/Vector3D.hpp"
#include <cmath>

namespace GameMath {
	Vector3D::Vector3D(float x, float y, float z)
		: x(x), y(y), z(z) 
	{}

	Vector3D Vector3D::Cross(const Vector3D& other) const
	{
		return Vector3D(
			y * other.z - z * other.y,
			z * other.x - x * other.z,
			x * other.y - y * other.x
		);
	}

	float Vector3D::Length() const {
		return std::sqrt(LengthSquared());
	}

	float Vector3D::LengthSquared() const {
		return x * x + y * y + z * z;
	}
}