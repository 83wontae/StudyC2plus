/*
#include <iostream>
#include <vector>
#include <array>
#include <initializer_list>
#include <string>

using namespace std;

struct Employee
{
	int salary = 0;
	int value = 1;
};

Employee* getEmployee()
{
	Employee* temp = new Employee;
	return temp;
}

void func(char* str) { cout << "char* version" << endl; }
void func(int i) { cout << "int version" << endl; }

int main()
{
	int* myIntegerPointer = nullptr;

	myIntegerPointer = new int;

	if (myIntegerPointer)
	{
		*myIntegerPointer = 8;

		delete myIntegerPointer;
		myIntegerPointer = nullptr;
	}

	//-----------------------------------------------------------//

	int i = 8;
	int* i_pointer = &i;

	Employee* anEmployee = getEmployee();
	cout << (*anEmployee).salary << endl;
	cout << anEmployee->salary << endl;

	//-----------------------------------------------------------//

	int arraySize = 8;
	int* myVariableSizedArray = new int[arraySize];

	myVariableSizedArray[3] = 2;

	delete[] myVariableSizedArray;
	myVariableSizedArray = nullptr;

	//-----------------------------------------------------------//

	func(NULL);
	func(nullptr);

	//-----------------------------------------------------------//

	auto anEmployee = make_unique<Employee>();
	if (anEmployee) {
		cout << "Salary: " << anEmployee->salary << endl;
	}

	auto employees = make_unique<Employee[]>(10);
	cout << "Salary: " << anEmployee[0].salary << endl;

	//-----------------------------------------------------------//

	auto anEmployee2 = make_shared<Employee>();
	if (anEmployee2) {
		cout << "Salary: " << anEmployee2->salary << endl;
	}

	shared_ptr<Employee[]> employees2(new Employee[10]);
	cout << "Salary: " << employees2[0].salary << endl;
}
*/