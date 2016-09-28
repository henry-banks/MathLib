#include <iostream>
#include "sfwdraw.h"
#include "vec2.h"
#include "Transform.h"

using namespace sfw;

void main()
{
	initContext(800,600);
	setBackgroundColor(0x222222ff);

	float moveSpeed;

	Transform trans(400, 300);
	/*trans.pos = vec2{ 400,300 };
	trans.rotAngle = 45;
	trans.scl = vec2{ 24, 8 };*/

	vec2 v1{40,0};
	

	float ang_vec = 0;

	while (stepContext())
	{
		ang_vec += getDeltaTime();
		vec2 v2 = fromAngle(ang_vec) * 40;
		float proj = dotProd(v1, normalize(v2));

		drawLine(400, 300, 400 + v1.x, 300 + v1.y, RED);
		drawLine(400, 300, 400 + v2.x, 300 + v2.y, GREEN);
		drawLine(400, 300, 400 + proj, 300 + proj , YELLOW);

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