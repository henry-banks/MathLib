#pragma once
#include "vec2.h"
class Transform
{
public:
	Transform();
	~Transform();

	vec2 pos;
	vec2 scl;

	float rotAngle;

	vec2 getDir();
	void setDir(const vec2 &inDir);

	void debugDraw();
};

