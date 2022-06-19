#pragma once
class CounterM
{
	const int maxValue;// ��� ������ �ݵ�� �ʱ�ȭ �ؾ���
	int value;

public:
	CounterM(int max) : maxValue{ max }, value{0} {} //������ ����Ʈ ������
	//CounterM(const CounterM& c) : maxValue{c.maxValue}, value{c.value} {} //<---������ ���� ������

	void reset() { value = 0; }

	//value�� 1�� ����
	//value�� maxValue�� �����ϸ� 0���� ���ư���.
	void count() { value = value < maxValue ? value + 1 : 0; }
	int getValue() const { return value; }
};

