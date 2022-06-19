/*
#include <iostream>

using namespace std;

int main()
{
	int a, b = { 0 };
	cout << "A is ?";
	cin >> a;
	cout << "B is ?";
	cin >> b;

	if(a > b)
	{
		cout << a << " is Big" << endl;
	}
	else
	{
		cout << b << " is Big" << endl;
	}

	if (a > b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	char grade = ' ';
	int score = 0;
	cout << "Score is ?";
	cin >> score;

	switch (score)
	{
	case 10:
	case 9:
		grade = 'A';
		break;
	case 8:
		grade = 'B';
		break;
	case 7:
		grade = 'C';
		break;
	case 6:
		grade = 'D';
		break;
	default:
		grade = 'F';
		break;
	}

	cout << "Grade is " << grade << endl;
}
*/