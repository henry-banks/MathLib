#include "shapedraw.h"
#include "sfwdraw.h"

void spd::drawCircle(const Circle & t, unsigned color)
{
	sfw::drawCircle(t.pos.x, t.pos.y, t.rad, 12, color);
}

void spd::drawAABB(const AABB & b, unsigned color)
{
	vec2 m1 = b.min();
	vec2 m2 = b.max();
	sfw::drawLine(m1.x, m1.y, m2.x, m1.y, color);
	sfw::drawLine(m1.x, m1.y, m1.x, m2.y, color);
	sfw::drawLine(m2.x, m2.y, m1.x, m2.y, color);
	sfw::drawLine(m2.x, m2.y, m2.x, m1.y, color);
}
