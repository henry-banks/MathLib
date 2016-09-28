#include "flops.h"
#include <math.h>

const float PI = 3.141592;

bool fequals(float lhs, float rhs)
{
	//Used for debugging
	float diff = fabs(lhs - rhs);

	if (diff < .000001) {
		return true;
	}

	return false;
}

float deg2rad(float deg)
{
	float out = deg * (PI / 180);
	return out;
}

float rad2deg(float rad)
{
	float out = rad * (180 / PI);
	return out;
}
