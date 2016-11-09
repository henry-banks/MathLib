#include "collision.h"
#include "vec2.h"
#include <vector>
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
	float p1Proj = dotProd(p.dir, point1);
	float p2Proj = dotProd(p.dir, point2);
	float p3Proj = dotProd(p.dir, point3);
	float p4Proj = dotProd(p.dir, point4);

	float minPoint = fminf(fminf(p1Proj, p2Proj), fminf(p3Proj, p4Proj));
	float maxPoint = fmaxf(fmaxf(p1Proj, p2Proj), fmaxf(p3Proj, p4Proj));

	//Point to test against
	float planeExtent = dotProd(p.dir, p.pos);

	//base penetration depth
	float pd = planeExtent - minPoint;


	//THIS IS THE IMPORTANT PART.
	out.penDepth = planeExtent - minPoint;
	out.colNormal = p.dir;

	return out;
}

CollisionDataSwept planeBoxCollisionSwept(const Plane & p, const vec2 & pVel, const AABB & b, const vec2 & bVel)
{
	CollisionDataSwept out;

	//Project points (goes counter-clockwise from max)
	float p1 = dotProd(p.dir, b.max());
	float p2 = dotProd(p.dir, vec2{ b.min().x, b.max().y });
	float p3 = dotProd(p.dir, b.min());
	float p4 = dotProd(p.dir, vec2{ b.max().x, b.min().y });

	float pMin = fminf(fminf(p1, p2), fminf(p3, p4));
	float pMax = fmaxf(fmaxf(p1, p2), fmaxf(p3, p4));

	float pBvel = dotProd(p.dir, bVel);
	float pPvel = dotProd(p.dir, pVel);
	
	float planeExtent = dotProd(p.dir, p.pos);

	out.entryTime = (pMin - pMax) / (pPvel - pBvel);
	out.exitTime = (pMax - planeExtent) / (pPvel - pBvel);

	return out;
}

CollisionData HullCollision(const Hull & a, const Hull & b)
{
	CollisionData out;
	//Make a list of ALL projected points
	std::vector<std::vector<float>> allPoints;

	//Project ALL points along ALL axes
	for (int i = 0; i < a.size + b.size; i++)
	{
		//A-axis projection
		std::vector<float> tempPoints;
		for (int j = 0; j < a.size; j++)
		{
			tempPoints.push_back(dotProd(a.normals[i], a.vertices[j]));
		}
		for (int j = 0; j < a.size; j++)
		{
			tempPoints.push_back(dotProd(a.normals[i], b.vertices[j]));
		}

		//B-axis projection
		for (int j = 0; j < a.size; j++)
		{
			tempPoints.push_back(dotProd(b.normals[i], a.vertices[j]));
		}
		for (int j = 0; j < a.size; j++)
		{
			tempPoints.push_back(dotProd(b.normals[i], b.vertices[j]));
		}
		allPoints.push_back(tempPoints);
	}

	return out;
}

CollisionData HullColAxis(const Hull & a, const Hull & b, const vec2 & normal, int index)
{
	CollisionData out;

	//Set min/max
	float aMax = dotProd(normal, a.vertices[0]);
	float aMin = dotProd(normal, a.vertices[0]);
	float bMax = dotProd(normal, b.vertices[0]);
	float bMin = dotProd(normal, b.vertices[0]);
	//Project a-vertices
	for (int i = 0; i < a.size; i++)
	{
		float tempPos = dotProd(normal, a.vertices[i]);
		if (tempPos > aMax)
			aMax = tempPos;
		else if (tempPos < aMin)
			aMin = tempPos;
	}

	//Project b-vertices
	for (int i = 0; i < b.size; i++)
	{
		float tempPos = dotProd(normal, b.vertices[i]);
		if (tempPos > bMax)
			bMax = tempPos;
		else if (tempPos < bMin)
			bMin = tempPos;
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
	return penDepth >= 0;
}

bool CollisionDataSwept::result() const
{
	//2nd one may be wrong
	return entryTime >= 0 && entryTime <= 1;
}
