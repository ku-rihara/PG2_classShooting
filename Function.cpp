#include<Novice.h>
#include<assert.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include"Function.h"



Vector2 normalize(Vector2 pos) {

	Vector2 result;

	float distance = sqrtf(pos.x * pos.x + pos.y * pos.y);

	result.x = pos.x / distance;
	result.y = pos.y / distance;

	return result;
}

Vector2 normalize(Vector2 objPos1, Vector2 objPos2) {

	Vector2 result;
	Vector2 objDistance;

	objDistance.x = objPos1.x - objPos2.x;
	objDistance.y = objPos1.y - objPos2.y;

	float c = sqrtf(objDistance.x * objDistance.x + objDistance.y * objDistance.y);

	result.x = objDistance.x / c;
	result.y = objDistance.y / c;

	return result;
}

float Distance(Vector2 posA, Vector2 posB) {

	float x = posA.x - posB.x;
	float y = posA.y - posB.y;

	return sqrtf(x * x + y * y);
}

float MAX(float a, float b) {

	if (a > b) {
		return	a;
	}

	else {
		return b;
	}
}
float Clamp(float n, float min, float max) {
	if (n > max) {
		return max;
	}
	if (n < min) {
		return min;
	}
	return n;
}

float Dot(Vector2 obj1, Vector2 obj2) {
	return obj1.x * obj2.x + obj1.y * obj2.y;
}

Vertex MakeLoalVertex(Vector2 size) {

	Vertex vertex;

	vertex.LeftTop.x = size.x;
	vertex.RightTop.x = size.x;
	vertex.LeftBottom.x = size.x;
	vertex.RightBottom.x = size.x;
	vertex.LeftTop.y = size.y;
	vertex.RightTop.y = size.y;
	vertex.LeftBottom.y = size.y;
	vertex.RightBottom.y = size.y;

	return vertex;
}

void newDrawQuad(Vertex VerTex, float startx, float starty, float DrawWidth, float DrawHeigth, int Handle, int Color) {

	Novice::DrawQuad(int(VerTex.LeftTop.x), int(VerTex.LeftTop.y), int(VerTex.RightTop.x), int(VerTex.RightTop.y), int(VerTex.LeftBottom.x), int(VerTex.LeftBottom.y), int(VerTex.RightBottom.x), int(VerTex.RightBottom.y), int(startx), int(starty), int(DrawWidth), int(DrawHeigth), Handle, Color);
}


bool  CircleColligion(Vector2 posA, Vector2 posB, float radA, float radB) {

	float distance;

	float x = posA.x - posB.x;
	float y = posA.y - posB.y;

	distance = sqrtf(x * x + y * y);

	if (distance <= radA + radB) {
		return true;
	}
	else {
		return false;
	}

}
