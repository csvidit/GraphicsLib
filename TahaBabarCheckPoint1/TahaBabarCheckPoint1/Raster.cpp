#include "Raster.h"
#include "Vector2.h"
#include "Color.h"
#include "Triangle2D.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Raster::Raster() {
	width = 0;
	height = 0;
	pixels = NULL;
}

Raster::Raster(int pWidth, int pHeight, Color pFillColor)
{
	width = pWidth;
	height = pHeight;
	pixels = new Color[width * height];
	for (int i = 0; i < width * height; i++) {
		pixels[i] = pFillColor;
	}
	//Background = pFillColor;

}

Raster::~Raster() {
	delete[] pixels;
}

int Raster::getWidth() {
	return width;
}

int Raster::getHeight() {
	return height;
}

Color Raster::getColorPixel(int x, int y) {
	if (x < width && y < height && x >= 0 && y >= 0) {
		int calculation = ((height - 1 - y) * width + x);

		return pixels[calculation];
	}
	else {
		//cout << "Please enter x and y within the width and height range." << endl;
		return Black;
	}
}

void Raster::setColorPixel(int x, int y, Color pFillColor)
{
	if (x < width && y < height && x >= 0 && y >= 0) {
		int calculation = ((height - 1 - y) * width + x);

		pixels[calculation] = pFillColor;

	}
	//else {
	//	cout << "Please enter x and y within the width and height range." << endl;
	//}
}

void Raster::clear(Color pFillColor) {
	for (int i = 0; i < width * height; i++) {
		pixels[i] = pFillColor;
	}
}

void Raster::writeToPPM() {
	ofstream file1;
	file1.open("FRAMEBUFFER.ppm");
	file1 << "P3" << endl;
	file1 << width << " " << height << endl;
	file1 << "255" << endl;
	Color start;
	
	for (int i = height - 1 ; i >= 0 ; i--) {
		for (int j = 0; j < width; j++) {
			start = getColorPixel(j, i);
			file1 
				<< (int) round(start.red * 255 )<< " " 
				<< (int) round(start.green * 255) << " "
				<< (int) round(start.blue * 255 )<< " ";
		}
		file1 << "\n";
	}
	
	file1.close();
}

void Raster::drawLineDDA(float x1, float y1, float x2, float y2, Color fillColor) {
	
	if (x2 == x1) { //vertical lines
		if (y2 < y1) {
			float temp = y1;
			y1 = y2;
			y2 = temp;
			for (int y = y1; y <= y2; y++) {
				setColorPixel(round(x1), y, fillColor);
			}
		}
		else{
			for (int y = y1; y <= y2; y++) {
				setColorPixel(round(x1), y, fillColor);

			}
		}
		return;
	}
	
	
	if (x2 < x1) {
		float temp = x1;
		x1 = x2;
		x2 = temp;
		temp = y1;
		y1 = y2;
		y2 = temp;
	}

	float calculationOne = (y2 - y1) / (x2 - x1);
	
	if (calculationOne >= -1 && calculationOne <= 1) 
	{
		float y = y1;
		for (int x = x1; x <= x2; x++) {
			if (x < width && y < height && x >= 0 && y >= 0) {
				setColorPixel(x, round(y), fillColor);
				y += calculationOne;
			}
		}
	}
	else if (calculationOne <= -1)
	{
		if (x2 > x1) {
			float temp = x2;
			x2 = x1;
			x1 = temp;
			temp = y2;
			y2 = y1;
			y1 = temp;
		}
		float x = x2;
		float calculationTwo = (x1 - x2) / (y1 - y2);
		for (int y = y2; y >= y1; y--) {
			if (x < width && y < height && x >= 0 && y >= 0) {
				setColorPixel(round(x), y, fillColor);
				x -= calculationTwo;
			}
		}
	}

	else {    
		float x = x2;
		float calculationTwo = (x1 - x2) / (y1 - y2);
		for (int y = y2; y >= y1; y--) {
			if (x < width && y < height && x >= 0 && y >= 0) {
				setColorPixel(round(x), y, fillColor);
				x -= calculationTwo;
			}
		}
		}
	}

