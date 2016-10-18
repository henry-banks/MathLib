#pragma once
#include "PlanetRender.h"
#include "PlanetMotor.h"

//Struct to hold all of this other stuff together
struct SpaceObject
{
	Transform trans;
	RigidBody body;
	PlanetMotor motor;
	PlanetRender render;

	void init(vec2 transPos, vec2 transScl, float motorSpeed, unsigned aColor, int aSize, Transform* aParent = nullptr);

	void update(float deltaTime);
	void draw();
	//All-in-one function
	void updateDraw(float deltaTime);
};