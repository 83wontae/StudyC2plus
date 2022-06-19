#include <iostream>
#include "Counter.h"
#include "CounterM.h"
#include "VecF.h"

using namespace std;


void R_Value_L_Value();

int main()
{
	//디폴드 생성자
	Counter cnt1;
	Counter cnt2[4];
	Counter* pCnt = new Counter[10];
	delete[] pCnt;

	CounterM cntM1{ 999 };//반드시 값을 넣어주어야함
	//CounterM cntM2[4];//error
	CounterM cntM2[3] = { CounterM(9), CounterM(99), CounterM(999) };
	//CounterM pCntM2 = new CounterM[10];//error

	/*
	* 복사 생성자
	* - 같은 클래스의 객체를 복사하여 객체를 만드는 생성자
	* - 묵시적 복사 생성자 : 객체의 데이터 멤버들을 그대로 복사하여 객체를 만들도록 묵시적으로 정의된 복사 생성자
	* 
	* class ClassName{
	* 
	* public:
	*	ClassName(const ClassName& obj){
	*	}
	* }
	*/

	CounterM cntM4{ 99 };
	CounterM cntM5{ cntM4 };// cntM4 -> cntM5로 복사된다.
	CounterM cntM6 = cntM4;// cntM5 -> cntM6로 복사된다.

	//얕은 복사(shallow copy)의 문제점
	float a[3] = { 1, 2, 3 };
	VecF v1(3, a);	//a값을 v1에 저장
	VecF v2(v1);	//v1을 복사하여 v2를 생성
	v1.print();
	cout << endl;
	v2.print();
	cout << endl;

	//복사 생성자의 문제점
	float p1[3] = { 1,2,3 };
	float p2[3] = { 2,4,6 };
	VecF v3(3, p1);
	VecF v4(3, p2);
	/*
	* add 함수에 temp변수를 생성하고 복사가 되서 2번 복사가 실행됨
	* new, memcpy는 비용이 많이든다. 절약할 필요가 있음
	*/
	VecF v5(v3.add(v4));

	//L-value와 R-value
	R_Value_L_Value();
	
};

void R_Value_L_Value()
{
	/*
	* L-value와 R-value
	* int a = 10;
	* int b = a;
	* L-value = a, b(다시 사용할수 있는 값)
	* R-value = 10(한번 사용되고 버려지는 값)
	* 
	* & : L-value 참조 기호
	* && : R-value 참조 기호
	*/

	VecF v1(3), v2(3);
	VecF& vLRef = v1;				//L-value 참조로 L-value를 참조 가능(v1을 생성하여 객체가 존재하기 때문에 가능)
	//int& a = 10;					//오류: L-value 참조로는 R-value를 참조할수 없음
	const int& b = 20;				//상수 L-value 참조로는 R-value를 참조할수 없음
	int&& c = 30;					//R-value 참조로 R-value를 참조 가능
	VecF&& vRRef1 = v1.add(v2);		//함수의 반환 객체는 R-value이므로 참조 가능
	//VecF&& vRRef2 = v2;			//오류: R-value 참조로는 L-value를 참조할수 없음

}