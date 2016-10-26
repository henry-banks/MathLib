#include "collision.h"
#include "vec2.h"

CollisionData1D colDet1D(float aMin, float aMax, float bMin, float bMax)
{
	CollisionData1D out;


	float pDr = aMax - bMin;
	float pDl = bMax - aMin;
	out.penDepth = pDr < pDr ? pDr : pDl;

	out.colNormal = (pDl - pDr) > 0 ? 1 : -1;

	out.result = out.penDepth > 0;
	out.MTV = out.penDepth * out.colNormal;

	return out;
}
