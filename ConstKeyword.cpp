/*
#include <iostream>
#include <vector>
#include <array>
#include <initializer_list>
#include <string>

using namespace std;

const int versionNumberMajor = 2;
const int versionNumberMinor = 1;
const std::string productName = "Super Hyper Net Modulator";


void addOne(int i)
{
	i++;
}

void addOneRef(int& i)
{
	i++;
}

void printString(const string& myString)
{
	std::cout << myString << std::endl;
}

int main()
{
	int x = 42;
	int& xReference = x;

	int myInt = 7;
	addOne(myInt);
	cout << "myInt = " << myInt << endl;
	addOneRef(myInt);
	cout << "myInt = " << myInt << endl;

	string someString = "Hello World";
	printString(someString);
	printString("Hello World2");
}
*/