/*
#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	{
		cout << "* * * * * * * * * *" << endl;
		cout << "*                 *" << endl;
		cout << "*                 *" << endl;
		cout << "*                 *" << endl;
		cout << "*                 *" << endl;
		cout << "*                 *" << endl;
		cout << "*                 *" << endl;
		cout << "*                 *" << endl;
		cout << "*                 *" << endl;
		cout << "* * * * * * * * * *" << endl;
	}

	{
		//대입 연산자
		double a = 0;
		int b = 0; // b = 0
		a = b = 0; // a = 0, b = 0
		a = b = 1.5; // a = 1, b = 1 ( 정수형이므로 소수점 자리가 제거됨 )

		//복합 대입 연산자
		//a += b;
		//a -= b;
		//a *= b;
		//a /= b;
		//a %= b;
	}

	{
		//증감 연산자, 후위표기법 전위표기법
		int a = 10;
		int b = 0;
		//b = ++a;//a = 11, b = 11
		b = a++;//a = 11, b = 10
		//b = --a;//a = 9, b = 9
		//b = a--;//a = 9, b = 10
		cout << "a = " << a << " b = " << b << endl;
	}

	{
		//관계 연산자, 조건 연산자
		int a = 10;
		int b = -5;
		bool result;
		result = (a > b) ? true : false;
		result = (a == 5) ? true : false;
		result = (a > 0 && b > 0) ? true : false;
		result = (a > 0 || b > 0) ? true : false;
		result = (a < 0 && --b > 0) ? true : false; // a < 0가 거짓이므로 --b > 0는 실행하지 않는다, 그러므로 --b가 실행되지 않아서 b의 값은 -5로 유지된다
		result = !(a > 0) ? true : false;
		cout << "result = " << boolalpha << result << boolalpha << endl;
	}

	{
		int num = 10;
		cout << bitset<32>(num) << "\n";
		int n = 10;

		cout << dec << n << " " << endl;// 8진수
		cout << oct << n << " " << endl;// 8진수
		cout << hex << uppercase << n << endl;// 16진수 대문자 표기


		int x = 0x35;//0011 0101
		int y = 0xf0;//1111 0000

		cout << "x = " << bitset<8>(x) << "\n";
		cout << "y = " << bitset<8>(y) << "\n";
		cout << "x | y = " << bitset<8>((x | y)) << "\n";//논리합
		cout << "x & y = " << bitset<8>((x & y)) << "\n";//논리곱
		cout << "x ^ y = " << bitset<8>((x ^ y)) << "\n";//배타적 논리 합, 두 값이 같으면 0, 다르면 1
		cout << "~x = " << bitset<8>((~x)) << "\n";//부정
		int x1 = x << 2;
		cout << "x1 << 2 = " << bitset<8>((x1)) << "\n";// << 비트 이동 후 뒤쪽으로 0이 채워짐
		
		char cX = 0b10010100;// -108
		cX = cX >> 2;
		cout << "cX >> 2 = " << bitset<8>((cX)) << "\n";// >> 비트 이동 후 맨앞쪽으 값으로 채워짐
	}

	{
		//묵시적 형 변환
		//- 두 값 사이의 연산에서는 우선순위가 낮은 자료형의 값이 순위가 높은 자료형의 값과 같은 형으로 자동적으로 변환됨
		//- 여러 개의 연산으로 구성된 수식에서 묵시적 형 변환은 연산자 단위로 이루어짐
		//- 대입 연산자(=)는 값을 저장할 변수의 자료형으로 묵시적형 변환을 함
		//- 오차나 오버플로가 발생할 수 있으므로 주의

		//연산자 우선 순위 
		//1.*,/
		//2.+,-

		//자료형 우선 순위
		//char -> int -> long -> float -> double -> long double

		//intVar = doubleVar + intVar * floatVar;
		//1.			    		 (float)
		//2.			    (double)
		//3.	 (int)
	}

	{
		//static_cast : 실행 중에 형 검사를 하지 않으며, 컴파일 할 때 수식에 지정된 그대로 변환함
		//dynamic_cast : 기초 클래스와 파생 클래스 간의 포인터 또는 참조 형 변환이 프로그램 실행 중에 일어나도록 지시함
		//reinterpret_cast : 포인터를 다름 자료형의 포인터나 정수 자료형으로, 또는 그 역으로 변환함
		//const_cast : const 지정을 일시 해제함

		double d = 10.5;
		int a = static_cast<int>(d);
	}
}
*/