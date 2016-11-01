#pragma once

#include "mat3.h"

//Bounding Volumes
struct Circle
{
	vec2 pos;	//offset
	float rad;
};
Circle	operator*(const mat3 &t, const Circle &c);
bool	operator==(const Circle &a, const Circle &b);


//Axis-Aligned Bounding Box
struct AABB
{
	vec2 pos;
	vec2 he; //Half-extents - x = half-width, y = half-height
	
	vec2 min() const;
	vec2 max() const;
};
AABB	operator*(const mat3 &t, const AABB &b);
//Must input an array of four points
AABB fromBoxAABB(const vec2 p[]);

struct Plane
{
	vec2 pos, dir;
};
Plane	operator*(const mat3 &t, const Plane &p);
bool	operator==(const Plane &a, const Plane &b);

struct Ray
{

};
Ray		operator*(const mat3 &t, const Ray &r);


struct Hull
{

};
Hull	operator*(const mat3 &t, const Hull &h);