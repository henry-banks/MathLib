#include "Transform.h"
#include "sfwdraw.h"
using namespace sfw;

Transform::Transform()
{
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

void Transform::debugDraw()
{
	drawCircle(pos.x, pos.y, 12);

	vec2 dirEnd = pos + getDir()*scl.x;
	vec2 upEnd = pos + perp(getDir()) * scl.y;

	drawLine(pos.x, pos.y, dirEnd.x, dirEnd.y, RED);
	drawLine(pos.x, pos.y, upEnd.x, upEnd.y, GREEN);
}
