#pragma once
#include "Transform.h"
class PlanetRender
{
public:
	PlanetRender();
	PlanetRender(unsigned aColor, int aSize);
	~PlanetRender();

	unsigned color;
	float size;

	void draw(Transform &planetTrans);
};

