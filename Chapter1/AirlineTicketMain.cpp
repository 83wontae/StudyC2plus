/*
#include <iostream>
#include "AirlineTicket.h"
#include "CircleClass.h"

using namespace std;

int main()
{
	AirlineTicket myTicket;
	myTicket.setPassengerName("Sherman T. Socketwrench");
	myTicket.setNumberOfMiles(700);
	double cost = myTicket.calculatePriceInDollars();
	cout << "This ticket will cost $" << cost << endl;

	auto myTicket2 = make_unique<AirlineTicket>();
	myTicket2->setPassengerName("Laudimore M. Hallidue");
	myTicket2->setNumberOfMiles(2000);
	myTicket2->setHasEliteSuperRewardsStatus(true);
	double cost2 = myTicket2->calculatePriceInDollars();
	cout << "This other ticket will cost &" << cost2 << endl;

	AirlineTicket* myTicket3 = new AirlineTicket();
	myTicket3->setPassengerName("Laudimore M. Hallidue");
	myTicket3->setNumberOfMiles(2000);
	myTicket3->setHasEliteSuperRewardsStatus(true);
	double cost3 = myTicket3->calculatePriceInDollars();
	cout << "This other ticket will cost &" << cost2 << endl;
	delete myTicket3;

	// unique 포인터 이동 시키기 
	auto myIntSmartPtr = make_unique<int>(42);
	unique_ptr<int> mData = move(myIntSmartPtr);

	// unique 포인터 가져오기
	AirlineTicket* pUniquePointer = myTicket2.get();
	pUniquePointer->setHasEliteSuperRewardsStatus(true);

	// 유니폼 초기화
	CircleStruct myCircle1 = { 10, 10, 2.5 };
	CircleClass myCircle2 = { 10, 10, 2.5 };
	CircleStruct myCircle3{ 10, 10, 2.5 };
	CircleClass myCircle4{ 10, 10, 2.5 };
	
	int a = 3;
	int b(3);
	int c = { 3 };
	int d{ 3 };
	int e{};

	int* pArray = new int[4]{ 0,1,2,3 };

	//auto a = { 11 };
	//auto b = { 11, 22 };

	//auto c { 11 };
	//auto d { 11, 22 };//error
}
*/