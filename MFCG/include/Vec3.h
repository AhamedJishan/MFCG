#pragma once

namespace MFCG
{
	template <typename T>
	class Vec3
	{
	public:

		Vec3() : x(T(0)), y(T(0)), z(T(0)) {}
		Vec3(const T& t) : x(t), y(t), z(t) {}
		Vec3(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}

	public:
		T x, y, z;
	};

	typedef Vec3<float> Vec3f;
}