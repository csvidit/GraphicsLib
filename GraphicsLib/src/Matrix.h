#ifndef MATRIX_H
#define MATRIX_H

struct Matrix4
{
	float ix;
	float jx;
	float kx;
	float ox;
	float iy;
	float jy;
	float ky;
	float oy;
	float iz;
	float jz;
	float kz;
	float oz;
	float iw;
	float jw;
	float kw;
	float ow;
	Matrix4();
	Matrix4(float pix, float pjx, float pkx, float pox,
		float piy, float pjy, float pky, float poy,
		float piz, float pjz, float pkz, float poz,
		float piw, float pjw, float pkw, float pow);
	Vector4 operator*(Vector4& other);
	Matrix4 operator*(Matrix4& other);
	void print();


};

#endif