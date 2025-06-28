#include "GameMath/Matrix3D.hpp"

namespace GameMath {
    // Default to identity: this is the most common 3D transform initializer
    // and avoids unnecessary overwrites in >80% of real-world use cases.
    Matrix3D::Matrix3D(bool identity)
        : matrix{   {1.0f, 0.0f, 0.0f, 0.0f},
                    {0.0f, 1.0f, 0.0f, 0.0f},
                    {0.0f, 0.0f, 1.0f, 0.0f},
                    {0.0f, 0.0f, 0.0f, 1.0f}}
    {
        if (!identity) {
            matrix[0][0] = matrix[1][1] = matrix[2][2] = matrix[3][3] = 0.0f;
        }
    }
}