#pragma once

namespace GameSystems::Math {
	/** @brief Represents a 3D transformation matrix in homogeneous coordinates. */
	struct Matrix3D {
		float matrix[4][4];

		/** @param	identity If true (default), initializes to identity matrix.
					If false, the matrix is zero-initialized.*/
		Matrix3D(bool identity = true);
	};
}
