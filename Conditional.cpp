#include <iostream>

enum class Color { DarkBlue, Black, Red };

void aaa();
void bbb();

int main()
{
	int i = 4;
	if (i > 4){
		std::cout << "i�� 4���� ũ��" << std::endl;
	}
	else if( i < 2 ){
		std::cout << "i�� 2���� �۴�" << std::endl;
	}
	else
	{
		std::cout << "i�� 4��2 ���̿� ���̴�" << std::endl;
	}

	switch (i)
	{
	case 0:
		std::cout << "i�� 0�̴�." << std::endl;
		break;
	case 1:
		std::cout << "i�� 1�̴�." << std::endl;
		break;
	case 2:
		std::cout << "i�� 2�̴�." << std::endl;
		break;
	case 3:
		std::cout << "i�� 3�̴�." << std::endl;
		break;
	case 4:
		std::cout << "i�� 4�̴�." << std::endl;
		break;
	default:
		std::cout << "i�� 0~4�̿ܿ� �ٸ����̴�." << std::endl;
		break;
	}

	Color backgroundColor = Color::DarkBlue;

	switch (backgroundColor)
	{
	case Color::DarkBlue:
	case Color::Black:
		std::cout << "������ ��û Ȥ�� �����̴�." << std::endl;
		bbb();
		[[__fallthrough]];
	case Color::Red:
		std::cout << "������ �����̴�." << std::endl;
		aaa();
		break;
	default:
		break;
	}

	std::cout << ((i > 2) ? "yes" : "no");
	std::cout << (i > 2 ? "yes" : "no");
}

void aaa()
{

}

void bbb()
{

}