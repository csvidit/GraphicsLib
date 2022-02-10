#include "Matrix.h"
#include <string>
#include <iostream>
#include <fstream>
#include <math.h>

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

Vector4 Matrix4::operator*(Vector4 other)
{
    Vector4 result;
    result.x = (other.x * ix) + (other.y * jx) + (other.z * kx) + (other.w * ox);
    //Vector4(ix,iy,iz,iw) * (other.x);
    //result.y = Vector4(jx, jy, jz, jw) * (other.y);
   // result.z = Vector4(kx, ky, kz, kw) * (other.z);
    //result.w = Vector4(ox, oy, oz, ow) * (other.w);
    result.y = (other.x * iy) + (other.y * jy) + (other.z * ky) + (other.w * oy);
    result.z = (other.x * iz) + (other.y * jz) + (other.z * kz) + (other.w * oz);
    result.w = (other.x * iw) + (other.y * jw) + (other.z * kw) + (other.w * ow);
    return result;
}

Matrix4 Matrix4::operator*(Matrix4 other)
{
    Vector4 one = Vector4(other.ix, other.iy, other.iz, other.iw);
    Vector4 two = Vector4(other.jx, other.jy, other.jz, other.jw);
    Vector4 three = Vector4(other.kx, other.ky, other.kz, other.kw);
    Vector4 four = Vector4(other.ox, other.oy, other.oz, other.ow);
    //Matrix4 prev(ix,jx,kx,ox,
      //           iy,jy,ky,oy,
        //         iz,jz,kz,oz,
          //       iw,jw,kw,ow);
    one =  *this * one;
    two = *this * two;
    three=  *this * three;
    four = *this * four;
    Matrix4 result;
    result.ix = one.x;
    result.iy = one.y;
    result.iz = one.z;
    result.iw = one.w;
    result.jx = two.x;
    result.jy = two.y;
    result.jz = two.z;
    result.jw = two.w;
    result.kx = three.x;
    result.ky = three.y;
    result.kz = three.z;
    result.kw = three.w;
    result.ox = four.x;
    result.oy = four.y;
    result.oz = four.z;
    result.ow = four.w;

//    prev.ix= next1.x;
//    prev.iy = next1.y;
//    prev.iz= next1.z;
//    prev.iw = next1.w;
//    prev.jx= next2.x;
//    prev.jy = next2.y;
//    prev.jz= next2.z;
//    prev.jw = next2.w;
//    prev.kx= next3.x;
//    prev.ky = next3.y;
//    prev.kz= next3.z;
//    prev.kw = next3.w;
//    prev.ox= next4.x;
//    prev.oy = next4.y;
//    prev.oz= next4.z;
//    prev.ow = next4.w;
//    Matrix4 result = Matrix4(col1.x, col2.x, col3.x, col4.x,
//        col1.y, col2.y, col3.y, col4.y,
//        col1.z, col2.z, col3.z, col4.z,
//        col1.w, col2.w, col3.w, col4.w);
        return result;


    //return prev;
   // Vector4 col88 = (*this) * Vector4(other.ix, other.iy, other.iz, other.iw);
//    Vector4 col2 = (*this) * Vector4(other.jx, other.jy, other.jz, other.jw);
//    Vector4 col3 = (*this) * Vector4(other.kx, other.ky, other.kz, other.kw);
//    Vector4 col4 = (*this) * Vector4(other.ox, other.oy, other.oz, other.ow);
//    Matrix4 result = Matrix4(col1.x, col2.x, col3.x, col4.x,
//    col1.y, col2.y, col3.y, col4.y,
//    col1.z, col2.z, col3.z, col4.z,
//    col1.w, col2.w, col3.w, col4.w);
//    return result;
}
Matrix4 Translate3D(float tX, float tY, float tZ)
{
Matrix4 translate3D = Matrix4(1, 0, 0, tX,
                              0, 1, 0, tY,
                              0, 0, 1, tZ,
                              0, 0, 0, 1);
return translate3D;
}

Matrix4 Scale3D(float sX, float sY, float sZ)
{
Matrix4 scale3D =
Matrix4(sX, 0, 0, 0,
        0, sY, 0, 0,
        0, 0, sZ, 0,
        0, 0, 0, 1);
return scale3D;
}

Matrix4 RotateX3D(float degrees)
{
float radians = degrees * M_PI / 180.0;
Matrix4 rotateX3D =
Matrix4(1, 0, 0, 0,
0, cos(radians), sin(radians), 0,
0, -sin(radians), cos(radians), 0,
0, 0, 0, 1);
return rotateX3D;
}

Matrix4 RotateY3D(float degrees)
{
float radians = degrees * M_PI / 180.0;
Matrix4 rotateY3D =
Matrix4(cos(radians), 0, -sin(radians), 0,
0, 1, 0, 0,
sin(radians), 0, cos(radians), 0,
0, 0, 0, 1);
return rotateY3D;
}


Matrix4 RotateZ3D(float degrees)
{

float radians = degrees * M_PI / 180.0;
Matrix4 rotateZ3D =
Matrix4(cos(radians), sin(radians), 0, 0,
-sin(radians), cos(radians), 0, 0,
0, 0, 1, 0,
0, 0, 0, 1);
return rotateZ3D;
}

Matrix4 Rotate3D(float degreesX, float degreesY, float degreesZ)
{
//    Matrix4 rotateX = RotateX3D(degreesX);
//    Matrix4 rotateY = RotateY3D(degreesY);
//    Matrix4 rotateZ = RotateZ3D(degreesZ);
//    Matrix4 rotate3D = rotateX * rotateY * rotateZ;
    Matrix4 rotate3D = RotateX3D(degreesX) * RotateY3D(degreesY) * RotateZ3D(degreesZ);
return rotate3D;
}

Matrix4 Rotate3D(float degrees, Vector4 vec)
{
    float alpha = atanf(vec.x/vec.z);
    float beta = acosf(vec.y/vec.magnitude());
    Matrix4 firstStep = RotateY3D(alpha);
    Matrix4 SecondStep = RotateX3D(beta);
    Matrix4 thirdStep = RotateY3D(degrees);
    Matrix4 fourthStep = RotateX3D(-beta);
    Matrix4 fifthStep = RotateY3D(-alpha);
    Matrix4 rotate3D = firstStep * SecondStep * thirdStep * fourthStep * fifthStep;
//    Matrix4 rotate3D = RotateY3D(alpha)*RotateX3D(beta)*RotateY3D(degrees)*RotateX3D(-beta)*RotateY3D(-alpha);
    return rotate3D;
}

void Matrix4::print()
{
    cout << ix << " " << jx << " " << kx << " " << ox << endl;
    cout << iy << " " << jy << " " << ky << " " << oy << endl;
    cout << iz << " " << jz << " " << kz << " " << oz << endl;
    cout << iw << " " << jw << " " << kw << " " << ow << endl;

}
