#include "flops.h"
#include <math.h>
#include "vec2.h"
#include <vector>

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

float linearHalf(float x)
{
	float result = x*0.5f;
	return result;
}

float slowToFast(float x)
{
	float result = pow(x,2);
	return result;
}

float fastToSlow(float x)
{
	float result = sqrt(x);
	return result;
}

float upDown(float x)
{
	float result = 1 - abs(2*x - 1);
	return result;
}

float bounce(float x)
{
	float result = 1 - abs(cos(x * 10)*(1 - x));
	return result;
}

float parabolicBump(float x)
{
	float result = (1 - pow(2*x - 1, 2));
	return result;
}