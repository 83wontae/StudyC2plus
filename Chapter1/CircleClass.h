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
		// ������ * ������ * PI(3.141592) --> ���� ���� ����
		return radius * radius * PI;
	}

	void display()
	{
		std::cout << " �߽� : (" << center.x << ", " << center.y << ")" << std::endl;
		std::cout << " ������ : " << radius << std::endl;
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
		// ������ * ������ * PI(3.141592) --> ���� ���� ����
		return c.radius * c.radius * PI;
	}

	double getDistance(CircleType c1, CircleType c2)
	{
		double dx = c1.center.x - c2.center.x;
		double dy = c1.center.y - c2.center.y;
		double dCntr = sqrt(dx * dx + dy * dy);// sqrt --> ������ ���ϱ�

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

