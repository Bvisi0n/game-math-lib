#pragma once

namespace GameMath {
    /** @class Vector2D
        @brief Represents a 2D mathematical vector with x and y components. */
    class Vector2D {
    public:
        float x, y;

        Vector2D(float x = 0.0f, float y = 0.0f);

        /** @brief Calculates the dot product between this vector and another.
            @param other: The vector to compute the dot product with.
            @return The scalar dot product result. */
        float Dot(const Vector2D& other) const;

        /** @brief Calculates the Euclidean length (magnitude) of the vector.
            @return The length of the vector as a float. */
		float Length() const;

        /** @brief Returns a normalized (unit length) copy of this vector.
            @return A new Vector2D with unit length, or (0, 0) if the vector is zero. */
        Vector2D Normalized() const;
    };
}
