#pragma once

namespace GameSystems::Math {
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

        /** @brief Normalizes the vector in-place (makes its length 1).
            If the vector is zero-length, it remains unchanged. */
        void Normalize();

        /** @brief Returns a normalized copy of this vector.
            @return A unit vector pointing in the same direction. Returns (0,0,0) if the original vector is zero. */
        Vector3D Normalized() const;

        /** @brief Returns true if the vector's magnitude is almost zero (but not necessarily exactly).
            @param tolerance: Threshold under which the vector is considered nearly zero.
            @return True if squared length is strictly less than tolerance squared. */
        bool IsNearlyZero(float tolerance) const;

        /** @brief Returns true if the vector is exactly (0, 0, 0) or within a given tolerance.
            @param tolerance: Maximum allowed vector length to still be considered zero.
            @return True if vector's squared length is less than or equal to tolerance squared. */
        bool IsZero(float tolerance = 0.0f) const;
    };
}
