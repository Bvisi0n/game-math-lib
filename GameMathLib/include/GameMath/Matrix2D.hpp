#pragma once

namespace GameMath {
	/** @brief Represents a 2D transformation matrix in homogeneous coordinates. */
	struct Matrix2D{
		float matrix[3][3];

		/** @param	identity If true (default), initializes to identity matrix.
					If false, the matrix is zero-initialized.*/
		Matrix2D(bool identity = true);
	};
}