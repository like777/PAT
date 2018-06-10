#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Student
{
	char name[21];
	int pro;
	int middle;
	int final;
	int total;
};

bool cmp(Student student1, Student student2)
{
	if (student1.total == student2.total)
	{
		for (int i = 0; i < strlen(student1.name) || i < strlen(student2.name); i++)
		{
			if (i == strlen(student1.name))
			{
				return true;
			}
			else if (i == strlen(student2.name))
			{
				return false;
			}
			if (student1.name[i] == student2.name[i])
			{
				continue;
			}
			return student1.name[i] < student2.name[i];
		}		
	}else
	{
		return student1.total > student2.total;
	}
}
int main()
{
	int p, m, n;
	scanf("%d%d%d", &p, &m, &n);

	char name[21];
	int g;
	map<string, Student> students;
	for (int i = 0; i < p; i++)
	{
		//cin >> name >> g;
		scanf("%s %d", &name, &g);
		Student student;
		//student.name = name;
		for (int j = 0; j < strlen(name) + 1; j++)
			student.name[j] = name[j];
		if (g >= 200)
		{
			for (int j = 0; j < strlen(name) + 1; j++)
				students[name].name[j] = name[j];
			students[name].pro = g;
			students[name].middle = -1;
			students[name].final = -1;
			students[name].total = 0;
		}
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%s %d", name, &g);
		if (students[name].middle == -1)
		{
			students[name].middle = g;
		}else
		{
			students.erase(students.find(name));
		}
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%s %d", name, &g);
		if (students[name].final == -1)
		{
			students[name].final = g;
			if (students[name].middle > g)
			{
				students[name].total = (students[name].middle * 4 + g * 6 + 5) / 10;
			}else
			{
				students[name].total = g;
			}
		}else
		{
			students.erase(students.find(name));
		}
	}

	vector<Student> tVector;
	for (map<string, Student>::iterator it = students.begin(); it != students.end(); ++it)
	{
		tVector.push_back((*it).second);
	}
	sort(tVector.begin(), tVector.end(), cmp);

	for (int i = 0; i < tVector.size(); ++i)
	{
		if (tVector[i].total >= 60)
		{
			printf("%s %d %d %d %d\n", tVector[i].name, tVector[i].pro, tVector[i].middle, tVector[i].final, tVector[i].total);
		}
	}
}