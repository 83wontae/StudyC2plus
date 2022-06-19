#pragma once

#include <iostream>
#include <cstring>

using namespace std;

/*
* VecF Ŭ����
* VecF ��ü�� ������ �� �ִ� float ���� ���� �μ��� �����Ͽ� ����
* ������ ���� �迭�� ������ ��� �� ������ �ʱ�ȭ�Ѵ�.
* �μ��� ���޵� VecF ��ü�� ������ ����� ��ȯ�� �� ����.
* ��ü�� ����� ���͸� ��� ����.
*/
class VecF
{
	int n;			// ������ ũ��
	float* arr;		// ���� ������ �迭 ������

public:
	VecF(int d, float* a = nullptr) : n{ d } {
		arr = new float[d];
		if (a) memcpy(arr, a, sizeof(float) * n);
	}
	//���� ������
	//VecF(const VecF& fv) : n{fv.n}, arr{fv.arr} {} //arr�ּҰ� ���簡 �Ǿ� ���� ����(shallow copy)�� ��
	VecF(const VecF& fv) : n{ fv.n }{
		arr = new float[n];// ������ �ٽ� �����ϸ鼭 ���� ����(shallow copy)�� �ȵ�
		memcpy(arr, fv.arr, sizeof(float) * n);
	}
	//�̵� ������( ���� ������ ���� �켱������ ���� )
	//fv�� ���� �̵��ϴ� ó���� ����ǹǷ� const�� ������ �ʴ´�.
	VecF(VecF&& fv) : n{ fv.n }, arr{ fv.arr}/*�ּҰ��� �����*/ {
		fv.arr = nullptr;	//�̵� source ��ü �ʱ�ȭ( nullptr�� �ʱ�ȭ ���� ������ �ı��ڿ��� arr�� �޸𸮸� ��ȯ )
		fv.n = 0;			//�̵� source ��ü �ʱ�ȭ
	}

	~VecF() {
		delete[] arr;
	}

	VecF add(const VecF& fv) const {
		VecF tmp{ n };// pR-value
		for (int i = 0; i < n; i++)
			tmp.arr[i] = arr[i] + fv.arr[i];
		return tmp;
	}

	void print() const {
		cout << "[ ";
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << "]";
	}
};

