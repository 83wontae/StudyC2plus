#pragma once

struct CircleStruct
{
	int x, y;
	double radius;
};

class CircleClass
{
public:
	CircleClass(int x, int y, double radius) : mX(x), mY(y), mRadius(radius) {}

private:
	int mX, mY;
	double mRadius;
};

