/*
#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main()
{
	int myArray1[3] = {};
	myArray1[0] = 0;
	myArray1[1] = 0;
	myArray1[2] = 0;

	int myArray2[] = { 1,2,3,4 };

	unsigned int array1Size = size(myArray1);
	unsigned int array2Size = sizeof(myArray2);

	char ticTacToeBoard[3][3];
	ticTacToeBoard[1][1] = 'o';

	array<int, 3> arr = { 9, 8, 7 };
	cout << "Array Size = " << arr.size() << endl;
	cout << "2nd element = " << arr[1] << endl;

	vector<int> myVector = { 11, 22 };

	myVector.push_back(33);
	myVector.push_back(44);

	cout << "1st element: " << myVector[0] << endl;

	array<int, 3> values = { 11, 22, 33 };
	
	auto [a, b, c] = values; // �ȵǸ� C++ 2017 ��� �̻� ������ ������� �ʰ� �ִ�. ( "������Ʈ �Ӽ� - �Ϲ� - C++ ��� ǥ��" Ȯ�� )

}
*/