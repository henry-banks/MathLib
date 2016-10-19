#include "ShipRender.h"
#include "sfwdraw.h"

using namespace sfw;

ShipRender::ShipRender()
{
}


ShipRender::~ShipRender()
{
}

void ShipRender::draw(const Transform & t, const mat3 & camera)
{
	mat3 glob = t.getGlobalTransform();

	mat3 l = camera * glob;
	//vec3 nPos = l.c[2];
	
	vec2 pos;
	pos.x = l.c[2].x;
	pos.y = l.c[2].y;

	vec3 point1 = (l *  vec3 { 0, 7 ,1});
	vec3 point2 = (l *  vec3 { 4, -7 ,1});
	vec3 point3 = (l *  vec3 { -4, -7 ,1});
	vec3 point4 = (l *  vec3 { 0, -5, 1});

	drawLine(point1.x, point1.y, point2.x, point2.y, WHITE);
	drawLine(point1.x, point1.y, point3.x, point3.y, WHITE);
	drawLine(point2.x, point2.y, point4.x, point4.y, WHITE);
	drawLine(point3.x, point3.y, point4.x, point4.y, WHITE);

}
