#include "Shapes.h"
#include "flops.h"
#include <math.h>

Circle operator*(const mat3 & t, const Circle & c)
{
	Circle out = c;

	//Set position
	out.pos = (t*vec3{ c.pos.x, c.pos.y, 1 }).xy;

	float xRad = magnitude(t * vec3{ 0,c.rad,0 });
	float yRad = magnitude(t * vec3{ c.rad,0,0 });
	
	out.rad = xRad > yRad ? xRad : yRad;

	return out;
}

bool operator==(const Circle & a, const Circle & b)
{
	return a.pos == b.pos && fequals(a.rad, b.rad);
}

AABB operator*(const mat3 & t, const AABB & b)
{
	AABB out = b;

	//do it not work?
	/*out.pos = (t * vec3{ b.pos.x, b.pos.y, 1 }).xy;
	out.he = (t * vec3{ b.he.x, b.he.y, 1 }).xy;*/

	vec3 tp[4];

	tp[0] = t * vec3{ b.min().x, b.min().y, 1 };
	tp[1] = t * vec3{ b.max().x, b.max().y, 1 };
	tp[2] = t * vec3{ b.min().x, b.max().y, 1 };
	tp[3] = t * vec3{ b.max().x, b.min().y, 1 };

	vec2 minv = tp[0].xy;
	vec2 maxv = tp[0].xy;

	for (int i = 0; i < 4; i++)
	{
		minv = min(minv, tp[i].xy);
		maxv = max(maxv, tp[i].xy);
	}


	return out;
}

AABB fromBoxAABB(const vec2 p[])
{
	AABB out;

	//Setting up values to test against.
	//I set them all to a certain point's values because I
	//cannot effectively guess what the points' coordinates will be.
	float maxX = p[0].x;
	float minX = p[0].x;
	float maxY = p[0].y;
	float minY = p[0].y;

	for (int i = 0; i < 4; i++)
	{
		if (p[i].x > maxX)
			maxX = p[i].x;
		else if (p[i].x < minX)
			minX = p[i].x;

		if (p[i].y > maxY)
			maxY = p[i].y;
		else if (p[i].y < minY)
			minY = p[i].y;
	}
	//Set position to be the midpoint between the max and min points
	out.pos = vec2{ (maxX + minX) / 2,(maxY + minY) / 2 };
	//Set half-extents to be distance between position and max point
	//Max point used so that the values will be positive
	out.he = vec2{ maxX - out.pos.x, maxY - out.pos.y };

	return out;
}

CPlane operator*(const mat3 & t, const CPlane & p)
{
	return CPlane();
}

Ray operator*(const mat3 & t, const Ray & r)
{
	return Ray();
}

Hull operator*(const mat3 & t, const Hull & h)
{
	return Hull();
}

vec2 AABB::min() const
{
	vec2 out = pos - he;
	return out;
}

vec2 AABB::max() const
{
	vec2 out = pos + he;
	return out;
}
