#include <iostream>
#include "sfwdraw.h"
#include "flops.h"
#include "Spaceship.h"
#include "SpaceshipController.h"
#include "ShipRender.h"
#include "shapedraw.h"
#include <cstdlib>
#include <vector>
#include <string>

//SpaceObject #include's everything else so I don't need to #include it here
#include "SpaceObject.h"
#include "Collider.h"

using namespace sfw;
using namespace std;

void drawPlanet()
{
	float W = 1600, H = 1000;

	//initContext(800,400);
	initContext(W, H);
	setBackgroundColor(0x222222ff);

	unsigned f = loadTextureMap("./fontmap.png", 16, 16);

	Transform playerTransform = { W/2,H/2 };
	Transform ST1 = { -15, -40 };
	Transform ST2 ={15, -40};
	SpaceObject ST3;
	SpaceObject ST4;

	ShipRender playerRender;

	ST3.init(vec2{ 0, 0 }, vec2{ 2,2 }, 50, WHITE, 6, &playerTransform);
	ST4.init(vec2{ 30,0 }, vec2{ 1,1 }, 50, CYAN, 3, &ST3.trans);

	ST1.m_parent = &playerTransform;
	ST2.m_parent = &playerTransform;

	//SETTING UP A BUNCH OF STUFF

	RigidBody playerBody;
	Spaceship playerShip;
	SpaceshipController control;

	SpaceObject sun;
	sun.init(vec2{ W / 2, H / 2 }, vec2{ 10, 10 }, 20,	YELLOW, 60, nullptr);

	SpaceObject p1;
	p1.init(vec2{ 5,-5 }, vec2{ 10, 10 }, 20, WHITE, 5, &sun.trans);

	SpaceObject p2;
	p2.init(vec2{ -10,5 }, vec2{ 5,5 }, 50, 0xfc9432ff, 10, &sun.trans);
	SpaceObject m1;
	m1.init(vec2{ .5,0 }, vec2{ 1,1 }, 30, WHITE, 2, &p2.trans);

	SpaceObject p3;
	p3.init(vec2{ 8,-16 }, vec2{ 5,5 }, 50, GREEN, 10, &sun.trans);

	SpaceObject p4;
	p4.init(vec2{ -10,30 }, vec2{ 5,5 }, 50, CYAN, 20, &sun.trans);
	SpaceObject m2;
	m2.init(vec2{ .75,0 }, vec2{ 1,1 }, 20, WHITE, 2, &p4.trans);
	SpaceObject m3;
	m3.init(vec2{ -1,0 }, vec2{ 1,1 }, 40, WHITE, 3, &p4.trans);

	SpaceObject p5;
	p5.init(vec2{ -30,-20 }, vec2{ 5,5 }, 50, MAGENTA, 30, &sun.trans);

	SpaceObject p6;
	p5.init(vec2{ 50,50 }, vec2{ 5,5 }, 20, 0x4287d6ff, 40, &sun.trans);

	SpaceObject p7;
	p7.init(vec2{ -500,-500 }, vec2{ 5,5 }, 30, 0xceb514ff, 40, &sun.trans);

	SpaceObject p8;
	p8.init(vec2{ -30,-27 }, vec2{ 2,2 }, 15, 0x7e3b8eff, 40, &sun.trans);

	//DEFUNCT OLD PLANET SETUP
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

	Transform cameraTransform;

	//Collider setup
	vec2 hullVerts[] = { {0,20}, {-10,-10},{10,-10} };
	Collider playerCollider(hullVerts, 3);

	while (stepContext())
	{

		float deltaTime = getDeltaTime();

		//Border wrapping
		/*if (playerTransform.pos.x < 0) playerTransform.pos.x = W;
		else if (playerTransform.pos.x > W) playerTransform.pos.x = 0;
		if (playerTransform.pos.y < 0) playerTransform.pos.y = H;
		else if (playerTransform.pos.y > H) playerTransform.pos.y = 0;*/

		//Temporary reset key
		if (getKey('Q'))
			playerTransform.pos = vec2{ W/2,H/2 };

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


		/*sunRender.draw(sunTrans);
		mercuryRender.draw(pMercury);
		venusRender.draw(pVenus);
		moon1Render.draw(moon1);*/

		/*sunTrans.debugDraw();
		pMercury.debugDraw();
		pVenus.debugDraw();
		moon1.debugDraw();*/

		cameraTransform.pos = playerTransform.pos;

		mat3 proj = translate(W / 2, H / 2) * scale(15, 15);
		mat3 view = inverse(cameraTransform.getGlobalTransform());

		mat3 camera = proj * view;

		//Main draw function

		//playerTransform.debugDraw(camera);
		//playerBody.debugDraw(playerTransform);
		//ST1.debugDraw(camera);
		//ST2.debugDraw(camera);

		//playerRender.draw(playerTransform, camera);
		//playerTransform.debugDraw(camera);
		//playerBody.debugDraw(playerTransform, camera);

	/*	ST3.updateDraw(deltaTime);
		ST4.updateDraw(deltaTime);*/

		/*sun.trans.debugDraw(camera);
		p1.trans.debugDraw(camera);
		p2.trans.debugDraw(camera);
		m1.trans.debugDraw(camera);
		p5.trans.debugDraw(camera);*/


		sun.updateDraw(deltaTime, camera);
		p1.updateDraw(deltaTime, camera);
		p2.updateDraw(deltaTime, camera);
		m1.updateDraw(deltaTime, camera);
		p3.updateDraw(deltaTime, camera);
		p4.updateDraw(deltaTime, camera);
		p5.updateDraw(deltaTime, camera);
		m2.updateDraw(deltaTime, camera);
		m3.updateDraw(deltaTime, camera);
		p6.updateDraw(deltaTime, camera);
		p7.updateDraw(deltaTime, camera);
		p8.updateDraw(deltaTime, camera);


		//Draw coordinates
		string xpos = to_string(playerTransform.pos.x - W/2);
		string ypos = to_string(playerTransform.pos.y - H/2);

		drawString(f, xpos.c_str(), 5, 20, 12, 12, 0, '\0', WHITE);
		drawString(f, ypos.c_str(), 175, 20, 12, 12, 0, '\0', WHITE);

		playerCollider.DebugDraw(camera, playerTransform);

		//Draw borders
		/*drawLine(2, 2, W-1, 2, WHITE);
		drawLine(2, 2, 2, H-1, WHITE);
		drawLine(2, H-2, W-1, H-1, WHITE);
		drawLine(W-2, 2, W-1, H-1, WHITE);*/
	}

	sfw::termContext();
}

