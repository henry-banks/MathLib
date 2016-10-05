#pragma once
#include "Spaceship.h"

class SpaceshipController
{
public:
	SpaceshipController();
	~SpaceshipController();

	void update(Spaceship &ship);
};

