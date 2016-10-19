#pragma once
#include "Transform.h"

class ShipRender
{
public:
	ShipRender();
	~ShipRender();

	unsigned color;
	float size;

	void draw(const Transform &t, const mat3 &camera);

};