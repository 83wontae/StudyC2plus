#pragma once
#include <iostream>

using namespace std;

/*
* NamedObj Ŭ���� ����
* - �̸��� ���� ��ü�� ���� �� �ִ� Ŭ������ �����ϰ��� �Ѵ�.
* ��ü�� ������ �� ������ȣ�� ������ �Ǵµ�, �� ��ȣ�� NamedObj��ü��
* �����ʿ� ���� 1������ �����Ͽ� ���ʷ� �ο��Ǵ� �Ϸù�ȣ�̴�.
* ��ü�� �ڱ� �ڽ��� �Ϸù�ȣ�� �̸��� ����� �� ������, ���� �����ϴ�
* NamedObj Ŭ������ ��ü ���� ���� �� �ִ�.
*/
class NamedObj
{
	char* name;			// �̸��� ������
	int id;				// ID ��ȣ�� ������
	static int nConstr;	// ������ ��ü ��
	static int nDestr;	// �Ҹ�� ��ü ��

public:
	//������ - ������ s�� �ʱ�ȭ ��
	NamedObj(const char* s);

	//�Ҹ���
	~NamedObj();

	//ID�� �̸��� �����
	void display() const {
		cout << "ID : " << id << " --> �̸� : " << name << endl;
	}

	//���� �����ϴ� ��ü�� ���� ����
	static int nobj() {
		return nConstr - nDestr;
	}
};

