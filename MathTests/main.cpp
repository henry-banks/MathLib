#include <cassert>
#include <iostream>

#include "Test.h"
#include <cassert>
#include <iostream>

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

	//hel if i kno.
	//assert(DistFromPlane(initp(), init3()) == )

	//¯\_(ツ)_/¯
	//assert(CubicBezier() == )

	printf("All good :D");

	getchar();
	return;
}