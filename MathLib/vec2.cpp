#include "vec2.h"
#include <math.h>

vec2 vInit2(float inX, float inY)
{
	vec2 out;
	out.x = inX;
	out.y = inY;

	return out;
}

vec2 operator+(const vec2 & lhs, const vec2 & rhs)
{
	vec2 out;
	out.x = lhs.x + rhs.x;
	out.y = lhs.y + rhs.y;

	return out;
}

vec2 operator-(const vec2 & lhs, const vec2 & rhs)
{
	vec2 out;
	out.x = lhs.x - rhs.x;
	out.y = lhs.y - rhs.y;

	return out;
}

vec2 operator-(const vec2 & v)
{
	return vec2();
}

vec2 operator*(const vec2 & lhs, float rhs)
{
	vec2 out;
	out.x = lhs.x * rhs;
	out.y = lhs.y * rhs;

	return out;
}

vec2 operator*(float lhs, const vec2 & rhs)
{
	vec2 out;
	out.x = lhs * rhs.x;
	out.y = lhs * rhs.y;

	return out;
}

vec2 operator/(const vec2 & lhs, const vec2 & rhs)
{
	vec2 out;
	out.x = lhs.x / rhs.x;
	out.y = lhs.y / rhs.y;

	return out;
}

vec2 & operator+=(vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs + rhs;
}

vec2 & operator-=(vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs - rhs;
}

vec2 & operator*=(vec2 & lhs, float rhs)
{
	return lhs = lhs * rhs;
}

vec2 & operator*=(float lhs, vec2 & rhs)
{
	return  rhs = rhs * lhs;
}

vec2 & operator/=(vec2 & lhs, vec2 & rhs)
{
	return lhs = lhs / rhs;
}

bool operator==(const vec2 & lhs, const vec2 & rhs)
{
	return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator!=(const vec2 & lhs, const vec2 & rhs)
{
	return lhs.x != rhs.x && lhs.y != rhs.y;
}

float magnitude(const vec2 & v)
{
	float h = sqrt((v.x*v.x) + (v.y*v.y));
	return h;
}