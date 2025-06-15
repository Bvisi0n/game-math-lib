#pragma once

namespace GameMath {
    /** @brief Represents a 3D mathematical vector with x, y and z components. */
    class Vector3D {
    public:
        float x, y, z;

        Vector3D(float x = 0.0f, float y = 0.0f, float z = 0.0f);
    };
}