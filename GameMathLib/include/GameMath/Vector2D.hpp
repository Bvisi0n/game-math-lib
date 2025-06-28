#pragma once

namespace GameMath {
    /** @brief Represents a 2D mathematical vector with x and y components. */
    struct Vector2D {
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
            @param scalar: The value to multiply each component by.
            @return A new Vector2D representing the scaled vector. */
		Vector2D operator*(const float scalar) const;

        /** @brief Divides both vector components by a scalar value.
            @param scalar: The value to divide each component by.
			@return A new Vector2D representing the scaled-down vector. If scalar is zero, returns (0, 0). */
		Vector2D operator/(const float scalar) const;

        /** @brief Checks for exact (bitwise) equality.
            @param other: The vector to compare with.
            @return True if x and y are exactly equal. Use Equals() for tolerance. */
		bool operator==(const Vector2D& other) const;

        /** @brief Checks for exact (bitwise) inequality.
            @param other: The vector to compare with.
            @return True if either component differs exactly. Use Equals() for tolerance. */
		bool operator!=(const Vector2D& other) const;

        /** @brief Clamps each component to its specified min/max range. 
            Asserts in debug if min > max. No check in release.
            @param minX: Lower bound for x.
            @param maxX: Upper bound for x.
            @param minY: Lower bound for y.
            @param maxY: Upper bound for y. */
        void ClampComponents(float minX, float maxX, float minY, float maxY);

        /** @brief Clamps vector length between min and max. 
            Asserts in debug if min > max. No check in release.
            @param minLength: Lower bound for the vector’s length.
            @param maxLength: Upper bound for the vector’s length. */
        void ClampLength(float minLength, float maxLength);

        /** @brief Returns the Euclidean distance to another vector.
            @param other: The vector to measure distance to.
            @return float: The Euclidean distance between this vector and other. */
        float DistanceTo(const Vector2D& other) const;

        /** @brief Calculates the dot product between this vector and another.
            @param other: The vector to compute the dot product with.
            @return The result of the dot product as a float. */
        float Dot(const Vector2D& other) const;

        /** @brief Compares two vectors using a tolerance value.
            @param other: The vector to compare against.
            @param tolerance: Allowed difference between components (default 0.0001f).
            @return True if both components are within the given tolerance. */
        bool Equals(const Vector2D& other, float tolerance = 0.0001f) const;

        /** @brief Calculates the Euclidean length (magnitude) of the vector.
            @return The length of the vector as a float. */
		float Length() const;

        /** @brief Calculates the squared length of the vector.
            @return The squared length of the vector (x² + y²). */
		float LengthSquared() const;

        /** @brief Normalizes this vector in-place to unit length.
            If the vector is zero, it becomes (0, 0). */
        void Normalize();

        /** @brief Returns a normalized (unit length) copy of this vector.
            @return A new Vector2D with unit length, or (0, 0) if the vector is zero. */
        Vector2D Normalized() const;

        /** @brief Returns a 90° counter-clockwise rotated copy of this vector.
			@return A new Vector2D perpendicular to this one. */
        Vector2D Perpendicular() const;

        /** @brief Checks if the vector's magnitude is within tolerance of zero.
            @param tolerance: The maximum allowed length.
            @return True if the vector's length is less than or equal to tolerance. */
        bool IsNearlyZero(float tolerance) const;

        /** @brief Checks if both components are within or equal to the given tolerance.
            @param tolerance: The per-component inclusive threshold.
            @return True if abs(x) and abs(y) <= tolerance. */
		bool IsZero(float tolerance = 0.0f) const;

        /** @brief Rounds both vector components to the nearest multiple of gridSize.
            Snaps the vector in place. If gridSize is zero, the vector remains unchanged.
            Negative values are converted to positive internally. 
            @param gridSize: The grid spacing to snap to. Must be non-zero. */
        void SnapToGrid(float gridSize);

        /** @brief Truncates the vector to a maximum length.
            If the vector's length exceeds maxLength, it is scaled down to that length.
            If the vector is zero, it remains unchanged.
            @param maxLength: The maximum allowed length for the vector. */
        void Truncate(float maxLength);
    };
}