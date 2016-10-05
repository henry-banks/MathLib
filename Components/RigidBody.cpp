#include "RigidBody.h"



RigidBody::RigidBody()
{
	acc = vec2{ 0,0 };
	velocity = vec2{ 0,0 };
	angVel = 0.0f;
	angAcc = 0.0f;
}


RigidBody::~RigidBody()
{
}

void RigidBody::addForce(const vec2 & force)
{
	acc += force;
}

void RigidBody::addImpulse(const vec2 & impulse)
{
	velocity += impulse;
}

void RigidBody::addTorque(float torque)
{
	angAcc += torque;
}

void RigidBody::integrate(Transform & trans, float deltaTime)
{
	//Magic math
	velocity += acc * deltaTime;
	angVel = angVel + angAcc * deltaTime;

	trans.pos = trans.pos + velocity * deltaTime;
	trans.rotAngle = trans.rotAngle + angVel * deltaTime;
}
