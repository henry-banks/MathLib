#pragma once

#include "vec2.h"
#include "Transform.h"

class RigidBody
{
public:
	RigidBody();
	~RigidBody();

	vec2 velocity;
	//Angular Velocity
	float angVel;
	//Acceleration
	vec2 acc;
	float angAcc;

	void addForce(const vec2 &force);
	void addImpulse(const vec2 &impulse);
	void addTorque(float torque);
	
	void integrate(Transform &trans, float deltaTime);
};

