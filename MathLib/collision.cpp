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

CollisionDataSwept boxCollisionSwept(const AABB & a, const vec2 & dA, const AABB & b, const vec2 & dB)
{
	CollisionDataSwept out;

	SweptCollisionData1D xCol = sweptDetection1D(a.min().x, a.max().x, dA.x, b.min().x, b.max().x, dB.x);
	SweptCollisionData1D yCol = sweptDetection1D(a.min().y, a.max().y, dA.y, b.min().y, b.max().y, dB.y);

	//Check to see if stuff is overlapping in their current, static positions(?)
	CollisionData1D xDis = collisionDetection1D(a.min().x, a.max().x, b.min().x, b.max().x);
	CollisionData1D yDis = collisionDetection1D(a.min().y, a.max().y, b.min().y, b.max().y);

	//Determines if swept in a certain direction
	bool xSwept = (dA.x - dB.x != 0);
	bool ySwept = (dA.y - dB.y != 0);


	if (yCol.entryTime < xCol.entryTime && !isinf(xCol.entryTime)){
		out.colNormal = vec2{ xCol.colNormal,0 };
		out.entryTime = xCol.entryTime;
	}
	else {
		out.colNormal = vec2{ 0,yCol.colNormal };
		out.entryTime = yCol.entryTime;
	}

	if (yCol.exitTime < xCol.exitTime || isinf(xCol.entryTime))
		out.exitTime = yCol.exitTime;
	else
		out.exitTime = xCol.exitTime;

	return out;
}

CollisionData planeBoxCollision(const Plane & p, const AABB & b)
{
	CollisionData out;

	//Points go counter-clockwise from max
	vec2 point1 = b.max();
	vec2 point2 = vec2{ b.min().x, b.max().y };
	vec2 point3 = b.min();
	vec2 point4 = vec2{ b.max().x, b.min().y };

	//Project points (will probably condense into above)
	float p1Proj = dotProd(point1, p.dir);
	float p2Proj = dotProd(point2, p.dir);
	float p3Proj = dotProd(point3, p.dir);
	float p4Proj = dotProd(point4, p.dir);

	float minPoint = fminf(fminf(p1Proj, p2Proj), fminf(p3Proj, p4Proj));
	float maxPoint = fmaxf(fmaxf(p1Proj, p2Proj), fmaxf(p3Proj, p4Proj));

	//Point to test against
	float planeExtent = dotProd(p.pos, p.dir);

	//base penetration depth
	float pd = planeExtent - minPoint;

	//THIS IS STUPID
	//that other thing
	//float pdMax = planeExtent - maxPoint;

	//
	//if (pd < 0) {
	//	//sum shit
	//}
	//else if (pdMax >= 0) {
	//	//other shit
	//}
	//else if (pdMax < 0 && pd >= 0) {
	//	//clipping shit
	//}

	//THIS IS THE IMPORTANT PART.
	CollisionData1D stuff = collisionDetection1D(minPoint, maxPoint, planeExtent, INFINITY);
	out.penDepth = pd;
	out.colNormal = vec2{stuff.colNormal, stuff.colNormal};

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
	return penDepth >= 0;
}

bool CollisionDataSwept::result() const
{
	//2nd one may be wrong
	return entryTime >= 0 && entryTime <= 1;
}
