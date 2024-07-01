#pragma once

#include <cmath>

namespace mfcg
{
	template <typename T>
	class Vec3
	{
	public:
		// x, y, z component of the vector
		T x, y, z;

	public:
		// Constructs a vec3 with x=0, y=0, z=0
		Vec3() : x(T(0)), y(T(0)), z(T(0)) {}
		// Constructs a vec3 with =t, y=t, z=t
		Vec3(const T& t) : x(t), y(t), z(t) {}
		// Constructs a vec3 with x=_x, y=_y, z=_z
		Vec3(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
		
		/**
		* @brief Computes the magnitude (length) of the vector.
		*
		* This function calculates the magnitude of the vector.
		* It utilizes the formula: sqrt(x^2 + y^2 + z^2), where `x`, `y`, and `z` are
		* the components of the vector.
		*
		* @return The length of the vector.
		*/
		T magnitude()
		{
			return sqrt(x * x + y * y + z * z);
		}

		/**
		* @brief Computes the squared magnitude of the vector.
		*
		* This function calculates the squared length of the vector using the formula:
		* x^2 + y^2 + z^2, where `x`, `y`, and `z` are the components of the vector.
		* It is more efficient than calculating the actual length, as it avoids the
		* computational cost of the square root operation. This can be useful in
		* performance-critical applications where only relative lengths are needed.
		*
		* @return The squared length of the vector.
		*/
		T sqrMagnitude()
		{
			return x * x + y * y + z * z;
		}

		/**
		* @brief Normalizes the vector to unit length.
		*
		* This function converts the vector into a unit vector (a vector with length 1)
		* by dividing each component by the vector's length.
		* This operation modifies the vector in place.
		*
		* @return A reference to the normalized vector.
		*/
		Vec3<T>& normalize()
		{
			T len = magnitude();
			if (len > 0)
			{
				T lenInv = 1 / len;
				x *= lenInv;
				y *= lenInv;
				z *= lenInv;
			}
			return *this;
		}

		/**
		* @brief Computes the dot product of this vector with another vector.
		*
		* @tparam T The type of the vector components (e.g., float, double).
		* @param v The vector to compute the dot product with.
		* @return The dot product of this vector and the given vector.
		*/
		T dot(const Vec3<T>& v)
		{
			return x * v.x + y * v.y + z * v.z;
		}

		/**
		* @brief Computes the cross product of this vector with another vector.
		*
		* @tparam T The type of the vector components (e.g., float, double).
		* @param v The vector to compute the cross product with.
		* @return The cross product of this vector and the given vector.
		*/
		Vec3<T> cross(const Vec3<T>& v)
		{
			return Vec3<T>(
				y * v.z - z * v.y,
				z * v.x - x * v.z,
				x * v.y - y * v.x);
		}

		// Overloaded addition operator for vector addition
		Vec3<T> operator +(const Vec3<T>& v)
		{
			return Vec3<T>(x + v.x, y + v.y, z + v.z);
		}
		// Overloaded subtraction operator for vector suntraction
		Vec3<T> operator -(const Vec3<T>& v)
		{
			return Vec3<T>(x - v.x, y - v.y, z - v.z);
		}
		// Overloaded multiplication operator for scalar multiplication
		Vec3<T> operator *(const T& s)
		{
			return Vec3<T>(x * s, y * s, z * s);
		}
	};

	// TYPEDEFS
	// --------
	typedef Vec3<float> Vec3f;
	typedef Vec3<int> Vec3i;
	typedef Vec3<double> Vec3d;


	// UTILITY FUNCTIONS FOR VEC3
	// --------------------------

	/**
	* @brief Computes the magnitude (length) of the given vector.
	*
	* This function calculates the length of the provided vector `v`.
	* It utilizes the formula: sqrt(v.x^2 + v.y^2 + v.z^2), where
	* `v.x`, `v.y`, and `v.z` are the components of the vector `v`.
	*
	* @tparam T The data type of the vector components (int/float/double etc.).
	* @param v The vector whose length is to be calculated.
	* @return The length of the vector.
	*/
	template<typename T>
	T magnitude(const Vec3<T>& v)
	{
		return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	}

	/**
	* @brief Computes the squared magnitude (length) of the given vector.
	*
	* This function calculates the squared length of the provided vector `v` using
	* the formula: v.x^2 + v.y^2 + v.z^2, where `v.x`, `v.y`, and `v.z` are the
	* components of the vector `v`. It is more efficient than calculating the actual
	* length, as it avoids the computational cost of the square root operation.
	* This can be useful in performance-critical applications where only relative
	* lengths are needed.
	*
	* @tparam T The data type of the vector components (int/float/double etc.).
	* @param v The vector whose squared length is to be calculated.
	* @return The squared length of the vector.
	*/
	template<typename T>
	T sqrMagnitude(const Vec3<T>& v)
	{
		return v.x * v.x + v.y * v.y + v.z * v.z;
	}

	/**
	* @brief Normalizes the given vector to unit length.
	*
	* This function converts the given vector `v` into a unit vector (a vector with length 1)
	* by dividing each component by the vector's length.
	* This operation modifies the vector in place.
	*
	* @tparam T The data type of the vector components (int/float/double etc.).
	* @param v The vector to be normalized.
	*/
	template<typename T>
	void normalize(Vec3<T>& v)
	{
		T len = magnitude(v);
		if (len > 0)
		{
			T lenInv = 1 / len;
			v.x *= lenInv;
			v.y *= lenInv;
			v.z *= lenInv;
		}
	}

	/**
	* @brief Computes the dot product of two vectors.
	*
	* @tparam T The type of the vector components (e.g., float, double).
	* @param a The first vector.
	* @param b The second vector.
	* @return The dot product of the two vectors.
	*/
	template<typename T>
	T dot(const Vec3<T>& a, const Vec3<T>& b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}

	/**
	* @brief Computes the cross product of two vectors.
	*
	* @tparam T The type of the vector components (e.g., float, double).
	* @param a The first vector.
	* @param b The second vector.
	* @return The cross product of the two vectors.
	*/
	template<typename T>
	Vec3<T> cross(const Vec3<T> a, const Vec3<T>& b)
	{
		return Vec3<T>(
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x);
	}
}