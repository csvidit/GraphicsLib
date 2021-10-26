#ifndef TRIANGLE2D_H
#define TRIANGLE2D_H

#include "Vector2.h"
#include "Color.h"


struct Triangle2D
{
	Vector2 v1;
	Vector2 v2;
	Vector2 v3;
	Color c1;
	Color c2;
	Color c3;
	Triangle2D();
	Triangle2D(Vector2 point1, Vector2 point2, Vector2 point3, Color color1, Color color2, Color color3);
	void calculateBarycentricCoordinates(Vector2 P, float& lambda1, float& lambda2, float& lambda3);
	
};

#endif
