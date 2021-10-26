#include "Vector2.h"
#include "Matrix.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Matrix4::Matrix4()
{
	ix = 1;
	jx = 0;
	kx = 0;
	ox = 0;
	iy = 0;
	jy = 1;
	ky = 0;
	oy = 0;
	iz = 0;
	jz = 0;
	kz = 1;
	oz = 0;
	iw = 0;
	jw = 0;
	kw = 0;
	ow = 1;
}

Matrix4::Matrix4(float pix, float pjx, float pkx, float pox,
	float piy, float pjy, float pky, float poy,
	float piz, float pjz, float pkz, float poz,
	float piw, float pjw, float pkw, float pow)
{
	ix = pix;
	jx = pjx;
	kx = pkx;
	ox = pox;
	iy = piy;
	jy = pjy;
	ky = pky;
	oy = poy;
	iz = piz;
	jz = pjz;
	kz = pkz;
	oz = poz;
	iw = piw;
	jw = pjw;
	kw = pkw;
	ow = pow;
}

Vector4 Matrix4::operator*(Vector4& other)
{
	Vector4 resultx = Vector4(ix, iy, iz, iw).operator*(other.x);
	Vector4 resulty = Vector4(jx, jy, jz, jw).operator*(other.y);
	Vector4 resultz = Vector4(kx, ky, kz, kw).operator*(other.z);
	Vector4 resultw = Vector4(ox, oy, oz, ow).operator*(other.w);
	return (resultx + resulty + resultz + resultw);
}

Matrix4 Matrix4::operator*(Matrix4& other)
{
	Vector4 col1 = operator*(Vector4(other.ix, other.iy, other.iz, other.iw));
	Vector4 col2 = operator*(Vector4(other.jx, other.jy, other.jz, other.jw));
	Vector4 col3 = operator*(Vector4(other.kx, other.ky, other.kz, other.kw));
	Vector4 col4 = operator*(Vector4(other.ox, other.oy, other.oz, other.ow));
	Matrix result = Matrix(col1.x, col2.x, col3.x, col4.x,
		col1.y, col2.y, col3.y, col4.y,
		col1.z, col2.z, col3.z, col4.z,
		col1.w, col2.w, col3.w, col4.w);
	return result;
}

void Matrix4::print()
{
	cout << ix << " " << jx << " " << kz << " " << ox << endl;
	cout << iy << " " << jy << " " << ky << " " << oy << endl;
	cout << iz << " " << jz << " " << kz << " " << oz << endl;
	cout << iw << " " << jw << " " << kw << " " << ow << endl;

}
