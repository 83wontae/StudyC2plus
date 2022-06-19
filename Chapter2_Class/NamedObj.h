#pragma once
#include <iostream>

using namespace std;

/*
* NamedObj 클래스 정의
* - 이름을 갖는 객체를 만들 수 있는 클래스를 정의하고자 한다.
* 객체가 생성될 때 고유번호를 가지게 되는데, 이 번호는 NamedObj객체가
* 생성됨에 따라 1번부터 시작하여 차례로 부여되는 일련번호이다.
* 객체는 자기 자신의 일련번호와 이름을 출력할 수 있으며, 현재 존재하는
* NamedObj 클래스의 객체 수를 구할 수 있다.
*/
class NamedObj
{
	char* name;			// 이름을 저장함
	int id;				// ID 번호를 저장함
	static int nConstr;	// 생성된 객체 수
	static int nDestr;	// 소멸된 객체 수

public:
	//생성자 - 이음을 s로 초기화 함
	NamedObj(const char* s);

	//소멸자
	~NamedObj();

	//ID와 이름을 출력함
	void display() const {
		cout << "ID : " << id << " --> 이름 : " << name << endl;
	}

	//현재 존재하는 객체의 수를 구함
	static int nobj() {
		return nConstr - nDestr;
	}
};

