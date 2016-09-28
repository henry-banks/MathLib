#include <iostream>
#include "sfwdraw.h"
#include "vec2.h"
#include "Transform.h"

using namespace sfw;

void main()
{
	initContext(800,600);
	setBackgroundColor(0x222222ff);

	Transform trans;
	trans.pos = vec2{ 400,300 };
	trans.rotAngle = 45;
	trans.scl = vec2{ 24, 8 };

	while (stepContext())
	{
		trans.rotAngle += getDeltaTime();
		trans.debugDraw();
	}

	termContext();
}