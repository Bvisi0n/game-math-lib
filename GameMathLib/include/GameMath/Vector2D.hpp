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

        /** @brief Compares two vectors for exact component equality.
            @param other: The vector to compare with.
            @return True if x and y are exactly equal, otherwise false. */
		bool operator==(const Vector2D& other) const;

        /** @brief Checks whether two vectors are not equal.
            @param other: The vector to compare against.
            @return True if at least one component is different. */
		bool operator!=(const Vector2D& other) const;

        /** @brief Calculates the dot product between this vector and another.
            @param other: The vector to compute the dot product with.
            @return The scalar dot product result. */
        float Dot(const Vector2D& other) const;

        /** @brief Calculates the Euclidean length (magnitude) of the vector.
            @return The length of the vector as a float. */
		float Length() const;

        /** @brief Calculates the squared length of the vector.
            @return The squared length of the vector (x² + y²). */
		float LengthSquared() const;

        /** @brief Returns a normalized (unit length) copy of this vector.
            @return A new Vector2D with unit length, or (0, 0) if the vector is zero. */
        Vector2D Normalized() const;

        /** @brief Checks if the vector's total magnitude is within tolerance of zero.
            @param tolerance: The maximum allowed length.
            @return True if LengthSquared() is below tolerance squared. */
        bool IsNearlyZero(float tolerance) const;

        /** @brief Checks if both components are within tolerance of zero.
            @param tolerance: The per-component threshold.
			@return True if abs(x) and abs(y) are below tolerance. */
		bool IsZero(float tolerance = 0.0f) const;
    };
} 
