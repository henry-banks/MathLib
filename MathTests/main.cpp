#include <cassert>
#include <iostream>

#include "Test.h"
#include "vec2.h"
#include "vec3.h"

void main()
{
	assert(Quadratic_y(0) == -7);
	assert(Quadratic_y(-1) == -8);

	assert(QuadFormula(1, 2, -7).roots == 2);
	assert(QuadFormula(1, 0, -1).leftRoot == -1);
	assert(QuadFormula(1, 0, -1).rightRoot == 1);

	assert(LinBlend(0, 0, 0) == 0);
	assert(LinBlend(3, 4, 0) == 3);
	
	Point2D a, b;
	a.x = 0; a.y = 5;
	b.x = 12; b.y = 5;
	assert(Distance(a, b) == 12);
	assert(Distance(init2(0, 0), init2(0, 0)) == 0);
	
	assert(InnerProd(init3(0, 0, 0), init3(0, 0, 0)) == 0);
	assert(InnerProd(init3(2, 3, 4), init3(4, 3, 2)) == 25);
	assert(InnerProd(init3(1, 2, 3), init3(1, 2, 3)) == 14);

	assert(DistFromPlane(initp(1, 0, 0, 0), init3(1, 0, 0)) == 1);
	assert(DistFromPlane(initp(1,2,2,1), init3(1,1,1)) == 2);

	//No thanks
	/*assert(CubicBezier(0, init3(0, 0, 0), init3(1, 0, 0), init3(2, 0, 0), init3(4, 0, 0)).x == 0);
	assert(CubicBezier(0, init3(0, 0, 0), init3(1, 0, 0), init3(2, 0, 0), init3(4, 0, 0)).x == 4);
	assert(CubicBezier(0, init3(0, 0, 0), init3(1, 0, 0), init3(2, 0, 0), init3(4, 0, 0)).z == 0);*/

	//Vector stuff
	assert((vInit2(1,2) + vInit2(2,1)) == vInit2(3,3));
	assert((vInit2(1, 2) - vInit2(2, 1)) == vInit2(-1, 1));
	assert((vInit2(1, 2) * 2) == vInit2(2, 4));
	assert((2 * vInit2(2, 1)) == vInit2(4, 2));
	assert((vInit2(1, 2) / vInit2(2, 1)) == vInit2(.5, 2));

	assert((vInit2(1, 2) += vInit2(2, 1)) == vInit2(3, 3));
	assert((vInit2(1, 2) -= vInit2(2, 1)) == vInit2(-1, 1));
	assert((2 *= vInit2(2, 1)) == vInit2(4, 2));
	assert((vInit2(1, 2) *= 2) == vInit2(2, 4));
	assert((vInit2(1, 2) /= vInit2(2, 1)) == vInit2(.5, 2));

	assert(vInit2(1, 2) == vInit2(1, 2));
	assert(vInit2(1, 2) != vInit2(2, 1));

	//assert(magnitude(vInit2(1, 1)) == sqrt(2));

	assert((vInit3(1, 2, 3) + vInit3(3, 2, 1)) == vInit3(4, 4, 4));

	printf("All good :D");

	getchar();
	return;
}