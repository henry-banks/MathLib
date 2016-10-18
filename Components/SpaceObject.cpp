#include "SpaceObject.h"
#include <iostream>

void SpaceObject::init(vec2 transPos, vec2 transScl, float motorSpeed, unsigned aColor, int aSize, Transform* aParent)
{
	trans.pos = transPos;
	trans.scl = transScl;
	trans.m_parent = aParent;

	motor.rotSpeed = motorSpeed;

	render.color = aColor;
	render.size = aSize;
}

void SpaceObject::update(float deltaTime)
{
	motor.update(body);
	body.integrate(trans, deltaTime);
}

void SpaceObject::draw()
{
	render.draw(trans);
}

void SpaceObject::updateDraw(float deltaTime)
{
	printf("%f\n", deltaTime);

	update(deltaTime);
	draw();
}
