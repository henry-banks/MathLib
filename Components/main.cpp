#include <iostream>
#include "sfwdraw.h"
#include "vec2.h"
#include "flops.h"
#include "Transform.h"

using namespace sfw;

void main()
{
	float W = 1200, H = 1200;
	float steps = 100;

	//initContext(800,400);
	initContext(W, H);
	setBackgroundColor(0x222222ff);

	float moveSpeed;

	Transform trans(400, 300);
	/*trans.pos = vec2{ 400,300 };
	trans.rotAngle = 45;
	trans.scl = vec2{ 24, 8 };*/

	vec2 v1{40,0};
	

	float ang_vec = 0;

	vec2 start = { 200, 300 },
		end = { 900, 800 },
		mid = { 0, 1100 };

	while (stepContext())
	{

		/*for (int i = 0; i < 6400; i++)
		{
			float x1 = i;
			float x2 = (i + 1);

			float y1 = sin(x1);
			float y2 = sin(x2);

			x1 *= 20;
			x2 *= 20;
			y1 *= 20;
			y2 *= 20;

			drawLine(x1, y1+200, x2, y2+200);
		}*/

		for (int i = 0; i < steps; ++i)
		{
			float x1 = i / steps;
			float x2 = (i + 1) / steps;

			vec2 y1 = QuadBezier(start, mid, end, x1);
			vec2 y2 = QuadBezier(start, mid, end, x2);

			x1 *= W;
			x2 *= W;
			y1 *= H;
			y2 *= H;

			drawLine(y1.x, y1.y, y2.x, y2.y);
		}

		/*ang_vec += getDeltaTime();
		vec2 v2 = fromAngle(ang_vec) * 40;
		float proj = dotProd(v1, normalize(v2));

		drawLine(400, 300, 400 + v1.x, 300 + v1.y, RED);
		drawLine(400, 300, 400 + v2.x, 300 + v2.y, GREEN);
		drawLine(400, 300, 400 + proj, 300 + proj , YELLOW);*/

		//trans.rotAngle = -(getMouseX()) / 100;

		////printf("%f\n", trans.rotAngle);

		//if (getKey(81)) {
		//	moveSpeed = 3;
		//}
		//if (!getKey(81)) {
		//	moveSpeed = 1;
		//}

		//if (getKey('D')) {
		//	trans.pos.x += moveSpeed;
		//}
		//if (getKey('A')) {
		//	trans.pos.x -= moveSpeed;
		//}

		//if (getKey('W')) {
		//	//trans.pos += (vec2{ .01f * trans.rotAngle,1 });
		//	trans.pos.y += moveSpeed;
		//}
		//if (getKey('S')) {
		//	//trans.pos -= (vec2{ .01f * trans.rotAngle,1 });
		//	trans.pos.y -= moveSpeed;
		//}

		////trans.rotAngle += getDeltaTime();
		//trans.debugDraw();
	}

	termContext();
}