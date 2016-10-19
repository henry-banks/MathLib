#pragma once
#include "RigidBody.h"
#include <vector>
class Tank
{
public:
	Tank(vec2 pos = vec2{ 0,0 }, float baseAngle = 0, float turretAngle = 0);
	~Tank();

	Transform base;

	Transform turret;

	float baseAngle;
	float turretAngle;
	float dist;

	float buttonTimer;

	bool isAdv;
	//0 = turn turret, 1 = turn base, 2 = move
	int step;

	float destIndex;
	std::vector<vec2> destList;
	std::vector<vec2> currentList;

	void updateDraw(float deltaTime);

	void rotBase(float inAngle);
	void rotTurret(float inAngle);

	void move(float dist);
};

