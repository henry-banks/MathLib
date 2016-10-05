#pragma once
#include "vec2.h"
class Transform
{
public:
	Transform();
	Transform(float x, float y);
	Transform(float x, float y, float w, float h, float s);
	~Transform();

	vec2 pos;
	vec2 scl;
	//AKA 'facing'
	float rotAngle;

	vec2 getDir() const;
	void setDir(const vec2 &inDir);
	vec2 getUp() const;

	void debugDraw(int c);
};