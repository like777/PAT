#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Student
{
	string name;
	vector<int> things;
};

int main()
{
	int n, m;
	int count = 0, thingscount = 0;
	cin >> n >> m;

	map<int, bool> wrongthings;
	for (int i = 0; i < m; i++)
	{
		int number;
		cin >> number;
		wrongthings[number] = true;
	}

	for (int i = 0; i < n; i++)
	{
		Student student;
		string str;
		int number, temp;
		cin >> student.name >> number;
		for (int j = 0; j < number; j++)
		{
			cin >> temp;
			if (wrongthings[temp] == true)
			{
				student.things.push_back(temp);
				++thingscount;
			}
		}
		if (student.things.size() != 0)
		{
			count ++;
			cout << student.name << ": ";
			for (int j = 0; j < student.things.size(); j++)
			{
				if (j != 0)
					cout << " ";
				printf("%04d", student.things[j]);
			}
			cout << endl;
		}
	}
	cout << count << " " << thingscount;

}