#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct Student
{
	string name;
	vector<int> courses;
};

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);

	int count = 0;
	map<string, int> mp;
	vector<Student> students(n);
	for (int i = 0; i < k; i++)
	{
		int course, student_number;
		string name;
		scanf("%d%d", &course, &student_number);
		for (int j = 0; j < student_number; j++)
		{
			cin >> name;
			if (!mp[name])
			{
				mp[name] = ++count;
				students[count - 1].name = name;
				students[count - 1].courses.push_back(course);
			}else
			{
				students[mp[name] - 1].courses.push_back(course);
			}
		}
	}

	string name;
	vector<Student> students1(n);
	for (int i = 0; i < n; i++)
	{
		cin >> name;
		if (mp[name])
		{
			students1[i] = students[mp[name] - 1];
		}else
		{
			students1[i].name = name;
		}

	}

	for (int i = 0; i < n; i++)
	{
		cout << students1[i].name;
		sort(students1[i].courses.begin(), students1[i].courses.end());
		printf(" %d", students1[i].courses.size());
		for (int j = 0; j < students1[i].courses.size(); j++)
		{
			printf(" %d", students1[i].courses[j]);
		}
		printf("\n");
	}
}