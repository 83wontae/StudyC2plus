/*
#include <iostream>
#include <vector>
#include <array>

void myFunction(int i, char c);
int addNumber(int number1, int number2);

auto AutoAddNumber(int number1, int number2)
{
	std::cout << "Entering function " << __func__ << std::endl;
	return number1 + number2;
}

int main()
{
	int someInt = 1;
	char someChar = 's';
	myFunction(8, 'a');
	myFunction(someInt, 'b');
	myFunction(5, someChar);
	int value = addNumber(1, 2);
}

void myFunction(int i, char c)
{
	std::cout << "the value of i is " << i << std::endl;
	std::cout << "the value of c is " << c << std::endl;
}

int addNumber(int number1, int number2)
{
	return number1 + number2;
}
*/