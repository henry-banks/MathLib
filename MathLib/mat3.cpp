#include "mat3.h"
#include <math.h>

mat3 mat3Identity()
{
	return mat3{1,0,0,0,1,0,0,0,1};
}

mat3 operator+(const mat3 & l, const mat3 & r)
{
	mat3 out;
	for (int i = 0; i < 9; i++)
	{
		out.m[i] = l.m[i] + r.m[i];
	}

	return out;
}

mat3 operator-(const mat3 & l, const mat3 & r)
{
	mat3 out;
	for (int i = 0; i < 9; i++)
	{
		out.m[i] = l.m[i] - r.m[i];
	}

	return out;
}

mat3 operator-(const mat3 & l)
{
	mat3 out;
	for (int i = 0; i < 9; i++)
	{
		out.m[i] = -l.m[i];
	}

	return out;
}

mat3 transpose(const mat3 & l)
{
	mat3 out;
	out = l;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			out.mm[i][j] = l.mm[j][i];
		}
	}
	return out;
}

bool operator==(const mat3 & l, const mat3 & r)
{
	bool out = true;
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
	// This is all magic math that esme uses.
	mat3 c = transpose(l);
	mat3 out;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			out.mm[i][j] = dotProd(c.c[j], r.c[i]); //  c.mm[row][col] * r.mm[col][row];
		}
	}
	return out;
}

vec3 operator*(const mat3 & l, const vec3 & r)
{
	mat3 c = l;
	vec3 out;

	for (int i = 0; i < 3; i++) {
		out.v[i] = dotProd(c.c[i], r);
	}
	return out;
}

mat3 inverse(const mat3 & l)
{
	mat3 out;
	//more magic math.  it's all magic and all math
	//This particular magic math is called the Triple Cross Product
	out.c[0] = crossProd(l.c[1], l.c[2]);
	out.c[1] = crossProd(l.c[2], l.c[0]);
	out.c[2] = crossProd(l.c[0], l.c[1]);
	//out = transpose(l);
	
	//Set certain things as negative
	/*for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			i == j ?
				out.mm[i][j] = l.mm[i][j] :
				out.mm[i][j] = -l.mm[j][i];
		}
	}*/
	return 1/determinant(l)*transpose(out);
}

float determinant(const mat3 & l)
{
	//THIS IS ALL MAGIC MATH
	/*float det = (l.mm[0][0] * ((l.mm[1][1] * l.mm[2][2]) - (l.mm[1][2] * l.mm[2][1]))) -
				(l.mm[0][1] * ((l.mm[1][0] * l.mm[2][2]) - (l.mm[1][2] * l.mm[2][0]))) +
				(l.mm[0][2] * ((l.mm[1][0] * l.mm[2][1]) - (l.mm[1][1] * l.mm[2][0])));*/

	return dotProd(l.c[0], crossProd(l.c[1], l.c[2]));
}

mat3 scale(const vec2 & s)
{
	mat3 out = mat3Identity();
	out.mm[0][0] = s.x;
	out.mm[1][1] = s.y;
	return out;
}

mat3 scale(float x, float y)
{
	mat3 out = mat3Identity();
	out.mm[0][0] = x;
	out.mm[1][1] = y;
	return out;
}


mat3 translate(const vec2 & t)
{
	mat3 out = mat3Identity();
	out.mm[0][2] = t.x;
	out.mm[1][2] = t.y;
	return out;
}

mat3 translate(float x, float y)
{
	mat3 out = mat3Identity();
	out.mm[0][2] = x;
	out.mm[1][2] = y;
	return out;
}

mat3 rotation(float a)
{
	vec2 d = fromAngle(a);
	mat3 out = mat3Identity();//mat3{ cosf(a),-sinf(a),0,sinf(a),cosf(a),0,0,0,1 };
	//magicmath
	out.c[0].xy = d;
	out.c[1].xy = -perp(d);
	return out;
}

float mat3::operator[](unsigned idx) const
{
	return m[idx];
}

float & mat3::operator[](unsigned idx)
{
	return m[idx];
}
