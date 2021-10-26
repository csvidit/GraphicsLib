#include "Triangle2D.h"
#include "Raster.h"
#include "Vector2.h"
#include "Color.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Triangle2D::Triangle2D() {
	v1 = Vector2(0.0, 0.0);
	v2 = Vector2(0.0, 0.0);
	v3 = Vector2(0.0, 0.0);
	c1 = Black;
	c2 = Black;
	c3 = Black;
	}

Triangle2D::Triangle2D(Vector2 point1, Vector2 point2, Vector2 point3, Color color1, Color color2, Color color3) {
	v1 = point1;
	v2 = point2;
	v3 = point3;
	c1 = color1;
	c2 = color2;
	c3 = color3;
}

void Triangle2D::calculateBarycentricCoordinates(Vector2 P, float& lambda1, float& lambda2, float& lambda3) {

	lambda1 = determinant(v1 - v2, P - v2)/determinant(v1 - v2, v3 - v2);
	lambda2 = determinant(P - v2, v3 - v2) / determinant(v1 - v2, v3 - v2);
	lambda3 = 1.0 - lambda1 - lambda2;
}

