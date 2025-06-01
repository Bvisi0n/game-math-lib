#pragma once

namespace GameMath {
    class Vector2D {
    public:
        float x, y;

        Vector2D(float x = 0.0f, float y = 0.0f);

        /* @brief Calculates the Euclidean length (magnitude) of the vector.
         * @return The length of the vector as a float. */
		float Length() const;
    };
}
