#include "SpaceshipController.h"
#include "sfwdraw.h"

using namespace sfw;

SpaceshipController::SpaceshipController()
{
}


SpaceshipController::~SpaceshipController()
{
}

void SpaceshipController::update(Spaceship & ship)
{
	float hInput = 0;
	hInput -= getKey('A');
	hInput += getKey('D');

	float vInput = 0;
	vInput += getKey('W');
	vInput -= getKey('S');

	ship.doTurn(hInput);
	ship.doThrust(vInput);
}
