#include "Transform.h"
#include "sfwdraw.h"
using namespace sfw;

Transform::Transform()
{
	pos.x = 0;
	pos.y = 0;

	scl.x = 28;
	scl.y = 8;
}

Transform::Transform(float x, float y)
{
	pos.x = x;
	pos.y = y;

	scl.x = 28;
	scl.y = 8;
}

Transform::Transform(float x, float y, float w, float h, float a)
{
	pos.x = x;
	pos.y = y;

	scl.x = w;
	scl.y = h;

	rotAngle = a;
}


Transform::~Transform()
{
}

vec2 Transform::getDir()
{
	return fromAngle(rotAngle);
}

void Transform::setDir(const vec2 & inDir)
{
	rotAngle = angle(inDir);
}

void Transform::debugDraw(int c)
{
	drawCircle(pos.x, pos.y, 12);

	vec2 dirEnd = pos + getDir()*scl.x;
	vec2 upEnd = pos + perp(getDir()) * scl.y;

	drawLine(pos.x, pos.y, dirEnd.x, dirEnd.y, RED);
	drawLine(pos.x, pos.y, upEnd.x, upEnd.y, GREEN);
}
