#include <cassert>
#include <iostream>

#include "Test.h"
#include "vec2.h"
#include "vec3.h"
#include "flops.h"
#include "mat2.h"
#include "mat3.h"
#include "Shapes.h"
#include "collision.h"

//Putting everything into functions so that I can collapse stuff.
void mathTest()
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
	assert(DistFromPlane(initp(1, 2, 2, 1), init3(1, 1, 1)) == 2);

	//No thanks
	/*assert(CubicBezier(0, init3(0, 0, 0), init3(1, 0, 0), init3(2, 0, 0), init3(4, 0, 0)).x == 0);
	assert(CubicBezier(0, init3(0, 0, 0), init3(1, 0, 0), init3(2, 0, 0), init3(4, 0, 0)).x == 4);
	assert(CubicBezier(0, init3(0, 0, 0), init3(1, 0, 0), init3(2, 0, 0), init3(4, 0, 0)).z == 0);*/
}
//NOT vec2/vec3
void vectorTest()
{
	assert((vInit2(1, 2) + vInit2(2, 1)) == vInit2(3, 3));
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

	assert((vInit3(1, 2, 3) + vInit3(3, 2, 1)) == vInit3(4, 4, 4));
	assert((vInit3(1, 2, 3) - vInit3(3, 2, 1)) == vInit3(-2, 0, 2));
	assert(-vInit3(1, 2, 3) == vInit3(-1, -2, -3));
	assert((vInit3(1, 2, 3) * 5) == vInit3(5, 10, 15));
	assert((3 * vInit3(3, 2, 1)) == vInit3(9, 6, 3));
	assert((vInit3(1, 2, 3) / vInit3(2, 2, 1)) == vInit3(.5, 1, 3));

	assert(magnitude(normalize(vInit2(5, 3))) == 1);
	assert(magnitude(normalize(vInit3(5, 3, 6))) == 1);

	assert(fequals(1, .99999999f));
	assert(!fequals(1, .99999f));

	assert(fequals(magnitude(normalize(vInit2(1, 1))), 1));

	assert(fequals(dotProd(vec2{ 5,4 }, vec2{ 1,0 }), 5));
	assert(fequals(dotProd(vec2{ 5,4 }, vec2{ 0,1 }), 4));

	assert(fequals(angleBetween(vec2{ 1,0 }, vec2{ 0,1 }), deg2rad(90)));
	assert(fequals(angleBetween(vec2{ 1,1 }, vec2{ 0,1 }), deg2rad(45)));
	assert(fequals(angleBetween(vec2{ 1,1 }, vec2{ 0,1 }), angle(vec2{ 1,1 })));

	assert((fromAngle(0) == vec2{ 1,0 }));
	assert((fromAngle(deg2rad(90)) == vec2{ 0,1 }));

	assert((crossProd(vec3{ 1,0,0 }, vec3{ 0,1,0 }) == vec3{ 0,0,1 }));
	assert((crossProd(vec3{ 0,1,0 }, vec3{ 1,0,0 }) == vec3{ 0,0,-1 }));

	//printf("%f %f", angleBetween(vec2{ 0,1 }, vec2{ 0,1 }), deg2rad(90));

	/*printf("%f\n", vInit2(5, 3).x);
	printf("%f\n\n", vInit2(5, 3).y);

	printf("%f\n", normalize(vInit3(5, 3, 6)).x);
	printf("%f\n", normalize(vInit3(5, 3, 6)).y);
	printf("%f\n", normalize(vInit3(5, 3, 6)).z);
	printf("%f\n", magnitude(normalize(vInit3(5, 3,6))));*/
}
void lerpCurveTest()
{
	assert(fequals(lerp(4, 23479, 0), 4));
	assert(fequals(lerp(4, 23479, 1), 23479));
	assert(fequals(lerp(0, 1, 0.5), 0.5));

	assert(fequals(QuadBezier(15, 40, 21, 0), 15));
	assert(fequals(QuadBezier(15, 40, 21, 1), 21));
}
void vec2Test()
{
	mat2 a0 = mat2{ 0,0,0,0 };
	mat2 aI = mat2Identity();
	mat2 r0 = mat2{ 4,3,2,1 };
	vec2 x0 = vec2{ 1,0 };

	assert(a0 == a0);
	assert(aI * 2 == 2 * aI);
	assert((aI * 2 == mat2{ 2,0,0,2 }));
	assert(aI + a0 == aI);
	assert(aI - aI == a0);
	assert(aI*-1 == -aI);

	assert(aI * aI == aI);
	assert((mat2{ 1,2,3,4 }) * aI == (mat2{ 1,2,3,4 }));

	assert(aI * x0 == x0);
	assert((r0 * x0 == vec2{ 4,2 }));

	assert(transpose(aI) == aI);
	assert(inverse(aI) == aI);

	assert(r0*inverse(r0) == aI);
}
void vec3Test()
{
	mat3 m0 = mat3{ 0,0,0,0,0,0,0,0,0 };
	mat3 mI = mat3Identity();
	mat3 t0 = mat3{ 9,8,7,6,5,4,3,2,1 };
	vec3 v0 = vec3{ 2,1,0 };

	assert(m0 == m0);
	assert(mI * 2 == 2 * mI);
	assert((mI * 2 == mat3{ 2,0,0,0,2,0,0,0,2 }));
	assert(mI + m0 == mI);
	assert(mI - mI == m0);
	assert(mI * -1 == -mI);

	assert(mI * mI == mI);
	assert((mat3{ 1,2,3,4,5,6,7,8,9 }) * mI == (mat3{ 1,2,3,4,5,6,7,8,9 }));

	assert(transpose(mI) == mI);
	assert(inverse(mI) == mI);

	//assert(t0 * inverse(t0) == mI);
}
void translateTest()
{
	vec3 j = { 2,5,1 };
	assert((scale(5, 1)* j == vec3{ 10,5,1 }));
	//assert((rotationDegrees(90) == mat3{ 0,-1,0,1,0,0,0,0,1 }));
	//assert((rotationDegrees(90)* j == vec3{ -5,2,1 }));
	//assert((translate(0, 3) == mat3{ 1,0,0,0,1,3,0,0,1 }));
	//assert((translate(0, 3)* j == vec3{ 2,8,1 }));
}
void geometryTest()
{
	Circle c = { 0,0,5 };

assert((translate(4, 0) * c == Circle{ 4,0,5 }));

assert((scale(2, 1) * c == Circle{ 0,0,10 }));
assert((scale(2, 2) * c == Circle{ 0,0,10 }));
assert((scale(1, 2) * c == Circle{ 0,0,10 }));

assert((scale(-1, 1) * c == Circle{ 0,0,5 }));
assert((rotationDegrees(45) * c == Circle{ 0,0,5 }));

AABB testBox{ vec2{ 1, 2 }, vec2{ 3, 4 } };

assert((testBox.min() == vec2{ -2, -2 }));
assert((testBox.max() == vec2{ 4,6 }));
}
void collisionTest()
{
	assert(collisionDetection1D(0, 2, 1, 3).result() == true);

	assert(collisionDetection1D(0, 2, 1, 3).penDepth == 1);
	assert(collisionDetection1D(1, 3, 0, 2).penDepth == 1);

	assert(collisionDetection1D(0, 2, 1, 3).colNormal = 1);
	assert(collisionDetection1D(1, 3, 0, 2).colNormal == -1);


	assert(sweptDetection1D(0, 1, 2, 3, 4, 0).entryTime == 1.f);
	assert(sweptDetection1D(0, 1, 5, 3, 4, 0).entryTime == .4f);

	assert(sweptDetection1D(0, 1, -5, 3, 4, 10).result() == false);

	AABB A = { 0,0, 2,4 };
	AABB B = { 2,2, 2,4 };

	assert(boxCollision(A, B).penDepth == 2);
	assert((boxCollision(A, B).colNormal == vec2{ 1,0 }));
	assert((boxCollision(B, A).colNormal == vec2{ -1,0 }));

	AABB As = { 0,0, 1,1 };
	AABB Bs = { 0,10, 1,1 };

	CollisionDataSwept testSwept = boxCollisionSwept(As, vec2{ 0,-1 }, Bs, vec2{ 0,-1 });

	assert(fequals(boxCollisionSwept(As, vec2{ 0,1 }, Bs, vec2{ 0,-1 }).entryTime, 4));
	assert(fequals(boxCollisionSwept(As, vec2{ 0,1 }, Bs, vec2{ 0,-1 }).exitTime, 6));

	//Either -4 or -6
	assert(fequals(boxCollisionSwept(As, vec2{ 0,-1 }, Bs, vec2{ 0,1 }).entryTime, -6));

	AABB bP = { 0,0, 4,4 };

	Plane p1 = { 0,0, 0,1 };	//clipping case
	Plane p2 = { 0,-10, 0,1 };	//non-overlapping
	Plane p3 = { 0,10, 0,1 };	//full overlapping

	Plane p4 = { vec2{6,6}, normalize(vec2{-1,1}) };	//overlapping
	Plane p5 = { vec2{6,6}, normalize(vec2{-1,-1}) };	//non-overlapping

	assert(planeBoxCollision(p1, bP).result());
	assert(!planeBoxCollision(p2, bP).result());
	assert(planeBoxCollision(p3, bP).result());
	assert(planeBoxCollision(p4, bP).result());
	assert(!planeBoxCollision(p5, bP).result());

	Plane p6 = { 10,0, -1,0 }; //fully overlapping

	//assert(fequals(planeBoxCollisionSwept(p6, vec2{ 0,0 }, bP, vec2{ 1,0 }).entryTime, 6.f));

	//Convex hull
	vec2 verts[] = { {0,1},{1,1},{1,0},{0,0} };
	vec2 verts2[] = { {-1,-1},{-1,1},{0,0} };

	Hull h1(verts, 4);
	Hull h2(verts2, 3);

	assert((h1.normals[0] == vec2{ 0,1 }));
	assert((h1.normals[1] == vec2{ 1,0 }));
	assert((h1.normals[2] == vec2{ 0,-1 }));
	assert((h1.normals[3] == vec2{ -1,0 }));

	Hull tHull = translate(1, 0) * h1;

	assert((tHull.vertices[0] == vec2{ 1,1 }));
	assert((tHull.vertices[1] == vec2{ 2,1 }));
	assert((tHull.vertices[2] == vec2{ 2,0 }));
	assert((tHull.vertices[3] == vec2{ 1,0 }));

	assert(fequals(HullCollision(h1, h2).penDepth, 0));
	assert(fequals(HullCollision(h1, tHull).penDepth, -1));
}