void Raster::drawLine_DDA_Interpolated(float x1, float y1, float x2, float y2, Color color1, Color color2) {

	Vector2 v1(x1, y1);
	Vector2 v2(x2, y2);
	Vector2 v3 = v2 - v1;
	float v1Full = v3.magnitude();
	
	if (x2 == x1) { //vertical lines
		if (y2 < y1) {
			float temp = y1;
			y1 = y2;
			y2 = temp;
			for (int y = y1; y <= y2; y++) {
				Vector2 v4(x1, y);
				Vector2 v5 = v4 - v1;
				float v2Full = v5.magnitude();
				float ratio = v2Full / v1Full;
				Color first = color2 * ratio;
				Color second = color1 * (1.0 - ratio);
				Color fillColor = (first + second);
				setColorPixel(round(x1), y, fillColor);
			}
		}
		else {
			for (int y = y1; y <= y2; y++) {
				Vector2 v4(x1, y);
				Vector2 v5 = v4 - v1;
				float v2Full = v5.magnitude();
				float ratio = v2Full / v1Full;
				Color first = color2 * ratio;
				Color second = color1 * (1.0 - ratio);
				Color fillColor = (first + second);
				setColorPixel(round(x1), y, fillColor);

			}
		}
		return;
	}
	
	
	if (x2 < x1) {
		float temp = x1;
		x1 = x2;
		x2 = temp;
		temp = y1;
		y1 = y2;
		y2 = temp;
	}
	
	
	

	float calculationOne = (y2 - y1) / (x2 - x1);

	if (calculationOne >= -1 && calculationOne <= 1)
	{
		float y = y1;
		for (int x = x1; x <= x2; x++) {
			if (x < width && y < height && x >= 0 && y >= 0) {
				Vector2 v4(x, y);
				Vector2 v5 = v4 - v1;
				float v2Full = v5.magnitude();
				float ratio = v2Full / v1Full;
				Color first = color2 * ratio;
				Color second = color1 * (1.0 - ratio);
				Color fillColor = (first + second);
				setColorPixel(x, round(y), fillColor);
				y += calculationOne;
			}
		}
	}
	else if (calculationOne <= -1)
	{
		if (x2 > x1) {
			float temp = x2;
			x2 = x1;
			x1 = temp;
			temp = y2;
			y2 = y1;
			y1 = temp;
		}
		float x = x2;
		float calculationTwo = (x1 - x2) / (y1 - y2);
		for (int y = y2; y >= y1; y--) {
			if (x < width && y < height && x >= 0 && y >= 0) {
				Vector2 v4(x, y);
				Vector2 v5 = v4 - v1;
				float v2Full = v5.magnitude();
				float ratio = v2Full / v1Full;
				Color first = color2 * ratio;
				Color second = color1 * (1.0 - ratio);
				Color fillColor = (first + second);
				setColorPixel(round(x), y, fillColor);
				x -= calculationTwo;
			}
		}
	}

	else { 
		float x = x2;
		float calculationTwo = (x1 - x2) / (y1 - y2);
		for (int y = y2; y >= y1; y--) {
			if (x < width && y < height && x >= 0 && y >= 0) {
				Vector2 v4(x, y);
				Vector2 v5 = v4 - v1;
				float v2Full = v5.magnitude();
				float ratio = v2Full / v1Full;
				Color first = color2 * ratio;
				Color second = color1 * (1.0 - ratio);
				Color fillColor = (first + second);
				setColorPixel(round(x), y, fillColor);
				x -= calculationTwo;
			}
		}
	}
}

void Raster::drawTriangle2D_DotProduct(Triangle2D t1) {
	if (t1.v1.x == t1.v2.x || t1.v2.x == t1.v3.x || t1.v1.x == t1.v3.x)
	{
		cout << "Please enter distinct x points for the triangle" << endl;
	}

	float sortingX[] = { t1.v1.x, t1.v2.x, t1.v3.x };
	float sortingY[] = { t1.v1.y, t1.v2.y, t1.v3.y };
	float xMax = sortingX[0];
	float xMin = sortingX[0];
	float yMax = sortingY[0];
	float yMin = sortingY[0];

	for (int i = 0; i < 3; i++)
	{
		if (sortingX[i] > xMax)
		{
			xMax = sortingX[i];
		}
		else if (sortingX[i] < xMin)
		{
			xMin = sortingX[i];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (sortingY[i] > yMax)
		{
			yMax = sortingY[i];
		}
		else if (sortingY[i] < yMin)
		{
			yMin = sortingY[i];
		}
	}

	for (int x = xMin; x <= xMax; x++) {
		for (int y = yMin; y <= yMax; y++) {
			if (inside(x, y, t1))
			{
				setColorPixel(x, y, t1.c1); //the method can be changed to take user input on color
			}
		}
	}
}

bool Raster::inside(float x, float y, Triangle2D t) {
	Vector2 edgeOne = t.v2 - t.v1;
	Vector2 prepOne = edgeOne.prependicular();
	Vector2 g1 = Vector2(x, y) - t.v1;
	float dotOne = prepOne.dot(g1);

	Vector2 edgeTwo = t.v3 - t.v2;
	Vector2 prepTwo = edgeTwo.prependicular();
	Vector2 g2 = Vector2(x, y) - t.v2;
	float dotTwo = prepTwo.dot(g2);

	Vector2 edgeThree = t.v1 - t.v3;
	Vector2 prepThree = edgeThree.prependicular();
	Vector2 g3 = Vector2(x, y) - t.v3;
	float dotThree = prepThree.dot(g3);

	if (dotOne >= 0 && dotTwo >= 0 && dotThree >= 0) {
		return true;
	}
	else {
		return false;
	}
}


void Raster::drawTriangle_Barycentric(Triangle2D T) {
	
	if (T.v1.x == T.v2.x || T.v2.x == T.v3.x || T.v1.x == T.v3.x)
	{
		cout << "Please enter distinct x points for the triangle" << endl;
	}
	
	float sortingX[] = { T.v1.x, T.v2.x, T.v3.x };
	float sortingY[] = { T.v1.y, T.v2.y, T.v3.y };
	float xMax = sortingX[0];
	float xMin = sortingX[0];
	float yMax = sortingY[0];
	float yMin = sortingY[0];

	for (int i = 0; i < 3; i++)
	{
		if (sortingX[i] > xMax)
		{
			xMax = sortingX[i];
		}
		else if (sortingX[i] < xMin)
		{
			xMin = sortingX[i];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (sortingY[i] > yMax)
		{
			yMax = sortingY[i];
		}
		else if (sortingY[i] < yMin)
		{
			yMin = sortingY[i];
		}
	}
	
	float lambda1 = 0;
	float lambda2 = 0;
	float lambda3 = 0;
	for (int x = xMin; x <= xMax; x++) {
		for (int y = yMin; y <= yMax; y++) {
			Vector2 p(x,y);
			T.calculateBarycentricCoordinates(p, lambda1, lambda2, lambda3);
			if (lambda1 >= 0 && lambda1 <= 1 && lambda2 >= 0 && lambda2 <= 1 && lambda3 >= 0 && lambda3 <= 1) {
				setColorPixel(x, y, Color(lambda1, lambda2, lambda3, 1.0f));
			}
		}
	}
}


