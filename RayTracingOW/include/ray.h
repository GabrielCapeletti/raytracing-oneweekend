#ifndef RTOW_RAY_H
#define RTOW_RAY_H

#include "vector3.h"

namespace rayt
{
	class ray
	{
	public:
		ray(vector3& origin, vector3& direction);

		vector3 origin() const;
		vector3 direction() const;
		vector3 value_at(float value) const;
		
	private:
		vector3 _origin;
		vector3 _direction;
	};
}

#endif
