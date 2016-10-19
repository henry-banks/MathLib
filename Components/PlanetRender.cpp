#include "PlanetRender.h"
#include "sfwdraw.h"


PlanetRender::PlanetRender()
{
}

PlanetRender::PlanetRender(unsigned aColor, int aSize)
{
	color = aColor;
	size = aSize;
}


PlanetRender::~PlanetRender()
{
}

void PlanetRender::draw(const Transform & planetTrans, const mat3 &t)
{
	mat3 glob = planetTrans.getGlobalTransform();

	mat3 l = t * glob;
	//vec3 nPos = l.c[2];

	vec2 pos;
	pos.x = l.c[2].x;
	pos.y = l.c[2].y;

	sfw::drawCircle(pos.x, pos.y, size, 12, color);
}
