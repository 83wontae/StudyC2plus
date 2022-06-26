#pragma once
#include <iostream>

using namespace std;

class Student
{
	string mName;
	int mClassNum;
	int mScore;

public:
	Student(string name, int classNum, int score) : mName(name), mClassNum(classNum), mScore(score) {};

	void PrintInfo()
	{
		cout << "이름 : " << mName << ", " << mClassNum << "반, 점수 : " << mScore << endl;
	}
};

