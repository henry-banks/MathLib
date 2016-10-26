#pragma once

//Collision stuff

//1-dimensional collision (points on a line)
struct CollisionData1D
{
	bool result;		//penDepth > 0?
	float penDepth;		//Penetration Depth - How much overlap
	float colNormal;	//Collision Normal - -1 or 1
	float MTV;			//Minimum Translation Normal - penDepth - colNormal;

};

CollisionData1D colDet1D(float aMin, float aMax, float bMin, float bMax);