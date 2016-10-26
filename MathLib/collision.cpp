#include "collision.h"
#include "vec2.h"
#include <math.h>

CollisionData1D collisionDetection1D(float aMin, float aMax, float bMin, float bMax)
{
	CollisionData1D out;

	float pDr = aMax - bMin;
	float pDl = bMax - aMin;
	out.penDepth = fmin(pDr, pDl);

	out.colNormal = copysign(1, pDl - pDr);

	out.MTV = out.penDepth * out.colNormal;

	return out;
}

SweptCollisionData1D sweptDetection1D(float aMin, float aMax, float aVel, float bMin, float bMax, float bVel)
{
	SweptCollisionData1D out;

	float tl = (aMin - bMax) / (bVel - aVel);
	float tr = (bMin - aMax) / (aVel - bVel);

	out.entryTime = fmin(tl, tr);
	out.exitTime = fmax(tl, tr);

	out.colNormal = copysign(1, tl - tr);

	return out;
}

CollisionData boxCollision(const AABB & a, const AABB & b)
{
	CollisionData out;

	CollisionData1D xCol = collisionDetection1D(a.min().x, a.max().x, b.min().x, b.max().x);
	CollisionData1D yCol = collisionDetection1D(a.min().y, a.max().y, b.min().y, b.max().y);
	
	if (xCol.penDepth < yCol.penDepth) {
		out.colNormal = vec2{ xCol.colNormal, 0 };
		out.penDepth = xCol.penDepth;
	}
		
	else {
		out.colNormal = vec2{ 0,yCol.colNormal };
		out.penDepth = yCol.penDepth;
	}
		
	return out;
}

bool SweptCollisionData1D::result() const
{
	//return false;
	return entryTime >= 0 && entryTime <= 1;
}

bool CollisionData1D::result() const
{
	return penDepth >= 0;
}

vec2 CollisionData::MTV() const
{
	return colNormal * penDepth;
}

bool CollisionData::result() const
{
	return false;
}
