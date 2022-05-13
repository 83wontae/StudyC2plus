/*
#include <iostream>

using namespace std;

enum PieceType { PieceTypeKing = 1, PieceTypeQueen, PieceTypeRook = 10, PieceTypePawn };

enum class StronglyPieceType : unsigned long { StronglyPieceTypeKing = 1, StronglyPieceTypeQueen, StronglyPieceTypeRook = 10, StronglyPieceTypePawn };

struct Employee {
	char firstInitial;
	char lastInitial;
	int employeeNumber;
	int salary;
};

int main()
{
	int someInteger = 256;
	short someShort;
	long someLong;
	float someFloat;
	double someDouble;

	someInteger++;
	someInteger *= 2;
	someShort = static_cast<short>(someInteger);
	someLong = someShort * 10000;
	someFloat = someLong + 0.785;
	someDouble = static_cast<double>(someFloat) / 100000;
	cout << someDouble << endl;

	//열거 타입
	
	//const int PieceTypeKing = 0;
	//const int PieceTypeQueen = 1;
	//const int PieceTypeRook = 2;
	//const int PieceTypePawn = 3;

	//int myPiece = PieceTypeKing;
	

	PieceType myPiece;
	myPiece = PieceTypeKing;

	StronglyPieceType myStronglyPiece;
	myStronglyPiece = StronglyPieceType::StronglyPieceTypeKing;
	// enum class는 자동으로 정수 타입 변환이 안됨. if (PieceType::Queen == 2){...}와 같이 쓸수 없다.
	int intPiece = static_cast<int>(StronglyPieceType::StronglyPieceTypeKing);

	Employee anEmployee;
	anEmployee.firstInitial = 'M';
	anEmployee.lastInitial = 'G';
	anEmployee.employeeNumber = 42;
	anEmployee.salary = 80000;
	cout << "Employee: " << anEmployee.firstInitial << anEmployee.lastInitial << endl;
	cout << "Number: " << anEmployee.employeeNumber << endl;
	cout << "Salary: $" << anEmployee.salary << endl;

}
*/