#include "vec3.h"
#include <math.h>

vec3 vInit3(float inX, float inY, float inZ)
{
	vec3 out;
	out.x = inX;
	out.y = inY;
	out.z = inZ;

	return vec3();
}

vec3 operator+(const vec3 & lhs, const vec3 & rhs)
{
	vec3 out;
	out.x = lhs.x + rhs.x;
	out.y = lhs.y + rhs.y;
	out.z = lhs.z + rhs.z;

	return out;
}

vec3 operator-(const vec3 & lhs, const vec3 & rhs)
{
	vec3 out;
	out.x = lhs.x - rhs.x;
	out.y = lhs.y - rhs.y;
	out.z = lhs.z - rhs.z;

	return out;
}

vec3 operator-(const vec3 & v)
{
	vec3 out;
	out.x = -v.x;
	out.y = -v.y;
	out.z = -v.z;

	return out;
}

vec3 operator*(const vec3 & lhs, float rhs)
{
	vec3 out;
	out.x = lhs.x * rhs;
	out.y = lhs.y * rhs;
	out.z = lhs.z * rhs;

	return out;
}

vec3 operator*(float lhs, const vec3 & rhs)
{
	vec3 out;
	out.x = lhs * rhs.x;
	out.y = lhs * rhs.y;
	out.z = lhs * rhs.z;

	return out;
}

vec3 operator/(const vec3 & lhs, const vec3 & rhs)
{
	vec3 out;
	out.x = lhs.x / rhs.x;
	out.y = lhs.y / rhs.y;
	out.z = lhs.z / rhs.z;

	return out;
}

vec3 & operator+=(vec3 & lhs, const vec3 & rhs)
{
	return lhs = lhs + rhs;
}

vec3 & operator-=(vec3 & lhs, const vec3 & rhs)
{
	return lhs = lhs - rhs;
}

vec3 & operator*=(vec3 & lhs, float rhs)
{
	return lhs = lhs * rhs;
}

vec3 & operator*=(float lhs, vec3 & rhs)
{
	return rhs = rhs * lhs;
}

vec3 & operator/=(vec3 & lhs, vec3 & rhs)
{
	return lhs = lhs / rhs;
}

bool operator==(const vec3 & lhs, const vec3 & rhs)
{
	return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}

bool operator!=(const vec3 & lhs, const vec3 & rhs)
{
	return lhs.x != rhs.x && lhs.y != rhs.y && lhs.z != rhs.z;
}

float magnitude(const vec3 & v)
{
	float h = sqrt((v.x*v.x) + (v.y*v.y) + (v.z*v.z));
	return h;
}
