#ifndef VECTOR2_H
#define VECTOR2_H



struct Vector2
{
	float x;
	float y;
	Vector2();
	Vector2(float input1, float input2);
	Vector2 operator+(Vector2& other);
	Vector2 operator-(Vector2& other);
	Vector2 operator*(float other);
	float magnitude();
	float dot(Vector2 input);
	Vector2 normalize();
	Vector2 prependicular();

};

	float determinant(Vector2 a, Vector2 b);

#endif
