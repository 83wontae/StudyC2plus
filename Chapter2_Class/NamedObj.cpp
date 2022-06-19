#include "NamedObj.h"
#include <cstring>

//static 데이터 멤버의 정의 및 초기화

int NamedObj::nConstr = 0;
int NamedObj::nDestr = 0;

NamedObj::NamedObj(const char* s)
{
	name = new char[strlen(s) + 1];
	strcpy_s(name, strlen(s) + 1, s);
	id = ++nConstr;
}

NamedObj::~NamedObj()
{
	++nDestr;
	delete[] name;
}
