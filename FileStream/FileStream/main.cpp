#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


void ReadFile()
{
	string line;
	ifstream file("example.txt");
	if (file.is_open()) {
		while (getline(file, line)) {
			cout << line << endl;
		}
		file.close();
	}
	else {
		cout << "Unable to open file" << endl;
	}
}

void WriteFile()
{
	string line;
	ofstream file("writefile.txt");
	if (file.is_open()) {
		file << "This is the first line\n";
		file << "This is the second line\n";
		file.close();
	}
	else {
		cout << "error" << endl;
	}
}

struct person
{
	string name;
	int score;
};

void ReadPerson(person& p, string str)
{
	int index = 0;
	while (1)
	{
		vector<string> arrStr;
		arrStr = StringCutByKey(str, ",");
		for (string s : arrStr)
		{
			string lstr;
			string rstr;
			StringCutHelfByKey(s, "=", lstr, rstr);
			if (lstr == "name")
			{
				p.name = rstr;
			}
			else if (lstr == "score")
			{
				p.score = rstr;
			}
		}
	}
}

void aaa()
{
	vector<person> arr;

	string line;
	ifstream file("example.txt");
	if (file.is_open()) {
		//while (getline(file, ' ')) // ' '<- 공백기준으로 자르기
		while (getline(file, line)) {
			person p;
			ReadPerson(p, line);
		}
		file.close();
	}
	else {
		cout << "Unable to open file" << endl;
	}
}

vector<string> StringCutByKey(string source, string key)
{
	vector<string> arrStr;
	int point = 0;
	while (1)
	{
		int index = source.find(key, point);
		if (index == string::npos)
			break;

		string out = source.substr(point, index - point);
		out.erase(remove(out.begin(), out.end(), ' '), out.end());
		arrStr.push_back(out);
		point = index + 1;
	}

	string out = source.substr(point, source.length());
	out.erase(remove(out.begin(), out.end(), ' '), out.end());
	arrStr.push_back(out);

	return arrStr;
}

void StringCutHelfByKey(string source, string key, string& leftstr, string& rightstr)
{
	int index = source.find(key);
	leftstr = source.substr(0, index);
	rightstr = source.substr(index + 1);
}

int main() {
	
}