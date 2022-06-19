#pragma once
class Counter
{
	int value;

public:
	Counter() : value { 0 } {} //묵시적 디폴트 생성자

	void reset() { value = 0; }
	void count() { ++value; }
	int getValue() const { return value; }
};

