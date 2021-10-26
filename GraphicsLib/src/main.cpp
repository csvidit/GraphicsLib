#include <iostream>
using namespace std;

#include "Color.h"
#include "Raster.h"
#include "Triangle2D.h"
#include "Vector2.h"
#include "Matrix.h"


int main() {/*
			
	Color c1(1.1f, 0.25f, 0.25f, 0.25f);
	Color c2(0.0f, 0.5f, 1.0f, 0.60f);
	Color c3 = c1 + c2;
	cout << c3.red << endl;
	cout << c3.green << endl;
	cout << c3.blue << endl;
	cout << c3.alpha << endl;

	Color c4(1.0f, 0.25f, 0.25f, 0.40f);
	Color c5(0.25f, 0.5f, 0.10f, 0.10f);
	Color c6 = c4 - c5;
	cout << c6.red << endl;
	cout << c6.green << endl;
	cout << c6.blue << endl;
	cout << c6.alpha << endl;

	Color c7(0.25f, 0.38f, 0.75f, 0.50f);
	Color c8 = c7 * 2.0;
	cout << c8.red << endl;
	cout << c8.green << endl;
	cout << c8.blue << endl;
	cout << c8.alpha << endl;
	*/
	//Color red = Red;
	//Raster r1(20, 20, red);
	
	//for (int k = 0; k < r1.getWidth(); k++) {
	//	if (k < r1.getWidth()) {
			//r1.setColorPixel(0, 0, Blue);
			//r1.setColorPixel(r1.getWidth() - 1, 0, Blue);
		//}
	//}
	
	
	//r1.drawLineDDA(0, 8, 5, 18, Blue); //(x1,y1,x2,y2,color)
	//r1.writeToPPM();
    //r1.writeToPPM();
	
	//for (int k = 0; k < r1.getWidth() / 2; k = 2 * k) {
		//r1.setColorPixel(k, 0, Red);
	//}
	//for (int k = 1; k < r1.getWidth() / 2; k = (2 * k) - 1) {
		//r1.setColorPixel(k, 0, Blue);
	//}
	//r1.writeToPPM();
	
	//cout << "Done" << endl;

	/*
	Raster myRaster(100, 100, White);
	Triangle2D myTriangle(Vector2(2, 15), Vector2(72, 10), Vector2(45, 80), Red, Green, Blue);
	myRaster.drawLineDDA(0, 20, 0, 80, Red);
	myRaster.drawLineDDA(2, 80, 2, 20, Red);
	myRaster.drawLineDDA(20, 20, 80, 90, Red);
	myRaster.drawLineDDA(100, 80, 10, 80, Red);
	//myRaster.drawLine_DDA_Interpolated(0, 20, 0, 80, Red, Blue);

	//myRaster.drawTriangle_Barycentric(myTriangle);
	//myRaster.drawLineDDA(0, 20, 0, 80, Blue);
	//myRaster.drawTriangle2D_DotProduct(myTriangle);
	myRaster.writeToPPM();
	cout << "done" << endl;
	*/

	Matrix4 A(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	Matrix B(17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32);
	Matrix C = A * B;
	C.print();
	return 0;
};

