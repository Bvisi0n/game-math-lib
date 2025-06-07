#pragma once

namespace GameMath {
    /** @class Vector2D
        @brief Represents a 2D mathematical vector with x and y components. */
    class Vector2D {
    public:
        float x, y;

        Vector2D(float x = 0.0f, float y = 0.0f);

        /** @brief Adds two vectors component-wise.
            @param other: The vector to add.
            @return A new Vector2D representing the sum. */
        Vector2D operator+(const Vector2D& other) const;

        /** @brief Subtracts another vector from this one component-wise.
            @param other: The vector to subtract.
			@return A new Vector2D representing the difference. */
        Vector2D operator-(const Vector2D& other) const;

        /** @brief Scales the vector by a scalar factor.
            @param scalar: The float value to multiply each component by.
            @return A new Vector2D representing the scaled vector. */
		Vector2D operator*(const float scalar) const;

        /** @brief Divides both vector components by a scalar value.
            If the scalar is zero, the result is defined as (0, 0) to avoid division by zero.
            @param scalar: The value to divide each component by.
			@return A new Vector2D representing the scaled-down vector. */
		Vector2D operator/(const float scalar) const;

        /** @brief Checks for exact (bitwise) equality.
            @param other: The vector to compare with.
            @return True if x and y are exactly equal. Use Equals() for tolerance. */
		bool operator==(const Vector2D& other) const;

        /** @brief Checks for exact (bitwise) inequality.
            @param other: The vector to compare with.
            @return True if x or y differ exactly. Use Equals() for tolerance. */
		bool operator!=(const Vector2D& other) const;

        /** @brief Calculates the dot product between this vector and another.
            @param other: The vector to compute the dot product with.
            @return The scalar dot product result. */
        float Dot(const Vector2D& other) const;

        /** @brief Compares two vectors using a tolerance value.
            @param other: The vector to compare against.
            @param tolerance: Allowed difference between components (default 0.0001f).
            @return True if the components are equal within the given tolerance. */
        bool Equals(const Vector2D& other, float tolerance = 0.0001f) const;

        /** @brief Calculates the Euclidean length (magnitude) of the vector.
            @return The length of the vector as a float. */
		float Length() const;

        /** @brief Calculates the squared length of the vector.
            @return The squared length of the vector (x² + y²). */
		float LengthSquared() const;

        /** @brief Returns a normalized (unit length) copy of this vector.
            @return A new Vector2D with unit length, or (0, 0) if the vector is zero. */
        Vector2D Normalized() const;

        /** @brief Returns a vector that is perpendicular to this vector.
            The result is a 90° counter-clockwise rotation of the original vector.
			@return A new Vector2D perpendicular to this one. */
        Vector2D Perpendicular() const;

        /** @brief Checks if the vector's magnitude is within tolerance of zero.
            @param tolerance The maximum allowed length.
            @return True if the vector's length is less than or equal to tolerance. */
        bool IsNearlyZero(float tolerance) const;

        /** @brief Checks if both components are within tolerance of zero.
            @param tolerance: The per-component threshold.
			@return True if abs(x) and abs(y) are less than or equal to tolerance. */
		bool IsZero(float tolerance = 0.0f) const;
    };
}