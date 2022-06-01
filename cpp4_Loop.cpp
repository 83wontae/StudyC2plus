/*
#include <iostream>

using namespace std;

int main()
{
	// 3개의 정수값을 입력하여 합 구하기
	int val = 0;
	int total = 0;

	for (int i = 0; i < 3; i++)
	{
		cout << "Num" << i + 1 << " ? ";
		cin >> val;
		total += val;
	}

	cout << "total = " << total << endl;

	//범위 기반 for 루프(C++ 11 이후)
	int arr[5] = { 2, 3, 4, 5, 6 };
	int sum = 0;
	for (int itr : arr)
	{
		sum += itr;

		//++itr;// <--이렇게 arr안에 원소를 변경 불가능
	}

	cout << "sum = " << sum << endl;

	for (int& itr : arr)
	{
		++itr;// int& 로 참조 기호를 사용하면 arr안에 원소 변경 가능
	}

	for (int& itr : arr)
	{
		cout << "itr = " << itr << endl;
	}

	//while 문
	int i = 0;
	system("cls");
	while( i < 3 )
	{
		cout << "Num" << i + 1 << " ? ";
		cin >> val;
		total += val;
		i++;
	}

	int selection = 0;
	do {
		std::cout << "What do you like?: \n";
		std::cout << "1) Red\n";
		std::cout << "2) Blue\n";
		std::cout << "3) Black\n";
		std::cout << "4) White\n";
		std::cin >> selection;
	} while (selection > 4 || 1 > selection);

	std::cout << "You like " << selection << endl;
}
*/