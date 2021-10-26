#include "Vector2.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Vector2::Vector2() {
	x = 0.0;
	y = 0.0;
}

Vector2::Vector2(float input1, float input2) {
	x = input1;
	y = input2;
}

Vector2 Vector2::operator+(Vector2& other) {
	Vector2 result = Vector2(x + other.x, y + other.y);
	return result;
}

Vector2 Vector2::operator-(Vector2& other) {
	Vector2 result = Vector2(x - other.x, y - other.y);
	return result;
}

Vector2 Vector2::operator*(float other) {
	Vector2 result = Vector2(x * other, y * other);
	return result;
}

float Vector2::magnitude() {
	float result = sqrt(pow(x, 2) + pow(y, 2));
	return result;
}

float Vector2::dot(Vector2 input) {
	float result = (x * input.x) + (y * input.y);
	return result;
}

Vector2 Vector2::normalize() {
	Vector2 result;
	float magnitudeResult = 1/magnitude();
	result.x = magnitudeResult * x;
	result.y = magnitudeResult * y;
	return result;
}

Vector2 Vector2::prependicular() {
	Vector2 result;
	result.x = -y;
	result.y = x;
	return result;
}

float determinant(Vector2 a, Vector2 b) {
	float result = (b.x * a.y) - (a.x * b.y);
	return result;
}