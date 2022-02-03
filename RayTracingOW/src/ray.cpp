#include "../include/ray.h"

namespace rayt
{
	ray::ray(vector3& origin, vector3& direction)
	{
		_origin = vector3(origin);
		_direction = vector3(direction);
	}

	vector3 ray::origin() const
	{
		return _origin;
	}

	vector3 ray::direction() const
	{
		return _direction;
	}	

	vector3 ray::value_at(float value) const
	{
		return _origin + (_direction * value);
	}
}
