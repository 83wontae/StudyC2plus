#pragma once
class Counter
{
	int value;

public:
	Counter() : value { 0 } {} //������ ����Ʈ ������

	void reset() { value = 0; }
	void count() { ++value; }
	int getValue() const { return value; }
};

