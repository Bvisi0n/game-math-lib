#include "GameMath/Matrix2D.hpp"

namespace GameMath {
    // Default to identity: this is the most common 2D transform initializer
    // and avoids unnecessary overwrites in >80% of real-world use cases.
	Matrix2D::Matrix2D(bool identity)
        : m{{1.0f, 0.0f, 0.0f},
            {0.0f, 1.0f, 0.0f},
            {0.0f, 0.0f, 1.0f}}
    {
        if (!identity) {
            m[0][0] = m[1][1] = m[2][2] = 0.0f;
        }
    }
}