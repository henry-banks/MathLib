#include "Tank.h"
#include "sfwdraw.h"

using namespace sfw;

//Tank::Tank()
//{
//}


Tank::Tank(vec2 pos, float baseAngle, float turretAngle)
{
	turret.m_parent = &base;

	base.pos = pos;
	base.rotAngle = baseAngle;

	turret.rotAngle = turretAngle;

	buttonTimer = 0.5f;
}

Tank::~Tank()
{
}

void Tank::updateDraw(float deltaTime)
{
	if (getKey('W') && buttonTimer <= 0) {

		switch (step)
		{
		case 0:
			rotTurret(turretAngle);
			step++;
			break;
		case 1:
			rotBase(baseAngle);
			step++;
			break;
		case 2:
			base.pos = destList[++destIndex];
			step = 0;
			break;
		default:
			step = 0;
			break;
		}
		rotBase(baseAngle);
		rotTurret(turretAngle);
	}
	if (buttonTimer > 0) {
		buttonTimer -= .01;
	}

}

void Tank::rotBase(float inAngle)
{
	base.rotAngle += inAngle;
}

void Tank::rotTurret(float inAngle)
{
	turret.rotAngle += inAngle;
}

void Tank::move(float dist)
{

}
