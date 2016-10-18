#include <iostream>
#include "Transform.h"
#include "sfwdraw.h"
#include "flops.h"

using namespace sfw;

Transform::Transform()
{
	pos.x = 0;
	pos.y = 0;

	scl.x = 10;
	scl.y = 10;

	rotAngle = 0;

	m_parent = nullptr;
}

Transform::Transform(float x, float y)
{
	pos.x = x;
	pos.y = y;

	scl.x = 1;
	scl.y = 1;

	rotAngle = 3;

	m_parent = nullptr;
}

Transform::Transform(float x, float y, float w, float h, float a)
{
	pos.x = x;
	pos.y = y;

	scl.x = w;
	scl.y = h;

	rotAngle = a;

	m_parent = nullptr;
}


Transform::~Transform()
{
}

vec2 Transform::getDir() const
{
	return fromAngle(deg2rad(rotAngle));
}

void Transform::setDir(const vec2 & inDir)
{
	rotAngle = angle(inDir);
}

vec2 Transform::getUp() const
{
	return -perp(getDir());
}

mat3 Transform::getLocalTransform() const
{
	mat3 s = scale(scl.x, scl.y);
	mat3 t = translate(pos.x, pos.y);
	mat3 r = rotationRadians(deg2rad(rotAngle));

	mat3 out = t*r*s;

	return out;
}

mat3 Transform::getGlobalTransform() const
{
	if (m_parent == nullptr)
		return getLocalTransform();

	else
		return m_parent->getGlobalTransform() * getLocalTransform();
}

void Transform::debugDraw(const mat3 &t) const
{

	//<PROBLEM>
	mat3 l = t * getGlobalTransform();

	vec3 nPos = l.c[2];

	vec3 right	= getGlobalTransform() * vec3{ 1,0,1 };
	vec3 up		= getGlobalTransform() * vec3{ 0,1,1 };
	//</PROBLEM>



	drawLine(nPos.x, nPos.y, right.x, right.y, RED);
	drawLine(nPos.x, nPos.y, up.x, up.y, GREEN);

	/*vec2 dirEnd = pos + getDir()*scl.x / 2.25;
	vec2 upEnd = pos + perp(getDir()) * scl.y * 2.25;

	drawLine(nPos.x, nPos.y, dirEnd.x, dirEnd.y, RED);
	drawLine(nPos.x, nPos.y, upEnd.x, upEnd.y, GREEN);*/
	
	vec3 pPos = m_parent ? m_parent->getGlobalTransform().c[2] : nPos;
	drawLine(pPos.x, pPos.y, nPos.x, nPos.y, BLUE);

	drawCircle(nPos.x, nPos.y, 12, 12, WHITE);

}
