#include <cmath>
#include <ostream>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../include/vector3.h"
#include "../include/stb_image/stb_image_write.h"

namespace rayt
{
	float vector3::x() const
	{
		return _values[0];
	}

	float vector3::y() const
	{
		return _values[1];
	}

	float vector3::z() const
	{
		return _values[2];
	}

	float  vector3::length() const
	{
		return sqrt(length_squared());
	}

	float vector3::length_squared() const
	{
		return _values[0] * _values[0] + _values[1] * _values[1] + _values[2] * _values[2];
	}	

	static double dot(const vector3& u, const vector3& v)
	{
		return u[0] * v[0]
			+ u[1] * v[1]
			+ u[2] * v[2];
	}

	static vector3 cross(const vector3& u, const vector3& v)
	{
		return
		{
			u[1] * v[2] - u[2] * v[1],
			u[2] * v[0] - u[0] * v[2],
			u[0] * v[1] - u[1] * v[0]
		};
	}

	static vector3 normalized(vector3 v)
	{
		return v / v.length();
	}
}

