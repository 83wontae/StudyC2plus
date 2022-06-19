#include <iostream>
#include "Counter.h"
#include "CounterM.h"
#include "VecF.h"

using namespace std;


void R_Value_L_Value();

int main()
{
	//������ ������
	Counter cnt1;
	Counter cnt2[4];
	Counter* pCnt = new Counter[10];
	delete[] pCnt;

	CounterM cntM1{ 999 };//�ݵ�� ���� �־��־����
	//CounterM cntM2[4];//error
	CounterM cntM2[3] = { CounterM(9), CounterM(99), CounterM(999) };
	//CounterM pCntM2 = new CounterM[10];//error

	/*
	* ���� ������
	* - ���� Ŭ������ ��ü�� �����Ͽ� ��ü�� ����� ������
	* - ������ ���� ������ : ��ü�� ������ ������� �״�� �����Ͽ� ��ü�� ���鵵�� ���������� ���ǵ� ���� ������
	* 
	* class ClassName{
	* 
	* public:
	*	ClassName(const ClassName& obj){
	*	}
	* }
	*/

	CounterM cntM4{ 99 };
	CounterM cntM5{ cntM4 };// cntM4 -> cntM5�� ����ȴ�.
	CounterM cntM6 = cntM4;// cntM5 -> cntM6�� ����ȴ�.

	//���� ����(shallow copy)�� ������
	float a[3] = { 1, 2, 3 };
	VecF v1(3, a);	//a���� v1�� ����
	VecF v2(v1);	//v1�� �����Ͽ� v2�� ����
	v1.print();
	cout << endl;
	v2.print();
	cout << endl;

	//���� �������� ������
	float p1[3] = { 1,2,3 };
	float p2[3] = { 2,4,6 };
	VecF v3(3, p1);
	VecF v4(3, p2);
	/*
	* add �Լ��� temp������ �����ϰ� ���簡 �Ǽ� 2�� ���簡 �����
	* new, memcpy�� ����� ���̵��. ������ �ʿ䰡 ����
	*/
	VecF v5(v3.add(v4));

	//L-value�� R-value
	R_Value_L_Value();
	
};

void R_Value_L_Value()
{
	/*
	* L-value�� R-value
	* int a = 10;
	* int b = a;
	* L-value = a, b(�ٽ� ����Ҽ� �ִ� ��)
	* R-value = 10(�ѹ� ���ǰ� �������� ��)
	* 
	* & : L-value ���� ��ȣ
	* && : R-value ���� ��ȣ
	*/

	VecF v1(3), v2(3);
	VecF& vLRef = v1;				//L-value ������ L-value�� ���� ����(v1�� �����Ͽ� ��ü�� �����ϱ� ������ ����)
	//int& a = 10;					//����: L-value �����δ� R-value�� �����Ҽ� ����
	const int& b = 20;				//��� L-value �����δ� R-value�� �����Ҽ� ����
	int&& c = 30;					//R-value ������ R-value�� ���� ����
	VecF&& vRRef1 = v1.add(v2);		//�Լ��� ��ȯ ��ü�� R-value�̹Ƿ� ���� ����
	//VecF&& vRRef2 = v2;			//����: R-value �����δ� L-value�� �����Ҽ� ����

}