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

void PlanetRender::draw(Transform & planetTrans)
{
	mat3 glob = planetTrans.getGlobalTransform();

	vec2 pos = glob.c[2].xy;

	sfw::drawCircle(pos.x, pos.y, size, 12, color);
}
