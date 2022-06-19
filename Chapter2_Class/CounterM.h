#pragma once
class CounterM
{
	const int maxValue;// 상수 변수는 반드시 초기화 해야함
	int value;

public:
	CounterM(int max) : maxValue{ max }, value{0} {} //묵시적 디폴트 생성자
	//CounterM(const CounterM& c) : maxValue{c.maxValue}, value{c.value} {} //<---묵시적 복사 생성자

	void reset() { value = 0; }

	//value를 1씩 누적
	//value가 maxValue에 도달하면 0으로 돌아간다.
	void count() { value = value < maxValue ? value + 1 : 0; }
	int getValue() const { return value; }
};

