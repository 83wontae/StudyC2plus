#include <iostream>
#include <vector>
#include <array>
#include <string>
#include "Student.h"
#include <map>

using namespace std;

unsigned int UniqueID = 0;

unsigned int CreateUniqueID()
{
	return ++UniqueID;
}

int main()
{
	int workType = 0;
	bool Running = true;

	//vector<Student> students;
	map<int, Student> mapStudent;

	while (Running)
	{
		system("cls");
		switch (workType)
		{
		case 1:
		{
			string name = "";
			int classNum = 0;
			int score = 0;
			cout << "[Add Student]" << endl;
			cout << "Student name :" << endl;
			cin >> name;
			cout << "Student class :" << endl;
			cin >> classNum;
			cout << "Student score :" << endl;
			cin >> score;

			Student newStudent = { "ฟ๘ลย", 1, 100 };
			//students.push_back(newStudent);

			mapStudent.insert({ CreateUniqueID(), newStudent });

			cout << endl;
		}
		break;

		case 2:
		{
			int deleteIndex = 0;
			cout << "Delete Index : " << endl;
			cin >> deleteIndex;
			/*
			if (deleteIndex < students.size())
			{
				students.erase(students.begin() + deleteIndex);
			}
			*/

			if (mapStudent.find(deleteIndex) != mapStudent.end())
			{
				mapStudent.erase(deleteIndex);
			}
		}
		break;

		case 3:
		{
			int index = 0;
			/*
			for (Student s : students)
			{
				cout << "Index : " << index << ", ";
				index++;
				s.PrintInfo();
			}
			*/
			for (auto iter : mapStudent)
			{
				cout << "UID : " << iter.first << ", ";
				iter.second.PrintInfo();
			}

			cout << endl;
		}
		break;

		default:
			break;
		}


		cout << "[StudentManager]" << endl;
		cout << "1) Add Student" << endl;
		cout << "2) Delete Student" << endl;
		cout << "3) Print All Student" << endl;
		cout << "4) Quit" << endl;

		cin >> workType;
	}
}