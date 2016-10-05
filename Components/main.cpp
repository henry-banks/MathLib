#include <iostream>
#include "sfwdraw.h"
#include "vec2.h"
#include "flops.h"
#include "Transform.h"
#include "RigidBody.h"
#include "Spaceship.h"
#include "SpaceshipController.h"

using namespace sfw;

void main()
{
	float W = 800, H = 800;
	float margin = 10;
	float steps = 100;
	float maxSpeed = 100;

	//initContext(800,400);
	initContext(W, H);
	setBackgroundColor(0x222222ff);

	Transform playerTransform = { 200,200 };
	RigidBody playerBody;

	Spaceship playerShip;
	SpaceshipController control;

	while (stepContext())
	{
		float deltaTime = getDeltaTime();

		/*if (playerBody.velocity.y < maxSpeed && getKey('W')) playerBody.velocity.y += 10;
		if (playerBody.velocity.y > -1 * maxSpeed && getKey('S')) playerBody.velocity.y -= 10;
		if (playerBody.velocity.x < maxSpeed && getKey('D')) playerBody.velocity.x += 10;
		if (playerBody.velocity.x > -1 * maxSpeed && getKey('A')) playerBody.velocity.x -= 10;

		if (getKey('Q')) playerBody.angVel += 1.0f;
		if (getKey('E')) playerBody.angVel -= 1.0f;*/

		if (playerTransform.pos.x < 0) playerTransform.pos.x = W;
		else if (playerTransform.pos.x > W) playerTransform.pos.x = 0;
		if (playerTransform.pos.y < 0) playerTransform.pos.y = H;
		else if (playerTransform.pos.y > H) playerTransform.pos.y = 0;

		control.update(playerShip);
		playerShip.update(playerTransform, playerBody);
		playerBody.integrate(playerTransform, deltaTime);

		//std::cout << playerTransform.rotAngle << "\n";

		//Main draw function
		playerTransform.debugDraw(RED);
		playerBody.debugDraw(playerTransform);
	}

	termContext();
}