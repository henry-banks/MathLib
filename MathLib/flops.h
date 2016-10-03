//FLoating point OPerationS
#pragma once

//Check if float numbers are equivalent to the 7th place (.0000001)
bool fequals(float lhs, float rhs);

float deg2rad(float deg);
float rad2deg(float rad);

float linearHalf(float x);

float slowToFast(float x);
float fastToSlow(float x);
float upDown(float x);
float bounce(float x);
float parabolicBump(float x);
