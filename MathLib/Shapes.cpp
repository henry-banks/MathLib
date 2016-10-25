#include "Shapes.h"
#include "flops.h"

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
	vec3 pos3 = t * vec3{ b.pos.x, b.pos.y, 1 };
	out.pos = pos3.xy;

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
