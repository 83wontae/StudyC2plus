/*
#include <iostream>
#include <vector>
#include <array>
#include <initializer_list>
#include <string>

using namespace std;

int makeSum(initializer_list<int> list);

int main()
{
	int temp = 0;
	while (temp < 5 )
	{
		cout << "This is silly." << endl;
		++temp;
	}

	temp = 100;
	do {
		cout << "This is silly." << endl;
		++temp;
	} while (temp < 5);

	for (int i = 0; i < 5; ++i)
	{
		cout << "This is silly. " << "(i = " << i << ")" << endl;
	}

	array<int, 4> array = { 1,2,3,4 };
	for (int i : array)
	{
		cout << "This is silly. " << "(i = " << i << ")" << endl;
	}

	int a = makeSum({ 1,2,3 });
	int b = makeSum({ 10,20,30,40,50,60 });

	string myString = "Hello, World!";
	cout << "The value of myString is " << myString << endl;
	cout << "The value of myString is " << myString[1] << endl;
}

int makeSum(initializer_list<int> list)
{
	int total = 0;
	for (int value : list) {
		total += value;
	}
	return total;
}
*/