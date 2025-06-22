#include "GameMath/Vector3D.hpp"
#include <cmath>

namespace GameMath {
	Vector3D::Vector3D(float x, float y, float z)
		: x(x), y(y), z(z) 
	{}

	float Vector3D::Length() const {
		return std::sqrt(LengthSquared());
	}

	float Vector3D::LengthSquared() const {
		return x * x + y * y + z * z;
	}
}