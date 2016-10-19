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

void PlanetRender::draw(Transform & planetTrans, bool isOrigin)
{
	mat3 glob = planetTrans.getGlobalTransform();

	vec2 pos;
	if (isOrigin) {
		pos.x = glob.c[2].x;
		pos.y = glob.c[2].y;
	}
	//Allows satellites to be very small distances away from origin
	//Currently doesn't work
	else {
		pos.x = glob.c[2].x;
		pos.y = glob.c[2].y;
	}

	sfw::drawCircle(pos.x, pos.y, size, 12, color);
}
