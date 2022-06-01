#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main()
{
	int myArray1[3] = {};
	myArray1[0] = 0;
	myArray1[1] = 0;
	myArray1[2] = 0;

	int myArray2[] = { 1,2,3,4 };//배열 크기는 4
	int myArray3[]{ 1,2,3,4 };// "=" 생략 가능
	int myArray4[5]{ 1,2,3 };// 3, 4는 0으로 초기화됨

	int myArray5[2][4] = { {1,2,3,4}, {5,6,7,8} };//2차원 이상 배열일 경우 행우선 저장

	int num1 = 7;
	int num2 = 4;
	int num3 = 9;
	int num4 = 10;
	int num5 = 25;
	int num6 = 14;
	int num7 = 18;
	int num8 = 42;
	int Max = 0;
	if (Max < num1) Max = num1;
	if (Max < num2) Max = num2;
	if (Max < num3) Max = num3;
	if (Max < num4) Max = num4;
	if (Max < num5) Max = num5;
	if (Max < num6) Max = num6;
	if (Max < num7) Max = num7;
	if (Max < num8) Max = num8;

	int data[10] = { 47, 4, 9, 10, 25, 14, 18, 42, 21, 33 };
	Max = 0;
	for (int i = 0; i < 10; ++i)
	{
		if (Max < data[i]) Max = data[i];
	}

	cout << " 배열의 최대값 : " << Max << endl;
}