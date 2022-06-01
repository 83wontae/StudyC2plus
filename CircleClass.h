#pragma once

#include <iostream>

const double PI = 3.141592;

struct C2dType
{
	double x, y;
};

struct CircleType
{
	C2dType center;
	double radius;

	double Area()
	{
		// 반지름 * 반지름 * PI(3.141592) --> 원의 면적 공식
		return radius * radius * PI;
	}

	void display()
	{
		std::cout << " 중심 : (" << center.x << ", " << center.y << ")" << std::endl;
		std::cout << " 반지름 : " << radius << std::endl;
	}
};

class CircleClass
{
public:
	CircleClass() : mX(0), mY(0), mRadius(0) {}
	CircleClass(int x, int y, double radius) : mX(x), mY(y), mRadius(radius) {}

	void init(int x, int y, double radius)
	{
		mX = x;
		mY = y;
		mRadius = radius;
	}

	double circleArea(CircleType c)
	{
		// 반지름 * 반지름 * PI(3.141592) --> 원의 면적 공식
		return c.radius * c.radius * PI;
	}

	double getDistance(CircleType c1, CircleType c2)
	{
		double dx = c1.center.x - c2.center.x;
		double dy = c1.center.y - c2.center.y;
		double dCntr = sqrt(dx * dx + dy * dy);// sqrt --> 제곱근 구하기

		return dCntr;
	}

	bool IsOverlaped(CircleType c1, CircleType c2)
	{
		double distance = getDistance(c1, c2);
		return (distance < c1.radius + c2.radius);
	}
private:
	int mX, mY;
	double mRadius;
};

