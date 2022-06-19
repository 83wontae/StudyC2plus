#pragma once

#include <iostream>
#include <cstring>

using namespace std;

/*
* VecF 클래스
* VecF 객체는 저장할 수 있는 float 값의 수를 인수로 지정하여 생성
* 저장할 값의 배열이 제공될 경우 그 값으로 초기화한다.
* 인수로 전달된 VecF 객체와 덧셈한 결과를 반환할 수 있음.
* 객체에 저장된 벡터를 출력 가능.
*/
class VecF
{
	int n;			// 벡터의 크기
	float* arr;		// 벡터 정보의 배열 포인터

public:
	VecF(int d, float* a = nullptr) : n{ d } {
		arr = new float[d];
		if (a) memcpy(arr, a, sizeof(float) * n);
	}
	//복사 생성자
	//VecF(const VecF& fv) : n{fv.n}, arr{fv.arr} {} //arr주소가 복사가 되어 얕은 복사(shallow copy)가 됨
	VecF(const VecF& fv) : n{ fv.n }{
		arr = new float[n];// 공간을 다시 생성하면서 얕은 복사(shallow copy)가 안됨
		memcpy(arr, fv.arr, sizeof(float) * n);
	}
	//이동 생성자( 복사 생성자 보다 우선순위가 높다 )
	//fv는 값이 이동하는 처리가 적용되므로 const를 붙이지 않는다.
	VecF(VecF&& fv) : n{ fv.n }, arr{ fv.arr}/*주소값이 복사됨*/ {
		fv.arr = nullptr;	//이동 source 객체 초기화( nullptr로 초기화 하지 않으면 파괴자에서 arr의 메모리를 반환 )
		fv.n = 0;			//이동 source 객체 초기화
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

