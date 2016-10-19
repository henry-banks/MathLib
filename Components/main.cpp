#include <iostream>
#include "sfwdraw.h"
#include "flops.h"
#include "Spaceship.h"
#include "SpaceshipController.h"
#include "Tank.h"

//SpaceObject #include's everything else so I don't need to #include it here
#include "SpaceObject.h"

using namespace sfw;

void drawMain()
{
	float W = 800, H = 800;
	float margin = 10;
	float steps = 100;
	float maxSpeed = 100;

	//initContext(800,400);
	initContext(W, H);
	setBackgroundColor(0x222222ff);

	Transform playerTransform = { 200,200 };
	Transform ST1 = { -50, -2 };
	Transform ST2 ={50, -2};

	ST1.m_parent = &playerTransform;
	ST2.m_parent = &playerTransform;

	//SETTING UP A BUNCH OF STUFF

	RigidBody playerBody;
	Spaceship playerShip;
	SpaceshipController control;

	SpaceObject sun;
	sun.init(vec2{ W / 2, H / 2 }, vec2{ 10, 10 }, 50,	YELLOW, 30, nullptr, true);

	SpaceObject p1;
	p1.init(vec2{ 5,-5 }, vec2{ 10, 10 }, 20, WHITE, 5, &sun.trans);

	SpaceObject p2;
	p2.init(vec2{ -10,5 }, vec2{ 5,5 }, 50, 0xfc9432ff, 10, &sun.trans);
	SpaceObject m1;
	m1.init(vec2{ 1,0 }, vec2{ 1,1 }, 30, WHITE, 2, &p2.trans);

	SpaceObject p3;
	p3.init(vec2{ 8,-16 }, vec2{ 5,5 }, 50, GREEN, 10, &sun.trans);

	SpaceObject p4;
	p4.init(vec2{ -10,30 }, vec2{ 5,5 }, 50, CYAN, 20, &sun.trans);


	/*Transform sunTrans;
	sunTrans.pos = vec2{ W / 2, H / 2 };
	sunTrans.scl = vec2{ 10, 10 };
	RigidBody sunBody;
	PlanetMotor sunMotor;
	sunMotor.rotSpeed = 20;
	PlanetRender sunRender;

	Transform pMercury;
	pMercury.pos = vec2{ 5,-5 };
	pMercury.scl = vec2{ 10,10 };
	pMercury.m_parent = &sunTrans;
	RigidBody mercuryBody;
	PlanetMotor mercuryMotor;
	mercuryMotor.rotSpeed = 20;
	PlanetRender mercuryRender;

	Transform pVenus;
	pVenus.pos = vec2{ -15,5 };
	pVenus.scl = vec2{ 5,5 };
	pVenus.m_parent = &sunTrans;
	RigidBody venusBody;
	PlanetMotor venusMotor;
	venusMotor.rotSpeed = 50;
	PlanetRender venusRender;

	Transform moon1;
	moon1.pos = vec2{ 1,0 };
	moon1.scl = vec2{ 1,1 };
	moon1.m_parent = &pVenus;
	RigidBody moonBody;
	PlanetMotor moonMotor;
	moonMotor.rotSpeed = 10;
	PlanetRender moon1Render;*/

	while (stepContext())
	{

		float deltaTime = getDeltaTime();

		if (playerTransform.pos.x < 0) playerTransform.pos.x = W;
		else if (playerTransform.pos.x > W) playerTransform.pos.x = 0;
		if (playerTransform.pos.y < 0) playerTransform.pos.y = H;
		else if (playerTransform.pos.y > H) playerTransform.pos.y = 0;

		control.update(playerShip);
		playerShip.update(playerTransform, playerBody);
		playerBody.integrate(playerTransform, deltaTime);

		//std::cout << playerTransform.rotAngle << "\n";

		//printf("1: %f, %f\n2: %f, %f\n\n", ST1.pos.x, ST1.pos.y, ST2.pos.x, ST2.pos.y);
		//printf("%f, %f\n", sunTrans.getGlobalTransform().c[2].x, sunTrans.getGlobalTransform().c[2].y);

		/*sunMotor.update(sunBody);
		sunBody.integrate(sunTrans, deltaTime);
		
		mercuryMotor.update(mercuryBody);
		mercuryBody.integrate(pMercury, deltaTime);

		venusMotor.update(venusBody);
		venusBody.integrate(pVenus, deltaTime);

		moonMotor.update(moonBody);
		moonBody.integrate(moon1, deltaTime);*/

		/*playerTransform.debugDraw();
		playerBody.debugDraw(playerTransform);
		ST1.debugDraw();
		ST2.debugDraw();*/

		/*sunRender.draw(sunTrans);
		mercuryRender.draw(pMercury);
		venusRender.draw(pVenus);
		moon1Render.draw(moon1);*/

		/*sunTrans.debugDraw();
		pMercury.debugDraw();
		pVenus.debugDraw();
		moon1.debugDraw();*/

		//printf("%f\n", sun.body.angVel);

		//Main draw function
		sun.updateDraw(deltaTime);
		p1.updateDraw(deltaTime);
		p2.updateDraw(deltaTime);
		m1.updateDraw(deltaTime);
		p3.updateDraw(deltaTime);
		p4.updateDraw(deltaTime);
	}

	sfw::termContext();
}

void drawText()
{
	Transform t;
	t.pos = vec2{ 4,3 };
	t.scl = vec2{ 2,1 };
	t.rotAngle = 90;

	mat3 tMat = t.getLocalTransform();

	printf("position: %f %f\n", t.pos.x, t.pos.y);
	printf("scale: %f %f\n", t.scl.x, t.scl.y);
	printf("rotation: %f %f\n", tMat.c[2].x, tMat.c[2].y);

	printf("\nFull Matrix:");
	debugDraw(tMat);

	system("pause");
}

void drawTank()
{
	float W = 800, H = 800;
	initContext(W, H);
	setBackgroundColor(0x222222ff);

	

	while (stepContext())
	{
		Tank t;

	}
	termContext();
}

void main()
{
	drawTank();
}