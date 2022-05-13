#include <iostream>

enum class Color { DarkBlue, Black, Red };

void aaa();
void bbb();

int main()
{
	int i = 4;
	if (i > 4){
		std::cout << "i는 4보다 크다" << std::endl;
	}
	else if( i < 2 ){
		std::cout << "i는 2보다 작다" << std::endl;
	}
	else
	{
		std::cout << "i는 4와2 사이에 수이다" << std::endl;
	}

	switch (i)
	{
	case 0:
		std::cout << "i는 0이다." << std::endl;
		break;
	case 1:
		std::cout << "i는 1이다." << std::endl;
		break;
	case 2:
		std::cout << "i는 2이다." << std::endl;
		break;
	case 3:
		std::cout << "i는 3이다." << std::endl;
		break;
	case 4:
		std::cout << "i는 4이다." << std::endl;
		break;
	default:
		std::cout << "i는 0~4이외에 다른수이다." << std::endl;
		break;
	}

	Color backgroundColor = Color::DarkBlue;

	switch (backgroundColor)
	{
	case Color::DarkBlue:
	case Color::Black:
		std::cout << "배경색이 진청 혹은 검정이다." << std::endl;
		bbb();
		[[__fallthrough]];
	case Color::Red:
		std::cout << "배경색이 빨강이다." << std::endl;
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