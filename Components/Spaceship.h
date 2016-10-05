#pragma once
#include "RigidBody.h"

class Spaceship
{
	/*float thrust;
	float maxThrust;
	float thrustSpeed;

	float turn;
	float maxTurn;
	float turnSpeed;*/

	float vertThrust;
	float horizThrust;

	float speed;
	float maxSpeed;
public:
	Spaceship();
	~Spaceship();

	void doThrust(float val);
	void doTurn(float val);

	void update(RigidBody &rigid, float deltaTime);

};