void drawCollision()
{
	float W = 1600, H = 1000;

	//initContext(800,400);
	initContext(W, H);
	setBackgroundColor(0x222222ff);

	unsigned f = loadTextureMap("./fontmap.png", 16, 16);
	Transform playerTransform = { W / 2,H / 2 };
	playerTransform.scl = vec2{ 4,4 };

	RigidBody playerBody;
	Spaceship playerShip;
	SpaceshipController control;

	Transform cameraTransform;

	//Collider setup
	vec2 hullVerts[] = { { 0,2 },{ -1,-1 },{ 1,-1 } };
	Collider playerCollider(hullVerts, 3);

	Transform occluderTrans(0, 0);
	occluderTrans.scl = vec2{ 20,20 };
	Collider occluderCollider(hullVerts, 3);
	RigidBody occluderBody;

	while (stepContext())
	{
		float deltaTime = getDeltaTime();

		//Temporary reset key
		if (getKey('Q'))
			playerTransform.pos = vec2{ W / 2,H / 2 };

		//Player controls
		control.update(playerShip);
		playerShip.update(playerTransform, playerBody);
		playerBody.integrate(playerTransform, deltaTime);


		occluderBody.integrate(occluderTrans, deltaTime);

		//Camera stuff
		cameraTransform.pos = playerTransform.pos;
		mat3 proj = translate(W / 2, H / 2) * scale(15, 15);
		mat3 view = inverse(cameraTransform.getGlobalTransform());
		mat3 camera = proj * view;

		//collision
		DynamicResolution(playerTransform, playerBody, playerCollider, occluderTrans, occluderBody, occluderCollider);
		//Draw coordinates
		string xpos = to_string(playerTransform.pos.x - W / 2);
		string ypos = to_string(playerTransform.pos.y - H / 2);

		drawString(f, xpos.c_str(), 5, 20, 12, 12, 0, '\0', WHITE);
		drawString(f, ypos.c_str(), 175, 20, 12, 12, 0, '\0', WHITE);

		playerCollider.DebugDraw(camera, playerTransform);
		occluderCollider.DebugDraw(camera, occluderTrans);

		playerBody.debugDraw(playerTransform, camera);
		occluderBody.debugDraw(occluderTrans, camera);
	}

	sfw::termContext();
}

