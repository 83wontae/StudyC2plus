/*
#include <iostream>

using namespace std;

int main()
{
	// 3���� �������� �Է��Ͽ� �� ���ϱ�
	int val = 0;
	int total = 0;

	for (int i = 0; i < 3; i++)
	{
		cout << "Num" << i + 1 << " ? ";
		cin >> val;
		total += val;
	}

	cout << "total = " << total << endl;

	//���� ��� for ����(C++ 11 ����)
	int arr[5] = { 2, 3, 4, 5, 6 };
	int sum = 0;
	for (int itr : arr)
	{
		sum += itr;

		//++itr;// <--�̷��� arr�ȿ� ���Ҹ� ���� �Ұ���
	}

	cout << "sum = " << sum << endl;

	for (int& itr : arr)
	{
		++itr;// int& �� ���� ��ȣ�� ����ϸ� arr�ȿ� ���� ���� ����
	}

	for (int& itr : arr)
	{
		cout << "itr = " << itr << endl;
	}

	//while ��
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