#ifndef RTOW_VECTOR_3_H
#define RTOW_VECTOR_3_H

#include <ostream>

#include "vector3.h"

namespace rayt
{
	class vector3
	{
	public:
		vector3() : _values{ 0, 0, 0 } { }
		vector3(float e0, float e1, float e2) : _values{ e0, e1, e2 } { }

		float x() const;
		float y() const;
		float z() const;
		float length() const;
		float length_squared() const;

		vector3 operator-() const
		{
			return { -_values[0], -_values[1], -_values[2] };
		}

		float operator[](int i) const
		{
			return _values[i];
		}

		float& operator[](int i)
		{
			return _values[i];
		}

		vector3& operator+=(const vector3& v)
		{
			_values[0] += v[0];
			_values[1] += v[1];
			_values[2] += v[2];

			return *this;
		}

		vector3& operator*=(const float t)
		{
			_values[0] *= t;
			_values[1] *= t;
			_values[2] *= t;

			return *this;
		}

		vector3& operator/=(const float t)
		{
			return *this *= 1 / t;
		}
		
	private:
		float _values[3];
	};

	inline std::ostream& operator <<(std::ostream& out, const vector3& v)
	{
		return out << v[0] << ' ' << v[1] << ' ' << v[2];
	}

	inline vector3 operator +(const vector3& lhs, const vector3& rhs)
	{
		return { lhs[0] + rhs[0], lhs[1] + rhs[1], lhs[2] + rhs[2] };
	}

	inline vector3 operator *(const vector3& lhs, const vector3& rhs)
	{
		return { lhs[0] * rhs[0], lhs[1] * rhs[1], lhs[2] * rhs[2] };
	}

	inline vector3 operator *(float t, const vector3& v)
	{
		return { t * v[0], t * v[1], t * v[2] };
	}

	inline vector3 operator -(const vector3& lhs, const vector3& rhs)
	{
		return { lhs[0] - rhs[0], lhs[1] - rhs[1], lhs[2] - rhs[2] };
	}

	inline vector3 operator *(const vector3& v, float t)
	{
		return t * v;
	}

	inline vector3 operator /(vector3 v, float t)
	{
		return v * (1 / t);
	}
	
	using color = vector3;
}

#endif