//WARNING: VERY LARGE
void drawAll()
{
	float W = 1600, H = 1000;

	//initContext(800,400);
	initContext(W, H);
	setBackgroundColor(0x222222ff);

	unsigned f = loadTextureMap("./fontmap.png", 16, 16);

	Transform playerTransform = { W / 2,H / 2 };
	Transform ST1 = { -15, -40 };
	Transform ST2 = { 15, -40 };
	SpaceObject ST3;
	SpaceObject ST4;

	ShipRender playerRender;

	ST3.init(vec2{ 0, 0 }, vec2{ 2,2 }, 50, WHITE, 6, &playerTransform);
	ST4.init(vec2{ 30,0 }, vec2{ 1,1 }, 50, CYAN, 3, &ST3.trans);

	ST1.m_parent = &playerTransform;
	ST2.m_parent = &playerTransform;

	//SETTING UP A BUNCH OF STUFF

	RigidBody playerBody;
	Spaceship playerShip;
	SpaceshipController control;

	SpaceObject sun;
	sun.init(vec2{ W / 2, H / 2 }, vec2{ 10, 10 }, 20, YELLOW, 60, nullptr);

	SpaceObject p1;
	p1.init(vec2{ 5,-5 }, vec2{ 10, 10 }, 20, WHITE, 5, &sun.trans);

	SpaceObject p2;
	p2.init(vec2{ -10,5 }, vec2{ 5,5 }, 50, 0xfc9432ff, 10, &sun.trans);
	SpaceObject m1;
	m1.init(vec2{ .5,0 }, vec2{ 1,1 }, 30, WHITE, 2, &p2.trans);

	SpaceObject p3;
	p3.init(vec2{ 8,-16 }, vec2{ 5,5 }, 50, GREEN, 10, &sun.trans);

	SpaceObject p4;
	p4.init(vec2{ -10,30 }, vec2{ 5,5 }, 50, CYAN, 20, &sun.trans);
	SpaceObject m2;
	m2.init(vec2{ .75,0 }, vec2{ 1,1 }, 20, WHITE, 2, &p4.trans);
	SpaceObject m3;
	m3.init(vec2{ -1,0 }, vec2{ 1,1 }, 40, WHITE, 3, &p4.trans);

	SpaceObject p5;
	p5.init(vec2{ -30,-20 }, vec2{ 5,5 }, 50, MAGENTA, 30, &sun.trans);

	SpaceObject p6;
	p5.init(vec2{ 50,50 }, vec2{ 5,5 }, 20, 0x4287d6ff, 40, &sun.trans);

	SpaceObject p7;
	p7.init(vec2{ -500,-500 }, vec2{ 5,5 }, 30, 0xceb514ff, 40, &sun.trans);

	SpaceObject p8;
	p8.init(vec2{ -30,-27 }, vec2{ 2,2 }, 15, 0x7e3b8eff, 40, &sun.trans);

	Transform cameraTransform;

	//Collider setup
	vec2 hullVerts[] = { { 0,20 },{ -10,-10 },{ 10,-10 } };
	Collider playerCollider(hullVerts, 3);

	Transform occluderTrans(0, 0);
	occluderTrans.scl = vec2{ 20,20 };
	Collider occluderCollider(hullVerts, 3);
	RigidBody occluderBody;

	while (stepContext())
	{
		float deltaTime = getDeltaTime();

		//Temporary reset key
		if (getKey('Q'))
			playerTransform.pos = vec2{ W / 2,H / 2 };

		//Player controls
		control.update(playerShip);
		playerShip.update(playerTransform, playerBody);
		playerBody.integrate(playerTransform, deltaTime);


		occluderBody.integrate(occluderTrans, deltaTime);

		//Camera stuff
		cameraTransform.pos = playerTransform.pos;
		mat3 proj = translate(W / 2, H / 2) * scale(15, 15);
		mat3 view = inverse(cameraTransform.getGlobalTransform());
		mat3 camera = proj * view;


		sun.updateDraw(deltaTime, camera);
		p1.updateDraw(deltaTime, camera);
		p2.updateDraw(deltaTime, camera);
		m1.updateDraw(deltaTime, camera);
		p3.updateDraw(deltaTime, camera);
		p4.updateDraw(deltaTime, camera);
		p5.updateDraw(deltaTime, camera);
		m2.updateDraw(deltaTime, camera);
		m3.updateDraw(deltaTime, camera);
		p6.updateDraw(deltaTime, camera);
		p7.updateDraw(deltaTime, camera);
		p8.updateDraw(deltaTime, camera);

		//collision
		DynamicResolution(playerTransform, playerBody, playerCollider, occluderTrans, occluderBody, occluderCollider);
		//Draw coordinates
		string xpos = to_string(playerTransform.pos.x - W / 2);
		string ypos = to_string(playerTransform.pos.y - H / 2);

		drawString(f, xpos.c_str(), 5, 20, 12, 12, 0, '\0', WHITE);
		drawString(f, ypos.c_str(), 175, 20, 12, 12, 0, '\0', WHITE);

		playerCollider.DebugDraw(camera, playerTransform);
		occluderCollider.DebugDraw(camera, occluderTrans);

		playerBody.debugDraw(playerTransform, camera);
		occluderBody.debugDraw(occluderTrans, camera);
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

void main()
{
	drawAll();
}