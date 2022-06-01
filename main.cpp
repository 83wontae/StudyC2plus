#include <iostream>

using namespace std;

constexpr int fac(int n) {
	return n > 1 ? n * fac(n - 1) : 1;
}

int main()
{
	int a = 0b1001111;
	int b = 0237;
	int c = 0x9f;

	
	unsigned int d = 2999999999u;
	cout << d << "\n" << endl;

	char c1 = '\101';
	char c2 = '\x41';
	cout << c1 << endl;
	cout << c2 << endl;

	double d1 = 1200.;
	double d2 = 1200.0;
	double d3 = 12e2;
	double d4 = 1.2e+3;

	float f1 = 1200.0f;
	float f2 = 12e2f;

	auto auto1 = 12e2f;

	int total = 0;
	int total2(0); 
	int total3 = { 0 };
	int total4{ 0 };

	constexpr int nfac = fac(4);
	cout << nfac << endl;
	//short x{ total };
	//float y{ total };

}