#include "Spaceship.h"
#include "sfwdraw.h"

using namespace sfw;


Spaceship::Spaceship()
{
	/*thrust = 0;
	maxThrust = 100;
	thrustSpeed = 1;

	turn = 0;
	maxTurn = 100;
	turnSpeed = 1;*/

	vertThrust = 0;
	horizThrust = 0;

	speed = 100;
	maxSpeed = 1000;
}


Spaceship::~Spaceship()
{
}

void Spaceship::doThrust(float val)
{
	vertThrust = val;

	/*if (getKey('W')) vertThrust += 1;
	if (getKey('S')) vertThrust -= 1;*/
}

void Spaceship::doTurn(float val)
{
	horizThrust = val;

	/*if (getKey('A')) horizThrust -= 1;
	if (getKey('D')) horizThrust += 1;*/
}

void Spaceship::update(RigidBody & rigid, float deltaTime)
{
	/*doThrust();
	doTurn();*/

	rigid.acc.y = vertThrust * speed;
	rigid.acc.x = horizThrust * speed;

	//If the ship is goign faster than the max speed...
	if (magnitude(rigid.velocity) > maxSpeed)
	{
		//Get the direction
		vec2 dir = normalize(rigid.velocity);

		//Set the velocity to be the direction, going at MAXIMUM SPEED.
		rigid.velocity = dir * maxSpeed;
	}

	//Comment this bit out for funtimes :D
	vertThrust = 0;
	horizThrust = 0;

	/*if (getKey('W')) rigid.acc.y += 10;
	if (getKey('S')) rigid.acc.y -= 10;
	if (getKey('D')) rigid.acc.x += 10;
	if (getKey('A')) rigid.acc.x -= 10;*/
}
