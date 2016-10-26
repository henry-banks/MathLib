#pragma once

#include "mat3.h"

//Bounding Volumes
struct Circle
{
	vec2 pos;	//offset
	float rad;
};

//Axis-Aligned Bounding Box
struct AABB
{
	vec2 pos;
	vec2 he; //Half-extents - x = half-width, y = half-height
	
	vec2 min() const;
	vec2 max() const;
};

struct CPlane
{
};
struct Ray
{

};
struct Hull
{

};

Circle	operator*(const mat3 &t, const Circle &c);
bool	operator==(const Circle &a, const Circle &b);

AABB	operator*(const mat3 &t, const AABB &b);
//Must input an array of four points
AABB fromBoxAABB(const vec2 p[]);

CPlane	operator*(const mat3 &t, const CPlane &p);
Ray		operator*(const mat3 &t, const Ray &r);
Hull	operator*(const mat3 &t, const Hull &h);