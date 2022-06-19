#include <iostream>
#include <vector>
#include <array>

//#pragma warning(disable:4996)//strcpy�� ���� ��� ����

using namespace std;

// �л� ���ϱ� �Լ�
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

//ȭ���� ������ ��ȯ (�Լ��� ����)
float FahrToC(float fahr);

//���� ���� &
void SwapValues(int& x, int& y);

//const & ���� ���� ����
struct SalesRec {
	char pID[10];//10Byte
	int dYear, dMonth, dDate;//4*3Byte
	char deliverAddr[40];//40Byte
};

void PrSalesRec(const SalesRec& srec);

//�Լ� ����Ʈ �μ�(d = �Ҽ��� �ڸ���)
double Round(double x, int d = 0);
//void f(int x, int y = 10, int z = 20)// OK
//void f(int x, int y = 10, int z)// ����


//�Լ� ���� ����
struct TimeRec {
	int hours;
	int minutes;
};

void AddTime(TimeRec& t1, const TimeRec& t2);
void AddTime(TimeRec& t, int minutes);
//void f(int a, int b); // �Ű������� ����
//int f(int a, int b); // ��ȯ �ڷ����� �ٸ� �� ����.
//void f(int a, int b, int c = 100); // ù��° �Լ��� ��� �ϹǷ� ������ �����
/*
void h(int a);
void h(float a);

h(10);
h(10.0f);
h(10.0); // double ������ ����� ��ȣ�Ͽ� ����

*/

/*
inline �Լ���?
- �Լ� ȣ�� ������ ������ �ʰ� �Լ� ȣ�� ��ġ�� �Լ��� ó�� ������ ���Եǰ� �����ϵ��� ����� �Լ�
- �Լ��� ��������ν� ���� �� �ִ� ���ȭ�� ������ �츮�鼭, �Լ� ȣ�⿡ ���� �μ����� ó���ð��� ������
- �Լ� ȣ�� ��ƾ���κ��� �Լ��� �Ѿ�� �κ��� �ڵ� ����ȭ�� ��������
- �ſ� ����� ȣ��Ǹ� ���� ������ �䱸�Ǵ� �Լ��� inline �Լ��� �����ϸ� ������ ���̴µ� ������ ��

inline �Լ��� �����ϴ��� �ݵ�� inline���� �����Ǵ� ���� �ƴ�
inline ������ �����ϰ� �Ϲ� �Լ��� �����ϴ� ���
- �Լ��� �ʹ� ū ���
- ��ȯ ȣ��(recursive call)�� �ϴ� ���, ��� �Լ�
- ���α׷� ������ �� �Լ��� ���� �����͸� ����ϴ� ���, �ݹ� �Լ�


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

	// �Լ���"
	// �ʿ��� �۾��� �ϳ��� ��� �̸��� �ο��ϴ� ���
	// �Լ��� �ʿ��� ��ġ�� �Լ��� �̸��� ȣ���Ͽ� �����
	// �Ű������� ���Ͽ� �Լ����� ó���� ������(�μ�)�� ������
	// �Լ��� ������ ó���� �� �� ��� ���� ��ȯ�� �� ����
	// �Լ��� ������ �Ϸ��ϸ� ȣ���� ������ ������

	// return
	// void �� return;
	// ��ȯ ���� ������ return ��;
	// main�� ���� ���� ������

	float fTemp, cTemp;
	cout << "ȭ���µ� : ";
	cin >> fTemp;
	cTemp = FahrToC(fTemp);
	cout << "---> ���� �µ� : " << cTemp << endl;

	int a1, b1;
	cout << "�� ���� �Է��ϼ��� : ";
	cin >> a1 >> b1;
	SwapValues(a1, b1);
	cout << "a1 = " << a1 << " b1 = " << b1 << endl;

	//https://ko.wikipedia.org/wiki/C_%EB%AC%B8%EC%9E%90%EC%97%B4_%EC%B2%98%EB%A6%AC
	SalesRec stRec;
	strcpy_s(stRec.pID, "123456789");
	stRec.dYear = 2022;
	stRec.dMonth = 06;
	stRec.dDate = 07;
	strcpy_s(stRec.deliverAddr, "��⵵ ��õ");

	//const & ���� ���� ����
	PrSalesRec(stRec);
	*/

	//�Լ� ���� ����
	TimeRec tRec1 = { 2, 30 };
	TimeRec tRec2 = { 1, 45 };
	
	cout << tRec1.hours << "�ð� " << tRec1.minutes << "�� + ";
	cout << tRec2.hours << "�ð� " << tRec2.minutes << "�� = ";
	AddTime(tRec1, tRec2);
	cout << tRec1.hours << "�ð� " << tRec1.minutes << "��" << endl;

	cout << tRec1.hours << "�ð� " << tRec1.minutes << "�� + ";
	cout << "135�� = ";
	AddTime(tRec1, 135);
	cout << tRec1.hours << "�ð� " << tRec1.minutes << "��" << endl;
}

//ȭ���� ������ ��ȯ
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
	cout << "ǰ���ڵ� : " << srec.pID << endl;
	cout << "������� : " << srec.dYear << "�� ";
	cout << srec.dMonth << "�� ";
	cout << srec.dDate << "��" << endl;
	cout << "����ּ� : " << srec.deliverAddr << endl;
}

double Round(double x, int d)
{
	double a = x >= 0 ? 0.5 : -0.5;//��� ������ ���� �ݿø� �� ����
	double pow10 = pow(10, d);// 10�� d���� �Ҽ��� �ڸ� ó��
	return trunc(x * pow10 + a) / pow10;// x * pow10�� �Ҽ��� �ڸ� ó��, a�� ������ ����(trunc)ó��, pow10�� ����� �ڸ��� ����  
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