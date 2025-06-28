#pragma once

namespace GameMath {
    /** @brief Represents a 3D mathematical vector with x, y and z components. */
    struct Vector3D {
        float x, y, z;

        Vector3D(float x = 0.0f, float y = 0.0f, float z = 0.0f);

        /** @brief Returns the cross product of this vector and another.
            @param other: The vector to cross with.
            @return A new Vector3D perpendicular to both input vectors. */
		Vector3D Cross(const Vector3D& other) const;

        /** @brief Compares two vectors using a tolerance value.
            @param other: The vector to compare against.
            @param tolerance: Allowed difference between components (default 0.0001f).
            @return True if all components are within the given tolerance. */
        bool Equals(const Vector3D& other, float tolerance = 0.0001f) const;

        /** @brief Returns the magnitude of the vector.
            @return The Euclidean length of this vector. */
        float Length() const;

        /** @brief Returns the squared magnitude of the vector.
            @return The sum of squared components. Avoids sqrt for performance. */
        float LengthSquared() const;
    };
}