#include <iostream>
#include <vector>
#include <array>

//#pragma warning(disable:4996)//strcpy를 사용시 경고 끄기

using namespace std;

// 분산 구하기 함수
double variance(const double arr[], int n)
{
	double sum = 0, sqSum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += arr[i];
		sqSum += arr[i] * arr[i];
	}
	double result = sqSum / n - sum * sum / (n * n);
	return result;
}

//화씨를 섭씨로 변환 (함수의 원형)
float FahrToC(float fahr);

//참조 전달 &
void SwapValues(int& x, int& y);

//const & 참조 전달 예제
struct SalesRec {
	char pID[10];//10Byte
	int dYear, dMonth, dDate;//4*3Byte
	char deliverAddr[40];//40Byte
};

void PrSalesRec(const SalesRec& srec);

//함수 디폴트 인수(d = 소수점 자리수)
double Round(double x, int d = 0);
//void f(int x, int y = 10, int z = 20)// OK
//void f(int x, int y = 10, int z)// 오류


//함수 다중 정의
struct TimeRec {
	int hours;
	int minutes;
};

void AddTime(TimeRec& t1, const TimeRec& t2);
void AddTime(TimeRec& t, int minutes);
//void f(int a, int b); // 매개변수만 가능
//int f(int a, int b); // 반환 자료형은 다를 수 없다.
//void f(int a, int b, int c = 100); // 첫번째 함수와 비슷 하므로 문제가 생긴다
/*
void h(int a);
void h(float a);

h(10);
h(10.0f);
h(10.0); // double 형으로 대상이 모호하여 에러

*/

/*
inline 함수란?
- 함수 호출 절차를 따르지 않고 함수 호출 위치에 함수의 처리 문장이 삽입되게 번역하도록 선언된 함수
- 함수를 사용함으로써 얻을 수 있는 모듈화의 장점을 살리면서, 함수 호출에 따른 부수적인 처리시간이 생략됨
- 함수 호출 루틴으로부터 함수로 넘어가는 부분의 코드 최적화가 가능해짐
- 매우 빈번히 호출되며 빠른 실행이 요구되는 함수를 inline 함수로 선언하면 성능을 높이는데 도움이 됨

inline 함수로 선언하더라도 반드시 inline으로 번연되는 것은 아님
inline 선언을 무시하고 일반 함수로 번역하는 경우
- 함수가 너무 큰 경우
- 순환 호출(recursive call)을 하는 경우, 재귀 함수
- 프로그램 내에서 그 함수에 대한 포인터를 사용하는 경우, 콜백 함수


inline void SwapValues(int& x, int& y);
*/

int main()
{
	/*
	double a[50], b[100];

	double sum = 0, sqSum = 0;
	for (int i = 0; i < 50; ++i)
	{
		sum += a[i];
		sqSum += a[i] * a[i];
	}
	cout << sqSum / 50 - sum * sum / (50 * 50) << endl;


	sum = sqSum = 0;
	for (int i = 0; i < 100; ++i)
	{
		sum += b[i];
		sqSum += b[i] * b[i];
	}
	cout << sqSum / 100 - sum * sum / (100 * 100) << endl;

	double a[50], b[100];
	cout << variance(a, 50) << endl;
	cout << variance(b, 100) << endl;

	// 함수란"
	// 필요한 작업을 하나로 묶어서 이름을 부여하는 기능
	// 함수가 필요한 위치에 함수의 이름을 호출하여 사용함
	// 매개변수를 통하여 함수에서 처리할 데이터(인수)를 전달함
	// 함수는 정해진 처리를 한 후 결과 값을 반환할 수 있음
	// 함수의 실행을 완료하면 호출한 곳으로 복귀함

	// return
	// void 는 return;
	// 반환 값이 있으면 return 값;
	// main은 예외 제외 가능함

	float fTemp, cTemp;
	cout << "화씨온도 : ";
	cin >> fTemp;
	cTemp = FahrToC(fTemp);
	cout << "---> 섭씨 온도 : " << cTemp << endl;

	int a1, b1;
	cout << "두 수를 입력하세오 : ";
	cin >> a1 >> b1;
	SwapValues(a1, b1);
	cout << "a1 = " << a1 << " b1 = " << b1 << endl;

	//https://ko.wikipedia.org/wiki/C_%EB%AC%B8%EC%9E%90%EC%97%B4_%EC%B2%98%EB%A6%AC
	SalesRec stRec;
	strcpy_s(stRec.pID, "123456789");
	stRec.dYear = 2022;
	stRec.dMonth = 06;
	stRec.dDate = 07;
	strcpy_s(stRec.deliverAddr, "경기도 부천");

	//const & 참조 전달 예제
	PrSalesRec(stRec);
	*/

	//함수 다중 정의
	TimeRec tRec1 = { 2, 30 };
	TimeRec tRec2 = { 1, 45 };
	
	cout << tRec1.hours << "시간 " << tRec1.minutes << "분 + ";
	cout << tRec2.hours << "시간 " << tRec2.minutes << "분 = ";
	AddTime(tRec1, tRec2);
	cout << tRec1.hours << "시간 " << tRec1.minutes << "분" << endl;

	cout << tRec1.hours << "시간 " << tRec1.minutes << "분 + ";
	cout << "135분 = ";
	AddTime(tRec1, 135);
	cout << tRec1.hours << "시간 " << tRec1.minutes << "분" << endl;
}

//화씨를 섭씨로 변환
float FahrToC(float fahr)
{
	return (fahr - 32) * 5 / 9;
}

void SwapValues(int& x, int& y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void PrSalesRec(const SalesRec& srec)
{
	cout << "품목코드 : " << srec.pID << endl;
	cout << "배달일자 : " << srec.dYear << "년 ";
	cout << srec.dMonth << "월 ";
	cout << srec.dDate << "일" << endl;
	cout << "배달주소 : " << srec.deliverAddr << endl;
}

double Round(double x, int d)
{
	double a = x >= 0 ? 0.5 : -0.5;//양수 음수에 따른 반올림 값 설정
	double pow10 = pow(10, d);// 10에 d제곱 소수점 자리 처리
	return trunc(x * pow10 + a) / pow10;// x * pow10로 소수점 자리 처리, a를 더한후 내림(trunc)처리, pow10를 나누어서 자리수 복구  
}

void AddTime(TimeRec& t1, const TimeRec& t2)
{
	t1.minutes += t2.minutes;
	t1.hours += t2.hours + (t1.minutes / 60);
	t1.minutes %= 60;
}

void AddTime(TimeRec& t, int minutes)
{
	t.minutes += minutes;
	t.hours += (t.minutes / 60);
	t.minutes %= 60;
}