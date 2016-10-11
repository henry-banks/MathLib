#include "mat3.h"

mat3 mat3Identity()
{
	return mat3{1,0,0,0,1,0,0,0,1};
}

mat3 operator+(const mat3 & l, const mat3 & r)
{
	mat3 out;
	for (int i = 0; i < 3; i++)
	{
		out.m[i] = l.m[i] + r.m[i];
	}

	return out;
}

mat3 operator-(const mat3 & l, const mat3 & r)
{
	mat3 out;
	for (int i = 0; i < 3; i++)
	{
		out.m[i] = l.m[i] - r.m[i];
	}

	return out;
}

mat3 operator-(const mat3 & l)
{
	mat3 out;
	for (int i = 0; i < 3; i++)
	{
		out.m[i] = -l.m[i];
	}

	return out;
}

mat3 transpose(const mat3 & l)
{
	return mat3();
}

bool operator==(const mat3 & l, const mat3 & r)
{
	bool out;
	for (int i = 0; i < 9; i++)
	{
		if (l.m[i] != r.m[i]) {
			out = false;
			break;
		}
	}

	return out;
}

mat3 operator*(const mat3 & l, const float & r)
{
	mat3 out = l;
	for (int col = 0; col < 3; col++) {
		for (int row = 0; row < 3; row++) {
			out.mm[col][row] *= r;
		}
	}
	return out;
}

mat3 operator*(const float & l, const mat3 & r)
{
	mat3 out = r;
	for (int col = 0; col < 3; col++) {
		for (int row = 0; row < 3; row++) {
			out.mm[col][row] *= l;
		}
	}
	return out;
}

mat3 operator*(const mat3 & l, const mat3 & r)
{
	mat3 out = l;
	for (int col = 0; col < 3; col++) {
		for (int row = 0; row < 3; row++) {
			out.mm[col][row] *= l.mm[row][col];
		}
	}
	return out;
}

mat3 operator*(const mat3 & l, const vec3 & r)
{
	return mat3();
}

mat3 inverse(const mat3 & l)
{
	return mat3();
}

float determinant(const mat3 & l)
{
	return 0.0f;
}

float mat3::operator[](unsigned idx) const
{
	return m[idx];
}

float & mat3::operator[](unsigned idx)
{
	return m[idx];
}