//Assertions
void aTests()
{
	mathTest();
	vectorTest();
	lerpCurveTest();
	vec2Test();
	vec3Test();
	translateTest();
	geometryTest();
	collisionTest();

	printf("All good :D\n\n");
}

void MatrixTest1()
{
	mat3 scalMat = mat3{ -2,0,0,0,1,0,0,0,1 };
	mat3 transMat = mat3{ 1,0,5,0,1,-4,0,0,1 };

	//Is it supposed to be a vec2?
	vec3 multVec = vec3{ -3,4,0 };

	mat3 p = scalMat * transMat;
	mat3 q = transMat * scalMat;

	multVec = p*multVec;
	printf("p: %d %d\n", multVec.x, multVec.y);

	multVec = q * vec3{ -3,4,0 };
	printf("q: %d %d\n", multVec.x, multVec.y);
}

void transMatrix()
{
	

	mat3 transMat = mat3Identity();
	mat3 tempMat = mat3Identity();


	mat3 rot90 = rotationRadians(deg2rad(-90));
	mat3 rot45 = rotationDegrees(45);
	mat3 trans1 = translate(0, 10);
	mat3 trans2 = translate(0, 4);
	mat3 trans3 = translate(6, 4);
	mat3 trans4 = translate(0, -4);

	transMat = mat3Identity()* rot90 * trans1;// *rot45 * trans3 * trans2*trans4;

	vec3 testVec = rot90 * trans1 * vec3{ 0, 0, 1 };

	assert((testVec == vec3{ 0,-10,1 }));

	//here we go...
	vec3 test =
		rotationDegrees(-90) * translate(10, 0) *
		rotationDegrees (45) * translate( 4, 0) *
		rotationDegrees (45) * translate(-6, 0) *
		translate(6, 4)		 * vec3 {0, 0, 1};


	transMat = transMat * tempMat;
	printf("\n%f, %f, %f\n", test.x, test.y, test.z);


	//tempMat = rotationDegrees(-90);
	//transMat = transMat * transMat;

	//tempMat = translate(10, 0);
	//transMat = transMat * transMat;

	//tempMat = rotationDegrees(45);
	//transMat = transMat * transMat;

	//tempMat = translate(4, 0);
	//transMat = transMat * transMat;

	//tempMat = translate(6, 4);
	////Addition for global movement?
	//transMat = transMat * transMat;

	//tempMat = rotationDegrees(45);
	//transMat = transMat * transMat;

	//transMat = translate(-6, 0);
	//transMat = transMat * transMat;

	debugDraw(tempMat);
}

void main()
{
	aTests();

	//transMatrix();

	getchar();
	return;
}